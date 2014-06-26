/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.physics;
import haxe.Timer;
import haxor.component.Behaviour;
import haxor.component.Component;
import haxor.component.RigidBody;
import haxor.core.Engine;
import haxor.core.ICollidable;
import haxor.core.ITriggerable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.core.Vector;
import haxor.math.AABB3;
import haxor.math.Vector3;
import haxor.math.Vector4;


enum ColliderPrimitive
{
	Point;
	Plane;
	Box;
	Sphere;
	Capsule;
	Mesh;
}


@:allow(haxor)
class Collision
{
	static private var m_temp : Array<Collision>;
	static private var m_nexttemp : Int;	
	static public var temp(get_temp, never):Collision;
	static private function get_temp():Collision
	{
		if (m_temp == null)
		{
			m_temp = [];
			m_nexttemp = 0;
			for (i in 0...50000) m_temp.push(new Collision());			
		}
		var t :Collision = m_temp[m_nexttemp];
		m_nexttemp = (m_nexttemp + 1) % m_temp.length;
		return t;
	}
	
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
	
	public function Invert():Collision
	{
		normal.Invert();
		return this;
	}
	
	private function Update():Bool
	{
		//if(from.name!="wall") trace(from.name+" "+m_active + " " + depth);
		//if ((Time.frame % 30) == 0) trace(from.name + " " + to.name + " " + depth);
		//if (from.name.indexOf("Camera") >= 0) trace(depth);
		if (!m_active)
		{
			if (depth < 0.0)
			{
				m_active = true;			
				from.NotifyEnter(this,false);
				to.NotifyEnter(this, true);
				
			}
			//return true;
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
		
		//if (!m_active) if (depth > 0.0) if (speed > 0.0) return false;
		return true;
	}
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Collider extends Behaviour// implements IUpdateable
{
	
	
	static public var list(get_list, never):Array<Collider>;
	static private function get_list():Array<Collider> { return m_list; }
	static private var m_list : Array<Collider>;
	
	static private var m_indexes : Array<Int>;
	
	static public function Initialize():Void
	{
		m_list		= [];		
		m_indexes 	= [];
	}
	
	public var trigger : Bool;
	
	public var material : PhysicsMaterial;
	
	public var boundSphere(get_boundSphere, never) : Vector4;
	private function get_boundSphere():Vector4	{ if (m_sphere_refresh) { GenerateBoundSphere();  } return m_boundSphere; }
	private var m_boundSphere : Vector4;
	
	private function GenerateBoundSphere() : Void { }
	
	public var boundAABB(get_boundAABB, never) : AABB3;
	private function get_boundAABB():AABB3	{ if (m_aabb_refresh) { GenerateBoundAABB();  } return m_boundAABB; }
	private var m_boundAABB : AABB3;
	
	private function GenerateBoundAABB() : Void { }
	
	private var m_cid : Int;
	
	private var m_sid : Int;
	
	public var primitive(get_primitive, never):ColliderPrimitive;
	private function get_primitive():ColliderPrimitive { return m_primitive; }
	private var m_primitive : ColliderPrimitive;
		
	private var m_query : Vector<Collider>;
	
	private var m_init : Bool;
	
	private var m_aabb_refresh : Bool;
	
	private var m_sphere_refresh : Bool;
	
	private var m_rigidbody : RigidBody;
	
	function new(p_entity) 
	{
		trigger = false;		
		var cid : Int 	= m_indexes.length > 0 ? m_indexes.shift() : m_list.length;		
		m_cid 			= cid;
		m_sid = -1;
		if (cid >= m_list.length) m_list.push(this); else m_list[cid] = this;		
		m_boundAABB 	= new AABB3();
		m_boundSphere 	= new Vector4();		
		
		m_query   = new Vector<Collider>();		
		m_aabb_refresh = true;
		m_sphere_refresh = true;
				
		super(p_entity);		
		Engine.Add(this);
		m_init = false;
		m_rigidbody = p_entity.rigidbody;
	}
	
	override public function OnAwake():Void 
	{
		m_init = true;
		Refresh();
	}
	
	private function Refresh():Void
	{	
		m_sphere_refresh = true;
		m_aabb_refresh   = true;		
		if(m_init)Physics.broadphase.SetDirty(this);
	}
	
	public function OnUpdate():Void
	{
		
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		var cid : Int = cast m_cid;
		m_list[cid] = null;		
		m_indexes.push(cid);
		Physics.broadphase.RemoveCollider(this);
	}
	
	override private function OnTransformUpdate():Void 
	{	
		Refresh();
		GenerateBoundAABB();
		GenerateBoundSphere();
		//m_aabb_refresh   = false;
		//m_sphere_refresh = false;
	}
	
	private function NotifyEnter(c : Collision,p_rev:Bool):Void
	{
		
		var cl : Array<Component> = entity.m_components;
		var from : Collider = c.from;
		var to   : Collider = c.to;
		var c0 : Collider =  !p_rev ? c.from : c.to;
		var c1 : Collider =  !p_rev ? c.to   : c.from;
		for (i in 0...cl.length)
		{
			if (Std.is(cl[i], ITriggerable))
			{
				if (!c0.trigger) if (!c1.trigger) continue;
				var l : ITriggerable = cast cl[i]; 
				l.OnTriggerEnter(c1); 
			}			
			
			if (Std.is(cl[i], ICollidable))
			{
				if (c0.trigger) if (c1.trigger) continue;
				var l : ICollidable = cast cl[i]; 
				
				if(p_rev) c.Invert();
				c.from = c1;
				c.to   = c0;
				
				l.OnCollisionEnter(c); 
				
				if (p_rev) c.Invert();
				c.from = from;
				c.to   = to;				
			}			
		}
	}
	
	private function NotifyStay(c:Collision,p_rev:Bool):Void
	{	
		var cl : Array<Component> = entity.m_components;
		var from : Collider = c.from;
		var to   : Collider = c.to;
		var c0 : Collider =  !p_rev ? c.from : c.to;
		var c1 : Collider =  !p_rev ? c.to   : c.from;
		for (i in 0...cl.length)
		{
			if (Std.is(cl[i], ITriggerable))
			{
				if (!c0.trigger) if (!c1.trigger) continue;
				var l : ITriggerable = cast cl[i]; 
				l.OnTriggerStay(c1); 
			}			
			
			if (Std.is(cl[i], ICollidable))
			{
				if (c0.trigger) if (c1.trigger) continue;
				var l : ICollidable = cast cl[i]; 
				
				if(p_rev) c.Invert();
				c.from = c1;
				c.to   = c0;
				
				l.OnCollisionStay(c); 
				
				if (p_rev) c.Invert();
				c.from = from;
				c.to   = to;				
			}			
		}
	}
	
	private function NotifyExit(c:Collision,p_rev:Bool):Void
	{		
		var cl : Array<Component> = entity.m_components;
		var from : Collider = c.from;
		var to   : Collider = c.to;
		var c0 : Collider =  !p_rev ? c.from : c.to;
		var c1 : Collider =  !p_rev ? c.to   : c.from;
		for (i in 0...cl.length)
		{
			if (Std.is(cl[i], ITriggerable))
			{
				if (!c0.trigger) if (!c1.trigger) continue;
				var l : ITriggerable = cast cl[i]; 
				l.OnTriggerExit(c1); 
			}			
			
			if (Std.is(cl[i], ICollidable))
			{
				if (c0.trigger) if (c1.trigger) continue;
				var l : ICollidable = cast cl[i]; 
				
				if(p_rev) c.Invert();
				c.from = c1;
				c.to   = c0;
				
				l.OnCollisionExit(c); 
				
				if (p_rev) c.Invert();
				c.from = from;
				c.to   = to;				
			}			
		}
	}
	
}