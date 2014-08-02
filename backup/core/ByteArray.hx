/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import js.html.ArrayBuffer;
import js.html.Float32Array;
import js.html.Uint32Array;
import js.html.Uint8Array;
import haxor.component.Transform;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ByteArray
{
	
	static public function FromLayout(v : Array<Dynamic>):ByteArray
	{
		return new ByteArray(SizeOfLayout(v));
	}
	
	static public function SizeOfLayout(v : Array<Dynamic>):Int
	{
		var len : Int = 0;
		for (i in 0...v.length) len += SizeOf(v[i]);
		return len;
	}
	
	static public function SizeOf(v : Dynamic, p : Int = 32):Int
	{		
		
		
		if (v == Int)   		return cast (p / 4);
		if (v == Float) 		return  4;
		if (v == Vector2) 		return  8;
		if (v == Vector3) 		return 12;
		if (v == Vector4) 		return 16;
		if (v == Quaternion) 	return 16;
		if (v == Matrix4) 		return 64;
		if (v == Color) 		return cast (p / 4);
		if (v == Transform) 	return 40;
			
		if (Std.is(v, Int)) 		return cast (p / 4);		
		if (Std.is(v, Float))   	return  4;
		if (Std.is(v, Vector2)) 	return  8;
		if (Std.is(v, Vector3)) 	return 12;
		if (Std.is(v, Vector4)) 	return 16;
		if (Std.is(v, Quaternion)) 	return 16;
		if (Std.is(v, Matrix4)) 	return 64;
		if (Std.is(v, Color)) 		return cast (p / 4);
		if (Std.is(v, Transform))	return cast 40;
		if (Std.is(v, ArrayBuffer))	{ var a : ArrayBuffer = cast v; return a.byteLength; }		
		return -1;
	}
	
	static public function SerializeString(v : String):Uint8Array
	{
		var res :Uint8Array = new Uint8Array(v.length);
		for (i in 0...v.length) res[i] = v.charCodeAt(i);
		return res;
	}
	
	static public function UnserializeString(v : Uint8Array):String
	{
		var res : String=""; 
		for (i in 0...v.length) res += String.fromCharCode(v[i]);
		return res;
	}
	
	static public function SerializeInt32(v : Int):Uint8Array
	{		
		return new Uint8Array([((v >> 24 ) & 0xff), ((v >> 16 ) & 0xff), ((v >> 8 ) & 0xff), (v  & 0xff)]);			
	}
	
	static public function UnserializeInt32(v : Uint8Array):Int
	{	
		return (v[0] << 24) | (v[1] << 16) | (v[2] << 8) | (v[3]);
	}
	
	static public function SerializeFloat(v : Float):Uint8Array
	{	
		var buf = new ArrayBuffer(4);
		(new Float32Array(buf))[0] = v;
		return SerializeInt32((new Uint32Array(buf))[0]);
	}
	
	static public function UnserializeFloat(v : Uint8Array):Float
	{			
		var buf = new ArrayBuffer(4);		
		(new Uint32Array(buf))[0] = UnserializeInt32(v);
		return (new Float32Array(buf))[0];
	}

	public var length(get_length, never):Int;
	private function get_length():Int { return m_data.byteLength; }
	
	/**
	 * 
	 */
	public var position : Int;
	
	/**
	 * 
	 */
	public var data(get_data, set_data):Uint8Array;
	private function get_data():Uint8Array { return m_data; }
	private function set_data(v:Uint8Array):Uint8Array { m_data = v; position = 0; m_locked = false; return v; }
	private var m_data : Uint8Array;
	
	
	private var m_locked : Bool;
	
	static private var m_lzma : Dynamic=null;
	
	public function new(p_length : Int,p_element_size :Dynamic=null) 
	{		
		var es : Int = p_element_size == null ? 1 : (Std.is(p_element_size, Int) ? p_element_size : SizeOf(p_element_size));		
		m_data = new Uint8Array(p_length * es);
		position = 0;		
		m_locked = false;
		if (m_lzma == null)
		{
			var c : Dynamic=null;
			untyped __js__("c = new LZMA('./assets/plugins/lzma_worker.js')");
			m_lzma = c;
		}
	}
	
	public function Reset() :Void { position = 0; }
	
	public function WriteBytes(v : Uint8Array) :Void { for (i in 0...v.byteLength) m_data[position++] = v[i]; }
	
	public function WriteByteArray(v : Array<Int>) :Void { for (i in 0...v.length) m_data[position++] = v[i]; }
	
	public function WriteInt8 (v : Int):Void { m_data[position++] = v; }
	
	public function WriteInt16(v : Int):Void { m_data[position++] = (v >> 8 ) & 0xff; m_data[position++] = (v & 0xff); }
	
	public function WriteInt24(v : Int):Void { m_data[position++] = (v >> 16) & 0xff; m_data[position++] = (v >> 8) & 0xff; m_data[position++] = (v & 0xff); }
	
	public function WriteInt32(v : Int):Void { m_data[position++] = (v >> 24) & 0xff; m_data[position++] = (v >> 16) & 0xff; m_data[position++] = (v >> 8) & 0xff; m_data[position++] = (v & 0xff); }
	
	public function WriteFloat(v : Float):Void { WriteBytes(SerializeFloat(v)); }	
	
	public function WriteVector2(v : Vector2):Void {  WriteFloat(v.x); WriteFloat(v.y); }
	
	public function WriteVector3(v : Vector3):Void {  WriteFloat(v.x); WriteFloat(v.y); WriteFloat(v.z); }
	
	public function WriteVector4(v : Vector4):Void {  WriteFloat(v.x); WriteFloat(v.y); WriteFloat(v.z); WriteFloat(v.w); }
	
	public function WriteColorRGBA(v : Color):Void {  WriteInt32(v.rgba); }
	
	public function WriteColorARGB(v : Color):Void {  WriteInt32(v.argb); }
	
	public function WriteColorRGB(v : Color):Void {  WriteInt24(v.rgb); }
	
	public function WriteQuaternion(v : Quaternion):Void {  WriteFloat(v.x); WriteFloat(v.y); WriteFloat(v.z); WriteFloat(v.w); }
	
	public function WriteMatrix4(v : Matrix4) : Void 
	{ 
		WriteFloat(v.m00); WriteFloat(v.m01); WriteFloat(v.m02); WriteFloat(v.m03);
		WriteFloat(v.m10); WriteFloat(v.m11); WriteFloat(v.m12); WriteFloat(v.m13);
		WriteFloat(v.m20); WriteFloat(v.m21); WriteFloat(v.m22); WriteFloat(v.m23);
		WriteFloat(v.m30); WriteFloat(v.m31); WriteFloat(v.m32); WriteFloat(v.m33);
	}
	
	public function WriteTransform(v : Transform) : Void { WriteVector3(v.position); WriteQuaternion(v.rotation); WriteVector3(v.scale); }
	
	public function WriteString(v : String):Void 
	{
		for (i in 0...v.length) m_data[position++] = v.charCodeAt(i);
	}
	
	public function ReadBytes(p_offset:Int=0, p_length : Int=0) : Uint8Array
	{
		var len : Int = p_length <= 0 ? length : p_length;
		var res : Uint8Array = new Uint8Array(len);		
		for (i in 0...len) res[i] = m_data[position + p_offset + i];
		return res;
	}
	
	public function ReadInt8(p_offset:Int = 0) : Int { var o :Int = position + p_offset; return m_data[o]; }
	
	public function ReadInt16(p_offset:Int = 0) : Int { var o :Int = position + p_offset; return (m_data[o] <<  8) | m_data[o + 1]; }
	
	public function ReadInt24(p_offset:Int = 0) : Int { var o :Int = position + p_offset; return (m_data[o] << 16) | (m_data[o + 1] <<  8) | m_data[o + 2]; }
	
	public function ReadInt32(p_offset:Int = 0) : Int { var o :Int = position + p_offset; return (m_data[o] << 24) | (m_data[o + 1] << 16) | (m_data[o + 2] << 8) | m_data[o + 3]; }
	
	public function ReadFloat(p_offset:Int = 0) : Float { var o :Int = p_offset; return UnserializeFloat(ReadBytes(o, 4)); }
	
	public function ReadVector2(p_offset:Int = 0) : Vector2 { var v : Vector2 = new Vector2(ReadFloat(p_offset + 0), ReadFloat(p_offset + 4)); return v; }
	
	public function ReadVector3(p_offset:Int = 0) : Vector3 { var v : Vector3 = new Vector3(ReadFloat(p_offset +0), ReadFloat(p_offset +4), ReadFloat(p_offset +8)); return v; }
	
	public function ReadVector4(p_offset:Int = 0) : Vector4 { var v : Vector4 = new Vector4(ReadFloat(p_offset +0), ReadFloat(p_offset +4), ReadFloat(p_offset +8), ReadFloat(p_offset +12)); return v; }
	
	public function ReadColorRGBA(p_offset : Int = 0) : Color  { var v : Color = new Color(); v.rgba = ReadInt32(p_offset); return v; }
	
	public function ReadColorARGB(p_offset : Int = 0) : Color  { var v : Color = new Color(); v.argb = ReadInt32(p_offset); return v; }
	
	public function ReadColorRGB(p_offset : Int = 0) : Color  { var v : Color = new Color(); v.rgb = ReadInt24(p_offset); return v; }
	
	public function ReadQuaternion(p_offset:Int = 0) : Quaternion { var v : Quaternion = new Quaternion(ReadFloat(p_offset +0), ReadFloat(p_offset +4), ReadFloat(p_offset +8), ReadFloat(p_offset +12)); return v; }
	
	public function ReadMatrix4(p_offset:Int = 0) : Matrix4
	{
		var v : Matrix4 = new Matrix4();
		var o :Int = p_offset;
		v.m00 = ReadFloat(o); 	   v.m01 = ReadFloat(o +  4); v.m02 = ReadFloat(o +  8); v.m03 = ReadFloat(o + 12);
		v.m10 = ReadFloat(o + 16); v.m11 = ReadFloat(o + 20); v.m12 = ReadFloat(o + 24); v.m13 = ReadFloat(o + 28);
		v.m20 = ReadFloat(o + 32); v.m21 = ReadFloat(o + 36); v.m22 = ReadFloat(o + 40); v.m23 = ReadFloat(o + 44);
		v.m30 = ReadFloat(o + 48); v.m31 = ReadFloat(o + 52); v.m32 = ReadFloat(o + 56); v.m33 = ReadFloat(o + 60);
		return v;
	}
	
	public function ReadTransform(p_transform : Transform,p_offset : Int=0):Void
	{
		p_transform.position = ReadVector3(p_offset);
		p_transform.rotation = ReadQuaternion(p_offset + 12);
		p_transform.scale    = ReadVector3(p_offset + 28);
	}
	
	public function ReadFloatArray() : Float32Array
	{
		var len : Int = (length - position);
		len = cast (len / 4);
		var res : Float32Array = new Float32Array(len);
		var p : Int = position;
		for (i in 0...len) { res[i] = ReadFloat(); position += 4; }
		p = position;
		return res;
	}
	
	public function ReadString(p_length:Int = 0) : String 
	{
		var len : Int = p_length <= 0 ? (length - position) : p_length; 
		var s : String = "";
		for (i in 0...len) s += String.fromCharCode(m_data[position+i]);
		return s;
	}
	
	/**
	 * 
	 * @return
	 */
	public function EncodeBase64():String 
	{
		var len : Int = length;
		if(len <= 0) return "";
		var flen : Float = Mathf.Floor((len/3.0)+0.7);
		var base64_length : Int = Std.int(flen * 4);
		base64_length = base64_length < 4 ? 4 : base64_length;
		var rest : Int = (length * 8) % 6;	
		var map : String = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		var res : ByteArray = new ByteArray(base64_length);
		var wl : Int = base64_length - 4;								
		var i : Int = 0;
		var rt0 : Bool = rest != 2;
		var rt1 : Bool = (rest != 2) && (rest != 4);
		while(i<len)
		{
			var b0 : Int  = m_data[i];
			var b1 : Int  = (i < (len-1)) ? m_data[i+1] : 0;
			var b2 : Int  = (i < (len-2)) ? m_data[i+2] : 0;
			var b60 : Int = ((b0 >> 2) & 63);
			var b61 : Int = ((b0 &  3) << 4) | ((b1 >> 4) & 15);
			var b62 : Int = ((b1 & 15) << 2) | ((b2 >> 6) &  3);
			var b63 : Int =  (b2 & 63);
			var s0:String = map.charAt(b60);
			var s1:String = map.charAt(b61);
			var s2:String = ((res.position < wl) || rt0) ? map.charAt(b62) : "=";
			var s3:String = ((res.position < wl) || rt1) ? map.charAt(b63) : "=";
			res.WriteString(s0);
			res.WriteString(s1);
			res.WriteString(s2);
			res.WriteString(s3);
			i += 3;
		}
		res.position = 0;		
		m_data = res.m_data;
		position = 0;
		return res.ReadString();
	}
	
	/**
	 * 
	 * @return
	 */
	public function DecodeBase64():String 
	{		
		var map   : String = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
		var unmap : Uint8Array = new Uint8Array(255);
		for(i in 0...map.length) unmap[map.charCodeAt(i)] = i;
		var data_len 	  : Int = length;			
		var i : Int = 0;
		var res : Array<Int> = [];
		var eqc : Int = "=".charCodeAt(0);
		while(i < data_len)
		{
			var b60 : Int = unmap[m_data[i]]   & 63;
			var b61 : Int = unmap[m_data[i+1]] & 63;
			var b62 : Int = unmap[m_data[i+2]] & 63;
			var b63 : Int = unmap[m_data[i+3]] & 63;
			var b0  : Int =   (b60       << 2) |  (b61 >> 4);
			var b1  : Int =  ((b61 & 15) << 4) |  (b62 >> 2);
			var b2  : Int =  ((b62 &  3) << 6) |  (b63 & 63);			
			res.push(b0);			
			if (m_data[i + 2] != eqc) if (m_data[i + 3] != eqc) res.push(b1);
			if (m_data[i + 3] != eqc) res.push(b2);			
			i += 4;
		}
		m_data = new Uint8Array(res.length);
		position = 0;
		WriteByteArray(res);
		position = 0;
		return ReadString();
	}
	
	public function Compress(p_mode : Int,p_complete : Void -> Void=null):Void 
	{		
		if (m_locked) return;		
		m_locked = true;		
		position = 0;
		var ds : String = ReadString();		
		var oc : Dynamic=  function(v : Array<Int>) 
		{			
			var len = v.length;
			m_data = new Uint8Array(len);
			for (i in 0...len) WriteInt8(v[i]);
			position = 0;
			m_locked = false;			
			if (p_complete != null) p_complete();
			
		};		
		var c :Dynamic = m_lzma;		
		untyped __js__("c.compress(ds, p_mode,oc, function op(v) { } )");
	}
	
	public function CompressWeb(p_mode : Int, p_complete : Void -> Void):Void
	{
		if (m_locked) return;
		Compress(p_mode, function():Void
		{
			EncodeBase64();
			if (p_complete != null) p_complete();
		});
	}
	
	public function Decompress(p_complete : Void -> Void=null):Void
	{
		if (m_locked) return;		
		m_locked = true;		
		position = 0;		
		var oc : Dynamic=  function(v : String) 
		{			
			var len = v.length;
			m_data = new Uint8Array(len);
			for (i in 0...len) WriteInt8(v.charCodeAt(i));
			position = 0;
			m_locked = false;			
			if (p_complete != null) p_complete();			
		};					
		var c : Dynamic = m_lzma;
		var d : Dynamic = m_data;
		untyped __js__("c.decompress(d,oc, function op(v) { } )");				
	}
	
	public function DecompressWeb(p_complete : Void -> Void):Void
	{
		if (m_locked) return;
		DecodeBase64();
		Decompress(p_complete);
	}
	
}