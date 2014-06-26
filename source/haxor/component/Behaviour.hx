/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.component;
import haxor.core.Entity;
import haxor.core.Engine;
import haxor.core.Resource;

/**
 * ...
 * @author Eduardo Pons
 */
class Behaviour extends Component
{
	
	
	/**
	 * 
	 */
	public var enabled(get_enabled, set_enabled):Bool;
	var m_enabled : Bool;	
	function get_enabled():Bool { return m_enabled; }
	function set_enabled(v:Bool):Bool { m_enabled = v; CheckEnabled(); return v; }

	function new(p_entity:Entity) 
	{
		super(p_entity);		
		enabled = true;
		Engine.AddAwakeBehaviour(this);
		Engine.AddStartBehaviour(this);
		OnBuild();
	}
	
	/**
	 * 
	 */
	public function OnBuild() : Void { }
	
	/**
	 * 
	 */
	public function OnAwake() : Void { }
	
	/**
	 * 
	 */
	public function OnStart() : Void { }
	
	function CheckEnabled():Void 
	{
		if (m_enabled && entity.enabled) Engine.EnableBehaviour(this) else Engine.DisableBehaviour(this);		
	}
}