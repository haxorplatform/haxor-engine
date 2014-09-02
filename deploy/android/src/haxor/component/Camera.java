package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Camera extends haxor.component.Behaviour
{
	public    Camera(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Camera(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.Camera.__hx_ctor_haxor_component_Camera(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_Camera(haxor.component.Camera __temp_me160413, java.lang.String p_name)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me160413, p_name);
	}
	
	
	
	
	public static   haxe.root.Array<haxor.component.Camera> get_list()
	{
		return haxor.context.EngineContext.camera.list.copy();
	}
	
	
	
	
	public static   haxor.component.Camera get_current()
	{
		return haxor.component.Camera.m_current;
	}
	
	
	public static  haxor.component.Camera m_current;
	
	
	
	public static   haxor.component.Camera get_main()
	{
		return haxor.component.Camera.m_main;
	}
	
	
	public static   haxor.component.Camera set_main(haxor.component.Camera v)
	{
		return haxor.component.Camera.m_main = v;
	}
	
	
	public static  haxor.component.Camera m_main;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Camera(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Camera(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  haxor.math.Color background;
	
	public  haxor.graphics.texture.TextureCube skybox;
	
	public  int clear;
	
	
	
	public final   int get_mask()
	{
		return this.m_mask;
	}
	
	
	public   int set_mask(int v)
	{
		if (( this.m_mask == v )) 
		{
			return v;
		}
		
		this.m_mask = v;
		int it = this.m_mask;
		this.m_layers = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 32 ))
			{
				int i = _g++;
				if (( (( it & 1 )) != 0 )) 
				{
					this.m_layers.push(( 1 << i ));
				}
				
				it = ( it >> 1 );
			}
			
		}
		
		return v;
	}
	
	
	public  int m_mask;
	
	public  haxe.root.Array<java.lang.Object> m_layers;
	
	
	
	public final   double get_fov()
	{
		return this.m_fov;
	}
	
	
	public final   double set_fov(double v)
	{
		this.m_fov = v;
		this.m_projection_dirty = true;
		return v;
	}
	
	
	public  double m_fov;
	
	
	
	public final   double get_near()
	{
		return this.m_near;
	}
	
	
	public final   double set_near(double v)
	{
		this.m_near = v;
		this.m_projection_dirty = true;
		this.m_proj_uniform_dirty = true;
		return v;
	}
	
	
	public  double m_near;
	
	
	
	public final   double get_far()
	{
		return this.m_far;
	}
	
	
	public final   double set_far(double v)
	{
		this.m_far = v;
		this.m_projection_dirty = true;
		this.m_proj_uniform_dirty = true;
		return v;
	}
	
	
	public  double m_far;
	
	
	
	public  int m_order;
	
	public   int get_order()
	{
		return this.m_order;
	}
	
	
	public   int set_order(int v)
	{
		if (( this.m_order == v )) 
		{
			return v;
		}
		
		this.m_order = v;
		haxor.context.EngineContext.camera.SortCameraList();
		return this.m_order;
	}
	
	
	
	
	public final   haxor.math.AABB2 get_pixelViewport()
	{
		return this.m_pixelViewport.get_clone();
	}
	
	
	public  haxor.math.AABB2 m_pixelViewport;
	
	
	
	public final   haxor.math.AABB2 get_viewport()
	{
		return this.m_viewport.get_clone();
	}
	
	
	public final   haxor.math.AABB2 set_viewport(haxor.math.AABB2 v)
	{
		this.m_viewport.SetAABB2(v);
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	
	
	public  double m_aspect;
	
	public  haxor.math.AABB2 m_viewport;
	
	public  haxor.math.Matrix4 CameraToWorld;
	
	public final   haxor.math.Matrix4 get_CameraToWorld()
	{
		return this.m_entity.m_transform.get_WorldMatrix();
	}
	
	
	public  haxor.math.Matrix4 WorldToCamera;
	
	public   haxor.math.Matrix4 get_WorldToCamera()
	{
		return this.m_entity.m_transform.get_WorldMatrixInverse();
	}
	
	
	public  haxor.math.Matrix4 ProjectionMatrix;
	
	public final   haxor.math.Matrix4 get_ProjectionMatrix()
	{
		this.UpdateProjection();
		return this.m_projectionMatrix;
	}
	
	
	public  haxor.math.Matrix4 m_projectionMatrix;
	
	public  haxor.math.Matrix4 m_skyboxProjection;
	
	public  haxor.math.Matrix4 ProjectionMatrixInverse;
	
	public final   haxor.math.Matrix4 get_ProjectionMatrixInverse()
	{
		this.UpdateProjection();
		return this.m_projectionMatrixInverse;
	}
	
	
	public  haxor.math.Matrix4 m_projectionMatrixInverse;
	
	public  haxor.math.Matrix4 m_skyboxProjectionInverse;
	
	public  haxor.graphics.texture.RenderTexture target;
	
	public final   haxor.graphics.texture.RenderTexture get_target()
	{
		return this.m_target;
	}
	
	
	public final   haxor.graphics.texture.RenderTexture set_target(haxor.graphics.texture.RenderTexture v)
	{
		this.m_target = v;
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	
	
	public  haxor.graphics.texture.RenderTexture m_target;
	
	
	
	public   double get_quality()
	{
		return this.m_quality;
	}
	
	
	public   double set_quality(double v)
	{
		if (( v <= 0.0 )) 
		{
			this.m_quality = 0.0;
		}
		 else 
		{
			if (( v >= 1.0 )) 
			{
				this.m_quality = 1.0;
			}
			 else 
			{
				this.m_quality = v;
			}
			
		}
		
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	
	
	public  double m_quality;
	
	
	
	public   boolean get_captureDepth()
	{
		return this.m_captureDepth;
	}
	
	
	public   boolean set_captureDepth(boolean v)
	{
		this.m_captureDepth = v;
		haxor.context.EngineContext.camera.ClearTargets(this);
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	
	
	public  boolean m_captureDepth;
	
	
	
	public   haxe.root.Array get_filters()
	{
		return this.m_filters;
	}
	
	
	public   haxe.root.Array set_filters(haxe.root.Array v)
	{
		if (( v == null )) 
		{
			this.m_filters = new haxe.root.Array(new java.lang.Object[]{});
		}
		 else 
		{
			this.m_filters = v;
		}
		
		return this.m_filters;
	}
	
	
	public  haxe.root.Array m_filters;
	
	public  boolean m_projection_dirty;
	
	public  boolean m_view_uniform_dirty;
	
	public  boolean m_proj_uniform_dirty;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		{
			haxor.context.UID _this = haxor.context.EngineContext.camera.cid;
			if (( _this.m_cache.length <= 0 )) 
			{
				this.__cid = _this.m_id++;
			}
			 else 
			{
				this.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		if (( haxor.component.Camera.m_main == null )) 
		{
			haxor.component.Camera.m_main = this;
		}
		
		this.m_order = 0;
		this.m_quality = 1.0;
		this.m_pixelViewport = haxor.math.AABB2.get_empty();
		this.m_viewport = haxor.math.AABB2.get_empty();
		this.m_projectionMatrix = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_projectionMatrixInverse = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_skyboxProjection = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_skyboxProjectionInverse = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_fov = ((double) (60) );
		this.m_near = 0.1;
		this.m_far = ((double) (500) );
		this.m_filters = new haxe.root.Array(new java.lang.Object[]{});
		this.background = new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.clear = haxor.core.ClearFlag.ColorDepth;
		this.set_mask(1);
		{
			haxor.math.AABB2 v = new haxor.math.AABB2(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
			this.m_viewport.SetAABB2(v);
			haxor.context.EngineContext.camera.UpdateViewport(this);
			haxor.math.AABB2 __temp_expr161032 = v;
		}
		
		this.m_projection_dirty = true;
		this.m_view_uniform_dirty = true;
		this.m_proj_uniform_dirty = true;
		haxor.context.EngineContext.camera.Create(this);
	}
	
	
	public   haxor.math.Vector4 WorldToProjection(haxor.math.Vector3 p_world_point)
	{
		haxor.math.Vector4 p = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			p = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		p.w = 1.0;
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;
		{
			haxor.math.Matrix4 _this1 = this.get_WorldToCamera();
			double vx = ( ( ( ( _this1.m00 * p.x ) + ( _this1.m01 * p.y ) ) + ( _this1.m02 * p.z ) ) + ( _this1.m03 * p.w ) );
			double vy = ( ( ( ( _this1.m10 * p.x ) + ( _this1.m11 * p.y ) ) + ( _this1.m12 * p.z ) ) + ( _this1.m13 * p.w ) );
			double vz = ( ( ( ( _this1.m20 * p.x ) + ( _this1.m21 * p.y ) ) + ( _this1.m22 * p.z ) ) + ( _this1.m23 * p.w ) );
			double vw = ( ( ( ( _this1.m30 * p.x ) + ( _this1.m31 * p.y ) ) + ( _this1.m32 * p.z ) ) + ( _this1.m33 * p.w ) );
			p.x = vx;
			p.y = vy;
			p.z = vz;
			p.w = vw;
			haxor.math.Vector4 __temp_expr161033 = p;
		}
		
		{
			haxor.math.Matrix4 _this2 = null;
			{
				this.UpdateProjection();
				_this2 = this.m_projectionMatrix;
			}
			
			double vx1 = ( ( ( ( _this2.m00 * p.x ) + ( _this2.m01 * p.y ) ) + ( _this2.m02 * p.z ) ) + ( _this2.m03 * p.w ) );
			double vy1 = ( ( ( ( _this2.m10 * p.x ) + ( _this2.m11 * p.y ) ) + ( _this2.m12 * p.z ) ) + ( _this2.m13 * p.w ) );
			double vz1 = ( ( ( ( _this2.m20 * p.x ) + ( _this2.m21 * p.y ) ) + ( _this2.m22 * p.z ) ) + ( _this2.m23 * p.w ) );
			double vw1 = ( ( ( ( _this2.m30 * p.x ) + ( _this2.m31 * p.y ) ) + ( _this2.m32 * p.z ) ) + ( _this2.m33 * p.w ) );
			p.x = vx1;
			p.y = vy1;
			p.z = vz1;
			p.w = vw1;
			haxor.math.Vector4 __temp_expr161034 = p;
		}
		
		return p;
	}
	
	
	public   double WorldToDepth(haxor.math.Vector3 p_world_point)
	{
		haxor.math.Matrix4 wm = this.get_WorldToCamera();
		return ( ( ( ( wm.m20 * p_world_point.x ) + ( wm.m21 * p_world_point.y ) ) + ( wm.m22 * p_world_point.z ) ) + wm.m23 );
	}
	
	
	public   boolean IsCulled(haxor.math.Vector3 p_world_point)
	{
		return this.WorldToProjection(p_world_point).IsCulled();
	}
	
	
	public final   void LookAt(haxor.math.Vector3 p_at, haxor.math.Vector3 p_up, java.lang.Object p_smooth)
	{
		double __temp_p_smooth160412 = ( (( p_smooth == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_smooth)) )) );
		haxor.math.Vector3 p = this.m_entity.m_transform.get_position();
		haxor.math.Quaternion r = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			r = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion q = null;
		{
			haxor.math.Quaternion p_result = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				p_result = _this1.m_q.__get(_this1.m_nq = ( (( _this1.m_nq + 1 )) % _this1.m_q.length ));
			}
			
			haxor.math.Matrix4 __temp_stmt161036 = null;
			{
				haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
				__temp_stmt161036 = _this2.m_m4.__get(_this2.m_nq = ( (( _this2.m_nm4 + 1 )) % _this2.m_m4.length ));
			}
			
			haxor.math.Matrix4 __temp_stmt161035 = haxor.math.Matrix4.LookAt(p, p_at, p_up, __temp_stmt161036);
			q = haxor.math.Quaternion.FromMatrix(__temp_stmt161035, p_result);
		}
		
		if (( __temp_p_smooth160412 > 0 )) 
		{
			haxor.math.Quaternion __temp_stmt161037 = null;
			{
				haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
				__temp_stmt161037 = _this3.m_q.__get(_this3.m_nq = ( (( _this3.m_nq + 1 )) % _this3.m_q.length ));
			}
			
			r = haxor.math.Quaternion.Lerp(r, q, ( __temp_p_smooth160412 * haxor.core.Time.m_delta ), __temp_stmt161037);
		}
		 else 
		{
			r = q;
		}
		
		this.m_entity.m_transform.set_rotation(r);
	}
	
	
	public   void UpdateProjection()
	{
		if ( ! (this.m_projection_dirty) ) 
		{
			return ;
		}
		
		this.m_projection_dirty = false;
		this.m_view_uniform_dirty = true;
		haxor.math.Matrix4.Perspective(this.m_fov, this.m_aspect, this.m_near, this.m_far, this.m_projectionMatrix);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov, this.m_aspect, this.m_near, this.m_far, this.m_projectionMatrixInverse);
		haxor.math.Matrix4.Perspective(this.m_fov, this.m_aspect, 0.1, 100000.0, this.m_skyboxProjection);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov, this.m_aspect, 0.1, 100000.0, this.m_skyboxProjectionInverse);
	}
	
	
	@Override public   void OnTransformUpdate()
	{
		this.m_view_uniform_dirty = true;
	}
	
	
	@Override public   void OnDestroy()
	{
		haxor.context.EngineContext.camera.Destroy(this);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161038 = true;
			switch (field.hashCode())
			{
				case -729568467:
				{
					if (field.equals("m_quality")) 
					{
						__temp_executeDef161038 = false;
						this.m_quality = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 94746189:
				{
					if (field.equals("clear")) 
					{
						__temp_executeDef161038 = false;
						this.clear = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 651215103:
				{
					if (field.equals("quality")) 
					{
						__temp_executeDef161038 = false;
						this.set_quality(value);
						return value;
					}
					
					break;
				}
				
				
				case 3344108:
				{
					if (field.equals("mask")) 
					{
						__temp_executeDef161038 = false;
						this.set_mask(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -2007028630:
				{
					if (field.equals("m_aspect")) 
					{
						__temp_executeDef161038 = false;
						this.m_aspect = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083311234:
				{
					if (field.equals("m_mask")) 
					{
						__temp_executeDef161038 = false;
						this.m_mask = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 779429116:
				{
					if (field.equals("m_order")) 
					{
						__temp_executeDef161038 = false;
						this.m_order = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 101581:
				{
					if (field.equals("fov")) 
					{
						__temp_executeDef161038 = false;
						this.set_fov(value);
						return value;
					}
					
					break;
				}
				
				
				case 106006350:
				{
					if (field.equals("order")) 
					{
						__temp_executeDef161038 = false;
						this.set_order(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 103595515:
				{
					if (field.equals("m_fov")) 
					{
						__temp_executeDef161038 = false;
						this.m_fov = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103595077:
				{
					if (field.equals("m_far")) 
					{
						__temp_executeDef161038 = false;
						this.m_far = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3377192:
				{
					if (field.equals("near")) 
					{
						__temp_executeDef161038 = false;
						this.set_near(value);
						return value;
					}
					
					break;
				}
				
				
				case 101143:
				{
					if (field.equals("far")) 
					{
						__temp_executeDef161038 = false;
						this.set_far(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083278150:
				{
					if (field.equals("m_near")) 
					{
						__temp_executeDef161038 = false;
						this.m_near = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161038) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161039 = true;
			switch (field.hashCode())
			{
				case 588326199:
				{
					if (field.equals("m_proj_uniform_dirty")) 
					{
						__temp_executeDef161039 = false;
						this.m_proj_uniform_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1332194002:
				{
					if (field.equals("background")) 
					{
						__temp_executeDef161039 = false;
						this.background = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1460314497:
				{
					if (field.equals("m_view_uniform_dirty")) 
					{
						__temp_executeDef161039 = false;
						this.m_view_uniform_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -900095734:
				{
					if (field.equals("skybox")) 
					{
						__temp_executeDef161039 = false;
						this.skybox = ((haxor.graphics.texture.TextureCube) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1839774860:
				{
					if (field.equals("m_projection_dirty")) 
					{
						__temp_executeDef161039 = false;
						this.m_projection_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 94746189:
				{
					if (field.equals("clear")) 
					{
						__temp_executeDef161039 = false;
						this.clear = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 2059636265:
				{
					if (field.equals("m_filters")) 
					{
						__temp_executeDef161039 = false;
						this.m_filters = ((haxe.root.Array) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3344108:
				{
					if (field.equals("mask")) 
					{
						__temp_executeDef161039 = false;
						this.set_mask(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -854547461:
				{
					if (field.equals("filters")) 
					{
						__temp_executeDef161039 = false;
						this.set_filters(((haxe.root.Array) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1083311234:
				{
					if (field.equals("m_mask")) 
					{
						__temp_executeDef161039 = false;
						this.m_mask = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -633081425:
				{
					if (field.equals("m_captureDepth")) 
					{
						__temp_executeDef161039 = false;
						this.m_captureDepth = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1708462764:
				{
					if (field.equals("m_layers")) 
					{
						__temp_executeDef161039 = false;
						this.m_layers = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 741715741:
				{
					if (field.equals("captureDepth")) 
					{
						__temp_executeDef161039 = false;
						this.set_captureDepth(haxe.lang.Runtime.toBool(value));
						return value;
					}
					
					break;
				}
				
				
				case 101581:
				{
					if (field.equals("fov")) 
					{
						__temp_executeDef161039 = false;
						this.set_fov(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -729568467:
				{
					if (field.equals("m_quality")) 
					{
						__temp_executeDef161039 = false;
						this.m_quality = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 103595515:
				{
					if (field.equals("m_fov")) 
					{
						__temp_executeDef161039 = false;
						this.m_fov = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 651215103:
				{
					if (field.equals("quality")) 
					{
						__temp_executeDef161039 = false;
						this.set_quality(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3377192:
				{
					if (field.equals("near")) 
					{
						__temp_executeDef161039 = false;
						this.set_near(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1479636573:
				{
					if (field.equals("m_target")) 
					{
						__temp_executeDef161039 = false;
						this.m_target = ((haxor.graphics.texture.RenderTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083278150:
				{
					if (field.equals("m_near")) 
					{
						__temp_executeDef161039 = false;
						this.m_near = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef161039 = false;
						this.target = ((haxor.graphics.texture.RenderTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 101143:
				{
					if (field.equals("far")) 
					{
						__temp_executeDef161039 = false;
						this.set_far(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -227302363:
				{
					if (field.equals("m_skyboxProjectionInverse")) 
					{
						__temp_executeDef161039 = false;
						this.m_skyboxProjectionInverse = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103595077:
				{
					if (field.equals("m_far")) 
					{
						__temp_executeDef161039 = false;
						this.m_far = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 156269646:
				{
					if (field.equals("m_projectionMatrixInverse")) 
					{
						__temp_executeDef161039 = false;
						this.m_projectionMatrixInverse = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106006350:
				{
					if (field.equals("order")) 
					{
						__temp_executeDef161039 = false;
						this.set_order(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -168262144:
				{
					if (field.equals("ProjectionMatrixInverse")) 
					{
						__temp_executeDef161039 = false;
						this.ProjectionMatrixInverse = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 779429116:
				{
					if (field.equals("m_order")) 
					{
						__temp_executeDef161039 = false;
						this.m_order = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1224692597:
				{
					if (field.equals("m_skyboxProjection")) 
					{
						__temp_executeDef161039 = false;
						this.m_skyboxProjection = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1725671174:
				{
					if (field.equals("m_pixelViewport")) 
					{
						__temp_executeDef161039 = false;
						this.m_pixelViewport = ((haxor.math.AABB2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1937424514:
				{
					if (field.equals("m_projectionMatrix")) 
					{
						__temp_executeDef161039 = false;
						this.m_projectionMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1196685478:
				{
					if (field.equals("viewport")) 
					{
						__temp_executeDef161039 = false;
						this.set_viewport(((haxor.math.AABB2) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1609016560:
				{
					if (field.equals("ProjectionMatrix")) 
					{
						__temp_executeDef161039 = false;
						this.ProjectionMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -2007028630:
				{
					if (field.equals("m_aspect")) 
					{
						__temp_executeDef161039 = false;
						this.m_aspect = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 699511570:
				{
					if (field.equals("WorldToCamera")) 
					{
						__temp_executeDef161039 = false;
						this.WorldToCamera = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1342067768:
				{
					if (field.equals("m_viewport")) 
					{
						__temp_executeDef161039 = false;
						this.m_viewport = ((haxor.math.AABB2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1649208622:
				{
					if (field.equals("CameraToWorld")) 
					{
						__temp_executeDef161039 = false;
						this.CameraToWorld = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161039) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161040 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -1332194002:
				{
					if (field.equals("background")) 
					{
						__temp_executeDef161040 = false;
						return this.background;
					}
					
					break;
				}
				
				
				case 1899224918:
				{
					if (field.equals("OnTransformUpdate")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTransformUpdate"))) );
					}
					
					break;
				}
				
				
				case -900095734:
				{
					if (field.equals("skybox")) 
					{
						__temp_executeDef161040 = false;
						return this.skybox;
					}
					
					break;
				}
				
				
				case 198540312:
				{
					if (field.equals("UpdateProjection")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateProjection"))) );
					}
					
					break;
				}
				
				
				case 94746189:
				{
					if (field.equals("clear")) 
					{
						__temp_executeDef161040 = false;
						return this.clear;
					}
					
					break;
				}
				
				
				case -2013229230:
				{
					if (field.equals("LookAt")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LookAt"))) );
					}
					
					break;
				}
				
				
				case 3344108:
				{
					if (field.equals("mask")) 
					{
						__temp_executeDef161040 = false;
						return this.get_mask();
					}
					
					break;
				}
				
				
				case -610626693:
				{
					if (field.equals("IsCulled")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsCulled"))) );
					}
					
					break;
				}
				
				
				case 1976456757:
				{
					if (field.equals("get_mask")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mask"))) );
					}
					
					break;
				}
				
				
				case 854894902:
				{
					if (field.equals("WorldToDepth")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("WorldToDepth"))) );
					}
					
					break;
				}
				
				
				case 1415344297:
				{
					if (field.equals("set_mask")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_mask"))) );
					}
					
					break;
				}
				
				
				case -951518276:
				{
					if (field.equals("WorldToProjection")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("WorldToProjection"))) );
					}
					
					break;
				}
				
				
				case -1083311234:
				{
					if (field.equals("m_mask")) 
					{
						__temp_executeDef161040 = false;
						return this.m_mask;
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1708462764:
				{
					if (field.equals("m_layers")) 
					{
						__temp_executeDef161040 = false;
						return this.m_layers;
					}
					
					break;
				}
				
				
				case 588326199:
				{
					if (field.equals("m_proj_uniform_dirty")) 
					{
						__temp_executeDef161040 = false;
						return this.m_proj_uniform_dirty;
					}
					
					break;
				}
				
				
				case 101581:
				{
					if (field.equals("fov")) 
					{
						__temp_executeDef161040 = false;
						return this.get_fov();
					}
					
					break;
				}
				
				
				case -1460314497:
				{
					if (field.equals("m_view_uniform_dirty")) 
					{
						__temp_executeDef161040 = false;
						return this.m_view_uniform_dirty;
					}
					
					break;
				}
				
				
				case -74796956:
				{
					if (field.equals("get_fov")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_fov"))) );
					}
					
					break;
				}
				
				
				case -1839774860:
				{
					if (field.equals("m_projection_dirty")) 
					{
						__temp_executeDef161040 = false;
						return this.m_projection_dirty;
					}
					
					break;
				}
				
				
				case 1985312624:
				{
					if (field.equals("set_fov")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_fov"))) );
					}
					
					break;
				}
				
				
				case 2059636265:
				{
					if (field.equals("m_filters")) 
					{
						__temp_executeDef161040 = false;
						return this.m_filters;
					}
					
					break;
				}
				
				
				case 103595515:
				{
					if (field.equals("m_fov")) 
					{
						__temp_executeDef161040 = false;
						return this.m_fov;
					}
					
					break;
				}
				
				
				case -866613986:
				{
					if (field.equals("set_filters")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_filters"))) );
					}
					
					break;
				}
				
				
				case 3377192:
				{
					if (field.equals("near")) 
					{
						__temp_executeDef161040 = false;
						return this.get_near();
					}
					
					break;
				}
				
				
				case -778034158:
				{
					if (field.equals("get_filters")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_filters"))) );
					}
					
					break;
				}
				
				
				case 1976489841:
				{
					if (field.equals("get_near")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_near"))) );
					}
					
					break;
				}
				
				
				case -854547461:
				{
					if (field.equals("filters")) 
					{
						__temp_executeDef161040 = false;
						return this.get_filters();
					}
					
					break;
				}
				
				
				case 1415377381:
				{
					if (field.equals("set_near")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_near"))) );
					}
					
					break;
				}
				
				
				case -633081425:
				{
					if (field.equals("m_captureDepth")) 
					{
						__temp_executeDef161040 = false;
						return this.m_captureDepth;
					}
					
					break;
				}
				
				
				case -1083278150:
				{
					if (field.equals("m_near")) 
					{
						__temp_executeDef161040 = false;
						return this.m_near;
					}
					
					break;
				}
				
				
				case -815002662:
				{
					if (field.equals("set_captureDepth")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_captureDepth"))) );
					}
					
					break;
				}
				
				
				case 101143:
				{
					if (field.equals("far")) 
					{
						__temp_executeDef161040 = false;
						return this.get_far();
					}
					
					break;
				}
				
				
				case 1016440166:
				{
					if (field.equals("get_captureDepth")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_captureDepth"))) );
					}
					
					break;
				}
				
				
				case -74797394:
				{
					if (field.equals("get_far")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_far"))) );
					}
					
					break;
				}
				
				
				case 741715741:
				{
					if (field.equals("captureDepth")) 
					{
						__temp_executeDef161040 = false;
						return this.get_captureDepth();
					}
					
					break;
				}
				
				
				case 1985312186:
				{
					if (field.equals("set_far")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_far"))) );
					}
					
					break;
				}
				
				
				case -729568467:
				{
					if (field.equals("m_quality")) 
					{
						__temp_executeDef161040 = false;
						return this.m_quality;
					}
					
					break;
				}
				
				
				case 103595077:
				{
					if (field.equals("m_far")) 
					{
						__temp_executeDef161040 = false;
						return this.m_far;
					}
					
					break;
				}
				
				
				case 639148578:
				{
					if (field.equals("set_quality")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_quality"))) );
					}
					
					break;
				}
				
				
				case 106006350:
				{
					if (field.equals("order")) 
					{
						__temp_executeDef161040 = false;
						return this.get_order();
					}
					
					break;
				}
				
				
				case 727728406:
				{
					if (field.equals("get_quality")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_quality"))) );
					}
					
					break;
				}
				
				
				case 779429116:
				{
					if (field.equals("m_order")) 
					{
						__temp_executeDef161040 = false;
						return this.m_order;
					}
					
					break;
				}
				
				
				case 651215103:
				{
					if (field.equals("quality")) 
					{
						__temp_executeDef161040 = false;
						return this.get_quality();
					}
					
					break;
				}
				
				
				case 1142956325:
				{
					if (field.equals("get_order")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_order"))) );
					}
					
					break;
				}
				
				
				case -1479636573:
				{
					if (field.equals("m_target")) 
					{
						__temp_executeDef161040 = false;
						return this.m_target;
					}
					
					break;
				}
				
				
				case 928339249:
				{
					if (field.equals("set_order")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_order"))) );
					}
					
					break;
				}
				
				
				case -1158389746:
				{
					if (field.equals("set_target")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_target"))) );
					}
					
					break;
				}
				
				
				case -2056631988:
				{
					if (field.equals("pixelViewport")) 
					{
						__temp_executeDef161040 = false;
						return this.get_pixelViewport();
					}
					
					break;
				}
				
				
				case 1199772314:
				{
					if (field.equals("get_target")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_target"))) );
					}
					
					break;
				}
				
				
				case -2130109405:
				{
					if (field.equals("get_pixelViewport")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_pixelViewport"))) );
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef161040 = false;
						return this.target;
					}
					
					break;
				}
				
				
				case -1725671174:
				{
					if (field.equals("m_pixelViewport")) 
					{
						__temp_executeDef161040 = false;
						return this.m_pixelViewport;
					}
					
					break;
				}
				
				
				case -227302363:
				{
					if (field.equals("m_skyboxProjectionInverse")) 
					{
						__temp_executeDef161040 = false;
						return this.m_skyboxProjectionInverse;
					}
					
					break;
				}
				
				
				case 1196685478:
				{
					if (field.equals("viewport")) 
					{
						__temp_executeDef161040 = false;
						return this.get_viewport();
					}
					
					break;
				}
				
				
				case 156269646:
				{
					if (field.equals("m_projectionMatrixInverse")) 
					{
						__temp_executeDef161040 = false;
						return this.m_projectionMatrixInverse;
					}
					
					break;
				}
				
				
				case -726369425:
				{
					if (field.equals("get_viewport")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_viewport"))) );
					}
					
					break;
				}
				
				
				case 717944855:
				{
					if (field.equals("get_ProjectionMatrixInverse")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_ProjectionMatrixInverse"))) );
					}
					
					break;
				}
				
				
				case 822623203:
				{
					if (field.equals("set_viewport")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_viewport"))) );
					}
					
					break;
				}
				
				
				case -168262144:
				{
					if (field.equals("ProjectionMatrixInverse")) 
					{
						__temp_executeDef161040 = false;
						if (handleProperties) 
						{
							return this.get_ProjectionMatrixInverse();
						}
						 else 
						{
							return this.ProjectionMatrixInverse;
						}
						
					}
					
					break;
				}
				
				
				case -2007028630:
				{
					if (field.equals("m_aspect")) 
					{
						__temp_executeDef161040 = false;
						return this.m_aspect;
					}
					
					break;
				}
				
				
				case -1224692597:
				{
					if (field.equals("m_skyboxProjection")) 
					{
						__temp_executeDef161040 = false;
						return this.m_skyboxProjection;
					}
					
					break;
				}
				
				
				case 1342067768:
				{
					if (field.equals("m_viewport")) 
					{
						__temp_executeDef161040 = false;
						return this.m_viewport;
					}
					
					break;
				}
				
				
				case 1937424514:
				{
					if (field.equals("m_projectionMatrix")) 
					{
						__temp_executeDef161040 = false;
						return this.m_projectionMatrix;
					}
					
					break;
				}
				
				
				case -1649208622:
				{
					if (field.equals("CameraToWorld")) 
					{
						__temp_executeDef161040 = false;
						if (handleProperties) 
						{
							return this.get_CameraToWorld();
						}
						 else 
						{
							return this.CameraToWorld;
						}
						
					}
					
					break;
				}
				
				
				case -141425447:
				{
					if (field.equals("get_ProjectionMatrix")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_ProjectionMatrix"))) );
					}
					
					break;
				}
				
				
				case -1722686039:
				{
					if (field.equals("get_CameraToWorld")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_CameraToWorld"))) );
					}
					
					break;
				}
				
				
				case -1609016560:
				{
					if (field.equals("ProjectionMatrix")) 
					{
						__temp_executeDef161040 = false;
						if (handleProperties) 
						{
							return this.get_ProjectionMatrix();
						}
						 else 
						{
							return this.ProjectionMatrix;
						}
						
					}
					
					break;
				}
				
				
				case 699511570:
				{
					if (field.equals("WorldToCamera")) 
					{
						__temp_executeDef161040 = false;
						if (handleProperties) 
						{
							return this.get_WorldToCamera();
						}
						 else 
						{
							return this.WorldToCamera;
						}
						
					}
					
					break;
				}
				
				
				case 626034153:
				{
					if (field.equals("get_WorldToCamera")) 
					{
						__temp_executeDef161040 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_WorldToCamera"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161040) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161041 = true;
			switch (field.hashCode())
			{
				case -729568467:
				{
					if (field.equals("m_quality")) 
					{
						__temp_executeDef161041 = false;
						return this.m_quality;
					}
					
					break;
				}
				
				
				case 94746189:
				{
					if (field.equals("clear")) 
					{
						__temp_executeDef161041 = false;
						return ((double) (this.clear) );
					}
					
					break;
				}
				
				
				case 651215103:
				{
					if (field.equals("quality")) 
					{
						__temp_executeDef161041 = false;
						return this.get_quality();
					}
					
					break;
				}
				
				
				case 3344108:
				{
					if (field.equals("mask")) 
					{
						__temp_executeDef161041 = false;
						return ((double) (this.get_mask()) );
					}
					
					break;
				}
				
				
				case -2007028630:
				{
					if (field.equals("m_aspect")) 
					{
						__temp_executeDef161041 = false;
						return this.m_aspect;
					}
					
					break;
				}
				
				
				case -1083311234:
				{
					if (field.equals("m_mask")) 
					{
						__temp_executeDef161041 = false;
						return ((double) (this.m_mask) );
					}
					
					break;
				}
				
				
				case 779429116:
				{
					if (field.equals("m_order")) 
					{
						__temp_executeDef161041 = false;
						return ((double) (this.m_order) );
					}
					
					break;
				}
				
				
				case 101581:
				{
					if (field.equals("fov")) 
					{
						__temp_executeDef161041 = false;
						return this.get_fov();
					}
					
					break;
				}
				
				
				case 106006350:
				{
					if (field.equals("order")) 
					{
						__temp_executeDef161041 = false;
						return ((double) (this.get_order()) );
					}
					
					break;
				}
				
				
				case 103595515:
				{
					if (field.equals("m_fov")) 
					{
						__temp_executeDef161041 = false;
						return this.m_fov;
					}
					
					break;
				}
				
				
				case 103595077:
				{
					if (field.equals("m_far")) 
					{
						__temp_executeDef161041 = false;
						return this.m_far;
					}
					
					break;
				}
				
				
				case 3377192:
				{
					if (field.equals("near")) 
					{
						__temp_executeDef161041 = false;
						return this.get_near();
					}
					
					break;
				}
				
				
				case 101143:
				{
					if (field.equals("far")) 
					{
						__temp_executeDef161041 = false;
						return this.get_far();
					}
					
					break;
				}
				
				
				case -1083278150:
				{
					if (field.equals("m_near")) 
					{
						__temp_executeDef161041 = false;
						return this.m_near;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161041) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			int __temp_hash161043 = field.hashCode();
			boolean __temp_executeDef161042 = true;
			switch (__temp_hash161043)
			{
				case 602652923:case 1899224918:case 312095663:
				{
					if (( (( ( __temp_hash161043 == 602652923 ) && field.equals("OnDestroy") )) || ( (( ( __temp_hash161043 == 1899224918 ) && field.equals("OnTransformUpdate") )) || field.equals("OnBuild") ) )) 
					{
						__temp_executeDef161042 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1976456757:
				{
					if (field.equals("get_mask")) 
					{
						__temp_executeDef161042 = false;
						return this.get_mask();
					}
					
					break;
				}
				
				
				case 198540312:
				{
					if (field.equals("UpdateProjection")) 
					{
						__temp_executeDef161042 = false;
						this.UpdateProjection();
					}
					
					break;
				}
				
				
				case 1415344297:
				{
					if (field.equals("set_mask")) 
					{
						__temp_executeDef161042 = false;
						return this.set_mask(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -2013229230:
				{
					if (field.equals("LookAt")) 
					{
						__temp_executeDef161042 = false;
						this.LookAt(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case -74796956:
				{
					if (field.equals("get_fov")) 
					{
						__temp_executeDef161042 = false;
						return this.get_fov();
					}
					
					break;
				}
				
				
				case -610626693:
				{
					if (field.equals("IsCulled")) 
					{
						__temp_executeDef161042 = false;
						return this.IsCulled(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985312624:
				{
					if (field.equals("set_fov")) 
					{
						__temp_executeDef161042 = false;
						return this.set_fov(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 854894902:
				{
					if (field.equals("WorldToDepth")) 
					{
						__temp_executeDef161042 = false;
						return this.WorldToDepth(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1976489841:
				{
					if (field.equals("get_near")) 
					{
						__temp_executeDef161042 = false;
						return this.get_near();
					}
					
					break;
				}
				
				
				case -951518276:
				{
					if (field.equals("WorldToProjection")) 
					{
						__temp_executeDef161042 = false;
						return this.WorldToProjection(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415377381:
				{
					if (field.equals("set_near")) 
					{
						__temp_executeDef161042 = false;
						return this.set_near(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -866613986:
				{
					if (field.equals("set_filters")) 
					{
						__temp_executeDef161042 = false;
						return this.set_filters(((haxe.root.Array) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -74797394:
				{
					if (field.equals("get_far")) 
					{
						__temp_executeDef161042 = false;
						return this.get_far();
					}
					
					break;
				}
				
				
				case -778034158:
				{
					if (field.equals("get_filters")) 
					{
						__temp_executeDef161042 = false;
						return this.get_filters();
					}
					
					break;
				}
				
				
				case 1985312186:
				{
					if (field.equals("set_far")) 
					{
						__temp_executeDef161042 = false;
						return this.set_far(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -815002662:
				{
					if (field.equals("set_captureDepth")) 
					{
						__temp_executeDef161042 = false;
						return this.set_captureDepth(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1142956325:
				{
					if (field.equals("get_order")) 
					{
						__temp_executeDef161042 = false;
						return this.get_order();
					}
					
					break;
				}
				
				
				case 1016440166:
				{
					if (field.equals("get_captureDepth")) 
					{
						__temp_executeDef161042 = false;
						return this.get_captureDepth();
					}
					
					break;
				}
				
				
				case 928339249:
				{
					if (field.equals("set_order")) 
					{
						__temp_executeDef161042 = false;
						return this.set_order(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 639148578:
				{
					if (field.equals("set_quality")) 
					{
						__temp_executeDef161042 = false;
						return this.set_quality(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -2130109405:
				{
					if (field.equals("get_pixelViewport")) 
					{
						__temp_executeDef161042 = false;
						return this.get_pixelViewport();
					}
					
					break;
				}
				
				
				case 727728406:
				{
					if (field.equals("get_quality")) 
					{
						__temp_executeDef161042 = false;
						return this.get_quality();
					}
					
					break;
				}
				
				
				case -726369425:
				{
					if (field.equals("get_viewport")) 
					{
						__temp_executeDef161042 = false;
						return this.get_viewport();
					}
					
					break;
				}
				
				
				case -1158389746:
				{
					if (field.equals("set_target")) 
					{
						__temp_executeDef161042 = false;
						return this.set_target(((haxor.graphics.texture.RenderTexture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 822623203:
				{
					if (field.equals("set_viewport")) 
					{
						__temp_executeDef161042 = false;
						return this.set_viewport(((haxor.math.AABB2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1199772314:
				{
					if (field.equals("get_target")) 
					{
						__temp_executeDef161042 = false;
						return this.get_target();
					}
					
					break;
				}
				
				
				case -1722686039:
				{
					if (field.equals("get_CameraToWorld")) 
					{
						__temp_executeDef161042 = false;
						return this.get_CameraToWorld();
					}
					
					break;
				}
				
				
				case 717944855:
				{
					if (field.equals("get_ProjectionMatrixInverse")) 
					{
						__temp_executeDef161042 = false;
						return this.get_ProjectionMatrixInverse();
					}
					
					break;
				}
				
				
				case 626034153:
				{
					if (field.equals("get_WorldToCamera")) 
					{
						__temp_executeDef161042 = false;
						return this.get_WorldToCamera();
					}
					
					break;
				}
				
				
				case -141425447:
				{
					if (field.equals("get_ProjectionMatrix")) 
					{
						__temp_executeDef161042 = false;
						return this.get_ProjectionMatrix();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161042) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_proj_uniform_dirty");
		baseArr.push("m_view_uniform_dirty");
		baseArr.push("m_projection_dirty");
		baseArr.push("m_filters");
		baseArr.push("filters");
		baseArr.push("m_captureDepth");
		baseArr.push("captureDepth");
		baseArr.push("m_quality");
		baseArr.push("quality");
		baseArr.push("m_target");
		baseArr.push("target");
		baseArr.push("m_skyboxProjectionInverse");
		baseArr.push("m_projectionMatrixInverse");
		baseArr.push("ProjectionMatrixInverse");
		baseArr.push("m_skyboxProjection");
		baseArr.push("m_projectionMatrix");
		baseArr.push("ProjectionMatrix");
		baseArr.push("WorldToCamera");
		baseArr.push("CameraToWorld");
		baseArr.push("m_viewport");
		baseArr.push("m_aspect");
		baseArr.push("viewport");
		baseArr.push("m_pixelViewport");
		baseArr.push("pixelViewport");
		baseArr.push("m_order");
		baseArr.push("order");
		baseArr.push("m_far");
		baseArr.push("far");
		baseArr.push("m_near");
		baseArr.push("near");
		baseArr.push("m_fov");
		baseArr.push("fov");
		baseArr.push("m_layers");
		baseArr.push("m_mask");
		baseArr.push("mask");
		baseArr.push("clear");
		baseArr.push("skybox");
		baseArr.push("background");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


