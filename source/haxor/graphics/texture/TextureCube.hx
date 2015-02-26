package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.core.Enums.TextureType;
import haxor.core.Resource;
import haxor.math.Color;

/**
 * Class that describes a Cubemap container with 6 texture slots to fill each side.
 * @author Eduardo Pons
 */
class TextureCube extends Texture
{
	
	/**
	 * Positive X side.
	 */
	public var px(get_px, set_px) : Texture;	
	private inline function get_px():Texture { return m_faces[0]; }
	private function set_px(v:Texture):Texture { m_faces[0] = v; return v; }
	private var p_px : Texture;
	
	/**
	 * Negative X side.
	 */
	public var nx(get_nx, set_nx) : Texture;	
	private inline function get_nx():Texture { return m_faces[1]; }
	private function set_nx(v:Texture):Texture {  m_faces[1] = v; return v; }
	private var p_nx : Texture;
	
	/**
	 * Positive Y side.
	 */
	public var py(get_py, set_py) : Texture;	
	private inline function get_py():Texture { return m_faces[2]; }
	private function set_py(v:Texture):Texture { m_faces[2] = v; return v; }
	private var p_py : Texture;
	
	/**
	 * Negative Y side.
	 */
	public var ny(get_ny, set_ny) : Texture;	
	private inline function get_ny():Texture { return m_faces[3]; }
	private function set_ny(v:Texture):Texture {  m_faces[3] = v; return v; }
	private var p_ny : Texture;
	
	/**
	 * Positive Z side.
	 */
	public var pz(get_pz, set_pz) : Texture;	
	private inline function get_pz():Texture { return m_faces[4]; }
	private function set_pz(v:Texture):Texture { m_faces[4] = v; return v; }
	private var p_pz : Texture;
	
	/**
	 * Negative Z side.
	 */
	public var nz(get_nz, set_nz) : Texture;	
	private inline function get_nz():Texture { return m_faces[5]; }
	private function set_nz(v:Texture):Texture { m_faces[5] = v; return v; }
	private var p_nz : Texture;
	
	/**
	 * List of Textures that contains all cubemap sides.
	 */
	private var m_faces : Array<Texture>;
	
	/**
	 * Type enum of this texture.
	 * @return
	 */
	override function get_type():TextureType { return TextureType.TextureCube; }
	
	/**
	 * Creates a new Cubemap texture.
	 */
	public function new() 
	{
		m_faces 	= [null, null, null, null, null, null];				
		super();
		EngineContext.texture.Create(this);
	}
	
	/**
	 * Loads this cubemap faces from a single cross texture.
	 * @param	p_texture
	 */
	public function LoadCrossTexture(p_texture : Texture2D):Void
	{
		EngineContext.texture.CrossToCubemap(this, p_texture);
	}
	
	/**
	 * Destroy callback.
	 */
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		for (i in 0...m_faces.length) if (m_faces[i] != null) Resource.Destroy(m_faces[i]);		
	}
	
	
	
}