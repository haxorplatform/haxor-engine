/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.component;
import haxor.core.Console;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.ILateUpdateable;
import haxor.core.IUpdateable;
import haxor.core.Time;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

@:allow(haxor)
class Animation extends Behaviour// implements ILateUpdateable
{
	static var m_list : Array<Animation>;
	
	static var m_iterator : Int;
	
	static public function Update():Void
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
	
	static public function Initialize():Void
	{
		m_list = [];
		m_iterator = 0;
	}
	
	public var clips : Array<AnimationClip>;

	private var m_clock : Float;
	
	public var time(get_time, set_time):Float;
	private function get_time():Float { return m_time; }
	private function set_time(v:Float):Float 
	{
		m_time = v;
		for (i in 0...clips.length) clips[i].Sample(m_time);
		return v; 
	}
	private var m_time : Float;
	
	public var playing(get_playing, never):Bool;
	private function get_playing():Bool { for (i in 0...clips.length) if (clips[i].playing) return true; return false; }
	
	public var reverse : Bool;
	
	private var m_fade_elapsed  : Float;
	
	private var m_fade_duration : Float;
	
	private var m_fade_clip : AnimationClip;
	
	function new(p_entity:Entity) 
	{
		super(p_entity);		
		m_list.push(this);
		clips   = [];
		m_time  = 0;
		reverse = false;
		m_clock = Time.elapsed;
		m_fade_elapsed  = 0.0;
		m_fade_duration = 0.0;
	}
	
	public function Contains(p_clip : AnimationClip):Bool
	{
		for (i in 0...clips.length) if (clips[i] == p_clip) return true;
		return false;
	}
	
	public function Add(p_clip : AnimationClip):Void
	{
		if (Contains(p_clip)) return;
		
		clips.push(p_clip);
	}
	
	public function Remove(p_clip : AnimationClip):Void
	{
		if (!Contains(p_clip)) return;
		clips.remove(p_clip);
	}
	
	public function Get(p_clip_name : String):AnimationClip
	{
		for (i in 0...clips.length) if (clips[i].name == p_clip_name) return clips[i];
		return null;
	}
	
	public function Fade(p_clip : AnimationClip, p_time : Float = 0.0, p_fade:Float = 0.0) : Void
	{
		Play(p_clip, p_time);
		m_fade_elapsed  = 0.0;
		m_fade_duration = p_fade;
		m_fade_clip = p_clip;
		//if (p_fade <= 0.0) return;		
	}
	
	public function Play(p_clip : AnimationClip,p_time : Float=0.0) : Void
	{
		if (!Contains(p_clip)) return;
		m_time = p_time;
		p_clip.Sample(p_time);
		p_clip.playing = true;
		//Engine.Add(this);
	}
	
	public function Stop(p_clip : AnimationClip = null):Void
	{
		if (p_clip == null) { for (i in 0...clips.length) clips[i].playing = false; return; }
		if (!Contains(p_clip)) return;
		p_clip.playing = false;
	}
	
	private function Animate():Void
	{
		var is_playing : Bool = false;	
		transform.Lock();
		if (m_fade_elapsed >= m_fade_duration) m_fade_elapsed = m_fade_duration;
		//trace(m_fade_elapsed + " " + m_fade_duration);
		var w : Float = m_fade_duration <= 0.0 ? 1.0 : (m_fade_elapsed / m_fade_duration);
		//if ((Time.frame % 20) == 0) trace(w);
		var spd : Float = 1.0;
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
		
		transform.Unlock();
		transform.Concat();
		var dt : Float = Time.elapsed - m_clock;
		m_clock = Time.elapsed;
		if (is_playing) 
		{
			m_time += (reverse ? -dt : dt)*spd;
			m_fade_elapsed += dt;
		}
	}
}