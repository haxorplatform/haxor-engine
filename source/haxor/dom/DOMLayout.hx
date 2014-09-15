#if html

package haxor.dom;
import haxor.platform.Types.Float32;
import haxor.dom.LayoutFlag;
import haxor.graphics.Screen;
import haxor.math.AABB2;


@:allow(haxor)
class DOMLayout
{
	private var m_element : DOMEntity;
	
	/**
	 * Pivot X behaviour.
	 */
	public var px(get_px, set_px):Float32;	
	private inline function get_px():Float32 	      { return m_px; }
	private function set_px(v:Float):Float32 { m_px = v; if ((m_flag & LayoutFlag.PivotX) != 0) Update(); return v; }
	private var m_px : Float32;
	
	/**
	 * Pivot Y behaviour.
	 */
	public var py(get_py, set_py):Float32;	
	private inline function get_py():Float32 	      { return m_py; }
	private function set_py(v:Float32):Float32 { m_py = v; if ((m_flag & LayoutFlag.PivotY) != 0) Update(); return v; }
	private var m_py : Float32;
	
	/**
	 * X position behaviour.
	 */
	public var x(get_x, set_x):Float32;	
	private inline function get_x():Float32 	      { return m_x; }
	private function set_x(v:Float32):Float32 { m_x = v; if ((m_flag & LayoutFlag.PositionX) != 0) Update(); return v; }
	private var m_x : Float32;
	
	/**
	 * Y position behaviour.
	 */
	public var y(get_y, set_y):Float32;	
	private inline function get_y():Float32 	      { return m_y; }
	private function set_y(v:Float32):Float32 { m_y = v; if ((m_flag & LayoutFlag.PositionY) != 0) Update(); return v; }
	private var m_y : Float32;
	
	/**
	 * Width behaviour.
	 */
	public var width(get_width, set_width):Float32;	
	private inline function get_width():Float32 	      { return m_width; }
	private function set_width(v:Float32):Float32 { m_width = v; if ((m_flag & LayoutFlag.SizeX) != 0) Update(); return v; }
	private var m_width : Float32;
	
	/**
	 * Height behaviour.
	 */
	public var height(get_height, set_height):Float32;	
	private inline function get_height():Float32 	      { return m_height; }
	private function set_height(v:Float32):Float32 { m_height = v; if ((m_flag & LayoutFlag.SizeY) != 0) Update(); return v; }
	private var m_height : Float32;
	
	/**
	 * Layout behaviour flag.
	 */
	public var flag(get_flag, set_flag):Int;	
	private inline function get_flag():Int 	      { return m_flag; }
	private function set_flag(v:Int):Int { m_flag = v; Update(); return v; }
	private var m_flag : Int;
	
	/**
	 * Margin of the DOM entity.
	 */
	public var margin(get_margin, set_margin) : AABB2;	
	private function get_margin():AABB2 	      { return m_margin.clone; }
	private function set_margin(v:AABB2):AABB2 { m_margin = v.clone; m_element.UpdateTransform(); return v; }
	private var m_margin : AABB2;
	
	/**
	 * Locks this Layout further updates.
	 */
	private var m_lock : Bool;
	
	/**
	 * Shortcut for setting multiple attributes.
	 * @param	p_flag
	 * @param	p_px
	 * @param	p_py
	 * @param	p_x
	 * @param	p_y
	 */
	public function Set(p_flag : Int,p_px : Float, p_py:Float, p_x:Float, p_y:Float):Void
	{
		m_flag = p_flag;
		m_px = p_px;
		m_py = p_py;
		m_x  = p_x;
		m_y  = p_y;
		Update();
	}
	
	/**
	 * Shortcut for 100% width and 100% height.
	 */
	public function FitSize():Void
	{
		m_width  = 1;
		m_height = 1;
		flag = LayoutFlag.SizeXY;		
	}
	
	/**
	 * Shortcut for 100% width.
	 */
	public function FitWidth():Void { width  = 1; flag   = flag | LayoutFlag.SizeX; }
	
	/**
	 * Shortcut for 100% height.
	 */
	public function FitHeight():Void { height  = 1; flag   = flag | LayoutFlag.SizeY; }
	
	/**
	 * Creates a new DOMEntity Layout.
	 * @param	p_element
	 */
	private function new(p_element : DOMEntity)
	{
		m_element = p_element;
		m_lock = false;
		m_margin = AABB2.empty;
		m_x = m_y = 0;
		m_width = 1;
		m_height = 1;
		m_px = 0;
		m_py = 0;
	}
	
	/**
	 * Updates the element data based on the layout behaviour.
	 */
	private function Update()
	{
		if (m_lock) return;
		m_lock = true;
		var p : Container = m_element.parent;
		var pw : Float = p == null ? 0  : (p.width - p.layout.margin.xMin - p.layout.margin.xMax);
		var ph : Float = p == null ? 0  : (p.height - p.layout.margin.yMin - p.layout.margin.yMax);
		if ((m_flag & LayoutFlag.PositionX) != 0) { m_element.x = pw * x; }		
		if ((m_flag & LayoutFlag.PositionY) != 0) { m_element.y = ph * y; }
		if ((m_flag & LayoutFlag.PivotX) != 0) 	  { m_element.px = m_element.width  * px; }
		if ((m_flag & LayoutFlag.PivotY) != 0) 	  { m_element.py = m_element.height * py; }		
		if ((m_flag & LayoutFlag.SizeX) != 0) 	  { m_element.width = pw * width; }
		if ((m_flag & LayoutFlag.SizeY) != 0) 	  { m_element.height = ph * height; }		
		m_lock = false;
	}
	
}

#end