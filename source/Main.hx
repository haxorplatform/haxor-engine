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
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.Asset;
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

class Main extends Application implements IUpdateable implements IRenderable
{
	
	static public function main():Void 
	{ 
		EntryPoint.Initialize();
	}
	
	public var cam : Camera;
	
	public var orbit : CameraOrbit;
	
	public var container : Transform;
	
	public var mat : Material;
	
	public var player : Transform;
	
	var queue : Int = 3;
	
	#if html
	var field : js.html.DivElement;
	#end
	
	var fc : Camera;
	
	var cp : Transform;
	
	var ci0 : CameraOrbitInput;
	
	var ci1 : CameraOrbitInput;
	
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
		var ui : js.Stats = new js.Stats();
		ui.domElement.style.position = "absolute";
        ui.domElement.style.top = '0px';		
        js.Browser.document.body.appendChild(ui.domElement);
		
		Activity.Run(function(t:Float32):Bool
		{
			ui.update();
			return true;
		});
		#end
		
		var cpo : CameraOrbit;
		
		cpo = orbit = CameraOrbit.Create(40.0, 45, 45);
		
		ci0 = cpo.AddComponent(CameraOrbitInput);
		ci0.name = "C0";
		ci0.zoomSpeed = 1.0;
		cpo.smooth = 5.0;
		
		Activity.Delay(1.0, function() { ci0.enabled = false; } );
		
		
		cam = orbit.camera;
		cam.far = 1000.0;
		cam.background = new Color(0.3, 0.3, 0.3);
		
		
		cpo = CameraOrbit.Create( -1.0, 0, 0);
		fc = cpo.camera;
		fc.clear = ClearFlag.None;
		fc.near = 1.0;
		fc.far = 12.0;
		fc.fov = 40;
		
		ci1 = cpo.AddComponent(CameraOrbitInput);
		ci1.name = "C1";
		ci1.zoomSpeed = 1.0;
		cpo.smooth = 5.0;
		
		var mat : Material = Material.Transparent();
		mat.SetColor("Tint", Color.red);
		
		for (i in 0...1)
		{
			var mr : MeshRenderer = (new Entity("cube" + i)).AddComponent(MeshRenderer);
			mr.mesh = Model.cube;
			mr.material = mat;
			mr.transform.localScale = Random.sphere.Scale(15.0);
			mr.transform.localPosition = Random.sphere.Scale(40.0);
			mr.transform.localRotation = Quaternion.FromAxisAngle(Random.onSphere, Random.Range(0, 360));
		}
		
		Debug.renderer = true;
		Debug.rendererAABB = true;
	}
	
	public var obj : Array<MeshRenderer>;
	
	public var tp : Array<Vector3>;
	
	public function OnUpdate():Void
	{	
		if (ci0 == null) return;
		var log : String = "";
		
		log += "Stats";
		log += "\nSAP: " + Camera.SAPCulling;
		log += "\nVisible: " + RenderStats.visible;
		log += "\nCulled: " + RenderStats.culled;
		log += "\nActive: " + RenderStats.total;
		log += "\nRenderers: " + RenderStats.renderers;
		log += "\nTris: " + RenderStats.triangles;
		log += "\nInput0: " + ci0.enabled;
		log += "\nInput1: " + ci1.enabled;
		
		/*
		var upl : Process<IUpdateable> = EngineContext.update;
		log += "\nUpdates: " + upl.length + "/" + upl.list.length;		
		for (i in 0...upl.length)
		{
			var r : Resource = cast upl.list[i];
			log += "\n   " + r.name+" " + r.GetTypeName()+" "+r.__pid[0];
		}
		//*/
		
		if (Input.Down(KeyCode.A))
		{
			Camera.SAPCulling = !Camera.SAPCulling;
		}
		
		if (Input.Down(KeyCode.Q))
		{
			ci0.enabled = !ci0.enabled;			
			ci1.enabled = !ci1.enabled;
		}
		
		if (tp == null)
		{
			tp = [];
			for (i in 0...12)
			for (j in 0...12)
			for (k in 0...12)
			{
				var p : Vector3 = (new Vector3(i-6, j-6, k-6)).Scale(1.0);
				tp.push(p);
			}
			
		}
		
		if (fc != null)
		{			
			Debug.Camera(fc);			
			Debug.BoundingAABB(fc.m_aabb);
			/*
			for (i in 0...tp.length)
			{
				var p : Vector3 = tp[i];				
				var isc : Bool = fc.IsCulled(p);
				var cl : Color = isc ? Color.red : Color.green;
				cl.a = isc ? 0.1 : 1.0;
				Gizmo.Point(p, 7.0,cl);
			}
			//*/
		}
		
		
		
		#if html
		if(field!=null) field.innerText = log;		
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
		//Gizmo.Axis(Vector3.temp.Set(), Vector3.temp.Set(2, 2, 2));
		
		
	}
	
	
}