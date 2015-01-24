package haxor.core;

/**
 * Interface that describes an object that updates in a fixed rate for physics simulation purpose.
 * @author Eduardo Pons
 */
interface IFixedUpdateable
{
	/**
	 * Update method.
	 */
	public function OnFixedUpdate():Void;	
	
}