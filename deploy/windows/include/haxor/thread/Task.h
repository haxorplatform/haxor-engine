#ifndef INCLUDED_haxor_thread_Task
#define INCLUDED_haxor_thread_Task

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/thread/Activity.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace thread{


class HXCPP_CLASS_ATTRIBUTES  Task_obj : public ::haxor::thread::Activity_obj{
	public:
		typedef ::haxor::thread::Activity_obj super;
		typedef Task_obj OBJ_;
		Task_obj();
		Void __construct(hx::Null< bool >  __o_p_threaded,Dynamic p_callback);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Task_obj > __new(hx::Null< bool >  __o_p_threaded,Dynamic p_callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Task_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Task"); }

		virtual Float get_progress( );
		Dynamic get_progress_dyn();

		virtual Float set_progress( Float v);
		Dynamic set_progress_dyn();

		Float m_progress;
		bool m_has_progress;
		bool active;
		virtual bool get_active( );
		Dynamic get_active_dyn();

		bool m_active;
		virtual Void OnStart( );
		Dynamic OnStart_dyn();

		virtual Void OnStep( );
		Dynamic OnStep_dyn();

		virtual Void OnComplete( );
		Dynamic OnComplete_dyn();

		virtual Void OnProgress( );
		Dynamic OnProgress_dyn();

		virtual bool OnExecute( Float p_time);
		Dynamic OnExecute_dyn();

};

} // end namespace haxor
} // end namespace thread

#endif /* INCLUDED_haxor_thread_Task */ 
