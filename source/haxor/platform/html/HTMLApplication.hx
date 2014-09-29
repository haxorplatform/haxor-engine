#if html
package haxor.platform.html;
import haxor.dom.DOMStage;
import haxor.platform.Types.Float32;
import js.html.DivElement;
import haxor.core.BaseApplication;
import js.Browser;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.EventListener;
import js.html.Image;
import js.html.Event;
import js.html.Node;
import js.html.NodeList;
import js.html.ProgressEvent;
import js.html.EventTarget;
import js.html.XMLHttpRequest;
import js.html.Element;



/**
 * Class that defines a base Application for HTML projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class HTMLApplication extends BaseApplication
{
	/**
	 * Referene to the DOMStage UI root.
	 */
	public var stage(get_stage, never):DOMStage;
	private function get_stage():DOMStage { return DOMStage.m_instance; }
	
	
	/**
	 * Reference to the Element container in the HTML
	 */
	private var m_container : Element;
		
	/**
	 * Constructor called on page load for each [application] tag found in the page.
	 * @param	p_tag [application] element found on the HTML source.
	 */
	private function new() 
	{
		super();				
		m_platform 			= Platform.HTML;				
	}
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerWidth():Float32{ return m_container.clientWidth; }
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerHeight():Float32 { return m_container.clientHeight; }
	
	
}
#end