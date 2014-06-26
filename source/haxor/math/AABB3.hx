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
class AABB3
{
	
	static public function FromMinMax(p_xmin : Float, p_xmax : Float, p_ymin:Float, p_ymax : Float, p_zmin:Float, p_zmax : Float ) :AABB3
	{
		var b : AABB3 = new AABB3();
		b.xMin = p_xmin;
		b.xMax = p_xmax;
		b.yMin = p_ymin;
		b.yMax = p_ymax;
		b.zMin = p_zmin;
		b.zMax = p_zmax;
		return b;
	}
	
	static public function FromCenter(p_x : Float, p_y : Float, p_z:Float, p_width : Float, p_height:Float, p_depth : Float ) :AABB3
	{
		var b : AABB3 = new AABB3();
		b.width  = p_width;
		b.height = p_height;
		b.depth  = p_depth;
		b.center = new Vector3(p_x, p_y, p_z);
		return b;
	}
	
	static public var empty(get_empty, null):AABB3;
	static private function get_empty():AABB3 { return new AABB3(); }	

	public var clone(get_clone, null):AABB3;
	private function get_clone():AABB3 { return FromMinMax(xMin, xMax, yMin, yMax,zMin,zMax); }
	
	public var min(get_min, set_min):Vector3;
	private function get_min():Vector3 { return new Vector3(m_xMin, m_yMin); }
	private function set_min(v:Vector3):Vector3 { xMin = v.x; yMin = v.y; return v; }
	
	public var max(get_max, set_max):Vector3;
	private function get_max():Vector3 { return new Vector3(m_xMax, m_yMax); }
	private function set_max(v:Vector3):Vector3 { xMax = v.x; yMax = v.y; return v; }
	
	public var xMin(get_xMin, set_xMin):Float;
	private var m_xMin:Float;	
	private function get_xMin():Float { return m_xMin; }
	private function set_xMin(v:Float):Float { m_xMin = v; Validate(); return v; }	
	
	public var yMin(get_yMin, set_yMin):Float;
	private var m_yMin:Float;	
	private function get_yMin():Float { return m_yMin; }
	private function set_yMin(v:Float):Float { m_yMin = v; Validate(); return v; }
	
	public var zMin(get_zMin, set_zMin):Float;
	private var m_zMin:Float;	
	private function get_zMin():Float { return m_zMin; }
	private function set_zMin(v:Float):Float { m_zMin = v; Validate(); return v; }
	
	public var xMax(get_xMax, set_xMax):Float;
	private var m_xMax:Float;	
	private function get_xMax():Float { return m_xMax; }
	private function set_xMax(v:Float):Float { m_xMax = v; Validate(); return v; }	
	
	public var yMax(get_yMax, set_yMax):Float;
	private var m_yMax:Float;	
	private function get_yMax():Float { return m_yMax; }
	private function set_yMax(v:Float):Float { m_yMax = v; Validate(); return v; }
	
	public var zMax(get_zMax, set_zMax):Float;
	private var m_zMax:Float;	
	private function get_zMax():Float { return m_zMax; }
	private function set_zMax(v:Float):Float { m_zMax = v; Validate(); return v; }
	
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Vector3.temp.Set(xMin + (xMax - xMin) * 0.5, yMin + (yMax - yMin) * 0.5, zMin + (zMax - zMin) * 0.5); }
	private function set_center(v:Vector3):Vector3 
	{ 
		var hw:Float = width * 0.5;
		var hh:Float = height * 0.5;
		var hd:Float = depth * 0.5;
		m_xMin = v.x - hw;
		m_xMax = v.x + hw;
		m_yMin = v.y - hh;
		m_yMax = v.y + hh;
		m_zMin = v.z - hd;
		m_zMax = v.z + hd;
		Validate();
		return v;
	}
	
	public var x(get_x, set_x):Float;
	private function get_x():Float { return get_xMin(); }
	private function set_x(v:Float):Float { set_xMin(v); return v; }
	
	public var y(get_y, set_y):Float;
	private function get_y():Float { return get_yMin(); }
	private function set_y(v:Float):Float { set_yMin(v); return v; }
	
	public var z(get_z, set_z):Float;
	private function get_z():Float { return get_zMin(); }
	private function set_z(v:Float):Float { set_zMin(v); return v; }
	
	
	public var width(get_width, set_width):Float;
	private function get_width():Float { return Mathf.Abs(xMax - xMin); }
	private function set_width(v:Float):Float { xMax = xMin + v; return v; }
	
	public var height(get_height, set_height):Float;
	private function get_height():Float { return Mathf.Abs(yMax - yMin); }
	private function set_height(v:Float):Float { yMax = yMin + v; return v; }
	
	public var depth(get_depth, set_depth):Float;
	private function get_depth():Float { return Mathf.Abs(zMax - zMin); }
	private function set_depth(v:Float):Float { zMax = zMin + v; return v; }
	
	public var size(get_size, set_size):Vector3;
	private function get_size():Vector3 { return Vector3.temp.Set(width, height,depth); }
	private function set_size(v:Vector3):Vector3 { width = v.x; height = v.y; depth = v.z; return v; }
	
	public function new(p_x:Float = 0, p_y : Float =0,p_z : Float=0, p_width:Float = 0,p_height : Float=0,p_depth : Float=0)
	{            
		m_xMin = p_x;
		m_yMin = p_y;
		m_zMin = p_y;
		m_xMax = m_xMin + p_width;
		m_yMax = m_yMin + p_height;
		m_zMax = m_zMin + p_depth;
	}
	
	private function Validate():Void
	{
		var x0 : Float = m_xMin;
		var x1 : Float = m_xMax;
		var y0 : Float = m_yMin;
		var y1 : Float = m_yMax;
		var z0 : Float = m_zMin;
		var z1 : Float = m_zMax;
		if (x0 <= x1) { m_xMin = x0; m_xMax = x1; } else { m_xMin = x1; m_xMax = x0; }
		if (y0 <= y1) { m_yMin = y0; m_yMax = y1; } else { m_yMin  = y1; m_yMax = y0; }
		if (z0 <= z1) { m_zMin = z0; m_zMax = z1; } else { m_zMin  = z1; m_zMax = z0; }
	}

	/**
	 * 
	 * @param	p_point
	 */
	public function Encapsulate(p_point:Vector3):Void
	{
		Encapsulate3(p_point.x, p_point.y, p_point.z);           
	}
	
	/**
	 * 
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : AABB3):AABB3
	{
		m_xMax = Mathf.Max([p_v.m_xMax, m_xMax]);
		m_xMin = Mathf.Min([p_v.m_xMin, m_xMin]);
		m_yMax = Mathf.Max([p_v.m_yMax, m_yMax]);
		m_yMin = Mathf.Min([p_v.m_yMin, m_yMin]);
		m_zMax = Mathf.Max([p_v.m_zMax, m_zMax]);
		m_zMin = Mathf.Min([p_v.m_zMin, m_zMin]);
		return this;
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function Encapsulate3(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0):Void
	{
		xMin = Mathf.Min([p_x, xMin]);
		xMax = Mathf.Max([p_x, xMax]);
		yMin = Mathf.Min([p_y, yMin]);
		yMax = Mathf.Max([p_y, yMax]);            
		zMin = Mathf.Min([p_z, zMin]);
		zMax = Mathf.Max([p_z, zMax]);            
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	public function ToString():String
	{		
		var s0:String = Mathf.RoundPlaces(m_xMin,4)+"";
		var s1:String = Mathf.RoundPlaces(m_xMax,4)+"";
		var s2:String = Mathf.RoundPlaces(m_yMin,4)+"";
		var s3:String = Mathf.RoundPlaces(m_yMax,4)+"";
		var s4:String = Mathf.RoundPlaces(m_zMin,4)+"";
		var s5:String = Mathf.RoundPlaces(m_zMax,4)+"";
		
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "|" +s4+","+s5+"]";
	}
	
	function toString():String { return ToString(); }
}