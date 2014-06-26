/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.physics.broadphase;
import haxor.core.Console;
import haxor.core.Time;
import haxor.core.Vector;
import haxor.physics.Collider;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class BroadPhase
{
	
	public var pairs : Vector<Collision>;
	
	public var queryMs : Int;
	
	public var queries : Int;
	
	private var m_query : Vector<Collider>;	
	
	private var m_indexes : Array<Int>;
	
	private var m_dirty : Array <Bool>;
	
	private var m_update : Array<Collider>;
	
	private var m_next_update : Int;
	
	private var m_pair_lookup : Array<Array<Int>>;
	
	private var m_buffer : Vector<Collider>;
	
	public function new()
	{
		
		m_indexes 		= [];	
		
		
		m_update		= [];
		m_next_update 	= 0;
		
		m_dirty			= [];
		
		queries			= 0;
		m_pair_lookup	= [];
		for (i in 0...4096)
		{
			m_dirty.push(false);
			m_update.push(null);
			var l : Array<Int> = [];
			for (j in 0...4096) l.push(-1);
			m_pair_lookup.push(l);			
		}
		
		
		queryMs = 0;
		
		pairs    = new Vector<Collision>();		
		m_query  = new Vector<Collider>();
		m_buffer = new Vector<Collider>();
		
	}
	
	public function Initialize():Void
	{	
		queries			= 0;
		m_pair_lookup	= [];
		for (i in 0...4096)
		{
			var l : Array<Int> = [];
			for (j in 0...4096) l.push(-1);
			m_pair_lookup.push(l);
		}
		
		var l : Array<Collider> = Collider.list;
		//trace("BroadPhase> Initialize "+l.length+" colliders.");
		m_query.Clear();
		
		
		for (i in 0...l.length)
		{
			l[i].NotifyExit(null,false);
			UpdateCollider(l[i]);
		}
	}
	
	public function SetDirty(p_collider : Collider):Void
	{
		if (m_dirty[p_collider.m_cid]) return;
		m_dirty[p_collider.m_cid] = true;
		m_update[m_next_update++] = p_collider;
	}
	
	public function Update():Void
	{
		queries = 0;
		queryMs = cast Time.ms;
		for (i in 0...m_next_update)
		{
			var c: Collider = m_update[i];
			UpdateCollider(c);
			m_dirty[c.m_cid] = false;
		}
		
		queryMs = cast Time.ms - queryMs;
				
		m_next_update = 0;	
		
	}
	
	public function UpdateCollider(p_collider : Collider):Void
	{	
		m_query.Clear();
		GetQuery(p_collider);		
		queries += m_query.count;
		SearchPairs(p_collider);				
	}
	
	public function RemoveCollider(p_collider : Collider):Void
	{
		for (i in 0...pairs.count)
		{
			var p : Collision = pairs.Get(i);			
			if (p.from == p_collider) { RemovePair(p.from,p.to); continue; }
			if (p.to   == p_collider) { RemovePair(p.from,p.to); continue; }
		}
	}
	
	private function AddQuery(p_collider:Collider):Void
	{
		m_query.Add(p_collider);
	}
	
	private function AddPair(p_a : Collider, p_b:Collider):Collision
	{			
		var bpp : Collision = SamplePair(p_a, p_b);
		if (bpp != null) { return bpp; }
		
		if (!BroadCheck(p_a, p_b))
		{			
			return null;
		}
		
		//trace("AddPair "+p_a.m_cid+" "+p_b.m_cid);
		
		var bpp : Collision = null;
		var idx : Int 		= -1;
		
		bpp = pairs.Peek();
		
		if (bpp == null) bpp = new Collision();
		
		idx = pairs.Add(bpp);
		
		CachePair(p_a, p_b, idx);
		bpp.m_destroyed = false;
		bpp.m_active    = false;
		bpp.from 	  = p_a;		
		bpp.to  	  = p_b;		
		bpp.m_id      = idx;
		return bpp;
	}
	
	
	
	private function DestroyPair(p_a : Collider, p_b:Collider):Void
	{
		var bpp : Collision = SamplePair(p_a, p_b);				
		if (bpp == null) { return; }
		bpp.m_destroyed = true;
	}
	
	private function RemovePair(p_a : Collider, p_b:Collider):Void
	{		
		var bpp : Collision = SamplePair(p_a, p_b);		
		
		if (bpp == null) { return; }
		
		//trace("RemovePair");
		//Console.Breakpoint();
		
		var idx : Int = bpp.m_id;
		CachePair(p_a, p_b, -1);
		bpp 	= pairs.RemoveAt(idx);
		if(bpp != null)	bpp.m_id  = idx;		
	}
	
	private function CachePair(p_a:Collider, p_b:Collider,p_index:Int):Void
	{
		var cid_a : Int = p_a.m_cid;
		var cid_b : Int = p_b.m_cid;		
		m_pair_lookup[cid_a][cid_b] = p_index;
		m_pair_lookup[cid_b][cid_a] = p_index;
	}
	
	private function SamplePair(p_a:Collider, p_b:Collider) : Collision
	{
		var idx :Int = m_pair_lookup[p_a.m_cid][p_b.m_cid];
		if (idx < 0) return null;
		return pairs.Get(idx);		
	}
	
	private function Exists(p_a:Collider, p_b:Collider):Bool 
	{
		var cid_a : Int = p_a.m_cid;
		var cid_b : Int = p_b.m_cid;		
		if (m_pair_lookup[cid_a][cid_b] >= 0) return true;
		if (m_pair_lookup[cid_b][cid_a] >= 0) return true;
		return false;
	}
	
	private function SearchPairs(p_collider:Collider):Void
	{	
		var c : Collider 		   = p_collider;
		var q0 : Vector<Collider>  = c.m_query;
		var q1 : Vector<Collider>  = m_query;		
		
		/*
		m_buffer.Clear();		
		//Search for colliders that EXIT between frames
		for (i in 0...q0.count)
		{
			var f : Bool = false;
			var a : Collider = q0.Get(i);			
			for (j in 0...q1.count)
			{
				var b : Collider = q1.Get(j);				
				if (b == p_collider) continue;
				if (a == b) f = true;
			}			
			if (!f) m_buffer.Add(a);
		}	
		
		for (i in 0...m_buffer.count) DestroyPair(p_collider, m_buffer.Get(i));
		//*/
		m_buffer.Clear();		
		//Search for colliders that ENTER between frames
		for (i in 0...q1.count)
		{
			var f : Bool = false;
			var a : Collider = q1.Get(i);
			if (a == p_collider) continue;
			for (j in 0...q0.count)
			{
				var b : Collider = q0.Get(j);
				if (a == b) f = true;
			}			
			if (!f) m_buffer.Add(a);			
		}
		for (i in 0...m_buffer.count) AddPair(p_collider, m_buffer.Get(i));		
		//*/
		q0.Clear();
		for (i in 0...q1.count) q0.Add(q1.Get(i));
		
		//*/
	}
	
	//public function GetRayQuery(p_ray:Ray):Array<Collider> { return Collider.list; }
	
	public function GetQuery(p_collider:Collider):Void
	{ 
		for (i in 0...Collider.list.length) AddQuery(Collider.list[i]);
	}
	
	public function BroadCheck(p_a : Collider, p_b : Collider):Bool 
	{ 
		if (!p_a.enabled) return false;
		if (!p_b.enabled) return false;
		var can_interact : Bool = Physics.CanInteract(p_a.entity.layer, p_b.entity.layer);			
		if (!can_interact) return false;
		if (p_a.m_rigidbody == null)
		if (p_b.m_rigidbody == null) return false;
		//if (p_a.trigger) 		
		//if (p_b.trigger) 
		//if (p_b.m_rigidbody == null) return false;		
		return true;
	}
	
}
