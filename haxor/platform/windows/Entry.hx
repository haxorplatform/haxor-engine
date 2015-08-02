#if windows
package haxor.platform.windows;
import haxor.math.Vector3;
import haxor.graphics.mesh.Model;
import haxor.graphics.material.Material;
import haxor.component.MeshRenderer;
import haxor.graphics.GL;
import haxor.core.Engine;
import haxor.core.Application;
import haxor.core.BaseApplication;
import haxor.core.Entity;
import haxor.core.Console;
import haxor.context.EngineContext;
import cpp.Lib;
import haxe.Int32;
import haxe.Int64;


/**
 * Entry point class that controls the initialization of Windows projects.
 * When it runs the Initialize method, it creates a native window instance and instantiates the chosen application passed in the arguments.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Entry
{
	//__init__ don't have basic classes available.
	//Manual start it is.
	/*	
	static function __init__():Void
	{
		Initialize();
	}
	//*/
	
	/**
	 * Initialize this platform application.
	 */
	static public function Initialize():Void
	{
		Console.Initialize();
		
		var app_class_type : String = "";
		
		var app_title : String = "Haxor";
		
		var args : Array<String> = Sys.args();
		
		for (i in 0... args.length)
		{
			
			if (args[i].toLowerCase().indexOf("-v") >= 0)
			{
				var vl : Int = args[i].length - 1;
				Console.verbose = vl;
			}
						
			if (args[i].toLowerCase() == "-main")
			{
				var p : Int = i + 1;
				app_class_type = (p >= args.length) ? "" : args[p];				
			}
			
			if (args[i].toLowerCase() == "-t")
			{
				var p : Int = i + 1;
				app_title = (p >= args.length) ? "" : args[p];				
			}
		}
		
		if (app_class_type == "")
		{
			Console.Log("Haxor> Application type not found. Default to [Main]");
			app_class_type = "Main";
		}
		
		Console.Log("Haxor> Windows Platform Init verbose[" + Console.verbose+"] application[" + app_class_type+"]", 1);
		
		var app_class : Class<Dynamic> = Type.resolveClass(app_class_type);
		
		if (app_class == null) 
		{ 
			Console.Log("Haxor> Error. Class [" + app_class_type+"] not found! Try adding 'import " + app_class_type+"' in your Main file."); 
			Sys.command("pause");
			return; 
		}
		
		Engine.Initialize();
		
		var app : Application;
		var e : Entity = new Entity("application");
		app = e.AddComponent(cast app_class);
				
		if (!Std.is(app, BaseApplication))
		{ 
			Console.Log("Haxor> Error. Class [" + app_class_type+"] does not extends Application!"); 
			return; 
		}
		
		var wnd : Window = new Window(app, app_title, 0, 0, 800, 600);
		
		GL.Initialize(app);		
		GL.m_gl.Initialize(wnd);
		GL.m_gl.CheckExtensions();
		
		EngineContext.Build();
		
		//need to remove this!!
		var dummy : MeshRenderer = (new Entity("__dummy__")).AddComponent(MeshRenderer);
		dummy.material = Material.Opaque();
		dummy.mesh = Model.planeXY;
		dummy.transform.localScale = new Vector3();
		
		if (app.Load()) app.LoadComplete();
		
		wnd.Run();
		
		
		
	}
	
}

#end