package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Application extends haxor.platform.android.AndroidApplication
{
	public    Application(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Application(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.core.Application.__hx_ctor_haxor_core_Application(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_core_Application(haxor.core.Application __temp_me151272, java.lang.String p_name)
	{
		haxor.platform.android.AndroidApplication.__hx_ctor_haxor_platform_android_AndroidApplication(__temp_me151272, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Application(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Application(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
}


