package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CameraOrbitInput extends haxor.component.Behaviour implements haxor.core.IUpdateable
{
	public    CameraOrbitInput(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    CameraOrbitInput(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.CameraOrbitInput.__hx_ctor_haxor_component_CameraOrbitInput(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_CameraOrbitInput(haxor.component.CameraOrbitInput __temp_me164155, java.lang.String p_name)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me164155, p_name);
		__temp_me164155.rotateSpeed = 15.0;
		__temp_me164155.zoomSpeed = 10.0;
		__temp_me164155.zoom = true;
		__temp_me164155.rotate = true;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.CameraOrbitInput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.CameraOrbitInput(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  boolean rotate;
	
	public  boolean zoom;
	
	public  double zoomSpeed;
	
	public  double rotateSpeed;
	
	public  haxor.component.CameraOrbit m_orbit;
	
	@Override public   void OnStart()
	{
		this.m_orbit = ((haxor.component.CameraOrbit) (this.m_entity.GetComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.CameraOrbit.class) )) ))) );
	}
	
	
	public   void OnUpdate()
	{
		double dx = 0.0;
		if (( haxor.input.Input.get_touches().length == 1 )) 
		{
			dx = haxor.input.Input.get_touches().__get(0).delta.x;
		}
		 else 
		{
			dx = haxor.input.Input.deltaMouse.x;
		}
		
		double dy = 0.0;
		if (( haxor.input.Input.get_touches().length == 1 )) 
		{
			dy = haxor.input.Input.get_touches().__get(0).delta.y;
		}
		 else 
		{
			dy = haxor.input.Input.deltaMouse.y;
		}
		
		if (this.rotate) 
		{
			boolean is_rotate = ( haxor.input.Input.Pressed(haxor.input.KeyCode.Mouse0) || ( haxor.input.Input.get_touches().length == 1 ) );
			if (is_rotate) 
			{
				this.m_orbit.angle.x += ( (  - (dx)  * this.rotateSpeed ) * haxor.core.Time.m_delta );
				this.m_orbit.angle.y += ( ( dy * this.rotateSpeed ) * haxor.core.Time.m_delta );
			}
			
		}
		
		if (this.zoom) 
		{
			if (( java.lang.Math.abs(haxor.input.Input.wheel) > 0 )) 
			{
				this.m_orbit.distance += ( (( (( haxor.input.Input.wheel < 0 )) ? (this.zoomSpeed) : ( - (this.zoomSpeed) ) )) * haxor.core.Time.m_delta );
			}
			
			if (( haxor.input.Input.get_touches().length == 2 )) 
			{
				this.m_orbit.distance -= ( ( ( haxor.input.Input.get_touches().__get(0).delta.y * this.zoomSpeed ) * 0.05 ) * haxor.core.Time.m_delta );
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164689 = true;
			switch (field.hashCode())
			{
				case 1853248428:
				{
					if (field.equals("rotateSpeed")) 
					{
						__temp_executeDef164689 = false;
						this.rotateSpeed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1641633844:
				{
					if (field.equals("zoomSpeed")) 
					{
						__temp_executeDef164689 = false;
						this.zoomSpeed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164689) 
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
			boolean __temp_executeDef164690 = true;
			switch (field.hashCode())
			{
				case 779427320:
				{
					if (field.equals("m_orbit")) 
					{
						__temp_executeDef164690 = false;
						this.m_orbit = ((haxor.component.CameraOrbit) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -925180581:
				{
					if (field.equals("rotate")) 
					{
						__temp_executeDef164690 = false;
						this.rotate = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1853248428:
				{
					if (field.equals("rotateSpeed")) 
					{
						__temp_executeDef164690 = false;
						this.rotateSpeed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3744723:
				{
					if (field.equals("zoom")) 
					{
						__temp_executeDef164690 = false;
						this.zoom = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1641633844:
				{
					if (field.equals("zoomSpeed")) 
					{
						__temp_executeDef164690 = false;
						this.zoomSpeed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164690) 
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
			boolean __temp_executeDef164691 = true;
			switch (field.hashCode())
			{
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef164691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -925180581:
				{
					if (field.equals("rotate")) 
					{
						__temp_executeDef164691 = false;
						return this.rotate;
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef164691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case 3744723:
				{
					if (field.equals("zoom")) 
					{
						__temp_executeDef164691 = false;
						return this.zoom;
					}
					
					break;
				}
				
				
				case 779427320:
				{
					if (field.equals("m_orbit")) 
					{
						__temp_executeDef164691 = false;
						return this.m_orbit;
					}
					
					break;
				}
				
				
				case 1641633844:
				{
					if (field.equals("zoomSpeed")) 
					{
						__temp_executeDef164691 = false;
						return this.zoomSpeed;
					}
					
					break;
				}
				
				
				case 1853248428:
				{
					if (field.equals("rotateSpeed")) 
					{
						__temp_executeDef164691 = false;
						return this.rotateSpeed;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164691) 
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
			boolean __temp_executeDef164692 = true;
			switch (field.hashCode())
			{
				case 1853248428:
				{
					if (field.equals("rotateSpeed")) 
					{
						__temp_executeDef164692 = false;
						return this.rotateSpeed;
					}
					
					break;
				}
				
				
				case 1641633844:
				{
					if (field.equals("zoomSpeed")) 
					{
						__temp_executeDef164692 = false;
						return this.zoomSpeed;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164692) 
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
			boolean __temp_executeDef164693 = true;
			switch (field.hashCode())
			{
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef164693 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef164693 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164693) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_orbit");
		baseArr.push("rotateSpeed");
		baseArr.push("zoomSpeed");
		baseArr.push("zoom");
		baseArr.push("rotate");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


