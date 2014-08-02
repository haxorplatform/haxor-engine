package haxor.media;

import js.html.Audio;
import js.html.AudioElement;
import js.html.Event;
import js.html.MediaElement;
import haxor.core.Resource;
import haxor.math.Mathf;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Sound extends Resource
{
	static public var main(get_main, set_main) : Float;
	static private var m_main : Float;
	static private function get_main():Float { return m_main; }
	static private function set_main(v:Float):Float 
	{
		m_main = v; 
		if(m_list != null)
		for (i in 0...m_list.length)
		{
			m_list[i].UpdateVolume();
		}
		return m_main; 
	}

	static private var m_list : Array<Sound>;
	
	public var volume(get_volume, set_volume) : Float;
	private var m_volume : Float;
	private function get_volume():Float { return m_volume; }
	private function set_volume(v:Float):Float 
	{	
		m_volume = v; 
		UpdateVolume();
		return v; 
	}
	
	
	public var time(get_time, set_time) : Float;
	private function get_time():Float { return m_clip == null ? 0.0 : m_clip.currentTime; }
	private function set_time(v:Float):Float {	return m_clip==null ? 0.0 : (m_clip.currentTime = Mathf.Max([v, m_clip.startTime])); }
	
	public var loop(get_loop, set_loop) : Bool;
	private function get_loop():Bool { return m_loop; }
	private function set_loop(v:Bool):Bool 
	{
		m_loop = v;
		return 
		//m_clip.loop =
		v; 		
	}
	private var m_loop : Bool;
	
	public var repeat : Int;
	
	private var m_repeat_count : Int;
	
	public var clip(get_clip,null) : MediaElement;
	private function get_clip():MediaElement { return m_clip; }
	private var m_clip  : MediaElement;
	

	public function new(p_clip : MediaElement) 
	{		
		super();
		if (m_list == null) m_list = [];
		m_clip 	 = p_clip;
		if (m_clip != null)
		{
			name 	 = m_clip.id;
			m_volume = m_clip.volume;
			m_loop   = m_clip.loop;		
			m_clip.addEventListener("ended", OnSoundEnd);
			m_clip.addEventListener("timeupdate", OnSoundUpdate);	
			m_clip.loop = false;
		}
		repeat = 0;
		m_repeat_count = 0;
		m_list.push(this);
	}
	
	public function Play(p_time : Float=0.0):Void
	{		
		if (m_clip == null) return;
		time = p_time;
		m_clip.play();		
		UpdateVolume();
	}
	
	public function Pause():Void 
	{
		if (m_clip == null) return;
		if (m_clip.paused) { m_clip.play(); } else m_clip.pause();
	}
	
	public function Stop():Void
	{
		if (m_clip == null) return;
		time = 0.0;
		m_repeat_count = 0;
		m_clip.pause();		
	}
	
	private function UpdateVolume():Void
	{
		if (m_clip == null) return;
		m_clip.volume = m_volume * m_main;
	}
	
	private function OnSoundEnd(e : Event):Void
	{
		//trace("ended");
		//Play();
	}
	
	private function OnSoundUpdate(e : Event):Void
	{
		
		if(m_loop)
		if ((m_clip.duration - m_clip.currentTime) <= 0.1)
		{
			if (repeat > 0)
			{
				m_repeat_count++;
				if (m_repeat_count <= repeat)
				{
					trace(m_repeat_count);
					Play();
				}
				else
				{
					m_repeat_count = 0;
					Stop();
				}
			}
			else
			{
				Play();
			}
		}		
		//*/
		//trace(m_clip.currentTime + " " + m_clip.duration + " " + m_clip.initialTime + " " + m_clip.startTime);
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		Stop();
		if (m_clip != null)
		{
			m_clip.parentElement.removeChild(m_clip);
			m_clip = null;
		}
	}
}