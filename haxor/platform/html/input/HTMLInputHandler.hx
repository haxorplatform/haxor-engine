#if html

package haxor.platform.html.input;
import js.html.Event;
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
	 * Browser navigator instance.
	 */
	private var m_navigator : Navigator;
	
	/**
	 * Stack of input events.
	 */
	private var m_events : Array<UIEvent>;
	
	/**
	 * Flag that indicates if joysticks are detectables
	 */
	private var m_check_joystick : Bool;
	
	/**
	 * Initializes this input handler with the target DOM element.
	 * @param	p_target
	 */
	private function new(p_target_id : String):Void
	{
		super();
		m_navigator = Browser.navigator;
		m_target	= Browser.document.getElementById(p_target_id);
		if (m_target == null)
		{
			Console.LogWarning("Input> Target Element not found! Using [document] as target.");
			m_target = Browser.document.body;
		}
		
		m_events = [];
				
		//Events that must be handled in the target.		 
		m_target.onmousedown  			= OnInputEvent;
		m_target.onmouseover  			= OnInputEvent;
		m_target.onmousewheel 			= OnInputEvent;
		m_target.oncontextmenu			= OnInputEvent;
		
		//Events that must be handled globally.
		Browser.document.onmousemove  	= OnInputEvent;
		Browser.document.onmouseup    	= OnInputEvent;		
		Browser.document.onkeydown    	= OnInputEvent;
		Browser.document.onkeyup      	= OnInputEvent;
		
		//Not every browser has 'addEventListener'
		try { m_target.addEventListener("DOMMouseScroll", OnInputEvent); } catch (ex:Dynamic) { }
		
		//Check multitouch by inducing error on checking for existence of 'TouchEvent'
		try	{ Input.m_multitouch = (js.html.TouchEvent != null); } catch (ex:Dynamic) {	Input.m_multitouch = false;	}
		
		if (Input.multitouch)
		{
			//Helps with page slide in iOS
			Browser.document.addEventListener("touchmove", function(e:Event) { e.preventDefault(); }, false);
			
			m_target.ontouchstart   	  = OnTouchEvent;			
			Browser.window.ontouchmove    = OnTouchEvent;
			Browser.window.ontouchcancel  = OnTouchEvent;
			Browser.window.ontouchend  	  = OnTouchEvent;
		}
		
		
		var t 	: Dynamic 	= m_target;		
		var nav : Dynamic 	= m_navigator;
		m_check_joystick = !!nav.getGamepads || (nav.userAgent.indexOf('Firefox/') != -1);
		
	}
	
	/**
	 * Update the input data from events and joystick.
	 */
	override function UpdateInput():Void 
	{	
		
		if (m_events.length > 0) while (m_events.length > 0) ProcessInputEvent(m_events.shift());			
		UpdateJoystick();		
	}
	
	/**
	 * Handles incoming events and stack them to process inside the execution loop.
	 * @param	p_event
	 */	
	private function OnInputEvent(p_event : UIEvent):Void
	{	
		var e : UIEvent = p_event==null ? (cast Browser.window.event) : p_event;
		var c : UIEvent;
		
		#if ie8
		c = cast { };		
		untyped __js__('
		for (var x in e)
		{
			if (x == "keyLocation") continue;
           c[x] = e[x];
		}
		');		
		#else
		c = e;
		#end
		
		m_events.push(c);
		var is_mousedown  : Bool = c.type == "mousedown";
		var is_mousewheel : Bool = (c.type == "mousewheel") ||(c.type == "wheel");
		var prevent : Bool = (is_mousedown || is_mousewheel);
		
		#if !ie8
		prevent = prevent && (Std.is(m_target, CanvasElement));
		#end
		
		if (Input.scroll) prevent = false;
		if (c.type == "contextmenu") if (!Input.menu) prevent = true;		
		if (prevent) if (Input.relativeMouse.x >= 0) if (Input.relativeMouse.x <= 1) if (Input.relativeMouse.y >= 0) if (Input.relativeMouse.y <= 1) if(e.preventDefault != null) e.preventDefault();
	}
	
	/**
	 * Process an input event.
	 * @param	p_event
	 */
	private function ProcessInputEvent(p_event:UIEvent):Void
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
				
				var px : Int = me.pageX;
				var py : Int = me.pageY;				
				if (px == null) px = me.clientX;
				if (py == null) py = me.clientY;				
				var p : Vector2 = GetAbsolutePosition(m_target, px, py);				
				OnMouseMove(p.x, p.y);
			
			case "mouseup":				
				OnMouseButton(me.button,false);				
			case "mousedown":   				
				OnMouseButton(me.button,true);				
			case "keyup":		OnKey(ke.keyCode, false);
			case "keydown": 	OnKey(ke.keyCode, true);
			case "contextmenu":
			
		}
	}
	
	/**
	 * Handler for touch events.
	 * @param	p_event
	 */
	private function OnTouchEvent(p_event : UIEvent):Void
	{
		var te:TouchEvent		= cast p_event;		
		for (i in 0...te.changedTouches.length)
		{
			var t : js.html.Touch = te.changedTouches.item(i);
			var p : Vector2 = GetAbsolutePosition(m_target, t.pageX, t.pageY);			
			switch(p_event.type)
			{
				case "touchstart": 	OnTouchStart(t.identifier, p.x, p.y, t.radiusX, t.radiusY, t.force, t.rotationAngle);					
				case "touchmove":  	OnTouchMove(t.identifier, p.x, p.y);
				case "touchcancel": OnTouchCancel(t.identifier);
				case "touchend":	OnTouchEnd(t.identifier);
			}
		}			
		if(Input.m_touches.length>0) if(!Input.scroll) p_event.preventDefault();
	}
	
	/**
	 * Updates joystick state.
	 */
	private function UpdateJoystick():Void
	{
		if (!m_check_joystick) return;
		var nav : Dynamic 		= m_navigator;
		var l 	: GamepadList 	= null;
		
		//Fetches the list of gamepads.
		if (nav.getGamepads != null)  l = nav.getGamepads();
		
		//Returns if none.
		if (l == null) 		return;		
		if (l.length <= 0) 	return;
		
		//Checks the API joystick list.
		for (i in 0...l.length)
		{
			var gp : js.html.Gamepad  = l.item(i);			
			if (gp == null) continue;			
			OnJoystickStart(gp.index, gp.id);			
			for (i in 0...gp.buttons.length)
			{
				var bt : Dynamic = gp.buttons[i];
				OnJoystickDataUpdate(i, bt.value,false);				
			}			
			for (i in 0...gp.axes.length) OnJoystickDataUpdate(i, gp.axes[i],true);			
			OnJoystickAnalogUpdate();			
		}
	
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
		return Vector2.temp.Set(px, py);
	}
	
	
	
}

#end