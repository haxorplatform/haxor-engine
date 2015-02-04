package haxor.context;
import haxor.component.Component;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.Transform;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.IFixedUpdateable;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.graphics.Gizmo;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Vector4;
import haxor.physics.broadphase.BroadPhase;
import haxor.physics.Collision;
import haxor.physics.CollisionSolver;
import haxor.physics.Physics;
import haxor.platform.Types.Float32;

/**
 * Class that handles all Physics functionalities and structures.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class PhysicsContext
{

	/**
	 * Unique RigidBodies ids.
	 */
	private var rid : UID;
	
	/**
	 * Unique Colliders ids.
	 */
	private var cid : UID;
	
	/**
	 * List of created colliders.
	 */
	private var colliders : Array<Collider>;
	
	/**
	 * List of created rigid bodies.
	 */
	private var rigidbodies : Array<RigidBody>;
		
	/**
	 * List of colliders per Rigidbody.
	 */
	private var rbc : Array<Array<Collider>>;
	
	/**
	 * List of rigidbody associated to colliders.
	 */
	private var crb : Array<RigidBody>;
	
	/**
	 * List of dirt flags for colliders.
	 */
	private var collider_dirty : Array<Bool>;
		
	/**
	 * Accumulated delta time for physics simulation.
	 */
	private var accum_dt : Float;
	
	/**
	 * Creates the context.
	 */
	private function new() 
	{
		rid = new UID();
		cid = new UID();
		colliders   = [];
		
				
		rigidbodies = [];
		
		rbc = [];
		crb = [];
		
		collider_dirty = [];
		
		accum_dt = 0;
		
	}
	
	/**
	 * Initializes the context with Graphics available.
	 */
	private function Initialize():Void
	{
		
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function CreateCollider(c: Collider):Void
	{		
		colliders.push(c);		
		var nid : Int = cid.next;
		c.__cid = cid.id;
		
		if (nid >= c.__cid)
		{
			crb.push(null);
			collider_dirty.push(true);
		}
		else
		{			
			collider_dirty[c.__cid] = true;
		}
		crb[c.__cid] = c.entity.GetComponent(RigidBody);
		Physics.broadphase.Add(c);
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function OnColliderUpdate(c : Collider,h : Bool):Void
	{
		collider_dirty[c.__cid] = true;		
	}
	
	
	
	/**
	 * 
	 * @param	r
	 */
	private function CreateRigidBody(r : RigidBody):Void
	{
		rigidbodies.push(r);			
		var nid : Int = rid.id;
		r.__cid = nid;
		
		if (nid >= rbc.length)
		{
			rbc.push([]);
		}
		else
		{
			rbc[nid] = [];
		}
		
		//search all colliders that can form its body.
		var cl : Array<Collider> = cast r.GetComponents(Collider);
		for (i in 0...cl.length)
		{
			var c : Collider = cl[i];
			rbc[nid].push(c);
			crb[c.__cid] = r;
		}
		
	}
	
	/**
	 * Physics execution loop.
	 */
	private function Step():Void
	{
		var up : Process<IFixedUpdateable> = EngineContext.fixed_update;
		var bp : BroadPhase = Physics.broadphase;
		var cs : CollisionSolver = Physics.m_solver;					
		var steps : Int = 0;
		
		cs.broadphase = bp;			
		
		accum_dt += Time.delta;
		
		var t0 : Float32;
		
		while (accum_dt > Time.fixedDelta)
		{
			//Fail-safe
			if (steps >= 5) break;
			steps++;
			
			//Update FixedUpdate nodes.
			for (i in 0...up.length)
			{
				var r : Resource = cast up.list[i];
				if (r.m_destroyed) continue;			
				up.list[i].OnFixedUpdate();
			}
			
			
			UpdateColliders();
			
			var l : Array<RigidBody> = rigidbodies;
		
			for (i in 0...l.length)
			{
				if (l[i].enabled)
				{
					if (!l[i].kinematic)
					{
						l[i].ComputeForces();
						l[i].IntegrateVelocity(Time.fixedDelta);
					}
				}			
			}
			
			for (i in 0...cs.iterations)
			{
				cs.Step();				
			}
			
			for (i in 0...l.length)
			{
				if (l[i].enabled)
				{
					if (!l[i].kinematic)
					{
						l[i].IntegratePosition(Time.fixedDelta);
					}
				}
				l[i].ResetForces();
			}
			
			accum_dt -= Time.fixedDelta;
		}
		
	}
	
	/**
	 * 
	 */
	private function UpdateColliders():Void
	{
		var bp : BroadPhase = Physics.broadphase;
		//Step broadphase loop if necessary
		bp.Step();
		
		//Update colliders broadphase structures.
		for (i in 0...colliders.length)
		{
			var c : Collider = colliders[i];
			
			if (!c.enabled) continue;
			
			if (collider_dirty[c.__cid])
			{					
				bp.Clear(c);
				bp.Update(c);			
				bp.Query(c);
			}
			collider_dirty[c.__cid] = false;
		}		
		
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function DestroyCollider(c:Collider):Void
	{
		colliders.remove(c);
		cid.id = c.__cid;
		var rb : RigidBody = crb[c.__cid];
		crb[c.__cid] = null;		
		Physics.broadphase.Remove(c);
		if (rb != null)
		{			
			rbc[rb.__cid].remove(c);
		}
		Physics.broadphase.Remove(c);
	}
	
	/**
	 * 
	 * @param	r
	 */
	private function DestroyRigidBody(r : RigidBody):Void
	{
		rigidbodies.remove(r);		
		var cl : Array<Collider> = rbc[r.__cid];
		for (i in 0...cl.length) 
		{
			var c : Collider =	cl[i];
			crb[c.__cid] = null;
		}
	}
	
}