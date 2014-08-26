package haxor.component;

import haxor.core.Entity;
import haxor.io.FloatArray;
import haxor.math.Color;
import haxor.math.Vector3;

/**
 * Base class that describes all Lights in Haxor.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Light extends Behaviour
{
	/**
	 * Ambient global color.
	 */
	static public var ambient : Color 	= new Color(0.0, 0.0, 0.0, 1.0);
	
	/**
	 * Max number of lights.
	 */
	static public var max : Int = 8;
	
	/**
	 * Float array that will contain the raw light information for shaders.
	 */
	static private var m_buffer : FloatArray;
	
	/**
	 * List of all lights in the scene.
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
	
	/**
	 * Color of this light.
	 */
	public var color	 : Color;
	
	/**
	 * Intensity of this light.
	 */
	public var intensity : Float;

	/**
	 * Creates a new Light.
	 */
	private function new() 
	{
		if (m_list == null) m_list = [];
		if (m_buffer == null) m_buffer = new FloatArray(12 * max);
		m_list.push(this);		
		super();
		color 		= Color.white;
		intensity 	= 1.0;
	}
	
	/**
	 * Callback called when this resource is destroyed.
	 */
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		m_list.remove(this);
	}
	
	/**
	 * Auxiliar method to update this data uniform.
	 * @param	p_id
	 * @param	p_type
	 * @param	p_intensity
	 * @param	p_radius
	 * @param	p_atten
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 */
	static private function SetLightData(p_id : Int, p_type : Float, p_intensity:Float, p_radius:Float, p_atten:Float, p_x:Float,p_y:Float,p_z:Float,p_r:Float,p_g:Float,p_b:Float,p_a:Float):Void
	{
		var pos : Int = p_id * 12;  	 // id * 3 * 4
		m_buffer.Set(pos + 0,p_type); 	 // attrib.x
		m_buffer.Set(pos + 1,p_intensity); // attrib.y
		m_buffer.Set(pos + 2,p_radius);    // attrib.z
		m_buffer.Set(pos + 3,p_atten);     // attrib.w		
		m_buffer.Set(pos + 4,p_x);
		m_buffer.Set(pos + 5,p_y);
		m_buffer.Set(pos + 6,p_z);		
		m_buffer.Set(pos + 8,p_r);
		m_buffer.Set(pos + 9,p_g);
		m_buffer.Set(pos +10,p_b);
		m_buffer.Set(pos +11,p_a);
		//m_buffer[pos + 7] = 0.0;		
	}
	
}