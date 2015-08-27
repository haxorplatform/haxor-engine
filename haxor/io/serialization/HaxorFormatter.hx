package haxor.io.serialization;
import haxe.Json;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.io.serialization.Formatter;

/**
 * Class that implements class serialization for Haxor's type and structures.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class HaxorFormatter extends Formatter
{
	
	/**
	 * CTOR
	 */
	public function new() 
	{
		super();
		RegisterClass(Vector2);
		RegisterClass(Vector3);
		RegisterClass(Vector4);
		RegisterClass(AABB2);
		RegisterClass(AABB3);
		RegisterClass(Color);	
		RegisterClass(Matrix4); 	
		RegisterClass(Resource);	
		RegisterClass(Quaternion);
		RegisterClass(FloatArray);
		RegisterClass(Int32Array);
		RegisterClass(UInt16Array);
		RegisterClass(Buffer);		
	}
	
	/**
	 * PArses the text data and returns a typed instance of the serialized object.
	 * @param	p_data
	 * @return
	 */
	override public function Deserialize(p_data:String) : Dynamic
	{
		var d : Dynamic 	= Json.parse(p_data);				
		var res : Dynamic   = FromObject(d);
		if (Std.is(d, Array))
		{
			var l : Array<Dynamic> = cast res;
			//for (i in 0...l.length) if (Std.is(l[i], Entity)) { var e : Entity = cast l[i]; e.ResetGUID(); }
		}
		else
		if (Std.is(res, Entity)) 
		{ 
			var e : Entity = cast res; 
			//e.ResetGUID(); 			
		}
		return res;
	}
	
	/**
	 * Converts a field value to string or return null if it fails.
	 * @param	p_v
	 * @return
	 */
	override public function ToString(p_v:Dynamic):String 
	{
		var s : String = super.ToString(p_v);
		if (s != null) return s;
		if (Std.is(p_v, Vector2)) 	 { var v:Vector2 	= cast p_v; return v.x + "," + v.y; }
		if (Std.is(p_v, Vector3)) 	 { var v:Vector3 	= cast p_v; return v.x + "," + v.y + "," + v.z; }
		if (Std.is(p_v, Vector4)) 	 { var v:Vector4 	= cast p_v; return v.x + "," + v.y + "," + v.z + "," + v.w; }
		if (Std.is(p_v, AABB2)) 	 { var v:AABB2 		= cast p_v; return v.xMin + "," + v.xMax + "," + v.yMin + "," + v.yMax; }
		if (Std.is(p_v, AABB3)) 	 { var v:AABB3 		= cast p_v; return v.xMin + "," + v.xMax + "," + v.yMin + "," + v.yMax+","+v.zMin+","+v.zMax; }		
		if (Std.is(p_v, Color)) 	 { var v:Color	 	= cast p_v; return v.r + "," + v.g + "," + v.b + "," + v.a; }
		if (Std.is(p_v, Matrix4)) 	 { var v:Matrix4 	= cast p_v; return v.ToArray().join(","); }
		if (Std.is(p_v, Resource)) 	 { var v:Resource   = cast p_v; return v.guid; }
		if (Std.is(p_v, Quaternion)) { var v:Quaternion = cast p_v; return v.x + "," + v.y + "," + v.z + "," + v.w; }		
		if (Std.is(p_v, FloatArray)) { var v:Buffer     = cast p_v; return v.ToByteArray().join(","); }
		if (Std.is(p_v, Int32Array)) { var v:Buffer     = cast p_v; return v.ToByteArray().join(","); }
		if (Std.is(p_v, UInt16Array)){ var v:Buffer     = cast p_v; return v.ToByteArray().join(","); }
		if (Std.is(p_v, Buffer))	 { var v:Buffer     = cast p_v; return v.ToByteArray().join(","); }
		return null;
	}
	
	/**
	 * Parses the string and returns a new instance with the correct type.
	 * @param	p_v
	 * @param	p_t
	 * @return
	 */
	override public function FromString(p_v:String, p_t:String):Dynamic 
	{
		if (p_v == null) return null;
		if (p_t == null) return null;
		var res : Dynamic = super.FromString(p_v, p_t);
		if (res != null) return res;
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
		if (p_t == "haxor.io.Buffer") 		return Buffer.Parse(p_v, ",", true);
		if (p_t == "haxor.core.Resource")
		{
			var res : Resource = Resource.FindByGUID(p_v);
			return res;
		}
		return null;
	}
	
}