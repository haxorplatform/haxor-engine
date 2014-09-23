package haxor.math;
import haxor.context.EngineContext;
import haxor.platform.Types.Float32;

/**
 * Class that represents 2D Axis Aligned Bounding Box.
 * @author Eduardo Pons
 */
class AABB2
{
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup. [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):AABB2; 
	static private inline function get_temp():AABB2 { return EngineContext.data.aabb2; }
	
	/**
	 * Creates a new AABB2 with the informed min/max.
	 * @param	p_xmin
	 * @param	p_xmax
	 * @param	p_ymin
	 * @param	p_ymax
	 * @return
	 */
	static public function FromMinMax(p_xmin : Float32, p_xmax : Float32, p_ymin:Float32, p_ymax : Float32 ) :AABB2
	{
		var b : AABB2 = new AABB2();
		b.m_xMin = p_xmin;
		b.m_xMax = p_xmax;
		b.m_yMin = p_ymin;
		b.m_yMax = p_ymax;
		b.Validate();
		return b;
	}
	
	/**
	 * Returns a new AABB2 with size zero and center at origin.
	 */
	static public var empty(get_empty, null):AABB2;
	static private function get_empty():AABB2 { return new AABB2(); }	

	/**
	 * Returns a copy of this instance.
	 */
	public var clone(get_clone, null):AABB2;
	private function get_clone():AABB2 { return FromMinMax(xMin, xMax, yMin, yMax); }
	
	public var min(get_min, set_min):Vector2;
	private function get_min():Vector2 { return new Vector2(m_xMin, m_yMin); }
	private function set_min(v:Vector2):Vector2 { xMin = v.x; yMin = v.y; return v; }
	
	public var max(get_max, set_max):Vector2;
	private function get_max():Vector2 { return new Vector2(m_xMax, m_yMax); }
	private function set_max(v:Vector2):Vector2 { xMax = v.x; yMax = v.y; return v; }
	
	public var xMin(get_xMin, set_xMin):Float32;		
	private function get_xMin():Float32{ return m_xMin; }
	private function set_xMin(v:Float32):Float32{ m_xMin = v; Validate(); return v; }	
	private var m_xMin:Float32;
	
	public var yMin(get_yMin, set_yMin):Float32;		
	private function get_yMin():Float32{ return m_yMin; }
	private function set_yMin(v:Float32):Float32{ m_yMin = v; Validate(); return v; }	
	private var m_yMin:Float32;
	
	public var xMax(get_xMax, set_xMax):Float32;		
	private function get_xMax():Float32{ return m_xMax; }
	private function set_xMax(v:Float32):Float32{ m_xMax = v; Validate(); return v; }	
	private var m_xMax:Float32;
	
	public var yMax(get_yMax, set_yMax):Float32;		
	private function get_yMax():Float32{ return m_yMax; }
	private function set_yMax(v:Float32):Float32{ m_yMax = v; Validate(); return v; }
	private var m_yMax:Float32;
	
	public var center(get_center, set_center):Vector2;
	private function get_center():Vector2 { return new Vector2(xMin + (xMax - xMin) * 0.5, yMin + (yMax - yMin) * 0.5); }
	private function set_center(v:Vector2):Vector2 
	{ 
		var hw:Float32= width * 0.5;
		var hh:Float32= height * 0.5;
		m_xMin = v.x - hw;
		m_xMax = v.x + hw;
		m_yMin = v.y - hh;
		m_yMax = v.y + hh;
		return v;
	}
	
	public var x(get_x, set_x):Float32;
	private inline function get_x():Float32{ return get_xMin(); }
	private inline function set_x(v:Float32):Float32{ set_xMin(v); return v; }
	
	public var y(get_y, set_y):Float32;
	private inline function get_y():Float32{ return get_yMin(); }
	private inline function set_y(v:Float32):Float32{ set_yMin(v); return v; }
	
	
	public var width(get_width, set_width):Float32;
	private inline function get_width():Float32{ return Mathf.Abs(xMax - xMin); }
	private inline function set_width(v:Float32):Float32{ xMax = xMin + v; return v; }
	
	public var height(get_height, set_height):Float32;
	private inline function get_height():Float32{ return Mathf.Abs(yMax - yMin); }
	private inline function set_height(v:Float32):Float32{ yMax = yMin + v; return v; }
	
	public var size(get_size, set_size):Vector2;
	private inline function get_size():Vector2 { return new Vector2(width, height); }
	private inline function set_size(v:Vector2):Vector2 { width = v.x; height = v.y; return v; }
	
	/**
	 * Creates a new AABB2.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function new(p_x:Float32= 0, p_y : Float32 =0, p_width:Float32= 0,p_height : Float=0)
	{            
		SetXYWH(p_x, p_y, p_width, p_height);
	}
	
	/**
	 * Adjusts all min/max values so they stay in the correct order.
	 */
	private function Validate():Void
	{
		/*
		var x0 : Float32 = m_xMin;
		var x1 : Float32 = m_xMax;
		var y0 : Float32 = m_yMin;
		var y1 : Float32 = m_yMax;
		if (x0 <= x1) { m_xMin = x0; m_xMax = x1; } else { m_xMin = x1; m_xMax = x0; }
		if (y0 <= y1) { m_yMin = y0; m_yMax = y1; } else { m_yMin  = y1; m_yMax = y0; }
		//*/
	}
	
	/**
	 * Increases this AABB area using another AABB
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : AABB2):AABB2
	{
		m_xMax = Mathf.Max(p_v.m_xMax, m_xMax);
		m_xMin = Mathf.Min(p_v.m_xMin, m_xMin);
		m_yMax = Mathf.Max(p_v.m_yMax, m_yMax);
		m_yMin = Mathf.Min(p_v.m_yMin, m_yMin);		
		return this;
	}
	
	/**
	 * Sets this AABB limits. Returns its own reference.
	 * @param	p_xmin
	 * @param	p_xmax
	 * @param	p_ymin
	 * @param	p_ymax
	 * @return
	 */
	public function Set(p_xmin:Float32, p_xmax:Float32, p_ymin:Float32, p_ymax:Float32):AABB2
	{
		m_xMin = p_xmin;
		m_yMin = p_ymin;		
		m_xMax = p_xmax;
		m_yMax = p_ymax;		
		Validate();
		return this;
	}
	
	/**
	 * Sets this AABB2 limits using x,y,width and height.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @return
	 */
	public function SetXYWH(p_x:Float32, p_y:Float32, p_width:Float32, p_height:Float32):AABB2
	{
		m_xMin = p_x;
		m_yMin = p_y;
		m_xMax = m_xMin + p_width;
		m_yMax = m_yMin + p_height;
		return this;
	}
	
	/**
	 * Copies the values of the informed AABB2 into this instance.  Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function SetAABB2(p_v : AABB2):AABB2
	{
		m_xMin = p_v.m_xMin;
		m_yMin = p_v.m_yMin;		
		m_xMax = p_v.m_xMax;
		m_yMax = p_v.m_yMax;		
		return this;
	}

	/**
	 * Expands this AABB area to enclose the informed point.
	 * @param	p_point
	 */
	public function Encapsulate(p_point:Vector2):Void
	{
		xMin = Mathf.Min(p_point.x, xMin);
		xMax = Mathf.Max(p_point.x, xMax);
		yMin = Mathf.Min(p_point.y, yMin);
		yMax = Mathf.Max(p_point.y, yMax);            
	}
	
	/**
	 * Increases this AABB area to enclosure the informed point component-wise.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function Encapsulate3(p_x:Float32= 0, p_y:Float32= 0):AABB2
	{
		m_xMin = Mathf.Min(p_x, m_xMin);
		m_xMax = Mathf.Max(p_x, m_xMax);
		m_yMin = Mathf.Min(p_y, m_yMin);
		m_yMax = Mathf.Max(p_y, m_yMax);            
		Validate();
		return this;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	public function ToString(p_places:Int=2):String
	{		
		var s0:String = Mathf.RoundPlaces(m_xMin,p_places)+"";
		var s1:String = Mathf.RoundPlaces(m_xMax,p_places)+"";
		var s2:String = Mathf.RoundPlaces(m_yMin,p_places)+"";
		var s3:String = Mathf.RoundPlaces(m_yMax,p_places)+"";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
}