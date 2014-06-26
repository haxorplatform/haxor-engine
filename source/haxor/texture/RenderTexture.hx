/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.texture;

import js.html.Uint8Array;
import js.html.webgl.Framebuffer;
import js.html.webgl.Renderbuffer;
import haxor.api.TextureAPI;
import haxor.texture.Texture;


/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class RenderTexture extends Texture
{
	
	private var m_rid : Renderbuffer;
	
	private var m_fid : Framebuffer;

	/**
	 * 
	 */
	public var depth(get_depth, never):Texture2D;
	function get_depth():Texture2D { return m_depth; }
	private var m_depth:Texture2D;
	
	
	
	public function new(p_width : Int,p_height : Int,p_format : TextureFormat,p_store_depth : Bool=false)
	{
		super();
		m_width  = Math.floor(p_width);
		m_height = Math.floor(p_height);
		m_format = p_format;
		
		if (p_store_depth && TextureAPI.TEXTURE_DEPTH) m_depth = new Texture2D(m_width, m_height, TextureFormat.Depth);
		TextureAPI.Create(this);
	}
	
}