/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.texture;
import js.html.webgl.Texture;
import haxor.api.TextureAPI;
import haxor.core.Resource;
import haxor.math.Color;

import haxor.texture.Texture;

/**
 * ...
 * @author Eduardo Pons
 */
class TextureCube extends Texture
{
	/**
	 * 
	 * @param	p_texture
	 * @return
	 */
	static public function FromCrossTexture(p_texture : Texture2D) : TextureCube
	{
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
	}
	
	var m_faces : Array<Texture>;
	
	var m_is_cross : Bool;
	
	/**
	 * 
	 */
	public var px(get_px, set_px) : Texture;
	var p_px : Texture;
	function get_px():Texture { return m_faces[0]; }
	function set_px(v:Texture):Texture { InvalidateCross(); m_faces[0] = v; return v; }
	
	/**
	 * 
	 */
	public var nx(get_nx, set_nx) : Texture;
	var p_nx : Texture;
	function get_nx():Texture { return m_faces[1]; }
	function set_nx(v:Texture):Texture { InvalidateCross(); m_faces[1] = v; return v; }
	
	/**
	 * 
	 */
	public var py(get_py, set_py) : Texture;
	var p_py : Texture;
	function get_py():Texture { return m_faces[2]; }
	function set_py(v:Texture):Texture { InvalidateCross(); m_faces[2] = v; return v; }
	
	/**
	 * 
	 */
	public var ny(get_ny, set_ny) : Texture;
	var p_ny : Texture;
	function get_ny():Texture { return m_faces[3]; }
	function set_ny(v:Texture):Texture { InvalidateCross(); m_faces[3] = v; return v; }
	
	/**
	 * 
	 */
	public var pz(get_pz, set_pz) : Texture;
	var p_pz : Texture;
	function get_pz():Texture { return m_faces[4]; }
	function set_pz(v:Texture):Texture { InvalidateCross(); m_faces[4] = v; return v; }
	
	/**
	 * 
	 */
	public var nz(get_nz, set_nz) : Texture;
	var p_nz : Texture;
	function get_nz():Texture { return m_faces[5]; }
	function set_nz(v:Texture):Texture { InvalidateCross(); m_faces[5] = v; return v; }
	

	/**
	 * 
	 */
	public function new() 
	{
		m_faces = [null, null, null, null, null, null];
		m_is_cross = false;
		super();
		TextureAPI.Create(this);
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		for (i in 0...m_faces.length) if (m_faces[i] != null) Resource.Destroy(m_faces[i]);		
	}
	
	function InvalidateCross():Void 
	{
		if (!m_is_cross) return;		
		for (i in 0...m_faces.length) if (m_faces[i] != null) Resource.Destroy(m_faces[i]);		
	}
	
	
	
	
}