package haxor.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Input extends haxe.lang.HxObject
{
	static 
	{
		haxor.input.Input.scroll = false;
		haxor.input.Input.menu = false;
		haxor.input.Input.emulateTouch = false;
	}
	public    Input(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Input()
	{
		haxor.input.Input.__hx_ctor_haxor_input_Input(this);
	}
	
	
	public static   void __hx_ctor_haxor_input_Input(haxor.input.Input __temp_me160536)
	{
		{
		}
		
	}
	
	
	public static  haxe.ds.IntMap<haxor.core.InputState> m_state;
	
	public static  haxe.ds.IntMap<java.lang.Object> m_hold;
	
	public static  haxe.root.Array<java.lang.Object> m_down;
	
	public static  haxe.root.Array<java.lang.Object> m_active;
	
	public static  haxor.input.InputHandler m_handler;
	
	
	
	public static   haxe.root.Array<haxor.input.Touch> get_touches()
	{
		return haxor.input.Input.m_touches;
	}
	
	
	public static  haxe.root.Array<haxor.input.Touch> m_touches;
	
	public static  haxe.root.Array<haxor.input.Touch> m_api_touches;
	
	
	
	public static   haxe.root.Array<haxor.input.Joystick> get_joystick()
	{
		return haxor.input.Input.m_joysticks;
	}
	
	
	public static  haxe.root.Array<haxor.input.Joystick> m_joysticks;
	
	public static  haxe.root.Array<haxor.input.Joystick> m_api_joystick;
	
	
	
	public static   boolean get_multitouch()
	{
		return haxor.input.Input.m_multitouch;
	}
	
	
	public static  boolean m_multitouch;
	
	public static  haxor.math.Vector2 mouse;
	
	public static  haxor.math.Vector2 deltaMouse;
	
	public static  haxor.math.Vector2 relativeMouse;
	
	public static  double wheel;
	
	public static  boolean scroll;
	
	public static  boolean menu;
	
	public static  boolean emulateTouch;
	
	public static   haxor.core.InputState GetInputState(int p_code)
	{
		return haxor.input.Input.m_state.get(((int) (p_code) ));
	}
	
	
	public static   boolean Pressed(int p_code)
	{
		haxor.core.InputState s = haxor.input.Input.GetInputState(p_code);
		return ( ( s == haxor.core.InputState.Down ) || ( s == haxor.core.InputState.Hold ) );
	}
	
	
	public static   boolean Down(int p_code)
	{
		haxor.core.InputState s = haxor.input.Input.GetInputState(p_code);
		return ( s == haxor.core.InputState.Down );
	}
	
	
	public static   boolean Hit(int p_code)
	{
		haxor.core.InputState s = haxor.input.Input.GetInputState(p_code);
		return ( s == haxor.core.InputState.Up );
	}
	
	
	public static   double GetHoldTime(int p_code)
	{
		return ((double) (haxe.lang.Runtime.toDouble(haxor.input.Input.m_hold.get(((int) (p_code) )))) );
	}
	
	
	public static   void Initialize()
	{
		haxor.input.Input.m_state = new haxe.ds.IntMap<haxor.core.InputState>();
		haxor.input.Input.m_hold = new haxe.ds.IntMap<java.lang.Object>();
		haxor.input.Input.m_active = new haxe.root.Array<java.lang.Object>();
		haxor.input.Input.m_down = new haxe.root.Array<java.lang.Object>();
		haxor.input.Input.m_touches = new haxe.root.Array<haxor.input.Touch>(new haxor.input.Touch[]{});
		haxor.input.Input.m_api_touches = new haxe.root.Array<haxor.input.Touch>(new haxor.input.Touch[]{});
		{
			int _g = 0;
			while (( _g < 10 ))
			{
				int i = _g++;
				haxor.input.Input.m_api_touches.push(new haxor.input.Touch());
			}
			
		}
		
		{
			int _g1 = 0;
			while (( _g1 < 256 ))
			{
				int i1 = _g1++;
				haxor.input.Input.m_state.set(((int) (i1) ), ((haxor.core.InputState) (haxor.core.InputState.None) ));
				haxor.input.Input.m_hold.set(((int) (i1) ), ((java.lang.Object) (0) ));
				haxor.input.Input.m_down.push(false);
			}
			
		}
		
		haxor.input.Input.m_joysticks = new haxe.root.Array<haxor.input.Joystick>(new haxor.input.Joystick[]{});
		haxor.input.Input.m_api_joystick = new haxe.root.Array<haxor.input.Joystick>(new haxor.input.Joystick[]{});
		{
			int _g2 = 0;
			while (( _g2 < 10 ))
			{
				int i2 = _g2++;
				haxor.input.Input.m_api_joystick.push(new haxor.input.Joystick());
			}
			
		}
		
		haxor.input.Input.mouse = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		haxor.input.Input.deltaMouse = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		haxor.input.Input.relativeMouse = new haxor.math.Vector2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		haxor.core.Console.Log("Haxor> Input Initialize", 4);
	}
	
	
	public static   void UpdateTouchFSM()
	{
		int _g1 = 0;
		int _g = haxor.input.Input.m_touches.length;
		while (( _g1 < _g ))
		{
			int j = _g1++;
			haxor.input.Input.TouchFSM(haxor.input.Input.m_touches.__get(j));
		}
		
	}
	
	
	public static   void UpdateInput()
	{
		int _g1 = 0;
		int _g = haxor.input.Input.m_active.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			haxor.input.Input.UpdateInputState(((int) (haxe.lang.Runtime.toInt(haxor.input.Input.m_active.__get(i))) ), haxe.lang.Runtime.toBool(haxor.input.Input.m_down.__get(((int) (haxe.lang.Runtime.toInt(haxor.input.Input.m_active.__get(i))) ))), null);
		}
		
	}
	
	
	public static   void TouchFSM(haxor.input.Touch t)
	{
		if (( t == null )) 
		{
			return ;
		}
		
		haxor.core.InputState current = t.state;
		boolean d = t.m_down;
		if (( current == haxor.core.InputState.Up )) 
		{
			haxor.input.Input.m_touches.remove(t);
		}
		
		if (( current == haxor.core.InputState.Hold )) 
		{
			t.hold += haxor.core.Time.m_delta;
		}
		
		t.state = haxor.input.Input.InputStateFSM(current, d);
	}
	
	
	public static   void UpdateInputState(int p_code, boolean p_is_down, java.lang.Object p_update_state)
	{
		boolean __temp_p_update_state160535 = ( (( p_update_state == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_update_state)) );
		haxor.core.InputState current = haxor.input.Input.m_state.get(((int) (p_code) ));
		if (( current == null )) 
		{
			current = haxor.core.InputState.None;
		}
		
		haxor.core.InputState next = current;
		boolean d0 = haxe.lang.Runtime.toBool(haxor.input.Input.m_down.__get(p_code));
		boolean d = haxe.lang.Runtime.toBool(haxor.input.Input.m_down.__set(p_code, p_is_down));
		if ( ! (d0) ) 
		{
			if (d) 
			{
				haxor.input.Input.m_active.push(p_code);
			}
			
		}
		
		if ( ! (d) ) 
		{
			if (d0) 
			{
				return ;
			}
			
		}
		
		if (__temp_p_update_state160535) 
		{
			if (( current == haxor.core.InputState.Up )) 
			{
				haxor.input.Input.m_hold.set(((int) (p_code) ), ((java.lang.Object) (0) ));
				haxor.input.Input.m_active.remove(p_code);
			}
			
			if (( current == haxor.core.InputState.Hold )) 
			{
				double h = ((double) (haxe.lang.Runtime.toDouble(haxor.input.Input.m_hold.get(((int) (p_code) )))) );
				haxor.input.Input.m_hold.set(((int) (p_code) ), ((java.lang.Object) (( h + haxor.core.Time.m_delta )) ));
			}
			
			next = haxor.input.Input.InputStateFSM(current, d);
			if (( current != next )) 
			{
				haxor.input.Input.m_state.set(((int) (p_code) ), ((haxor.core.InputState) (next) ));
			}
			
		}
		
	}
	
	
	public static   haxor.core.InputState InputStateFSM(haxor.core.InputState p_current, boolean p_is_down)
	{
		haxor.core.InputState current = p_current;
		haxor.core.InputState next = current;
		boolean d = p_is_down;
		switch (haxe.root.Type.enumIndex(current))
		{
			case 0:
			{
				if (d) 
				{
					next = haxor.core.InputState.Down;
				}
				
				break;
			}
			
			
			case 1:
			{
				if ( ! (d) ) 
				{
					next = haxor.core.InputState.Up;
				}
				
				next = haxor.core.InputState.Hold;
				break;
			}
			
			
			case 2:
			{
				next = haxor.core.InputState.None;
				break;
			}
			
			
			case 3:
			{
				if ( ! (d) ) 
				{
					next = haxor.core.InputState.Up;
				}
				
				break;
			}
			
			
		}
		
		return next;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.Input(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.Input();
	}
	
	
}


