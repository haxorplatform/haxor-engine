package haxor.context;
import haxor.component.Camera;
import haxor.component.MeshRenderer;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Resource;
import haxor.core.Enums.PixelFormat;
import haxor.ds.SAP;
import haxor.graphics.GL;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Material.MaterialUniform;
import haxor.graphics.material.Shader;
import haxor.graphics.Screen;
import haxor.graphics.texture.RenderTexture;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

/**
 * Class that handles the Camera class structures and functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class CameraContext
{
	
	/**
	 * Unique class id for Cameras.
	 */
	private var cid : UID;

	/**
	 * List of all cameras in the scene.
	 */
	private var list : Array<Camera>;
	
	/**
	 * Front render target.
	 */
	private var front : Array<RenderTexture>;
	
	/**
	 * Back render target.
	 */
	private var back  : Array<RenderTexture>;
	
	/**
	 * Material used for clearing with the skybox.
	 */
	private var skybox_material : Material;
	
	/**
	 * Creates the context.
	 */
	private function new() 
	{
		cid   = new UID();
		list  = [];
		front = [];
		back  = [];		
		
		for (i in 0...64)
		{			
			front.push(null);
			back.push(null);			
		}
	}
	
	/**
	 * Register the camera.
	 * @param	p_camera
	 */
	private function Create(c:Camera):Void
	{
		skybox_material = new Material("internal/Skybox");		
		skybox_material.ztest 	  = true;
		skybox_material.cull 	  = CullMode.None;
		skybox_material.zwrite	  = false;
		skybox_material.shader = new Shader(ShaderContext.clear_skybox_source);
		
		list.push(c);		
		SortCameraList();	
		EngineContext.renderer.AddCamera(c);
	}
	
	/**
	 * Destroys the camera.
	 * @param	p_camera
	 */
	private function Destroy(c:Camera):Void
	{
		ClearTargets(c);
		list.remove(c);
		SortCameraList();
		cid.id = c.__cid;
		EngineContext.renderer.RemoveCamera(c);
	}
	
	
	
	/**
	 * Activates camera related stuff.
	 * @param	p_camera
	 */
	private function Bind(c:Camera):Void
	{
		var ft 		: RenderTexture = front[c.__cid];
		var rt 		: RenderTexture = c.m_target;		
		var target 	: RenderTexture = ft == null ? rt : ft;				
		c.UpdateProjection();		
		EngineContext.renderer.UpdateCameraSAP(c);		
		EngineContext.texture.BindTarget(target);
		EngineContext.renderer.UpdateDisplayList(c);		
		Graphics.Clear(c);
		
	}
	
	/**
	 * Callback when the application container resized.
	 */
	private function Resize():Void
	{
		for (i in 0...list.length) UpdateViewport(list[i]);
	}
	
	/**
	 * Clears the camera internal render targets.
	 * @param	c
	 */
	private function ClearTargets(c:Camera):Void
	{
		var rt : RenderTexture;		
		rt = front[c.__cid]; if(rt != null)  Resource.Destroy(rt); 
		rt = back[c.__cid];  if(rt !=null)   Resource.Destroy(rt); 
		front[c.__cid] = null;
		back[c.__cid]  = null;
	}
	
	/**
	 * Finishes the camera rendering.
	 * @param	c
	 */
	private function Unbind(c:Camera):Void
	{
		//c.m_uniform_dirty = false;
		SwapTargets(c);
	}
	
	/**
	 * Flips the targets for ping-pong rendering.
	 * @param	c
	 */
	private function SwapTargets(c:Camera):Void
	{
		var tmp : RenderTexture;		
		tmp = front[c.__cid];
		front[c.__cid] = back[c.__cid];
		back[c.__cid] = tmp;
	}
	
	/**
	 * Updates the internal camera viewport data.
	 * @param	c
	 */
	private function UpdateViewport(c:Camera):Void
	{
		var need_buffer : Bool = false;		
		if (c.m_quality < 1.0) 	need_buffer = true; 
		else 
		if (c.filters.length > 0) need_buffer = true;
		
		var w : Float32 = Screen.width;
		var h : Float32 = Screen.height;
		
		if (c.m_target != null)
		{			
			w = cast c.m_target.width;
			h = cast c.m_target.height;
		}
		
		c.m_aspect = w / h;
		
		var sw : Float32 = w * c.m_quality;
		var sh : Float32 = h * c.m_quality;
		w = sw < 1.0 ? 1.0 : sw;
		h = sh < 1.0 ? 1.0 : sh;
		
		var vx: Float32 = Std.int(c.m_viewport.x * w);
		var vy: Float32 = Std.int(c.m_viewport.y * h);            
		var aw: Float32 = (c.m_viewport.width  * w);
		var ah: Float32 = (c.m_viewport.height * h);
		
		c.m_pixelViewport.x 	  = vx;
		c.m_pixelViewport.y 	  = h - ah - vy;
		c.m_pixelViewport.width   = aw;
		c.m_pixelViewport.height  = ah;
		
		var tw : Int = cast aw;
		var th : Int = cast ah;
		
		var grt : RenderTexture;
		
		grt = front[c.__cid];
		
		if (grt != null)
		{
			if (tw != grt.width) ClearTargets(c); 
			else
			if (th != grt.height)ClearTargets(c);			
		}	
		
		grt = front[c.__cid];
		
		if (grt == null)
		{
			if (need_buffer)
			{
				
				var tf : PixelFormat = c.m_target == null ? PixelFormat.RGB8 : c.m_target.format;
				front[c.__cid] = new RenderTexture(cast aw, cast ah, tf,c.m_captureDepth);
				back[c.__cid]  = c.filters.length <= 0 ? front[c.__cid] : new RenderTexture(cast aw, cast ah, tf,c.m_captureDepth);
				front[c.__cid].name = 
				back[c.__cid].name = 
				"CameraScreenBuffer";				
			}
		}
		c.m_projection_dirty = true;
		c.m_proj_uniform_dirty = true;
	}
	
	/**
	 * Sorts the cameras render order.
	 */
	private function SortCameraList():Void
	{
		if(list.length>1)
		list.sort(function(a:Camera, b:Camera):Int { return a.order == b.order ? (a.entity.name < b.entity.name ? -1 : 1) : (a.order < b.order ? -1 : 1); });		
	}
}