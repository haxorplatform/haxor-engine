#ifndef INCLUDED_haxor_thread_Activity
#define INCLUDED_haxor_thread_Activity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
#include <haxor/core/IUpdateable.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,thread,Activity)
namespace haxor{
namespace thread{


class HXCPP_CLASS_ATTRIBUTES  Activity_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Activity_obj OBJ_;
		Activity_obj();
		Void __construct(Dynamic p_callback,hx::Null< bool >  __o_p_threaded);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Activity_obj > __new(Dynamic p_callback,hx::Null< bool >  __o_p_threaded);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Activity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::core::IUpdateable_obj *()
			{ return new ::haxor::core::IUpdateable_delegate_< Activity_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Activity"); }

		Dynamic m_callback;
		Dynamic &m_callback_dyn() { return m_callback;}
		Float m_time_start;
		Float elapsed;
		virtual Float get_elapsed( );
		Dynamic get_elapsed_dyn();

		Float m_elapsed;
		bool m_cancelled;
		virtual Void Cancel( );
		Dynamic Cancel_dyn();

		virtual Void OnUpdate( );
		Dynamic OnUpdate_dyn();

		static ::haxor::thread::Activity Iterate( int p_offset,int p_length,Dynamic p_callback,hx::Null< int >  p_step,hx::Null< bool >  p_threaded);
		static Dynamic Iterate_dyn();

		static ::haxor::thread::Activity Delay( Float p_time,Dynamic p_callback,hx::Null< bool >  p_threaded);
		static Dynamic Delay_dyn();

		static ::haxor::thread::Activity Run( Dynamic p_callback,hx::Null< bool >  p_threaded);
		static Dynamic Run_dyn();

};

} // end namespace haxor
} // end namespace thread

#endif /* INCLUDED_haxor_thread_Activity */ 
