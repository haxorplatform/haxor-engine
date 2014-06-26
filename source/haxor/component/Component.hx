/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

 
package haxor.component;
import haxor.core.Application;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.Resource;

/**
 * ...
 * @author Eduardo Pons
 */
class Component extends Resource
{
	
	
	/**
	 * 
	 */
	public var entity(get_entity, never) : Entity;
	private var m_entity:Entity;	
	function get_entity():Entity { return m_entity; }
	
	/**
	 * 
	 */
	public var transform(get_transform, never):Transform;			
	function get_transform():Transform { return m_entity.transform; }
	
	/**
	 * 
	 */
	public var camera(get_camera, never):Camera;
	function get_camera():Camera { return cast m_entity.camera; }
	
	/**
	 * 
	 */
	public var renderer(get_renderer, never) : Renderer;	
	function get_renderer():Renderer { return cast m_entity.renderer; }
	
	/**
	 * 
	 */
	public var rigidbody(get_rigidbody, never) : RigidBody;	
	function get_rigidbody():RigidBody { return cast m_entity.rigidbody; }
	
	/**
	 * 
	 */
	public var layer(get_layer, set_layer):Int;
	private function get_layer():Int { return entity.layer; }
	private function set_layer(v:Int):Int { entity.layer = v; return v; }
	
	override private function set_name(v:String):String { super.set_name(m_entity.name = v); return v; }
	override private function get_name():String { return m_entity.name; }
	

	function new(p_entity:Entity) 
	{
		super();
		m_entity = p_entity;		
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<Component>) : Dynamic { return entity.AddComponent(p_type); }
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponent(p_type : Class<Component>) : Dynamic	{ return entity.GetComponent(p_type);	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponents(p_type : Class<Component>) : Array<Component>	{	return entity.GetComponents(p_type);	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentInChildren(p_type : Class<Component>) : Dynamic { return entity.GetComponentInChildren(p_type); }
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentsInChildren(p_type : Class<Component>) : Array<Component> { 	return entity.GetComponentsInChildren(p_type);	}
	
	
	
	private function OnTransformUpdate():Void { }
	
	
}