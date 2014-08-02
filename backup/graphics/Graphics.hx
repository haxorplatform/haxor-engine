/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics;

import haxe.ds.IntMap.IntMap;
import haxe.ds.StringMap.StringMap;
import js.html.Element;
import js.html.Image;
import js.html.ImageData;
import js.html.Uint8Array;
import js.html.webgl.Framebuffer;
import js.html.webgl.UniformLocation;
import js.JQuery;
import haxor.api.BufferAPI;
import haxor.api.MaterialAPI;
import haxor.api.ShaderAPI;
import haxor.api.TextureAPI;
import haxor.component.Camera;
import haxor.component.Transform;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Time;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.math.Matrix4;
import haxor.graphics.Mesh;
import haxor.graphics.MeshTemplate;
import haxor.texture.RenderTexture;
import haxor.texture.TextureCube;
import haxor.texture.Texture;
import haxor.texture.Texture2D;
import haxor.texture.TextureHTML;


import haxe.Http;
import haxe.Timer;

#if js


import js.html.ArrayBuffer;
import js.html.ArrayBufferView;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext;
import js.html.CanvasRenderingContext2D;
import js.html.Float32Array;
import js.html.Int32Array;
import js.html.Uint16Array;
import js.html.webgl.Buffer;
import js.html.webgl.ContextAttributes;
import js.html.webgl.GL;
import js.html.webgl.Program;
import js.html.webgl.RenderingContext;
import js.Lib;

#end


/**
 * Graphic library wrapper.
 * @author Eduardo Pons
 */
class Graphics
{
	
	
	static var g3 : RenderingContext;
	
	static var g2 :CanvasRenderingContext2D;
	
	static var c : CanvasElement;
	
	static var m_vpx : Int;
	static var m_vpy : Int;
	static var m_vpw : Int;
	static var m_vph : Int;
	
	/**
	 * 
	 */
	static public var c2d(get_c2d, never) : CanvasRenderingContext2D;
	static function get_c2d():CanvasRenderingContext2D { return g2; }
	
	/**
	 * 
	 */
	static public var c3d(get_c3d, never) : RenderingContext;
	static function get_c3d():RenderingContext { return g3; }

	/**
	 * Initialize the graphics library passing the target canvas to be rendered.
	 * @param	p_canvas Reference to the canvas.
	 * @return Flag that indicates that the desired context was loaded.
	 */
	static public function Initialize(p_canvas:CanvasElement):Bool
	{	
		var success : Bool = true;
		var mode : String = p_canvas.getAttribute("mode") == null ? "" : p_canvas.getAttribute("mode").toLowerCase();
		var attrib3 : Dynamic = { };
		trace("Haxor> Canvas ["+p_canvas.id+"] Config");
		var attrib3_list = ["alpha", "antialias", "depth", "stencil", "premultipliedAlpha", "preserveDrawingBuffer"];
		var attrib3_default = [false, true, true, false, true, false];
		for (i in 0...attrib3_list.length)
		{
			var a : String = attrib3_list[i];
			var ca : Dynamic = p_canvas.getAttribute(attrib3_list[i]);			
			var flag : Bool = ca == null ? attrib3_default[i] : (ca == "true");
			trace("\t" + attrib3_list[i] + ": " + flag);			
			untyped __js__("attrib3[a]=flag");
		}
		
		
		
		try 
		{	
			c = p_canvas;
			c.width  = c.clientWidth;
			c.height = c.clientHeight;
			
			if (mode == "3d") g3 = c.getContextWebGL(attrib3);
			else 
			if(mode == "2d")  g2 = c.getContext2d();
        } 
		catch (e : Dynamic) 
		{        
			
		}
		
		if (mode == "3d")
		if (g3 == null) 			
		{
			success = false;
			Console.LogError("Haxor> GL class could not initialise Rendering Context 3D.");
		}
		
		if (mode == "2d")
		if (g2 == null) 
		{
			success = false;
			Console.LogError("Haxor> GL class could not initialise Rendering Context 2D.");
		}
		
		if (success)
		{						
			trace("Haxor> Graphics wrapper initialized in mode [" + mode + "]");
			if (mode == "3d")
			{
				TextureAPI.Initialize(g3);
				ShaderAPI.Initialize(g3);
				BufferAPI.Initialize(g3);	
				MaterialAPI.Initialize(g3);
								
				trace("Haxor> WebGL extensions:");
				var extensions : Array<String> = g3 == null ? [] : g3.getSupportedExtensions();
				for (i in 0...extensions.length)
				{
					if (extensions[i].indexOf("MOZ_") >= 0) continue;
					var ext : Dynamic = g3.getExtension(extensions[i]);
					trace("\t" + extensions[i]);
					
					switch(extensions[i])
					{
						case "OES_texture_half_float":
							TextureAPI.HALF_FLOAT_OES = 0x8D61;
							
						case "OES_texture_half_float_linear":
							TextureAPI.HALF_FLOAT_LINEAR = true;
						
						case "EXT_texture_filter_anisotropic", "WEBKIT_EXT_texture_filter_anisotropic":
							TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT = ext.TEXTURE_MAX_ANISOTROPY_EXT;
							trace("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + g3.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT));
						
						case "OES_texture_float":
							TextureAPI.TEXTURE_FLOAT = true;	
						
						case "WEBGL_depth_texture":
							TextureAPI.TEXTURE_DEPTH = true;	
					}					
				}
			}
		}		
		return success;
	}
	
	static public function ClearBuffer(p_r:Float, p_g:Float, p_b:Float, p_a:Float, p_depth:Float = 1):Void
	{
		g3.clearDepth(p_depth);
		g3.clearColor(p_r, p_g, p_b, p_a);
		g3.clear(GL.COLOR_BUFFER_BIT | GL.DEPTH_BUFFER_BIT);
	}
	
	static public function Viewport(p_x : Int, p_y : Int, p_width:Int, p_height:Int):Void
	{
		var vpx:Int = cast p_x;
		var vpy:Int = cast p_y;
		var vpw:Int = cast p_width;
		var vph:Int = cast p_height;
		
		if (vpx != m_vpx) g3.viewport(m_vpx = vpx, m_vpy = vpy, m_vpw = vpw, m_vph = vph); else
		if (vpy != m_vpy) g3.viewport(m_vpx = vpx, m_vpy = vpy, m_vpw = vpw, m_vph = vph); else
		if (vpw != m_vpw) g3.viewport(m_vpx = vpx, m_vpy = vpy, m_vpw = vpw, m_vph = vph); else
		if (vph != m_vph) g3.viewport(m_vpx = vpx, m_vpy = vpy, m_vpw = vpw,m_vph = vph);
	}
	
	static public function ClearDepth():Void
	{
		g3.clearDepth(1.0);
		g3.clear(GL.DEPTH_BUFFER_BIT);		
	}
	
	/**
	 * 
	 * @param	p_camera
	 */
	static public function Clear(p_camera : Camera):Void
	{
		var c : Camera = p_camera;
		var vp : AABB2 = p_camera.m_pixelViewport;
		
		Viewport(cast vp.x, cast vp.y, cast vp.width, cast vp.height);
		
		if (c.clear != ClearFlag.None)
		{
			var flag:Int = 0;			
            if ((c.clear & ClearFlag.Color) != 0)  flag |= GL.COLOR_BUFFER_BIT;
            if ((c.clear & ClearFlag.Skybox) != 0) flag |= GL.COLOR_BUFFER_BIT;
            if ((c.clear & ClearFlag.Depth) != 0)  flag |= GL.DEPTH_BUFFER_BIT;
            g3.clearDepth(1.0);
            g3.clearColor(c.background.r, c.background.g, c.background.b, c.background.a);
            g3.clear(flag);
			
			if ((c.clear & ClearFlag.Skybox) != 0)
			{
				if (p_camera.skybox != null)
				{					
					Material.skybox.SetUniform("SkyboxTexture", p_camera.skybox);
					Material.skybox.SetUniform("SkyboxProjectionMatrixInverse",p_camera.m_skyboxProjectionInverse);
					Render(p_camera, null, BufferAPI.skybox, Material.skybox);
				}
			}
			
		}	
		
		
	}
	
	static public function Flush():Void
	{		
		BufferAPI.m_current     = null;
		MaterialAPI.m_camera    = null;
		MaterialAPI.m_transform = null;		
		
		g3.flush();
	}
	
	static public function Blit(p_source : Texture, p_destination : RenderTexture, p_material : Material=null):Void
	{		
		TextureAPI.BindRT(p_destination);
		var m : Material 	= p_material == null ? Material.blit : p_material;
		var w : Int = p_destination == null ? Screen.width  : p_destination.width;
		var h : Int = p_destination == null ? Screen.height : p_destination.height;
				
		Viewport(0, 0, w, h);
		m.SetUniform("Texture", p_source);
		Render(null, null, BufferAPI.screen, m);
		if (Material.blit == MaterialAPI.m_current) MaterialAPI.m_current = null;
		
	}
	
	static public function Render(p_camera : Camera,p_transform : Transform, p_mesh : Mesh, p_material : Material):Void
	{
		
		var m : Material 	= p_material == null ? Material.error : p_material;
		var s : Shader 		= m.shader.hasError ? Material.error.shader : m.shader;
		var t : Transform   = p_transform == null ? Transform.root : p_transform;
		
		
		//if(p_transform!= null) trace(t.name);
		ShaderAPI.Bind(s);	
		MaterialAPI.Bind(m);		
		MaterialAPI.SetLights(t,m,p_mesh);
		MaterialAPI.SetUniforms(p_camera, t, m);
		BufferAPI.Bind(p_mesh, s.gid);
		//if((Time.frame % 20)==0) trace("rendering: " + t.name);
		BufferAPI.Draw(p_mesh);
		//if((Time.frame % 20)==0) trace("====");
		//BufferAPI.Finish();
		
				
		if (MaterialAPI.m_current != m)
		{
			MaterialAPI.m_camera 	= null;
			MaterialAPI.m_transform = null;
			//TextureAPI.Finish();
		}
		MaterialAPI.m_current = m;
	}
	
	static public function RenderTexture(p_texture : Texture, p_x : Float=0, p_y : Float=0, p_width : Float=-1, p_height:Float=-1,p_color : Color = null):Void
	{
		if (p_texture == null) return;
		var c : Color = p_color == null ? Color.white : p_color;
		var mat : Material = Material.gui;
		if (mat.shader == null) { mat.shader = Asset.Get("haxor/internal/GUI"); return; }
		var tw : Float = p_width  < 0 ? p_texture.width : p_width;		
		var th : Float = p_height < 0 ? p_texture.height : p_height;
		mat.SetUniform("Texture", p_texture);
		mat.SetUniform("Position", 	new Vector2(p_x, p_y));
		mat.SetUniform("Size", 		new Vector2(tw, th));
		mat.SetUniform("Screen", 	new Vector2(Screen.width, Screen.height));		
		mat.SetUniform("Color", 	c);		
		Viewport(0, 0, cast Screen.width, cast Screen.height);
		Render(null, null, BufferAPI.gui, mat);
		MaterialAPI.m_current = null;
	}
	
	static public function ReadPixels(p_x:Int, p_y:Int,p_width:Int,p_height:Int,p_buffer:ArrayBufferView):Void
	{		
		g3.readPixels(p_x, p_y, p_width, p_height, GL.RGBA, GL.UNSIGNED_BYTE, p_buffer);		
	}
	
	
	
	
	
}