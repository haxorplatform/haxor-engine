package haxor.io.serialization.haxor;
import haxe.Json;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.graphics.material.Material;
import haxor.graphics.texture.Texture;
import haxor.io.FloatArray;
import haxor.io.serialization.ISerializable;
import haxor.io.serialization.SerializedField;
import haxor.math.Matrix4;
import haxor.platform.Types.Float32;



/**
 * Class that implements the serialization of data using the Haxor json format.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class HaxorFormatter extends DeprecFormatter
{
	
	/**
	 * Parses the data and returns the according instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data:String):Dynamic { var fmt : HaxorFormatter = new HaxorFormatter(); return fmt.Deserialize(p_data); }
	
	/**
	 * Converts the specified target to string.
	 * @param	p_target
	 * @param	p_has_tabs
	 * @return
	 */
	static public function ToString(p_target:Dynamic,p_has_tabs:Bool=false):String { var fmt : HaxorFormatter = new HaxorFormatter(p_has_tabs); return fmt.Serialize(p_target); }

	/**
	 * Flag that indicates if the final json will be formatted.
	 * @param	p_has_tabs
	 */
	private var m_has_tabs 	 : Bool;	
	
	/**
	 * Creates  a new Haxor formatter.
	 * @param	p_has_tabs
	 */
	public function new(p_has_tabs:Bool = false) 
	{
		super();
		m_has_tabs = p_has_tabs;		
	}
	
	/**
	 * Receives the text data describing an instance and either fills an existing instance or creates a new one.
	 * @param	p_data
	 * @param	p_instance
	 */
	override public function Deserialize(p_data:String):Dynamic { return DeserializeData(Json.parse(p_data)); }
		
	/**
	 * Callback to handle the generated parsing structure.
	 * @param	p_root
	 * @return
	 */
	override function OnSerialize(p_root:SerializedData):String 
	{	
		Clean(cast p_root);		
		return Json.stringify(p_root, function(k:Dynamic, v:Dynamic):Dynamic { return v; },m_has_tabs ? " " : null);		
	}
		
	/**
	 * Remove unnused fields.
	 * @param	n
	 */
	private function Clean(n:SerializedData):Void
	{
		if (!Std.is(n, SerializedData)) return;		
				
		#if html
		untyped __js__("delete n.target");
		#end
		
		for(i in 0...n.fields.length)
		{			
			var f:SerializedField = cast n.fields[i];
			
			#if html
			untyped __js__("delete f.meta");
			untyped __js__("delete f.target");
			#end			
			
			if (Std.is(f.value, Array)) 
			{ 
				var nl : Array<SerializedData> = cast f.value;				
				for (i in 0...nl.length) Clean(cast nl[i]);
				return;
			}
			Clean(f.value);
		}
		for (i in 0...n.children.length) Clean(cast n.children[i]);
	}
}