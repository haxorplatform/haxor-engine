package haxor.component.light;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Light extends haxor.component.Behaviour
{
	static 
	{
		haxor.component.light.Light.ambient = new haxor.math.Color(((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ));
		haxor.component.light.Light.max = 8;
		haxor.component.light.Light.m_list = new haxe.root.Array<haxor.component.light.Light>(new haxor.component.light.Light[]{});
	}
	public    Light(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Light()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.light.Light.__hx_ctor_haxor_component_light_Light(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_light_Light(haxor.component.light.Light __temp_me101)
	{
		if (( haxor.component.light.Light.m_list == null )) 
		{
			haxor.component.light.Light.m_list = new haxe.root.Array<haxor.component.light.Light>(new haxor.component.light.Light[]{});
		}
		
		if (( haxor.component.light.Light.m_buffer == null )) 
		{
			haxor.component.light.Light.m_buffer = new haxor.io.FloatArray(((int) (( 12 * haxor.component.light.Light.max )) ));
		}
		
		haxor.component.light.Light.m_list.push(__temp_me101);
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me101, null);
		__temp_me101.color = new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
		__temp_me101.intensity = 1.0;
	}
	
	
	public static  haxor.math.Color ambient;
	
	public static  int max;
	
	public static  haxor.io.FloatArray m_buffer;
	
	public static  haxe.root.Array<haxor.component.light.Light> list;
	
	public static  haxe.root.Array<haxor.component.light.Light> m_list;
	
	public static   haxe.root.Array<haxor.component.light.Light> get_list()
	{
		haxe.root.Array<haxor.component.light.Light> l = new haxe.root.Array<haxor.component.light.Light>();
		if (( haxor.component.light.Light.m_list == null )) 
		{
			return l;
		}
		
		int i = 0;
		while (( i < haxor.component.light.Light.m_list.length ))
		{
			l.push(haxor.component.light.Light.m_list.__get(i));
			i++;
		}
		
		return l;
	}
	
	
	public static   void SetLightData(int p_id, double p_type, double p_intensity, double p_radius, double p_atten, double p_x, double p_y, double p_z, double p_r, double p_g, double p_b, double p_a)
	{
		int pos = ( p_id * 12 );
		haxor.component.light.Light.m_buffer.Set(pos, p_type);
		haxor.component.light.Light.m_buffer.Set(( pos + 1 ), p_intensity);
		haxor.component.light.Light.m_buffer.Set(( pos + 2 ), p_radius);
		haxor.component.light.Light.m_buffer.Set(( pos + 3 ), p_atten);
		haxor.component.light.Light.m_buffer.Set(( pos + 4 ), p_x);
		haxor.component.light.Light.m_buffer.Set(( pos + 5 ), p_y);
		haxor.component.light.Light.m_buffer.Set(( pos + 6 ), p_z);
		haxor.component.light.Light.m_buffer.Set(( pos + 8 ), p_r);
		haxor.component.light.Light.m_buffer.Set(( pos + 9 ), p_g);
		haxor.component.light.Light.m_buffer.Set(( pos + 10 ), p_b);
		haxor.component.light.Light.m_buffer.Set(( pos + 11 ), p_a);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.light.Light(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.light.Light();
	}
	
	
	public  haxor.math.Color color;
	
	public  double intensity;
	
	@Override public   void OnDestroy()
	{
		super.OnDestroy();
		haxor.component.light.Light.m_list.remove(this);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef780 = true;
			switch (field.hashCode())
			{
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef780 = false;
						this.intensity = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef780) 
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
			boolean __temp_executeDef781 = true;
			switch (field.hashCode())
			{
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef781 = false;
						this.intensity = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef781 = false;
						this.color = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef781) 
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
			boolean __temp_executeDef782 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef782 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef782 = false;
						return this.color;
					}
					
					break;
				}
				
				
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef782 = false;
						return this.intensity;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef782) 
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
			boolean __temp_executeDef783 = true;
			switch (field.hashCode())
			{
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef783 = false;
						return this.intensity;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef783) 
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
		baseArr.push("intensity");
		baseArr.push("color");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


