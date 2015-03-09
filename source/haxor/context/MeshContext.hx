package haxor.context;
import haxor.core.Console;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.RenderStats;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.Mesh.MeshAttrib;
import haxor.io.FloatArray;
import haxor.graphics.GL;
import haxor.math.Mathf;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.VAOId;

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
	private var aid : UID;
	
	/**
	 * Unique Mesh ids.
	 */
	private var mid : UID;
	
	/**
	 * Default attribs for shaders.
	 */
	private var attribs : Array<String> = ["vertex", "normal", "uv0", "uv1", "uv2", "color", "weight", "bone"];
		
	/**
	 * List of created buffers.
	 */
	private var buffers : Array<MeshBufferId>;
	
	/**
	 * Currently bound element buffer.
	 */
	private var bound_element : MeshBufferId;
	
	/**
	 * List of vertex array objects per mesh.
	 */
	private var vao : Array<VAOId>;
	
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
	 * Flag that indicates the default color attrib is active
	 */
	private var m_auto_white : Bool;
	
	/**
	 * Creates the Mesh context to handle internal structures.
	 */
	private function new() 
	{
		aid = new UID();
		mid = new UID();
		buffers 	= [];		
		activated 	= [];
		vao			= [];
		
		m_auto_white = false;
		
		//Max 32 Active attribs.
		for (i in 0...32) activated.push(false);
		
		var max_buffers : Int = 512;
		
		for (i in 0...max_buffers)
		{			
			buffers.push(GL.INVALID);		
		}
		
		bound_element = GL.INVALID;
	}
	
	/**
	 * Callback called when the Graphics context is ready.
	 */
	private function Initialize():Void
	{
		Console.Log("MeshContext> Initialize.", 3);		
	}
	
	/**
	 * Creates the mesh and its internal data.
	 * @param	p_mesh
	 */
	private function Create(p_mesh : Mesh):Void
	{
		if(GL.VAO_ENABLED) if(mid.stored <= 0) vao.push(GL.INVALID);
		p_mesh.__cid = mid.id;		
		if (GL.VAO_ENABLED) vao[p_mesh.__cid] = GL.INVALID;
	}
	
	/**
	 * Destroys the mesh and its internal data.
	 * @param	p_mesh
	 */
	private function Destroy(p_mesh : Mesh):Void
	{
		p_mesh.Clear();
		if (GL.VAO_ENABLED) if (vao[p_mesh.__cid] != GL.INVALID) GL.DeleteVAO(vao[p_mesh.__cid]);
		mid.id = p_mesh.__cid;
	}
	
	/**
	 * Enables a mesh. Ignores if the the mesh is the same.
	 * @param	p_mesh
	 */
	private function Bind(p_mesh : Mesh):Void
	{
		if (p_mesh != current) 
		{ 
			Unbind(p_mesh); 
			current = p_mesh; 
			
			if (current != null)
			{
				// if VAO activate only it.
				ActivateAttributes();				
				#if gldebug
				GL.Assert("Mesh Bind");
				#end				
			}
		}
	}
	
	/**
	 * Activates the current mesh attribs.
	 */
	private function ActivateAttributes():Void
	{
		var has_vao : Bool = false;
		if (GL.VAO_ENABLED)
		{
			has_vao = true;
			var vao_id : VAOId = vao[current.__cid];
			
			if (vao_id == GL.INVALID)
			{
				vao[current.__cid] = vao_id = GL.CreateVAO();				
				has_vao = false;
			}
			GL.BindVAO(vao_id);
		}
		
		var a 		: MeshAttrib;
		var al 		: Array<MeshAttrib> = current.m_attribs;
		var id 		: MeshBufferId;
		var type 	: Int;
		var has_color : Bool = false;
		
		for (i in 0...al.length)
		{					
			a = al[i];
			var loc : Int = a._loc_; //Default attribs can be cached! wooray!
			if (loc == 5) { has_color = true; m_auto_white = false; }
			if (loc < 0) 
			{ 
				//User defined attribs needs to be searched though.
				//But they will be cached later! wooray!
				loc = EngineContext.material.GetAttribLocation(a); 
				if (loc < 0) continue;				
			}			
			
			type = GL.FLOAT; //TODO: Include GL.FIXED	
			
			if (!activated[loc])
			{
				activated[loc] = true;										
				GL.EnableVertexAttrib(loc);
			}									
			
			if(!has_vao)
			if (a.count > 0)
			{
				GL.BindBuffer(GL.ARRAY_BUFFER, buffers[a.__cid]);
				GL.VertexAttribPointer(loc, a.offset, type, false, 0, 0);
			}
		}
		
		//Forces color attrib to white if none is found		
		
		if (!has_color)
		{					
			if (activated[5]) { GL.DisableVertexAttrib(5); activated[5] = false; }
			if(!has_vao) if (!m_auto_white) { GL.VertexAttrib4f(5, 1.0, 1.0, 1.0, 1.0); m_auto_white = true; }
		}
		//*/
		if(!has_vao)
		if (current.indexed)
		{	
			a = current.m_topology_attrib;								
			if (bound_element != buffers[a.__cid])
			{	
				bound_element = buffers[a.__cid];
				GL.BindBuffer(GL.ELEMENT_ARRAY_BUFFER,bound_element);
			}
		}
	}
	
	/**
	 * Disables the bound Mesh
	 */
	private function Unbind(p_next : Mesh=null):Void
	{	
		if (current != null)
		{
			var al0 : Array<MeshAttrib> = current.m_attribs;
			for (i in 0...al0.length)
			{
				var l0 : Int = al0[i]._loc_;
				if (l0 >= 0) { if(activated[l0]) { GL.DisableVertexAttrib(l0); activated[l0] = false; } }
			}
		}
		//DisableAttribArray of the last mesh.		
		/*
		var al0 : Array<MeshAttrib> = current.m_attribs;
		if (p_next == null)
		{
			if(current != null)
			for (i in 0...al0.length)
			{
				var l0 : Int = al0[i]._loc_;
				if (l0 >= 0) { if(activated[l0]) { GL.DisableVertexAttrib(l0); activated[l0] = false; } }
			}
			current = null;
			bound_element = GL.INVALID;
			return;
		}
		
		
		if (current != null)
		{							
			var al1 : Array<MeshAttrib> = p_next.m_attribs;
			//Checks if the new mesh have matching attrib locations and skip disabling them.
			for (i in 0...al0.length)
			{
				var found : Bool = false;
				var l0 : Int = al0[i]._loc_;
				if (l0 < 0) continue;
				for (j in 0...al1.length)
				{
					var l1 : Int = al1[j]._loc_;
					if (l1 < 0) continue;
					if (l0 == l1) { found = true; break; }
				}
				if (found)
				{
					if (l0 >= 0)
					{
						if (!activated[l0]) { GL.EnableVertexAttrib(l0); activated[l0] = true; }
					}						
				}
				else
				{
					if (l0 >= 0) 
					{ 
						if (activated[l0]) { GL.DisableVertexAttrib(l0); activated[l0] = false; }
					}
				}
			}
		}
		//*/
	}
	
	/**
	 * Draws to the bound target, using all attribs from the passed mesh.
	 * @param	p_mesh
	 */
	private function Draw(m : Mesh):Void
	{
		if (m.indexed)
		{	
			GL.DrawElements(m.primitive, m.m_topology_attrib.data.length, GL.UNSIGNED_SHORT, 0);
			
			#if profile
			RenderStats.triangles += cast Mathf.Floor(m.m_topology_attrib.data.length / 3);
			#end
			
			#if gldebug
			GL.Assert("Mesh DrawElements");
			#end			
		}
		else
		{	
			
			GL.DrawArrays(m.primitive, 0, m.m_vcount);
			
			#if profile
			var off : Int = 3;
			if (m.primitive == MeshPrimitive.Lines)  off = 2;
			if (m.primitive == MeshPrimitive.Points) off = 1;
			RenderStats.triangles += cast Mathf.Floor(m.m_vcount / off);
			#end
			
			#if gldebug
			GL.Assert("Mesh DrawArrays");
			#end						
		}
		
	}
	
	/**
	 * Removes the attrib from the GPU.
	 * @param	p_attrib
	 */
	private function RemoveAttrib(p_attrib : MeshAttrib,p_mesh : Mesh):Void
	{		
		var id : MeshBufferId = buffers[p_attrib.__cid];
		if (id == GL.INVALID) return;		
		GL.DeleteBuffer(id);
		buffers[p_attrib.__cid] = GL.INVALID;
		aid.id = p_attrib.__cid;
		
		if (GL.VAO_ENABLED) if (vao[p_mesh.__cid] != GL.INVALID) { GL.DeleteVAO(vao[p_mesh.__cid]); vao[p_mesh.__cid] = GL.INVALID; }
	}
	
	/**
	 * Updates the Attribute for a given Mesh.
	 * @param	p_attrib
	 */
	private function UpdateAttrib(a : MeshAttrib,p_mode : Int,p_is_index : Bool,p_mesh : Mesh):Void
	{
		
		if (GL.VAO_ENABLED) if (vao[p_mesh.__cid] != GL.INVALID) { GL.DeleteVAO(vao[p_mesh.__cid]); vao[p_mesh.__cid] = GL.INVALID; }
		
		var id : MeshBufferId = buffers[a.__cid];
		var target_flag : Int = p_is_index ? GL.ELEMENT_ARRAY_BUFFER : GL.ARRAY_BUFFER;
		
		//If this attrib is one of the default attribs of Haxor. Cache its position.
		a._loc_ = attribs.indexOf(a.name);
		
		if (id == GL.INVALID)
		{			
			id = GL.CreateBuffer();			
			buffers[a.__cid] = id;			
		}			
		
		GL.BindBuffer(target_flag, id);		
		GL.BufferData(target_flag, a.data, p_mode);		
		#if gldebug
		GL.Assert("Mesh BufferData attrib[" + a.name+"]");
		#end
		
	}
	
}