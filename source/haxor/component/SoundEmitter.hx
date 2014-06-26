package haxor.component;
import haxor.core.Entity;
import haxor.media.Sound;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class SoundEmitter extends Behaviour
{
	public var sound : Sound;
	
	public var range : Float;
	
	function new(p_entity : Entity)
	{
		super(p_entity);
	}
	
	override public function OnStart():Void 
	{
		
	}
	
}