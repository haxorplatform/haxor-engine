package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class CameraContext_SortCameraList_224__Fun extends haxe.lang.Function
{
	public    CameraContext_SortCameraList_224__Fun()
	{
		super(2, 1);
	}
	
	
	public static  haxor.context.CameraContext_SortCameraList_224__Fun __hx_current;
	
	@Override public   double __hx_invoke2_f(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		haxor.component.Camera b = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Camera) (((java.lang.Object) (__fn_float2) )) )) : (((haxor.component.Camera) (__fn_dyn2) )) );
		haxor.component.Camera a = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Camera) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Camera) (__fn_dyn1) )) );
		if (( a.get_order() == b.get_order() )) 
		{
			if (( a.m_entity.get_name().compareTo(b.m_entity.get_name()) < 0 )) 
			{
				return ((double) (-1) );
			}
			 else 
			{
				return ((double) (1) );
			}
			
		}
		 else 
		{
			if (( a.get_order() < b.get_order() )) 
			{
				return ((double) (-1) );
			}
			 else 
			{
				return ((double) (1) );
			}
			
		}
		
	}
	
	
}


