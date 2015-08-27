package haxor.context;
import haxor.component.animation.Animation;
import haxor.component.Behaviour;
import haxor.component.Component;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.context.Process.BaseProcess;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Entity;
import haxor.core.IDisposable;
import haxor.core.IFixedUpdateable;
import haxor.core.IRenderable;
import haxor.core.IResizeable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.component.Renderer;
import haxor.core.RenderStats;
import haxor.physics.Physics;



/**
 * Class that holds all backstage processing and optimizations for the main Engine class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class EngineContext
{
	
	/**
	 * Unique id counter.
	 */
	static private var uid : Int 		= 0;
	
	/**
	 * Max elements in the process lists.
	 */
	static private var maxNodes : Int 	= 5000;
	
	/**
	 * Objects per frame that will be collected after Destroy.
	 */
	static private var collectRate : Int = 10;
	
	/**
	 * List of IUpdateable nodes.
	 */
	static private var update : Process<IUpdateable>;
	
	/**
	 * List of IFixedUpdateable nodes.
	 */
	static private var fixed_update : Process<IFixedUpdateable>;
	
	/**
	 * 
	 */
	static private var awake : Array<Behaviour>;
	
	/**
	 * 
	 */
	static private var start : Array<Behaviour>;
	
	/**
	 * List of IResizeable nodes.
	 */
	static private var resize : Process<IResizeable>;
	
	/**
	 * List of IRenderable nodes.
	 */
	static private var render : Process<IRenderable>;
		
	/**
	 * List of IDisposable nodes.
	 */
	static private var resources : Process<Resource>;
	
	/**
	 * List of elements marked for disposing.
	 */
	static private var disposables : Process<IDisposable>;
	
	/**
	 * List of all processes.
	 */
	static private var list : Array<BaseProcess>;
	
	/**
	 * Reference to the mesh context.
	 */
	static private var mesh : MeshContext;
	
	/**
	 * Reference to the Material context.
	 */
	static private var material : MaterialContext;
	
	/**
	 * Reference to the Texture context.
	 */
	static private var texture : TextureContext;
	
	/**
	 * Reference to the Camera context.
	 */
	static private var camera : CameraContext;
		
	/**
	 * Reference to the Renderer context.
	 */
	static private var renderer : RendererContext;
	
	/**
	 * Reference to the Particle context.
	 */
	static private var particle : ParticleContext;
	
	/**
	 * Reference to the Gizmo context.
	 */
	static private var gizmo : GizmoContext;
	
	/**
	 * Reference to the Data context.
	 */
	static private var data : DataContext;
	
	/**
	 * Reference to the Transform context.
	 */
	static private var transform : TransformContext;
	
	/**
	 * Reference to the Physics context.
	 */
	static private var physics : PhysicsContext;
	
	/**
	 * Reference to the Kernel context.
	 */
	static private var kernel : KernelContext;
	
	
	/**
	 * Initializes the Haxor context.
	 */
	static private function Initialize():Void
	{
		Console.Log("Haxor> Engine Context Initialize.",3);
		update       = new Process("process.update", 	 maxNodes);
		fixed_update = new Process("process.fixed-update", 	 maxNodes);
		render       = new Process("process.render", 	 maxNodes);
		resize       = new Process("process.resize", 	 maxNodes);
		resources    = new Process("process.resources",   maxNodes);
		disposables  = new Process("process.disposables", maxNodes);
		
		awake = [];
		start = [];
		
		list = [update, render, resize, resources, disposables];
		
		data		= new DataContext();
		
		#if (!ie8 && !nodejs)
		
		//Temp
		Animation.Initialize();
		Physics.Initialize();
		Debug.Initialize();
		
		renderer	= new RendererContext();
		particle    = new ParticleContext();
		mesh 		= new MeshContext();		
		material	= new MaterialContext();
		texture		= new TextureContext();		
		gizmo		= new GizmoContext();
		camera		= new CameraContext();		
		transform   = new TransformContext();
		physics     = new PhysicsContext();
		kernel		= new KernelContext();
		#end
		
	}
	
	/**
	 * Method called to initialize contexts that uses the graphics context.
	 */
	static private function Build():Void
	{
		#if (!ie8 && !nodejs)
		mesh.Initialize();
		material.Initialize();
		texture.Initialize();
		gizmo.Initialize();	
		transform.Initialize();
		renderer.Initialize();
		particle.Initialize();
		physics.Initialize();
		kernel.Initialize();
		#end
	}
	
	/**
	 * Adds this resource into the execution layers.
	 * @param	p_resource
	 */
	static private function Enable(p_resource:Resource):Void
	{
		if (Std.is(p_resource, IUpdateable)) 	 update.Add(p_resource);
		if (Std.is(p_resource,IFixedUpdateable)) fixed_update.Add(p_resource);
		if (Std.is(p_resource,IRenderable)) 	 render.Add(p_resource);
		if (Std.is(p_resource, IResizeable)) 	 resize.Add(p_resource);		
		
		
		if (Std.is(p_resource, Renderer)) 	renderer.Enable(cast p_resource);
		
		if (Std.is(p_resource, Entity))
		{
			var e :Entity = cast p_resource;
			for (i in 0...e.m_components.length)
			{
				var c : Component = e.m_components[i];
				if (Std.is(c, MeshRenderer))
				{
					renderer.Enable(cast c);					
				}
				
			}
		}
	}
	
	/**
	 * Removes this resource into the execution layers.
	 * @param	p_resource
	 */
	static private function Disable(p_resource:Resource):Void
	{
		if (Std.is(p_resource, IUpdateable)) 		update.Remove(p_resource);
		if(Std.is(p_resource,IFixedUpdateable)) fixed_update.Remove(p_resource);
		if(Std.is(p_resource,IRenderable)) 		render.Remove(p_resource);
		if(Std.is(p_resource, IResizeable)) 	resize.Remove(p_resource);
		if(Std.is(p_resource,Renderer)) 	 	renderer.Disable(cast p_resource);
		if(Std.is(p_resource, Entity))
		{
			var e :Entity = cast p_resource;
			for (i in 0...e.m_components.length)
			{
				var c : Component = e.m_components[i];
				if (Std.is(c, MeshRenderer)) renderer.Disable(cast c);
			}
		}
	}
	
	/**
	 * Handles the entity layer change. It can impact Render, Physics or possibly other operations of the engine.
	 * @param	p_from
	 * @param	p_to
	 */
	static private function OnEntiyLayerChange(p_entity:Entity,p_from:Int, p_to:Int):Void
	{
		var e :Entity = p_entity;
		for (i in 0...e.m_components.length)
		{
			var c : Component = e.m_components[i];
			#if (!ie8 && !nodejs)
			if (Std.is(c, Renderer)) EngineContext.renderer.OnLayerChange(cast c, p_from, p_to);
			#end
		}
	}
	
	/**
	 * Callback called when a resource has changed its guid.
	 * @param	p_resource
	 */
	static private function OnGUIDChange(p_resource:Resource):Void
	{
		//resources.Sort(function(a:Resource, b:Resource):Int { return a.guid < b.guid ? -1 : 1; });
	}
	
	/**
	 * Searches the resource list using a guid as query.
	 * @param	p_guid
	 * @return
	 */
	static private function FindByGUID(p_guid:String):Resource
	{
		var l : Array<Resource> = resources.list;
		var len : Int = resources.length;
		/*
		if (len <= 0) return 0;
		if (len <= 1) return l[0].guid==p_guid ? l[0] : null;
		var mid : Int = len / 2;
		var step : Int = len / 2;
		while (true)
		{
			var r : Resource = l[mid];
			if (r.guid == p_guid) return r;
			if (step <= 0) break;
			if (r.guid > p_guid) mid -= step;
			if (r.guid < p_guid) mid += step;			
			if (mid < 0)    break;
			if (mid >= len) break;
			step /= 2;
		}
		return null;
		//*/
		
		for (i in 0...len) if (l[(len-1)-i] != null) if (l[(len-1)-i].guid == p_guid) return l[(len-1)-i];
		return null;
	}
	
	/**
	 * Handles the destruction of resources of the engine.
	 * @param	p_resource
	 */
	static private function Destroy(p_resource:Resource):Void
	{
		if (p_resource.m_destroyed) return;		
		ScheduleDestroy(p_resource);
		if (Std.is(p_resource, Entity))
		{			
			var el  : Array<Entity> = [];
			var res : Entity = cast p_resource;
			var t   : Transform = res.transform;			
			t.Traverse(function(n:Transform, d:Int):Bool
			{
				el.push(n.entity);
				return true;
			},true);			
			for (e in el)
			{
				for (c in e.m_components) ScheduleDestroy(c);
				ScheduleDestroy(e);
			}
			t.parent.m_hierarchy.remove(t);						
		}
	}
	
	/**
	 * Schedules a destroy operation and removes it from the global list.
	 * @param	p_resource
	 */
	static private function ScheduleDestroy(p_resource:Resource):Void
	{
		if (p_resource.m_destroyed) return;
		p_resource.m_destroyed = true;		
		for (i in 0...list.length) list[i].Remove(p_resource);		
		EngineContext.disposables.Add(p_resource);		
	}
	
}