package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Texture extends haxor.core.Resource
{
	public    Texture(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Texture()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.texture.Texture.__hx_ctor_haxor_graphics_texture_Texture(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_Texture(haxor.graphics.texture.Texture __temp_me54101)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me54101, null);
		__temp_me54101.m_mipmaps = false;
		__temp_me54101.m_format = haxor.graphics.PixelFormat.RGBA8;
		__temp_me54101.m_minFilter = haxor.graphics.TextureFilter.Linear;
		__temp_me54101.m_magFilter = haxor.graphics.TextureFilter.Linear;
		__temp_me54101.m_wrap = ( ( haxor.graphics.TextureWrap.ClampX | haxor.graphics.TextureWrap.ClampY ) | haxor.graphics.TextureWrap.ClampZ );
		__temp_me54101.m_width = 0;
		__temp_me54101.m_height = 0;
		__temp_me54101.m_aniso = 0;
		__temp_me54101._cid_ = haxor.context.EngineContext.texture.tid++;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.Texture(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.Texture();
	}
	
	
	
	
	public final   int get_width()
	{
		return this.m_width;
	}
	
	
	public  int m_width;
	
	
	
	public final   int get_height()
	{
		return this.m_height;
	}
	
	
	public  int m_height;
	
	
	
	public final   haxor.graphics.PixelFormat get_format()
	{
		return this.m_format;
	}
	
	
	public  haxor.graphics.PixelFormat m_format;
	
	
	
	public final   int get_wrap()
	{
		return this.m_wrap;
	}
	
	
	public   int set_wrap(int v)
	{
		if (( this.m_wrap == v )) 
		{
			return v;
		}
		
		this.m_wrap = v;
		{
			haxor.context.TextureContext _this = haxor.context.EngineContext.texture;
			int target = 0;
			if (( this.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( this.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( this.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
			if (( this == _this.bind )) 
			{
				java.lang.Object __temp_expr54345 = null;
			}
			 else 
			{
				_this.bind = this;
				int id = ((int) (haxe.lang.Runtime.toInt(_this.ids.__get(_this.bind._cid_))) );
				int target1 = 0;
				{
					haxor.graphics.texture.Texture p_texture = _this.bind;
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
					
				}
				
				haxor.platform.graphics.GL.m_gl.BindTexture(target1, id);
			}
			
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
			if (haxor.platform.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
			{
				double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (this.m_aniso) ))) );
				haxor.platform.graphics.GL.m_gl.TexParameterf(target, haxor.platform.graphics.GL.TEXTURE_ANISOTROPY, p_value);
			}
			
			haxor.graphics.TextureFilter minf = this.m_minFilter;
			haxor.graphics.TextureFilter magf = this.m_magFilter;
			if (( this.m_format == haxor.graphics.PixelFormat.Half )) 
			{
				if ( ! (haxor.platform.graphics.GL.TEXTURE_HALF_LINEAR) ) 
				{
					minf = haxor.graphics.TextureFilter.Nearest;
					magf = haxor.graphics.TextureFilter.Nearest;
				}
				
			}
			
			switch (haxe.root.Type.enumIndex(minf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
					break;
				}
				
				
			}
			
			switch (haxe.root.Type.enumIndex(magf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
			}
			
		}
		
		return v;
	}
	
	
	public  int m_wrap;
	
	
	
	public final   int get_aniso()
	{
		return this.m_aniso;
	}
	
	
	public   int set_aniso(int v)
	{
		if (( this.m_aniso == v )) 
		{
			return v;
		}
		
		this.m_aniso = v;
		{
			haxor.context.TextureContext _this = haxor.context.EngineContext.texture;
			int target = 0;
			if (( this.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( this.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( this.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
			if (( this == _this.bind )) 
			{
				java.lang.Object __temp_expr54346 = null;
			}
			 else 
			{
				_this.bind = this;
				int id = ((int) (haxe.lang.Runtime.toInt(_this.ids.__get(_this.bind._cid_))) );
				int target1 = 0;
				{
					haxor.graphics.texture.Texture p_texture = _this.bind;
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
					
				}
				
				haxor.platform.graphics.GL.m_gl.BindTexture(target1, id);
			}
			
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
			if (haxor.platform.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
			{
				double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (this.m_aniso) ))) );
				haxor.platform.graphics.GL.m_gl.TexParameterf(target, haxor.platform.graphics.GL.TEXTURE_ANISOTROPY, p_value);
			}
			
			haxor.graphics.TextureFilter minf = this.m_minFilter;
			haxor.graphics.TextureFilter magf = this.m_magFilter;
			if (( this.m_format == haxor.graphics.PixelFormat.Half )) 
			{
				if ( ! (haxor.platform.graphics.GL.TEXTURE_HALF_LINEAR) ) 
				{
					minf = haxor.graphics.TextureFilter.Nearest;
					magf = haxor.graphics.TextureFilter.Nearest;
				}
				
			}
			
			switch (haxe.root.Type.enumIndex(minf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
					break;
				}
				
				
			}
			
			switch (haxe.root.Type.enumIndex(magf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
			}
			
		}
		
		return v;
	}
	
	
	public  int m_aniso;
	
	
	
	public final   haxor.graphics.TextureFilter get_minFilter()
	{
		return this.m_minFilter;
	}
	
	
	public   haxor.graphics.TextureFilter set_minFilter(haxor.graphics.TextureFilter v)
	{
		if (( this.m_minFilter == v )) 
		{
			return v;
		}
		
		this.m_minFilter = v;
		{
			haxor.context.TextureContext _this = haxor.context.EngineContext.texture;
			int target = 0;
			if (( this.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( this.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( this.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
			if (( this == _this.bind )) 
			{
				java.lang.Object __temp_expr54347 = null;
			}
			 else 
			{
				_this.bind = this;
				int id = ((int) (haxe.lang.Runtime.toInt(_this.ids.__get(_this.bind._cid_))) );
				int target1 = 0;
				{
					haxor.graphics.texture.Texture p_texture = _this.bind;
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
					
				}
				
				haxor.platform.graphics.GL.m_gl.BindTexture(target1, id);
			}
			
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
			if (haxor.platform.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
			{
				double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (this.m_aniso) ))) );
				haxor.platform.graphics.GL.m_gl.TexParameterf(target, haxor.platform.graphics.GL.TEXTURE_ANISOTROPY, p_value);
			}
			
			haxor.graphics.TextureFilter minf = this.m_minFilter;
			haxor.graphics.TextureFilter magf = this.m_magFilter;
			if (( this.m_format == haxor.graphics.PixelFormat.Half )) 
			{
				if ( ! (haxor.platform.graphics.GL.TEXTURE_HALF_LINEAR) ) 
				{
					minf = haxor.graphics.TextureFilter.Nearest;
					magf = haxor.graphics.TextureFilter.Nearest;
				}
				
			}
			
			switch (haxe.root.Type.enumIndex(minf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
					break;
				}
				
				
			}
			
			switch (haxe.root.Type.enumIndex(magf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
			}
			
		}
		
		return v;
	}
	
	
	public  haxor.graphics.TextureFilter m_minFilter;
	
	
	
	public final   haxor.graphics.TextureFilter get_magFilter()
	{
		return this.m_magFilter;
	}
	
	
	public   haxor.graphics.TextureFilter set_magFilter(haxor.graphics.TextureFilter v)
	{
		if (( this.m_magFilter == v )) 
		{
			return v;
		}
		
		this.m_magFilter = v;
		{
			haxor.context.TextureContext _this = haxor.context.EngineContext.texture;
			int target = 0;
			if (( this.get_type() == haxor.graphics.TextureType.Texture2D )) 
			{
				target = 3553;
			}
			 else 
			{
				if (( this.get_type() == haxor.graphics.TextureType.RenderTexture )) 
				{
					target = 3553;
				}
				 else 
				{
					if (( this.get_type() == haxor.graphics.TextureType.TextureCube )) 
					{
						target = 34067;
					}
					 else 
					{
						target = 3553;
					}
					
				}
				
			}
			
			if (( this == _this.bind )) 
			{
				java.lang.Object __temp_expr54348 = null;
			}
			 else 
			{
				_this.bind = this;
				int id = ((int) (haxe.lang.Runtime.toInt(_this.ids.__get(_this.bind._cid_))) );
				int target1 = 0;
				{
					haxor.graphics.texture.Texture p_texture = _this.bind;
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
					
				}
				
				haxor.platform.graphics.GL.m_gl.BindTexture(target1, id);
			}
			
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10242, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampX )) != 0 )) ? (33071) : (10497) ));
			haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10243, ( (( (( this.m_wrap & haxor.graphics.TextureWrap.ClampY )) != 0 )) ? (33071) : (10497) ));
			if (haxor.platform.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) 
			{
				double p_value = ((double) (java.lang.Math.max(((double) (1) ), ((double) (this.m_aniso) ))) );
				haxor.platform.graphics.GL.m_gl.TexParameterf(target, haxor.platform.graphics.GL.TEXTURE_ANISOTROPY, p_value);
			}
			
			haxor.graphics.TextureFilter minf = this.m_minFilter;
			haxor.graphics.TextureFilter magf = this.m_magFilter;
			if (( this.m_format == haxor.graphics.PixelFormat.Half )) 
			{
				if ( ! (haxor.platform.graphics.GL.TEXTURE_HALF_LINEAR) ) 
				{
					minf = haxor.graphics.TextureFilter.Nearest;
					magf = haxor.graphics.TextureFilter.Nearest;
				}
				
			}
			
			switch (haxe.root.Type.enumIndex(minf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9986);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9984);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9987);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10241, 9985);
					break;
				}
				
				
			}
			
			switch (haxe.root.Type.enumIndex(magf))
			{
				case 0:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 3:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 2:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9728);
					break;
				}
				
				
				case 1:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 5:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 6:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
				case 4:
				{
					haxor.platform.graphics.GL.m_gl.TexParameteri(target, 10240, 9729);
					break;
				}
				
				
			}
			
		}
		
		return v;
	}
	
	
	public  haxor.graphics.TextureFilter m_magFilter;
	
	public  boolean mipmaps;
	
	public final   boolean get_mipmaps()
	{
		return this.m_mipmaps;
	}
	
	
	public  boolean m_mipmaps;
	
	public  haxor.graphics.TextureType type;
	
	public   haxor.graphics.TextureType get_type()
	{
		return haxor.graphics.TextureType.None;
	}
	
	
	public  int __slot;
	
	public   void Apply()
	{
		haxor.context.EngineContext.texture.Update(this);
	}
	
	
	public   void GenerateMipmaps()
	{
		if (this.m_mipmaps) 
		{
			return ;
		}
		
		this.m_mipmaps = true;
		haxor.context.EngineContext.texture.UpdateMipmaps(this);
	}
	
	
	@Override public   void OnDestroy()
	{
		super.OnDestroy();
		haxor.context.EngineContext.texture.Destroy(this);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef54349 = true;
			switch (field.hashCode())
			{
				case -1483930146:
				{
					if (field.equals("__slot")) 
					{
						__temp_executeDef54349 = false;
						this.__slot = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef54349 = false;
						this.m_width = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 766385894:
				{
					if (field.equals("m_aniso")) 
					{
						__temp_executeDef54349 = false;
						this.m_aniso = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef54349 = false;
						this.m_height = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 92963128:
				{
					if (field.equals("aniso")) 
					{
						__temp_executeDef54349 = false;
						this.set_aniso(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef54349 = false;
						this.set_wrap(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1082997540:
				{
					if (field.equals("m_wrap")) 
					{
						__temp_executeDef54349 = false;
						this.m_wrap = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54349) 
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
			boolean __temp_executeDef54350 = true;
			switch (field.hashCode())
			{
				case -1483930146:
				{
					if (field.equals("__slot")) 
					{
						__temp_executeDef54350 = false;
						this.__slot = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef54350 = false;
						this.m_width = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef54350 = false;
						this.type = ((haxor.graphics.TextureType) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef54350 = false;
						this.m_height = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -314290919:
				{
					if (field.equals("m_mipmaps")) 
					{
						__temp_executeDef54350 = false;
						this.m_mipmaps = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1867509751:
				{
					if (field.equals("m_format")) 
					{
						__temp_executeDef54350 = false;
						this.m_format = ((haxor.graphics.PixelFormat) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1066492651:
				{
					if (field.equals("mipmaps")) 
					{
						__temp_executeDef54350 = false;
						this.mipmaps = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef54350 = false;
						this.set_wrap(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 1344661849:
				{
					if (field.equals("m_magFilter")) 
					{
						__temp_executeDef54350 = false;
						this.m_magFilter = ((haxor.graphics.TextureFilter) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1082997540:
				{
					if (field.equals("m_wrap")) 
					{
						__temp_executeDef54350 = false;
						this.m_wrap = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1132778155:
				{
					if (field.equals("magFilter")) 
					{
						__temp_executeDef54350 = false;
						this.set_magFilter(((haxor.graphics.TextureFilter) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 92963128:
				{
					if (field.equals("aniso")) 
					{
						__temp_executeDef54350 = false;
						this.set_aniso(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 24833816:
				{
					if (field.equals("m_minFilter")) 
					{
						__temp_executeDef54350 = false;
						this.m_minFilter = ((haxor.graphics.TextureFilter) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 766385894:
				{
					if (field.equals("m_aniso")) 
					{
						__temp_executeDef54350 = false;
						this.m_aniso = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -187049878:
				{
					if (field.equals("minFilter")) 
					{
						__temp_executeDef54350 = false;
						this.set_minFilter(((haxor.graphics.TextureFilter) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54350) 
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
			boolean __temp_executeDef54351 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef54351 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 957120406:
				{
					if (field.equals("GenerateMipmaps")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateMipmaps"))) );
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_width"))) );
					}
					
					break;
				}
				
				
				case 63476558:
				{
					if (field.equals("Apply")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Apply"))) );
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef54351 = false;
						return this.m_width;
					}
					
					break;
				}
				
				
				case -1483930146:
				{
					if (field.equals("__slot")) 
					{
						__temp_executeDef54351 = false;
						return this.__slot;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef54351 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_height"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef54351 = false;
						if (handleProperties) 
						{
							return this.get_type();
						}
						 else 
						{
							return this.type;
						}
						
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef54351 = false;
						return this.m_height;
					}
					
					break;
				}
				
				
				case -314290919:
				{
					if (field.equals("m_mipmaps")) 
					{
						__temp_executeDef54351 = false;
						return this.m_mipmaps;
					}
					
					break;
				}
				
				
				case -1268779017:
				{
					if (field.equals("format")) 
					{
						__temp_executeDef54351 = false;
						return this.get_format();
					}
					
					break;
				}
				
				
				case 1143005954:
				{
					if (field.equals("get_mipmaps")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mipmaps"))) );
					}
					
					break;
				}
				
				
				case 811899136:
				{
					if (field.equals("get_format")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_format"))) );
					}
					
					break;
				}
				
				
				case 1066492651:
				{
					if (field.equals("mipmaps")) 
					{
						__temp_executeDef54351 = false;
						if (handleProperties) 
						{
							return this.get_mipmaps();
						}
						 else 
						{
							return this.mipmaps;
						}
						
					}
					
					break;
				}
				
				
				case -1867509751:
				{
					if (field.equals("m_format")) 
					{
						__temp_executeDef54351 = false;
						return this.m_format;
					}
					
					break;
				}
				
				
				case 1344661849:
				{
					if (field.equals("m_magFilter")) 
					{
						__temp_executeDef54351 = false;
						return this.m_magFilter;
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef54351 = false;
						return this.get_wrap();
					}
					
					break;
				}
				
				
				case -1873217778:
				{
					if (field.equals("set_magFilter")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_magFilter"))) );
					}
					
					break;
				}
				
				
				case 1976770451:
				{
					if (field.equals("get_wrap")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_wrap"))) );
					}
					
					break;
				}
				
				
				case 1647618306:
				{
					if (field.equals("get_magFilter")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_magFilter"))) );
					}
					
					break;
				}
				
				
				case 1415657991:
				{
					if (field.equals("set_wrap")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_wrap"))) );
					}
					
					break;
				}
				
				
				case 1132778155:
				{
					if (field.equals("magFilter")) 
					{
						__temp_executeDef54351 = false;
						return this.get_magFilter();
					}
					
					break;
				}
				
				
				case -1082997540:
				{
					if (field.equals("m_wrap")) 
					{
						__temp_executeDef54351 = false;
						return this.m_wrap;
					}
					
					break;
				}
				
				
				case 24833816:
				{
					if (field.equals("m_minFilter")) 
					{
						__temp_executeDef54351 = false;
						return this.m_minFilter;
					}
					
					break;
				}
				
				
				case 92963128:
				{
					if (field.equals("aniso")) 
					{
						__temp_executeDef54351 = false;
						return this.get_aniso();
					}
					
					break;
				}
				
				
				case 1101921485:
				{
					if (field.equals("set_minFilter")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_minFilter"))) );
					}
					
					break;
				}
				
				
				case 1129913103:
				{
					if (field.equals("get_aniso")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_aniso"))) );
					}
					
					break;
				}
				
				
				case 327790273:
				{
					if (field.equals("get_minFilter")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_minFilter"))) );
					}
					
					break;
				}
				
				
				case 915296027:
				{
					if (field.equals("set_aniso")) 
					{
						__temp_executeDef54351 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_aniso"))) );
					}
					
					break;
				}
				
				
				case -187049878:
				{
					if (field.equals("minFilter")) 
					{
						__temp_executeDef54351 = false;
						return this.get_minFilter();
					}
					
					break;
				}
				
				
				case 766385894:
				{
					if (field.equals("m_aniso")) 
					{
						__temp_executeDef54351 = false;
						return this.m_aniso;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54351) 
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
			boolean __temp_executeDef54352 = true;
			switch (field.hashCode())
			{
				case -1483930146:
				{
					if (field.equals("__slot")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.__slot) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.get_width()) );
					}
					
					break;
				}
				
				
				case 766385894:
				{
					if (field.equals("m_aniso")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.m_aniso) );
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.m_width) );
					}
					
					break;
				}
				
				
				case 92963128:
				{
					if (field.equals("aniso")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.get_aniso()) );
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.get_height()) );
					}
					
					break;
				}
				
				
				case -1082997540:
				{
					if (field.equals("m_wrap")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.m_wrap) );
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.m_height) );
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef54352 = false;
						return ((double) (this.get_wrap()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54352) 
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
			boolean __temp_executeDef54353 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef54353 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef54353 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 957120406:
				{
					if (field.equals("GenerateMipmaps")) 
					{
						__temp_executeDef54353 = false;
						this.GenerateMipmaps();
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef54353 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 63476558:
				{
					if (field.equals("Apply")) 
					{
						__temp_executeDef54353 = false;
						this.Apply();
					}
					
					break;
				}
				
				
				case 811899136:
				{
					if (field.equals("get_format")) 
					{
						__temp_executeDef54353 = false;
						return this.get_format();
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef54353 = false;
						return this.get_type();
					}
					
					break;
				}
				
				
				case 1976770451:
				{
					if (field.equals("get_wrap")) 
					{
						__temp_executeDef54353 = false;
						return this.get_wrap();
					}
					
					break;
				}
				
				
				case 1143005954:
				{
					if (field.equals("get_mipmaps")) 
					{
						__temp_executeDef54353 = false;
						return this.get_mipmaps();
					}
					
					break;
				}
				
				
				case 1415657991:
				{
					if (field.equals("set_wrap")) 
					{
						__temp_executeDef54353 = false;
						return this.set_wrap(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1873217778:
				{
					if (field.equals("set_magFilter")) 
					{
						__temp_executeDef54353 = false;
						return this.set_magFilter(((haxor.graphics.TextureFilter) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1129913103:
				{
					if (field.equals("get_aniso")) 
					{
						__temp_executeDef54353 = false;
						return this.get_aniso();
					}
					
					break;
				}
				
				
				case 1647618306:
				{
					if (field.equals("get_magFilter")) 
					{
						__temp_executeDef54353 = false;
						return this.get_magFilter();
					}
					
					break;
				}
				
				
				case 915296027:
				{
					if (field.equals("set_aniso")) 
					{
						__temp_executeDef54353 = false;
						return this.set_aniso(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1101921485:
				{
					if (field.equals("set_minFilter")) 
					{
						__temp_executeDef54353 = false;
						return this.set_minFilter(((haxor.graphics.TextureFilter) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 327790273:
				{
					if (field.equals("get_minFilter")) 
					{
						__temp_executeDef54353 = false;
						return this.get_minFilter();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54353) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("__slot");
		baseArr.push("type");
		baseArr.push("m_mipmaps");
		baseArr.push("mipmaps");
		baseArr.push("m_magFilter");
		baseArr.push("magFilter");
		baseArr.push("m_minFilter");
		baseArr.push("minFilter");
		baseArr.push("m_aniso");
		baseArr.push("aniso");
		baseArr.push("m_wrap");
		baseArr.push("wrap");
		baseArr.push("m_format");
		baseArr.push("format");
		baseArr.push("m_height");
		baseArr.push("height");
		baseArr.push("m_width");
		baseArr.push("width");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}

