/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.ui.form;
import js.Browser;
import js.html.ButtonElement;
import js.html.Event;
import js.html.InputElement;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class CheckBox extends Toggle
{	
	
	public function new() 
	{			
		if(m_skin==null) m_skin = "checkbox";		
		super();		
		
	}
	
	override private function OnMouse(p_event:Event):Void 
	{				
		switch(p_event.type)
		{
			case "click"	 : toggle = !toggle;
		}
	}
	
}