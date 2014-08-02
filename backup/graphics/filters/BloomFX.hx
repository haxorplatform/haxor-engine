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
class BloomFX extends RenderFX
{

	public var factor(get_factor, set_factor):Float;
	private function set_factor(v:Float):Float { m_factor = v; SetUniform("Factor", v); return v; }
	private function get_factor():Float { return m_factor; }
	private var m_factor : Float;
	
	public var iterations(get_iterations, set_iterations):Int;
	private function set_iterations(v:Int):Int { m_blur.iterations = v; return v; }
	private function get_iterations():Int { return m_blur.iterations; }
		
	private var m_blur : BlurFX;
	
	private var m_b0 : RenderTexture;
	
	function new(p_iterations : Int=3,p_factor : Float=0.3) 
	{
		super();							
		m_blur = new BlurFX();
		iterations = 6;
		factor = 0.5;	
	}
	
	override public function OnRender(p_source : RenderTexture, p_destination : RenderTexture):Void
	{
		if (shader == null) { shader = Asset.Get("haxor/filter/Bloom"); }
		if (shader == null) return;
		
		if (m_b0 == null)
		{
			m_b0 = new RenderTexture(p_source.width, p_source.height, TextureFormat.RGBA8);
			m_b0.name = "B0";
			SetUniform("Blur", m_b0);
		}
		
		m_blur.OnRender(p_source, m_b0);
		
		Graphics.Blit(p_source, p_destination,this);		
	}
}