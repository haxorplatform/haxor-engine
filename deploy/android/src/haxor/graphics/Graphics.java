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
	
	
	public static   void __hx_ctor_haxor_graphics_Graphics(haxor.graphics.Graphics __temp_me54090)
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
					int p = ((int) (haxe.lang.Runtime.toInt(_this.programs.__get(p_material._cid_))) );
					_this.UpdateFlags(p_material);
					haxor.platform.graphics.GL.m_gl.UseProgram(p);
				}
				
			}
			
			if (( _this.current != null )) 
			{
				haxe.root.Array<haxor.graphics.material.MaterialUniform> ul = _this.current.m_uniforms;
				{
					int _g1 = 0;
					int _g = ul.length;
					while (( _g1 < _g ))
					{
						int i = _g1++;
						haxor.graphics.material.MaterialUniform u = ul.__get(i);
						if (u.__d) 
						{
							u.__d = false;
							int loc = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (_this.uniforms.__get(_this.current._cid_)) )) ).__get(u.__cid))) );
							if (( loc == haxor.platform.graphics.GL.INVALID )) 
							{
								continue;
							}
							
							if (u.isFloat) 
							{
								haxor.io.FloatArray b = ((haxor.io.FloatArray) (u.data) );
								int off = u.offset;
								switch (off)
								{
									case 1:
									{
										double p_x = b.Get(0);
										haxor.platform.graphics.GL.m_gl.Uniform1f(loc, p_x);
										break;
									}
									
									
									case 2:
									{
										double p_x1 = b.Get(0);
										double p_y = b.Get(1);
										haxor.platform.graphics.GL.m_gl.Uniform2f(loc, p_x1, p_y);
										break;
									}
									
									
									case 3:
									{
										double p_x2 = b.Get(0);
										double p_y1 = b.Get(1);
										double p_z = b.Get(2);
										haxor.platform.graphics.GL.m_gl.Uniform3f(loc, p_x2, p_y1, p_z);
										break;
									}
									
									
									case 4:
									{
										double p_x3 = b.Get(0);
										double p_y2 = b.Get(1);
										double p_z1 = b.Get(2);
										double p_w = b.Get(3);
										haxor.platform.graphics.GL.m_gl.Uniform4f(loc, p_x3, p_y2, p_z1, p_w);
										break;
									}
									
									
									default:
									{
										haxor.platform.graphics.GL.m_gl.Uniform1fv(loc, b);
										break;
									}
									
								}
								
							}
							 else 
							{
								haxor.io.Int32Array b1 = ((haxor.io.Int32Array) (u.data) );
								int off1 = u.offset;
								switch (off1)
								{
									case 1:
									{
										if (( u.texture != null )) 
										{
											haxor.context.EngineContext.texture.Activate(u.texture);
										}
										
										{
											int p_x4 = b1.Get(0);
											haxor.platform.graphics.GL.m_gl.Uniform1i(loc, p_x4);
										}
										
										break;
									}
									
									
									case 2:
									{
										int p_x5 = b1.Get(0);
										int p_y3 = b1.Get(1);
										haxor.platform.graphics.GL.m_gl.Uniform2i(loc, p_x5, p_y3);
										break;
									}
									
									
									case 3:
									{
										int p_x6 = b1.Get(0);
										int p_y4 = b1.Get(1);
										int p_z2 = b1.Get(2);
										haxor.platform.graphics.GL.m_gl.Uniform3i(loc, p_x6, p_y4, p_z2);
										break;
									}
									
									
									case 4:
									{
										int p_x7 = b1.Get(0);
										int p_y5 = b1.Get(1);
										int p_z3 = b1.Get(2);
										int p_w1 = b1.Get(3);
										haxor.platform.graphics.GL.m_gl.Uniform4i(loc, p_x7, p_y5, p_z3, p_w1);
										break;
									}
									
									
									default:
									{
										haxor.platform.graphics.GL.m_gl.Uniform1iv(loc, b1);
										break;
									}
									
								}
								
							}
							
						}
						
					}
					
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
						int _g11 = 0;
						int _g2 = al.length;
						while (( _g11 < _g2 ))
						{
							int i1 = _g11++;
							a = al.__get(i1);
							int loc1 = a._loc_;
							if (( loc1 == 5 )) 
							{
								has_color = true;
							}
							
							if (( loc1 < 0 )) 
							{
								loc1 = haxor.context.EngineContext.material.GetAttribLocation(a);
								if (( loc1 < 0 )) 
								{
									continue;
								}
								
							}
							
							type = 5126;
							if ( ! (haxe.lang.Runtime.toBool(_this1.activated.__get(loc1))) ) 
							{
								_this1.activated.__set(loc1, true);
								_this1.active_max = ((int) (java.lang.Math.max(((double) (_this1.active_max) ), ((double) (loc1) ))) );
								haxor.platform.graphics.GL.m_gl.EnableVertexAttrib(loc1);
							}
							
							haxor.platform.graphics.GL.m_gl.BindBuffer(34962, ((int) (haxe.lang.Runtime.toInt(_this1.buffers.__get(a._cid_))) ));
							haxor.platform.graphics.GL.m_gl.VertexAttribPointer(loc1, a.offset, type, false, 0, 0);
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


