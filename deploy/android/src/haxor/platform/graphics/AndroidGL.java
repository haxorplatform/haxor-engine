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
	
	
	public static   void __hx_ctor_haxor_platform_graphics_AndroidGL(haxor.platform.graphics.AndroidGL __temp_me1838, haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GraphicContext.__hx_ctor_haxor_platform_graphics_GraphicContext(__temp_me1838, p_application);
		__temp_me1838.api = haxor.platform.graphics.GraphicAPI.OpenGLES;
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
	
	public   boolean Initialize(haxor.platform.android.Entry p_entry, java.lang.Object p_version)
	{
		int __temp_p_version1835 = ( (( p_version == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_version)) )) );
		if (( p_entry == null )) 
		{
			haxor.core.Console.Log("Graphics> Invalid Entry Activity.", null);
			return false;
		}
		
		int cv = __temp_p_version1835;
		
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
		haxor.core.Console.Log(( ( ( ( ( ( "Graphics> Initialize Android GLES version[" + __temp_p_version1835 ) + "] Resolution[" ) + w ) + "," ) + h ) + "]" ), 1);
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
	
	
	@Override public   void Resize()
	{
		{
		}
		
	}
	
	
	@Override public   void Clear(double p_r, double p_g, double p_b, java.lang.Object p_a, java.lang.Object p_depth)
	{
		double __temp_p_depth1837 = ( (( p_depth == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_depth)) )) );
		double __temp_p_a1836 = ( (( p_a == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		android.opengl.GLES20.glClearDepthf(((float) (__temp_p_depth1837) ));
		android.opengl.GLES20.glClearColor(((float) (p_r) ), ((float) (p_g) ), ((float) (p_b) ), ((float) (__temp_p_a1836) ));
		android.opengl.GLES20.glClear(((int) (( android.opengl.GLES20.GL_COLOR_BUFFER_BIT | android.opengl.GLES20.GL_DEPTH_BUFFER_BIT )) ));
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1923 = true;
			switch (field.hashCode())
			{
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef1923 = false;
						this.c = ((android.opengl.GLSurfaceView) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1923) 
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
			boolean __temp_executeDef1924 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef1924 = false;
						return this.c;
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPause"))) );
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef1924 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnResume"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1924) 
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
			int __temp_hash1926 = field.hashCode();
			boolean __temp_executeDef1925 = true;
			switch (__temp_hash1926)
			{
				case 65193517:case -1850570540:case -1602602212:
				{
					if (( (( ( __temp_hash1926 == 65193517 ) && field.equals("Clear") )) || ( (( ( __temp_hash1926 == -1850570540 ) && field.equals("Resize") )) || field.equals("CheckExtensions") ) )) 
					{
						__temp_executeDef1925 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef1925 = false;
						return this.Initialize(((haxor.platform.android.Entry) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef1925 = false;
						this.OnResume();
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef1925 = false;
						this.OnPause();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1925) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("c");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


