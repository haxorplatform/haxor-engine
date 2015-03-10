package haxor.core;

/**
 * Interface that describes elements that can be disposed.
 * @author Eduardo Pons
 */
interface IDisposable
{

	/**
	 * Callback called when the object is destroyed.
	 */
	public function OnDestroy():Void;
	
	
}