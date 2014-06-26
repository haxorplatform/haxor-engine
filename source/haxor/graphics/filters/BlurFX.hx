/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.graphics.filters;
import haxe.io.Path;
import haxor.core.Asset;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.texture.RenderTexture;
import haxor.texture.Texture.TextureFormat;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class BlurFX extends RenderFX
{

	public var iterations : Int;
	
	public var strength : Float;
	
	
	var m_b0 : RenderTexture;
	var m_b1 : RenderTexture;
	
	function new() 
	{
		super();				
		iterations = 0;
		strength   = 0.0;
	}
	
	override public function OnRender(p_source : RenderTexture, p_destination : RenderTexture):Void
	{
		if (shader == null) { shader = Asset.Get("haxor/filter/Blur"); }
		if (shader == null) return;
		
		if (iterations <= 0) { iterations = 0; Graphics.Blit(p_source, p_destination);  return; }
		
		SetUniform("Strength", strength + 0.00001);
		
		if (m_b0 == null)
		{		
			m_b0 = new RenderTexture(p_source.width, p_source.height, TextureFormat.RGBA8);
			m_b0.name = "B0";
			m_b1 = new RenderTexture(p_source.width, p_source.height, TextureFormat.RGBA8);
			m_b1.name = "B1";
		}
		
		var last : RenderTexture = m_b0;
		
		Graphics.Blit(p_source, m_b0, this);
		for (i in 0...(iterations-1))
		{
			var tmp : RenderTexture = m_b0;
			m_b0 = m_b1;
			m_b1 = tmp;
			Graphics.Blit(m_b1, m_b0, this);
			last = m_b0;			
		}
		Graphics.Blit(last, p_destination);
		
	}
}