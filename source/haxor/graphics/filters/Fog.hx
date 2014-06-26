/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.graphics.filters;
import haxe.io.Path;
import haxor.component.Camera;
import haxor.core.Asset;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.math.Color;
import haxor.texture.RenderTexture;
import haxor.texture.Texture.TextureFormat;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Fog extends RenderFX
{

	public var color : Color;
	
	public var exp : Float;
	
	public var factor : Float;
	
	function new() 
	{
		super();							
		color 	= new Color(0.0, 0.0, 0.0, 1.0);
		exp 	= 1.0;
		factor  = 1.0;
	}
	
	override public function OnRender(p_source : RenderTexture, p_destination : RenderTexture):Void
	{		
		if (shader == null) { shader = Asset.Get("haxor/filter/Fog"); return; }
		SetUniform("Depth", depth);
		SetUniform("Color", color);
		SetUniform("Exp",    exp + 0.0001);		
		SetUniform("Factor", factor + 0.0001);		
		SetUniform("Near", Camera.current.near+0.00001);
		SetUniform("Far", Camera.current.far+0.00001);
		Graphics.Blit(p_source, p_destination,this);
	}
}