package haxor.io.serialization;


/**
 * Parsing step node.
 */
class SerializedData
{
	public var target 	: Dynamic;
	public var type 	: String;
	public var fields 	: Array<SerializedField>;
	public var children : Array<SerializedData>;	
	public function new(p_target:Dynamic) 
	{ 
		target 	 = p_target;
		type   	 = target == null ? "root" : Type.getClassName(Type.getClass(target));		
		fields   = []; 
		children = [];		
	}	
}