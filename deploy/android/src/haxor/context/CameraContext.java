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
	
	
	public static   void __hx_ctor_haxor_context_CameraContext(haxor.context.CameraContext __temp_me164181)
	{
		__temp_me164181.cid = new haxor.context.UID();
		__temp_me164181.list = new haxe.root.Array<haxor.component.Camera>(new haxor.component.Camera[]{});
		__temp_me164181.front = new haxe.root.Array<haxor.graphics.texture.RenderTexture>(new haxor.graphics.texture.RenderTexture[]{});
		__temp_me164181.back = new haxe.root.Array<haxor.graphics.texture.RenderTexture>(new haxor.graphics.texture.RenderTexture[]{});
		{
			int _g = 0;
			while (( _g < 64 ))
			{
				int i = _g++;
				__temp_me164181.front.push(null);
				__temp_me164181.back.push(null);
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
		haxor.context.EngineContext.renderer.AddCamera(c);
	}
	
	
	public   void Destroy(haxor.component.Camera c)
	{
		this.ClearTargets(c);
		this.list.remove(c);
		this.SortCameraList();
		{
			int v = c.__cid;
			this.cid.m_cache.push(v);
			int __temp_expr164772 = v;
		}
		
		haxor.context.EngineContext.renderer.RemoveCamera(c);
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
		boolean need_sap = ( ( haxor.context.EngineContext.renderer.sap_dirty || c.m_view_uniform_dirty ) || c.m_proj_uniform_dirty );
		if (need_sap) 
		{
			haxor.math.Vector3 __temp_stmt164773 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt164773 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
			}
			
			haxor.math.Vector3 n0 = __temp_stmt164773.Set4(c.m_fn0);
			haxor.math.Vector3 __temp_stmt164774 = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				__temp_stmt164774 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
			}
			
			haxor.math.Vector3 n1 = __temp_stmt164774.Set4(c.m_fn1);
			haxor.math.Vector3 __temp_stmt164775 = null;
			{
				haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
				__temp_stmt164775 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
			}
			
			haxor.math.Vector3 n2 = __temp_stmt164775.Set4(c.m_fn2);
			haxor.math.Vector3 __temp_stmt164776 = null;
			{
				haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
				__temp_stmt164776 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
			}
			
			haxor.math.Vector3 n3 = __temp_stmt164776.Set4(c.m_fn3);
			haxor.math.Vector3 __temp_stmt164777 = null;
			{
				haxor.context.DataContext _this4 = haxor.context.EngineContext.data;
				__temp_stmt164777 = _this4.m_v3.__get(_this4.m_nv3 = ( (( _this4.m_nv3 + 1 )) % _this4.m_v3.length ));
			}
			
			haxor.math.Vector3 f0 = __temp_stmt164777.Set4(c.m_ff0);
			haxor.math.Vector3 __temp_stmt164778 = null;
			{
				haxor.context.DataContext _this5 = haxor.context.EngineContext.data;
				__temp_stmt164778 = _this5.m_v3.__get(_this5.m_nv3 = ( (( _this5.m_nv3 + 1 )) % _this5.m_v3.length ));
			}
			
			haxor.math.Vector3 f1 = __temp_stmt164778.Set4(c.m_ff1);
			haxor.math.Vector3 __temp_stmt164779 = null;
			{
				haxor.context.DataContext _this6 = haxor.context.EngineContext.data;
				__temp_stmt164779 = _this6.m_v3.__get(_this6.m_nv3 = ( (( _this6.m_nv3 + 1 )) % _this6.m_v3.length ));
			}
			
			haxor.math.Vector3 f2 = __temp_stmt164779.Set4(c.m_ff2);
			haxor.math.Vector3 __temp_stmt164780 = null;
			{
				haxor.context.DataContext _this7 = haxor.context.EngineContext.data;
				__temp_stmt164780 = _this7.m_v3.__get(_this7.m_nv3 = ( (( _this7.m_nv3 + 1 )) % _this7.m_v3.length ));
			}
			
			haxor.math.Vector3 f3 = __temp_stmt164780.Set4(c.m_ff3);
			{
				haxor.math.Matrix4 _this8 = c.m_entity.m_transform.get_WorldMatrix();
				double vx = ( ( ( ( _this8.m00 * n0.x ) + ( _this8.m01 * n0.y ) ) + ( _this8.m02 * n0.z ) ) + _this8.m03 );
				double vy = ( ( ( ( _this8.m10 * n0.x ) + ( _this8.m11 * n0.y ) ) + ( _this8.m12 * n0.z ) ) + _this8.m13 );
				double vz = ( ( ( ( _this8.m20 * n0.x ) + ( _this8.m21 * n0.y ) ) + ( _this8.m22 * n0.z ) ) + _this8.m23 );
				n0.x = vx;
				n0.y = vy;
				n0.z = vz;
				haxor.math.Vector3 __temp_expr164781 = n0;
			}
			
			{
				haxor.math.Matrix4 _this9 = c.m_entity.m_transform.get_WorldMatrix();
				double vx1 = ( ( ( ( _this9.m00 * n1.x ) + ( _this9.m01 * n1.y ) ) + ( _this9.m02 * n1.z ) ) + _this9.m03 );
				double vy1 = ( ( ( ( _this9.m10 * n1.x ) + ( _this9.m11 * n1.y ) ) + ( _this9.m12 * n1.z ) ) + _this9.m13 );
				double vz1 = ( ( ( ( _this9.m20 * n1.x ) + ( _this9.m21 * n1.y ) ) + ( _this9.m22 * n1.z ) ) + _this9.m23 );
				n1.x = vx1;
				n1.y = vy1;
				n1.z = vz1;
				haxor.math.Vector3 __temp_expr164782 = n1;
			}
			
			{
				haxor.math.Matrix4 _this10 = c.m_entity.m_transform.get_WorldMatrix();
				double vx2 = ( ( ( ( _this10.m00 * n2.x ) + ( _this10.m01 * n2.y ) ) + ( _this10.m02 * n2.z ) ) + _this10.m03 );
				double vy2 = ( ( ( ( _this10.m10 * n2.x ) + ( _this10.m11 * n2.y ) ) + ( _this10.m12 * n2.z ) ) + _this10.m13 );
				double vz2 = ( ( ( ( _this10.m20 * n2.x ) + ( _this10.m21 * n2.y ) ) + ( _this10.m22 * n2.z ) ) + _this10.m23 );
				n2.x = vx2;
				n2.y = vy2;
				n2.z = vz2;
				haxor.math.Vector3 __temp_expr164783 = n2;
			}
			
			{
				haxor.math.Matrix4 _this11 = c.m_entity.m_transform.get_WorldMatrix();
				double vx3 = ( ( ( ( _this11.m00 * n3.x ) + ( _this11.m01 * n3.y ) ) + ( _this11.m02 * n3.z ) ) + _this11.m03 );
				double vy3 = ( ( ( ( _this11.m10 * n3.x ) + ( _this11.m11 * n3.y ) ) + ( _this11.m12 * n3.z ) ) + _this11.m13 );
				double vz3 = ( ( ( ( _this11.m20 * n3.x ) + ( _this11.m21 * n3.y ) ) + ( _this11.m22 * n3.z ) ) + _this11.m23 );
				n3.x = vx3;
				n3.y = vy3;
				n3.z = vz3;
				haxor.math.Vector3 __temp_expr164784 = n3;
			}
			
			{
				haxor.math.Matrix4 _this12 = c.m_entity.m_transform.get_WorldMatrix();
				double vx4 = ( ( ( ( _this12.m00 * f0.x ) + ( _this12.m01 * f0.y ) ) + ( _this12.m02 * f0.z ) ) + _this12.m03 );
				double vy4 = ( ( ( ( _this12.m10 * f0.x ) + ( _this12.m11 * f0.y ) ) + ( _this12.m12 * f0.z ) ) + _this12.m13 );
				double vz4 = ( ( ( ( _this12.m20 * f0.x ) + ( _this12.m21 * f0.y ) ) + ( _this12.m22 * f0.z ) ) + _this12.m23 );
				f0.x = vx4;
				f0.y = vy4;
				f0.z = vz4;
				haxor.math.Vector3 __temp_expr164785 = f0;
			}
			
			{
				haxor.math.Matrix4 _this13 = c.m_entity.m_transform.get_WorldMatrix();
				double vx5 = ( ( ( ( _this13.m00 * f1.x ) + ( _this13.m01 * f1.y ) ) + ( _this13.m02 * f1.z ) ) + _this13.m03 );
				double vy5 = ( ( ( ( _this13.m10 * f1.x ) + ( _this13.m11 * f1.y ) ) + ( _this13.m12 * f1.z ) ) + _this13.m13 );
				double vz5 = ( ( ( ( _this13.m20 * f1.x ) + ( _this13.m21 * f1.y ) ) + ( _this13.m22 * f1.z ) ) + _this13.m23 );
				f1.x = vx5;
				f1.y = vy5;
				f1.z = vz5;
				haxor.math.Vector3 __temp_expr164786 = f1;
			}
			
			{
				haxor.math.Matrix4 _this14 = c.m_entity.m_transform.get_WorldMatrix();
				double vx6 = ( ( ( ( _this14.m00 * f2.x ) + ( _this14.m01 * f2.y ) ) + ( _this14.m02 * f2.z ) ) + _this14.m03 );
				double vy6 = ( ( ( ( _this14.m10 * f2.x ) + ( _this14.m11 * f2.y ) ) + ( _this14.m12 * f2.z ) ) + _this14.m13 );
				double vz6 = ( ( ( ( _this14.m20 * f2.x ) + ( _this14.m21 * f2.y ) ) + ( _this14.m22 * f2.z ) ) + _this14.m23 );
				f2.x = vx6;
				f2.y = vy6;
				f2.z = vz6;
				haxor.math.Vector3 __temp_expr164787 = f2;
			}
			
			{
				haxor.math.Matrix4 _this15 = c.m_entity.m_transform.get_WorldMatrix();
				double vx7 = ( ( ( ( _this15.m00 * f3.x ) + ( _this15.m01 * f3.y ) ) + ( _this15.m02 * f3.z ) ) + _this15.m03 );
				double vy7 = ( ( ( ( _this15.m10 * f3.x ) + ( _this15.m11 * f3.y ) ) + ( _this15.m12 * f3.z ) ) + _this15.m13 );
				double vz7 = ( ( ( ( _this15.m20 * f3.x ) + ( _this15.m21 * f3.y ) ) + ( _this15.m22 * f3.z ) ) + _this15.m23 );
				f3.x = vx7;
				f3.y = vy7;
				f3.z = vz7;
				haxor.math.Vector3 __temp_expr164788 = f3;
			}
			
			haxor.math.Vector3 __temp_stmt164789 = null;
			{
				haxor.context.DataContext _this16 = haxor.context.EngineContext.data;
				__temp_stmt164789 = _this16.m_v3.__get(_this16.m_nv3 = ( (( _this16.m_nv3 + 1 )) % _this16.m_v3.length ));
			}
			
			haxor.math.Vector3 pmin = __temp_stmt164789.Set(n0.x, n0.y, n0.z);
			haxor.math.Vector3 __temp_stmt164790 = null;
			{
				haxor.context.DataContext _this17 = haxor.context.EngineContext.data;
				__temp_stmt164790 = _this17.m_v3.__get(_this17.m_nv3 = ( (( _this17.m_nv3 + 1 )) % _this17.m_v3.length ));
			}
			
			haxor.math.Vector3 pmax = __temp_stmt164790.Set(n0.x, n0.y, n0.z);
			haxor.math.Vector3 p = null;
			{
				double b = 0.0;
				{
					double b1 = java.lang.Math.min(n2.x, n3.x);
					b = java.lang.Math.min(n1.x, b1);
				}
				
				pmin.x = java.lang.Math.min(pmin.x, b);
			}
			
			{
				double b2 = 0.0;
				{
					double b3 = java.lang.Math.min(n2.y, n3.y);
					b2 = java.lang.Math.min(n1.y, b3);
				}
				
				pmin.y = java.lang.Math.min(pmin.y, b2);
			}
			
			{
				double b4 = 0.0;
				{
					double b5 = java.lang.Math.min(n2.z, n3.z);
					b4 = java.lang.Math.min(n1.z, b5);
				}
				
				pmin.z = java.lang.Math.min(pmin.z, b4);
			}
			
			{
				double b6 = 0.0;
				{
					double b7 = java.lang.Math.max(n2.x, n3.x);
					b6 = java.lang.Math.max(n1.x, b7);
				}
				
				pmax.x = java.lang.Math.max(pmax.x, b6);
			}
			
			{
				double b8 = 0.0;
				{
					double b9 = java.lang.Math.max(n2.y, n3.y);
					b8 = java.lang.Math.max(n1.y, b9);
				}
				
				pmax.y = java.lang.Math.max(pmax.y, b8);
			}
			
			{
				double b10 = 0.0;
				{
					double b11 = java.lang.Math.max(n2.z, n3.z);
					b10 = java.lang.Math.max(n1.z, b11);
				}
				
				pmax.z = java.lang.Math.max(pmax.z, b10);
			}
			
			{
				double b12 = 0.0;
				{
					double b13 = 0.0;
					{
						double b14 = java.lang.Math.min(f2.x, f3.x);
						b13 = java.lang.Math.min(f1.x, b14);
					}
					
					b12 = java.lang.Math.min(f0.x, b13);
				}
				
				pmin.x = java.lang.Math.min(pmin.x, b12);
			}
			
			{
				double b15 = 0.0;
				{
					double b16 = 0.0;
					{
						double b17 = java.lang.Math.min(f2.y, f3.y);
						b16 = java.lang.Math.min(f1.y, b17);
					}
					
					b15 = java.lang.Math.min(f0.y, b16);
				}
				
				pmin.y = java.lang.Math.min(pmin.y, b15);
			}
			
			{
				double b18 = 0.0;
				{
					double b19 = 0.0;
					{
						double b20 = java.lang.Math.min(f2.z, f3.z);
						b19 = java.lang.Math.min(f1.z, b20);
					}
					
					b18 = java.lang.Math.min(f0.z, b19);
				}
				
				pmin.z = java.lang.Math.min(pmin.z, b18);
			}
			
			{
				double b21 = 0.0;
				{
					double b22 = 0.0;
					{
						double b23 = java.lang.Math.min(f2.x, f3.x);
						b22 = java.lang.Math.max(f1.x, b23);
					}
					
					b21 = java.lang.Math.max(f0.x, b22);
				}
				
				pmax.x = java.lang.Math.max(pmax.x, b21);
			}
			
			{
				double b24 = 0.0;
				{
					double b25 = 0.0;
					{
						double b26 = java.lang.Math.min(f2.y, f3.y);
						b25 = java.lang.Math.max(f1.y, b26);
					}
					
					b24 = java.lang.Math.max(f0.y, b25);
				}
				
				pmax.y = java.lang.Math.max(pmax.y, b24);
			}
			
			{
				double b27 = 0.0;
				{
					double b28 = 0.0;
					{
						double b29 = java.lang.Math.min(f2.z, f3.z);
						b28 = java.lang.Math.max(f1.z, b29);
					}
					
					b27 = java.lang.Math.max(f0.z, b28);
				}
				
				pmax.z = java.lang.Math.max(pmax.z, b27);
			}
			
			double dx = ( (( pmax.x - pmin.x )) * 0.02 );
			double dy = ( (( pmax.y - pmin.y )) * 0.02 );
			double dz = ( (( pmax.z - pmin.z )) * 0.02 );
			pmin.x -= dx;
			pmax.x += dx;
			pmin.y -= dy;
			pmax.y += dy;
			pmin.z -= dz;
			pmax.z += dz;
			haxor.context.EngineContext.renderer.UpdateSAP(c.__fcid, c, pmin, pmax);
		}
		
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
		double __temp_stmt164791 = 0.0;
		{
			haxor.math.AABB2 _this = c.m_viewport;
			{
				double p_a = ( _this.get_xMax() - _this.get_xMin() );
				__temp_stmt164791 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
			}
			
		}
		
		aw = ( __temp_stmt164791 * w );
		double ah = 0.0;
		double __temp_stmt164792 = 0.0;
		{
			haxor.math.AABB2 _this1 = c.m_viewport;
			{
				double p_a1 = ( _this1.get_yMax() - _this1.get_yMin() );
				__temp_stmt164792 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
			}
			
		}
		
		ah = ( __temp_stmt164792 * h );
		{
			c.m_pixelViewport.set_xMin(vx);
			double __temp_expr164793 = vx;
		}
		
		{
			double v = ( ( h - ah ) - vy );
			c.m_pixelViewport.set_yMin(v);
			double __temp_expr164794 = v;
		}
		
		{
			haxor.math.AABB2 _this2 = c.m_pixelViewport;
			_this2.set_xMax(( _this2.get_xMin() + aw ));
			double __temp_expr164795 = aw;
		}
		
		{
			haxor.math.AABB2 _this3 = c.m_pixelViewport;
			_this3.set_yMax(( _this3.get_yMin() + ah ));
			double __temp_expr164796 = ah;
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
			this.list.sort(( (( haxor.context.CameraContext_SortCameraList_279__Fun.__hx_current != null )) ? (haxor.context.CameraContext_SortCameraList_279__Fun.__hx_current) : (haxor.context.CameraContext_SortCameraList_279__Fun.__hx_current = ((haxor.context.CameraContext_SortCameraList_279__Fun) (new haxor.context.CameraContext_SortCameraList_279__Fun()) )) ));
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164797 = true;
			switch (field.hashCode())
			{
				case 3015911:
				{
					if (field.equals("back")) 
					{
						__temp_executeDef164797 = false;
						this.back = ((haxe.root.Array<haxor.graphics.texture.RenderTexture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98494:
				{
					if (field.equals("cid")) 
					{
						__temp_executeDef164797 = false;
						this.cid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 97705513:
				{
					if (field.equals("front")) 
					{
						__temp_executeDef164797 = false;
						this.front = ((haxe.root.Array<haxor.graphics.texture.RenderTexture>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef164797 = false;
						this.list = ((haxe.root.Array<haxor.component.Camera>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164797) 
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
			boolean __temp_executeDef164798 = true;
			switch (field.hashCode())
			{
				case -1990951487:
				{
					if (field.equals("SortCameraList")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SortCameraList"))) );
					}
					
					break;
				}
				
				
				case 98494:
				{
					if (field.equals("cid")) 
					{
						__temp_executeDef164798 = false;
						return this.cid;
					}
					
					break;
				}
				
				
				case 1064863919:
				{
					if (field.equals("UpdateViewport")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateViewport"))) );
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef164798 = false;
						return this.list;
					}
					
					break;
				}
				
				
				case 2084803535:
				{
					if (field.equals("SwapTargets")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SwapTargets"))) );
					}
					
					break;
				}
				
				
				case 97705513:
				{
					if (field.equals("front")) 
					{
						__temp_executeDef164798 = false;
						return this.front;
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 3015911:
				{
					if (field.equals("back")) 
					{
						__temp_executeDef164798 = false;
						return this.back;
					}
					
					break;
				}
				
				
				case -1397770731:
				{
					if (field.equals("ClearTargets")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearTargets"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef164798 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164798) 
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
			boolean __temp_executeDef164799 = true;
			switch (field.hashCode())
			{
				case -1990951487:
				{
					if (field.equals("SortCameraList")) 
					{
						__temp_executeDef164799 = false;
						this.SortCameraList();
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef164799 = false;
						this.Create(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1064863919:
				{
					if (field.equals("UpdateViewport")) 
					{
						__temp_executeDef164799 = false;
						this.UpdateViewport(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef164799 = false;
						this.Destroy(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2084803535:
				{
					if (field.equals("SwapTargets")) 
					{
						__temp_executeDef164799 = false;
						this.SwapTargets(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef164799 = false;
						this.Bind(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef164799 = false;
						this.Unbind(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef164799 = false;
						this.Resize();
					}
					
					break;
				}
				
				
				case -1397770731:
				{
					if (field.equals("ClearTargets")) 
					{
						__temp_executeDef164799 = false;
						this.ClearTargets(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164799) 
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


