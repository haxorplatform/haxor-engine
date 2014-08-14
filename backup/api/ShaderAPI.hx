/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.api;
import js.html.webgl.GL;
import js.html.webgl.Program;
import js.html.webgl.RenderingContext;
import sys.db.Types.SBigInt;
import haxor.core.Console;
import haxor.graphics.Shader;

/**
 * ...
 * @author Eduardo Pons
 */
class ShaderAPI
{
	static private var c : RenderingContext;
	
	static var m_attribs : Array<String> = ["vertex", "normal", "uv0", "uv1", "color","weight","index"];	
	
	static var m_currentProgram : Program;
	
	static public var current  : Shader;
	
	static public function Initialize(p_context : RenderingContext):Void
	{
		c = p_context;
		m_currentProgram = null;
	}
	
	static public function Bind(p_shader : Shader):Void
	{	
		var p : Program = p_shader.gid;
		if (p == m_currentProgram) return;		
		m_currentProgram = p;
		current = p_shader;
		c.useProgram(p);
		//trace("\t"+p_shader.name);
	}

	static public function Create(p_shader : Shader):Void
	{
		if (c == null) return;
		var key:String;
		var src:String;
		var vs : js.html.webgl.Shader=null;
		var fs : js.html.webgl.Shader=null;
		
		src = Reflect.field(p_shader, "m_vertexShaderSource");		
		if (src != "")
		{
			vs = c.createShader(GL.VERTEX_SHADER);
			Reflect.setField(p_shader, "m_vertexShaderId", vs);
			c.shaderSource(vs, src);
			c.compileShader(vs);			
			if (!c.getShaderParameter(vs, GL.COMPILE_STATUS))
			{
				Reflect.setField(p_shader, "m_hasError", true);
				Console.LogError("Shader> Compile Error @ Vertex[" + p_shader.name + "]\n" + c.getShaderInfoLog(vs));
			}			
		}		
		
		src = Reflect.field(p_shader, "m_fragmentShaderSource");
		if (src != "")
		{
			fs = c.createShader(GL.FRAGMENT_SHADER);
			Reflect.setField(p_shader, "m_fragmentShaderId", fs);
			c.shaderSource(fs, src);
			c.compileShader(fs);
			if (!c.getShaderParameter(fs, GL.COMPILE_STATUS))
			{
				Reflect.setField(p_shader, "m_hasError", true);
				Console.LogError("Shader> Compile Error @ Fragment[" + p_shader.name + "]\n" + c.getShaderInfoLog(vs));
			}			
		}	
		
		var p : Program = c.createProgram();	
		if (p == null) { Console.LogError("Shader> Error! Could not create program @ " + p_shader.name); return; }
		if (vs != null) c.attachShader(p, vs);
		if (fs != null) c.attachShader(p, fs);		
		for (i in 0...m_attribs.length)	c.bindAttribLocation(p, i, m_attribs[i]);
		c.linkProgram(p);
				
		if (!c.getProgramParameter(p, GL.LINK_STATUS))
		{
			Reflect.setField(p_shader, "m_hasError", true);
			Console.LogError("Shader> Link Error @ [" + p_shader.name + "]\n[" + c.getProgramInfoLog(p) + "]");
			//if (c.getError()!=0) Console.LogError("GLSL> Error " + c.getError());
		}
		/*
		if (c.getProgramParameter(p, GL.VALIDATE_STATUS))
		{
			Reflect.setField(p_shader, "m_hasError", true);
			Console.LogError("Shader> Validate Error @ [" + p_shader.name + "]\n[" + c.getProgramInfoLog(p) + "]");
			//if (c.getError()!=0) Console.LogError("GLSL> Error " + c.getError());
		}
		//*/
		
		
		Reflect.setField(p_shader, "m_gid", p);
	}
	
	static public function GetAttribute(p_attribute : String,p_shader : Shader=null):Int
	{
		var shd   : Shader = p_shader == null ? current : p_shader;
		var cache : Map<String,Int> = shd.m_locations;
		if (cache.exists(p_attribute)) return cache.get(p_attribute);		
		var loc : Int = c.getAttribLocation(shd.gid, p_attribute);
		//trace(shd.name + " " + p_attribute + " " + loc);
		cache.set(p_attribute, loc);
		return loc;
	}
	
	static public function Destroy(p_shader : Shader):Void
	{		
		var vs : js.html.webgl.Shader = Reflect.getProperty(p_shader,"m_vertexShaderId");
		var fs : js.html.webgl.Shader = Reflect.getProperty(p_shader,"m_fragmentShaderId");
		if(vs != null) c.deleteShader(vs);
		if(fs != null) c.deleteShader(fs);		
		if (p_shader.gid != null)
		{
			c.deleteProgram(p_shader.gid);
			if (p_shader.gid == m_currentProgram) m_currentProgram = null;
		}
	}
	
	
}