/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.thread;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Thread
{
	
	static public var available(get_available, never):Bool;
	static private function get_available():Bool 
	{ 
		return untyped __js__("typeof(Worker)!=='undefined'"); 
	}
	
	
	public var thread : Dynamic;

	public var onmessage(get_onmessage, set_onmessage) : Dynamic -> Void;
	private function get_onmessage() : Dynamic -> Void { return m_onmessage; }
	private function set_onmessage(v : Dynamic -> Void) : Dynamic -> Void { m_onmessage = v; return v; }
	private var m_onmessage : Dynamic -> Void;
	
	public function new(p_script : String) 
	{		
		var w : Dynamic = null;
		var otm : Dynamic = InternalOnThreadMessage;
		untyped __js__ ("w = new Worker(p_script)");		
		untyped __js__ ("w.onmessage = otm;");
		thread = w;
	}	
	
	public function send(p_data :Dynamic, p_transfer : Bool = false):Void
	{
		if(p_transfer) thread.postMessage(p_data,[p_data]); else thread.postMessage(p_data);
	}
	
	private function OnThreadMessage(p_event : Dynamic):Void
	{
		
	}
	
	private function InternalOnThreadMessage(p_event : Dynamic):Void 
	{
		OnThreadMessage(p_event);
		if (m_onmessage != null) m_onmessage(p_event);		
	}
	
}