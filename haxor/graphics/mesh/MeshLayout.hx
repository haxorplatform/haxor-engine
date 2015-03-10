package haxor.graphics.mesh;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.graphics.mesh.Mesh;
import haxor.io.FloatArray;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;


/**
 * Class that describes a configurable Mesh layout with the parameters for vertex,color,normal,uv0,uv1,Tangent and Binormal
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MeshLayout<VL,NL,UL0,UL1,TL,BL> extends Mesh
{
	/**
	 * Array of vertex data.
	 */
	public var vertex(get_vertex, set_vertex) : Array<VL>;
	private function get_vertex() : Array<VL> { return m_vertex; }	
	private function set_vertex(v : Array<VL>):Array<VL> { return m_vertex = UpdateAttribute("vertex",v,false); }
	private var m_vertex : Array<VL>;
	
	/**
	 * Array of normal data.
	 */
	public var normal(get_normal, set_normal) : Array<NL>;
	private function get_normal() : Array<NL> 			 { return m_normal; }
	private function set_normal(v : Array<NL>):Array<NL> { return m_normal = UpdateAttribute("normal",v,false); }
	private var m_normal : Array<NL>;
	
	
	/**
	 * Array of color data.
	 */
	public var color(get_color, set_color) : Array<Color>;
	private function get_color() : Array<Color> { return m_color; }
	private function set_color(v : Array<Color>):Array<Color> { return m_color = UpdateAttribute("color",v,true); }
	private var m_color : Array<Color>;
	
	/**
	 * Array of uv0 data.
	 */
	public var uv0(get_uv0, set_uv0) : Array<UL0>;
	private function get_uv0() : Array<UL0> 			 { return m_uv0; }
	private function set_uv0(v : Array<UL0>):Array<UL0>  { return m_uv0 = UpdateAttribute("uv0",v,false); }
	private var m_uv0 : Array<UL0>;
	
	/**
	 * Array of uv1 data.
	 */
	public var uv1(get_uv1, set_uv1) : Array<UL1>;
	private function get_uv1() : Array<UL1> 			 { return m_uv1; }
	private function set_uv1(v : Array<UL1>):Array<UL1>  { return m_uv1 = UpdateAttribute("uv1",v,false); }
	private var m_uv1 : Array<UL1>;
	
	/**
	 * Array of tangent data.
	 */
	public var tangent(get_tangent, set_tangent) : Array<TL>;
	private function get_tangent() : Array<TL> 			  { return m_tangent; }
	private function set_tangent(v : Array<TL>):Array<TL> { return m_tangent = UpdateAttribute("tangent",v,false); }
	private var m_tangent : Array<TL>;
	
	/**
	 * Array of binormal data.
	 */
	public var binormal(get_binormal, set_binormal) : Array<BL>;
	private function get_binormal() : Array<BL> 			  { return m_binormal; }
	private function set_binormal(v : Array<BL>):Array<BL> 	  { return m_binormal = UpdateAttribute("binormal",v,false); }
	private var m_binormal : Array<BL>;
	
	override function new(p_name:String=""):Void
	{
		super(p_name);
		m_vertex 	= [];
		m_normal 	= [];
		m_color  	= [];
		m_uv0	 	= [];
		m_uv1 		= [];
		m_tangent 	= [];
		m_binormal 	= [];
	}
	
	/**
	 * Generates this Mesh bounds using the 'vertex' attribute. Stores the result in the 'bounds' variable.
	 */
	public function GenerateBounds():Void
	{		
		GenerateAttribBounds("vertex", m_bounds);
		
	}
	
	/**
	 * Updates the chosen attribute with the hi-level data array.
	 */
	private function UpdateAttribute<T>(p_name:String, p_list : Array<T>,p_is_color:Bool=false):Array<T>
	{
		if (p_list == null) 	{ Remove(p_name); return []; }		
		if (p_list.length <= 0) { Remove(p_name); return []; }		
		var a : MeshAttrib = GetAttribute(p_name);		
		var off : Int = 1;		
		if (Std.is(p_list[0], Vector2)) off = 2;
		if (Std.is(p_list[0], Vector3)) off = 3;
		if (Std.is(p_list[0], Vector4)) off = 4;
		if (Std.is(p_list[0], Color)) 	off = 4;			
		if (a == null) a = Set(p_name, new FloatArray(1), off);		
		
		var p : Int = 0;
		var f : FloatArray 	= cast a.data = new FloatArray(p_list.length * off);		
		//trace(name+" a[" + p_name+"] off[" + off + "] len[" + f.length + "]");
		for (i in 0...p_list.length)
		{
			var it : T = p_list[i];
			switch(off)
			{
				case 1:	var v  : Float32 	 = cast it; 	f.Set(p++, v);			
				case 2:	var v2 : Vector2 = cast it;  f.Set(p++, v2.x); f.Set(p++, v2.y);
				case 3:	var v3 : Vector3 = cast it;  f.Set(p++, v3.x); f.Set(p++, v3.y); f.Set(p++, v3.z);
				case 4:	
				if (p_is_color) 
				{ var c : Color = cast it;  f.Set(p++, c.r); f.Set(p++, c.g); f.Set(p++, c.b); f.Set(p++, c.a); }
				else
				{ var v4:Vector4 = cast it; f.Set(p++,v4.x); f.Set(p++, v4.y); f.Set(p++, v4.z); f.Set(p++, v4.w); }
			}
		}
		
		Set(p_name, f, off);
		
		return p_list;
	}
	
}

class SkinnedMesh3 extends Mesh3
{
	public var binds(get_binds, set_binds) : Array<Matrix4>;
	private function get_binds() : Array<Matrix4> { return m_binds; }
	private function set_binds(v : Array<Matrix4>):Array<Matrix4> { m_binds = v.copy(); return v; }
	private var m_binds : Array<Matrix4>;
	
	public var bone(get_bone, set_bone) : Array<Vector4>;
	private function get_bone() : Array<Vector4> { return m_bone; }
	private function set_bone(v : Array<Vector4>):Array<Vector4> { return m_bone = UpdateAttribute("bone",v,false); }
	private var m_bone:Array<Vector4>;
	
	public var weight(get_weight, set_weight) : Array<Vector4>;
	private function get_weight() : Array<Vector4> { return m_weight; }
	private function set_weight(v : Array<Vector4>):Array<Vector4> { return m_weight = UpdateAttribute("weight",v,false); }
	private var m_weight : Array<Vector4>;
	
	
}

class Mesh2D extends MeshLayout<Vector2,Vector3,Vector2,Vector2,Vector3,Vector3> { }

class Mesh23 extends MeshLayout<Vector2,Vector3,Vector3,Vector3,Vector3,Vector3> { }

class Mesh2 extends MeshLayout<Vector3,Vector3,Vector2,Vector2,Vector3,Vector3> { }

class Mesh3 extends MeshLayout < Vector3, Vector3, Vector3, Vector3, Vector3, Vector3 > { }

class Mesh4 extends MeshLayout<Vector3,Vector3,Vector4,Vector4,Vector3,Vector3> { }