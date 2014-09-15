package haxor.core;
import haxor.component.Behaviour;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.context.EngineContext;

/**
 * Class that represents all entities in the application scope.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Entity extends Resource
{
	
	/**
	 * Flag that indicates if the entity and its components are enabled.
	 */
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
	 * Layer mask of this entity. Layer masks will tell which camera, raycast, and other components/operations will target this entity.
	 */
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
		#if !ie8
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
		if (c.m_is_behaviour)
		{ 
			var b : Behaviour = cast c; 
			b.enabled = enabled; 
		}			
		c.OnBuild();
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
}