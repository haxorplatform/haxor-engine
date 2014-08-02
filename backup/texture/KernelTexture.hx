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
import haxor.core.Console;
import haxor.math.Color;
import haxor.texture.Texture;

import js.html.Uint8Array;


/**
 * ...
 * @author Eduardo Pons
 */
class KernelTexture extends Texture
{	
	
	private var m_buffer : ArrayBufferView;
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : TextureFormat) 
	{
		
		super();
		
		m_format = p_format;
		
		m_width  = p_width;
		m_height = p_height;
		
		m_minFilter = TextureFilter.Nearest;
		m_magFilter = TextureFilter.Nearest;
		
		var is_float : Bool = 
		(p_format == TextureFormat.Float)  ||
		(p_format == TextureFormat.Float3) ||
		(p_format == TextureFormat.Float4) ||
		(p_format == TextureFormat.Half)  ||
		(p_format == TextureFormat.Half3) ||
		(p_format == TextureFormat.Half4);
		
		m_buffer = is_float ? new Float32Array(4) : new Uint8Array(4);
		TextureAPI.Create(this);
	}
	
	public function Write(p_x : Int, p_y :Int, p_v0 : Dynamic=0, p_v1 : Dynamic=0, p_v2 : Dynamic=0, p_v3 : Dynamic=0):Void
	{
		var b : Dynamic = m_buffer;
		b[0] = p_v0;
		b[1] = p_v1;
		b[2] = p_v2;
		b[3] = p_v3;
		TextureAPI.WritePixels(this, p_x, p_y, m_buffer, 1, 1);
	}
	
	public function WriteRange(p_values : ArrayBufferView,p_x:Int=0, p_y:Int=0, p_width:Int=-1, p_height:Int=-1):Void
	{
		TextureAPI.WritePixels(this, p_x, p_y, p_values, p_width, p_height);
	}
	
}