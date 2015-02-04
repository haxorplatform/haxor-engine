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
	private var m_entity : Entity;

	/**
	 * Reference to the Entity transform component.
	 */
	public var transform(get_transform, null):Transform;
	private inline function get_transform():Transform { return entity.transform; }	
	
	
	/**
	 * Reference to the entity's AddComponent method.
	 * @param	p_type
	 * @return
	 */
	public inline function AddComponent(p_type : Class<Component>) : Dynamic { return entity.AddComponent(p_type); }
	
	/**
	 * Reference to the entity's GetComponent method.
	 * @param	p_type
	 * @return
	 */
	public inline function GetComponent(p_type : Class<Component>) : Dynamic	{ return entity.GetComponent(p_type);	}
	
	/**
	 * Reference to the entity's GetComponents method.
	 * @param	p_type
	 * @return
	 */
	public inline function GetComponents(p_type : Class<Component>) : Array<Dynamic>	{	return entity.GetComponents(p_type);	}
	
	/**
	 * Reference to the entity's GetComponentInChildren method.
	 * @param	p_type
	 * @return
	 */
	public inline function GetComponentInChildren(p_type : Class<Component>) : Dynamic { return entity.GetComponentInChildren(p_type); }
	
	/**
	 * Reference to the entity's GetComponentsInChildren method.
	 * @param	p_type
	 * @return
	 */
	public inline function GetComponentsInChildren(p_type : Class<Component>) : Array<Dynamic> { 	return entity.GetComponentsInChildren(p_type);	}
	
	/**
	 * Method called when the component is created.
	 */
	private function OnBuild():Void { }
	
	/**
	 * Callback called when the Transform of the Entity changed.
	 */
	private function OnTransformUpdate(p_hierarchy : Bool):Void { }
	
	/**
	 * Callback called when the MeshRenderer's visibility of this Entity changed.
	 */
	private function OnVisibilityChange(p_visible:Bool):Void { }
	
	
	
}