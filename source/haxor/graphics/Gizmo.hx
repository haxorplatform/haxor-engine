package haxor.graphics;
import haxor.context.EngineContext;
import haxor.math.Color;
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
	 * Draws the world axis.
	 * @param	p_area
	 */
	static public inline function Axis(p_area:Float32):Void 
	{ 		
		EngineContext.gizmo.DrawAxis(p_area); 
	}
	
	
}