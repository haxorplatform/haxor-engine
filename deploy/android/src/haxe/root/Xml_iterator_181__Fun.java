package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml_iterator_181__Fun extends haxe.lang.Function
{
	public    Xml_iterator_181__Fun(haxe.root.Array<java.lang.Object> cur, haxe.root.Array<haxe.root.Array> x)
	{
		super(0, 0);
		this.cur = cur;
		this.x = x;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		int __temp_stmt255732 = 0;
		{
			int __temp_arrIndex255659 = 0;
			int __temp_arrVal255657 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(__temp_arrIndex255659))) );
			int __temp_arrRet255658 = __temp_arrVal255657++;
			int __temp_expr255733 = ((int) (haxe.lang.Runtime.toInt(this.cur.__set(__temp_arrIndex255659, __temp_arrVal255657))) );
			__temp_stmt255732 = __temp_arrRet255658;
		}
		
		haxe.root.Array<haxe.root.Xml> __temp_stmt255734 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) );
		return __temp_stmt255734.__get(__temp_stmt255732);
	}
	
	
	public  haxe.root.Array<java.lang.Object> cur;
	
	public  haxe.root.Array<haxe.root.Array> x;
	
}


