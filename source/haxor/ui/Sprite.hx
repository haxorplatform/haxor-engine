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
import js.html.CanvasPattern;
import js.html.CanvasRenderingContext2D;
import js.html.Event;
import js.html.Image;
import js.html.ImageData;
import js.html.ImageElement;
import haxor.math.AABB2;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Sprite extends Container
{	
	public var slices(get_slices, set_slices):Array<Int>;
	private function get_slices():Array<Int> { return m_slices.copy(); }
	private function set_slices(v:Array<Int>):Array<Int> { if (v == null) m_slices = v = []; else m_slices = v.copy(); OnRepaint(); return v; }
	private var m_slices : Array<Int>;
	
	public var pattern(get_pattern, set_pattern):Bool;
	private function set_pattern(v:Bool):Bool { m_pattern = v; OnRepaint(); return v; }
	private function get_pattern():Bool { return m_pattern; }
	private var m_pattern : Bool;
	
	public var image(get_image, set_image):ImageElement;
	private function get_image():ImageElement { return m_image; }
	private function set_image(v:ImageElement) : ImageElement 
	{ 
		if (m_buffer == null) if (m_image != null) if(m_element == m_image.parentElement) m_element.removeChild(m_image);
		if (m_image == null) if (v != null) { width = width <= 0 ? v.naturalWidth : width; height = height <= 0 ? v.naturalHeight : height; }
		m_image = v; 
		if (m_buffer == null)
		{
			if (m_image != null)
			{
				m_image.style.position  = "absolute";				
				m_image.style.width  = "100%";
				m_image.style.height = "100%";
				m_image.style.display = "inline";
				m_element.appendChild(m_image);
			}
		}
		OnRepaint(); 
		return v; 
	}
	
	private var m_image : ImageElement;
	
	private var m_buffer : CanvasRenderingContext2D;

	public function new(p_use_canvas : Bool = true,p_src : String = "") 
	{
		super();
		
		if (p_use_canvas)
		{
			var c : CanvasElement = Browser.document.createCanvasElement();
			c.style.setProperty("pointer-events","none", "");
			c.style.zIndex = "auto";	
			c.style.position = "absolute";
			m_buffer = c.getContext2d();
			m_element.appendChild(c);
		}
		
		m_slices = [];				
		m_pattern = false;
		
		if (p_src != "")
		{
			var img : Image = new Image();
			img.style.setProperty("pointer-events","none", "");
			img.src = p_src;
			img.onload = function(e : Event)
			{
				image = img;
			};	
			//m_image = img;
		}
	}
	
	override private function OnRepaint():Void 
	{
		super.OnRepaint();	
		if (m_buffer != null)
		{			
			m_buffer.canvas.width  = cast m_width  - (layout.margin.xMin + layout.margin.xMax);
			m_buffer.canvas.height = cast m_height - (layout.margin.yMin + layout.margin.yMax);		
			if (m_image != null)
			{
				if (!m_pattern)
				{
					DrawSlicedImage(m_buffer, m_image, m_buffer.canvas.width, m_buffer.canvas.height, m_slices);
				}
				else
				{
					var p : CanvasPattern = m_buffer.createPattern(m_image, "repeat");
					m_buffer.rect(0, 0, m_buffer.canvas.width, m_buffer.canvas.height);
					m_buffer.fillStyle = p;
					m_buffer.fill();
				}
			}
		}
		else
		{
			if (m_image != null)
			{
				m_image.style.display = m_pattern ? "none" : "block";
				m_element.style.backgroundImage  = m_pattern ? "url(" + m_image.src + ")" : "";
				m_element.style.backgroundRepeat = m_pattern ? "repeat" : "";				
			}			
		}
	}
	
	override public function OnSkinChange(p_skin:UISkin):Void 
	{
		var img_skin : ImageSkin = cast p_skin.Get(m_skin);
		if (img_skin != null)
		{
			image = img_skin.image;
			slices = img_skin.slices;
		}
		
	}
	
	
}