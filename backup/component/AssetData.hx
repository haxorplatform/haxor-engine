package haxor.component;
import haxor.core.Entity;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AssetData extends Component implements Dynamic
{

	public function new(e : Entity) { super(e);	content = { }; }
	
	public var content : Dynamic;
	
}