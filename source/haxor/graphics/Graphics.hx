package haxor.graphics;
import haxor.component.Camera;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.core.Enums.ClearFlag;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.GL;
import haxor.graphics.texture.Texture;
import haxor.io.Buffer;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;

/**
 * Class that offers high level commands to draw Haxor elements.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Graphics
{
	/**
	 * Cache to avoid repeated viewport.
	 */
	static private var m_last_viewport : AABB2 = AABB2.empty;
	
	/**
	 * Sets the viewport if its different than the last one.
	 * @param	p_viewport
	 */
	static public function Viewport(p_viewport:AABB2):Void
	{
		var vp : AABB2 = p_viewport;
		var dirty : Bool = false;
		if (Mathf.Abs(vp.x - m_last_viewport.x) > 0.0) 				dirty = true; else
		if (Mathf.Abs(vp.y - m_last_viewport.y) > 0.0) 				dirty = true; else
		if (Mathf.Abs(vp.width - m_last_viewport.width) > 0.0) 		dirty = true; else
		if (Mathf.Abs(vp.height - m_last_viewport.height) > 0.0) 	dirty = true;
		
		if (dirty)
		{
			m_last_viewport.SetAABB2(vp);			
			GL.Viewport(cast vp.x, cast vp.y, cast vp.width, cast vp.height);
			GL.Scissor(cast vp.x, cast vp.y, cast vp.width, cast vp.height);
		}	
	}
	
	/**
	 * Clears the screen with the informed camera flags.
	 * @param	p_camera
	 */
	static public function Clear(p_camera : Camera):Void
	{
		var c : Camera = p_camera;		
		Viewport(p_camera.m_pixelViewport);		
		if (c.clear != ClearFlag.None)
		{
			var flag:Int = 0;			
            if ((c.clear & ClearFlag.Color) != 0)  flag |= GL.COLOR_BUFFER_BIT;
            if ((c.clear & ClearFlag.Skybox) != 0) flag |= GL.COLOR_BUFFER_BIT;
            if ((c.clear & ClearFlag.Depth) != 0)  flag |= GL.DEPTH_BUFFER_BIT;
			GL.ClearColor(c.background.r, c.background.g, c.background.b, c.background.a);
			GL.ClearDepth(1.0);
            GL.Clear(flag);			
			/*
			if ((c.clear & ClearFlag.Skybox) != 0)
			{
				if (p_camera.skybox != null)
				{					
					Material.skybox.SetUniform("SkyboxTexture", p_camera.skybox);
					Material.skybox.SetUniform("SkyboxProjectionMatrixInverse",p_camera.m_skyboxProjectionInverse);
					Render(p_camera, null, BufferAPI.skybox, Material.skybox);
				}
			}
			//*/
		}	
	}
	
	/**
	 * Renders the Mesh into the screen using the passed Material.
	 * @param	p_mesh
	 * @param	p_material
	 */
	static public function Render(p_mesh : Mesh, p_material : Material,p_transform:Transform=null,p_camera : Camera=null):Void
	{		
		EngineContext.material.Bind(p_material,p_transform,p_camera,p_mesh);
		EngineContext.mesh.Bind(p_mesh);
		EngineContext.mesh.Draw(p_mesh);
	}
	
	/**
	 * Render a texture quad in the screen.
	 * @param	p_texture
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @param	p_color
	 */
	static public function DrawTexture(p_texture : Texture, p_x:Float = 0.0, p_y:Float = 0.0, p_width:Float = 256, p_height:Float = 256, p_color:Color = null):Void
	{
		if (p_texture == null) return;
		var mat : Material = EngineContext.gizmo.texture_material;
		mat.SetFloat2("Screen", Screen.width, Screen.height);
		mat.SetFloat4("Rect", p_x, p_y, p_width, p_height);
		mat.SetTexture("Texture", p_texture);
		var c : Color = p_color == null ? Color.temp.Set(1, 1, 1, 1) : p_color;
		mat.SetColor("Tint", c);		
		Render(EngineContext.gizmo.texture, mat);
	}
	
	/**
	 * Reads a region of the screen and fills the buffer with pixel data.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @param	p_buffer
	 */
	static public function ReadPixels(p_x:Int, p_y:Int,p_width:Int,p_height:Int,p_buffer:Buffer):Void
	{		
		GL.ReadPixels(p_x, p_y, p_width, p_height, GL.RGBA, GL.UNSIGNED_BYTE, p_buffer);		
	}
	
}
