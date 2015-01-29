package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FloatKeyFrame extends haxor.component.animation.KeyFrame
{
	static 
	{
		haxor.component.animation.FloatKeyFrame.m_temp = new haxor.component.animation.FloatKeyFrame();
	}
	public    FloatKeyFrame(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    FloatKeyFrame()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.component.animation.FloatKeyFrame.__hx_ctor_haxor_component_animation_FloatKeyFrame(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_FloatKeyFrame(haxor.component.animation.FloatKeyFrame __temp_me63)
	{
		haxor.component.animation.KeyFrame.__hx_ctor_haxor_component_animation_KeyFrame(__temp_me63);
		__temp_me63.value = ((double) (0) );
	}
	
	
	public static  haxor.component.animation.FloatKeyFrame m_temp;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.FloatKeyFrame(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.FloatKeyFrame();
	}
	
	
	public  double value;
	
	@Override public   haxor.component.animation.KeyFrame Blend(haxor.component.animation.KeyFrame b, double r)
	{
		this.changed = false;
		haxor.component.animation.FloatKeyFrame ka = this;
		haxor.component.animation.FloatKeyFrame kb = ((haxor.component.animation.FloatKeyFrame) (b) );
		double va = ka.value;
		double vb = kb.value;
		if (( java.lang.Math.abs(( va - vb )) < 0.0001 )) 
		{
			return ka;
		}
		
		haxor.component.animation.FloatKeyFrame k = haxor.component.animation.FloatKeyFrame.m_temp;
		{
			double p_a = ka.value;
			k.value = ( p_a + ( (( kb.value - p_a )) * r ) );
		}
		
		k.changed = true;
		return k;
	}
	
	
	@Override public   java.lang.Object Sample(java.lang.Object v, java.lang.Object w)
	{
		double __temp_w62 = ( (( w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(w)) )) );
		if (( v == null )) 
		{
			return this.value;
		}
		 else 
		{
			double p_a = ((double) (haxe.lang.Runtime.toDouble(v)) );
			return ( p_a + ( (( this.value - p_a )) * __temp_w62 ) );
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef709 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef709 = false;
						this.value = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef709) 
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
			boolean __temp_executeDef710 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef710 = false;
						this.value = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef710) 
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
			boolean __temp_executeDef711 = true;
			switch (field.hashCode())
			{
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef711 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef711 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 64270385:
				{
					if (field.equals("Blend")) 
					{
						__temp_executeDef711 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Blend"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef711) 
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
			boolean __temp_executeDef712 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef712 = false;
						return this.value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef712) 
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
		baseArr.push("value");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


