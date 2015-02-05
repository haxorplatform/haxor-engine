package examples.dungeon;
import haxor.component.Behaviour;
import haxor.component.Transform;
import haxor.core.Asset;
import haxor.core.Tween;
import haxor.math.Easing.Cubic;
import haxor.math.Quaternion;
import haxor.math.Random;
import haxor.math.Vector3;
import haxor.thread.Activity;


/**
 * ...
 * @author dude
 */
class DungeonDoor extends Behaviour
{
	public var locked : Bool;

	public var open : Bool;
	
	private var m_left  : Transform;
	
	private var m_right : Transform;
	
	
	/*
	private var m_sound_move : Sound;
	
	private var m_sound_close : Sound;
	//*/
	
	override public function OnBuild():Void 
	{
		super.OnBuild();
		locked = false;
		open = false;		
		//trace("DungeonDoor> " + name + " Build");
	}
	
	override public function OnStart():Void 
	{
		
		transform.Traverse(function(it : Transform,d : Int):Bool
		{
			var n : String = it.name.toLowerCase();
			if (n.indexOf("left") >= 0)  if (m_left == null)  m_left  = it;
			if (n.indexOf("right") >= 0) if (m_right == null) m_right = it;			
			return true;
		});
		//*/
		//trace("DungeonDoor> " + name + " Start L[" + (m_left != null) + "] R[" + (m_right != null) + "]");
		
		//if(m_left!=null) m_left.rotation  = Quaternion.FromAxisAngle(Vector3.up, -90);
		//if (m_right != null) m_right.rotation = Quaternion.FromAxisAngle(Vector3.up, -90);
		
		//m_sound_move  = Asset.Get("sound/door_metal_open");
		//m_sound_close = Asset.Get("sound/door_metal_close_click");
		
		
		Activity.Delay(Random.Range(2, 4), Open);
	}
	
	
	public function Open():Void
	{
		if (locked) return;
		open = true;
		trace("DungeonDoor> " + name + " Open");
		Tween.Add(m_left, "localRotation", Quaternion.FromAxisAngle(Vector3.up,  80), 1.5, 0.0, Cubic.OutBack);
		Tween.Add(m_right, "localRotation", Quaternion.FromAxisAngle(Vector3.up, -80), 1.5, 0.0, Cubic.OutBack);
		/*
		if (m_sound_move != null)
		{
			m_sound_move.volume = 0.05;
			m_sound_move.Play();
		}
		//*/
	}
	
	public function Close():Void
	{
		trace("DungeonDoor> " + name + " Close");		
		open = false;
		Tween.Add(m_left, "localRotation", Quaternion.FromAxisAngle(Vector3.up,  0), 1.5, 0.0, Cubic.Out);
		Tween.Add(m_right, "localRotation", Quaternion.FromAxisAngle(Vector3.up, 0), 1.5, 0.0, Cubic.Out);
		/*
		if (m_sound_move != null) m_sound_move.Play();
		if (m_sound_close != null)
		{
			
			m_sound_close.volume = 0.09;
			Timer.delay(function() 
			{ 				
				if(open) m_sound_close.Play(); 
				open = false;
			}, 1300);			
		}
		//*/
	}
	
	
	
}