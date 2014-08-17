package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AndroidApplication extends haxor.core.BaseApplication
{
	public    AndroidApplication(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    AndroidApplication()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.AndroidApplication.__hx_ctor_haxor_platform_android_AndroidApplication(this);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_AndroidApplication(haxor.platform.android.AndroidApplication __temp_me27867)
	{
		haxor.core.BaseApplication.__hx_ctor_haxor_core_BaseApplication(__temp_me27867);
		__temp_me27867.m_platform = haxor.core.Platform.Android;
		__temp_me27867.m_screen_width = 0.0;
		__temp_me27867.m_screen_height = 0.0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.AndroidApplication(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.AndroidApplication();
	}
	
	
	public  haxor.platform.android.Entry m_entry;
	
	public  double m_screen_width;
	
	public  double m_screen_height;
	
	@Override public   double GetContainerWidth()
	{
		return this.m_screen_width;
	}
	
	
	@Override public   double GetContainerHeight()
	{
		return this.m_screen_height;
	}
	
	
	@Override public   void OnFocus()
	{
		haxor.platform.graphics.GL.m_gl.OnResume();
	}
	
	
	@Override public   void OnUnfocus()
	{
		haxor.platform.graphics.GL.m_gl.OnPause();
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27970 = true;
			switch (field.hashCode())
			{
				case 1535364104:
				{
					if (field.equals("m_screen_height")) 
					{
						__temp_executeDef27970 = false;
						this.m_screen_height = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1587516101:
				{
					if (field.equals("m_screen_width")) 
					{
						__temp_executeDef27970 = false;
						this.m_screen_width = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27970) 
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
			boolean __temp_executeDef27971 = true;
			switch (field.hashCode())
			{
				case 1535364104:
				{
					if (field.equals("m_screen_height")) 
					{
						__temp_executeDef27971 = false;
						this.m_screen_height = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 770090528:
				{
					if (field.equals("m_entry")) 
					{
						__temp_executeDef27971 = false;
						this.m_entry = ((haxor.platform.android.Entry) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1587516101:
				{
					if (field.equals("m_screen_width")) 
					{
						__temp_executeDef27971 = false;
						this.m_screen_width = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27971) 
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
			boolean __temp_executeDef27972 = true;
			switch (field.hashCode())
			{
				case -1244160288:
				{
					if (field.equals("OnUnfocus")) 
					{
						__temp_executeDef27972 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUnfocus"))) );
					}
					
					break;
				}
				
				
				case 770090528:
				{
					if (field.equals("m_entry")) 
					{
						__temp_executeDef27972 = false;
						return this.m_entry;
					}
					
					break;
				}
				
				
				case 315605529:
				{
					if (field.equals("OnFocus")) 
					{
						__temp_executeDef27972 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFocus"))) );
					}
					
					break;
				}
				
				
				case 1587516101:
				{
					if (field.equals("m_screen_width")) 
					{
						__temp_executeDef27972 = false;
						return this.m_screen_width;
					}
					
					break;
				}
				
				
				case 1461662450:
				{
					if (field.equals("GetContainerHeight")) 
					{
						__temp_executeDef27972 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetContainerHeight"))) );
					}
					
					break;
				}
				
				
				case 1535364104:
				{
					if (field.equals("m_screen_height")) 
					{
						__temp_executeDef27972 = false;
						return this.m_screen_height;
					}
					
					break;
				}
				
				
				case 199665307:
				{
					if (field.equals("GetContainerWidth")) 
					{
						__temp_executeDef27972 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetContainerWidth"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27972) 
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
			boolean __temp_executeDef27973 = true;
			switch (field.hashCode())
			{
				case 1535364104:
				{
					if (field.equals("m_screen_height")) 
					{
						__temp_executeDef27973 = false;
						return this.m_screen_height;
					}
					
					break;
				}
				
				
				case 1587516101:
				{
					if (field.equals("m_screen_width")) 
					{
						__temp_executeDef27973 = false;
						return this.m_screen_width;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27973) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_screen_height");
		baseArr.push("m_screen_width");
		baseArr.push("m_entry");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


