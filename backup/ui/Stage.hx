/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import js.Browser;
import js.html.BodyElement;
import js.html.Document;
import js.html.DOMWindow;
import js.html.MouseEvent;
import haxor.core.Engine;
import haxor.core.IResizeable;
import haxor.graphics.Screen;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Stage extends Container implements IResizeable
{
	static public var scrollWidth(get_scrollWidth, never):Int;
	static private var m_scrollWidth : Int = -1;
	static private function get_scrollWidth():Int	
	{		
		if (m_scrollWidth > 0) return m_scrollWidth;
		var outer : Dynamic = Browser.document.createElement("div");
		outer.style.visibility = "hidden";
		outer.style.width = "100px";
		outer.style.msOverflowStyle = "scrollbar"; // needed for WinJS apps

		Browser.document.body.appendChild(outer);

		var widthNoScroll  : Int = outer.offsetWidth;
		// force scrollbars
		outer.style.overflow = "scroll";

		// add innerdiv
		var inner  : Dynamic = Browser.document.createElement("div");
		inner.style.width = "100%";
		outer.appendChild(inner);        

		var widthWithScroll  : Int = inner.offsetWidth;

		// remove divs
		outer.parentNode.removeChild(outer);

		return m_scrollWidth = (widthNoScroll - widthWithScroll);
	}
	
	public var body(get_body, never):BodyElement;
	private function get_body():BodyElement { return cast Browser.document.body; }
	
	public var document(get_document, never):Document;
	private function get_document():Document { return Browser.document; }
	
	public var window(get_window, never):DOMWindow;
	private function get_window():DOMWindow { return Browser.window; }
	
	
	
	
	override private function set_width(v:Float):Float {  return v;	}
	override private function get_width():Float 
	{ 
		var bo : String = body.style.overflow;				
		var v : Float = window.innerWidth; 		
		return v;
	}
	
	override private function set_height(v:Float):Float {  return v;	}
	override private function get_height():Float 
	{ 
		var bo : String = body.style.overflow;		
		var v : Float = window.innerHeight; 		
		return v;
	}

	override private function get_mouseX():Float {	return m_mouseX; }
	private var m_mouseX : Float;
	
	override private function get_mouseY():Float {	return m_mouseY; }
	private var m_mouseY : Float;
	
	public var needScroll(get_needScroll, never):Bool;
	private function get_needScroll():Bool { return element.scrollHeight > element.clientHeight; }
	
	public function new() 
	{
		super();		
		m_mouseX = 0;
		m_mouseY = 0;
		x = y = 0;
		//body.appendChild(m_element);		
		body.insertBefore(m_element,body.firstChild);
		body.addEventListener("mousemove", OnMouseMove);
		Engine.Add(this);
		name = "stage";		
	}
	
	private function OnMouseMove(p_event : MouseEvent):Void
	{
		m_mouseX = p_event.clientX;
		m_mouseY = p_event.clientY;		
	}
	
	public function OnResize(p_width:Float, p_height:Float):Void
	{	
		m_width  = width;
		m_height = height;	
		
		UpdateRect();		
	}
	
}