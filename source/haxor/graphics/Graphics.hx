package haxor.graphics;
import haxor.component.Camera;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.core.Enums.ClearFlag;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.GL;
import haxor.math.AABB2;
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
		EngineContext.material.Bind(p_material,p_transform,p_camera);
		EngineContext.mesh.Bind(p_mesh);
		EngineContext.mesh.Draw(p_mesh);
	}
	
}