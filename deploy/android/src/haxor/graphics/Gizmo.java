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
	
	
	public static   void __hx_ctor_haxor_graphics_Gizmo(haxor.graphics.Gizmo __temp_me190)
	{
		{
		}
		
	}
	
	
	public static   void Grid(double p_area, haxor.math.Color p_color)
	{
		haxor.context.EngineContext.gizmo.DrawGrid(p_area, p_color);
	}
	
	
	public static   void Axis(haxor.math.Vector3 p_position, haxor.math.Vector3 p_size, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.context.EngineContext.gizmo.DrawAxis(p_position, p_size, p_color, p_transform);
	}
	
	
	public static   void Line(haxor.math.Vector3 p_from, haxor.math.Vector3 p_to, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.context.EngineContext.gizmo.DrawLine(p_from, p_to, p_color, p_transform);
	}
	
	
	public static   void Point(haxor.math.Vector3 p_position, java.lang.Object p_size, haxor.math.Color p_color, java.lang.Object p_smooth, haxor.math.Matrix4 p_transform)
	{
		boolean __temp_p_smooth188 = ( (( p_smooth == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_smooth)) );
		double __temp_p_size187 = ( (( p_size == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_size)) )) );
		haxor.context.EngineContext.gizmo.DrawPoint(p_position, __temp_p_size187, p_color, __temp_p_smooth188, p_transform);
	}
	
	
	public static   void WireSphere(haxor.math.Vector3 p_position, java.lang.Object p_radius, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		double __temp_p_radius189 = ( (( p_radius == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_radius)) )) );
		haxor.context.EngineContext.gizmo.DrawWireSphere(p_position, __temp_p_radius189, p_color, p_transform);
	}
	
	
	public static   void WireCube(haxor.math.Vector3 p_position, haxor.math.Vector3 p_size, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.context.EngineContext.gizmo.DrawWireCube(p_position, p_size, p_color, p_transform);
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


