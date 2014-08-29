package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.graphics.material.Material;


/**
 * Base class for all rendering elements in Haxor.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Renderer extends Behaviour
{
	
	/**
	 * Reference to this renderer material.
	 */
	public var material(get_material, set_material) : Material;
	private inline function get_material():Material { return m_material; }
	private function set_material(v:Material):Material 
	{ 
		if (m_material == v) return v;
		m_material = v; 
		m_last_queue = (v == null) ? -1 : v.queue;
		EngineContext.renderer.OnMaterialChange(this); 
		return v; 
	}
	private var m_material : Material;
	
	/**
	 * Flag to speedup detection of MeshRenderers
	 */
	private var m_has_mesh : Bool;
	
	/**
	 * Cache for the last material render queue to detect changes.
	 */
	private var m_last_queue : Int;
		
	/**
	 * Method called after component creation.
	 */
	override private function OnBuild():Void 
	{
		super.OnBuild();
		__cid = EngineContext.renderer.rid.id;
		m_has_mesh 		= false;
		m_last_queue 	= -1;		
	}
	/**
	 * Callback to execute the rendering routines.
	 */
	private function OnRender() : Void 
	{
		if(m_material != null)
		if (m_last_queue != m_material.queue)
		{
			m_last_queue = m_material.queue;
			EngineContext.renderer.OnMaterialChange(this);
		}
	}
	
	/**
	 * Destroy callback.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.renderer.Destroy(this);
	}
	
}