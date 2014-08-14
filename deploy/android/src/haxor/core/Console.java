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
	
	
	public static   void __hx_ctor_haxor_core_Console(haxor.core.Console __temp_me4454)
	{
		{
		}
		
	}
	
	
	public static  haxe.ds.StringMap<java.lang.Object> m_benchmarks;
	
	public static   void Initialize()
	{
		haxor.core.Console.m_benchmarks = new haxe.ds.StringMap<java.lang.Object>();
	}
	
	
	public static  int verbose;
	
	public static   void Breakpoint()
	{
		{
		}
		
	}
	
	
	public static   void Log(java.lang.String p_msg, java.lang.Object p_level)
	{
		int __temp_p_level4453 = ( (( p_level == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_level)) )) );
		if (( haxor.core.Console.verbose >= __temp_p_level4453 )) 
		{
			haxe.root.Sys.stdout().writeString(( p_msg + "\n" ));
			haxe.root.Sys.stdout().flush();
			
			android.util.Log.v("TRACE", p_msg);			
			;
		}
		
	}
	
	
	public static   void LogImage(java.lang.String p_url, int p_height)
	{
		{
		}
		
	}
	
	
	public static   void LogWarning(java.lang.String p_msg, haxe.root.Array p_obj)
	{
		haxor.core.Console.Log(( "[W] " + p_msg ), null);
	}
	
	
	public static   void LogError(java.lang.String p_msg, haxe.root.Array p_obj)
	{
		haxor.core.Console.Log(( "[E] " + p_msg ), null);
	}
	
	
	public static   void ClearStyle()
	{
		{
		}
		
	}
	
	
	public static   void Clear()
	{
		{
		}
		
	}
	
	
	public static   void TimeStart(java.lang.String p_id)
	{
		if (haxor.core.Console.m_benchmarks.exists(p_id)) 
		{
			return ;
		}
		
		{
			double value = haxe.Timer.stamp();
			haxor.core.Console.m_benchmarks.set(p_id, value);
		}
		
	}
	
	
	public static   void TimeEnd(java.lang.String p_id)
	{
		if ( ! (haxor.core.Console.m_benchmarks.exists(p_id)) ) 
		{
			return ;
		}
		
		double t = ((double) (haxe.lang.Runtime.toDouble(haxor.core.Console.m_benchmarks.get(p_id))) );
		haxor.core.Console.m_benchmarks.remove(p_id);
		haxor.core.Console.Log(( ( ( p_id + ": " ) + ((int) (java.lang.Math.floor(( t * 1000.0 ))) ) ) + "ms" ), null);
	}
	
	
	public static   void StackTrace()
	{
		haxor.core.Console.Log(java.util.Arrays.toString(((java.lang.Object[]) (java.lang.Thread.currentThread().getStackTrace()) )), 0);
	}
	
	
	public static   void SetStyle(java.lang.String p_size, java.lang.String p_color, java.lang.String p_background, java.lang.String p_font)
	{
		if (( p_font == null )) 
		{
			p_font = "\'Lucida Console\', Monaco, monospace";
		}
		
		if (( p_background == null )) 
		{
			p_background = "rgba(255,255,255,0)";
		}
		
		if (( p_color == null )) 
		{
			p_color = "rgba(0,0,0,1)";
		}
		
		if (( p_size == null )) 
		{
			p_size = "12px";
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


