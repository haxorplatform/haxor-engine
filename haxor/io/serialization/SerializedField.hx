package haxor.io.serialization;

/**
 * Class that describes a field found during instance parsing.
 */
class SerializedField
{
	public var target : Dynamic;
	public var meta   : Dynamic;
	public var name   : String;
	public var type   : String;
	public var value  : Dynamic;	
	public function new() { }
}