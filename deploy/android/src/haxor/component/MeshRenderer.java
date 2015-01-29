package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshRenderer extends haxor.component.Renderer
{
	public    MeshRenderer(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    MeshRenderer(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.MeshRenderer.__hx_ctor_haxor_component_MeshRenderer(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_MeshRenderer(haxor.component.MeshRenderer __temp_me39, java.lang.String p_name)
	{
		haxor.component.Renderer.__hx_ctor_haxor_component_Renderer(__temp_me39, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.MeshRenderer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.MeshRenderer(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  int __fcid;
	
	
	
	public final   haxor.graphics.mesh.Mesh get_mesh()
	{
		return this.m_mesh;
	}
	
	
	public   haxor.graphics.mesh.Mesh set_mesh(haxor.graphics.mesh.Mesh v)
	{
		if (( this.m_mesh == v )) 
		{
			return v;
		}
		
		this.m_mesh = v;
		this.UpdateWorldBounds();
		return v;
	}
	
	
	public  haxor.graphics.mesh.Mesh m_mesh;
	
	public  haxor.math.Vector3 m_ws_center;
	
	public  haxor.math.Vector3 m_ws_radius;
	
	public  boolean m_culling_dirty;
	
	@Override public   void OnBuild()
	{
		this.m_has_mesh = true;
		super.OnBuild();
		this.m_ws_center = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		this.m_ws_radius = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		this.m_culling_dirty = false;
	}
	
	
	public   boolean IsVisible(haxor.component.Camera p_camera)
	{
		haxor.component.Camera c = p_camera;
		if (( c == null )) 
		{
			return false;
		}
		
		if (( this.m_mesh == null )) 
		{
			return false;
		}
		
		haxor.math.Vector3 __temp_stmt641 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt641 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt640 = __temp_stmt641.Set3(this.m_ws_center);
		haxor.math.Vector4 __temp_stmt642 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt642 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		haxor.math.Vector4 ps_center = c.WorldToProjection(__temp_stmt640, __temp_stmt642);
		double w = ps_center.w;
		haxor.math.Vector4 p = ps_center;
		if (( w <= 0.0 )) 
		{
			return false;
		}
		
		if (( p.x >=  - (w)  )) 
		{
			if (( p.x <= w )) 
			{
				if (( p.y >=  - (w)  )) 
				{
					if (( p.y <= w )) 
					{
						if (( p.z >=  - (w)  )) 
						{
							if (( p.z <= w )) 
							{
								return true;
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
		haxor.math.Vector3 __temp_stmt644 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt644 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt643 = __temp_stmt644.Set3(this.m_ws_radius);
		haxor.math.Vector4 __temp_stmt645 = null;
		{
			haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
			__temp_stmt645 = _this3.m_v4.__get(_this3.m_nv4 = ( (( _this3.m_nv4 + 1 )) % _this3.m_v4.length ));
		}
		
		haxor.math.Vector4 v = c.WorldToProjection(__temp_stmt643, __temp_stmt645);
		double r = java.lang.Math.sqrt(( ( ( ( v.x * v.x ) + ( v.y * v.y ) ) + ( v.z * v.z ) ) + ( v.w * v.w ) ));
		if (( ( p.x + r ) >=  - (w)  )) 
		{
			if (( ( p.x - r ) <= w )) 
			{
				if (( ( p.y + r ) >=  - (w)  )) 
				{
					if (( ( p.y - r ) <= w )) 
					{
						if (( ( p.z + r ) >=  - (w)  )) 
						{
							if (( ( p.z - r ) <= w )) 
							{
								return true;
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
		return false;
	}
	
	
	@Override public   boolean CheckCulling()
	{
		haxor.component.Camera c = haxor.component.Camera.m_current;
		if (( c == null )) 
		{
			return this.m_culled;
		}
		
		if ( ! (c.m_view_uniform_dirty) ) 
		{
			if ( ! (c.m_proj_uniform_dirty) ) 
			{
				if ( ! (this.m_culling_dirty) ) 
				{
					return this.m_culled;
				}
				
			}
			
		}
		
		this.UpdateWorldBounds();
		return  ! (this.IsVisible(c)) ;
	}
	
	
	@Override public   void OnTransformUpdate()
	{
		this.m_culling_dirty = true;
	}
	
	
	public   void UpdateWorldBounds()
	{
		if (( this.m_mesh != null )) 
		{
			haxor.math.AABB3.Center(this.m_mesh.m_bounds, this.m_ws_center);
			{
				haxor.math.Matrix4 _this = this.m_entity.m_transform.get_WorldMatrix();
				haxor.math.Vector3 p_point = this.m_ws_center;
				double vx = ( ( ( ( _this.m00 * p_point.x ) + ( _this.m01 * p_point.y ) ) + ( _this.m02 * p_point.z ) ) + _this.m03 );
				double vy = ( ( ( ( _this.m10 * p_point.x ) + ( _this.m11 * p_point.y ) ) + ( _this.m12 * p_point.z ) ) + _this.m13 );
				double vz = ( ( ( ( _this.m20 * p_point.x ) + ( _this.m21 * p_point.y ) ) + ( _this.m22 * p_point.z ) ) + _this.m23 );
				p_point.x = vx;
				p_point.y = vy;
				p_point.z = vz;
				haxor.math.Vector3 __temp_expr646 = p_point;
			}
			
			double __temp_stmt647 = 0.0;
			{
				haxor.math.AABB3 _this1 = this.m_mesh.m_bounds;
				{
					double p_a = ( _this1.m_xMax - _this1.m_xMin );
					__temp_stmt647 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
				}
				
			}
			
			double __temp_stmt648 = 0.0;
			{
				haxor.math.AABB3 _this2 = this.m_mesh.m_bounds;
				{
					double p_a1 = ( _this2.m_yMax - _this2.m_yMin );
					__temp_stmt648 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
				}
				
			}
			
			double __temp_stmt649 = 0.0;
			{
				haxor.math.AABB3 _this3 = this.m_mesh.m_bounds;
				{
					double p_a2 = ( _this3.m_zMax - _this3.m_zMin );
					__temp_stmt649 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
				}
				
			}
			
			this.m_ws_radius.Set(__temp_stmt647, __temp_stmt648, __temp_stmt649);
			{
				haxor.math.Matrix4 _this4 = this.m_entity.m_transform.get_WorldMatrix();
				haxor.math.Vector3 p_point1 = this.m_ws_radius;
				double vx1 = ( ( ( _this4.m00 * p_point1.x ) + ( _this4.m01 * p_point1.y ) ) + ( _this4.m02 * p_point1.z ) );
				double vy1 = ( ( ( _this4.m10 * p_point1.x ) + ( _this4.m11 * p_point1.y ) ) + ( _this4.m12 * p_point1.z ) );
				double vz1 = ( ( ( _this4.m20 * p_point1.x ) + ( _this4.m21 * p_point1.y ) ) + ( _this4.m22 * p_point1.z ) );
				p_point1.x = vx1;
				p_point1.y = vy1;
				p_point1.z = vz1;
				haxor.math.Vector3 __temp_expr650 = p_point1;
			}
			
			double r = 0.0;
			{
				haxor.math.Vector3 _this5 = this.m_ws_radius;
				r = java.lang.Math.sqrt(( ( ( _this5.x * _this5.x ) + ( _this5.y * _this5.y ) ) + ( _this5.z * _this5.z ) ));
			}
			
			haxor.math.Vector3 pmin = null;
			{
				haxor.context.DataContext _this6 = haxor.context.EngineContext.data;
				pmin = _this6.m_v3.__get(_this6.m_nv3 = ( (( _this6.m_nv3 + 1 )) % _this6.m_v3.length ));
			}
			
			haxor.math.Vector3 pmax = null;
			{
				haxor.context.DataContext _this7 = haxor.context.EngineContext.data;
				pmax = _this7.m_v3.__get(_this7.m_nv3 = ( (( _this7.m_nv3 + 1 )) % _this7.m_v3.length ));
			}
			
			pmin.Set(( this.m_ws_center.x - r ), ( this.m_ws_center.y - r ), ( this.m_ws_center.z - r ));
			pmax.Set(( this.m_ws_center.x + r ), ( this.m_ws_center.y + r ), ( this.m_ws_center.z + r ));
			haxor.context.EngineContext.renderer.UpdateSAP(this.__fcid, this, pmin, pmax);
			this.m_culling_dirty = false;
		}
		
	}
	
	
	@Override public   void OnRender()
	{
		super.OnRender();
		if (( this.m_mesh == null )) 
		{
			return ;
		}
		
		haxor.graphics.Graphics.Render(this.m_mesh, this.m_material, this.m_entity.m_transform, haxor.component.Camera.m_current);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef651 = true;
			switch (field.hashCode())
			{
				case -1484326280:
				{
					if (field.equals("__fcid")) 
					{
						__temp_executeDef651 = false;
						this.__fcid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef651) 
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
			boolean __temp_executeDef652 = true;
			switch (field.hashCode())
			{
				case 391182257:
				{
					if (field.equals("m_culling_dirty")) 
					{
						__temp_executeDef652 = false;
						this.m_culling_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1484326280:
				{
					if (field.equals("__fcid")) 
					{
						__temp_executeDef652 = false;
						this.__fcid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 202785283:
				{
					if (field.equals("m_ws_radius")) 
					{
						__temp_executeDef652 = false;
						this.m_ws_radius = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef652 = false;
						this.set_mesh(((haxor.graphics.mesh.Mesh) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -222649914:
				{
					if (field.equals("m_ws_center")) 
					{
						__temp_executeDef652 = false;
						this.m_ws_center = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083307393:
				{
					if (field.equals("m_mesh")) 
					{
						__temp_executeDef652 = false;
						this.m_mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef652) 
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
			boolean __temp_executeDef653 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case -1484326280:
				{
					if (field.equals("__fcid")) 
					{
						__temp_executeDef653 = false;
						return this.__fcid;
					}
					
					break;
				}
				
				
				case -1017704386:
				{
					if (field.equals("UpdateWorldBounds")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateWorldBounds"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef653 = false;
						return this.get_mesh();
					}
					
					break;
				}
				
				
				case 1899224918:
				{
					if (field.equals("OnTransformUpdate")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTransformUpdate"))) );
					}
					
					break;
				}
				
				
				case 1976460598:
				{
					if (field.equals("get_mesh")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mesh"))) );
					}
					
					break;
				}
				
				
				case 1224889128:
				{
					if (field.equals("CheckCulling")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckCulling"))) );
					}
					
					break;
				}
				
				
				case 1415348138:
				{
					if (field.equals("set_mesh")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_mesh"))) );
					}
					
					break;
				}
				
				
				case 1890932680:
				{
					if (field.equals("IsVisible")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsVisible"))) );
					}
					
					break;
				}
				
				
				case -1083307393:
				{
					if (field.equals("m_mesh")) 
					{
						__temp_executeDef653 = false;
						return this.m_mesh;
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef653 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -222649914:
				{
					if (field.equals("m_ws_center")) 
					{
						__temp_executeDef653 = false;
						return this.m_ws_center;
					}
					
					break;
				}
				
				
				case 391182257:
				{
					if (field.equals("m_culling_dirty")) 
					{
						__temp_executeDef653 = false;
						return this.m_culling_dirty;
					}
					
					break;
				}
				
				
				case 202785283:
				{
					if (field.equals("m_ws_radius")) 
					{
						__temp_executeDef653 = false;
						return this.m_ws_radius;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef653) 
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
			boolean __temp_executeDef654 = true;
			switch (field.hashCode())
			{
				case -1484326280:
				{
					if (field.equals("__fcid")) 
					{
						__temp_executeDef654 = false;
						return ((double) (this.__fcid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef654) 
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
			int __temp_hash656 = field.hashCode();
			boolean __temp_executeDef655 = true;
			switch (__temp_hash656)
			{
				case 1528462453:case 1899224918:case 1224889128:case 312095663:
				{
					if (( (( ( __temp_hash656 == 1528462453 ) && field.equals("OnRender") )) || ( (( ( __temp_hash656 == 1899224918 ) && field.equals("OnTransformUpdate") )) || ( (( ( __temp_hash656 == 1224889128 ) && field.equals("CheckCulling") )) || field.equals("OnBuild") ) ) )) 
					{
						__temp_executeDef655 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1976460598:
				{
					if (field.equals("get_mesh")) 
					{
						__temp_executeDef655 = false;
						return this.get_mesh();
					}
					
					break;
				}
				
				
				case -1017704386:
				{
					if (field.equals("UpdateWorldBounds")) 
					{
						__temp_executeDef655 = false;
						this.UpdateWorldBounds();
					}
					
					break;
				}
				
				
				case 1415348138:
				{
					if (field.equals("set_mesh")) 
					{
						__temp_executeDef655 = false;
						return this.set_mesh(((haxor.graphics.mesh.Mesh) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1890932680:
				{
					if (field.equals("IsVisible")) 
					{
						__temp_executeDef655 = false;
						return this.IsVisible(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef655) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_culling_dirty");
		baseArr.push("m_ws_radius");
		baseArr.push("m_ws_center");
		baseArr.push("m_mesh");
		baseArr.push("mesh");
		baseArr.push("__fcid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


