package haxor.context;
import haxor.component.Camera;

/**
 * Class that handles the Camera class structures and functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class CameraContext
{
	/**
	 * Unique class id for Cameras.
	 */
	private var cid : Int = 0;

	/**
	 * List of all cameras in the scene.
	 */
	private var list : Array<Camera>;
	
	/**
	 * Creates the context.
	 */
	private function new() 
	{
		list = [];
	}
	
	private function Create(p_camera:Camera):Void
	{
		list.push(p_camera);
		SortCameraList();
	}
	
	private function Destroy(p_camera:Camera):Void
	{
		list.remove(p_camera);
		SortCameraList();
	}
	
	private function Resize():Void
	{
		
	}
	
	private function SortCameraList():Void
	{
		list.sort(function(a:Camera, b:Camera):Int { return a.order == b.order ? (a.entity.name < b.entity.name ? -1 : 1) : (a.order < b.order ? -1 : 1); });		
	}
}