/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net.server;
import haxe.Json;
import haxe.macro.Expr.Binop;
import js.html.EventListener;
import js.html.EventTarget;
import nodejs.NodeJS;
import haxor.core.JSON;

/**
 * Class that describes a TCPServer that will run on a nodejs context.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TCPServer
{
	static private var m_ids : Int = 0;
	
	/**
	 * 
	 */
	public var port(get_port, never):Int;
	private function get_port():Int { return m_port; }
	private var m_port : Int;
	
	/**
	 * 
	 */
	public var users(get_users, never) : Array<ServerUser>;
	private function get_users():Array<ServerUser> { return m_users.copy(); }	
	private var m_users : Array<ServerUser>;
	private function GetUserDataList():Array<Dynamic> { var res:Array<Dynamic> = []; for (i in 0...m_users.length) res.push(m_users[i].data); return res; }
	
	/**
	 * 
	 */
	public var count(get_count, never):Int;
	private function get_count():Int { return m_users.length; }
		
	private var _s : Dynamic;
	
	private var _io : Dynamic;
	
	private var m_debug : Bool;

	/**
	 * 
	 * @param	p_port
	 * @param	p_debug
	 */
	public function new(p_port : Int,p_debug:Bool=false) 
	{		
		m_debug = p_debug;
		m_port  = p_port;
		m_users = [];
		_io = NodeJS.require("websocket.io");
		_s  = _io.listen(p_port);						
		_s.on("connection", InternalOnUserConnect);				
		trace("TCP> Running @ "+port);
	}
	
	/**
	 * 
	 * @param	p_id
	 * @return
	 */
	public function FindUser(p_id : String):ServerUser
	{
		for (i in 0...m_users.length) if (m_users[i].id == p_id) return m_users[i];
		return null;
	}
	
	/**
	 * 
	 * @param	p_data
	 * @param	p_include_user
	 */
	public function Broadcast(p_data : Dynamic,p_include_user:Bool=true):Void
	{
		for (i in 0...m_users.length) m_users[i].Send(p_data);
	}
	
	function InternalOnUserConnect(p_socket : Dynamic):Void
	{
		p_socket.id = (m_ids++) + "";
		if (m_debug) OnLog("TCPServer> Connect uid[" + p_socket.id + "]");		
		
		p_socket.on("close", function() 
		{			
			var usr : ServerUser = FindUser(p_socket.id);
			if (usr != null)
			{
				if (m_debug) OnLog("TCPServer> Close uid[" + usr.id + "]");
				usr.Close();	
				m_users.remove(usr);
				UpdateAllUserLists();
				OnUserDisconnect(usr);
			}
			else
			{
				OnLog("TCPServer> Error: undefined user closed!");
			}			
		});
		
		p_socket.on("message", function(msg : Dynamic,cb : Dynamic) 
		{
			var usr : ServerUser = FindUser(p_socket.id);
			if (usr != null)
			{
				if (m_debug) OnLog("TCPServer> Message uid[" + usr.id + "] ["+msg+"]");
				var d : Dynamic = { };
				d = JSON.FromJSON(msg);
				if (d == "") d = msg;
				OnUserMessage(usr, d);
			}
			else
			{
				OnLog("TCPServer> Error: undefined user sent message!");
			}			
		});
		
		p_socket.on("error", function(err : Dynamic) 
		{			
			OnError(err);			
		});
		
		var usr : ServerUser = OnCreateUser(p_socket);		
		var d : Dynamic = JSON.ToJSON( { type: "tcp.ReceiveUserData", user: usr.data } );
		OnLog("TCPServer> tcp.ReceiveUserData["+d+"]");
		usr.Send(d);		
		m_users.push(usr);
		OnUserConnect(usr);
		UpdateAllUserLists();
	}
	
	/**
	 * 
	 * @param	p_error
	 */
	private function OnError(p_error:Dynamic):Void
	{
		trace(p_error);
	}
	
	/**
	 * 
	 * @param	p_socket
	 * @return
	 */
	private function OnCreateUser(p_socket : Dynamic):ServerUser
	{
		return new ServerUser(p_socket.id,p_socket);
	}
	
	/**
	 * 
	 * @param	p_msg
	 */
	private function OnLog(p_msg : String):Void
	{
		trace(p_msg);
	}
	
	/**
	 * 
	 * @param	p_user
	 */
	private function OnUserConnect(p_user : ServerUser):Void 
	{
		
	}
	
	/**
	 * 
	 * @param	p_user
	 */
	private function OnUserDisconnect(p_user : ServerUser):Void 
	{
		
	}
	
	/**
	 * 
	 */
	private function UpdateAllUserLists():Void
	{
		var l :Array<Dynamic> = GetUserDataList();
		for (i in 0...m_users.length) UpdateUserList(m_users[i],l);
	}
	
	/**
	 * 
	 * @param	p_user
	 * @param	p_list
	 */
	private function UpdateUserList(p_user:ServerUser,p_list:Array<Dynamic>):Void
	{
		if (p_user.closed) return;
		var d:Dynamic = { type: "tcp.ReceiveUsers", list: p_list };
		p_user.Send(d);
	}
	
	/**
	 * 
	 * @param	p_user
	 * @param	p_data
	 */
	private function OnUserMessage(p_user:ServerUser, p_data:Dynamic):Void
	{
		var d : Dynamic;
		switch(p_data.type)
		{
			case "tcp.RequestUsers": 
				OnLog("TCPServer> tcp.ReceiveUsers");
				UpdateUserList(p_user, GetUserDataList());
				return;
				
			case "tcp.SendMessage":				
				OnLog("TCPServer> tcp.ReceiveMessage");
				Broadcast( { type: "tcp.ReceiveMessage", user: p_user.data, message: p_data.message }, true);
				return;
				
			default:				
				OnLog("TCPServer> " + p_data.type);
				Broadcast( { type: p_data.type, user: p_user.data, data: p_data.data }, true);
		}
	}
	
}