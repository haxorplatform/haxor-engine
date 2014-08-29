package haxor.core;
import haxe.Timer;

#if android
import haxe.Int64;
import java.lang.System;
#end

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
	static private var m_clock_dt : Float;
	static private var m_clock_0 : Float;
	
	/**
	 * Returns the delta time in seconds between frames.
	 */
	static public var delta(get_delta, null):Float;
	static inline function get_delta():Float { return m_delta; }	
	static private var m_delta : Float;
	
	/**
	 * Returns the last frame delta time. This attribute is useful to update time based things on the render loop.
	 */
	static public var framedelta(get_framedelta, null):Float;
	static inline function get_framedelta():Float { return m_frame_delta; }
	static private var m_frame_delta : Float;
	
	/**
	 * Returns the elapsed time in seconds.
	 */
	static public var elapsed(get_elapsed, null):Float;
	static inline function get_elapsed():Float { return m_elapsed; }	
	static private var m_elapsed : Float;
	
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
	
	/**
	 * Rendered frame count.
	 */
	static public var frame(get_frame, null):Int;
	static inline function get_frame():Int { return m_frame; }
	static private var m_frame : Int;
	static private var m_frame_count : Float;
	
	static private var m_updates : Float;
	
	static private var m_stats_clock : Float;
	
	static private var m_start_clock : Float;
	
	static private var m_last_clock : Float;
	
	static private var m_last_frame_clock : Float;
	
	
	
	/**
	 * Initializes the Time global class.
	 */
	static private function Initialize():Void
	{	
		m_clock 		= 0.0;
		m_clock_dt		= 0.0;
		m_clock_0		= 0.0;
		UpdateClock();
		m_clock_0		= m_clock;
		UpdateClock();
		
		m_start_clock 	= m_clock;
		m_last_clock    = m_clock;	
		m_last_frame_clock = m_clock;
		m_stats_clock   = m_clock;
		m_elapsed		= 0.0;
		m_delta 		= 0.0;
		m_frame_delta   = 0.0;
		m_ups			= 0;
		m_fps			= 0;
		m_updates		= 0.0;
		m_frame_count	= 0.0;
		m_frame			= 0;
		UpdateClock();
	}
	
	static private function Update():Void
	{		
		UpdateClock();	
		m_clock_dt		= (m_clock - m_last_clock);
		if (m_clock_dt <= 0) m_clock_dt = 1.0;
		m_last_clock 	= m_clock;
		m_delta 		= m_clock_dt * 0.001;		
		
		m_elapsed		= m_clock*0.001;
		m_updates 		+= 1.0;
		
		if ((m_clock - m_stats_clock) >= 1000.0)
		{
			m_stats_clock += (m_clock - m_stats_clock);
			m_ups = cast m_updates;
			m_fps = cast m_frame_count;
			m_updates = 0.0;
			m_frame_count  = 0.0;
			Console.Log("FPS: " + m_fps, 7);
		}
	}
	
	/**
	 * Render callback to sample rendering based timing.
	 */
	static private function Render():Void
	{
		m_frame_count += 1.0;
		m_frame++;
		m_frame_delta = (m_clock - m_last_frame_clock) * 0.001;
		m_last_frame_clock = m_clock;
	}
	
	/**
	 * Updates the internal 'ms' clock. In the HTML platform the 'time' argumento of RequestAnimationFrame is used.
	 */
	static private inline function UpdateClock():Void
	{
		#if html
		#end
		
		#if android
		var t : Float = cast System.nanoTime();
		m_clock = (t * 0.000001)-m_clock_0;		
		#end
		
		#if (windows || osx || linux)		
		m_clock = (Timer.stamp() * 1000.0) - m_clock_0;
		#end
	}
	
	
}