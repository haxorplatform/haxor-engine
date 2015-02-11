package haxor.thread;
import haxor.context.EngineContext;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.core.Resource;
import haxor.graphics.GL;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.graphics.texture.RenderTexture;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.math.AABB2;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Kernel extends Material
{
	/**
	 * 
	 */
	public var result(get_result, never):Buffer;
	private function get_result():Buffer { return cast m_result; }
	private var m_result : Buffer;

	/**
	 * 
	 */
	public var enabled : Bool;
	
	/**
	 * 
	 */
	public var output(get_output, never):RenderTexture;
	private function get_output():RenderTexture { return m_output; }
	private var m_output : RenderTexture;
	
	/**
	 * 
	 */
	private var m_plane : Mesh3;
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_readable
	 * @param	p_format
	 */ 
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
		
		m_output = new RenderTexture(p_width, p_height,p_format == null ? PixelFormat.RGBA8 : p_format);
		m_output.minFilter =  m_output.magFilter = TextureFilter.Nearest;
		m_output.name = "Kernel" + uid + "Output";		
		
		var len : Int = p_width * p_height;		
		switch(p_format)
		{
			case PixelFormat.Alpha8: m_result = new Buffer(len);
			case PixelFormat.RGB8:   m_result = new Buffer(len * 3);
			case PixelFormat.RGBA8:  m_result = new Buffer(len * 4);
			case PixelFormat.Float:  m_result = new FloatArray(len);
			case PixelFormat.Float3: m_result = new FloatArray(len * 3);
			case PixelFormat.Float4: m_result = new FloatArray(len * 4);
			case PixelFormat.Luminance:
			case PixelFormat.Half:
			case PixelFormat.Half3:
			case PixelFormat.Half4:
			case PixelFormat.Depth:
		}	
		
		SetFloat("width",  p_width);
		SetFloat("height", p_height);		
		EngineContext.kernel.OnCreate(this);		
	}
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 */
	public function Resize(p_width : Int=-1, p_height:Int=-1):Void
	{
		var ow : Float32 = m_output.width;
		var oh : Float32 = m_output.height;
		
		var w : Float32 = p_width  < 0 ? ow  : p_width;
		var h : Float32 = p_height < 0 ? oh  : p_height;
		
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
	
	/**
	 * Renders one step of execution of this kernel.
	 */
	public function Execute():Void
	{
		if (!enabled) return;			
		if (shader == null) return;
		EngineContext.texture.BindTarget(m_output);		
		Graphics.Viewport(AABB2.temp.SetXYWH(0,0,m_output.width, m_output.height));
		Graphics.Render(m_plane,this,null,null);
		EngineContext.texture.BindTarget(null);
		//*/
	}
	
	/**
	 * Updates all kernel or a portion rectangle passed in the arguments.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function Update(p_x:Int=0,p_y:Int=0,p_width:Int=-1,p_height:Int=-1):Void
	{
		if (!enabled) return;
		if (shader == null) return;
		if (m_result == null) return;
		var w : Int = p_width <= 0  ? m_output.width  : p_width;
		var h : Int = p_height <= 0 ? m_output.height : p_height;				
		EngineContext.texture.BindTarget(m_output);		
		Graphics.ReadPixels(p_x, p_y, w, h, cast m_result.buffer);
		EngineContext.texture.BindTarget(null);				
	}
	
	/**
	 * Callback called upon destruction.
	 */
	override public function OnDestroy():Void 
	{
		super.OnDestroy();		
		Resource.Destroy(m_output);
		Resource.Destroy(m_plane);
		EngineContext.kernel.OnDestroy(this);
	}
}
