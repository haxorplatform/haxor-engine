package haxor.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class InputHandler extends haxe.lang.HxObject
{
	public    InputHandler(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    InputHandler()
	{
		haxor.input.InputHandler.__hx_ctor_haxor_input_InputHandler(this);
	}
	
	
	public static   void __hx_ctor_haxor_input_InputHandler(haxor.input.InputHandler __temp_me255488)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.InputHandler(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.InputHandler();
	}
	
	
	public  haxor.input.Joystick m_joystick;
	
	public   void Update()
	{
		haxor.input.Input.UpdateInput();
		haxor.input.Input.UpdateTouchFSM();
		this.UpdateInput();
		if (haxor.input.Input.emulateTouch) 
		{
			this.EmulateTouch(haxor.input.KeyCode.Mouse0, 0);
			this.EmulateTouch(haxor.input.KeyCode.Mouse1, 2);
			this.EmulateTouch(haxor.input.KeyCode.Mouse2, 1);
		}
		
	}
	
	
	public   void UpdateInput()
	{
		{
		}
		
	}
	
	
	public   void Clear()
	{
		haxor.input.Input.wheel = ((double) (0) );
		haxor.input.Input.deltaMouse.x = ((double) (0) );
		haxor.input.Input.deltaMouse.y = ((double) (0) );
	}
	
	
	public   void OnMouseMove(double p_x, double p_y)
	{
		haxor.input.Input.deltaMouse.x = ( p_x - haxor.input.Input.mouse.x );
		haxor.input.Input.deltaMouse.y = ( p_y - haxor.input.Input.mouse.y );
		haxor.input.Input.mouse.x = p_x;
		haxor.input.Input.mouse.y = p_y;
		haxor.input.Input.relativeMouse.x = ( haxor.input.Input.mouse.x / haxor.graphics.Screen.m_width );
		haxor.input.Input.relativeMouse.y = ( haxor.input.Input.mouse.y / haxor.graphics.Screen.m_height );
	}
	
	
	public   void OnMouseWheel(double p_wheel)
	{
		haxor.input.Input.wheel = p_wheel;
	}
	
	
	public   void OnMouseButton(int p_button, boolean p_down)
	{
		switch (p_button)
		{
			case 0:
			{
				haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse0, p_down, false);
				break;
			}
			
			
			case 1:
			{
				haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse1, p_down, false);
				break;
			}
			
			
			case 2:
			{
				haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse2, p_down, false);
				break;
			}
			
			
			case 3:
			{
				haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse3, p_down, false);
				break;
			}
			
			
			case 4:
			{
				haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse4, p_down, false);
				break;
			}
			
			
		}
		
	}
	
	
	public   void OnKey(int p_code, boolean p_down)
	{
		haxor.input.Input.UpdateInputState(p_code, p_down, null);
	}
	
	
	public   void OnTouchStart(int p_id, double p_x, double p_y, java.lang.Object p_rx, java.lang.Object p_ry, java.lang.Object p_pressure, java.lang.Object p_angle)
	{
		double __temp_p_angle255487 = ( (( p_angle == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_angle)) )) );
		double __temp_p_pressure255486 = ( (( p_pressure == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_pressure)) )) );
		double __temp_p_ry255485 = ( (( p_ry == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_ry)) )) );
		double __temp_p_rx255484 = ( (( p_rx == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_rx)) )) );
		haxor.input.Touch t = haxor.input.Input.m_api_touches.__get(p_id);
		t.id = p_id;
		t.position.x = p_x;
		t.position.y = p_y;
		t.relativePosition.x = ( t.position.x / haxor.graphics.Screen.m_width );
		t.relativePosition.y = ( t.position.y / haxor.graphics.Screen.m_height );
		t.delta.x = 0.0;
		t.delta.y = 0.0;
		t.pressure = __temp_p_pressure255486;
		t.radius.x = __temp_p_rx255484;
		t.radius.y = __temp_p_ry255485;
		t.angle = __temp_p_angle255487;
		t.m_down = true;
		if (( haxor.input.Input.m_touches.indexOf(t, null) < 0 )) 
		{
			haxor.input.Input.m_touches.push(t);
		}
		
	}
	
	
	public   void OnTouchMove(int p_id, double p_x, double p_y)
	{
		haxor.input.Touch t = haxor.input.Input.m_api_touches.__get(p_id);
		if (( t.id >= 0 )) 
		{
			t.delta.x = ( p_x - t.position.x );
			t.delta.y = ( p_y - t.position.y );
		}
		
		t.position.x = p_x;
		t.position.y = p_y;
		t.relativePosition.x = ( t.position.x / haxor.graphics.Screen.m_width );
		t.relativePosition.y = ( t.position.y / haxor.graphics.Screen.m_height );
	}
	
	
	public   void OnTouchCancel(int p_id)
	{
		haxor.input.Touch t = haxor.input.Input.m_api_touches.__get(p_id);
		t.m_down = false;
	}
	
	
	public   void OnTouchEnd(int p_id)
	{
		haxor.input.Touch t = haxor.input.Input.m_api_touches.__get(p_id);
		t.m_down = false;
	}
	
	
	public   void OnJoystickStart(int p_id, java.lang.String p_name)
	{
		this.m_joystick = null;
		haxor.input.Joystick jk = haxor.input.Input.m_api_joystick.__get(p_id);
		if (( jk == null )) 
		{
			return ;
		}
		
		this.m_joystick = jk;
		if (( haxor.input.Input.m_joysticks.indexOf(jk, null) >= 0 )) 
		{
			return ;
		}
		
		jk.id = p_id;
		jk.name = p_name;
		haxor.input.Input.m_joysticks.push(jk);
		haxor.input.Joystick.available = ( haxor.input.Input.m_joysticks.length > 0 );
	}
	
	
	public   void OnJoystickDataUpdate(int p_code, double p_value, boolean p_is_analog)
	{
		if (( this.m_joystick == null )) 
		{
			return ;
		}
		
		if ( ! (p_is_analog) ) 
		{
			this.m_joystick.button.__set(p_code, p_value);
			this.m_joystick.state.__set(p_code, haxor.input.Input.InputStateFSM(this.m_joystick.state.__get(p_code), ( ((double) (haxe.lang.Runtime.toDouble(this.m_joystick.button.__get(p_code))) ) >= haxor.input.Joystick.buttonBias )));
			if (( this.m_joystick.state.__get(p_code) == haxor.core.InputState.Hold )) 
			{
				haxe.root.Array<java.lang.Object> __temp_array255669 = this.m_joystick.hold;
				__temp_array255669.__set(p_code, ( ((double) (haxe.lang.Runtime.toDouble(__temp_array255669.__get(p_code))) ) + haxor.core.Time.m_delta ));
			}
			
			if (( this.m_joystick.state.__get(p_code) == haxor.core.InputState.None )) 
			{
				this.m_joystick.hold.__set(p_code, 0.0);
			}
			
		}
		 else 
		{
			this.m_joystick.analog.__set(p_code, p_value);
		}
		
	}
	
	
	public   void OnJoystickAnalogUpdate()
	{
		if (( this.m_joystick == null )) 
		{
			return ;
		}
		
		double b0 = ((double) (haxe.lang.Runtime.toDouble(haxor.input.Joystick.analogBias.__get(0))) );
		double b1 = ((double) (haxe.lang.Runtime.toDouble(haxor.input.Joystick.analogBias.__get(1))) );
		double s = 1.0;
		haxor.math.Vector3 v = null;
		haxor.input.Joystick jk = this.m_joystick;
		v = jk.analogLeft;
		v.x = ((double) (haxe.lang.Runtime.toDouble(jk.analog.__get(haxor.input.KeyCode.LeftAnalogueHor))) );
		if (( v.x < 0.0 )) 
		{
			s = -1.0;
		}
		 else 
		{
			s = 1.0;
		}
		
		{
			double p_v = 0.0;
			double __temp_stmt256198 = 0.0;
			{
				double p_a = v.x;
				__temp_stmt256198 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
			}
			
			p_v = ( (( __temp_stmt256198 - b0 )) / (( b1 - b0 )) );
			if (( p_v <= 0.0 )) 
			{
				v.x = 0.0;
			}
			 else 
			{
				if (( p_v >= 1.0 )) 
				{
					v.x = 1.0;
				}
				 else 
				{
					v.x = p_v;
				}
				
			}
			
		}
		
		v.x = ( ( s * (((double) (((int) (( v.x * 100.0 )) )) )) ) * 0.01 );
		v.y = ((double) (haxe.lang.Runtime.toDouble(jk.analog.__get(haxor.input.KeyCode.LeftAnalogueVert))) );
		if (( v.y < 0.0 )) 
		{
			s = -1.0;
		}
		 else 
		{
			s = 1.0;
		}
		
		{
			double p_v1 = 0.0;
			double __temp_stmt256199 = 0.0;
			{
				double p_a1 = v.y;
				__temp_stmt256199 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
			}
			
			p_v1 = ( (( __temp_stmt256199 - b0 )) / (( b1 - b0 )) );
			if (( p_v1 <= 0.0 )) 
			{
				v.y = 0.0;
			}
			 else 
			{
				if (( p_v1 >= 1.0 )) 
				{
					v.y = 1.0;
				}
				 else 
				{
					v.y = p_v1;
				}
				
			}
			
		}
		
		v.y = ( (  - (s)  * (((double) (((int) (( v.y * 100.0 )) )) )) ) * 0.01 );
		if (( ((double) (haxe.lang.Runtime.toDouble(jk.button.__get(haxor.input.KeyCode.LeftAnalogueStick))) ) > 0.5 )) 
		{
			v.z = 1.0;
		}
		 else 
		{
			v.z = 0.0;
		}
		
		v = jk.analogRight;
		v.x = ((double) (haxe.lang.Runtime.toDouble(jk.analog.__get(haxor.input.KeyCode.RightAnalogueHor))) );
		if (( v.x < 0.0 )) 
		{
			s = -1.0;
		}
		 else 
		{
			s = 1.0;
		}
		
		{
			double p_v2 = 0.0;
			double __temp_stmt256200 = 0.0;
			{
				double p_a2 = v.x;
				__temp_stmt256200 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
			}
			
			p_v2 = ( (( __temp_stmt256200 - b0 )) / (( b1 - b0 )) );
			if (( p_v2 <= 0.0 )) 
			{
				v.x = 0.0;
			}
			 else 
			{
				if (( p_v2 >= 1.0 )) 
				{
					v.x = 1.0;
				}
				 else 
				{
					v.x = p_v2;
				}
				
			}
			
		}
		
		v.x = ( ( s * (((double) (((int) (( v.x * 100.0 )) )) )) ) * 0.01 );
		v.y = ((double) (haxe.lang.Runtime.toDouble(jk.analog.__get(haxor.input.KeyCode.RightAnalogueVert))) );
		if (( v.y < 0.0 )) 
		{
			s = -1.0;
		}
		 else 
		{
			s = 1.0;
		}
		
		{
			double p_v3 = 0.0;
			double __temp_stmt256201 = 0.0;
			{
				double p_a3 = v.y;
				__temp_stmt256201 = ( (( p_a3 < 0 )) ? ( - (p_a3) ) : (p_a3) );
			}
			
			p_v3 = ( (( __temp_stmt256201 - b0 )) / (( b1 - b0 )) );
			if (( p_v3 <= 0.0 )) 
			{
				v.y = 0.0;
			}
			 else 
			{
				if (( p_v3 >= 1.0 )) 
				{
					v.y = 1.0;
				}
				 else 
				{
					v.y = p_v3;
				}
				
			}
			
		}
		
		v.y = ( (  - (s)  * (((double) (((int) (( v.y * 100.0 )) )) )) ) * 0.01 );
		if (( ((double) (haxe.lang.Runtime.toDouble(jk.button.__get(haxor.input.KeyCode.RightAnalogueStick))) ) > 0.5 )) 
		{
			v.z = 1.0;
		}
		 else 
		{
			v.z = 0.0;
		}
		
		jk.triggerLeft = ((double) (haxe.lang.Runtime.toDouble(jk.button.__get(haxor.input.KeyCode.LeftShoulderBottom))) );
		{
			double p_v4 = ( (( jk.triggerLeft - b0 )) / (( b1 - b0 )) );
			if (( p_v4 <= 0.0 )) 
			{
				jk.triggerLeft = 0.0;
			}
			 else 
			{
				if (( p_v4 >= 1.0 )) 
				{
					jk.triggerLeft = 1.0;
				}
				 else 
				{
					jk.triggerLeft = p_v4;
				}
				
			}
			
		}
		
		jk.triggerRight = ((double) (haxe.lang.Runtime.toDouble(jk.button.__get(haxor.input.KeyCode.RightShoulderBottom))) );
		{
			double p_v5 = ( (( jk.triggerRight - b0 )) / (( b1 - b0 )) );
			if (( p_v5 <= 0.0 )) 
			{
				jk.triggerRight = 0.0;
			}
			 else 
			{
				if (( p_v5 >= 1.0 )) 
				{
					jk.triggerRight = 1.0;
				}
				 else 
				{
					jk.triggerRight = p_v5;
				}
				
			}
			
		}
		
	}
	
	
	public   void RequestJoystickVibration(haxor.input.Joystick p_joystick)
	{
		{
		}
		
	}
	
	
	public   void EmulateTouch(int p_code, int p_id)
	{
		if (haxor.input.Input.Down(p_code)) 
		{
			haxor.math.Vector2 p = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				p = _this.m_v2.__get(_this.m_nv2 = ( (( _this.m_nv2 + 1 )) % _this.m_v2.length ));
			}
			
			switch (p_id)
			{
				case 0:
				{
					p.Set2(haxor.input.Input.mouse);
					break;
				}
				
				
				case 1:
				{
					p.Set(( haxor.graphics.Screen.m_width * 0.5 ), ( haxor.graphics.Screen.m_height * 0.5 ));
					break;
				}
				
				
				case 2:
				{
					p.Set(( haxor.graphics.Screen.m_width * java.lang.Math.random() ), ( haxor.graphics.Screen.m_height * java.lang.Math.random() ));
					break;
				}
				
				
			}
			
			this.OnTouchStart(p_id, p.x, p.y, null, null, null, null);
		}
		
		if (( p_id == 0 )) 
		{
			if (haxor.input.Input.Pressed(p_code)) 
			{
				double __temp_stmt256202 = 0.0;
				{
					haxor.math.Vector2 _this1 = haxor.input.Input.deltaMouse;
					__temp_stmt256202 = java.lang.Math.sqrt(( ( _this1.x * _this1.x ) + ( _this1.y * _this1.y ) ));
				}
				
				if (( __temp_stmt256202 > 0 )) 
				{
					this.OnTouchMove(p_id, haxor.input.Input.mouse.x, haxor.input.Input.mouse.y);
				}
				
			}
			
		}
		
		if (haxor.input.Input.Hit(p_code)) 
		{
			this.OnTouchEnd(p_id);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256203 = true;
			switch (field.hashCode())
			{
				case -792730418:
				{
					if (field.equals("m_joystick")) 
					{
						__temp_executeDef256203 = false;
						this.m_joystick = ((haxor.input.Joystick) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256203) 
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
			boolean __temp_executeDef256204 = true;
			switch (field.hashCode())
			{
				case -1333561812:
				{
					if (field.equals("EmulateTouch")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("EmulateTouch"))) );
					}
					
					break;
				}
				
				
				case -792730418:
				{
					if (field.equals("m_joystick")) 
					{
						__temp_executeDef256204 = false;
						return this.m_joystick;
					}
					
					break;
				}
				
				
				case 1696542215:
				{
					if (field.equals("RequestJoystickVibration")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RequestJoystickVibration"))) );
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case 1145357780:
				{
					if (field.equals("OnJoystickAnalogUpdate")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnJoystickAnalogUpdate"))) );
					}
					
					break;
				}
				
				
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateInput"))) );
					}
					
					break;
				}
				
				
				case -920839218:
				{
					if (field.equals("OnJoystickDataUpdate")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnJoystickDataUpdate"))) );
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 667176135:
				{
					if (field.equals("OnJoystickStart")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnJoystickStart"))) );
					}
					
					break;
				}
				
				
				case -2071726377:
				{
					if (field.equals("OnMouseMove")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseMove"))) );
					}
					
					break;
				}
				
				
				case -351112133:
				{
					if (field.equals("OnTouchEnd")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchEnd"))) );
					}
					
					break;
				}
				
				
				case 210002197:
				{
					if (field.equals("OnMouseWheel")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseWheel"))) );
					}
					
					break;
				}
				
				
				case -1805056230:
				{
					if (field.equals("OnTouchCancel")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchCancel"))) );
					}
					
					break;
				}
				
				
				case 1626355896:
				{
					if (field.equals("OnMouseButton")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseButton"))) );
					}
					
					break;
				}
				
				
				case 2000665713:
				{
					if (field.equals("OnTouchMove")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchMove"))) );
					}
					
					break;
				}
				
				
				case 76310496:
				{
					if (field.equals("OnKey")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnKey"))) );
					}
					
					break;
				}
				
				
				case 1896765378:
				{
					if (field.equals("OnTouchStart")) 
					{
						__temp_executeDef256204 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchStart"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256204) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef256205 = true;
			switch (field.hashCode())
			{
				case -1333561812:
				{
					if (field.equals("EmulateTouch")) 
					{
						__temp_executeDef256205 = false;
						this.EmulateTouch(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef256205 = false;
						this.Update();
					}
					
					break;
				}
				
				
				case 1696542215:
				{
					if (field.equals("RequestJoystickVibration")) 
					{
						__temp_executeDef256205 = false;
						this.RequestJoystickVibration(((haxor.input.Joystick) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef256205 = false;
						this.UpdateInput();
					}
					
					break;
				}
				
				
				case 1145357780:
				{
					if (field.equals("OnJoystickAnalogUpdate")) 
					{
						__temp_executeDef256205 = false;
						this.OnJoystickAnalogUpdate();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef256205 = false;
						this.Clear();
					}
					
					break;
				}
				
				
				case -920839218:
				{
					if (field.equals("OnJoystickDataUpdate")) 
					{
						__temp_executeDef256205 = false;
						this.OnJoystickDataUpdate(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), haxe.lang.Runtime.toBool(dynargs.__get(2)));
					}
					
					break;
				}
				
				
				case -2071726377:
				{
					if (field.equals("OnMouseMove")) 
					{
						__temp_executeDef256205 = false;
						this.OnMouseMove(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 667176135:
				{
					if (field.equals("OnJoystickStart")) 
					{
						__temp_executeDef256205 = false;
						this.OnJoystickStart(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 210002197:
				{
					if (field.equals("OnMouseWheel")) 
					{
						__temp_executeDef256205 = false;
						this.OnMouseWheel(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -351112133:
				{
					if (field.equals("OnTouchEnd")) 
					{
						__temp_executeDef256205 = false;
						this.OnTouchEnd(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1626355896:
				{
					if (field.equals("OnMouseButton")) 
					{
						__temp_executeDef256205 = false;
						this.OnMouseButton(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case -1805056230:
				{
					if (field.equals("OnTouchCancel")) 
					{
						__temp_executeDef256205 = false;
						this.OnTouchCancel(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 76310496:
				{
					if (field.equals("OnKey")) 
					{
						__temp_executeDef256205 = false;
						this.OnKey(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 2000665713:
				{
					if (field.equals("OnTouchMove")) 
					{
						__temp_executeDef256205 = false;
						this.OnTouchMove(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 1896765378:
				{
					if (field.equals("OnTouchStart")) 
					{
						__temp_executeDef256205 = false;
						this.OnTouchStart(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5), dynargs.__get(6));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256205) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_joystick");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


