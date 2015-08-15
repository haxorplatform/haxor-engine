package haxor.io.serialization;
import haxe.Json;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.graphics.material.Material;
import haxor.io.serialization.Formatter.FormatterField;
import haxor.io.serialization.Formatter.FormatterNode;
import sys.db.Types.SBigInt;


/**
 * Extension of the formatter node to handle extra information.
 */
extern class HaxorFormatterNode extends FormatterNode
{
	var component:Bool;		
	var resource:Bool;		
}

/**
 * Extension of the formatter node to handle extra data.
 */
extern class HaxorFormatterField extends FormatterField
{
	
}

/**
 * Class that implements the serialization of data using the Haxor json format.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class HaxorFormatter extends Formatter
{

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
	override public function Deserialize(p_data:String):Dynamic	
	{
		var n : HaxorFormatterNode = Json.parse(p_data);		
		return DeserializeStep(n);		
	}
	
	/**
	 * Process the node and follow up the deserialization.
	 * @param	n
	 * @return
	 */
	private function DeserializeStep(n : HaxorFormatterNode):Dynamic
	{
		var c : Class<Dynamic> = Type.resolveClass(n.type);
		var res : Dynamic = null;
		var ignore : Array<String> = [];
		
		res = Type.createInstance(c, []);
		
		switch(n.type)
		{
			case "haxor.core.Entity":
			{	
				ignore = ["m_components"];
			}
			
			case "haxor.graphics.material.Material":
			{
				ignore = ["uniforms"];
			}
		}
		
		for (i in 0...n.fields.length)
		{
			var f : HaxorFormatterField = cast n.fields[i];
			if (ignore.indexOf(f.name) >= 0) continue;
			DeserializeObject(f, res);			
		}		
		
		if (Std.is(res, Entity))   DeserializeEntity(n,cast res);		
		if (Std.is(res, Material)) DeserializeMaterial(n,cast res);	
		
		return res;
	}
	
	/**
	 * Parses the formatter node considering the special case of the Materials resource.
	 * @param	n
	 * @param	e
	 */
	private function DeserializeMaterial(n:HaxorFormatterNode, m:Material):Void
	{
		var mcf : HaxorFormatterField = cast n.fields.filter(function(f:FormatterField):Bool { return f.name == "uniforms"; } )[0];
		trace(mcf);
		/*
		var cnl : Array<HaxorFormatterNode> = cast mcf.value;
		for (i in 0...cnl.length)
		{
			var cn : HaxorFormatterNode = cnl[i];			
			var ct : Class<Component> = cast Type.resolveClass(cn.type);
			if (ct == null) continue;
			var c : Component = e.AddComponent(ct);
			var cfl : Array<HaxorFormatterField> = cast cn.fields;
			for (j in 0...cfl.length)
			{
				var cf : HaxorFormatterField = cfl[j];				
				DeserializeObject(cf, c);				
			}
			if (Std.is(c, Transform)) { var t:Transform = cast c; t.parent = null; }
		}
		//*/
	}
	
	/**
	 * Parses the formatter node considering the special case of the Entity resource.
	 * @param	n
	 * @param	e
	 */
	private function DeserializeEntity(n:HaxorFormatterNode, e:Entity):Void
	{
		var mcf : HaxorFormatterField = cast n.fields.filter(function(f:FormatterField):Bool { return f.name == "m_components"; } )[0];
		var cnl : Array<HaxorFormatterNode> = cast mcf.value;
		for (i in 0...cnl.length)
		{
			var cn : HaxorFormatterNode = cnl[i];			
			var ct : Class<Component> = cast Type.resolveClass(cn.type);
			if (ct == null) continue;
			var c : Component = e.AddComponent(ct);
			var cfl : Array<HaxorFormatterField> = cast cn.fields;
			for (j in 0...cfl.length)
			{
				var cf : HaxorFormatterField = cfl[j];				
				DeserializeObject(cf, c);				
			}
			if (Std.is(c, Transform)) { var t:Transform = cast c; t.parent = null; }
		}		
	}
	
	
	/**
	 * Parses the field and applies its value to the target.
	 * @param	f
	 * @param	t
	 */
	private function DeserializeObject(f:HaxorFormatterField, t:Dynamic):Void
	{
		var d : Dynamic = null;
		var nl : Array<HaxorFormatterNode>;
		switch(f.type)
		{
			case "$Node": 		d = DeserializeStep(f.value);
			case "$NodeArray":  
			{
				d = [];
				nl = f.value; 
				for (j in 0...nl.length) d.push(DeserializeStep(nl[j]));
			}
			default:				
				d = FromString(f.value, f.type);
				
				
		}				
		Reflect.setProperty(t, f.name, d);
	}
	
	/**
	 * Callback to handle the generated parsing structure.
	 * @param	p_root
	 * @return
	 */
	override function OnSerialize(p_root:FormatterNode):String 
	{	
		Clean(cast p_root);		
		return Json.stringify(p_root, function(k:Dynamic, v:Dynamic):Dynamic { return v; },m_has_tabs ? " " : null);		
	}
	
	/**
	 * Remove unnused fields.
	 * @param	n
	 */
	private function Clean(n:HaxorFormatterNode):Void
	{
		if (!Std.is(n, FormatterNode)) return;		
		
		if (Std.is(n.target, Resource)) n.component = true; else n.component = false;
		if (Std.is(n.target, Component)) n.component = true; else n.component = false;
				
		untyped __js__("delete n.target");
		
		for(i in 0...n.fields.length)
		{			
			var f:HaxorFormatterField = cast n.fields[i];
			untyped __js__("delete f.meta");
			untyped __js__("delete f.target");
						
			if (Std.is(f.value, Array)) 
			{ 
				var nl : Array<FormatterNode> = cast f.value;				
				for (i in 0...nl.length) Clean(cast nl[i]);
				return;
			}
			Clean(f.value);
		}
		for (i in 0...n.children.length) Clean(cast n.children[i]);
	}
}