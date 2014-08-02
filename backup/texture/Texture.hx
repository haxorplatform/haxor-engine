/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.texture;
import js.html.Uint8Array;
import js.html.Uint8ClampedArray;
import haxor.api.TextureAPI;
import haxor.core.Resource;
import haxor.graphics.Graphics;
import haxor.math.Color;
import haxor.math.Mathf;

/**
 * 
 */
enum TextureFilter
{            
	Nearest; 			   
	Linear; 				 	          
	NearestMipmapNearest;
	NearestMipmapLinear;             
	LinearMipmapNearest;             
	LinearMipmapLinear;               
	Trilinear; 			 	
}


class TextureWrap
{   
	static public var ClampX  = 1;
	static public var RepeatX = 2;            
	static public var ClampY  = 4;           
	static public var RepeatY = 8;
	static public var ClampZ  = 16;          
	static public var RepeatZ = 32;
}

enum TextureFormat
{
	Alpha8;
	Luminance; //RGBA == L
	//Alpha16;
	RGB8;
	RGBA8;
	//RGBA16;
	Half;
	Half3;
	Half4;
	Float;
	Float3;
	Float4;
	Depth;
}


/**
 * 
 */
@:allow(haxor)
class Texture extends Resource
{
	/**
	 * 
	 * @param	p_bytes
	 * @param	p_channels
	 * @param	p_format
	 * @return
	 */
	static public function DecodePixels(p_bytes : Uint8ClampedArray, p_channels : Int,p_format : TextureFormat) : Array<Color>
	{
		
		var cc : Int = p_channels;		
		var p:Int = 0;
		var b : Uint8ClampedArray = p_bytes;
		var res:Array<Color> = [];
		while (p < p_bytes.length)
		{
			var v0 : Int = b[p];
			var v1 : Int = cc > 1 ? b[p+1] : 0;
			var v2 : Int = cc > 2 ? b[p+2] : 0;
			var v3 : Int = cc > 3 ? b[p+3] : 0;
			var c : Color = DecodePixel([v0, v1, v2, v3], cc, p_format);			
			res.push(c);
			p += cc;
		}		
		return res;
	}
	
	/**
	 * 
	 * @param	p_bytes
	 * @param	p_channels
	 * @param	p_format
	 * @return
	 */
	static public function DecodePixel(p_bytes : Array<Int>, p_channels : Int, p_format : TextureFormat) : Color
	{
		var v0 : Float = p_bytes[0];
		var v1 : Float = p_channels > 1 ? p_bytes[1] : 0;
		var v2 : Float = p_channels > 2 ? p_bytes[2] : 0;
		var v3 : Float = p_channels > 3 ? p_bytes[3] : 0;
		
		var c : Color = new Color();		
		if (p_format == TextureFormat.Alpha8)  { c.r = c.g = c.b = 0.0; c.a = v0 / 255.0; }
		else
		{
			if (p_format == TextureFormat.Luminance)  { c.r = c.g = c.b = v0 / 255.0; c.a = 1.0; }
			else
			{
				c.r = v0 / 255.0;
				c.g = v1 / 255.0;
				c.b = v2 / 255.0;
				c.a = p_channels <= 3 ?  1.0 : (v3 / 255.0);				
			}
		}		
		return c;
	}
	
	/**
	 * 
	 * @param	p_pixels
	 * @param	p_format
	 * @return
	 */
	static public function EncodePixels(p_pixels : Array<Color>, p_format : TextureFormat) : Uint8ClampedArray
	{
		var res : Array<Int> = [];
		for (i in 0...p_pixels.length)
		{
			var c : Color = p_pixels[i];
			var pix : Uint8Array = EncodePixel(c, p_format);
			for (j in 0...pix.length) res.push(pix[j]);
		}
		return new Uint8ClampedArray(res);
	}
	
	/**
	 * 
	 * @param	p_bytes
	 * @param	p_channels
	 * @param	p_format
	 * @return
	 */
	static public function EncodePixel(p_pixel : Color, p_format : TextureFormat) : Uint8ClampedArray
	{
		var v0 : Int = Math.round(Mathf.Clamp01(p_pixel.r) * 255.0);
		var v1 : Int = Math.round(Mathf.Clamp01(p_pixel.g) * 255.0);
		var v2 : Int = Math.round(Mathf.Clamp01(p_pixel.b) * 255.0);
		var v3 : Int = Math.round(Mathf.Clamp01(p_pixel.a) * 255.0);
		
		switch(p_format)
		{
			case TextureFormat.Luminance: 	return new Uint8ClampedArray([v0, v1, v2, 255]);			
			case TextureFormat.Float,
				 TextureFormat.Half,
				 TextureFormat.Alpha8:  	return new Uint8ClampedArray([v3]);			
			case TextureFormat.RGB8:		return new Uint8ClampedArray([v0, v1, v2]);
			case TextureFormat.RGBA8:		return new Uint8ClampedArray([v0, v1, v2, v3]);
			case TextureFormat.Float3:		return new Uint8ClampedArray([v0, v1, v2]);
			case TextureFormat.Float4:		return new Uint8ClampedArray([v0, v1, v2, v3]);
			case TextureFormat.Half3:		return new Uint8ClampedArray([v0, v1, v2]);
			case TextureFormat.Half4:		return new Uint8ClampedArray([v0, v1, v2, v3]);
			case TextureFormat.Depth:		return new Uint8ClampedArray([0,0,0,0]);
		}		
		return new Uint8ClampedArray([0,0,0,0]);
	}
		
	/**
	 * 
	 */
	public var data(get_data, never):Dynamic;
	public function get_data():Dynamic { return m_data; }
	private var m_data : Dynamic;
	
	/**
	 * 
	 */
	public var width(get_width, never):Int;
	private var m_width:Int;
	function get_width():Int { return m_width; }
	
	/**
	 * 
	 */
	public var height(get_height, never):Int;
	private var m_height:Int;
	function get_height():Int { return m_height; }
	
	/**
	 * 
	 */
	public var html(get_html, never):Bool;
	private var m_html:Bool;
	function get_html():Bool { return m_html; }
	
	/**
	 * 
	 */
	public var format(get_format, never):TextureFormat;
	private var m_format:TextureFormat;
	function get_format():TextureFormat { return m_format; }
	
	/**
	 * 
	 */
	public var wrap(get_wrap, set_wrap):Int;	
	private function get_wrap():Int { return m_wrap; }
	private function set_wrap(v:Int):Int { m_wrap = v;  TextureAPI.SetParameters(this); return m_wrap; }
	private var m_wrap:Int;
	
	/**
	 * 
	 */
	public var aniso(get_aniso, set_aniso):Int;	
	private function get_aniso():Int { return m_aniso; }
	private function set_aniso(v:Int):Int { m_wrap = v;  TextureAPI.SetParameters(this); return m_aniso; }
	private var m_aniso:Int;
	
	
	/**
	 * 
	 */
	public var minFilter(get_minFilter, set_minFilter):TextureFilter;	
	private function get_minFilter():TextureFilter { return m_minFilter; }
	private function set_minFilter(v:TextureFilter) : TextureFilter { m_minFilter = v; TextureAPI.SetParameters(this); return m_minFilter; }
	private var m_minFilter:TextureFilter;
	
	/**
	 * 
	 */
	public var magFilter(get_magFilter, set_magFilter):TextureFilter;	
	private function get_magFilter():TextureFilter { return m_magFilter; }
	private function set_magFilter(v:TextureFilter) : TextureFilter { m_magFilter = v; TextureAPI.SetParameters(this); return m_magFilter; }
	private var m_magFilter:TextureFilter;	
	
	/**
	 * 
	 */
	public var gid(get_gid, never) : js.html.webgl.Texture;
	function get_gid(): js.html.webgl.Texture { return m_gid; }
	private var m_gid : js.html.webgl.Texture;
	
	/**
	 * 
	 */
	public var type(get_type, never) : Int;
	function get_type(): Int { return m_type; }
	private var m_type : Int;
	
	/**
	 * 
	 */
	public var mipmaps(get_mipmaps, never):Bool;
	function get_mipmaps():Bool { return m_mipmaps; }
	private var m_mipmaps:Bool;
	
	/**
	 * 
	 */
	private function new() 
	{
		super();
		m_data = null;
		m_mipmaps = false;
		m_format = TextureFormat.RGBA8;
		m_minFilter = TextureFilter.Linear;
		m_magFilter = TextureFilter.Linear;
		m_wrap = TextureWrap.ClampX | TextureWrap.ClampY | TextureWrap.ClampZ;
		m_width = m_height = 0;		
		m_gid = null;
		m_type = 0;
		m_aniso = 0;
		m_html = false;		
	}
	
	/**
	 * 
	 */
	public function Apply():Void
	{
		//if (!Mathf.IsPow2(m_width))  { trace("Haxor> Texture " + Name + " not POT!"); return; }
		//if (!Mathf.IsPow2(m_height)) { trace("Haxor> Texture " + Name + " not POT!"); return; }
		TextureAPI.Apply(this);
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();	
		TextureAPI.Destroy(this);
	}
	
	public function BuildMipmaps():Void { TextureAPI.BuildMipmaps(this); m_mipmaps = true; }
	
	public function OnBind() : Void { }
	
}
