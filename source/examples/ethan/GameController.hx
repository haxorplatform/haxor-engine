package examples.ethan;
import haxor.component.animation.AnimationClip;
import haxor.component.Behaviour;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.MeshRenderer;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.component.SkinnedMeshRenderer;
import haxor.component.Transform;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.graphics.Fog;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.texture.Texture2D;
import haxor.io.file.ColladaFile;
import haxor.math.Color;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.physics.Physics;
import haxor.core.Enums.AnimationWrap;

/**
 * ...
 * @author dude
 */
class GameController extends Behaviour
{
	public var app : Main;
	
	public var orbit : CameraOrbit;
	
	public var player : Entity;
	
	private var m_clips : Map<String,AnimationClip>;
	
	public function Initialize():Void
	{
		Console.Log("GameController> Initialize");
		
		app = cast application;
		
		m_clips = new Map<String,AnimationClip>();
		
		Physics.gravity = new Vector3(0, -9.8, 0);		
		
		Light.ambient = Color.blue30;
		
		var cf : ColladaFile = Asset.Get("player");
		
		player = cf.asset;				
		player.name = "player";
		player.transform.localPosition = new Vector3(0.0, 0.1, 0.0);
		
		var mr : Array<MeshRenderer> = cast player.GetComponentsInChildren(SkinnedMeshRenderer);
		var mat : Material;
		
		for (i in 0...mr.length)
		{
			switch(mr[i].name)
			{
				case "EthanBody":
					mat = Material.Opaque(Asset.Get("player/diffuse"));
					mat.shader = Shader.FlatTextureSkin;// Asset.Get("haxor/diffuse/ToonSkinFalloff");					
					mat.SetFloat("Falloff", 1.5);
					mat.SetFloat("FalloffIntensity", 1.0);					
					mat.SetTexture("RampTexture", Asset.Get("player/ramp"));
					mr[i].material = mat;
					
				case "EthanGlasses":
					mat = Material.Opaque(Asset.Get("player/diffuse"));
					mat.shader = Shader.FlatTextureSkin;//Asset.Get("haxor/diffuse/ToonSkinFalloff");					
					mat.SetFloat("Falloff", 1.5);
					mat.SetFloat("FalloffIntensity", 1.0);					
					mat.SetColor("Tint", Color.red);
					mat.SetTexture("RampTexture", Asset.Get("player/ramp"));
					mr[i].material = mat;
			}
			
			
		}
		
		LoadClip("player/animation/idle",	"idle");
		LoadClip("player/animation/run",	"run");
		PlayClip("run");
		
		
		var sc : SphereCollider = player.AddComponent(SphereCollider);
		sc.radius = 1;
		sc.center = new Vector3(0, 0, 0.5);
		player.AddComponent(RigidBody);
		
		
		var ground : Entity = new Entity("ground");
		var bc : BoxCollider = ground.AddComponent(BoxCollider);
		bc.size = new Vector3(50.0, 2.0, 50.0);
		bc.center = new Vector3(0.0, -1.0, 0.0);
		
		
		orbit = CameraOrbit.Create(10, 45, 45);
		orbit.transform.localPosition = new Vector3(0, 0, 0);
		orbit.smooth = 5;		
		orbit.camera.background = Color.gray25;
		orbit.camera.near = 1.0;
		orbit.camera.far  = 500;
		orbit.camera.fov  = 40;
		orbit.target = player.transform;
		orbit.follow = true;
		
		var orbit_input : CameraOrbitInput = orbit.entity.AddComponent(CameraOrbitInput);		
		orbit_input.zoomSpeed = 0.5;
		
		
		Fog.color = Color.gray25;
		Fog.exp   = 1.5;
		Fog.end   = 0.6;
		Fog.density = 0.0;
		
	}
	
	private function LoadClip(p_id:String, p_name:String,p_loop:Bool=true,p_speed:Float=1.0):AnimationClip
	{
		var cf : ColladaFile;		
		cf = Asset.Get(p_id);
		var e : Entity = player;
		cf.AddAnimations(e); 
		var cid:Int = e.animation.clips.length - 1;
		var c : AnimationClip = e.animation.clips[cid];			
		c.name = p_name;		
		c.wrap  = p_loop ? AnimationWrap.Loop : AnimationWrap.Clamp;
		c.speed = p_speed;				
		m_clips.set(p_name, c);
		return c;
	}
	
	public function PlayClip(p_name:String,p_fade:Float=0.0):Void
	{
		var c : AnimationClip = m_clips.get(p_name);
		if (c == null) return;
		var e : Entity = player;
		e.animation.Stop();
		e.animation.Fade(c, 0.0, p_fade);
	}
	
}