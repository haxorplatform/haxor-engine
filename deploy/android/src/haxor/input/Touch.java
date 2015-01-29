package haxor.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Touch extends haxe.lang.HxObject
{
	public    Touch(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Touch()
	{
		haxor.input.Touch.__hx_ctor_haxor_input_Touch(this);
	}
	
	
	public static   void __hx_ctor_haxor_input_Touch(haxor.input.Touch __temp_me272)
	{
		__temp_me272.state = haxor.core.InputState.None;
		__temp_me272.id = -1;
		__temp_me272.position = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me272.delta = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me272.relativePosition = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me272.pressure = ((double) (0) );
		__temp_me272.hold = ((double) (0) );
		__temp_me272.angle = ((double) (0) );
		__temp_me272.radius = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me272.m_down = false;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.Touch(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.Touch();
	}
	
	
	public  haxor.core.InputState state;
	
	public  int id;
	
	public  haxor.math.Vector2 position;
	
	public  haxor.math.Vector2 radius;
	
	public  double angle;
	
	public  haxor.math.Vector2 relativePosition;
	
	public  haxor.math.Vector2 delta;
	
	public  double pressure;
	
	public  double hold;
	
	public  boolean m_down;
	
	public   java.lang.String ToString()
	{
		return ( ( ( ( ( ( "id[" + this.id ) + "] pos" ) + this.position.ToString(2) ) + "[" ) + haxe.root.Std.string(this.state) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1083 = true;
			switch (field.hashCode())
			{
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef1083 = false;
						this.hold = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1083 = false;
						this.id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1276242363:
				{
					if (field.equals("pressure")) 
					{
						__temp_executeDef1083 = false;
						this.pressure = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef1083 = false;
						this.angle = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1083) 
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
			boolean __temp_executeDef1084 = true;
			switch (field.hashCode())
			{
				case -1083565772:
				{
					if (field.equals("m_down")) 
					{
						__temp_executeDef1084 = false;
						this.m_down = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef1084 = false;
						this.state = ((haxor.core.InputState) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef1084 = false;
						this.hold = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1084 = false;
						this.id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1276242363:
				{
					if (field.equals("pressure")) 
					{
						__temp_executeDef1084 = false;
						this.pressure = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef1084 = false;
						this.position = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 95468472:
				{
					if (field.equals("delta")) 
					{
						__temp_executeDef1084 = false;
						this.delta = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef1084 = false;
						this.radius = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1733258261:
				{
					if (field.equals("relativePosition")) 
					{
						__temp_executeDef1084 = false;
						this.relativePosition = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef1084 = false;
						this.angle = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1084) 
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
			boolean __temp_executeDef1085 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef1085 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef1085 = false;
						return this.state;
					}
					
					break;
				}
				
				
				case -1083565772:
				{
					if (field.equals("m_down")) 
					{
						__temp_executeDef1085 = false;
						return this.m_down;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1085 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef1085 = false;
						return this.hold;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef1085 = false;
						return this.position;
					}
					
					break;
				}
				
				
				case -1276242363:
				{
					if (field.equals("pressure")) 
					{
						__temp_executeDef1085 = false;
						return this.pressure;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef1085 = false;
						return this.radius;
					}
					
					break;
				}
				
				
				case 95468472:
				{
					if (field.equals("delta")) 
					{
						__temp_executeDef1085 = false;
						return this.delta;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef1085 = false;
						return this.angle;
					}
					
					break;
				}
				
				
				case 1733258261:
				{
					if (field.equals("relativePosition")) 
					{
						__temp_executeDef1085 = false;
						return this.relativePosition;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1085) 
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
			boolean __temp_executeDef1086 = true;
			switch (field.hashCode())
			{
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef1086 = false;
						return this.hold;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1086 = false;
						return ((double) (this.id) );
					}
					
					break;
				}
				
				
				case -1276242363:
				{
					if (field.equals("pressure")) 
					{
						__temp_executeDef1086 = false;
						return this.pressure;
					}
					
					break;
				}
				
				
				case 92960979:
				{
					if (field.equals("angle")) 
					{
						__temp_executeDef1086 = false;
						return this.angle;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1086) 
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
			boolean __temp_executeDef1087 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef1087 = false;
						return this.ToString();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1087) 
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
		baseArr.push("m_down");
		baseArr.push("hold");
		baseArr.push("pressure");
		baseArr.push("delta");
		baseArr.push("relativePosition");
		baseArr.push("angle");
		baseArr.push("radius");
		baseArr.push("position");
		baseArr.push("id");
		baseArr.push("state");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


