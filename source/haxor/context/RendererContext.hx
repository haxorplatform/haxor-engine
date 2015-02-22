package haxor.context;
import haxe.Timer;
import haxor.component.Camera;
import haxor.component.Component;
import haxor.component.MeshRenderer;
import haxor.component.Renderer;
import haxor.component.SkinnedMeshRenderer;
import haxor.core.Resource;
import haxor.core.Enums.PixelFormat;
import haxor.core.Time;
import haxor.ds.SAP;
import haxor.graphics.GL;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.Screen;
import haxor.graphics.texture.ComputeTexture;
import haxor.graphics.texture.RenderTexture;
import haxor.io.FloatArray;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Class that handles the all Renderers structures and functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class RendererContext
{
	/**
	 * Unique class id for MeshRenderers.
	 */
	private var rid : UID;
	
	/**
	 * Unique class id for frustum culling.
	 */
	private var fcid : UID;

	/**
	 * List of Renderers display lists per layer.
	 */
	private var display : Array<Process<Renderer>>;
	
	/**
	 * Sweep and prune for frustum culling optimization .
	 */
	private var sap : SAP;
	
	/**
	 * Flag that indicates if the SAP data has changed.
	 */
	private var sap_dirty : Bool;
	
	/**
	 * Flag that indicates if the display list needs sorting.
	 */
	private var sort : Array<Bool>;
		
	/**
	 * index to check not-visibility in an async way.
	 */
	private var deferred_culling : Int;
	
	/**
	 * offset to check if a mesh renderer is not visible.
	 */
	private var deferred_offset : Int;
	
	/**
	 * Creates the context.
	 */
	private function new() 
	{
		rid   = new UID();		
		
		fcid  = new UID();
		sap   = new SAP(0.01,false);
		
		sap_dirty = false;
		
		deferred_culling = 0;
		deferred_offset  = 100;
		
		display   = [];
		sort	  = [];
		for (i in 0...32)
		{	
			var p : Process<Renderer> = new Process("process.renderers",EngineContext.maxNodes,i==31);
			display.push(p);	
			sort.push(false);
		}
	}
	
	/**
	 * Creates the internal structure that needs the graphic context.
	 */
	private function Initialize():Void
	{
		
	}
	
	/**
	 * Setup data for the new renderer.
	 * @param	r
	 */
	private function Create(r:Renderer):Void
	{
		r.__cid  = rid.id;
		if (r.m_has_mesh)
		{
			var mr : MeshRenderer = cast r;
			mr.__fcid = fcid.id;
			sap.Create(mr.__fcid);			
		}
	}
	
	/**
	 * Updates the joints texture sector of the renderer.
	 * @param	smr
	 */
	private function UpdateSkinning(smr : SkinnedMeshRenderer,jf:Bool):Void
	{
		var t   : ComputeTexture = jf ? smr.m_jt : smr.m_bmt;		
		if (t == null) return;		
		var f32 : FloatArray = cast t.data.buffer;
		var vl  : Array<Float32> = jf ? smr.m_jf32 : smr.m_bmf32;		
		for (i in 0...vl.length) f32.Set(i, vl[i]);		
		t.Apply();				
		if (jf)
		{
			var tw : Float32  = cast t.width;
			var th : Float32  = cast t.height;
			var itw : Float32 = tw <= 0 ? 0.0 : (1.0 / tw);
			var ith : Float32 = th <= 0 ? 0.0 : (1.0 / th);
			smr.material.SetTexture("Joints", smr.m_jt);
			smr.material.SetTexture("Binds", smr.m_bmt);
			smr.material.SetFloat4("SkinTexSize", tw, th, itw, ith);			
		}		
	}
	
	/**
	 * Adds a camera to the SAP frustum culling.
	 * @param	c
	 */
	private function AddCamera(c:Camera):Void
	{
		c.__fcid = fcid.id;
		sap.Create(c.__fcid);
	}
	
	/**
	 * Removes a camera to the SAP frustum culling.
	 * @param	c
	 */
	private function RemoveCamera(c:Camera):Void
	{
		fcid.id = c.__fcid;
		sap.Remove(c.__fcid);
	}
	
	/**
	 * Callback called when a renderer changes its material.
	 * @param	r
	 */
	private function OnMaterialChange(r:Renderer):Void
	{
		var l : Int = r.m_entity.layer;
		sort[l] = true;
	}
	
	/**
	 * Callback called when a renderer changes its mesh.
	 * @param	r
	 */
	private function OnMeshChange(r:Renderer):Void
	{
		var l : Int = r.m_entity.layer;
		sort[l] = true;
	}
	
	/**
	 * Notifies all components from the Entity that this mesh renderer visibility changed.
	 * @param	m
	 * @param	f
	 */
	private function OnVisibilityChange(r:Renderer,f:Bool):Void
	{
		var cl : Array<Component>   = r.m_entity.m_components;
		for (i in 0...cl.length) cl[i].OnVisibilityChange(f);
	}
	
	/**
	 * Checks if the renderer is visible and post-pone or not the test for visiblity.
	 * @param	r
	 * @return
	 */
	private function DeferredCulling(r:Renderer):Bool
	{
		//if (Time.frame < 300) 
		return false;
		if (!r.visible) return false;
		var c_id  : Int = EngineContext.renderer.deferred_culling;
		var c_off :Int  = deferred_offset;
		deferred_culling = (deferred_culling + deferred_offset) % rid.next;					
		if (Mathf.AbsInt(c_id - r.__cid) > c_off) return true;			
		return false;
	}
	
	/**
	 * Callback called when the Renderer's entity changes layers.
	 * @param	r
	 * @param	from
	 * @param	to
	 */
	private function OnLayerChange(r:Renderer, from:Int, to:Int):Void
	{
		sort[from] = true;		
		display[from].Remove(r);
		if (r.enabled)
		{
			display[to].Add(r);
			sort[to] = true;
		}
	}
	
	/**
	 * Checks the culling and render order for a given camera.
	 */
	private function UpdateDisplayList(c:Camera):Void
	{
		var ll : Array<Int> = c.m_layers;
		for (i in 0...ll.length)
		{
			var l  : Int = ll[i];
			var rl : Process<Renderer> = display[l];
			var need_sort : Bool = sort[l];
			if (need_sort)
			{
				sort[l] = false;
				if (rl.length > 1)
				{
					rl.Sort(DisplayListSort);
				}
			}
		}
	}
	
	/**
	 * Enables the renderer.
	 * @param	r
	 */
	private function Enable(r:Renderer):Void
	{
		display[r.m_entity.layer].Add(r);
		sort[r.m_entity.layer] = true;
		if (r.m_has_mesh)
		{
			var mr : MeshRenderer = cast r;
			mr.m_culling_dirty = true;
		}
	}
	
	/**
	 * Disables the renderer.
	 * @param	r
	 */
	private function Disable(r:Renderer):Void
	{
		display[r.m_entity.layer].Remove(r);
		sort[r.m_entity.layer] = true;
	}
	
	/**
	 * Updates the Camera SAP structure using the camera space frustum corners.
	 * @param	c
	 */
	private function UpdateCameraSAP(c: Camera):Void
	{
		var need_sap :Bool = sap_dirty || c.m_view_uniform_dirty || c.m_proj_uniform_dirty;
		if (!need_sap) return;		
		var n0 : Vector3 = Vector3.temp.Set4(c.m_frustum[0]);			
		var n1 : Vector3 = Vector3.temp.Set4(c.m_frustum[1]);
		var n2 : Vector3 = Vector3.temp.Set4(c.m_frustum[2]);
		var n3 : Vector3 = Vector3.temp.Set4(c.m_frustum[3]);
		var f0 : Vector3 = Vector3.temp.Set4(c.m_frustum[4]);
		var f1 : Vector3 = Vector3.temp.Set4(c.m_frustum[5]);
		var f2 : Vector3 = Vector3.temp.Set4(c.m_frustum[6]);
		var f3 : Vector3 = Vector3.temp.Set4(c.m_frustum[7]);
		
		c.CameraToWorld.Transform3x4(n0);			
		c.CameraToWorld.Transform3x4(n1);
		c.CameraToWorld.Transform3x4(n2);
		c.CameraToWorld.Transform3x4(n3);
		c.CameraToWorld.Transform3x4(f0);
		c.CameraToWorld.Transform3x4(f1);
		c.CameraToWorld.Transform3x4(f2);			
		c.CameraToWorld.Transform3x4(f3);
	
		var pmin:Vector3 = Vector3.temp.Set(n0.x, n0.y, n0.z);			
		var pmax:Vector3 = Vector3.temp.Set(n0.x, n0.y, n0.z);
				
		pmin.x = Mathf.Min(pmin.x, Mathf.Min(n1.x, Mathf.Min(n2.x, n3.x)));
		pmin.y = Mathf.Min(pmin.y, Mathf.Min(n1.y, Mathf.Min(n2.y, n3.y)));
		pmin.z = Mathf.Min(pmin.z, Mathf.Min(n1.z, Mathf.Min(n2.z, n3.z)));	
		
		pmax.x = Mathf.Max(pmax.x, Mathf.Max(n1.x, Mathf.Max(n2.x, n3.x)));
		pmax.y = Mathf.Max(pmax.y, Mathf.Max(n1.y, Mathf.Max(n2.y, n3.y)));
		pmax.z = Mathf.Max(pmax.z, Mathf.Max(n1.z, Mathf.Max(n2.z, n3.z)));
		
		pmin.x = Mathf.Min(pmin.x, Mathf.Min(f0.x, Mathf.Min(f1.x, Mathf.Min(f2.x,f3.x))));
		pmin.y = Mathf.Min(pmin.y, Mathf.Min(f0.y, Mathf.Min(f1.y, Mathf.Min(f2.y,f3.y))));
		pmin.z = Mathf.Min(pmin.z, Mathf.Min(f0.z, Mathf.Min(f1.z, Mathf.Min(f2.z,f3.z))));			
		
		pmax.x = Mathf.Max(pmax.x, Mathf.Max(f0.x, Mathf.Max(f1.x, Mathf.Max(f2.x,f3.x))));
		pmax.y = Mathf.Max(pmax.y, Mathf.Max(f0.y, Mathf.Max(f1.y, Mathf.Max(f2.y,f3.y))));
		pmax.z = Mathf.Max(pmax.z, Mathf.Max(f0.z, Mathf.Max(f1.z, Mathf.Max(f2.z,f3.z))));
		
		c.m_aabb.Set3(pmin, pmax);
		
		UpdateSAP(c.__fcid, c, pmin, pmax);			
		
	}
	
	/**
	 * Update SAP interval 
	 * @param	r
	 * @param	p_min
	 * @param	p_max
	 */
	private function UpdateSAP(p_id:Int,p_d:Dynamic,p_min:Vector3,p_max:Vector3):Void
	{
		sap_dirty = true;
		sap.Update(p_id,p_d,p_min, p_max);
	}
	
	/**
	 * Checks if the pair overlaps in the SAP structure.
	 * @param	r
	 * @param	c
	 * @return
	 */
	private function IsSAPCulled(r:Renderer, c:Camera):Bool
	{		
		if (!r.m_has_mesh) return false;		
		var mr : MeshRenderer = cast r;
		if (mr.m_culling_dirty) return false;
		return !sap.Overlap(mr.__fcid, c.__fcid);
	}
	
	/**
	 * Destroys the renderer
	 * @param	r
	 */
	private function Destroy(r:Renderer):Void
	{
		display[r.m_entity.layer].Remove(r);
		sort[r.m_entity.layer] = true;
		rid.id  = r.__cid;
		
		//If MeshRenderer update SAP related stuff.
		if (r.m_has_mesh)
		{
			var mr : MeshRenderer = cast r;
			fcid.id = mr.__fcid;
			sap.Remove(mr.__fcid);
		}
	}
	
	/**
	 * Method that sorts renderers inside the display list.
	 * The sort priorities are
	 * 
	 * 1) Has Material
	 * 2) Material Queue
	 * 3) Is MeshRenderer
	 * 4) Material UID
	 * 5) Has Mesh
	 * 6) Mesh UID
	 * 
	 * This sort will help to cache API flags and structures, and in the future help to Batch drawcalls.
	 * 
	 * @param	a
	 * @param	b
	 * @return
	 */
	private function DisplayListSort(a:Renderer, b:Renderer):Int
	{
		//The renderer list has lots of null until it is filled.
		if (a == null) if (b == null) return 0;
		if (a == null) return  1;
		if (b == null) return -1;
		
		//If both don't hace materials return.
		if (a.material == null) if (b.material == null) return 0;
		
		//If either don't have the one which have it, wins.
		if (a.material == null) return  1;
		if (b.material == null) return -1;
		
		var ma : Material = a.material;
		var mb : Material = b.material;		
		var ia : Int = ma.queue;
		var ib : Int = mb.queue;		
		
		//First RenderQueues
		if (ia != ib) return ia<ib ? -1 : 1;
		
		//Check if both are MeshRenderers
		if (!a.m_has_mesh) if (!b.m_has_mesh) return 0;
		
		//Between Renderer and MeshRenderer prioritize MeshRenderers.
		if (!a.m_has_mesh) return  1;
		if (!b.m_has_mesh) return -1;
		
		var mra : MeshRenderer = cast a;
		var mrb : MeshRenderer = cast b;
		
		//Check if materials inside the same queue are equal.
		if (mra.material.uid < mrb.material.uid) return -1;
		if (mra.material.uid > mrb.material.uid) return  1;			
		
		//Check if meshes are ok.
		if (mra.mesh == null) if (mrb.mesh == null) return 0;
		if (mra.mesh == null) return  1;
		if (mrb.mesh == null) return -1;
	
		//Check if meshes inside the same queue are equal.
		if (mra.mesh.uid < mrb.mesh.uid) return -1;
		if (mra.mesh.uid > mrb.mesh.uid) return  1;				
		
		return 0;
	}
		
}