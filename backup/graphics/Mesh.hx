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
import js.html.Uint16Array;
import haxor.api.BufferAPI;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.graphics.Mesh;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * 
 */
enum MeshMode
{
	Static;
	Stream;
	Dynamic;	
}

/**
 * 
 */
enum MeshPrimitive
{
	Points;
	Triangles;
	TriangleStrip;
	TriangleFan;
	Lines;
	LineLoop;
	LineStrip;
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Mesh extends Resource
{
	private var m_buffers : Map<String,ArrayBufferView>;
	
	private var m_sizes : Map<String,Int>;
	
	private var m_locations : Map<String,Int>;
	
	/**
	 * 
	 */
	public var mode(get_mode, set_mode):MeshMode;
	var m_mode : MeshMode;
	function get_mode():MeshMode { return m_mode; }
	function set_mode(v:MeshMode):MeshMode 
	{		
		if (m_mode == v) return v;
		m_mode = v;		
		return v;
	}
	
	/**
	 * 
	 */
	public var primitive(get_primitive, set_primitive):MeshPrimitive;
	var m_primitive : MeshPrimitive;
	function get_primitive():MeshPrimitive { return m_primitive; }
	function set_primitive(v:MeshPrimitive):MeshPrimitive 
	{
		if (m_primitive == v) return v;
		m_primitive = v;		
		return v; 
	}
	
	
	/**
	 * 
	 */
	public var topology(get_topology, set_topology) : Uint16Array;
	private function get_topology():Uint16Array { return m_topology; }
	private function set_topology(v:Uint16Array):Uint16Array { m_topology = v == null ? new Uint16Array([]) : v.subarray(0); m_indexed = m_topology.length > 0; BufferAPI.Apply(this, "$topology"); return m_topology; }
	private var m_topology : Uint16Array;
	
	
	/**
	 * 
	 */
	public var indexed(get_indexed, never) : Bool;
	private function get_indexed():Bool { return m_indexed; }
	private var m_indexed : Bool;
	
	/**
	 * 
	 */
	public var attribs(get_attribs, never) : Array<String>;
	private function get_attribs():Array<String> { return m_attribs.copy(); }
	private var m_attribs : Array<String>;
	
	
	
	/**
	 * 
	 * @param	get_vertexCount
	 * @param	never
	 * @return
	 */
	public var vertexCount(get_vertexCount, never) : Int;
	private function get_vertexCount():Int { return m_vertexCount; }
	private var m_vertexCount : Int;
	
	/**
	 * 
	 */
	public var bounds(get_bounds, set_bounds) : AABB3;
	private var m_bounds : AABB3;
	private function get_bounds():AABB3	{ return m_bounds; }
	private function set_bounds(v:AABB3):AABB3	
	{
		m_bounds.xMin = v.xMin; m_bounds.xMax = v.xMax;
		m_bounds.yMin = v.yMin; m_bounds.yMax = v.yMax;
		m_bounds.zMin = v.zMin; m_bounds.zMax = v.zMax;
		return m_bounds;
	}
	
	
	/**
	 * 
	 */
	public function new() 
	{		
		
		super();				
		m_buffers   = new Map<String,ArrayBufferView>();
		m_sizes     = new Map<String,Int>();
		m_locations = new Map<String,Int>();
		m_attribs = [];	
		m_vertexCount = 0;
		m_topology = new Uint16Array([]);
		m_primitive = MeshPrimitive.Triangles;
		m_mode = MeshMode.Static;
		m_bounds = AABB3.empty;
		m_indexed = false;
		
	}
	
	public function GenerateBounds():Void
	{		
		m_bounds = AABB3.empty;
	}
	
	/**
	 * 
	 * @param	p_attrib
	 */
	public function Update(p_attrib : String):Void
	{
		BufferAPI.Apply(this, p_attrib);
	}
	
	/**
	 * 
	 * @param	p_attrib
	 * @param	p_data
	 */
	public function Set(p_attrib : String, p_data : Dynamic,p_element_size : Int = 0):Void
	{
		Remove(p_attrib);						
		if (p_data.length <= 0) return;
		if (p_data == null)     return;
		
		var f: Float32Array = null;
		if (Std.is(p_data, Float32Array)) 
		{
			f = cast p_data; 
			f = f.subarray(0); 
		}
		else
		if (Std.is(p_data, Array))
		{
			var d : Dynamic = p_data[0];
			if (Std.is(d, Float))   { f =  FToF32(cast p_data); p_element_size = 1; } else
			if (Std.is(d, Vector2)) { f = V2ToF32(cast p_data); p_element_size = 2; } else
			if (Std.is(d, Vector3)) { f = V3ToF32(cast p_data); p_element_size = 3; } else
			if (Std.is(d, Vector4)) { f = V4ToF32(cast p_data); p_element_size = 4; } else
			if (Std.is(d, Color))   { f =  CToF32(cast p_data); p_element_size = 4; }
		}
		
		if (f == null)
		{
			Console.LogWarning("Mesh> Float32Array is null @ attrib["+p_attrib+"]");
			return;
		}
		m_sizes[p_attrib] = p_element_size <= 0 ? 3 : p_element_size;
		m_buffers.set(p_attrib,f);
		m_attribs.push(p_attrib);
		m_vertexCount = -1;
		for (i in 0...m_attribs.length)
		{
			var f : Dynamic = m_buffers.get(m_attribs[i]);
			var len : Int = f.length;			
			var vc : Int = cast (len / m_sizes.get(m_attribs[i]));
			m_vertexCount = m_vertexCount < 0 ? vc : Mathf.MinInt([vc, m_vertexCount]);
		}
		Update(p_attrib);
	}
	
	/**
	 * 
	 * @param	p_attrib
	 * @return
	 */
	public function ElementSize(p_attrib : String) : Int { return m_sizes.exists(p_attrib) ? m_sizes.get(p_attrib) : 0; }
	
	/**
	 * 
	 * @param	p_attrib
	 * @return
	 */
	public function Get(p_attrib : String) : ArrayBufferView { return m_buffers.exists(p_attrib) ? m_buffers.get(p_attrib) : null; }
	
	/**
	 * 
	 * @param	p_attrib
	 */
	public function Remove(p_attrib : String):Void
	{
		if (!m_buffers.exists(p_attrib)) return;		
		m_sizes[p_attrib] = 0;
		m_buffers[p_attrib] = null;
		m_attribs.remove(p_attrib);
		BufferAPI.Destroy(this, p_attrib);
		m_vertexCount = m_attribs.length <=0 ? 0 : -1;
		for (i in 0...m_attribs.length)
		{
			var f : Dynamic = m_buffers.get(m_attribs[i]);
			var len : Int = f.length;			
			var vc : Int = cast (len / m_sizes.get(m_attribs[i]));
			m_vertexCount = m_vertexCount < 0 ? vc : Mathf.MinInt([vc, m_vertexCount]);
		}
	}
	
	public function Clear():Void
	{		
		for (a in m_attribs) { Remove(a); }
		m_attribs = [];
	}
	
	override public function OnDestroy():Void 
	{
		Clear();
	}
	
	private function VToF32(a : Dynamic):Float32Array
	{
		if (a == null) { return new Float32Array([]); }
		var d : Dynamic = a[0];
		if (Std.is(d, Float))   { return  FToF32(cast a); } else
		if (Std.is(d, Vector2)) { return V2ToF32(cast a); } else
		if (Std.is(d, Vector3)) { return V3ToF32(cast a); } else
		if (Std.is(d, Vector4)) { return V4ToF32(cast a); } else
		if (Std.is(d, Color))   { return  CToF32(cast a); }
		return new Float32Array([]);
	}
	
	private function F32ToV(a : Float32Array,s : Int):Dynamic
	{
		if (a == null) { return []; }		
		if (s == 1) { return F32ToF (a); } else
		if (s == 2) { return F32ToV2(a); } else
		if (s == 3) { return F32ToV3(a); } else
		if (s == 4) { return F32ToV4(a); }		
		return [];
	}
	
	private function F32ToF (f : Float32Array) : Array<Float>	{ if(f == null) return []; var i:Int = 0; var v : Float;   var a : Array<Float>   = [];	while (i < f.length) { v = f[i]; i++; a.push(v); } return a; }	
	private function F32ToV2(f : Float32Array) : Array<Vector2>	{ if(f == null) return []; var i:Int = 0; var v : Vector2; var a : Array<Vector2> = [];	while (i < f.length) { v = new Vector2(f[i], f[i + 1]); i += 2; a.push(v); } return a;	}	
	private function F32ToV3(f : Float32Array) : Array<Vector3> { if(f == null) return []; var i:Int = 0; var v : Vector3; var a : Array<Vector3> = [];  while (i < f.length) { v = new Vector3(f[i], f[i + 1], f[i + 2]); i += 3; a.push(v); } return a; }	
	private function F32ToV4(f : Float32Array) : Array<Vector4> { if(f == null) return []; var i:Int = 0; var v : Vector4; var a : Array<Vector4> = [];	while (i < f.length) { v = new Vector4(f[i], f[i + 1], f[i + 2], f[i + 3]); i += 4; a.push(v); } return a; }
	private function F32ToC (f : Float32Array) : Array<Color>   { if(f == null) return []; var i:Int = 0; var v : Color;   var a : Array<Color>   = [];	while (i < f.length) { v = new Color  (f[i], f[i + 1], f[i + 2], f[i + 3]); i += 4; a.push(v); } return a; }
	
	private function FToF32 (a : Array<Float>)   : Float32Array	{ var i:Int = 0; var k:Int = 0; var f : Float32Array = new Float32Array(a.length * 1); while (i < a.length) { f[k++] = a[i++]; } return f; }	
	private function V2ToF32(a : Array<Vector2>) : Float32Array	{ var i:Int = 0; var k:Int = 0;	var f : Float32Array = new Float32Array(a.length * 2); while (i < a.length) { f[k++] = a[i].x; f[k++] = a[i++].y; } return f; }
	private function V3ToF32(a : Array<Vector3>) : Float32Array	
	{ 		
		var i:Int = 0; var k:Int = 0;	var f : Float32Array = new Float32Array(a.length * 3); while (i < a.length) { f[k++] = a[i].x; f[k++] = a[i].y; f[k++] = a[i++].z; } return f; 
	}
	private function V4ToF32(a : Array<Vector4>) : Float32Array	{ var i:Int = 0; var k:Int = 0;	var f : Float32Array = new Float32Array(a.length * 4); while (i < a.length) { f[k++] = a[i].x; f[k++] = a[i].y; f[k++] = a[i].z; f[k++] = a[i++].w; } return f; }
	private function CToF32 (a : Array<Color>)   : Float32Array	{ var i:Int = 0; var k:Int = 0;	var f : Float32Array = new Float32Array(a.length * 4); while (i < a.length) { f[k++] = a[i].r; f[k++] = a[i].g; f[k++] = a[i].b; f[k++] = a[i++].a; } return f; }
}