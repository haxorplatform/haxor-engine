package haxor.dom;
import haxor.math.Mathf;
import js.Browser;
import js.html.CanvasElement;
import js.html.CanvasPattern;
import js.html.CanvasRenderingContext2D;
import js.html.Element;
import js.html.Event;
import js.html.Image;
import js.html.ImageElement;

/**
 * Class that wraps an element with an image associated.
 * @author 
 */
class Sprite extends Container
{
	/**
	 * Reference to this Sprite slices limits.
	 */
	public var slices(get_slices, set_slices):Array<Int>;
	private function get_slices():Array<Int> { return m_slices.copy(); }
	private function set_slices(v:Array<Int>):Array<Int> { if (v == null) m_slices = v = []; else m_slices = v.copy(); OnRepaint(); return v; }
	private var m_slices : Array<Int>;
	
	/**
	 * Reference to the created image.
	 */
	public var image(get_image, set_image):ImageElement;
	private function get_image():ImageElement { return m_image; }
	private function set_image(v:ImageElement) : ImageElement 
	{ 
		if (m_image == v) return v;		
		m_image = v; 
		var olc : Dynamic = function()
		{
			if (width <= 0)  width  = m_image.naturalWidth;
			if (height <= 0) height = m_image.naturalHeight;
			m_image.onload = null;
		};
		m_image.onload = olc;
		if (width <= 0)  width  = m_image.naturalWidth;
		if (height <= 0) height = m_image.naturalHeight;		
		if (m_image == null) return v;		
		OnRepaint(); 
		return v; 
	}
	private var m_image : ImageElement;
	private var m_src : String;
	
	/**
	 * Flag that indicates if the image will display its content as pattern.
	 */
	public var pattern(get_pattern, set_pattern):Bool;
	private function set_pattern(v:Bool):Bool { if (m_pattern == v) return v; m_pattern = v; OnRepaint(); return v; }
	private function get_pattern():Bool { return m_pattern; }
	private var m_pattern : Bool;
	
	private var _rc : CanvasRenderingContext2D;
	
	public function new(p_src : String,p_use_canvas:Bool=false,p_name:String="") 
	{
		#if ie8
		p_use_canvas = false;
		#end
		
		m_pattern = false;
		m_slices  = [];
		m_src	  = "";
		
		var e : Element = null;
		
		if (p_use_canvas)
		{
			var c : CanvasElement = Browser.document.createCanvasElement();			
			c.style.position = "absolute";
			_rc = c.getContext2d();
			e = c;
		}
				
		var img : Image = new Image();
		if (p_src != "")
		{
			img.src = m_src = p_src;
			img.style.backgroundImage  = "url(" + m_src + ")";
			img.style.backgroundRepeat = "repeat";
			image   = img;
		}
		if (e==null) e = img;
		
		super(e, p_name);
		
	}
	
	/**
	 * Updates the graphical data of this Sprite.
	 */
	override private function OnRepaint():Void 
	{
		super.OnRepaint();	
		if (m_image == null) 	return;
		if (m_element == null)	return;		
		if (_rc == null)
		{
			if (m_pattern)
			{	
				m_image.src = "";
				m_image.style.backgroundImage  = "url(" + m_src + ")";
				m_image.style.backgroundRepeat = "repeat";
			}
			else
			{
				m_image.src = m_src;
				m_image.style.removeProperty("background-image");
			}
		}
		else		
		{			
			var c : CanvasElement = cast m_element;
			c.width  = cast m_width  - (layout.margin.xMin + layout.margin.xMax);
			c.height = cast m_height - (layout.margin.yMin + layout.margin.yMax);		
			if (!m_pattern)
			{
				DrawSlicedImage(_rc, m_image, c.width, c.height, m_slices);
			}
			else
			{
				var p : CanvasPattern = _rc.createPattern(m_image, "repeat");
				_rc.rect(0, 0, c.width, c.height);
				_rc.fillStyle = p;
				_rc.fill();
			}			
		}
	}
	
	/**
	 * Draws a sliced image using the informed rendering context.
	 * @param	p_graphics
	 * @param	p_image
	 * @param	w
	 * @param	h
	 * @param	p_slices
	 */
	private function DrawSlicedImage(p_graphics : CanvasRenderingContext2D, p_image : ImageElement, w : Float, h:Float, p_slices:Array<Int>=null):Void
	{
		if (p_image == null) return;
		p_slices = p_slices == null ? [] : p_slices;
		var c  : CanvasElement = p_graphics.canvas;
		var iw : Float = p_image.naturalWidth;
		var ih : Float = p_image.naturalHeight;
		var w  : Float = c.width;
		var h  : Float = c.height;
		var l  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[0]);
		l = Mathf.Min(l, w/2);
		var r  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[1]);
		r = Mathf.Min(r, w/2);
		var t  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[2]);
		t = Mathf.Min(t, h/2);
		var b  : Float = p_slices.length <= 0 ? 0 : (p_slices.length <= 1 ? p_slices[0] : p_slices[3]);
		b = Mathf.Min(b, h/2);
		var ix0 : Float = 0; 						var iy0 : Float = 0; 					var iw0 : Float = l; 						 var ih0 : Float = t;
		var ix1 : Float = l; 						var iy1 : Float = 0; 					var iw1 : Float = Math.max(1, iw - l - r);   var ih1 : Float = t;
		var ix2 : Float = Math.max(1, iw - r);	 	var iy2 : Float = 0; 					var iw2 : Float = r; 						 var ih2 : Float = t;
		var ix3 : Float = 0; 						var iy3 : Float = t; 					var iw3 : Float = l; 						 var ih3 : Float = Math.max(1, ih - t - b);
		var ix4 : Float = l; 						var iy4 : Float = t; 					var iw4 : Float = Math.max(1, iw - l - r);   var ih4 : Float = Math.max(1, ih - t - b);
		var ix5 : Float = Math.max(1, iw - r);	 	var iy5 : Float = t; 					var iw5 : Float = r; 						 var ih5 : Float = Math.max(1, ih - t - b);
		var ix6 : Float = 0; 						var iy6 : Float = Math.max(1, ih - b);  var iw6 : Float = l; 						 var ih6 : Float = b;
		var ix7 : Float = l; 						var iy7 : Float = Math.max(1, ih - b);  var iw7 : Float = Math.max(1, iw - l - r);   var ih7 : Float = b;
		var ix8 : Float = Math.max(1, iw - r);	 	var iy8 : Float = Math.max(1, ih - b);  var iw8 : Float = r; 						 var ih8 : Float = b;
		
		var x0 : Float = 0; 						var y0 : Float = 0; 					var w0 : Float = l; 						 var h0 : Float = t;
		var x1 : Float = l; 						var y1 : Float = 0; 					var w1 : Float = Math.max(0, w - l - r);     var h1 : Float = t;
		var x2 : Float = Math.max(0, w - r);	 	var y2 : Float = 0; 					var w2 : Float = r; 						 var h2 : Float = t;
		var x3 : Float = 0; 						var y3 : Float = t; 					var w3 : Float = l; 						 var h3 : Float = Math.max(0, h - t - b);
		var x4 : Float = l; 						var y4 : Float = t; 					var w4 : Float = Math.max(0, w - l - r);     var h4 : Float = Math.max(0, h - t - b);
		var x5 : Float = Math.max(0, w - r);	 	var y5 : Float = t; 					var w5 : Float = r; 						 var h5 : Float = Math.max(0, h - t - b);
		var x6 : Float = 0; 						var y6 : Float = Math.max(0, h - b);    var w6 : Float = l; 						 var h6 : Float = b;
		var x7 : Float = l; 						var y7 : Float = Math.max(0, h - b);    var w7 : Float = Math.max(0, w - l - r);     var h7 : Float = b;
		var x8 : Float = Math.max(0, w - r);	 	var y8 : Float = Math.max(0, h - b);    var w8 : Float = r; 						 var h8 : Float = b;
		
		
		if (l > 0) if (t > 0) 	p_graphics.drawImage(p_image, ix0  , iy0 , iw0  , ih0  , x0  , y0  , w0  , h0);
		if (t > 0) 				p_graphics.drawImage(p_image, ix1  , iy1 , iw1  , ih1  , x1  , y1  , w1  , h1);
		if (r > 0) if (t > 0) 	p_graphics.drawImage(p_image, ix2  , iy2 , iw2  , ih2  , x2  , y2  , w2  , h2);
		if (l > 0) 				p_graphics.drawImage(p_image, ix3  , iy3 , iw3  , ih3  , x3  , y3  , w3  , h3);
								p_graphics.drawImage(p_image, ix4  , iy4 , iw4  , ih4  , x4  , y4  , w4  , h4);
		if (r > 0) 				p_graphics.drawImage(p_image, ix5  , iy5 , iw5  , ih5  , x5  , y5  , w5  , h5);		
		if (l > 0) if (b > 0) 	p_graphics.drawImage(p_image, ix6  , iy6 , iw6  , ih6  , x6  , y6  , w6  , h6);
		if (b > 0) 				p_graphics.drawImage(p_image, ix7  , iy7 , iw7  , ih7  , x7  , y7  , w7  , h7);
		if (r > 0) if (b > 0) 	p_graphics.drawImage(p_image, ix8  , iy8 , iw8  , ih8  , x8  , y8  , w8  , h8);
	}
}