package haxor.component.animation;
import haxor.core.Console;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.ILateUpdateable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.platform.Types.Float32;

/**
 * Class that describes a set of animation clips that will animate the target Entity. WIP Class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Animation extends Behaviour
{
	static private var m_list 		: Array<Animation>;	
	static private var m_iterator 	: Int;
	
	/**
	 * Updates all animations.
	 */
	static private function Update():Void
	{
		if (m_list.length > 0)
		{
			var steps : Int = Std.int(Math.max((m_list.length / 2), 1));
			for (i in 0...steps)
			{
				m_list[m_iterator].Animate();
				m_iterator = (m_iterator + 1) % m_list.length;
			}
		}
	}
	
	/**
	 * Initializes static data.
	 */
	static private function Initialize():Void
	{
		m_list = [];
		m_iterator = 0;
	}
	
	/**
	 * List of all AnimationClips.
	 */
	public var clips : Array<AnimationClip>;

	/**
	 * Current time sample.
	 */
	private var m_clock : Float32;
	
	/**
	 * Current playback time.
	 */
	public var time(get_time, set_time):Float32;
	private function get_time():Float32 { return m_time; }
	private function set_time(v:Float32):Float32 
	{
		m_time = v;
		for (i in 0...clips.length) clips[i].Sample(m_time);
		return v; 
	}
	private var m_time : Float32;
	
	/**
	 * Flag that indicates if any of the clips are playing.
	 */
	public var playing(get_playing, never):Bool;
	private function get_playing():Bool { for (i in 0...clips.length) if (clips[i].playing) return true; return false; }
	
	/**
	 * Flag that controls if the animation will play backwards.
	 */
	public var reverse : Bool;
	
	private var m_fade_elapsed  : Float32;
	
	private var m_fade_duration : Float32;
	
	private var m_fade_clip : AnimationClip;
	
	function new() 
	{
		super();
		m_list.push(this);
		clips   = [];
		m_time  = 0;
		reverse = false;
		m_clock = Time.elapsed;
		m_fade_elapsed  = 0.0;
		m_fade_duration = 0.0;
	}
	
	/**
	 * Tells if the Animation contains a given clip instance.
	 * @param	p_clip
	 * @return
	 */
	public function Contains(p_clip : AnimationClip):Bool
	{
		for (i in 0...clips.length) if (clips[i] == p_clip) return true;
		return false;
	}
	
	/**
	 * Adds a clip to the playlist.
	 * @param	p_clip
	 */
	public function Add(p_clip : AnimationClip):Void
	{
		if (Contains(p_clip)) return;
		
		clips.push(p_clip);
	}
	
	/**
	 * Removes the clip from the playlist.
	 * @param	p_clip
	 */
	public function Remove(p_clip : AnimationClip):Void
	{
		if (!Contains(p_clip)) return;
		clips.remove(p_clip);
	}
	
	/**
	 * Searches for a clip by its name.
	 * @param	p_clip_name
	 * @return
	 */
	public function Get(p_clip_name : String):AnimationClip
	{
		for (i in 0...clips.length) if (clips[i].name == p_clip_name) return clips[i];
		return null;
	}
	
	/**
	 * Fades the animation from the current clip to the informed one, starting the playback in the desired time.
	 * @param	p_clip
	 * @param	p_time
	 * @param	p_fade
	 */
	public function Fade(p_clip : AnimationClip, p_time : Float32 = 0.0, p_fade:Float32 = 0.0) : Void
	{
		Play(p_clip, p_time);
		m_fade_elapsed  = 0.0;
		m_fade_duration = p_fade;
		m_fade_clip = p_clip;
		//if (p_fade <= 0.0) return;		
	}
	
	/**
	 * Plays the informed clip starting in the desired time in seconds.
	 * @param	p_clip
	 * @param	p_time
	 */
	public function Play(p_clip : AnimationClip,p_time : Float32=0.0) : Void
	{
		if (!Contains(p_clip))
		{
			
			return;
		}
		m_time = p_time;
		p_clip.Sample(p_time);
		p_clip.playing = true;
		//Engine.Add(this);
	}
	
	/**
	 * Stops the informed clip. If null is passed, all clips are stopped.
	 * @param	p_clip
	 */
	public function Stop(p_clip : AnimationClip = null):Void
	{
		if (p_clip == null) { for (i in 0...clips.length) clips[i].playing = false; return; }
		if (!Contains(p_clip)) return;
		p_clip.playing = false;
	}
	
	/**
	 * Internal animation update.
	 */
	private function Animate():Void
	{
		var is_playing : Bool = false;	
		//transform.Lock();
		if (m_fade_elapsed >= m_fade_duration) m_fade_elapsed = m_fade_duration;
		//trace(m_fade_elapsed + " " + m_fade_duration);
		var w : Float32 = m_fade_duration <= 0.0 ? 1.0 : (m_fade_elapsed / m_fade_duration);
		
		//if ((Time.frame % 20) == 0) trace(w);
		var spd : Float32 = 1.0;
		
		for (i in 0...clips.length) 
		{
			var c : AnimationClip = clips[i];
			if (c.playing)
			{ 	
				
				c.Sample(time, w);
				spd = c.speed;
				is_playing = true; 				
			}
		}
		
		if (w >= 1.0)
		{
			m_fade_clip = null;
			m_fade_duration = m_fade_elapsed = 0.0;
		}
		
		//transform.Unlock();
		//transform.Concat();
		var dt : Float32 = Time.elapsed - m_clock;
		m_clock = Time.elapsed;
		
		if (is_playing) 
		{
			m_time += (reverse ? -dt : dt)*spd;
			m_fade_elapsed += dt;
		}
	}
}