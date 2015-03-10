package haxor.io.file;
import haxor.core.Resource;


/**
 * Base class that describes an Asset described as XML in the Editor context.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AssetXML extends AssetFile
{
	/**
	 * XML document.
	 */
	private var x : Xml;
	
	/**
	 * Creates a new AssetXML instance informing the source file of the XML.
	 * @param	p_name
	 * @param	p_src
	 */
	public function new(p_name:String,p_src : String) 
	{	
		super(p_name);
		x = Xml.parse(p_src);				
		TraverseStep(x.firstElement());
	}
	
	/**
	 * Callback called for each node during traversal.
	 * @param	n
	 */
	private function Parse(n : Xml):Void { }
	
	/**
	 * Internal traversal method.
	 * @param	n
	 */
	private function TraverseStep(n : Xml):Void
	{
		Parse(n);
		var l : Iterator<Xml> = n.elements();		
		while (l.hasNext()) TraverseStep(l.next());		
	}
	
	/**
	 * Auxiliar method to access an attribute and returns a default value if it doesn't exists.
	 * @param	n
	 * @param	a
	 * @param	v
	 * @return
	 */
	private function _a(n : Xml, a : String, v : Dynamic = null) : String { return n.exists(a) ? n.get(a) : v;	}
	
	/**
	 * Auxiliar method to access a trimmed attribute in lowercase and returns a default value if it doesn't exists.
	 * @param	n
	 * @param	a
	 * @param	v
	 * @return
	 */
	private function _tla(n : Xml, a : String, v : Dynamic=null) : String { return n.exists(a) ? StringTools.trim(n.get(a)).toLowerCase() : v;	}
	
	/**
	 * Navigates the XML in a similar-to XPath string.
	 * @param	n
	 * @param	p
	 * @param	v
	 * @param	t
	 * @param	tl
	 * @return
	 */
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
	
	/**
	 * Finds a XML within the informed node.
	 * @param	n
	 * @param	p
	 * @param	a
	 * @param	t
	 * @return
	 */
	private function _f(n : Xml, p : String, a : String, t : String) : Xml
	{
		var f	: Dynamic = _p(n, p, "");
		var it : Iterator<Xml> = f == "" ? null : (cast f);
		if (it == null) return null;
		while (it.hasNext()) {	var e : Xml = it.next(); if (_a(e, a, "") == t) return e; }
		return null;
	}
	
}