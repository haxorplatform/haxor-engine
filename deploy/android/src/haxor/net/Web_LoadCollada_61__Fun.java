package haxor.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Web_LoadCollada_61__Fun extends haxe.lang.Function
{
	public    Web_LoadCollada_61__Fun(haxe.root.Array<java.lang.String> p_url1, haxe.root.Array<haxe.lang.Function> p_callback1)
	{
		super(2, 0);
		this.p_url1 = p_url1;
		this.p_callback1 = p_callback1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		java.lang.String d = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (haxe.lang.Runtime.toString(__fn_float1)) : (haxe.lang.Runtime.toString(__fn_dyn1)) );
		if (( p < 1.0 )) 
		{
			this.p_callback1.__get(0).__hx_invoke2_o(0.0, null, p, haxe.lang.Runtime.undefined);
		}
		 else 
		{
			this.p_callback1.__get(0).__hx_invoke2_o(0.0, ( (( d == null )) ? (null) : (new haxor.io.file.ColladaFile(haxe.lang.Runtime.toString(this.p_url1.__get(0)), haxe.lang.Runtime.toString(d))) ), 1.0, haxe.lang.Runtime.undefined);
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<java.lang.String> p_url1;
	
	public  haxe.root.Array<haxe.lang.Function> p_callback1;
	
}


