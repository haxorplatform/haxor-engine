package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class KeyFrame extends haxe.lang.HxObject
{
	public    KeyFrame(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    KeyFrame()
	{
		haxor.component.animation.KeyFrame.__hx_ctor_haxor_component_animation_KeyFrame(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_KeyFrame(haxor.component.animation.KeyFrame __temp_me61)
	{
		__temp_me61.time = ((double) (0) );
		__temp_me61.changed = false;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.KeyFrame(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.KeyFrame();
	}
	
	
	public  double time;
	
	public  boolean changed;
	
	public   haxor.component.animation.KeyFrame Blend(haxor.component.animation.KeyFrame b, double r)
	{
		return null;
	}
	
	
	public   java.lang.Object Sample(java.lang.Object v, java.lang.Object w)
	{
		double __temp_w60 = ( (( w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(w)) )) );
		return null;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef704 = true;
			switch (field.hashCode())
			{
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef704 = false;
						this.time = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef704) 
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
			boolean __temp_executeDef705 = true;
			switch (field.hashCode())
			{
				case 738943668:
				{
					if (field.equals("changed")) 
					{
						__temp_executeDef705 = false;
						this.changed = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef705 = false;
						this.time = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef705) 
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
			boolean __temp_executeDef706 = true;
			switch (field.hashCode())
			{
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef706 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef706 = false;
						return this.time;
					}
					
					break;
				}
				
				
				case 64270385:
				{
					if (field.equals("Blend")) 
					{
						__temp_executeDef706 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Blend"))) );
					}
					
					break;
				}
				
				
				case 738943668:
				{
					if (field.equals("changed")) 
					{
						__temp_executeDef706 = false;
						return this.changed;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef706) 
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
			boolean __temp_executeDef707 = true;
			switch (field.hashCode())
			{
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef707 = false;
						return this.time;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef707) 
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
			boolean __temp_executeDef708 = true;
			switch (field.hashCode())
			{
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef708 = false;
						return this.Sample(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 64270385:
				{
					if (field.equals("Blend")) 
					{
						__temp_executeDef708 = false;
						return this.Blend(((haxor.component.animation.KeyFrame) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef708) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("changed");
		baseArr.push("time");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


