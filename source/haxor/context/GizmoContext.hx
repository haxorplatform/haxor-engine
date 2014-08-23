package haxor.context;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.io.FloatArray;
import haxor.math.Color;

/**
 * Class that handles gizmo structures and operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class GizmoContext
{
	/**
	 * Mesh of a grid.
	 */
	private var grid : Mesh;
	
	private var grid_material : Material;
	
	private function new() 
	{
		
	}
	
	
	private function Initialize():Void
	{
		CreateGrid(10.0);
	}
	
	/**
	 * Creates a Gizmo for grid.
	 * @param	p_step
	 */
	private function CreateGrid(p_step:Float):Void
	{
		grid = new Mesh("$GridMesh");
		var len : Int = cast(p_step);
		var ox : Float = -0.5;
		var oz : Float = -0.5;
		var px : Float = 0.0;
		var pz : Float = 0.0;		
		var vl : FloatArray = new FloatArray(len*2);
		var k : Int;		
		//x
		k = 0;
		for (i in 0...len)
		{	
			vl.Set(k++,px-ox); vl.Set(k++, oz);
			vl.Set(k++,px-ox); vl.Set(k++,-oz);
			px += p_step;
		}		
		//z
		k = 0;
		for (i in 0...len)
		{	
			vl.Set(k++, ox); vl.Set(k++, pz-oz);
			vl.Set(k++,-ox); vl.Set(k++, pz-oz);
			pz += p_step;
		}		
		grid.Set("vertex", vl);
		
		grid_material 			= new Material("$GridMaterial");
		grid_material.shader 	= new Shader(ShaderContext.gizmo_grid_source);
		grid_material.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);
		grid_material.SetFloat("Area", 1000.0);
		grid_material.SetColor("Tint", new Color(1.0,1.0,1.0,0.4));
	}
	
	/**
	 * Renders the Grid gizmo.
	 * @param	p_area
	 * @param	p_color
	 */
	private function DrawGrid(p_area:Float,p_color:Color=null):Void
	{
		grid_material.SetFloat("Area", p_area);
		if(p_color!=null)grid_material.SetColor("Tint", new Color(1.0,1.0,1.0,0.4));
		Graphics.RenderMesh(grid, grid_material);
	}
	
}