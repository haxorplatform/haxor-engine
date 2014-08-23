package haxor.graphics;
import haxor.context.EngineContext;
import haxor.math.Color;

/**
 * Class that handles the drawing of gizmos.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Gizmo
{

	/**
	 * Draws a Gizmo occupying the chosen area.
	 * @param	p_area
	 * @param	p_color
	 */
	static public inline function Grid(p_area:Float, p_color:Color = null):Void { EngineContext.gizmo.DrawGrid(p_area, p_color); }
	
	
}