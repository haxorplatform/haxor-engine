/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor;
import haxe.Timer;
import haxor.component.AssetData;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.ByteArray;
import haxor.core.Console;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.graphics.filters.BlurFX;
import haxor.math.Color;
import haxor.math.Vector3;
import haxor.net.Web;
import haxor.texture.TextureCube;
import haxor.ui.HaxorLoader;



/**
 * Hello World Application
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Main extends Application
{
	
	/**
	 * Use it to start things before everything.
	 */
	static function main() { }
	
	
	/**
	 * Request the Preload of stuff before Initializing the application.
	 */
	override function Load():Void 
	{		
		//Creates an instance of the standard haxor loader
		loader = new HaxorLoader();
		
		//Loads shaders, materials and textures to test stuff.
		
		//Sets the root of loading ('./' will be replaced by this URL)
		Web.root = 
		"http://haxor.thelaborat.org/resources/";
		//"https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";		
		
		Asset.LoadCollada("haxor/primitive/cube", 									"./primitive/cube.DAE");
		Asset.LoadTextureHTML("haxor/texture/logo",									"./texture/misc/haxor.png");
		Asset.LoadTextureHTML("haxor/skybox/dark_top",								"./texture/skybox/gradient/dark_top.jpg");
		Asset.LoadTextureHTML("haxor/skybox/dark_sides", 							"./texture/skybox/gradient/dark_sides.jpg");
		Asset.LoadTextureHTML("haxor/skybox/dark_bottom",							"./texture/skybox/gradient/dark_bottom.jpg");
		Asset.LoadShader("haxor/internal/Skybox", 									"./shader/internal/Skybox.shader");
		Asset.LoadShader("haxor/unlit/FlatTexture", 								"./shader/unlit/FlatTexture.shader");
		Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTexture", 				"./material/opaque/unlit/FlatTexture.mat");
		
		
	}
	
	/**
	 * After preloading this method is called.
	 */
	override function Initialize():Void 
	{
		
		//Creates a orbit camera to cirle around stuff
		//Negative-Close to zero distances == FPS camera!
		var camera_orbit : CameraOrbit = CameraOrbit.Create(1.0, 45, -30);		
		//Smooth the transition of the camera angle and distance
		camera_orbit.smooth = 5.0;
		
		//Camera component to set some rendering configuration
		var camera : Camera = camera_orbit.camera;		
		camera.background = Color.FromHex("0x333333");
		
		//Creates a Skybox texture
		var skybox : TextureCube = new TextureCube();	
		//Fetches the loaded textures using their 'id'
		//Set them to the cubemap 'negative' and 'positive' sides
		skybox.px = Asset.Get("haxor/skybox/dark_sides");
		skybox.pz = Asset.Get("haxor/skybox/dark_sides");
		skybox.py = Asset.Get("haxor/skybox/dark_top");
		
		skybox.nx = Asset.Get("haxor/skybox/dark_sides");		
		skybox.nz = Asset.Get("haxor/skybox/dark_sides");		
		skybox.ny = Asset.Get("haxor/skybox/dark_bottom");
		
		//Send changes to GPU
		skybox.Apply();
		
		//Sets as background
		camera.skybox = skybox;
		
		//Sets flag to clear depth and draw the skybox
		camera.clear = ClearFlag.SkyboxDepth;
		
		
		//Create an Orbit Input component, allowing to click/touch and drag to rotate the camera.
		//Wheel / DoubleTouch controls zoom
		var orbit_input : CameraOrbitInput = camera_orbit.AddComponent(CameraOrbitInput);
		orbit_input.zoomSpeed = 0.5;
				
		//Fetches the loaded asset using its 'id' and calls the method 'GetAsset' to generate an Entity from the AssetFile.
		var cube : Entity = Asset.Get("haxor/primitive/cube").GetAsset();
		
		//Gets the MeshRenderer component to set its material.
		var cube_renderer : MeshRenderer = cube.GetComponentInChildren(MeshRenderer);
		cube_renderer.material = Resource.Instantiate(Asset.Get("haxor/material/opaque/unlit/FlatTexture")); //Duplicate the unlit opaque material
		cube_renderer.material.SetUniform("DiffuseTexture", Asset.Get("haxor/texture/logo")); 				 //Sets its texture as the Haxor Logo
		
		
		//Fetches the AssetData that contains custom user data set in the 3d software.
		var cube_data : AssetData = cube.GetComponentInChildren(AssetData);
		
		//Uses Console class to emit a warning with the desired message.
		Console.LogWarning("cube.asset.description = " + cube_data.content.asset.description);
		Console.LogWarning("cube.readme = " + cube_data.content.readme);
		Console.LogWarning("cube.number = " + cube_data.content.number);  //Float
		Console.LogWarning("cube.boolean = " + cube_data.content.boolean); //bool
		
		//Default FPS = 45fps to allow more time for complex scenes
		//Set to 60fps to make it more smooth.
		fps = 60;
		
		//CTRL+SHIFT+J --> With the console open the breakpoint will be called here.
		Console.Breakpoint();
		
		//Wait stuff finish creation and show the scene hierarchy
		Timer.delay(function()
		{
			trace(Transform.root.OutputHierarchy());
		},1000);
	}
	
	
}