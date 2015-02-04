package haxor.physics.broadphase;
import haxor.component.physics.Collider;
import haxor.core.Console;
import haxor.core.Time;
import haxor.ds.SAP;
import haxor.math.AABB3;
import haxor.math.Vector3;



/**
 * Sweep and Prune based physics broadphase.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class SAPBroadPhase extends BroadPhase
{
	
	/**
	 * SAP data structure.
	 */
	public var sap : SAP;
	
	/**
	 * Initializes the BroadPhase.
	 */
	override public function Initialize():Void
	{	 
		sap = new SAP(0.0);
	}
	
	/**
	 * 
	 * @param	p_collider
	 */
	override public function Update(c:Collider):Void
	{ 
		if (c.m_aabb_dirty) { c.GenerateAABB(); c.m_aabb_dirty = false; }
		var bb : AABB3 = c.m_aabb;
		var vmin : Vector3 = Vector3.temp.Set(bb.xMin, bb.yMin, bb.zMin);
		var vmax : Vector3 = Vector3.temp.Set(bb.xMax, bb.yMax, bb.zMax);
		sap.Update(c.__cid, c, vmin, vmax);		
	}
	
	/**
	 * 
	 * @param	p_collider
	 */
	override public function Add(c:Collider):Void 
	{
		sap.Create(c.__cid);
	}
	
	/**
	 * 
	 * @param	p_collider
	 */
	override public function Remove(c:Collider):Void 
	{ 
		sap.Remove(c.__cid);
	}	
	
	/**
	 * 
	 * @param	c
	 */
	override public function Query(c:Collider):Void 
	{
		sap.Query(c.__cid,OnSAPFetch);
	}
	
	/**
	 * 
	 * @param	d
	 */
	private function OnSAPFetch(a : Dynamic,b : Dynamic):Void
	{
		OnFetch(cast a,cast b);
	}
	
}
