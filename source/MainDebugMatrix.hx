package ;
import haxe.Timer;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.context.Process;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Enums.InputState;
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
import haxor.io.file.Asset;
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
	
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		
		//Web.LoadCollada("./character/medieval/animations/all_idle01.DAE",function(f : ColladaFile, p:Float32):Void
		Web.LoadCollada("./character/skeleton/grunt/animation_idle01.DAE",function(f : ColladaFile, p:Float32):Void
		{
			if (p >= 1.0)
			{
				Asset.Add("animation_idle", f);
				if ((--queue) <= 0) LoadComplete();
			}
		});
		
		//Web.LoadTexture2D("./character/medieval/knight/DiffuseTexture.png",true,function(t : Texture2D, p:Float32):Void
		Web.LoadTexture2D("./character/skeleton/grunt/DiffuseTexture.png",true,function(t : Texture2D, p:Float32):Void
		{
			if (p >= 1.0)
			{
				Asset.Add("texture_diffuse", t);
				if ((--queue) <= 0) LoadComplete();
			}
		});
		
		//Web.LoadCollada("./character/medieval/knight/asset.dae",function(f : ColladaFile, p:Float32):Void
		Web.LoadCollada("./character/skeleton/grunt/model.DAE",function(f : ColladaFile, p:Float32):Void
		{
			if (p >= 1.0)
			{
				Asset.Add("model", f);
				if ((--queue) <= 0) LoadComplete();
			}
		});
		
		
				
		return false;
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
		
		orbit = CameraOrbit.Create(400.0, 45, 30);
		
		var ci : CameraOrbitInput = orbit.AddComponent(CameraOrbitInput);
		orbit.smooth = 5.0;
		ci.zoomSpeed = 0.1;
		cam = orbit.entity.GetComponentInChildren(Camera);
		cam.far = 1000.0;
		cam.background = new Color(0.3, 0.3, 0.3);
		
		container = (new Entity("container")).transform;
					
		mat = Material.Opaque(Asset.Get("texture_diffuse"));
		mat.shader = Shader.FlatTextureSkin;
		mat.name = "PlayerMaterial";				
		//mat.SetTexture("DiffuseTexture", Asset.Get("texture_diffuse"));
		
		var cf : ColladaFile = Asset.Get("model");
		
		player = new Entity("player").transform;
		var asset : Transform = cast(cf.asset, Entity).transform;
		asset.parent = player;
		//asset.rotation = Quaternion.FromAxisAngle(Vector3.right, 90.0);
		//asset.localScale = new Vector3(0.005, 0.005, 0.005);
		//asset.localScale = new Vector3(2.0, 2.0, 2.0);
		
		var mr : Array<MeshRenderer> = cast player.GetComponentsInChildren(MeshRenderer);
		for (i in 0...mr.length)
		{	
			//if (i == 1) mr[i].enabled = false;			
			mr[i].material = mat;			
		}
		
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
		GL.Clear(GL.DEPTH_BUFFER_BIT);
		//Gizmo.Grid(100.0,new Color(1,1,1,0.1));
		//Gizmo.Axis(50.0);
		
	}
	
	
}