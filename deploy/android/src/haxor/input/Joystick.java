package haxor.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Joystick extends haxe.lang.HxObject
{
	static 
	{
		haxor.input.Joystick.analogBias = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.1) ), ((java.lang.Object) (0.9) )});
		haxor.input.Joystick.buttonBias = 0.9;
		haxor.input.Joystick.available = false;
	}
	public    Joystick(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Joystick()
	{
		haxor.input.Joystick.__hx_ctor_haxor_input_Joystick(this);
	}
	
	
	public static   void __hx_ctor_haxor_input_Joystick(haxor.input.Joystick __temp_me151436)
	{
		haxor.core.InputState st = haxor.core.InputState.None;
		__temp_me151436.name = "";
		__temp_me151436.id = -1;
		__temp_me151436.button = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me151436.state = new haxe.root.Array<haxor.core.InputState>(new haxor.core.InputState[]{st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st});
		__temp_me151436.hold = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me151436.analog = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me151436.analogLeft = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me151436.analogRight = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me151436.triggerLeft = 0.0;
		__temp_me151436.triggerRight = 0.0;
	}
	
	
	public static  haxe.root.Array<java.lang.Object> analogBias;
	
	public static  double buttonBias;
	
	public static  boolean available;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.Joystick(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.Joystick();
	}
	
	
	public  java.lang.String name;
	
	public  int id;
	
	public  haxe.root.Array<java.lang.Object> button;
	
	public  haxe.root.Array<haxor.core.InputState> state;
	
	public  haxe.root.Array<java.lang.Object> hold;
	
	public  haxe.root.Array<java.lang.Object> analog;
	
	public  haxor.math.Vector3 analogLeft;
	
	public  haxor.math.Vector3 analogRight;
	
	public  double triggerLeft;
	
	public  double triggerRight;
	
	public   boolean IsDown(int p_button)
	{
		return ( ( this.state.__get(p_button) == haxor.core.InputState.Hold ) || ( this.state.__get(p_button) == haxor.core.InputState.Down ) );
	}
	
	
	public   boolean Hit(int p_button)
	{
		return ( this.state.__get(p_button) == haxor.core.InputState.Up );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152205 = true;
			switch (field.hashCode())
			{
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef152205 = false;
						this.triggerRight = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152205 = false;
						this.id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef152205 = false;
						this.triggerLeft = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152205) 
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
			boolean __temp_executeDef152206 = true;
			switch (field.hashCode())
			{
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef152206 = false;
						this.triggerRight = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef152206 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef152206 = false;
						this.triggerLeft = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152206 = false;
						this.id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 124714764:
				{
					if (field.equals("analogRight")) 
					{
						__temp_executeDef152206 = false;
						this.analogRight = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1377687758:
				{
					if (field.equals("button")) 
					{
						__temp_executeDef152206 = false;
						this.button = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1243085545:
				{
					if (field.equals("analogLeft")) 
					{
						__temp_executeDef152206 = false;
						this.analogLeft = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef152206 = false;
						this.state = ((haxe.root.Array<haxor.core.InputState>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1413355280:
				{
					if (field.equals("analog")) 
					{
						__temp_executeDef152206 = false;
						this.analog = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef152206 = false;
						this.hold = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152206) 
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
			boolean __temp_executeDef152207 = true;
			switch (field.hashCode())
			{
				case 72563:
				{
					if (field.equals("Hit")) 
					{
						__temp_executeDef152207 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Hit"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef152207 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -2096698100:
				{
					if (field.equals("IsDown")) 
					{
						__temp_executeDef152207 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsDown"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152207 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef152207 = false;
						return this.triggerRight;
					}
					
					break;
				}
				
				
				case -1377687758:
				{
					if (field.equals("button")) 
					{
						__temp_executeDef152207 = false;
						return this.button;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef152207 = false;
						return this.triggerLeft;
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef152207 = false;
						return this.state;
					}
					
					break;
				}
				
				
				case 124714764:
				{
					if (field.equals("analogRight")) 
					{
						__temp_executeDef152207 = false;
						return this.analogRight;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef152207 = false;
						return this.hold;
					}
					
					break;
				}
				
				
				case -1243085545:
				{
					if (field.equals("analogLeft")) 
					{
						__temp_executeDef152207 = false;
						return this.analogLeft;
					}
					
					break;
				}
				
				
				case -1413355280:
				{
					if (field.equals("analog")) 
					{
						__temp_executeDef152207 = false;
						return this.analog;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152207) 
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
			boolean __temp_executeDef152208 = true;
			switch (field.hashCode())
			{
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef152208 = false;
						return this.triggerRight;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152208 = false;
						return ((double) (this.id) );
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef152208 = false;
						return this.triggerLeft;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152208) 
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
			boolean __temp_executeDef152209 = true;
			switch (field.hashCode())
			{
				case 72563:
				{
					if (field.equals("Hit")) 
					{
						__temp_executeDef152209 = false;
						return this.Hit(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -2096698100:
				{
					if (field.equals("IsDown")) 
					{
						__temp_executeDef152209 = false;
						return this.IsDown(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152209) 
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
		baseArr.push("triggerRight");
		baseArr.push("triggerLeft");
		baseArr.push("analogRight");
		baseArr.push("analogLeft");
		baseArr.push("analog");
		baseArr.push("hold");
		baseArr.push("state");
		baseArr.push("button");
		baseArr.push("id");
		baseArr.push("name");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


