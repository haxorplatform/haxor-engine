package haxor.core;
import haxor.platform.Types.Float32;

/**
 * Interface that describes elements that handles resize callbacks.
 * @author Eduardo Pons
 */
interface IResizeable
{

	/**
	 * Resize callback.
	 * @param	p_width
	 * @param	p_height
	 */
	public function OnResize(p_width:Float32,p_height:Float32):Void;
	
	
}