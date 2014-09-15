package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_elementsNamed_238__Fun extends haxe.lang.Function
{
	public    Xml_elementsNamed_238__Fun(haxe.root.Array<haxe.root.Array> x, haxe.root.Array<java.lang.String> name1, haxe.root.Array<java.lang.Object> cur)
	{
		super(0, 0);
		this.x = x;
		this.name1 = name1;
		this.cur = cur;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int k1 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) );
		int l1 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length;
		while (( k1 < l1 ))
		{
			haxe.root.Xml n1 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).__get(k1);
			k1++;
			if (( ( n1.nodeType == haxe.root.Xml.Element ) && haxe.lang.Runtime.valEq(n1._nodeName, this.name1.__get(0)) )) 
			{
				this.cur.__set(0, k1);
				return n1;
			}
			
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.String> name1;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
}


