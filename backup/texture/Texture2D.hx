/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.texture;

import js.html.ArrayBufferView;
import js.html.Float32Array;
import js.html.Uint8ClampedArray;
import haxor.api.TextureAPI;
import haxor.math.Color;
import haxor.texture.Texture;

import js.html.Uint8Array;


/**
 * ...
 * @author Eduardo Pons
 */
class Texture2D extends Texture
{	
	/**
	 * 
	 */
	static public var white(get_white, never):Texture2D;
	static private function get_white():Texture2D
	{
		if (m_white != null) return m_white;
		m_white = new Texture2D(1, 1, TextureFormat.RGB8);
		m_white.Fill(Color.white);
		m_white.Apply();
		return m_white;
	}
	static private var m_white : Texture2D;
	
	/**
	 * 
	 */
	static public var red(get_red, never):Texture2D;
	static private function get_red():Texture2D
	{
		if (m_red != null) return m_red;
		m_red = new Texture2D(1, 1, TextureFormat.RGB8);
		m_red.Fill(Color.red);
		m_red.Apply();
		return m_red;
	}
	static private var m_red : Texture2D;
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_data
	 * @return
	 */
	static public function FromByteArray(p_width : Int, p_height : Int,p_format : TextureFormat,p_channel : Int, p_data : Uint8ClampedArray,p_mipmaps:Bool=false,p_reverse_y : Bool=false):Texture2D
	{
		var tex : Texture2D = new Texture2D(p_width, p_height, p_format,p_mipmaps);		
		var c : Array<Color> = Texture.DecodePixels(p_data, p_channel, p_format);
		var p : Int = 0;
		for (py in 0...p_height)
		for (px in 0...p_width)
		{
			tex.SetPixel(px,p_reverse_y ? ((p_height - 1) - py) : py, c[p++]);
		}
		tex.Apply();
		return tex;
	}
	
	/**
	 * 
	 */
	public var channels(get_channels, never):Int;
	function get_channels():Int
	{
		var cc : Int = 1;
		switch(m_format)
		{
			case TextureFormat.Alpha8: 		cc = 1;
			case TextureFormat.Depth: 		cc = 1;
			case TextureFormat.Half:		cc = 1;
			case TextureFormat.Half3:		cc = 3;
			case TextureFormat.Half4:		cc = 4;
			case TextureFormat.Float: 		cc = 1;
			case TextureFormat.Float3:		cc = 3;
			case TextureFormat.Float4:		cc = 4;
			case TextureFormat.Luminance: 	cc = 3;
			case TextureFormat.RGB8: 		cc = 3;
			case TextureFormat.RGBA8: 		cc = 4;
		}
		return cc;
	}
	
	
	
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : TextureFormat,p_mipmaps:Bool=false) 
	{
		super();
		m_mipmaps = p_mipmaps;
		m_width  = p_width;
		m_height = p_height;
		m_format = p_format;
		
		var cc:Int = channels;
		var len:Int = p_width * p_height * cc;		
		
		if ((p_format == TextureFormat.Float) || (p_format == TextureFormat.Float3) || (p_format == TextureFormat.Float4))
		{
			var tmp : Array<Float> = [];
			for (i in 0...len) tmp.push(0.0);
			m_data = new Float32Array(tmp);			
		}
		else
		{
			var tmp : Array<Int> = [];
			for (i in 0...len) tmp.push(255);
			m_data = new Uint8Array(tmp);
		}		
		Apply();
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_color
	 */
	public function GetPixel(p_x : Int, p_y :Int):Color
	{
		var c : Color = new Color();
		if (p_x >= m_width)  return c;
		if (p_x <  0) 		 return c;	
		if (p_y >= m_height) return c;
		if (p_y <  0) 		 return c;		
		var cc:Int = channels;
		var pos:Int = (p_x + (p_y * m_width)) * cc;	
		if (m_format == TextureFormat.Float)
		{
			var d : Float32Array = m_data;
			c.r = d[pos];
			c.g = d[pos];
			c.b = d[pos];
			c.a = 1.0;
			return c;
		}	
		
		if (m_format == TextureFormat.Float3)
		{
			var d : Float32Array = m_data;
			c.r = d[pos];
			c.g = d[pos+1];
			c.b = d[pos+2];
			c.a = 1.0;
			return c;
		}	
		
		if (m_format == TextureFormat.Float4)
		{
			var d : Float32Array = m_data;
			c.r = d[pos];
			c.g = d[pos+1];
			c.b = d[pos+2];
			c.a = d[pos+3];
			return c;
		}	
		
		var d : Uint8Array = m_data;
		var pix : Array<Int> = [];
		for (i in 0...cc) pix.push(d[pos + i]);		
		c = Texture.DecodePixel(pix, cc, m_format);
		return c;
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_color
	 */
	public function SetPixel(p_x : Int, p_y :Int, p_color : Color):Void
	{
		if (p_x >= m_width) return;
		if (p_x <  0) 		return;		
		if (p_y >= m_height) return;
		if (p_y <  0) 		 return;		
		var cc:Int = channels;
		var pos:Int = (p_x + (p_y * m_width)) * cc;		
		
		if (m_format == TextureFormat.Float)
		{
			var d : Float32Array = m_data;
			d[pos] = p_color.r;			
			return;
		}
		
		if (m_format == TextureFormat.Float3)
		{
			var d : Float32Array = m_data;
			d[pos] = p_color.r;
			d[pos+1] = p_color.g;
			d[pos + 2] = p_color.b;			
			return;
		}
		
		if (m_format == TextureFormat.Float4)
		{
			var d : Float32Array = m_data;
			d[pos] = p_color.r;
			d[pos+1] = p_color.g;
			d[pos+2] = p_color.b;
			d[pos+3] = p_color.a;
			return;
		}
		
		var db : Uint8Array = m_data;
		var pix : Uint8ClampedArray = Texture.EncodePixel(p_color, m_format);
		for (i in 0...pix.length) db[pos + i] = pix[i];		
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @return
	 */
	public function GetPixelsRect(p_x : Int, p_y :Int, p_width : Int, p_height : Int):Array<Color>
	{
		var res : Array<Color> = [];
		var cc:Int = channels;
		var pix : Int = 0;
		for (py in p_y...(p_y + p_height))
		{
			for (px in p_x...(p_x + p_width))
			{
				res.push(GetPixel(px, py));
			}			
		}
		return res;
	}
	
	/**
	 * 
	 * @return
	 */
	public function GetPixels():Array<Color>
	{
		return GetPixelsRect(0, 0, m_width, m_height);
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_color
	 */
	public function SetPixelsRect(p_x : Int, p_y :Int, p_width : Int, p_height : Int, p_color : Array<Color>):Void
	{		
		var cc:Int = channels;
		var pix : Int = 0;
		for (py in p_y...(p_y + p_height))
		{
			if (py >= m_height) break;
			if (py <  0) 		continue;
			
			for (px in p_x...(p_x + p_width))
			{
				if (px >= m_width) { pix++;  break; }
				if (px <  0) 	   { pix++;  continue;	}
				var pos:Int = (px + (py * m_width)) * cc;
				SetPixel(px, py, p_color[pix]);
				pix++;
			}
			
		}
	}
	
	/**
	 * 
	 * @param	p_color
	 */
	public function SetPixels(p_color : Array<Color>):Void
	{
		SetPixelsRect(0, 0, m_width, m_height, p_color);
	}
	
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function FillRect(p_color : Color,p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void
	{
		var cl : Array<Color> = [];
		for (i in 0...(p_width * p_height)) cl.push(p_color);
		SetPixelsRect(p_x, p_y, p_width, p_height, cl);		
	}
	
	/**
	 * 
	 * @param	p_color
	 */
	public function Fill(p_color : Color):Void
	{
		FillRect(p_color, 0, 0, m_width, m_height);
	}
	
}