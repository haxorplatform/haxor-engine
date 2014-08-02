package haxor.core;
import haxor.component.Behaviour;
import haxor.component.Component;

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
	 * Component list of this entity.
	 */
	private var m_components : Array<Component>;
	
	/**
	 * Creates a new entity with the given name.
	 * @param	p_name
	 */
	public function new(p_name : String) 
	{		
		super(p_name);
		m_enabled    = true;
		m_components = [];
	}
	
	/**
	 * Adds a new Component of the given type.
	 * @param	p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<Component>):Dynamic
	{
		if (m_destroyed) return null;
		var c:Component = Type.createInstance(p_type, []);
		c.m_entity 		= this;
		if (c.m_is_behaviour)
		{ 
			var b : Behaviour = cast c; 
			b.enabled = enabled; 
		}			
		m_components.push(c);
		return c;
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