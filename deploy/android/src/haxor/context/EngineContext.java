package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class EngineContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.EngineContext.uid = 0;
		haxor.context.EngineContext.maxNodes = 5000;
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
	
	
	public static   void __hx_ctor_haxor_context_EngineContext(haxor.context.EngineContext __temp_me105)
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
	
	public static  haxe.root.Array<haxor.context.BaseProcess> list;
	
	public static  haxor.context.MeshContext mesh;
	
	public static  haxor.context.MaterialContext material;
	
	public static  haxor.context.TextureContext texture;
	
	public static  haxor.context.CameraContext camera;
	
	public static  haxor.context.RendererContext renderer;
	
	public static  haxor.context.GizmoContext gizmo;
	
	public static  haxor.context.DataContext data;
	
	public static  haxor.context.TransformContext transform;
	
	public static   void Initialize()
	{
		haxor.core.Console.Log("Haxor> Engine Context Initialize.", 3);
		haxor.context.EngineContext.update = new haxor.context.Process<haxor.core.IUpdateable>(haxe.lang.Runtime.toString("process.update"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (null) ));
		haxor.context.EngineContext.render = new haxor.context.Process<haxor.core.IRenderable>(haxe.lang.Runtime.toString("process.render"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (null) ));
		haxor.context.EngineContext.resize = new haxor.context.Process<haxor.core.IResizeable>(haxe.lang.Runtime.toString("process.resize"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (null) ));
		haxor.context.EngineContext.resources = new haxor.context.Process<haxor.core.Resource>(haxe.lang.Runtime.toString("process.resources"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (null) ));
		haxor.context.EngineContext.disposables = new haxor.context.Process<haxor.core.IDisposable>(haxe.lang.Runtime.toString("process.disposables"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (null) ));
		haxor.context.EngineContext.list = new haxe.root.Array<haxor.context.BaseProcess>(new haxor.context.BaseProcess[]{haxor.context.EngineContext.update, haxor.context.EngineContext.render, haxor.context.EngineContext.resize, haxor.context.EngineContext.resources, haxor.context.EngineContext.disposables});
		haxor.context.EngineContext.data = new haxor.context.DataContext();
		haxor.component.animation.Animation.Initialize();
		haxor.context.EngineContext.renderer = new haxor.context.RendererContext();
		haxor.context.EngineContext.mesh = new haxor.context.MeshContext();
		haxor.context.EngineContext.material = new haxor.context.MaterialContext();
		haxor.context.EngineContext.texture = new haxor.context.TextureContext();
		haxor.context.EngineContext.gizmo = new haxor.context.GizmoContext();
		haxor.context.EngineContext.camera = new haxor.context.CameraContext();
		haxor.context.EngineContext.transform = new haxor.context.TransformContext();
	}
	
	
	public static   void Build()
	{
		haxor.context.EngineContext.mesh.Initialize();
		haxor.context.EngineContext.material.Initialize();
		haxor.context.EngineContext.texture.Initialize();
		haxor.context.EngineContext.gizmo.Initialize();
		haxor.context.EngineContext.transform.Initialize();
		haxor.context.EngineContext.renderer.Initialize();
	}
	
	
	public static   void Enable(haxor.core.Resource p_resource)
	{
		if (( p_resource instanceof haxor.core.IUpdateable )) 
		{
			haxor.context.EngineContext.update.Add(p_resource);
		}
		
		if (( p_resource instanceof haxor.core.IRenderable )) 
		{
			haxor.context.EngineContext.render.Add(p_resource);
		}
		
		if (( p_resource instanceof haxor.core.IResizeable )) 
		{
			haxor.context.EngineContext.resize.Add(p_resource);
		}
		
		if (( p_resource instanceof haxor.component.Renderer )) 
		{
			haxor.context.EngineContext.renderer.Enable(((haxor.component.Renderer) (p_resource) ));
		}
		
		if (( p_resource instanceof haxor.core.Entity )) 
		{
			haxor.core.Entity e = ((haxor.core.Entity) (p_resource) );
			{
				int _g1 = 0;
				int _g = e.m_components.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					haxor.component.Component c = e.m_components.__get(i);
					if (( c instanceof haxor.component.MeshRenderer )) 
					{
						haxor.context.EngineContext.renderer.Enable(((haxor.component.Renderer) (c) ));
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public static   void Disable(haxor.core.Resource p_resource)
	{
		if (( p_resource instanceof haxor.core.IUpdateable )) 
		{
			haxor.context.EngineContext.update.Remove(p_resource);
		}
		
		if (( p_resource instanceof haxor.core.IRenderable )) 
		{
			haxor.context.EngineContext.render.Remove(p_resource);
		}
		
		if (( p_resource instanceof haxor.core.IResizeable )) 
		{
			haxor.context.EngineContext.resize.Remove(p_resource);
		}
		
		if (( p_resource instanceof haxor.component.Renderer )) 
		{
			haxor.context.EngineContext.renderer.Disable(((haxor.component.Renderer) (p_resource) ));
		}
		
		if (( p_resource instanceof haxor.core.Entity )) 
		{
			haxor.core.Entity e = ((haxor.core.Entity) (p_resource) );
			{
				int _g1 = 0;
				int _g = e.m_components.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					haxor.component.Component c = e.m_components.__get(i);
					if (( c instanceof haxor.component.MeshRenderer )) 
					{
						haxor.context.EngineContext.renderer.Disable(((haxor.component.Renderer) (c) ));
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public static   void OnEntiyLayerChange(haxor.core.Entity p_entity, int p_from, int p_to)
	{
		haxor.core.Entity e = p_entity;
		{
			int _g1 = 0;
			int _g = e.m_components.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.component.Component c = e.m_components.__get(i);
				if (( c instanceof haxor.component.Renderer )) 
				{
					haxor.context.EngineContext.renderer.OnLayerChange(((haxor.component.Renderer) (c) ), p_from, p_to);
				}
				
			}
			
		}
		
	}
	
	
	public static   void Destroy(haxor.core.Resource p_resource)
	{
		if (p_resource.m_destroyed) 
		{
			return ;
		}
		
		p_resource.m_destroyed = true;
		{
			int _g1 = 0;
			int _g = haxor.context.EngineContext.list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.context.EngineContext.list.__get(i).Remove(p_resource);
			}
			
		}
		
		haxor.context.EngineContext.disposables.Add(p_resource);
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


