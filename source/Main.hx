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
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.Stats;
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
	
	public var mesh : Mesh;
	
	public var cam : Camera;
	
	public var orbit : CameraOrbit;
	
	public var mr : MeshRenderer;
	
	public var container : Transform;
	
	public var mat : Material;
	
	public var ss : String;
	
	var tex : Texture2D;
	
	var bmp : Bitmap;
	
	#if html
	var field : js.html.DivElement;
	#end
	
	override public function Load():Bool 
	{	
		Web.root = "http://haxor.thelaborat.org/resources/";
		
		Web.LoadTexture2D("./texture/misc/metal.jpg",true, function(t:Texture2D, p:Float):Void
		{
			if (p >= 1.0)
			{
				Asset.Add("texture", t);
				LoadComplete();
			}
		});
		//*/
		
		
		/*
		Web.Load("./character/medieval/animations/all_idle01.DAE", function(s:String, p:Float):Void
		{
		});
		
		
		
		//*/
		/*
		Web.Load("./shader/unlit/NDC.shader", function(d:String, p:Float):Void
		{	
			if (p >= 1.0)
			{
				ss = d;				
				LoadComplete();
			}
		});
		//*/
		/*
		Web.Load("./asset/dungeon/module0/asset.dae",function(d:String, p:Float):Void
		{		
			trace(p);
			if (p >= 1.0)
			{
				if (d != null)
				{
					Console.Log(d.substr(0, 50));
				}
			}
		});
		//*/
		/*
		Web.Load("./texture/logo.png",function(d:String, p:Float):Void
		{			
			if (p >= 1.0)
			{
				if (d != null)
				{
					Console.Log(d.substr(0, 50));
				}
			}
		});
		
		//*/
				
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
		
		Activity.Run(function(t:Float):Bool
		{
			ui.update();
			return true;
		});
		#end
		
		
		
		orbit = CameraOrbit.Create(-0.5, 0, 0);
		orbit.AddComponent(CameraOrbitInput);
		cam = orbit.entity.GetComponentInChildren(Camera);
		
		//cam = (new Entity("camera")).AddComponent(Camera);
		//cam.transform.localPosition = new Vector3(5, 5, 5);
		//cam.transform.localRotation = Quaternion.LookAt(new Vector3(5, 5, 5), Vector3.zero);		
		cam.background = new Color(0.3, 0.3, 0.3);
		
		var tex : Texture2D = Texture2D.green;
		tex = Asset.Get("texture");
		
		container = (new Entity("container")).transform;
		
		//cam.transform.parent = container;
		
		var l : Float = 2;
		
		var px : Float = 0.0;
		var py : Float = 0.0;
		var pz : Float = 0.0;
			
		mat = Material.Transparent(Asset.Get("texture"));
		mat.name = "T";
		mat.SetTexture("Tex0", Texture2D.red);
		mat.blend = true;
		
		
		
		Activity.Iterate(0,5000,function(i:Int):Bool
		//for (i in 0...30000)
		{	
			mr = (new Entity("cube" + i)).AddComponent(MeshRenderer);			
			mr.transform.localScale = 
			//Vector3.one.Scale(2.0);
			Vector3.temp.Set(0.1, 0.1, 0.1).Scale(Random.Range(3.0, 50.0));
			mr.transform.parent = container;			
			mr.transform.localPosition =			
			//new Vector3(0.0, 0.0, 40.0);
			Random.onSphere.Scale(50.0 + Random.value * 900.0);
			mr.mesh 	= Model.cube;
			
			mr.material = mat;						
			
			px += 0.12;
			
			if (px >= l)
			{
				px = 0.0;
				pz += 0.12;
				if (pz >= l)
				{
					pz = 0.0;
					py += 0.12;
					
				}
			}
			return true;
		}
		,10);//<<<<<<< here
		
	}
	
	public function OnUpdate():Void
	{	
		if (orbit != null)
		{
			//orbit.angle.x += Time.delta * 30.0;			
		}
		if (container != null)
		{
			//var lr : Quaternion = container.localRotation;
			//lr.Multiply(Quaternion.FromAxisAngle(Vector3.up, Time.delta * 30));
			//container.localRotation = lr;
		}
		
		var log : String = "";
		
		log += "Stats";
		log += "\nVisible: " + Stats.visible;
		log += "\nCulled: " + Stats.culled;
		log += "\nTotal: " + Stats.total+"/"+Stats.renderers;
		log += "\nTriangles: " + Stats.triangles;
		
		if (Joystick.available)
		{
			//trace(Input.joystick[0].ToString());
		}
		
		
		#if html
		if(field!=null) field.innerText = log;		
		#end
		
		#if windows		
		application.window.title = StringTools.replace(log+" FPS: "+Time.fps, "\n", " ");
		#end
		
	}
	
	public function OnRender():Void
	{	
		GL.Clear(GL.DEPTH_BUFFER_BIT);
		Gizmo.Grid(100.0,new Color(1,1,1,0.1));
		Gizmo.Axis(50.0);
	}
	
	
}