package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_iterator_178__Fun extends haxe.lang.Function
{
	public    Xml_iterator_178__Fun(haxe.root.Array<java.lang.Object> cur, haxe.root.Array<haxe.root.Array> x)
	{
		super(0, 0);
		this.cur = cur;
		this.x = x;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		return ( ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) ) < ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length );
	}
	
	
	public  haxe.root.Array<java.lang.Object> cur;
	
	public  haxe.root.Array<haxe.root.Array> x;
	
}


