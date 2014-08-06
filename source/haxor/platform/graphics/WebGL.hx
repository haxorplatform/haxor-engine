#if html
package haxor.platform.graphics;
import haxor.platform.Types.MeshBufferId;
import js.html.Event;
import haxe.ds.EnumValueMap;
import haxor.platform.html.HTMLApplication;
import haxor.graphics.Screen;
import haxor.core.Console;
import haxor.platform.graphics.GraphicContext;

import haxor.core.BaseApplication;
import js.html.Element;
import js.Browser;
import js.html.DivElement;
import js.html.webgl.GL;
import js.html.CanvasElement;
import haxe.format.JsonParser;
import js.html.webgl.RenderingContext;

/**
 * Wrapper for all WebGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class WebGL extends GraphicContext
{	
	private var c : RenderingContext;
	
	private var m_canvas : CanvasElement;
	
	private var m_container : Element;
		
	/**
	 * Creates a new WebGL context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		api = GraphicAPI.WebGL;
	}
	
	/**
	 * Creates the 3D rendering context by adding a [canvas] element in the choosen DOM Element container.
	 * @param	p_container_id
	 * @return
	 */
	public function Initialize(p_container_id : String):Bool
	{
		
		var app : HTMLApplication = cast m_application;
		app.m_container = m_container = Browser.document.getElementById(p_container_id);
		
		if (m_container == null)
		{ 
			Console.Log("Graphics> Canvas container not defined id["+p_container_id+"].");
			return false; 
		}
		
		m_canvas = Browser.document.createCanvasElement();
		/*
		m_canvas.style.position = "absolute";
		m_canvas.style.left   	= "0px";
		m_canvas.style.top  	= "0px";
		m_canvas.style.width  	= "100%";
		m_canvas.style.height 	= "100%";
		//*/
		m_canvas.width 			= m_container.clientWidth;		
		m_canvas.height 		= m_container.clientHeight;
		m_container.appendChild(m_canvas);
		
		var ctx_attrib 			: Dynamic 		 = { };		
		var ctx_attrib_list 	: Array<String>  = ["alpha", "antialias", "depth", "stencil", "premultipliedAlpha", "preserveDrawingBuffer"];
		var ctx_attrib_default  : Array<Bool> 	 = [false, false, true, false, true, false];
		
		Console.Log("Graphics> Initialize WebGL",1);
		
		for (i in 0...ctx_attrib_list.length)
		{
			var a : String 		= ctx_attrib_list[i];
			var ca : Dynamic 	= m_container.getAttribute(ctx_attrib_list[i]);			
			var flag : Bool 	= ca == null ? ctx_attrib_default[i] : (ca == "true");
			Console.Log("\t" + ctx_attrib_list[i] + ": " + flag,1);			
			untyped __js__("ctx_attrib[a]=flag");
		}
		
		c = m_canvas.getContextWebGL(ctx_attrib);
		
		if (c == null) 
		{ 
			Console.Log("Graphics> Could not create RenderingContext3D."); 
			return false;
		}
				
		return true;
	}
	
	/**
	 * See GraphicsContext.
	 */
	override public function CheckExtensions():Void 
	{
		if (c == null) return;
		
		Console.Log("Graphics> Available Extensions.",1);
		var extensions : Array<String> = c.getSupportedExtensions();
		for (i in 0...extensions.length)
		{
			if (extensions[i].indexOf("MOZ_") >= 0) continue;
			var ext : Dynamic = c.getExtension(extensions[i]);
			Console.Log("\t" + extensions[i],1);			
			switch(extensions[i])
			{
				case "OES_texture_half_float":
					//TextureAPI.HALF_FLOAT_OES = 0x8D61;
					
				case "OES_texture_half_float_linear":
					//TextureAPI.HALF_FLOAT_LINEAR = true;
				
				case "EXT_texture_filter_anisotropic", "WEBKIT_EXT_texture_filter_anisotropic":
					//TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT = ext.TEXTURE_MAX_ANISOTROPY_EXT;
					//trace("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + g3.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT));
				
				case "OES_texture_float":
					//TextureAPI.TEXTURE_FLOAT = true;	
				
				case "WEBGL_depth_texture":
					//TextureAPI.TEXTURE_DEPTH = true;
			}					
		}
		
	}
	
	/**
	 * See GraphicsContext.
	 */
	override public function Resize():Void 
	{
		m_canvas.width 			= m_container.clientWidth;		
		m_canvas.height 		= m_container.clientHeight;
	}
	
	/**
	 * See GraphicsContext.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 * @param	p_depth
	 */
	override public function Clear(p_r:Float, p_g:Float, p_b:Float, p_a:Float = 1.0, p_depth:Float = 1.0):Void 
	{
		c.clearDepth(p_depth);
		c.clearColor(p_r, p_g, p_b, p_a);
		c.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
	}
	
	/**
	 * See GraphicsContext.
	 * @return
	 */
	override public function CreateBuffer():MeshBufferId 
	{
		return c.createBuffer();
	}
	
	/**
	 * See GraphicsContext.
	 * @param	p_id
	 */
	override public function DeleteBuffer(p_id:MeshBufferId):Void 
	{
		c.deleteBuffer(p_id);
	}
	
}
#end