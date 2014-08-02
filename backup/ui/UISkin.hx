/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;

import js.html.Image;
import js.html.ImageData;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.math.Color;
import haxor.net.Web;
import haxor.ui.TextField;
import haxor.ui.UIEntity;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class UISkin extends Resource
{	
	
	static private var m_nodes : Array<ISkinnable> = [];
	
	static public function Add(p_node : ISkinnable):Void { m_nodes.push(p_node); }
	
	static public function Remove(p_node : ISkinnable):Void { m_nodes.remove(p_node); }
	
	/**
	 * 
	 */
	static public var current(get_current, set_current):UISkin;
	static private function get_current():UISkin { return m_current; }
	static private function set_current(v:UISkin):UISkin 
	{ 
		if (m_current == v) return v; 
		m_current = v; 
		if (v != null) for (i in 0...m_nodes.length) m_nodes[i].OnSkinChange(v);
		return v; 
	}
	static private var m_current : UISkin;
	
	/**
	 * 
	 */
	static public var list : Array<UISkin> = [];
	
	/**
	 * 
	 */
	public var skins(get_skins, never):Array<BaseSkin>;
	private function get_skins() : Array<BaseSkin> { return m_skins.copy(); }
	private var m_skins : Array<BaseSkin>;
	
	
	private var m_table : Map<String,BaseSkin>;
	
	private var m_is_dependence : Bool;
	
	private var m_root : String;
	
	/**
	 * 
	 * @param	p_skin_data
	 */
	public function new(p_data : Xml) 
	{
		super();		
		m_skins = [];
		m_table = new Map<String,BaseSkin>();
		m_is_dependence = Asset.m_dependenceEnabled;
		
		var elements : Iterator<Xml> = p_data.elementsNamed("skin");
		var n : Xml = elements.next();
		name   = n.exists("id") ? n.get("id") : "default";
		m_root = n.exists("root") ? n.get("root") : "";
		elements = n.elements();
		for (it in elements) TraverseSkinStep(it);		
		
		list.push(this);
		if (list.length == 1) current = this;
	}	
	
	public function Get(p_skin : String):BaseSkin { return m_table.exists(p_skin) ? m_table.get(p_skin) : null; }
	
	private function ParseSkinNode(n : Xml):Void
	{		
		switch(n.nodeName)
		{				
			case "image": CreateImageSkin(n);			
			case "filter":CreateFilterSkin(n);
			case "text":  CreateTextSkin(n);
			case "skin": 
			{
				var s : BaseSkin = new BaseSkin();
				s.id  = n.exists("id") ? n.get("id") : "default";
				s.xml = n;
				m_table.set(s.id, s);
			}
		}		
	}
	
	private function CreateImageSkin(p_node : Xml):Void
	{
		var src : String;
		var img : Image;
		var n : Xml = p_node;
		var nid : String = n.exists("id") ? n.get("id") : "default";
		var s : ImageSkin = new ImageSkin();
		s.xml = p_node;
		s.src = src = m_root + (n.exists("src") ? n.get("src") : "");
		if (src != "") s.image = m_is_dependence ? Asset.LoadImage(nid, src) : Web.LoadImage(src, function(d : Image, p : Float):Void { } );
		var sstr : String = n.exists("slices") ? n.get("slices") : "";
		var stk  : Array<String> = sstr.split(" ");				
		s.slices = [];
		for (i in 0...stk.length) s.slices.push(Std.parseInt(stk[i]));				
		m_table.set(nid, s);
	}
	
	private function CreateTextSkin(p_node : Xml):Void
	{
		var n : Xml = p_node;
		var nid : String = n.exists("id") ? n.get("id") : "default";
		var s : TextSkin = new TextSkin();				
		s.xml = p_node;
		s.font = n.exists("font") ? n.get("font") : "Arial, sans serif";
		s.size = n.exists("size") ? Std.parseInt(n.get("size")) : 12;		
		s.color = Color.FromHex(n.exists("color") ? n.get("color") : "0x0");
		var ta : String = (n.exists("aligment") ? n.get("aligment") : "l").toLowerCase();
		s.aligment = TextAligment.Left;
		switch(ta)
		{
			case "l": s.aligment = TextAligment.Left;
			case "c": s.aligment = TextAligment.Center;
			case "r": s.aligment = TextAligment.Right;
			case "ml": s.aligment = TextAligment.MiddleLeft;
			case "mc": s.aligment = TextAligment.MiddleCenter;
			case "mr": s.aligment = TextAligment.MiddleRight;
			case "bl": s.aligment = TextAligment.BottomLeft;
			case "bc": s.aligment = TextAligment.BottomCenter;
			case "br": s.aligment = TextAligment.BottomRight;
			case "j": s.aligment  = TextAligment.Justify;
		}
		var ts : String = (n.exists("style") ? n.get("style") : "regular").toLowerCase();
		s.style = TextStyle.Regular;
		switch(ts)
		{
			case "regular": 	s.style = TextStyle.Regular;
			case "bold":    	s.style = TextStyle.Bold;
			case "italic":  	s.style = TextStyle.Italic;
			case "bold italic": s.style = TextStyle.BoldItalic;
		}				
		m_table.set(nid, s);
	}
	
	private function CreateFilterSkin(p_node : Xml):Void
	{
		var n : Xml = p_node;
		var nid : String  = n.exists("id") ? n.get("id") : "default";
		var type : String = n.exists("type") ? n.get("type") : "";
		
		var s : BaseSkin = new BaseSkin();
		s.xml = p_node;
		var a :String = "";
		s.id = nid;
		
		var elements : Iterator<Xml> = p_node.elements();
		
		for (it in elements)
		{		
			var fn : String = it.nodeName;			
			switch(fn)
			{
				case "blur":    s.filter.blur = Std.parseInt(it.firstChild().toString() == "" ? "1" : it.firstChild().toString());
				case "shadow":
					s.filter.shadow.x 	  = Std.parseInt(it.exists("x") ? it.get("x") : "0");
					s.filter.shadow.y 	  = Std.parseInt(it.exists("y") ? it.get("y") : "0");
					s.filter.shadow.color = Color.FromHex(it.exists("color") ? it.get("color") : "0x0");
					s.filter.shadow.blur  = Std.parseInt(it.exists("blur") ? it.get("blur") : "0");
				
				case "text_shadow":
					s.filter.textShadow.x 	  = Std.parseInt(it.exists("x") ? it.get("x") : "0");
					s.filter.textShadow.y 	  = Std.parseInt(it.exists("y") ? it.get("y") : "0");
					s.filter.textShadow.color = Color.FromHex(it.exists("color") ? it.get("color") : "0x0");
					s.filter.textShadow.blur  = Std.parseInt(it.exists("blur") ? it.get("blur") : "0");
					
				case "box_shadow":
					s.filter.boxShadow.x 	  = Std.parseInt(it.exists("x") ? it.get("x") : "0");
					s.filter.boxShadow.y 	  = Std.parseInt(it.exists("y") ? it.get("y") : "0");
					s.filter.boxShadow.color  = Color.FromHex(it.exists("color") ? it.get("color") : "0x0");
					s.filter.boxShadow.blur   = Std.parseInt(it.exists("blur") ? it.get("blur") : "0");
					
				case "text_stroke":
					s.filter.textStroke.color = Color.FromHex(it.exists("color") ? it.get("color") : "0x0");
					s.filter.textStroke.width = Std.parseInt(it.exists("width") ? it.get("width") : "0");
				
				case "brightness":	s.filter.brightness = Std.parseFloat(it.firstChild().toString() == "" ? "1" : it.firstChild().toString());
				case "contrast":	s.filter.contrast   = Std.parseFloat(it.firstChild().toString() == "" ? "1" : it.firstChild().toString());
				case "grayscale":   s.filter.grayscale  = Std.parseFloat(it.firstChild().toString() == "" ? "0" : it.firstChild().toString());
				case "hue":			s.filter.hue        = Std.parseInt(it.firstChild().toString() == "" ? "0" : it.firstChild().toString());
				case "invert":		s.filter.invert     = Std.parseFloat(it.firstChild().toString() == "" ? "0" : it.firstChild().toString());
				case "sepia": 		s.filter.sepia 		= Std.parseFloat(it.firstChild().toString() == "" ? "0" : it.firstChild().toString());
				case "saturate":	s.filter.saturate   = Std.parseFloat(it.firstChild().toString() == "" ? "1" : it.firstChild().toString());
			}
		}	
		m_table.set(nid, s);
	}
	
	
	
	private function TraverseSkinStep(p_node : Xml)
	{		
		if (p_node.parent != null) if (p_node.parent.nodeName == "filter") return;
		ParseSkinNode(p_node);		
		var elements : Iterator<Xml> = p_node.iterator();
		for (it in elements) TraverseSkinStep(it);	
	}
}

class BaseSkin
{
	public var id : String;
	
	public var xml : Xml;
	
	public var filter : UIFilter;
	
	public function new()
	{		
		filter = new UIFilter();	
		id = "";
	}
}

class TextSkin extends BaseSkin
{
	public var font 	: String;	
	public var size 	: Int;
	public var color 	: Color;
	public var style 	: TextStyle;
	public var aligment : TextAligment;
	
	public function new()
	{
		super();
		font 	 = "'Trebuchet MS','Lucida Sans Unicode', 'Lucida Grande', sans-serif";
		size 	 = 12;
		color 	 = Color.black;
		style 	 = TextStyle.Regular;
		aligment = TextAligment.Left;
	}
}

class ImageSkin extends BaseSkin
{
	public var image : Image;		
	public var src : String;
	public var slices : Array<Int>;
	
	public function new()
	{	
		super();
		src = "";
		slices = [];
	}
}
