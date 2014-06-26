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
class FXAA extends RenderFX
{
	
	public var iterations : Int;
	
	function new() 
	{
		super();				
		iterations = 2;
	}
	
	override public function OnRender(p_source : RenderTexture, p_destination : RenderTexture):Void
	{
		if (shader == null) { shader = Asset.Get("haxor/filter/FXAA"); }
		if (shader == null) return;
		SetUniform("width", p_source.width+0.00001);
		SetUniform("height", p_source.height + 0.00001);
		for (i in 0...iterations)
		{
			Graphics.Blit(p_source, p_destination, this);
			Graphics.Blit(p_destination, p_source, this);
		}		
	}
}