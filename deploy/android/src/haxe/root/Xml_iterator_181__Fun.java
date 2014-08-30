package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_iterator_181__Fun extends haxe.lang.Function
{
	public    Xml_iterator_181__Fun(haxe.root.Array<haxe.root.Array> x, haxe.root.Array<java.lang.Object> cur)
	{
		super(0, 0);
		this.x = x;
		this.cur = cur;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int __temp_stmt151698 = 0;
		{
			int __temp_arrIndex151609 = 0;
			int __temp_arrVal151607 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(__temp_arrIndex151609))) );
			int __temp_arrRet151608 = __temp_arrVal151607++;
			int __temp_expr151699 = ((int) (haxe.lang.Runtime.toInt(this.cur.__set(__temp_arrIndex151609, __temp_arrVal151607))) );
			__temp_stmt151698 = __temp_arrRet151608;
		}
		
		haxe.root.Array<haxe.root.Xml> __temp_stmt151700 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) );
		return __temp_stmt151700.__get(__temp_stmt151698);
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
}


