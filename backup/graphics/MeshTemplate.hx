/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics;

import haxe.io.Bytes;
import haxe.io.BytesOutput;
import js.html.ArrayBufferView;
import js.html.Float32Array;
import js.html.Int16Array;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.graphics.Mesh;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MeshTemplate<VL,NL,UL0,UL1,TL,BL> extends Mesh
{
	
	public var vertex(get_vertex, set_vertex) : Array<VL>;
	private function get_vertex() : Array<VL> 			 { var s : Int = ElementSize("vertex"); if (s <= 0) return []; return cast F32ToV(cast Get("vertex"), s); }
	private function set_vertex(v : Array<VL>):Array<VL> 
	{ 
		Set("vertex", v); 
		return v; 
	}
	
	public var normal(get_normal, set_normal) : Array<NL>;
	private function get_normal() : Array<NL> 			 { var s : Int = ElementSize("normal"); if (s <= 0) return []; return cast F32ToV(cast Get("normal"), s); }
	private function set_normal(v : Array<NL>):Array<NL> { Set("normal", v); return v; }
	
	public var color(get_color, set_color) : Array<Color>;
	private function get_color() : Array<Color> { return F32ToC(cast Get("color")); }
	private function set_color(v : Array<Color>):Array<Color> { Set("color", v); return v; }
	
	public var uv0(get_uv0, set_uv0) : Array<UL0>;
	private function get_uv0() : Array<UL0> 			 { var s : Int = ElementSize("uv0"); if (s <= 0) return []; return cast F32ToV(cast Get("uv0"), s); }
	private function set_uv0(v : Array<UL0>):Array<UL0>  { Set("uv0", v); return v; }
	
	public var uv1(get_uv1, set_uv1) : Array<UL1>;
	private function get_uv1() : Array<UL1> 			 { var s : Int = ElementSize("uv1"); if (s <= 0) return []; return cast F32ToV(cast Get("uv1"), s); }
	private function set_uv1(v : Array<UL1>):Array<UL1>  { Set("uv1", v); return v; }
	
	public var tangent(get_tangent, set_tangent) : Array<TL>;
	private function get_tangent() : Array<TL> 			  { var s : Int = ElementSize("tangent"); if (s <= 0) return []; return cast F32ToV(cast Get("tangent"), s); }
	private function set_tangent(v : Array<TL>):Array<TL> { Set("tangent", v); return v; }
	
	public var binormal(get_binormal, set_binormal) : Array<BL>;
	private function get_binormal() : Array<BL> 			  { var s : Int = ElementSize("binormal"); if (s <= 0) return []; return cast F32ToV(cast Get("binormal"), s); }
	private function set_binormal(v : Array<BL>):Array<BL> 	  { Set("binormal", v); return v; }
	
	
	override public function GenerateBounds():Void
	{		
		var f : Float32Array = cast Get("vertex");
		if (f == null) return;
		var step : Int = ElementSize("vertex");
		if (step <= 0) return;
		var b : AABB3 = AABB3.empty;
		var i:Int = step;		
		var vx : Float = step > 0 ? f[0] : 0;
		var vy : Float = step > 1 ? f[1] : 0;
		var vz : Float = step > 2 ? f[2] : 0;		
		b.xMin = b.xMax = vx;
		b.yMin = b.yMax = vy;
		b.zMin = b.zMax = vz;		
		while (i < f.length)
		{
			vx = step > 0 ? f[i]   : 0;
			vy = step > 1 ? f[i+1] : 0;
			vz = step > 2 ? f[i+2] : 0;
			b.Encapsulate3(vx, vy, vz);
			i += step;
		}
		m_bounds = b;
	}
	
	
	
}

class SkinnedMesh3 extends Mesh3
{
	public var binds(get_binds, set_binds) : Array<Matrix4>;
	private function get_binds() : Array<Matrix4> { return m_binds; }
	private function set_binds(v : Array<Matrix4>):Array<Matrix4> { m_binds = v.copy(); return v; }
	private var m_binds : Array<Matrix4>;
	
	public var bone(get_bone, set_bone) : Array<Vector4>;
	private function get_bone() : Array<Vector4> { return F32ToV4(cast Get("bone")); }
	private function set_bone(v : Array<Vector4>):Array<Vector4> { Set("bone", v); return v; }
	
	public var weight(get_weight, set_weight) : Array<Vector4>;
	private function get_weight() : Array<Vector4> { return F32ToV4(cast Get("weight")); }
	private function set_weight(v : Array<Vector4>):Array<Vector4> { Set("weight", v); return v; }
	
	
}

class Mesh2D extends MeshTemplate<Vector2,Vector3,Vector2,Vector2,Vector3,Vector3> { }

class Mesh23 extends MeshTemplate<Vector2,Vector3,Vector3,Vector3,Vector3,Vector3> { }

class Mesh2 extends MeshTemplate<Vector3,Vector3,Vector2,Vector2,Vector3,Vector3> { }

class Mesh3 extends MeshTemplate < Vector3, Vector3, Vector3, Vector3, Vector3, Vector3 > { }

class Mesh4 extends MeshTemplate<Vector3,Vector3,Vector4,Vector4,Vector3,Vector3> { }