package haxor.context;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.core.Entity;

/**
 * Class that handles all Transform instances functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class TransformContext
{

	/**
	 * Unique Transforms ids.
	 */
	private var tid : UID;
	
	/**
	 * Creates the context.
	 */
	private function new() 
	{
		tid = new UID();
	}
	
	/**
	 * Initializes the context with Graphics available.
	 */
	private function Initialize():Void
	{
		
	}
	
	/**
	 * Notifies all components from the Entity that its transform updated.
	 * @param	t
	 */
	private function OnChange(t:Transform):Void
	{
		t.m_uniform_dirty = true;
		var cl : Array<Component>   = t.m_entity.m_components;
		for (i in 0...cl.length) cl[i].OnTransformUpdate(false);
	}
	
	/**
	 * Notifies all components from Entity that the hierarchy location has changed.
	 * @param	t
	 */
	private function OnHierarchyChange(t:Transform):Void
	{
		var cl : Array<Component>   = t.m_entity.m_components;
		for (i in 0...cl.length) cl[i].OnTransformUpdate(true);
	}
	
}