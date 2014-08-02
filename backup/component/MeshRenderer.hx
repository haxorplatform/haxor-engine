/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.component;

import haxor.core.Entity;
import haxor.core.Time;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.graphics.Mesh;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class MeshRenderer extends Renderer
{
	static public var list(get_list, never):Array<MeshRenderer>;
	static private function get_list():Array<MeshRenderer> { return (m_list == null) ? (m_list = []) : m_list; }
	static private var m_list : Array<MeshRenderer>;
	
	static var m_next_cull_test : Int=0;
	
	
	
	/**
	 * 
	 */
	public var mesh (get_mesh, set_mesh) : Mesh;
	private var m_mesh : Mesh;
	function get_mesh():Mesh { return m_mesh; }
	function set_mesh(v:Mesh):Mesh { m_mesh = v; return v; }
	
	public var visible : Bool;
	
	private var m_culled : Map<Camera,Bool>;
	
	function new(p_entity : Entity) 
	{
		super(p_entity);		
		list.push(this);
		m_culled = new Map<Camera,Bool>();
		visible = true;
	}
	static public var log : String = "";
	
	private function CheckCulling():Bool
	{
		
		//Needs revision
		if (m_mesh == null) return false;
		var c : Camera 	 = Camera.current;
		var b : AABB3  	 = m_mesh.bounds;
		var p : Vector3  = Vector3.temp;		
		var ic : Bool    = m_culled.exists(c) ? m_culled.get(c) : true;
			
		var wm : Matrix4 = transform.m_worldMatrix;
		
		var p0 : Vector4;
		var p1 : Vector4;
		var p2 : Vector4;
		var p3 : Vector4;
		var p4 : Vector4;
		var p5 : Vector4;
		var p6 : Vector4;
		var p7 : Vector4;
		
		
		p.x = b.xMin; p.y = b.yMin; p.z = b.zMin; wm.Transform3x4(p); p0 = c.WorldToProjection(p); //if (!p0.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMin; p.z = b.zMin; wm.Transform3x4(p); p1 = c.WorldToProjection(p); //if (!p1.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMax; p.z = b.zMin; wm.Transform3x4(p); p2 = c.WorldToProjection(p); //if (!p2.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMax; p.z = b.zMin; wm.Transform3x4(p); p3 = c.WorldToProjection(p); //if (!p3.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMin; p.z = b.zMax; wm.Transform3x4(p); p4 = c.WorldToProjection(p); //if (!p4.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMin; p.z = b.zMax; wm.Transform3x4(p); p5 = c.WorldToProjection(p); //if (!p5.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMin; p.y = b.yMax; p.z = b.zMax; wm.Transform3x4(p); p6 = c.WorldToProjection(p); //if (!p6.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }		
		p.x = b.xMax; p.y = b.yMax; p.z = b.zMax; wm.Transform3x4(p); p7 = c.WorldToProjection(p); //if (!p7.IsCulled()) { if (ic) CallOnVisible(); return visible = true; }
		
		 var iw0 : Float = 1.0 / Mathf.Abs(p0.w);
		 var iw1 : Float = 1.0 / Mathf.Abs(p1.w);
		 var iw2 : Float = 1.0 / Mathf.Abs(p2.w);
		 var iw3 : Float = 1.0 / Mathf.Abs(p3.w);
		 var iw4 : Float = 1.0 / Mathf.Abs(p4.w);
		 var iw5 : Float = 1.0 / Mathf.Abs(p5.w);
		 var iw6 : Float = 1.0 / Mathf.Abs(p6.w);
		 var iw7 : Float = 1.0 / Mathf.Abs(p7.w);
		 
		var v : Float;
						
		v = Mathf.Max([p0.z * iw0, p1.z * iw1, p2.z * iw2, p3.z * iw3, p4.z * iw4, p5.z * iw5, p6.z * iw6, p7.z * iw7]);  if (v < -1.0) return visible = false;
		
		v = Mathf.Min([p0.x * iw0, p1.x * iw1, p2.x * iw2, p3.x * iw3, p4.x * iw4, p5.x * iw5, p6.x * iw6, p7.x * iw7]);  if (v >  1.0) return visible = false;
		v = Mathf.Max([p0.x * iw0, p1.x * iw1, p2.x * iw2, p3.x * iw3, p4.x * iw4, p5.x * iw5, p6.x * iw6, p7.x * iw7]);  if (v < -1.0) return visible = false;
		
		v = Mathf.Min([p0.y * iw0, p1.y * iw1, p2.y * iw2, p3.y * iw3, p4.y * iw4, p5.y * iw5, p6.y * iw6, p7.y * iw7]);  if (v >  1.0) return visible = false;
		v = Mathf.Max([p0.y * iw0, p1.y * iw1, p2.y * iw2, p3.y * iw3, p4.y * iw4, p5.y * iw5, p6.y * iw6, p7.y * iw7]);  if (v < -1.0) return visible = false;
		
		v = Mathf.Min([p0.z * iw0, p1.z * iw1, p2.z * iw2, p3.z * iw3, p4.z * iw4, p5.z * iw5, p6.z * iw6, p7.z * iw7]);  if (v >  1.0) return visible = false;
		
		
		return visible = true;
		
		/*
		if (!CanBeCulled(p0, p2)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p1, p3)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p4, p6)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p5, p7)) { if (ic) CallOnVisible(); return visible = true; }		
		if (!CanBeCulled(p0, p1)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p1, p5)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p5, p4)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p4, p0)) { if (ic) CallOnVisible(); return visible = true; }		
		if (!CanBeCulled(p2, p3)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p3, p7)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p7, p6)) { if (ic) CallOnVisible(); return visible = true; }
		if (!CanBeCulled(p6, p2)) { if (ic) CallOnVisible(); return visible = true; }		
		//*/
		
		if (!ic) CallOnInvisible();
		visible = false;
		return false;
		
	}
	
	private function CallOnVisible():Void 
	{		
		var c : Camera = Camera.current;
		m_culled.set(c, false);
		
	}
	
	private function CallOnInvisible():Void 
	{		
		var c : Camera = Camera.current;
		m_culled.set(c, true);
		
	}
	
	private function CanBeCulled(p_a : Vector4,p_b : Vector4):Bool
	{
		//Ignores Z
		var a : Float;
		var b : Float;				
		var iwa : Float = p_a.w <= 0.0 ? -100.0 : (1.0 / p_a.w);
		var iwb : Float = p_b.w <= 0.0 ? -100.0 : (1.0 / p_b.w);
		var va  : Float;
		var vb  : Float;
		
		va = p_a.x * iwa; vb = p_b.x * iwb;		a = Mathf.Min([va, vb]);		b = Mathf.Max([va, vb]);		if (b < -1) return true;		if (a >  1) return true;		
		va = p_a.y * iwa; vb = p_b.y * iwb;		a = Mathf.Min([va, vb]);		b = Mathf.Max([va, vb]);		if (b < -1) return true;		if (a >  1) return true;
		va = p_a.z * iwa; vb = p_b.z * iwb;		a = Mathf.Min([va, vb]);		b = Mathf.Max([va, vb]);		if (b < -1) return true;		if (a >  1) return true;
		
		return false;
	}
	
	/**
	 * 
	 */
	override public function OnRender() : Void 
	{
		var m : Mesh = mesh;
		if (m == null) return;
		Graphics.Render(Camera.current,entity.transform, mesh,material);
	}
	
}