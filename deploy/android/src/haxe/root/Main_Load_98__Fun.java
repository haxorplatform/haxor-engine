package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Load_98__Fun extends haxe.lang.Function
{
	public    Main_Load_98__Fun(haxe.root.Array<haxe.root.Main> _g)
	{
		super(2, 0);
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		haxor.io.file.ColladaFile f = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.io.file.ColladaFile) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.io.file.ColladaFile) (__fn_dyn1) )) );
		if (( p >= 1.0 )) 
		{
			haxor.io.file.Asset.Add("animation_idle", f);
			if ((  -- this._g.__get(0).queue <= 0 )) 
			{
				this._g.__get(0).LoadComplete();
			}
			
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<haxe.root.Main> _g;
	
}


