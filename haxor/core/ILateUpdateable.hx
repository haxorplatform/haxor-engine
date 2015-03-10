package haxor.core;

/**
 * Interface that describes an object that is updated after all nodes executed their main 'Update' callback.
 * @author Eduardo Pons
 */
interface ILateUpdateable
{

	/**
	 * Update callback.
	 */
	public function OnLateUpdate():Void;
	
	
}