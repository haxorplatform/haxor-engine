package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GL extends haxe.lang.HxObject
{
	static 
	{
		haxor.platform.graphics.GL.NULL_ID = -1;
	}
	public    GL(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GL()
	{
		haxor.platform.graphics.GL.__hx_ctor_haxor_platform_graphics_GL(this);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_GL(haxor.platform.graphics.GL __temp_me26109)
	{
		{
		}
		
	}
	
	
	public static  int NULL_ID;
	
	public static  haxor.platform.graphics.AndroidGL m_gl;
	
	public static   void Initialize(haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GL.m_gl = new haxor.platform.graphics.AndroidGL(((haxor.core.BaseApplication) (p_application) ));
		haxor.platform.graphics.GL.m_gl.CheckExtensions();
	}
	
	
	public static   void Resize()
	{
		haxor.platform.graphics.GL.m_gl.Resize();
	}
	
	
	public static   void Clear(double p_r, double p_g, double p_b, double p_a, double p_depth)
	{
		haxor.platform.graphics.GL.m_gl.Clear(p_r, p_g, p_b, p_a, p_depth);
	}
	
	
	public static   int CreateBuffer()
	{
		return haxor.platform.graphics.GL.m_gl.CreateBuffer();
	}
	
	
	public static   void DeleteBuffer(int p_id)
	{
		haxor.platform.graphics.GL.m_gl.DeleteBuffer(p_id);
	}
	
	
	public static   void Flush()
	{
		haxor.platform.graphics.GL.m_gl.Flush();
	}
	
	
	public static   void Focus()
	{
		haxor.platform.graphics.GL.m_gl.Focus();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.GL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.GL();
	}
	
	
}


