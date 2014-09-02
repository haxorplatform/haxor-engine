package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Stats extends haxe.lang.HxObject
{
	public    Stats(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Stats()
	{
		haxor.core.Stats.__hx_ctor_haxor_core_Stats(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_Stats(haxor.core.Stats __temp_me164210)
	{
		{
		}
		
	}
	
	
	public static  int visible;
	
	public static  int culled;
	
	public static  int triangles;
	
	public static  int total;
	
	public static   int get_total()
	{
		return ( haxor.core.Stats.visible + haxor.core.Stats.culled );
	}
	
	
	public static  int renderers;
	
	public static   void Initialize()
	{
		haxor.core.Stats.visible = 0;
		haxor.core.Stats.culled = 0;
		haxor.core.Stats.triangles = 0;
		haxor.core.Stats.renderers = 0;
	}
	
	
	public static   void BeginRender()
	{
		haxor.core.Stats.visible = 0;
		haxor.core.Stats.culled = 0;
		haxor.core.Stats.triangles = 0;
		haxor.core.Stats.renderers = haxor.context.EngineContext.renderer.rid.get_next();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Stats(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Stats();
	}
	
	
}


