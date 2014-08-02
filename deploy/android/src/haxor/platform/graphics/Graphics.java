package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Graphics extends haxor.platform.graphics.AndroidGL
{
	public    Graphics(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Graphics(haxor.core.BaseApplication p_application)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.platform.graphics.Graphics.__hx_ctor_haxor_platform_graphics_Graphics(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_Graphics(haxor.platform.graphics.Graphics __temp_me1839, haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.AndroidGL.__hx_ctor_haxor_platform_graphics_AndroidGL(__temp_me1839, p_application);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.Graphics(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.Graphics(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
}


