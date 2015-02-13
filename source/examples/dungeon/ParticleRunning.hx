package examples.dungeon;
import haxor.component.ParticleRenderer;
import haxor.core.Asset;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.core.Enums.PixelFormat;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Vector3;


/**
 * ...
 * @author dude
 */
class ParticleRunning extends ParticleRenderer
{

	
	
	override public function OnBuild():Void 
	{
		super.OnBuild();
		
		name = "ParticleRunning";
		var mat : Material = Asset.Get("ParticleRunningMaterial");
		
		if (mat == null)
		{
			mat = Asset.Instantiate(Asset.Get("haxor/material/transparent/unlit/ParticleAlpha"));
			mat.name = "ParticleRunningMaterial";
			var tex : Texture =
			//Asset.Get("haxor/texture/particle");
			Asset.Get("Dust");
			mat.shader = Shader.FlatParticle;
			mat.SetTexture("Texture", tex);
			mat.zwrite = false;
			Asset.Add("ParticleRunningMaterial", mat);
		}
		
		material = mat;
		
		//life.color = Asset.Get("DustColor");
		var tint_color : Texture2D = cast life.color = new Texture2D(1, 1, PixelFormat.RGBA8);
		var pix : Color = Color.FromBytes(70, 100, 145);		
		tint_color.data.SetPixel(0, 0, pix);
		tint_color.Apply();
		
		var emt : BoxEmitter = cast  emitter = new BoxEmitter(45.0, 1.0, 30.0);
		emt.ranges = [0, 0, 0, 1000, 0, 0];
		
		count = 30;
		
		//duration = 10.0;
		
		loop = true;
		
		local = false;
		
		rate.start = 
		rate.end   = 0.0;
		
		sheet.frame.start = 0;
		sheet.frame.end   = 0;
		sheet.frame.random = true;
		sheet.length = 10;
		
		sheet.fps    = 15;
		sheet.width  = 512.0 / 10.0;
		sheet.height = 64.0;
		
		start.life.start = 1.0;
		start.life.end   = 1.0;
		start.life.random=true;
		
		start.speed.start  = 3.0;
		start.speed.end    = 8.0;
		start.speed.random = true;
		
		//life.speed.start = 5.0;
		//life.speed.end   = 60.0;
		//life.speed.curve = 2.0;
		
		var ps : Float = 40.0;
		life.size.start = Vector3.one.Scale(ps);
		life.size.end   = Vector3.one.Scale(ps);
		
		mesh.bounds = AABB3.FromCenter(0, 0, 0, 30, 30, 30);
		
		//trace(">> "+entity.enabled + " " + enabled);
		
		//Play();
	}
	
	
	
}