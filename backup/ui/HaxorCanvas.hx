/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import js.Browser;
import js.html.CanvasElement;
import js.html.Rect;
import haxor.math.AABB2;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class HaxorCanvas extends UIEntity
{
	public var element(get_element, never):CanvasElement;
	private function get_element():CanvasElement { return cast m_element; }
	
	public var hasAlpha(get_hasAlpha, never):Bool;
	private function get_hasAlpha():Bool { return m_element.getAttribute("alpha") == "true"; }
	
	public var hasAntialias(get_hasAntialias, never):Bool;
	private function get_hasAntialias():Bool { return m_element.getAttribute("antialias") == "true"; }
	
	public var hasDepth(get_hasDepth, never):Bool;
	private function get_hasDepth():Bool { return m_element.getAttribute("depth") == "true"; }
	
	public var hasStencil(get_hasStencil, never):Bool;
	private function get_hasStencil():Bool { return m_element.getAttribute("depth") == "true"; }
	
	public var hasPremultipliedAlpha(get_hasPremultipliedAlpha, never):Bool;
	private function get_hasPremultipliedAlpha():Bool { return m_element.getAttribute("premultipliedAlpha") == "true"; }
	
	public var preserveBuffer(get_preserveBuffer, never):Bool;
	private function get_preserveBuffer():Bool { return m_element.getAttribute("preserveDrawingBuffer") == "true"; }
	
	public function new(p_element : CanvasElement=null,p_alpha:Bool=true,p_antialias:Bool=false,p_depth:Bool=true,p_stencil:Bool=false,p_premultiplied_alpha : Bool=false,p_preserve_buffer:Bool=false) 
	{	
		m_element = p_element == null ? Browser.document.createCanvasElement() : p_element;
		super();
		name = "haxor";
		m_element.id = "haxor";
		m_element.style.cursor = "default";
		if (p_element == null)
		{			
			m_element.setAttribute("alpha", p_alpha+"");
			m_element.setAttribute("depth", p_depth+"");
			m_element.setAttribute("antialias", p_antialias+"");
			m_element.setAttribute("stencil", p_stencil+"");
			m_element.setAttribute("premultipliedAlpha", p_premultiplied_alpha+"");
			m_element.setAttribute("preserveDrawingBuffer", p_preserve_buffer+"");
			m_element.setAttribute("mode", "3d");			
		}
		
		if (p_element == null)
		{
			layout.flag = LayoutFlag.SizeXY;
			layout.width = layout.height = 1.0;
			if(application.stage != null) application.stage.AddChildAt(this, 0);
		}
		
	}
	
	override private function UpdateRect():Void 
	{
		super.UpdateRect();
		var r : AABB2 = rect;
		element.width  = cast r.width;
		element.height = cast r.height;		
	}
	
}