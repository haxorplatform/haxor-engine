package ;
import haxe.Timer;
import haxor.component.animation.Animation;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.MeshRenderer;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.component.Transform;
import haxor.context.Process;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Entity;
import haxor.core.Enums.AnimationWrap;
import haxor.core.Enums.CameraMode;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.ForceMode;
import haxor.core.Enums.InputState;
import haxor.core.IFixedUpdateable;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.RenderStats;
import haxor.core.Time;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.ds.SAP;
import haxor.ds.USet;
import haxor.graphics.Gizmo;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout;
import haxor.graphics.mesh.Model;
import haxor.graphics.Screen;
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.input.Input;
import haxor.input.Joystick;
import haxor.input.KeyCode;
import haxor.io.Buffer;
import haxor.io.file.ColladaFile;
import haxor.io.file.MaterialFile;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Random;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.net.Web;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext.GraphicAPI;
import haxor.physics.broadphase.SAPBroadPhase;
import haxor.physics.Collision;
import haxor.physics.Physics;
import haxor.physics.PhysicsMaterial;
import haxor.platform.Types.Float32;
import haxor.platform.Types.MeshBufferId;
import haxor.thread.Activity;




/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class Dungeon00 extends Application implements IUpdateable implements IRenderable
{
	
	static public function main():Void 
	{ 
		EntryPoint.Initialize();
	}
	
	public var cam : Camera;
	
	public var orbit : CameraOrbit;
	
	public var player : Transform;
	
	public var debug : Bool;
	
	var queue : Int = 3;
	
	#if html
	var ui : js.Stats;
	var field : js.html.DivElement;
	#end
	
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		#if html
		field = cast js.Browser.document.getElementById("field");
		ui = new js.Stats();
		ui.domElement.style.position = "absolute";
        ui.domElement.style.top = '0px';		
        js.Browser.document.body.appendChild(ui.domElement);
		
		Activity.Run(function(t:Float32):Bool
		{
			ui.update();
			return true;
		});
		#end
		
		debug = false;
		
		orbit = CameraOrbit.Create(80.0, 45, 30);
		
		var ci : CameraOrbitInput = orbit.AddComponent(CameraOrbitInput);
		orbit.smooth = 5.0;
		ci.zoomSpeed = 1.0;
		cam = orbit.entity.GetComponentInChildren(Camera);
		cam.far = 1000.0;
		cam.background = new Color(0.3, 0.3, 0.3);
		
		
	}
	
	
	
	public function OnUpdate():Void
	{	
		var log : String = "";
		
		log += "Stats";
		log += "\nVisible: " + RenderStats.visible;
		log += "\nCulled: " + RenderStats.culled;
		log += "\nActive: " + RenderStats.total;
		log += "\nRenderers: " + RenderStats.renderers;
		log += "\nTris: " + RenderStats.triangles;
		
		
		
		if (player != null)
		{
			var r : Quaternion = player.localRotation;
			//r.Multiply(Quaternion.FromAxisAngle(Vector3.up, 200.0 * Time.delta));
			r = Quaternion.FromAxisAngle(Vector3.up, 33.0);
			player.localRotation = r;			
			
			
		}
		
		#if html
		
		if (Input.Down(KeyCode.D1))
		{
			debug = !debug;
			if (!debug)
			{
				field.innerText = "";				
			}
			ui.domElement.style.display = debug ? "block" : "none";
		}
		
		
		if(debug) if(field!=null) field.innerText = log;		
		#end
		
		#if windows		
		application.window.title = StringTools.replace(log+" FPS: "+Time.fps, "\n", " ");
		#end
		
		#if android
		Console.Log(StringTools.replace(log + " FPS: " + Time.fps, "\n", " "));
		#end

		
	}
	
	public function OnRender():Void
	{			
		Gizmo.Grid(100.0, new Color(1, 1, 1, 0.1));
		Gizmo.Axis(Vector3.temp.Set(), Vector3.temp.Set(2, 2, 2));
	}
	
	
}