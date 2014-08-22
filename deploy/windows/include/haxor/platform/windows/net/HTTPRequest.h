#ifndef INCLUDED_haxor_platform_windows_net_HTTPRequest
#define INCLUDED_haxor_platform_windows_net_HTTPRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/net/HTTPRequestTask.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,net,HTTPRequestTask)
HX_DECLARE_CLASS4(haxor,platform,windows,net,HTTPRequest)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace platform{
namespace windows{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  HTTPRequest_obj : public ::haxor::net::HTTPRequestTask_obj{
	public:
		typedef ::haxor::net::HTTPRequestTask_obj super;
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
		::String __ToString() const { return HX_CSTRING("HTTPRequest"); }

		bool m_loading;
		virtual Void OnStep( );

		static bool m_lock;
};

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace net

#endif /* INCLUDED_haxor_platform_windows_net_HTTPRequest */ 
