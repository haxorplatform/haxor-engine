package haxor.component;

import haxor.core.Entity;
import haxor.math.Color;

/**
 * ...
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
	static public function Create(p_color : Color, p_intensity:Float, p_atten :Float, p_radius : Float):PointLight
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
	
	public var atten : Float;

	public var radius : Float;
	
	public function new(p_entity:Entity) 
	{
		super(p_entity);
		atten 	= 1.0;
		radius 	= 1.0;
	}
	
}