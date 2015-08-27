#if (html||nodejs)

package haxor.platform.html.net;
import haxor.io.Buffer;
import haxor.platform.html.graphics.mesh.MeshReader;
import haxor.graphics.mesh.Mesh;
import js.html.URL;
import js.html.XMLHttpRequestResponseType;
import haxor.platform.Types.Float32;
import js.Browser;
import haxor.core.Enums.PixelFormat;
import js.html.Event;
import js.html.Image;
import haxor.graphics.Bitmap;
import js.html.Uint8Array;
import js.html.CanvasRenderingContext2D;
import js.html.DOMURL;
import js.html.ImageData;

/**
 * Loads a bitmap file from the web. In the HTML platform.
 */
class MeshLoader extends HTTPLoader<Uint8Array>
{
	/**
	 * Internal callback.
	 */
	private var m_mesh_callback : Mesh-> Float->Void;
	
	/**
	 * Creates a new LoadBitmapFile Task.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : Mesh-> Float->Void):Void
	{		
		super(p_url, true, OnBufferCallback);		
		m_mesh_callback = p_callback;
		request.responseType = XMLHttpRequestResponseType.ARRAYBUFFER;
	}
	
	/**
	 * 
	 * @param	p_bitmap
	 * @param	p_progress
	 */
	private function OnBufferCallback(p_data:Uint8Array, p_progress:Float32):Void 
	{
		if (p_progress < 1.0)
		{
			if(m_mesh_callback!=null) m_mesh_callback(null, progress);
		}
		else
		{
			if (p_data == null) return;
			var b : Buffer = new Buffer(p_data.length);
			for (i in 0...b.length) b.SetByte(i, p_data[i]);
			var m : Mesh = MeshReader.Read(b);
			m_mesh_callback(m, 1.0);			
		}
	}
	
	override function OnError():Void { if(m_mesh_callback!=null) m_mesh_callback(null, 1.0);	}
}

#end