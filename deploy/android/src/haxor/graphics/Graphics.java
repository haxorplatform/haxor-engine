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
	
	
	public static   void __hx_ctor_haxor_graphics_Graphics(haxor.graphics.Graphics __temp_me160484)
	{
		{
		}
		
	}
	
	
	public static  haxor.math.AABB2 m_last_viewport;
	
	public static   void Viewport(haxor.math.AABB2 p_viewport)
	{
		haxor.math.AABB2 vp = p_viewport;
		boolean dirty = false;
		double __temp_stmt161224 = 0.0;
		{
			double p_a = ( vp.get_xMin() - haxor.graphics.Graphics.m_last_viewport.get_xMin() );
			__temp_stmt161224 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt161224 > 0.0 )) 
		{
			dirty = true;
		}
		 else 
		{
			double __temp_stmt161225 = 0.0;
			{
				double p_a1 = ( vp.get_yMin() - haxor.graphics.Graphics.m_last_viewport.get_yMin() );
				__temp_stmt161225 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
			}
			
			if (( __temp_stmt161225 > 0.0 )) 
			{
				dirty = true;
			}
			 else 
			{
				double __temp_stmt161226 = 0.0;
				{
					double p_a2 = 0.0;
					double __temp_stmt161227 = 0.0;
					{
						double p_a3 = ( vp.get_xMax() - vp.get_xMin() );
						__temp_stmt161227 = ( (( p_a3 < 0 )) ? ( - (p_a3) ) : (p_a3) );
					}
					
					double __temp_stmt161228 = 0.0;
					{
						haxor.math.AABB2 _this = haxor.graphics.Graphics.m_last_viewport;
						{
							double p_a4 = ( _this.get_xMax() - _this.get_xMin() );
							__temp_stmt161228 = ( (( p_a4 < 0 )) ? ( - (p_a4) ) : (p_a4) );
						}
						
					}
					
					p_a2 = ( __temp_stmt161227 - __temp_stmt161228 );
					__temp_stmt161226 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
				}
				
				if (( __temp_stmt161226 > 0.0 )) 
				{
					dirty = true;
				}
				 else 
				{
					double __temp_stmt161229 = 0.0;
					{
						double p_a5 = 0.0;
						double __temp_stmt161230 = 0.0;
						{
							double p_a6 = ( vp.get_yMax() - vp.get_yMin() );
							__temp_stmt161230 = ( (( p_a6 < 0 )) ? ( - (p_a6) ) : (p_a6) );
						}
						
						double __temp_stmt161231 = 0.0;
						{
							haxor.math.AABB2 _this1 = haxor.graphics.Graphics.m_last_viewport;
							{
								double p_a7 = ( _this1.get_yMax() - _this1.get_yMin() );
								__temp_stmt161231 = ( (( p_a7 < 0 )) ? ( - (p_a7) ) : (p_a7) );
							}
							
						}
						
						p_a5 = ( __temp_stmt161230 - __temp_stmt161231 );
						__temp_stmt161229 = ( (( p_a5 < 0 )) ? ( - (p_a5) ) : (p_a5) );
					}
					
					if (( __temp_stmt161229 > 0.0 )) 
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
				double __temp_stmt161232 = 0.0;
				{
					double p_a8 = ( vp.get_xMax() - vp.get_xMin() );
					__temp_stmt161232 = ( (( p_a8 < 0 )) ? ( - (p_a8) ) : (p_a8) );
				}
				
				p_width = ((int) (__temp_stmt161232) );
				int p_height = 0;
				double __temp_stmt161233 = 0.0;
				{
					double p_a9 = ( vp.get_yMax() - vp.get_yMin() );
					__temp_stmt161233 = ( (( p_a9 < 0 )) ? ( - (p_a9) ) : (p_a9) );
				}
				
				p_height = ((int) (__temp_stmt161233) );
				haxor.graphics.GL.m_gl.Viewport(p_x, p_y, p_width, p_height);
			}
			
			{
				int p_x1 = ((int) (vp.get_xMin()) );
				int p_y1 = ((int) (vp.get_yMin()) );
				int p_width1 = 0;
				double __temp_stmt161234 = 0.0;
				{
					double p_a10 = ( vp.get_xMax() - vp.get_xMin() );
					__temp_stmt161234 = ( (( p_a10 < 0 )) ? ( - (p_a10) ) : (p_a10) );
				}
				
				p_width1 = ((int) (__temp_stmt161234) );
				int p_height1 = 0;
				double __temp_stmt161235 = 0.0;
				{
					double p_a11 = ( vp.get_yMax() - vp.get_yMin() );
					__temp_stmt161235 = ( (( p_a11 < 0 )) ? ( - (p_a11) ) : (p_a11) );
				}
				
				p_height1 = ((int) (__temp_stmt161235) );
				haxor.graphics.GL.m_gl.Scissor(p_x1, p_y1, p_width1, p_height1);
			}
			
		}
		
	}
	
	
	public static   void Clear(haxor.component.Camera p_camera)
	{
		haxor.component.Camera c = p_camera;
		haxor.graphics.Graphics.Viewport(p_camera.m_pixelViewport);
		if (( c.clear != haxor.core.ClearFlag.None )) 
		{
			int flag = 0;
			if (( (( c.clear & haxor.core.ClearFlag.Color )) != 0 )) 
			{
				flag |= 16384;
			}
			
			if (( (( c.clear & haxor.core.ClearFlag.Skybox )) != 0 )) 
			{
				flag |= 16384;
			}
			
			if (( (( c.clear & haxor.core.ClearFlag.Depth )) != 0 )) 
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
		haxor.context.EngineContext.mesh.Bind(p_mesh);
		haxor.context.EngineContext.mesh.Draw(p_mesh);
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


