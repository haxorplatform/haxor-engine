package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Mesh2D extends haxor.graphics.mesh.MeshLayout<haxor.math.Vector2, haxor.math.Vector3, haxor.math.Vector2, haxor.math.Vector2, haxor.math.Vector3, haxor.math.Vector3>
{
	public    Mesh2D(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Mesh2D(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.Mesh2D.__hx_ctor_haxor_graphics_mesh_Mesh2D(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_Mesh2D(haxor.graphics.mesh.Mesh2D __temp_me160508, java.lang.String p_name)
	{
		haxor.graphics.mesh.MeshLayout.__hx_ctor_haxor_graphics_mesh_MeshLayout(__temp_me160508, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.Mesh2D(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.Mesh2D(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
}


