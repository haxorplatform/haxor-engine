package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.core.Resource;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Enums.TextureFilter;
import haxor.graphics.Enums.TextureType;
import haxor.graphics.Enums.TextureWrap;
import haxor.io.Buffer;

/**
 * Base class that describes a Texture sampler of the API.
 */
@:allow(haxor)
class Texture extends Resource
{	
	
	/**
	 * Width of this texture.
	 */
	public var width(get_width, never):Int;	
	private inline function get_width():Int { return m_width; }	
	private var m_width : Int;
	
	/**
	 * Height of this texture.
	 */
	public var height(get_height, never):Int;	
	private inline function get_height():Int { return m_height; }	
	private var m_height : Int;
	
	/**
	 * Format of the pixels of this texture.
	 */
	public var format(get_format, never):PixelFormat;	
	private inline function get_format():PixelFormat { return m_format; }
	private var m_format:PixelFormat;
	
	/**
	 * Wrapping mode of this texture.
	 */
	public var wrap(get_wrap, set_wrap):Int;		
	private inline function get_wrap():Int { return m_wrap; }
	private function set_wrap(v:Int):Int {  if (m_wrap == v) return v; m_wrap = v;  EngineContext.texture.UpdateParameters(this); return v; }	
	private var m_wrap:Int;
	
	/**
	 * Aniso level of this texture (if feature is available). 
	 */
	public var aniso(get_aniso, set_aniso):Int;	
	private inline function get_aniso():Int { return m_aniso; }
	private function set_aniso(v:Int):Int { if (m_aniso == v) return v; m_aniso = v;  EngineContext.texture.UpdateParameters(this); return v; }
	private var m_aniso:Int;
	
	
	/**
	 * Minification filter.
	 */
	public var minFilter(get_minFilter, set_minFilter):TextureFilter;	
	private inline function get_minFilter():TextureFilter { return m_minFilter; }
	private function set_minFilter(v:TextureFilter) : TextureFilter { if (m_minFilter == v) return v; m_minFilter = v; EngineContext.texture.UpdateParameters(this); return v; }
	private var m_minFilter:TextureFilter;
	
	/**
	 * Magnification filter.
	 */
	public var magFilter(get_magFilter, set_magFilter):TextureFilter;	
	private inline function get_magFilter():TextureFilter { return m_magFilter; }
	private function set_magFilter(v:TextureFilter) : TextureFilter { if (m_magFilter == v) return v; m_magFilter = v; EngineContext.texture.UpdateParameters(this); return v; }
	private var m_magFilter:TextureFilter;	
	
	/**
	 * Flag that indicates if this texture has generated mipmaps.
	 */
	public var mipmaps(get_mipmaps, null):Bool;
	private inline function get_mipmaps():Bool { return m_mipmaps; }	
	private var m_mipmaps:Bool;
	
	/**
	 * Returns the type of texture (2D,Cube,RTT,...)
	 */
	public var type(get_type, null):TextureType;
	private function get_type():TextureType { return TextureType.None; }
	
	/**
	 * Internal var to distribute this texture in a given 'active' slot.
	 */
	private var __slot : Int;
	/**
	 * Creates a new Texture element. This constructor is private because this class must be extended to implement real Texture features.
	 */
	private function new() 
	{
		super();		
		m_mipmaps 		= false;
		m_format 		= PixelFormat.RGBA8;
		m_minFilter 	= TextureFilter.Linear;
		m_magFilter 	= TextureFilter.Linear;
		m_wrap 			= TextureWrap.ClampX | TextureWrap.ClampY | TextureWrap.ClampZ;
		m_width 		= 0;
		m_height 		= 0;		
		m_aniso 		= 0;		
		__cid			= EngineContext.texture.tid++;		
	}
	
	/**
	 * Apply modifications for this texture and updates its content in the API.
	 */
	public function Apply():Void
	{
		EngineContext.texture.Update(this);
	}
	
	/**
	 * Creates a mipmap set for this texture.
	 */
	public function GenerateMipmaps():Void { if (m_mipmaps) return; m_mipmaps = true; EngineContext.texture.UpdateMipmaps(this); }
	
	/**
	 * Callback called to destroy this texture in the API.
	 */
	override public function OnDestroy():Void 
	{
		super.OnDestroy();	
		EngineContext.texture.Destroy(this);
	}
	
}
