package examples.dungeon;
import haxor.component.animation.AnimationClip;
import haxor.component.animation.AnimationEvent;
import haxor.core.Asset;



/**
 * ...
 * @author dude
 */
class Knight extends Player
{
	
	override public function OnStart():Void 
	{
		character = "knight";
		super.OnStart();
		
		LoadClip("player/animation/all/idle01", 	"idle");
		LoadClip("player/animation/all/walk",   	"walk");
		LoadClip("player/animation/all/run", 		"run");
		LoadClip("player/animation/kp/attack01", 	"attack01");
		LoadClip("player/animation/kp/attack02", 	"attack02");
		LoadClip("player/animation/kp/idle01",  	"idle_attack");		
		LoadClip("player/animation/kp/die01",	  	"die");	
		LoadClip("player/animation/kp/hit01",  		"hit");	
		
		
		PlayClip("idle");
		
		var c:AnimationClip;
		
		
		//var snd : Sound;		
		//snd = Asset.Get("sound/run_step");			
		//if (snd != null)
		{
			//snd.volume = 0.05;
			c = GetClip("run");
			if(m_dust_particle!=null)c.AddEvent(9,  function(e : AnimationEvent):Void { /*Asset.Get("sound/run_step").Play();*/ m_dust_particle.Emit(2.0);  } );
			if(m_dust_particle!=null)c.AddEvent(17, function(e : AnimationEvent):Void { /*Asset.Get("sound/run_step").Play();*/ m_dust_particle.Emit(2.0); } );
		}		
		/*
		snd = Asset.Get("player/sound/swing"); 		
		if (snd != null)
		{
			snd.volume = 0.1;
			c = GetClip("attack01");
			c.AddEvent(12,  function(e : AnimationEvent):Void { Asset.Get("player/sound/swing").Play(); } );
		}
		//*/
		
		
	}
	
}