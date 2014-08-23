package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Component extends Resource
{
	
	/**
	 * Returns the container entity name.
	 * @return
	 */
	override function get_name():String { return m_entity.name; }
	
	/**
	 * Sets the container entity name.
	 * @return
	 */
	override function set_name(v:String):String { m_entity.name = v; return v; }
	
	/**
	 * Container entity of this component.
	 */
	public var entity(get_entity, null):Entity;
	private inline function get_entity():Entity { return m_entity; }
	/**
	 * Reference to the entity that contains this component.
	 */
	private var m_entity : Entity;

	
	
	/**
	 * Hidden constructor. Instantiation is controlled internally.
	 */
	private function new() 
	{
		super("");		
		OnBuild();
	}
	
	/**
	 * Method called when the component is created.
	 */
	private function OnBuild():Void { }
	
	/**
	 * Callback called when the Transform of the Entity changed.
	 */
	private function OnTransformUpdate():Void { }
	
}