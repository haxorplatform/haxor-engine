#ifndef INCLUDED_haxor_platform_windows_LoadTask
#define INCLUDED_haxor_platform_windows_LoadTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,platform,windows,LoadTask)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  LoadTask_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LoadTask_obj OBJ_;
		LoadTask_obj();
		Void __construct(::String p_url,::String p_method,::String p_data,Dynamic p_ondata,Dynamic p_onerror);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LoadTask_obj > __new(::String p_url,::String p_method,::String p_data,Dynamic p_ondata,Dynamic p_onerror);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LoadTask_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LoadTask"); }

		::String url;
		::String method;
		::String data;
		Dynamic ondata;
		Dynamic &ondata_dyn() { return ondata;}
		Dynamic onerror;
		Dynamic &onerror_dyn() { return onerror;}
		virtual Void Run( );
		Dynamic Run_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_LoadTask */ 
