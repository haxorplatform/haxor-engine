package examples.dungeon;
import haxor.component.Behaviour;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.physics.Collider;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.math.Color;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.physics.Physics;

/**
 * ...
 * @author dude
 */
class GameController extends Behaviour
{
	public var app : DungeonApp;
	
	public var orbit : CameraOrbit;
	
	public var dungeon : Dungeon;
	
	public var player : Player;
	
	//public var ambiance 	: Sound;	
	//public var fog	 	: Fog;	
	//public var fxaa 		: FXAA;
	
	public function Initialize():Void
	{
		Console.Log("GameController> Initialize");
		
		app = cast application;
		
		Physics.gravity = new Vector3(0, -980, 0);		
		
		Physics.SetInteraction(GameLayer.Default, GameLayer.Default, true);
		Physics.SetInteraction(GameLayer.Default, GameLayer.Player, true);
		Physics.SetInteraction(GameLayer.Player, GameLayer.CameraArea, true);
		Physics.SetInteraction(GameLayer.Player, GameLayer.Door, true);
		
		
		
		Light.ambient = Color.FromBytes(130, 140, 160);
		
		
		dungeon = (new Entity()).AddComponent(Dungeon);
		dungeon.name = "dungeon";
		
		
		player = (new Entity()).AddComponent(Knight); 
		player.name = "player";
		//player.transform.position = new Vector3(0, 1010, 0);
		//player.enabled = false;
		//*/
		
		
		orbit = CameraOrbit.Create(700, -135, 45);
		//orbit = CameraOrbit.Create(-0.1, 2, -10);
		orbit.transform.localPosition = new Vector3(0, 9, 26);
		orbit.smooth = 5;		
		orbit.camera.background = Color.FromBytes(0, 0, 0);		
		orbit.camera.near = 150.0;
		orbit.camera.far  = 2000;
		orbit.camera.fov  = 40;
		orbit.target = player.transform;
		orbit.follow = true;
		
		//orbit.camera.near = 3.0;
		//orbit.camera.far  = 210;
		
		var orbit_input : CameraOrbitInput = orbit.entity.AddComponent(CameraOrbitInput);
		//orbit_input.zoomSpeed = 15;
		orbit_input.zoomSpeed = 35;
		//*/
	
		
		/*
		fxaa = new FXAA();
		fxaa.iterations = 2;		
		fog = new Fog();		
		orbit.camera.filters = [fxaa,fog];		
		//fog.enabled = false;		
		fog.color  = Color.FromBytes(10, 0, 40);
		fog.exp	   = 3.2;
		fog.factor = 
		//33;
		293;		
		//*/		
		
		/*
		ambiance = Asset.Get("sound/ambiance");
		if (ambiance != null)
		{
			ambiance.volume = 0.1;
			ambiance.loop = true;		
			ambiance.Play();
		}		
		//*/
	}
	
	public function OnDungeonLoaded():Void
	{
		trace("GameController> Dungeon Loaded");
		
		var p : Vector3 = dungeon.GetSpawnPosition("Player_Start_001");
		p.y += 10.0;
		trace("\tSpawn Point ["+p.ToString()+"]");
		
		if(player != null) player.transform.localPosition = p;
		orbit.pivot.localPosition      = p;		
	}
	
	public function OnTriggerEnter(p_entity:Entity, p_collider:Collider):Void
	{
		trace("GameController> TriggerEnter ["+p_entity.name+"]["+p_collider.name+"]");
		switch(p_entity.layer)
		{
			case GameLayer.Door:
				if (p_collider.layer == GameLayer.Player)
				{
					trace("GameController> Door Trigger Enter");
					//var d : DungeonDoor = p_entity.transform.parent.GetComponent(DungeonDoor);
					//if (d != null) d.Open();
				}
				
			case GameLayer.Player:
				
			default:
		}
	}
	
	public function OnTriggerExit(p_entity:Entity, p_collider:Collider):Void
	{
		trace("GameController> TriggerExit ["+p_entity.name+"]["+p_collider.name+"]");
		switch(p_entity.layer)
		{
			case GameLayer.Door:
				if (p_collider.layer == GameLayer.Player)
				{
					trace("GameController> Door Trigger Exit");
					//var d : DungeonDoor = p_entity.transform.parent.GetComponent(DungeonDoor);
					//if (d != null) d.Close();
				}
			
			default:
		}
	}
}