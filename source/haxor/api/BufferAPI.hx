/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.api;
import js.html.ArrayBufferView;
import js.html.Float32Array;
import js.html.Uint16Array;
import js.html.webgl.Buffer;
import js.html.webgl.GL;
import js.html.webgl.Program;
import js.html.webgl.RenderingContext;
import haxor.core.Console;
import haxor.core.Time;
import haxor.graphics.Mesh;
import haxor.graphics.MeshTemplate.Mesh3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Vector3;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class BufferAPI
{
	/**
	 * 
	 */
	static public var skybox(get_skybox, never) : Mesh3;
	static var m_skybox : Mesh3;
	static function get_skybox():Mesh3
	{
		if (m_skybox != null) return m_skybox;
		m_skybox = new Mesh3();
		m_skybox.name = "$Skybox";
		m_skybox.vertex = 
		[
			new Vector3( -1, 1, 1),
			new Vector3( -1, -1, 1),						
			new Vector3( 1, -1, 1),			
			new Vector3(-1, 1, 1),
			new Vector3( 1,-1, 1),			
			new Vector3( 1, 1, 1)			
        ];		
		//m_skybox.topology = new Uint16Array([0, 2, 1, 0, 3, 2]);		
		return m_skybox;
	}
	
	/**
	 * 
	 */
	static public var screen(get_screen, never) : Mesh3;
	static var m_screen : Mesh3;
	static function get_screen():Mesh3
	{
		if (m_screen != null) return m_screen;
		m_screen = new Mesh3();
		m_screen.name = "$Screen";
		m_screen.vertex = 
		[
			new Vector3(-1, 1, 1),
			new Vector3(-1,-1, 1),						
			new Vector3( 1,-1, 1),			
			new Vector3(-1, 1, 1),
			new Vector3( 1,-1, 1),			
			new Vector3( 1, 1, 1)			
        ];			
		return m_screen;
	}
	
	/**
	 * 
	 */
	static public var gui(get_gui, never) : Mesh3;
	static var m_gui : Mesh3;
	static function get_gui():Mesh3
	{
		if (m_gui != null) return m_gui;
		m_gui = new Mesh3();
		m_gui.name = "$GUIMesh";
		m_gui.vertex = 
		[
			new Vector3(0.0,1.0,1),
			new Vector3(0.0,0.0,1),						
			new Vector3(1.0,0.0,1),			
			new Vector3(0.0,1.0,1),
			new Vector3(1.0,0.0,1),
			new Vector3(1.0,1.0,1)
        ];			
		return m_gui;
	}
	
	static private var c : RenderingContext;
	
	static private var m_buffers : Map<String,Buffer>;
	
	static private var m_enabledAttribs : Array<Bool>;
	
	static private var m_boundBuffers : Map<Buffer,Bool>;
	
	static private var m_current : Mesh;
	
	static private var m_active : Int;
	
	static private var m_junk : Buffer;
	
	
	static public function Initialize(p_context : RenderingContext):Void
	{		
		c = p_context;
		m_buffers = new Map<String,Buffer>();
		m_boundBuffers = new Map<Buffer,Bool>();
		m_enabledAttribs = [];
		m_active = -1;
		for (i in 0...256) m_enabledAttribs.push(false);
		
		m_junk = c.createBuffer();
		c.bindBuffer(GL.ARRAY_BUFFER, m_junk);
		var jb : Float32Array = new Float32Array(4 * 100000);
		for (i in 0...jb.length) jb[i] = 1.0;
		c.bufferData(GL.ARRAY_BUFFER, jb, GL.STATIC_DRAW);
		
		
	}
	
	static public function Create(p_mesh : Mesh, p_buffer : String):Buffer
	{
		var b:Buffer = c.createBuffer(); 
		
		m_buffers.set(p_buffer + p_mesh.id, b);
		return b;
	}
	
	static public function Apply(p_mesh : Mesh,p_buffer : String):Void
	{
		var t  : Uint16Array = p_mesh.topology;
		if (t == null) return;
		var mf : Int = ModeFlag(p_mesh.mode);
		var ist : Bool = p_buffer == "$topology";
		var b : Buffer = Get(p_mesh, p_buffer);
		if (b != null) {  c.deleteBuffer(b); b = null; } //WHY ?!?!
		if (b == null) { b = Create(p_mesh, p_buffer); }
		var d : ArrayBufferView = p_mesh.Get(p_buffer);
		
		
		//Console.Breakpoint();
		c.bindBuffer(ist ? GL.ELEMENT_ARRAY_BUFFER : GL.ARRAY_BUFFER, b);
		c.bufferData(ist ? GL.ELEMENT_ARRAY_BUFFER : GL.ARRAY_BUFFER, ist ? t : d, mf);
		
	}
		
	static public function Destroy(p_mesh : Mesh,p_buffer : String):Void
	{
		var b:Buffer = Get(p_mesh, p_buffer);
		if (b != null) c.deleteBuffer(b);
	}
	
	static private function GetAttribLocation(p : Program,a:String, m : Mesh):Int
	{
		if (m.m_locations.exists(a)) return m.m_locations.get(a);		
		var loc : Int = c.getAttribLocation(p, a);
		m.m_locations.set(a, loc);
		return loc;
	}
	
	static private function BindArrayBuffer(p_buffer:Buffer):Void
	{
		
	}
	
	
	static public function Bind(p_mesh : Mesh,p_program : Program):Void
	{
		if (m_current != p_mesh) Finish();
		
		m_current = p_mesh;
		var al :Array<String> = p_mesh.attribs;
		var b:Buffer;
		//m_enabledAttribs = [];		
		for (i in 0...al.length)
		{
			var a:String = al[i];
			var mb : Buffer = Get(p_mesh, a);			
			b = mb == null ? m_junk : mb;			
			var es : Int  = mb == null ? 4 : p_mesh.ElementSize(a);
			if (es <= 0) continue;
			var loc : Int = ShaderAPI.GetAttribute(a);
			if (loc < 0) 
			{
				continue; 
			}
			
			var type : Int = GL.FLOAT;			
			c.bindBuffer(GL.ARRAY_BUFFER, b);
			if (!m_enabledAttribs[loc]) 
			{
				c.enableVertexAttribArray(loc);
				m_enabledAttribs[loc] = true; 
				m_active = cast Math.max(m_active, loc);
			}			
			c.vertexAttribPointer(loc, es, type, false, 0, 0);			
		}	
		
		if (p_mesh.indexed)
		{
			b = Get(p_mesh, "$topology");
			if (b != null) c.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, b);
		}
	}
	
	static public function Finish() : Void
	{
		
		for (i in 0...6)
		{			
			//if (m_enabledAttribs[i])
			//{
				c.disableVertexAttribArray(i);		
				m_enabledAttribs[i] = false;
			//}
		}
		//c.bindBuffer(GL.ARRAY_BUFFER, null);
		//c.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, null);
		m_active = 0;
		//*/
	}
	
	static public function Draw(p_mesh : Mesh):Void
	{
		var pf : Int = PrimitiveFlag(p_mesh.primitive);				
		
		if (p_mesh.indexed)
		{	
			c.drawElements(pf, p_mesh.topology.length, GL.UNSIGNED_SHORT, 0);
		}
		else
		{				
			c.drawArrays(pf, 0, p_mesh.vertexCount);			
		}
		//Finish();
	}
	
	static function Get(m : Mesh, a : String) : Buffer { var k:String = a + m.id; return m_buffers.exists(k) ? m_buffers.get(k) : null; }
	
	static function PrimitiveFlag(f : MeshPrimitive) :Int
	{
		switch(f)
		{
			case MeshPrimitive.Points:			return GL.POINTS;
			case MeshPrimitive.Lines: 			return GL.LINES;
			case MeshPrimitive.LineLoop: 		return GL.LINE_LOOP;
			case MeshPrimitive.LineStrip: 		return GL.LINE_STRIP;
			case MeshPrimitive.Triangles:		return GL.TRIANGLES;
			case MeshPrimitive.TriangleFan:		return GL.TRIANGLE_FAN;
			case MeshPrimitive.TriangleStrip:	return GL.TRIANGLE_STRIP;
		}
		return GL.TRIANGLES;
	}
	
	static function ModeFlag(f : MeshMode) :Int
	{
		return GL.DYNAMIC_DRAW;
		switch(f)
		{
			case MeshMode.Dynamic: return GL.DYNAMIC_DRAW;			
			case MeshMode.Stream:  return GL.STREAM_DRAW;
			case MeshMode.Static:  return GL.STATIC_DRAW;		
		}
		return GL.STATIC_DRAW;
	}
	
	
	
}