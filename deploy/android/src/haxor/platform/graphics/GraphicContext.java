package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GraphicContext extends haxe.lang.HxObject
{
	public    GraphicContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GraphicContext(haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GraphicContext.__hx_ctor_haxor_platform_graphics_GraphicContext(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_GraphicContext(haxor.platform.graphics.GraphicContext __temp_me26106, haxor.core.BaseApplication p_application)
	{
		__temp_me26106.m_api = haxor.platform.graphics.GraphicAPI.None;
		__temp_me26106.m_application = p_application;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.GraphicContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.GraphicContext(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	public  haxor.platform.graphics.GraphicAPI api;
	
	public   haxor.platform.graphics.GraphicAPI get_api()
	{
		return this.m_api;
	}
	
	
	public  haxor.platform.graphics.GraphicAPI m_api;
	
	public  haxor.core.BaseApplication m_application;
	
	public   void CheckExtensions()
	{
		{
		}
		
	}
	
	
	public   void Focus()
	{
		{
		}
		
	}
	
	
	public   void Flush()
	{
		{
		}
		
	}
	
	
	public   int CreateBuffer()
	{
		return haxor.platform.graphics.GL.NULL_ID;
	}
	
	
	public   void DeleteBuffer(int p_id)
	{
		{
		}
		
	}
	
	
	public   void Destroy()
	{
		{
		}
		
	}
	
	
	public   void Resize()
	{
		{
		}
		
	}
	
	
	public   void Clear(double p_r, double p_g, double p_b, double p_a, double p_depth)
	{
		{
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26218 = true;
			switch (field.hashCode())
			{
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef26218 = false;
						this.m_application = ((haxor.core.BaseApplication) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 96794:
				{
					if (field.equals("api")) 
					{
						__temp_executeDef26218 = false;
						this.api = ((haxor.platform.graphics.GraphicAPI) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103590728:
				{
					if (field.equals("m_api")) 
					{
						__temp_executeDef26218 = false;
						this.m_api = ((haxor.platform.graphics.GraphicAPI) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26218) 
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
			boolean __temp_executeDef26219 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 96794:
				{
					if (field.equals("api")) 
					{
						__temp_executeDef26219 = false;
						return this.api;
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case -74801743:
				{
					if (field.equals("get_api")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_api"))) );
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 103590728:
				{
					if (field.equals("m_api")) 
					{
						__temp_executeDef26219 = false;
						return this.m_api;
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteBuffer"))) );
					}
					
					break;
				}
				
				
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef26219 = false;
						return this.m_application;
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateBuffer"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 67980004:
				{
					if (field.equals("Flush")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Flush"))) );
					}
					
					break;
				}
				
				
				case 68052152:
				{
					if (field.equals("Focus")) 
					{
						__temp_executeDef26219 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Focus"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26219) 
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
			boolean __temp_executeDef26220 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef26220 = false;
						this.Clear(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -74801743:
				{
					if (field.equals("get_api")) 
					{
						__temp_executeDef26220 = false;
						return this.get_api();
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef26220 = false;
						this.Resize();
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef26220 = false;
						this.CheckExtensions();
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef26220 = false;
						this.Destroy();
					}
					
					break;
				}
				
				
				case 68052152:
				{
					if (field.equals("Focus")) 
					{
						__temp_executeDef26220 = false;
						this.Focus();
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef26220 = false;
						this.DeleteBuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 67980004:
				{
					if (field.equals("Flush")) 
					{
						__temp_executeDef26220 = false;
						this.Flush();
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef26220 = false;
						return this.CreateBuffer();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26220) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_application");
		baseArr.push("m_api");
		baseArr.push("api");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


