package ;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Enums.CullMode;
import haxor.graphics.Enums.MeshPrimitive;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.texture.Bitmap;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.math.Color;
import haxor.net.Web;
import haxor.platform.graphics.GL;
import haxor.platform.graphics.GraphicContext.GraphicAPI;
import haxor.platform.Types.BitmapFile;
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
	
	public var mat : Material;
	
	public var ss : String;
	
	override public function Load():Bool 
	{	
		Web.root = "https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";
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
		
		
		var bmp : Bitmap = new Bitmap(2, 2, PixelFormat.RGBA8);
		bmp.SetPixel(0, 0, Color.red);
		bmp.SetPixel(1, 0, Color.green);
		bmp.SetPixel(0, 1, Color.blue);
		bmp.SetPixel(1, 1, Color.yellow);
		
		
		Console.Log(bmp.GetPixel(0, 0).ToString());
		Console.Log(bmp.GetPixel(1, 0).ToString());
		Console.Log(bmp.GetPixel(0, 1).ToString());
		Console.Log(bmp.GetPixel(1, 1).ToString());
		
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		application.fps = 50;
		
		var s : Float = 0.8;
		
		var vl : FloatArray  =  FloatArray.Alloc([ 
		-s, -s, 0.5, 
		 s, -s, 0.5, 
		 s,  s, 0.5,
		-s,  s, 0.5
		 ]);
		
		var cl : FloatArray  =  FloatArray.Alloc([
		1.0,  0.0, 0.0,1.0,
		0.0,  1.0, 0.0,1.0,
		0.0,  0.0, 1.0,1.0,
		1.0,  1.0, 0.0,1.0
		]);
		
		
		var il : UInt16Array =  UInt16Array.Alloc([0, 1, 2,0,2,3]);
		
		var m : Mesh = mesh = new Mesh(); 
		m.Set("vertex", vl, 3);
		m.Set("color", cl, 4);
		
		m.topology = il;
		if (ss == null)
		{
			ss = 
			'
			<shader id="haxor/debug">
				<vertex>			
				attribute vec3 vertex;
				attribute vec4 color;			
				varying vec4 v_color;			
				void main(void) 
				{ 
					v_color = color;
					gl_Position = vec4(vertex, 1.0);				
				}			
				</vertex>			
				<fragment>					
				varying vec4 v_color;			
				void main(void) 
				{ 
					gl_FragColor = v_color;
				}			
				</fragment>
			</shader>
			';
		}
		
		
		var shd : Shader = new Shader(ss);
		
		mat = new Material("DebugMaterial");
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);
		mat.shader = shd;
		
		
	}
	
	public function OnUpdate():Void
	{	
	
		
		
	}
	
	public function OnRender():Void
	{
				
		GL.ClearColor(1.0, 0.0, 1.0, 1.0);
		GL.ClearDepth(1.0);
		GL.Clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
		
	
		if (mesh == null) return;
		if (mat == null) return;
		Graphics.RenderMesh(mesh, mat);		
		
	}
	
	
}