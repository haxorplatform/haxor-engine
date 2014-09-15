package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Transform_Search_471__Fun extends haxe.lang.Function
{
	public    Transform_Search_471__Fun(haxe.root.Array<haxor.component.Transform> _g, haxe.root.Array<haxor.component.Transform> res, haxe.root.Array<java.lang.String> p_name1, haxe.root.Array<java.lang.Object> p_exact1)
	{
		super(2, 0);
		this._g = _g;
		this.res = res;
		this.p_name1 = p_name1;
		this.p_exact1 = p_exact1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		int d = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float2) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn2)) )) );
		haxor.component.Transform it = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Transform) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Transform) (__fn_dyn1) )) );
		if (( it == this._g.__get(0) )) 
		{
			return true;
		}
		
		if (( this.res.__get(0) != null )) 
		{
			return true;
		}
		
		if (haxe.lang.Runtime.toBool(this.p_exact1.__get(0))) 
		{
			if (haxe.lang.Runtime.valEq(it.get_name(), this.p_name1.__get(0))) 
			{
				this.res.__set(0, it);
			}
			
		}
		 else 
		{
			if (( haxe.lang.StringExt.indexOf(it.get_name(), this.p_name1.__get(0), null) >= 0 )) 
			{
				this.res.__set(0, it);
			}
			
		}
		
		return true;
	}
	
	
	public  haxe.root.Array<haxor.component.Transform> _g;
	
	public  haxe.root.Array<haxor.component.Transform> res;
	
	public  haxe.root.Array<java.lang.String> p_name1;
	
	public  haxe.root.Array<java.lang.Object> p_exact1;
	
}


