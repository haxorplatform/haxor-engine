package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TextureCube extends haxor.graphics.texture.Texture
{
	public    TextureCube(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    TextureCube()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.graphics.texture.TextureCube.__hx_ctor_haxor_graphics_texture_TextureCube(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_TextureCube(haxor.graphics.texture.TextureCube __temp_me42388)
	{
		__temp_me42388.m_faces = new haxe.root.Array<haxor.graphics.texture.Texture>(new haxor.graphics.texture.Texture[]{null, null, null, null, null, null});
		__temp_me42388.m_is_cross = false;
		haxor.graphics.texture.Texture.__hx_ctor_haxor_graphics_texture_Texture(__temp_me42388);
		haxor.context.EngineContext.texture.Create(__temp_me42388);
	}
	
	
	public static   haxor.graphics.texture.TextureCube FromCrossTexture(haxor.graphics.texture.Texture2D p_texture)
	{
		return null;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.TextureCube(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.TextureCube();
	}
	
	
	
	
	public final   haxor.graphics.texture.Texture get_px()
	{
		return this.m_faces.__get(0);
	}
	
	
	public   haxor.graphics.texture.Texture set_px(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(0, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_px;
	
	
	
	public final   haxor.graphics.texture.Texture get_nx()
	{
		return this.m_faces.__get(1);
	}
	
	
	public   haxor.graphics.texture.Texture set_nx(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(1, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_nx;
	
	
	
	public final   haxor.graphics.texture.Texture get_py()
	{
		return this.m_faces.__get(2);
	}
	
	
	public   haxor.graphics.texture.Texture set_py(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(2, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_py;
	
	
	
	public final   haxor.graphics.texture.Texture get_ny()
	{
		return this.m_faces.__get(3);
	}
	
	
	public   haxor.graphics.texture.Texture set_ny(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(3, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_ny;
	
	
	
	public final   haxor.graphics.texture.Texture get_pz()
	{
		return this.m_faces.__get(4);
	}
	
	
	public   haxor.graphics.texture.Texture set_pz(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(4, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_pz;
	
	
	
	public final   haxor.graphics.texture.Texture get_nz()
	{
		return this.m_faces.__get(5);
	}
	
	
	public   haxor.graphics.texture.Texture set_nz(haxor.graphics.texture.Texture v)
	{
		this.InvalidateCross();
		this.m_faces.__set(5, v);
		return v;
	}
	
	
	public  haxor.graphics.texture.Texture p_nz;
	
	public  haxe.root.Array<haxor.graphics.texture.Texture> m_faces;
	
	public  boolean m_is_cross;
	
	@Override public   void OnDestroy()
	{
		super.OnDestroy();
		{
			int _g1 = 0;
			int _g = this.m_faces.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (( this.m_faces.__get(i) != null )) 
				{
					haxor.core.Resource.Destroy(this.m_faces.__get(i));
				}
				
			}
			
		}
		
	}
	
	
	public   void InvalidateCross()
	{
		if ( ! (this.m_is_cross) ) 
		{
			return ;
		}
		
		{
			int _g1 = 0;
			int _g = this.m_faces.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (( this.m_faces.__get(i) != null )) 
				{
					haxor.core.Resource.Destroy(this.m_faces.__get(i));
				}
				
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef42630 = true;
			switch (field.hashCode())
			{
				case 255286397:
				{
					if (field.equals("m_is_cross")) 
					{
						__temp_executeDef42630 = false;
						this.m_is_cross = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3592:
				{
					if (field.equals("px")) 
					{
						__temp_executeDef42630 = false;
						this.set_px(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 770610020:
				{
					if (field.equals("m_faces")) 
					{
						__temp_executeDef42630 = false;
						this.m_faces = ((haxe.root.Array<haxor.graphics.texture.Texture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3431479:
				{
					if (field.equals("p_px")) 
					{
						__temp_executeDef42630 = false;
						this.p_px = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3431419:
				{
					if (field.equals("p_nz")) 
					{
						__temp_executeDef42630 = false;
						this.p_nz = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3530:
				{
					if (field.equals("nx")) 
					{
						__temp_executeDef42630 = false;
						this.set_nx(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3532:
				{
					if (field.equals("nz")) 
					{
						__temp_executeDef42630 = false;
						this.set_nz(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3431417:
				{
					if (field.equals("p_nx")) 
					{
						__temp_executeDef42630 = false;
						this.p_nx = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3431481:
				{
					if (field.equals("p_pz")) 
					{
						__temp_executeDef42630 = false;
						this.p_pz = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3593:
				{
					if (field.equals("py")) 
					{
						__temp_executeDef42630 = false;
						this.set_py(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3594:
				{
					if (field.equals("pz")) 
					{
						__temp_executeDef42630 = false;
						this.set_pz(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3431480:
				{
					if (field.equals("p_py")) 
					{
						__temp_executeDef42630 = false;
						this.p_py = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3431418:
				{
					if (field.equals("p_ny")) 
					{
						__temp_executeDef42630 = false;
						this.p_ny = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3531:
				{
					if (field.equals("ny")) 
					{
						__temp_executeDef42630 = false;
						this.set_ny(((haxor.graphics.texture.Texture) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42630) 
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
			boolean __temp_executeDef42631 = true;
			switch (field.hashCode())
			{
				case 2043460517:
				{
					if (field.equals("InvalidateCross")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("InvalidateCross"))) );
					}
					
					break;
				}
				
				
				case 3592:
				{
					if (field.equals("px")) 
					{
						__temp_executeDef42631 = false;
						return this.get_px();
					}
					
					break;
				}
				
				
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -1249338479:
				{
					if (field.equals("get_px")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_px"))) );
					}
					
					break;
				}
				
				
				case 255286397:
				{
					if (field.equals("m_is_cross")) 
					{
						__temp_executeDef42631 = false;
						return this.m_is_cross;
					}
					
					break;
				}
				
				
				case -905788667:
				{
					if (field.equals("set_px")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_px"))) );
					}
					
					break;
				}
				
				
				case 770610020:
				{
					if (field.equals("m_faces")) 
					{
						__temp_executeDef42631 = false;
						return this.m_faces;
					}
					
					break;
				}
				
				
				case 3431479:
				{
					if (field.equals("p_px")) 
					{
						__temp_executeDef42631 = false;
						return this.p_px;
					}
					
					break;
				}
				
				
				case 3431419:
				{
					if (field.equals("p_nz")) 
					{
						__temp_executeDef42631 = false;
						return this.p_nz;
					}
					
					break;
				}
				
				
				case 3530:
				{
					if (field.equals("nx")) 
					{
						__temp_executeDef42631 = false;
						return this.get_nx();
					}
					
					break;
				}
				
				
				case -905788727:
				{
					if (field.equals("set_nz")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nz"))) );
					}
					
					break;
				}
				
				
				case -1249338541:
				{
					if (field.equals("get_nx")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nx"))) );
					}
					
					break;
				}
				
				
				case -1249338539:
				{
					if (field.equals("get_nz")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nz"))) );
					}
					
					break;
				}
				
				
				case -905788729:
				{
					if (field.equals("set_nx")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nx"))) );
					}
					
					break;
				}
				
				
				case 3532:
				{
					if (field.equals("nz")) 
					{
						__temp_executeDef42631 = false;
						return this.get_nz();
					}
					
					break;
				}
				
				
				case 3431417:
				{
					if (field.equals("p_nx")) 
					{
						__temp_executeDef42631 = false;
						return this.p_nx;
					}
					
					break;
				}
				
				
				case 3431481:
				{
					if (field.equals("p_pz")) 
					{
						__temp_executeDef42631 = false;
						return this.p_pz;
					}
					
					break;
				}
				
				
				case 3593:
				{
					if (field.equals("py")) 
					{
						__temp_executeDef42631 = false;
						return this.get_py();
					}
					
					break;
				}
				
				
				case -905788665:
				{
					if (field.equals("set_pz")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_pz"))) );
					}
					
					break;
				}
				
				
				case -1249338478:
				{
					if (field.equals("get_py")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_py"))) );
					}
					
					break;
				}
				
				
				case -1249338477:
				{
					if (field.equals("get_pz")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_pz"))) );
					}
					
					break;
				}
				
				
				case -905788666:
				{
					if (field.equals("set_py")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_py"))) );
					}
					
					break;
				}
				
				
				case 3594:
				{
					if (field.equals("pz")) 
					{
						__temp_executeDef42631 = false;
						return this.get_pz();
					}
					
					break;
				}
				
				
				case 3431480:
				{
					if (field.equals("p_py")) 
					{
						__temp_executeDef42631 = false;
						return this.p_py;
					}
					
					break;
				}
				
				
				case 3431418:
				{
					if (field.equals("p_ny")) 
					{
						__temp_executeDef42631 = false;
						return this.p_ny;
					}
					
					break;
				}
				
				
				case 3531:
				{
					if (field.equals("ny")) 
					{
						__temp_executeDef42631 = false;
						return this.get_ny();
					}
					
					break;
				}
				
				
				case -905788728:
				{
					if (field.equals("set_ny")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_ny"))) );
					}
					
					break;
				}
				
				
				case -1249338540:
				{
					if (field.equals("get_ny")) 
					{
						__temp_executeDef42631 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_ny"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42631) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef42632 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef42632 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1249338479:
				{
					if (field.equals("get_px")) 
					{
						__temp_executeDef42632 = false;
						return this.get_px();
					}
					
					break;
				}
				
				
				case 2043460517:
				{
					if (field.equals("InvalidateCross")) 
					{
						__temp_executeDef42632 = false;
						this.InvalidateCross();
					}
					
					break;
				}
				
				
				case -905788667:
				{
					if (field.equals("set_px")) 
					{
						__temp_executeDef42632 = false;
						return this.set_px(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -905788727:
				{
					if (field.equals("set_nz")) 
					{
						__temp_executeDef42632 = false;
						return this.set_nz(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338541:
				{
					if (field.equals("get_nx")) 
					{
						__temp_executeDef42632 = false;
						return this.get_nx();
					}
					
					break;
				}
				
				
				case -1249338539:
				{
					if (field.equals("get_nz")) 
					{
						__temp_executeDef42632 = false;
						return this.get_nz();
					}
					
					break;
				}
				
				
				case -905788729:
				{
					if (field.equals("set_nx")) 
					{
						__temp_executeDef42632 = false;
						return this.set_nx(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -905788665:
				{
					if (field.equals("set_pz")) 
					{
						__temp_executeDef42632 = false;
						return this.set_pz(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338478:
				{
					if (field.equals("get_py")) 
					{
						__temp_executeDef42632 = false;
						return this.get_py();
					}
					
					break;
				}
				
				
				case -1249338477:
				{
					if (field.equals("get_pz")) 
					{
						__temp_executeDef42632 = false;
						return this.get_pz();
					}
					
					break;
				}
				
				
				case -905788666:
				{
					if (field.equals("set_py")) 
					{
						__temp_executeDef42632 = false;
						return this.set_py(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -905788728:
				{
					if (field.equals("set_ny")) 
					{
						__temp_executeDef42632 = false;
						return this.set_ny(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338540:
				{
					if (field.equals("get_ny")) 
					{
						__temp_executeDef42632 = false;
						return this.get_ny();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42632) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_is_cross");
		baseArr.push("m_faces");
		baseArr.push("p_nz");
		baseArr.push("nz");
		baseArr.push("p_pz");
		baseArr.push("pz");
		baseArr.push("p_ny");
		baseArr.push("ny");
		baseArr.push("p_py");
		baseArr.push("py");
		baseArr.push("p_nx");
		baseArr.push("nx");
		baseArr.push("p_px");
		baseArr.push("px");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


