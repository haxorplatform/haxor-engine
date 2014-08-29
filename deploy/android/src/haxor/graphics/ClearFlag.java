package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ClearFlag extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.ClearFlag.None = 0;
		haxor.graphics.ClearFlag.Color = 1;
		haxor.graphics.ClearFlag.Depth = 2;
		haxor.graphics.ClearFlag.Skybox = 4;
		haxor.graphics.ClearFlag.ColorDepth = 3;
		haxor.graphics.ClearFlag.SkyboxDepth = 6;
	}
	public    ClearFlag(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ClearFlag()
	{
		haxor.graphics.ClearFlag.__hx_ctor_haxor_graphics_ClearFlag(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_ClearFlag(haxor.graphics.ClearFlag __temp_me80624)
	{
		{
		}
		
	}
	
	
	public static  int None;
	
	public static  int Color;
	
	public static  int Depth;
	
	public static  int Skybox;
	
	public static  int ColorDepth;
	
	public static  int SkyboxDepth;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.ClearFlag(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.ClearFlag();
	}
	
	
}


