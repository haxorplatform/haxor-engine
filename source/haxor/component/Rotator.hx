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
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.Material;
import haxor.math.Quaternion;
import haxor.math.Vector3;

/**
 * ...
 * @author Eduardo Pons
 */
class Rotator extends Behaviour implements IUpdateable
{
	public var speed : Float;
	
	public var orient : Quaternion;
	
	override public function OnBuild():Void 
	{
		super.OnStart();
		speed = 45;		
		orient = transform.rotation.clone;
		orient = Quaternion.identity;
	}
	
	public function OnUpdate() : Void 
	{
		var q : Quaternion = Quaternion.FromAxisAngle(Vector3.forward, Time.elapsed * speed);
		transform.rotation = q.Multiply(orient);
	}
	
}