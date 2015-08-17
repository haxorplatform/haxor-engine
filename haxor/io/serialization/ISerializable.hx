package haxor.io.serialization;
import haxor.io.serialization.Formatter.FormatterField;
import haxor.io.serialization.Formatter.FormatterNode;

/**
 * Interface that describes a class capable of handling special cases of serialization of variables.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
interface ISerializable 
{
  
	/**
	 * Callback called when the formatter is processing this instance's fields.
	 * This callback can ovewrite the default behaviour or return an empty string to delegate the serialization to the formatter.
	 * @param	p_id
	 * @param	p_fields
	 * @return
	 */
	public function OnSerializeField(p_field : SerializedField,p_fmt : Formatter):String;
		
	/**
	 * Callback called when the deserialization is processing the input data and finds a field and its value.
	 * If the class successfully process the contents it will return true, otherwise false is returned and the formatter tries to cope with the situation.
	 * @param	p_id
	 * @param	p_fields
	 * @return
	 */
	public function OnDeserializeField(p_field : SerializedField,p_fmt : Formatter):Bool;
	
}