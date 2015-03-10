package haxor.component;
import haxor.core.Entity;

/**
 * Class that describes a simple component which holds any kind of data.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class DataComponent extends Component
{

	/**
	 * Creates a new DataComponent.
	 */
	public function new() { super(); data = new Map<String,Dynamic>(); }
	
	/**
	 * Reference of container of this instance data.
	 */
	public var data : Dynamic;
	
}