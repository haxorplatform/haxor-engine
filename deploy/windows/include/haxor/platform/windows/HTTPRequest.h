#ifndef INCLUDED_haxor_platform_windows_HTTPRequest
#define INCLUDED_haxor_platform_windows_HTTPRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/thread/Task.h>
HX_DECLARE_CLASS1(haxe,Http)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,HTTPRequest)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  HTTPRequest_obj : public ::haxor::thread::Task_obj{
	public:
		typedef ::haxor::thread::Task_obj super;
		typedef HTTPRequest_obj OBJ_;
		HTTPRequest_obj();
		Void __construct(::String p_url,::String p_method,bool p_binary,::String p_data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HTTPRequest_obj > __new(::String p_url,::String p_method,bool p_binary,::String p_data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HTTPRequest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTTPRequest"); }

		::String url;
		bool binary;
		::haxe::Http request;
		::String data;
		::String method;
		::String response;
		int bytesLoaded;
		int bytesTotal;
		::String error;
		bool m_loading;
		virtual Void OnStart( );

		virtual Void OnStep( );

		virtual Void OnComplete( );

		virtual Void OnError( );
		Dynamic OnError_dyn();

		static bool m_lock;
};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_HTTPRequest */ 
