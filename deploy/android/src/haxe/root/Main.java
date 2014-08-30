package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main extends haxor.core.Application implements haxor.core.IRenderable, haxor.core.IUpdateable
{
	public static void main(String[] args)
	{
		Sys._args = args;
		main();
	}
	public    Main(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Main(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxe.root.Main.__hx_ctor__Main(this, p_name);
	}
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me151273, java.lang.String p_name)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me151273, p_name);
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
	
	
	public  haxor.graphics.mesh.Mesh mesh;
	
	public  haxor.component.Camera cam;
	
	public  haxor.component.CameraOrbit orbit;
	
	public  haxor.component.MeshRenderer mr;
	
	public  haxor.component.Transform container;
	
	public  haxor.graphics.material.Material mat;
	
	public  java.lang.String ss;
	
	public  haxor.graphics.texture.Texture2D tex;
	
	public  haxor.graphics.texture.Bitmap bmp;
	
	@Override public   boolean Load()
	{
		haxe.root.Array<haxe.root.Main> _g = new haxe.root.Array<haxe.root.Main>(new haxe.root.Main[]{this});
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		haxor.net.Web.LoadTexture2D("./texture/misc/metal.jpg", true, new haxe.root.Main_Load_97__Fun(((haxe.root.Array<haxe.root.Main>) (_g) )));
		return false;
	}
	
	
	@Override public   void Initialize()
	{
		haxe.root.Array<haxe.root.Main> _g = new haxe.root.Array<haxe.root.Main>(new haxe.root.Main[]{this});
		haxor.core.Console.Log("Initialize!", null);
		this.orbit = haxor.component.CameraOrbit.Create(3.0, 45, 45);
		this.cam = ((haxor.component.Camera) (this.orbit.m_entity.GetComponentInChildren(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.Camera.class) )) ))) );
		this.cam.background = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (null) ));
		haxor.graphics.texture.Texture2D tex = haxor.graphics.texture.Texture2D.get_green();
		tex = ((haxor.graphics.texture.Texture2D) (haxor.io.file.Asset.Get("texture")) );
		{
			haxor.core.Entity _this = new haxor.core.Entity(haxe.lang.Runtime.toString("container"));
			this.container = _this.m_transform;
		}
		
		haxe.root.Array<java.lang.Object> l = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (2) )});
		haxe.root.Array<java.lang.Object> px = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) )});
		haxe.root.Array<java.lang.Object> py = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) )});
		haxe.root.Array<java.lang.Object> pz = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) )});
		{
			haxor.graphics.texture.Texture p_texture = ((haxor.graphics.texture.Texture) (haxor.io.file.Asset.Get("texture")) );
			boolean p_ztest = true;
			boolean p_zwrite = true;
			boolean p_double_sided = false;
			haxor.graphics.material.Material m = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("Transparent"));
			if (p_double_sided) 
			{
				m.cull = 0;
			}
			
			m.SetBlending(770, 771);
			m.set_shader(( (( p_texture == null )) ? (( (( haxor.graphics.material.Shader.m_flat_shader == null )) ? (haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source))) : (haxor.graphics.material.Shader.m_flat_shader) )) : (( (( haxor.graphics.material.Shader.m_flat_texture_shader == null )) ? (haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_texture_source))) : (haxor.graphics.material.Shader.m_flat_texture_shader) )) ));
			m.queue = 2000;
			m.ztest = p_ztest;
			m.zwrite = p_zwrite;
			m.blend = true;
			if (( p_texture != null )) 
			{
				m.SetTexture("DiffuseTexture", p_texture);
			}
			
			this.mat = m;
		}
		
		this.mat.set_name("T");
		this.mat.SetTexture("Tex0", haxor.graphics.texture.Texture2D.get_red());
		this.mat.blend = true;
		haxor.thread.Activity.Iterate(0, 200, new haxe.root.Main_Initialize_193__Fun(((haxe.root.Array<java.lang.Object>) (px) ), ((haxe.root.Array<java.lang.Object>) (l) ), ((haxe.root.Array<haxe.root.Main>) (_g) ), ((haxe.root.Array<java.lang.Object>) (pz) ), ((haxe.root.Array<java.lang.Object>) (py) )), 50, null, null);
	}
	
	
	public   void OnUpdate()
	{
		if (( this.orbit != null )) 
		{
			this.orbit.angle.x += ( haxor.core.Time.m_delta * 30.0 );
		}
		
		if (haxor.input.Joystick.available) 
		{
			if (( haxor.input.Input.get_joystick().length > 0 )) 
			{
				haxe.Log.trace.__hx_invoke2_o(0.0, haxor.input.Input.get_joystick().__get(0).analogLeft.ToString(null), 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (233) )) )})));
			}
			
		}
		
		if (haxor.input.Input.Down(haxor.input.KeyCode.Mouse0)) 
		{
			haxe.Log.trace.__hx_invoke2_o(0.0, "left", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (237) )) )})));
		}
		
		if (haxor.input.Input.Down(haxor.input.KeyCode.Mouse1)) 
		{
			haxe.Log.trace.__hx_invoke2_o(0.0, "middle", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (238) )) )})));
		}
		
		if (haxor.input.Input.Down(haxor.input.KeyCode.Mouse2)) 
		{
			haxe.Log.trace.__hx_invoke2_o(0.0, "right", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (239) )) )})));
		}
		
		if (haxor.input.Input.Down(haxor.input.KeyCode.A)) 
		{
			haxe.Log.trace.__hx_invoke2_o(0.0, "A", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (240) )) )})));
		}
		
		if (haxor.input.Input.Down(haxor.input.KeyCode.ControlKey)) 
		{
			haxe.Log.trace.__hx_invoke2_o(0.0, "Left Control", 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (241) )) )})));
		}
		
		double __temp_stmt151668 = 0.0;
		{
			double p_a = haxor.input.Input.wheel;
			__temp_stmt151668 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt151668 > 0 )) 
		{
			haxe.Log.trace.__hx_invoke2_o(haxor.input.Input.wheel, haxe.lang.Runtime.undefined, 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "OnUpdate"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (243) )) )})));
		}
		
		java.lang.String log = "Touches\n";
		{
			int _g1 = 0;
			int _g = haxor.input.Input.get_touches().length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				log += ( haxor.input.Input.get_touches().__get(i).ToString() + "\n" );
			}
			
		}
		
		if (( haxor.input.Input.get_touches().length > 0 )) 
		{
			haxor.core.Console.Log(log, null);
		}
		
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
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151669 = true;
			switch (field.hashCode())
			{
				case 97669:
				{
					if (field.equals("bmp")) 
					{
						__temp_executeDef151669 = false;
						this.bmp = ((haxor.graphics.texture.Bitmap) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef151669 = false;
						this.mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 114727:
				{
					if (field.equals("tex")) 
					{
						__temp_executeDef151669 = false;
						this.tex = ((haxor.graphics.texture.Texture2D) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef151669 = false;
						this.cam = ((haxor.component.Camera) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef151669 = false;
						this.ss = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef151669 = false;
						this.orbit = ((haxor.component.CameraOrbit) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef151669 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3493:
				{
					if (field.equals("mr")) 
					{
						__temp_executeDef151669 = false;
						this.mr = ((haxor.component.MeshRenderer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef151669 = false;
						this.container = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151669) 
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
			boolean __temp_executeDef151670 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef151670 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef151670 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef151670 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case 98255:
				{
					if (field.equals("cam")) 
					{
						__temp_executeDef151670 = false;
						return this.cam;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef151670 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 106004554:
				{
					if (field.equals("orbit")) 
					{
						__temp_executeDef151670 = false;
						return this.orbit;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef151670 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 3493:
				{
					if (field.equals("mr")) 
					{
						__temp_executeDef151670 = false;
						return this.mr;
					}
					
					break;
				}
				
				
				case 97669:
				{
					if (field.equals("bmp")) 
					{
						__temp_executeDef151670 = false;
						return this.bmp;
					}
					
					break;
				}
				
				
				case -410956671:
				{
					if (field.equals("container")) 
					{
						__temp_executeDef151670 = false;
						return this.container;
					}
					
					break;
				}
				
				
				case 114727:
				{
					if (field.equals("tex")) 
					{
						__temp_executeDef151670 = false;
						return this.tex;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef151670 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef151670 = false;
						return this.ss;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151670) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			int __temp_hash151672 = field.hashCode();
			boolean __temp_executeDef151671 = true;
			switch (__temp_hash151672)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash151672 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef151671 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef151671 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef151671 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151671) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("bmp");
		baseArr.push("tex");
		baseArr.push("ss");
		baseArr.push("mat");
		baseArr.push("container");
		baseArr.push("mr");
		baseArr.push("orbit");
		baseArr.push("cam");
		baseArr.push("mesh");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


