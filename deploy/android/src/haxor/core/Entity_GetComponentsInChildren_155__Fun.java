package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Entity_GetComponentsInChildren_155__Fun extends haxe.lang.Function
{
	public    Entity_GetComponentsInChildren_155__Fun(haxe.root.Array<haxe.root.Array> res, haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1)
	{
		super(2, 0);
		this.res = res;
		this.p_type1 = p_type1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		int d = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float2) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn2)) )) );
		haxor.component.Transform t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Transform) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Transform) (__fn_dyn1) )) );
		haxe.root.Array l = t.m_entity.GetComponents(this.p_type1.__get(0));
		{
			int _g1 = 0;
			int _g = l.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.res.__get(0).push(l.__get(i));
			}
			
		}
		
		return true;
	}
	
	
	public  haxe.root.Array<haxe.root.Array> res;
	
	public  haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1;
	
}


