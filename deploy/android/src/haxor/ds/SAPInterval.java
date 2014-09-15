package haxor.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class SAPInterval extends haxe.lang.HxObject
{
	public    SAPInterval(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    SAPInterval()
	{
		haxor.ds.SAPInterval.__hx_ctor_haxor_ds_SAPInterval(this);
	}
	
	
	public static   void __hx_ctor_haxor_ds_SAPInterval(haxor.ds.SAPInterval __temp_me255415)
	{
		__temp_me255415.min = 0.0;
		__temp_me255415.max = 0.0;
		__temp_me255415.id = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.ds.SAPInterval(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.ds.SAPInterval();
	}
	
	
	public  int id;
	
	public  double min;
	
	public  double max;
	
	public  haxor.ds.SAPInterval next;
	
	public  haxor.ds.SAPInterval prev;
	
	public  java.lang.Object data;
	
	public   void Set(double p_min, double p_max)
	{
		this.min = p_min;
		this.max = p_max;
	}
	
	
	public   boolean Overlap(haxor.ds.SAPInterval p_interval)
	{
		if (( p_interval.min > this.min )) 
		{
			return ( p_interval.min <= this.max );
		}
		
		return ( p_interval.max >= this.min );
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places255414 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt256089 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255414) ));
			double __temp_stmt256090 = 0.0;
			{
				double p_v = ( this.min * d );
				__temp_stmt256090 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256089 = ( __temp_stmt256090 / d );
		}
		
		double __temp_stmt256091 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255414) ));
			double __temp_stmt256092 = 0.0;
			{
				double p_v1 = ( this.max * d1 );
				__temp_stmt256092 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256091 = ( __temp_stmt256092 / d1 );
		}
		
		return ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt256089) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256091) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256093 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256093 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256093 = false;
						this.id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef256093 = false;
						this.max = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef256093 = false;
						this.min = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256093) 
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
			boolean __temp_executeDef256094 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256094 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256094 = false;
						this.id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3449395:
				{
					if (field.equals("prev")) 
					{
						__temp_executeDef256094 = false;
						this.prev = ((haxor.ds.SAPInterval) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef256094 = false;
						this.min = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef256094 = false;
						this.next = ((haxor.ds.SAPInterval) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef256094 = false;
						this.max = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256094) 
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
			boolean __temp_executeDef256095 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256095 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256095 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 573365287:
				{
					if (field.equals("Overlap")) 
					{
						__temp_executeDef256095 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Overlap"))) );
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef256095 = false;
						return this.min;
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256095 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef256095 = false;
						return this.max;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256095 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef256095 = false;
						return this.next;
					}
					
					break;
				}
				
				
				case 3449395:
				{
					if (field.equals("prev")) 
					{
						__temp_executeDef256095 = false;
						return this.prev;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256095) 
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
			boolean __temp_executeDef256096 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256096 = false;
						return ((double) (haxe.lang.Runtime.toDouble(this.data)) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256096 = false;
						return ((double) (this.id) );
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef256096 = false;
						return this.max;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef256096 = false;
						return this.min;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256096) 
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
			boolean __temp_executeDef256097 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256097 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256097 = false;
						this.Set(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 573365287:
				{
					if (field.equals("Overlap")) 
					{
						__temp_executeDef256097 = false;
						return this.Overlap(((haxor.ds.SAPInterval) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256097) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("data");
		baseArr.push("prev");
		baseArr.push("next");
		baseArr.push("max");
		baseArr.push("min");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


