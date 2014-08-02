/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.physics;
import haxor.core.Resource;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class PhysicsMaterial extends Resource
{
	static public var empty(get_empty, never):PhysicsMaterial;
	static private var m_empty : PhysicsMaterial;
	static private function get_empty():PhysicsMaterial 
	{ 
		if (m_empty != null) return m_empty; 
		m_empty = new PhysicsMaterial();
		m_empty.name = "$DefaultPhysicsMaterial";
		return m_empty;
	}	
	
	
	public var bounce : Float;
	
	public var friction : Float;

	public function new() 
	{
		super();
		bounce   = 0.0;
		friction = 0.0;
	}
	
}