package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Load_75__Fun extends haxe.lang.Function
{
	public    Main_Load_75__Fun(haxe.root.Array<haxe.root.Main> _g)
	{
		super(2, 0);
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		double p1 = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((double) (__fn_float2) )) : (((double) (haxe.lang.Runtime.toDouble(__fn_dyn2)) )) );
		haxor.graphics.texture.Bitmap b = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.graphics.texture.Bitmap) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.graphics.texture.Bitmap) (__fn_dyn1) )) );
		haxor.core.Console.Log(( "p> " + haxe.lang.Runtime.toString(p1) ), null);
		if (( p1 >= 1.0 )) 
		{
			if (( b != null )) 
			{
				this._g.__get(0).bmp = b;
				this._g.__get(0).LoadComplete();
			}
			
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<haxe.root.Main> _g;
	
}


