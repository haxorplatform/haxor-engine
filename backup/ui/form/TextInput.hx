/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui.form;
import haxor.math.AABB2;
import haxor.ui.LayoutFlag;
import haxor.ui.TextField;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TextInput extends Button
{
	
	override private function set_skin(v:String):String 
	{
		m_field.skin = v + ".field";
		super.set_skin(v);
		return v;
	}
	
	public var field(get_field, never):TextField;
	private function get_field():TextField { return m_field; }
	private var m_field : TextField;
	
	public function new(p_multiline : Bool = false,p_use_canvas : Bool=true) 
	{
		if(m_skin==null) m_skin = "text_input";
		
		m_field = new TextField(p_multiline ? "textarea" : "input");
		
		super(p_use_canvas);
		
		m_element.removeChild(m_input);
		
		m_field.layout.flag = LayoutFlag.SizeXY;
		m_field.layout.width  = m_field.layout.height = 1;		
		m_field.layout.margin = AABB2.FromMinMax(4, 4, 0, 0);
		
		m_field.text = "W";
		height = m_field.textHeight;
		m_field.text = "";
		
		m_input = cast m_field.m_field;
		
		if (p_multiline)
		{
			m_field.onarearesize = function(p_dx : Int, p_dy : Int):Void
			{
				width  += p_dx;
				height += p_dy;
			};
		}
		
		AddChild(m_field);
		
	}
	
}