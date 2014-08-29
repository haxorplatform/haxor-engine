package haxor.context;
import haxor.core.Console;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.core.Enums.TextureType;
import haxor.core.Enums.TextureWrap;
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.graphics.texture.TextureCube;
import haxor.graphics.GL;
import haxor.io.Buffer;
import haxor.platform.Types.FrameBufferId;
import haxor.platform.Types.RenderBufferId;
import haxor.platform.Types.TextureId;
import haxor.thread.Activity;



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
	private var tid : UID;
	
	/**
	 * Texture ids for all Texture instances.
	 */
	private var ids : Array <TextureId>;
	
	/**
	 * Frame buffer ids for all RenderTextures.
	 */
	private var framebuffers : Array <FrameBufferId>;
	
	/**
	 * Render buffer ids for all RenderTextures.
	 */
	private var renderbuffers : Array <RenderBufferId>;
	
	/**
	 * Reference to the current render target.
	 */
	private var target : RenderTexture;
	
	
	/**
	 * Active texture for a given slot.
	 */
	private var active : Array<Texture>;
	
	/**
	 * Currently bound texture.
	 */
	private var bind : Texture;
		
	private var slot : Int;
	
	/**
	 * Creates the TextureContext.
	 */
	public function new() 
	{
		tid 	= new UID();
		bind 	= null;
		target  = null;
		active 	= [];		
		ids		= [];
		slot    = 0;
		framebuffers = [];
		renderbuffers = [];
	}
	
	/**
	 * Initializes the context when the graphics API is available.
	 */
	private function Initialize():Void
	{
		for (i in 0...GL.MAX_ACTIVE_TEXTURE) active.push(null);
		for (i in 0...2048)
		{
			ids.push(GL.INVALID);
			framebuffers.push(GL.INVALID);
			renderbuffers.push(GL.INVALID);
		}
	}
	
	/**
	 * Prepares the memory region for the incoming texture.
	 * @param	p_texture
	 */
	private function Alloc(p_texture:Texture):Void
	{
		var w : Int = p_texture.width;
		var h : Int = p_texture.height;
		var chn_fmt  : Int 	= FormatToChannelLayout(p_texture.m_format);
		var chn_bit  : Int 	= FormatToChannelBits(p_texture.m_format);
		var chn_type : Int  = FormatToChannelType(p_texture.m_format);
		var tex_type : Int  = TextureToTarget(p_texture);
		Bind(p_texture);		
		GL.TexImage2DAlloc(tex_type, 0, chn_fmt, w, h, 0, chn_bit, chn_type);
	}
	
	/**
	 * Creates a new Texture in the API.
	 * @param	p_texture
	 */
	private function Create(p_texture:Texture):Void
	{
		p_texture.__slot = slot % GL.MAX_ACTIVE_TEXTURE;
		
		slot++;
		
		var id : TextureId = GL.CreateTexture();
		
		
		ids[p_texture.__cid] = id;
		
		UpdateParameters(p_texture);
		
		if (p_texture.type != TextureType.TextureCube)
		//if (p_texture.type == TextureType.Texture2D)
		{
			Alloc(p_texture);
		}
		
		if (p_texture.type == TextureType.RenderTexture)
		{
			var rt : RenderTexture = cast p_texture;
			
			var fb_id : FrameBufferId = GL.CreateFramebuffer();
			framebuffers[p_texture.__cid] = fb_id;
			
			GL.BindFramebuffer(GL.FRAMEBUFFER,fb_id);
			
			//Alloc(p_texture);
			
			GL.FramebufferTexture2D(GL.FRAMEBUFFER, GL.COLOR_ATTACHMENT0, GL.TEXTURE_2D, id, 0);
			
			if (rt.depth != null)
			{
				var depth_id : TextureId = ids[rt.depth.__cid];
				GL.FramebufferTexture2D(GL.FRAMEBUFFER, GL.DEPTH_ATTACHMENT, GL.TEXTURE_2D,depth_id, 0);							
			}
			else
			{
				var rb_id : RenderBufferId = GL.CreateRenderbuffer();
				renderbuffers[p_texture.__cid] = rb_id;
				GL.BindRenderbuffer(GL.RENDERBUFFER, rb_id);
				GL.RenderbufferStorage(GL.RENDERBUFFER, GL.DEPTH_COMPONENT16, rt.width, rt.height);
				GL.FramebufferRenderbuffer(GL.FRAMEBUFFER, GL.DEPTH_ATTACHMENT, GL.RENDERBUFFER, rb_id);
			}			
			
			GL.BindFramebuffer(GL.FRAMEBUFFER, GL.NULL);
			GL.BindRenderbuffer(GL.RENDERBUFFER, GL.NULL);
			Unbind();
		}
		
	}
	
	/**
	 * Binds the Texture for usage.
	 * @param	p_texture
	 */
	private inline function Bind(p_texture : Texture):Void
	{
		if (p_texture == bind) return;
		bind = p_texture;
		var id 		: TextureId = ids[bind.__cid];		
		var target 	: Int 		= TextureToTarget(bind);		
		GL.BindTexture(target,id);
	}
	
	/**
	 * Unbinds the current texture.
	 */
	private inline function Unbind():Void
	{
		if (bind == null) return;				
		var target 	: Int 		= TextureToTarget(bind);	
		bind = null;
		GL.BindTexture(target, GL.NULL);
	}
	
	
	/**
	 * Updates parameters such as wrapping, filtering and others.
	 * @param	p_texture
	 */
	private inline function UpdateParameters(p_texture : Texture):Void
	{
		var target:Int = TextureToTarget(p_texture);
		
		Bind(p_texture);
		
		GL.TexParameteri(target, GL.TEXTURE_WRAP_S, (p_texture.wrap & TextureWrap.ClampX) != 0 ?  GL.CLAMP_TO_EDGE : GL.REPEAT);		
		GL.TexParameteri(target, GL.TEXTURE_WRAP_T, (p_texture.wrap & TextureWrap.ClampY) != 0 ?  GL.CLAMP_TO_EDGE : GL.REPEAT);
		
		
		if(GL.TEXTURE_ANISOTROPY_ENABLED) GL.TexParameterf(target, GL.TEXTURE_ANISOTROPY,cast Math.max(1, p_texture.aniso));
		
		var minf : TextureFilter = p_texture.minFilter;
		var magf : TextureFilter = p_texture.magFilter;
		
		if (p_texture.format == PixelFormat.Half)		
		if (!GL.TEXTURE_HALF_LINEAR)
		{
			minf = TextureFilter.Nearest;
			magf = TextureFilter.Nearest;
		}
		
		switch(minf)
		{
			case TextureFilter.Nearest: 			 GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.NEAREST);
			case TextureFilter.NearestMipmapLinear:  GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_LINEAR); 
			case TextureFilter.NearestMipmapNearest: GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_NEAREST); 
			case TextureFilter.Linear:  			 GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.LINEAR); 
			case TextureFilter.LinearMipmapLinear:	 GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR); 
			case TextureFilter.Trilinear:	 		 GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR); 			
			case TextureFilter.LinearMipmapNearest:	 GL.TexParameteri(target, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_NEAREST); 
			
		}
		
		
		switch(magf)
		{
			case TextureFilter.Nearest: 			 GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
			case TextureFilter.NearestMipmapLinear:  GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.NEAREST); 
			case TextureFilter.NearestMipmapNearest: GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.NEAREST); 
			case TextureFilter.Linear:  			 GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 
			case TextureFilter.LinearMipmapLinear:	 GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 
			case TextureFilter.Trilinear:	 		 GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.LINEAR); 			
			case TextureFilter.LinearMipmapNearest:	 GL.TexParameteri(target, GL.TEXTURE_MAG_FILTER, GL.LINEAR);  
		}		
	}
	
	/**
	 * Updates the texture data in the API.
	 * @param	p_texture
	 */
	private function Update(p_texture:Texture):Void
	{
		var target:Int = TextureToTarget(p_texture);
		Bind(p_texture);		
		if (target == GL.TEXTURE_CUBE_MAP)
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
			WriteTexture(target, p_texture);
		}
	}
	
	/**
	 * Upload all pixels of the Texture2D async.
	 * @param	p_texture
	 */
	private function UploadTexture(p_texture:Texture2D,p_x:Int,p_y:Int,p_width:Int,p_height:Int,p_steps:Int,p_on_complete:Void->Void):Void
	{	
		var b : Bitmap = p_texture.data;
		var py : Int 		= p_y;
		var chn_fmt  : Int 	= FormatToChannelLayout(p_texture.m_format);
		var chn_bit  : Int 	= FormatToChannelBits(p_texture.m_format);
		var chn_type : Int  = FormatToChannelType(p_texture.m_format);	
		var steps 	 : Int  = Std.int(p_height / p_steps);
		if (steps <= 1) steps = 1;
		var ua : Activity = new Activity(function(t : Float):Bool
		{
			if (py >= p_height) { if (p_on_complete != null) p_on_complete(); return false; }
			Bind(p_texture);
			for (i in 0...steps)
			{
				if (py < 0) { py++; continue; }
				if (py >= b.height) { if (p_on_complete != null) p_on_complete(); return false; }				
				var pos : Int = (p_x + py * p_width) * b.channels;
				var len : Int = p_width * b.channels;				
				b.buffer.SetViewSlice(pos, len);
				GL.TexSubImage2D(GL.TEXTURE_2D, 0, p_x, py, p_width, 1, chn_fmt, chn_type, b.buffer);
				b.buffer.ResetSlice();				
				py++;				
			}
			return true;
		},false,true);
	}
	
	
	/**
	 * Writes the contents of a texture to the API memory.
	 * @param	p_texture
	 */
	private function WriteTexture(p_target : Int,p_texture:Texture):Void
	{
		var w :Int  = p_texture.width;
		var h : Int = p_texture.height;
		var chn_fmt  : Int 	= FormatToChannelLayout(p_texture.m_format);
		var chn_bit  : Int 	= FormatToChannelBits(p_texture.m_format);
		var chn_type : Int  = FormatToChannelType(p_texture.m_format);		
				
		if (p_texture.format == PixelFormat.Depth)
		{
			GL.TexImage2DAlloc(p_target, 0, chn_fmt, w, h, 0, chn_fmt, chn_type);
		}
		else
		{
			if (p_texture.type == TextureType.Texture2D)
			{
				var t2d : Texture2D = cast p_texture;						
				GL.TexImage2D(p_target, 0, chn_fmt, w, h, 0, chn_bit, chn_type, t2d.data.buffer);
			}
			else
			if (p_texture.type == TextureType.RenderTexture)
			{
				var rt : RenderTexture = cast p_texture;
				var id : TextureId = ids[rt.__cid];
				GL.FramebufferTexture2D(GL.FRAMEBUFFER, GL.COLOR_ATTACHMENT0,p_target,id,0);
			}
		}	
	}
	
	/**
	 * Activates the texture for uniform binding
	 * @param	p_texture
	 * @param	p_slot
	 */
	private function Activate(p_texture : Texture,p_slot:Int):Void
	{		
		var slot : Int = p_texture.__slot;
		if (active[p_slot] == p_texture) return;		
		active[p_slot] = p_texture;		
		GL.ActiveTexture(GL.TEXTURE0 + p_slot);		
		Bind(p_texture);		
	}
	
	/**
	 * Binds the RenderTexture as rendering target.
	 * @param	rt
	 */
	private function BindTarget(rt : RenderTexture):Void 
	{		
		
		if (rt == null)
		{			
			if (target != rt) 
			{ 
				GL.BindFramebuffer(GL.FRAMEBUFFER, GL.NULL); 
				GL.BindRenderbuffer(GL.RENDERBUFFER, GL.NULL);
				target = null; 
			}			
		}
		else
		{
			if (target != rt) 
			{ 
				var fb_id : FrameBufferId = framebuffers[rt.__cid];
				GL.BindFramebuffer(GL.FRAMEBUFFER, fb_id); 				
				if (rt.depth == null)
				{
					var rb_id : RenderBufferId = renderbuffers[rt.__cid];
					GL.BindRenderbuffer(GL.RENDERBUFFER, rb_id);
				}
				target = rt; 
			}
		}
	}
	
	/**
	 * Updates the mipmap data for this texture.
	 * @param	p_texture
	 */
	public function UpdateMipmaps(p_texture:Texture):Void
	{
		Bind(p_texture);
		var target:Int = TextureToTarget(p_texture);
		GL.GenerateMipmap(target);		
	}
	
	/**
	 * Destroys all data for the informed Texture.
	 * @param	p_texture
	 */
	public function Destroy(p_texture:Texture):Void
	{
		var tex_id : TextureId = ids[p_texture.__cid];
		if (tex_id != GL.INVALID) GL.DeleteTexture(tex_id);
		if (p_texture.type == TextureType.RenderTexture)
		{
			var fb_id : FrameBufferId 	= framebuffers[p_texture.__cid];
			var rb_id : RenderBufferId	= renderbuffers[p_texture.__cid];			
			if (fb_id != GL.INVALID) GL.DeleteFramebuffer(fb_id);
			if (rb_id != GL.INVALID) GL.DeleteRenderbuffer(rb_id);
		}
		EngineContext.texture.tid.id = p_texture.__cid;
	}
	
	/**
	 * Returns the bind target for a given texture.
	 * @param	p_texture
	 * @return
	 */
	static private inline function TextureToTarget(p_texture:Texture):Int
	{
		if (p_texture.type == TextureType.Texture2D) 	 	return GL.TEXTURE_2D;
		if (p_texture.type == TextureType.RenderTexture) 	return GL.TEXTURE_2D;
		if (p_texture.type == TextureType.TextureCube) 		return GL.TEXTURE_CUBE_MAP;		
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