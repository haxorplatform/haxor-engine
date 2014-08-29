package ;
import haxe.Timer;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
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
		
		orbit = CameraOrbit.Create(3.0, 45, 45);
		cam = orbit.entity.GetComponentInChildren(Camera);
		cam.background = new Color(0.3, 0.3, 0.3);
		
		var tex : Texture2D = Texture2D.green;
		tex = Asset.Get("texture");
		
		container = (new Entity("container")).transform;
		var l : Float = 2;
		
		var px : Float = 0.0;
		var py : Float = 0.0;
		var pz : Float = 0.0;
			
		mat = Material.Transparent(Asset.Get("texture"));
		mat.name = "T";
		mat.SetTexture("Tex0", Texture2D.red);
		mat.blend = true;
		
		Activity.Iterate(0,1500,function(i:Int):Bool
		//for (i in 0...1400)
		{	
			mr = (new Entity("cube" + i)).AddComponent(MeshRenderer);			
			mr.transform.localScale = new Vector3(0.1, 0.1, 0.1);
			mr.transform.parent = container;			
			mr.transform.position = new Vector3(px, py, pz);
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
		},50);
		
	}
	
	public function OnUpdate():Void
	{	
		if (orbit != null)
		{
			orbit.angle.x += Time.delta * 30.0;			
		}
	
		if (Joystick.available)
		{
			
		}
		
		if(Input.Down(KeyCode.Mouse0))trace("left");
		if (Input.Down(KeyCode.Mouse1)) trace("middle");
		if (Input.Down(KeyCode.Mouse2)) trace("right");
		if (Input.Down(KeyCode.A)) trace("A");
		if(Input.Down(KeyCode.ControlKey))trace("Left Control");
		//*/
		if (Mathf.Abs(Input.wheel) > 0) trace(Input.wheel);
		//trace(Input.wheel + " " + Input.mouse.ToString() + " " + Input.deltaMouse.ToString()+" "+Input.GetInputState(KeyCode.Mouse0));
	}
	
	public function OnRender():Void
	{	
		GL.Clear(GL.DEPTH_BUFFER_BIT);
		Gizmo.Grid(100.0,new Color(1,1,1,0.1));
		Gizmo.Axis(50.0);
	}
	
	
}