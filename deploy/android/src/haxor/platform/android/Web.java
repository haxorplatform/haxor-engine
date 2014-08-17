package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Web extends haxe.lang.HxObject
{
	static 
	{
		haxor.platform.android.Web.root = "";
	}
	public    Web(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Web()
	{
		haxor.platform.android.Web.__hx_ctor_haxor_platform_android_Web(this);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_Web(haxor.platform.android.Web __temp_me27915)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String root;
	
	public static   void Load(java.lang.String p_url, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadStringTask ld = new haxor.platform.android.LoadStringTask(haxe.lang.Runtime.toString(p_url), haxe.lang.Runtime.toString("GET"), haxe.lang.Runtime.toString(""), ((haxe.lang.Function) (p_callback) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.Web(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.Web();
	}
	
	
}


