package haxor.io.serialization;
import haxe.Json;
import haxe.rtti.Meta;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.platform.Types.Float32;
import haxor.core.Resource;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * Helper type definition for the confuse Meta table data.
 */
typedef MetaTable = Dynamic<Dynamic<Array<Dynamic>>>;

/**
 * Helper class to handle the dynamic object generated after encoding.
 */
extern class FormatterData
{
	public inline function GetName():String			{ return Reflect.getProperty(this, "$name"); }
	public inline function GetFields():Array<String>{ return Reflect.fields(this); }
	public inline function GetIndex():Int 			{ return Std.parseInt(Reflect.hasField(this, "$index") ? (Reflect.getProperty(this, "$index")+"") : "-1"); }
	public inline function GetType():Class<Dynamic> { var dn : String = this.GetTypeName(); return dn == "$Dynamic" ? null : Type.resolveClass(dn); }
	public inline function GetTypeName():String		{ return Reflect.hasField(this, "$type") ? Reflect.getProperty(this, "$type") : "$Dynamic"; }
	public inline function GetInstance():Dynamic    { var c : Class<Dynamic> = this.GetType(); return (c == null) ? { } : Type.createInstance(c, []); } 
}

/**
 * Class that parses class instances and returns their string formatted version.
 * TODO: Allow encoding of primitive types e.g. .Encode(Vector3.one)
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Formatter
{	
	static private var NULL    : String = String.fromCharCode(5);
	static private var UNKNOWN : String = String.fromCharCode(6);

	private var m_class_types      : Array<Dynamic>;	
	private var m_class_names      : Array<String>;
		
	/**
	 * CTOR
	 */
	public function new() 
	{
		m_class_types = [];
		m_class_names = [];
		RegisterClass(Int,"Int");		
		RegisterClass(Float32);
		RegisterClass(Bool,"Bool");	 	
		RegisterClass(String);		
	}
		
	/**
	 * Serializes the object into string.
	 * @param	p_data
	 * @param	p_use_tabs
	 * @return
	 */
	public function Serialize(p_data:Dynamic, p_use_tabs:Bool = false):String
	{
		var d : Dynamic = ToObject(p_data);
		return Json.stringify(d, function(k:Dynamic, v:Dynamic):Dynamic { return v; }, p_use_tabs ? " " : null);
	}
	
	/**
	 * PArses the text data and returns a typed instance of the serialized object.
	 * @param	p_data
	 * @return
	 */
	public function Deserialize(p_data:String) : Dynamic
	{
		var d : Dynamic = Json.parse(p_data);				
		return FromObject(d);
	}
	
	/**
	 * Generates a type-less object with the data information and extra fields for decoding.
	 * @param	p_data
	 * @return
	 */
	public function ToObject(p_data:Dynamic):Dynamic
	{
		return EncodeStep("",null, p_data,true,-1);
	}
	
	/**
	 * Decodes the 'Formatter' formatted object with all the encoded data.
	 * @param	p_data
	 * @return
	 */
	public function FromObject(p_data:Dynamic):Dynamic
	{
		if (p_data == null) return null;
		return DecodeStep(null,p_data);
	}
	
	/**
	 * Parses the object and generates a new instance with all data in it.
	 * @param	p_name
	 * @param	p_type
	 * @param	p_data
	 * @return
	 */
	private function DecodeStep(p_parent:Dynamic,p_data:Dynamic):Dynamic
	{
		var d 				 : FormatterData = cast p_data;
		
		if (Std.is(d, Array)) 
		{			
			return DecodeArrayStep(p_parent,cast d);		
		}
		
		var data_index  	 : Int     			= d.GetIndex();//Std.parseInt(Reflect.hasField(d, "$index") ? (Reflect.getProperty(d, "$index")+"") : "-1");				
		var data_type_name   : String  			= d.GetTypeName();// Reflect.hasField(d, "$type") ? Reflect.getProperty(d, "$type") : "$Dynamic";				
		var data_name   	 : String  			= d.GetName();//Reflect.getProperty(d, "$name");		
		var data_type		 : Class<Dynamic> 	= d.GetType();// data_type_name == "$Dynamic" ? null : Type.resolveClass(data_type_name);
		var data_fields 	 : Array<String> 	= d.GetFields();// Reflect.fields(p_data);
		
		var res  : Dynamic = d.GetInstance();// (data_type == null) ? { } : Type.createInstance(data_type, []);
		
		var isrl : ISerializable = Std.is(res, ISerializable) ? (cast res) : null;
		
		for (i in 0...data_fields.length)
		{
			var field_name  : String  = data_fields[i];
			if (field_name.charAt(0) == "$") continue;
			var field_value : Dynamic = Reflect.getProperty(d, field_name);
			
			if (isrl != null) 
			{ 
				var has_parsed : Bool = isrl.OnDeserializeField(this,field_name, field_value);				
				if (has_parsed) {  continue; }
			}
			
			var field_input : Dynamic = null;
			
			if (Std.is(field_value, String))
			{
				field_input = FromEncodedString(cast field_value);
			}
			else
			{
				field_input = DecodeStep(res, field_value);
			}			
			Reflect.setProperty(res, field_name, field_input);
		}		
		return res;
	}
		
	/**
	 * Decodes an array filled with encoded objects.
	 * @param	p_name
	 * @param	p_data
	 * @return
	 */
	private function DecodeArrayStep(p_parent:Dynamic,p_data:Array<Dynamic>):Array<Dynamic>
	{
		var dl 	: Array<Dynamic> = p_data;
		var res : Array<Dynamic> = [];
		for (i in 0...dl.length)
		{
			var data_value : Dynamic = dl[i];
			var data_input : Dynamic = null;
			
			if (Std.is(data_value, String))
			{
				data_input = FromEncodedString(cast data_value);
			}
			else
			{
				data_input = DecodeStep(p_parent,data_value);
			}
			res.push(data_input);
		}
		return res;
	}
	
	/**
	 * Callback called when a field is going to be decoded and set to the target object.
	 * @param	p_target
	 * @param	p_field_name
	 * @param	p_field_value
	 * @return
	 */
	private function OnDecodeField(p_container:Dynamic,p_field_name:String,p_field_value:Dynamic):Bool
	{
		var field_name  : String  		= p_field_name;
		if (field_name.charAt(0) == "$") return false;		
		var field_value : Dynamic 		= p_field_value;
		var isrl 		: ISerializable = Std.is(p_container, ISerializable) ? (cast p_container) : null;
		
		if (isrl != null) { if (isrl.OnDeserializeField(this,field_name, field_value)) { return false; } }
		
		var field_input : Dynamic = null;
		
		if (Std.is(field_value, String))
		{
			field_input = FromEncodedString(cast field_value);
		}
		else
		{
			field_input = DecodeStep(p_container, field_value);
		}	
		
		if (Std.is(p_container, Array))
		{
			var l : Array<Dynamic> = cast p_container;
			l.push(field_input);
			return true;
		}
		Reflect.setProperty(p_container, field_name, field_input);
		return true;
	}
	
	/**
	 * Process 1 object.
	 * @param	p_name
	 * @param	p_data
	 * @param	p_auto_parese
	 * @return
	 */
	private function EncodeStep(p_name:String,p_parent:Dynamic, p_target:Dynamic, p_auto_parese:Bool=true,p_index:Int=-1):Dynamic
	{
		var n			      : String		   = p_name;
		var t 				  : Dynamic        = p_target;
		var target_type 	  : Class<Dynamic> = Type.getClass(t);
		var target_type_name  : String 		   = target_type == null ? "$Dynamic" : Type.getClassName(target_type);
				
		if (target_type_name == "Array") { return EncodeArray(p_name,p_parent, cast p_target, p_auto_parese); }
		
		var res : Dynamic = {};
		
		Reflect.setField(res, "$type", target_type_name);
		Reflect.setField(res, "$name", n);
		Reflect.setField(res, "$index", p_index);
		
		var class_list : Array<Class<Dynamic>> = GetClassPath(t);
		
		if (class_list.length <= 0) class_list.push(null);
		
		for (i in 0...class_list.length)
		{
			var c 			: Class<Dynamic>    = class_list[i];
			var type_metas  : MetaTable 		= c==null ? null : Meta.getFields(c);			
			var type_fields : Array<String>     = type_metas==null ? Reflect.fields(t) : Reflect.fields(type_metas);
			
			for (j in 0...type_fields.length)
			{
				var field_name : String  = type_fields[j];
				var var_metas  : Dynamic = type_metas==null ? null : Reflect.getProperty(type_metas, field_name);				
				
				if(var_metas != null)
				if (!Reflect.hasField(var_metas, "serialize")) continue;
				
				var metas_args 		: Array<Dynamic> = var_metas==null ? [true] : (var_metas.serialize == null ? [true] : var_metas.serialize);
				var auto_parse		: Bool 			 = metas_args[0] == null ? true : (metas_args[0]);
								
				var field_value 	: Dynamic 		 = Reflect.getProperty(t, field_name);
				
				//var field_type 		: Class<Dynamic> = (field_value == null) ? null : Type.getClass(field_value);
				//var field_type_name : String 		 = (field_type == null) ? "$Dynamic" : Type.getClassName(field_type);				
				//if (Std.is(field_value, Bool)) field_type_name = "Bool"; else
				//if (Std.is(field_value, Int))  field_type_name = "Int";
				
				var field_input : Dynamic = null;
				field_input = OnEncodeField(p_parent, field_name, field_value, auto_parse, -1);				
				Reflect.setField(res, field_name, field_input);
			}			
		}
		return res;		
	}
	
	/**
	 * Encodes data when they are arrays.
	 * @param	p_name
	 * @param	p_data
	 * @param	p_auto_parse
	 * @return
	 */
	private function EncodeArray(p_name:String,p_parent:Dynamic, p_target:Array<Dynamic>, p_auto_parse:Bool):Array<Dynamic>
	{			
		var t    : Array<Dynamic>  = p_target;
		var res  : Array<Dynamic>  = [];
		var ap   : Bool = p_name == "" ? false : p_auto_parse;
		for (i in 0...t.length)
		{
			var field_name	 : String  = p_name;
			var field_value  : Dynamic = t[i];
			var field_input  : Dynamic = null;			
			field_input = OnEncodeField(p_parent, field_name, field_value, ap, i);			
			res.push(field_input);
		}
		return res;		
	}
	
	/**
	 * Callback called when a field is being encoded.
	 * @param	p_parent
	 * @param	p_field_name
	 * @param	p_field_value
	 * @param	p_auto_parse
	 * @param	p_index
	 * @return
	 */
	private function OnEncodeField(p_parent:Dynamic, p_field_name:String, p_field_value:Dynamic,p_auto_parse:Bool,p_index:Int):Dynamic
	{
		var isrl 		 : ISerializable = Std.is(p_parent, ISerializable) ? (cast p_parent) : null;
		var field_name	 : String  		 = p_field_name;
		var field_value  : Dynamic 		 = p_field_value;
		var field_input  : Dynamic 		 = null;
		
		if (field_value == null)
		{
			field_input = NULL;
		}
		else
		{
			if (isrl != null) 
			{ 
				field_input = isrl.OnSerializeField(this,field_name, field_value); 				
			}
			
			if (field_input == null) field_input = p_auto_parse ? ToString(field_value) : null;
			
			if (field_input == null)
			{
				field_input = EncodeStep(field_name,p_parent,field_value,p_auto_parse,p_index);
			}
			else
			{				
				var c : String = ValueToCode(field_value);
				field_input = c + field_input;
			}
		}
		return field_input;
	}
	
	/**
	 * Utility method to serialize common classes.
	 * @param	p_v
	 * @return
	 */		
	public function ToString(p_v:Dynamic):String
	{
		if (p_v == null) return "";
		if (Std.is(p_v, Int)) 	 	 { var v:Int		= cast p_v; return v + ""; }
		if (Std.is(p_v, Float32))	 { var v:Float32	= cast p_v; return v + ""; }
		if (Std.is(p_v, Bool))	 	 { var v:Bool		= cast p_v; return v + ""; }
		if (Std.is(p_v, String)) 	 { var v:String		= cast p_v; return v; }				
		return null;
	}
	
	/**
	 * Parses the string and returns the correct type.
	 * @param	p_v
	 * @return
	 */
	public function FromString(p_v:String,p_t:String):Dynamic
	{		
		if (p_t == null) return null;
		if (p_v == null) return null;
		if (p_t == "Int") 	  				return Std.parseInt(p_v);
		if (p_t == "Float")  				return Std.parseFloat(p_v);
		if (p_t == "Bool")    				return p_v != "false";
		if (p_t == "String")  				return p_v;		
		return null;
	}
	
	/**
	 * Returns the parsed string according to its value.
	 * @param	p_v
	 * @return
	 */
	public function FromEncodedString(p_v:String):Dynamic
	{
		var cs : String = p_v.substr(0, 2);
		var sv : String = p_v.substr(2);
		var tn : String = CodeToTypeName(cs);
		return FromString(sv, tn);
	}
	
	/**
	 * Returns the list of classes from base to the current type.
	 * @param	p_var
	 * @return
	 */
	private function GetClassPath(p_var : Dynamic) : Array<Class<Dynamic>>
	{
		var res : Array<Class<Dynamic>> = [];
		var c : Class<Dynamic> = Type.getClass(p_var);		
		while (c != null) {	res.unshift(c); c = Type.getSuperClass(c); }		
		return res;	
	}
	
	/**
	 * Converts an int to 2 byte string code.
	 * @param	p_code
	 * @return
	 */
	private function ToStringCode(p_code:Int):String
	{
		var n0:Int = (p_code % 230) + 14;
		var n1:Int = Std.int(p_code / 230) + 14;
		var b0 : String = String.fromCharCode(n0);
		var b1 : String = String.fromCharCode(n1);
		return b1 + b0;
	}
	
	/**
	 * Converts from 2 byte string to code.
	 * @param	p_code
	 * @return
	 */
	private function FromStringCode(p_code:String):Int
	{
		var b1 : Int = p_code.charCodeAt(0)-14;
		var b0 : Int = p_code.charCodeAt(1)-14;		
		return b0 + Std.int(b1*230);
	}
	
	/**
	 * Register a class to the type table
	 * @param	p_type
	 */
	private function RegisterClass(p_type:Dynamic,p_name:String=""):Void
	{
		m_class_types.push(p_type);
		var n : String = p_name == "" ? Type.getClassName(p_type) : p_name;
		m_class_names.push(n);
	}
	
	/**
	 * Tests the value and returns its type code string.
	 * @param	p_value
	 * @return
	 */
	private function ValueToCode(p_value:Dynamic):String
	{
		if (p_value == null) return NULL;
		for (i in 0...m_class_types.length) if (Std.is(p_value, m_class_types[i])) return ToStringCode(i);
		return UNKNOWN;
	}
	
	/**
	 * Returns the stored type name indexed by the string code.
	 * @param	p_code
	 * @return
	 */
	private function CodeToTypeName(p_code:String):String
	{
		if (p_code == UNKNOWN) return null;
		if (p_code == NULL)    return null;
		var c : Int = FromStringCode(p_code);		
		if (c >= m_class_names.length) return null;
		return m_class_names[c];
	}
	
		
}