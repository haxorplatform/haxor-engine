package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Mesh4 extends haxor.graphics.mesh.MeshLayout<haxor.math.Vector3, haxor.math.Vector3, haxor.math.Vector4, haxor.math.Vector4, haxor.math.Vector3, haxor.math.Vector3>
{
	public    Mesh4(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Mesh4(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.Mesh4.__hx_ctor_haxor_graphics_mesh_Mesh4(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_Mesh4(haxor.graphics.mesh.Mesh4 __temp_me255458, java.lang.String p_name)
	{
		haxor.graphics.mesh.MeshLayout.__hx_ctor_haxor_graphics_mesh_MeshLayout(__temp_me255458, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.Mesh4(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.Mesh4(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
}


