/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.api;
import js.Boot;
import js.html.ArrayBufferView;
import js.html.Uint8Array;
import js.html.webgl.Framebuffer;
import js.html.webgl.GL;
import js.html.webgl.RenderingContext;
import haxor.core.Console;
import haxor.graphics.Mesh;
import haxor.math.Mathf;
import haxor.texture.RenderTexture;
import haxor.texture.Texture;
import haxor.texture.TextureCube;
import haxor.texture.TextureHTML;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class TextureAPI
{
	//Temp enums while extensions aren't finished
	static public var HALF_FLOAT_LINEAR			: Bool = false;
	
	//Temp enums while extensions aren't finished
	static public var HALF_FLOAT_OES 				: Int  = -1;
	
	//Temp enums while extensions aren't finished
	static public var TEXTURE_MAX_ANISOTROPY_EXT 	: Int  = -1;
	
	//Temp enums while extensions aren't finished
	static public var TEXTURE_FLOAT : Bool = false;
	
	//Temp enums while extensions aren't finished
	static public var TEXTURE_DEPTH : Bool = false;
	
	static private var c : RenderingContext;
	
	static private var m_active : Int;
	
	static private var m_slots : Array<Texture>;
	
	static private var m_actives : Array<Bool>;
	
	static private var m_buffer : RenderTexture;
	
	static public function Initialize(p_context : RenderingContext):Void
	{
		c = p_context;
		m_active = -1;
		m_slots = [];
		m_actives = [];
		m_buffer = null;
		for (i in 0...256) 
		{
			m_slots.push(null);
			m_actives.push(false);
		}
	}
	
	static public function SetParameters(p_texture : Texture):Void
	{		
		var flag:Int = p_texture.type;
		
		Bind(p_texture);
		
		c.texParameteri(flag, GL.TEXTURE_WRAP_S, (p_texture.wrap & TextureWrap.ClampX) != 0 ?  GL.CLAMP_TO_EDGE : GL.REPEAT);
		c.texParameteri(flag, GL.TEXTURE_WRAP_T, (p_texture.wrap & TextureWrap.ClampY) != 0 ?  GL.CLAMP_TO_EDGE : GL.REPEAT);
		
		if (TEXTURE_MAX_ANISOTROPY_EXT > 0) 		c.texParameterf(flag, TEXTURE_MAX_ANISOTROPY_EXT, Math.max(1, p_texture.aniso));
		
		var minf : TextureFilter = p_texture.minFilter;
		var magf : TextureFilter = p_texture.magFilter;
		
		if (p_texture.format == TextureFormat.Half)		
		if (!HALF_FLOAT_LINEAR)
		{
			minf = TextureFilter.Nearest;
			magf = TextureFilter.Nearest;
		}
		
		switch(minf)
		{
			case TextureFilter.Nearest: 			 c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.NEAREST);
			case TextureFilter.NearestMipmapLinear:  c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_LINEAR); 
			case TextureFilter.NearestMipmapNearest: c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_NEAREST); 
			case TextureFilter.Linear:  			 c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.LINEAR); 
			case TextureFilter.LinearMipmapLinear:	 c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR); 
			case TextureFilter.Trilinear:	 		 c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR); 			
			case TextureFilter.LinearMipmapNearest:	 c.texParameteri(flag, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_NEAREST); 
			
		}
		
		switch(magf)
		{
			case TextureFilter.Nearest: 			 c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
			case TextureFilter.NearestMipmapLinear:  c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.NEAREST); 
			case TextureFilter.NearestMipmapNearest: c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.NEAREST); 
			case TextureFilter.Linear:  			 c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 
			case TextureFilter.LinearMipmapLinear:	 c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 
			case TextureFilter.Trilinear:	 		 c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 			
			case TextureFilter.LinearMipmapNearest:	 c.texParameteri(flag, GL.TEXTURE_MAG_FILTER, GL.LINEAR);  
		}		
	}

	static public function Create(p_texture : Texture) : Void
	{
		var id : js.html.webgl.Texture = c.createTexture();		
		p_texture.m_type = Std.is(p_texture, TextureCube) ? GL.TEXTURE_CUBE_MAP : GL.TEXTURE_2D;
		p_texture.m_gid  = id;		
		SetParameters(p_texture);
		
		if (Std.is(p_texture, RenderTexture))
		{
			var rt : RenderTexture = cast p_texture;
			
			rt.m_fid = c.createFramebuffer();
			c.bindFramebuffer(GL.FRAMEBUFFER, rt.m_fid);			
			
			Alloc(rt);
			
			c.framebufferTexture2D(GL.FRAMEBUFFER, GL.COLOR_ATTACHMENT0, GL.TEXTURE_2D, rt.gid, 0);
			
			if (rt.depth != null)
			{
				c.framebufferTexture2D(GL.FRAMEBUFFER, GL.DEPTH_ATTACHMENT, GL.TEXTURE_2D, rt.depth.m_gid, 0);							
			}
			else
			{
				rt.m_rid = c.createRenderbuffer();
				c.bindRenderbuffer(GL.RENDERBUFFER, rt.m_rid);
				c.renderbufferStorage(GL.RENDERBUFFER, GL.DEPTH_COMPONENT16, rt.width, rt.height);
				c.framebufferRenderbuffer(GL.FRAMEBUFFER, GL.DEPTH_ATTACHMENT, GL.RENDERBUFFER, rt.m_rid);
			}			
			
			c.bindFramebuffer(GL.FRAMEBUFFER, null);
			c.bindRenderbuffer(GL.RENDERBUFFER, null);
			Unbind(rt);
		}
	}
	
	static public function Apply(p_texture : Texture) : Void
	{
		var id : js.html.webgl.Texture;				
		if (p_texture.gid == null) Create(p_texture);
		id = p_texture.gid;
		
		var flag:Int = p_texture.type;		
		c.bindTexture(flag, id);				
		if (flag == GL.TEXTURE_CUBE_MAP)
		{
			var tc : TextureCube = cast p_texture;						
			if (tc.px != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X	  , tc.px);			
			if (tc.nx != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X + 1, tc.nx);			
			if (tc.py != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X + 2, tc.py);
			if (tc.ny != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X + 3, tc.ny);
			if (tc.pz != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X + 4, tc.pz);
			if (tc.nz != null) WriteTexture(GL.TEXTURE_CUBE_MAP_POSITIVE_X + 5, tc.nz);			
		}
		else
		{						
			WriteTexture(flag, p_texture);
		}
	}
	
	static public function WritePixels(p_texture : Texture, p_x:Int, p_y:Int,p_pixels : ArrayBufferView,p_width:Int=-1,p_height=-1) :Void
	{
		Bind(p_texture);
		var w : Int = p_width < 0 ? p_texture.width : p_width;
		var h : Int = p_height < 0 ? p_texture.height : p_height;
		var chn_fmt : Int 	= ChannelLayout(p_texture);
		var chn_bit :Int 	= ChannelBits(p_texture);
		var chn_type : Int  = ChannelType(p_texture);	
		
		
		if ((p_height < 0)||(p_width < 0))
		{	
			c.texImage2D(GL.TEXTURE_2D, 0, chn_fmt, w, h, 0, chn_bit, chn_type, p_pixels); 			
		}
		else
		{		
			c.texSubImage2D(GL.TEXTURE_2D, 0, p_x, p_y, w, h, chn_fmt, chn_type, p_pixels);
		}
		
		//Unbind(p_texture);
	}
	
	static public function Alloc(p_texture : Texture,p_invert_y:Bool=false) :Void
	{		
		var w :Int  = p_texture.width;
		var h : Int = p_texture.height;
		var chn_fmt : Int 	= ChannelLayout(p_texture);
		var chn_bit :Int 	= ChannelBits(p_texture);
		var chn_type : Int  = ChannelType(p_texture);
		Bind(p_texture);		
		if(p_invert_y) c.pixelStorei(GL.UNPACK_FLIP_Y_WEBGL, 1);
		c.texImage2D(p_texture.type, 0, chn_fmt, w, h, 0, chn_bit, chn_type, null);
	}
	
	static function WriteTexture(p_flag : Int, p_texture : Texture,p_flip_y : Bool=false) :Void
	{	
		var d : Dynamic = p_texture.data;
		
		if (d == null)
		{
			c.texImage2D(p_flag, 0, GL.RGB, 1, 1, 0, GL.RGB, GL.UNSIGNED_BYTE, new Uint8Array( [128, 64, 64]));
			return;
		}
		
		var w :Int  = p_texture.width;
		var h : Int = p_texture.height;
		var chn_fmt : Int 	= ChannelLayout(p_texture);
		var chn_bit :Int 	= ChannelBits(p_texture);
		var chn_type : Int  = ChannelType(p_texture);		
		var is_element : Bool = p_texture.html;			
		
		c.pixelStorei(GL.UNPACK_FLIP_Y_WEBGL, p_flip_y ? 1 : 0);
		if (is_element)
		{
			if (p_flag == GL.TEXTURE_2D) c.pixelStorei(GL.UNPACK_FLIP_Y_WEBGL, p_flip_y ? 0 : 1);						
			c.texImage2D(p_flag, 0, chn_fmt, chn_bit, chn_type, d);			
		}
		else
		{	
			if (p_texture.format == TextureFormat.Depth) d = null;
			c.texImage2D(p_flag, 0, chn_fmt, w, h, 0, chn_bit, chn_type, d);
		}		
	}
	
	
	
	static public function Activate(p_texture : Texture, p_slot : Int):Void
	{
		m_active = m_active < 0 ? 1 : cast Mathf.Max([m_active, p_slot]);
		
		c.activeTexture(GL.TEXTURE0 + p_slot);
		
		Bind(p_texture);
		
		return;
		
		if (!m_actives[p_slot])
		{ 
			c.activeTexture(GL.TEXTURE0 + p_slot);
			m_actives[p_slot] = true;
		}
		m_active = m_active < 0 ? 1 : cast Mathf.Max([m_active, p_slot]);
				
		if (m_slots[p_slot] != p_texture) 
		{ 
			Bind(p_texture);
			m_slots[p_slot] = p_texture; 
		}
		
		if (p_texture.html)
		{
			//Future MovieTexture
			var etex : TextureHTML = cast p_texture;					
			if (etex.video) WriteTexture(p_texture.type, p_texture);
		}	
		
		
	}
	
	static public function BindRT(p_render_texture : RenderTexture=null):Void 
	{		
		
		if (p_render_texture == null)
		{			
			if (m_buffer != p_render_texture) 
			{ 
				c.bindFramebuffer(GL.FRAMEBUFFER, null); 
				c.bindRenderbuffer(GL.RENDERBUFFER, null);
				m_buffer = null; 
			}
			//c.bindFramebuffer(GL.FRAMEBUFFER, null);
		}
		else
		{
			
			//c.bindFramebuffer(GL.FRAMEBUFFER, p_render_texture.m_fid);
			if (m_buffer != p_render_texture) 
			{ 
				c.bindFramebuffer(GL.FRAMEBUFFER, p_render_texture.m_fid); 				
				if(p_render_texture.depth == null) c.bindRenderbuffer(GL.RENDERBUFFER, p_render_texture.m_rid);
				m_buffer = p_render_texture; 
			}
		}
	}
	
	static public function Bind(p_texture : Texture):Void
	{	
		c.bindTexture(p_texture.type, p_texture.gid);				
	}
	
	static public function Unbind(p_texture : Texture):Void
	{	
		c.bindTexture(p_texture.type,null);				
	}
	
	static public function Finish():Void
	{
		
		for (i in 0...m_active)
		{
			//m_actives[i] = false;
			//m_slots[i] = null;
			c.activeTexture(GL.TEXTURE0 + i);
			c.bindTexture(GL.TEXTURE_2D, null);
			c.bindTexture(GL.TEXTURE_CUBE_MAP, null);
		}
		m_active = -1;
		
		//*/
	}
	
	
	static private function ChannelType(p_texture : Texture) : Int
	{
		if (p_texture.format == TextureFormat.Half)   return HALF_FLOAT_OES;
		if (p_texture.format == TextureFormat.Half3)  return HALF_FLOAT_OES;
		if (p_texture.format == TextureFormat.Half4)  return HALF_FLOAT_OES;
		if (p_texture.format == TextureFormat.Float)  return GL.FLOAT;
		if (p_texture.format == TextureFormat.Float3) return GL.FLOAT;		
		if (p_texture.format == TextureFormat.Float4) return GL.FLOAT;
		if (p_texture.format == TextureFormat.Depth)  return GL.UNSIGNED_SHORT;
		
		
		return GL.UNSIGNED_BYTE;
	}
	
	static private function ChannelLayout(p_texture : Texture):Int
	{
		switch (p_texture.format)
		{
			case TextureFormat.Alpha8:  						return GL.ALPHA;
			case TextureFormat.RGB8: 	  						return GL.RGB; 
			case TextureFormat.RGBA8: 	  						return GL.RGBA;
			case TextureFormat.Luminance, 
				 TextureFormat.Half,
				 TextureFormat.Float: 							return GL.LUMINANCE;
			case TextureFormat.Float3,
				 TextureFormat.Half3:							return GL.RGB;
			case TextureFormat.Float4,
				 TextureFormat.Half4:							return GL.RGBA;
			case TextureFormat.Depth:							return GL.DEPTH_COMPONENT;
		}		
		return GL.RGBA;
	}
	
	static private function ChannelBits(p_texture : Texture):Int
	{
		
		switch (p_texture.format)
		{
			case TextureFormat.Alpha8: 		return GL.ALPHA;
			case TextureFormat.RGB8: 		return GL.RGB; 
			case TextureFormat.RGBA8: 		return GL.RGBA;
			//case TextureFormat.RGB5:		return GL.RGB;
			
			case TextureFormat.Float,
				 TextureFormat.Half:		return GL.LUMINANCE;
			
			case TextureFormat.Float3,
				 TextureFormat.Half3:		return GL.RGB;
			
			case TextureFormat.Float4,
				 TextureFormat.Half4:		return GL.RGBA;
			
			case TextureFormat.Luminance: 	return GL.LUMINANCE;
			case TextureFormat.Depth:		return GL.DEPTH_COMPONENT;
		}
		return GL.RGBA;
	}
	
	static public function BuildMipmaps(p_texture : Texture) : Void
	{
		var id : js.html.webgl.Texture  = p_texture.gid;
		var flag:Int 					= p_texture.type;
		c.bindTexture(flag, id);
		c.generateMipmap(flag);	
		
	}
	
	/**
	 * 
	 * @param	p_texture
	 */
	static public function Destroy(p_texture : Texture):Void
	{		
		if (p_texture.gid != null) c.deleteTexture(p_texture.gid);
		if (Std.is(p_texture, RenderTexture))
		{
			var rt : RenderTexture = cast p_texture;
			if (rt.m_fid != null) c.deleteFramebuffer(rt.m_fid);
			if (rt.m_rid != null) c.deleteRenderbuffer(rt.m_rid);
		}
	}
	
}