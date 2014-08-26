package haxor.component;
import haxor.core.Entity;
import haxor.graphics.material.Material;


/**
 * Base class for all rendering elements in Haxor.
 * @author Eduardo Pons
 */
class Renderer extends Behaviour
{
	
	/**
	 * Reference to this renderer material.
	 */
	public var material(get_material, set_material) : Material;
	private inline function get_material():Material { return m_material; }
	private function set_material(v:Material):Material { if (m_material == v) return v; m_material = v; return v; }
	private var m_material : Material;
	
	/**
	 * Internal constructor.
	 */
	function new() 
	{
		super();
	}
	
	/**
	 * Callback to execute the rendering routines.
	 */
	private function OnRender() : Void { }
	
}