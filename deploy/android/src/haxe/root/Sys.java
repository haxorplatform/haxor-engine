package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Sys extends haxe.lang.HxObject
{
	public    Sys(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Sys()
	{
		haxe.root.Sys.__hx_ctor__Sys(this);
	}
	
	
	public static   void __hx_ctor__Sys(haxe.root.Sys __temp_me42342)
	{
		{
		}
		
	}
	
	
	public static   void sleep(double seconds)
	{
		try 
		{
			java.lang.Thread.sleep(((long) (( seconds * 1000 )) ));
		}
		catch (java.lang.Throwable __temp_catchallException42483)
		{
			java.lang.Object __temp_catchall42484 = __temp_catchallException42483;
			if (( __temp_catchall42484 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall42484 = ((haxe.lang.HaxeException) (__temp_catchallException42483) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall42484;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static   double time()
	{
		return ( ((double) (java.lang.System.currentTimeMillis()) ) / 1000 );
	}
	
	
	public static   haxe.io.Output stdout()
	{
		return new haxe.java.io.NativeOutput(((java.io.OutputStream) (java.lang.System.out) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Sys(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Sys();
	}
	
	
}


