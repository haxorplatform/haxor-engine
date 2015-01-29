package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_elementsNamed_226__Fun extends haxe.lang.Function
{
	public    Xml_elementsNamed_226__Fun(haxe.root.Array<haxe.root.Array> x, haxe.root.Array<java.lang.Object> cur, haxe.root.Array<java.lang.String> name1)
	{
		super(0, 0);
		this.x = x;
		this.cur = cur;
		this.name1 = name1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int k = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) );
		int l = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length;
		while (( k < l ))
		{
			haxe.root.Xml n = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).__get(k);
			if (( ( n.nodeType == haxe.root.Xml.Element ) && haxe.lang.Runtime.valEq(n._nodeName, this.name1.__get(0)) )) 
			{
				break;
			}
			
			k++;
		}
		
		this.cur.__set(0, k);
		return ( k < l );
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
	public  haxe.root.Array<java.lang.String> name1;
	
}


