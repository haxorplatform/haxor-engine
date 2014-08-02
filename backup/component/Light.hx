package haxor.component;

import js.html.Float32Array;
import haxor.core.Entity;
import haxor.math.Color;
import haxor.math.Vector3;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Light extends Behaviour
{
	static public var ambient : Color 	= new Color(0.0, 0.0, 0.0, 1.0);
	
	static public var max : Int 		= 8;
	
	static private var m_buffer : Float32Array;
	
	static private function SetLightData(p_id : Int, p_type : Float, p_intensity:Float, p_radius:Float, p_atten:Float, p_x:Float,p_y:Float,p_z:Float,p_r:Float,p_g:Float,p_b:Float,p_a:Float):Void
	{
		var pos : Int = p_id * 12;  	 // id * 3 * 4
		m_buffer[pos + 0] = p_type; 	 // attrib.x
		m_buffer[pos + 1] = p_intensity; // attrib.y
		m_buffer[pos + 2] = p_radius;    // attrib.z
		m_buffer[pos + 3] = p_atten;     // attrib.w
		
		m_buffer[pos + 4] = p_x;
		m_buffer[pos + 5] = p_y;
		m_buffer[pos + 6] = p_z;
		//m_buffer[pos + 7] = 0.0;
		
		m_buffer[pos + 8] = p_r;
		m_buffer[pos + 9] = p_g;
		m_buffer[pos +10] = p_b;
		m_buffer[pos +11] = p_a;
		
	}
	
	
	/**
	 * 
	 */
	static public var list(get_list, null) : Array<Light>;
	static private var m_list : Array<Light> = [];
	static private function get_list():Array<Light>
	{
		var l:Array<Light> = new Array<Light>();
		if (m_list == null) return l;
		var i:Int = 0;
		while (i < m_list.length) { l.push(m_list[i]); i++; }		
		return l;
	}
	
	public var color	 : Color;
	
	public var intensity : Float;

	public function new(p_entity:Entity) 
	{
		if (m_list == null) m_list = [];
		if (m_buffer == null) m_buffer = new Float32Array(12 * max);
		m_list.push(this);
		
		super(p_entity);
		color 		= Color.white;
		intensity 	= 1.0;
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		m_list.remove(this);
	}
	
}