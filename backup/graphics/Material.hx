/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics;

import js.html.Float32Array;
import js.html.webgl.UniformLocation;
import haxor.api.MaterialAPI;
import haxor.graphics.BlendMode;
import haxor.graphics.CullMode;
import haxor.graphics.DepthTest;
import haxor.graphics.RenderQueue;
import haxor.core.Resource;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.math.Matrix4;
import haxor.texture.RenderTexture;
import haxor.texture.Texture;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Material extends Resource
{
	/**
	 * 
	 */
	static public var error(get_error, never) : Material;
	static var m_error : Material;
	static function get_error():Material
	{
		if (m_error != null) return m_error;
		m_error = new Material();
		m_error.queue = RenderQueue.Background;
		m_error.cull = CullMode.None;
		m_error.name = "$MaterialError";
		m_error.shader = Shader.error;
		return m_error;
	}
	
	/**
	 * 
	 */
	static public var blit(get_blit, never) : Material;
	static var m_blit : Material;
	static function get_blit():Material
	{
		if (m_blit != null) return m_blit;
		m_blit = new Material();
		m_blit.queue = RenderQueue.Background;
		m_blit.cull = CullMode.None;
		m_blit.name = "$MaterialBlit";
		m_blit.shader = Shader.blit;
		return m_blit;
	}
	
	/**
	 * 
	 */
	static public var gui(get_gui, never) : Material;
	static var m_gui : Material;
	static function get_gui():Material
	{
		if (m_gui != null) return m_gui;
		m_gui 			= new Material();
		m_gui.queue 	= RenderQueue.Background;
		m_gui.cull 		= CullMode.None;
		m_gui.name 		= "$MaterialGUI";		
		m_gui.ztest 	= false;
		return m_gui;
	}
	
	/**
	 * 
	 */
	static public var skybox(get_skybox, never) : Material;
	static var m_skybox : Material;
	static function get_skybox():Material
	{
		
		if (m_skybox != null) return m_skybox;
		m_skybox = new Material();		
		m_skybox.name = "$SkyboxMaterial";
		m_skybox.blend 	  = true;
		m_skybox.ztest 	  = false;
		m_skybox.zwrite	  = false; 
		m_skybox.blendSrc = BlendMode.SrcAlpha;
		m_skybox.blendDst = BlendMode.OneMinusSrcAlpha;
		m_skybox.shader = Shader.skybox;
		return m_skybox;
	}
	
	public var ztest:Bool;
	
	public var zfunc : Int;

	public var zwrite:Bool;
	
	public var blend:Bool;
		
	public var queue : Int;

	public var blendSrc : Int;
	
	public var blendDst : Int;

	public var invert : Bool;
	
	public var lighting : Bool;

	public var cull : Int;
	
	public var screen : RenderTexture;
	
	public var grab : Bool = false;
	
	public var shader(get_shader,set_shader) : Shader;
	private function get_shader():Shader { return m_shader; }
	private function set_shader(v:Shader):Shader 
	{		
		if (m_shader == v) return v;
		m_shader = v;				
		if (MaterialAPI.m_current == this) MaterialAPI.m_current = null;		
		return v; 
	}
	private var m_shader : Shader;
	
	/**
	 * 
	 */
	public var uniforms(get_uniforms, never):Iterator<String>;
	var m_uniforms  : Map<String,Dynamic>;
	var m_locations : Map<String,UniformLocation>;	
	var m_changed : Map<String,Bool>;	
	function get_uniforms():Iterator<String> { return m_uniforms.keys(); }
	
	
	public function new() 
	{
		super();		
		queue           = RenderQueue.Geometry;
		zfunc           = DepthTest.LessEqual;
		ztest		    = true;
		zwrite			= true;
		blend		    = false;
		blendSrc        = BlendMode.One;
		blendDst        = BlendMode.Zero;
		invert		    = false;
		lighting		= false;
		grab			= false;
		cull            = CullMode.Back; 			
		m_uniforms  = new Map<String,Dynamic>();
		m_locations = new Map<String,UniformLocation>();
		m_changed   = new Map<String,Bool>();
		
		
	}
	
	public function SetBlending(p_src : Int, p_dst : Int):Void
	{
		blend = !((p_src == BlendMode.One) && (p_dst == BlendMode.Zero));
		blendSrc = p_src;
		blendDst = p_dst;
	}
	
	/**
	 * 
	 * @param	p_name
	 * @param	p_data
	 */
	public function SetUniform(p_name : String, p_value : Dynamic) : Void 
	{ 
		if (p_value == null) m_uniforms.remove(p_name); 
		else
		{ 			
			m_uniforms.set(p_name, p_value); 
			var k : String = shader == null ? p_name : (p_name + shader.id);
			m_changed.set(k, true); 			
			//m_changed.set(p_name, true);
		} 
	}
	
	/**
	 * 
	 * @param	p_name
	 * @return
	 */
	public function GetUniform(p_name : String) : Dynamic 
	{ 
		return m_uniforms.get(p_name);
		//if (m_uniforms.exists(p_name)) return m_uniforms.get(p_name); return null; 
	}
	
	override private function Clone():Dynamic 
	{
		var m : Material = new Material();
		m.name 			= name + "Copy";
		m.shader 		= shader;
		m.queue         = queue;
		m.zfunc         = zfunc;
		m.ztest		    = ztest;
		m.zwrite		= zwrite;
		m.blend		    = blend;
		m.blendSrc      = blendSrc;
		m.blendDst      = blendDst;
		m.invert		= invert;
		m.cull          = cull; 	
		m.lighting		= lighting;
		m.grab			= grab;
		var ul : Iterator<String> = uniforms;
		while (ul.hasNext())
		{
			var u : String = ul.next();
			m.SetUniform(u, GetUniform(u));
		}
		return m;		
	}
	
	
}