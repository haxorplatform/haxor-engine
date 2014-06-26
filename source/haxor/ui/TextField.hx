/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import haxor.core.Application;
import js.Browser;
import js.html.ClientRect;
import js.html.DivElement;
import js.html.Element;
import js.html.Event;
import js.html.InputElement;
import js.html.ParagraphElement;
import js.html.SpanElement;
import js.html.TextAreaElement;
import haxor.core.Console;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.ui.form.FPSCounter;
import haxor.ui.UISkin;

enum TextStyle
{
	Regular;
	Italic;
	Bold;
	BoldItalic;	
}

enum TextAligment
{
	Left;
	Center;
	Right;
	Justify;
	//JustifyRight;
	MiddleLeft;
	MiddleCenter;
	MiddleRight;	
	BottomLeft;
	BottomCenter;
	BottomRight;
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class TextField extends UIEntity
{
	
	override private function set_name(v:String):String 
	{
		super.set_name(v);
		m_field.setAttribute("name", v);
		return v;
	}
	
	public var element(get_element, never):DivElement;
	private function get_element():DivElement { return cast m_element; }
	
	public var field(get_field, never):Element;
	private function get_field():Element { return cast m_field; }
	
	public var font(get_font, set_font):String;
	private function get_font():String { return m_font; }
	private function set_font(v:String):String
	{
		
		m_font = v;
		m_field.style.fontFamily = v;
		UpdateRect();		
		return v;
	}	
	private var m_font : String;
	
	public var fontSize(get_fontSize, set_fontSize):Int;
	private function get_fontSize():Int { return m_fontSize; }
	private function set_fontSize(v:Int):Int
	{
		m_fontSize = v;
		m_field.style.fontSize = v + "pt";
		UpdateRect();
		return v;
	}	
	private var m_fontSize : Int;
	
	public var fontStyle(get_fontStyle, set_fontStyle):TextStyle;
	private function get_fontStyle():TextStyle { return m_fontStyle; }
	private function set_fontStyle(v:TextStyle):TextStyle
	{
		m_fontStyle = v;
		switch(v)
		{
			case TextStyle.Regular: 	m_field.style.fontWeight = "normal"; m_field.style.fontStyle  = "normal";
			case TextStyle.Bold:    	m_field.style.fontWeight = "bold";
			case TextStyle.BoldItalic:  m_field.style.fontWeight = "bold";   m_field.style.fontStyle  = "italic";
			case TextStyle.Italic:      m_field.style.fontWeight = "normal"; m_field.style.fontStyle  = "italic";			
		}
		UpdateRect();
		return v;
	}	
	private var m_fontStyle : TextStyle;
	
	public var aligment(get_aligment, set_aligment):TextAligment;
	private function get_aligment():TextAligment { return m_aligment; }
	private function set_aligment(v:TextAligment):TextAligment
	{
		m_aligment = v;
		//m_field.style.direction = "ltr";
		switch(v)
		{
			case TextAligment.Left:	    m_field.style.textAlign = "left";		
			case TextAligment.Center:   m_field.style.textAlign = "center";
			case TextAligment.Right:    m_field.style.textAlign = "right";
			case TextAligment.Justify:  m_field.style.textAlign = "justify";
			
			//case TextAligment.JustifyRight:
			//m_field.style.textAlign = "justify";
			//m_field.style.direction = "rtl";
			
			
			case TextAligment.MiddleLeft:	   m_field.style.textAlign = "left";	
			case TextAligment.MiddleCenter:  m_field.style.textAlign = "center";
			case TextAligment.MiddleRight:   m_field.style.textAlign = "right";
			
			
			case TextAligment.BottomLeft:	m_field.style.textAlign = "left";		
			case TextAligment.BottomCenter: m_field.style.textAlign = "center";
			case TextAligment.BottomRight:  m_field.style.textAlign = "right";
		}
		UpdateRect();		
		return v;
	}	
	private var m_aligment : TextAligment;
	 
	
	public var text(get_text, set_text):String;
	private function get_text():String 
	{ 
		var f : Dynamic = m_field;
		if (Std.is(f,InputElement))
		{			
			return f.value;
		}
		return m_text; 
	}
	
	private function set_text(v:String):String 
	{ 
		m_text = v; 				
		var f : Dynamic = m_field;
		if (Std.is(f,InputElement))
		{			
			f.value = v;			
		}
		else
		{
			if (m_html) f.innerHTML = v; else f.textContent = v;
		}				
		UpdateRect(); 
		return v; 
	}
	private var m_text : String;
	
	public var color(get_color, set_color):Color;
	private function get_color():Color { return m_color.clone; }
	private function set_color(v:Color):Color { m_color = v.clone; m_field.style.color = v.css; return v; }
	private var m_color : Color;
	
	public var textWidth(get_textWidth, never):Float;
	private function get_textWidth():Float 
	{
		if (appended) 
		return m_field.clientWidth;
		var cp : Element = cast m_element.cloneNode(true);
		Browser.document.body.appendChild(cp);				
		var len : Int = cp.firstElementChild.clientWidth;
		Browser.document.body.removeChild(cp);				
		return len; 
	}
	
	public var textHeight(get_textHeight, never):Float;
	private function get_textHeight():Float 
	{ 		
		if (appended) 
		return m_field.clientHeight;
		var cp : Element = cast m_element.cloneNode(true);
		Browser.document.body.appendChild(cp);				
		var len : Int = cp.firstElementChild.clientHeight;
		Browser.document.body.removeChild(cp);				
		return len; 
	}
	
	public var lineHeight(get_lineHeight, never):Float;
	private function get_lineHeight():Float 
	{ 
		var len : Int = 0;
		var f : Dynamic = m_field.cloneNode(true);
		Browser.document.body.appendChild(f);
		var t : String = Std.is(f,InputElement) ? f.value : f.innerHTML;				
		if (Std.is(f, InputElement))  f.value = "W"; else f.innerHTML = "W";
		len = f.clientHeight;		
		Browser.document.body.removeChild(f);
		return len; 
	}
	
	public var wordwrap(get_wordwrap, set_wordwrap):Bool;
	private function get_wordwrap():Bool { return m_wordwrap; }
	private function set_wordwrap(v:Bool):Bool 
	{ 
		m_wordwrap = v; 
		m_element.style.whiteSpace = v ? "normal" : "nowrap";  
		m_field.style.width = v ? "100%" : "";
		UpdateRect();
		return v; 
	}
	private var m_wordwrap : Bool;
	
	public var html(get_html, set_html):Bool;
	private function get_html():Bool { return m_html; }
	private function set_html(v:Bool):Bool 
	{ 
		m_html = v;
		text = m_text;
		return v; 
	}
	private var m_html : Bool;
	
	public var password(get_password, set_password):Bool;
	private function get_password():Bool {  if (input) { var ie : Dynamic = cast m_field;  return ie.type == "password"; } else return false; }
	private function set_password(v:Bool):Bool {  if (input) { var ie : Dynamic = cast m_field; ie.type = v ? "password" : "text"; }  return v; }
	
	public var caption(get_caption, set_caption):String;
	private function get_caption():String { if (input) { var ie : Dynamic = cast m_field; return ie.placeholder; } else return ""; }
	private function set_caption(v:String):String {  if (input) { var ie : Dynamic = cast m_field; ie.placeholder = v; }  return v; }
	
	public var maxchar(get_maxchar, set_maxchar):Int;
	private function get_maxchar():Int { if (input) { var ie : Dynamic = cast m_field; return ie.maxLength; } else return 0; }
	private function set_maxchar(v:Int):Int {  if (input) { var ie : Dynamic = cast m_field; ie.maxLength = v; }  return v; }
	
	
	public var input(get_input, never):Bool;
	private function get_input():Bool 
	{ 
		return Std.is(m_field, InputElement) || Std.is(m_field,TextAreaElement);
	}
	
	public var onarearesize : Int -> Int -> Void;
	
	private var m_field : Element;
	
	private var m_taw : Int;
	private var m_tah : Int;
	private var m_tacb : Int;

	public function new(p_tag : String = "span") 
	{
		m_element = Browser.document.createDivElement();
		m_field   = Browser.document.createElement(p_tag);
		m_field.style.position = "absolute";
		if ((p_tag == "input")||(p_tag=="textarea"))
		{
			var ie : InputElement = cast m_field;			
			if (ie != null) ie.type = "text";			
			m_field.style.background 		= "none";
			m_field.style.backgroundColor   = "rgba(0,0,0,0)";
			m_field.style.border 	 		= "none";		
			m_field.style.outline 	 		= "none";
			m_field.style.height			= "100%";
			m_field.style.setProperty("-webkit-user-select", "all", "");
			m_field.style.setProperty("-moz-user-select", "all", "");
			m_field.style.setProperty("-o-user-select", "all", "");
			m_field.style.setProperty("-ms-user-select", "all", "");
			
			
			m_field.addEventListener("input",function(e:Event):Void
			{
				UpdateRect();
			});
			
		}
		m_element.appendChild(m_field);
		
		m_aligment 	= TextAligment.Left;		
		m_fontStyle   = TextStyle.Regular;	
		
		m_text 		= "";		
		m_html      = false;
		m_fontSize  = 12;
		m_font 	    = "'Trebuchet MS','Lucida Sans Unicode', 'Lucida Grande', sans-serif";
		
		overflow 	= "hidden";		
		
		m_element.style.wordWrap = "break-word";
		m_field.style.wordWrap   = "break-word";
		
		m_wordwrap 	= false;
		
		m_field.style.textAlign = "left";
		m_field.style.fontWeight = "normal"; 
		m_field.style.fontStyle  = "normal";				
		m_field.style.fontSize = "12pt";		
		m_field.style.fontFamily = m_font;
		//m_field.style.border = "solid 1px yellow";
		//m_element.style.whiteSpace = "normal";
		m_element.style.whiteSpace = "nowrap";
		//m_field.style.width = "100%";
		m_field.style.width = "";
		
		
		
		color = Color.black;
		
		m_skin = "default";
		
		super();
		
		selectable = true;
		
		m_filters.target = m_field;
				
		if (input)
		{
			m_element.onclick = function(e:Event):Void { m_field.focus(); }
			
			if (Std.is(m_field,TextAreaElement))
			{				
				m_tacb = Browser.window.setInterval(function()
				{
					var fsw : Int = Std.parseInt(StringTools.replace(m_field.style.width, "px", ""));
					var fsh : Int = Std.parseInt(StringTools.replace(m_field.style.height, "px", ""));
					var dw : Int = fsw - m_taw;
					var dh : Int = fsh - m_tah;
					
					if (Mathf.Abs(dw) <= 0) if (Mathf.Abs(dh) <= 0) return;
					if (onarearesize != null) onarearesize(dw, dh);
										
				}, 30);
			}
			
		}
	}
	
	override private function UpdateRect():Void 
	{
		
		super.UpdateRect();
		
		var r  : AABB2 = rect;
		var rw : Float = r.width;
		
		
		var rh : Float = r.height;
		var tx : Float = 0;
		var ty : Float = 0;
		
		var tw : Float = wordwrap ? rw : textWidth;
		var th : Float = textHeight+2;
		
		switch(m_aligment)
		{
			case TextAligment.Left:	    tx = 0.0; ty = 0.0;
			case TextAligment.Center:   tx = 0.5; ty = 0.0;
			case TextAligment.Right:    tx = 1.0; ty = 0.0;
			case TextAligment.Justify:       tx = 0.0; ty = 0.0;
			//case TextAligment.JustifyRight:  tx = 1.0; ty = 0.0;
			
			case TextAligment.MiddleLeft:     tx = 0.0; ty = 0.5;
			case TextAligment.MiddleCenter:   tx = 0.5; ty = 0.5;
			case TextAligment.MiddleRight:    tx = 1.0; ty = 0.5;			
			
			case TextAligment.BottomLeft:	tx = 0.0; ty = 1.0;
			case TextAligment.BottomCenter: tx = 0.5; ty = 1.0;
			case TextAligment.BottomRight:  tx = 1.0; ty = 1.0;
		}
		
		m_field.style.left  = ((rw - tw) * tx) + "px";
		m_field.style.top   = ((rh - th) * ty) + "px";
		
		if (Std.is(m_field, TextAreaElement))
		{
			var ta : TextAreaElement = cast m_field;
			ta.style.width  = (m_taw = cast(rw - 4)) + "px";
			ta.style.height = (m_tah = cast(rh - 4 - 8)) + "px";
			ta.style.top = "4px";			
		}
		
		
		
		
	}
	
	override public function OnSkinChange(p_skin:UISkin):Void 
	{
		var s : TextSkin = cast p_skin.Get(m_skin);				
		if (s != null)
		{
			font 	  = s.font;
			fontSize  = s.size;
			fontStyle = s.style;
			color     = s.color;
			aligment  = s.aligment;		
		}		
	}
}
