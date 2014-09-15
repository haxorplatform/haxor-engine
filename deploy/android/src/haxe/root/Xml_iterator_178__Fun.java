package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_iterator_178__Fun extends haxe.lang.Function
{
	public    Xml_iterator_178__Fun(haxe.root.Array<haxe.root.Array> x, haxe.root.Array<java.lang.Object> cur)
	{
		super(0, 0);
		this.x = x;
		this.cur = cur;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		return ( ((int) (haxe.lang.Runtime.toInt(this.cur.__get(0))) ) < ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) ).length );
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
}


