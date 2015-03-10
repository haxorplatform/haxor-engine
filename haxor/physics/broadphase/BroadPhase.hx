package haxor.physics.broadphase;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.Time;
import haxor.ds.PairTable;
import haxor.ds.USet;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Vector4;
import haxor.physics.Collision;



/**
 * Base class that describes a broadphase of a physics engine.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class BroadPhase
{
	
	/**
	 * 
	 */
	public var pairs : USet<Collision>;
	
	/**
	 * 
	 */
	private var m_table : PairTable<Collision>;
	
	/**
	 * 
	 */
	public function new() 
	{
		pairs = new USet();
		
		m_table = new PairTable(800, null, true);
		m_table.Iterate(InitCollisions);		
	}
		
	/**
	 * Initializes the BroadPhase.
	 */
	public function Initialize():Void {	 }
	
	/**
	 * Executes one step during the physics simulation.
	 */
	public function Step():Void	{ }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_bounds
	 */
	public function Update(c:Collider):Void { }
	
	/**
	 * 
	 * @param	p_collider
	 */
	public function Add(c:Collider):Void { }
	
	/**
	 * 
	 * @param	p_collider
	 */
	public function Remove(c:Collider):Void { }
	
	/**
	 * 
	 */
	public function Query(c : Collider) : Void { }
	
	/**
	 * 
	 */
	public function Clear(c:Collider):Void 
	{	
		var cid : Int = c.__cid;
		var col : Collision;
		for (i in 0...cid)
		{
			col = m_table.Get(i, cid);
			pairs.Remove(col);
		}		
		for (i in (cid+1)...m_table.rows)
		{
			col = m_table.Get(cid, i);
			pairs.Remove(col);
		}
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function OnFetch(a: Collider, b : Collider) : Void
	{			
		var ia : Int = a.__cid > b.__cid ? a.__cid : b.__cid;
		var ib : Int = a.__cid < b.__cid ? a.__cid : b.__cid;
		if (ia == ib) return;
		
		var ra : RigidBody = EngineContext.physics.crb[ia];
		var rb : RigidBody = EngineContext.physics.crb[ib];
		
		if (ra == null) if (rb == null) return;
		
		if(ra!=null)if (!ra.enabled) return;
		if(rb!=null)if (!rb.enabled) return;		
		
		var ca : Collider = ia > ib ? a : b;		
		if (!ca.enabled) return;
				
		var cb : Collider = ia < ib ? a : b;		
		if (!cb.enabled) return;
		
		if (!Physics.CanInteract(ca.entity.layer, cb.entity.layer)) return;
		
		var col : Collision = m_table.Get(ia, ib);
		col.Reset();
		col.from = ca;
		col.to   = cb;
		pairs.Add(col);
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_v
	 */
	private function InitCollisions(p_x : Int, p_y : Int, p_v : Collision):Void
	{
		m_table.Set(p_x, p_y, new Collision());
	}
}
