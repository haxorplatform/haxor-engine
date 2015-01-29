package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CullMode extends haxe.lang.HxObject
{
	static 
	{
		haxor.core.CullMode.None = 0;
		haxor.core.CullMode.Front = 1;
		haxor.core.CullMode.Back = 2;
	}
	public    CullMode(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    CullMode()
	{
		haxor.core.CullMode.__hx_ctor_haxor_core_CullMode(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_CullMode(haxor.core.CullMode __temp_me168)
	{
		{
		}
		
	}
	
	
	public static  int None;
	
	public static  int Front;
	
	public static  int Back;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.CullMode(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.CullMode();
	}
	
	
}


