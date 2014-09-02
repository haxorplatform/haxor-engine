package haxor.thread;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Activity_RunOnce_94__Fun extends haxe.lang.Function
{
	public    Activity_RunOnce_94__Fun(haxe.root.Array<haxe.lang.Function> p_callback1)
	{
		super(1, 0);
		this.p_callback1 = p_callback1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		double t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float1) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn1)) )) );
		this.p_callback1.__get(0).__hx_invoke0_o();
		return false;
	}
	
	
	public  haxe.root.Array<haxe.lang.Function> p_callback1;
	
}


