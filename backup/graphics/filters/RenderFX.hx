/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics.filters;
import haxor.graphics.Material;
import haxor.texture.RenderTexture;
import haxor.texture.Texture2D;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class RenderFX extends Material
{
	public var enabled : Bool;
	
	public var depth : Texture2D;

	function new() 
	{
		super();
		enabled = true;
	}
	
	public function OnRender(p_source : RenderTexture, p_destination : RenderTexture):Void
	{
		
	}
}