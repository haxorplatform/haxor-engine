package haxor.context;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Enums.TextureType;
import haxor.graphics.texture.Texture;
import haxor.platform.graphics.GL;
import haxor.platform.Types.TextureId;



/**
 * Class that handles Texture related internal structures.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class TextureContext
{
	/**
	 * Unique Texture ids.
	 */
	private var tid : Int;
	
	private var ids : Array <TextureId>;
	
	/**
	 * Active texture for a given slot.
	 */
	private var active : Array<TextureId>;
	
	/**
	 * Currently bound texture.
	 */
	private var bind : TextureId;
		
	
	/**
	 * Creates the TextureContext.
	 */
	public function new() 
	{
		tid 	= 0;
		bind 	= GL.NULL;
		active 	= [];		
		ids		= [];
	}
	
	/**
	 * Initializes the context when the graphics API is available.
	 */
	public function Initialize():Void
	{
		for (i in 0...GL.MAX_ACTIVE_TEXTURE) active.push(GL.NULL);
		for (i in 0...2048) ids.push(GL.NULL);
	}
	
	/**
	 * Creates a new Texture in the API.
	 * @param	p_texture
	 */
	public function Create(p_texture:Texture):Void
	{
		p_texture.__slot = p_texture._cid_ % GL.MAX_ACTIVE_TEXTURE;
	}
	
	/**
	 * Binds the Texture for usage.
	 * @param	p_texture
	 */
	public function Bind(p_texture : Texture):Void
	{
		var id : TextureId = ids[p_texture._cid_];
		if (id == bind) return;
		var target : Int = TextureToTarget(p_texture);
		bind = id;
		//GL.BindTexture(target,id);
	}
	
	/**
	 * Updates parameters such as wrapping, filtering and others.
	 * @param	p_texture
	 */
	public function UpdateParameters(p_texture : Texture):Void
	{
		
	}
	
	/**
	 * Updates the texture data in the API.
	 * @param	p_texture
	 */
	public function Update(p_texture:Texture):Void
	{
		
	}
	
	/**
	 * Updates the mipmap data for this texture.
	 * @param	p_texture
	 */
	public function UpdateMipmaps(p_texture:Texture):Void
	{
		
	}
	
	/**
	 * Destroys all data for the informed Texture.
	 * @param	p_texture
	 */
	public function Destroy(p_texture:Texture):Void
	{
		
	}
	
	/**
	 * Returns the bind target for a given texture.
	 * @param	p_texture
	 * @return
	 */
	static private inline function TextureToTarget(p_texture:Texture):Int
	{
		switch(p_texture.type)
		{
			case TextureType.None: 			return GL.TEXTURE_2D;
			case TextureType.Texture2D: 	return GL.TEXTURE_2D;
			case TextureType.TextureCube:	return GL.TEXTURE_CUBE_MAP;
			case TextureType.RenderTexture:	return GL.TEXTURE_2D;
		}
		return GL.TEXTURE_2D;
	}
	
	/**
	 * Maps the TextureFormat enumeration to its respective bit description to the API.
	 * @param	p_format
	 * @return
	 */
	static private function FormatToChannelBits(p_format : PixelFormat):Int
	{		
		switch (p_format)
		{
			case PixelFormat.Alpha8: 		return GL.ALPHA;
			case PixelFormat.RGB8: 			return GL.RGB; 
			case PixelFormat.RGBA8: 		return GL.RGBA;
			case PixelFormat.Float,  PixelFormat.Half:			return GL.LUMINANCE;			
			case PixelFormat.Float3, PixelFormat.Half3:			return GL.RGB;			
			case PixelFormat.Float4, PixelFormat.Half4:			return GL.RGBA;			
			case PixelFormat.Luminance: 	return GL.LUMINANCE;
			case PixelFormat.Depth:			return GL.DEPTH_COMPONENT;
		}
		return GL.RGBA;
	}
	
	/**
	 * Returns the channel component format based on the pixel format.
	 * @param	p_format
	 * @return
	 */
	static private function FormatToChannelType(p_format : PixelFormat) : Int
	{
		switch(p_format)
		{
			case PixelFormat.Half, PixelFormat.Half3, PixelFormat.Half4 :    return GL.HALF_FLOAT;
			case PixelFormat.Float, PixelFormat.Float3, PixelFormat.Float4 : return GL.FLOAT;
			case PixelFormat.Depth: return GL.UNSIGNED_SHORT;
			case PixelFormat.RGBA8, PixelFormat.RGB8, PixelFormat.Luminance, PixelFormat.Alpha8: return GL.UNSIGNED_BYTE;
		}		
		return GL.UNSIGNED_BYTE;
	}
	
	/**
	 * Returns the pixel layout based on the pixel format.
	 * @param	p_format
	 * @return
	 */
	static private function FormatToChannelLayout(p_format : PixelFormat):Int
	{
		switch (p_format)
		{
			case PixelFormat.Alpha8:  						return GL.ALPHA;
			case PixelFormat.RGB8: 	  						return GL.RGB; 
			case PixelFormat.RGBA8: 	  					return GL.RGBA;
			case PixelFormat.Luminance, PixelFormat.Half, PixelFormat.Float: return GL.LUMINANCE; //(L,L,L,1.0)
			case PixelFormat.Float3, PixelFormat.Half3:		return GL.RGB;
			case PixelFormat.Float4, PixelFormat.Half4:		return GL.RGBA;
			case PixelFormat.Depth:							return GL.DEPTH_COMPONENT;
		}		
		return GL.RGBA;
	}
	
}