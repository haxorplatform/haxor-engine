package examples.dungeon;
import haxor.component.AnimationClip.AnimationWrap;
import haxor.component.ParticleRenderer;
import haxor.core.Asset;
import haxor.core.Resource;
import haxor.graphics.Material;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.texture.Texture;
import haxor.texture.Texture2D;

/**
 * ...
 * @author dude
 */
class ParticleTorch extends ParticleRenderer
{

	public var strength(get_strength, set_strength):Float;
	private function get_strength():Float { return m_strength; }
	private function set_strength(v:Float):Float 
	{ 
		m_strength = Mathf.Clamp01(v); 
		start.life.start = Mathf.Lerp(2.0, 3.0, m_strength);
		start.life.end   = Mathf.Lerp(3.0, 5.0, m_strength);
		return m_strength;
	}
	private var m_strength : Float;
	
	override public function OnBuild():Void 
	{
		name = "ParticleTorch";
		var mat_id : String = "ParticleTorchMaterial";
		var mat : Material = Asset.Get(mat_id);
		
		var tex : Texture =
		//Asset.Get("haxor/texture/particle");
		Asset.Get("Fire");
		
		//if (mat == null)
		{			
			mat = Resource.Instantiate(Asset.Get("haxor/material/transparent/unlit/ParticleAdditive"));
			mat.name = mat_id;			
			mat.SetUniform("Texture", tex);
			mat.zwrite = false;
			//Asset.Add(mat_id, mat);
		}
		
		material = mat;
		
		var emt : SphereEmitter = cast  emitter = new SphereEmitter(10.0);
		//emt.ranges = [0, 0, 0, 1000, 0, 0];
		
		count = 200;
		
		//duration = 10.0;
		
		loop = true;
		
		local = false;
		
		rate.start = 
		rate.end   = 20.0;
		
		sheet.length = 
		4;
		//0;
		sheet.fps    = 4;
		sheet.width  = tex.width / 2.0;
		sheet.height = tex.height / 2.0;
		sheet.wrap   = AnimationWrap.Loop;
		start.life.random=true;
		
		start.speed.start  = 1.0;
		start.speed.end    = 1.0;
		start.speed.random = true;
		
		life.speed.start = 1.0;
		life.speed.end   = 3.0;
		life.speed.curve = 1.0;
		
		force = new Vector3(0, 3, 0);
		
		life.color = Asset.Get("FireColor");
		
		var ps : Float = 20.0;
		
		start.size.start = Vector3.one.Scale(ps);
		start.size.end   = Vector3.one.Scale(ps*2.0);
		
		life.size.start = Vector3.one.Scale(1.0);
		life.size.end   = Vector3.one.Scale(0.0);
		
		mesh.bounds = AABB3.FromCenter(0, 0, 0, 30, 30, 30);
		
		strength = 0.5;
		
		Play();
		
		//trace(">> "+entity.enabled + " " + enabled);
		
		//Play();
	}
	
	
	
}