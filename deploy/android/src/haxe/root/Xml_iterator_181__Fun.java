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
		int __temp_stmt164536 = 0;
		{
			int __temp_arrIndex164465 = 0;
			int __temp_arrVal164463 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(__temp_arrIndex164465))) );
			int __temp_arrRet164464 = __temp_arrVal164463++;
			int __temp_expr164537 = ((int) (haxe.lang.Runtime.toInt(this.cur.__set(__temp_arrIndex164465, __temp_arrVal164463))) );
			__temp_stmt164536 = __temp_arrRet164464;
		}
		
		haxe.root.Array<haxe.root.Xml> __temp_stmt164538 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) );
		return __temp_stmt164538.__get(__temp_stmt164536);
	}
	
	
	public  haxe.root.Array<java.lang.Object> cur;
	
	public  haxe.root.Array<haxe.root.Array> x;
	
}


