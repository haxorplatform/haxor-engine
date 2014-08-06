package ;




import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.mesh.Mesh;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.platform.graphics.GL;







/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class Main extends Application implements IUpdateable implements IRenderable
{
	
	static function main() { EntryPoint.Initialize(); }
	
	
	override public function Load():Bool 
	{	
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		Console.Log("mesh create");
		
		
		
		var m : Mesh = new Mesh();
		
		
		var f32 : FloatArray = FloatArray.Create([0.0, 1.1, 2.2, 3.3]);
		var i16 : UInt16Array = UInt16Array.Create([2, 3, 4, 5]);
		
		f32.Set(0, 1.1);
		Console.Log(f32.Get(0)+"!!!");
		
		m.Set("factor", f32, 1);
		m.Set("idx", i16, 1);
		
		m.topology = UInt16Array.Create([0, 1, 2, 2, 1, 3]);
		
		for (i in 0...m.attribs.length)
		{
			var a : MeshAttrib = m.GetAttribute(m.attribs[i]);
			trace(a.name+" " + a.type+" " + a.offset+" "+a.data.length);
		}
		//*/
	}
	
	
	
	public function OnUpdate():Void
	{		
		
	}
	
	public function OnRender():Void
	{
		
		//Console.Log("ups["+Time.ups+"] fps["+Time.fps+"] elapsed["+Time.elapsed+"] frames["+Time.frame+"]");
		
		GL.Clear(1.0, 0.0, 1.0,1.0,1.0);
	}
	
	
}