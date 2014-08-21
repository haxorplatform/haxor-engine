package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Load_68__Fun extends haxe.lang.Function
{
	public    Main_Load_68__Fun()
	{
		super(2, 0);
	}
	
	
	public static  haxe.root.Main_Load_68__Fun __hx_current;
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		java.lang.String s = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (haxe.lang.Runtime.toString(__fn_float1)) : (haxe.lang.Runtime.toString(__fn_dyn1)) );
		haxor.core.Console.Log(( "progress> " + haxe.lang.Runtime.toString(p) ), null);
		if (( p >= 1.0 )) 
		{
			if (( s != null )) 
			{
				haxor.core.Console.Log(haxe.lang.StringExt.substr(s, 0, 100), null);
			}
			
		}
		
		return null;
	}
	
	
}


