package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureType;
import haxor.graphics.GL;

/**
 * Class that describes a RenderTexture which can be used as target for offscreen rendering or kernel execution.
 * @author Eduardo Pons
 */
@:allow(haxor)
class RenderTexture extends Texture
{
	/**
	 * Reference to the Texture used as DepthTexture.
	 */
	public var depth(get_depth, never):Texture2D;
	private inline function get_depth():Texture2D { return m_depth; }
	private var m_depth:Texture2D;
	
	/**
	 * Returns the enum for this texture type.
	 * @return
	 */
	override inline function get_type():TextureType {	return TextureType.RenderTexture;}
	
	
	/**
	 * Creates a new RenderTexture.
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 * @param	p_store_depth
	 */
	public function new(p_width : Int,p_height : Int,p_format : PixelFormat,p_store_depth : Bool=false)
	{
		super();
		m_format = p_format;
		m_width  = Std.int(p_width);
		m_height = Std.int(p_height);		
		
		var store_depth : Bool = p_store_depth && GL.TEXTURE_DEPTH_ENABLED;
		
		if (store_depth)
		{
			m_depth = new Texture2D(m_width, m_height, PixelFormat.Depth);
		}
		
		EngineContext.texture.Create(this);
	}
	
}