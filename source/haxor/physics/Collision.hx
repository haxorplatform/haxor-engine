package haxor.physics;
import haxor.component.physics.Collider;
import haxor.math.Vector3;

@:allow(haxor)
class Collision
{
	public var from   : Collider;
	public var to     : Collider;
	public var point  : Vector3;
	public var depth  : Float;
	public var normal : Vector3;
	public var speed  : Float;
	
	private var m_id : Int;
	
	private var m_active : Bool;
	
	private var m_destroyed : Bool;
	
	public function new()
	{
		normal = Vector3.zero;
		point  = Vector3.zero;
		depth  = 0.0;
		speed  = 0.0;		
		m_id = -1;
		m_active = false;
		m_destroyed = false;
	}
	/*
		
	public function Invert():Collision
	{
		normal.Invert();
		return this;
	}
	
	private function Update():Bool
	{
		if (!m_active)
		{
			if (depth < 0.0)
			{
				m_active = true;			
				from.NotifyEnter(this,false);
				to.NotifyEnter(this, true);				
			}			
		}
		else
		{
			if (depth < 0.0)
			{				
				from.NotifyStay(this,false);
				to.NotifyStay(this,true);
			}
			else
			{				
				from.NotifyExit(this,false);
				to.NotifyExit(this,true);
				m_active = false;
			}
		}		
		return true;
	}
	//*/
}