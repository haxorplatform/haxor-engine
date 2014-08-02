/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.core;

import haxe.Timer;
import haxor.core.Application.ApplicationProtocol;
import haxor.net.Web;
import js.Boot;
import js.html.Image;
import js.html.Node;
import js.html.ScriptElement;
import haxor.api.SoundAPI;
import haxor.api.TextureAPI;
import haxor.component.Animation;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.component.MeshRenderer;
import haxor.component.Renderer;
import haxor.component.RigidBody;
import haxor.component.Transform;
import haxor.editor.Gizmo;
import haxor.editor.IGizmoRenderer;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.graphics.MeshTemplate.Mesh3;
import haxor.graphics.Screen;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.physics.Collider;
import haxor.physics.Physics;
import haxor.texture.RenderTexture;
import haxor.texture.Texture.TextureFormat;
import haxor.texture.Texture2D;
import haxor.thread.Thread;
import haxor.ui.HaxorCanvas;
import haxor.ui.Stage;
import haxor.ui.UIEntity;
import js.html.WebSocket;
import js.html.XMLHttpRequest;


#if js

import js.Browser;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.DivElement;
import js.html.Document;
import js.html.DOMWindow;
import js.html.Element;
import js.html.Event;
import js.html.HtmlElement;
import js.html.ImageElement;
import js.html.SpanElement;
import js.html.Worker;
import js.Lib;

#end

enum EngineState
{
	Load;
	Run;
	Dispose;
}



/**
 * Class that describes the main engine.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Engine
{
	static public var VERSION_MAJOR : Int = 0;
	
	static public var VERSION_MINOR : Int = 5;
	
	static public var VERSION_BUILD : Int = 5;
		
	static public var version : String = VERSION_MAJOR + "." + VERSION_MINOR + "." + VERSION_BUILD;
	
	/**
	 * Hack to force init from class passed in HTML
	 */
	static function __init__():Void	
	{ 
		//var iid : Dynamic =	untyped __js__("setInterval(function(){ clearInterval(iid); haxor.core.Engine.Run();  },0)"); 
		
		//Browser.document.onload = function(e:Event) { Run(); };
		//Browser.window.alert("__init__");
		untyped __js__("setTimeout(function(){ haxor.core.Engine.Run();  },1)"); 
	}
	
	/**
	 * 
	 */
	static public var application(get_application, never) : Application;	
	static var m_application : Application;
	static function get_application():Application  { return m_application; }
	
	static var m_state : EngineState;
	
	static var m_onrender : Float -> Bool;
	
	static public var pause : Bool = false;
	
	/**
	 * 
	 */
	static public var canvas(get_canvas, never):HaxorCanvas;
	static private function get_canvas():HaxorCanvas { return m_canvas; }
	static private var m_canvas : HaxorCanvas;
	
	static var m_mode : String;
	
	static var m_ui : Bool;
	
	static var m_onrenderTime : Float;
	
	static var m_garbageCollectRate : Int = 10;
	
	static var m_garbageList : Array<Resource>;
	
	static var m_entityList : Array<Entity>;
	
	static var m_startList : Array<Behaviour>;
	
	static var m_awakeList : Array<Behaviour>;
	
	static public var m_updateList : Array<IUpdateable>;
	
	static var m_lateUpdateList : Array<ILateUpdateable>;
	
	static var m_fixedUpdateList : Array<IFixedUpdateable>;
	
	static var m_onrenderList : Array<IRenderable>;
	
	static var m_onrenderQueueMap : Map<IQueueRenderable,Int>;
	
	static var m_onrenderQueueList : Array<IQueueRenderable>;
	
	static var m_lastResizeWidth:Int;
	
	static var m_lastResizeHeight:Int;
	
	static var m_resizeList : Array<IResizeable>;
	
	static public function AddDisposable(p_object : Resource):Void
	{		
		if (p_object.destroyed) return;
		p_object.m_destroyed = true;		
		if (Std.is(p_object, Behaviour)) DisableBehaviour(cast p_object);		
		m_garbageList.push(p_object);
	}
	
	static public function AddAwakeBehaviour(p_behaviour : Behaviour):Void
	{		
		m_awakeList.push(p_behaviour);
	}
	
	static public function AddStartBehaviour(p_behaviour : Behaviour):Void
	{	
		m_startList.push(p_behaviour);
	}
	
	static var rqid : Int = 0;
	static var rqdbg : String = "";
	
	static public function Add(p_node : Dynamic):Void
	{
		var c : Array<Dynamic> = [IUpdateable, ILateUpdateable, IFixedUpdateable, IRenderable, IResizeable,IQueueRenderable,IGizmoRenderer];
		var l : Array<Dynamic> = [m_updateList, m_lateUpdateList, m_fixedUpdateList, m_onrenderList,m_resizeList,m_onrenderQueueList,Gizmo.m_handlers];		
		for (i in 0...c.length)
		{
			if (Std.is(p_node, c[i]))
			{
				var found : Bool = false;
				for (k in 0...l[i].length) if (l[i][k] == p_node) found = true;
				if (found) continue;
				l[i].push(p_node);
				if (l[i] == m_onrenderQueueList)
				{
					//rqdbg += rqid + " " + p_node.m_entity.m_name+"\n";
					//rqid++;					
					//if (rqid > 2200) { Console.Breakpoint(); }
					
					m_onrenderQueueMap.set(cast p_node, -1);
					SortRenderQueue();
				}
			}			
			
		}
	}
	
	static public function Remove(p_node : Dynamic):Void
	{
		var b : Dynamic = p_node;	
		if (Std.is(b, IUpdateable)) 		m_updateList.remove(cast b);
		if (Std.is(b, ILateUpdateable)) 	m_lateUpdateList.remove(cast b);
		if (Std.is(b, IFixedUpdateable)) 	m_fixedUpdateList.remove(cast b);
		if (Std.is(b, IRenderable)) 		m_onrenderList.remove(cast b);		
		if (Std.is(b, IResizeable)) 		m_resizeList.remove(cast b);		
		if (Std.is(b, IQueueRenderable))	m_onrenderQueueList.remove(cast b);
		if (Std.is(b, IGizmoRenderer))		Gizmo.m_handlers.remove(cast b);
	}
	
	static public function EnableBehaviour(p_behaviour : Behaviour):Void
	{
		var b : Behaviour = p_behaviour;
		if (b.destroyed) return;
		Add(p_behaviour);
	}
	
	static public function DisableBehaviour(p_behaviour : Behaviour):Void
	{
		if (p_behaviour == null)
		{			
			return;
		}		
		var b : Behaviour = p_behaviour;		
		Remove(b);
	}
	
	static function StartBehaviour():Void
	{
		//var it : Iterator<Behaviour> = m_startList.iterator();		
		//while (it.hasNext())
		//{
			//m_startList.clear();
			//while (it.hasNext())
			var l : Array<Behaviour> = m_startList;
			m_startList = [];
			for(i in 0...l.length)
			{
				var b : Behaviour = l[i];
				if (b.destroyed) continue;
				//if (b.GetTypeName().indexOf("DungeonDoor")>=0) trace(b.name + " AHHHHH");
				//trace(b.GetTypeName() + " start");
				b.OnStart();
				
				if(!b.destroyed)if (Std.is(b, IResizeable)) { var r:IResizeable = cast b;  r.OnResize(Screen.width, Screen.height); }
			}
			//it = m_startList.iterator();			
		//}
		//m_startList = [];
	}
	
	static function AwakeBehaviour():Void
	{
		//var it : Iterator<Behaviour> = m_awakeList.iterator();
		//while (it.hasNext())
		//{
			//m_awakeList.clear();
			//while (it.hasNext())
			var l : Array<Behaviour> = m_awakeList;
			m_awakeList = [];
			for(i in 0...l.length)
			{
				var b : Behaviour = l[i];// it.next();			
				
				if (b.destroyed) continue;
				//trace(b.GetTypeName() + " awake");
				b.OnAwake();
			}
			//it = m_awakeList.iterator();	
		//}
		
	}

	
	static function CallUpdate():Void 
	{
		//var it : Iterator<IUpdateable> = m_updateList.iterator();
		//while(it.hasNext()) it.next().OnUpdate();
		for (i in 0...m_updateList.length) if(m_updateList[i]!=null)m_updateList[i].OnUpdate();
	}
	
	static function CallLateUpdate():Void 
	{
		//var it : Iterator<ILateUpdateable> = m_lateUpdateList.iterator();
		//while (it.hasNext()) it.next().OnLateUpdate();
		for (i in 0...m_lateUpdateList.length) if(m_lateUpdateList[i]!=null)m_lateUpdateList[i].OnLateUpdate();
	}
	
	static public var fixedUpdateMs : Float;
	
	static function CallFixedUpdate():Void 
	{
		//var it : Iterator<IFixedUpdateable> = m_fixedUpdateList.iterator();
		//while (it.hasNext())
		//{
			//var n : IFixedUpdateable = it.next();			
			fixedUpdateMs = Time.ms;
			var k :Int = 0;
			var fdt : Float = Time.m_fixedDeltaTime;
			var dt : Float = fdt;
			
			while(Time.m_simulationTimeSlice >= Time.fixedDeltaTime)
			{					
				for (i in 0...m_fixedUpdateList.length)
				{				
					if (m_fixedUpdateList[i] != null)
					{
						m_fixedUpdateList[i].OnFixedUpdate();
					}					
				}				
				Physics.Update();
				Time.m_simulationTimeSlice -= dt;
			}
			Physics.UpdateCollisionState();
			Time.fixedDeltaTime = fdt;
			fixedUpdateMs = Time.ms - fixedUpdateMs;
		//}
	}
	
	static function Render():Void 
	{
		//var r : Iterator<IRenderable> = m_onrenderList.iterator();
		//while (r.hasNext()) { r.next().OnRender(); }
		for (i in 0...m_onrenderList.length) if(m_onrenderList[i]!=null)m_onrenderList[i].OnRender();
	}
	
	static public var renderMs : Int;
	
	static function Render3D():Void 
	{
		
		var cl : Array<Camera> = Camera.list;
		var rql : Array<IQueueRenderable>;
		var sort_queue : Bool = false;
		
		renderMs = cast Time.ms;
		
		Stats.renderCount    = 0;
		Stats.visibleCount   = 0;
		Stats.invisibleCount = 0;
		//Stats.cullTests      = 0;
		
		for (i in 0...cl.length)
		{
			var c : Camera = cl[i];
			if (!c.enabled) continue;
			Camera.current = c;
			
			TextureAPI.BindRT(c.m_grab);
			/*
			if (c.filters.length > 0)
			{				
				TextureAPI.BindRT(c.m_srcRT);
			}
			else
			{
				TextureAPI.BindRT(c.target);
			}
			//*/
			
			Graphics.Clear(c);
			
			rql = m_onrenderQueueList;
			
			
			
			var k : Int = 5;
			var cc : Int = 250;
			for(j in 0...rql.length)
			{
				var it : IQueueRenderable = rql[j];						
				if (it == null) continue;
				
				while (k > 0)
				{
					if (m_nextCompare < (rql.length - 1)) 
					if (NeedQueueSort(rql[m_nextCompare], rql[m_nextCompare + 1])) sort_queue = true;
					k--;
					m_nextCompare = (m_nextCompare + 1) % m_onrenderQueueList.length;
				}
				
				if (Std.is(it, Renderer)) 
				{ 
					var rn : Renderer = cast it; 													
					if ((rn.layer &  c.mask) != 0)
					{
						if (Std.is(it, MeshRenderer))
						{
							var mr : MeshRenderer = cast it;
							
							if (mr.visible) Stats.visibleCount++; else Stats.invisibleCount++;
							
							if (mr.visible)
							{								
								if(mr.material != null)
								if (mr.material.grab)
								{
									var rt : RenderTexture = c.m_grab;
									
									if (mr.material.screen == null)
									{										
										mr.material.screen = new RenderTexture(rt.width, rt.height, TextureFormat.RGBA8);										
									}
									else
									{
										if (rt.width != mr.material.screen.width)   { Resource.Destroy(mr.material.screen); mr.material.screen = null; } else
										if (rt.height != mr.material.screen.height) { Resource.Destroy(mr.material.screen); mr.material.screen = null; }
										if (mr.material.screen == null)
										{										
											mr.material.screen = new RenderTexture(rt.width, rt.height, TextureFormat.RGBA8);										
										}
									}
									Graphics.Blit(rt, mr.material.screen);
									TextureAPI.BindRT(rt);
								}
								
								Stats.renderCount++;
								it.OnRender();
							}
						}
						else
						{
							Stats.renderCount++;
							it.OnRender();
						}
					}
				}
				else it.OnRender();
			}						
			
			
			
			if (c.filters.length > 0)
			{					
				
				var depth_texture : Texture2D = 
				//c.m_srcRT.depth;
				c.m_grab.depth;				
				Graphics.Blit(c.m_grab, c.m_srcRT);
				
				var lastRT : RenderTexture = c.m_srcRT;
				var srcRT  : RenderTexture = c.m_srcRT;
				var dstRT  : RenderTexture = c.m_dstRT;
				
				for (k in 0...c.filters.length)
				{					
					if (c.filters[k].enabled) 
					{
						c.filters[k].depth = depth_texture;
						c.filters[k].OnRender(c.m_srcRT, c.m_dstRT);
						c.filters[k].depth = null;
					}
					else 
					{
						Graphics.Blit(c.m_srcRT, c.m_dstRT);
					}
					lastRT 	  = c.m_dstRT;
					c.m_dstRT = c.m_srcRT;
					c.m_srcRT = lastRT;
				}
				
				Graphics.Blit(lastRT, c.m_target);
				c.m_srcRT = srcRT;
				c.m_dstRT = dstRT;				
			}
			else
			{
				Graphics.Blit(c.m_grab, c.m_target);
				//Graphics.Blit(c.m_srcRT, c.m_target);
			}
			
			c.SwapBuffer();
			
			TextureAPI.BindRT(null);
			Gizmo.Render();
			
		}
		Render();
		
		if (sort_queue) { SortRenderQueue(); }
		renderMs = cast Time.ms - renderMs;
	}
	
	static private var m_nextCompare:Int = 0;
	
	static private function NeedQueueSort(a:IQueueRenderable, b:IQueueRenderable):Bool
	{
		var ia : Int = a.GetQueue();
		var ib : Int = b.GetQueue();
		if (ia > ib)
		{
			return true;
		}
		
		if (!Std.is(a, MeshRenderer)) return false;
		if (!Std.is(b, MeshRenderer)) return false;
		
		var mra : MeshRenderer = cast a;
		var mrb : MeshRenderer = cast b;
		
		if (mra.mesh == null) if (mrb.mesh == null) return  false;
		if (mra.mesh == null) { return true; }
		if (mrb.mesh == null) { return true; }
		
		ia = mra.mesh.id;
		ib = mrb.mesh.id;
				
		if (ia > ib) { return true; }
		
		if (mra.material == null) if (mrb.material == null) return false;
		if (mra.material == null) { return  true; }
		if (mrb.material == null) { return true; }
		
		if (mra.material.shader == null) if (mrb.material.shader == null) return false;
		if (mra.material.shader == null) { return true; }
		if (mrb.material.shader == null) { return true; }
		
		ia = mra.material.shader.id;
		ib = mrb.material.shader.id;
		
		if (ia > ib) { return true; }
		
		return false;		
	}
	
	static private function CompareQueueRenderer(a:IQueueRenderable, b:IQueueRenderable):Int
	{
		var ia : Int = a.GetQueue();
		var ib : Int = b.GetQueue();
		
		if (ia != ib) return ia < ib ? -1 : 1;
		
		if (!Std.is(a,MeshRenderer)) if (!Std.is(b,MeshRenderer)) return 0;
		if (!Std.is(a,MeshRenderer)) return  1;
		if (!Std.is(b,MeshRenderer)) return -1;
		
		var mra : MeshRenderer = cast a;
		var mrb : MeshRenderer = cast b;
		
		if (mra.material == null) if (mrb.material == null) return 0;
		if (mra.material == null) return  1;
		if (mrb.material == null) return -1;
		
		ia = mra.material.id;
		ib = mrb.material.id;
		
		if (ia != ib) return ia < ib ? -1 : 1;
		
		if (mra.mesh == null) if (mrb.mesh == null) return 0;
		if (mra.mesh == null) return  1;
		if (mrb.mesh == null) return -1;
		
		ia = mra.mesh.id;
		ib = mrb.mesh.id;
		
		if (ia != ib) return ia < ib ? -1 : 1;
		
		ia = mra.transform.id;
		ib = mrb.transform.id;
		
		if (ia != ib) return ia < ib ? -1 : 1;
		
		return 0;
	}
	
	static private function SortRenderQueue():Void
	{		
		m_onrenderQueueList.sort(function(a:IQueueRenderable, b:IQueueRenderable):Int
		{	
			return CompareQueueRenderer(a,b);
		});		
	}
	
	static function CollectDisposable():Void
	{
		var count:Int = cast Math.min(m_garbageCollectRate, m_garbageList.length);
		for (i in 0...count)
		{
			var d : IDisposable = m_garbageList.pop();
			if(Std.is(d,Resource))
			d.OnDestroy();
		}
	}
	
	/**
	 * 
	 * @param	p_application
	 */
	static public function Run():Void
	{	
		
		trace("Haxor Engine v" + version);
		trace("Haxor> Workers [" + Thread.available + "]");
		trace("Haxor> OS      [" + Browser.navigator.platform + "]");
		trace("Haxor> UA      [" + Browser.navigator.userAgent + "]");		
		trace("Haxor> Vendor  [" + Application.vendor + "]");
		var script_element : Element  = null;
		var application_class_name : String = "";		
		
		if ((Application.protocol == ApplicationProtocol.File) || (Browser.window.location.href.toLowerCase().indexOf("localhost") >= 0)) 
		{	
			//trace("Haxor> Local Build [true]");
			untyped __js__("(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)  })(window,document,'script','http://www.google-analytics.com/analytics.js','ga');  ga('create', 'UA-50135074-1', 'auto');  ga('send', 'pageview');");
		}
		
		
		Animation.Initialize();
		
		//Searches for 'application' attribute in Haxor <script> tag.
		Application.TraverseDOM(function(n : Node) : Bool
		{
			
			
			if(n.nodeName.toLowerCase() == "script")
			//if (Std.is(n, ScriptElement))
			{
				var e : Element = cast n;
				if (e.hasAttribute("application")) 
				{ 
					application_class_name = e.getAttribute("application"); 
					script_element = cast e; 
					return false; 
				}
				else
				if (e.hasAttribute("data-application"))  //IE10
				{
					application_class_name = e.getAttribute("data-application"); 
					script_element = e; 
					return false; 
				}
			}
			return true;
		});
		
		if (application_class_name == "") { throw("Haxor> Application class NOT found!"); return; }
		
		var application_class :Class<Dynamic> = Type.resolveClass(application_class_name);		
		
		trace("Haxor> Application [" + application_class_name + "]");
		
		if (application_class == null) { throw("Haxor> Application class is NULL."); }
		else
		{
			
			
			m_application = Type.createInstance(application_class,[]);
			if (!Std.is(m_application,Application)) { throw("Haxor> Application class does not extends 'Application' base class!"); }
			else
			{	
				var mode : String = script_element.getAttribute("mode") == null ? "ui" : script_element.getAttribute("mode");
				var ui   : String = script_element.getAttribute("ui")   == null ? "false" : script_element.getAttribute("ui");
				trace("Haxor> Initialize mode[" + mode + "] ui["+ui+"]");
				Initialize(mode,ui=="true");
			}					
		}
	}	
	
	static private function Initialize(p_mode : String,p_ui:Bool):Void 
	{	
		Time.Initialize();		
		
		m_mode = p_mode;
		m_ui   = p_ui;
		
		m_onrenderTime = 0;	
		m_lastResizeWidth  = 0;
		m_lastResizeHeight = 0;
		
		
		m_garbageList 		= [];// new Array<Resource>();	                        
		m_entityList 		= [];// new Array<Entity>();		                    
		m_startList 		= [];// new Array<Behaviour>();		                    
		m_awakeList 		= [];// new Array<Behaviour>();		                    
		m_updateList 		= [];// new Array<IUpdateable>();		                    
		m_lateUpdateList 	= [];// new Array<ILateUpdateable>();		                    
		m_fixedUpdateList 	= [];// new Array<IFixedUpdateable>();		                    
		m_onrenderList = [];// new Array<IRenderable>();
		m_resizeList 		 = [];// new Array<IResizeable>();
		m_onrenderQueueList   = [];// new Array<IQueueRenderable>();
		m_onrenderQueueMap    = new Map<IQueueRenderable,Int>();
		
		if (p_ui)
		{
			m_application.m_stage = new Stage();
		}
		
		var target_element : Element = null;
		
		SoundAPI.Initialize();
		
		switch(p_mode)
		{	
			case "3d": 
			Application.TraverseDOM(function(it : Node):Bool
			{
				if (Std.is(it, Element))
				{
					var e : Element = cast it;
					if (e.id == "haxor") if (Std.is(e, CanvasElement)) { target_element = cast e; return false; }
				}
				return true;
			});
			
			if (target_element == null) trace("Haxor> Canvas 3d not found. Creating default.");
			m_canvas 		= new HaxorCanvas(cast target_element);
			target_element 	= m_canvas.element;
			m_onrender 		= RenderCallback3D;
			Graphics.Initialize(cast m_canvas.element);
			Gizmo.Initialize();
			
			case "2d":			
		
			case "ui":
				
				m_onrender 		= RenderCallbackUI;
		}		
		
		var input_element  : Element = p_ui ? application.stage.element : m_canvas.element;
		var screen_element : Element = p_ui ? application.stage.element : m_canvas.element;
		
		Collider.Initialize();		
		Physics.Initialize();
		Transform.Initialize();		
		RigidBody.Initialize();
		Input.Initialize(input_element);
		Screen.m_target = screen_element;
		
		Browser.window.setInterval(Update, 0);	
		
		m_state = EngineState.Load;
		
		Asset.BeginDependences();	
		
		if (p_mode == "3d")
		{
			Web.root = 
			"http://haxor.thelaborat.org/resources/";		
			//"https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";		
			Asset.LoadShader("haxor/internal/Skybox", 									"./shader/internal/Skybox.shader");
			Asset.LoadShader("haxor/internal/Error",  									"./shader/internal/Error.shader");
			Asset.LoadShader("haxor/internal/Gizmo", 									"./shader/internal/Gizmo.shader");
			Asset.LoadShader("haxor/internal/GUI", 										"./shader/internal/GUI.shader");
			Asset.LoadShader("haxor/kernel/ParticleKernel", 							"./shader/kernel/ParticleKernel.shader");
			Web.root = "./";		
		}
		
		application.Load();
		
		
	}
	
	static public var updateMs : Float;
	
	static public var transformMs : Float;
	
	static public var inputMs : Float;
	
	static function Update():Void
	{
		
		switch(m_state)
		{
			case EngineState.Load:
			{
				
				var p :Float = Asset.m_dependenceProgress;
				Time.Update();
				Input.Update();	
				CallUpdate();				
				ResizeCallback();
				if (p >= 1)
				{					
					var is_load_complete : Bool = application.loader == null ? true : application.loader.m_finished;
					
					if (application.loader != null)
					{
						if (!application.loader.m_complete)
						{
							application.loader.m_complete = true;
							application.loader.OnProgress(1);
							application.OnProgress(1.0);
							application.loader.OnComplete();
						}
					}				
					
					if (is_load_complete)
					{						
						Asset.EndDependences();
						Asset.Create();
						m_state = EngineState.Run;		
						Time.m_simulationTimeSlice = 0.0;
						application.Initialize();
						return;
					}	
					
				}
			}
			
			case EngineState.Run:				
			{		
				
				Time.Update();
				
				inputMs = Time.ms;
				
				Input.Update();	
				
				if (Input.IsDown(KeyCode.ControlKey))
				if (Input.IsDown(KeyCode.Alt))
				if (Input.Hit(KeyCode.P))
				{
					pause = !pause;
				}
				
				if (pause) return;
				
				inputMs = Time.ms - inputMs;
				
				var t : Float = Time.ms;
				
				if (m_awakeList.length > 0) AwakeBehaviour();		
				if (m_startList.length > 0) StartBehaviour();		
							
				
				CallUpdate();		
				CallLateUpdate();	
				
				updateMs = Time.ms - t;
				
				transformMs = Time.ms;
				
				Transform.Update(false);
				Transform.Update(true);
				
				transformMs = Time.ms - transformMs;
				
				Animation.Update();
				
				CallFixedUpdate();
				
				
				if (Graphics.c3d != null)
				{
					if (Camera.m_list != null)
					{
						Stats.cullTests = 0;
						
						var rql : Array<IQueueRenderable> = m_onrenderQueueList;
						var fcc : Int = 20;// cast rql.length / 15;
						for(cc in 0...fcc)
						{
							if (Camera.m_list.length > 0)
							{					
								Camera.current = Camera.m_list[0];
								var fcid : Int = MeshRenderer.m_next_cull_test;
								var fcr : IQueueRenderable = cast rql[fcid];
								if (Std.is(fcr, MeshRenderer)) { var fcmr : MeshRenderer = cast fcr; fcmr.CheckCulling(); Stats.cullTests++; } 
								MeshRenderer.m_next_cull_test = (MeshRenderer.m_next_cull_test + 1) % rql.length;
							}
							//cc--;
						}
					}
				}
				
				
				m_onrenderTime += Time.frameDeltaTime;
				var spf : Float = 1.0 / application.fps;
				if (m_onrenderTime >= spf) 
				{		
					Time.frame++;
					m_onrenderTime -= spf;
					Browser.window.requestAnimationFrame(m_onrender);
				}
				
				if (m_garbageList.length > 0) CollectDisposable();		
								
			}
			
			case EngineState.Dispose:
				
		}
	}
	
	static function ResizeCallback():Void 
	{	
		if(m_ui)
		{
			Screen.m_width  = cast application.stage.width;
			Screen.m_height = cast application.stage.height;
		}
		else
		if (m_canvas != null)
		{
			Screen.m_width  = m_canvas.element.width;
			Screen.m_height = m_canvas.element.height;
		}
		
		var sw : Int = cast Screen.width;
		var sh : Int = cast Screen.height;
		
		if (m_lastResizeWidth != sw) 
		{				
			var it : Iterator<IResizeable> = m_resizeList.iterator(); 
			while (it.hasNext()) it.next().OnResize(Screen.m_width, Screen.m_height);			
			m_lastResizeWidth = sw;			
		}
		else
		if (m_lastResizeHeight != sh) 
		{				
			var it : Iterator<IResizeable> = m_resizeList.iterator(); 
			while (it.hasNext()) it.next().OnResize(Screen.m_width, Screen.m_height);
			m_lastResizeHeight = sh;
		}
	}
	
	static function RenderCallback3D(p_time:Float):Bool
	{	
		ResizeCallback();		
		Render3D();
		Graphics.Flush();		
		return true;
	}
	
	static function RenderCallbackUI(p_time:Float):Bool
	{			
		
		ResizeCallback();
		Render();			
		return true;
	}
	
}