/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.component;
import haxor.core.Entity;
import haxor.core.IQueueRenderable;
import haxor.graphics.Material;

/**
 * ...
 * @author Eduardo Pons
 */
class Renderer extends Behaviour implements IQueueRenderable
{
	/**
	 * 
	 * @return
	 */
	public function GetQueue():Int { return material == null ? 9999 : material.queue; }
	
	/**
	 * 
	 */
	public var material : Material;
	
	function new(p_entity : Entity) 
	{
		super(p_entity);		
	}
	
	public function OnRender() : Void { }
	
}