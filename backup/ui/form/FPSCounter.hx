/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui.form;
import js.html.Event;
import haxor.component.Transform;
import haxor.core.Console;
import haxor.core.Engine;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Color;
import haxor.ui.Layout;
import haxor.ui.LayoutFlag;
import haxor.ui.TextField;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class FPSCounter extends TextField implements IUpdateable
{
	
	private var m_rate : Float;
	
	private var m_elapsed : Float;
	
	private var m_frames : Float;
	
	private var m_samples : Array<Float>;

	public function new(p_refresh_rate = 1.0) 
	{
		super();
		m_rate = p_refresh_rate;
		m_elapsed = 0;
		m_frames = 0;
		
		m_samples = [];
		
		text = "0fps";
		
		layout.x = 1;
		fontSize = 18;
		layout.flag = LayoutFlag.PositionX;
		y = 0;
		px = 205;
		width = 200;		
		
		height = textHeight;		
		
		aligment = TextAligment.Right;
		color = Color.yellow;
		filters.textShadow.color = Color.black;
		filters.textShadow.y = 2;	
		wordwrap = false;
		//m_field.style.border = "1px solid yellow";
		//m_element.style.border = "1px solid red";
		
		mouseEnabled = false;
		
		m_element.onselect = function(e:Event):Void { e.preventDefault(); };
		
		Engine.Add(this);
	}
	
	public function OnUpdate():Void
	{
		
		m_elapsed += Time.frameDeltaTime;
		if (m_elapsed >= m_rate)
		{
			m_elapsed -= m_rate;
			m_samples.push(m_frames / m_rate);
			var avg : Float = 0.0;
			for (i in 0...m_samples.length) avg += m_samples[i] / m_samples.length;
			if (m_samples.length > 1) m_samples.shift();
			text = Std.int(avg) + "fps "+Transform.m_threaded;
			m_frames = 0;
			return;
		}		
		m_frames+=1;
	}
	
}