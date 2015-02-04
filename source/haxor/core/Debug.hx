package haxor.core;
import haxor.component.MeshRenderer;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.SphereCollider;
import haxor.component.Transform;
import haxor.core.Enums.ColliderType;
import haxor.graphics.Gizmo;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

/**
 * Class that implements helper methods for debugging.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Debug
{
	
	/**
	 * 
	 */
	static public var collider : Bool;
	
	/**
	 * 
	 */
	static public var colliderAABB : Bool;
	
	/**
	 * 
	 */
	static public var colliderSB : Bool;

	
	/**
	 * 
	 */
	static public var transform : Bool;
	
	/**
	 * 
	 */
	static public var renderer : Bool;
	
	
	static private var color_white     : Color = Color.white;
	static private var color_collider  : Color = Color.green50;
	static private var color_trigger   : Color = Color.red50;
	static private var color_bounding  : Color = Color.blue30;
	static private var color_renderer  : Color = Color.blue50;
	
	/**
	 * 
	 */
	static private function Initialize():Void
	{
		collider  = false;
		colliderAABB      = false;
		colliderSB    = false;
		transform = false;
		renderer  = false;
	}
	
	/**
	 * Draws the collider gizmo.
	 * @param	c
	 */
	static public function Collider(c : Collider):Void
	{
		var t : Transform = c.transform;
		var wm : Matrix4 = t.WorldMatrix;
		var bc : BoxCollider;
		var sc : SphereCollider;
		var o : Vector3 = Vector3.temp.Set();
		var cl : Color = c.trigger ? color_trigger : color_collider;
		
		cl.a = c.enabled ? 1.0 : 0.01;
		
		switch(c.type)
		{
			case ColliderType.Box:
				bc = cast c;
				o.Set3(bc.m_center);
				Gizmo.WireCube(o, bc.m_size, cl, wm);
				
			case ColliderType.Sphere:
				sc = cast c;
				var rad : Vector3 = Vector3.temp.Set(0.5773507, 0.5773507,0.5773507);
				var sm : Matrix4 = Matrix4.GetScale(wm, Matrix4.temp);
				sm.Transform3x3(rad);				
				o.Set3(sc.m_center);
				Gizmo.WireSphere(o, rad.length * sc.radius, cl, wm);				
				
			case ColliderType.Point:
			case ColliderType.Plane:
			case ColliderType.Mesh:
			case ColliderType.Capsule:				
		}
	}
	
	/**
	 * 
	 * @param	c
	 */
	static public function BoundingAABB(c:Collider):Void
	{
		var bb : AABB3 = c.aabb;		
		Gizmo.WireCube(bb.center, bb.size, color_bounding);
	}
	
	/**
	 * 
	 * @param	c
	 */
	static public function BoundingSphere(c:Collider):Void
	{
		var sb : Vector4 = c.sphere;
		Gizmo.WireSphere(Vector3.temp.Set(sb.x,sb.y,sb.z), sb.w, color_bounding);
	}
	
	/**
	 * 
	 * @param	r
	 */
	static public function MeshRenderer(r : MeshRenderer):Void
	{
		var bb : AABB3 = r.mesh.m_bounds;
		Gizmo.WireCube(bb.center, bb.size, color_renderer,r.transform.WorldMatrix);
	}
	
	/**
	 * Draws the transform axis.
	 * @param	t
	 */
	static public function Transform(t : Transform):Void
	{
		Gizmo.Axis(Vector3.temp.Set(), Vector3.temp.Set(1, 1, 1), color_white, t.WorldMatrix);
	}
}