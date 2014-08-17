package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Graphics extends haxe.lang.HxObject
{
	public    Graphics(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Graphics()
	{
		haxor.graphics.Graphics.__hx_ctor_haxor_graphics_Graphics(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_Graphics(haxor.graphics.Graphics __temp_me27901)
	{
		{
		}
		
	}
	
	
	public static   void RenderMesh(haxor.graphics.mesh.Mesh p_mesh, haxor.graphics.material.Material p_material)
	{
		{
			haxor.context.MaterialContext _this = haxor.context.EngineContext.material;
			if (( p_material != _this.current )) 
			{
				_this.current = p_material;
				if (( p_material != null )) 
				{
					_this.UpdateFlags(p_material);
					haxor.platform.graphics.GL.m_gl.UseProgram(((int) (haxe.lang.Runtime.toInt(_this.programs.__get(p_material._cid_))) ));
				}
				
			}
			
		}
		
		{
			haxor.context.MeshContext _this1 = haxor.context.EngineContext.mesh;
			if (( p_mesh != _this1.current )) 
			{
				_this1.current = p_mesh;
				haxor.graphics.mesh.MeshAttrib a = null;
				if (( _this1.current != null )) 
				{
					haxe.root.Array<haxor.graphics.mesh.MeshAttrib> al = _this1.current.m_attribs;
					int id = 0;
					int type = 0;
					boolean has_color = false;
					{
						int _g1 = 0;
						int _g = al.length;
						while (( _g1 < _g ))
						{
							int i = _g1++;
							a = al.__get(i);
							int loc = a._loc_;
							if (( loc == 5 )) 
							{
								has_color = true;
							}
							
							if (( loc < 0 )) 
							{
								loc = haxor.context.EngineContext.material.GetAttribLocation(a);
								if (( loc < 0 )) 
								{
									continue;
								}
								
							}
							
							type = 5126;
							if ( ! (haxe.lang.Runtime.toBool(_this1.activated.__get(loc))) ) 
							{
								_this1.activated.__set(loc, true);
								_this1.active_max = ((int) (java.lang.Math.max(((double) (_this1.active_max) ), ((double) (loc) ))) );
								haxor.platform.graphics.GL.m_gl.EnableVertexAttrib(loc);
							}
							
							haxor.platform.graphics.GL.m_gl.BindBuffer(34962, ((int) (haxe.lang.Runtime.toInt(_this1.buffers.__get(a._cid_))) ));
							haxor.platform.graphics.GL.m_gl.VertexAttribPointer(loc, a.offset, type, false, 0, 0);
						}
						
					}
					
					if ( ! (has_color) ) 
					{
						haxor.platform.graphics.GL.m_gl.VertexAttrib4f(5, 1.0, 1.0, 1.0, 1.0);
					}
					
					if (_this1.current.m_indexed) 
					{
						a = _this1.current.m_topology_attrib;
						haxor.platform.graphics.GL.m_gl.BindBuffer(34963, ((int) (haxe.lang.Runtime.toInt(_this1.buffers.__get(a._cid_))) ));
					}
					
					haxor.platform.graphics.GL.m_gl.Assert("Mesh Bind");
				}
				
			}
			
		}
		
		if (p_mesh.m_indexed) 
		{
			haxor.platform.graphics.GL.m_gl.DrawElements(p_mesh.primitive, p_mesh.m_topology_attrib.data.m_length, 5123, 0);
			haxor.platform.graphics.GL.m_gl.Assert("Mesh DrawElements");
		}
		 else 
		{
			haxor.platform.graphics.GL.m_gl.DrawArrays(p_mesh.primitive, 0, p_mesh.m_vcount);
			haxor.platform.graphics.GL.m_gl.Assert("Mesh DrawArrays");
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.Graphics(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.Graphics();
	}
	
	
}


