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
 * Base class for formatting the serialization of classes in haxor.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class DeprecFormatter
{
	/**
	 * Creates a new formatter.
	 * @param	p_target
	 */
	public function new() 
	{
		
	}

	/**
	 * Generates the serialized version of this object in string format.
	 * @return
	 */
	public function Serialize(p_target:Dynamic):String 
	{			
		var n : SerializedData = SerializeStep(null, p_target);
		return OnSerialize(n);
	}
	
	/**
	 * Parses the object and returns the formatter root structure.
	 * @param	p_target
	 * @return
	 */
	public function GetSerializedData(p_target:Dynamic):SerializedData { return SerializeStep(null, p_target); }
	
	/**
	 * Parse step.
	 * @param	p_node
	 * @param	p_target
	 */
	private function SerializeStep(p_parent:SerializedData, p_target:Dynamic):SerializedData
	{
		var t : Dynamic 			= p_target;		
		var type : Class<Dynamic>   = Type.getClass(t);
		var n : SerializedData 		= new SerializedData(p_target);
		if(p_parent!=null) p_parent.children.push(n);
		
		var types  : Array<Class<Dynamic>> = GetClassPath(t);		
		
		for (i in 0...types.length)
		{
			var c : Class<Dynamic> = types[i];
			var type_metas  : Dynamic<Dynamic<Array<Dynamic>>> = Meta.getFields(c);			
			var type_fields : Array<String> = Reflect.fields(type_metas);
			
			for (j in 0...type_fields.length)
			{
				var field_name : String = type_fields[j];
				var var_metas : Dynamic = Reflect.getProperty(type_metas, field_name);				
				if (!Reflect.hasField(var_metas, "serialize")) continue;
				var field_value : Dynamic 		= Reflect.getProperty(t, field_name);
				if (field_value == null) continue;
				var field_type : Class<Dynamic> = Type.getClass(field_value);
				var field_type_name : String 	= Type.getClassName(field_type);
				
				var ff : SerializedField = cast { };
				ff.target = t;
				ff.meta   = var_metas;
				ff.name   = field_name;
				ff.type   = Std.is(field_value, Bool) ? "Bool" : (Std.is(field_value, Int) ? "Int" : (field_type_name));				
				ff.value  = field_value;				
				
				n.fields.push(ff);
			}
		}
		
		var ts : ISerializable = Std.is(t, ISerializable) ? (cast t) : null;		
		for (i in 0...n.fields.length)
		{
			var ff : SerializedField = n.fields[i];
			var s : String = null;
			
			if (Std.is(ff.value, Resource)) ff.type = "$GUID";
			
			//if (ts != null) { s = ts.OnSerializeField(ff,this); }
			if (s == null)  { s = OnField(ff); }
			if (s != null) ff.value = s;
			else
			{
				if (Std.is(ff.value, Array))
				{
					var l : Array<Dynamic> 			= cast ff.value;
					
					
					var nl : Array<SerializedData> 	= [];
					for (j in 0...l.length)
					{	
						nl.push(SerializeStep(null, l[j]));
					}
					ff.type  = "$NodeArray";
					ff.value = nl;
					//*/
				}
				else
				{	
					ff.type  = "$Node";
					ff.value = SerializeStep(null, ff.value);
				}				
			}
		}	
		return n;
	}
		
	/**
	 * Receives the data in string format and returns a new instance of 'type' filled with the desired data.
	 * @param	p_data
	 * @param	p_type
	 * @return
	 */
	public function Deserialize(p_data:String) : Dynamic { return null; }
	
	/**
	 * Parses the field and applies its value to the target.
	 * @param	f
	 * @param	t
	 */
	public function DeserializeField(p_field:SerializedField, p_target:Dynamic):Dynamic
	{
		var d 	: Dynamic = null;
		var nl 	: Array<SerializedData>;
		switch(p_field.type)
		{
			case "$Node": 		d = DeserializeData(p_field.value);			
			case "$NodeArray":  
			{
				d 	= [];
				nl 	= p_field.value; 
				for (j in 0...nl.length) d.push(DeserializeData(nl[j]));
			}
			default:				
				d 	= DeprecFormatter.FromString(p_field.value, p_field.type);
		}				
		Reflect.setProperty(p_target, p_field.name, d);
		return d;
	}
	
	/**
	 * Process the node and follow up the deserialization.
	 * @param	n
	 * @return
	 */
	public function DeserializeData(p_data : SerializedData):Dynamic
	{
		var c 		: Class<Dynamic> 	= Type.resolveClass(p_data.type);
		var res 	: Dynamic 			= null;		
		
		res = Type.createInstance(c, []);				
		for (i in 0...p_data.fields.length)
		{
			var f : SerializedField = cast p_data.fields[i];
			var has_parsed : Bool = false;
			if (Std.is(res, ISerializable))
			{
				var isrl : ISerializable = cast res;
				//has_parsed = isrl.OnDeserializeField(f,this);
			}						
			if(!has_parsed) DeserializeField(f, res);
		}						
		return res;
	}
	
	/**
	 * Searches for a given field using its name as query.
	 * @param	p_field
	 * @param	p_name
	 * @return
	 */
	public function GetField(p_node:SerializedData, p_name:String):SerializedField
	{
		return p_node.fields.filter(function(f:SerializedField):Bool { return f.name == p_name; } )[0];
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
	 * Virtual method to be overriden and process the attributes marked with (a)serialize metadata.
	 * @param	p_type_name
	 * @param	p_name
	 * @param	p_value
	 * @return
	 */
	private function OnField(p_field : SerializedField):String { return ToString(p_field.value); }
	
	/**
	 * Callback called at the end of parsing.
	 * The argument specifies the root node of parsing hierarchy.
	 * @param	p_root
	 * @return
	 */
	private function OnSerialize(p_root:SerializedData):String { return ""; }
	
	/**
	 * Utility method to serialize common classes.
	 * @param	p_v
	 * @return
	 */		
	static public function ToString(p_v:Dynamic):String
	{
		if (p_v == null) return "";
		if (Std.is(p_v, Int)) 	 	 { var v:Int		= cast p_v; return v + ""; }
		if (Std.is(p_v, Float32))	 { var v:Float32	= cast p_v; return v + ""; }
		if (Std.is(p_v, Bool))	 	 { var v:Bool		= cast p_v; return v + ""; }
		if (Std.is(p_v, String)) 	 { var v:String		= cast p_v; return v; }		
		if (Std.is(p_v, Vector2)) 	 { var v:Vector2 	= cast p_v; return v.x + "," + v.y; }
		if (Std.is(p_v, Vector3)) 	 { var v:Vector3 	= cast p_v; return v.x + "," + v.y + "," + v.z; }
		if (Std.is(p_v, Vector4)) 	 { var v:Vector4 	= cast p_v; return v.x + "," + v.y + "," + v.z + "," + v.w; }
		if (Std.is(p_v, AABB2)) 	 { var v:AABB2 		= cast p_v; return v.xMin + "," + v.xMax + "," + v.yMin + "," + v.yMax; }
		if (Std.is(p_v, AABB3)) 	 { var v:AABB3 		= cast p_v; return v.xMin + "," + v.xMax + "," + v.yMin + "," + v.yMax+","+v.zMin+","+v.zMax; }		
		if (Std.is(p_v, Color)) 	 { var v:Color	 	= cast p_v; return v.r + "," + v.g + "," + v.b + "," + v.a; }
		if (Std.is(p_v, Matrix4)) 	 { var v:Matrix4 	= cast p_v; return v.ToArray().join(","); }
		if (Std.is(p_v, Quaternion)) { var v:Quaternion = cast p_v; return v.x + "," + v.y + "," + v.z + "," + v.w; }
		if (Std.is(p_v, Buffer))	 { var v:Buffer     = cast p_v; return v.ToByteArray().join(","); }
		if (Std.is(p_v, Resource)) 	 { var v:Resource   = cast p_v; return v.guid; }		
		return null;
	}
	
	/**
	 * Parses the string and returns the correct type.
	 * @param	p_v
	 * @return
	 */
	static public function FromString(p_v:String,p_t:String):Dynamic
	{		
		if (p_t == null) return null;
		if (p_v == null) return null;		
		if (p_t == "Int") 	  				return Std.parseInt(p_v);
		if (p_t == "Float")  				return Std.parseFloat(p_v);
		if (p_t == "Bool")    				return p_v != "false";
		if (p_t == "String")  				return p_v;
		if (p_t == "haxor.math.Vector2")  	return Vector2.Parse(p_v, ",");
		if (p_t == "haxor.math.Vector3")  	return Vector3.Parse(p_v, ",");
		if (p_t == "haxor.math.Vector4")  	return Vector4.Parse(p_v, ",");
		if (p_t == "haxor.math.AABB2")    	return AABB2.Parse(p_v, ",");
		if (p_t == "haxor.math.AABB3")    	return AABB3.Parse(p_v, ",");
		if (p_t == "haxor.math.Color")    	return Color.Parse(p_v, ",");
		if (p_t == "haxor.math.Matrix4")  	return Matrix4.Parse(p_v, ",");
		if (p_t == "haxor.math.Quaternion") return Quaternion.Parse(p_v, ",");
		if (p_t == "haxor.io.FloatArray") 	return FloatArray.Parse(p_v, ",",true);
		if (p_t == "haxor.io.Int32Array") 	return Int32Array.Parse(p_v, ",", true);
		if (p_t == "haxor.io.UInt16Array") 	return UInt16Array.Parse(p_v, ",", true);
		if (p_t == "$GUID") 				return Resource.FindByGUID(p_v);		
		return null;
	}
}