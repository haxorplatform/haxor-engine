package haxor.component.animation;
import haxor.core.Enums.AnimationWrap;
import haxor.core.Resource;
import haxor.math.Mathf;
import haxor.platform.Types.Float32;

/**
 * Class that describes the animation of a instance's properties.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AnimationClip extends Resource
{
	
	/**
	 * Clip track of a given property.
	 */
	public var tracks : Array<ClipTrack>;
	
	/**
	 * Playback speed of this clip.
	 */
	public var speed : Float32;
	
	/**
	 * Flag that indicates if this clip is playing.
	 */
	public var playing : Bool;
	
	/**
	 * Frame wrapping of this clip.
	 */
	public var wrap : Int;
	
	/**
	 * Length in seconds of this clip.
	 */
	public var length(get_length, never):Float32;
	private function get_length():Float32 { return m_length; }
	private var m_length : Float32;
	
	private var m_events 	 : Array<AnimationEvent>;	
	private var m_last_frame : Int;
	
	/**
	 * Creates a new AnimationClip.
	 */
	public function new() 
	{
		super();
		tracks   = [];
		speed    = 1.0;
		playing  = false;
		m_length = 0;
		wrap     = AnimationWrap.Clamp;
		m_events = [];
		m_last_frame = 0;
		
	}
	
	/**
	 * Adds an animation event that will be called 'repeat' times everytime the playhead hits the desired frame.
	 * @param	p_frame
	 * @param	p_listener
	 * @param	p_repeat
	 * @param	p_args
	 */
	public function AddEvent(p_frame : Int, p_listener : AnimationEvent -> Void,p_repeat:Int=0, p_args : Array<Dynamic> = null):Void
	{
		var e : AnimationEvent = new AnimationEvent(p_frame, p_listener, p_repeat, p_args);
		m_events.push(e);
		m_events.sort(function(a : AnimationEvent, b : AnimationEvent):Int
		{
			return a.frame < b.frame ? -1 : 1;
		});
	}
	
	/**
	 * Unregister the animation event in a given frame. If '-1' is informed, all events are removed.
	 * @param	p_frame
	 */
	public function RemoveEvent(p_frame:Int=-1):Void
	{
		var i : Int = 0;
		while(i < m_events.length)
		{			
			if ((m_events[i].frame == p_frame) || (p_frame < 0)) m_events.remove(m_events[i--]);
			i++;
		}
	}
	
	/**
	 * Creates a new track that will affects the target's property.
	 * @param	p_target
	 * @param	p_property
	 * @return
	 */
	public function Add(p_target : Dynamic, p_property : String) : ClipTrack
	{
		var ct : ClipTrack = new ClipTrack();
		ct.target 	= p_target;
		ct.property = p_property;
		tracks.push(ct);
		UpdateLength();
		return ct;
	}
	
	/**
	 * Removes the property from the track list. If the informed property name is an empty string, all tracks are removed.
	 * @param	p_target
	 * @param	p_property
	 */
	public function Remove(p_target : Dynamic, p_property:String = ""):Void
	{
		for (i in 0...tracks.length)
		{
			if (tracks[i].target == p_target)
			{
				if (p_property == "") 			{ tracks.remove(tracks[i]); }
				else
				if (p_property == p_property) 	{ tracks.remove(tracks[i]); }
			}
		}
		UpdateLength();
	}
	
	/**
	 * Applies the track animation in a given time. 
	 * @param	p_time
	 * @param	p_weight
	 */
	public function Sample(p_time : Float,p_weight:Float=1.0):Void
	{		
		if (!playing) return;	
		
		var spd : Float32 = Mathf.Max(0, speed);
		var t : Float32 = p_time;// * spd;
		switch(wrap)
		{
			case AnimationWrap.Clamp: 	 t = Mathf.Min(Mathf.Max(t,0), length);
			case AnimationWrap.Loop:  	 t = Mathf.Loop(t, 0, length);
			case AnimationWrap.Oscilate: t = Mathf.Oscilate(t, 0, length);
		}
		
		var frame : Int = -1;		
		for (i in 0...tracks.length)
		{
			frame = tracks[i].Sample(t,p_weight);
		}
		
		if (frame >= 0)
		{
			var i : Int = 0;
			if (m_last_frame != frame)
			{
				while(i < m_events.length)
				{
					var ev : AnimationEvent = m_events[i];
					var ef : Int = ev.frame;
					if (ef >= m_last_frame)
					if (ef <= frame)
					{
						if (!ev.Dispatch()) 
						{
							m_events.remove(ev); i--; 
						}
					}
					i++;
				}			
				m_last_frame = frame;
			}
		}
		
	}
	
	/**
	 * Creates a new AnimationClip using a section of the current timeline.
	 * @param	p_start
	 * @param	p_end
	 * @return
	 */
	public function Split(p_start : Int, p_end : Int):AnimationClip
	{
		var nc : AnimationClip = new AnimationClip();
		nc.speed 	= speed;
		nc.wrap  	= wrap;
		nc.playing  = playing;
		
		for (i in 0...tracks.length)
		{
			var ct : ClipTrack = tracks[i];
			var nct : ClipTrack = ct.Split(p_start, p_end);
			nc.tracks.push(nct);
		}
		nc.UpdateLength();		
		return nc;
	}
	
	private function UpdateLength():Void
	{
		m_length = 0;		
		for (i in 0...tracks.length) m_length = Math.max(tracks[i].length, m_length);
	}
	
}



