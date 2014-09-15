/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import haxor.core.Application;
import haxor.ui.component.UIComponent;
import js.Browser;
import js.html.BodyElement;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.DivElement;
import js.html.Element;
import js.html.Image;
import js.html.ImageElement;
import haxor.core.Resource;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.ui.UISkin;

@:allow(haxor)
class StrokeFilter
{
	private var m_filter : UIFilter;
	
	public var width(get_width, set_width):Int;
	private function get_width():Int { return m_width; }
	private function set_width(v:Int):Int { m_width = v; m_filter.Update();  return v; }
	private var m_width : Int;
	
	public var color(get_color, set_color):Color;
	private function get_color():Color { return m_color.clone; }
	private function set_color(v:Color):Color { m_color = v.clone; m_filter.Update();  return v; }
	private var m_color:Color;
	
	private function new(p_filter : UIFilter)
	{
		m_filter = p_filter;
		m_width = 0;
		m_color = Color.black;
	}
	
}

@:allow(haxor)
class ShadowFilter
{
	private var m_filter : UIFilter;
	
	public var x(get_x, set_x):Int;
	private function get_x():Int { return m_x; }
	private function set_x(v:Int):Int { m_x = v; m_filter.Update();  return v; }
	private var m_x : Int;
	
	public var y(get_y, set_y):Int;
	private function get_y():Int { return m_y; }
	private function set_y(v:Int):Int { m_y = v; m_filter.Update();  return v; }
	private var m_y : Int;
	
	public var blur(get_blur, set_blur):Int;
	private function get_blur():Int { return m_blur; }
	private function set_blur(v:Int):Int { m_blur = v; m_filter.Update();  return v; }
	private var m_blur : Int;
	
	public var color(get_color, set_color):Color;
	private function get_color():Color { return m_color.clone; }
	private function set_color(v:Color):Color { m_color = v.clone; m_filter.Update();  return v; }
	private var m_color:Color;
	
	private function new(p_filter : UIFilter)
	{
		m_filter = p_filter;
		m_x = 0;
		m_y = 0;
		m_blur = 0;
		m_color = Color.black;
	}
}

@:allow(haxor)
class UIFilter
{
	public var target : Element;
	
	public var blur(get_blur, set_blur):Int;
	private function get_blur():Int { return m_blur; }
	private function set_blur(v:Int):Int { m_blur = v; Update(); return v; }
	private var m_blur : Int;
	
	public var hue(get_hue, set_hue):Int;
	private function get_hue():Int { return m_hue; }
	private function set_hue(v:Int):Int { m_hue = v; Update(); return v; }
	private var m_hue : Int;
	
	public var shadow(get_shadow, never):ShadowFilter;
	private function get_shadow():ShadowFilter { return m_shadow; }
	private var m_shadow : ShadowFilter;
	
	public var textShadow(get_textShadow, never):ShadowFilter;
	private function get_textShadow():ShadowFilter { return m_textShadow; }
	private var m_textShadow : ShadowFilter;
	
	public var textStroke(get_textStroke, never):StrokeFilter;
	private function get_textStroke():StrokeFilter { return m_textStroke; }
	private var m_textStroke : StrokeFilter;
	
	public var boxShadow(get_boxShadow, never):ShadowFilter;
	private function get_boxShadow():ShadowFilter { return m_boxShadow; }
	private var m_boxShadow : ShadowFilter;
	
	public var sepia(get_sepia, set_sepia):Float;
	private function get_sepia():Float { return m_sepia; }
	private function set_sepia(v:Float):Float { m_sepia = v; Update(); return v; }
	private var m_sepia : Float;
	
	public var grayscale(get_grayscale, set_grayscale):Float;
	private function get_grayscale():Float { return m_grayscale; }
	private function set_grayscale(v:Float):Float { m_grayscale = v; Update(); return v; }
	private var m_grayscale : Float;
	
	public var brightness(get_brightness, set_brightness):Float;
	private function get_brightness():Float { return m_brightness; }
	private function set_brightness(v:Float):Float { m_brightness = v; Update(); return v; }
	private var m_brightness : Float;
	
	public var contrast(get_contrast, set_contrast):Float;
	private function get_contrast():Float { return m_contrast; }
	private function set_contrast(v:Float):Float { m_contrast = v; Update(); return v; }
	private var m_contrast : Float;
	
	public var invert(get_invert, set_invert):Float;
	private function get_invert():Float { return m_invert; }
	private function set_invert(v:Float):Float { m_invert = v; Update(); return v; }
	private var m_invert : Float;
	
	public var saturate(get_saturate, set_saturate):Float;
	private function get_saturate():Float { return m_saturate; }
	private function set_saturate(v:Float):Float { m_saturate = v; Update(); return v; }
	private var m_saturate : Float;
	
	public function new(p_target : Element=null)
	{
		target = p_target;
		Reset();
	}
	
	public function Reset():Void
	{
		m_blur 		 = 0;
		m_grayscale  = 0;
		m_sepia 	 = 0;
		m_brightness = 1;
		m_contrast 	 = 1;
		m_hue        = 0;
		m_invert     = 0;
		m_saturate   = 1;
		m_shadow     = new ShadowFilter(this);
		m_textShadow = new ShadowFilter(this);
		m_boxShadow  = new ShadowFilter(this);
		m_textStroke = new StrokeFilter(this);
		Update();
	}
	
	public function Set(p_filter : UIFilter):Void
	{
		var f : UIFilter = p_filter;
		m_blur 		 = f.m_blur;
		m_grayscale  = f.m_grayscale;
		m_sepia 	 = f.m_sepia;
		m_brightness = f.m_brightness;
		m_contrast 	 = f.m_contrast;
		m_hue        = f.m_hue;
		m_invert     = f.m_invert;
		m_saturate   = f.m_saturate;
		
		var sf0 : ShadowFilter;
		var sf1 : ShadowFilter;
		
		sf0 = m_shadow; 
		sf1 = f.m_shadow;
		sf0.m_x 	= sf1.m_x;
		sf0.m_y 	= sf1.m_y;
		sf0.m_color = sf1.m_color.clone;
		sf0.m_blur  = sf1.m_blur;
		
		sf0 = m_textShadow; 
		sf1 = f.m_textShadow;
		sf0.m_x 	= sf1.m_x;
		sf0.m_y 	= sf1.m_y;
		sf0.m_color = sf1.m_color.clone;
		sf0.m_blur  = sf1.m_blur;
		
		sf0 = m_boxShadow; 
		sf1 = f.m_boxShadow;
		sf0.m_x 	= sf1.m_x;
		sf0.m_y 	= sf1.m_y;
		sf0.m_color = sf1.m_color.clone;
		sf0.m_blur  = sf1.m_blur;
		
		m_textStroke.color = f.m_textStroke.color.clone;
		m_textStroke.m_width = f.m_textStroke.m_width;
		
		Update();
	}
	
	private function Update():Void
	{
		if (target == null) return;
		var s : String = "";
		if (m_blur > 0) s += "blur(" + m_blur + "px) ";
		if (m_hue > 0) s += "hue-rotate(" + m_hue + "deg) ";
		if (Mathf.Abs(m_sepia) 		> Mathf.Epsilon) s += "sepia(" + m_sepia +") ";
		if (Mathf.Abs(m_grayscale) 		> Mathf.Epsilon) s += "grayscale(" + m_grayscale +") ";
		if (Mathf.Abs(m_brightness-1.0) > Mathf.Epsilon) s += "brightness(" + m_brightness + ") ";
		if (Mathf.Abs(m_contrast-1.0) 	> Mathf.Epsilon) s += "contrast(" + m_contrast + ") ";
		if (Mathf.Abs(m_invert) 	> Mathf.Epsilon) s += "invert(" + m_invert + ") ";
		if (Mathf.Abs(m_saturate-1.0) 	> Mathf.Epsilon) s += "saturate(" + m_saturate + ") ";
		var shd : ShadowFilter;
		var stk : StrokeFilter;
		
		shd = m_shadow;
		if ((shd.x > 0) || (shd.y > 0) || (shd.blur > 0))
		{
			s += "drop-shadow("+shd.x+"px "+shd.y+"px "+shd.blur+"px "+shd.color.css+") ";
		}
		
		if (s == "")
		{
			target.style.removeProperty("-webkit-filter");
			target.style.removeProperty("-moz-filter");
			//target.style.removeProperty("filter");
		}
		else
		{
			target.style.setProperty("-webkit-filter",s,"");
			target.style.setProperty("-moz-filter",s,"");
			//target.style.setProperty("filter",s,"");
		}
		
		shd = m_textShadow;
		if ((shd.x > 0) || (shd.y > 0) || (shd.blur > 0))
		{
			target.style.textShadow = shd.x+"px "+shd.y+"px "+shd.blur+"px " + shd.color.css;
		}
		else
		{
			target.style.textShadow = "";
		}
		
		shd = m_boxShadow;
		if ((shd.x > 0) || (shd.y > 0) || (shd.blur > 0))
		{
			target.style.boxShadow = shd.x+"px "+shd.y+"px "+shd.blur+"px " + shd.color.css;
		}
		else
		{
			target.style.boxShadow = "";
		}
		
		stk = m_textStroke;
		if (stk.width > 0)
		{
			target.style.setProperty("-webkit-text-stroke",stk.width+"px "+stk.color.css,"");
			target.style.setProperty("-moz-text-stroke",stk.width+"px "+stk.color.css,"");
		}
		else
		{
			target.style.removeProperty("-webkit-text-stroke");
			target.style.removeProperty("-moz-text-stroke");
		}
		
	}
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class UIEntity extends Resource implements ISkinnable
{
	
	override private function set_name(v:String):String { super.set_name(v); m_element.setAttribute("name", v); return v; }
	
	private var m_components:Array<UIComponent>;
	
	public var skin(get_skin, set_skin) : String;
	private function get_skin():String { return m_skin; }
	private function set_skin(v:String):String 
	{
		
		if (m_skin == null) m_skin = "";		
		if (m_skin == "") if (v != "") UISkin.Add(this);
		if (m_skin != "") if (v == "") UISkin.Remove(this);		
		m_skin = v; 				
		if (v != "")
		{			 
			if (UISkin.current != null)
			{
				var fs : BaseSkin = UISkin.current.Get(v + ".filter");				
				if(filters != null)if (fs == null) filters.Reset(); else filters.Set(fs.filter);
				OnSkinChange(UISkin.current);
			}
		}		
		return v; 
	}
	private var m_skin : String;
	
	
	public var x(get_x, set_x):Float;
	private var m_x : Float;
	private function get_x():Float 	      { return m_x; }
	private function set_x(v:Float):Float { m_x = v; UpdateTransform(); return v; }
	
	public var y(get_y, set_y):Float;
	private var m_y : Float;
	private function get_y():Float 	      { return m_y; }
	private function set_y(v:Float):Float { m_y = v;  UpdateTransform(); return v; }
	
	public var px(get_px, set_px):Float;
	private var m_px : Float;
	private function get_px():Float 	      { return m_px; }
	private function set_px(v:Float):Float 
	{
		m_px = v; 
		UpdateTransform();		
		return v; 
	}
	
	public var py(get_py, set_py):Float;
	private var m_py : Float;
	private function get_py():Float 	      { return m_py; }
	private function set_py(v:Float):Float 
	{
		m_py = v;  
		UpdateTransform(); 
		
		return v; 
	}
	
	public var width(get_width, set_width):Float;
	private var m_width : Float;
	private function get_width():Float 	      { return m_width; }
	private function set_width(v:Float):Float { m_width = Mathf.Max([0,v]);  UpdateRect(); return m_width; }
	
	public var height(get_height, set_height):Float;
	private var m_height : Float;
	private function get_height():Float 	      { return m_height; }
	private function set_height(v:Float):Float { m_height = Mathf.Max([0, v]); UpdateRect(); return m_height; }
	
	public var sx(get_sx, set_sx):Float;
	private var m_sx : Float;
	private function get_sx():Float 	      { return m_sx; }
	private function set_sx(v:Float):Float 
	{ 
		m_sx = v; 
		UpdateTransform(); 		
		return v; 		
	}
	
	public var sy(get_sy, set_sy):Float;
	private var m_sy : Float;
	private function get_sy():Float 	      { return m_sy; }
	private function set_sy(v:Float):Float 
	{ 
		m_sy = v; 
		UpdateTransform(); 		
		return v; 
	}
	
	public var rotation(get_rotation, set_rotation):Float;
	private var m_rotation : Float;
	private function get_rotation():Float 	      { return m_rotation; }
	private function set_rotation(v:Float):Float { m_rotation = v; UpdateTransform(); return v; }
	
	public var rect(get_rect, never):AABB2;
	private function get_rect():AABB2 
	{
		var m : AABB2 = layout.margin;
		return new AABB2(Std.int(m_x - m_px + m.xMin), Std.int(m_y - m_py + m.yMin), Std.int(m_width - (m.xMin + m.xMax)), Std.int(m_height - (m.yMin + m.yMax))); 
	}
	
	
	
	
	public var alpha(get_alpha, set_alpha):Float;
	private var m_alpha : Float;
	private var m_globalAlpha : Float;
	private function get_alpha():Float 	      { return m_alpha; }
	private function set_alpha(v:Float):Float 
	{ 		
		m_alpha = v; 
		UpdateMaterial();
		return v; 
	}
	
	public var filters(get_filters, never):UIFilter;
	private function get_filters():UIFilter { return m_filters; }
	private var m_filters: UIFilter;
	
	
	public var visible(get_visible, set_visible):Bool;
	private var m_visible : Bool;
	private var m_globalVisible : Bool;
	private function get_visible():Bool 	      { return m_visible; }
	private function set_visible(v:Bool):Bool 
	{ 		
		m_visible = v; 
		UpdateMaterial();
		return v; 
	}
	
	public var selectable(get_selectable, set_selectable):Bool;
	private var m_selectable : Bool;	
	private function get_selectable():Bool 	      { return m_selectable; }
	private function set_selectable(v:Bool):Bool 
	{ 		
		m_selectable = v; 
		m_element.style.setProperty(Application.vendor + "user-select", v ? "text" : "none", "");
		return v; 
	}
	
	
	public var mouseEnabled(get_mouseEnabled, set_mouseEnabled):Bool;
	private function get_mouseEnabled():Bool { return m_mouseEnabled; }
	private function set_mouseEnabled(v:Bool):Bool 
	{
		m_mouseEnabled = v;
		if (m_element != null)
		{
			m_element.style.setProperty("pointer-events", v ? "auto" : "none", "");
		}
		return v; 
	}
	private var m_mouseEnabled : Bool;
	
	private var m_added_stage : Bool;
	
	public var mouseX(get_mouseX, never):Float;
	private function get_mouseX():Float { return parent == null ? stage.mouseX :  (parent.mouseX - x); }
	
	public var mouseY(get_mouseY, never):Float;
	private function get_mouseY():Float { return parent == null ? stage.mouseY :  (parent.mouseY - y); }
	
	private var m_element : Element;
	
	public var graphics(get_graphics, never):CanvasRenderingContext2D;
	private function get_graphics():CanvasRenderingContext2D
	{		
		if (m_graphics != null) return m_graphics;
		var cc : DivElement = stage.document.createDivElement();
		cc.style.overflow = "hidden";
		cc.style.width = "100%";
		cc.style.height = "100%";
		var c : CanvasElement = stage.document.createCanvasElement();
		//c.style.zIndex = "-1";
		c.style.zIndex = "auto";
		m_graphics = c.getContext2d();		
		c.width  = 1920;// cast m_width - (layout.margin.xMin +layout.margin.xMax);
		c.height = 1920;// cast m_height - (layout.margin.yMin + layout.margin.yMax);							
		cc.appendChild(c);
		var fc : Element = m_element.firstElementChild;
		if (fc == null) m_element.appendChild(cc); else m_element.insertBefore(cc, fc);
		return m_graphics;
	}
	private var m_graphics : CanvasRenderingContext2D;
	
	
	public var layout(get_layout, never):Layout;
	private function get_layout():Layout { return m_layout; }
	private var m_layout : Layout;
	
	public var parent(get_parent, never):Container;
	private var m_parent : Container;
	private function get_parent():Container { return m_parent; }	
	
	public var stage(get_stage, never):Stage;
	private function get_stage():Stage 
	{ 		
		if (m_stage != null) return m_stage;
		var it : Container = parent;
		while (it != null)
		{
			if (Std.is(it, Stage)) { m_stage = cast it; return m_stage; }
			it = it.parent;
		}
		return null;		
	}
	private var m_stage : Stage;

	public var appended(get_appended, null):Bool;
	private function get_appended():Bool 
	{		
		var it : Element = m_element;
		while (it != null)
		{
			if (Std.is(it, BodyElement)) return true;
			it = it.parentElement;
		}
		return false; 
	}

	public var overflow(get_overflow, set_overflow):String;
	private function get_overflow():String { return m_element.style.overflow; }
	private function set_overflow(v:String):String { m_element.style.overflow = v; return v; }
	
	public function new() 
	{
		super();
		
		m_components = [];
		
		if (m_element != null)
		{
			var e : Element = cast m_element;
			e.style.position = "absolute";			
			e.style.zIndex = "auto";
			m_layout = new Layout(this);
		}
		
		name = GetTypeName() + id;
		
		m_filters = new UIFilter(m_element);
		
		m_element.setAttribute("script", Type.getClassName(Type.getClass(this)));
		
		m_x = 0;
		m_y = 0;
		m_px = 0;
		m_py = 0;
		m_width = 0;
		m_height = 0;
		m_rotation = 0;
		m_sx = 1.0;
		m_sy = 1.0;
		m_mouseEnabled = true;
		
		selectable = false;
		
		m_alpha 	  = 1;
		m_globalAlpha = 1;
		
		m_globalVisible = true;
		m_visible 		= true;				
		m_parent 		= null;
		
		skin = m_skin == null ? "" : m_skin;
	
		m_added_stage = false;
		
		UpdateTransform();
	}
	
	public function ClearGraphics():Void
	{
		m_graphics.canvas.width  = 1920;// cast m_width - (layout.margin.xMin +layout.margin.xMax);
		m_graphics.canvas.height = 1920;// cast m_height - (layout.margin.yMin + layout.margin.yMax);		
	}
	
	private function UpdateMaterial():Void
	{
		var pa : Float = parent == null ? 1.0 : parent.m_globalAlpha;
		var pv : Bool  = parent == null ? true : parent.m_globalVisible;
		var e : Element = cast m_element; 
		var is_negative : Bool = (pa < 0) || (m_alpha < 0);
		
		
		m_globalAlpha   = (Mathf.Clamp01(m_alpha) * Mathf.Clamp01(m_alpha));
		if(is_negative) m_globalAlpha = -m_globalAlpha;
		m_globalVisible = (m_visible && pv) && (!is_negative);
				
		//e.style.setProperty("-ms-filter","Alpha(opacity="+Std.int(m_globalAlpha*100)+")","");
		e.style.opacity = (m_globalAlpha)+"";
		e.style.display = m_globalVisible ? "block" : "none";
		
		for (i in 0...m_components.length) m_components[i].OnMaterialUpdate();
	}
	
	private function UpdateRect():Void
	{
		
		var e : Element = cast m_element; 		
		var m : AABB2   = layout.margin;
		
		layout.Update();
		
		
		e.style.width 	= Std.int(m_width - (m.xMin + m.xMax)) + "px";
		e.style.height 	= Std.int(m_height - (m.yMin + m.yMax)) + "px";
		
		for (i in 0...m_components.length) m_components[i].OnRectUpdate();
		
		/*
		if (m_graphics != null)
		{			
			//m_graphics.canvas.width  = cast m_width - (m.xMin + m.xMax);
			//m_graphics.canvas.height = cast m_height - (m.yMin + m.yMax);					
		}
		//*/	
		OnRepaint();
	}
	
	private function UpdateTransform():Void 
	{
		var e : Element = cast m_element; 		
		var m : AABB2   = layout.margin;
		
		layout.Update();
		
		var px : Float =  Mathf.Floor(m_x - m_px + m.xMin);
		var py : Float =  Mathf.Floor(m_y - m_py + m.yMin);
		var ox : Float = px + m_px;
		var oy : Float = py + m_py;
		//e.style.left 	= Std.int(m_x - m_px + m.xMin) + "px"; 		
		//e.style.top 	= Std.int(m_y - m_py + m.yMin) + "px";		
		
		//var flags : Array<String> = ["-webkit-", "-moz-", "-o-", "-ms-"];		
		//for (i in 0...flags.length) e.style.setProperty(flags[i]+"transform","scale("+m_sx+","+m_sy+") rotate("+m_rotation+"deg) translate("+px+"px,"+py+"px)","");		
		var tov : String = e.style.getPropertyValue(Application.vendor + "transform-origin") ;
		if ((tov != "") && (tov != null)) e.style.removeProperty(Application.vendor + "transform-origin");		
		e.style.cssText = e.style.cssText + " " + Application.vendor + "transform-origin: "+ox+"px "+oy+"px;";
		//e.style.setProperty(Application.vendor + "transform-origin", (ox) + "px " + (oy) + " px", "");
		//e.style.setProperty(Application.vendor+"transform","scale("+m_sx+","+m_sy+") rotate("+m_rotation+"deg) translate("+px+"px,"+py+"px)","");
		e.style.setProperty(Application.vendor+"transform","scale3d("+m_sx+","+m_sy+",1.0) rotate3d(0,0,1,"+m_rotation+"deg) translate3d("+px+"px,"+py+"px,0px)","");
		
		for (i in 0...m_components.length) m_components[i].OnTransformUpdate();
		
	}
	
	
	private function OnRepaint():Void { }
	
	private function OnAdded():Void { }
	
	private function OnAddedToStage():Void { }
	
	private function OnRemoved():Void { }
	
	
	private function AddedToStage():Void
	{
		if (!m_added_stage)
		{
			m_added_stage = true;
			OnAddedToStage();
			for (i in 0...m_components.length) m_components[i].OnAddedToStage();
		}
	}
	
	
	private function DrawSlicedImage(p_graphics : CanvasRenderingContext2D, p_image : ImageElement, w : Float, h:Float, p_slices:Array<Int>=null):Void
	{
		if (p_image == null) return;
		p_slices = p_slices == null ? [] : p_slices;
		var c  : CanvasElement = p_graphics.canvas;
		var iw : Float = p_image.naturalWidth;
		var ih : Float = p_image.naturalHeight;
		var w  : Float = c.width;
		var h  : Float = c.height;
		var l  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[0]);
		l = Mathf.Min([l, w/2]);
		var r  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[1]);
		r = Mathf.Min([r, w/2]);
		var t  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[2]);
		t = Mathf.Min([t, h/2]);
		var b  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[3]);
		b = Mathf.Min([b, h/2]);
		var ix0 : Float = 0; 						var iy0 : Float = 0; 					var iw0 : Float = l; 						 var ih0 : Float = t;
		var ix1 : Float = l; 						var iy1 : Float = 0; 					var iw1 : Float = Math.max(1, iw - l - r);   var ih1 : Float = t;
		var ix2 : Float = Math.max(1, iw - r);	 	var iy2 : Float = 0; 					var iw2 : Float = r; 						 var ih2 : Float = t;
		var ix3 : Float = 0; 						var iy3 : Float = t; 					var iw3 : Float = l; 						 var ih3 : Float = Math.max(1, ih - t - b);
		var ix4 : Float = l; 						var iy4 : Float = t; 					var iw4 : Float = Math.max(1, iw - l - r);   var ih4 : Float = Math.max(1, ih - t - b);
		var ix5 : Float = Math.max(1, iw - r);	 	var iy5 : Float = t; 					var iw5 : Float = r; 						 var ih5 : Float = Math.max(1, ih - t - b);
		var ix6 : Float = 0; 						var iy6 : Float = Math.max(1, ih - b);  var iw6 : Float = l; 						 var ih6 : Float = b;
		var ix7 : Float = l; 						var iy7 : Float = Math.max(1, ih - b);  var iw7 : Float = Math.max(1, iw - l - r);   var ih7 : Float = b;
		var ix8 : Float = Math.max(1, iw - r);	 	var iy8 : Float = Math.max(1, ih - b);  var iw8 : Float = r; 						 var ih8 : Float = b;
		
		var x0 : Float = 0; 						var y0 : Float = 0; 					var w0 : Float = l; 						 var h0 : Float = t;
		var x1 : Float = l; 						var y1 : Float = 0; 					var w1 : Float = Math.max(0, w - l - r);     var h1 : Float = t;
		var x2 : Float = Math.max(0, w - r);	 	var y2 : Float = 0; 					var w2 : Float = r; 						 var h2 : Float = t;
		var x3 : Float = 0; 						var y3 : Float = t; 					var w3 : Float = l; 						 var h3 : Float = Math.max(0, h - t - b);
		var x4 : Float = l; 						var y4 : Float = t; 					var w4 : Float = Math.max(0, w - l - r);     var h4 : Float = Math.max(0, h - t - b);
		var x5 : Float = Math.max(0, w - r);	 	var y5 : Float = t; 					var w5 : Float = r; 						 var h5 : Float = Math.max(0, h - t - b);
		var x6 : Float = 0; 						var y6 : Float = Math.max(0, h - b);    var w6 : Float = l; 						 var h6 : Float = b;
		var x7 : Float = l; 						var y7 : Float = Math.max(0, h - b);    var w7 : Float = Math.max(0, w - l - r);     var h7 : Float = b;
		var x8 : Float = Math.max(0, w - r);	 	var y8 : Float = Math.max(0, h - b);    var w8 : Float = r; 						 var h8 : Float = b;
		
		
		if (l > 0) if (t > 0) 	p_graphics.drawImage(p_image, ix0  , iy0 , iw0  , ih0  , x0  , y0  , w0  , h0);
		if (t > 0) 				p_graphics.drawImage(p_image, ix1  , iy1 , iw1  , ih1  , x1  , y1  , w1  , h1);
		if (r > 0) if (t > 0) 	p_graphics.drawImage(p_image, ix2  , iy2 , iw2  , ih2  , x2  , y2  , w2  , h2);
		if (l > 0) 				p_graphics.drawImage(p_image, ix3  , iy3 , iw3  , ih3  , x3  , y3  , w3  , h3);
								p_graphics.drawImage(p_image, ix4  , iy4 , iw4  , ih4  , x4  , y4  , w4  , h4);
		if (r > 0) 				p_graphics.drawImage(p_image, ix5  , iy5 , iw5  , ih5  , x5  , y5  , w5  , h5);		
		if (l > 0) if (b > 0) 	p_graphics.drawImage(p_image, ix6  , iy6 , iw6  , ih6  , x6  , y6  , w6  , h6);
		if (b > 0) 				p_graphics.drawImage(p_image, ix7  , iy7 , iw7  , ih7  , x7  , y7  , w7  , h7);
		if (r > 0) if (b > 0) 	p_graphics.drawImage(p_image, ix8  , iy8 , iw8  , ih8  , x8  , y8  , w8  , h8);
	}
	
	/**
	 * 
	 * @param	p_skin
	 */
	public function OnSkinChange(p_skin : UISkin):Void
	{
		
	}
	
	
	/**
	 * 
	 * @param	Class<Component> p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<UIComponent>) : Dynamic
	{
		var c:UIComponent = Type.createInstance(p_type, [this]);		
		m_components.push(c);
		return c;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponent(p_type : Class<UIComponent>) : Dynamic
	{
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) return m_components[i];
		return null;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponents(p_type : Class<UIComponent>) : Array<UIComponent>
	{
		var res : Array<UIComponent> = [];
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) res.push(m_components[i]);
		return res;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentInChildren(p_type : Class<UIComponent>) : Dynamic
	{
		var res : UIComponent = null;		
		if (!Std.is(this, Container)) return res;
		var c : Container = cast this;		
		c.Traverse(function(d : Int,t : UIEntity):Bool
		{
			var l : Array<UIComponent> = t.GetComponents(p_type);
			if (l.length > 0) { res = l[0]; return false; }
			return true;
		});
		return res;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentsInChildren(p_type : Class<UIComponent>) : Array<UIComponent>
	{
		var res : Array<UIComponent> = [];
		if (!Std.is(this, Container)) return res;
		var c : Container = cast this;		
		c.Traverse(function(d : Int,t : UIEntity):Bool
		{
			var l : Array<UIComponent> = t.GetComponents(p_type);
			for (i in 0...l.length) res.push(l[i]);
			return true;
		});
		return res;
	}
	
	public function ToFront():Void { if (parent != null) parent.SetChildIndex(this, 10000); }
	
	public function StepFront():Void { if (parent != null) parent.SetChildIndex(this, parent.GetChildIndex(this)+1); }
	
	public function ToBack():Void { if (parent != null) parent.SetChildIndex(this, 0); }
	
	public function StepBack():Void { if (parent != null) parent.SetChildIndex(this, parent.GetChildIndex(this)-1); }
	
}