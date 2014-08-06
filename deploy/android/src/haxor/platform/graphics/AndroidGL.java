package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AndroidGL extends haxor.platform.graphics.GraphicContext
{
	public    AndroidGL(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    AndroidGL(haxor.core.BaseApplication p_application)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.platform.graphics.AndroidGL.__hx_ctor_haxor_platform_graphics_AndroidGL(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_AndroidGL(haxor.platform.graphics.AndroidGL __temp_me26108, haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GraphicContext.__hx_ctor_haxor_platform_graphics_GraphicContext(__temp_me26108, p_application);
		__temp_me26108.api = haxor.platform.graphics.GraphicAPI.OpenGLES;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.AndroidGL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.AndroidGL(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	public  android.opengl.GLSurfaceView c;
	
	public  int[] m_ids;
	
	public   boolean Initialize(haxor.platform.android.Entry p_entry, java.lang.Object p_version)
	{
		int __temp_p_version26107 = ( (( p_version == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_version)) )) );
		if (( p_entry == null )) 
		{
			haxor.core.Console.Log("Graphics> Invalid Entry Activity.", null);
			return false;
		}
		
		int cv = __temp_p_version26107;
		
		 c = new android.opengl.GLSurfaceView(p_entry.getApplication());
		 ;
		if (( this.c == null )) 
		{
			haxor.core.Console.Log("Graphics> Could not create GLSurfaceView.", null);
			return false;
		}
		
		int w = 0;
		int h = 0;
		
		c.setEGLContextClientVersion(cv);
		c.setRenderer(p_entry);		
		p_entry.setContentView(c);		
		
		android.view.Display display = p_entry.getWindowManager().getDefaultDisplay();
		
		android.util.DisplayMetrics metrics = new android.util.DisplayMetrics();
		display.getMetrics(metrics);

		w = metrics.widthPixels;
		h = metrics.heightPixels;
		
		;
		this.m_ids = new int[((int) (1) )];
		haxor.core.Console.Log(( ( ( ( ( ( "Graphics> Initialize Android GLES version[" + __temp_p_version26107 ) + "] Resolution[" ) + w ) + "," ) + h ) + "]" ), 1);
		return true;
	}
	
	
	public   void OnPause()
	{
		c.onPause();
	}
	
	
	public   void OnResume()
	{
		c.onResume();
	}
	
	
	@Override public   void CheckExtensions()
	{
		if (( this.c == null )) 
		{
			return ;
		}
		
		haxor.core.Console.Log("Graphics> Available Extensions.", 1);
	}
	
	
	@Override public   void Clear(double p_r, double p_g, double p_b, double p_a, double p_depth)
	{
		android.opengl.GLES20.glClearDepthf(((float) (p_depth) ));
		android.opengl.GLES20.glClearColor(((float) (p_r) ), ((float) (p_g) ), ((float) (p_b) ), ((float) (p_a) ));
		android.opengl.GLES20.glClear(((int) (( android.opengl.GLES20.GL_COLOR_BUFFER_BIT | android.opengl.GLES20.GL_DEPTH_BUFFER_BIT )) ));
	}
	
	
	@Override public   int CreateBuffer()
	{
		this.m_ids[0] = -1;
		android.opengl.GLES20.glGenBuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
		haxor.core.Console.Log(( "GLES20> " + this.m_ids.length ), null);
		return this.m_ids[0];
	}
	
	
	@Override public   void DeleteBuffer(int p_id)
	{
		this.m_ids[0] = p_id;
		android.opengl.GLES20.glDeleteBuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26221 = true;
			switch (field.hashCode())
			{
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef26221 = false;
						this.m_ids = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef26221 = false;
						this.c = ((android.opengl.GLSurfaceView) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26221) 
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
			boolean __temp_executeDef26222 = true;
			switch (field.hashCode())
			{
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteBuffer"))) );
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef26222 = false;
						return this.c;
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateBuffer"))) );
					}
					
					break;
				}
				
				
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef26222 = false;
						return this.m_ids;
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPause"))) );
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef26222 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnResume"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26222) 
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
			int __temp_hash26224 = field.hashCode();
			boolean __temp_executeDef26223 = true;
			switch (__temp_hash26224)
			{
				case -1081856533:case 1213974652:case 65193517:case -1602602212:
				{
					if (( (( ( __temp_hash26224 == -1081856533 ) && field.equals("DeleteBuffer") )) || ( (( ( __temp_hash26224 == 1213974652 ) && field.equals("CreateBuffer") )) || ( (( ( __temp_hash26224 == 65193517 ) && field.equals("Clear") )) || field.equals("CheckExtensions") ) ) )) 
					{
						__temp_executeDef26223 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef26223 = false;
						return this.Initialize(((haxor.platform.android.Entry) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef26223 = false;
						this.OnResume();
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef26223 = false;
						this.OnPause();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26223) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_ids");
		baseArr.push("c");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


