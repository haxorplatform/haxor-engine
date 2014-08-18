#ifndef INCLUDED_haxor_core_Time
#define INCLUDED_haxor_core_Time

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,Time)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Time_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Time_obj OBJ_;
		Time_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Time_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Time_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Time"); }

		static Float clock;
		static Float get_clock( );
		static Dynamic get_clock_dyn();

		static Float m_clock;
		static Float m_clock_dt;
		static Float m_clock_0;
		static Float delta;
		static Float get_delta( );
		static Dynamic get_delta_dyn();

		static Float m_delta;
		static Float elapsed;
		static Float get_elapsed( );
		static Dynamic get_elapsed_dyn();

		static Float m_elapsed;
		static int fps;
		static int get_fps( );
		static Dynamic get_fps_dyn();

		static int m_fps;
		static int ups;
		static int get_ups( );
		static Dynamic get_ups_dyn();

		static int m_ups;
		static int frame;
		static int get_frame( );
		static Dynamic get_frame_dyn();

		static int m_frame;
		static Float m_frame_count;
		static Float m_updates;
		static Float m_stats_clock;
		static Float m_start_clock;
		static Float m_last_clock;
		static Float m_last_frame_clock;
		static Float m_frame_delta;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void Update( );
		static Dynamic Update_dyn();

		static Void Render( );
		static Dynamic Render_dyn();

		static Void UpdateClock( );
		static Dynamic UpdateClock_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Time */ 
