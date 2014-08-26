package haxor.context;
import haxor.component.Component;
import haxor.component.MeshRenderer;
import haxor.component.Renderer;
import haxor.context.Process.BaseProcess;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.IDisposable;
import haxor.core.IRenderable;
import haxor.core.IResizeable;
import haxor.core.IUpdateable;
import haxor.core.Resource;

/**
 * ...
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
	static private var maxNodes : Int 	= 1000;
	
	/**
	 * Objects per frame that will be collected after Destroy.
	 */
	static private var collectRate : Int = 10;
	
	/**
	 * List of IUpdateable nodes.
	 */
	static private var update : Process<IUpdateable>;
	
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
	 * List of MeshRenderer display lists per layer.
	 */
	static private var renderers : Array<Process<MeshRenderer>>;
	
	
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
	 * Reference to the Data context.
	 */
	static private var data : DataContext;
	
	/**
	 * Reference to the Camera context.
	 */
	static private var camera : CameraContext;
	
	/**
	 * Reference to the Trasnform context.
	 */
	static private var transform : TransformContext;
	
	/**
	 * Reference to the Gizmo context.
	 */
	static private var gizmo : GizmoContext;
	
	/**
	 * Initializes the Haxor context.
	 */
	static private function Initialize():Void
	{
		
		Console.Log("Haxor> Engine Context Initialize.",3);
		update      = new Process("process.update", 	 maxNodes);
		render      = new Process("process.render", 	 maxNodes);
		resize      = new Process("process.resize", 	 maxNodes);
		resources   = new Process("process.resources",   maxNodes);
		disposables = new Process("process.disposables", maxNodes);
		renderers   = [];
		
		list = [update, render, resize, resources, disposables];
		
		for (i in 0...32)
		{	
			var p : Process<MeshRenderer> = new Process("process.renderers",maxNodes,i==31);
			renderers.push(p);
			list.push(p);
		}
		
		mesh 		= new MeshContext();
		material	= new MaterialContext();
		texture		= new TextureContext();
		data		= new DataContext();
		gizmo		= new GizmoContext();
		camera		= new CameraContext();
		transform   = new TransformContext();
	}
	
	/**
	 * Method called to initialize contexts that uses the graphics context.
	 */
	static private function Build():Void
	{
		mesh.Initialize();
		material.Initialize();
		texture.Initialize();
		gizmo.Initialize();	
		transform.Initialize();
	}
	
	/**
	 * Adds this resource into the execution layers.
	 * @param	p_resource
	 */
	static private function Enable(p_resource:Resource):Void
	{
		if(Std.is(p_resource,IUpdateable)) update.Add(p_resource);
		if(Std.is(p_resource,IRenderable)) render.Add(p_resource);
		if(Std.is(p_resource,IResizeable)) resize.Add(p_resource);
		if (Std.is(p_resource, Entity))
		{
			var e :Entity = cast p_resource;
			for (i in 0...e.m_components.length)
			{
				var c : Component = e.m_components[i];
				if (Std.is(c, MeshRenderer)) renderers[e.layer].Add(c);
				
			}
		}
	}
	
	/**
	 * Removes this resource into the execution layers.
	 * @param	p_resource
	 */
	static private function Disable(p_resource:Resource):Void
	{
		if(Std.is(p_resource,IUpdateable)) update.Remove(p_resource);
		if(Std.is(p_resource,IRenderable)) render.Remove(p_resource);
		if(Std.is(p_resource,IResizeable)) resize.Remove(p_resource);
		if (Std.is(p_resource, Entity))
		{
			var e :Entity = cast p_resource;
			for (i in 0...e.m_components.length)
			{
				var c : Component = e.m_components[i];
				if (Std.is(c, MeshRenderer)) renderers[e.layer].Remove(c);				
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
			if (!Std.is(c, MeshRenderer)) continue;
			renderers[p_from].Remove(c);
			if(e.enabled) renderers[p_to].Add(c);
		}
	}
	
	/**
	 * Handles the destruction of resources of the engine.
	 * @param	p_resource
	 */
	static private function Destroy(p_resource:Resource):Void
	{
		if (p_resource.m_destroyed) return;
		p_resource.m_destroyed = true;		
		for (i in 0...list.length) list[i].Remove(p_resource);		
		EngineContext.disposables.Add(p_resource);		
	}
	
}