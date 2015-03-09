package examples.dungeon;
import haxor.component.MeshRenderer;
import haxor.core.Asset;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.RenderQueue;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.graphics.mesh.Model;
import haxor.graphics.texture.Texture;
import haxor.io.UInt16Array;
import haxor.math.Color;
import haxor.math.Vector3;


/**
 * ...
 * @author dude
 */
class BlobShadow extends MeshRenderer
{

	override function OnBuild():Void 
	{
		super.OnBuild();
		/*
		var m : Mesh3 = new Mesh3();
		m.name = "BlobShadowMesh";		
		var s : Float = 0.5;
		m.vertex = 
		[
		new Vector3( -s, 0, s), new Vector3(s, 0, s),		
		new Vector3( -s, 0,-s), new Vector3(s, 0,-s)			
		];
		
		m.uv0	 = 
		[
		new Vector3( 0, 1, 0), new Vector3(1, 1, 0),		
		new Vector3( 0, 0, 0), new Vector3(1, 0, 0)
		];
		
		m.topology = UInt16Array.Alloc
		([
		0, 1, 2,
		1, 3, 2		
		]);
		
		m.GenerateBounds();
		//*/
		mesh = Model.planeXZ;
		
		var tex : Texture = Asset.Get("BlobShadow");
		
		material = Material.Transparent(tex, true,false,true);		
		material.SetBlending(BlendMode.Zero, BlendMode.SrcColor);
		material.SetColor("Tint", Color.white);
		
		
	}
	
}