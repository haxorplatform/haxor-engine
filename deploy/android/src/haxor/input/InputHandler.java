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
	
	
	public static   void __hx_ctor_haxor_input_InputHandler(haxor.input.InputHandler __temp_me151435)
	{
		haxor.thread.Activity.Run(((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (__temp_me151435) ), haxe.lang.Runtime.toString("Update"))) ), null, null);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.InputHandler(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.InputHandler();
	}
	
	
	public   boolean Update(double t)
	{
		haxor.input.Input.wheel = ((double) (0) );
		haxor.input.Input.deltaMouse.x = ((double) (0) );
		haxor.input.Input.deltaMouse.y = ((double) (0) );
		haxor.input.Input.UpdateInput();
		haxor.input.Input.UpdateTouchFSM();
		this.UpdateInput();
		this.EmulateTouch(haxor.input.KeyCode.Mouse0, 0);
		this.EmulateTouch(haxor.input.KeyCode.Mouse1, 2);
		this.EmulateTouch(haxor.input.KeyCode.Mouse2, 1);
		return true;
	}
	
	
	public   void UpdateInput()
	{
		{
		}
		
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
		double __temp_p_angle151434 = ( (( p_angle == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_angle)) )) );
		double __temp_p_pressure151433 = ( (( p_pressure == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_pressure)) )) );
		double __temp_p_ry151432 = ( (( p_ry == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_ry)) )) );
		double __temp_p_rx151431 = ( (( p_rx == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_rx)) )) );
		haxor.input.Touch t = haxor.input.Input.m_api_touches.__get(p_id);
		t.id = p_id;
		t.position.x = p_x;
		t.position.y = p_y;
		t.relativePosition.x = ( t.position.x / haxor.graphics.Screen.m_width );
		t.relativePosition.y = ( t.position.y / haxor.graphics.Screen.m_height );
		t.delta.x = 0.0;
		t.delta.y = 0.0;
		t.pressure = __temp_p_pressure151433;
		t.radius.x = __temp_p_rx151431;
		t.radius.y = __temp_p_ry151432;
		t.angle = __temp_p_angle151434;
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
				double __temp_stmt152202 = 0.0;
				{
					haxor.math.Vector2 _this1 = haxor.input.Input.deltaMouse;
					__temp_stmt152202 = java.lang.Math.sqrt(( ( _this1.x * _this1.x ) + ( _this1.y * _this1.y ) ));
				}
				
				if (( __temp_stmt152202 > 0 )) 
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
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152203 = true;
			switch (field.hashCode())
			{
				case -1333561812:
				{
					if (field.equals("EmulateTouch")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("EmulateTouch"))) );
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case -351112133:
				{
					if (field.equals("OnTouchEnd")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchEnd"))) );
					}
					
					break;
				}
				
				
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateInput"))) );
					}
					
					break;
				}
				
				
				case -1805056230:
				{
					if (field.equals("OnTouchCancel")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchCancel"))) );
					}
					
					break;
				}
				
				
				case -2071726377:
				{
					if (field.equals("OnMouseMove")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseMove"))) );
					}
					
					break;
				}
				
				
				case 2000665713:
				{
					if (field.equals("OnTouchMove")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchMove"))) );
					}
					
					break;
				}
				
				
				case 210002197:
				{
					if (field.equals("OnMouseWheel")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseWheel"))) );
					}
					
					break;
				}
				
				
				case 1896765378:
				{
					if (field.equals("OnTouchStart")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchStart"))) );
					}
					
					break;
				}
				
				
				case 1626355896:
				{
					if (field.equals("OnMouseButton")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMouseButton"))) );
					}
					
					break;
				}
				
				
				case 76310496:
				{
					if (field.equals("OnKey")) 
					{
						__temp_executeDef152203 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnKey"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152203) 
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
			boolean __temp_executeDef152204 = true;
			switch (field.hashCode())
			{
				case -1333561812:
				{
					if (field.equals("EmulateTouch")) 
					{
						__temp_executeDef152204 = false;
						this.EmulateTouch(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef152204 = false;
						return this.Update(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -351112133:
				{
					if (field.equals("OnTouchEnd")) 
					{
						__temp_executeDef152204 = false;
						this.OnTouchEnd(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef152204 = false;
						this.UpdateInput();
					}
					
					break;
				}
				
				
				case -1805056230:
				{
					if (field.equals("OnTouchCancel")) 
					{
						__temp_executeDef152204 = false;
						this.OnTouchCancel(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -2071726377:
				{
					if (field.equals("OnMouseMove")) 
					{
						__temp_executeDef152204 = false;
						this.OnMouseMove(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 2000665713:
				{
					if (field.equals("OnTouchMove")) 
					{
						__temp_executeDef152204 = false;
						this.OnTouchMove(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 210002197:
				{
					if (field.equals("OnMouseWheel")) 
					{
						__temp_executeDef152204 = false;
						this.OnMouseWheel(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1896765378:
				{
					if (field.equals("OnTouchStart")) 
					{
						__temp_executeDef152204 = false;
						this.OnTouchStart(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5), dynargs.__get(6));
					}
					
					break;
				}
				
				
				case 1626355896:
				{
					if (field.equals("OnMouseButton")) 
					{
						__temp_executeDef152204 = false;
						this.OnMouseButton(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 76310496:
				{
					if (field.equals("OnKey")) 
					{
						__temp_executeDef152204 = false;
						this.OnKey(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152204) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


