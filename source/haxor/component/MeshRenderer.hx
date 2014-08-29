package haxor.component;

import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.core.Time;
import haxor.graphics.Graphics;
import haxor.graphics.mesh.Mesh;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * Class that describes a Renderer that uses a Mesh as buffer.
 * @author Eduardo Pons
 */
@:allow(haxor)
class MeshRenderer extends Renderer
{
	
	/**
	 * Reference to this renderer mesh.
	 */
	public var mesh (get_mesh, set_mesh) : Mesh;	
	private inline function get_mesh():Mesh { return m_mesh; }
	private function set_mesh(v:Mesh):Mesh { if (m_mesh == v) return v; m_mesh = v; return v; }
	private var m_mesh : Mesh;
	
	/**
	 * Returns a flag that indicates if this MeshRenderer is visible by the main camera.
	 */
	public var visible(get_visible, never):Bool;
	private inline function get_visible():Bool { return IsVisible(Camera.main); }
		
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		m_has_mesh = true;		
	}
	
	/**
	 * Returns the visibility status of this renderer in the informed camera field of vision.
	 * @param	p_camera
	 * @return
	 */
	public function IsVisible(p_camera : Camera):Bool
	{
		if (p_camera == null) return false;
		return true;
	}
	
	private function CheckCulling():Bool
	{	
		/*
		//Needs revision
		if (m_mesh == null) return false;
		var c : Camera 	 = Camera.current;
		var b : AABB3  	 = m_mesh.bounds;
		var p : Vector3  = Vector3.temp;		
		var ic : Bool    = m_culled.exists(c) ? m_culled.get(c) : true;			
		var wm : Matrix4 = transform.m_worldMatrix;		
		var p0 : Vector4;
		var p1 : Vector4;
		var p2 : Vector4;
		var p3 : Vector4;
		var p4 : Vector4;
		var p5 : Vector4;
		var p6 : Vector4;
		var p7 : Vector4;
		p.x = b.xMin; p.y = b.yMin; p.z = b.zMin; wm.Transform3x4(p); p0 = c.WorldToProjection(p); //if (!p0.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMin; p.z = b.zMin; wm.Transform3x4(p); p1 = c.WorldToProjection(p); //if (!p1.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMax; p.z = b.zMin; wm.Transform3x4(p); p2 = c.WorldToProjection(p); //if (!p2.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMax; p.z = b.zMin; wm.Transform3x4(p); p3 = c.WorldToProjection(p); //if (!p3.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMin; p.z = b.zMax; wm.Transform3x4(p); p4 = c.WorldToProjection(p); //if (!p4.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMin; p.z = b.zMax; wm.Transform3x4(p); p5 = c.WorldToProjection(p); //if (!p5.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMax; p.z = b.zMax; wm.Transform3x4(p); p6 = c.WorldToProjection(p); //if (!p6.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMax; p.z = b.zMax; wm.Transform3x4(p); p7 = c.WorldToProjection(p); //if (!p7.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		 var iw0 : Float = 1.0 / Mathf.Abs(p0.w);
		 var iw1 : Float = 1.0 / Mathf.Abs(p1.w);
		 var iw2 : Float = 1.0 / Mathf.Abs(p2.w);
		 var iw3 : Float = 1.0 / Mathf.Abs(p3.w);
		 var iw4 : Float = 1.0 / Mathf.Abs(p4.w);
		 var iw5 : Float = 1.0 / Mathf.Abs(p5.w);
		 var iw6 : Float = 1.0 / Mathf.Abs(p6.w);
		 var iw7 : Float = 1.0 / Mathf.Abs(p7.w);		 
		var v : Float;						
		v = Mathf.MaxRange([p0.z * iw0, p1.z * iw1, p2.z * iw2, p3.z * iw3, p4.z * iw4, p5.z * iw5, p6.z * iw6, p7.z * iw7]);  if (v < -1.0) return visible = false;		
		v = Mathf.MinRange([p0.x * iw0, p1.x * iw1, p2.x * iw2, p3.x * iw3, p4.x * iw4, p5.x * iw5, p6.x * iw6, p7.x * iw7]);  if (v >  1.0) return visible = false;
		v = Mathf.MaxRange([p0.x * iw0, p1.x * iw1, p2.x * iw2, p3.x * iw3, p4.x * iw4, p5.x * iw5, p6.x * iw6, p7.x * iw7]);  if (v < -1.0) return visible = false;		
		v = Mathf.MinRange([p0.y * iw0, p1.y * iw1, p2.y * iw2, p3.y * iw3, p4.y * iw4, p5.y * iw5, p6.y * iw6, p7.y * iw7]);  if (v >  1.0) return visible = false;
		v = Mathf.MaxRange([p0.y * iw0, p1.y * iw1, p2.y * iw2, p3.y * iw3, p4.y * iw4, p5.y * iw5, p6.y * iw6, p7.y * iw7]);  if (v < -1.0) return visible = false;		
		v = Mathf.MinRange([p0.z * iw0, p1.z * iw1, p2.z * iw2, p3.z * iw3, p4.z * iw4, p5.z * iw5, p6.z * iw6, p7.z * iw7]);  if (v >  1.0) return visible = false;		
		return visible = true;
		//*/
		return true;
	}
	
		
	/**
	 * Renders the Mesh using Material.
	 */
	override public function OnRender() : Void 
	{			
		super.OnRender();		
		if (m_mesh == null) return;			
		Graphics.Render(m_mesh,material,entity.transform,Camera.current);
	}
	
}