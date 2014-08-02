package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Console extends haxe.lang.HxObject
{
	static 
	{
		haxor.core.Console.verbose = 0;
	}
	public    Console(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Console()
	{
		haxor.core.Console.__hx_ctor_haxor_core_Console(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_Console(haxor.core.Console __temp_me1826)
	{
		{
		}
		
	}
	
	
	public static  int verbose;
	
	public static   void Log(java.lang.String p_msg, java.lang.Object p_level)
	{
		int __temp_p_level1825 = ( (( p_level == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_level)) )) );
		if (( haxor.core.Console.verbose >= __temp_p_level1825 )) 
		{
			haxe.root.Sys.stdout().writeString(( p_msg + "\n" ));
			haxe.root.Sys.stdout().flush();
			
			android.util.Log.v("TRACE", p_msg);			
			;
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Console(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Console();
	}
	
	
}


