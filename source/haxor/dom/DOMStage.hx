#if html

package haxor.dom;
import haxor.math.AABB2;
import js.html.HTMLCollection;
import haxor.platform.Types.Float32;
import haxor.context.EngineContext;
import haxor.math.Mathf;
import haxor.io.file.Asset;
import js.html.NodeList;
import js.html.MouseEvent;
import haxor.core.IResizeable;
import js.html.Element;

/**
 * Class that contains all DOM entities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class DOMStage extends Container  implements IResizeable
{
	/**
	 * Ignores size set.
	 * @param	v
	 * @return
	 */
	override function set_width(v:Float32):Float32 { return v; }
	override function set_height(v:Float32):Float32 { return v; }
	
	/**
	 * Holds the creates DOMStage instance.
	 */
	static private var m_instance : DOMStage;
	
	/**
	 * Root DOM element.
	 */
	private var m_container : Element;

	/**
	 * Creates the DOMStage which will contain all DOMEntities in the application.
	 * @param	p_container
	 */
	private function new(p_container:Element) 
	{
		m_instance = this;
		super(p_container, "stage");
		EngineContext.resize.Add(this);		
	}
	
	/**
	 * Resize callback.
	 * @param	p_width
	 * @param	p_height
	 */
	public function OnResize(p_width:Float, p_height:Float):Void
	{	
		m_width  = p_width;
		m_height = p_height;		
		UpdateRect();		
	}
	
	/**
	 * Traverse the DOM tree and create the UI hierarchy from the tags.
	 * @param	n
	 * @param	c
	 */
	static private function BuildStep(n:Element, p : Container) : Bool
	{
		var e : DOMEntity=null;
		if (n == null) return false;
		if (p != null)
		{			
			switch(n.nodeName.toLowerCase())
			{
				case "container":	e = BuildContainer(n);
				case "sprite":		e = BuildSprite(n);
			}
			if (e != null)
			{
				p.AddChild(e);
			}
			else
			if (p.element != null)
			{
				
				if (n.getAttribute("script") == null)
				{
					if (p.element != n)
					{						
						p.element.appendChild(n);
						return true;
					}
				}				
			}
		}
		
		if (Std.is(e, Container))
		{		
			var l : HTMLCollection = n.children;		
			var i : Int = 0;
			while(i < l.length)
			{
				var it : Element = cast l.item(i);			
				var is_dom : Bool = BuildStep(it, cast e);				
				if (is_dom) i--;
				i++;
			}
		}
		return false;
	}
	
	/**
	 * Build a sprite instance from the HTMLElement
	 * @param	n
	 * @return
	 */
	static private function BuildSprite(n : Element):Container
	{
		var a_src : String = _ss(n.getAttribute("src"));
		var a_canvas : Bool  = n.getAttribute("canvas") != null;
		var a_pattern : Bool = n.getAttribute("pattern") != null;
		var res : Sprite = new Sprite(a_src, a_canvas);		
		res.pattern = a_pattern;
		BuildDOMEntity(n, res);
		return res;
	}
	
	/**
	 * Creates a new Container from the HTMLElement
	 * @param	n
	 * @return
	 */
	static private function BuildContainer(n : Element):Container
	{
		var res : Container = new Container();				
		BuildDOMEntity(n, res);
		return res;
	}
	
	/**
	 * Constructs the DOMEntity with some basic data common for all elements.
	 * @param	n
	 * @param	e
	 */
	static private function BuildDOMEntity(n : Element, e : DOMEntity):Void
	{
		var sa : String;
		sa = n.getAttribute("name");		
		if (sa != null) if (sa != "") e.name = _ss(sa);
		
		sa = n.getAttribute("style");
		if (sa != null) if (sa != "") e.element.style.cssText = sa;
		
		if (e.element != null) e.element.style.position = "absolute";
		
		var pivot 	 : Array<Float> = _tv(n.getAttribute("px"), n.getAttribute("py"), n.getAttribute("pxy"));
		var position : Array<Float> = _tv(n.getAttribute("x"), n.getAttribute("y"), n.getAttribute("xy"));
		var scale 	 : Array<Float> = _tv(n.getAttribute("sx"), n.getAttribute("sy"), n.getAttribute("sxy"),1,1);
		var size 	 : Array<Float> = _tv(n.getAttribute("w"), n.getAttribute("h"), n.getAttribute("wh"));		
		var tv : Array<Float>;
		var v : Array<Float> = [0];
		var fx : Int;
		var fy : Int;		
		
		tv = scale;	e.sx = tv[2];	e.sy = tv[3];		
		
		tv = pivot; fx = LayoutFlag.PivotX; fy = LayoutFlag.PivotY;		
		if (tv[0] > 0) { e.layout.flag |= fx; e.layout.px = tv[2]; } else { e.px = tv[2]; }
		if (tv[1] > 0) { e.layout.flag |= fy; e.layout.py = tv[3]; } else { e.py = tv[3]; }		
		
		tv = position; fx = LayoutFlag.PositionX; fy = LayoutFlag.PositionY;		
		if (tv[0] > 0) { e.layout.flag |= fx; e.layout.x = tv[2]; } else { e.x = tv[2]; }
		if (tv[1] > 0) { e.layout.flag |= fy; e.layout.y = tv[3]; } else { e.y = tv[3]; }		
		
		tv = size; fx = LayoutFlag.SizeX; fy = LayoutFlag.SizeY;		
		if (tv[0] > 0) { e.layout.flag |= fx; e.layout.width  = tv[2]; } else { e.width  = tv[2]; }
		if (tv[1] > 0) { e.layout.flag |= fy; e.layout.height = tv[3]; } else { e.height = tv[3]; }		
		
		_sn(n.getAttribute("alpha"),    v, 1.0); e.alpha    = v[0];
		_sn(n.getAttribute("rotation"), v, 0.0); e.rotation = v[0];		
	
		sa = n.getAttribute("margin");
		if (sa != null) 
		if (sa != "")
		{
			var mtk : Array<String> = sa.split(" ");
			var m : AABB2 = e.layout.m_margin;
			var n : Float = 0.0;
			if (mtk.length == 1)
			{
				n = Std.parseFloat(mtk[0]);
				m.Set(n, n, n, n);
			}
			else
			{
				if (mtk.length >= 1) { n = Std.parseFloat(mtk[0]); m.xMin = n; }
				if (mtk.length >= 2) { n = Std.parseFloat(mtk[1]); m.xMax = n; }
				if (mtk.length >= 3) { n = Std.parseFloat(mtk[2]); m.yMin = n; }
				if (mtk.length >= 4) { n = Std.parseFloat(mtk[3]); m.yMax = n; }
			}
			e.layout.margin = m;
		}
		
	}
	
	/**
	 * Shortcut to sample transform stuff.
	 * @param	sx
	 * @param	sy
	 * @param	sxy
	 * @param	v
	 * @return
	 */
	static private function _tv(sx:String,sy:String,sxy:String,v0 : Float=0.0,v1 : Float=0.0):Array<Float>
	{
		
		var res : Array<Float> = [0, 0, 0, 0];
		var v : Array<Float> = [0];
		var ixr : Bool = false;
		var iyr : Bool = false;
		if (sxy != null)	
		{ 
			var sl:Array<String> = sxy.split(" ");			
			if (sl.length == 1)
			{ 
				ixr = ixr || _sn(sl[0], v); 
				iyr = iyr || ixr;
				res[2] = v[0];  
				res[3] = v[0];  
			}
			
			if (sl.length >= 2)
			{
				ixr = ixr || _sn(sl[0], v); res[2] = v[0];  
				iyr = iyr || _sn(sl[1], v); res[3] = v[0];
			}			
		}
		else
		{
			if (sx != null)	{ ixr = ixr || _sn(sx, v); res[2] = v[0]; } 		
			if (sy != null)	{ iyr = iyr || _sn(sy, v); res[3] = v[0]; }		
		}
		
		if (sxy == null) if (sx == null) res[2] = v0;
		if (sxy == null) if (sy == null) res[3] = v1;
		
		if (ixr) res[2] = Mathf.Abs(res[2]) <= 0.000001 ? 0.0 : (res[2] / 100);
		if (iyr) res[3] = Mathf.Abs(res[3]) <= 0.000001 ? 0.0 : (res[3] / 100);		
		res[0] = ixr ? 1 : 0;
		res[1] = iyr ? 1 : 0;		
		
		return res;
	}
	
	/**
	 * Shortcut to check if a transform value is relative or not and return it parsed.
	 * @param	s
	 * @param	v
	 * @return
	 */
	static private function _sn(s:String, v:Array<Float>,?n:Float):Bool 
	{		
		if (s == null) { v[0] = n; return false; }
		var isr : Bool = false;
		if (s.indexOf("%") >= 0) { isr = true; s = StringTools.replace(s, "%", ""); }
		v[0] = Std.parseFloat(s);
		return isr;
	}
	
	/**
	 * Shortcut to return the string or fetch it from dictionary.
	 * @param	s
	 * @return
	 */
	static private function _ss(s:String):String 
	{ 
		if (s == null) return ""; 		
		return (s.indexOf("@") == 0) ? Asset.Get(s.substr(1)) : s;
	}
	
}

#end