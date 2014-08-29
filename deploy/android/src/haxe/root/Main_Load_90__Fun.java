package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Load_90__Fun extends haxe.lang.Function
{
	public    Main_Load_90__Fun(haxe.root.Array<haxe.root.Main> _g)
	{
		super(2, 0);
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		haxor.graphics.texture.Texture2D t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.graphics.texture.Texture2D) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.graphics.texture.Texture2D) (__fn_dyn1) )) );
		if (( p >= 1.0 )) 
		{
			haxor.io.file.Asset.Add("texture", t);
			this._g.__get(0).LoadComplete();
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<haxe.root.Main> _g;
	
}


