package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RenderQueue extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.RenderQueue.Background = 0;
		haxor.graphics.RenderQueue.Opaque = 1000;
		haxor.graphics.RenderQueue.Transparent = 2000;
		haxor.graphics.RenderQueue.Overlay = 3000;
		haxor.graphics.RenderQueue.Interface = 4000;
	}
	public    RenderQueue(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RenderQueue()
	{
		haxor.graphics.RenderQueue.__hx_ctor_haxor_graphics_RenderQueue(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_RenderQueue(haxor.graphics.RenderQueue __temp_me55688)
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
		return new haxor.graphics.RenderQueue(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.RenderQueue();
	}
	
	
}


