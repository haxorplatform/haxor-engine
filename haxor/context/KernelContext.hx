package haxor.context;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.core.Entity;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.math.Vector3;
import haxor.thread.Kernel;

/**
 * Class that handles all shader Kernel's information and structures.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class KernelContext
{

	/**
	 * Plane that will draw the screen.
	 */
	private var m_plane : Mesh3;
	
	/**
	 * List of all kernels.
	 */
	private var list : Array<Kernel>;
	
	/**
	 * Creates the context.
	 */
	private function new() { }
	
	/**
	 * Initializes the context.
	 */
	private function Initialize():Void
	{
		list = [];
	}
	
	/**
	 * 
	 */
	private function Execute():Void
	{
		for (i in 0...list.length) list[i].Execute();
	}
	
	/**
	 * Callback called when a kernel is created.
	 * @param	k
	 */
	private function OnCreate(k : Kernel):Void
	{
		list.push(k);
	}
	
	/**
	 * Callback called when a kernel is destroyed.
	 * @param	k
	 */
	private function OnDestroy(k: Kernel):Void
	{
		list.remove(k);
	}
}