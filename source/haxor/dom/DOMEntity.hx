#if html

package haxor.dom;
import haxor.platform.Types.Float32;
import haxor.core.BaseApplication;
import haxor.platform.html.HTMLApplication;
import haxor.core.Application;
import haxor.input.Input;
import haxor.math.Mathf;
import haxor.dom.DOMLayout;
import haxor.math.AABB2;
import js.html.Element;
import haxor.core.Resource;

/**
 * Class that describes a primitive element of the DOM structure.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class DOMEntity extends Resource
{
	/**
	 * X coord of the local position.
	 */
	public var x(get_x, set_x):Float32;	
	private inline function get_x():Float32 	      { return m_x; }
	private function set_x(v:Float32):Float32 { m_x = v; UpdateTransform(); return v; }
	private var m_x : Float32;
	
	/**
	 * Y coord of the local position.
	 */
	public var y(get_y, set_y):Float32;
	private var m_y : Float32;
	private function get_y():Float32 	      { return m_y; }
	private function set_y(v:Float32):Float32 { m_y = v;  UpdateTransform(); return v; }
	
	/**
	 * X coord of the pivot.
	 */
	public var px(get_px, set_px):Float32;	
	private function get_px():Float32 	      { return m_px; }
	private function set_px(v:Float32):Float32    {	m_px = v; UpdateTransform(); return v; }
	private var m_px : Float32;
	
	/**
	 * Y coord of the pivot.
	 */
	public var py(get_py, set_py):Float32;	
	private function get_py():Float32 	      { return m_py; }
	private function set_py(v:Float32):Float32    {	m_py = v;  UpdateTransform(); return v; }
	private var m_py : Float32;
	
	/**
	 * Width of this element.
	 */
	public var width(get_width, set_width):Float32;	
	private function get_width():Float32 	      { return m_width; }
	private function set_width(v:Float32):Float32 { m_width = Mathf.Max(0, v);  UpdateRect(); return m_width; }
	private var m_width : Float32;
	
	/**
	 * Height of this element.
	 */
	public var height(get_height, set_height):Float32;	
	private function get_height():Float32 	      { return m_height; }
	private function set_height(v:Float32):Float32 { m_height = Mathf.Max(0, v); UpdateRect(); return m_height; }
	private var m_height : Float32;
	
	/**
	 * Scale X of this element.
	 */
	public var sx(get_sx, set_sx):Float32;	
	private function get_sx():Float32 	      { return m_sx; }
	private function set_sx(v:Float32):Float32    { m_sx = v; UpdateTransform(); return v; }
	private var m_sx : Float32;
	
	/**
	 * Scale Y of this element.
	 */
	public var sy(get_sy, set_sy):Float32;	
	private function get_sy():Float32 	      { return m_sy; }
	private function set_sy(v:Float32):Float32    { m_sy = v; UpdateTransform(); return v; }
	private var m_sy : Float32;
	
	/**
	 * Rotation around the pivot in degrees.
	 */
	public var rotation(get_rotation, set_rotation):Float32;	
	private function get_rotation():Float32 	      { return m_rotation; }
	private function set_rotation(v:Float32):Float32 { m_rotation = v; UpdateTransform(); return v; }
	private var m_rotation : Float32;
	
	/**
	 * Mouse X position relative to this entity.
	 */
	public var mouseX(get_mouseX, never):Float32;
	private function get_mouseX():Float32 { return parent == null ? Input.mouse.x :  (parent.mouseX - x); }
	
	/**
	 * Mouse Y position relative to this entity.
	 */
	public var mouseY(get_mouseY, never):Float32;
	private function get_mouseY():Float32 { return parent == null ? Input.mouse.y :  (parent.mouseY - y); }
	
	/**
	 * Rect of this element, containing its local position, width and height.
	 */
	public var rect(get_rect, never):AABB2;
	private function get_rect():AABB2 
	{
		var m : AABB2 = layout.margin;
		return new AABB2(Std.int(m_x - m_px + m.xMin), Std.int(m_y - m_py + m.yMin), Std.int(m_width - (m.xMin + m.xMax)), Std.int(m_height - (m.yMin + m.yMax))); 
	}
	
	/**
	 * Alpha of this element.
	 */
	public var alpha(get_alpha, set_alpha):Float32;	
	private function get_alpha():Float32 	      { return m_alpha; }
	private function set_alpha(v:Float32):Float32 { m_alpha = v; UpdateMaterial(); return v; }
	private var m_alpha : Float32;
	private var m_globalAlpha : Float32;
	
	/**
	 * Visibility flag of this element.
	 */
	public var visible(get_visible, set_visible):Bool;		
	private function get_visible():Bool 	      { return m_visible; }
	private function set_visible(v:Bool):Bool     { m_visible = v; UpdateMaterial(); return v; }
	private var m_visible : Bool;
	private var m_globalVisible : Bool;
	
	/**
	 * Flag that enables mouse interaction in this element.
	 */
	public var mouseEnabled(get_mouseEnabled, set_mouseEnabled):Bool;
	private function get_mouseEnabled():Bool { return m_mouseEnabled; }
	private function set_mouseEnabled(v:Bool):Bool 	{ m_mouseEnabled = v; if (m_element != null) m_element.style.setProperty("pointer-events", v ? "auto" : "none", ""); return v; }
	private var m_mouseEnabled : Bool;
	
	/**
	 * Entity's Layout behaviour.
	 */
	public var layout(get_layout, never):DOMLayout;
	private function get_layout():DOMLayout { return m_layout; }
	private var m_layout : DOMLayout;
	
	/**
	 * Entity's parent container.
	 */
	public var parent(get_parent, never):Container;	
	private function get_parent():Container { return m_parent; }	
	private var m_parent : Container;
	
	/**
	 * Returns this application stage instance.
	 */
	public var stage(get_stage, never):DOMStage;
	private function get_stage():DOMStage { return DOMStage.m_instance; }
	
	/**
	 * Overrides the name setter to change the physical element in the DOM tree.
	 * @param	v
	 * @return
	 */
	override private function set_name(v:String):String { super.set_name(v); m_element.setAttribute("name", v); return v; }
	
	/**
	 * Reference to the DOM element being used by this entity.
	 */
	public var element(get_element, never):Element;
	private inline function get_element():Element { return m_element; }	
	private var m_element : Element;
	
	/**
	 * Flag that indicates if this entity was added to stage.
	 */
	private var m_added_stage : Bool;
	
	/**
	 * Creates a new DOM Entity.
	 * @param	p_element
	 * @param	p_name
	 */
	public function new(p_element:Element,p_name:String="") 
	{
		super(p_name);
		
		m_layout  = new DOMLayout(this);				
		m_element = p_element;
		
		if (m_element != null)
		{
			var e : Element = cast m_element;
			e.style.position = "absolute";			
			e.style.zIndex 	 = "auto";	
			e.setAttribute("script", Type.getClassName(Type.getClass(this)));
		}
		
		if (p_name == "") name = GetTypeName() + uid; else name = p_name;
		
		m_x 			= 0;
		m_y 			= 0;
		m_px 			= 0;
		m_py 			= 0;
		m_width 		= 0;
		m_height 		= 0;
		m_rotation 		= 0;
		m_sx 			= 1.0;
		m_sy 			= 1.0;
		m_mouseEnabled  = true;
		m_alpha 	  	= 1;
		m_globalAlpha 	= 1;
		m_globalVisible = true;
		m_visible 		= true;				
		m_parent 		= null;
		
		//selectable = false;
		
	}
	
	/**
	 * Updates this entity visual data.
	 */
	private function UpdateMaterial():Void
	{
		var pa : Float = parent == null ? 1.0  : parent.m_globalAlpha;
		var pv : Bool  = parent == null ? true : parent.m_globalVisible;
		var e : Element = cast m_element; 
		var is_negative : Bool = (pa < 0) || (m_alpha < 0);
		
		m_globalAlpha   = (Mathf.Clamp01(m_alpha) * Mathf.Clamp01(m_alpha));
		if(is_negative) m_globalAlpha = -m_globalAlpha;
		m_globalVisible = (m_visible && pv) && (!is_negative);
		/*		
		#if ie8
		e.style.setProperty("-ms-filter","Alpha(opacity="+Std.int(m_globalAlpha*100)+")","");
		#else
		e.style.opacity = (m_globalAlpha) + "";
		#end
		//*/
		e.style.opacity = (m_globalAlpha) + "";
		e.style.display = m_globalVisible ? "block" : "none";
		
		//for (i in 0...m_components.length) m_components[i].OnMaterialUpdate();
	}
	
	/**
	 * Updates this entity rectangle dimensions.
	 */
	private function UpdateRect():Void
	{		
		var e : Element = cast m_element; 		
		var m : AABB2   = layout.margin;		
		layout.Update();		
		e.style.width 	= Std.int(m_width - (m.xMin + m.xMax)) + "px";
		e.style.height 	= Std.int(m_height - (m.yMin + m.yMax)) + "px";		
		//for (i in 0...m_components.length) m_components[i].OnRectUpdate();		
		OnRepaint();
	}
	
	/**
	 * Updates this entity transform information.
	 */
	private function UpdateTransform():Void 
	{
		var e : Element = cast m_element; 		
		var m : AABB2   = layout.margin;
		
		layout.Update();
		
		var px : Float =  Mathf.Floor(m_x - m_px + m.xMin);
		var py : Float =  Mathf.Floor(m_y - m_py + m.yMin);
		var ox : Float = px + m_px;
		var oy : Float = py + m_py;
		
		#if ie8
		e.style.left 	= Std.int(m_x - m_px + m.xMin) + "px"; 		
		e.style.top 	= Std.int(m_y - m_py + m.yMin) + "px";		
		#else
		//var flags : Array<String> = ["-webkit-", "-moz-", "-o-", "-ms-"];		
		//for (i in 0...flags.length) e.style.setProperty(flags[i]+"transform","scale("+m_sx+","+m_sy+") rotate("+m_rotation+"deg) translate("+px+"px,"+py+"px)","");		
		var vdn : String = application.vendor;
		var tov : String = e.style.getPropertyValue(vdn + "transform-origin");
		if ((tov != "") && (tov != null)) e.style.removeProperty(vdn + "transform-origin");		
		e.style.cssText = e.style.cssText + " " + vdn + "transform-origin: "+ox+"px "+oy+"px;";
		//e.style.setProperty(Application.vendor + "transform-origin", (ox) + "px " + (oy) + " px", "");
		//e.style.setProperty(Application.vendor+"transform","scale("+m_sx+","+m_sy+") rotate("+m_rotation+"deg) translate("+px+"px,"+py+"px)","");
		e.style.setProperty(vdn+"transform","scale3d("+m_sx+","+m_sy+",1.0) rotate3d(0,0,1,"+m_rotation+"deg) translate3d("+px+"px,"+py+"px,0px)","");
		#end
		
		//for (i in 0...m_components.length) m_components[i].OnTransformUpdate();
		
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
			//for (i in 0...m_components.length) m_components[i].OnAddedToStage();
		}
	}
	
	/*
	public function ToFront():Void { if (parent != null) parent.SetChildIndex(this, 10000); }
	
	public function StepFront():Void { if (parent != null) parent.SetChildIndex(this, parent.GetChildIndex(this)+1); }
	
	public function ToBack():Void { if (parent != null) parent.SetChildIndex(this, 0); }
	
	public function StepBack():Void { if (parent != null) parent.SetChildIndex(this, parent.GetChildIndex(this)-1); }
	//*/
}

#end