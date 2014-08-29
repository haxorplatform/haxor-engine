package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Graphics extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.Graphics.m_last_viewport = haxor.math.AABB2.get_empty();
	}
	public    Graphics(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Graphics()
	{
		haxor.graphics.Graphics.__hx_ctor_haxor_graphics_Graphics(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_Graphics(haxor.graphics.Graphics __temp_me80636)
	{
		{
		}
		
	}
	
	
	public static  haxor.math.AABB2 m_last_viewport;
	
	public static   void Viewport(haxor.math.AABB2 p_viewport)
	{
		haxor.math.AABB2 vp = p_viewport;
		boolean dirty = false;
		double __temp_stmt81363 = 0.0;
		{
			double p_a = ( vp.get_xMin() - haxor.graphics.Graphics.m_last_viewport.get_xMin() );
			__temp_stmt81363 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt81363 > 0.0 )) 
		{
			dirty = true;
		}
		 else 
		{
			double __temp_stmt81364 = 0.0;
			{
				double p_a1 = ( vp.get_yMin() - haxor.graphics.Graphics.m_last_viewport.get_yMin() );
				__temp_stmt81364 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
			}
			
			if (( __temp_stmt81364 > 0.0 )) 
			{
				dirty = true;
			}
			 else 
			{
				double __temp_stmt81365 = 0.0;
				{
					double p_a2 = 0.0;
					double __temp_stmt81366 = 0.0;
					{
						double p_a3 = ( vp.get_xMax() - vp.get_xMin() );
						__temp_stmt81366 = ( (( p_a3 < 0 )) ? ( - (p_a3) ) : (p_a3) );
					}
					
					double __temp_stmt81367 = 0.0;
					{
						haxor.math.AABB2 _this = haxor.graphics.Graphics.m_last_viewport;
						{
							double p_a4 = ( _this.get_xMax() - _this.get_xMin() );
							__temp_stmt81367 = ( (( p_a4 < 0 )) ? ( - (p_a4) ) : (p_a4) );
						}
						
					}
					
					p_a2 = ( __temp_stmt81366 - __temp_stmt81367 );
					__temp_stmt81365 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
				}
				
				if (( __temp_stmt81365 > 0.0 )) 
				{
					dirty = true;
				}
				 else 
				{
					double __temp_stmt81368 = 0.0;
					{
						double p_a5 = 0.0;
						double __temp_stmt81369 = 0.0;
						{
							double p_a6 = ( vp.get_yMax() - vp.get_yMin() );
							__temp_stmt81369 = ( (( p_a6 < 0 )) ? ( - (p_a6) ) : (p_a6) );
						}
						
						double __temp_stmt81370 = 0.0;
						{
							haxor.math.AABB2 _this1 = haxor.graphics.Graphics.m_last_viewport;
							{
								double p_a7 = ( _this1.get_yMax() - _this1.get_yMin() );
								__temp_stmt81370 = ( (( p_a7 < 0 )) ? ( - (p_a7) ) : (p_a7) );
							}
							
						}
						
						p_a5 = ( __temp_stmt81369 - __temp_stmt81370 );
						__temp_stmt81368 = ( (( p_a5 < 0 )) ? ( - (p_a5) ) : (p_a5) );
					}
					
					if (( __temp_stmt81368 > 0.0 )) 
					{
						dirty = true;
					}
					
				}
				
			}
			
		}
		
		if (dirty) 
		{
			haxor.graphics.Graphics.m_last_viewport.SetAABB2(vp);
			{
				int p_x = ((int) (vp.get_xMin()) );
				int p_y = ((int) (vp.get_yMin()) );
				int p_width = 0;
				double __temp_stmt81371 = 0.0;
				{
					double p_a8 = ( vp.get_xMax() - vp.get_xMin() );
					__temp_stmt81371 = ( (( p_a8 < 0 )) ? ( - (p_a8) ) : (p_a8) );
				}
				
				p_width = ((int) (__temp_stmt81371) );
				int p_height = 0;
				double __temp_stmt81372 = 0.0;
				{
					double p_a9 = ( vp.get_yMax() - vp.get_yMin() );
					__temp_stmt81372 = ( (( p_a9 < 0 )) ? ( - (p_a9) ) : (p_a9) );
				}
				
				p_height = ((int) (__temp_stmt81372) );
				haxor.graphics.GL.m_gl.Viewport(p_x, p_y, p_width, p_height);
			}
			
			{
				int p_x1 = ((int) (vp.get_xMin()) );
				int p_y1 = ((int) (vp.get_yMin()) );
				int p_width1 = 0;
				double __temp_stmt81373 = 0.0;
				{
					double p_a10 = ( vp.get_xMax() - vp.get_xMin() );
					__temp_stmt81373 = ( (( p_a10 < 0 )) ? ( - (p_a10) ) : (p_a10) );
				}
				
				p_width1 = ((int) (__temp_stmt81373) );
				int p_height1 = 0;
				double __temp_stmt81374 = 0.0;
				{
					double p_a11 = ( vp.get_yMax() - vp.get_yMin() );
					__temp_stmt81374 = ( (( p_a11 < 0 )) ? ( - (p_a11) ) : (p_a11) );
				}
				
				p_height1 = ((int) (__temp_stmt81374) );
				haxor.graphics.GL.m_gl.Scissor(p_x1, p_y1, p_width1, p_height1);
			}
			
		}
		
	}
	
	
	public static   void Clear(haxor.component.Camera p_camera)
	{
		haxor.component.Camera c = p_camera;
		haxor.graphics.Graphics.Viewport(p_camera.m_pixelViewport);
		if (( c.clear != haxor.graphics.ClearFlag.None )) 
		{
			int flag = 0;
			if (( (( c.clear & haxor.graphics.ClearFlag.Color )) != 0 )) 
			{
				flag |= 16384;
			}
			
			if (( (( c.clear & haxor.graphics.ClearFlag.Skybox )) != 0 )) 
			{
				flag |= 16384;
			}
			
			if (( (( c.clear & haxor.graphics.ClearFlag.Depth )) != 0 )) 
			{
				flag |= 256;
			}
			
			haxor.graphics.GL.m_gl.ClearColor(c.background.r, c.background.g, c.background.b, c.background.a);
			haxor.graphics.GL.m_gl.ClearDepth(1.0);
			haxor.graphics.GL.m_gl.Clear(flag);
		}
		
	}
	
	
	public static   void Render(haxor.graphics.mesh.Mesh p_mesh, haxor.graphics.material.Material p_material, haxor.component.Transform p_transform, haxor.component.Camera p_camera)
	{
		haxor.context.EngineContext.material.Bind(p_material, p_transform, p_camera);
		{
			haxor.context.MeshContext _this = haxor.context.EngineContext.mesh;
			if (( p_mesh != _this.current )) 
			{
				_this.current = p_mesh;
				haxor.graphics.mesh.MeshAttrib a = null;
				if (( _this.current != null )) 
				{
					haxe.root.Array<haxor.graphics.mesh.MeshAttrib> al = _this.current.m_attribs;
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
							if ( ! (haxe.lang.Runtime.toBool(_this.activated.__get(loc))) ) 
							{
								_this.activated.__set(loc, true);
								_this.active_max = ((int) (java.lang.Math.max(((double) (_this.active_max) ), ((double) (loc) ))) );
								haxor.graphics.GL.m_gl.EnableVertexAttrib(loc);
							}
							
							haxor.graphics.GL.m_gl.BindBuffer(34962, ((int) (haxe.lang.Runtime.toInt(_this.buffers.__get(a.__cid))) ));
							haxor.graphics.GL.m_gl.VertexAttribPointer(loc, a.offset, type, false, 0, 0);
						}
						
					}
					
					if ( ! (has_color) ) 
					{
						if (haxe.lang.Runtime.toBool(_this.activated.__get(5))) 
						{
							haxor.graphics.GL.m_gl.DisableVertexAttrib(5);
							_this.activated.__set(5, false);
						}
						
						haxor.graphics.GL.m_gl.VertexAttrib4f(5, 1.0, 1.0, 1.0, 1.0);
					}
					
					if (_this.current.m_indexed) 
					{
						a = _this.current.m_topology_attrib;
						haxor.graphics.GL.m_gl.BindBuffer(34963, ((int) (haxe.lang.Runtime.toInt(_this.buffers.__get(a.__cid))) ));
					}
					
				}
				
			}
			
		}
		
		if (p_mesh.m_indexed) 
		{
			haxor.graphics.GL.m_gl.DrawElements(p_mesh.primitive, p_mesh.m_topology_attrib.data.m_length, 5123, 0);
		}
		 else 
		{
			haxor.graphics.GL.m_gl.DrawArrays(p_mesh.primitive, 0, p_mesh.m_vcount);
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


