/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import haxor.graphics.Screen;
import haxor.math.AABB2;


@:allow(haxor)
class Layout
{
	private var m_element : UIEntity;
	
	public var px(get_px, set_px):Float;
	private var m_px : Float;
	private function get_px():Float 	      { return m_px; }
	private function set_px(v:Float):Float { m_px = v; if ((m_flag & LayoutFlag.PivotX) != 0)Update(); return v; }
	
	public var py(get_py, set_py):Float;
	private var m_py : Float;
	private function get_py():Float 	      { return m_py; }
	private function set_py(v:Float):Float { m_py = v; if ((m_flag & LayoutFlag.PivotY) != 0)Update(); return v; }
	
	public var x(get_x, set_x):Float;
	private var m_x : Float;
	private function get_x():Float 	      { return m_x; }
	private function set_x(v:Float):Float { m_x = v; if ((m_flag & LayoutFlag.PositionX) != 0)Update(); return v; }
	
	public var y(get_y, set_y):Float;
	private var m_y : Float;
	private function get_y():Float 	      { return m_y; }
	private function set_y(v:Float):Float { m_y = v; if ((m_flag & LayoutFlag.PositionY) != 0)Update(); return v; }
	
	
	public var width(get_width, set_width):Float;
	private var m_width : Float;
	private function get_width():Float 	      { return m_width; }
	private function set_width(v:Float):Float { m_width = v; if ((m_flag & LayoutFlag.SizeX) != 0)Update(); return v; }
	
	public var height(get_height, set_height):Float;
	private var m_height : Float;
	private function get_height():Float 	      { return m_height; }
	private function set_height(v:Float):Float { m_height = v; if ((m_flag & LayoutFlag.SizeY) != 0)Update(); return v; }
	
	public var flag(get_flag, set_flag):Int;
	private var m_flag : Int;
	private function get_flag():Int 	      { return m_flag; }
	private function set_flag(v:Int):Int { m_flag = v; Update(); return v; }
	
	public var margin(get_margin, set_margin) : AABB2;
	private var m_margin : AABB2;
	private function get_margin():AABB2 	      { return m_margin.clone; }
	private function set_margin(v:AABB2):AABB2 { m_margin = v.clone; m_element.UpdateTransform(); return v; }
	
	private var m_lock : Bool;
	
	public function Set(p_flag : Int,p_px : Float, p_py:Float, p_x:Float, p_y:Float):Void
	{
		m_flag = p_flag;
		m_px = p_px;
		m_py = p_py;
		m_x  = p_x;
		m_y  = p_y;
		Update();
	}
	
	public function FitSize():Void
	{
		m_width  = 1;
		m_height = 1;
		flag = LayoutFlag.SizeXY;		
	}
	
	public function FitWidth():Void { width  = 1; flag   = flag | LayoutFlag.SizeX; }
	
	public function FitHeight():Void { height  = 1; flag   = flag | LayoutFlag.SizeY; }
	
	private function new(p_element : UIEntity)
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
	
	private function Update()
	{
		if (m_lock) return;
		m_lock = true;
		var p :Container = m_element.parent;
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