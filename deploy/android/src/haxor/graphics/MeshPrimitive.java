package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshPrimitive extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.MeshPrimitive.Points = 0;
		haxor.graphics.MeshPrimitive.Triangles = 4;
		haxor.graphics.MeshPrimitive.TriangleStrip = 5;
		haxor.graphics.MeshPrimitive.TriangleFan = 6;
		haxor.graphics.MeshPrimitive.Lines = 1;
		haxor.graphics.MeshPrimitive.LineLoop = 2;
		haxor.graphics.MeshPrimitive.LineStrip = 3;
	}
	public    MeshPrimitive(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MeshPrimitive()
	{
		haxor.graphics.MeshPrimitive.__hx_ctor_haxor_graphics_MeshPrimitive(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_MeshPrimitive(haxor.graphics.MeshPrimitive __temp_me33819)
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
		return new haxor.graphics.MeshPrimitive(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.MeshPrimitive();
	}
	
	
}


