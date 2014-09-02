package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Transform_OutputHierarchy_371__Fun extends haxe.lang.Function
{
	public    Transform_OutputHierarchy_371__Fun(haxe.root.Array<java.lang.String> hs, haxe.root.Array<java.lang.Object> d0)
	{
		super(2, 0);
		this.hs = hs;
		this.d0 = d0;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		int d = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float2) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn2)) )) );
		haxor.component.Transform t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Transform) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Transform) (__fn_dyn1) )) );
		java.lang.String tab = "";
		int td = d;
		int d1 = ((int) (java.lang.Math.max(((double) (0) ), ((double) (( td - ((int) (haxe.lang.Runtime.toInt(this.d0.__get(0))) ) )) ))) );
		{
			int _g = 0;
			while (( _g < d1 ))
			{
				int i = _g++;
				tab += " ";
			}
			
		}
		
		{
			int __temp_index160729 = 0;
			this.hs.__set(__temp_index160729, ( this.hs.__get(__temp_index160729) + ( ( ( ( ( ( tab + t.get_name() ) + " " ) + t.get_position().ToString(null) ) + t.get_rotation().ToString(null) ) + t.get_scale().ToString(null) ) + "\n" ) ));
		}
		
		return true;
	}
	
	
	public  haxe.root.Array<java.lang.String> hs;
	
	public  haxe.root.Array<java.lang.Object> d0;
	
}


