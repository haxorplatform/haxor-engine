package haxor.graphics;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.context.GizmoContext;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Class that handles the drawing of gizmos.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Gizmo
{

	/**
	 * Draws a grid occupying the chosen area.
	 * @param	p_area
	 * @param	p_color
	 */
	static public inline function Grid(p_area:Float32, p_color:Color = null):Void 
	{ 
		EngineContext.gizmo.DrawGrid(p_area, p_color); 
	}
	
	/**
	 * Draws an outlined axis to show orientation.
	 * @param	p_area
	 */
	static public inline function Axis(p_position:Vector3,p_size : Vector3 = null,p_color : Color = null, p_transform : Matrix4 = null):Void 
	{ 		
		EngineContext.gizmo.DrawAxis(p_position,p_size,p_color,p_transform); 
	}
	
	/**
	 * Draws a line between 2 points.
	 * @param	p_position
	 * @param	p_size
	 * @param	p_color
	 * @param	p_transform
	 */
	static public inline function Line(p_from:Vector3,p_to : Vector3 = null,p_color : Color = null, p_transform : Matrix4 = null):Void 
	{ 		
		EngineContext.gizmo.DrawLine(p_from,p_to,p_color,p_transform); 
	}
	
	/**
	 * Draws a point in the specified position.
	 * @param	p_position
	 * @param	p_size
	 * @param	p_color
	 * @param	p_smooth
	 * @param	p_transform
	 */
	static public function Point(p_position:Vector3,p_size : Float = 1.0,p_color : Color = null,p_smooth:Bool=true, p_transform : Matrix4 = null):Void
	{		
		EngineContext.gizmo.DrawPoint(p_position,p_size,p_color,p_smooth, p_transform);
	}
	
	/**
	 * Draws an outlined sphere.
	 * @param	p_radius
	 * @param	p_color
	 * @param	p_transform
	 */
	static public function WireSphere(p_position:Vector3,p_radius : Float = 1.0,p_color : Color = null, p_transform : Matrix4 = null):Void
	{		
		EngineContext.gizmo.DrawWireSphere(p_position,p_radius,p_color, p_transform);
	}
	
	/**
	 * Draws an outlined cube.
	 * @param	p_position
	 * @param	p_size
	 * @param	p_color
	 * @param	p_transform
	 */
	static public function WireCube(p_position:Vector3,p_size : Vector3 = null,p_color : Color = null, p_transform : Matrix4 = null):Void
	{		
		EngineContext.gizmo.DrawWireCube(p_position,p_size,p_color, p_transform);
	}
	
	
}