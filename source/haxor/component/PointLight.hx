package haxor.component;
import haxor.core.Entity;
import haxor.math.Color;
import haxor.platform.Types.Float32;

/**
 * Class that describes a Point light.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class PointLight extends Light
{
	/**
	 * Creates a new PointLight with pre-configured data.
	 * @param	p_color
	 * @param	p_intensity
	 * @param	p_atten
	 * @param	p_radius
	 * @return
	 */
	static public function Create(p_color : Color, p_intensity:Float32, p_atten :Float32, p_radius : Float32):PointLight
	{
		var e : Entity = new Entity();
		e.name = "PointLight";
		var l : PointLight = e.AddComponent(PointLight);
		l.color 	= p_color;
		l.intensity = p_intensity;
		l.atten 	= p_atten;
		l.radius 	= p_radius;
		return l;
	}
	
	/**
	 * Attenuation exponent.
	 */
	public var atten : Float32;

	/**
	 * Light radius.
	 */
	public var radius : Float32;
	
	/**
	 * Creates a new Light.
	 */
	private function new() 
	{
		super();
		atten 	= 1.0;
		radius 	= 1.0;
	}
	
}