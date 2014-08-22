#ifndef INCLUDED_haxor_net_HTTPRequestTask
#define INCLUDED_haxor_net_HTTPRequestTask

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/thread/Task.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,net,HTTPRequestTask)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  HTTPRequestTask_obj : public ::haxor::thread::Task_obj{
	public:
		typedef ::haxor::thread::Task_obj super;
		typedef HTTPRequestTask_obj OBJ_;
		HTTPRequestTask_obj();
		Void __construct(::String p_url,::String p_method,bool p_binary,Dynamic p_data);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HTTPRequestTask_obj > __new(::String p_url,::String p_method,bool p_binary,Dynamic p_data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HTTPRequestTask_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTTPRequestTask"); }

		::String url;
		Dynamic request;
		Dynamic response;
		bool binary;
		::String method;
		Dynamic data;
		int bytesLoaded;
		int bytesTotal;
		::String error;
		virtual Void OnStart( );

		virtual Void OnError( );
		Dynamic OnError_dyn();

};

} // end namespace haxor
} // end namespace net

#endif /* INCLUDED_haxor_net_HTTPRequestTask */ 
