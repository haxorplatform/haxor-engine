package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RenderStats extends haxe.lang.HxObject
{
	public    RenderStats(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RenderStats()
	{
		haxor.core.RenderStats.__hx_ctor_haxor_core_RenderStats(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_RenderStats(haxor.core.RenderStats __temp_me173)
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
		return ( haxor.core.RenderStats.visible + haxor.core.RenderStats.culled );
	}
	
	
	public static  int renderers;
	
	public static   void Initialize()
	{
		haxor.core.RenderStats.visible = 0;
		haxor.core.RenderStats.culled = 0;
		haxor.core.RenderStats.triangles = 0;
		haxor.core.RenderStats.renderers = 0;
	}
	
	
	public static   void BeginRender()
	{
		haxor.core.RenderStats.visible = 0;
		haxor.core.RenderStats.culled = 0;
		haxor.core.RenderStats.triangles = 0;
		haxor.core.RenderStats.renderers = haxor.context.EngineContext.renderer.rid.get_next();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.RenderStats(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.RenderStats();
	}
	
	
}


