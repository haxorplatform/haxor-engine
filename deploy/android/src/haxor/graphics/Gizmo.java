package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Gizmo extends haxe.lang.HxObject
{
	public    Gizmo(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Gizmo()
	{
		haxor.graphics.Gizmo.__hx_ctor_haxor_graphics_Gizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_Gizmo(haxor.graphics.Gizmo __temp_me151368)
	{
		{
		}
		
	}
	
	
	public static   void Grid(double p_area, haxor.math.Color p_color)
	{
		haxor.context.EngineContext.gizmo.DrawGrid(p_area, p_color);
	}
	
	
	public static   void Axis(double p_area)
	{
		haxor.context.EngineContext.gizmo.DrawAxis(p_area);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.Gizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.Gizmo();
	}
	
	
}


