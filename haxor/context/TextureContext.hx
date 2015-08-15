package haxor.context;
import haxor.component.MeshRenderer;
import haxor.component.SkinnedMeshRenderer;
import haxor.core.Console;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.core.Enums.TextureType;
import haxor.core.Enums.TextureWrap;
import haxor.graphics.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.graphics.texture.TextureCube;
import haxor.graphics.GL;
import haxor.io.Buffer;
import haxor.math.Mathf;
import haxor.platform.Types.Float32;
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
	 * Bound texture for a given slot.
	 */
	private var bind : Array<Texture>;
	
	/**
	 * Currently bound texture.
	 */
	private var bound : Texture;
		
	/**
	 * Currently active slot
	 */
	private var active : Int;
	
	/**
	 * Next texture slot.
	 */
	private var next_slot : Int;
	
	/**
	 * Flag that indicates if texture upload is going to be flipped (html);
	 */
	private var is_flip_y : Bool;
	
	/**
	 * Creates the TextureContext.
	 */
	public function new() 
	{
		tid 	= new UID();
		bind 	= null;
		target  = null;
		active 	= -1;	
		next_slot = 0;
		bind	= [];
		ids		= [];		
		
		framebuffers = [];
		renderbuffers = [];
	}
	
	/**
	 * Initializes the context when the graphics API is available.
	 */
	private function Initialize():Void
	{
		for (i in 0...GL.MAX_ACTIVE_TEXTURE) bind.push(null);
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
		p_texture.__slot = -1;// next_slot % (GL.MAX_ACTIVE_TEXTURE);		
		//next_slot++;
		
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
	private function Bind(p_texture : Texture,p_slot:Int=-1):Void
	{
		if (p_slot < 0)
		{			
			ApplyBind(p_texture,false);
		}
		else
		{
			if (bind[p_slot] != p_texture)
			{
				if (active != p_slot) 
				{ 
					GL.ActiveTexture(GL.TEXTURE0 + p_slot); 
					active = p_slot; 
				}
				ApplyBind(p_texture,true);
			}
		}				
	}
	
	/**
	 * Effectively binds the texture.
	 * @param	p_texture
	 */
	private function ApplyBind(p_texture : Texture,p_force:Bool):Void
	{
		if ((bound != p_texture) || p_force) 
		{ 
			bind[active] = p_texture;
			var id 		: TextureId = ids[p_texture.__cid];		
			var target 	: Int 		= TextureToTarget(p_texture);						
			GL.BindTexture(target, id); 
			bound = p_texture; 
		}
	}
	
	/**
	 * Unbinds the current texture.
	 */
	private function Unbind():Void
	{	
		if (bound != null)
		{
			bound = null;
			GL.BindTexture(GL.TEXTURE_2D, GL.NULL);
		}
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
		
		var minf : Int = p_texture.minFilter;
		var magf : Int = p_texture.magFilter;
		
		var is_half :Bool = false;
		if (p_texture.format == PixelFormat.Half)  is_half = true;
		if (p_texture.format == PixelFormat.Half3) is_half = true;
		if (p_texture.format == PixelFormat.Half4) is_half = true;
		
		var is_float :Bool = false;
		if (p_texture.format == PixelFormat.Float)  is_float = true;
		if (p_texture.format == PixelFormat.Float3) is_float = true;
		if (p_texture.format == PixelFormat.Float4) is_float = true;
		
		if (is_half)		
		if (!GL.TEXTURE_HALF_LINEAR)
		{
			minf = TextureFilter.Nearest;
			magf = TextureFilter.Nearest;
		}
		
		if (is_float)
		if (!GL.TEXTURE_FLOAT_LINEAR)
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
	private function UploadTexture(p_texture:Texture2D,p_x:Int,p_y:Int,p_width:Int,p_height:Int,p_steps:Int,p_on_complete:Void->Void=null):Void
	{	
		var b : Bitmap = p_texture.data;
		var py : Int 		= p_y;
		var chn_fmt  : Int 	= FormatToChannelLayout(p_texture.m_format);
		var chn_bit  : Int 	= FormatToChannelBits(p_texture.m_format);
		var chn_type : Int  = FormatToChannelType(p_texture.m_format);	
		var steps 	 : Int  = Std.int(p_height / p_steps);
		if (steps <= 1) steps = 1;
		var ua : Activity = new Activity(function(t : Float32):Bool
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
			var is_ti2d : Bool = (p_texture.type == TextureType.Compute) || (p_texture.type == TextureType.Texture2D);			
			if (is_ti2d)
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
	 * Extracts the cubemap faces from a cross texture.
	 * @param	ct
	 * @param	t
	 */
	private function CrossToCubemap(tc : TextureCube, cross : Texture2D):Void
	{		
		var target:Int = TextureToTarget(tc);		
		var chn_fmt  : Int 	= FormatToChannelLayout(tc.m_format);
		var chn_bit  : Int 	= FormatToChannelBits(tc.m_format);
		var chn_type : Int  = FormatToChannelType(tc.m_format);	
		var cells : Array<Int> = [1, 4, 5, 6, 7, 9];
		var sides : Array<Int> = 
		[
			GL.TEXTURE_CUBE_MAP_NEGATIVE_Y,			
			GL.TEXTURE_CUBE_MAP_NEGATIVE_X,
			GL.TEXTURE_CUBE_MAP_POSITIVE_Z,
			GL.TEXTURE_CUBE_MAP_POSITIVE_X,
			GL.TEXTURE_CUBE_MAP_NEGATIVE_Z,
			GL.TEXTURE_CUBE_MAP_POSITIVE_Y			
		];
		var cw  : Int  = cast (cross.width / 4);
		var ch  : Int  = cast (cross.height / 3);
		var bpp : Int  = cross.data.channels * cross.data.buffer.bytesPerElement;
		var line_bytes :Int  = cw * bpp;
		var line_offset : Int = cross.width * bpp;		
		Activity.RunOnce(
		function():Void		
		{
			Bind(tc);
			for (i in 0...cells.length)
			{
				var cid : Int = cells[i];
				var sid : Int = sides[i];
				var px  : Int = (cid % 4) * cw;
				var py  : Int = cast Mathf.Floor(cid / 4) * ch;
				var pos : Int = (px + (py * cross.width));
				GL.TexImage2DAlloc(sid, 0,chn_fmt,cw,ch,0, chn_bit, chn_type);
				for (j in 0...ch)
				{						
					cross.data.buffer.SetViewSlice(pos * bpp, line_bytes);
					GL.TexSubImage2D(sid, 0, 0, (ch-1) - j, cw, 1, chn_fmt, chn_type, cross.data.buffer);
					cross.data.buffer.ResetSlice();
					pos += cross.width;
				}					
			}			
		}
		,false,true);
			
		
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
	static private function FormatToChannelBits(p_format : Int):Int
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
			case PixelFormat.sRGB: 		return GL.TEXTURE_SRGB ? GL.SRGB : GL.RGB;
			case PixelFormat.sRGBA:     return GL.TEXTURE_SRGB ? GL.SRGB_ALPHA : GL.RGBA;
			case PixelFormat.sRGBA8:    return GL.TEXTURE_SRGB ? GL.SRGB8_ALPHA8 : GL.RGBA;
		}
		return GL.RGBA;
	}
	
	/**
	 * Returns the channel component format based on the pixel format.
	 * @param	p_format
	 * @return
	 */
	static private function FormatToChannelType(p_format : Int) : Int
	{
		switch(p_format)
		{
			case PixelFormat.Half, PixelFormat.Half3, PixelFormat.Half4 :    return GL.HALF_FLOAT;
			case PixelFormat.Float, PixelFormat.Float3, PixelFormat.Float4 : return GL.FLOAT;
			case PixelFormat.Depth: return GL.UNSIGNED_SHORT;
			case PixelFormat.RGBA8, PixelFormat.RGB8, PixelFormat.Luminance, PixelFormat.Alpha8: return GL.UNSIGNED_BYTE;
			case PixelFormat.sRGB: 		return GL.UNSIGNED_BYTE;
			case PixelFormat.sRGBA:     return GL.UNSIGNED_BYTE;
			case PixelFormat.sRGBA8:    return GL.UNSIGNED_BYTE;
		}		
		return GL.UNSIGNED_BYTE;
	}
	
	/**
	 * Returns the pixel layout based on the pixel format.
	 * @param	p_format
	 * @return
	 */
	static private function FormatToChannelLayout(p_format : Int):Int
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
			
			case PixelFormat.sRGB: 		return GL.TEXTURE_SRGB ? GL.SRGB : GL.RGB;
			case PixelFormat.sRGBA:     return GL.TEXTURE_SRGB ? GL.SRGB_ALPHA : GL.RGBA;
			case PixelFormat.sRGBA8:    return GL.TEXTURE_SRGB ? GL.SRGB8_ALPHA8 : GL.RGBA;
			
		}		
		return GL.RGBA;
	}
	
}