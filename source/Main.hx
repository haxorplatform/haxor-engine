package ;
import haxor.component.Camera;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Enums.CullMode;
import haxor.graphics.Enums.MeshPrimitive;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Enums.TextureFilter;
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
import haxor.io.Buffer;
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
	
		
	public var mat : Material;
	
	public var ss : String;
	
	var tex : Texture2D;
	
	var bmp : Bitmap;
	
	override public function Load():Bool 
	{	
		Web.root = "http://haxor.thelaborat.org/resources/";
		
		
		
		
		/*
		Web.Load("./character/medieval/animations/all_idle01.DAE", function(s:String, p:Float):Void
		{
		});
		
		
		Web.LoadImg("./projects/dungeon/big/DungeonAtlas01.jpg", function(b:Bitmap, p:Float):Void
		{
			Console.Log("p> " + p);
			if (p >= 1.0)
			{
				if (b != null)
				{
					bmp = b;	
					LoadComplete();
				}
			}
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
				
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		cam = entity.AddComponent(Camera);		
		cam.background = new Color(0.3, 0.3, 0.3);
		
		
		mat = Material.Transparent();		
		
	}
	
	public function OnUpdate():Void
	{	
	
		
		
	}
	
	public function OnRender():Void
	{
		Graphics.Clear(cam);
		if (mat == null) return;
		//mat.SetMatrix4("ViewMatrix", 
		mat.SetFloat("Time", Time.elapsed);
		Graphics.RenderMesh(Model.cube, mat);
		
		
		
	}
	
	
}