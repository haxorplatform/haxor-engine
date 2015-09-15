package haxor.component.util;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.core.IUpdateable;
import haxor.graphics.texture.TextureCube;
import haxor.input.Input;
import haxor.input.KeyCode;

/**
 * Stores and selects a skybox to set to the main camera.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class SkyboxSelector extends Behaviour implements IUpdateable
{

	/**
	 * Skyboxes.
	 */
	@serialize
	public var Skybox0 : TextureCube;
	@serialize
	public var Skybox1 : TextureCube;
	@serialize
	public var Skybox2 : TextureCube;
	
	
	/**
	 * Update
	 */
	public function OnUpdate():Void
	{
		#if !editor
		if (Camera.main == null) return;
		if (Input.Down(KeyCode.D1)) if(Skybox0!=null) Camera.main.skybox = Skybox0;
		if (Input.Down(KeyCode.D2)) if(Skybox1!=null) Camera.main.skybox = Skybox1;
		if (Input.Down(KeyCode.D3)) if(Skybox2!=null) Camera.main.skybox = Skybox2;
		#end
	}
	
	
}