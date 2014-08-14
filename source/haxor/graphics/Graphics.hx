package haxor.graphics;
import haxor.context.EngineContext;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.Mesh;
import haxor.platform.graphics.GL;

/**
 * Class that offers high level commands to draw Haxor elements.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Graphics
{
	
	/**
	 * Renders the Mesh into the screen using the passed Material.
	 * @param	p_mesh
	 * @param	p_material
	 */
	static public function RenderMesh(p_mesh : Mesh, p_material : Material):Void
	{
		EngineContext.material.Bind(p_material);		
		EngineContext.mesh.Bind(p_mesh);
		EngineContext.mesh.Draw(p_mesh);
	}
	
}