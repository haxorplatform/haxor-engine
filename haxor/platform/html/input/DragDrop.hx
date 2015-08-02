#if html

package haxor.platform.html.input;
import js.html.EventTarget;
import js.html.Event;
import js.html.Element;


/**
 * Class that handles HTML drag and drop operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class DragDrop
{

	/**
	 * List of targets for dragdrop operations.
	 */
	static private var m_targets : Array<EventTarget> = [];
	
	/**
	 * List of listeners.
	 */
	static private var m_listeners : Array<EventTarget->String->Event->Void> = [];
	
	/**
	 * List of relevant events for dragging.
	 */
	static private var m_events : Array<String> = [ "drag", "dragend", "dragenter", "dragleave", "dragover", "dragstart", "drop" ];
	
	/**
	 * Adds a global listener for all elements registered for dragging.
	 * @param	p_callback
	 */
	static public function AddListener(p_callback : EventTarget->String->Event->Void):Void { if (m_listeners.indexOf(p_callback) < 0) m_listeners.push(p_callback); }
	
	/**
	 * Removes a registered listener.
	 * @param	p_callback
	 */
	static public function RemoveListener(p_callback : EventTarget->String->Event->Void):Void { if (m_listeners.indexOf(p_callback) >= 0) m_listeners.remove(p_callback); }
	
	/**
	 * Adds an element to receive dragdrop.
	 * @param	p_element
	 */
	static public function Add(p_element : EventTarget,p_callback : String->Event->Void=null):Void
	{
		if (m_targets.indexOf(p_element) >= 0) return;
		var el : Dynamic = p_element;
		el.__ddevl = function(ev:Event)
		{
			ev.preventDefault();
			ev.stopPropagation();
			var ev_type : String = "";						
			switch(ev.type)
			{				
				case "drag": 		ev_type = "drag";				
				case "dragend":		ev_type = "end";				
				case "dragenter":	ev_type = "enter";				
				case "dragleave":	ev_type = "leave";				
				case "dragover":	ev_type = "over";				
				case "dragstart":	ev_type = "start";				
				case "drop":		ev_type = "drop";				
			}
			if (ev_type == "") return;
			if (p_callback != null) p_callback(ev_type, ev);						
			for (cb in m_listeners) cb(p_element, ev_type, ev);
		};
		for (s in m_events) p_element.addEventListener(s,el.__ddevl);
	}
	
	/**
	 * Removes an element from the dragdrop workflow.
	 * @param	p_element
	 * @param	p_callback
	 */
	static public function Remove(p_element : EventTarget):Void
	{
		if (m_targets.indexOf(p_element) < 0) return;
		var el : Dynamic = p_element;
		for (s in m_events) p_element.removeEventListener(s,el.__ddevl);
	}
	
}

#end