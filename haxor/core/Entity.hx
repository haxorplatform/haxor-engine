package haxor.core;
import haxe.Timer;
import haxor.component.animation.Animation;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.component.Component;
import haxor.component.DataComponent;
import haxor.component.physics.RigidBody;
import haxor.component.Renderer;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.io.serialization.Formatter;
import haxor.io.serialization.ISerializable;
import haxor.component.util.SkyboxSelector;


/**
 * Class that represents all entities in the application scope.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
@:final
class Entity extends Resource implements ISerializable
{
	
	/**
	 * Flag that indicates if the entity and its components are enabled.
	 */
	@serialize
	public var enabled(get_enabled, set_enabled):Bool;
	private inline function get_enabled():Bool { return m_enabled && (!m_destroyed); }
	private function set_enabled(v:Bool):Bool 
	{ 
		if (m_destroyed) return false;
		if (m_enabled == v) return v;
		m_enabled = v; 
		for (i in 0...m_components.length)
		{
			var c : Component = m_components[i];
			if (c.m_is_behaviour)
			{
				var b : Behaviour = cast c;
				b.enabled = v;
			}			
		}
		return v; 
	}
	private var m_enabled : Bool;
	
	/**
	 * Reference to this Entity transform component.
	 */
	public var transform(get_transform, null):Transform;
	private inline function get_transform():Transform { return m_transform; }
	private var m_transform : Transform;
	
	/**
	 * Reference to this Entity Camera component.
	 */
	public var camera(get_camera, never):Camera;
	function get_camera():Camera { return cast GetComponent(Camera); }
	
	
	/**
	 * Reference to the first instance of DataComponent
	 */
	public var data(get_data, never):DataComponent;
	function get_data():DataComponent { return cast GetComponent(DataComponent); }
	
	/**
	 * Reference to this Entity Animation component.
	 */
	public var animation(get_animation, never):Animation;
	function get_animation():Animation { return cast GetComponent(Animation); }
	
	/**
	 * Reference to this Entity Renderer component.
	 */
	public var renderer(get_renderer, never) : Renderer;	
	function get_renderer():Renderer { return cast GetComponent(Renderer); }
	
	/**
	 * Reference to this Entity RigidBody component.
	 */
	public var rigidbody(get_rigidbody, never) : RigidBody;	
	function get_rigidbody():RigidBody { return cast GetComponent(RigidBody); }

	/**
	 * Layer mask of this entity. Layer masks will tell which camera, raycast, and other components/operations will target this entity.
	 */
	@serialize
	public var layer(get_layer, set_layer) : Int;
	private inline function get_layer():Int { return m_layer; }
	private function set_layer(v:Int):Int 
	{ 
		if (v <= 0) v = 1;
		if (m_layer == v) return v;
		var ll : Int = m_layer;
		m_layer = v;
		EngineContext.OnEntiyLayerChange(this,ll, m_layer);		
		return m_layer; 
	}
	private var m_layer:Int;
	
	/**
	 * Component list of this entity.
	 */
	@serialize(false)
	private var m_components : Array<Component>;
	
	
	/**
	 * Creates a new entity with the given name.
	 * @param	p_name
	 */
	public function new(p_name : String="") 
	{		
		//Console.Log("entity ctor");
		super(p_name);		
		m_enabled    = true;
		m_components = [];
		m_layer		 = 1;			
		#if (!ie8 && !nodejs)
		m_transform = cast AddComponent(Transform);		
		#end
		
		//Console.Log("entity ctor end");
	}
	
	/**
	 * Adds a new Component of the given type.
	 * @param	p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<Component>):Dynamic
	{
		if (m_destroyed) return null;		
		if (m_transform != null) if (p_type == Transform) return m_transform;
		var c:Component = null;		
		c = Type.createInstance(p_type, [""]);		
		if (c == null) return null;
		c.m_entity 		= this;		
		c.OnBuild();
		if (c.m_is_behaviour)
		{ 
			var b : Behaviour = cast c; 
			b.enabled = enabled; 
		}	
		m_components.push(c);
		return c;
	}
	
	/**
	 * Returns the first occurrence of the component defined by the informed type.
	 * @param	p_type
	 * @return
	 */
	public function GetComponent(p_type : Class<Component>) : Dynamic
	{
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) return m_components[i];
		return null;
	}
	
	/**
	 * Returns a list of components that matches the informed p_type.
	 * @param	p_type
	 * @return
	 */
	public function GetComponents(p_type : Class<Component>) : Array<Dynamic>
	{
		var res : Array<Component> = [];
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) res.push(m_components[i]);
		return res;
	}
	
	/**
	 * Returns the first occurrence, inside the hierarchy, of the component defined by the informed type.
	 * @param	p_type
	 * @return
	 */
	public function GetComponentInChildren(p_type : Class<Component>) : Dynamic
	{
		var res : Array<Component> = [];
		var res : Component = null;
		transform.Traverse(function(t : Transform,d:Int):Bool
		{
			if (res != null) return true;
			var l : Array<Dynamic> = t.entity.GetComponents(p_type);
			if (l.length > 0) { res = l[0]; return true; }			
			return true;
		});
		return res;
	}
	
	/**
	 * Returns the list of components inside the hierarchy that matches the informed type.
	 * @param	p_type
	 * @return
	 */
	public function GetComponentsInChildren(p_type : Class<Component>) : Array<Dynamic>
	{
		var res : Array<Dynamic> = [];
		transform.Traverse(function(t : Transform,d:Int):Bool
		{
			var l : Array<Dynamic> = t.entity.GetComponents(p_type);
			for (i in 0...l.length) res.push(l[i]);
			return true;
		});
		return res;
	}
	
	/**
	 * Calls the OnDestroy callback of all components.
	 */
	override public function OnDestroy():Void 
	{
		for (i in 0...m_components.length)
		{
			m_components[i].OnDestroy();
		}
		m_components = null;
	}
	
	/**
	 * Callback called when the formatter is processing this instance's fields.
	 * This callback can ovewrite the default behaviour or return an empty string to delegate the serialization to the formatter.
	 * @param	p_id
	 * @param	p_fields
	 * @return
	 */
	public function OnSerializeField(p_formatter:Formatter,p_field : String,p_value:Dynamic):String { return null; }
		
	/**
	 * Callback called when the deserialization is processing the input data and finds a field and its value.
	 * If the class successfully process the contents it will return true, otherwise false is returned and the formatter tries to cope with the situation.
	 * @param	p_id
	 * @param	p_fields
	 * @return
	 */
	public function OnDeserializeField(p_formatter:Formatter,p_field:String,p_value:Dynamic):Bool
	{
		var fmt : Formatter = p_formatter;
		
		switch(p_field)
		{
			case "m_components":
			{				
				
				var cnl : Array<Dynamic> = cast p_value;
				
				for (i in 0...cnl.length)
				{
					var cn : FormatterData 		= cnl[i];								
					var ct : Class<Component> 	= cast cn.GetType();
					if (ct == null) continue;					
					var c 	: Component 		= AddComponent(ct);
					
					var fields : Array<String> = cn.GetFields();
					for (i in 0...fields.length)
					{						
						var field_name		: String  = fields[i];												
						var field_value 	: Dynamic = Reflect.getProperty(cn, field_name);
						fmt.OnDecodeField(c, field_name, field_value);						
					}					
				}
				return true;
			}
		}
		//*/
		return false;
	}
	
	/**
	 * Resets the guid of this entity and components.
	 */
	private function ResetGUID():Void
	{
		guid = "";
		for (i in 0...m_components.length) m_components[i].guid = "";
	}
	
}