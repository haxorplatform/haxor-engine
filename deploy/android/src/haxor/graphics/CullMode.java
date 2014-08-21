package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CullMode extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.CullMode.None = 0;
		haxor.graphics.CullMode.Front = 1;
		haxor.graphics.CullMode.Back = 2;
	}
	public    CullMode(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    CullMode()
	{
		haxor.graphics.CullMode.__hx_ctor_haxor_graphics_CullMode(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_CullMode(haxor.graphics.CullMode __temp_me54086)
	{
		{
		}
		
	}
	
	
	public static  int None;
	
	public static  int Front;
	
	public static  int Back;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.CullMode(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.CullMode();
	}
	
	
}


