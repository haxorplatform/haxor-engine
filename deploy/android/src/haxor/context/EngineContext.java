package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class EngineContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.EngineContext.uid = 0;
		haxor.context.EngineContext.maxNodes = 1000;
		haxor.context.EngineContext.collectRate = 10;
	}
	public    EngineContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    EngineContext()
	{
		haxor.context.EngineContext.__hx_ctor_haxor_context_EngineContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_EngineContext(haxor.context.EngineContext __temp_me4449)
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
	
	public static  haxor.context.MeshContext mesh;
	
	public static  haxor.context.MaterialContext material;
	
	public static   void Initialize()
	{
		haxor.core.Console.Log("Haxor> Engine Context Initialize.", 3);
		haxor.context.EngineContext.update = new haxor.context.Process<haxor.core.IUpdateable>(haxe.lang.Runtime.toString("process.update"), ((int) (haxor.context.EngineContext.maxNodes) ));
		haxor.context.EngineContext.render = new haxor.context.Process<haxor.core.IRenderable>(haxe.lang.Runtime.toString("process.render"), ((int) (haxor.context.EngineContext.maxNodes) ));
		haxor.context.EngineContext.resize = new haxor.context.Process<haxor.core.IResizeable>(haxe.lang.Runtime.toString("process.resize"), ((int) (haxor.context.EngineContext.maxNodes) ));
		haxor.context.EngineContext.resources = new haxor.context.Process<haxor.core.Resource>(haxe.lang.Runtime.toString("process.resources"), ((int) (haxor.context.EngineContext.maxNodes) ));
		haxor.context.EngineContext.disposables = new haxor.context.Process<haxor.core.IDisposable>(haxe.lang.Runtime.toString("process.disposables"), ((int) (haxor.context.EngineContext.maxNodes) ));
		haxor.context.EngineContext.mesh = new haxor.context.MeshContext();
		haxor.context.EngineContext.material = new haxor.context.MaterialContext();
	}
	
	
	public static   void Build()
	{
		haxor.context.EngineContext.mesh.Initialize();
		haxor.context.EngineContext.material.Initialize();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.EngineContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.EngineContext();
	}
	
	
}


