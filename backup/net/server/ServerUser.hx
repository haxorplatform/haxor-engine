/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net.server;
import haxe.Json;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ServerUser
{
	
	private var m_socket : Dynamic;
	
	public var id(get_id, never):String;
	private function get_id():String { return m_id; }
	private var m_id : String;
	
	public var closed(get_closed, never):Bool;
	private function get_closed():Bool { return m_socket == null; }
	
	
	public var data(get_data, never):Dynamic;
	private function get_data():Dynamic	 
	{
		var d:Dynamic = { };
		d.id = id;
		return d;
	}
	
	public function new(p_id : String,p_socket:Dynamic) 
	{
		m_id = p_id;
		m_socket = p_socket;
	}
	
	public function Close():Void
	{
		m_socket = null;
	}
	
	public function Send(p_data:Dynamic):Void
	{
		if (m_socket == null) return;
		var d :String = "null";
		
		if (Std.is(p_data, String)) d = p_data;		
		else
		{
			try
			{
				d = Json.stringify(p_data);
			}
			catch (err : Dynamic)
			{
				d = p_data + "";
			}
		}
		//m_socket.emit("message",d);
		m_socket.send(d);
	}
	
	public function Broadcast(p_data:Dynamic):Void
	{
		if (m_socket == null) return;
		var d :String ;
		if (Std.is(p_data, String)) d = p_data;		
		else 						d = Json.stringify(p_data);
		m_socket.broadcast.send("message", d);
	}
	
}