#ifndef INCLUDED_haxor_platform_windows_LoadDataTask
#define INCLUDED_haxor_platform_windows_LoadDataTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/windows/HTTPRequest.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,HTTPRequest)
HX_DECLARE_CLASS3(haxor,platform,windows,LoadDataTask)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  LoadDataTask_obj : public ::haxor::platform::windows::HTTPRequest_obj{
	public:
		typedef ::haxor::platform::windows::HTTPRequest_obj super;
		typedef LoadDataTask_obj OBJ_;
		LoadDataTask_obj();
		Void __construct(::String p_url,bool p_binary,Dynamic p_callback);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LoadDataTask_obj > __new(::String p_url,bool p_binary,Dynamic p_callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LoadDataTask_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LoadDataTask"); }

		Dynamic callback;
		Dynamic &callback_dyn() { return callback;}
		virtual Void OnStart( );

		virtual Void OnProgress( );

		virtual Void OnComplete( );

		virtual Void OnError( );

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_LoadDataTask */ 
