package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RendererContext extends haxe.lang.HxObject
{
	public    RendererContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RendererContext()
	{
		haxor.context.RendererContext.__hx_ctor_haxor_context_RendererContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_RendererContext(haxor.context.RendererContext __temp_me255386)
	{
		__temp_me255386.rid = new haxor.context.UID();
		__temp_me255386.fcid = new haxor.context.UID();
		__temp_me255386.sap = new haxor.ds.SAP(((java.lang.Object) (0.01) ), ((java.lang.Object) (false) ));
		__temp_me255386.sap_dirty = false;
		__temp_me255386.deferred_culling = 0;
		__temp_me255386.deferred_offset = 100;
		__temp_me255386.display = new haxe.root.Array<haxor.context.Process>(new haxor.context.Process[]{});
		__temp_me255386.sort = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 32 ))
			{
				int i = _g++;
				haxor.context.Process<haxor.component.Renderer> p = new haxor.context.Process<haxor.component.Renderer>(haxe.lang.Runtime.toString("process.renderers"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (( i == 31 )) ));
				__temp_me255386.display.push(((haxor.context.Process) (p) ));
				__temp_me255386.sort.push(false);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.RendererContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.RendererContext();
	}
	
	
	public  haxor.context.UID rid;
	
	public  haxor.context.UID fcid;
	
	public  haxe.root.Array<haxor.context.Process> display;
	
	public  haxor.ds.SAP sap;
	
	public  boolean sap_dirty;
	
	public  haxe.root.Array<java.lang.Object> sort;
	
	public  haxor.graphics.texture.ComputeTexture skinning;
	
	public  int deferred_culling;
	
	public  int deferred_offset;
	
	public   void Initialize()
	{
		this.skinning = new haxor.graphics.texture.ComputeTexture(((int) (512) ), ((int) (512) ), ((haxor.core.PixelFormat) (haxor.core.PixelFormat.Float4) ));
	}
	
	
	public   void Create(haxor.component.Renderer r)
	{
		{
			haxor.context.UID _this = this.rid;
			if (( _this.m_cache.length <= 0 )) 
			{
				r.__cid = _this.m_id++;
			}
			 else 
			{
				r.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			{
				haxor.context.UID _this1 = this.fcid;
				if (( _this1.m_cache.length <= 0 )) 
				{
					mr.__fcid = _this1.m_id++;
				}
				 else 
				{
					mr.__fcid = ((int) (haxe.lang.Runtime.toInt(_this1.m_cache.shift())) );
				}
				
			}
			
			this.sap.Create(mr.__fcid);
		}
		
	}
	
	
	public   void AddCamera(haxor.component.Camera c)
	{
		{
			haxor.context.UID _this = this.fcid;
			if (( _this.m_cache.length <= 0 )) 
			{
				c.__fcid = _this.m_id++;
			}
			 else 
			{
				c.__fcid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		this.sap.Create(c.__fcid);
	}
	
	
	public   void RemoveCamera(haxor.component.Camera c)
	{
		{
			int v = c.__fcid;
			this.fcid.m_cache.push(v);
			int __temp_expr256021 = v;
		}
		
		this.sap.Remove(c.__fcid);
	}
	
	
	public   void OnMaterialChange(haxor.component.Renderer r)
	{
		int l = r.m_entity.m_layer;
		this.sort.__set(l, true);
	}
	
	
	public   void OnMeshChange(haxor.component.Renderer r)
	{
		int l = r.m_entity.m_layer;
		this.sort.__set(l, true);
	}
	
	
	public   void OnVisibilityChange(haxor.component.Renderer r, boolean f)
	{
		haxe.root.Array<haxor.component.Component> cl = r.m_entity.m_components;
		{
			int _g1 = 0;
			int _g = cl.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				cl.__get(i).OnVisibilityChange(f);
			}
			
		}
		
	}
	
	
	public   boolean DeferredCulling(haxor.component.Renderer r)
	{
		return false;
	}
	
	
	public   void OnLayerChange(haxor.component.Renderer r, int from, int to)
	{
		this.sort.__set(from, true);
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(from)) )) ).Remove(r);
		if (r.get_enabled()) 
		{
			((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(to)) )) ).Add(r);
			this.sort.__set(to, true);
		}
		
	}
	
	
	public   void UpdateDisplayList(haxor.component.Camera c)
	{
		haxe.root.Array<java.lang.Object> ll = c.m_layers;
		{
			int _g1 = 0;
			int _g = ll.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int l = ((int) (haxe.lang.Runtime.toInt(ll.__get(i))) );
				haxor.context.Process<haxor.component.Renderer> rl = ((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(l)) )) );
				boolean need_sort = haxe.lang.Runtime.toBool(this.sort.__get(l));
				if (need_sort) 
				{
					this.sort.__set(l, false);
					if (( rl.m_length > 1 )) 
					{
						rl.Sort(((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) ));
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void Enable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Add(r);
		this.sort.__set(r.m_entity.m_layer, true);
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			mr.m_culling_dirty = true;
		}
		
	}
	
	
	public   void Disable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
	}
	
	
	public   void UpdateCameraSAP(haxor.component.Camera c)
	{
		boolean need_sap = ( ( this.sap_dirty || c.m_view_uniform_dirty ) || c.m_proj_uniform_dirty );
		if ( ! (need_sap) ) 
		{
			return ;
		}
		
		haxor.math.Vector4 __temp_stmt256023 = c.m_frustum.__get(0);
		haxor.math.Vector3 __temp_stmt256024 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256024 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		haxor.math.Vector3 n0 = __temp_stmt256024.Set4(__temp_stmt256023);
		haxor.math.Vector4 __temp_stmt256025 = c.m_frustum.__get(1);
		haxor.math.Vector3 __temp_stmt256026 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt256026 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
		}
		
		haxor.math.Vector3 n1 = __temp_stmt256026.Set4(__temp_stmt256025);
		haxor.math.Vector4 __temp_stmt256027 = c.m_frustum.__get(2);
		haxor.math.Vector3 __temp_stmt256028 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt256028 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
		}
		
		haxor.math.Vector3 n2 = __temp_stmt256028.Set4(__temp_stmt256027);
		haxor.math.Vector4 __temp_stmt256029 = c.m_frustum.__get(3);
		haxor.math.Vector3 __temp_stmt256030 = null;
		{
			haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
			__temp_stmt256030 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
		}
		
		haxor.math.Vector3 n3 = __temp_stmt256030.Set4(__temp_stmt256029);
		haxor.math.Vector4 __temp_stmt256031 = c.m_frustum.__get(4);
		haxor.math.Vector3 __temp_stmt256032 = null;
		{
			haxor.context.DataContext _this4 = haxor.context.EngineContext.data;
			__temp_stmt256032 = _this4.m_v3.__get(_this4.m_nv3 = ( (( _this4.m_nv3 + 1 )) % _this4.m_v3.length ));
		}
		
		haxor.math.Vector3 f0 = __temp_stmt256032.Set4(__temp_stmt256031);
		haxor.math.Vector4 __temp_stmt256033 = c.m_frustum.__get(5);
		haxor.math.Vector3 __temp_stmt256034 = null;
		{
			haxor.context.DataContext _this5 = haxor.context.EngineContext.data;
			__temp_stmt256034 = _this5.m_v3.__get(_this5.m_nv3 = ( (( _this5.m_nv3 + 1 )) % _this5.m_v3.length ));
		}
		
		haxor.math.Vector3 f1 = __temp_stmt256034.Set4(__temp_stmt256033);
		haxor.math.Vector4 __temp_stmt256035 = c.m_frustum.__get(6);
		haxor.math.Vector3 __temp_stmt256036 = null;
		{
			haxor.context.DataContext _this6 = haxor.context.EngineContext.data;
			__temp_stmt256036 = _this6.m_v3.__get(_this6.m_nv3 = ( (( _this6.m_nv3 + 1 )) % _this6.m_v3.length ));
		}
		
		haxor.math.Vector3 f2 = __temp_stmt256036.Set4(__temp_stmt256035);
		haxor.math.Vector4 __temp_stmt256037 = c.m_frustum.__get(7);
		haxor.math.Vector3 __temp_stmt256038 = null;
		{
			haxor.context.DataContext _this7 = haxor.context.EngineContext.data;
			__temp_stmt256038 = _this7.m_v3.__get(_this7.m_nv3 = ( (( _this7.m_nv3 + 1 )) % _this7.m_v3.length ));
		}
		
		haxor.math.Vector3 f3 = __temp_stmt256038.Set4(__temp_stmt256037);
		{
			haxor.math.Matrix4 _this8 = c.m_entity.m_transform.get_WorldMatrix();
			double vx = ( ( ( ( _this8.m00 * n0.x ) + ( _this8.m01 * n0.y ) ) + ( _this8.m02 * n0.z ) ) + _this8.m03 );
			double vy = ( ( ( ( _this8.m10 * n0.x ) + ( _this8.m11 * n0.y ) ) + ( _this8.m12 * n0.z ) ) + _this8.m13 );
			double vz = ( ( ( ( _this8.m20 * n0.x ) + ( _this8.m21 * n0.y ) ) + ( _this8.m22 * n0.z ) ) + _this8.m23 );
			n0.x = vx;
			n0.y = vy;
			n0.z = vz;
			haxor.math.Vector3 __temp_expr256039 = n0;
		}
		
		{
			haxor.math.Matrix4 _this9 = c.m_entity.m_transform.get_WorldMatrix();
			double vx1 = ( ( ( ( _this9.m00 * n1.x ) + ( _this9.m01 * n1.y ) ) + ( _this9.m02 * n1.z ) ) + _this9.m03 );
			double vy1 = ( ( ( ( _this9.m10 * n1.x ) + ( _this9.m11 * n1.y ) ) + ( _this9.m12 * n1.z ) ) + _this9.m13 );
			double vz1 = ( ( ( ( _this9.m20 * n1.x ) + ( _this9.m21 * n1.y ) ) + ( _this9.m22 * n1.z ) ) + _this9.m23 );
			n1.x = vx1;
			n1.y = vy1;
			n1.z = vz1;
			haxor.math.Vector3 __temp_expr256040 = n1;
		}
		
		{
			haxor.math.Matrix4 _this10 = c.m_entity.m_transform.get_WorldMatrix();
			double vx2 = ( ( ( ( _this10.m00 * n2.x ) + ( _this10.m01 * n2.y ) ) + ( _this10.m02 * n2.z ) ) + _this10.m03 );
			double vy2 = ( ( ( ( _this10.m10 * n2.x ) + ( _this10.m11 * n2.y ) ) + ( _this10.m12 * n2.z ) ) + _this10.m13 );
			double vz2 = ( ( ( ( _this10.m20 * n2.x ) + ( _this10.m21 * n2.y ) ) + ( _this10.m22 * n2.z ) ) + _this10.m23 );
			n2.x = vx2;
			n2.y = vy2;
			n2.z = vz2;
			haxor.math.Vector3 __temp_expr256041 = n2;
		}
		
		{
			haxor.math.Matrix4 _this11 = c.m_entity.m_transform.get_WorldMatrix();
			double vx3 = ( ( ( ( _this11.m00 * n3.x ) + ( _this11.m01 * n3.y ) ) + ( _this11.m02 * n3.z ) ) + _this11.m03 );
			double vy3 = ( ( ( ( _this11.m10 * n3.x ) + ( _this11.m11 * n3.y ) ) + ( _this11.m12 * n3.z ) ) + _this11.m13 );
			double vz3 = ( ( ( ( _this11.m20 * n3.x ) + ( _this11.m21 * n3.y ) ) + ( _this11.m22 * n3.z ) ) + _this11.m23 );
			n3.x = vx3;
			n3.y = vy3;
			n3.z = vz3;
			haxor.math.Vector3 __temp_expr256042 = n3;
		}
		
		{
			haxor.math.Matrix4 _this12 = c.m_entity.m_transform.get_WorldMatrix();
			double vx4 = ( ( ( ( _this12.m00 * f0.x ) + ( _this12.m01 * f0.y ) ) + ( _this12.m02 * f0.z ) ) + _this12.m03 );
			double vy4 = ( ( ( ( _this12.m10 * f0.x ) + ( _this12.m11 * f0.y ) ) + ( _this12.m12 * f0.z ) ) + _this12.m13 );
			double vz4 = ( ( ( ( _this12.m20 * f0.x ) + ( _this12.m21 * f0.y ) ) + ( _this12.m22 * f0.z ) ) + _this12.m23 );
			f0.x = vx4;
			f0.y = vy4;
			f0.z = vz4;
			haxor.math.Vector3 __temp_expr256043 = f0;
		}
		
		{
			haxor.math.Matrix4 _this13 = c.m_entity.m_transform.get_WorldMatrix();
			double vx5 = ( ( ( ( _this13.m00 * f1.x ) + ( _this13.m01 * f1.y ) ) + ( _this13.m02 * f1.z ) ) + _this13.m03 );
			double vy5 = ( ( ( ( _this13.m10 * f1.x ) + ( _this13.m11 * f1.y ) ) + ( _this13.m12 * f1.z ) ) + _this13.m13 );
			double vz5 = ( ( ( ( _this13.m20 * f1.x ) + ( _this13.m21 * f1.y ) ) + ( _this13.m22 * f1.z ) ) + _this13.m23 );
			f1.x = vx5;
			f1.y = vy5;
			f1.z = vz5;
			haxor.math.Vector3 __temp_expr256044 = f1;
		}
		
		{
			haxor.math.Matrix4 _this14 = c.m_entity.m_transform.get_WorldMatrix();
			double vx6 = ( ( ( ( _this14.m00 * f2.x ) + ( _this14.m01 * f2.y ) ) + ( _this14.m02 * f2.z ) ) + _this14.m03 );
			double vy6 = ( ( ( ( _this14.m10 * f2.x ) + ( _this14.m11 * f2.y ) ) + ( _this14.m12 * f2.z ) ) + _this14.m13 );
			double vz6 = ( ( ( ( _this14.m20 * f2.x ) + ( _this14.m21 * f2.y ) ) + ( _this14.m22 * f2.z ) ) + _this14.m23 );
			f2.x = vx6;
			f2.y = vy6;
			f2.z = vz6;
			haxor.math.Vector3 __temp_expr256045 = f2;
		}
		
		{
			haxor.math.Matrix4 _this15 = c.m_entity.m_transform.get_WorldMatrix();
			double vx7 = ( ( ( ( _this15.m00 * f3.x ) + ( _this15.m01 * f3.y ) ) + ( _this15.m02 * f3.z ) ) + _this15.m03 );
			double vy7 = ( ( ( ( _this15.m10 * f3.x ) + ( _this15.m11 * f3.y ) ) + ( _this15.m12 * f3.z ) ) + _this15.m13 );
			double vz7 = ( ( ( ( _this15.m20 * f3.x ) + ( _this15.m21 * f3.y ) ) + ( _this15.m22 * f3.z ) ) + _this15.m23 );
			f3.x = vx7;
			f3.y = vy7;
			f3.z = vz7;
			haxor.math.Vector3 __temp_expr256046 = f3;
		}
		
		haxor.math.Vector3 __temp_stmt256047 = null;
		{
			haxor.context.DataContext _this16 = haxor.context.EngineContext.data;
			__temp_stmt256047 = _this16.m_v3.__get(_this16.m_nv3 = ( (( _this16.m_nv3 + 1 )) % _this16.m_v3.length ));
		}
		
		haxor.math.Vector3 pmin = __temp_stmt256047.Set(n0.x, n0.y, n0.z);
		haxor.math.Vector3 __temp_stmt256048 = null;
		{
			haxor.context.DataContext _this17 = haxor.context.EngineContext.data;
			__temp_stmt256048 = _this17.m_v3.__get(_this17.m_nv3 = ( (( _this17.m_nv3 + 1 )) % _this17.m_v3.length ));
		}
		
		haxor.math.Vector3 pmax = __temp_stmt256048.Set(n0.x, n0.y, n0.z);
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
					double b23 = java.lang.Math.max(f2.x, f3.x);
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
					double b26 = java.lang.Math.max(f2.y, f3.y);
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
					double b29 = java.lang.Math.max(f2.z, f3.z);
					b28 = java.lang.Math.max(f1.z, b29);
				}
				
				b27 = java.lang.Math.max(f0.z, b28);
			}
			
			pmax.z = java.lang.Math.max(pmax.z, b27);
		}
		
		this.UpdateSAP(c.__fcid, c, pmin, pmax);
	}
	
	
	public   void UpdateSAP(int p_id, java.lang.Object p_d, haxor.math.Vector3 p_min, haxor.math.Vector3 p_max)
	{
		this.sap_dirty = true;
		this.sap.Update(p_id, p_d, p_min, p_max);
	}
	
	
	public   boolean IsSAPCulled(haxor.component.Renderer r, haxor.component.Camera c)
	{
		if ( ! (r.m_has_mesh) ) 
		{
			return false;
		}
		
		haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
		return this.sap.Overlap(mr.__fcid, c.__fcid);
	}
	
	
	public   void Destroy(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
		{
			int v = r.__cid;
			this.rid.m_cache.push(v);
			int __temp_expr256049 = v;
		}
		
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			{
				int v1 = mr.__fcid;
				this.fcid.m_cache.push(v1);
				int __temp_expr256050 = v1;
			}
			
			this.sap.Remove(mr.__fcid);
		}
		
	}
	
	
	public   int DisplayListSort(haxor.component.Renderer a, haxor.component.Renderer b)
	{
		if (( a == null )) 
		{
			if (( b == null )) 
			{
				return 0;
			}
			
		}
		
		if (( a == null )) 
		{
			return 1;
		}
		
		if (( b == null )) 
		{
			return -1;
		}
		
		if (( a.m_material == null )) 
		{
			if (( b.m_material == null )) 
			{
				return 0;
			}
			
		}
		
		if (( a.m_material == null )) 
		{
			return 1;
		}
		
		if (( b.m_material == null )) 
		{
			return -1;
		}
		
		haxor.graphics.material.Material ma = a.m_material;
		haxor.graphics.material.Material mb = b.m_material;
		int ia = ma.queue;
		int ib = mb.queue;
		if (( ia != ib )) 
		{
			if (( ia < ib )) 
			{
				return -1;
			}
			 else 
			{
				return 1;
			}
			
		}
		
		if ( ! (a.m_has_mesh) ) 
		{
			if ( ! (b.m_has_mesh) ) 
			{
				return 0;
			}
			
		}
		
		if ( ! (a.m_has_mesh) ) 
		{
			return 1;
		}
		
		if ( ! (b.m_has_mesh) ) 
		{
			return -1;
		}
		
		haxor.component.MeshRenderer mra = ((haxor.component.MeshRenderer) (a) );
		haxor.component.MeshRenderer mrb = ((haxor.component.MeshRenderer) (b) );
		if (( mra.m_material.get_uid() < mrb.m_material.get_uid() )) 
		{
			return -1;
		}
		
		if (( mra.m_material.get_uid() > mrb.m_material.get_uid() )) 
		{
			return 1;
		}
		
		if (( mra.m_mesh == null )) 
		{
			if (( mrb.m_mesh == null )) 
			{
				return 0;
			}
			
		}
		
		if (( mra.m_mesh == null )) 
		{
			return 1;
		}
		
		if (( mrb.m_mesh == null )) 
		{
			return -1;
		}
		
		if (( mra.m_mesh.get_uid() < mrb.m_mesh.get_uid() )) 
		{
			return -1;
		}
		
		if (( mra.m_mesh.get_uid() > mrb.m_mesh.get_uid() )) 
		{
			return 1;
		}
		
		return 0;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256051 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef256051 = false;
						this.deferred_offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef256051 = false;
						this.deferred_culling = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256051) 
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
			boolean __temp_executeDef256052 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef256052 = false;
						this.deferred_offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef256052 = false;
						this.rid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef256052 = false;
						this.deferred_culling = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3137176:
				{
					if (field.equals("fcid")) 
					{
						__temp_executeDef256052 = false;
						this.fcid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef256052 = false;
						this.skinning = ((haxor.graphics.texture.ComputeTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef256052 = false;
						this.display = ((haxe.root.Array<haxor.context.Process>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef256052 = false;
						this.sort = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113634:
				{
					if (field.equals("sap")) 
					{
						__temp_executeDef256052 = false;
						this.sap = ((haxor.ds.SAP) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1013395147:
				{
					if (field.equals("sap_dirty")) 
					{
						__temp_executeDef256052 = false;
						this.sap_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256052) 
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
			boolean __temp_executeDef256053 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) );
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef256053 = false;
						return this.rid;
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 3137176:
				{
					if (field.equals("fcid")) 
					{
						__temp_executeDef256053 = false;
						return this.fcid;
					}
					
					break;
				}
				
				
				case -1518609943:
				{
					if (field.equals("IsSAPCulled")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsSAPCulled"))) );
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef256053 = false;
						return this.display;
					}
					
					break;
				}
				
				
				case 54756921:
				{
					if (field.equals("UpdateSAP")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateSAP"))) );
					}
					
					break;
				}
				
				
				case 113634:
				{
					if (field.equals("sap")) 
					{
						__temp_executeDef256053 = false;
						return this.sap;
					}
					
					break;
				}
				
				
				case -133505132:
				{
					if (field.equals("UpdateCameraSAP")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateCameraSAP"))) );
					}
					
					break;
				}
				
				
				case -1013395147:
				{
					if (field.equals("sap_dirty")) 
					{
						__temp_executeDef256053 = false;
						return this.sap_dirty;
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef256053 = false;
						return this.sort;
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef256053 = false;
						return this.skinning;
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateDisplayList"))) );
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef256053 = false;
						return this.deferred_culling;
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnLayerChange"))) );
					}
					
					break;
				}
				
				
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef256053 = false;
						return this.deferred_offset;
					}
					
					break;
				}
				
				
				case -610139087:
				{
					if (field.equals("DeferredCulling")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeferredCulling"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnVisibilityChange"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMeshChange"))) );
					}
					
					break;
				}
				
				
				case 1529056006:
				{
					if (field.equals("AddCamera")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddCamera"))) );
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMaterialChange"))) );
					}
					
					break;
				}
				
				
				case -1164867351:
				{
					if (field.equals("RemoveCamera")) 
					{
						__temp_executeDef256053 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveCamera"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256053) 
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
			boolean __temp_executeDef256054 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef256054 = false;
						return ((double) (this.deferred_offset) );
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef256054 = false;
						return ((double) (this.deferred_culling) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256054) 
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
			boolean __temp_executeDef256055 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef256055 = false;
						return this.DisplayListSort(((haxor.component.Renderer) (dynargs.__get(0)) ), ((haxor.component.Renderer) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef256055 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef256055 = false;
						this.Destroy(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef256055 = false;
						this.Create(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1518609943:
				{
					if (field.equals("IsSAPCulled")) 
					{
						__temp_executeDef256055 = false;
						return this.IsSAPCulled(((haxor.component.Renderer) (dynargs.__get(0)) ), ((haxor.component.Camera) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1529056006:
				{
					if (field.equals("AddCamera")) 
					{
						__temp_executeDef256055 = false;
						this.AddCamera(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 54756921:
				{
					if (field.equals("UpdateSAP")) 
					{
						__temp_executeDef256055 = false;
						this.UpdateSAP(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1), ((haxor.math.Vector3) (dynargs.__get(2)) ), ((haxor.math.Vector3) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -1164867351:
				{
					if (field.equals("RemoveCamera")) 
					{
						__temp_executeDef256055 = false;
						this.RemoveCamera(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -133505132:
				{
					if (field.equals("UpdateCameraSAP")) 
					{
						__temp_executeDef256055 = false;
						this.UpdateCameraSAP(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef256055 = false;
						this.OnMaterialChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef256055 = false;
						this.Disable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef256055 = false;
						this.OnMeshChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef256055 = false;
						this.Enable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef256055 = false;
						this.OnVisibilityChange(((haxor.component.Renderer) (dynargs.__get(0)) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef256055 = false;
						this.UpdateDisplayList(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -610139087:
				{
					if (field.equals("DeferredCulling")) 
					{
						__temp_executeDef256055 = false;
						return this.DeferredCulling(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef256055 = false;
						this.OnLayerChange(((haxor.component.Renderer) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256055) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("deferred_offset");
		baseArr.push("deferred_culling");
		baseArr.push("skinning");
		baseArr.push("sort");
		baseArr.push("sap_dirty");
		baseArr.push("sap");
		baseArr.push("display");
		baseArr.push("fcid");
		baseArr.push("rid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


