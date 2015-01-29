package haxor.component.physics;
import haxor.core.Enums.ColliderType;
import haxor.math.AABB3;
import haxor.math.Vector4;
import haxor.physics.PhysicsMaterial;

/**
 * Base class for all collider elements.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Collider extends Behaviour// implements IUpdateable
{
	
	/*
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
	
	public var primitive(get_primitive, never):ColliderType;
	private function get_primitive():ColliderType { return m_primitive; }
	private var m_primitive : ColliderType;
		
	private var m_query : Array<Collider>;
	
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
	//*/
}