/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net.client;
import js.html.ArrayBuffer;
import js.html.Blob;
import js.html.Float32Array;
import js.html.Uint8Array;
import haxor.core.ByteArray;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class ClientUser
{
	
	public var id(get_id, never):String;
	private function get_id():String { return m_id; }
	private var m_id : String;
	
	private var m_sync : Map<String,Dynamic>;
	
	/**
	 * 
	 * @param	p_id
	 */
	public function new(p_id : String) 
	{
		m_id = p_id;
		m_sync = new Map<String,Dynamic>();
	}
	
	/**
	 * 
	 * @param	p_data
	 */
	private function Sync(p_data : Dynamic):Void
	{				
		var l : Dynamic = p_data;		
		if (l == null) return;
		if (l.length == null) return;	
		//trace("Received> " + l.length);
		for (i in 0...l.length)
		{
			var d : Dynamic = l[i].data;
			if (Std.is(d, ArrayBuffer))
			{
				var a : Uint8Array = new Uint8Array(cast d);
				var ba : ByteArray = new ByteArray(1);
				ba.data = a;
				d = ba;
			}		
			//trace("\t" + l[i].label+" "+d);
			m_sync.set(l[i].label, d);
		}			
		//trace(" ");
	}
	
	/**
	 * 
	 * @param	p_label
	 * @param	p_clear
	 * @return
	 */
	public function Sample(p_label:String,p_clear :Bool = false):Dynamic
	{
		if (!m_sync.exists(p_label)) return null;
		var d : Dynamic = m_sync.get(p_label);
		if(p_clear) m_sync.set(p_label, null);
		return d;
	}
	
}