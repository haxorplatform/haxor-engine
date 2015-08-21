package haxor.component.physics;
import haxor.component.Behaviour;
import haxor.component.physics.Collider;
import haxor.core.Console;
import haxor.core.Enums.ColliderType;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class SphereCollider extends Collider
{
	
	/**
	 * Center of the sphere in local coordinates.
	 */
	@serialize
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Vector3.temp.Set(m_center.x, m_center.y, m_center.z); }
	private function set_center(v:Vector3):Vector3 { m_center.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_center : Vector3;
	
	/**
	 * Radius of the sphere.
	 */
	@serialize
	public var radius(get_radius, set_radius):Float;
	private function get_radius():Float32 { return m_radius; }
	private function set_radius(v:Float32):Float { m_radius=v; Refresh(); return v; }
	private var m_radius : Float32;
	
	/**
	 * Method called after creation.
	 */
	override function OnBuild():Void 
	{
		m_type = ColliderType.Sphere;
		super.OnBuild();
		m_center = Vector3.zero;
		m_radius = 1.0;		
		Refresh();
	}
	
	/**
	 * Generates the world space sphere bounding.
	 */
	override private function GenerateSphere():Void 
	{
		var res : Vector4 = m_sphere;
		var wm : Matrix4 = transform.WorldMatrix;
		var c : Vector3 = Vector3.temp.Set3(m_center);
		wm.Transform3x4(c);
		res.Set3(c);
		wm 	= Matrix4.GetScale(wm, Matrix4.temp);
		res.w = Mathf.Max(wm.m00, Mathf.Max(wm.m11, wm.m22)) * m_radius;		
	}
	
	/**
	 * Generates the world space aabb.
	 * @return
	 */
	override private function GenerateAABB():Void 
	{
		var b : AABB3	 	= m_aabb;
		var wm : Matrix4 	= transform.WorldMatrix;		
		var r : Float32     = radius * 0.5773507;
		var c : Vector3 	= Vector3.temp.Set(r,r,r);
		wm.Transform3x3(c); 		
		r = c.length*0.5;		
		c.Set3(m_center);
		wm.Transform3x4(c);				
		b.Set( -r + c.x, r + c.x, -r + c.y, r + c.y, -r + c.z, r + c.z);				
	}	
}