/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

 
package haxor.component;
import haxor.core.Entity;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;

/**
 * ...
 * @author Eduardo Pons
 */
class CameraOrbit extends Behaviour implements IUpdateable
{
	static public function Create(p_distance:Float=1,p_angle_x:Float=0,p_angle_y:Float=0) : CameraOrbit
	{
		var e : Entity = new Entity();		
		e.name = "camera_orbit";		
		var c : Camera = cast e.AddComponent(Camera);		
		c.background = Color.black;				
		var orbit : CameraOrbit = cast e.AddComponent(CameraOrbit);		
		orbit.distance = p_distance;
		orbit.smooth = 0;
		orbit.angle = new Vector2(p_angle_x, p_angle_y);
		return orbit;
	}
	
	public var pivot(get_pivot, never):Transform;
	private function get_pivot():Transform 
	{
		if (m_pivot == null)
		{
			var e :Entity = new Entity();		
			m_pivot = e.transform;
			m_pivot.name = "camera_orbit";
			m_pivot.parent = entity.transform.parent;		
			entity.transform.parent = m_pivot;
			m_pivot.position = entity.transform.position;
		}
		return m_pivot; 
	}
	var m_pivot : Transform;
	
	public var distance : Float;
	
	public var angle : Vector2;
	
	public var smooth : Float;
	
	public var target : Transform;
	
	var m_angle:Vector2;
	
	var m_distance:Float;
	
	var m_rotation : Quaternion;
	
	override public function OnAwake():Void 
	{
		m_pivot		= pivot;
	}
	
	override public function OnStart():Void 
	{
		m_distance 	= distance == null ? 1.0 : distance;
		m_angle 	= angle == null ? Vector2.zero : angle.clone;
        m_rotation 	= Quaternion.identity;
	}
	
	public function OnUpdate():Void
	{
		var blend : Float = smooth <= 0 ? 1.0 : (Time.frameDeltaTime * smooth);
		m_angle.x = Mathf.Lerp(m_angle.x, angle.x, blend);
		m_angle.y = Mathf.Lerp(m_angle.y, angle.y, blend);
		m_distance = Mathf.Lerp(m_distance, distance, blend);	
		var p : Vector3 = Vector3.temp;
		p.Set(0, 0, m_distance);
		entity.transform.position = p;
		var q : Quaternion = Quaternion.temp;
		q.SetAxisAngle(Vector3.up, m_angle.x);
        q.Multiply(Quaternion.temp.SetAxisAngle(Vector3.right, m_angle.y));
        pivot.rotation = q;
		
		if (target != null)
		{
			var p : Vector3 = pivot.position;
			p = Vector3.Lerp(p, target.position, Time.deltaTime * smooth);
			pivot.position = p;
		}
	}
	
}

class CameraOrbitInput extends Behaviour implements IUpdateable
{
	public var rotate 		: Bool = true;	
	public var zoom 		: Bool = true;		
	public var zoomSpeed 	: Float = 2.0;	
	public var rotateSpeed 	: Float = 0.8;
	
	private var m_orbit : CameraOrbit;
	
	override public function OnStart():Void 
	{
		m_orbit = GetComponent(CameraOrbit);
	}
	
	public function OnUpdate():Void
	{
		var dx : Float = (Input.touch.length == 1) ? Input.touch[0].delta.x : Input.deltaMouse.x;
		var dy : Float = (Input.touch.length == 1) ? Input.touch[0].delta.y : Input.deltaMouse.y;
		
		
		
		if (rotate)
		{
			var is_rotate : Bool = (Input.GetInputState(KeyCode.Mouse0) == InputState.Hold) || (Input.touch.length == 1);
			if (is_rotate)
			{
				m_orbit.angle.x += -dx * rotateSpeed;
				m_orbit.angle.y += -dy * rotateSpeed;
			}
		}
		
		if (zoom)
		{
			if (Math.abs(Input.wheel) > 0)
			{
				m_orbit.distance += Input.wheel < 0 ? zoomSpeed : -zoomSpeed;
			}
			
			if (Input.touch.length == 2)
			{
				m_orbit.distance -= Input.touch[0].delta.y * zoomSpeed * 0.05;
			}
		}
		
		/*
		|| (Input.touch.length == 1)
		if (Input.touch.length == 1)
		{
			dx = Input.touch[0].delta.x;
			dy = Input.touch[0].delta.y;
		}
		//*/
	}

}