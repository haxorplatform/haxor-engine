#ifndef INCLUDED_sys_ssl__Socket_SocketInput
#define INCLUDED_sys_ssl__Socket_SocketInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS3(sys,ssl,_Socket,SocketInput)
namespace sys{
namespace ssl{
namespace _Socket{


class HXCPP_CLASS_ATTRIBUTES  SocketInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef SocketInput_obj OBJ_;
		SocketInput_obj();
		Void __construct(Dynamic s,Dynamic ssl);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SocketInput_obj > __new(Dynamic s,Dynamic ssl);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SocketInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SocketInput"); }

		Dynamic __s;
		Dynamic ssl;
		virtual int readByte( );

		virtual int readBytes( ::haxe::io::Bytes buf,int pos,int len);

		virtual Void close( );

		static Dynamic socket_recv;
		static Dynamic &socket_recv_dyn() { return socket_recv;}
		static Dynamic socket_recv_char;
		static Dynamic &socket_recv_char_dyn() { return socket_recv_char;}
		static Dynamic socket_close;
		static Dynamic &socket_close_dyn() { return socket_close;}
};

} // end namespace sys
} // end namespace ssl
} // end namespace _Socket

#endif /* INCLUDED_sys_ssl__Socket_SocketInput */ 
