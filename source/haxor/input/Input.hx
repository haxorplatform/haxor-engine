/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.input;
import js.Browser;
import js.html.CanvasElement;
import js.html.DivElement;
import js.html.Element;
import js.html.Event;
import js.html.Gamepad;
import js.html.GamepadList;
import js.html.KeyboardEvent;
import js.html.MouseEvent;
import js.html.Node;
import js.html.TouchEvent;
import js.html.TouchList;
import js.html.UIEvent;
import js.html.WheelEvent;
import js.JQuery;
import haxor.core.Application;
import haxor.core.Console;
import haxor.core.Engine;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.Screen;
import haxor.math.Mathf;
import haxor.math.Vector2;
import haxor.math.Vector3;

/**
 * 
 */
enum InputState
{
	None;
	Down;
	Up;	
	Hold;
}

class Joystick
{
	
	static public var analogBias : Array<Float> = [0.1,0.9];
	
	static public var buttonBias : Float 		= 0.9;
	
	static public var available : Bool 			= false;	
	
	static public var FACE_1 				: Int = 0; // Face (main) buttons
	static public var FACE_2				: Int = 1;
	static public var FACE_3				: Int = 2;
	static public var FACE_4				: Int = 3;
	static public var LEFT_SHOULDER			: Int = 4; // Top shoulder buttons
	static public var RIGHT_SHOULDER		: Int = 5;
	static public var LEFT_SHOULDER_BOTTOM	: Int = 6; // Bottom shoulder buttons
	static public var RIGHT_SHOULDER_BOTTOM	: Int = 7;
	static public var SELECT				: Int = 8;
	static public var START					: Int = 9;
	static public var LEFT_ANALOGUE_STICK	: Int = 10; // Analogue sticks (if depressible)
	static public var RIGHT_ANALOGUE_STICK	: Int = 11;
	static public var PAD_TOP				: Int = 12; // Directional (discrete) pad
	static public var PAD_BOTTOM			: Int = 13;
	static public var PAD_LEFT				: Int = 14;
	static public var PAD_RIGHT				: Int = 15;
	
	static public var LEFT_ANALOGUE_HOR		: Int = 0;
	static public var LEFT_ANALOGUE_VERT	: Int = 1;
	static public var RIGHT_ANALOGUE_HOR	: Int = 2;
	static public var RIGHT_ANALOGUE_VERT	: Int = 3;
		
	public var name : String;
	
	public var id : Int;
	
	public var button : Array<Float>;
	
	public var state : Array<InputState>;
	
	public var hold : Array<Float>;
	
	public var analog : Array<Float>;
	
	public var analogLeft  : Vector3;
	 
	public var analogRight : Vector3;
	
	public var triggerLeft  : Float;
	
	public var triggerRight : Float;
	
	public function new()
	{
		name 	= "";
		id   	= -1;
		button  = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
		var st : InputState = InputState.None;
		state   = [st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st];
		hold    = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
		analog  = [0, 0, 0, 0, 0, 0, 0, 0];
		analogLeft  = new Vector3();
		analogRight = new Vector3();
		triggerLeft  = 0.0;
		triggerRight = 0.0;
	}
	
	public function IsDown(p_button : Int):Bool { return (state[p_button] == InputState.Hold) || (state[p_button] == InputState.Down); }
	
	public function Hit(p_button : Int):Bool    { return (state[p_button] == InputState.Up); }
	
	
}

/**
 * 
 */
class Touch
{
	
	
	public var state 	: InputState;
	
	public var id 		: Int;
	
	public var position : Vector2;
	
	public var radius : Vector2;
	
	public var angle : Float;
	
	public var relativePosition : Vector2;
	
	public var delta 	: Vector2;
	
	public var pressure : Float;
	
	public var hold : Float;
	
	var m_isDown : Bool;
	
	public function new()
	{
		state = InputState.None;
		id = -1;
		position = new Vector2();
		delta = new Vector2();
		relativePosition = new Vector2();
		pressure = 0;
		hold = 0;	
		angle = 0;
		radius = new Vector2();
		m_isDown = false;
	}	
	
	
}

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Input 
{
	
	static var m_target : Element;
	
	static var m_inputStateMap : Map<Int,InputState>;
	
	static var m_inputHoldMap : Map<Int,Float>;
	
	static var m_isDownList: Array<Bool>;
	
	static var m_activeInput: Array<Int>;
	
	static var m_needReset : Bool;
	
	static var m_eventStack : Array<UIEvent>;
	
	static var m_hasActiveTouches : Bool;
	
	static public var touch(get_touch, never) : Array<Touch>;
	static var m_touchList : Array<Touch>;
	static var m_eventTouchList : js.html.TouchList;
	static function get_touch() : Array<Touch> { return m_touchList.copy(); }
	
	static public var joystick(get_joystick, never) : Array<Joystick>;	
	static function get_joystick() : Array<Joystick> { return m_joysticks; }
	static var m_joystickList : Array<Joystick>;	
	static var m_joysticks    : Array<Joystick>;	
	
	static var m_navigator : Dynamic;
	
	static public var multitouch(get_multitouch, never) : Bool;
	static var m_isMultiTouch : Bool;
	static function get_multitouch():Bool { return m_isMultiTouch; }
	
	static public var mouse : Vector2;
		
	static public var deltaMouse : Vector2;
	
	static public var relativeMouse : Vector2;
	
	static public var wheel : Float;
	
	/**
	 * Flag that tells if page scrolling is enabled
	 */
	static public var scroll : Bool = false;
	
	/**
	 * 
	 * @param	p_code
	 * @return
	 */
	static public function GetInputState(p_code : Int) : InputState { return m_inputStateMap.get(p_code); }
	
	/**
	 * 
	 * @param	p_code
	 * @return
	 */
	static public function IsDown(p_code : Int) : Bool 
	{
		var s : InputState = GetInputState(p_code);
		return (s == InputState.Down) || (s == InputState.Hold);
	}
	
	/**
	 * 
	 * @param	p_code
	 * @return
	 */
	static public function Hit(p_code : Int) : Bool 
	{
		var s : InputState = GetInputState(p_code);
		return (s == InputState.Up);
	}
	
	/**
	 * 
	 * @param	p_code
	 * @return
	 */
	static public function GetHoldTime(p_code : Int) : Float { return m_inputHoldMap.get(p_code); }
	
	static function Update():Void
	{
		wheel = 0; 
		deltaMouse.x = 0; 
		deltaMouse.y = 0; 	
		
		if(m_hasActiveTouches) ProcessTouch();
		
		ProcessJoystick();
		
		if (m_eventStack.length > 0) while (m_eventStack.length > 0) ProcessInput(m_eventStack.shift());		
		for (i in 0...m_activeInput.length) UpdateInputState(m_activeInput[i], m_isDownList[m_activeInput[i]]);						
	}
	
	
	private function OnInputEvent(p_event : UIEvent):Void
	{
		m_eventStack.push(p_event);
		var prevent : Bool = (p_event.type == "mousedown") || (p_event.type == "mousewheel");
		if (prevent) if (relativeMouse.x >= 0) if (relativeMouse.x <= 1) if (relativeMouse.y >= 0) if (relativeMouse.y <= 1) p_event.preventDefault();
		
	}
	
	static function Initialize(p_target : Element):Void
	{
		var t : Dynamic = m_target = p_target;
		
		var nav : Dynamic = m_navigator = Browser.navigator;
		
		Joystick.available = !!nav.webkitGetGamepads || !!nav.webkitGamepads || (nav.userAgent.indexOf('Firefox/') != -1);
		
		
		m_joysticks 	= [];
		m_joystickList 	= [];
		for (i in 0...10)
		{
			m_joystickList.push(new Joystick());
		}
				
		
		p_target.onmousedown  = OnInput;
		Browser.document.onmousemove  = OnInput;
		//p_target.onmousemove  = OnInput;
		p_target.onmouseover  = OnInput;
		Browser.document.onmouseup    = OnInput;
		//p_target.onmouseup  = OnInput;
		p_target.onmousewheel = OnInput;				
		if (t.addEventListener) t.addEventListener("DOMMouseScroll", OnInput);
		
		Browser.document.onkeydown    = OnInput;
		Browser.document.onkeyup      = OnInput;
		
		try	{ m_isMultiTouch = (js.html.TouchEvent != null); } catch (ex:Dynamic) {	m_isMultiTouch = false;	}
		
		m_eventTouchList = null;
		
		p_target.ontouchstart   = OnTouch;
		Browser.document.ontouchmove    = OnTouch;
		Browser.document.ontouchcancel  = OnTouch;
		Browser.document.ontouchend  	= OnTouch;
		
		m_inputStateMap = new Map<Int,InputState>();
		m_inputHoldMap  = new Map<Int,Float>();
		m_activeInput = new Array<Int>();
		m_isDownList = new Array <Bool>();
		m_eventStack = new Array<UIEvent>();
		m_touchList = [];
		for (i in 0...256)
		{
			m_inputStateMap.set(i, InputState.None);		
			m_inputHoldMap.set(i, 0);	
			m_isDownList.push(false);
		}
		
		mouse = new Vector2();
		deltaMouse = new Vector2();
		relativeMouse = new Vector2();
		m_hasActiveTouches = false;
		var w : Dynamic = Browser.window;
		
		trace("Haxor> Input initialize - Target[" + m_target.getAttribute("name") + "] MultiTouch[" + m_isMultiTouch + "] Joystick[" + Joystick.available +"]");
	}
	
	static function ProcessJoystick():Void
	{
		
		if (!Joystick.available) return;
		var nav : Dynamic = m_navigator;
		var l : GamepadList = null;
		
		if (nav.webkitGetGamepads != null)  l = nav.webkitGetGamepads(); else
		if (nav.webkitGamepads != null) 	l = nav.webkitGamepads();
		
		if (l == null) return;
		
		m_joysticks  = [];
		
		if (l.length <= 0) return;
		
		for (i in 0...l.length)
		{
			var gp : Gamepad  = l.item(i);
			if (gp == null) continue;
			var jid:Int 	  = gp.index;			
			var js : Joystick = m_joystickList[jid];
			
			js.id   = gp.index;
			js.name = gp.id;
			for (i in 0...gp.buttons.length)
			{
				js.button[i] = gp.buttons[i];
				js.state[i] = InputStateFSM(js.state[i], js.button[i] >= Joystick.buttonBias);
				if (js.state[i] == InputState.Hold) js.hold[i] += Time.frameDeltaTime;
				if (js.state[i] == InputState.None) js.hold[i]  = 0.0;
			}
			
			for (i in 0...gp.axes.length)
			{
				js.analog[i] = gp.axes[i];
			}
			
			var b0 : Float = Joystick.analogBias[0];
			var b1 : Float = Joystick.analogBias[1];
			var s  : Float = 1.0;
			var v  : Vector3;
			
			v = js.analogLeft;
			v.x = gp.axes[Joystick.LEFT_ANALOGUE_HOR];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0));  v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
			v.y = gp.axes[Joystick.LEFT_ANALOGUE_VERT]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0));  v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
			v.z = gp.buttons[Joystick.LEFT_ANALOGUE_STICK] >= Joystick.buttonBias ? 1.0 : 0.0;
			
			v = js.analogRight;
			v.x = gp.axes[Joystick.RIGHT_ANALOGUE_HOR];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0)); v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
			v.y = gp.axes[Joystick.RIGHT_ANALOGUE_VERT]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0)); v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
			v.z = gp.buttons[Joystick.RIGHT_ANALOGUE_STICK] >= Joystick.buttonBias ? 1.0 : 0.0;
			
			js.triggerLeft  = gp.buttons[Joystick.LEFT_SHOULDER_BOTTOM];  js.triggerLeft  = Mathf.Clamp01((js.triggerLeft - b0) / (b1 - b0));
			js.triggerRight = gp.buttons[Joystick.RIGHT_SHOULDER_BOTTOM]; js.triggerRight = Mathf.Clamp01((js.triggerRight - b0) / (b1 - b0));
			m_joysticks.push(js);
		}
		
	}
	
	static function ProcessTouch():Void
	{
		
		var l : TouchList = m_eventTouchList;
		
		for (j in 0...m_touchList.length) Reflect.setField(m_touchList[j], "m_isDown", false);
		
		if (l != null)
		for (i in 0...l.length)
		{
			var et : js.html.Touch = l[i];			
			var exists : Bool = false;
			
			var p : Vector2 = GetAbsolutePosition(m_target, et.pageX, et.pageY);
			
			for (j in 0...m_touchList.length)
			{
				var t : Touch = m_touchList[j];				
				if (t.id == et.identifier)
				{
					exists = true;
					Reflect.setField(t, "m_isDown", true);
					UpdateTouch(t, et, p);
				}				
			}
			if (!exists)
			{				
				var nt:Touch = new Touch();
				UpdateTouch(nt, et, p);
				Reflect.setField(nt, "m_isDown", true);
				m_touchList.push(nt);			
			}
		}
		
		for (j in 0...m_touchList.length) UpdateTouchState(m_touchList[j]);
		if (m_touchList.length <= 0) m_hasActiveTouches = false;
	}
	
	static function UpdateTouch(t : Touch,d : js.html.Touch,p : Vector2) : Void
	{		
		if (t.id >= 0)
		{
			t.delta.x = p.x - t.position.x;
			t.delta.y = p.y - t.position.y;
		}
		t.id = d.identifier;		
		t.position.x = p.x;
		t.position.y = p.y;
		t.relativePosition.x = t.position.x / Screen.width;
		t.relativePosition.y = t.position.y / Screen.height;
		t.pressure = d.force;
		t.radius.x = d.radiusX;
		t.radius.y = d.radiusY;
		t.angle    = d.rotationAngle;
	}
	
	static function UpdateTouchState(t : Touch):Void
	{
		if (t == null) return;
		var current : InputState = t.state;		
		var d : Bool = cast Reflect.field(t, "m_isDown");
		
		if (current == InputState.Up)
		{
			m_touchList.remove(t);
		}
		
		if (current == InputState.Hold)
		{
			t.hold += Time.frameDeltaTime;			
		}
		t.state = InputStateFSM(current, d);			
	}
	
	
	
	static function GetAbsolutePosition(p_element : Element,p_x:Int,p_y:Int):Vector2
	{
		var px:Int = 0;
		var py:Int = 0;
		var e: Element = p_element;				
		do
		{
			px += e.offsetLeft;
			py += e.offsetTop;				
			e = e.offsetParent;
		}while (e != null);
		px = p_x - px;
		py = p_y - py;
		return new Vector2(px, py);
	}
	
	static function ProcessInput(p_event:UIEvent):Void
	{
		var me:MouseEvent 		= cast p_event;
		var ke:KeyboardEvent	= cast p_event;
		
		wheel = 0;
		deltaMouse.x = 0;
		deltaMouse.y = 0;
		
		var element : Element = cast p_event.target;
		
		
		switch(p_event.type)
		{
			case "wheel","mousewheel", "DOMMouseScroll":
				
				var we : WheelEvent = cast p_event;
				var dw : Int = (we.wheelDeltaY == null) ? (we.detail*40) : we.wheelDeltaY;
				
				wheel = dw / 100.0;
			
			case "mousemove":				
				var p : Vector2 = GetAbsolutePosition(m_target, me.pageX, me.pageY);
				deltaMouse.x = p.x - mouse.x;
				deltaMouse.y = p.y - mouse.y;
				mouse.x = p.x;
				mouse.y = p.y;
				relativeMouse.x = mouse.x / Screen.width;
				relativeMouse.y = mouse.y / Screen.height;
				
			
			case "mouseup":
				switch(me.button)
				{
					case 0: { UpdateInputState(KeyCode.Mouse0,false);  }
					case 1: { UpdateInputState(KeyCode.Mouse1,false);  }
					case 2: { UpdateInputState(KeyCode.Mouse2, false); }
					case 3: { UpdateInputState(KeyCode.Mouse3, false); }
					case 4: { UpdateInputState(KeyCode.Mouse4, false); }					
				}
				
			case "mousedown": 
				switch(me.button)
				{
					case 0: { UpdateInputState(KeyCode.Mouse0,true);  }
					case 1: { UpdateInputState(KeyCode.Mouse1,true);  }
					case 2: { UpdateInputState(KeyCode.Mouse2, true); }
					case 3: { UpdateInputState(KeyCode.Mouse3, true); }
					case 4: { UpdateInputState(KeyCode.Mouse4, true); }
				}
				
			case "keyup":
				UpdateInputState(ke.keyCode, false);
				
			case "keydown":
				UpdateInputState(ke.keyCode, true);				
		}
	}
	
	static function OnInput(p_event : UIEvent):Void
	{
		
		m_eventStack.push(p_event);
		var is_mousedown  : Bool = p_event.type == "mousedown";
		var is_mousewheel : Bool = (p_event.type == "mousewheel") ||(p_event.type == "wheel");
		var prevent : Bool = (is_mousedown || is_mousewheel) && (Std.is(m_target, CanvasElement));
		if (scroll) prevent = false;
		if (prevent) if (relativeMouse.x >= 0) if (relativeMouse.x <= 1) if (relativeMouse.y >= 0) if (relativeMouse.y <= 1) p_event.preventDefault();
		
	}
	
	static function OnTouch(p_event : UIEvent):Void
	{
		var te:TouchEvent		= cast p_event;		
		switch(p_event.type)
		{
			case "touchstart":	{ m_hasActiveTouches = true; m_eventTouchList = te.touches; }			
			case "touchmove":   { m_eventTouchList = te.touches; }
			case "touchcancel": {  m_eventTouchList = te.touches; }
			case "touchend":    { m_eventTouchList = te.touches; }
		}		
		if(m_hasActiveTouches) if(!scroll)p_event.preventDefault();
	}
	
	static function InputStateFSM(p_current : InputState, p_is_down:Bool) : InputState
	{
		var current : InputState = p_current;
		var next : InputState = current;
		var d : Bool = p_is_down;		
		switch(current)
		{
			case InputState.None: 
				if (d) { next = InputState.Down; }				
			case InputState.Down: 
				if (!d) next = InputState.Up;
				next = InputState.Hold;
				
			case InputState.Up:				
				next = InputState.None;				
				
			case InputState.Hold:				
				if (!d) next = InputState.Up;
		}
		return next;
	}
	
	
	static function UpdateInputState(p_code : Int, p_is_down:Bool) : Void
	{
		var current : InputState = m_inputStateMap.get(p_code);
		if(current == null)current =  InputState.None;
		var next : InputState = current;
		var d0:Bool = m_isDownList[p_code];
		var d : Bool = m_isDownList[p_code] = p_is_down;
		
		if (!d0) if (d) { m_activeInput.push(p_code);  }
		if (!d) if (d0) { return; }
		
		if (current == InputState.Up)
		{
			m_inputHoldMap.set(p_code, 0);
			m_activeInput.remove(p_code);
		}
		
		if (current == InputState.Hold)
		{
			var h:Float = m_inputHoldMap.get(p_code);
			m_inputHoldMap.set(p_code, h + Time.frameDeltaTime);
		}
		
		next = InputStateFSM(current, d);
		
		if(current != next) m_inputStateMap.set(p_code, next);
	}
	
	
}