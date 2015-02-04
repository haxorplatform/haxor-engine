package haxor.component.physics;
import haxor.context.EngineContext;
import haxor.core.Enums.ColliderType;
import haxor.math.AABB3;
import haxor.math.Vector4;
import haxor.physics.Physics;
import haxor.physics.PhysicsMaterial;

/**
 * Base class for all collider elements.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Collider extends Behaviour// implements IUpdateable
{
	
	/**
	 * Flag that indicates the type of collider.
	 */
	public var type(get_type, never):ColliderType;
	private function get_type():ColliderType { return m_type; }
	private var m_type : ColliderType;
	
	/**
	 * 
	 * @param	v
	 * @return
	 */
	override function set_enabled(v:Bool):Bool 
	{
		super.set_enabled(v);
		EngineContext.physics.OnColliderUpdate(this,false);
		return v;
	}
	
	/**
	 * Flag that indicates if this collider should behave as a trigger.
	 */
	public var trigger : Bool;
	
	/**
	 * Material that describes physical properties of this collider.
	 */
	public var material : PhysicsMaterial;
	
	/**
	 * Bounding sphere.
	 */
	public var sphere(get_sphere, never) : Vector4;
	private function get_sphere():Vector4	{ if (m_sphere_dirty) { GenerateSphere(); m_sphere_dirty = false; } return m_sphere.clone; }
	private var m_sphere : Vector4;
	private var m_sphere_dirty : Bool;
	
	/**
	 * Boundings
	 */
	public var aabb(get_aabb, never) : AABB3;
	private function get_aabb():AABB3	{ if (m_aabb_dirty) { GenerateAABB(); m_aabb_dirty = false; } return m_aabb.clone; }
	private var m_aabb : AABB3;
	private var m_aabb_dirty : Bool;
		
	
	/**
	 * Method called after creation is complete.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		EngineContext.physics.CreateCollider(this);
		trigger  = false;
		m_aabb 	 = AABB3.empty;
		m_sphere = Vector4.zero;
		m_aabb_dirty = false;
		m_sphere_dirty = false;
	}
	
	/**
	 * Callback called when this element Transform has changed.
	 */
	override function OnTransformUpdate(p_hierarchy:Bool):Void 
	{
		super.OnTransformUpdate(p_hierarchy);		
		Refresh();
		EngineContext.physics.OnColliderUpdate(this,p_hierarchy);
	}
	
	
	/**
	 * Method that will generate the bounding sphere in world coords of this collider.
	 */
	private function GenerateSphere() : Void { }
	
	/**
	 * Method that will generate the aabb in world coords of this collider.
	 */
	private function GenerateAABB() : Void { }
	
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
	
	
	
	
	
	private var m_cid : Int;
	
	private var m_sid : Int;
		
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
	
	private function Refresh():Void
	{	
		m_aabb_dirty   = true;
		m_sphere_dirty = true;
	}
	
}