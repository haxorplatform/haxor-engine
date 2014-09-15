package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RenderQueue extends haxe.lang.HxObject
{
	static 
	{
		haxor.core.RenderQueue.Background = 0;
		haxor.core.RenderQueue.Opaque = 1000;
		haxor.core.RenderQueue.Transparent = 2000;
		haxor.core.RenderQueue.Overlay = 3000;
		haxor.core.RenderQueue.Interface = 4000;
	}
	public    RenderQueue(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RenderQueue()
	{
		haxor.core.RenderQueue.__hx_ctor_haxor_core_RenderQueue(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_RenderQueue(haxor.core.RenderQueue __temp_me255395)
	{
		{
		}
		
	}
	
	
	public static  int Background;
	
	public static  int Opaque;
	
	public static  int Transparent;
	
	public static  int Overlay;
	
	public static  int Interface;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.RenderQueue(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.RenderQueue();
	}
	
	
}


