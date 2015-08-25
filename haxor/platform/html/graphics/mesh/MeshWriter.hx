#if html

package haxor.platform.html.graphics.mesh;
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

/**
 * Class that handles the conversion of a Mesh files raw bytes into a Mesh.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MeshWriter
{
	
	/**
	 * Decodes the PNG file described in the informed buffer and calls a callback when the process has ended.
	 * @param	p_buffer
	 * @return
	 */
	static public function WriteAsync(p_mesh : Mesh,p_on_complete : Buffer -> Void) : Void
	{
		Activity.RunOnce(function():Void
		{
			var b : Buffer = Write(p_mesh);
			if (p_on_complete != null) p_on_complete(b);
		});
	}
	
	/**
	 * Decodes the PNG file described in the informed buffer and returns a Bitmap class reference.
	 * @param	p_buffer
	 * @return
	 */
	static public function Write(p_mesh : Mesh) : Buffer
	{
		var m 			: Mesh   = p_mesh;
		var header 		: String = "";
		var var_sep     : String = String.fromCharCode(3);
		var buff_sep    : String = String.fromCharCode(4);
		var attrib_sep  : String = String.fromCharCode(5);
		
		var p			: Int = 0;
		
		header += m.guid 	  + var_sep;
		header += m.name 	  + var_sep;
		header += m.mode 	  + var_sep;
		header += m.primitive + var_sep;
		
		var al : Array<String> = m.attribs;
		var bl : Array<Buffer> = [];
		var attrib_length : Int = 0;
		for (i in 0...al.length)
		{
			var a : MeshAttrib = m.GetAttribute(al[i]);
			if (a == null) continue;
			var b   : Buffer = a.data;
			var len : Int    = b.byteLength;
			header += a.name   	+ attrib_sep;
			header += a.offset 	+ attrib_sep;
			header += len 		+ attrib_sep;
			if (i < (al.length - 1)) header += buff_sep;
			bl.push(b);
			attrib_length += len;
		}
		
		var res : Buffer = new Buffer(header.length + 1 + attrib_length);
				
		for (i in 0...header.length)
		{
			res.SetByte(p++, header.charCodeAt(i));
		}
		
		res.SetByte(p++, 0);
		
		for (i in 0...bl.length)
		{
			var b : Buffer = bl[i];
			for (j in 0...b.byteLength)
			{
				res.SetByte(p++, b.GetByte(j));
			}
		}
		return res;
	}
	
}

#end