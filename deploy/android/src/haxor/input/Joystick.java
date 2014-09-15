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
	
	
	public static   void __hx_ctor_haxor_input_Joystick(haxor.input.Joystick __temp_me255493)
	{
		haxor.core.InputState st = haxor.core.InputState.None;
		__temp_me255493.name = "";
		__temp_me255493.id = -1;
		__temp_me255493.button = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me255493.state = new haxe.root.Array<haxor.core.InputState>(new haxor.core.InputState[]{st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st});
		__temp_me255493.hold = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me255493.analog = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )});
		__temp_me255493.analogLeft = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me255493.analogRight = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		__temp_me255493.triggerLeft = 0.0;
		__temp_me255493.triggerRight = 0.0;
		__temp_me255493.m_vibrationLeft = 0.0;
		__temp_me255493.m_vibrationRight = 0.0;
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
	
	
	
	public final   double get_vibrationLeft()
	{
		return this.m_vibrationLeft;
	}
	
	
	public   double set_vibrationLeft(double v)
	{
		double __temp_stmt256206 = 0.0;
		{
			double p_a = ( this.m_vibrationLeft - v );
			__temp_stmt256206 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt256206 <= 0.0 )) 
		{
			return v;
		}
		
		this.m_vibrationLeft = v;
		haxor.input.Input.m_handler.RequestJoystickVibration(this);
		return v;
	}
	
	
	public  double m_vibrationLeft;
	
	
	
	public final   double get_vibrationRight()
	{
		return this.m_vibrationRight;
	}
	
	
	public   double set_vibrationRight(double v)
	{
		double __temp_stmt256207 = 0.0;
		{
			double p_a = ( this.m_vibrationRight - v );
			__temp_stmt256207 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt256207 <= 0.0 )) 
		{
			return v;
		}
		
		this.m_vibrationRight = v;
		haxor.input.Input.m_handler.RequestJoystickVibration(this);
		return v;
	}
	
	
	public  double m_vibrationRight;
	
	public   boolean Pressed(int p_button)
	{
		return ( ( this.state.__get(p_button) == haxor.core.InputState.Hold ) || ( this.state.__get(p_button) == haxor.core.InputState.Down ) );
	}
	
	
	public   boolean Down(int p_button)
	{
		return ( this.state.__get(p_button) == haxor.core.InputState.Down );
	}
	
	
	public   boolean Hit(int p_button)
	{
		return ( this.state.__get(p_button) == haxor.core.InputState.Up );
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_analog, java.lang.Object p_button, java.lang.Object p_trigger, java.lang.Object p_pad)
	{
		boolean __temp_p_pad255492 = ( (( p_pad == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_pad)) );
		boolean __temp_p_trigger255491 = ( (( p_trigger == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_trigger)) );
		boolean __temp_p_button255490 = ( (( p_button == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_button)) );
		boolean __temp_p_analog255489 = ( (( p_analog == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_analog)) );
		java.lang.String s = "";
		s += ( "J" + this.id );
		if (__temp_p_analog255489) 
		{
			s += ( " AL" + this.analogLeft.ToString(1) );
			s += ( " AR" + this.analogRight.ToString(1) );
		}
		
		if (__temp_p_button255490) 
		{
			s += ( " A[" + (( (this.Pressed(haxor.input.KeyCode.ButtonA)) ? ("1]") : ("0]") )) );
			s += ( " B[" + (( (this.Pressed(haxor.input.KeyCode.ButtonB)) ? ("1]") : ("0]") )) );
			s += ( " X[" + (( (this.Pressed(haxor.input.KeyCode.ButtonX)) ? ("1]") : ("0]") )) );
			s += ( " Y[" + (( (this.Pressed(haxor.input.KeyCode.ButtonY)) ? ("1]") : ("0]") )) );
			s += ( " L[" + (( (this.Pressed(haxor.input.KeyCode.LeftShoulder)) ? ("1]") : ("0]") )) );
			s += ( " R[" + (( (this.Pressed(haxor.input.KeyCode.RightShoulder)) ? ("1]") : ("0]") )) );
			s += ( " LB[" + (( (this.Pressed(haxor.input.KeyCode.LeftShoulderBottom)) ? ("1]") : ("0]") )) );
			s += ( " RB[" + (( (this.Pressed(haxor.input.KeyCode.RightShoulderBottom)) ? ("1]") : ("0]") )) );
			s += ( " Start[" + (( (this.Pressed(haxor.input.KeyCode.ButtonStart)) ? ("1]") : ("0]") )) );
			s += ( " Select[" + (( (this.Pressed(haxor.input.KeyCode.ButtonSelect)) ? ("1]") : ("0]") )) );
		}
		
		if (__temp_p_pad255492) 
		{
			s += ( " PL[" + (( (this.Pressed(haxor.input.KeyCode.PadLeft)) ? ("1]") : ("0]") )) );
			s += ( " PR[" + (( (this.Pressed(haxor.input.KeyCode.PadRight)) ? ("1]") : ("0]") )) );
			s += ( " PU[" + (( (this.Pressed(haxor.input.KeyCode.PadTop)) ? ("1]") : ("0]") )) );
			s += ( " PD[" + (( (this.Pressed(haxor.input.KeyCode.PadBottom)) ? ("1]") : ("0]") )) );
		}
		
		if (__temp_p_trigger255491) 
		{
			double __temp_stmt256208 = 0.0;
			{
				double d = java.lang.Math.pow(((double) (10) ), ((double) (1) ));
				double __temp_stmt256209 = 0.0;
				{
					double p_v = ( this.triggerLeft * d );
					__temp_stmt256209 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
				}
				
				__temp_stmt256208 = ( __temp_stmt256209 / d );
			}
			
			s += ( ( " TL[" + haxe.lang.Runtime.toString(__temp_stmt256208) ) + "]" );
			double __temp_stmt256210 = 0.0;
			{
				double d1 = java.lang.Math.pow(((double) (10) ), ((double) (1) ));
				double __temp_stmt256211 = 0.0;
				{
					double p_v1 = ( this.triggerRight * d1 );
					__temp_stmt256211 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
				}
				
				__temp_stmt256210 = ( __temp_stmt256211 / d1 );
			}
			
			s += ( ( " TR[" + haxe.lang.Runtime.toString(__temp_stmt256210) ) + "]" );
		}
		
		return s;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256212 = true;
			switch (field.hashCode())
			{
				case -1647800132:
				{
					if (field.equals("m_vibrationRight")) 
					{
						__temp_executeDef256212 = false;
						this.m_vibrationRight = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256212 = false;
						this.id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 977316522:
				{
					if (field.equals("vibrationRight")) 
					{
						__temp_executeDef256212 = false;
						this.set_vibrationRight(value);
						return value;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef256212 = false;
						this.triggerLeft = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1438810777:
				{
					if (field.equals("m_vibrationLeft")) 
					{
						__temp_executeDef256212 = false;
						this.m_vibrationLeft = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef256212 = false;
						this.triggerRight = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1769771591:
				{
					if (field.equals("vibrationLeft")) 
					{
						__temp_executeDef256212 = false;
						this.set_vibrationLeft(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256212) 
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
			boolean __temp_executeDef256213 = true;
			switch (field.hashCode())
			{
				case -1647800132:
				{
					if (field.equals("m_vibrationRight")) 
					{
						__temp_executeDef256213 = false;
						this.m_vibrationRight = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256213 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 977316522:
				{
					if (field.equals("vibrationRight")) 
					{
						__temp_executeDef256213 = false;
						this.set_vibrationRight(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256213 = false;
						this.id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1438810777:
				{
					if (field.equals("m_vibrationLeft")) 
					{
						__temp_executeDef256213 = false;
						this.m_vibrationLeft = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1377687758:
				{
					if (field.equals("button")) 
					{
						__temp_executeDef256213 = false;
						this.button = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1769771591:
				{
					if (field.equals("vibrationLeft")) 
					{
						__temp_executeDef256213 = false;
						this.set_vibrationLeft(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef256213 = false;
						this.state = ((haxe.root.Array<haxor.core.InputState>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef256213 = false;
						this.triggerRight = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef256213 = false;
						this.hold = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef256213 = false;
						this.triggerLeft = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1413355280:
				{
					if (field.equals("analog")) 
					{
						__temp_executeDef256213 = false;
						this.analog = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 124714764:
				{
					if (field.equals("analogRight")) 
					{
						__temp_executeDef256213 = false;
						this.analogRight = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1243085545:
				{
					if (field.equals("analogLeft")) 
					{
						__temp_executeDef256213 = false;
						this.analogLeft = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256213) 
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
			boolean __temp_executeDef256214 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256214 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 72563:
				{
					if (field.equals("Hit")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Hit"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256214 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 2136258:
				{
					if (field.equals("Down")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Down"))) );
					}
					
					break;
				}
				
				
				case -1377687758:
				{
					if (field.equals("button")) 
					{
						__temp_executeDef256214 = false;
						return this.button;
					}
					
					break;
				}
				
				
				case 1346388994:
				{
					if (field.equals("Pressed")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Pressed"))) );
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef256214 = false;
						return this.state;
					}
					
					break;
				}
				
				
				case -1647800132:
				{
					if (field.equals("m_vibrationRight")) 
					{
						__temp_executeDef256214 = false;
						return this.m_vibrationRight;
					}
					
					break;
				}
				
				
				case 3208383:
				{
					if (field.equals("hold")) 
					{
						__temp_executeDef256214 = false;
						return this.hold;
					}
					
					break;
				}
				
				
				case -380449753:
				{
					if (field.equals("set_vibrationRight")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_vibrationRight"))) );
					}
					
					break;
				}
				
				
				case -1413355280:
				{
					if (field.equals("analog")) 
					{
						__temp_executeDef256214 = false;
						return this.analog;
					}
					
					break;
				}
				
				
				case -1300483405:
				{
					if (field.equals("get_vibrationRight")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vibrationRight"))) );
					}
					
					break;
				}
				
				
				case -1243085545:
				{
					if (field.equals("analogLeft")) 
					{
						__temp_executeDef256214 = false;
						return this.analogLeft;
					}
					
					break;
				}
				
				
				case 977316522:
				{
					if (field.equals("vibrationRight")) 
					{
						__temp_executeDef256214 = false;
						return this.get_vibrationRight();
					}
					
					break;
				}
				
				
				case 124714764:
				{
					if (field.equals("analogRight")) 
					{
						__temp_executeDef256214 = false;
						return this.analogRight;
					}
					
					break;
				}
				
				
				case -1438810777:
				{
					if (field.equals("m_vibrationLeft")) 
					{
						__temp_executeDef256214 = false;
						return this.m_vibrationLeft;
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef256214 = false;
						return this.triggerLeft;
					}
					
					break;
				}
				
				
				case 1511565468:
				{
					if (field.equals("set_vibrationLeft")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_vibrationLeft"))) );
					}
					
					break;
				}
				
				
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef256214 = false;
						return this.triggerRight;
					}
					
					break;
				}
				
				
				case -1843249008:
				{
					if (field.equals("get_vibrationLeft")) 
					{
						__temp_executeDef256214 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vibrationLeft"))) );
					}
					
					break;
				}
				
				
				case -1769771591:
				{
					if (field.equals("vibrationLeft")) 
					{
						__temp_executeDef256214 = false;
						return this.get_vibrationLeft();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256214) 
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
			boolean __temp_executeDef256215 = true;
			switch (field.hashCode())
			{
				case -1647800132:
				{
					if (field.equals("m_vibrationRight")) 
					{
						__temp_executeDef256215 = false;
						return this.m_vibrationRight;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256215 = false;
						return ((double) (this.id) );
					}
					
					break;
				}
				
				
				case 977316522:
				{
					if (field.equals("vibrationRight")) 
					{
						__temp_executeDef256215 = false;
						return this.get_vibrationRight();
					}
					
					break;
				}
				
				
				case -681194017:
				{
					if (field.equals("triggerLeft")) 
					{
						__temp_executeDef256215 = false;
						return this.triggerLeft;
					}
					
					break;
				}
				
				
				case -1438810777:
				{
					if (field.equals("m_vibrationLeft")) 
					{
						__temp_executeDef256215 = false;
						return this.m_vibrationLeft;
					}
					
					break;
				}
				
				
				case 363482948:
				{
					if (field.equals("triggerRight")) 
					{
						__temp_executeDef256215 = false;
						return this.triggerRight;
					}
					
					break;
				}
				
				
				case -1769771591:
				{
					if (field.equals("vibrationLeft")) 
					{
						__temp_executeDef256215 = false;
						return this.get_vibrationLeft();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256215) 
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
			boolean __temp_executeDef256216 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256216 = false;
						return this.ToString(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3));
					}
					
					break;
				}
				
				
				case -1843249008:
				{
					if (field.equals("get_vibrationLeft")) 
					{
						__temp_executeDef256216 = false;
						return this.get_vibrationLeft();
					}
					
					break;
				}
				
				
				case 72563:
				{
					if (field.equals("Hit")) 
					{
						__temp_executeDef256216 = false;
						return this.Hit(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1511565468:
				{
					if (field.equals("set_vibrationLeft")) 
					{
						__temp_executeDef256216 = false;
						return this.set_vibrationLeft(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2136258:
				{
					if (field.equals("Down")) 
					{
						__temp_executeDef256216 = false;
						return this.Down(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1300483405:
				{
					if (field.equals("get_vibrationRight")) 
					{
						__temp_executeDef256216 = false;
						return this.get_vibrationRight();
					}
					
					break;
				}
				
				
				case 1346388994:
				{
					if (field.equals("Pressed")) 
					{
						__temp_executeDef256216 = false;
						return this.Pressed(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -380449753:
				{
					if (field.equals("set_vibrationRight")) 
					{
						__temp_executeDef256216 = false;
						return this.set_vibrationRight(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256216) 
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
		baseArr.push("m_vibrationRight");
		baseArr.push("vibrationRight");
		baseArr.push("m_vibrationLeft");
		baseArr.push("vibrationLeft");
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


