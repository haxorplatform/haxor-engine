package haxor.component.physics;
import haxor.component.Behaviour;
import haxor.component.physics.Collider;
import haxor.core.Enums.ColliderType;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;



/**
 * Class that describes an oriented bounding box.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class BoxCollider extends Collider
{
	/**
	 * Collider center relative to the local coords of the Transform.
	 */
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Vector3.temp.Set(m_center.x, m_center.y, m_center.z); }
	private function set_center(v:Vector3):Vector3 { m_center.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_center : Vector3;
	
	/**
	 * Collider size.
	 */
	public var size(get_size, set_size):Vector3;
	private function get_size():Vector3 { return Vector3.temp.Set(m_size.x, m_size.y, m_size.z); }
	private function set_size(v:Vector3):Vector3 { m_size.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_size : Vector3;
	
	/**
	 * Method called after creation.
	 */
	override function OnBuild():Void 
	{
		m_type   = ColliderType.Box;
		super.OnBuild();
		m_center = Vector3.zero;
		m_size   = Vector3.one;				
	}
	
	/**
	 * 
	 */
	override private function GenerateSphere():Void
	{
		var v : Vector4 = m_sphere;
		var wm : Matrix4 = transform.WorldMatrix;
		var c : Vector3 = Vector3.temp.Set(m_center.x, m_center.y, m_center.z);
		wm.Transform3x4(c);
		v.x = c.x;		
		v.y = c.y;		
		v.z = c.z;
		wm 	= Matrix4.GetScale(wm, Matrix4.temp.SetIdentity());
		v.w = Mathf.Max(wm.m00, Mathf.Max(wm.m11, wm.m22)) * m_size.length;		
	}
	
	/**
	 * 
	 */
	override private function GenerateAABB():Void
	{
		var b : AABB3	 	= m_aabb;		
		var wm : Matrix4 	= transform.WorldMatrix;
		var c : Vector3 	= Vector3.temp.Set(m_center.x, m_center.y, m_center.z);		
		var hx : Float32      = m_size.x * 0.5;
		var hy : Float32      = m_size.y * 0.5;
		var hz : Float32      = m_size.z * 0.5;		
		var vx : Vector3    = Vector3.temp.Set(hx * wm.m00, hx * wm.m10, hx * wm.m20);
		var vy : Vector3    = Vector3.temp.Set(hy * wm.m01, hy * wm.m11, hy * wm.m21);
		var vz : Vector3    = Vector3.temp.Set(hz * wm.m02, hz * wm.m12, hz * wm.m22);		
		wm.Transform3x4(c);		
		b.xMin = b.xMax = c.x;
		b.yMin = b.yMax = c.y;
		b.zMin = b.zMax = c.z;		
		b.Encapsulate3(c.x + vx.x + vy.x + vz.x,   c.y + vx.y +  vy.y + vz.y,   c.z + vx.z + vy.z + vz.z);
		b.Encapsulate3(c.x - vx.x + vy.x + vz.x,   c.y - vx.y +  vy.y + vz.y,   c.z - vx.z + vy.z + vz.z);
		b.Encapsulate3(c.x + vx.x - vy.x + vz.x,   c.y + vx.y -  vy.y + vz.y,   c.z + vx.z - vy.z + vz.z);
		b.Encapsulate3(c.x - vx.x - vy.x + vz.x,   c.y - vx.y -  vy.y + vz.y,   c.z - vx.z - vy.z + vz.z);		
		b.Encapsulate3(c.x + vx.x + vy.x - vz.x,   c.y + vx.y +  vy.y - vz.y,   c.z + vx.z + vy.z - vz.z);
		b.Encapsulate3(c.x - vx.x + vy.x - vz.x,   c.y - vx.y +  vy.y - vz.y,   c.z - vx.z + vy.z - vz.z);
		b.Encapsulate3(c.x + vx.x - vy.x - vz.x,   c.y + vx.y -  vy.y - vz.y,   c.z + vx.z - vy.z - vz.z);
		b.Encapsulate3(c.x - vx.x - vy.x - vz.x,   c.y - vx.y -  vy.y - vz.y,   c.z - vx.z - vy.z - vz.z);		
	}
	//*/
}