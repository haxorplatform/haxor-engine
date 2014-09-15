package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_elements_203__Fun extends haxe.lang.Function
{
	public    Xml_elements_203__Fun(haxe.root.Array<java.lang.Object> cur, haxe.root.Array<haxe.root.Array> x)
	{
		super(0, 0);
		this.cur = cur;
		this.x = x;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int k1 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) );
		int l1 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length;
		while (( k1 < l1 ))
		{
			haxe.root.Xml n = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).__get(k1);
			k1 += 1;
			if (( n.nodeType == haxe.root.Xml.Element )) 
			{
				this.cur.__set(0, k1);
				return n;
			}
			
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<java.lang.Object> cur;
	
	public  haxe.root.Array<haxe.root.Array> x;
	
}


