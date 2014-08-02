/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import haxe.Timer;
import haxor.net.Web;
import js.Browser;
import js.html.CanvasElement;
import js.html.Document;
import js.html.DOMWindow;
import js.html.Element;
import js.html.Event;
import js.html.HtmlElement;
import js.html.ImageElement;
import js.html.Node;
import js.html.NodeList;
import js.Lib;
import haxor.component.Transform;
import haxor.graphics.Graphics;
import haxor.graphics.Screen;
import haxor.input.Input;
import haxor.ui.HaxorCanvas;
import haxor.ui.LayoutFlag;
import haxor.ui.Stage;
import haxor.ui.UIEntity;
import haxor.ui.UILoader;

enum ApplicationProtocol
{
	Unknown;
	File;
	HTTP;
	HTTPS;
}

/**
 * Defines the main application for the Haxor engine. The initialize method is the program entry point.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Application extends Entity
{
	
	/**
	 * 
	 */
	static public var protocol(get_protocol, never) : ApplicationProtocol;
	static private function get_protocol():ApplicationProtocol	 
	{
		if (Browser.window.location.protocol == "file:") return ApplicationProtocol.File;
		if (Browser.window.location.protocol == "http:") return ApplicationProtocol.HTTP;
		if (Browser.window.location.protocol == "https:") return ApplicationProtocol.HTTPS;
		return ApplicationProtocol.Unknown;		
	}
	
	/**
	 * 
	 */
	static public var vendor(get_vendor, never) : String;
	static private var m_vendor : String;
	static private function get_vendor():String	 
	{		
		if (m_vendor != null) return m_vendor;
		var vdr : String = "";
		untyped __js__("if(window.msRequestAnimationFrame != null) 		vdr = \"-ms-\"");
		untyped __js__("if(window.oRequestAnimationFrame != null)  		vdr = \"-o-\"");
		untyped __js__("if(window.webkitRequestAnimationFrame != null)  vdr = \"-webkit-\"");
		untyped __js__("if(window.mozRequestAnimationFrame != null)  	vdr = \"-moz-\"");
		return m_vendor = vdr;
	}
	
	/**
	 * 
	 * @param	p_callback
	 */
	static public function TraverseDOM(p_callback : Node -> Bool):Void
	{
		TraverseDOMStep(Browser.document.body,p_callback);
	}
	
	/**
	 * 
	 * @param	p_node
	 * @param	p_callback
	 */
	static private function TraverseDOMStep(p_node : Node, p_callback : Node -> Bool):Void
	{
		if (p_node == null) return;
		var l :NodeList = p_node.childNodes;
		if (l == null) return;
		for (i in 0...l.length)
		{
			var res : Bool = true;
			if (p_callback != null) res = p_callback(l.item(i));
			if (!res) return;
			TraverseDOMStep(l.item(i), p_callback);
		}
	}
	
	/**
	 * Returns the instance of the Stage
	 */
	public var stage(get_stage, never) : Stage;	
	function get_stage():Stage  { return m_stage; }
	private var m_stage : Stage;
	
	/**
	 * 
	 */
	public var loader(get_loader, set_loader) : UILoader;	
	private function get_loader():UILoader  { return m_loader; }		
	private function set_loader(v : UILoader):UILoader  
	{
		if (m_loader != null) return m_loader;
		if (v == null) return m_loader;
		m_loader = v;
		stage.AddChildAt(v, stage.childCount);
		return m_loader;
	}
	private var m_loader : UILoader;
	
	
	/**
	 * Frames Per Second that this application will run
	 */
	public var fps : Float;
	
	/**
	 * Create a new BaseApplication. This constructor is automatically called.
	 */
	function new() 
	{
		super();		
		name 	= "application";				
		fps     = 45;
		Transform.m_root = transform;		
		Build();
	}
	
	/**
	 * Method called after application creation.
	 */
	private function Build():Void { }
	
	/**
	 * Application entry-point method. Override this to start the application after pre-loading.
	 */
	private function Initialize():Void {	}
	
	/**
	 * Application entry-point method. Override this to start the application.
	 */
	private function Load():Void {	}
	
	/**
	 * Loads standar filters shaders.
	 */
	private function LoadStandardFilters():Void
	{
		Asset.LoadShader("haxor/filter/Blur", 										"./shader/filter/Blur.shader");
		Asset.LoadShader("haxor/filter/Bloom", 										"./shader/filter/Bloom.shader");
		Asset.LoadShader("haxor/filter/FXAA", 										"./shader/filter/FXAA.shader");
		Asset.LoadShader("haxor/filter/Fog", 										"./shader/filter/Fog.shader");
	}
	
	/**
	 * Loads primitives meshes like cube and spheres.
	 */
	private function LoadPrimitives():Void
	{
		Asset.LoadCollada("haxor/primitive/cube", 									"./primitive/cube.DAE");
		Asset.LoadCollada("haxor/primitive/sphere",									"./primitive/sphere.DAE");
		Asset.LoadCollada("haxor/primitive/teapot",									"./primitive/teapot.DAE");
		Asset.LoadCollada("haxor/primitive/torus",									"./primitive/torus.DAE");
	}
	
	/**
	 * Loads the standard library of shaders, materials and texture from the haxor server
	 */
	private function LoadStandardLib()
	{
		Web.root = 
		"http://haxor.thelaborat.org/resources/";	
		//"https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";		
		
		LoadPrimitives();
		
		Asset.LoadTextureHTML("haxor/texture/logo",									"./texture/misc/haxor.png");
		
		Asset.LoadTextureHTML("haxor/skybox/dark_top",								"./texture/skybox/gradient/dark_top.jpg");
		Asset.LoadTextureHTML("haxor/skybox/dark_sides", 							"./texture/skybox/gradient/dark_sides.jpg");
		Asset.LoadTextureHTML("haxor/skybox/dark_bottom",							"./texture/skybox/gradient/dark_bottom.jpg");
		
		Asset.LoadShader("haxor/unlit/FlatTexture", 								"./shader/unlit/FlatTexture.shader");						
		Asset.LoadShader("haxor/unlit/FlatTextureSkin", 							"./shader/unlit/FlatTextureSkin.shader");				
		Asset.LoadShader("haxor/unlit/FlatSkin", 									"./shader/unlit/FlatSkin.shader");				
		Asset.LoadShader("haxor/unlit/Flat", 										"./shader/unlit/Flat.shader");
		
		Asset.LoadShader("haxor/lightmap/FlatTexture", 								"./shader/lightmap/FlatTexture.shader");						
		
		Asset.LoadShader("haxor/unlit/Particle", 									"./shader/unlit/Particle.shader");
		
		Asset.LoadShader("haxor/diffuse/DiffuseSkin", 								"./shader/diffuse/DiffuseSkin.shader");
		Asset.LoadShader("haxor/diffuse/ToonSkin", 									"./shader/diffuse/ToonSkin.shader");
		Asset.LoadShader("haxor/diffuse/ToonSkinFalloff", 							"./shader/diffuse/ToonSkinFalloff.shader");
		
		Asset.LoadShader("haxor/screen/Displacement",								"./shader/screen/Displacement.shader");
		
		Asset.LoadMaterial("haxor/material/opaque/unlit/Flat", 		  				"./material/opaque/unlit/Flat.mat");		
		Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTexture", 				"./material/opaque/unlit/FlatTexture.mat");
						   
		Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTextureSkin",			"./material/opaque/unlit/FlatTextureSkin.mat");		
		
		Asset.LoadMaterial("haxor/material/opaque/lightmap/FlatTexture", 			"./material/opaque/lightmap/FlatTexture.mat");
		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/DiffuseSkin", 		  	"./material/opaque/diffuse/DiffuseSkin.mat");		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/ToonSkin", 		  		"./material/opaque/diffuse/ToonSkin.mat");		
		
		Asset.LoadMaterial("haxor/material/transparent/unlit/Flat", 		  		"./material/transparent/unlit/Flat.mat");		
		Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTexture", 			"./material/transparent/unlit/FlatTexture.mat");						   
		Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTextureSkin", 		"./material/transparent/unlit/FlatTextureSkin.mat");
		
		Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAdditive", 	"./material/transparent/unlit/ParticleAdditive.mat");
		Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAlpha", 		"./material/transparent/unlit/ParticleAlpha.mat");
		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/Diffuse",	  				"./material/opaque/diffuse/Diffuse.mat");		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/Flat",	  				"./material/opaque/diffuse/Flat.mat");		
		
		Asset.LoadMaterial("haxor/material/screen/Displacement",	  				"./material/screen/Displacement.mat");
				
		LoadStandardFilters();
		
		Asset.LoadTextureHTML("haxor/texture/particle", 							"./texture/particle/particle.png");
		
		Web.root = "./";
	}
	
	/**
	 * 
	 * @param	p_resource
	 */
	private function OnDependenceLoad(p_id:String):Void { }
	
	/**
	 * 
	 * @param	p_progress
	 */
	private function OnDependenceProgress(p_id : String,p_progress : Float):Void { }
	
	/**
	 * 
	 * @param	p_progress
	 */
	private function OnProgress(p_progress : Float):Void { }
	
}