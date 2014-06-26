/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net.client;
import haxe.io.Bytes;
import haxe.Json;
import haxe.Timer;
import js.Browser;
import js.html.ArrayBuffer;
import js.html.Event;
import js.html.rtc.DataChannel;
import js.html.rtc.IceCandidate;
import js.html.rtc.PeerConnection;
import js.html.rtc.SessionDescription;
import js.html.Uint8Array;
import js.html.WebSocket;
import haxor.component.Behaviour;
import haxor.core.ByteArray;
import haxor.core.Console;
import haxor.core.IUpdateable;
import haxor.core.JSON;
import haxor.core.Time;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Network extends Behaviour
{	
	static var TCP_SERVER_SEND_MESSAGE 		: String = "tcp.SendMessage";	
	static var TCP_SERVER_REQUEST_USERDATA  : String = "tcp.RequestUserData";
	static var TCP_SERVER_REQUEST_USERS 	: String = "tcp.RequestUsers";
	static var TCP_SERVER_RECEIVE_USERDATA  : String = "tcp.ReceiveUserData";
	static var TCP_SERVER_RECEIVE_USERS 	: String = "tcp.ReceiveUsers";
	static var TCP_SERVER_RECEIVE_MESSAGE 	: String = "tcp.ReceiveMessage";
	static var RTC_SERVER_KEY				: String = "067hpsf5ed841jor";
	static var RTC_STREAM_RATE				: Float  = 0.025;
	
	static private var m_on_users : Array<ClientUser> -> Void;
			
	/**
	 * 
	 */
	public var me(get_me, never):ClientUser;
	private function get_me():ClientUser { return cast m_me; }
	private var m_me:ClientUser;
	
	/**
	 * 
	 */
	public var users(get_users, never) : Array<ClientUser>;
	private function get_users():Array<ClientUser> { return m_users.copy(); }
	private var m_users : Array<ClientUser>;
	
	/**
	 * 
	 */
	public var count(get_count, never):Int;
	private function get_count():Int { return m_users.length; }
		
	/**
	 * 
	 */
	public var connected(get_connected, never):Bool;	
	private function get_connected():Bool { return m_me != null; }	
	
	private var m_tcp : WebSocket;	
	
	private var m_debug : Bool;
	
	private var m_first_users:Bool;
	
	private var m_rtc : Dynamic;
	
	private var m_connection : Map<String,Dynamic>;
	
	private var m_clock : Float;
	
	private var m_buffer : Array<Dynamic>;
	
	/**
	 * 
	 * @param	p_tcp_host
	 * @param	p_tcp_port
	 * @param	p_rtc_host
	 * @param	p_rtc_port
	 * @param	p_debug
	 */
	public function Connect(p_tcp_host:String, p_tcp_port : Int,p_rtc_host:String="", p_rtc_port:Int=0, p_debug : Bool = false) : Void
	{
		m_debug 	 = p_debug;
		m_users 	 = [];
		m_buffer     = [];
		m_connection = new Map<String,Dynamic>();
		m_clock = 0;
		try
		{
			if (m_debug) OnDebug("Network.TCP> Connecting TCP [" + p_tcp_host + ":" + p_tcp_port + "]");
			if (m_debug) if(p_rtc_port > 0) OnDebug("Network.TCP> RTC Host [" + p_rtc_host + ":" + p_rtc_port + "]");
			m_tcp = new WebSocket(p_tcp_host+":"+p_tcp_port);		
			m_tcp.onopen  = function(e : Dynamic):Void 
			{
				if (m_debug) OnDebug("Network.TCP> Connection Open [" + p_tcp_host + ":" + p_tcp_port + "]");				
				m_first_users = true;
				OnOpen(); 				
			};			
			
			m_tcp.onclose   = function(e : Dynamic):Void 
			{
				m_me = null;
				if (m_debug) OnDebug("Network.TCP> Connection Closed [" + p_tcp_host + ":" + p_tcp_port + "]");				
				OnClose(); 
			};
			
			m_tcp.onmessage = function(e : Dynamic):Void 
			{
				//if (m_debug) OnDebug("Network.TCP> Message [" + e.data + "]");
				var usr : ClientUser;
				var d : Dynamic = JSON.FromJSON(e.data);								
				if (d == null) d = e.data;
				
				if (d != null)
				{
					if (d.type != null)
					{
						var mt : String = d.type;
						if (mt.indexOf("tcp") >= 0)
						{						
							switch(mt)
							{
								case "tcp.ReceiveUserData": 
									m_me = OnCreateUser(d.user); 
									if (m_debug) OnDebug("Network.TCP> Connect uid[" + m_me.id + "]");
									SetupRTC();
									OnConnect();	
									
								case "tcp.ReceiveMessage":
									usr = FindUser(d.user.id);
									if (m_debug) OnDebug("Network.TCP> TextMessage uid[" + (usr == null ? "undefined" : usr.id) + "][" + d.message + "]");
									OnUserMessage(usr, d.message);
									
								case "tcp.ReceiveUsers":
									if (m_me != null)
									{										
										var res:Array<ClientUser> = [];
										var ul : Array<Dynamic> = d.list;
										for (it in ul)
										{											
											if (it.id == m_me.id) continue;
											var usr : ClientUser = OnCreateUser(it);											
											res.push(usr);
										}
										var old : Array<ClientUser> = m_users;
										m_users = res;
										
										for (i in 0...m_users.length)
										{
											var found : Bool = false;
											for (j in 0...old.length)
											{												
												if (old[j].id == m_users[i].id) { found = true; break; }
											}
											if (!found)
											{												
												if (!m_first_users)
												{
													if (m_debug) OnDebug("Network.TCP> User Enter uid[" + m_users[i].id+"]");
													OnUserEnter(m_users[i]);
												}
											}
										}
																			
										for (i in 0...old.length)
										{
											var found : Bool = false;
											for (j in 0...m_users.length) if (m_users[j].id == old[i].id) { found = true; break; }
											if (!found)
											{												
												if (!m_first_users)
												{
													if (m_debug) OnDebug("Network.TCP> User Leave uid[" + old[i].id+"]");
													OnUserLeave(old[i]);
												}
											}
										}
										UpdateRTC();
										OnUsersListUpdate();
										if (m_on_users != null) { m_on_users(m_users); m_on_users = null; }
										m_first_users = false;
									}
									else
									{
										Console.LogError("Network.TCP> Receiving user list without 'Me' data.");
									}
							}
							return;
						}
					}					
				}
				OnData(e.data);	
			};
		}
		catch (err : Dynamic)
		{
			m_me = null;
			OnError(err);
			OnDebug("Network.TCP> Error: " + err);
		}
	
		Browser.window.onpagehide = Browser.window.onunload = Browser.window.onbeforeunload = function(e:Dynamic):Void
		{			
			Close();
		};		
		
		
	}
	
	public function Close():Void
	{
		m_me = null;
		if(m_tcp != null) m_tcp.close();
	}
	
	public function Send(p_data : Dynamic):Void
	{
		if (!connected) return;
		if (Std.is(p_data, String))
		{
			var s :String = cast p_data;
			m_tcp.send(s);
		}
		else
		if (Std.is(p_data, ArrayBuffer))
		{
			var a : ArrayBuffer = cast p_data;
			m_tcp.send(a);
		}
		else
		if (Std.is(p_data, ByteArray))
		{
			var a : ByteArray = cast p_data;
			m_tcp.send(a.data);
		}
		else
		{
			var d :String = JSON.ToJSON(p_data);			
			if (m_debug) OnDebug("Network.TCP> Send JSON("+d+")");
			m_tcp.send(d);
		}		
	}
	
	public function FindUser(p_id:String) 
	{
		if (m_me.id == p_id) return me;
		for (i in 0...m_users.length) if (m_users[i].id == p_id) return m_users[i]; return null; 
	}
	
	public function SendMessage(p_data : String):Void
	{
		var msg : Dynamic = { type: TCP_SERVER_SEND_MESSAGE, message: p_data };
		Send(msg);
	}
	
	public function RequestUsers(p_callback : Array<ClientUser> -> Void):Void
	{
		m_on_users = p_callback;
		ServerRequestUsers();
	}
	
	private function ServerRequestUserData():Void  { Send({type:TCP_SERVER_REQUEST_USERDATA }); }
	
	private function ServerRequestUsers():Void 	{ Send({type: TCP_SERVER_REQUEST_USERS });	}
	
	private function OnCreateUser(p_user : Dynamic):ClientUser { return new ClientUser(p_user.id);  }
	
	private function OnUsersListUpdate():Void { }
	
	private function OnUserEnter(p_user : ClientUser) : Void { }
	
	private function OnUserLeave(p_user : ClientUser) : Void { }
	
	private function OnConnect() : Void { }
	
	private function OnOpen() : Void { }
	
	private function OnClose() : Void { }
	
	private function OnError(p_msg : String):Void { trace(p_msg); }
	
	private function OnDebug(p_msg : String):Void { trace(p_msg); }
	
	private function OnUserMessage(p_user : ClientUser,p_msg : String):Void { }
	
	private function OnData(p_data:String) : Void 
	{
		
	}
	
	private function IsRTCConnected(p_id:String):Bool
	{
		if (!m_connection.exists(p_id)) 
		{
			//Console.LogWarning("Network.RTC> Peer " + p_id + " is not linked."); 
			return false; 
		}
		return m_connection.get(p_id).connected;
	}
	
	private function UpdateRTC():Void
	{
		for (i in 0...m_users.length)
		{
			var u : ClientUser = m_users[i];
			if (u.id == m_me.id) continue;
			PeerConnect(u.id);
		}
	}
	
	private function PeerConnect(p_user : String):Void
	{
		var u : String = p_user;
		if (m_connection.exists(u)) return;
		if (IsRTCConnected(u)) return;		
		if (m_debug) trace("Network.RTC> Creating Link [" + me.id + "] -> [" + u + "]");
		
		var conn :Dynamic = m_rtc.connect(u);
		
		var timeout : Timer =
		Timer.delay(function():Void
		{
			if (conn.connected) return;
			if (m_debug) trace("Network.RTC> Link [" + me.id + "] -> [" + u + "] Timeout");
			if(m_connection.exists(u)) m_connection.remove(u);
			PeerConnect(p_user);
		},Std.int(1000 + (Math.random() * 1000)));
		
		
		conn.connected = false;
		conn.on("open", function():Void
		{
			if (m_debug) trace("Network.RTC> Link ["+me.id+"] -> [" + u + "] OPEN peer["+conn.peer+"]");
			conn.connected = true;				
			timeout.stop();
		});
		
		conn.on("close", function():Void
		{
			if (m_debug) trace("Network.RTC> Link ["+me.id+"] -> [" + u + "] CLOSE");
			conn.connected = false;
		});		
		
		m_connection.set(u, conn);
		
		
	}
	
	/**
	 * 
	 * @param	p_data
	 */
	public function Write(p_label:String,p_data : Dynamic):Void
	{
		if ((Time.elapsed - m_clock) >= RTC_STREAM_RATE) 
		{ 
			var d : Dynamic  = { label: p_label, data:p_data };
			m_buffer.push(d);			
		}		
	}
	
	
	public function Sync():Void
	{	
		if ((Time.elapsed - m_clock) >= RTC_STREAM_RATE) m_clock = Time.elapsed;
		if (m_buffer.length > 0)
		{			
			for (i in 0...m_users.length)
			{
				var u : ClientUser = m_users[i];
				if (u.id == m_me.id) continue;
				if (!IsRTCConnected(u.id)) { continue;	}				
				var conn :Dynamic = m_connection.get(u.id);
				conn.send(m_buffer);
			}			
			m_buffer = [];
		}
	}
		
	private function SetupRTC():Void
	{
		if (m_me == null)
		{
			OnError("Network.TCP> Could not create RTC peer.");
			return;
		}
		var p 	: Dynamic=null;		
		var debug_level:String = m_debug ? "0" : "0";
		var id	: String = m_me.id;				
		var skey : String = RTC_SERVER_KEY;
		untyped __js__ ("p = new Peer(id,{ key: skey, debug: debug_level})");
		m_rtc = p;
		if (m_debug) trace("Network.RTC> Created Client RTC id[" + id + "] key["+RTC_SERVER_KEY+"]");		
		
		m_rtc.on("open", function(p_id:String):Void
		{
			if (m_debug) trace("Network.RTC> Open [" + p_id + "]");
			UpdateRTC();
		});	
		
		m_rtc.on("connection", function(p_connection:Dynamic):Void
		{
			if (m_debug) trace("Network.RTC> Connection Received [" + p_connection.peer + "]"); 
			var uid : String = p_connection.peer;
			
			PeerConnect(uid);
			
			p_connection.on("data", function(p_data:Dynamic):Void
			{
				//trace("Network> Receiving from [" + p_connection.peer+"]");
				//if (m_debug) trace("Network.RTC> Peer Data [" + p_data + "]"); 
				OnRTCData(uid, p_data);
			});
		});
	}
	
	private function OnRTCData(p_id:String, p_data:Dynamic):Void
	{	
		var d : Dynamic = p_data;		
		
		//if(m_debug) trace("Network.RTC> Data from [" + p_id + "] Label[" + d.label + "] Data[" + d + "]");
		
		for (i in 0...m_users.length)
		{
			var u : ClientUser = m_users[i];
			if (u.id == m_me.id) continue;
			if (u.id != p_id) continue;
			u.Sync(p_data);
			break;
		}				
		
	}
	
}