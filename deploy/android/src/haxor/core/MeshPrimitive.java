package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshPrimitive extends haxe.lang.HxObject
{
	static 
	{
		haxor.core.MeshPrimitive.Points = 0;
		haxor.core.MeshPrimitive.Triangles = 4;
		haxor.core.MeshPrimitive.TriangleStrip = 5;
		haxor.core.MeshPrimitive.TriangleFan = 6;
		haxor.core.MeshPrimitive.Lines = 1;
		haxor.core.MeshPrimitive.LineLoop = 2;
		haxor.core.MeshPrimitive.LineStrip = 3;
	}
	public    MeshPrimitive(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MeshPrimitive()
	{
		haxor.core.MeshPrimitive.__hx_ctor_haxor_core_MeshPrimitive(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_MeshPrimitive(haxor.core.MeshPrimitive __temp_me255398)
	{
		{
		}
		
	}
	
	
	public static  int Points;
	
	public static  int Triangles;
	
	public static  int TriangleStrip;
	
	public static  int TriangleFan;
	
	public static  int Lines;
	
	public static  int LineLoop;
	
	public static  int LineStrip;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.MeshPrimitive(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.MeshPrimitive();
	}
	
	
}


