#ifndef INCLUDED_sys_net_Socket
#define INCLUDED_sys_net_Socket

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,net,Host)
HX_DECLARE_CLASS2(sys,net,Socket)
namespace sys{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Socket_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Socket_obj OBJ_;
		Socket_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Socket_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Socket_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Socket"); }

		Dynamic __s;
		::haxe::io::Input input;
		::haxe::io::Output output;
		virtual Void close( );
		Dynamic close_dyn();

		virtual Void write( ::String content);
		Dynamic write_dyn();

		virtual Void connect( ::sys::net::Host host,int port);
		Dynamic connect_dyn();

		virtual Void shutdown( bool read,bool write);
		Dynamic shutdown_dyn();

		virtual Void setTimeout( Float timeout);
		Dynamic setTimeout_dyn();

		static Dynamic socket_new;
		static Dynamic &socket_new_dyn() { return socket_new;}
		static Dynamic socket_close;
		static Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_write;
		static Dynamic &socket_write_dyn() { return socket_write;}
		static Dynamic socket_connect;
		static Dynamic &socket_connect_dyn() { return socket_connect;}
		static Dynamic socket_set_timeout;
		static Dynamic &socket_set_timeout_dyn() { return socket_set_timeout;}
		static Dynamic socket_shutdown;
		static Dynamic &socket_shutdown_dyn() { return socket_shutdown;}
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Socket */ 
