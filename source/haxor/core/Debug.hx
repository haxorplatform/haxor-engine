package haxor.core;
import haxor.component.Camera;
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
	
	/**
	 * 
	 */
	static public var rendererAABB : Bool;
	
	
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
		rendererAABB = false;
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
	static public function BoundingAABB(c:AABB3):Void
	{
		var bb : AABB3 = c;		
		Gizmo.WireCube(bb.center, bb.size, color_bounding);
	}
	
	/**
	 * 
	 * @param	c
	 */
	static public function BoundingSphere(c:Vector4):Void
	{
		var sb : Vector4 = c;
		Gizmo.WireSphere(Vector3.temp.Set(sb.x,sb.y,sb.z), sb.w, color_bounding);
	}
	
	/**
	 * 
	 * @param	r
	 */
	static public function MeshRenderer(r : MeshRenderer):Void
	{
		var bb : AABB3 = r.mesh.m_bounds;
		var c : Color = Color.temp.SetColor(color_renderer);
		c.a = r.visible ? 1.0 : 0.2;
		Gizmo.WireCube(bb.center, bb.size, c, r.transform.WorldMatrix);
		
		if (rendererAABB)
		{
			bb = r.m_aabb;
			c = Color.temp.SetColor(color_bounding);
			c.a = r.visible ? 1.0 : 0.2;
			Gizmo.WireCube(bb.center, bb.size, c);
		}
		
	}
	
	/**
	 * Draws the transform axis.
	 * @param	t
	 */
	static public function Transform(t : Transform):Void
	{
		Gizmo.Axis(Vector3.temp.Set(), Vector3.temp.Set(0.5, 0.5, 0.5), color_white, t.WorldMatrix);
	}
	
	/**
	 * Draws the camera frustum.
	 * @param	c
	 */
	static public function Camera(c: Camera):Void
	{
		
		Debug.Transform(c.transform);
		Debug.Transform(c.transform.parent);
		
		var fp : Array<Vector4> = c.m_frustum;		
		var l : Array<Vector4> = [];
		for (i in 0...fp.length)
		{
			l.push(Vector4.temp.Set4(fp[i]));
			c.CameraToWorld.Transform4x4(l[i]);
		}
		fp = l;
		
		var p0 : Vector3 = Vector3.temp;
		var p1 : Vector3 = Vector3.temp;
		
		p0.Set4(fp[0]); p1.Set4(fp[1]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[1]); p1.Set4(fp[2]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[2]); p1.Set4(fp[3]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[3]); p1.Set4(fp[0]); Gizmo.Line(p0, p1, color_white);
		
		p0.Set4(fp[4]); p1.Set4(fp[5]); Gizmo.Line(p0, p1, color_white);		
		p0.Set4(fp[5]); p1.Set4(fp[6]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[6]); p1.Set4(fp[7]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[7]); p1.Set4(fp[4]); Gizmo.Line(p0, p1, color_white);		
		
		p0.Set4(fp[0]); p1.Set4(fp[4]); Gizmo.Line(p0, p1, color_white);		
		p0.Set4(fp[1]); p1.Set4(fp[5]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[2]); p1.Set4(fp[6]); Gizmo.Line(p0, p1, color_white);
		p0.Set4(fp[3]); p1.Set4(fp[7]); Gizmo.Line(p0, p1, color_white);
		//*/
	}
}