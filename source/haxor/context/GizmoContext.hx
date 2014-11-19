package haxor.context;
import haxor.component.Camera;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.Screen;
import haxor.io.FloatArray;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.platform.Types.Float32;

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
	
	/**
	 * Mesh of a axis.
	 */
	private var axis : Mesh;
	
	/**
	 * Mesh of a screen texture.
	 */
	private var texture : Mesh;
	
	/**
	 * Material to be used by gizmos.
	 */
	private var gizmo_material : Material;
	
	/**
	 * Material used to draw textures in screen.
	 */
	private var texture_material : Material;
	
	
	private function new() 
	{
		
	}
	
	
	private function Initialize():Void
	{
		var mat : Material;
		mat = gizmo_material	= new Material("$GizmoMaterial");
		mat.shader 	= new Shader(ShaderContext.gizmo_source);
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);		
		mat.SetFloat("Area", 1000.0);
		mat.SetColor("Tint", new Color(1.0, 1.0, 1.0, 0.4));
		mat.ztest = false;
		
		mat = texture_material	= new Material("$TextureMaterial");
		mat.shader 	= new Shader(ShaderContext.texture_source);
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);		
		mat.SetFloat2("Screen", Screen.width, Screen.height);
		mat.SetFloat4("Rect", 0, 0, 100, 100);
		mat.SetColor("Tint", new Color(1.0, 1.0, 1.0, 1.0));
		mat.cull = CullMode.None;
		mat.ztest = false;
		
		CreateAxis();
		CreateGrid(100.0);
		CreateTextureQuad();
	}
	
	/**
	 * Creates the quad which will render textures on the screen.
	 */
	private function CreateTextureQuad():Void
	{
		var m : Mesh = texture = new Mesh("$TextureQuad");
		var vl : FloatArray;		
		vl = FloatArray.Alloc([
		0, 0, 0, 
		0,-1, 0,
		1,-1, 0,		
		0, 0, 0, 
		1,-1, 0,
		1, 0, 0		
		]);		
		m.Set("vertex", vl, 3);		
		m.bounds = m.GenerateAttribBounds("vertex", AABB3.temp);		
	}
	
	/**
	 * Creates lines to show the world space axis.
	 */
	private function CreateAxis():Void
	{
		var m : Mesh = axis = new Mesh("$GridAxis");
		m.primitive = MeshPrimitive.Lines;
		var vl : FloatArray = new FloatArray(18);
		var cl : FloatArray = new FloatArray(24);
		var k : Int;
		
		//Positions
		k = 0;		
		//X
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 1.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		
		//Y
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 0.0); vl.Set(k++, 1.0); vl.Set(k++, 0.0);
		
		//Z
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 1.0);
		
		//Color
		k = 0;
		//X
		cl.Set(k++, 1.0); cl.Set(k++, 0.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0);
		cl.Set(k++, 1.0); cl.Set(k++, 0.3); cl.Set(k++, 0.3); cl.Set(k++, 1.0);
		
		//Y
		cl.Set(k++, 0.0); cl.Set(k++, 1.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0);
		cl.Set(k++, 0.3); cl.Set(k++, 1.0); cl.Set(k++, 0.3); cl.Set(k++, 1.0);
		
		//Z
		cl.Set(k++, 0.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0); cl.Set(k++, 1.0);
		cl.Set(k++, 0.3); cl.Set(k++, 0.3); cl.Set(k++, 1.0); cl.Set(k++, 1.0);
		
		
		m.Set("vertex", vl, 3);
		m.Set("color",  cl, 4);
		
		m.bounds = m.GenerateAttribBounds("vertex", AABB3.temp);		
	}
	
	/**
	 * Creates a Gizmo for grid.
	 * @param	p_step
	 */
	private function CreateGrid(p_step:Float32):Void
	{	
		grid = new Mesh("$GridMesh");
		grid.primitive = MeshPrimitive.Lines;
		var len : Int = cast(p_step+1);
		p_step = 1.0 / p_step;
		var ox : Float32 = 0.5;
		var oz : Float32 = 0.5;
		var px : Float32 = 0.0;
		var pz : Float32 = 0.0;		
		var vl : FloatArray = new FloatArray(12 * len);		
		var k : Int;		
		//x
		k = 0;
		for (i in 0...len)
		{	
			vl.Set(k++, px-ox); vl.Set(k++, 0.0); vl.Set(k++, oz);
			vl.Set(k++, px-ox); vl.Set(k++, 0.0); vl.Set(k++,-oz);			
			px += p_step;
		}	
		
		//z		
		for (i in 0...len)
		{	
			vl.Set(k++, ox); vl.Set(k++, 0.0); vl.Set(k++, pz-oz);
			vl.Set(k++,-ox); vl.Set(k++, 0.0); vl.Set(k++, pz-oz);
			pz += p_step;
		}		
		grid.Set("vertex", vl, 3);		
		grid.bounds = grid.GenerateAttribBounds("vertex", AABB3.temp);		
	}
	
	/**
	 * Renders the Grid gizmo.
	 * @param	p_area
	 * @param	p_color
	 */
	private function DrawGrid(p_area:Float32,p_color:Color=null):Void
	{
		gizmo_material.SetFloat("Area", p_area);
		if (p_color != null) gizmo_material.SetColor("Tint", p_color);					
		Graphics.Render(grid, gizmo_material,null,Camera.main);
	}
	
	/**
	 * Renders the world axis.
	 * @param	p_area
	 */
	private function DrawAxis(p_area:Float32):Void
	{
		gizmo_material.SetFloat("Area", p_area);		
		gizmo_material.SetColor("Tint", Color.temp.Set(1,1,1,1));		
		Graphics.Render(axis, gizmo_material,null,Camera.main);
	}
	
}