package haxor.physics;
import haxor.core.Resource;

/**
 * Class that describes the physical properties of a collider.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class PhysicsMaterial extends Resource
{
	/**
	 * 
	 */
	static public var empty(get_empty, never):PhysicsMaterial;
	static private var m_empty : PhysicsMaterial;
	static private function get_empty():PhysicsMaterial 
	{ 
		if (m_empty != null) return m_empty; 
		m_empty = new PhysicsMaterial();
		m_empty.name = "$DefaultPhysicsMaterial";
		return m_empty;
	}	
	
	/**
	 * 
	 */
	public var bounce : Float;
	
	/**
	 * 
	 */
	public var friction : Float;

	/**
	 * 
	 */
	public function new() 
	{
		super();
		bounce   = 0.0;
		friction = 0.0;
	}
	
}