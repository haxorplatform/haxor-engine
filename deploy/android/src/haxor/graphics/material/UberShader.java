package haxor.graphics.material;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class UberShader extends haxor.graphics.material.Shader
{
	public    UberShader(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    UberShader(java.lang.String p_source)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.material.UberShader.__hx_ctor_haxor_graphics_material_UberShader(this, p_source);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_material_UberShader(haxor.graphics.material.UberShader __temp_me21757, java.lang.String p_source)
	{
		haxor.graphics.material.Shader.__hx_ctor_haxor_graphics_material_Shader(__temp_me21757, p_source);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.material.UberShader(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.material.UberShader(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
}


