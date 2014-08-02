/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import haxe.Timer;
import js.Browser;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Time
{
	static var m_clock : Float;
	
	static var m_timeScaleMap : Map<String,Float>;
	
	static var m_benchclock : Float;
	
	
	
	/**
	 * 
	 */
	static public var elapsed(get_elapsed, never) : Float;
	static var m_elapsed : Float;
	static function get_elapsed(): Float { return m_elapsed; }
	
	/**
	 * 
	 */
	static public var scale : Float = 1.0;
	
	/**
	 * 
	 */
	static public var frame : Int;
	
	/**
	 * 
	 */
	static public var fps : Int;
	
	
	static var m_fpsElapsed:Float;
	static var m_fpsCounter:Int;
	
	/**
	 * 
	 */
	static public var frameDeltaTime(get_frameDeltaTime, never) : Float;
	static var m_frameDeltaTime : Float;	
	static function get_frameDeltaTime(): Float { return m_frameDeltaTime; }
	
	/**
	 * 
	 */
	static public var deltaTime(get_deltaTime, never) : Float;
	static function get_deltaTime(): Float { return m_frameDeltaTime * scale; }
	
	/**
	 * 
	 */
	static private var m_simulationTimeSlice : Float;	
	
	
	
	
	/**
	 * 
	 */
	static public var fixedDeltaTime(get_fixedDeltaTime, set_fixedDeltaTime) : Float;
	static var m_fixedDeltaTime : Float;
	static function get_fixedDeltaTime(): Float { return m_fixedDeltaTime; }
	static function set_fixedDeltaTime(v:Float): Float { m_fixedDeltaTime = v; return v; }

	static public var ms(get_ms, never):Float;
	static private function get_ms():Float	 
	{
		return m_ms_func() * m_ms_convert;
	}
	
	static private var m_ms_convert : Float;
	
	static private var m_ms_func : Dynamic;
	
	static function Initialize():Void
	{		
		scale = 1;		
		m_frameDeltaTime = 0;
		m_elapsed = 0;
		frame = 0;
		fps = 0;
		m_fpsCounter = 0;
		m_fpsElapsed = 0;
		m_simulationTimeSlice = 0;
		m_clock = -1;
		m_fixedDeltaTime = 1.0 / 100.0;
		m_timeScaleMap = new Map<String,Float>();
		if (Browser.window.performance.now != null)
		{
			m_ms_convert = 1.0;
			m_ms_func = Browser.window.performance.now; 
		}
		else
		{
			m_ms_func = Timer.stamp;
			m_ms_convert = 0.001;
			
		}
	}
	
	/**
	 * 
	 * @param	p_alias
	 * @return
	 */
	static public function GetTimeScale(p_alias : String):Float
	{
		if (!m_timeScaleMap.exists(p_alias))
		{
			m_timeScaleMap.set(p_alias, 1);
		}
		return m_frameDeltaTime * m_timeScaleMap.get(p_alias) * scale;
	}
	
	/**
	 * 
	 * @param	p_alias
	 * @param	p_scale
	 */
	static public function SetTimeScale(p_alias : String,p_scale : Float):Void
	{
		m_timeScaleMap.set(p_alias, p_scale);
	}
	
	/**
	 * 
	 */
	static function Update():Void 
	{
		if (m_clock < 0)
		{
			m_clock = ms;
		}
		
		
		var dt:Float = (ms - m_clock) * 0.001;
		
		if (dt >= 0.1) dt = 0.1;
		
		m_clock = ms;
		m_elapsed += dt;
		m_frameDeltaTime = dt;				
		m_simulationTimeSlice += dt * scale;
		m_fpsElapsed += dt;
		m_fpsCounter++;
		if (m_fpsElapsed >= 0.5)
		{
			m_fpsElapsed -= 0.5;			
			fps = m_fpsCounter * 2;
			m_fpsCounter=0;
		}
	}
	
	
	
	
	
}