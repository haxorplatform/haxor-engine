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
	 * Current camera being used in the rendering pipeline.
	 */
	static public var current : Camera;
	
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
	private inline function set_fov(v:Float):Float { m_fov = v; UpdateProjection(); return v; }
	private var m_fov:Float;
	
	/**
	 * Near plane.
	 */
	public var near(get_near, set_near):Float;		
	private inline function get_near():Float { return m_near; }
	private inline function set_near(v:Float):Float { m_near = v; UpdateProjection(); return v; }
	private var m_near:Float;
	
	/**
	 * Far plane.
	 */
	public var far(get_far, set_far):Float;	
	private inline function get_far():Float { return m_far; }
	private inline function set_far(v:Float):Float { m_far = v; UpdateProjection(); return v; }
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
	private inline function set_viewport(v:AABB2):AABB2
	{
		m_viewport.xMin = v.xMin;
		m_viewport.xMax = v.xMax;
		m_viewport.yMin = v.yMin;
		m_viewport.yMax = v.yMax;
		OnResize(Screen.width, Screen.height);
		return m_viewport;
	}
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
	private inline function get_ProjectionMatrix():Matrix4	{ return m_projectionMatrix.clone; }
	private var m_projectionMatrix:Matrix4;	
	private var m_skyboxProjection:Matrix4;
	
	/**
	 * Projection Inverse Matrix.
	 */
	public var ProjectionMatrixInverse(get_ProjectionMatrixInverse, null):Matrix4;	
	private inline function get_ProjectionMatrixInverse():Matrix4	{ return m_projectionMatrixInverse.clone; }
	private var m_projectionMatrixInverse:Matrix4;	
	private var m_skyboxProjectionInverse:Matrix4;
	
	/**
	 * Render Target. If null will render to screen.
	 */
	public var target : RenderTexture;			
	private inline function get_target():RenderTexture { return m_target; }
	private inline function set_target(v:RenderTexture):RenderTexture
	{
		m_target = v;
		if(v != null) OnResize(v.width, v.height);
		return v;
	}
	private var m_target : RenderTexture;
	
	/*
	public var filters(get_filters, set_filters) : Array<RenderFX>;
	private function get_filters():Array<RenderFX> { return m_filters; }
	private function set_filters(v:Array<RenderFX>):Array<RenderFX>
	{
		m_filters = v == null ? [] : v;
		return m_filters;
	}
	private var m_filters : Array<RenderFX>;
	//*/
	
	private var m_srcRT : RenderTexture;
	private var m_dstRT : RenderTexture;
	private var m_grab	: RenderTexture;
	private var m_back	: RenderTexture;
	private var m_g0	: RenderTexture;
	private var m_g1	: RenderTexture;
	
	function new() 
	{
		super();
		__cid						= EngineContext.camera.cid++;
		m_order						= 0;		
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
		//m_filters 					= [];
		background 					= new Color(0, 0, 0, 1);
		clear 						= ClearFlag.ColorDepth;
		mask 						= 1;				
		viewport 					= new AABB2(0, 0, 1, 1); 
		EngineContext.camera.Create(this);
	}
	
	
	public function OnResize(w:Float,h:Float):Void
	{		
		var vx: Float = Std.int(m_viewport.x * w);
		var vy: Float = Std.int(m_viewport.y * h);            
		var aw: Float = (m_viewport.width * w);
		var ah: Float = (m_viewport.height * h);
		
		if (m_target != null)
		{
			aw = m_target.width;
			ah = m_target.height;
		}
		
		m_pixelViewport.x = vx;
		m_pixelViewport.y = h - ah - vy;
		m_pixelViewport.width = aw;
		m_pixelViewport.height = ah;
		m_aspect = aw / ah;
		
		var tw : Int = cast aw;// Mathf.NextPOT(cast aw);
		var th : Int = cast ah;// Mathf.NextPOT(cast ah);
		
		if (m_srcRT != null)
		{
			if (tw != m_srcRT.width)  { Resource.Destroy(m_srcRT); Resource.Destroy(m_dstRT); Resource.Destroy(m_g0); Resource.Destroy(m_g1); m_g0 = m_g1 = m_dstRT = m_srcRT = null; } else
			if (th != m_srcRT.height) { Resource.Destroy(m_srcRT); Resource.Destroy(m_dstRT); Resource.Destroy(m_g0); Resource.Destroy(m_g1); m_g0 = m_g1 = m_dstRT = m_srcRT = null; }			
		}		
		if (m_srcRT == null)
		{
			m_srcRT  = new RenderTexture(cast aw, cast ah, PixelFormat.RGBA8,true);
			m_dstRT  = new RenderTexture(cast aw, cast ah, PixelFormat.RGBA8,true);
			m_g0     = new RenderTexture(cast aw, cast ah, PixelFormat.RGBA8, true);
			m_g1     = new RenderTexture(cast aw, cast ah, PixelFormat.RGBA8, true);
			m_g0.name = m_g1.name = "ScreenBufferTexture";
			m_grab = m_g0;
			m_back = m_g1;
		}
		
		UpdateProjection();
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
	
	/*
	public function IsCulled(p_world_point : Vector3):Bool
	{
		return WorldToProjection(p_world_point).IsCulled();						
	}
	//*/
	
	/**
	 * Points the camera towards the target. If smooth is greater than zero the camera will lerp to the orientation during time.
	 * @param	p_at
	 * @param	p_up
	 */
	public inline function LookAt(p_at : Vector3, p_up : Vector3 = null,p_smooth:Float=0.0):Void
	{
		var p : Vector3 	= null;
		var r : Quaternion  = null;
		var q : Quaternion  = Quaternion.LookAt(p, p_at, p_up, Quaternion.temp);
		if (p_smooth > 0)
		{
			r = Quaternion.Lerp(r, q, p_smooth * Time.delta, Quaternion.temp);
		}
		else
		{
			r = q;
		}
		//transform.rotation = Quaternion.LookAt(transform.position, p_at);
	}
	
	
	private function UpdateProjection():Void 
	{	
		m_projectionMatrix.SetPerspective(m_fov, m_aspect, m_near, m_far);
		m_projectionMatrixInverse.SetPerspectiveInverse(m_fov, m_aspect, m_near, m_far);
		m_skyboxProjection.SetPerspective(m_fov, m_aspect, 0.1,100000.0);
		m_skyboxProjectionInverse.SetPerspectiveInverse(m_fov, m_aspect, 0.1, 100000.0);				
	}
	/*
	override private function OnTransformUpdate():Void 
	{	
		var wm : Matrix4 = entity.transform.WorldMatrix;
		var m:Matrix4 = Matrix4.temp; 
		m.Set(
		wm.m00, wm.m01, wm.m02, wm.m03,
		wm.m10, wm.m11, wm.m12, wm.m13,
		wm.m20, wm.m21, wm.m22, wm.m23,
		0, 0, 0, 1);
		
		var ex : Float = m.m03; 
		var ey : Float = m.m13; 
		var ez : Float = m.m23;
		
		var r:Matrix4 = m.ToRotation();
				
		var vxx : Float = r.m00; var vxy : Float = r.m01; var vxz : Float = r.m02;		
		var vyx : Float = r.m10; var vyy : Float = r.m11; var vyz : Float = r.m12;		
		var vzx : Float = r.m20; var vzy : Float = r.m21; var vzz : Float = r.m22;
				
		//Transpose to invert rotation
		m_worldToCamera.m00 = vxx; m_worldToCamera.m01 = vyx; m_worldToCamera.m02 =  vzx;
		m_worldToCamera.m10 = vxy; m_worldToCamera.m11 = vyy; m_worldToCamera.m12 =  vzy;
		m_worldToCamera.m20 = vxz; m_worldToCamera.m21 = vyz; m_worldToCamera.m22 =  vzz;
		
		m_worldToCamera.m03 = -(ex * m_worldToCamera.m00 + ey * m_worldToCamera.m01 + ez * m_worldToCamera.m02);
		m_worldToCamera.m13 = -(ex * m_worldToCamera.m10 + ey * m_worldToCamera.m11 + ez * m_worldToCamera.m12);
		m_worldToCamera.m23 = -(ex * m_worldToCamera.m20 + ey * m_worldToCamera.m21 + ez * m_worldToCamera.m22);		
		
		Matrix4.GetInverseTransform(m_worldToCamera,m_cameraToWorld);
	}
	//*/
	
	private function SwapBuffer():Void
	{
		if (m_grab == m_g0) { m_grab = m_g1; m_back = m_g0; } else
		if (m_grab == m_g1) { m_grab = m_g0; m_back = m_g1; } 
	}
	
	/**
	 * Handles the Camera dispose.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.camera.Destroy(this);
	}
	
	
}