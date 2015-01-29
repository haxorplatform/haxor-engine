package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_elements_192__Fun extends haxe.lang.Function
{
	public    Xml_elements_192__Fun(haxe.root.Array<haxe.root.Array> x, haxe.root.Array<java.lang.Object> cur)
	{
		super(0, 0);
		this.x = x;
		this.cur = cur;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int k = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) );
		int l = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length;
		while (( k < l ))
		{
			if (( ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).__get(k).nodeType == haxe.root.Xml.Element )) 
			{
				break;
			}
			
			k += 1;
		}
		
		this.cur.__set(0, k);
		return ( k < l );
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
}


