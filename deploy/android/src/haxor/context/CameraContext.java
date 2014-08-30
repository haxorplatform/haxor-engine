package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CameraContext extends haxe.lang.HxObject
{
	public    CameraContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    CameraContext()
	{
		haxor.context.CameraContext.__hx_ctor_haxor_context_CameraContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_CameraContext(haxor.context.CameraContext __temp_me151338)
	{
		__temp_me151338.cid = new haxor.context.UID();
		__temp_me151338.list = new haxe.root.Array<haxor.component.Camera>(new haxor.component.Camera[]{});
		__temp_me151338.front = new haxe.root.Array<haxor.graphics.texture.RenderTexture>(new haxor.graphics.texture.RenderTexture[]{});
		__temp_me151338.back = new haxe.root.Array<haxor.graphics.texture.RenderTexture>(new haxor.graphics.texture.RenderTexture[]{});
		{
			int _g = 0;
			while (( _g < 64 ))
			{
				int i = _g++;
				__temp_me151338.front.push(null);
				__temp_me151338.back.push(null);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.CameraContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.CameraContext();
	}
	
	
	public  haxor.context.UID cid;
	
	public  haxe.root.Array<haxor.component.Camera> list;
	
	public  haxe.root.Array<haxor.graphics.texture.RenderTexture> front;
	
	public  haxe.root.Array<haxor.graphics.texture.RenderTexture> back;
	
	public   void Create(haxor.component.Camera c)
	{
		this.list.push(c);
		this.SortCameraList();
	}
	
	
	public   void Destroy(haxor.component.Camera c)
	{
		this.ClearTargets(c);
		this.list.remove(c);
		this.SortCameraList();
		{
			int v = c.__cid;
			this.cid.m_cache.push(v);
			int __temp_expr152009 = v;
		}
		
	}
	
	
	public   void Bind(haxor.component.Camera c)
	{
		haxor.graphics.texture.RenderTexture ft = this.front.__get(c.__cid);
		haxor.graphics.texture.RenderTexture rt = c.m_target;
		haxor.graphics.texture.RenderTexture target = null;
		if (( ft == null )) 
		{
			target = rt;
		}
		 else 
		{
			target = ft;
		}
		
		c.UpdateProjection();
		haxor.context.EngineContext.texture.BindTarget(target);
		haxor.context.EngineContext.renderer.UpdateDisplayList(c);
		haxor.graphics.Graphics.Clear(c);
	}
	
	
	public   void Resize()
	{
		int _g1 = 0;
		int _g = this.list.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			this.UpdateViewport(this.list.__get(i));
		}
		
	}
	
	
	public   void ClearTargets(haxor.component.Camera c)
	{
		haxor.graphics.texture.RenderTexture rt = null;
		rt = this.front.__get(c.__cid);
		if (( rt != null )) 
		{
			haxor.core.Resource.Destroy(rt);
		}
		
		rt = this.back.__get(c.__cid);
		if (( rt != null )) 
		{
			haxor.core.Resource.Destroy(rt);
		}
		
		this.front.__set(c.__cid, null);
		this.back.__set(c.__cid, null);
	}
	
	
	public   void Unbind(haxor.component.Camera c)
	{
		this.SwapTargets(c);
	}
	
	
	public   void SwapTargets(haxor.component.Camera c)
	{
		haxor.graphics.texture.RenderTexture tmp = null;
		tmp = this.front.__get(c.__cid);
		this.front.__set(c.__cid, this.back.__get(c.__cid));
		this.back.__set(c.__cid, tmp);
	}
	
	
	public   void UpdateViewport(haxor.component.Camera c)
	{
		boolean need_buffer = false;
		if (( c.m_quality < 1.0 )) 
		{
			need_buffer = true;
		}
		 else 
		{
			if (( c.get_filters().length > 0 )) 
			{
				need_buffer = true;
			}
			
		}
		
		double w = haxor.graphics.Screen.m_width;
		double h = haxor.graphics.Screen.m_height;
		if (( c.m_target != null )) 
		{
			w = ((double) (c.m_target.m_width) );
			h = ((double) (c.m_target.m_height) );
		}
		
		c.m_aspect = ( w / h );
		double sw = ( w * c.m_quality );
		double sh = ( h * c.m_quality );
		if (( sw < 1.0 )) 
		{
			w = 1.0;
		}
		 else 
		{
			w = sw;
		}
		
		if (( sh < 1.0 )) 
		{
			h = 1.0;
		}
		 else 
		{
			h = sh;
		}
		
		double vx = 0.0;
		{
			double x = ( c.m_viewport.get_xMin() * w );
			vx = ((double) (((int) (x) )) );
		}
		
		double vy = 0.0;
		{
			double x1 = ( c.m_viewport.get_yMin() * h );
			vy = ((double) (((int) (x1) )) );
		}
		
		double aw = 0.0;
		double __temp_stmt152010 = 0.0;
		{
			haxor.math.AABB2 _this = c.m_viewport;
			{
				double p_a = ( _this.get_xMax() - _this.get_xMin() );
				__temp_stmt152010 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
			}
			
		}
		
		aw = ( __temp_stmt152010 * w );
		double ah = 0.0;
		double __temp_stmt152011 = 0.0;
		{
			haxor.math.AABB2 _this1 = c.m_viewport;
			{
				double p_a1 = ( _this1.get_yMax() - _this1.get_yMin() );
				__temp_stmt152011 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
			}
			
		}
		
		ah = ( __temp_stmt152011 * h );
		{
			c.m_pixelViewport.set_xMin(vx);
			double __temp_expr152012 = vx;
		}
		
		{
			double v = ( ( h - ah ) - vy );
			c.m_pixelViewport.set_yMin(v);
			double __temp_expr152013 = v;
		}
		
		{
			haxor.math.AABB2 _this2 = c.m_pixelViewport;
			_this2.set_xMax(( _this2.get_xMin() + aw ));
			double __temp_expr152014 = aw;
		}
		
		{
			haxor.math.AABB2 _this3 = c.m_pixelViewport;
			_this3.set_yMax(( _this3.get_yMin() + ah ));
			double __temp_expr152015 = ah;
		}
		
		int tw = ((int) (aw) );
		int th = ((int) (ah) );
		haxor.graphics.texture.RenderTexture grt = null;
		grt = this.front.__get(c.__cid);
		if (( grt != null )) 
		{
			if (( tw != grt.m_width )) 
			{
				this.ClearTargets(c);
			}
			 else 
			{
				if (( th != grt.m_height )) 
				{
					this.ClearTargets(c);
				}
				
			}
			
		}
		
		grt = this.front.__get(c.__cid);
		if (( grt == null )) 
		{
			if (need_buffer) 
			{
				haxor.core.PixelFormat tf = null;
				if (( c.m_target == null )) 
				{
					tf = haxor.core.PixelFormat.RGB8;
				}
				 else 
				{
					tf = c.m_target.m_format;
				}
				
				this.front.__set(c.__cid, new haxor.graphics.texture.RenderTexture(((int) (aw) ), ((int) (ah) ), ((haxor.core.PixelFormat) (tf) ), ((java.lang.Object) (c.m_captureDepth) )));
				if (( c.get_filters().length <= 0 )) 
				{
					this.back.__set(c.__cid, this.front.__get(c.__cid));
				}
				 else 
				{
					this.back.__set(c.__cid, new haxor.graphics.texture.RenderTexture(((int) (aw) ), ((int) (ah) ), ((haxor.core.PixelFormat) (tf) ), ((java.lang.Object) (c.m_captureDepth) )));
				}
				
				this.front.__get(c.__cid).set_name(this.back.__get(c.__cid).set_name("CameraScreenBuffer"));
			}
			
		}
		
		c.m_projection_dirty = true;
		c.m_proj_uniform_dirty = true;
	}
	
	
	public   void SortCameraList()
	{
		if (( this.list.length > 1 )) 
		{
			this.list.sort(( (( haxor.context.CameraContext_SortCameraList_215__Fun.__hx_current != null )) ? (haxor.context.CameraContext_SortCameraList_215__Fun.__hx_current) : (haxor.context.CameraContext_SortCameraList_215__Fun.__hx_current = ((haxor.context.CameraContext_SortCameraList_215__Fun) (new haxor.context.CameraContext_SortCameraList_215__Fun()) )) ));
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152016 = true;
			switch (field.hashCode())
			{
				case 3015911:
				{
					if (field.equals("back")) 
					{
						__temp_executeDef152016 = false;
						this.back = ((haxe.root.Array<haxor.graphics.texture.RenderTexture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98494:
				{
					if (field.equals("cid")) 
					{
						__temp_executeDef152016 = false;
						this.cid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 97705513:
				{
					if (field.equals("front")) 
					{
						__temp_executeDef152016 = false;
						this.front = ((haxe.root.Array<haxor.graphics.texture.RenderTexture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef152016 = false;
						this.list = ((haxe.root.Array<haxor.component.Camera>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152016) 
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
			boolean __temp_executeDef152017 = true;
			switch (field.hashCode())
			{
				case -1990951487:
				{
					if (field.equals("SortCameraList")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SortCameraList"))) );
					}
					
					break;
				}
				
				
				case 98494:
				{
					if (field.equals("cid")) 
					{
						__temp_executeDef152017 = false;
						return this.cid;
					}
					
					break;
				}
				
				
				case 1064863919:
				{
					if (field.equals("UpdateViewport")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateViewport"))) );
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef152017 = false;
						return this.list;
					}
					
					break;
				}
				
				
				case 2084803535:
				{
					if (field.equals("SwapTargets")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SwapTargets"))) );
					}
					
					break;
				}
				
				
				case 97705513:
				{
					if (field.equals("front")) 
					{
						__temp_executeDef152017 = false;
						return this.front;
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 3015911:
				{
					if (field.equals("back")) 
					{
						__temp_executeDef152017 = false;
						return this.back;
					}
					
					break;
				}
				
				
				case -1397770731:
				{
					if (field.equals("ClearTargets")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearTargets"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef152017 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152017) 
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
			boolean __temp_executeDef152018 = true;
			switch (field.hashCode())
			{
				case -1990951487:
				{
					if (field.equals("SortCameraList")) 
					{
						__temp_executeDef152018 = false;
						this.SortCameraList();
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef152018 = false;
						this.Create(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1064863919:
				{
					if (field.equals("UpdateViewport")) 
					{
						__temp_executeDef152018 = false;
						this.UpdateViewport(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef152018 = false;
						this.Destroy(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2084803535:
				{
					if (field.equals("SwapTargets")) 
					{
						__temp_executeDef152018 = false;
						this.SwapTargets(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef152018 = false;
						this.Bind(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef152018 = false;
						this.Unbind(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef152018 = false;
						this.Resize();
					}
					
					break;
				}
				
				
				case -1397770731:
				{
					if (field.equals("ClearTargets")) 
					{
						__temp_executeDef152018 = false;
						this.ClearTargets(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152018) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("back");
		baseArr.push("front");
		baseArr.push("list");
		baseArr.push("cid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


