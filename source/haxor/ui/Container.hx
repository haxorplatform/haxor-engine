/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import js.Browser;
import js.html.DivElement;
import js.html.Element;
import haxor.core.Console;
import haxor.math.Mathf;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Container extends UIEntity
{
	static public function Path(p_element : Element):String
	{
		var p : Array<String> = [];
		var it : Element = p_element;
		while (it != null)
		{
			if (it.hasAttribute("script"))
			{
				if (it.getAttribute("script") == "haxor.ui.Stage") break;
				p.push(it.getAttribute("name"));
			}
			it = it.parentElement;
		}		
		p.reverse();		
		return p.join(".");
	}
	
	public var element(get_element, never):DivElement;
	private function get_element():DivElement { return cast m_element; }
	
	public var childCount(get_childCount, never):Int;
	private function get_childCount():Int { return m_children == null ? 0 : m_children.length; }
	
	private var m_children : Array<UIEntity>;

	public function new() 
	{	
		m_element = Browser.document.createDivElement();
		m_children = [];		
		super();		
	}
	
	public function IsChild(p_child : UIEntity):Bool
	{
		if (m_children == null) return false;
		for (it in m_children) { if (it == p_child) return true; }
		return false;
	}
	
	public function AddChild(p_child : UIEntity):Void
	{		
		AddChildAt(p_child);
	}
	
	public function AddChildAt(p_child : UIEntity, p_index : Int = -1):Void
	{		
		if (p_child == this) return;
		if (IsChild(p_child)) return;
		if (p_child.parent != null)
		{
			p_child.parent.RemoveChild(p_child);
		}
		var pos : Int = p_index < 0 ? m_children.length : p_index;
		m_children.push(p_child);
		m_element.appendChild(p_child.m_element);
		p_child.m_parent = this;
		
		SetChildIndex(p_child, pos);
		UpdateTransform();
		UpdateRect();
		UpdateMaterial();
		if ((stage != null) || Std.is(this,Stage))
		{
			AddedToStage();
		}
	}
	
	public function RemoveChild(p_child : UIEntity):Void
	{
		if (!IsChild(p_child)) return;
		m_children.remove(p_child);
		m_element.removeChild(p_child.m_element);		
		p_child.m_parent = null;
	}
	
	public function GetChildByName(p_name : String):UIEntity
	{
		for (i in 0...m_children.length) if (m_children[i].name == p_name) return m_children[i];
		return null;
	}
	
	public function GetChildAt(p_index : Int):UIEntity
	{
		return m_children[p_index];
	}
	
	public function GetChildIndex(p_child : UIEntity):Int
	{
		for (i in 0...m_children.length) if (m_children[i] == p_child) return i;
		return -1;
	}
	
	public function SetChildIndex(p_child : UIEntity,p_index:Int) :Void
	{
		if (!IsChild(p_child)) return;		
		var p : Int = Mathf.ClampInt(p_index, 0, m_children.length - 1);
		if (p_child == m_children[p]) return;		
		var e1 : Element = m_children[p].m_element;
		m_element.removeChild(p_child.m_element);		
		m_element.insertBefore(p_child.m_element, e1);		
		m_children.remove(p_child);		
		m_children.insert(p, p_child);		
	}
	
	public function Find(p_path : String):UIEntity
	{
		var pth : Array<String> = p_path.split(".");
		if (pth.length <= 0) return null;
		var it : Dynamic = this;
		
		for (i in 0...pth.length)
		{
			var p : String = pth[i];
			it = it.GetChildByName(p);
			if (!Std.is(it, Container)) if (i >= (pth.length - 1)) return cast it;
		}
		return it;
	}
	
	public function Traverse(p_callback : Int -> UIEntity -> Bool):Void
	{
		TraverseStep(0,this, p_callback);
	}
	
	private function TraverseStep(d : Int,it : UIEntity, p_c : Int -> UIEntity -> Bool):Void
	{
		if (p_c != null) if(!p_c(d,it)) return;
		if (Std.is(it, Container))
		{
			var c : Container = cast it;
			for (i in 0...c.m_children.length)
			{
				TraverseStep(d+1,c.m_children[i], p_c);
			}
		}
	}
	
	override private function UpdateMaterial():Void 
	{
		super.UpdateMaterial();
		for (i in 0...m_children.length) m_children[i].UpdateMaterial();		
	}
	
	override private function UpdateTransform():Void 
	{
		super.UpdateTransform();
		for (i in 0...m_children.length) m_children[i].UpdateTransform();		
	}
	
	override private function UpdateRect():Void 
	{		
		super.UpdateRect();		
		for (i in 0...m_children.length) m_children[i].UpdateRect();
	}
	
	override function AddedToStage():Void 
	{
		super.AddedToStage();
		for (i in 0...m_children.length) m_children[i].AddedToStage();
	}
}