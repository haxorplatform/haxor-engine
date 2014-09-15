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
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me255322, java.lang.String p_name)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me255322, p_name);
		__temp_me255322.queue = 3;
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
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		haxor.net.Web.LoadCollada("./character/medieval/animations/all_idle01.DAE", new haxe.root.Main_Load_98__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		haxor.net.Web.LoadTexture2D("./character/medieval/knight/DiffuseTexture.png", true, new haxe.root.Main_Load_108__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		haxor.net.Web.LoadCollada("./character/medieval/knight/asset.dae", new haxe.root.Main_Load_118__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		return false;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		this.orbit = haxor.component.CameraOrbit.Create(2.0, 45, 30);
		haxor.component.CameraOrbitInput ci = ((haxor.component.CameraOrbitInput) (this.orbit.m_entity.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.CameraOrbitInput.class) )) ))) );
		this.orbit.smooth = 5.0;
		ci.zoomSpeed = 0.1;
		this.cam = ((haxor.component.Camera) (this.orbit.m_entity.GetComponentInChildren(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.Camera.class) )) ))) );
		this.cam.background = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (null) ));
		{
			haxor.core.Entity _this = new haxor.core.Entity(haxe.lang.Runtime.toString("container"));
			this.container = _this.m_transform;
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
		haxor.io.file.ColladaFile cf = ((haxor.io.file.ColladaFile) (haxor.io.file.Asset.Get("model")) );
		{
			haxor.core.Entity _this1 = new haxor.core.Entity(haxe.lang.Runtime.toString("player"));
			this.player = _this1.m_transform;
		}
		
		haxor.component.Transform asset = null;
		{
			haxor.core.Entity _this2 = null;
			_this2 = ((haxor.core.Entity) (cf.get_asset()) );
			asset = _this2.m_transform;
		}
		
		asset.set_parent(this.player.m_entity.m_transform);
		asset.set_localScale(new haxor.math.Vector3(((java.lang.Object) (2.0) ), ((java.lang.Object) (2.0) ), ((java.lang.Object) (2.0) )));
		haxe.root.Array<haxor.component.MeshRenderer> mr = ((haxe.root.Array<haxor.component.MeshRenderer>) (((haxe.root.Array) (this.player.m_entity.GetComponentsInChildren(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.MeshRenderer.class) )) ))) )) );
		{
			int _g1 = 0;
			int _g = mr.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxe.Log.trace.__hx_invoke2_o(0.0, mr.__get(i).m_mesh.get_bounds().ToString(null), 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "Initialize"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (178) )) )})));
				mr.__get(i).set_material(this.mat);
			}
			
		}
		
	}
	
	
	public   void OnUpdate()
	{
		java.lang.String log = "";
		log += "Stats";
		log += ( "\nVisible: " + haxor.core.Stats.visible );
		log += ( "\nCulled: " + haxor.core.Stats.culled );
		log += ( "\nActive: " + haxor.core.Stats.get_total() );
		log += ( "\nRenderers: " + haxor.core.Stats.renderers );
		log += ( "\nTris: " + haxor.core.Stats.triangles );
		if (( this.player != null )) 
		{
			haxor.math.Quaternion r = this.player.get_localRotation();
			r.Multiply(haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) )), ( 20.0 * haxor.core.Time.m_delta )), null);
			this.player.set_localRotation(r);
		}
		
		haxor.core.Console.Log(haxe.root.StringTools.replace(( ( log + " FPS: " ) + haxor.core.Time.m_fps ), "\n", " "), null);
	}
	
	
	public   void OnRender()
	{
		haxor.graphics.GL.m_gl.Clear(256);
		{
			haxor.math.Color p_color = new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0.1) ));
			haxor.context.EngineContext.gizmo.DrawGrid(100.0, p_color);
		}
		
		haxor.context.EngineContext.gizmo.DrawAxis(50.0);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255706 = true;
			switch (field.hashCode())
			{
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef255706 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255706) 
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
			boolean __temp_executeDef255707 = true;
			switch (field.hashCode())
			{
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef255707 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef255707 = false;
						this.cam = ((haxor.component.Camera) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -985752863:
				{
					if (field.equals("player")) 
					{
						__temp_executeDef255707 = false;
						this.player = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef255707 = false;
						this.orbit = ((haxor.component.CameraOrbit) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef255707 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef255707 = false;
						this.container = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255707) 
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
			boolean __temp_executeDef255708 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef255708 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef255708 = false;
						return this.cam;
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef255708 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef255708 = false;
						return this.orbit;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef255708 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef255708 = false;
						return this.container;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef255708 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef255708 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef255708 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case -985752863:
				{
					if (field.equals("player")) 
					{
						__temp_executeDef255708 = false;
						return this.player;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255708) 
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
			boolean __temp_executeDef255709 = true;
			switch (field.hashCode())
			{
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef255709 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255709) 
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
			int __temp_hash255711 = field.hashCode();
			boolean __temp_executeDef255710 = true;
			switch (__temp_hash255711)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash255711 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef255710 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef255710 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef255710 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255710) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
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


