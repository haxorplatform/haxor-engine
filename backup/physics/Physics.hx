/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.physics;
import haxor.component.RigidBody;
import haxor.core.Time;
import haxor.core.Vector;
import haxor.editor.Gizmo;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.physics.broadphase.BroadPhase;
import haxor.physics.broadphase.SAPBroadPhase;
import haxor.physics.Collider;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Physics
{
	static public var iterations : Int = 10;
	
	static private var m_interaction : Map<Int,Bool>;
	
	static public var gravity : Vector3;
	
	static public var broadphase(get_broadphase,set_broadphase) : BroadPhase;
	static private var m_broadphase : BroadPhase;
	static private function get_broadphase():BroadPhase { return m_broadphase; }
	static private function set_broadphase(v:BroadPhase):BroadPhase 
	{ 
		if (v == null) return m_broadphase;
		//if (Type.getClass(v) == Type.getClass(m_broadphase)) return m_broadphase;
		m_broadphase = v;
		m_broadphase.Initialize();
		return m_broadphase;
		
	}
	
	static private var m_garbage : Vector<Collision>;
	
	static public function Initialize():Void
	{
		m_interaction = new Map<Int,Bool>();
		for (i in 0...32)
		for (j in 0...32)
		{
			SetInteraction((1 << i), (1 << j), false);
		}	
		
		SetInteraction(1,1, true);
		
		gravity = new Vector3(0.0, -9.81, 0.0);
		broadphase = new SAPBroadPhase();
		m_garbage = new Vector<Collision>();
	}
	
	static public function SetInteraction(p_layer_a : Int, p_layer_b : Int, p_flag : Bool):Void
	{
		var f : Int = p_layer_a | p_layer_b;
		m_interaction.set(f, p_flag);
	}
	
	static public function GetCollision(p_a: Collider, p_b : Collider,p_result:Collision=null):Collision
	{
		var pa : ColliderPrimitive = p_a.primitive;
		var pb : ColliderPrimitive = p_b.primitive;
		var  c : Collision = p_result == null ? Collision.temp : p_result;		
		if (pa == ColliderPrimitive.Box) 	if (pb == ColliderPrimitive.Box) 	   	c = GetCollisionBoxBox(cast p_a, cast p_b,c);
		if (pa == ColliderPrimitive.Sphere) if (pb == ColliderPrimitive.Box)   	 	c = GetCollisionSphereBox(cast p_a, cast p_b,c);
		if (pa == ColliderPrimitive.Box) 	if (pb == ColliderPrimitive.Sphere)   { c = GetCollisionSphereBox(cast p_b, cast p_a,c); if (c != null) { c.Invert(); } }		
		if (pa == ColliderPrimitive.Sphere) if (pb == ColliderPrimitive.Sphere)  	c = GetCollisionSphereSphere(cast p_a, cast p_b,c);
		return c;
	}
	
	static public function CanInteract(p_a:Int, p_b:Int):Bool
	{
		var k :Int = p_a | p_b;
		return m_interaction.exists(k) ? m_interaction.get(k) : false;
	}
	
	static private function Update():Void
	{
		broadphase.Update();
		var l : Array<RigidBody> = RigidBody.list;
		
		for (i in 0...l.length)
		{
			if (l[i].enabled)
			{
				if (!l[i].kinematic)
				{
					l[i].ComputeForces();
					l[i].IntegrateVelocity(Time.fixedDeltaTime);
				}
			}			
		}
		
		for (k in 0...iterations)
		{
			/*
			var l : Array<Collider> = Collider.list;
			for (i in 0...l.length)
			{
				for (j in (i + 1)...l.length)
				{
					var c : Collision = Collision.temp;
					c.from = l[i];
					c.to   = l[j];
					ProcessCollision(c);
				}
			}
			//*/
			
			for (j in 0...broadphase.pairs.count)
			{
				var c : Collision = broadphase.pairs.Get(j);
				ProcessCollision(c);
			}
			//*/
		}
		//*/
		for (i in 0...l.length)
		{
			if (l[i].enabled)
			{
				if (!l[i].kinematic)
				{
					l[i].IntegratePosition(Time.fixedDeltaTime);
				}
			}
			l[i].ResetForces();
		}
		
	}
	
	static private function UpdateCollisionState():Void
	{
		
		
		var i :Int = 0;
		var k :Int = 0;
		while(i < broadphase.pairs.count)
		{
			var c : Collision = broadphase.pairs.Get(i);
			c.Update();
			i++;
		}
		
		//trace(m_garbage.count);
		for (i in 0...m_garbage.count)
		{
			var c : Collision = m_garbage.Get(i);
			broadphase.RemovePair(c.from, c.to);
		}
		m_garbage.Clear();
		//*/
	}
	
	static private function ProcessCollision(p_collision : Collision):Void
	{
		var c :Collision = GetCollision(p_collision.from, p_collision.to, p_collision);
		if (c == null) 
		{
			//m_garbage.Add(p_collision);
			return;
		}
		
		var rba : RigidBody = c.from.m_rigidbody;
		var rbb : RigidBody = c.to.m_rigidbody;
		
		var ma : Float = rba==null ? 0.0 : rba.mass;
		var mb : Float = rbb==null ? 0.0 : rbb.mass;
		var sum : Float = ma + mb;
		var ra  : Float = rba==null ? 0.0 : (ma / sum);
		var rb  : Float = rbb==null ? 0.0 : (mb / sum);
		var p : Vector3;
		ApplyCollision(c, rba,ra,c.to.trigger);			c.Invert();
		ApplyCollision(c, rbb,rb,c.from.trigger);		c.Invert();
	}
	
	static private function ApplyCollision(p_collision : Collision, p_target : RigidBody,p_ratio : Float,p_is_trigger:Bool):Void
	{
		var r : RigidBody = p_target;
		if (r == null) 	 return;		
		var c : Collision = p_collision;		
		var rv : Float = Vector3.Dot(c.normal, r.velocity);
		c.speed = rv;	
		
		if (!r.kinematic)
		if(!p_is_trigger)
		if(c.depth < 0.0)
		{
			var m0 : PhysicsMaterial = p_collision.from.material; m0 = (m0 == null) ? PhysicsMaterial.empty : m0;
			var m1 : PhysicsMaterial = p_collision.to.material;   m1 = (m1 == null) ? PhysicsMaterial.empty : m1;					
			var bf : Float      = (m0.bounce + m1.bounce) * 0.5;
			var restitution : Float = bf;
			
			if (rv < 0.0)
			{
				var impulse_v : Float = -(1.0 + restitution) * Vector3.Dot(r.velocity, c.normal);
				
				var v : Vector3 = r.velocity;
				v.x += c.normal.x * impulse_v;
				v.y += c.normal.y * impulse_v;
				v.z += c.normal.z * impulse_v;
				r.velocity = v;
				
				
				var correction : Float = c.depth * -0.8 * Time.fixedDeltaTime;
				var cm : Vector3 = r.transform.position;					
				cm.x += c.normal.x * correction;
				cm.y += c.normal.y * correction;
				cm.z += c.normal.z * correction;
				r.transform.position = cm;					
				//*/
			}
		}
		
		if (c.depth > 0.0) if (rv > 0.0) 
		{ 
			m_garbage.Add(p_collision); 
		}
		
	}
	
	
	static private function GetCollisionBoxBox(p_a:BoxCollider, p_b:BoxCollider,c : Collision=null):Collision
	{
		return null;
	}
	
	static private function GetCollisionSphereSphere(p_a:SphereCollider, p_b:SphereCollider,c : Collision=null):Collision
	{
		var wma  : Matrix4 = p_a.transform.m_worldMatrix;
		var wmb  : Matrix4 = p_b.transform.m_worldMatrix;
		var c0  : Vector3 = Vector3.temp.Set3(p_a.m_center);		wma.Transform3x4(c0);
		var rv0 : Vector3 = Vector3.temp.Set(0, 0, p_a.radius);		wma.Transform3x3(rv0);
		var r0  : Float   = rv0.length;
		var c1  : Vector3 = Vector3.temp.Set3(p_b.m_center);		wmb.Transform3x4(c1);
		var rv1 : Vector3 = Vector3.temp.Set(0, 0, p_b.radius);		wmb.Transform3x3(rv1);
		var r1  : Float   = rv1.length;
		
		var d : Float = Vector3.Distance(c0, c1) * 2.0;
		
		if (c == null)
		{
			c = Collision.temp;
			c.from  = p_a;
			c.to    = p_b;	
		}
		
		c.depth = d - (r0 + r1);
		
		if (c.depth >= 0.0) return null;
		
		if (c.depth<0.0)
		{			
			c.normal.x = c0.x - c1.x;
			c.normal.y = c0.y - c1.y;
			c.normal.z = c0.z - c1.z;
			c.normal.Normalize();						
		}
		return c;
	}
	
	static private function GetCollisionSphereBox(p_a:SphereCollider, p_b:BoxCollider,c : Collision=null):Collision
	{
		var wma  : Matrix4 = p_a.transform.WorldMatrix;		
		var wmb  : Matrix4 = p_b.transform.WorldMatrix;
		var wmib : Matrix4 = p_b.transform.WorldMatrixInverse;
		
		var c0  : Vector3 = Vector3.temp.Set3(p_a.m_center); 		
		wma.Transform3x4(c0);  
		wmib.Transform3x4(c0);
				
		
		var rv0 : Vector3 = Vector3.temp.Set(0, 0, p_a.radius);				
		wma.Transform3x3(rv0); 
		
		
		var c1  : Vector3 = Vector3.temp.Set3(p_b.m_center);		
		var s1  : Vector3 = Vector3.temp.Set3(p_b.size);
		
		var hx  : Float = s1.x * 0.5;
		
		var xmin0 : Float = c1.x - hx;		
		var xmax1 : Float = c0.x + rv0.x;		
		//if (xmin0 >= xmax1) return null;
		
		var xmin1 : Float = c0.x - rv0.x;
		var xmax0 : Float = c1.x + hx;
		//if (xmin1 >= xmax0) return null;
		
		var hy  : Float = s1.y * 0.5;
		
		var ymin0 : Float = c1.y - hy;		
		var ymax1 : Float = c0.y + rv0.y;
		//if (ymin0 >= ymax1) return null;
		
		var ymin1 : Float = c0.y - rv0.y;
		var ymax0 : Float = c1.y + hy;
		//if (ymin1 >= ymax0) return null;
		
		var hz  : Float = s1.z * 0.5;
		
		var zmin0 : Float = c1.z - hz;		
		var zmax1 : Float = c0.z + rv0.z;	
		//if (zmin0 >= zmax1) return null;
		
		var zmin1 : Float = c0.z - rv0.z;
		var zmax0 : Float = c1.z + hz;		
		//if (zmin1 >= zmax0) return null;
		
		var cp : Vector3 = Vector3.temp;
		cp.x = Math.max(xmin0, Math.min(xmax0, c0.x));
		cp.y = Math.max(ymin0, Math.min(ymax0, c0.y));
		cp.z = Math.max(zmin0, Math.min(zmax0, c0.z));
		
		wmb.Transform3x4(cp);
		wmb.Transform3x4(c0);
		
		var r :Float = rv0.length*0.5;
		var d : Float = Vector3.Distance(cp, c0);
		
		
		
		if (c == null)
		{
			c = Collision.temp;
			c.from  = p_a;
			c.to    = p_b;	
		}
		
		c.depth = d-r;
		if (c.depth >= 0.0) return null;
		if (c.depth < 0.0)
		{	
			c.point.Set3(cp);			
			c.normal.x = c0.x - cp.x;
			c.normal.y = c0.y - cp.y;
			c.normal.z = c0.z - cp.z;
			//wmb.Transform3x3(c.normal);			
			c.normal.Normalize();			
		}
		
		return c;
	}
}