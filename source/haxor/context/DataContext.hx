package haxor.context;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.physics.Collision;
import haxor.platform.Types.Float32;

/**
 * Class to help optimize data manipulation by creating cached temporaries of it.s
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class DataContext
{
	/**
	 * Max temp vars.
	 */
	static private var MAX_TEMP : Int = 128;
	
	/**
	 * Temp aux vars of Int.
	 */
	private var i : Array<Int>;
	
	
	/**
	 * Temp aux vars of Floats.
	 */
	private var v : Array<Float32>;
	
	
	/**
	 * Temp aux vars of Vector2.
	 */
	private var v2(get_v2, null):Vector2; 
	private inline function get_v2():Vector2 { return m_v2[m_nv2 = (m_nv2 + 1) % m_v2.length]; }
	private var m_v2 : Array<Vector2>;
	private var m_nv2 : Int;
	
	/**
	 * Temp aux vars of Vector3.
	 */
	private var v3(get_v3, null):Vector3; 
	private inline function get_v3():Vector3 { return m_v3[m_nv3 = (m_nv3 + 1) % m_v3.length]; }
	private var m_v3 : Array<Vector3>;
	private var m_nv3 : Int;
	
	/**
	 * Temp aux vars of Vector4.
	 */
	private var v4(get_v4, null):Vector4; 
	private inline function get_v4():Vector4 { return m_v4[m_nv4 = (m_nv4 + 1) % m_v4.length]; }
	private var m_v4 : Array<Vector4>;
	private var m_nv4 : Int;
	
	/**
	 * Temp aux vars of Color.
	 */
	private var c(get_c, null):Color; 
	private inline function get_c():Color { return m_c[m_nc = (m_nc + 1) % m_c.length]; }
	private var m_c : Array<Color>;
	private var m_nc : Int;
	
	/**
	 * Temp aux vars of Quaternion.
	 */
	private var q(get_q, null):Quaternion; 
	private inline function get_q():Quaternion { return m_q[m_nq = (m_nq + 1) % m_q.length]; }
	private var m_q : Array<Quaternion>;
	private var m_nq : Int;
	
	/**
	 * Temp aux vars of AABB3.
	 */
	private var aabb3(get_aabb3, null):AABB3; 
	private inline function get_aabb3():AABB3 { return m_aabb3[m_naabb3 = (m_naabb3 + 1) % m_aabb3.length]; }
	private var m_aabb3 : Array<AABB3>;
	private var m_naabb3 : Int;
	
	/**
	 * Temp aux vars of AABB2.
	 */
	private var aabb2(get_aabb2, null):AABB2; 
	private inline function get_aabb2():AABB2 { return m_aabb2[m_naabb2 = (m_naabb2 + 1) % m_aabb2.length]; }
	private var m_aabb2 : Array<AABB2>;
	private var m_naabb2 : Int;
	
	/**
	 * Temp aux vars for collision data.
	 */
	private var collision(get_collision, null):Collision; 
	private inline function get_collision():Collision { return m_collision[m_ncollision = (m_ncollision + 1) % m_collision.length]; }
	private var m_collision : Array<Collision>;
	private var m_ncollision : Int;
	
	/**
	 * Temp aux vars of Quaternion.
	 */
	private var m4(get_m4, null):Matrix4; 
	private inline function get_m4():Matrix4 { return m_m4[m_nq = (m_nm4 + 1) % m_m4.length]; }
	private var m_m4 : Array<Matrix4>;
	private var m_nm4 : Int;
	
	private var m4l : Array<Float32>;
	
	private function new() 
	{
		i	 	    = [];
		v 		    = [];
		m_v2 	    = [];
		m_v3 	    = [];
		m_v4 	    = [];
		m_c 	    = [];
		m_q 	    = [];
		m_m4	    = [];
		m_aabb3     = [];
		m_aabb2     = [];
		m_collision = [];
		
		m_nv2 	     = 0;
		m_nv3 	     = 0;
		m_nv4 	     = 0;
		m_nc 	     = 0;
		m_nq 	     = 0;
		m_nm4	     = 0;
		m_naabb3     = 0;
		m_naabb2     = 0;
		m_ncollision = 0;
		
		m4l	    = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
		
		for (k in 0...MAX_TEMP)
		{
			i.push(0);
			v.push(0.0);
			m_v2.push(Vector2.zero);
			m_v3.push(Vector3.zero);
			m_v4.push(Vector4.zero);
			m_c.push(Color.black);
			m_q.push(Quaternion.identity);
			m_m4.push(Matrix4.identity);
			m_aabb3.push(AABB3.empty);
			m_aabb2.push(AABB2.empty);
			m_collision.push(new Collision());
		}
	}
	
	
}