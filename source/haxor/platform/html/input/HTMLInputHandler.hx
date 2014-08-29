#if html

package haxor.platform.html.input;
import haxor.input.InputHandler;
import haxor.thread.Activity;
import js.html.Node;
import haxor.core.Console;
import js.html.CanvasElement;
import js.html.KeyboardEvent;
import js.html.MouseEvent;
import js.html.WheelEvent;
import haxor.input.KeyCode;
import haxor.graphics.Screen;
import haxor.input.Touch;
import js.html.TouchEvent;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.core.Enums.InputState;
import haxor.core.Time;
import haxor.math.Mathf;
import js.html.Gamepad;
import js.html.GamepadList;
import haxor.input.Input;
import haxor.input.Joystick;
import js.Browser;
import js.html.UIEvent;
import js.html.Navigator;

import js.html.TouchList;
import js.html.Element;

/**
 * Platform class that handles the input detection and update of the static 'Input' class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class HTMLInputHandler extends InputHandler
{

	/**
	 * Target DOM element to handle inputs.
	 */
	private var m_target : Element;
	
	/**
	 * List of touches.
	 */
	private var m_touches : TouchList;
	
	/**
	 * Browser navigator instance.
	 */
	private var m_navigator : Navigator;
	
	/**
	 * Stack of input events.
	 */
	private var m_events : Array<UIEvent>;
	
	/**
	 * Flag that indicates if there is any active touches.
	 */
	private var m_has_touches : Bool;
	

	/**
	 * Initializes this input handler with the target DOM element.
	 * @param	p_target
	 */
	private function new(p_target_id : String):Void
	{
		m_navigator = Browser.navigator;
		m_target	= Browser.document.getElementById(p_target_id);
		if (m_target == null)
		{
			Console.LogWarning("Input> Target Element not found! Using [document] as target.");
			m_target = Browser.document.body;
		}
		
		m_events = [];
		
		m_has_touches = false;
				
		//Events that must be handled in the target.		 
		m_target.onmousedown  			= OnInputEvent;
		m_target.onmouseover  			= OnInputEvent;
		m_target.onmousewheel 			= OnInputEvent;
		
		//Events that must be handled globally.
		Browser.document.onmousemove  	= OnInputEvent;
		Browser.document.onmouseup    	= OnInputEvent;		
		Browser.document.onkeydown    	= OnInputEvent;
		Browser.document.onkeyup      	= OnInputEvent;
		
		//Not every browser has 'addEventListener'
		try { m_target.addEventListener("DOMMouseScroll", OnInputEvent); } catch (ex:Dynamic) { }
		
		//Check multitouch by inducing error on checking for existence of 'TouchEvent'
		try	{ Input.m_multitouch = (js.html.TouchEvent != null); } catch (ex:Dynamic) {	Input.m_multitouch = false;	}
		
		m_touches = null;
		
		if (Input.multitouch)
		{
			m_target.ontouchstart   		= OnTouchEvent;
			Browser.document.ontouchmove    = OnTouchEvent;
			Browser.document.ontouchcancel  = OnTouchEvent;
			Browser.document.ontouchend  	= OnTouchEvent;
		}
		
		var t 	: Dynamic 	= m_target;		
		var nav : Dynamic 	= m_navigator;
		Joystick.available = !!nav.getGamepads || (nav.userAgent.indexOf('Firefox/') != -1);
		
		super();
	}
	
	override function UpdateInput():Void 
	{
		if(m_has_touches) UpdateTouch();		
		UpdateJoystick();		
		if (m_events.length > 0) while (m_events.length > 0) ProcessInput(m_events.shift());		
	}
	
	/**
	 * Handles incoming events and stack them to process inside the execution loop.
	 * @param	p_event
	 */	
	private function OnInputEvent(p_event : UIEvent):Void
	{	
		m_events.push(p_event);
		var is_mousedown  : Bool = p_event.type == "mousedown";
		var is_mousewheel : Bool = (p_event.type == "mousewheel") ||(p_event.type == "wheel");
		var prevent : Bool = (is_mousedown || is_mousewheel) && (Std.is(m_target, CanvasElement));
		if (Input.scroll) prevent = false;
		if (prevent) if (Input.relativeMouse.x >= 0) if (Input.relativeMouse.x <= 1) if (Input.relativeMouse.y >= 0) if (Input.relativeMouse.y <= 1) p_event.preventDefault();
	}
	
	/**
	 * Updates joystick state.
	 */
	private function UpdateJoystick():Void
	{
		if (!Joystick.available) return;
		var nav : Dynamic 		= m_navigator;
		var l 	: GamepadList 	= null;
		
		//Fetches the list of gamepads.
		if (nav.webkitGetGamepads != null)  l = nav.webkitGetGamepads(); else
		if (nav.webkitGamepads != null) 	l = nav.webkitGamepads();
		
		//Returns if none.
		if (l == null) 		return;		
		if (l.length <= 0) 	return;
		
		Input.m_joysticks  = [];
		
		//Checks the API joystick list.
		for (i in 0...l.length)
		{
			var gp : Gamepad  = l.item(i);
			
			if (gp == null) continue;
						
			var id	: Int 	  = gp.index;			//Joystick Id.
			var js 	: Joystick = Input.m_api_joystick[id]; //
			
			js.id   = gp.index;
			js.name = gp.id;
			for (i in 0...gp.buttons.length)
			{
				js.button[i] 	= gp.buttons[i];
				js.state[i] 	= Input.InputStateFSM(js.state[i], js.button[i] >= Joystick.buttonBias);
				if (js.state[i] == InputState.Hold) js.hold[i] += Time.delta;
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
			v.x = gp.axes[KeyCode.LeftAnalogueHor];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0));  v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
			v.y = gp.axes[KeyCode.LeftAnalogueVert]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0));  v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
			v.z = gp.buttons[KeyCode.LeftAnalogueStick] >= Joystick.buttonBias ? 1.0 : 0.0;
			
			v = js.analogRight;
			v.x = gp.axes[KeyCode.RightAnalogueHor];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0)); v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
			v.y = gp.axes[KeyCode.RightAnalogueVert]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0)); v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
			v.z = gp.buttons[KeyCode.RightAnalogueStick] >= Joystick.buttonBias ? 1.0 : 0.0;
			
			js.triggerLeft  = gp.buttons[KeyCode.LeftShoulderBottom];  js.triggerLeft  = Mathf.Clamp01((js.triggerLeft - b0) / (b1 - b0));
			js.triggerRight = gp.buttons[KeyCode.RightShoulderBottom]; js.triggerRight = Mathf.Clamp01((js.triggerRight - b0) / (b1 - b0));
			Input.m_joysticks.push(js);
		}
		
	}
	
	/**
	 * Process an input event.
	 * @param	p_event
	 */
	private function ProcessInput(p_event:UIEvent):Void
	{
		var me:MouseEvent 		= cast p_event;
		var ke:KeyboardEvent	= cast p_event;		
		var element : Element = cast p_event.target;
		switch(p_event.type)
		{
			case "wheel","mousewheel", "DOMMouseScroll":				
				var we : WheelEvent = cast p_event;
				var dw : Int = (we.wheelDeltaY == null) ? (we.detail*40) : we.wheelDeltaY;				
				OnMouseWheel(dw / 100.0);
			case "mousemove":				
				var p : Vector2 = GetAbsolutePosition(m_target, me.pageX, me.pageY);
				OnMouseMove(p.x, p.y);
			
			case "mouseup":		OnMouseButton(me.button,false);				
			case "mousedown":   OnMouseButton(me.button,true);				
			case "keyup":		OnKey(ke.keyCode, false);
			case "keydown": 	OnKey(ke.keyCode, false);
		}
	}
	
	/**
	 * Updates touch state and data.
	 */
	private function UpdateTouch():Void
	{
		
		var l : TouchList = m_touches;
		
		Input.ResetTouchDownFlag();
		
		if (l != null)
		for (i in 0...l.length)
		{
			var et 		: js.html.Touch 	= l[i];			
			var exists 	: Bool 				= false;
			
			var p : Vector2 = GetAbsolutePosition(m_target, et.pageX, et.pageY);
			
			for (j in 0...Input.m_touch.length)
			{
				var t : Touch = Input.m_touch[j];				
				if (t.id == et.identifier)
				{
					exists 		= true;
					t.m_down 	= true;
					UpdateTouchData(t, et, p);
				}				
			}
			if (!exists)
			{				
				var nt:Touch = new Touch();
				UpdateTouchData(nt, et, p);
				nt.m_down 	 = true;
				Input.m_touch.push(nt);
			}
		}
		
		Input.UpdateTouchFSM();
		
		if (Input.m_touch.length <= 0) m_has_touches = false;
	}
	
	/**
	 * Handler for touch events.
	 * @param	p_event
	 */
	private function OnTouchEvent(p_event : UIEvent):Void
	{
		var te:TouchEvent		= cast p_event;		
		switch(p_event.type)
		{
			case "touchstart":	{ 	m_touches = te.touches; m_has_touches = true; }			
			case "touchmove":   { 	m_touches = te.touches; }
			case "touchcancel": {  	m_touches = te.touches; }
			case "touchend":    { 	m_touches = te.touches; }
		}		
		if(m_has_touches) if(!Input.scroll) p_event.preventDefault();
	}
	
	/**
	 * Updates Touch data from HTML to Haxor internal structure.
	 * @param	t
	 * @param	d
	 * @param	p
	 */
	private function UpdateTouchData(t : Touch,d : js.html.Touch,p : Vector2) : Void
	{		
		if (t.id >= 0)
		{
			t.delta.x = p.x - t.position.x;
			t.delta.y = p.y - t.position.y;
		}
		t.id 					= d.identifier;		
		t.position.x 			= p.x;
		t.position.y 			= p.y;
		t.relativePosition.x 	= t.position.x / Screen.width;
		t.relativePosition.y 	= t.position.y / Screen.height;
		t.pressure 				= d.force;
		t.radius.x 				= d.radiusX;
		t.radius.y 				= d.radiusY;
		t.angle    				= d.rotationAngle;
	}
	
	/**
	 * Returns the absolute position relative to the target element.
	 * @param	p_element
	 * @param	p_x
	 * @param	p_y
	 * @return
	 */
	private function GetAbsolutePosition(p_element : Element,p_x:Int,p_y:Int):Vector2
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
	
	
	
}

#end