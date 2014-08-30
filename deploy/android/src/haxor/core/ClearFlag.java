package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ClearFlag extends haxe.lang.HxObject
{
	static 
	{
		haxor.core.ClearFlag.None = 0;
		haxor.core.ClearFlag.Color = 1;
		haxor.core.ClearFlag.Depth = 2;
		haxor.core.ClearFlag.Skybox = 4;
		haxor.core.ClearFlag.ColorDepth = 3;
		haxor.core.ClearFlag.SkyboxDepth = 6;
	}
	public    ClearFlag(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ClearFlag()
	{
		haxor.core.ClearFlag.__hx_ctor_haxor_core_ClearFlag(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_ClearFlag(haxor.core.ClearFlag __temp_me151364)
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
		return new haxor.core.ClearFlag(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.ClearFlag();
	}
	
	
}


