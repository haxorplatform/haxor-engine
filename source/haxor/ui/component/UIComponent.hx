/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

 
package haxor.ui.component;
import haxor.core.Application;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.Resource;
import js.html.Element;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class UIComponent extends Resource
{
	
	
	/**
	 * 
	 */
	public var entity(get_entity, never) : UIEntity;
	private var m_entity:UIEntity;	
	function get_entity():UIEntity { return m_entity; }
	
	/**
	 * 
	 */
	public var element(get_element, never) : Element;	
	function get_element():Element { return m_entity.m_element; }
	
	
	override private function set_name(v:String):String { super.set_name(m_entity.name = v); return v; }
	override private function get_name():String { return m_entity.name; }
	

	function new(p_entity:UIEntity) 
	{
		super();
		m_entity = p_entity;		
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<UIComponent>) : Dynamic { return entity.AddComponent(p_type); }
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponent(p_type : Class<UIComponent>) : Dynamic	{ return entity.GetComponent(p_type);	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponents(p_type : Class<UIComponent>) : Array<UIComponent>	{	return entity.GetComponents(p_type);	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentInChildren(p_type : Class<UIComponent>) : Dynamic { return entity.GetComponentInChildren(p_type); }
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentsInChildren(p_type : Class<UIComponent>) : Array<UIComponent> { 	return entity.GetComponentsInChildren(p_type);	}
	
	private function OnAddedToStage():Void { }
	
	private function OnTransformUpdate():Void { }
	
	private function OnRectUpdate():Void { }
	
	private function OnMaterialUpdate():Void { }
	
	
}