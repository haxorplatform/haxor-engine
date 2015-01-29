package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main extends haxor.core.Application implements haxor.core.IRenderable, haxor.core.IUpdateable
{
	public    Main(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Main(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxe.root.Main.__hx_ctor__Main(this, p_name);
	}
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me9, java.lang.String p_name)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me9, p_name);
		__temp_me9.queue = 3;
	}
	
	
	public static   void main()
	{
		haxor.platform.android.Entry.Initialize();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Main(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Main(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  haxor.component.Camera cam;
	
	public  haxor.component.CameraOrbit orbit;
	
	public  haxor.component.Transform container;
	
	public  haxor.graphics.material.Material mat;
	
	public  haxor.component.Transform player;
	
	public  int queue;
	
	@Override public   boolean Load()
	{
		haxe.root.Array<haxe.root.Main> _g = new haxe.root.Array<haxe.root.Main>(new haxe.root.Main[]{this});
		haxor.net.Web.root = "http://www.haxor.xyz/resources/";
		haxor.net.Web.LoadCollada("./character/skeleton/grunt/animation_idle01.DAE", new haxe.root.Main_Load_104__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		haxor.net.Web.LoadTexture2D("./character/skeleton/grunt/DiffuseTexture.png", true, new haxe.root.Main_Load_114__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		haxor.net.Web.LoadCollada("./character/skeleton/grunt/model.DAE", new haxe.root.Main_Load_124__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		return false;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		this.orbit = haxor.component.CameraOrbit.Create(40.0, 45, 30);
		haxor.component.CameraOrbitInput ci = ((haxor.component.CameraOrbitInput) (this.orbit.m_entity.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.CameraOrbitInput.class) )) ))) );
		this.orbit.smooth = 5.0;
		ci.zoomSpeed = 1.0;
		this.cam = ((haxor.component.Camera) (this.orbit.m_entity.GetComponentInChildren(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.Camera.class) )) ))) );
		{
			haxor.component.Camera _this = this.cam;
			_this.m_far = 1000.0;
			_this.m_projection_dirty = true;
			_this.m_proj_uniform_dirty = true;
			double __temp_expr432 = 1000.0;
		}
		
		this.cam.background = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (null) ));
		{
			haxor.core.Entity _this1 = new haxor.core.Entity(haxe.lang.Runtime.toString("container"));
			this.container = _this1.m_transform;
		}
		
		{
			haxor.graphics.texture.Texture p_texture = ((haxor.graphics.texture.Texture) (haxor.io.file.Asset.Get("texture_diffuse")) );
			boolean p_ztest = true;
			boolean p_zwrite = true;
			haxor.graphics.material.Material m = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("Opaque"));
			m.set_shader(( (( p_texture == null )) ? (( (( haxor.graphics.material.Shader.m_flat_shader == null )) ? (haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source))) : (haxor.graphics.material.Shader.m_flat_shader) )) : (( (( haxor.graphics.material.Shader.m_flat_texture_shader == null )) ? (haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_texture_source))) : (haxor.graphics.material.Shader.m_flat_texture_shader) )) ));
			m.queue = 1000;
			m.ztest = p_ztest;
			m.zwrite = p_zwrite;
			if (( p_texture != null )) 
			{
				m.SetTexture("DiffuseTexture", p_texture);
			}
			
			this.mat = m;
		}
		
		this.mat.set_shader(( (( haxor.graphics.material.Shader.m_flat_texture_skin_shader == null )) ? (haxor.graphics.material.Shader.m_flat_texture_skin_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_texture_skin_source))) : (haxor.graphics.material.Shader.m_flat_texture_skin_shader) ));
		this.mat.set_name("PlayerMaterial");
		this.mat.SetTexture("DiffuseTexture", ((haxor.graphics.texture.Texture) (haxor.io.file.Asset.Get("texture_diffuse")) ));
		haxor.io.file.ColladaFile cf = null;
		cf = ((haxor.io.file.ColladaFile) (haxor.io.file.Asset.Get("model")) );
		{
			haxor.core.Entity _this2 = new haxor.core.Entity(haxe.lang.Runtime.toString("player"));
			this.player = _this2.m_transform;
		}
		
		haxor.component.Transform asset = null;
		{
			haxor.core.Entity _this3 = null;
			_this3 = ((haxor.core.Entity) (cf.get_asset()) );
			asset = _this3.m_transform;
		}
		
		asset.set_parent(this.player);
		asset.set_localScale(new haxor.math.Vector3(((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) )));
		haxe.root.Array<haxor.component.MeshRenderer> mr = ((haxe.root.Array<haxor.component.MeshRenderer>) (((haxe.root.Array) (this.player.m_entity.GetComponentsInChildren(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.MeshRenderer.class) )) ))) )) );
		{
			int _g1 = 0;
			int _g = mr.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				mr.__get(i).set_material(this.mat);
			}
			
		}
		
		haxor.component.animation.Animation anim = null;
		cf = ((haxor.io.file.ColladaFile) (haxor.io.file.Asset.Get("animation_idle")) );
		cf.AddAnimations(asset.m_entity, null);
		anim = asset.m_entity.m_animation;
		anim.Play(anim.clips.__get(0), null);
		anim.clips.__get(0).wrap = haxor.core.AnimationWrap.Loop;
	}
	
	
	public   void OnUpdate()
	{
		java.lang.String log = "";
		log += "Stats";
		log += ( "\nVisible: " + haxor.core.RenderStats.visible );
		log += ( "\nCulled: " + haxor.core.RenderStats.culled );
		log += ( "\nActive: " + haxor.core.RenderStats.get_total() );
		log += ( "\nRenderers: " + haxor.core.RenderStats.renderers );
		log += ( "\nTris: " + haxor.core.RenderStats.triangles );
		if (( this.player != null )) 
		{
			haxor.math.Quaternion r = this.player.get_localRotation();
			r = haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) )), 33.0);
			this.player.set_localRotation(r);
		}
		
		haxor.core.Console.Log(haxe.root.StringTools.replace(( ( log + " FPS: " ) + haxor.core.Time.m_fps ), "\n", " "), null);
	}
	
	
	public  haxe.root.Array<haxor.math.Vector4> pl;
	
	public   void OnRender()
	{
		{
			haxor.math.Color p_color = new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0.1) ));
			haxor.context.EngineContext.gizmo.DrawGrid(100.0, p_color);
		}
		
		if (( this.pl == null )) 
		{
			this.pl = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
			{
				int _g = 0;
				while (( _g < 500 ))
				{
					int i = _g++;
					haxor.math.Vector4 pt = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
					pt.Set3(new haxor.math.Vector3(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize().Scale(java.lang.Math.random()).Scale(25.0));
					pt.w = haxor.math.Random.Range(10.0, 10.0);
					this.pl.push(pt);
				}
				
			}
			
		}
		
		{
			int _g1 = 0;
			int _g2 = this.pl.length;
			while (( _g1 < _g2 ))
			{
				int i1 = _g1++;
				haxor.math.Vector3 __temp_stmt433 = null;
				{
					haxor.math.Vector4 _this = this.pl.__get(i1);
					__temp_stmt433 = new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
				}
				
				double __temp_stmt434 = this.pl.__get(i1).w;
				haxor.math.Color __temp_stmt435 = new haxor.math.Color(((java.lang.Object) (0.9) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (1) ));
				haxor.math.Color __temp_stmt437 = null;
				{
					haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
					__temp_stmt437 = _this1.m_c.__get(_this1.m_nc = ( (( _this1.m_nc + 1 )) % _this1.m_c.length ));
				}
				
				haxor.math.Color __temp_stmt436 = __temp_stmt437.Set(0, 0, 0, 0.5);
				haxor.graphics.Gizmo.Point(__temp_stmt433, __temp_stmt434, __temp_stmt436.SetRGB(__temp_stmt435), true, null);
				haxor.math.Vector3 __temp_stmt438 = null;
				{
					haxor.math.Vector4 _this2 = this.pl.__get(i1);
					__temp_stmt438 = new haxor.math.Vector3(((java.lang.Object) (_this2.x) ), ((java.lang.Object) (_this2.y) ), ((java.lang.Object) (_this2.z) ));
				}
				
				haxor.math.Vector3 __temp_stmt440 = null;
				{
					haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
					__temp_stmt440 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
				}
				
				haxor.math.Vector3 __temp_stmt439 = __temp_stmt440.Set(1, 1, 1);
				haxor.math.Color __temp_stmt441 = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (1) ));
				haxor.math.Color __temp_stmt443 = null;
				{
					haxor.context.DataContext _this4 = haxor.context.EngineContext.data;
					__temp_stmt443 = _this4.m_c.__get(_this4.m_nc = ( (( _this4.m_nc + 1 )) % _this4.m_c.length ));
				}
				
				haxor.math.Color __temp_stmt442 = __temp_stmt443.Set(0, 0, 0, 1.0);
				haxor.graphics.Gizmo.WireCube(__temp_stmt438, __temp_stmt439.Scale(0.5), __temp_stmt442.SetRGB(__temp_stmt441), null);
				haxor.math.Vector3 __temp_stmt444 = null;
				{
					haxor.math.Vector4 _this5 = this.pl.__get(i1);
					__temp_stmt444 = new haxor.math.Vector3(((java.lang.Object) (_this5.x) ), ((java.lang.Object) (_this5.y) ), ((java.lang.Object) (_this5.z) ));
				}
				
				haxor.math.Color __temp_stmt445 = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (1) ));
				haxor.math.Color __temp_stmt447 = null;
				{
					haxor.context.DataContext _this6 = haxor.context.EngineContext.data;
					__temp_stmt447 = _this6.m_c.__get(_this6.m_nc = ( (( _this6.m_nc + 1 )) % _this6.m_c.length ));
				}
				
				haxor.math.Color __temp_stmt446 = __temp_stmt447.Set(0, 0, 0, 1.0);
				haxor.graphics.Gizmo.WireSphere(__temp_stmt444, 1.0, __temp_stmt446.SetRGB(__temp_stmt445), null);
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef448 = true;
			switch (field.hashCode())
			{
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef448 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef448) 
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
			boolean __temp_executeDef449 = true;
			switch (field.hashCode())
			{
				case 3580:
				{
					if (field.equals("pl")) 
					{
						__temp_executeDef449 = false;
						this.pl = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef449 = false;
						this.cam = ((haxor.component.Camera) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef449 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef449 = false;
						this.orbit = ((haxor.component.CameraOrbit) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -985752863:
				{
					if (field.equals("player")) 
					{
						__temp_executeDef449 = false;
						this.player = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef449 = false;
						this.container = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef449 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef449) 
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
			boolean __temp_executeDef450 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef450 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef450 = false;
						return this.cam;
					}
					
					break;
				}
				
				
				case 3580:
				{
					if (field.equals("pl")) 
					{
						__temp_executeDef450 = false;
						return this.pl;
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef450 = false;
						return this.orbit;
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef450 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef450 = false;
						return this.container;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef450 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef450 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef450 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case -985752863:
				{
					if (field.equals("player")) 
					{
						__temp_executeDef450 = false;
						return this.player;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef450 = false;
						return this.queue;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef450) 
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
			boolean __temp_executeDef451 = true;
			switch (field.hashCode())
			{
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef451 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef451) 
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
			int __temp_hash453 = field.hashCode();
			boolean __temp_executeDef452 = true;
			switch (__temp_hash453)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash453 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef452 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef452 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef452 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef452) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("pl");
		baseArr.push("queue");
		baseArr.push("player");
		baseArr.push("mat");
		baseArr.push("container");
		baseArr.push("orbit");
		baseArr.push("cam");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


