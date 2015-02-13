package examples.dungeon;
import haxor.component.ParticleRenderer;
import haxor.core.Asset;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.texture.Texture;
import haxor.math.AABB3;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;
import haxor.core.Enums.AnimationWrap;

/**
 * ...
 * @author dude
 */
class ParticleTorch extends ParticleRenderer
{

	public var strength(get_strength, set_strength):Float32;
	private function get_strength():Float32 { return m_strength; }
	private function set_strength(v:Float32):Float32 
	{ 
		m_strength = Mathf.Clamp01(v); 
		start.life.start = Mathf.Lerp(2.0, 3.0, m_strength);
		start.life.end   = Mathf.Lerp(3.0, 5.0, m_strength);
		return m_strength;
	}
	private var m_strength : Float32;
	
	public var wind : Float32;
	
	
	
	override public function OnBuild():Void 
	{
		super.OnBuild();
		
		name = "ParticleTorch";
		var mat_id : String = "ParticleTorchMaterial";
		var mat : Material = Asset.Get(mat_id);
		
		var tex : Texture =
		//Asset.Get("haxor/texture/particle");
		Asset.Get("Fire");
		
		//if (mat == null)
		{			
			
			mat = Asset.Instantiate(Asset.Get("haxor/material/transparent/unlit/ParticleAdditive"));
			mat.shader = Shader.FlatParticle;
			mat.name = mat_id;			
			mat.SetTexture("Texture", tex);
			mat.zwrite = false;
			//Asset.Add(mat_id, mat);
		}
		
		material = mat;
		
		var emt : SphereEmitter = cast  emitter = new SphereEmitter(10.0);
		
		//emt.ranges = [0, 0, 0, 1000, 0, 0];
		
		count = 64;
		
		//duration = 10.0;
		
		loop = true;
		
		local = false;
		
		rate.start = 
		rate.end   = 20.0;
		
		sheet.length = 4;
		//0;
		sheet.fps    = 8;
		sheet.width  = tex.width / 2.0;
		sheet.height = tex.height / 2.0;
		sheet.wrap   = AnimationWrap.Loop;
				
		start.life.start = 2;
		start.life.end   = 10;
		start.life.random = true;				
		
		start.speed.start  = 1.0;
		start.speed.end    = 2.0;
		start.speed.random = true;
		
		var ps : Float = 10.0;
		
		start.size.start = Vector3.one.Scale(ps);
		start.size.end   = Vector3.one.Scale(ps*2.0);
		
		
		force = new Vector3(0, 1, 0);
		
		life.color = Asset.Get("FireColor");
		
		
		wind = 0.0;
		
		life.size.start = Vector3.one.Scale(2.0);
		life.size.end   = Vector3.one.Scale(0.0);
		life.speed.start  = 3.0;
		life.speed.end    = 8.0;
		life.speed.random = true;
		
		
		mesh.bounds = AABB3.FromCenter(0, 0, 0, 30, 30, 30);
		
		//strength = 1.0;
		
		Play();
		
		//trace(">> "+entity.enabled + " " + enabled);
		
		//Play();
	}
	
	override public function OnUpdate():Void 
	{
		super.OnUpdate();
		
		var s : Float32 = Mathf.Sin(Time.elapsed * 0.1);
		var c : Float32 = Mathf.Cos((Time.elapsed+0.5) * 0.2);
		
		force.Set(s * c * 1.0, force.y, 0.0);
		
	}
	
}