package haxor.math;

import haxor.context.EngineContext;
import haxor.platform.Types.Float32;

/**
 * Class that describes a 3D Axis Aligned Bounding Box.
 * @author Eduardo Pons
 */
class AABB3
{
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup. [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):AABB3; 
	static private inline function get_temp():AABB3 { return EngineContext.data.aabb3; }
	
	/**
	 * Returns the center of the informed AABB3.
	 * @param	p_b
	 * @param	p_result
	 * @return
	 */
	static public function Center(p_b : AABB3, p_result:Vector3 = null):Vector3
	{
		var v : Vector3 = p_result == null ? Vector3.zero : p_result;
		return v.Set(
		p_b.m_xMin + (p_b.m_xMax - p_b.m_xMin) * 0.5, 
		p_b.m_yMin + (p_b.m_yMax - p_b.m_yMin) * 0.5, 
		p_b.m_zMin + (p_b.m_zMax - p_b.m_zMin) * 0.5);		
	}
	
	/**
	 * Creates an AABB3 using min/max limits.
	 * @param	p_xmin
	 * @param	p_xmax
	 * @param	p_ymin
	 * @param	p_ymax
	 * @param	p_zmin
	 * @param	p_zmax
	 * @return
	 */
	static public function FromMinMax(p_xmin : Float32, p_xmax : Float32, p_ymin:Float32, p_ymax : Float32, p_zmin:Float32, p_zmax : Float32,p_result:AABB3=null) :AABB3
	{
		var b : AABB3 = p_result == null ? (new AABB3()) : p_result;
		b.xMin = p_xmin;
		b.xMax = p_xmax;
		b.yMin = p_ymin;
		b.yMax = p_ymax;
		b.zMin = p_zmin;
		b.zMax = p_zmax;
		return b;
	}
	
	/**
	 * Creates an AABB3 around the informed point.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_width
	 * @param	p_height
	 * @param	p_depth
	 * @return
	 */
	static public function FromCenter(p_x : Float32, p_y : Float32, p_z:Float32, p_width : Float32, p_height:Float32, p_depth : Float32,p_result:AABB3=null) :AABB3
	{
		var b : AABB3 = p_result == null ? new AABB3() : p_result;
		b.width  = p_width;
		b.height = p_height;
		b.depth  = p_depth;
		b.center = new Vector3(p_x, p_y, p_z);
		return b;
	}
	
	/**
	 * Returns a new AABB3 with size zero and center at origin.
	 */
	static public var empty(get_empty, null):AABB3;
	static private function get_empty():AABB3 { return new AABB3(); }	

	/**
	 * Creates a copy of this AABB3.
	 */
	public var clone(get_clone, null):AABB3;
	private function get_clone():AABB3 { return FromMinMax(xMin, xMax, yMin, yMax,zMin,zMax); }
	
	
	public var min(get_min, set_min):Vector3;
	private inline function get_min():Vector3 { return new Vector3(m_xMin, m_yMin); }
	private inline function set_min(v:Vector3):Vector3 { xMin = v.x; yMin = v.y; return v; }
	
	public var max(get_max, set_max):Vector3;
	private inline function get_max():Vector3 { return new Vector3(m_xMax, m_yMax); }
	private inline function set_max(v:Vector3):Vector3 { xMax = v.x; yMax = v.y; return v; }
	
	public var xMin(get_xMin, set_xMin):Float32;	
	private inline function get_xMin():Float32{ return m_xMin; }
	private function set_xMin(v:Float32):Float32{ m_xMin = v; Validate(); return v; }	
	private var m_xMin:Float32;	
	
	public var yMin(get_yMin, set_yMin):Float32;	
	private inline function get_yMin():Float32{ return m_yMin; }
	private function set_yMin(v:Float32):Float32{ m_yMin = v; Validate(); return v; }
	private var m_yMin:Float32;	
	
	public var zMin(get_zMin, set_zMin):Float32;	
	private inline function get_zMin():Float32{ return m_zMin; }
	private function set_zMin(v:Float32):Float32{ m_zMin = v; Validate(); return v; }
	private var m_zMin:Float32;	
	
	public var xMax(get_xMax, set_xMax):Float32;	
	private inline function get_xMax():Float32{ return m_xMax; }
	private function set_xMax(v:Float32):Float32{ m_xMax = v; Validate(); return v; }	
	private var m_xMax:Float32;	
	
	public var yMax(get_yMax, set_yMax):Float32;	
	private inline function get_yMax():Float32{ return m_yMax; }
	private function set_yMax(v:Float32):Float32{ m_yMax = v; Validate(); return v; }
	private var m_yMax:Float32;	
	
	public var zMax(get_zMax, set_zMax):Float32;	
	private inline function get_zMax():Float32{ return m_zMax; }
	private function set_zMax(v:Float32):Float32{ m_zMax = v; Validate(); return v; }
	private var m_zMax:Float32;	
	
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Center(this); }
	private function set_center(v:Vector3):Vector3 
	{ 
		var hw:Float32= width * 0.5;
		var hh:Float32= height * 0.5;
		var hd:Float32= depth * 0.5;
		m_xMin = v.x - hw;
		m_xMax = v.x + hw;
		m_yMin = v.y - hh;
		m_yMax = v.y + hh;
		m_zMin = v.z - hd;
		m_zMax = v.z + hd;
		Validate();
		return v;
	}
	
	public var x(get_x, set_x):Float32;
	private inline function get_x():Float32{ return get_xMin(); }
	private inline function set_x(v:Float32):Float32{ set_xMin(v); return v; }
	
	public var y(get_y, set_y):Float32;
	private inline function get_y():Float32{ return get_yMin(); }
	private inline function set_y(v:Float32):Float32{ set_yMin(v); return v; }
	
	public var z(get_z, set_z):Float32;
	private inline function get_z():Float32{ return get_zMin(); }
	private inline function set_z(v:Float32):Float32{ set_zMin(v); return v; }
	
	
	public var width(get_width, set_width):Float32;
	private inline function get_width():Float32{ return Mathf.Abs(xMax - xMin); }
	private inline function set_width(v:Float32):Float32{ xMax = xMin + v; return v; }
	
	public var height(get_height, set_height):Float32;
	private inline function get_height():Float32{ return Mathf.Abs(yMax - yMin); }
	private inline function set_height(v:Float32):Float32{ yMax = yMin + v; return v; }
	
	public var depth(get_depth, set_depth):Float32;
	private inline function get_depth():Float32{ return Mathf.Abs(zMax - zMin); }
	private inline function set_depth(v:Float32):Float32{ zMax = zMin + v; return v; }
	
	public var size(get_size, set_size):Vector3;
	private inline function get_size():Vector3 { return Vector3.zero.Set(width, height,depth); }
	private inline function set_size(v:Vector3):Vector3 { width = v.x; height = v.y; depth = v.z; return v; }
	
	/**
	 * Creates a new AABB3 with the desired dimensions.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_width
	 * @param	p_height
	 * @param	p_depth
	 */
	public function new(p_x:Float32= 0, p_y : Float32 =0,p_z : Float=0, p_width:Float32= 0,p_height : Float=0,p_depth : Float=0)
	{            
		m_xMin = p_x;
		m_yMin = p_y;
		m_zMin = p_y;
		m_xMax = m_xMin + p_width;
		m_yMax = m_yMin + p_height;
		m_zMax = m_zMin + p_depth;
	}
	
	/**
	 * Adjusts all min/max values so they stay in the correct order.
	 */
	private function Validate():Void
	{
		var x0 : Float32 = m_xMin;
		var x1 : Float32 = m_xMax;
		var y0 : Float32 = m_yMin;
		var y1 : Float32 = m_yMax;
		var z0 : Float32 = m_zMin;
		var z1 : Float32 = m_zMax;
		if (x0 <= x1) { m_xMin = x0; m_xMax = x1; } else { m_xMin = x1; m_xMax = x0; }
		if (y0 <= y1) { m_yMin = y0; m_yMax = y1; } else { m_yMin  = y1; m_yMax = y0; }
		if (z0 <= z1) { m_zMin = z0; m_zMax = z1; } else { m_zMin  = z1; m_zMax = z0; }
	}

	/**
	 * Increases this AABB area using another AABB
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : AABB3):AABB3
	{
		m_xMax = Mathf.Max(p_v.m_xMax, m_xMax);
		m_xMin = Mathf.Min(p_v.m_xMin, m_xMin);
		m_yMax = Mathf.Max(p_v.m_yMax, m_yMax);
		m_yMin = Mathf.Min(p_v.m_yMin, m_yMin);
		m_zMax = Mathf.Max(p_v.m_zMax, m_zMax);
		m_zMin = Mathf.Min(p_v.m_zMin, m_zMin);
		return this;
	}
	
	/**
	 * Sets this AABB limits. Returns its own reference.
	 * @param	p_xmin
	 * @param	p_xmax
	 * @param	p_ymin
	 * @param	p_ymax
	 * @param	p_zmin
	 * @param	p_zmax
	 * @return
	 */
	public function Set(p_xmin:Float32, p_xmax:Float32, p_ymin:Float32, p_ymax:Float32, p_zmin:Float32, p_zmax:Float32):AABB3
	{
		m_xMin = p_xmin;
		m_yMin = p_ymin;
		m_zMin = p_zmin;		
		m_xMax = p_xmax;
		m_yMax = p_ymax;
		m_zMax = p_zmax;
		Validate();
		return this;
	}
	
	/**
	 * Copies the values of the informed AABB3 into this instance.  Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function SetAABB3(p_v : AABB3):AABB3
	{
		m_xMin = p_v.m_xMin;
		m_yMin = p_v.m_yMin;
		m_zMin = p_v.m_zMin;		
		m_xMax = p_v.m_xMax;
		m_yMax = p_v.m_yMax;
		m_zMax = p_v.m_zMax;
		return this;
	}
	
	/**
	 * Sets this AABB3 limits using x,y,width and height.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @return
	 */
	public function SetXYZWHD(p_x:Float32= 0, p_y : Float32 =0,p_z : Float=0, p_width:Float32= 0,p_height : Float=0,p_depth : Float=0):AABB3
	{
		m_xMin = p_x;
		m_yMin = p_y;
		m_zMin = p_y;
		m_xMax = m_xMin + p_width;
		m_yMax = m_yMin + p_height;
		m_zMax = m_zMin + p_depth;
		return this;
	}
	
	/**
	 * Increases this AABB area to enclosure the informed point.
	 * @param	p_point
	 */
	public inline function Encapsulate(p_point:Vector3):AABB3 { return Encapsulate3(p_point.x, p_point.y, p_point.z); }
	
	/**
	 * Increases this AABB area to enclosure the informed point component-wise.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function Encapsulate3(p_x:Float32= 0, p_y:Float32= 0, p_z:Float32= 0):AABB3
	{
		m_xMin = Mathf.Min(p_x, m_xMin);
		m_xMax = Mathf.Max(p_x, m_xMax);
		m_yMin = Mathf.Min(p_y, m_yMin);
		m_yMax = Mathf.Max(p_y, m_yMax);            
		m_zMin = Mathf.Min(p_z, m_zMin);
		m_zMax = Mathf.Max(p_z, m_zMax);            
		Validate();
		return this;
	}

	/**
	 * Returns this class string representation.
	 * @param	p_places
	 * @return
	 */
	public function ToString(p_places:Int=2):String
	{		
		var s0:String = Mathf.RoundPlaces(m_xMin,p_places)+"";
		var s1:String = Mathf.RoundPlaces(m_xMax,p_places)+"";
		var s2:String = Mathf.RoundPlaces(m_yMin,p_places)+"";
		var s3:String = Mathf.RoundPlaces(m_yMax,p_places)+"";
		var s4:String = Mathf.RoundPlaces(m_zMin,p_places)+"";
		var s5:String = Mathf.RoundPlaces(m_zMax,p_places)+"";		
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "|" +s4+","+s5+"]";
	}
	
}