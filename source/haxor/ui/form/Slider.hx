/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui.form;
import js.Browser;
import js.html.Element;
import js.html.Event;
import js.html.MouseEvent;
import haxor.core.Engine;
import haxor.core.IUpdateable;
import haxor.core.Tween;
import haxor.math.Easing;
import haxor.math.Mathf;
import haxor.ui.Sprite;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Slider extends FormComponent implements IUpdateable
{
	
	override private function set_skin(v:String):String 
	{		
		super.set_skin(v);
		m_track.skin   = v + ".track";
		m_drag.skin    = v + ".drag";
		m_fill.skin    = v + ".fill";		
		m_buffer.skin  = v + ".buffer";			
		return v;
	}

	public var ratio(get_ratio, set_ratio):Float;
	private function get_ratio():Float 
	{
		var dw : Float = width - m_drag.width;		
		return dw <= 0 ? 0 : (m_drag.x / dw);
	}
	
	private function set_ratio(v:Float):Float
	{
		var dw : Float = width - m_drag.width;		
		if (smooth <= 0)
		{
			m_drag.x = dw * Mathf.Clamp01(v);
			m_fill.layout.width = Mathf.Clamp01(v+0.01);		
		}
		else
		{			
			Tween.Cancel(m_drag);
			Tween.Cancel(m_fill);
			Tween.Add(m_drag, "x", dw * Mathf.Clamp01(v), smooth, 0, Cubic.Out);
			Tween.Add(m_fill.layout, "width", Mathf.Clamp01(v+0.01), smooth, 0, Cubic.Out);
		}
		return v;
	}
	
	
	public var buffer(get_buffer, set_buffer):Float;
	private function get_buffer():Float 		{ return m_buffer.layout.width; }
	private function set_buffer(v:Float):Float	{ m_buffer.layout.width = v;  return v;  }
	
	public var smooth : Float;
	
	public var onchange : Float -> Void;
	
	private var m_track : Button;
	
	private var m_buffer : Sprite;
	
	private var m_fill : Sprite;
	
	private var m_drag : Button;
	
	private var m_isdrag : Bool;
	
	private var m_lastratio : Float;
	
	public function new(p_use_canvas : Bool=true) 
	{
		m_skin = "slider";
		
		m_track  = new Button(p_use_canvas);
		m_drag   = new Button(p_use_canvas);
		m_fill   = new Sprite(p_use_canvas);
		m_buffer = new Sprite(p_use_canvas);
		
		super(true);
		
		smooth = 0;
		
		m_isdrag = false;
		
		m_track.name  = "track";
		m_drag.name   = "drag";
		m_fill.name   = "fill";
		m_buffer.name = "buffer";
		
		m_track.layout.FitSize();
		m_drag.layout.FitHeight();
		m_fill.layout.FitSize();
		m_buffer.layout.FitSize();
		
		m_buffer.layout.width = 0;
		
		m_lastratio = m_drag.x = 0;
		m_drag.width = 11;
		
		m_fill.mouseEnabled = false;
		m_buffer.mouseEnabled = false;
		
		AddChild(m_track);
		AddChild(m_buffer);
		AddChild(m_fill);
		AddChild(m_drag);
		
		m_track.element.addEventListener("mousedown", OnMouse);
		m_drag.element.addEventListener("mousedown", OnMouse);
		Browser.document.addEventListener("mouseup", OnMouse);
		m_track.element.addEventListener("mouseup", OnMouse);
		m_drag.element.addEventListener("mouseup", OnMouse);
	}
	
	private function OnMouse(p_event : MouseEvent):Void
	{
		var e : Element = cast p_event.target;
		if (p_event.type == "mouseup")
		{
			if(m_isdrag)Engine.Remove(this);
			m_isdrag = false;
			return;
		}
				
		if (e.parentElement == m_track.element)
		{			
			ratio = width <= 0 ? 0 : (p_event.offsetX / width);
		}
		else
		if (e.parentElement == m_drag.element)
		{			
			if(!m_isdrag)Engine.Add(this);
			m_isdrag = true;
			m_lastratio = Mathf.Clamp01(mouseX / width);
		}
	}
	
	public function OnUpdate():Void
	{
		if (m_isdrag)
		{
			var r : Float = Mathf.Clamp01(mouseX / width);			
			if (Mathf.Abs(m_lastratio - r) > 0.01)
			{
				m_lastratio = r;
				ratio = r;
			}
		}
	}
	
	override private function UpdateRect():Void 
	{
		var r : Float = ratio;
		
		super.UpdateRect();
		
		var dw : Float = width - m_drag.width;
		m_drag.x = dw * Mathf.Clamp01(r);
		m_fill.layout.width = Mathf.Clamp01(r);
		
	}
	
}