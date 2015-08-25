#if html

package haxor.platform.html.graphics.mesh;
import haxor.math.Matrix4;
import haxor.graphics.mesh.MeshLayout.SkinnedMesh3;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.thread.Activity;
import haxor.core.Enums.MeshMode;
import haxor.math.Mathf;
import haxor.core.Enums.MeshPrimitive;
import haxor.graphics.mesh.Mesh;
import haxor.core.Console;
import js.html.ImageData;
import haxor.core.Enums.PixelFormat;
import js.Browser;
import js.html.CanvasRenderingContext2D;
import js.html.Event;
import js.html.URL;
import js.html.Image;
import js.html.Blob;
import haxor.graphics.Bitmap;
import haxor.io.Buffer;
import haxor.platform.Types.Float32;

/**
 * Class that handles the conversion of a Mesh files raw bytes into a Mesh.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MeshReader
{
	
	/**
	 * Decodes the PNG file described in the informed buffer and calls a callback when the process has ended.
	 * @param	p_buffer
	 * @return
	 */
	static public function ReadAsync(p_buffer : Buffer,p_on_complete : Mesh -> Void) : Void
	{
		Activity.RunOnce(function():Void
		{
			var m : Mesh = Read(p_buffer);
			if (p_on_complete != null) p_on_complete(m);
		});
	}
	
	/**
	 * Decodes the PNG file described in the informed buffer and returns a Bitmap class reference.
	 * @param	p_buffer
	 * @return
	 */
	static public function Read(p_buffer : Buffer) : Mesh
	{
		var b 		: Buffer = p_buffer;
		var header 	: String = "";
		var p		: Int    = 0;
		for (i in 0...b.length)
		{
			var v : Int = b.GetByte(p++);
			if (v == 0) break;
			header += String.fromCharCode(v);
		}
		
		var var_sep    : String = String.fromCharCode(3);
		var buff_sep   : String = String.fromCharCode(4);
		var attrib_sep : String = String.fromCharCode(5);
		
		var tokens 			 : Array<String> = header.split(var_sep);
		var mesh_type_name	 : String 		 = tokens.length <= 0 ? "" : tokens[0];
		var mesh_type		 : Class<Mesh>   = cast Type.resolveClass(mesh_type_name);
		if (mesh_type == null) return null;
		var mesh_guid 		 : String 		 = tokens.length <= 1 ? "" : tokens[1];
		var mesh_name   	 : String        = tokens.length <= 2 ? "" : tokens[2];
		var mesh_mode   	 : Int        	 = tokens.length <= 3 ? MeshMode.StaticDraw    : Std.parseInt(tokens[3]);		
		var mesh_primitive   : Int        	 = tokens.length <= 4 ? MeshPrimitive.Triangles: Std.parseInt(tokens[4]);
		if (Math.isNaN(mesh_mode)) 		mesh_mode 		= MeshMode.StaticDraw;
		if (Math.isNaN(mesh_primitive)) mesh_primitive  = MeshPrimitive.Triangles;		
		var mesh_binds		 : String        = tokens.length <= 5 ? "" : tokens[5];
		var mesh_attribs	 : String		 = tokens.length <= 6 ? "" : tokens[6];
		
		
		
		var mesh : Mesh = Type.createInstance(mesh_type,[mesh_name]);
		mesh.mode 		= mesh_mode;
		mesh.primitive	= mesh_primitive;
		mesh.guid		= mesh_guid;
		
		if (Std.is(mesh, SkinnedMesh3))
		{
			var bf32 : FloatArray = FloatArray.Parse(mesh_binds, ",");
			var mc : Int = Std.int(bf32.length / 16);
			var mp : Int = 0;
			var ml : Array<Matrix4> = [];
			for (i in 0...mc)
			{
				var f32:Array<Float32> = [];
				for (j in 0...16)
				{
					f32.push(bf32.Get(p++));
				}
				ml.push(Matrix4.FromArray(f32));
			}
			var skm : SkinnedMesh3 = cast mesh;
			skm.binds = ml;
		}
		
		tokens = mesh_attribs.split(buff_sep);
		
		var attribs : Array<String> = [];		
		var offsets : Array<Int>    = [];
		var lengths : Array<Int>	= [];
		
		for (i in 0...tokens.length)
		{
			var attrib_tokens : Array<String> = tokens[i].split(attrib_sep);
			if (attrib_tokens.length < 3) continue;
			var attrib_name   : String = attrib_tokens[0];
			var attrib_offset : Int    = Std.parseInt(attrib_tokens[1]);
			if (Mathf.IsNaN(attrib_offset)) continue;
			var attrib_length : Int    = Std.parseInt(attrib_tokens[2]);
			if (Mathf.IsNaN(attrib_length)) continue;
			
			var ab : Buffer;
			
			if (attrib_name == "$topology")
			{
				ab = new UInt16Array(Std.int(attrib_length / 2));
			}
			else
			{
				ab = new FloatArray(attrib_length);
			}
			
			
			for (i in 0...attrib_length)
			{
				if (p >= b.byteLength) break;
				ab.SetByte(i, b.GetByte(p++));
			}
			
			if (p >= b.byteLength) break;			
			
			if (attrib_name == "$topology")
			{
				mesh.topology = cast ab;
			}
			else
			{
				mesh.Set(attrib_name, ab, attrib_offset);
			}
		}
		mesh.bounds = mesh.GenerateAttribBounds("vertex");
		return mesh;
	}
	
}

#end