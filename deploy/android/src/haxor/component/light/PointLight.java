package haxor.component.light;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class PointLight extends haxor.component.light.Light
{
	public    PointLight(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    PointLight()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.component.light.PointLight.__hx_ctor_haxor_component_light_PointLight(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_light_PointLight(haxor.component.light.PointLight __temp_me102)
	{
		haxor.component.light.Light.__hx_ctor_haxor_component_light_Light(__temp_me102);
		__temp_me102.atten = 1.0;
		__temp_me102.radius = 1.0;
	}
	
	
	public static   haxor.component.light.PointLight Create(haxor.math.Color p_color, double p_intensity, double p_atten, double p_radius)
	{
		haxor.core.Entity e = new haxor.core.Entity(haxe.lang.Runtime.toString(null));
		e.set_name("PointLight");
		haxor.component.light.PointLight l = ((haxor.component.light.PointLight) (e.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.light.PointLight.class) )) ))) );
		l.color = p_color;
		l.intensity = p_intensity;
		l.atten = p_atten;
		l.radius = p_radius;
		return l;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.light.PointLight(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.light.PointLight();
	}
	
	
	public  double atten;
	
	public  double radius;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef784 = true;
			switch (field.hashCode())
			{
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef784 = false;
						this.radius = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef784 = false;
						this.atten = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef784) 
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
			boolean __temp_executeDef785 = true;
			switch (field.hashCode())
			{
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef785 = false;
						this.radius = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef785 = false;
						this.atten = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef785) 
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
			boolean __temp_executeDef786 = true;
			switch (field.hashCode())
			{
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef786 = false;
						return this.radius;
					}
					
					break;
				}
				
				
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef786 = false;
						return this.atten;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef786) 
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
			boolean __temp_executeDef787 = true;
			switch (field.hashCode())
			{
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef787 = false;
						return this.radius;
					}
					
					break;
				}
				
				
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef787 = false;
						return this.atten;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef787) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("radius");
		baseArr.push("atten");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


