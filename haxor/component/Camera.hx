package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Enums.CameraMode;
import haxor.core.IResizeable;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.Screen;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.TextureCube;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;


/**
 * Class that describes a rendering camera.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Camera extends Behaviour implements IResizeable
{
		
	
	/**
	 * 
	 */
	static public var SAPCulling : Bool = true;
	
	/**
	 * Returns the list of cameras in the runtime.
	 */
	static public var list(get_list, never):Array<Camera>;
	static private inline function get_list():Array<Camera> { return EngineContext.camera.list.copy(); }
	
	/**
	 * Current camera being used in the rendering pipeline.
	 */
	static public var current(get_current,never) : Camera;
	static private inline function get_current():Camera { return m_current; }
	static private var m_current : Camera;
	
	/**
	 * Main camera being used in the rendering pipeline. The default value of this variable is the first camera created.
	 */
	static public var main(get_main,set_main) : Camera;
	static private inline function get_main():Camera { return m_main; }
	static private inline function set_main(v:Camera):Camera { return m_main=v; }
	static private var m_main : Camera;
	
	/**
	 * Frustum culling id.
	 */
	private var __fcid:Int;
	
	/**
	 * Background clear color.
	 */
	@serialize
	public var background:Color;
	
	/**
	 * Skybox Texture
	 */
	@serialize
	public var skybox: TextureCube;
	/*
	private function get_skybox():TextureCube { return m_skybox; }
	private function set_skybox(v:TextureCube):TextureCube { if (m_skybox != null) m_skybox.__slot = -1; m_skybox = v; if (m_skybox != null) m_skybox.__slot = -1; return v; }
	private var m_skybox : TextureCube;
	//*/
	
	/**
	 * Clear flag bits.
	 */
	@serialize
	public var clear:Int;
	
	/**
	 * Layer bits that will be rendered by this camera.
	 */
	@serialize
	public var mask(get_mask,set_mask):Int;
	private inline function get_mask():Int { return m_mask; }
	private function set_mask(v:Int):Int
	{
		if (m_mask == v) return v;
		m_mask  = v;
		var it : Int = m_mask;
		m_layers = [];
		for (i in 0...32)
		{
			if ((it & 1)!=0) m_layers.push(1 << i);
			it = it >> 1;
		}		
		return v;
	}
	private var m_mask : Int;
	private var m_layers : Array<Int>;
	
	
	/**
	 * Field of View.
	 */
	@serialize
	public var fov(get_fov, set_fov):Float32;	
	private inline function get_fov():Float32{ return m_fov; }
	private inline function set_fov(v:Float32):Float32{ m_fov = v; m_projection_dirty=true; return v; }
	private var m_fov:Float32;
	
	/**
	 * Near plane.
	 */
	@serialize
	public var near(get_near, set_near):Float32;		
	private inline function get_near():Float32{ return m_near; }
	private inline function set_near(v:Float32):Float32{ m_near = v; m_projection_dirty = true; m_proj_uniform_dirty = true; return v; }
	private var m_near:Float32;
	
	/**
	 * Far plane.
	 */
	@serialize
	public var far(get_far, set_far):Float32;	
	private inline function get_far():Float32{ return m_far; }
	private inline function set_far(v:Float32):Float32{ m_far = v; m_projection_dirty=true; m_proj_uniform_dirty = true;return v; }
	private var m_far:Float32;	
	
	/**
	 * Render order of this camera versus all cameras in the scene.
	 */
	@serialize
	public var order(get_order, set_order):Int;
	private var m_order:Int;	
	private function get_order():Int { return m_order; }
	private function set_order(v:Int):Int { if (m_order == v) return v; m_order = v; EngineContext.camera.SortCameraList(); return m_order; }	

	/**
	 * Viewport in pixel units.
	 */
	public var pixelViewport(get_pixelViewport, never):AABB2;	
	private inline function get_pixelViewport():AABB2 { return m_pixelViewport.clone; }
	//TODO set_pixelViewport
	private var m_pixelViewport:AABB2;
	
	/**
	 * Viewport in normalized screen units.
	 */
	@serialize
	public var viewport(get_viewport, set_viewport):AABB2;	
	private inline function get_viewport():AABB2 { return m_viewport.clone; }
	private inline function set_viewport(v:AABB2):AABB2 { m_viewport.SetAABB2(v); EngineContext.camera.UpdateViewport(this); return v; }
	private var m_aspect:Float32;
	private var m_viewport:AABB2;	
	
	/**
	 * ViewInverse Matrix.
	 */
	public var CameraToWorld(get_CameraToWorld, null):Matrix4;	
	private inline function get_CameraToWorld():Matrix4	{ return transform.WorldMatrix; }
	
	
	/**
	 * View Matrix.
	 */
	public var WorldToCamera(get_WorldToCamera, null):Matrix4;	
	private function get_WorldToCamera():Matrix4	{ return transform.WorldMatrixInverse; }
	
	
	/**
	 * Projection Matrix.
	 */
	public var ProjectionMatrix(get_ProjectionMatrix, null):Matrix4;	
	private inline function get_ProjectionMatrix():Matrix4	{ UpdateProjection(); return m_projectionMatrix; }
	private var m_projectionMatrix:Matrix4;	
	private var m_skyboxProjection:Matrix4;
	
	/**
	 * Projection Inverse Matrix.
	 */
	public var ProjectionMatrixInverse(get_ProjectionMatrixInverse, null):Matrix4;	
	private inline function get_ProjectionMatrixInverse():Matrix4	{ UpdateProjection(); return m_projectionMatrixInverse; }
	private var m_projectionMatrixInverse:Matrix4;	
	private var m_skyboxProjectionInverse:Matrix4;
	
	/**
	 * Render Target. If null will render to screen.
	 */
	@serialize
	public var target : RenderTexture;			
	private inline function get_target():RenderTexture { return m_target; }
	private inline function set_target(v:RenderTexture):RenderTexture { m_target = v; EngineContext.camera.UpdateViewport(this); return v; }
	private var m_target : RenderTexture;
	
	/**
	 * Quality of this camera rendering. If 1.0 the camera will render the full size of the screen, less than 1.0 it will render a fraction of the full resolution, thus generating less fragments.
	 */
	@serialize
	public var quality(get_quality, set_quality) : Float32;
	private function get_quality():Float32{ return m_quality; }
	private function set_quality(v:Float32):Float32{ m_quality = Mathf.Clamp01(v); EngineContext.camera.UpdateViewport(this); return v; }
	private var m_quality : Float32;
	
	/**
	 * Flag that indicates if this Camera needs to capture the Depth buffer.
	 */
	@serialize
	public var captureDepth(get_captureDepth, set_captureDepth) : Bool;
	private function get_captureDepth():Bool { return m_captureDepth; }
	private function set_captureDepth(v:Bool):Bool { m_captureDepth = v; EngineContext.camera.ClearTargets(this); EngineContext.camera.UpdateViewport(this); return v; }
	private var m_captureDepth : Bool;
	
	/**
	 * Array of Post Processing filters.
	 */
	public var filters(get_filters, set_filters) : Array<Dynamic>;
	private function get_filters():Array<Dynamic> { return m_filters; }
	private function set_filters(v:Array<Dynamic>):Array<Dynamic>
	{
		m_filters = v == null ? [] : v;
		return m_filters;
	}
	private var m_filters : Array<Dynamic>;
	
	/**
	 * Camera Frustum corners in CameraSpace. They are offered in the current order Front to Back:
	 * 0-,---------,-3
	 * |  4-------7  |
	 * |  |       |  |
	 * |  5-------6  |
	 * 1-´---------`-2
	 */
	public var frustum(get, never):Array<Vector4>;
	private function get_frustum():Array<Vector4> { UpdateProjection(); return m_frustum; }
	private var m_frustum : Array<Vector4>;
	
	
	/**
	 * Flag that indicates the type of behaviour of the camera.
	 */
	@serialize
	public var mode(get_mode, set_mode):Int;
	private function get_mode():Int { return m_mode; }
	private function set_mode(v:Int):Int { if (m_mode == v) return v; m_mode = v; m_projection_dirty = true; m_proj_uniform_dirty = true; UpdateProjection(); return v; }
	private var m_mode : Int;
	
	/**
	 * Visible region of the orthographic frustum. Ignored when not using orthographic mode.
	 */
	public var screen(get_screen, set_screen) : AABB2;
	private function get_screen():AABB2{ return m_screen.clone; }
	private function set_screen(v:AABB2):AABB2 { m_screen.SetAABB2(v); m_projection_dirty = true; m_proj_uniform_dirty = true; UpdateProjection(); return v; }
	private var m_screen : AABB2;
	
	/**
	 * Flag that indicates if the projection matrix changed.
	 */
	private var m_projection_dirty : Bool;
	
	/**
	 * Flag that indicates if this camera uniforms must be updated.
	 */
	private var m_view_uniform_dirty : Bool;
	
	/**
	 * Flag that indicates if this camera uniforms must be updated.
	 */
	private var m_proj_uniform_dirty : Bool;
	
	/**
	 * 
	 */
	private var m_aabb : AABB3;
	
	/**
	 * Method called after creation is complete.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		EngineContext.camera.Create(this);
		if (m_main == null)			m_main = this;
		m_order						= 0;		
		m_quality					= 1.0;
		m_pixelViewport 			= AABB2.empty;
		m_viewport 					= AABB2.empty;
		m_aabb						= AABB3.empty;
		m_projectionMatrix  		= Matrix4.identity;		
		m_projectionMatrixInverse 	= Matrix4.identity;
		m_skyboxProjection 			= Matrix4.identity;
		m_skyboxProjectionInverse 	= Matrix4.identity;		
		m_fov 						= 60;
		m_near 						= 0.1;
		m_far 						= 500;	
		m_filters 					= [];
		background 					= new Color(0, 0, 0, 1);
		clear 						= ClearFlag.ColorDepth;
		mask 						= 1;				
		viewport 					= new AABB2(0, 0, 1, 1); 
		m_projection_dirty			= true;	
		m_view_uniform_dirty		= true;
		m_proj_uniform_dirty		= true;
		
		m_mode = CameraMode.Perspective;
		
		m_screen = AABB2.FromMinMax( -1, 1, -1, 1);
		
		m_frustum = [		
		new Vector4(),
		new Vector4(),
		new Vector4(),
		new Vector4(),
		new Vector4(),
		new Vector4(),
		new Vector4(),
		new Vector4()];
		
	}
	
	/**
	 * Transform the point from world coordinates to the projection space of the camera.
	 * @param	p_world_point
	 * @return
	 */
	public function WorldToProjection(p_world_point : Vector3,p_result:Vector4=null):Vector4
	{
		var p : Vector4 = p_result==null ? new Vector4() : p_result;		
		p.w = 1.0;		
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;		
		WorldToCamera.Transform4x4(p);
		ProjectionMatrix.Transform4x4(p);		
		return p;
	}
	
	/**
	 * Returns the Camera Space Z-value of the point in World Space.
	 * @param	p_world_point
	 * @return
	 */
	public function WorldToDepth(p_world_point : Vector3):Float
	{
		var wm : Matrix4 = WorldToCamera;
		return (wm.m20 * p_world_point.x) + (wm.m21 * p_world_point.y) + (wm.m22 * p_world_point.z) + wm.m23;		
	}
	
	/**
	 * Returns a flag that tells if the point is inside or outside the view frustum.
	 * @param	p_world_point
	 * @return
	 */
	public function IsCulled(p_world_point : Vector3):Bool
	{
		return WorldToProjection(p_world_point).IsCulled();
	}
	
	
	/**
	 * Points the camera towards the target in world space. If smooth is greater than zero the camera will lerp to the orientation during time.
	 * @param	p_at
	 * @param	p_up
	 */
	public inline function LookAt(p_at : Vector3, p_up : Vector3 = null,p_smooth:Float32=0.0):Void { transform.LookAt(p_at, p_up, p_smooth); }
	
	/**
	 * Updates the Projection matrix upon request.
	 */
	private function UpdateProjection():Void 
	{	
		if (!m_projection_dirty) return;
		m_projection_dirty = false;
		m_view_uniform_dirty = true;
		
		switch(m_mode)
		{
			case CameraMode.Custom:
								
				
			case CameraMode.Perspective:
				
				m_projectionMatrix.SetPerspective(m_fov, m_aspect, m_near, m_far);
				m_projectionMatrixInverse.SetPerspectiveInverse(m_fov, m_aspect, m_near, m_far);		
				m_skyboxProjection.SetPerspective(m_fov, m_aspect, 0.1,100000.0);
				m_skyboxProjectionInverse.SetPerspectiveInverse(m_fov, m_aspect, 0.1, 100000.0);				
				
			case CameraMode.Ortho:
				m_projectionMatrix.SetOrtho(m_screen.xMin, m_screen.xMax, m_screen.yMax, m_screen.yMin, m_near, -m_far);
				m_projectionMatrixInverse.SetOrthoInverse(m_screen.xMin, m_screen.xMax, m_screen.yMax, m_screen.yMin, m_near, -m_far);
				m_skyboxProjection.SetOrtho(m_screen.xMin, m_screen.xMax, m_screen.yMax, m_screen.yMin, m_near, -m_far);
				m_skyboxProjectionInverse.SetOrthoInverse(m_screen.xMin, m_screen.xMax, m_screen.yMax, m_screen.yMin, m_near, -m_far);				
				
			case CameraMode.UI:
				m_projectionMatrix.SetOrtho(0, Screen.width, 0, Screen.height, m_near, -m_far);
				m_projectionMatrixInverse.SetOrthoInverse(0, Screen.width, 0, Screen.height, m_near, -m_far);
				m_skyboxProjection.SetOrtho(0, Screen.width, 0, Screen.height, m_near, -m_far);
				m_skyboxProjectionInverse.SetOrthoInverse(0, Screen.width, 0, Screen.height, m_near, -m_far);		
		}
		
		
		
		var p : Vector4;
		var iw : Float32 = 0.0;
		var k : Int = 0;
		
		p = m_frustum[k++]; p.Set( -1.0, 1.0, -1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);
		p = m_frustum[k++]; p.Set( -1.0,-1.0, -1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);
		p = m_frustum[k++]; p.Set(  1.0,-1.0, -1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);				
		p = m_frustum[k++]; p.Set(  1.0, 1.0, -1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);		
		
		
		p = m_frustum[k++]; p.Set( -1.0, 1.0, 1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);
		p = m_frustum[k++]; p.Set( -1.0,-1.0, 1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);
		p = m_frustum[k++]; p.Set(  1.0,-1.0, 1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);
		p = m_frustum[k++]; p.Set(  1.0, 1.0, 1.0, 1.0); m_projectionMatrixInverse.Transform4x4(p); iw = p.w <= 0.0 ? 0.0 : 1.0 / p.w; p.Scale(iw);		
		
		
	}
	
	/**
	 * Updates the internal matrix when the transform updates.
	 */
	override private function OnTransformUpdate(p_hierarchy : Bool):Void
	{ 
		m_view_uniform_dirty = true; 
	}
	
	/**
	 * Handles the Camera dispose.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.camera.Destroy(this);
	}
	
	/**
	 * Callback called when the screen changes size.
	 * @param	p_w
	 * @param	p_h
	 */
	public function OnResize(p_w:Float32, p_h:Float32):Void
	{
		if (m_mode == CameraMode.UI) UpdateProjection();
	}
	
}
