/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.math;

/**
 * ...
 * @author Eduardo Pons
 */
class AABB2
{
	static public function FromMinMax(p_xmin : Float, p_xmax : Float, p_ymin:Float, p_ymax : Float ) :AABB2
	{
		var b : AABB2 = new AABB2();
		b.xMin = p_xmin;
		b.xMax = p_xmax;
		b.yMin = p_ymin;
		b.yMax = p_ymax;
		return b;
	}
	
	static public var empty(get_empty, null):AABB2;
	static private function get_empty():AABB2 { return new AABB2(); }	

	public var clone(get_clone, null):AABB2;
	private function get_clone():AABB2 { return FromMinMax(xMin, xMax, yMin, yMax); }
	
	public var min(get_min, set_min):Vector2;
	private function get_min():Vector2 { return new Vector2(m_xMin, m_yMin); }
	private function set_min(v:Vector2):Vector2 { xMin = v.x; yMin = v.y; return v; }
	
	public var max(get_max, set_max):Vector2;
	private function get_max():Vector2 { return new Vector2(m_xMax, m_yMax); }
	private function set_max(v:Vector2):Vector2 { xMax = v.x; yMax = v.y; return v; }
	
	public var xMin(get_xMin, set_xMin):Float;
	private var m_xMin:Float;	
	private function get_xMin():Float { return m_xMin; }
	private function set_xMin(v:Float):Float { m_xMin = v; Validate(); return v; }	
	
	public var yMin(get_yMin, set_yMin):Float;
	private var m_yMin:Float;	
	private function get_yMin():Float { return m_yMin; }
	private function set_yMin(v:Float):Float { m_yMin = v; Validate(); return v; }	
	
	public var xMax(get_xMax, set_xMax):Float;
	private var m_xMax:Float;	
	private function get_xMax():Float { return m_xMax; }
	private function set_xMax(v:Float):Float { m_xMax = v; Validate(); return v; }	
	
	public var yMax(get_yMax, set_yMax):Float;
	private var m_yMax:Float;	
	private function get_yMax():Float { return m_yMax; }
	private function set_yMax(v:Float):Float { m_yMax = v; Validate(); return v; }
	
	public var center(get_center, set_center):Vector2;
	private function get_center():Vector2 { return new Vector2(xMin + (xMax - xMin) * 0.5, yMin + (yMax - yMin) * 0.5); }
	private function set_center(v:Vector2):Vector2 
	{ 
		var hw:Float = width * 0.5;
		var hh:Float = height * 0.5;
		m_xMin = v.x - hw;
		m_xMax = v.x + hw;
		m_yMin = v.y - hh;
		m_yMax = v.y + hh;
		return v;
	}
	
	public var x(get_x, set_x):Float;
	private function get_x():Float { return get_xMin(); }
	private function set_x(v:Float):Float { set_xMin(v); return v; }
	
	public var y(get_y, set_y):Float;
	private function get_y():Float { return get_yMin(); }
	private function set_y(v:Float):Float { set_yMin(v); return v; }
	
	
	public var width(get_width, set_width):Float;
	private function get_width():Float { return Mathf.Abs(xMax - xMin); }
	private function set_width(v:Float):Float { xMax = xMin + v; return v; }
	
	public var height(get_height, set_height):Float;
	private function get_height():Float { return Mathf.Abs(yMax - yMin); }
	private function set_height(v:Float):Float { yMax = yMin + v; return v; }
	
	public var size(get_size, set_size):Vector2;
	private function get_size():Vector2 { return new Vector2(width, height); }
	private function set_size(v:Vector2):Vector2 { width = v.x; height = v.y; return v; }
	
	public function new(p_x:Float = 0, p_y : Float =0, p_width:Float = 0,p_height : Float=0)
	{            
		m_xMin = p_x;
		m_yMin = p_y;
		m_xMax = m_xMin + p_width;
		m_yMax = m_yMin + p_height;
	}
	
	private function Validate():Void
	{
		/*
		var x0 : Float = m_xMin;
		var x1 : Float = m_xMax;
		var y0 : Float = m_yMin;
		var y1 : Float = m_yMax;
		if (x0 <= x1) { m_xMin = x0; m_xMax = x1; } else { m_xMin = x1; m_xMax = x0; }
		if (y0 <= y1) { m_yMin = y0; m_yMax = y1; } else { m_yMin  = y1; m_yMax = y0; }
		//*/
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="p_point"></param>
	public function Encapsulate(p_point:Vector2):Void
	{
		xMin = Mathf.Min(p_point.x, xMin);
		xMax = Mathf.Max(p_point.x, xMax);
		yMin = Mathf.Min(p_point.y, yMin);
		yMax = Mathf.Max(p_point.y, yMax);            
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	public function ToString():String
	{		
		var s0:String = Mathf.RoundPlaces(m_xMin)+"";
		var s1:String = Mathf.RoundPlaces(m_xMax)+"";
		var s2:String = Mathf.RoundPlaces(m_yMin)+"";
		var s3:String = Mathf.RoundPlaces(m_yMax)+"";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
}