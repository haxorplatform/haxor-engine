package haxor.component;
import haxor.core.Entity;
import haxor.core.ICollidable;
import haxor.core.ITriggerable;
import haxor.physics.Collider;
import haxor.physics.Collider.Collision;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ColliderDebugger extends Component implements ICollidable implements ITriggerable
{
	
	function new(e : Entity)
	{
		super(e);
		
	}
	
	public function OnCollisionEnter(c:Collision):Void
	{
		trace(name + "> CollisionEnter ["+c.from.name+"] -> ["+c.to.name+"]");
	}
	
	public function OnCollisionStay(c:Collision):Void
	{
		
	}
	
	public function OnCollisionExit(c:Collision):Void
	{
		trace(name + "> CollisionExit ["+c.from.name+"] -> ["+c.to.name+"]");
	}
	
	public function OnTriggerEnter(c:Collider):Void
	{
		trace(name + "> TriggerEnter ["+c.name+"] -> ["+name+"]");
	}
	
	public function OnTriggerExit(c:Collider):Void
	{
		trace(name + "> TriggerExit ["+c.name+"] -> ["+name+"]");
	}
	
	public function OnTriggerStay(c:Collider):Void
	{
		
	}
}
