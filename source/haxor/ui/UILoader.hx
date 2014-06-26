/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class UILoader extends Container
{
	
	private var m_complete : Bool;
	
	private var m_finished : Bool;
	
	public function new() 
	{
		super();		
		layout.flag  = LayoutFlag.SizeXY;
		layout.width = layout.height = 1.0;
		m_complete = false;
		m_finished = false;
	}
	
	public function OnElementProgress(p_id : String,p_float : Float):Void { }
	
	public function OnElementComplete(p_id:String):Void { }
	
	public function OnProgress(p_float : Float):Void { }
	
	public function OnComplete():Void 
	{
		Finish();
	}
	
	public function Finish():Void
	{
		Remove();		
		m_finished = true;
	}
	
	public function Remove():Void
	{
		parent.RemoveChild(this);
	}
	
}