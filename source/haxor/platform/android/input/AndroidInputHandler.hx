#if android

package haxor.platform.android.input;
import haxor.core.Console;
import haxor.input.InputHandler;

import android.view.MotionEvent;


/**
 * Platform class that handles the input detection and update of the static 'Input' class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AndroidInputHandler extends InputHandler
{
	
	private var m_tf : Array<MotionEvent>;
	
	private var m_tb : Array<MotionEvent>;
	
	/**
	 * Initializes this input handler.
	 * @param	p_target
	 */
	private function new():Void
	{
		m_tf = [];
		m_tb = [];
		
		//Add this handler into the execution loop.
		super();
	}
	
	/**
	 * Handles the stacking of touch events for future handling.
	 * @param	p_event
	 * @return
	 */
	public function OnTouchEvent(p_event : MotionEvent):Void
	{
		ProcessTouchEvent(p_event);
		//m_tb.push(p_event);				
	}
	
	/**
	 * Update loop.
	 */
	override function UpdateInput():Void 
	{
		//if (m_tf.length > 0) while (m_tf.length > 0) ProcessTouchEvent(m_tf.shift());		
		//var t : Array<MotionEvent> = m_tf; m_tf = m_tb; m_tb = t;
	}
	
	/**
	 * Process the touch event in the stack.
	 * @param	p_event
	 */
	private function ProcessTouchEvent(p_event:MotionEvent):Void
	{
		if (p_event == null) return;
		
		var action  : Int = p_event.getActionMasked();
		var aid 	: Int = p_event.getActionIndex();
		var id  	: Int = p_event.getPointerId(aid);
		
		//if (action != MotionEvent.ACTION_MOVE) Console.Log(ActionToString(action)+" a["+aid+"] id["+id+"]");
		
		var px : Float  = 0.0; 
		var py : Float  = 0.0; 
		
		if(aid >= 0) px = p_event.getX(aid);						 
		if(aid >= 0) py = p_event.getY(aid);
		
		switch(action)
		{
			case MotionEvent.ACTION_DOWN: 			OnTouchStart(id, px, py);
			case MotionEvent.ACTION_CANCEL:			OnTouchCancel(id);
			case MotionEvent.ACTION_UP:				OnTouchEnd(id);
			case MotionEvent.ACTION_POINTER_DOWN:	OnTouchStart(id, px, py);				
			case MotionEvent.ACTION_POINTER_UP:		OnTouchEnd(id);	
			case MotionEvent.ACTION_MOVE:
			for (i in 0...p_event.getPointerCount())
			{
				if (i >= p_event.getPointerCount()) break;						
				id = p_event.getPointerId(i);
				var idx : Int = p_event.findPointerIndex(id);			
				if (idx >= 0) px = p_event.getX(idx);						 
				if (idx >= 0) py = p_event.getY(idx);
				OnTouchMove(id, px, py); 
			}
		}
	}
	
	/**
	 * Helper function to convert action code to string.
	 * @param	a
	 * @return
	 */
	private function ActionToString(a : Int) :String
	{
		switch (a)
		{					
			case MotionEvent.ACTION_DOWN: 				return "down";
			case MotionEvent.ACTION_MOVE: 				return "move";
			case MotionEvent.ACTION_POINTER_DOWN: 		return "pointer_down";
			case MotionEvent.ACTION_UP: 				return "up";
			case MotionEvent.ACTION_POINTER_UP: 		return "pointer_up";
			case MotionEvent.ACTION_OUTSIDE: 			return "outside";
			case MotionEvent.ACTION_CANCEL: 			return "cancel";
		}
		return "#"+a;
	}
}

#end