package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class HaxorContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.HaxorContext.uid = 0;
		haxor.context.HaxorContext.maxNodes = 1000;
		haxor.context.HaxorContext.collectRate = 10;
	}
	public    HaxorContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    HaxorContext()
	{
		haxor.context.HaxorContext.__hx_ctor_haxor_context_HaxorContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_HaxorContext(haxor.context.HaxorContext __temp_me1823)
	{
		{
		}
		
	}
	
	
	public static  int uid;
	
	public static  int maxNodes;
	
	public static  int collectRate;
	
	public static  haxor.context.Process<haxor.core.IUpdateable> update;
	
	public static  haxor.context.Process<haxor.core.IResizeable> resize;
	
	public static  haxor.context.Process<haxor.core.IRenderable> render;
	
	public static  haxor.context.Process<haxor.core.Resource> resources;
	
	public static  haxor.context.Process<haxor.core.IDisposable> disposables;
	
	public static   void Initialize()
	{
		haxor.context.HaxorContext.update = new haxor.context.Process<haxor.core.IUpdateable>(haxe.lang.Runtime.toString("process.update"), ((int) (haxor.context.HaxorContext.maxNodes) ));
		haxor.context.HaxorContext.render = new haxor.context.Process<haxor.core.IRenderable>(haxe.lang.Runtime.toString("process.render"), ((int) (haxor.context.HaxorContext.maxNodes) ));
		haxor.context.HaxorContext.resize = new haxor.context.Process<haxor.core.IResizeable>(haxe.lang.Runtime.toString("process.resize"), ((int) (haxor.context.HaxorContext.maxNodes) ));
		haxor.context.HaxorContext.resources = new haxor.context.Process<haxor.core.Resource>(haxe.lang.Runtime.toString("process.resources"), ((int) (haxor.context.HaxorContext.maxNodes) ));
		haxor.context.HaxorContext.disposables = new haxor.context.Process<haxor.core.IDisposable>(haxe.lang.Runtime.toString("process.disposbales"), ((int) (haxor.context.HaxorContext.maxNodes) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.HaxorContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.HaxorContext();
	}
	
	
}


