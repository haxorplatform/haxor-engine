#if html
package haxor.platform.html;
import js.html.VisibilityState;
import js.html.HTMLCollection;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import haxor.platform.html.graphics.WebGL;
import haxor.math.Mathf;
import haxor.core.Asset;
import haxor.dom.Container;
import js.html.NamedNodeMap;
import haxor.dom.DOMStage;
import haxe.Timer;
import haxor.platform.Types.Float32;
import haxor.platform.html.input.HTMLInputHandler;
import haxor.input.Input;
import haxor.context.EngineContext;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.Time;
import haxor.core.BaseApplication;
import haxor.core.Console;
import js.html.ScriptElement;
import js.html.Node;
import js.html.NodeList;
import js.html.Element;
import js.html.Event;
import js.Browser;
import haxor.graphics.GL;


/**
 * Entry point class that controls the initialization of JS/HTML projects.
 * When it runs the __init__ method, it searches the div specified in the 'container' attrib in the <script> running this app.
 * It uses as class reference the 'type' attribute.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Entry
{
	/**
	 * Reference to the application.
	 */
	static private var m_application : HTMLApplication;
	
	/**
	 * Reference to the input handler.
	 */
	static private var m_input : HTMLInputHandler;
	
	/**
	 * Flag that indicates if the browser window is focused.
	 */
	static private var m_window_focus : Bool;
	
	/**
	 * Flag that indicates if RequestAnimationFrame exists.
	 */
	static private var m_raf_enabled : Bool;
	
	/**
	 * Flag that indicates if the browser has precision clock.
	 */
	static private var m_has_pc : Bool;
	
	/**
	 * Id of the RAF loop.
	 */
	static private var m_raf_id : Int;
	
	/**
	 * SetTimeout loop id.
	 */
	static private var m_interval_id : Int;
	
	/**
	 * Last interval clock.
	 */
	static private var m_step_clock : Float;
	
	/**
	 * Starting time of RAF.
	 */
	static private var m_raf_offset_clock : Float;
	
	/**
	 * Starting time of SetInterval
	 */
	static private var m_itv_offset_clock : Float;
	
	/**
	 * Startup the application entry point.
	 */
	static public function Initialize():Void 
	{ 	
		Browser.window.onload = OnWindowLoad; 
	}
	
	
	/**
	 * Callback to listen for the document load complete event and create all applications.
	 * @param	p_event
	 */
	static function OnWindowLoad(p_event:Event):Void
	{	
		Console.Initialize();
		
		var script_list : HTMLCollection = Browser.document.getElementsByTagName("SCRIPT");
		
		var attrib : String = "";
		
		var app_class_type   	: String = "Main";		
		var app_container_id 	: String = "haxor";		
		var app_input_id 		: String = "haxor";
		
		//Check if verbose level was informed.
		for (i in 0...script_list.length)
		{
			var scr : ScriptElement = cast script_list.item(i);
			attrib = scr.getAttribute("verbose");
			if (attrib != null)
			{
				attrib = attrib == "" ? "0" : attrib;
				Console.verbose = Std.parseInt(attrib);
			}
			
			attrib = scr.getAttribute("application");			
			if (attrib != null)
			{
				app_class_type = attrib;				
			}
			
			attrib = scr.getAttribute("container");			
			if (attrib != null)
			{
				app_container_id = attrib;				
			}
			
			attrib = scr.getAttribute("input");			
			if (attrib != null)
			{
				app_input_id = attrib;				
			}
		}
		
		Console.Log("Haxor> HTML Platform Init verbose[" + Console.verbose+"] application[" + app_class_type+"] container["+app_container_id+"]", 1);
		
		var tag_strings : HTMLCollection = Browser.document.getElementsByTagName("strings");
		
		if (tag_strings != null)
		{
			if (tag_strings.length > 0)
			{
				var k:Int = 0;				
				for (i in 0...tag_strings.length)
				{
					var it : Element = cast tag_strings.item(i);
					var l : NodeList = it.childNodes;
					for (j in 0...l.length)
					{
						var e : Element = cast l.item(j);
						switch(e.nodeName.toLowerCase())
						{
							case "entry":
							var key : String = e.getAttribute("key");
							var val : String = e.textContent;		
							Asset.Add(key, val);
							k++;
						}					
						
					}			
					it.remove();
				}
				
				Console.Log("Haxor> Found " + k + " Strings",2);
			}
		}
		
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
		
		m_application.m_container = Browser.document.getElementById(app_container_id);
		
		if (m_application.m_container == null)
		{
			Console.Log("Graphics> DOM container not defined id["+app_container_id+"] using 'body'.");
			m_application.m_container = Browser.document.body;
		}
		
		var cd : String = m_application.m_container.style.display;
		m_application.m_container.style.display = "none";
		
		#if (!ie8 || !nodejs)
		GL.Initialize(m_application);
		GL.m_gl.Initialize(app_container_id);
		GL.m_gl.CheckExtensions();
		#end
		
		//Console.Log("Haxor> Creating Stage with ["+app_container_id+"]",1);
		//var stage : DOMStage = new DOMStage(m_application.m_container);
		//stage.Parse(m_application.m_container);
		
		Timer.delay(function():Void {  m_application.m_container.style.display = cd; }, 100);
		
		EngineContext.Build();
				
		m_input = new HTMLInputHandler(app_input_id);
		Input.m_handler	= m_input;
		
		m_raf_enabled  = Browser.window.requestAnimationFrame != null;
		m_has_pc	   = Browser.window.performance != null;		
		m_raf_id	   = -1;
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
		//m_itv_offset_clock = m_has_pc ? Browser.window.performance.now() : (Timer.stamp() * 1000);
		//m_interval_id = Browser.window.setInterval(IntervalLoop, 16);
		
		if (m_raf_enabled)
		{
			CancelRAF();
			m_raf_offset_clock = m_has_pc ? Browser.window.performance.now() : 0.0;
			m_raf_id = Browser.window.requestAnimationFrame(RAFLoop);
		}
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
			Time.m_system = m_has_pc ? Browser.window.performance.now() : t;
			m_application.Update();
			if(p_visible) m_application.Render();
		}
	}
		
	/**
	 * Browser update/rendering loop.
	 * @param	p_time
	 * @return
	 */
	static private function RAFLoop(p_time : Float32):Bool
	{	
		var t : Float32 = m_has_pc ? Browser.window.performance.now() : p_time;				
		Step(t - m_raf_offset_clock,true);
		m_raf_id = Browser.window.requestAnimationFrame(RAFLoop);
		return true;
	}
	
	/**
	 * IE8/Windows Unfocus compatible loop.
	 */
	static private function IntervalLoop():Void
	{			
		var v : Bool = Browser.document.visibilityState != VisibilityState.HIDDEN;
		if (v) return;
		if (!m_application.runOnBackground) return;
		var t : Float    = m_has_pc ? Browser.window.performance.now() : (Timer.stamp() * 1000.0);
		Step(t - m_itv_offset_clock, v);
	}
	
	
	/**
	 * Cancels the RAF Loop
	 */
	static private function CancelRAF():Void { if (m_raf_id > 0) Browser.window.cancelAnimationFrame(m_raf_id); m_raf_id = -1; }
	
	/**
	 * Cancels the set interval loop.
	 */
	static private function CancelInterval():Void { if (m_interval_id > 0) Browser.window.clearInterval(m_interval_id); m_interval_id = -1; }
	
	
}

#end