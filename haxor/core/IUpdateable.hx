package haxor.core;

/**
 * Interface that describes objects that can be updated during the main loop.
 * @author Eduardo Pons
 */
interface IUpdateable
{

	/**
	 * Update callback.
	 */
	public function OnUpdate():Void;
	
	
}