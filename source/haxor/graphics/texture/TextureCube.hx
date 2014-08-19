package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.core.Resource;
import haxor.math.Color;

/**
 * Class that describes a Cubemap container with 6 texture slots to fill each side.
 * @author Eduardo Pons
 */
class TextureCube extends Texture
{
	/**
	 * Creates a new Cubemap texture from a cross cubemap texture.
	 * @param	p_texture
	 * @return
	 */
	static public function FromCrossTexture(p_texture : Texture2D) : TextureCube
	{
		//Use glCopyTexImage to transfer each quad to the right place
		
		/*
		var res : TextureCube = new TextureCube();
		var cw : Int = cast (p_texture.width / 4);
		var ch : Int = cw;
		
		for (ih in 0...3)
		for (iw in 0...4)
		{
			if (ih == 0) if (iw != 1) continue;
			if (ih == 2) if (iw != 1) continue;
			var px:Int = iw * cw;
			var py:Int = ih * ch;			
			var cpix : Array<Color> = p_texture.GetPixelsRect(px, py, cw, ch);
			var side : Texture2D = new Texture2D(cw, ch, p_texture.format);
			side.SetPixels(cpix);						
			if (ih == 2) if (iw == 1) res.ny = side;
			if (ih == 1) if (iw == 0) res.nx = side;
			if (ih == 1) if (iw == 1) res.pz = side;
			if (ih == 1) if (iw == 2) res.px = side;
			if (ih == 1) if (iw == 3) res.nz = side;
			if (ih == 0) if (iw == 1) res.py = side;
		}
		res.Apply();
		res.m_is_cross = true;
		return res;
		//*/
		return null;
	}
	
	/**
	 * Positive X side.
	 */
	public var px(get_px, set_px) : Texture;	
	private inline function get_px():Texture { return m_faces[0]; }
	private function set_px(v:Texture):Texture { InvalidateCross(); m_faces[0] = v; return v; }
	private var p_px : Texture;
	
	/**
	 * Negative X side.
	 */
	public var nx(get_nx, set_nx) : Texture;	
	private inline function get_nx():Texture { return m_faces[1]; }
	private function set_nx(v:Texture):Texture { InvalidateCross(); m_faces[1] = v; return v; }
	private var p_nx : Texture;
	
	/**
	 * Positive Y side.
	 */
	public var py(get_py, set_py) : Texture;	
	private inline function get_py():Texture { return m_faces[2]; }
	private function set_py(v:Texture):Texture { InvalidateCross(); m_faces[2] = v; return v; }
	private var p_py : Texture;
	
	/**
	 * Negative Y side.
	 */
	public var ny(get_ny, set_ny) : Texture;	
	private inline function get_ny():Texture { return m_faces[3]; }
	private function set_ny(v:Texture):Texture { InvalidateCross(); m_faces[3] = v; return v; }
	private var p_ny : Texture;
	
	/**
	 * Positive Z side.
	 */
	public var pz(get_pz, set_pz) : Texture;	
	private inline function get_pz():Texture { return m_faces[4]; }
	private function set_pz(v:Texture):Texture { InvalidateCross(); m_faces[4] = v; return v; }
	private var p_pz : Texture;
	
	/**
	 * Negative Z side.
	 */
	public var nz(get_nz, set_nz) : Texture;	
	private inline function get_nz():Texture { return m_faces[5]; }
	private function set_nz(v:Texture):Texture { InvalidateCross(); m_faces[5] = v; return v; }
	private var p_nz : Texture;
	
	/**
	 * List of Textures that contains all cubemap sides.
	 */
	private var m_faces : Array<Texture>;
	
	/**
	 * Flag that indicates if this TextureCube was made of a cross texture.
	 */
	private var m_is_cross : Bool;

	/**
	 * Creates a new Cubemap texture.
	 */
	public function new() 
	{
		m_faces 	= [null, null, null, null, null, null];
		m_is_cross  = false;
		super();
		EngineContext.texture.Create(this);
	}
	
	/**
	 * Destroy callback.
	 */
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		for (i in 0...m_faces.length) if (m_faces[i] != null) Resource.Destroy(m_faces[i]);		
	}
	
	/**
	 * Destroys the internal cross textures if the user sets any cubemap side with a custom texture.
	 */
	private function InvalidateCross():Void 
	{
		if (!m_is_cross) return;		
		for (i in 0...m_faces.length) if (m_faces[i] != null) Resource.Destroy(m_faces[i]);		
	}
	
	
	
	
}