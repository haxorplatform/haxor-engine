package haxor.physics;
import haxor.component.physics.Collider;
import haxor.ds.USet.IUSetItem;
import haxor.math.Vector3;

/**
 * Class that describes a collision structure between colliders and 1 or 2 rigidbodies.
 */
@:allow(haxor)
class Collision implements IUSetItem
{
	/**
	 * 
	 */
	public var usid:Int;
	
	public var from   : Collider;
	public var to     : Collider;
	public var point  : Vector3;
	public var depth  : Float;
	public var normal : Vector3;
	public var speed  : Float;
	
	public function new()
	{
		normal = Vector3.zero;
		point  = Vector3.zero;
		depth  = 0.0;
		speed  = 0.0;	
		usid   = -1;
	}
	
	/**
	 * Inverts the collision normal direction.
	 * @return
	 */
	public function Invert():Collision
	{
		var tc : Collider = from;
		from = to;
		to   = tc;
		normal.Invert();
		return this;
	}
	
	/**
	 * 
	 */
	public function Reset():Void
	{
		normal.Set();
		point.Set();
		depth = 0;
		speed = 0;		
	}
	
	/*
		
	
	
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