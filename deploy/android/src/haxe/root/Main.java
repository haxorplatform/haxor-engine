package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main extends haxor.core.Application implements haxor.core.IRenderable, haxor.core.IUpdateable
{
	public static void main(String[] args)
	{
		main();
	}
	public    Main(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Main()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxe.root.Main.__hx_ctor__Main(this);
	}
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me42338)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me42338);
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
		return new haxe.root.Main();
	}
	
	
	public  haxor.graphics.mesh.Mesh mesh;
	
	public  haxor.graphics.material.Material mat;
	
	public  java.lang.String ss;
	
	@Override public   boolean Load()
	{
		haxor.net.Web.root = "https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";
		return true;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		double s = 0.8;
		haxor.io.FloatArray vl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) ( - (s) ) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (s) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (s) ), ((java.lang.Object) (s) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (s) ), ((java.lang.Object) (0.5) )}));
		haxor.io.FloatArray uvl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) )}));
		haxor.io.FloatArray cl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) )}));
		haxor.io.UInt16Array il = haxor.io.UInt16Array.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0, 1, 2, 0, 2, 3}));
		haxor.graphics.mesh.Mesh m = this.mesh = new haxor.graphics.mesh.Mesh();
		m.Set("vertex", vl, 3);
		m.Set("uv0", uvl, 2);
		m.Set("color", cl, 4);
		m.set_topology(il);
		if (( this.ss == null )) 
		{
			this.ss = "\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec2 uv0;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tuniform float Size;\r\n\t\t\t\tuniform float Time;\r\n\t\t\t\tvarying vec4 v_color;\t\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tv_uv0.x = vertex.x / (Size);\r\n\t\t\t\t\tv_uv0.y = -vertex.y / (Size);\r\n\t\t\t\t\tv_uv0.x = (v_uv0.x + 1.0) * 0.5;\r\n\t\t\t\t\tv_uv0.y = (v_uv0.y + 1.0) * 0.5;\r\n\t\t\t\t\t//v_uv0 = uv0;\r\n\t\t\t\t\tvec4 v = vec4(vertex,1.0);\r\n\t\t\t\t\tv.x = v.x*sin(Time);\r\n\t\t\t\t\tgl_Position = vec4(v);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\r\n\t\t\t\tuniform sampler2D Texture;\r\n\t\t\t\tuniform vec4 Tint[2];\r\n\t\t\t\tvarying vec4 v_color;\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tvec4 c = texture2D(Texture, v_uv0);\r\n\t\t\t\t\t//gl_FragColor = vec4(v_uv0.x,v_uv0.y,0.0,1.0);\r\n\t\t\t\t\tgl_FragColor = c;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t";
		}
		
		int h = 2048;
		haxor.graphics.texture.Texture2D tex = new haxor.graphics.texture.Texture2D(((int) (1) ), ((int) (h) ), ((haxor.graphics.PixelFormat) (haxor.graphics.PixelFormat.Float4) ));
		haxe.root.Array<haxor.math.Color> cl1 = new haxe.root.Array<haxor.math.Color>(new haxor.math.Color[]{haxor.math.Color.get_red(), haxor.math.Color.get_green(), haxor.math.Color.get_blue(), haxor.math.Color.get_yellow()});
		{
			int _g = 0;
			while (( _g < h ))
			{
				int i = _g++;
				double r = ( ((double) (i) ) / (( h - 1 )) );
				tex.m_data.SetPixel(0, i, haxor.math.Color.Sample(cl1, r));
			}
			
		}
		
		tex.set_minFilter(haxor.graphics.TextureFilter.Nearest);
		tex.set_magFilter(haxor.graphics.TextureFilter.Nearest);
		tex.Upload(100, null);
		haxor.graphics.material.Shader shd = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(this.ss));
		this.mat = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("DebugMaterial"));
		this.mat.blend = true;
		this.mat.cull = 0;
		this.mat.SetBlending(770, 771);
		this.mat.set_shader(shd);
		this.mat.SetFloat("Size", s);
		this.mat.SetTexture("Texture", tex);
		this.mat.SetFloat4Array("Tint", new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.3) )}));
	}
	
	
	public   void OnUpdate()
	{
		{
		}
		
	}
	
	
	public   void OnRender()
	{
		haxor.platform.graphics.GL.m_gl.Viewport(0, 0, ((int) (haxor.graphics.Screen.m_width) ), ((int) (haxor.graphics.Screen.m_height) ));
		haxor.platform.graphics.GL.m_gl.ClearColor(0.7, 0.3, 1.0, 1.0);
		haxor.platform.graphics.GL.m_gl.ClearDepth(1.0);
		haxor.platform.graphics.GL.m_gl.Clear(16640);
		if (( this.mesh == null )) 
		{
			return ;
		}
		
		if (( this.mat == null )) 
		{
			return ;
		}
		
		this.mat.SetFloat("Time", haxor.core.Time.m_elapsed);
		haxor.graphics.Graphics.RenderMesh(this.mesh, this.mat);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef42473 = true;
			switch (field.hashCode())
			{
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef42473 = false;
						this.ss = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef42473 = false;
						this.mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef42473 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42473) 
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
			boolean __temp_executeDef42474 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef42474 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef42474 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef42474 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef42474 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef42474 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef42474 = false;
						return this.ss;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef42474 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42474) 
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
			int __temp_hash42476 = field.hashCode();
			boolean __temp_executeDef42475 = true;
			switch (__temp_hash42476)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash42476 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef42475 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef42475 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef42475 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42475) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("ss");
		baseArr.push("mat");
		baseArr.push("mesh");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


