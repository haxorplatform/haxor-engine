package haxor.thread;

#if windows
import cpp.vm.Thread;
#end

#if android
import java.lang.Runnable;
import java.lang.Thread;
#end

import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.Time;

/**
 * Class that describes an operation to be run in the execution pool.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Activity extends Resource implements IUpdateable implements IRenderable
#if java
implements Runnable
#end

{
	
	/**
	 * Iterates a given Int range and calls the method so the user can handle the operation at the given index.
	 * @param	p_offset
	 * @param	p_length
	 * @param	p_callback
	 * @param	p_threaded
	 * @return
	 */
	static public function Iterate(p_offset : Int, p_length : Int,p_callback : Int->Bool,p_step :Int=1, p_threaded : Bool = false,p_graphics_context:Bool=false):Activity
	{
		var it : Int = p_offset;
		return new Activity(function(t : Float):Bool
		{
			var finished : Bool = false;
			for (i in 0...p_step)
			{
				if (!p_callback(it)) { finished = true; break; }
				it++;
				if (it >= p_length) return false;
			}
			return !finished;		
		},p_threaded,p_graphics_context);
	}
	
	/**
	 * Executes the operation waiting the informed delay in seconds.
	 * @param	p_time
	 * @param	p_callback
	 * @return
	 */
	static public function Delay(p_time : Float, p_callback : Void->Void, p_threaded:Bool=false,p_graphics_context: Bool=false):Activity
	{
		return new Activity(function(t : Float):Bool
		{
			if (t >= p_time)
			{
				p_callback();
				return false;
			}
			return true;
		},p_threaded,p_graphics_context);
	}
	
	/**
	 * Starts a new activity with the informed callback.
	 * @param	p_callback
	 * @return
	 */
	static public function Run(p_callback : Float->Bool,p_threaded : Bool=false,p_graphics_context:Bool=false):Activity
	{
		return new Activity(p_callback,p_threaded,p_graphics_context);
	}
	
	/**
	 * Starts a new Activity and runs the informed callback just once.
	 * @param	p_callback
	 * @param	p_threaded
	 * @param	p_graphics_context
	 * @return
	 */
	static public function RunOnce(p_callback : Void->Void, p_threaded : Bool = false, p_graphics_context:Bool = false):Activity
	{
		return new Activity(function(t : Float):Bool
		{
			p_callback();
			return false;
		},p_threaded,p_graphics_context);
	}
	
	/**
	 * Reference to its callback for external handling.
	 */
	private var m_callback : Float->Bool;

	/**
	 * Starting time of this activity.
	 */
	private var m_time_start : Float;
	
	/**
	 * Elapsed time of execution.
	 */
	public var elapsed(get_elapsed, null):Float;
	private inline function get_elapsed():Float { return m_elapsed; }
	private var m_elapsed : Float;
	
	/**
	 * Flag that stops the execution if necessary.
	 */
	private var m_cancelled:Bool;
	
	/**
	 * Creates a new activity handled by the informed callback.
	 */
	public function new(p_callback : Float->Bool, p_threaded : Bool = false, p_graphics_context:Bool = false) :Void
	{
		super();
		if (p_callback == null) { return; }
		m_time_start = Time.elapsed;
		m_elapsed	 = 0.0;
		m_callback   = p_callback;
		m_cancelled = false;
		#if html
		p_threaded = false;
		#end
		
		if (p_graphics_context) p_threaded = false;
		
		if (!p_threaded)
		{
			if (p_graphics_context)
			{
				EngineContext.render.Add(this);
			}
			else
			{
				EngineContext.update.Add(this);
			}
		}
		else
		{
			#if windows
			Thread.create(function():Void
			{
				while (true)
				{		
					if (m_cancelled) break;
					if (!p_callback(m_elapsed)) break;
					m_elapsed += 0.0001;
					Sys.sleep(0.0001);
				}
			});
			#end
			
			#if android
			var thread : Thread = new Thread(this);
			thread.start();
			#end
		}
	}
	
	/**
	 * Method that prevents the Activity to keep running.
	 */
	public function Cancel():Void
	{
		m_cancelled = true;
	}
	
	/**
	 * Execution loop for update based activities.
	 */
	public function OnUpdate():Void { OnRun(); }
	
	/**
	 * Execution loop for render based activities (when graphics context is needed.
	 */
	public function OnRender():Void { OnRun(); }
	
	/**
	 * Main execution loop.
	 */
	private function OnRun():Void
	{
		if (m_cancelled) { Resource.Destroy(this); return; }
		m_elapsed = Time.elapsed - m_time_start;
		if (!m_callback(m_elapsed))
		{
			Resource.Destroy(this);
		}
	}
	
	#if java
	@overload
	@:noCompletion
	public function run():Void
	{
		while (true)
		{			
			if (m_cancelled) { break; }
			if (!m_callback(m_elapsed)) break;
			m_elapsed += 0.0001;
			Sys.sleep(0.0001);
		}
		Resource.Destroy(this);
	}
	#end
		
}