package haxor.physics;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.Enums.ColliderType;
import haxor.core.Time;
import haxor.ds.Pool;
import haxor.ds.USet;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.physics.broadphase.BroadPhase;
import haxor.platform.Types.Float32;

/**
 * Class that will handle collision pairs that arrives from the broadphase.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class CollisionSolver
{
	
	/**
	 * Broadphase that will filter the collision set.
	 */
	public var broadphase : BroadPhase;
	
		
	/**
	 * Solving steps to stabilize the system.
	 */
	public var iterations : Int;
			
	/**
	 * 
	 */
	private function new() 
	{	
		iterations = 3;
	}
	
	/**
	 * 
	 * @param	p_collision
	 */
	public function Step() : Void
	{
		var l : USet<Collision> = broadphase.pairs;
		var c : Collision;
		
		for (i in 0...iterations)
		for (j in 0...l.length)
		{
			c  = l.Get(j);				
			Solve(c);				
			Apply(c);
		}
		
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function Solve(c : Collision):Void
	{
		var ca : Collider     = c.from;
		var cb : Collider     = c.to;
		var ta : ColliderType = ca.type;
		var tb : ColliderType = cb.type;
		if (ta == ColliderType.Box) 	if (tb == ColliderType.Box) 	   	{ SolveBoxBox(cast ca, cast cb, c);      return; }
		if (ta == ColliderType.Sphere)  if (tb == ColliderType.Box)   	 	{ SolveSphereBox(cast ca, cast cb,c);    return; }
		if (ta == ColliderType.Box) 	if (tb == ColliderType.Sphere)      { SolveSphereBox(cast cb, cast ca,c);	 return; }	
		if (ta == ColliderType.Sphere)  if (tb == ColliderType.Sphere)  	{ SolveSphereSphere(cast ca, cast cb,c); return; }
	}
	
	/**
	 * 
	 * @param	c
	 */
	private function Apply(c : Collision):Void
	{
		var ca : Collider     = c.from;
		var cb : Collider     = c.to;
		
		var ra : RigidBody = EngineContext.physics.crb[ca.__cid];
		var rb : RigidBody = EngineContext.physics.crb[cb.__cid];
		
		var ma : Float32  = ra==null ? 0.0 : ra.mass;
		var mb : Float32  = rb==null ? 0.0 : rb.mass;
		var sum : Float32 = (ma + mb) <= 0.0 ? 0.0 : (1.0 / (ma+mb));
		var ar  : Float32 = ra==null ? 0.0 : (ma * sum);
		var br  : Float32 = rb == null ? 0.0 : (mb * sum);
		
		if (ra != null) Resolve(ra,c, ar); c.Invert();
		if (rb != null) Resolve(rb,c, br); c.Invert();
	}
	
	/**
	 * 
	 * @param	rb
	 * @param	rbc
	 * @param	c
	 */
	private function Resolve(rb : RigidBody,c : Collision,ratio : Float32):Void
	{
		var rv : Float32 = Vector3.Dot(c.normal, rb.velocity);
		c.speed = rv;	
		
		var ca : Collider     = c.from;
		var cb : Collider     = c.to;
		
		var need_impulse : Bool = !(ca.trigger || cb.trigger);
		
		if (!rb.kinematic)
		if(need_impulse)
		if(c.depth < 0.0)
		{
			
			
			var m0 : PhysicsMaterial = ca.material;   m0 = (m0 == null) ? PhysicsMaterial.empty : m0;
			var m1 : PhysicsMaterial = cb.material;   m1 = (m1 == null) ? PhysicsMaterial.empty : m1;					
			var bf : Float32      = (m0.bounce + m1.bounce) * 0.5;
			var restitution : Float32 = bf;
			
			if (rv < 0.0)
			{
				var impulse_v : Float32 = -(1.0 + restitution) * Vector3.Dot(rb.velocity, c.normal);
				
				var v : Vector3 = rb.velocity;
				v.x += c.normal.x * impulse_v;
				v.y += c.normal.y * impulse_v;
				v.z += c.normal.z * impulse_v;
				rb.velocity = v;
				
				
				var correction : Float32 = c.depth * -0.9 * Time.fixedDelta;
				var cm : Vector3 = rb.transform.localPosition;					
				cm.x += c.normal.x * correction;
				cm.y += c.normal.y * correction;
				cm.z += c.normal.z * correction;
				rb.transform.localPosition = cm;					
				//*/
			}
		}
	}
	
	/**
	 * 
	 * @param	ca
	 * @param	cb
	 * @param	c
	 */
	private function SolveBoxBox(ca : BoxCollider, cb : BoxCollider, c : Collision)  :Void { }
	
	/**
	 * 
	 * @param	ca
	 * @param	cb
	 * @param	c
	 */
	private function SolveSphereSphere(ca : SphereCollider, cb : SphereCollider, c: Collision) : Void
	{
		var wma  : Matrix4 = ca.transform.WorldMatrix;
		var wmb  : Matrix4 = cb.transform.WorldMatrix;
		var c0   : Vector3 = Vector3.temp.Set3(ca.m_center);		wma.Transform3x4(c0);
		var rv0  : Vector3 = Vector3.temp.Set(0, 0, ca.radius);		wma.Transform3x3(rv0);
		var r0   : Float32 = rv0.length;
		var c1   : Vector3 = Vector3.temp.Set3(cb.m_center);		wmb.Transform3x4(c1);
		var rv1  : Vector3 = Vector3.temp.Set(0, 0, cb.radius);		wmb.Transform3x3(rv1);
		var r1   : Float32 = rv1.length;
		
		var d : Float = Vector3.Distance(c0, c1) * 2.0;
				
		c.depth = d - (r0 + r1);
		
		if (c.depth<0.0)
		{			
			c.normal.x = c0.x - c1.x;
			c.normal.y = c0.y - c1.y;
			c.normal.z = c0.z - c1.z;
			c.normal.Normalize();
			c.point.Set3(c0);
			var n : Vector3 = Vector3.temp.Set3(c.normal);
			n.Scale(-(r0 + c.depth)*0.5);
			c.point.Add(n);
		}
	}
	
	/**
	 * 
	 * @param	ca
	 * @param	cb
	 * @param	c
	 */
	private function SolveSphereBox(ca : SphereCollider, cb : BoxCollider, c: Collision) : Void
	{
		var wma  : Matrix4 = ca.transform.WorldMatrix;		
		var wmb  : Matrix4 = cb.transform.WorldMatrix;
		var wmib : Matrix4 = cb.transform.WorldMatrixInverse;
		
		var c0  : Vector3 = Vector3.temp.Set3(ca.m_center); 		
		wma.Transform3x4(c0);  
		wmib.Transform3x4(c0);
						
		var rv0 : Vector3 = Vector3.temp.Set(0, 0, ca.radius);				
		wma.Transform3x3(rv0); 
		
		
		var c1  : Vector3 = Vector3.temp.Set3(cb.m_center);		
		var s1  : Vector3 = Vector3.temp.Set3(cb.size);
		
		var hx  : Float32 = s1.x * 0.5;
		
		var xmin0 : Float32 = c1.x - hx;		
		var xmax1 : Float32 = c0.x + rv0.x;		
		
		var xmin1 : Float32 = c0.x - rv0.x;
		var xmax0 : Float32 = c1.x + hx;
		
		var hy  : Float32 = s1.y * 0.5;
		
		var ymin0 : Float32 = c1.y - hy;		
		var ymax1 : Float32 = c0.y + rv0.y;
		
		var ymin1 : Float32 = c0.y - rv0.y;
		var ymax0 : Float32 = c1.y + hy;
		
		var hz  : Float32 = s1.z * 0.5;
		
		var zmin0 : Float32 = c1.z - hz;		
		var zmax1 : Float32 = c0.z + rv0.z;	
		
		var zmin1 : Float32 = c0.z - rv0.z;
		var zmax0 : Float32 = c1.z + hz;		
		
		
		var cp : Vector3 = Vector3.temp;
		cp.x = Mathf.Max(xmin0, Mathf.Min(xmax0, c0.x));
		cp.y = Mathf.Max(ymin0, Mathf.Min(ymax0, c0.y));
		cp.z = Mathf.Max(zmin0, Mathf.Min(zmax0, c0.z));
		
		wmb.Transform3x4(cp);
		wmb.Transform3x4(c0);
		
		var r : Float32 = rv0.length*0.5;
		var d : Float32 = Vector3.Distance(cp, c0);
		
		c.depth = d-r;		
		if (c.depth < 0.0)
		{	
			c.point.Set3(cp);			
			c.normal.x = c0.x - cp.x;
			c.normal.y = c0.y - cp.y;
			c.normal.z = c0.z - cp.z;			
			c.normal.Normalize();
		}				
	}
	
}