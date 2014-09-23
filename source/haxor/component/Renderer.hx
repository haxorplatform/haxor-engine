
package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.graphics.material.Material;
import haxor.math.Mathf;


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
	 * Returns a flag that indicates if this MeshRenderer is visible (either by the user intent or camera culling.
	 */
	public var visible(get_visible, never):Bool;
	private inline function get_visible():Bool { return m_visible && (!m_culled); }
	private function set_visible(v:Bool):Bool { m_visible = v; return v; }
	private var m_visible : Bool;
	private var m_culled : Bool;
	
	/**
	 * Flag to speedup detection of MeshRenderers
	 */
	private var m_has_mesh : Bool=false;
	
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
		m_last_queue 	= -1;
		m_visible	= true;
		m_culled    = false;				
		EngineContext.renderer.Create(this);
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
	 * Callback called by the engine to update this renderer culling flags.
	 */
	private function UpdateCulling():Void
	{
		//If visible. Can post-pone not-visibility culling a bit.
		//if (EngineContext.renderer.DeferredCulling(this)) return;
		var v0 : Bool = m_culled;
		var v1 : Bool = CheckCulling();		
		m_culled = v1;
		
		if (v0 != v1)
		{			
			EngineContext.renderer.OnVisibilityChange(this, !v1);
		}
	}
	
	/**
	 * Callback called so the renderer can update its internal culling flag. Return false to signal if this renderer isn't visible.
	 */
	private function CheckCulling():Bool { return false; }
	
	/**
	 * Destroy callback.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.renderer.Destroy(this);
	}
	
}
