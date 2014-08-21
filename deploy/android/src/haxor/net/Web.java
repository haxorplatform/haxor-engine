package haxor.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Web extends haxe.lang.HxObject
{
	static 
	{
		haxor.net.Web.root = "";
	}
	public    Web(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Web()
	{
		haxor.net.Web.__hx_ctor_haxor_net_Web(this);
	}
	
	
	public static   void __hx_ctor_haxor_net_Web(haxor.net.Web __temp_me54130)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String root;
	
	public static   void Load(java.lang.String p_url, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadDataTask<java.lang.String> ld = new haxor.platform.android.LoadDataTask<java.lang.String>(haxe.lang.Runtime.toString(p_url), haxe.lang.Runtime.toBool(false), ((haxe.lang.Function) (p_callback) ));
	}
	
	
	public static   void LoadBitmap(java.lang.String p_url, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadBitmap ld = new haxor.platform.android.LoadBitmap(haxe.lang.Runtime.toString(p_url), ((haxe.lang.Function) (p_callback) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.net.Web(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.net.Web();
	}
	
	
}


