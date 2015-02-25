package haxor.component.light;

import haxor.core.Entity;
import haxor.io.FloatArray;
import haxor.math.Color;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;


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
	static private var m_buffer : Array<Float32> = 
	[ 
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	];
	
	/**
	 * List of all lights in the scene.
	 */
	static public var list(get_list, null) : Array<Light>;
	static private var m_list : Array<Light> = [];
	static private function get_list():Array<Light>
	{
		return m_list.copy();
	}
	
	/**
	 * Color of this light.
	 */
	public var color	 : Color;
	
	/**
	 * Intensity of this light.
	 */
	public var intensity : Float32;

	/**
	 * Creates a new Light.
	 */
	private function new() 
	{
		if (m_list == null) m_list = [];
		if(m_buffer.length<=0) for (i in 0...(12 * max)) m_buffer.push(0.0);
		m_list.push(this);		
		super();		
	}
	
	override function OnBuild():Void 
	{
		super.OnBuild();
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
	static private function SetLightData(p_id : Int, p_type : Float32, p_intensity:Float32, p_radius:Float32, p_atten:Float32, p_x:Float32,p_y:Float32,p_z:Float32,p_r:Float32,p_g:Float32,p_b:Float32,p_a:Float32):Void
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
	
}