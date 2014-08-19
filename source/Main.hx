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
import haxor.graphics.Enums.TextureFilter;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.Screen;
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture2D;
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
				
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		var s : Float = 0.8;
		
		var vl : FloatArray  =  FloatArray.Alloc([ 
		-s, -s, 0.5, 
		 s, -s, 0.5, 
		 s,  s, 0.5,
		-s,  s, 0.5
		 ]);
		 
		var uvl : FloatArray  =  FloatArray.Alloc([ 
		0.0,0.0,
		1.0,0.0,
		1.0,1.0,
		0.0,1.0,
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
		m.Set("uv0", uvl, 2);
		m.Set("color", cl, 4);
		
		m.topology = il;
		if (ss == null)
		{
			ss = 
			'
			<shader id="haxor/debug">
				<vertex>			
				attribute vec3 vertex;
				attribute vec2 uv0;
				attribute vec4 color;			
				uniform float Size;
				uniform float Time;
				varying vec4 v_color;		
				varying vec2 v_uv0;
				void main(void) 
				{ 
					v_color = color;
					v_uv0.x = vertex.x / (Size);
					v_uv0.y = -vertex.y / (Size);
					v_uv0.x = (v_uv0.x + 1.0) * 0.5;
					v_uv0.y = (v_uv0.y + 1.0) * 0.5;
					//v_uv0 = uv0;
					vec4 v = vec4(vertex,1.0);
					v.x = v.x*sin(Time);
					gl_Position = vec4(v);				
				}			
				</vertex>			
				<fragment>			
				uniform sampler2D Texture;
				uniform vec4 Tint[2];
				varying vec4 v_color;	
				varying vec2 v_uv0;
				void main(void) 
				{ 
					vec4 c = texture2D(Texture, v_uv0);
					//gl_FragColor = vec4(v_uv0.x,v_uv0.y,0.0,1.0);
					gl_FragColor = c;
				}			
				</fragment>
			</shader>
			';
		}
		
		var h : Int = 2048;
		var tex : Texture2D = new Texture2D(1, h, PixelFormat.Float4);
		var cl : Array<Color> = [Color.red, Color.green, Color.blue, Color.yellow];
		for (i in 0...h)
		{
			var r : Float = i / (h - 1);
			tex.data.SetPixel(0, i,Color.Sample(cl,r));
			//tex.data.SetPixel(0, i,new Color(Math.random(),Math.random(),Math.random(),1.0));
			//tex.data.SetPixel(0, i,cl[i]);
		}		
		tex.minFilter = TextureFilter.Nearest;
		tex.magFilter = TextureFilter.Nearest;
		tex.Upload(100);
		//tex.Apply();
		
		
		//var rtt : RenderTexture = new RenderTexture(128, 128, PixelFormat.RGBA8);
		
		
		var shd : Shader = new Shader(ss);	
		
		mat = new Material("DebugMaterial");
		mat.blend = true;
		mat.cull = CullMode.None;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);
		mat.shader = shd;
		mat.SetFloat("Size", s);
		mat.SetTexture("Texture", tex);
		mat.SetFloat4Array("Tint", [0.0, 1.0, 0.0, 0.3,1.0, 0.0, 0.0, 0.3]);
		
	}
	
	public function OnUpdate():Void
	{	
	
		
		
	}
	
	public function OnRender():Void
	{
				
		GL.Viewport(0, 0,cast Screen.width,cast Screen.height);
		GL.ClearColor(0.7, 0.3, 1.0, 1.0);
		GL.ClearDepth(1.0);
		GL.Clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
		
	
		if (mesh == null) return;
		if (mat == null) return;
		mat.SetFloat("Time", Time.elapsed);
		Graphics.RenderMesh(mesh, mat);		
		
	}
	
	
}