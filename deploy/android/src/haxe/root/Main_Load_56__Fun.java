package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Load_56__Fun extends haxe.lang.Function
{
	public    Main_Load_56__Fun()
	{
		super(2, 0);
	}
	
	
	public static  haxe.root.Main_Load_56__Fun __hx_current;
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p1 = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		java.lang.String d1 = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (haxe.lang.Runtime.toString(__fn_float1)) : (haxe.lang.Runtime.toString(__fn_dyn1)) );
		if (( p1 >= 1.0 )) 
		{
			if (( d1 != null )) 
			{
				haxor.core.Console.Log(haxe.lang.StringExt.substr(d1, 0, 100), null);
			}
			
		}
		
		return null;
	}
	
	
}


