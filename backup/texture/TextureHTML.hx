/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.texture;

import js.Browser;
import js.html.ImageElement;
import js.html.VideoElement;
import haxor.api.TextureAPI;
import haxor.core.Engine;
import haxor.texture.Texture;

import js.html.Element;
import js.html.Event;
import js.html.Image;

/**
 * ...
 * @author Eduardo Pons
 */
class TextureHTML extends Texture
{
	
	/**
	 * 
	 */
	public var video(get_video, null) : Bool;
	var m_video:Bool;
	function get_video():Bool { return m_video; }

	/**
	 * 
	 * @param	p_data
	 */
	public function new(p_element : Element)
	{	
		super();						
		
		m_video = false;
		m_html = true;
		
		if (p_element == null)
		{
			m_width  = 0;
			m_height = 0;
		}
		else
		if (Std.is(p_element, Image))
		{
			var d : Image = cast p_element;
			m_width  = d.naturalWidth;
			m_height = d.naturalHeight;
			
		}
		else
		if (Std.is(p_element, VideoElement))
		{
			m_video = true;
			var d : VideoElement = cast p_element;
			m_width  = d.videoWidth;
			m_height = d.videoHeight;
		}
		else
		{
			m_width  = p_element.clientWidth;
			m_height = p_element.clientHeight;
		}
		
		m_data 	 = p_element;		
		m_format = TextureFormat.RGBA8;		
		
		Apply();
	}
	
}