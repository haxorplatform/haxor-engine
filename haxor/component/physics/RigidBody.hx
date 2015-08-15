package haxor.component.physics;
import haxor.context.EngineContext;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.Enums.ForceMode;
import haxor.core.IFixedUpdateable;
import haxor.core.Time;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.physics.Physics;
import haxor.platform.Types.Float32;



/**
 * Class that describes a RigidBody.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class RigidBody extends Behaviour
{
	
	/**
	 * 
	 */
	public var velocity(get_velocity,set_velocity) : Vector3;
	private function get_velocity():Vector3 { return Vector3.temp.Set(m_velocity.x, m_velocity.y, m_velocity.z); }
	private function set_velocity(v:Vector3):Vector3 
	{ 
		m_speed      = v.length;		
		var ispd : Float32 = m_speed <= 0.0 ? 0.0 : (1.0 / m_speed);
		m_velocity.Set3(v);
		m_direction.Set3(v).Scale(ispd);
		return v;
	}
	private var m_velocity : Vector3;
	private var m_direction : Vector3;
	private var m_dragForce : Vector3;
	private var m_speed : Float;
	
	/**
	 * 
	 */
	public var angularVelocity(get_angularVelocity,set_angularVelocity) : Vector3;
	private function get_angularVelocity():Vector3 { return Vector3.temp.Set(m_angularVelocity.x, m_angularVelocity.y, m_angularVelocity.z); }
	private function set_angularVelocity(v:Vector3):Vector3 
	{ 
		m_angularSpeed      = v.length;
		var ispd : Float32 = m_angularSpeed <= 0.0 ? 0.0 : (1.0 / m_angularSpeed);		
		m_angularVelocity.Set3(v);
		m_angularDirection.Set3(v).Scale(ispd);
		return v;
	}
	private var m_angularVelocity : Vector3;
	private var m_angularDirection : Vector3;
	private var m_dragTorque : Vector3;
	private var m_angularSpeed : Float32;
	
	/**
	 * 
	 */
	public var gravity : Bool;
	
	/**
	 * 
	 */
	public var drag(get_drag, set_drag) : Float32;
	private function get_drag():Float32 { return m_drag; }
	private function set_drag(v:Float32):Float32
	{
		m_drag = Mathf.Max(0,v);
		return m_drag;
	}
	private var m_drag : Float32;
	private var m_idrag : Float32;
	
	/**
	 * 
	 */
	public var angularDrag(get_angularDrag, set_angularDrag) : Float32;
	private function get_angularDrag():Float32 { return m_angularDrag; }
	private function set_angularDrag(v:Float32):Float32
	{
		m_angularDrag = Mathf.Max(0,v);		
		return m_angularDrag;
	}
	private var m_angularDrag : Float32;
	private var m_iangularDrag : Float32;
	
	/**
	 * 
	 */
	public var mass(get_mass, set_mass) : Float32;
	private function get_mass():Float32 { return m_mass; }
	private function set_mass(v:Float32):Float32
	{
		m_mass = Mathf.Max(0,v);
		m_imass = m_mass <= 0.0 ? 0.0 : (1.0 / m_mass);
		return m_mass;
	}
	private var m_mass : Float32;
	private var m_imass : Float32;
	
	/**
	 * 
	 */
	public var centerOfMass : Vector3;
	
	/**
	 * 
	 */
	public var kinematic : Bool;
	
	private var m_accel : Vector3;
	
	private var m_torque : Vector3;
	
	private var m_hasForce : Bool;
	
	private var m_hasTorque : Bool;
	
	private var m_avq : Quaternion;

	/**
	 * 
	 */
	override function OnBuild():Void 
	{
		
		m_velocity 	 = Vector3.zero;		
		m_dragForce  = Vector3.zero;
		m_direction  = Vector3.zero;
		m_speed      = 0.0;
		
		m_avq			   = new Quaternion();
		m_angularVelocity  = Vector3.zero;
		m_dragTorque	   = Vector3.zero;
		m_angularDirection = Vector3.zero;
		m_angularSpeed     = 0.0;
		
		m_accel  	 = Vector3.zero;
		m_torque	 = Vector3.zero;
		
		m_hasForce   = false;
		m_hasTorque  = false;
		
		kinematic = false;
		
		mass  	 	 = 1.0;
		drag     	 = 0.0;
		angularDrag  = 0.0;
		
		
		gravity  	 = true;
		
		centerOfMass 	= Vector3.zero;
		
		EngineContext.physics.CreateRigidBody(this);		
	}
	
	/**
	 * 
	 * @param	p_torque
	 * @param	p_mode
	 */
	public function AddTorque(p_torque : Vector3,p_mode : Int = -1):Void
	{
		var m : Int = p_mode < 0 ? ForceMode.Force : p_mode;
		var mdt : Float32   = 1.0;
		var dt  : Float32   = 1.0;// Time.fixedDeltaTime; 
		var v   : Vector3 = p_mode == ForceMode.Velocity ? angularVelocity : m_torque;
		switch(m)
		{
			case ForceMode.Velocity: 	 //mdt = dt;
			case ForceMode.Force: 		 mdt = m_imass;// * dt * dt;
			case ForceMode.Acceleration: //mdt = dt * dt;
			case ForceMode.Impulse:      mdt = m_imass;// * dt;
		}		
		v.x += p_torque.x * mdt;
		v.y += p_torque.y * mdt;
		v.z += p_torque.z * mdt;
		m_hasTorque = p_mode != ForceMode.Velocity;
	}
	
	/**
	 * 
	 * @param	p_force
	 * @param	p_mode
	 */
	public function AddForce(p_force : Vector3,p_mode : Int = -1):Void
	{
		var m : Int = p_mode < 0 ? ForceMode.Force : p_mode;
		var mdt : Float32   = 1.0;
		var dt  : Float32  = Time.fixedDelta; 
		var v   : Vector3 = p_mode == ForceMode.Velocity ? velocity : m_accel;
		switch(m)
		{
			case ForceMode.Velocity: 	 mdt = dt;
			case ForceMode.Force: 		 mdt = m_imass * dt * dt;
			case ForceMode.Acceleration: mdt = dt * dt;
			case ForceMode.Impulse:      mdt = m_imass * dt;
		}		
		v.x += p_force.x * mdt;
		v.y += p_force.y * mdt;
		v.z += p_force.z * mdt;
		
		if (p_mode == ForceMode.Velocity) velocity = v;
		
		m_hasForce = p_mode != ForceMode.Velocity;
	}
	
	override public function OnDestroy():Void 
	{
		//var cl : Array<Component> = entity.GetComponents(Collider);
		//for (i in 0...cl.length) { var c : Collider = cast cl[i]; c.m_rigidbody = null; }
	}
	
	private function ComputeForces():Void
	{
		if (gravity) AddForce(Physics.gravity, ForceMode.Velocity);
		
		if(drag > 0.0)
		if(m_speed > 0.0)
		{
			m_dragForce.x = -m_velocity.x * drag;
			m_dragForce.y = -m_velocity.y * drag;
			m_dragForce.z = -m_velocity.z * drag;
			if (Mathf.Abs(m_dragForce.x) >= Mathf.Epsilon) { m_accel.x += m_dragForce.x; m_hasForce = true; }
			if (Mathf.Abs(m_dragForce.y) >= Mathf.Epsilon) { m_accel.y += m_dragForce.y; m_hasForce = true; }
			if (Mathf.Abs(m_dragForce.z) >= Mathf.Epsilon) { m_accel.z += m_dragForce.z; m_hasForce = true; }
		}
		
		if(angularDrag > 0.0)
		if(m_angularSpeed > 0.0)
		{
			m_dragTorque.x = -m_angularVelocity.x * angularDrag;
			m_dragTorque.y = -m_angularVelocity.y * angularDrag;
			m_dragTorque.z = -m_angularVelocity.z * angularDrag;			
			if (Mathf.Abs(m_dragTorque.x) >= Mathf.Epsilon) { m_torque.x += m_dragTorque.x; m_hasTorque = true; }
			if (Mathf.Abs(m_dragTorque.y) >= Mathf.Epsilon) { m_torque.y += m_dragTorque.y; m_hasTorque = true; }
			if (Mathf.Abs(m_dragTorque.z) >= Mathf.Epsilon) { m_torque.z += m_dragTorque.z; m_hasTorque = true; }
		}		
	}
	
	private function IntegrateVelocity(p_dt:Float32):Void
	{
		if (kinematic) return;
		
		var dt : Float32 = p_dt;
		
		if (m_hasForce)
		{
			var v : Vector3 = velocity;
			v.x += m_accel.x * dt;
			v.y += m_accel.y * dt;
			v.z += m_accel.z * dt;			
			velocity = v;
		}
		
		if(!m_hasForce)
		if (m_speed <= 0.14)
		{
			//velocity = Vector3.zero;
		}
		
		if (m_hasTorque)
		{	
			var v : Vector3 = angularVelocity;
			v.x += m_torque.x * dt;
			v.y += m_torque.y * dt;
			v.z += m_torque.z * dt;
			angularVelocity = v;
		}
		
		if(!m_hasTorque)
		if (m_angularSpeed <= (0.14 * Mathf.Deg2Rad))
		{
			//angularVelocity 	= Vector3.zero;			
		}
		
	}
	
	private function IntegratePosition(p_dt : Float32):Void
	{		
		var integrate_position : Bool = true;
		var dt : Float32 = p_dt;
		
		if (Mathf.Abs(m_velocity.x) < Mathf.Epsilon)
		if (Mathf.Abs(m_velocity.y) < Mathf.Epsilon)
		if (Mathf.Abs(m_velocity.z) < Mathf.Epsilon) integrate_position = false;
		
		
		if (integrate_position)
		{
			var p : Vector3 = transform.localPosition;			
			p.x += m_velocity.x * dt;
			p.y += m_velocity.y * dt;
			p.z += m_velocity.z * dt;
			transform.localPosition = p;			
		}
		
		var integrate_rotation : Bool = false;
		
		if (Mathf.Abs(m_angularVelocity.x) < Mathf.Epsilon)
		if (Mathf.Abs(m_angularVelocity.y) < Mathf.Epsilon)
		if (Mathf.Abs(m_angularVelocity.z) < Mathf.Epsilon) integrate_rotation = false;
		
		
		if (integrate_rotation)
		{
			var r : Quaternion = transform.localRotation;			
			m_avq.Set(m_angularVelocity.x, m_angularVelocity.y, m_angularVelocity.z, 0.0);			
			m_avq.Multiply(r,false);						
			m_avq.Scale(0.25);			
			r.x += m_avq.x * dt;
			r.y += m_avq.y * dt;
			r.z += m_avq.z * dt;
			r.w += m_avq.w * dt;
			r.Normalize();			
			transform.localRotation = r;			
		}
	}
	
	/**
	 * 
	 */
	public function ResetForces():Void
	{
		m_accel.x   = 0;
		m_accel.y   = 0;
		m_accel.z   = 0;
		m_hasForce  = false;
		m_torque.x  = 0;
		m_torque.y  = 0;
		m_torque.z  = 0;
		m_hasTorque = false;
	}
	
}