/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.physics.broadphase;
import haxor.core.Console;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.physics.Collider;
import haxor.physics.Physics;
import haxor.physics.SphereCollider;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class SAPBroadPhase extends BroadPhase
{	
	
	private var m_x : SAPInterval;	
	private var m_y : SAPInterval;
	private var m_z : SAPInterval;
	
	private var m_intervals_x : Array<SAPInterval>;
	private var m_intervals_y : Array<SAPInterval>;
	private var m_intervals_z : Array<SAPInterval>;
	
	
	
	public function new()
	{
		super();
		
		m_intervals_x = [];
		m_intervals_y = [];
		m_intervals_z = [];
		
		for (i in 0...4096)
		{
			m_intervals_x.push(new SAPInterval());
			m_intervals_y.push(new SAPInterval());
			m_intervals_z.push(new SAPInterval());
		}		
	}
	
	override public function RemoveCollider(p_collider:Collider):Void 
	{
		super.RemoveCollider(p_collider);
		var cid  : Int   = p_collider.m_cid;
		RemoveInterval(m_intervals_x[cid]);
		RemoveInterval(m_intervals_y[cid]);
		RemoveInterval(m_intervals_z[cid]);
	}
	
	override public function UpdateCollider(p_collider:Collider):Void 
	{
		var cid  : Int   = p_collider.m_cid;
		var b    : AABB3 = p_collider.boundAABB;
		var itvx  : SAPInterval;
		var itvy  : SAPInterval;
		var itvz  : SAPInterval;		
		itvx = m_intervals_x[cid]; itvx.Set(b.xMin,b.xMax); itvx.collider = p_collider;
		itvy = m_intervals_y[cid]; itvy.Set(b.yMin,b.yMax); itvy.collider = p_collider;
		itvz = m_intervals_z[cid]; itvz.Set(b.zMin,b.zMax); itvz.collider = p_collider;		
		if (m_x == null) m_x = itvx; else UpdateInterval(itvx, m_x);
		if (m_y == null) m_y = itvy; else UpdateInterval(itvy, m_y);
		if (m_z == null) m_z = itvz; else UpdateInterval(itvz, m_z);		
		super.UpdateCollider(p_collider);
	}
	
	override public function GetQuery(p_collider:Collider):Void
	{	
		var cid  : Int   = p_collider.m_cid;
		var ix   : SAPInterval;
		var iy   : SAPInterval;
		var iz   : SAPInterval;	
		var itx  : SAPInterval;
		var ity  : SAPInterval;
		var itz  : SAPInterval;
		
		ix = m_intervals_x[cid];
		iy = m_intervals_y[cid];
		iz = m_intervals_z[cid];
		
		var sc : SphereCollider = cast p_collider;
		
		itx = ix.next;
		//Forward Check
		while (itx != null)
		{	
			var c : Collider = itx.collider;
			
			//HitX
			if (itx.Overlap(ix))
			{		
				ity = GetIntervalY(c);
				//HitY
				if (ity.Overlap(iy))
				{	
					itz = GetIntervalZ(c);
					//HitZ
					if (itz.Overlap(iz))
					{
						AddQuery(c);						
					}
				}									
			}			
			itx = itx.next;			
		}
		
		itx = ix.prev;
		//Backward Check
		
		while (itx != null)
		{
			var c : Collider = itx.collider;			
			//HitX
			if (itx.Overlap(ix))
			{			
				ity = GetIntervalY(c);
				//HitY
				if (ity.Overlap(iy))
				{	
					itz = GetIntervalZ(c);
					//HitZ
					if (itz.Overlap(iz))
					{
						AddQuery(c);						
					}
				}				
			}	
			
			itx = itx.prev;			
		}				
	}
	
	private function GetIntervalX(p_collider:Collider):SAPInterval { var cid  : Int   = p_collider.m_cid; return m_intervals_x[cid]; }
	private function GetIntervalY(p_collider:Collider):SAPInterval { var cid  : Int   = p_collider.m_cid; return m_intervals_y[cid]; }
	private function GetIntervalZ(p_collider:Collider):SAPInterval { var cid  : Int   = p_collider.m_cid; return m_intervals_z[cid]; }
	
	private function UpdateInterval(p_itv : SAPInterval, p_start:SAPInterval):Void
	{
		//Check if interval belongs anywhere
		if (p_itv.prev == null) 
		if (p_itv.next == null)
		{
			AddIntervalSorted(p_itv, p_start);
			return;
		}		
		
		var it : SAPInterval 	 = p_itv;
		var nav : Int 			 = 0;
		var target : SAPInterval = null;
		
		while (it != null)
		{
			var n : SAPInterval = it.next;
			var p : SAPInterval = it.prev;
			if (n == null) if (p == null) break;
			if (p != null) if (p_itv.min < p.min) { nav = -1; target = p; }
			if (n != null) if (p_itv.min > n.min) { nav =  1; target = n; }
			if (nav == 0) break;
			it = nav < 0 ? p : n;
			nav = 0;
		}		
		
		if (target != null)
		{			
			RemoveInterval(p_itv);
			AddIntervalAtSorted(p_itv, target);		
		}
	}
	
	private function RemoveInterval(p_itv : SAPInterval):Void
	{
		var p : SAPInterval = p_itv.prev;
		var n : SAPInterval = p_itv.next;		
		if (p != null) p.next = n;
		if (n != null) n.prev = p;
		p_itv.next = p_itv.prev = null;
		
		//Update starting nodes
		if (p_itv == m_x) { m_x = n; }		
		if (p_itv == m_y) { m_y = n; }
		if (p_itv == m_z) { m_z = n; }
		
		
	}
		
	private function AddIntervalSorted(p_itv : SAPInterval, p_start : SAPInterval):Void
	{
		if (p_itv == p_start) return;
		var it : SAPInterval = p_start;		
		
		while (it != null)
		{	
			if (p_itv.min > it.min)
			{
				if (it.next == null) 
				{ 
					p_itv.next = null;
					p_itv.prev = it;
					it.next    = p_itv; 										
					return; 
				}				
				it = it.next;
			}
			else
			{
				AddIntervalAtSorted(p_itv, it);
				return;
			}
		}
	}
	
	private function AddIntervalAtSorted(p_itv : SAPInterval, p_at : SAPInterval):Void
	{		
		if (p_itv == p_at) return;
		
		//check min max to add left or right
		
		//right
		if (p_itv.min > p_at.min)
		{
			p_itv.next = p_at.next;
			p_itv.prev = p_at;
			p_at.next  = p_itv;			
			if (p_itv.next != null) p_itv.next.prev = p_itv;			
		}
		else //left
		{
			p_itv.next = p_at;
			p_itv.prev = p_at.prev;
			p_at.prev  = p_itv;
			if (p_itv.prev != null) p_itv.prev.next = p_itv;
			
			//Update starting node if inserted left
			if (p_at == m_x) { m_x = p_itv; }		
			if (p_at == m_y) { m_y = p_itv; }
			if (p_at == m_z) { m_z = p_itv; }
		}
	}
	
	private function Iterate(p_start : SAPInterval, p_callback : SAPInterval -> Void):Void
	{
		var it : SAPInterval = p_start;
		while (it != null)
		{
			p_callback(it);
			it = it.next;
		}
	}
}

/**
 * Class that describes an interval node for sweep and prune.
 */
class SAPInterval
{
	public var id		: Int;
	public var min 		: Float;	
	public var max 		: Float;	
	public var collider : Collider;	
	public var next 	: SAPInterval;	
	public var prev 	: SAPInterval;
	
	/**
	 * Creates a new interval.
	 */
	public function new() { min = max = 0.0; id = 0; }
	
	/**
	 * Sets this interval limits.
	 * @param	p_min
	 * @param	p_max
	 */
	public function Set(p_min:Float,p_max:Float):Void	{ min = p_min;	max = p_max;	}
	
	/**
	 * Tests if this interval overlaps with other one.
	 * @param	p_interval
	 * @return
	 */
	public function Overlap(p_interval : SAPInterval):Bool
	{
		if (p_interval.min > min)
		{
			return p_interval.min <= max;
		}
		return p_interval.max >= min;
	}
	
	/**
	 * Returns the string representation of this node.
	 * @return
	 */
	public function ToString():String { return "["+Mathf.RoundPlaces(min,2)+"|"+collider.name+"|"+Mathf.RoundPlaces(max,2)+"]"; }
}