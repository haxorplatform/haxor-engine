#ifndef INCLUDED_sys_ssl_Socket
#define INCLUDED_sys_ssl_Socket

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,net,Host)
HX_DECLARE_CLASS2(sys,ssl,Socket)
HX_DECLARE_CLASS3(sys,ssl,_Socket,SocketInput)
HX_DECLARE_CLASS3(sys,ssl,_Socket,SocketOutput)
namespace sys{
namespace ssl{


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

		::sys::ssl::_Socket::SocketInput input;
		::sys::ssl::_Socket::SocketOutput output;
		Dynamic custom;
		Dynamic __s;
		Dynamic ctx;
		Dynamic ssl;
		::String certFile;
		::String certFolder;
		virtual Void connect( ::sys::net::Host host,int port);
		Dynamic connect_dyn();

		virtual Void setCertLocation( ::String file,::String folder);
		Dynamic setCertLocation_dyn();

		virtual ::String read( );
		Dynamic read_dyn();

		virtual Void write( ::String content);
		Dynamic write_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void shutdown( bool read,bool write);
		Dynamic shutdown_dyn();

		virtual Dynamic host( );
		Dynamic host_dyn();

		virtual Void setTimeout( Float timeout);
		Dynamic setTimeout_dyn();

		virtual Void waitForRead( );
		Dynamic waitForRead_dyn();

		virtual Void setBlocking( bool b);
		Dynamic setBlocking_dyn();

		virtual Void setFastSend( bool b);
		Dynamic setFastSend_dyn();

		virtual Void initSSL( );
		Dynamic initSSL_dyn();

		virtual Dynamic buildSSLContext( );
		Dynamic buildSSLContext_dyn();

		static Dynamic select( Array< ::Dynamic > read,Array< ::Dynamic > write,Array< ::Dynamic > others,Dynamic timeout);
		static Dynamic select_dyn();

		static Dynamic SSL_library_init;
		static Dynamic &SSL_library_init_dyn() { return SSL_library_init;}
		static Dynamic SSL_load_error_strings;
		static Dynamic &SSL_load_error_strings_dyn() { return SSL_load_error_strings;}
		static Dynamic SSL_new;
		static Dynamic &SSL_new_dyn() { return SSL_new;}
		static Dynamic SSL_close;
		static Dynamic &SSL_close_dyn() { return SSL_close;}
		static Dynamic SSL_connect;
		static Dynamic &SSL_connect_dyn() { return SSL_connect;}
		static Dynamic SSL_shutdown;
		static Dynamic &SSL_shutdown_dyn() { return SSL_shutdown;}
		static Dynamic SSL_free;
		static Dynamic SSL_set_bio;
		static Dynamic &SSL_set_bio_dyn() { return SSL_set_bio;}
		static Dynamic SSLv23_client_method;
		static Dynamic &SSLv23_client_method_dyn() { return SSLv23_client_method;}
		static Dynamic TLSv1_client_method;
		static Dynamic SSL_CTX_new;
		static Dynamic &SSL_CTX_new_dyn() { return SSL_CTX_new;}
		static Dynamic SSL_CTX_close;
		static Dynamic &SSL_CTX_close_dyn() { return SSL_CTX_close;}
		static Dynamic SSL_CTX_load_verify_locations;
		static Dynamic &SSL_CTX_load_verify_locations_dyn() { return SSL_CTX_load_verify_locations;}
		static Dynamic SSL_CTX_set_verify;
		static Dynamic &SSL_CTX_set_verify_dyn() { return SSL_CTX_set_verify;}
		static Dynamic SSL_CTX_use_certificate_file;
		static Dynamic BIO_new_socket;
		static Dynamic &BIO_new_socket_dyn() { return BIO_new_socket;}
		static Dynamic BIO_NOCLOSE;
		static Dynamic &BIO_NOCLOSE_dyn() { return BIO_NOCLOSE;}
		static Dynamic socket_read;
		static Dynamic &socket_read_dyn() { return socket_read;}
		static Dynamic socket_write;
		static Dynamic &socket_write_dyn() { return socket_write;}
		static Dynamic ssl_accept;
		static Dynamic lib( ::String f,hx::Null< int >  args);
		static Dynamic lib_dyn();

		static Dynamic socket_new;
		static Dynamic &socket_new_dyn() { return socket_new;}
		static Dynamic socket_close;
		static Dynamic &socket_close_dyn() { return socket_close;}
		static Dynamic socket_connect;
		static Dynamic &socket_connect_dyn() { return socket_connect;}
		static Dynamic socket_listen;
		static Dynamic socket_select;
		static Dynamic &socket_select_dyn() { return socket_select;}
		static Dynamic socket_bind;
		static Dynamic socket_accept;
		static Dynamic socket_peer;
		static Dynamic socket_host;
		static Dynamic &socket_host_dyn() { return socket_host;}
		static Dynamic socket_set_timeout;
		static Dynamic &socket_set_timeout_dyn() { return socket_set_timeout;}
		static Dynamic socket_shutdown;
		static Dynamic &socket_shutdown_dyn() { return socket_shutdown;}
		static Dynamic socket_set_blocking;
		static Dynamic &socket_set_blocking_dyn() { return socket_set_blocking;}
		static Dynamic socket_set_fast_send;
		static Dynamic &socket_set_fast_send_dyn() { return socket_set_fast_send;}
};

} // end namespace sys
} // end namespace ssl

#endif /* INCLUDED_sys_ssl_Socket */ 
