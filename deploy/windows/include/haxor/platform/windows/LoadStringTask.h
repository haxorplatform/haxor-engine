#ifndef INCLUDED_haxor_platform_windows_LoadStringTask
#define INCLUDED_haxor_platform_windows_LoadStringTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/windows/LoadTask.h>
HX_DECLARE_CLASS3(haxor,platform,windows,LoadStringTask)
HX_DECLARE_CLASS3(haxor,platform,windows,LoadTask)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  LoadStringTask_obj : public ::haxor::platform::windows::LoadTask_obj{
	public:
		typedef ::haxor::platform::windows::LoadTask_obj super;
		typedef LoadStringTask_obj OBJ_;
		LoadStringTask_obj();
		Void __construct(::String p_url,::String p_method,::String p_data,Dynamic p_callback);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LoadStringTask_obj > __new(::String p_url,::String p_method,::String p_data,Dynamic p_callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LoadStringTask_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LoadStringTask"); }

		Dynamic callback;
		Dynamic &callback_dyn() { return callback;}
		virtual Void OnData( ::String p_data);

		virtual Void OnError( ::String p_message);
		Dynamic OnError_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_LoadStringTask */ 
