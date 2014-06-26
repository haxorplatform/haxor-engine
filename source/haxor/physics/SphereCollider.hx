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
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.physics.Collider;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class SphereCollider extends Collider
{
	
	public var center(get_center, set_center):Vector3;
	private function get_center():Vector3 { return Vector3.temp.Set(m_center.x, m_center.y, m_center.z); }
	private function set_center(v:Vector3):Vector3 { m_center.Set(v.x, v.y, v.z); Refresh(); return v; }
	private var m_center : Vector3;
	
	public var radius(get_radius, set_radius):Float;
	private function get_radius():Float { return m_radius; }
	private function set_radius(v:Float):Float { m_radius=v; Refresh(); return v; }
	private var m_radius : Float;
	
	function new(p_entity) 
	{
		m_center = Vector3.zero;
		m_radius = 1.0;
		super(p_entity);
		m_primitive = ColliderPrimitive.Sphere;
	}
	
	override private function get_boundSphere():Vector4 
	{
		var v : Vector4 = super.get_boundSphere();		
		var wm : Matrix4 = transform.m_worldMatrix;
		var c : Vector3 = Vector3.temp.Set(m_center.x, m_center.y, m_center.z);
		wm.Transform3x4(c);
		v.x = c.x;		
		v.y = c.y;		
		v.z = c.z;
		wm 	= wm.scale;
		v.w = Math.max(wm.m00, Math.max(wm.m11, wm.m22)) * m_radius;
		return v;
	}
	
	override private function get_boundAABB():AABB3 
	{
		var b : AABB3	 	= super.get_boundAABB();		
		var wm : Matrix4 	= transform.m_worldMatrix;		
		var c : Vector3 	= Vector3.temp.Set(0, 0, radius);
		wm.Transform3x3(c); c.y = c.z = c.x = c.length; b.size = c;
		c.Set3(m_center);
		wm.Transform3x4(c);
		b.center = c;
		return b;
	}
	
}