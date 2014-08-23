package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TextureContext extends haxe.lang.HxObject
{
	public    TextureContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    TextureContext()
	{
		haxor.context.TextureContext.__hx_ctor_haxor_context_TextureContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_TextureContext(haxor.context.TextureContext __temp_me56086)
	{
		__temp_me56086.tid = 0;
		__temp_me56086.bind = null;
		__temp_me56086.target = null;
		__temp_me56086.active = new haxe.root.Array<haxor.graphics.texture.Texture>(new haxor.graphics.texture.Texture[]{});
		__temp_me56086.ids = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me56086.framebuffers = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me56086.renderbuffers = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	}
	
	
	public static   int TextureToTarget(haxor.graphics.texture.Texture p_texture)
	{
		if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
		{
			return 3553;
		}
		
		if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
		{
			return 3553;
		}
		
		if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
		{
			return 34067;
		}
		
		return 3553;
	}
	
	
	public static   int FormatToChannelBits(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 0:
			{
				return 6406;
			}
			
			
			case 2:
			{
				return 6407;
			}
			
			
			case 3:
			{
				return 6408;
			}
			
			
			case 7:case 4:
			{
				return 6409;
			}
			
			
			case 8:case 5:
			{
				return 6407;
			}
			
			
			case 9:case 6:
			{
				return 6408;
			}
			
			
			case 1:
			{
				return 6409;
			}
			
			
			case 10:
			{
				return 6402;
			}
			
			
		}
		
		return 6408;
	}
	
	
	public static   int FormatToChannelType(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 4:case 5:case 6:
			{
				return haxor.graphics.GL.HALF_FLOAT;
			}
			
			
			case 7:case 8:case 9:
			{
				return 5126;
			}
			
			
			case 10:
			{
				return 5123;
			}
			
			
			case 3:case 2:case 1:case 0:
			{
				return 5121;
			}
			
			
		}
		
		return 5121;
	}
	
	
	public static   int FormatToChannelLayout(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 0:
			{
				return 6406;
			}
			
			
			case 2:
			{
				return 6407;
			}
			
			
			case 3:
			{
				return 6408;
			}
			
			
			case 1:case 4:case 7:
			{
				return 6409;
			}
			
			
			case 8:case 5:
			{
				return 6407;
			}
			
			
			case 9:case 6:
			{
				return 6408;
			}
			
			
			case 10:
			{
				return 6402;
			}
			
			
		}
		
		return 6408;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.TextureContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.TextureContext();
	}
	
	
	public  int tid;
	
	public  haxe.root.Array<java.lang.Object> ids;
	
	public  haxe.root.Array<java.lang.Object> framebuffers;
	
	public  haxe.root.Array<java.lang.Object> renderbuffers;
	
	public  haxor.graphics.texture.RenderTexture target;
	
	public  haxe.root.Array<haxor.graphics.texture.Texture> active;
	
	public  haxor.graphics.texture.Texture bind;
	
	public   void Initialize()
	{
		{
			int _g1 = 0;
			int _g = haxor.graphics.GL.MAX_ACTIVE_TEXTURE;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.active.push(null);
			}
			
		}
		
		{
			int _g2 = 0;
			while (( _g2 < 2048 ))
			{
				int i1 = _g2++;
				this.ids.push(haxor.graphics.GL.INVALID);
				this.framebuffers.push(haxor.graphics.GL.INVALID);
				this.renderbuffers.push(haxor.graphics.GL.INVALID);
			}
			
		}
		
	}
	
	
	public   void Alloc(haxor.graphics.texture.Texture p_texture)
	{
		int w = p_texture.m_width;
		int h = p_texture.m_height;
		int chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		int chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		int chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		int tex_type = 0;
		if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
		{
			tex_type = 3553;
		}
		 else 
		{
			if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
			{
				tex_type = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
				{
					tex_type = 34067;
				}
				 else 
				{
					tex_type = 3553;
				}
				
			}
			
		}
		
		if (( p_texture == this.bind )) 
		{
			java.lang.Object __temp_expr56386 = null;
		}
		 else 
		{
			this.bind = p_texture;
			int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
			int target = 0;
			{
				haxor.graphics.texture.Texture p_texture1 = this.bind;
				if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
					{
						target = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
						{
							target = 34067;
						}
						 else 
						{
							target = 3553;
						}
						
					}
					
				}
				
			}
			
			haxor.graphics.GL.m_gl.BindTexture(target, id);
		}
		
		haxor.graphics.GL.m_gl.TexImage2DAlloc(tex_type, 0, chn_fmt, w, h, 0, chn_bit, chn_type);
	}
	
	
	public   void Create(haxor.graphics.texture.Texture p_texture)
	{
		p_texture.__slot = ( p_texture.__cid % haxor.graphics.GL.MAX_ACTIVE_TEXTURE );
		int id = haxor.graphics.GL.m_gl.CreateTexture();
		this.ids.__set(p_texture.__cid, id);
		{
			int target = 0;
			if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
			if (( p_texture == this.bind )) 
			{
				java.lang.Object __temp_expr56387 = null;
			}
			 else 
			{
				this.bind = p_texture;
				int id1 = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
				int target1 = 0;
				{
					haxor.graphics.texture.Texture p_texture1 = this.bind;
					if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
					{
						target1 = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
						{
							target1 = 3553;
						}
						 else 
						{
							if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
							{
								target1 = 34067;
							}
							 else 
							{
								target1 = 3553;
							}
							
						}
						
					}
					
				}
				
				haxor.graphics.GL.m_gl.BindTexture(target1, id1);
			}
			
			haxor.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( p_texture.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
			haxor.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( p_texture.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
			if (haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
			{
				double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (p_texture.m_aniso) ))) );
				haxor.graphics.GL.m_gl.TexParameterf(target, haxor.graphics.GL.TEXTURE_ANISOTROPY, p_value);
			}
			
			haxor.graphics.TextureFilter minf = p_texture.m_minFilter;
			haxor.graphics.TextureFilter magf = p_texture.m_magFilter;
			if (( p_texture.m_format == haxor.graphics.PixelFormat.Half )) 
			{
				if ( ! (haxor.graphics.GL.TEXTURE_HALF_LINEAR) ) 
				{
					minf = haxor.graphics.TextureFilter.Nearest;
					magf = haxor.graphics.TextureFilter.Nearest;
				}
				
			}
			
			switch (haxe.root.Type.enumIndex(minf))
			{
				case 0:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
					break;
				}
				
				
				case 2:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
					break;
				}
				
				
				case 1:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 6:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 4:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
					break;
				}
				
				
			}
			
			switch (haxe.root.Type.enumIndex(magf))
			{
				case 0:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 2:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 1:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 6:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 4:
				{
					haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
			}
			
		}
		
		if (( p_texture.get_type() != haxor.graphics.TextureType.TextureCube )) 
		{
			this.Alloc(p_texture);
		}
		
		if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
		{
			haxor.graphics.texture.RenderTexture rt = ((haxor.graphics.texture.RenderTexture) (p_texture) );
			int fb_id = haxor.graphics.GL.m_gl.CreateFramebuffer();
			this.framebuffers.__set(p_texture.__cid, fb_id);
			haxor.graphics.GL.m_gl.BindFramebuffer(36160, fb_id);
			haxor.graphics.GL.m_gl.FramebufferTexture2D(36160, 36064, 3553, id, 0);
			if (( rt.m_depth != null )) 
			{
				int depth_id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(rt.m_depth.__cid))) );
				haxor.graphics.GL.m_gl.FramebufferTexture2D(36160, 36096, 3553, depth_id, 0);
			}
			 else 
			{
				int rb_id = haxor.graphics.GL.m_gl.CreateRenderbuffer();
				this.renderbuffers.__set(p_texture.__cid, rb_id);
				haxor.graphics.GL.m_gl.BindRenderbuffer(36161, rb_id);
				haxor.graphics.GL.m_gl.RenderbufferStorage(36161, 33189, rt.m_width, rt.m_height);
				haxor.graphics.GL.m_gl.FramebufferRenderbuffer(36160, 36096, 36161, rb_id);
			}
			
			haxor.graphics.GL.m_gl.BindFramebuffer(36160, haxor.graphics.GL.NULL);
			haxor.graphics.GL.m_gl.BindRenderbuffer(36161, haxor.graphics.GL.NULL);
			if (( this.bind == null )) 
			{
				java.lang.Object __temp_expr56388 = null;
			}
			 else 
			{
				int target2 = 0;
				{
					haxor.graphics.texture.Texture p_texture2 = this.bind;
					if (( p_texture2.get_type() == haxor.graphics.TextureType.Texture2D )) 
					{
						target2 = 3553;
					}
					 else 
					{
						if (( p_texture2.get_type() == haxor.graphics.TextureType.RenderTexture )) 
						{
							target2 = 3553;
						}
						 else 
						{
							if (( p_texture2.get_type() == haxor.graphics.TextureType.TextureCube )) 
							{
								target2 = 34067;
							}
							 else 
							{
								target2 = 3553;
							}
							
						}
						
					}
					
				}
				
				this.bind = null;
				haxor.graphics.GL.m_gl.BindTexture(target2, haxor.graphics.GL.NULL);
			}
			
		}
		
	}
	
	
	public final   void Bind(haxor.graphics.texture.Texture p_texture)
	{
		if (( p_texture == this.bind )) 
		{
			return ;
		}
		
		this.bind = p_texture;
		int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
		int target = 0;
		{
			haxor.graphics.texture.Texture p_texture1 = this.bind;
			if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
		}
		
		haxor.graphics.GL.m_gl.BindTexture(target, id);
	}
	
	
	public final   void Unbind()
	{
		if (( this.bind == null )) 
		{
			return ;
		}
		
		int target = 0;
		{
			haxor.graphics.texture.Texture p_texture = this.bind;
			if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
		}
		
		this.bind = null;
		haxor.graphics.GL.m_gl.BindTexture(target, haxor.graphics.GL.NULL);
	}
	
	
	public final   void UpdateParameters(haxor.graphics.texture.Texture p_texture)
	{
		int target = 0;
		if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
		{
			target = 3553;
		}
		 else 
		{
			if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
				{
					target = 34067;
				}
				 else 
				{
					target = 3553;
				}
				
			}
			
		}
		
		if (( p_texture == this.bind )) 
		{
			java.lang.Object __temp_expr56389 = null;
		}
		 else 
		{
			this.bind = p_texture;
			int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
			int target1 = 0;
			{
				haxor.graphics.texture.Texture p_texture1 = this.bind;
				if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
				{
					target1 = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
					{
						target1 = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
						{
							target1 = 34067;
						}
						 else 
						{
							target1 = 3553;
						}
						
					}
					
				}
				
			}
			
			haxor.graphics.GL.m_gl.BindTexture(target1, id);
		}
		
		haxor.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( p_texture.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
		haxor.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( p_texture.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
		if (haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
		{
			double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (p_texture.m_aniso) ))) );
			haxor.graphics.GL.m_gl.TexParameterf(target, haxor.graphics.GL.TEXTURE_ANISOTROPY, p_value);
		}
		
		haxor.graphics.TextureFilter minf = p_texture.m_minFilter;
		haxor.graphics.TextureFilter magf = p_texture.m_magFilter;
		if (( p_texture.m_format == haxor.graphics.PixelFormat.Half )) 
		{
			if ( ! (haxor.graphics.GL.TEXTURE_HALF_LINEAR) ) 
			{
				minf = haxor.graphics.TextureFilter.Nearest;
				magf = haxor.graphics.TextureFilter.Nearest;
			}
			
		}
		
		switch (haxe.root.Type.enumIndex(minf))
		{
			case 0:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
				break;
			}
			
			
			case 3:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
				break;
			}
			
			
			case 2:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
				break;
			}
			
			
			case 1:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
				break;
			}
			
			
			case 5:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
				break;
			}
			
			
			case 6:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
				break;
			}
			
			
			case 4:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
				break;
			}
			
			
		}
		
		switch (haxe.root.Type.enumIndex(magf))
		{
			case 0:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
				break;
			}
			
			
			case 3:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
				break;
			}
			
			
			case 2:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
				break;
			}
			
			
			case 1:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
				break;
			}
			
			
			case 5:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
				break;
			}
			
			
			case 6:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
				break;
			}
			
			
			case 4:
			{
				haxor.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
				break;
			}
			
			
		}
		
	}
	
	
	public   void Update(haxor.graphics.texture.Texture p_texture)
	{
		int target = 0;
		if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
		{
			target = 3553;
		}
		 else 
		{
			if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
				{
					target = 34067;
				}
				 else 
				{
					target = 3553;
				}
				
			}
			
		}
		
		if (( p_texture == this.bind )) 
		{
			java.lang.Object __temp_expr56390 = null;
		}
		 else 
		{
			this.bind = p_texture;
			int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
			int target1 = 0;
			{
				haxor.graphics.texture.Texture p_texture1 = this.bind;
				if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
				{
					target1 = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
					{
						target1 = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
						{
							target1 = 34067;
						}
						 else 
						{
							target1 = 3553;
						}
						
					}
					
				}
				
			}
			
			haxor.graphics.GL.m_gl.BindTexture(target1, id);
		}
		
		if (( target == 34067 )) 
		{
			haxor.graphics.texture.TextureCube tc = ((haxor.graphics.texture.TextureCube) (p_texture) );
			if (( tc.m_faces.__get(0) != null )) 
			{
				this.WriteTexture(34069, tc.m_faces.__get(0));
			}
			
			if (( tc.m_faces.__get(1) != null )) 
			{
				this.WriteTexture(34070, tc.m_faces.__get(1));
			}
			
			if (( tc.m_faces.__get(2) != null )) 
			{
				this.WriteTexture(34071, tc.m_faces.__get(2));
			}
			
			if (( tc.m_faces.__get(3) != null )) 
			{
				this.WriteTexture(34072, tc.m_faces.__get(3));
			}
			
			if (( tc.m_faces.__get(4) != null )) 
			{
				this.WriteTexture(34073, tc.m_faces.__get(4));
			}
			
			if (( tc.m_faces.__get(5) != null )) 
			{
				this.WriteTexture(34074, tc.m_faces.__get(5));
			}
			
		}
		 else 
		{
			this.WriteTexture(target, p_texture);
		}
		
	}
	
	
	public   void UploadTexture(haxor.graphics.texture.Texture2D p_texture, int p_steps, haxe.lang.Function p_on_complete)
	{
		haxe.root.Array<haxe.lang.Function> p_on_complete1 = new haxe.root.Array<haxe.lang.Function>(new haxe.lang.Function[]{p_on_complete});
		haxe.root.Array<haxor.graphics.texture.Texture2D> p_texture1 = new haxe.root.Array<haxor.graphics.texture.Texture2D>(new haxor.graphics.texture.Texture2D[]{p_texture});
		haxe.root.Array<haxor.context.TextureContext> _g = new haxe.root.Array<haxor.context.TextureContext>(new haxor.context.TextureContext[]{this});
		haxe.root.Array<haxor.graphics.texture.Bitmap> b = new haxe.root.Array<haxor.graphics.texture.Bitmap>(new haxor.graphics.texture.Bitmap[]{p_texture1.__get(0).m_data});
		haxe.root.Array<java.lang.Object> py = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{-180});
		haxe.root.Array<java.lang.Object> chn_fmt = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{haxor.context.TextureContext.FormatToChannelLayout(p_texture1.__get(0).m_format)});
		int chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture1.__get(0).m_format);
		haxe.root.Array<java.lang.Object> chn_type = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{haxor.context.TextureContext.FormatToChannelType(p_texture1.__get(0).m_format)});
		haxe.root.Array<java.lang.Object> steps = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{( p_texture1.__get(0).m_height / p_steps )});
		if (( ((int) (haxe.lang.Runtime.toInt(steps.__get(0))) ) <= 1 )) 
		{
			steps.__set(0, 1);
		}
		
		haxor.thread.Activity ua = new haxor.thread.Activity(((haxe.lang.Function) (new haxor.context.TextureContext_UploadTexture_276__Fun(((haxe.root.Array<java.lang.Object>) (steps) ), ((haxe.root.Array<java.lang.Object>) (chn_type) ), ((haxe.root.Array<java.lang.Object>) (chn_fmt) ), ((haxe.root.Array<haxor.graphics.texture.Texture2D>) (p_texture1) ), ((haxe.root.Array<haxe.lang.Function>) (p_on_complete1) ), ((haxe.root.Array<java.lang.Object>) (py) ), ((haxe.root.Array<haxor.context.TextureContext>) (_g) ), ((haxe.root.Array<haxor.graphics.texture.Bitmap>) (b) ))) ), ((java.lang.Object) (false) ), ((java.lang.Object) (true) ));
	}
	
	
	public   void WriteTexture(int p_target, haxor.graphics.texture.Texture p_texture)
	{
		int w = p_texture.m_width;
		int h = p_texture.m_height;
		int chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		int chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		int chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		if (( p_texture.m_format == haxor.graphics.PixelFormat.Depth )) 
		{
			haxor.graphics.GL.m_gl.TexImage2DAlloc(p_target, 0, chn_fmt, w, h, 0, chn_fmt, chn_type);
		}
		 else 
		{
			if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				haxor.graphics.texture.Texture2D t2d = ((haxor.graphics.texture.Texture2D) (p_texture) );
				{
					haxor.io.Buffer p_data = t2d.m_data.get_buffer();
					haxor.graphics.GL.m_gl.TexImage2D(p_target, 0, chn_fmt, w, h, 0, chn_bit, chn_type, p_data);
				}
				
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					haxor.graphics.texture.RenderTexture rt = ((haxor.graphics.texture.RenderTexture) (p_texture) );
					int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(rt.__cid))) );
					haxor.graphics.GL.m_gl.FramebufferTexture2D(36160, 36064, p_target, id, 0);
				}
				
			}
			
		}
		
	}
	
	
	public   int Activate(haxor.graphics.texture.Texture p_texture)
	{
		int slot = p_texture.__slot;
		if (( this.active.__get(p_texture.__cid) == p_texture )) 
		{
			return slot;
		}
		
		this.active.__set(p_texture.__cid, p_texture);
		haxor.graphics.GL.m_gl.ActiveTexture(( 33984 + slot ));
		if (( p_texture == this.bind )) 
		{
			java.lang.Object __temp_expr56391 = null;
		}
		 else 
		{
			this.bind = p_texture;
			int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
			int target = 0;
			{
				haxor.graphics.texture.Texture p_texture1 = this.bind;
				if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
					{
						target = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
						{
							target = 34067;
						}
						 else 
						{
							target = 3553;
						}
						
					}
					
				}
				
			}
			
			haxor.graphics.GL.m_gl.BindTexture(target, id);
		}
		
		return slot;
	}
	
	
	public   void BindTarget(haxor.graphics.texture.RenderTexture rt)
	{
		if (( rt == null )) 
		{
			if (( this.target != rt )) 
			{
				haxor.graphics.GL.m_gl.BindFramebuffer(36160, haxor.graphics.GL.NULL);
				haxor.graphics.GL.m_gl.BindRenderbuffer(36161, haxor.graphics.GL.NULL);
				this.target = null;
			}
			
		}
		 else 
		{
			if (( this.target != rt )) 
			{
				int fb_id = ((int) (haxe.lang.Runtime.toInt(this.framebuffers.__get(rt.__cid))) );
				haxor.graphics.GL.m_gl.BindFramebuffer(36160, fb_id);
				if (( rt.m_depth == null )) 
				{
					int rb_id = ((int) (haxe.lang.Runtime.toInt(this.renderbuffers.__get(rt.__cid))) );
					haxor.graphics.GL.m_gl.BindRenderbuffer(36161, rb_id);
				}
				
				this.target = rt;
			}
			
		}
		
	}
	
	
	public   void UpdateMipmaps(haxor.graphics.texture.Texture p_texture)
	{
		if (( p_texture == this.bind )) 
		{
			java.lang.Object __temp_expr56392 = null;
		}
		 else 
		{
			this.bind = p_texture;
			int id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(this.bind.__cid))) );
			int target = 0;
			{
				haxor.graphics.texture.Texture p_texture1 = this.bind;
				if (( p_texture1.get_type() == haxor.graphics.TextureType.Texture2D )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( p_texture1.get_type() == haxor.graphics.TextureType.RenderTexture )) 
					{
						target = 3553;
					}
					 else 
					{
						if (( p_texture1.get_type() == haxor.graphics.TextureType.TextureCube )) 
						{
							target = 34067;
						}
						 else 
						{
							target = 3553;
						}
						
					}
					
				}
				
			}
			
			haxor.graphics.GL.m_gl.BindTexture(target, id);
		}
		
		int target1 = 0;
		if (( p_texture.get_type() == haxor.graphics.TextureType.Texture2D )) 
		{
			target1 = 3553;
		}
		 else 
		{
			if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
			{
				target1 = 3553;
			}
			 else 
			{
				if (( p_texture.get_type() == haxor.graphics.TextureType.TextureCube )) 
				{
					target1 = 34067;
				}
				 else 
				{
					target1 = 3553;
				}
				
			}
			
		}
		
		haxor.graphics.GL.m_gl.GenerateMipmap(target1);
	}
	
	
	public   void Destroy(haxor.graphics.texture.Texture p_texture)
	{
		int tex_id = ((int) (haxe.lang.Runtime.toInt(this.ids.__get(p_texture.__cid))) );
		if (( tex_id != haxor.graphics.GL.INVALID )) 
		{
			haxor.graphics.GL.m_gl.DeleteTexture(tex_id);
		}
		
		if (( p_texture.get_type() == haxor.graphics.TextureType.RenderTexture )) 
		{
			int fb_id = ((int) (haxe.lang.Runtime.toInt(this.framebuffers.__get(p_texture.__cid))) );
			int rb_id = ((int) (haxe.lang.Runtime.toInt(this.renderbuffers.__get(p_texture.__cid))) );
			if (( fb_id != haxor.graphics.GL.INVALID )) 
			{
				haxor.graphics.GL.m_gl.DeleteFramebuffer(fb_id);
			}
			
			if (( rb_id != haxor.graphics.GL.INVALID )) 
			{
				haxor.graphics.GL.m_gl.DeleteRenderbuffer(rb_id);
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56393 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef56393 = false;
						this.tid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56393) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56394 = true;
			switch (field.hashCode())
			{
				case 3023933:
				{
					if (field.equals("bind")) 
					{
						__temp_executeDef56394 = false;
						this.bind = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef56394 = false;
						this.tid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1422950650:
				{
					if (field.equals("active")) 
					{
						__temp_executeDef56394 = false;
						this.active = ((haxe.root.Array<haxor.graphics.texture.Texture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 104120:
				{
					if (field.equals("ids")) 
					{
						__temp_executeDef56394 = false;
						this.ids = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef56394 = false;
						this.target = ((haxor.graphics.texture.RenderTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 419710502:
				{
					if (field.equals("framebuffers")) 
					{
						__temp_executeDef56394 = false;
						this.framebuffers = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1967185373:
				{
					if (field.equals("renderbuffers")) 
					{
						__temp_executeDef56394 = false;
						this.renderbuffers = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56394) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56395 = true;
			switch (field.hashCode())
			{
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef56395 = false;
						return this.tid;
					}
					
					break;
				}
				
				
				case 369503682:
				{
					if (field.equals("UpdateMipmaps")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateMipmaps"))) );
					}
					
					break;
				}
				
				
				case 104120:
				{
					if (field.equals("ids")) 
					{
						__temp_executeDef56395 = false;
						return this.ids;
					}
					
					break;
				}
				
				
				case -1399554994:
				{
					if (field.equals("BindTarget")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindTarget"))) );
					}
					
					break;
				}
				
				
				case 419710502:
				{
					if (field.equals("framebuffers")) 
					{
						__temp_executeDef56395 = false;
						return this.framebuffers;
					}
					
					break;
				}
				
				
				case -1591330541:
				{
					if (field.equals("Activate")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Activate"))) );
					}
					
					break;
				}
				
				
				case 1967185373:
				{
					if (field.equals("renderbuffers")) 
					{
						__temp_executeDef56395 = false;
						return this.renderbuffers;
					}
					
					break;
				}
				
				
				case 1457889372:
				{
					if (field.equals("WriteTexture")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("WriteTexture"))) );
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef56395 = false;
						return this.target;
					}
					
					break;
				}
				
				
				case 472316858:
				{
					if (field.equals("UploadTexture")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UploadTexture"))) );
					}
					
					break;
				}
				
				
				case -1422950650:
				{
					if (field.equals("active")) 
					{
						__temp_executeDef56395 = false;
						return this.active;
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case 3023933:
				{
					if (field.equals("bind")) 
					{
						__temp_executeDef56395 = false;
						return this.bind;
					}
					
					break;
				}
				
				
				case -1667730509:
				{
					if (field.equals("UpdateParameters")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateParameters"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 63353621:
				{
					if (field.equals("Alloc")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Alloc"))) );
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef56395 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56395) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56396 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef56396 = false;
						return ((double) (this.tid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56396) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef56397 = true;
			switch (field.hashCode())
			{
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef56397 = false;
						this.Destroy(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef56397 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case 369503682:
				{
					if (field.equals("UpdateMipmaps")) 
					{
						__temp_executeDef56397 = false;
						this.UpdateMipmaps(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 63353621:
				{
					if (field.equals("Alloc")) 
					{
						__temp_executeDef56397 = false;
						this.Alloc(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1399554994:
				{
					if (field.equals("BindTarget")) 
					{
						__temp_executeDef56397 = false;
						this.BindTarget(((haxor.graphics.texture.RenderTexture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef56397 = false;
						this.Create(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1591330541:
				{
					if (field.equals("Activate")) 
					{
						__temp_executeDef56397 = false;
						return this.Activate(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef56397 = false;
						this.Bind(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1457889372:
				{
					if (field.equals("WriteTexture")) 
					{
						__temp_executeDef56397 = false;
						this.WriteTexture(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.graphics.texture.Texture) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef56397 = false;
						this.Unbind();
					}
					
					break;
				}
				
				
				case 472316858:
				{
					if (field.equals("UploadTexture")) 
					{
						__temp_executeDef56397 = false;
						this.UploadTexture(((haxor.graphics.texture.Texture2D) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.lang.Function) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -1667730509:
				{
					if (field.equals("UpdateParameters")) 
					{
						__temp_executeDef56397 = false;
						this.UpdateParameters(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef56397 = false;
						this.Update(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56397) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("bind");
		baseArr.push("active");
		baseArr.push("target");
		baseArr.push("renderbuffers");
		baseArr.push("framebuffers");
		baseArr.push("ids");
		baseArr.push("tid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


