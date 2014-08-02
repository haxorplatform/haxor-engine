/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui.form;
import js.Browser;
import js.html.ButtonElement;
import js.html.Event;
import js.html.InputElement;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Toggle extends Button
{	
	public var toggle(get_toggle, set_toggle):Bool;
	private function get_toggle():Bool { return m_input.checked; }
	private function set_toggle(v:Bool):Bool 
	{ 
		if (m_input.checked == v) return v;
		m_input.checked = v; 		
		state = state;
		return v; 
	}
	
	public function new() 
	{	
		if(m_skin==null) m_skin = "toggle";		
		super();		
		m_input.checked = false;
		element.onclick = OnMouse;		
	}
	
	override private function OnMouse(p_event:Event):Void 
	{
		var t : String = toggle ? "toggle_": "";
		
		switch(p_event.type)
		{
			case "mouseover" : state = HasState(t+"over") ? t+"over" : t+"none";
			case "mouseout"  : state = t+"none";
			case "mousedown" : state = HasState(t+"down") ? t+"down" : t+"none";
			case "mouseup"   : state = HasState(t+"over") ? t+"over" : t+"none";
			case "click"	 : toggle = !toggle;
		}
	}
	
	override private function OnStateChange(p_from:String, p_to:String):Void 
	{
		var s :String = p_to;
		if (s.indexOf("toggle_") >= 0) s = s.split("_")[1];
		s = toggle ? "toggle_" + s : s;		
		super.OnStateChange(p_from, s);
	}
	
	override public function OnSkinChange(p_skin:UISkin):Void 
	{
		var st : String;				
		st = m_skin + ".toggle_none"; AddState("toggle_none", p_skin.Get(st));
		st = m_skin + ".toggle_over"; AddState("toggle_over", p_skin.Get(st));
		st = m_skin + ".toggle_down"; AddState("toggle_down", p_skin.Get(st));
		
		super.OnSkinChange(p_skin);
	}
}