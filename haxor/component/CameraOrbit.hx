package haxor.component;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Enums.InputState;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;


/**
 * ...
 * @author Eduardo Pons
 */
class CameraOrbit extends Behaviour implements IUpdateable
{
	static public function Create(p_distance:Float32=1,p_angle_x:Float32=0,p_angle_y:Float32=0) : CameraOrbit
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
			m_pivot.name = entity.name;
			m_pivot.parent = entity.transform.parent;		
			entity.transform.parent = m_pivot;
			entity.name = "camera";
			m_pivot.position = entity.transform.position;
		}
		return m_pivot; 
	}
	var m_pivot : Transform;
	
	public var distance : Float32;
	
	public var angle : Vector2;
	
	public var smooth : Float32;
	
	public var target : Transform;
	
	public var follow : Bool;
	
	var m_angle:Vector2;
	
	var m_distance:Float32;
	
	var m_rotation : Quaternion;
	
	override function OnBuild():Void 
	{
		super.OnBuild();
		distance = 0.0;		
		m_pivot	= pivot;
		follow = false;
	}
	
	
	override public function OnStart():Void 
	{
		m_distance 	= distance;
		m_angle 	= angle == null ? Vector2.zero : angle.clone;
        m_rotation 	= Quaternion.identity;
		
		var p : Vector3 = Vector3.temp;
		p.Set(0, 0, m_distance);
		entity.transform.localPosition = p;
		
	}
	
	public function OnUpdate():Void
	{
		var blend : Float32 = smooth <= 0 ? 1.0 : (Time.delta * smooth);
		m_angle.x = Mathf.Lerp(m_angle.x, angle.x, blend);
		m_angle.y = Mathf.Lerp(m_angle.y, angle.y, blend);
		m_distance = Mathf.Lerp(m_distance, distance, blend);	
		
		var q : Quaternion = Quaternion.temp;
		q.SetAxisAngle(Vector3.up, m_angle.x);
        q.Multiply(Quaternion.temp.SetAxisAngle(Vector3.right, -m_angle.y));
        pivot.localRotation = q;
		
		var p : Vector3 = Vector3.temp;
		p.Set(0, 0, m_distance);
		entity.transform.localPosition = p;
		
		if (target != null)
		{
			if (follow)
			{				
				var p : Vector3 = pivot.localPosition;
				p = Vector3.Lerp(p, target.localPosition, Time.delta * smooth);
				pivot.localPosition = p;
			}
		}
	}
	
}


class CameraOrbitInput extends Behaviour implements IUpdateable
{
	public var rotate 		: Bool = true;	
	public var zoom 		: Bool = true;		
	public var zoomSpeed 	: Float32 = 0.5;	
	public var rotateSpeed 	: Float32 = 0.5;
	
	private var m_orbit : CameraOrbit;
	
	override public function OnStart():Void 
	{
		m_orbit = GetComponent(CameraOrbit);
	}
	
	public function OnUpdate():Void
	{		
		var dx : Float32 = (Input.touches.length == 1) ? Input.touches[0].delta.x : Input.deltaMouse.x;
		var dy : Float32 = (Input.touches.length == 1) ? Input.touches[0].delta.y : Input.deltaMouse.y;
		
		if (rotate)
		{
			
			var is_rotate : Bool = Input.Pressed(KeyCode.Mouse0) || (Input.touches.length == 1);
			
			if (is_rotate)
			{
				m_orbit.angle.x += -dx * rotateSpeed;
				m_orbit.angle.y +=  dy * rotateSpeed;
			}
		}
		
		if (zoom)
		{
			if (Math.abs(Input.wheel) > 0)
			{
				m_orbit.distance += (Input.wheel < 0 ? zoomSpeed : -zoomSpeed);
			}
			
			if (Input.touches.length == 2)
			{
				m_orbit.distance += (Input.touches[0].delta.y * zoomSpeed * 0.05);
			}
		}
		
		
	}

}
//*/