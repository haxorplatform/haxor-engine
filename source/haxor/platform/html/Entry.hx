#if html
package haxor.platform.html;
import haxor.dom.Container;
import haxor.io.file.Asset;
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
 * When it runs the __init__ method, it searches for [hx] tags in the HTML's [body] and creates one application for each one.
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
	 * Startup the application entry point.
	 */
	static public function Initialize():Void { Browser.window.onload = OnWindowLoad; }
	
	
	/**
	 * Callback to listen for the document load complete event and create all applications.
	 * @param	p_event
	 */
	static function OnWindowLoad(p_event:Event):Void
	{	
		Console.Initialize();
		
		var script_list : NodeList = Browser.document.getElementsByTagName("SCRIPT");
		
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
		
		var tag_strings : NodeList = Browser.document.getElementsByTagName("strings");
		
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
		
		#if !ie8
		GL.Initialize(m_application);
		GL.m_gl.Initialize(app_container_id);
		GL.m_gl.CheckExtensions();
		#end
		
		Console.Log("Haxor> Creating Stage with ["+app_container_id+"]");
		var stage : DOMStage = new DOMStage(m_application.m_container);
		stage.Parse(m_application.m_container);
		
		Timer.delay(function():Void {  m_application.m_container.style.display = cd; }, 100);
		
		EngineContext.Build();
				
		m_input = new HTMLInputHandler(app_input_id);
		Input.m_handler	= m_input;
		
		if (Browser.window.requestAnimationFrame != null)
		{
			Browser.window.requestAnimationFrame(RequestAnimationCallback);
		}
		else
		{
			Time.m_clock_0 = (Timer.stamp() * 1000.0);
			TimeOutLoop();
		}
		
		if (m_application.Load())
		{
			m_application.LoadComplete();
		}
		
	}
	
	/**
	 * Browser update/rendering loop.
	 * @param	p_time
	 * @return
	 */
	static private function RequestAnimationCallback(p_time : Float32):Bool
	{	
		Time.m_system = p_time;
		m_application.Update();
		m_application.Render();
		Browser.window.requestAnimationFrame(RequestAnimationCallback);
		return true;
	}
	
	/**
	 * IE8 compatible loop.
	 */
	static private function TimeOutLoop():Void
	{
		Time.m_system = (Timer.stamp() * 1000.0) - Time.m_clock_0;
		m_application.Update();
		m_application.Render();
		Browser.window.setTimeout(TimeOutLoop, 10);
	}
	
	
}

#end