/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui.form;
import js.html.CanvasElement;
import js.html.ImageElement;
import haxor.ui.Container;
import haxor.ui.Sprite;
import haxor.ui.UISkin.ImageSkin;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class FormComponent extends Container
{
	
	public var state(get_state, set_state):String;
	private function get_state():String { return m_state; }
	private function set_state(v:String):String 
	{
		var s0 : String = m_state;
		var s1 : String = v;
		m_state = v;
		OnStateChange(s0, s1);
		return m_state; 
	}
	private var m_state : String;
	private var m_table : Map<String,Dynamic>;
	
	public function new(p_use_canvas : Bool=true) 
	{
		m_table = new Map<String,Dynamic>();
		m_state = "";
		super();
		
	}
	
	private function OnStateChange(p_from : String,p_to:String):Void { }

	private function GetState(p_state : String):Dynamic { if (m_table.exists(p_state)) return m_table.get(p_state); return null; }
	
	private function HasState(p_state : String):Bool { return m_table.exists(p_state); } 
	
	private function AddState(p_state : String, p_asset : Dynamic):Void
	{		
		m_table.remove(p_state);
		if (p_asset == null) 	return;
		if (p_state == "") 		return;
		if (m_table == null) 	return;
		m_table.set(p_state, p_asset);
	}
	
	private function ClearStates():Void
	{
		m_table = new Map<String,Dynamic>();
	}
	
}