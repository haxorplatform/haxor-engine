package haxor.core;
import haxor.physics.Collider;

/**
 * Interface that describes an object that has trigger behaviour.
 * @author Eduardo Pons
 */
interface ITriggerable
{

	/**
	 * Callback called when the object entered a trigger.
	 * @param	c
	 */
	public function OnTriggerEnter(c:Collider):Void;
	
	/**
	 * Callback called when the object exited the trigger.
	 * @param	c
	 */
	public function OnTriggerExit(c:Collider):Void;
	
	/**
	 * Callback called when the object is inside the trigger.
	 * @param	c
	 */
	public function OnTriggerStay(c:Collider):Void;
	
	
}