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
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.platform.graphics.GL;
import haxor.platform.graphics.GraphicContext.GraphicAPI;
import haxor.platform.Types.MeshBufferId;



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
	
	override public function Load():Bool 
	{	
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		
		var s : Float = 0.8;
		
		var vl : FloatArray  =  FloatArray.Alloc([ 
		-s, -s, 0.5, 
		 s, -s, 0.5, 
		 0,  s, 0.5 
		 ]);
		
		var cl : FloatArray  =  FloatArray.Alloc([
		1.0,  0.0, 0.0,1.0,
		0.0,  1.0, 0.0,1.0,
		0.0,  0.0, 1.0, 1.0,
		0.0,  0.0, 1.0,1.0
		]);
		
		
		var il : UInt16Array =  UInt16Array.Alloc([0, 1, 2]);
		
		var m : Mesh = mesh = new Mesh(); 
		m.Set("vertex", vl, 3);
		//m.Set("color", cl, 4);
		
		m.topology = il;
		
		var ss : String = 
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
		
		var shd : Shader = new Shader(ss);
		
		mat = new Material("DebugMaterial");
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);
		mat.shader = shd;
		
		//*/
		
		
	}
	
	
	
	public function OnUpdate():Void
	{		
		
	}
	
	var init : Bool = false;
	
	var vb : MeshBufferId;
		
	public function OnRender():Void
	{
		
		//Console.Log("ups["+Time.ups+"] fps["+Time.fps+"] elapsed["+Time.elapsed+"] frames["+Time.frame+"]");
		
		GL.ClearColor(1.0, 0.0, 1.0, 1.0);
		GL.ClearDepth(1.0);
		GL.Clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
		
	
		if (mesh == null) return;
		if (mat == null) return;
		Graphics.RenderMesh(mesh, mat);		
		
	}
	
	
}