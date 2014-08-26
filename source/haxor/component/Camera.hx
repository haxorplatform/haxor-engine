package haxor.component;
import haxor.context.EngineContext;
import haxor.core.IResizeable;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.graphics.Enums.ClearFlag;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Screen;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.TextureCube;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.math.Vector4;


/**
 * Class that describes a rendering camera.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Camera extends Behaviour
{
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
	 * Background clear color.
	 */
	public var background:Color;
	
	/**
	 * Skybox Texture
	 */
	public var skybox: TextureCube;
	
	/**
	 * Clear flag bits.
	 */
	public var clear:Int;
	
	/**
	 * Layer bits that will be rendered by this camera.
	 */
	public var mask:Int;
	
	/**
	 * Field of View.
	 */
	public var fov(get_fov, set_fov):Float;	
	private inline function get_fov():Float { return m_fov; }
	private inline function set_fov(v:Float):Float { m_fov = v; m_projection_dirty=true; return v; }
	private var m_fov:Float;
	
	/**
	 * Near plane.
	 */
	public var near(get_near, set_near):Float;		
	private inline function get_near():Float { return m_near; }
	private inline function set_near(v:Float):Float { m_near = v; m_projection_dirty=true; return v; }
	private var m_near:Float;
	
	/**
	 * Far plane.
	 */
	public var far(get_far, set_far):Float;	
	private inline function get_far():Float { return m_far; }
	private inline function set_far(v:Float):Float { m_far = v; m_projection_dirty=true; return v; }
	private var m_far:Float;	
	
	/**
	 * Render order of this camera versus all cameras in the scene.
	 */
	public var order(get_order, set_order):Int;
	private var m_order:Int;	
	private function get_order():Int { return m_order; }
	private function set_order(v:Int):Int { m_order = v; EngineContext.camera.SortCameraList(); return m_order; }	

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
	public var viewport(get_viewport, set_viewport):AABB2;	
	private inline function get_viewport():AABB2 { return m_viewport.clone; }
	private inline function set_viewport(v:AABB2):AABB2 { m_viewport.SetAABB2(v); EngineContext.camera.UpdateViewport(this); return v; }
	private var m_aspect:Float;
	private var m_viewport:AABB2;	
	
	/**
	 * ViewInverse Matrix.
	 */
	public var CameraToWorld(get_CameraToWorld, null):Matrix4;	
	private inline function get_CameraToWorld():Matrix4	{ return m_cameraToWorld.clone; }
	private var m_cameraToWorld:Matrix4;	
	
	/**
	 * View Matrix.
	 */
	public var WorldToCamera(get_WorldToCamera, null):Matrix4;
	private var m_worldToCamera:Matrix4;	
	private function get_WorldToCamera():Matrix4	{ return m_worldToCamera; }
	
	/**
	 * Projection Matrix.
	 */
	public var ProjectionMatrix(get_ProjectionMatrix, null):Matrix4;	
	private inline function get_ProjectionMatrix():Matrix4	{ UpdateProjection(); return m_projectionMatrix.clone; }
	private var m_projectionMatrix:Matrix4;	
	private var m_skyboxProjection:Matrix4;
	
	/**
	 * Projection Inverse Matrix.
	 */
	public var ProjectionMatrixInverse(get_ProjectionMatrixInverse, null):Matrix4;	
	private inline function get_ProjectionMatrixInverse():Matrix4	{ UpdateProjection(); return m_projectionMatrixInverse.clone; }
	private var m_projectionMatrixInverse:Matrix4;	
	private var m_skyboxProjectionInverse:Matrix4;
	
	/**
	 * Render Target. If null will render to screen.
	 */
	public var target : RenderTexture;			
	private inline function get_target():RenderTexture { return m_target; }
	private inline function set_target(v:RenderTexture):RenderTexture { m_target = v; EngineContext.camera.UpdateViewport(this); return v; }
	private var m_target : RenderTexture;
	
	/**
	 * Quality of this camera rendering. If 1.0 the camera will render the full size of the screen, less than 1.0 it will render a fraction of the full resolution, thus generating less fragments.
	 */
	public var quality(get_quality, set_quality) : Float;
	private function get_quality():Float { return m_quality; }
	private function set_quality(v:Float):Float { m_quality = Mathf.Clamp01(v); EngineContext.camera.UpdateViewport(this); return v; }
	private var m_quality : Float;
	
	/**
	 * Flag that indicates if this Camera needs to capture the Depth buffer.
	 */
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
	//*/
	
	private var m_projection_dirty : Bool;
	
	override function OnBuild():Void 
	{
		super.OnBuild();
		__cid						= EngineContext.camera.cid++;
		if (m_main == null)			m_main = this;
		m_order						= 0;		
		m_quality					= 1.0;
		m_pixelViewport 			= AABB2.empty;
		m_viewport 					= AABB2.empty;
		m_worldToCamera 			= Matrix4.identity;
		m_cameraToWorld				= Matrix4.identity;
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
		EngineContext.camera.Create(this);
	}
	
	/**
	 * Transform the point from world coordinates to the projection space of the camera.
	 * @param	p_world_point
	 * @return
	 */
	public function WorldToProjection(p_world_point : Vector3):Vector4
	{
		var p : Vector4 = Vector4.temp;		
		p.w = 1.0;		
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;		
		m_worldToCamera.Transform4x4(p);
		m_projectionMatrix.Transform4x4(p);		
		return p;
	}
	
	/**
	 * Returns the Camera Space Z-value of the point in World Space.
	 * @param	p_world_point
	 * @return
	 */
	public function WorldToDepth(p_world_point : Vector3):Float
	{
		var wm : Matrix4 = m_worldToCamera;
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
	public inline function LookAt(p_at : Vector3, p_up : Vector3 = null,p_smooth:Float=0.0):Void
	{
		var p : Vector3 	= transform.position;
		var r : Quaternion  = Quaternion.temp;
		var q : Quaternion  = Quaternion.LookAt(p, p_at, p_up, Quaternion.temp);
		if (p_smooth > 0)
		{
			r = Quaternion.Lerp(r, q, p_smooth * Time.delta, Quaternion.temp);
		}
		else
		{
			r = q;
		}
		transform.rotation = r;
	}
	
	/**
	 * Updates the Projection matrix upon request.
	 */
	private function UpdateProjection():Void 
	{	
		if (!m_projection_dirty) return;
		m_projection_dirty = false;
		m_projectionMatrix.SetPerspective(m_fov, m_aspect, m_near, m_far);
		m_projectionMatrixInverse.SetPerspectiveInverse(m_fov, m_aspect, m_near, m_far);
		m_skyboxProjection.SetPerspective(m_fov, m_aspect, 0.1,100000.0);
		m_skyboxProjectionInverse.SetPerspectiveInverse(m_fov, m_aspect, 0.1, 100000.0);				
	}
	
	/**
	 * Updates the internal matrix when the transform updates.
	 */
	override private function OnTransformUpdate():Void 
	{	
		m_cameraToWorld.SetMatrix4(transform.WorldMatrix);
		m_worldToCamera.SetMatrix4(transform.WorldMatrixInverse);
	}
	
	//*/
	/**
	 * Handles the Camera dispose.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.camera.Destroy(this);
	}
	
	
}