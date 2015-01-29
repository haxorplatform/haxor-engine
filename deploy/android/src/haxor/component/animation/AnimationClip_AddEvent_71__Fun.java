package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AnimationClip_AddEvent_71__Fun extends haxe.lang.Function
{
	public    AnimationClip_AddEvent_71__Fun()
	{
		super(2, 1);
	}
	
	
	public static  haxor.component.animation.AnimationClip_AddEvent_71__Fun __hx_current;
	
	@Override public   double __hx_invoke2_f(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		haxor.component.animation.AnimationEvent b = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((haxor.component.animation.AnimationEvent) (((java.lang.Object) (__fn_float2) )) )) : (((haxor.component.animation.AnimationEvent) (__fn_dyn2) )) );
		haxor.component.animation.AnimationEvent a = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.animation.AnimationEvent) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.animation.AnimationEvent) (__fn_dyn1) )) );
		if (( a.frame < b.frame )) 
		{
			return ((double) (-1) );
		}
		 else 
		{
			return ((double) (1) );
		}
		
	}
	
	
}


