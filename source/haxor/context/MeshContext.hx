package haxor.context;
import haxor.core.Console;
import haxor.graphics.Enums.MeshPrimitive;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.Mesh.MeshAttrib;
import haxor.io.FloatArray;
import haxor.platform.graphics.GL;
import haxor.platform.Types.MeshBufferId;

/**
 * Class that handles Mesh related internal structures and behaviours.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class MeshContext
{
	
	/**
	 * Unique attribute ids.
	 */
	private var aid : Int;
	
	/**
	 * Unique Mesh ids.
	 */
	private var mid : Int;
	
	/**
	 * Default attribs for shaders.
	 */
	private var attribs : Array<String> = ["vertex", "normal", "uv0", "uv1", "uv2", "color", "weight", "index"];
		
	/**
	 * List of created buffers.
	 */
	private var buffers : Array<MeshBufferId>;
	
	/**
	 * List of activated attributes.
	 */
	private var activated : Array<Bool>;
	
	/**
	 * Greatest location active.
	 */
	private var active_max : Int;
	
	/**
	 * Currently bound mesh.
	 */
	private var current : Mesh;

	
	/**
	 * Creates the Mesh context to handle internal structures.
	 */
	private function new() 
	{
		aid = 0;
		mid = 0;
		buffers 	= [];		
		activated 	= [];
		
		//Max 32 Active attribs.
		for (i in 0...32) activated.push(false);
		
		var max_buffers : Int = 512;
		
		for (i in 0...max_buffers)
		{			
			buffers.push(GL.NULL);		
		}
	}
	
	/**
	 * Callback called when the Graphics context is ready.
	 */
	private function Initialize():Void
	{
		Console.Log("MeshContext> Initialize.", 3);
		
	}
	
	/**
	 * Enables a mesh. Ignores if the the mesh is the same.
	 * @param	p_mesh
	 */
	private inline function Bind(p_mesh : Mesh):Void
	{
		if (p_mesh != current) 
		{ 
			Unbind(); 
			current = p_mesh; 
			
			var a : MeshAttrib;
			
			if (current != null)
			{
				var al 		: Array<MeshAttrib> = current.m_attribs;
				var id 		: MeshBufferId;
				var type 	: Int;
				var has_color : Bool = false;
				
				for (i in 0...al.length)
				{					
					a = al[i];
					var loc : Int = a._loc_; //Default attribs can be cached! wooray!				
					if (loc == 5) has_color = true;
					if (loc < 0) 
					{ 
						//User defined attribs needs to be searched though.
						//But they will be cached later! wooray!
						loc = EngineContext.material.GetAttribLocation(a); 
						if (loc < 0) continue; 
					}
					type = GL.FLOAT; //TODO: GL.FIXED	
					
					if (!activated[loc])
					{
						activated[loc] = true;						
						active_max = cast Math.max(active_max, loc);						
						GL.EnableVertexAttrib(loc);
					}
					GL.BindBuffer(GL.ARRAY_BUFFER, buffers[a._cid_]);					
					GL.VertexAttribPointer(loc, a.offset, type, false, 0, 0);
										
				}
				
				//Forces color attrib to white if none is found
				if(!has_color) GL.VertexAttrib4f(5, 1.0, 1.0, 1.0, 0.5);
				
				if (current.indexed)
				{	
					a = current.m_topology_attrib;					
					GL.BindBuffer(GL.ELEMENT_ARRAY_BUFFER,buffers[a._cid_]);
				}
				
				GL.Assert("Mesh Bind");
			}
		}
	}
	
	/**
	 * Disables the bound Mesh
	 */
	private inline function Unbind():Void
	{	
		//DisableAttribArray
		/*
		for (i in 0...active_max)
		{
			if (activated[i]) GL.DisableVertexAttrib(i);
			activated[i] = false;
		}
		active_max = 0;
		//*/
	}
	
	/**
	 * Draws to the bound target, using all attribs from the passed mesh.
	 * @param	p_mesh
	 */
	private inline function Draw(m : Mesh):Void
	{
		if (m.indexed)
		{	
			GL.DrawElements(m.primitive, m.m_topology_attrib.data.length, GL.UNSIGNED_SHORT, 0);						
			GL.Assert("Mesh DrawElements");
		}
		else
		{
			GL.DrawArrays(m.primitive, 0, m.m_vcount);
			GL.Assert("Mesh DrawArrays");
		}
		
	}
	
	/**
	 * Removes the attrib from the GPU.
	 * @param	p_attrib
	 */
	private function RemoveAttrib(p_attrib : MeshAttrib):Void
	{		
		var id : MeshBufferId = buffers[p_attrib._cid_];
		if (id == GL.NULL) return;		
		GL.DeleteBuffer(id);
		buffers[p_attrib._cid_] = GL.NULL;
	}
	
	/**
	 * Updates the Attribute for a given Mesh.
	 * @param	p_attrib
	 */
	private function UpdateAttrib(a : MeshAttrib,p_mode : Int,p_is_index : Bool):Void
	{
		var id : MeshBufferId = buffers[a._cid_];
		var target_flag : Int = p_is_index ? GL.ELEMENT_ARRAY_BUFFER : GL.ARRAY_BUFFER;
		
		//If this attrib is one of the default attribs of Haxor. Cache its position.
		a._loc_ = attribs.indexOf(a.name);
		
		if (id == GL.NULL)
		{			
			id = GL.CreateBuffer();			
			buffers[a._cid_] = id;			
		}			
		
		GL.BindBuffer(target_flag, id);		
		GL.BufferData(target_flag, a.data, p_mode);		
		GL.Assert("Mesh BufferData attrib["+a.name+"]");
		
	}
	
}