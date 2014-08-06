package haxor.graphics.mesh;
import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.io.BaseArray;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.platform.graphics.GL;
import haxor.platform.Types.Float32Buffer;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.UInt16Buffer;



/**
 * Class that describes a Mesh as an attribute container.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Mesh extends Resource implements ArrayAccess<String>
{
	
	/**
	 * List of indexes that describes the access of this mesh attributes.
	 */
	public var topology(get_topology, set_topology) : UInt16Array;
	private function get_topology():UInt16Array
	{
		if (m_topology_attrib.data == null) return new UInt16Array(0);		
		return cast m_topology_attrib.data;
	}
	private function set_topology(v:UInt16Array):UInt16Array
	{ 
		if (v == null) 
		{ 
			m_topology_attrib.data = null;
			m_indexed = false; 
			//Graphics.DeleteBuffer(m_topology_attrib);
		}
		else
		{			
			m_topology_attrib.data   = v;
			m_indexed = true;
			//Graphics.UpdateBuffer(m_topology_attrib);
		}		
		return v;
	}	
	private var m_topology_attrib : MeshAttrib;
	
	
	/**
	 * Flag that indicates if this mesh uses index buffers.
	 */
	public var indexed(get_indexed, never) : Bool;
	private function get_indexed():Bool { return m_indexed; }
	private var m_indexed : Bool;
	
	/**
	 * List of attibutes that defines this mesh.
	 */
	public var attribs(get_attribs, null):Array<String>;
	private function get_attribs():Array<String> { var l : Array<String> = []; for (i in 0...m_attribs.length) l.push(m_attribs[i].name); return l; }
	private var m_attribs : Array<MeshAttrib>;
	
	/**
	 * Returns the vertex count of this mesh.
	 */
	public var vcount(get, never):Int;
	private inline function get_vcount():Int { return m_vcount; }
	private var m_vcount : Int;
	
	/**
	 * Creates a new Mesh object.
	 */
	public function new():Void
	{
		super();		
		m_attribs 	= [];
		m_indexed	= false;
		m_vcount    = 0;
		m_topology_attrib 		 = new MeshAttrib();
		m_topology_attrib.name 	 = "$topology";
		m_topology_attrib.offset = 1;
		m_topology_attrib.type 	 = "int";
	}
	
	/**
	 * Removes all attributes from this mesh and clears the GPU memory.
	 */
	public function Clear():Void
	{
		for (i in 0...m_attribs.length)
		{
			//Graphics.DeleteBuffer(m_attribs[i]);
		}
		m_attribs = [];
		m_vcount  = 0;
		topology  = null;
	}
	
	/**
	 * Checks if a given attribute exists.
	 * @param	p_name
	 * @return
	 */
	public function Exists(p_name:String):Bool
	{
		return GetAttribute(p_name) != null;
	}
	
	/**
	 * Returns the attribute data contents.
	 */
	public function Get<T>(p_name : String) : T
	{
		var a : MeshAttrib = GetAttribute(p_name);
		return a == null ? null : (cast a.data);
	}
	
	/**
	 * 
	 * @param	p_name
	 * @return
	 */
	public function GetAttribute(p_name :String) : MeshAttrib
	{
		for (i in 0...m_attribs.length) if (m_attribs[i].name == p_name) return m_attribs[i];
		return null;
	}

	
	/**
	 * Removes the attribute from the mesh internal list and destroy its data from the GPU.
	 * @param	p_name
	 */
	public function Remove(p_name : String):Void
	{
		var a : MeshAttrib = GetAttribute(p_name);
		if (a == null) return;
		m_attribs.remove(a);
		//Graphics.DeleteBuffer(a);
	}
	
	/**
	 * Sets a given attribute data content. If the attribute does not exists, it will be created.
	 * The offset parameter specifies the size of the tuple inside the BufferView.
	 * @param	p_name
	 * @param	p_data
	 * @param	p_offset
	 */		
	public function Set(p_name : String, p_data : BaseArray,p_offset : Int = 3):Void
	{	
		if (p_data == null) 	{ Console.Log("Mesh> [" + name+"] tried to set null array.",1); return; }		
		if (p_data.length <= 0)	{ Console.Log("Mesh> [" + name+"] tried to set empty array.", 1); return;	}		
		var a : MeshAttrib = GetAttribute(p_name);
		if (a == null)
		{
			a 		 = new MeshAttrib();			
			a.name   = p_name;			
			m_attribs.push(a);
		}		
		a.offset = p_offset;							
		a.data   = p_data;		
		m_vcount = m_attribs[0].count;
		for (i in 1...m_attribs.length)
		{
			var c: Int = m_attribs[i].count;
			m_vcount = m_vcount < c ? m_vcount : c;
		}
		var bid : MeshBufferId = GL.CreateBuffer();
		Console.Log(">>> "+bid);
		//Graphics.UpdateBuffer(a);
	}
	
	
	
}


/**
 * Class that describes a mesh attribute holder. It will handle the raw buffer which will contains (Float, Vector3, Color,...) data.
 */
class MeshAttrib
{
	
	/**
	 * Unique id used to sample cached buffer ids.
	 */
	public var id : Int;
	
	/**
	 * Attribute Name.
	 */
	public var name : String;
	
	/**
	 * Attribute Data.
	 */
	public var data : BaseArray;
	
	/**
	 * Type data content.
	 */
	public var type : String;
	
	/**
	 * Data offset (1 = Floats, 3 = Vector3,...)
	 */
	public var offset : Int;
	
	/**
	 * Returns the primitive count based on the array length and the offset for each element.
	 */
	public var count(get_count, never):Int;
	private function get_count():Int { return data == null ? 0 : Std.int(data.length / offset); }
	
	public function new():Void
	{
		id 	   = EngineContext.mesh.aid++;
		name   = "";
		type   = "";
		data   = null;
		offset = 0;
	}
}

