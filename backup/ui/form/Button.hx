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
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.Event;
import js.html.Image;
import js.html.ImageElement;
import js.html.InputElement;
import js.html.SpanElement;
import js.html.TextMetrics;
import haxor.core.Console;
import haxor.core.Tween;
import haxor.math.Color;
import haxor.math.Easing;
import haxor.math.Mathf;
import haxor.ui.Container;
import haxor.ui.LayoutFlag;
import haxor.ui.Sprite;
import haxor.ui.TextField;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Button extends FormComponent
{
	
	override private function set_name(v:String):String 
	{
		super.set_name(v);
		if(m_input != null) m_input.setAttribute("name", v);
		return v;
	}
	
	override private function set_skin(v:String):String 
	{
		if (m_label != null) m_label.skin = v + ".label";		
		super.set_skin(v);
		return v;
	}
	
	public var label(get_label, never):TextField;
	private function get_label():TextField 
	{
		if (m_label != null) m_label;
		m_label = new TextField();
		m_label.layout.flag = LayoutFlag.SizeXY;
		m_label.layout.width = m_label.layout.height = 1;
		m_label.aligment = TextAligment.MiddleCenter;
		m_label.element.style.cursor = "pointer";		
		AddChild(m_label);
		m_label.skin = m_skin + ".label";
		return m_label; 
	}	
	private var m_label : TextField;
	
	public var input(get_input, never):InputElement;
	private function get_input():InputElement { return cast m_input; }
	private var m_input : InputElement;
	
	public var smooth : Float;
	
	private var m_a0 : Sprite;
	private var m_a1 : Sprite;
	private var m_a  : Sprite;
	
	public function new(p_use_canvas:Bool=true) 
	{	
		if (m_skin == null) m_skin = "button";
		
		m_a0 = new Sprite(p_use_canvas);
		m_a0.name = "back";
		m_a0.layout.width  = 
		m_a0.layout.height = 1.0;
		m_a0.layout.flag   = LayoutFlag.SizeXY;
		
		m_a1 = new Sprite(p_use_canvas);
		m_a1.name = "front";
		m_a1.layout.width  = 
		m_a1.layout.height = 1.0;
		m_a1.layout.flag   = LayoutFlag.SizeXY;
				
		m_a = m_a1;
		m_a0.alpha = -0.1;
		
		smooth = 0;
		
		m_input = Browser.window.document.createInputElement();
		m_input.style.background = "none";
		m_input.style.border = "none";		
		m_input.style.outline = "none";
		m_input.style.position = "absolute";
		m_input.style.width  = 
		m_input.style.height = "100%";
		m_input.style.margin = "0px";
		m_input.style.cursor = "pointer";
		m_input.type = "button";		
		
		
		super(p_use_canvas);
		
		AddChild(m_a0);
		AddChild(m_a1);
		
		m_element.appendChild(m_input);	
		element.onmousedown = OnMouse;
		element.onmouseout  = OnMouse;
		element.onmouseover = OnMouse;
		element.onmouseup   = OnMouse;
		
	}
	
	private function OnMouse(p_event : Event):Void
	{
		switch(p_event.type)
		{
			case "mouseover" : state = HasState("over") ? "over" : "none";
			case "mouseout"  : state = "none";
			case "mousedown" : state = HasState("down") ? "down" : "none";
			case "mouseup"   : state = HasState("over") ? "over" : "none";
		}		
	}
	
	override private function OnStateChange(p_from:String, p_to:String):Void 
	{
		var s : Dynamic = GetState(p_to);
		
		if (m_a == m_a1) { m_a0.alpha = -0.1; m_a1.alpha = 1.0; }
		if (m_a == m_a0) { m_a1.alpha = -0.1; m_a0.alpha = 1.0; }
		
		SetChildIndex(m_a, 0);
		Tween.Add(m_a, "alpha", -0.001, smooth, 0, Cubic.In);
		
		m_a = (m_a1 == m_a) ? m_a0 : m_a1;
		
		if (s == null) 
		{ 
			m_a.image = null; 			
			return; 
		}
		else
		if (Std.is(s, ImageElement)) 
		{ 
			m_a.image = cast s; 
		}
		else
		if (Std.is(s, ImageSkin))
		{ 			
			var iskn : ImageSkin = cast s;
			m_a.image  = iskn.image;
			m_a.slices = iskn.slices;			
		}
		
		Tween.Add(m_a, "alpha", 1, smooth, 0, Cubic.Out);		
		
	}
	
	override public function OnSkinChange(p_skin:UISkin):Void 
	{
		var st : String;		
		var bs : BaseSkin = p_skin.Get(m_skin);
		
		if (bs != null)
		{
			if (bs.xml.exists("smooth")) smooth = Std.parseFloat(bs.xml.get("smooth"));			
		}
		else
		{
			smooth = 0;
		}
		
		st = m_skin + ".none"; AddState("none", p_skin.Get(st));
		st = m_skin + ".over"; AddState("over", p_skin.Get(st));
		st = m_skin + ".down"; AddState("down", p_skin.Get(st));
		var smt : Float = smooth;
		smooth = 0;
		state = "none";
		smooth = smt;
	}
	
}