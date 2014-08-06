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
	
	
	public static   void __hx_ctor_haxor_platform_android_AndroidApplication(haxor.platform.android.AndroidApplication __temp_me26077)
	{
		haxor.core.BaseApplication.__hx_ctor_haxor_core_BaseApplication(__temp_me26077);
		__temp_me26077.m_platform = haxor.core.Platform.Android;
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
	
	@Override public   void OnFocus()
	{
		haxor.platform.graphics.GL.m_gl.OnResume();
	}
	
	
	@Override public   void OnUnfocus()
	{
		haxor.platform.graphics.GL.m_gl.OnPause();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26147 = true;
			switch (field.hashCode())
			{
				case 770090528:
				{
					if (field.equals("m_entry")) 
					{
						__temp_executeDef26147 = false;
						this.m_entry = ((haxor.platform.android.Entry) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26147) 
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
			boolean __temp_executeDef26148 = true;
			switch (field.hashCode())
			{
				case -1244160288:
				{
					if (field.equals("OnUnfocus")) 
					{
						__temp_executeDef26148 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUnfocus"))) );
					}
					
					break;
				}
				
				
				case 770090528:
				{
					if (field.equals("m_entry")) 
					{
						__temp_executeDef26148 = false;
						return this.m_entry;
					}
					
					break;
				}
				
				
				case 315605529:
				{
					if (field.equals("OnFocus")) 
					{
						__temp_executeDef26148 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFocus"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26148) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_entry");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


