package haxor.core;
import haxe.Timer;


/**
 * Class that holds Time information of the application.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Time
{
	/**
	 * Returns the execution time in ms.
	 */
	static public var clock(get_clock, null):Float;
	static private inline function get_clock():Float { return m_clock; }
	static private var m_clock : Float;
	
	/**
	 * Returns the delta time in seconds between frames.
	 */
	static public var delta(get_delta, null):Float;
	static inline function get_delta():Float { return m_delta; }	
	static private var m_delta : Float;
	
	/**
	 * Frames per second.
	 */
	static public var fps(get_fps, null):Int;
	static inline function get_fps():Int { return m_fps; }	
	static private var m_fps : Int;
	
	/**
	 * Updates per second.
	 */
	static public var ups(get_ups, null):Int;
	static inline function get_ups():Int { return m_ups; }	
	static private var m_ups : Int;
	
	static private var m_frames : Float;
	
	static private var m_updates : Float;
	
	static private var m_stats_clock : Float;
	
	static private var m_start_clock : Float;
	
	static private var m_last_clock : Float;
	
	/**
	 * Initializes the Time global class.
	 */
	static private function Initialize():Void
	{	
		var c:Float = Timer.stamp() * 0.001;
		
		#if html
		c = 0.0;
		#end
		
		m_clock 		= c;
		m_start_clock 	= c;
		m_last_clock    = c;		
		m_stats_clock   = c;
		m_delta 		= 0.0;
		m_ups			= 0;
		m_fps			= 0;
		m_updates		= 0.0;
		m_frames		= 0.0;
		UpdateClock();
	}
	
	static private function Update():Void
	{		
		UpdateClock();		
		m_delta = (m_clock - m_last_clock)*0.001;
		m_last_clock = m_clock;
		
		m_updates += 1.0;
		
		if ((m_clock - m_stats_clock) >= 1000.0)
		{
			m_stats_clock = m_clock;
			m_ups = cast m_updates;
			m_fps = cast m_frames;
			m_updates = 0.0;
			m_frames  = 0.0;
		}
	}
	
	static private function Render():Void
	{
		m_frames += 1.0;
	}
	
	static private function UpdateClock():Void
	{
		
		#if html		
		#else
		m_clock = (Timer.stamp() * 1000.0) - m_start_clock;
		#end
		
		
	}
	
	
}