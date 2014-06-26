/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics;
import js.Browser;
import js.html.CanvasElement;
import js.html.DivElement;
import js.html.Element;
import haxor.core.Application;
import haxor.core.Engine;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Screen
{
	static private var m_target : Element;
	
	/**
	 * 
	 */
	static public var width(get_width, never) : Int;
	static function get_width():Int { return m_width; }
	static private var m_width : Int = 0;
	
	/**
	 * 
	 */
	static public var height(get_height, never) : Int;
	static function get_height():Int { return m_height; }
	static private var m_height : Int = 0;

	/**
	 * 
	 * @param	p_element
	 * @return
	 */
	static public function IsFullscreen(p_element : Element):Bool
	{
		
		if (p_element == null) return false;
		var d:Dynamic = Browser.document;
		if (d.fullscreenElement != null) 				return p_element == d.fullscreenElement;
		if (d.mozFullScreenElement != null) 			return p_element == d.mozFullScreenElement;
		if (d.msFullScreenElement != null) 				return p_element == d.msFullScreenElement;
		if (d.oFullScreenElement != null) 				return p_element == d.oFullScreenElement;
		if (d.webkitCurrentFullScreenElement != null)   return p_element == d.webkitCurrentFullScreenElement;
		return false;
	}
	
	/**
	 * 
	 * @param	p_element
	 * @return
	 */
	static public function SetFullscreen(p_element : Element,p_flag : Bool,p_keyboard:Bool = true):Void
	{
		if (p_element == null) return;
		var is_fs : Bool = IsFullscreen(p_element);
		if (is_fs == p_flag) return;
		var c : Dynamic = p_element;
		var d : Dynamic = Browser.document;
		if (p_flag)
		{	
			if (c.requestFullScreen != null) 		p_keyboard ? c.requestFullScreen(Element.ALLOW_KEYBOARD_INPUT) 		 : c.requestFullScreen();		else			
			if (c.mozRequestFullScreen != null) 	p_keyboard ? c.mozRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT) 	 : c.mozRequestFullScreen();	else
			if (c.msRequestFullScreen != null) 		p_keyboard ? c.msRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT) 	 : c.msRequestFullScreen();		else
			if (c.oRequestFullScreen != null) 		p_keyboard ? c.oRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT) 	 : c.oRequestFullScreen();		else
			if (c.webkitRequestFullScreen != null) 	p_keyboard ? c.webkitRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT) : c.webkitRequestFullScreen();			
		}
		else 
		{	
			if (d.cancelFullScreen) 		d.cancelFullScreen();			else
			if (d.mozCancelFullScreen)  	d.mozCancelFullScreen();		else
			if (d.msCancelFullScreen)  		d.msCancelFullScreen();			else
			if (d.oCancelFullScreen)  		d.oCancelFullScreen();			else
			if (d.webkitCancelFullScreen) 	d.webkitCancelFullScreen();			
		}		
	}
	
	/**
	 * 
	 */
	static public var fullscreen(get_fullscreen, set_fullscreen):Bool;	
	static private function get_fullscreen():Bool { return IsFullscreen(m_target); }
	static private function set_fullscreen(v:Bool):Bool {  SetFullscreen(m_target, v); return v; }
	
}