package haxor.component;

import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.core.Time;
import haxor.graphics.mesh.Mesh;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

#if !ie8
import haxor.graphics.Graphics;
#end

/**
 * Class that describes a Renderer that uses a Mesh as buffer.
 * @author Eduardo Pons
 */
@:allow(haxor)
class MeshRenderer extends Renderer
{
	static public var current : MeshRenderer;
	
	/**
	 * Id used for frustum culling optimization.
	 */
	private var __fcid:Int;
	
	/**
	 * Reference to this renderer mesh.
	 */
	public var mesh (get_mesh, set_mesh) : Mesh;	
	private inline function get_mesh():Mesh { return m_mesh; }
	private function set_mesh(v:Mesh):Mesh { if (m_mesh == v) return v; m_mesh = v; UpdateWorldBounds(); return v; }
	private var m_mesh : Mesh;
	
	/**
	 * World space bounding position.
	 */
	private var m_ws_center : Vector3;
	
	/**
	 * World radius vector.
	 */
	private var m_ws_radius : Vector3;
	
	/**
	 * 
	 */
	private var m_aabb : AABB3;
	
	/**
	 * Flag that indicates that the culling must be retested.
	 */
	private var m_culling_dirty:Bool;
	
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{			
		m_has_mesh  = true;
		super.OnBuild();				
		m_ws_center = Vector3.zero;
		m_ws_radius = Vector3.zero;
		m_culling_dirty = false;		
		m_aabb = AABB3.empty;
	}
	
	/**
	 * Returns the visibility status of this renderer in the informed camera field of vision.
	 * @param	p_camera
	 * @return
	 */
	public function IsVisible(p_camera : Camera):Bool
	{
		var c : Camera = p_camera;
		if (c == null) 		return false;
		if (mesh == null) 	return false;	
		
		var ps_center : Vector4 = c.WorldToProjection(Vector3.temp.Set3(m_ws_center), Vector4.temp);				
		var w : Float32 = ps_center.w;
		var p : Vector4 = ps_center;
		
		if (w <= 0.0) return false;
		
		//If center is not culled, no need to check radius.
		if (p.x >= -w)
		if (p.x <=  w)
		if (p.y >= -w)
		if (p.y <=  w)
		if (p.z >= -w)
		if (p.z <=  w)  return true;
		
		var v : Vector4 = c.WorldToProjection(Vector3.temp.Set3(m_ws_radius), Vector4.temp);	
		var r : Float32 	= v.length;
		
		if (p.x+r >= -w)
		if (p.x-r <=  w)
		if (p.y+r >= -w)
		if (p.y-r <=  w)
		if (p.z+r >= -w)
		if (p.z-r <=  w)  return true;
		
		return false;
	}
	
	/**
	 * Checks this renderer culling using the current camera.
	 * @return
	 */
	override function CheckCulling():Bool 
	{
		var c : Camera = Camera.current;
		if (c == null) return m_culled;
		
		if (!c.m_view_uniform_dirty)
		if (!c.m_proj_uniform_dirty)
		if (!m_culling_dirty) return m_culled;
		UpdateWorldBounds();
		return !IsVisible(c);
	}
	
	/**
	 * Updates culling and other data.
	 */
	override function OnTransformUpdate(p_hierarchy : Bool):Void 
	{		
		m_culling_dirty = true;			
	}
		
	
	/**
	 * Update this renderer bounds in world space.
	 */
	private function UpdateWorldBounds():Void
	{
		if (mesh != null)
		{			
			
			//world bounding sphere center
			AABB3.Center(mesh.m_bounds, m_ws_center);
			
			transform.WorldMatrix.Transform3x4(m_ws_center);
			
			//world bounding sphere radius
			m_ws_radius.Set(mesh.m_bounds.width, mesh.m_bounds.height, mesh.m_bounds.depth);
			transform.WorldMatrix.Transform3x3(m_ws_radius);
			
			var r : Float32 = m_ws_radius.length*0.5;
			var pmin : Vector3 = Vector3.temp;
			var pmax : Vector3 = Vector3.temp;
			pmin.Set(m_ws_center.x - r, m_ws_center.y - r, m_ws_center.z - r);
			pmax.Set(m_ws_center.x + r, m_ws_center.y + r, m_ws_center.z + r);
			m_aabb.Set3(pmin, pmax);
			EngineContext.renderer.UpdateSAP(__fcid, this, pmin, pmax);
			
			m_culling_dirty = false;
		}
	}
	
	/**
	 * Renders the Mesh using Material.
	 */
	override public function OnRender() : Void 
	{			
		super.OnRender();		
		if (m_mesh == null) return;	
		
		current = this;		
		#if !ie8		
		Graphics.Render(m_mesh, material, entity.transform, Camera.current);
		#end
	}
	
}