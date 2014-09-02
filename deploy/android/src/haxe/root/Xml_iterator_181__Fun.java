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
		int __temp_stmt160810 = 0;
		{
			int __temp_arrIndex160721 = 0;
			int __temp_arrVal160719 = ((int) (haxe.lang.Runtime.toInt(this.cur.__get(__temp_arrIndex160721))) );
			int __temp_arrRet160720 = __temp_arrVal160719++;
			int __temp_expr160811 = ((int) (haxe.lang.Runtime.toInt(this.cur.__set(__temp_arrIndex160721, __temp_arrVal160719))) );
			__temp_stmt160810 = __temp_arrRet160720;
		}
		
		haxe.root.Array<haxe.root.Xml> __temp_stmt160812 = ((haxe.root.Array<haxe.root.Xml>) (((haxe.root.Array) (this.x.__get(0)) )) );
		return __temp_stmt160812.__get(__temp_stmt160810);
	}
	
	
	public  haxe.root.Array<haxe.root.Array> x;
	
	public  haxe.root.Array<java.lang.Object> cur;
	
}


