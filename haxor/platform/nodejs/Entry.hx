#if nodejs

package haxor.platform.nodejs;
import js.Node;
import haxor.core.Time;
import haxor.math.Mathf;
import haxor.core.Engine;
import haxor.platform.Types.Float32;
import haxe.Timer;
import js.Browser;
import haxor.core.BaseApplication;
import haxor.core.Entity;
import haxor.core.Console;

/**
 * Entry point class that controls the initialization of NodeJS projects.
 * It uses as class reference the 'type' attribute.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Entry
{
	/**
	 * Reference to the application.
	 */
	static private var m_application : NodeApplication;
	
	/**
	 * SetTimeout loop id.
	 */
	static private var m_interval_id : Int;
	
	/**
	 * Last interval clock.
	 */
	static private var m_step_clock : Float;
	
	/**
	 * Starting time of SetInterval
	 */
	static private var m_itv_offset_clock : Float;
	
	/**
	 * Startup the application entry point.
	 */
	static public function Initialize():Void 
	{ 		
		Console.Initialize();
		
		var app_class_type   	: String = "Main";		
		
		app_class_type = Node.process.argv.length > 2 ? Node.process.argv[2] : app_class_type;
		
		Console.Log("Haxor> NodeJS Platform Init verbose[" + Console.verbose+"] application[" + app_class_type+"]", 1);
				
		if (app_class_type == "")
		{
			Console.Log("Haxor> Error. You must define an Application class.");
			return;
		}
		
		var app_class : Class<Dynamic> = Type.resolveClass(app_class_type);
		
		if (app_class == null) 
		{ 
			Console.Log("Haxor> Error. Class [" + app_class_type+"] not found! Try adding 'import " + app_class_type+"' in your Main file."); 
			return; 
		}
		
		Engine.Initialize();
		
		var e : Entity = new Entity("application");
		m_application  = e.AddComponent(cast app_class);
				
		if (!Std.is(m_application, BaseApplication))
		{ 
			Console.Log("Haxor> Error. Class [" + app_class_type+"] does not extends Application!"); 
			return; 
		}
		
		Console.Log("Haxor> Application [" + app_class_type+"] created successfully!", 1);
		
		//EngineContext.Build();
		
		m_interval_id  = -1;						
		m_step_clock   = -1;
		
		m_application.runOnBackground = true;
		
		Run();
				
		if (m_application.Load())
		{
			m_application.LoadComplete();
		}
		
	}
	
	/**
	 * Starts the loop.
	 */
	static private function Run():Void
	{
		CancelInterval();		
		var itv_id : Int = -1;
		var itv_fn : Dynamic = IntervalLoop;
		untyped { itv_id = setInterval(itv_fn, 16); }
		m_interval_id = itv_id;		
	}
		
	/**
	 * Executes the loop step.
	 * @param	p_time
	 * @param	p_visible
	 */
	static private function Step(p_time : Float32,p_visible:Bool):Void
	{	
		if (m_step_clock < 0) m_step_clock = p_time;		
		var t : Float    = p_time;		
		var dt : Float   = t - m_step_clock;
		m_step_clock 	 = t;		
		var steps : Int  = p_visible ? 1 : Mathf.MaxInt(1, cast Mathf.Floor(dt / 16));
		for (i in 0...steps)
		{
			Time.m_system = t;
			m_application.Update();
			if(p_visible) m_application.Render();
		}
	}
		
	/**
	 * IE8/Windows Unfocus compatible loop.
	 */
	static private function IntervalLoop():Void
	{	
		var t : Float = Timer.stamp() * 1000.0;
		Step(t,true);
	}
	
	/**
	 * Cancels the set interval loop.
	 */
	static private function CancelInterval():Void { if (m_interval_id > 0) Browser.window.clearInterval(m_interval_id); m_interval_id = -1; }
	
	
}

#end