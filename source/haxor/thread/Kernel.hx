package haxor.thread;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.graphics.texture.RenderTexture;
import haxor.io.Buffer;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Kernel<T> extends Material
{
	
	public var result(get_result, never):T;
	private function get_result():T { return cast m_result; }
	private var m_result : Buffer;

	public var enabled : Bool;
	
	private var m_plane : Mesh3;
	
	public var output(get_output, never):RenderTexture;
	private function get_output():RenderTexture { return m_output; }
	private var m_output : RenderTexture;
	
	public function new(p_width : Int, p_height : Int,p_readable : Bool=true,p_format : PixelFormat = null) 
	{
		super();
		
		enabled = true;
		
		m_plane = new Mesh3();
		m_plane.vertex =
		[
			new Vector3(-1, 1, 1),
			new Vector3(-1,-1, 1),						
			new Vector3( 1,-1, 1),			
			new Vector3(-1, 1, 1),
			new Vector3( 1,-1, 1),			
			new Vector3( 1, 1, 1)			
        ];	
		
		m_output = new RenderTexture(p_width, p_height,p_format == null ? TextureFormat.RGBA8 : p_format);
		m_output.minFilter =  m_output.magFilter = TextureFilter.Nearest;
		m_output.name = "Kernel" + id + "Output";
		
		m_result = p_readable ? (new Uint8Array(p_width * p_height * 4)) : null;
		//ztest = false;
		
		var w : Float = cast p_width;  w += 0.00000001;
		var h : Float = cast p_height; h += 0.00000001;
		
		SetUniform("width",  w);
		SetUniform("height", h);
	}
	
	public function Resize(p_width : Int=-1, p_height:Int=-1):Void
	{
		var ow : Float = m_output.width;
		var oh : Float = m_output.height;
		
		var w : Float = p_width  < 0 ? ow  : p_width;
		var h : Float = p_height < 0 ? oh : p_height;
		
		w = Mathf.Lerp(-1,1,w / ow);
		h = Mathf.Lerp(-1,1,h / oh);
		
		m_plane.vertex =
		[
			new Vector3(-1, h, 1),
			new Vector3(-1,-1, 1),						
			new Vector3( w,-1, 1),			
			new Vector3(-1, h, 1),
			new Vector3( w,-1, 1),			
			new Vector3( w, h, 1)
        ];		
	}
	
	public function Execute():Void
	{
		if (!enabled) return;				
		
		TextureAPI.BindRT(m_output);		
		Graphics.Viewport(0, 0, m_output.width, m_output.height);
		Graphics.Render(null, null, m_plane, this);
		TextureAPI.BindRT(null);
	}
	
	public function Update(p_x:Int=0,p_y:Int=0,p_width:Int=-1,p_height:Int=-1):Void
	{
		if (!enabled) return;
		if (m_result == null) return;
		var w : Int = p_width <= 0  ? m_output.width  : p_width;
		var h : Int = p_height <= 0 ? m_output.height : p_height;		
		
		TextureAPI.BindRT(m_output);		
		Graphics.ReadPixels(p_x, p_y, w, h, m_result);
		TextureAPI.BindRT(null);
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();				
		Resource.Destroy(m_output);
		Resource.Destroy(m_plane);
	}
}

class KernelUint8 extends Kernel<Uint8Array> { }

class KernelFloat extends Kernel<Float32Array>
{
	override private function get_result():Float32Array 
	{
		if (m_result == null) return null;
		var bb : Uint8Array = cast m_result;		
		return new Float32Array(bb.buffer);
	}
	
	public function new(p_width:Int, p_height:Int,p_readable : Bool=true,p_format : TextureFormat = null)
	{
		super(p_width, p_height,p_readable,p_format);
		//SetUniform("width", p_width);
		//SetUniform("height", p_height);
	}
}