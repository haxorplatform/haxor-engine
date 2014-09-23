#if html

package haxor.dom;
import js.html.MouseEvent;
import haxor.core.IResizeable;
import js.html.Element;

/**
 * Class that contains all DOM entities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class DOMStage extends Container  implements IResizeable
{
	/**
	 * Holds the creates DOMStage instance.
	 */
	static private var m_instance : DOMStage;
	
	/**
	 * Root DOM element.
	 */
	private var m_container : Element;

	/**
	 * Creates the DOMStage which will contain all DOMEntities in the application.
	 * @param	p_container
	 */
	private function new(p_container:Element) 
	{
		m_instance = this;
		super(p_container,"stage");
	}
	
	/**
	 * Resize callback.
	 * @param	p_width
	 * @param	p_height
	 */
	public function OnResize(p_width:Float, p_height:Float):Void
	{	
		m_width  = width;
		m_height = height;			
		UpdateRect();		
	}
	
}

#end