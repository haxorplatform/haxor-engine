/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.physics;
import haxor.component.Behaviour;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.physics.Collider;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class BoxCollider extends Collider
{
	
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Vector3.temp.Set(m_center.x, m_center.y, m_center.z); }
	private function set_center(v:Vector3):Vector3 { m_center.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_center : Vector3;
	
	public var size(get_size, set_size):Vector3;
	private function get_size():Vector3 { return Vector3.temp.Set(m_size.x, m_size.y, m_size.z); }
	private function set_size(v:Vector3):Vector3 { m_size.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_size : Vector3;
	
	function new(p_entity) 
	{
		m_center = Vector3.zero;
		m_size   = Vector3.one;
		super(p_entity);		
		m_primitive = ColliderPrimitive.Box;
	}
	
	override private function GenerateBoundSphere():Void
	{
		var v : Vector4 = m_boundSphere;
		var wm : Matrix4 = transform.m_worldMatrix;
		var c : Vector3 = Vector3.temp.Set(m_center.x, m_center.y, m_center.z);
		wm.Transform3x4(c);
		v.x = c.x;		
		v.y = c.y;		
		v.z = c.z;
		wm 	= wm.scale;
		v.w = Math.max(wm.m00, Math.max(wm.m11, wm.m22)) * m_size.length;		
	}
	
	override private function GenerateBoundAABB():Void
	{
		var b : AABB3	 	= m_boundAABB;		
		var wm : Matrix4 	= transform.m_worldMatrix;
		var c : Vector3 	= Vector3.temp.Set(m_center.x, m_center.y, m_center.z);		
		var hx : Float      = m_size.x * 0.5;
		var hy : Float      = m_size.y * 0.5;
		var hz : Float      = m_size.z * 0.5;		
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
	
}