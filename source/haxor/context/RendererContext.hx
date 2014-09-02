package haxor.context;
import haxor.component.Camera;
import haxor.component.Component;
import haxor.component.MeshRenderer;
import haxor.component.Renderer;
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
import haxor.math.Mathf;
import haxor.math.Vector3;

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
	 * Float Texture that will contains skinning data.
	 */
	private var skinning : ComputeTexture;
	
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
		//430 skinned mesh renderers with 50 joints and 50 binds.
		skinning = new ComputeTexture(512, 512, PixelFormat.Float4); 
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
		return sap.Overlap(mr.__fcid, c.__fcid);
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