package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CameraOrbit extends haxor.component.Behaviour implements haxor.core.IUpdateable
{
	public    CameraOrbit(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    CameraOrbit(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.CameraOrbit.__hx_ctor_haxor_component_CameraOrbit(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_CameraOrbit(haxor.component.CameraOrbit __temp_me255348, java.lang.String p_name)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me255348, p_name);
	}
	
	
	public static   haxor.component.CameraOrbit Create(java.lang.Object p_distance, java.lang.Object p_angle_x, java.lang.Object p_angle_y)
	{
		double __temp_p_angle_y255347 = ( (( p_angle_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_angle_y)) )) );
		double __temp_p_angle_x255346 = ( (( p_angle_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_angle_x)) )) );
		double __temp_p_distance255345 = ( (( p_distance == null )) ? (((double) (1) )) : (((double) (haxe.lang.Runtime.toDouble(p_distance)) )) );
		haxor.core.Entity e = new haxor.core.Entity(haxe.lang.Runtime.toString(null));
		e.set_name("camera_orbit");
		haxor.component.Camera c = ((haxor.component.Camera) (e.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.Camera.class) )) ))) );
		c.background = new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		haxor.component.CameraOrbit orbit = ((haxor.component.CameraOrbit) (e.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.CameraOrbit.class) )) ))) );
		orbit.distance = __temp_p_distance255345;
		orbit.smooth = ((double) (0) );
		orbit.angle = new haxor.math.Vector2(((java.lang.Object) (__temp_p_angle_x255346) ), ((java.lang.Object) (__temp_p_angle_y255347) ));
		return orbit;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.CameraOrbit(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.CameraOrbit(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   haxor.component.Transform get_pivot()
	{
		if (( this.m_pivot == null )) 
		{
			haxor.core.Entity e = new haxor.core.Entity(haxe.lang.Runtime.toString(null));
			this.m_pivot = e.m_transform;
			this.m_pivot.set_name(this.m_entity.get_name());
			this.m_pivot.set_parent(this.m_entity.m_transform.m_parent);
			this.m_entity.m_transform.set_parent(this.m_pivot);
			this.m_entity.set_name("camera");
			this.m_pivot.set_position(this.m_entity.m_transform.get_position());
		}
		
		return this.m_pivot;
	}
	
	
	public  haxor.component.Transform m_pivot;
	
	public  double distance;
	
	public  haxor.math.Vector2 angle;
	
	public  double smooth;
	
	public  haxor.component.Transform target;
	
	public  haxor.math.Vector2 m_angle;
	
	public  double m_distance;
	
	public  haxor.math.Quaternion m_rotation;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		this.distance = 0.0;
		this.m_pivot = this.get_pivot();
	}
	
	
	@Override public   void OnStart()
	{
		this.m_distance = this.distance;
		if (( this.angle == null )) 
		{
			this.m_angle = new haxor.math.Vector2(((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		}
		 else 
		{
			haxor.math.Vector2 _this = this.angle;
			this.m_angle = new haxor.math.Vector2(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ));
		}
		
		this.m_rotation = new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
		haxor.math.Vector3 p = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			p = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
		}
		
		p.Set(0, 0, this.m_distance);
		this.m_entity.m_transform.set_localPosition(p);
	}
	
	
	public   void OnUpdate()
	{
		double blend = 0.0;
		if (( this.smooth <= 0 )) 
		{
			blend = 1.0;
		}
		 else 
		{
			blend = ( haxor.core.Time.m_delta * this.smooth );
		}
		
		{
			double p_a = this.m_angle.x;
			this.m_angle.x = ( p_a + ( (( this.angle.x - p_a )) * blend ) );
		}
		
		{
			double p_a1 = this.m_angle.y;
			this.m_angle.y = ( p_a1 + ( (( this.angle.y - p_a1 )) * blend ) );
		}
		
		{
			double p_a2 = this.m_distance;
			this.m_distance = ( p_a2 + ( (( this.distance - p_a2 )) * blend ) );
		}
		
		haxor.math.Quaternion q = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			q = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		q.SetAxisAngle(new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) )), this.m_angle.x);
		haxor.math.Vector3 __temp_stmt255875 = new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		haxor.math.Quaternion __temp_stmt255876 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt255876 = _this1.m_q.__get(_this1.m_nq = ( (( _this1.m_nq + 1 )) % _this1.m_q.length ));
		}
		
		q.Multiply(__temp_stmt255876.SetAxisAngle(__temp_stmt255875,  - (this.m_angle.y) ), null);
		this.get_pivot().set_localRotation(q);
		haxor.math.Vector3 p = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			p = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
		}
		
		p.Set(0, 0, this.m_distance);
		this.m_entity.m_transform.set_localPosition(p);
		if (( this.target != null )) 
		{
			haxor.math.Vector3 p1 = this.get_pivot().get_localPosition();
			p1 = haxor.math.Vector3.Lerp(p1, this.target.get_localPosition(), ( haxor.core.Time.m_delta * this.smooth ), null);
			this.get_pivot().set_localPosition(p1);
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255877 = true;
			switch (field.hashCode())
			{
				case 433842055:
				{
					if (field.equals("m_distance")) 
					{
						__temp_executeDef255877 = false;
						this.m_distance = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 288459765:
				{
					if (field.equals("distance")) 
					{
						__temp_executeDef255877 = false;
						this.distance = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -898533970:
				{
					if (field.equals("smooth")) 
					{
						__temp_executeDef255877 = false;
						this.smooth = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255877) 
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
			boolean __temp_executeDef255878 = true;
			switch (field.hashCode())
			{
				case 105081616:
				{
					if (field.equals("m_rotation")) 
					{
						__temp_executeDef255878 = false;
						this.m_rotation = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 780102128:
				{
					if (field.equals("m_pivot")) 
					{
						__temp_executeDef255878 = false;
						this.m_pivot = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 433842055:
				{
					if (field.equals("m_distance")) 
					{
						__temp_executeDef255878 = false;
						this.m_distance = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 288459765:
				{
					if (field.equals("distance")) 
					{
						__temp_executeDef255878 = false;
						this.distance = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 766383745:
				{
					if (field.equals("m_angle")) 
					{
						__temp_executeDef255878 = false;
						this.m_angle = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef255878 = false;
						this.angle = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef255878 = false;
						this.target = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -898533970:
				{
					if (field.equals("smooth")) 
					{
						__temp_executeDef255878 = false;
						this.smooth = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255878) 
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
			boolean __temp_executeDef255879 = true;
			switch (field.hashCode())
			{
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef255879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case 106679362:
				{
					if (field.equals("pivot")) 
					{
						__temp_executeDef255879 = false;
						return this.get_pivot();
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef255879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case 1143629337:
				{
					if (field.equals("get_pivot")) 
					{
						__temp_executeDef255879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_pivot"))) );
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef255879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case 780102128:
				{
					if (field.equals("m_pivot")) 
					{
						__temp_executeDef255879 = false;
						return this.m_pivot;
					}
					
					break;
				}
				
				
				case 105081616:
				{
					if (field.equals("m_rotation")) 
					{
						__temp_executeDef255879 = false;
						return this.m_rotation;
					}
					
					break;
				}
				
				
				case 288459765:
				{
					if (field.equals("distance")) 
					{
						__temp_executeDef255879 = false;
						return this.distance;
					}
					
					break;
				}
				
				
				case 433842055:
				{
					if (field.equals("m_distance")) 
					{
						__temp_executeDef255879 = false;
						return this.m_distance;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef255879 = false;
						return this.angle;
					}
					
					break;
				}
				
				
				case 766383745:
				{
					if (field.equals("m_angle")) 
					{
						__temp_executeDef255879 = false;
						return this.m_angle;
					}
					
					break;
				}
				
				
				case -898533970:
				{
					if (field.equals("smooth")) 
					{
						__temp_executeDef255879 = false;
						return this.smooth;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef255879 = false;
						return this.target;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255879) 
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
			boolean __temp_executeDef255880 = true;
			switch (field.hashCode())
			{
				case 433842055:
				{
					if (field.equals("m_distance")) 
					{
						__temp_executeDef255880 = false;
						return this.m_distance;
					}
					
					break;
				}
				
				
				case 288459765:
				{
					if (field.equals("distance")) 
					{
						__temp_executeDef255880 = false;
						return this.distance;
					}
					
					break;
				}
				
				
				case -898533970:
				{
					if (field.equals("smooth")) 
					{
						__temp_executeDef255880 = false;
						return this.smooth;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255880) 
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
			int __temp_hash255882 = field.hashCode();
			boolean __temp_executeDef255881 = true;
			switch (__temp_hash255882)
			{
				case 327758243:case 312095663:
				{
					if (( (( ( __temp_hash255882 == 327758243 ) && field.equals("OnStart") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef255881 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1143629337:
				{
					if (field.equals("get_pivot")) 
					{
						__temp_executeDef255881 = false;
						return this.get_pivot();
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef255881 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255881) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_rotation");
		baseArr.push("m_distance");
		baseArr.push("m_angle");
		baseArr.push("target");
		baseArr.push("smooth");
		baseArr.push("angle");
		baseArr.push("distance");
		baseArr.push("m_pivot");
		baseArr.push("pivot");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


