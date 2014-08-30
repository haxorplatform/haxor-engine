package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Entity_GetComponentInChildren_137__Fun extends haxe.lang.Function
{
	public    Entity_GetComponentInChildren_137__Fun(haxe.root.Array<haxor.component.Component> res1, haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1)
	{
		super(2, 0);
		this.res1 = res1;
		this.p_type1 = p_type1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		int d = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float2) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn2)) )) );
		haxor.component.Transform t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Transform) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Transform) (__fn_dyn1) )) );
		if (( this.res1.__get(0) != null )) 
		{
			return true;
		}
		
		haxe.root.Array l = t.m_entity.GetComponents(this.p_type1.__get(0));
		if (( l.length > 0 )) 
		{
			this.res1.__set(0, ((haxor.component.Component) (l.__get(0)) ));
			return true;
		}
		
		return true;
	}
	
	
	public  haxe.root.Array<haxor.component.Component> res1;
	
	public  haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1;
	
}


