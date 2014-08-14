package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Time extends haxe.lang.HxObject
{
	public    Time(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Time()
	{
		haxor.core.Time.__hx_ctor_haxor_core_Time(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_Time(haxor.core.Time __temp_me21745)
	{
		{
		}
		
	}
	
	
	public static  double clock;
	
	public static   double get_clock()
	{
		return haxor.core.Time.m_clock;
	}
	
	
	public static  double m_clock;
	
	public static  double delta;
	
	public static   double get_delta()
	{
		return haxor.core.Time.m_delta;
	}
	
	
	public static  double m_delta;
	
	public static  double elapsed;
	
	public static   double get_elapsed()
	{
		return haxor.core.Time.m_elapsed;
	}
	
	
	public static  double m_elapsed;
	
	public static  int fps;
	
	public static   int get_fps()
	{
		return haxor.core.Time.m_fps;
	}
	
	
	public static  int m_fps;
	
	public static  int ups;
	
	public static   int get_ups()
	{
		return haxor.core.Time.m_ups;
	}
	
	
	public static  int m_ups;
	
	public static  int frame;
	
	public static   int get_frame()
	{
		return haxor.core.Time.m_frame;
	}
	
	
	public static  int m_frame;
	
	public static  double m_frame_count;
	
	public static  double m_updates;
	
	public static  double m_stats_clock;
	
	public static  double m_start_clock;
	
	public static  double m_last_clock;
	
	public static  double m_last_frame_clock;
	
	public static  double m_frame_delta;
	
	public static   void Initialize()
	{
		double c = ( haxe.Timer.stamp() * 0.001 );
		haxor.core.Time.m_clock = c;
		haxor.core.Time.m_start_clock = c;
		haxor.core.Time.m_last_clock = c;
		haxor.core.Time.m_last_frame_clock = c;
		haxor.core.Time.m_stats_clock = c;
		haxor.core.Time.m_elapsed = ( c * 1000.0 );
		haxor.core.Time.m_delta = 0.0;
		haxor.core.Time.m_frame_delta = 0.0;
		haxor.core.Time.m_ups = 0;
		haxor.core.Time.m_fps = 0;
		haxor.core.Time.m_updates = 0.0;
		haxor.core.Time.m_frame_count = 0.0;
		haxor.core.Time.m_frame = 0;
		haxor.core.Time.m_clock = ( ( haxe.Timer.stamp() * 1000.0 ) - haxor.core.Time.m_start_clock );
	}
	
	
	public static   void Update()
	{
		haxor.core.Time.m_clock = ( ( haxe.Timer.stamp() * 1000.0 ) - haxor.core.Time.m_start_clock );
		haxor.core.Time.m_delta = ( (( haxor.core.Time.m_clock - haxor.core.Time.m_last_clock )) * 0.001 );
		haxor.core.Time.m_last_clock = haxor.core.Time.m_clock;
		haxor.core.Time.m_elapsed = ( haxor.core.Time.m_clock * 0.001 );
		haxor.core.Time.m_updates += 1.0;
		if (( ( haxor.core.Time.m_clock - haxor.core.Time.m_stats_clock ) >= 1000.0 )) 
		{
			haxor.core.Time.m_stats_clock = haxor.core.Time.m_clock;
			haxor.core.Time.m_ups = ((int) (haxor.core.Time.m_updates) );
			haxor.core.Time.m_fps = ((int) (haxor.core.Time.m_frame_count) );
			haxor.core.Time.m_updates = 0.0;
			haxor.core.Time.m_frame_count = 0.0;
		}
		
	}
	
	
	public static   void Render()
	{
		haxor.core.Time.m_frame_count += 1.0;
		haxor.core.Time.m_frame++;
		haxor.core.Time.m_frame_delta = ( (( haxor.core.Time.m_clock - haxor.core.Time.m_last_frame_clock )) * 0.001 );
		haxor.core.Time.m_last_frame_clock = haxor.core.Time.m_clock;
	}
	
	
	public static   void UpdateClock()
	{
		haxor.core.Time.m_clock = ( ( haxe.Timer.stamp() * 1000.0 ) - haxor.core.Time.m_start_clock );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Time(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Time();
	}
	
	
}


