package haxor.component;
import haxor.component.animation.KeyFrame.QuaternionKeyFrame;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Class that rotates the Transform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Rotator extends Behaviour implements IUpdateable
{

	/**
	 * Rotation Speed.
	 */
	@serialize
	public var speed : Vector3;	
	
	private var m_elapsed : Float32;
	
	override function OnBuild():Void 
	{
		super.OnBuild();		
		speed = new Vector3();
		m_elapsed = Time.elapsed;
	}
	
	public function OnUpdate():Void
	{
		var s : Vector3 = Vector3.temp.Set3(speed).Scale(Time.elapsed-m_elapsed);		
		var q : Quaternion = Quaternion.identity;
		q.Multiply(Quaternion.FromAxisAngle(Vector3.right,   s.x));
		q.Multiply(Quaternion.FromAxisAngle(Vector3.up,      s.y));
		q.Multiply(Quaternion.FromAxisAngle(Vector3.forward, s.z));
		transform.localRotation = q;
	}
	
	
}