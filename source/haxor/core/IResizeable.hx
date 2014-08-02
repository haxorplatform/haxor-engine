package haxor.core;

/**
 * Interface that describes elements that handles resize callbacks.
 * @author Eduardo Pons
 */
interface IResizeable
{

	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 */
	public function OnResize(p_width:Float,p_height:Float):Void;
	
	
}