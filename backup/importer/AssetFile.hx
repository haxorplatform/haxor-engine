package haxor.importer;
import haxor.graphics.Material;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AssetFile<T>
{
	
	private var x : Xml;

	public function new(p_src : String) 
	{	
		x = Xml.parse(p_src);				
		TraverseStep(x.firstElement());
	}
	
	public function GetAsset() : T
	{		
		return null;
	}
	
	private function Parse(n : Xml):Void
	{
		
	}
	
	private function TraverseStep(n : Xml):Void
	{
		Parse(n);
		var l : Iterator<Xml> = n.elements();		
		while (l.hasNext()) TraverseStep(l.next());		
	}
	
	private function _f32a(v : String) : Array<Float>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");
		var a : Array<Float> = [];
		for (i in 0...l.length) a.push(Std.parseFloat(l[i]));
		return a;
	}
	
	private function _i16a(v : String) : Array<Int>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");		
		var a : Array<Int> = [];
		for (i in 0...l.length) a.push(Std.parseInt(l[i]));
		return a;
	}
	
	private function _i16ta(v : String,s:Int) : Array< Array<Int> >
	{		
		var l  : Array<String>  = StringTools.trim(StringTools.replace(v, "\n", " ")).split(" ");
		var tl : String 		= "";
		var a : Array< Array<Int> > 		= [];
		var bf : Array<Int>;
		var k :Int = 0;
		
		while(k < l.length)
		{			
			bf = [];
			for (j in 0...s) bf.push(Std.parseInt(l[k++]));
			a.push(bf);
		}
		return a;
	}
	
	private function _a(n : Xml, a : String, v : Dynamic = null) : String { return n.exists(a) ? n.get(a) : v;	}
	
	private function _tla(n : Xml, a : String, v : Dynamic=null) : String { return n.exists(a) ? StringTools.trim(n.get(a)).toLowerCase() : v;	}
	
	private function _p(n : Xml, p : String, v : Dynamic=null,t:Bool=false,tl:Bool=false) : Dynamic
	{
		var l : Array<String> = p.split(".");
		var it : Xml = n;
		for (i in 0...l.length)
		{
			var tk : String = l[i];			
			switch(tk)
			{
				case "$text": 
					if (it.firstChild() == null) return v;
					var txt : String = it.firstChild().toString();
					if (t) txt = StringTools.trim(txt);
					if (tl) txt = txt.toLowerCase();
					return txt;
					
				default:
				if (tk.charAt(0) == "@")
				{
					if (t) if (tl) return _tla(it, tk.substr(1), v);
					return _a(it, tk.substr(1), v);
				}
				var eit : Iterator<Xml> = it.elementsNamed(tk);
				if (eit == null) 	return v;
				if (i == (l.length - 1)) return eit;
				if (!eit.hasNext()) return v;				
				it = eit.next();
			}
		}
		return v;
	}
	
	private function _f(n : Xml, p : String, a : String, t : String) : Xml
	{
		var f	: Dynamic = _p(n, p, "");
		var it : Iterator<Xml> = f == "" ? null : (cast f);
		if (it == null) return null;
		while (it.hasNext()) {	var e : Xml = it.next(); if (_a(e, a, "") == t) return e; }
		return null;
	}
	
}