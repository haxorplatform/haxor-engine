package haxor.core;
import haxe.Timer;
import haxor.platform.Types.Float32;

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
	 * Samples the system time using the offered API in 'ms'.
	 */
	static public var system(get_system, null):Float32;
	static private inline function get_system():Float32
	{ 	
		#if html
		return m_system - m_clock_0; 
		#end
		
		#if android
		var t : Float32 = cast System.nanoTime();
		return m_system = (t * 0.000001) - m_clock_0;		
		#end
		
		#if (windows || osx || linux)		
		return m_system = (Timer.stamp() * 1000.0) - m_clock_0;
		#end
		
	}
	static private var m_system : Float32;
	
	/**
	 * Returns the execution time in ms.
	 */
	static public var clock(get_clock, null):Float32;
	static private inline function get_clock():Float32{ return m_clock; }
	static private var m_clock : Float32;
	static private var m_clock_dt : Float32;
	static private var m_clock_0 : Float32;
	
	/**
	 * Returns the delta time in seconds between frames.
	 */
	static public var delta(get_delta, null):Float32;
	static inline function get_delta():Float32{ return m_delta; }	
	static private var m_delta : Float32;
	
	/**
	 * Returns the last frame delta time. This attribute is useful to update time based things on the render loop.
	 */
	static public var frameDelta(get_frameDelta, null):Float32;
	static inline function get_frameDelta():Float32{ return m_frame_delta; }
	static private var m_frame_delta : Float32;
	
	/**
	 * Get or Set the fixed timestep for physics iterations.
	 */
	static public var fixedDelta(get_fixedDelta, set_fixedDelta) : Float32;	
	static function get_fixedDelta(): Float32 { return m_fixedDelta; }
	static function set_fixedDelta(v:Float32): Float32 { m_fixedDelta = v; return v; }
	static var m_fixedDelta : Float32;
	
	/**
	 * Returns the elapsed time in seconds.
	 */
	static public var elapsed(get_elapsed, null):Float32;
	static inline function get_elapsed():Float32{ return m_elapsed; }	
	static private var m_elapsed : Float32;
	
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
	static private var m_frame_count : Float32;
	
	static private var m_updates : Float32;
	
	static private var m_stats_clock : Float32;
	
	static private var m_start_clock : Float32;
	
	static private var m_last_clock : Float32;
	
	static private var m_last_frame_clock : Float32;
	
	
	
	/**
	 * Initializes the Time global class.
	 */
	static private function Initialize():Void
	{	
		m_system		= 0.0;
		m_clock_0		= 0.0;
		m_clock_0		= system;
		
		m_clock 		= system;
		m_clock_dt		= 0.0;
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
		m_fixedDelta    = 1.0 / 100.0;
	}
	
	static private function Update():Void
	{		
		m_clock			= system;
		m_clock_dt		= (m_clock - m_last_clock);
		if (m_clock_dt <= 0) m_clock_dt = 1.0;
		m_last_clock 	= m_clock;
		m_delta 		= m_clock_dt * 0.001;
		m_delta = m_delta > 0.1 ? 0.1 : (m_delta <= 0.0 ? 0.01 : m_delta);
		
		m_elapsed		+= m_delta;
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
		m_frame_delta = m_frame_delta > 0.1 ? 0.1 : (m_frame_delta <= 0.0 ? 0.01 : m_frame_delta);
		if(m_clock > m_last_frame_clock) m_last_frame_clock = m_clock;
	}
	
	
	
	
}