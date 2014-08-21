#ifndef INCLUDED_sys_net_Host
#define INCLUDED_sys_net_Host

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(cpp,Lib)
HX_DECLARE_CLASS2(sys,net,Host)
namespace sys{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Host_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Host_obj OBJ_;
		Host_obj();
		Void __construct(::String name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Host_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Host_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		static void __init__();

		::String __ToString() const { return HX_CSTRING("Host"); }

		int ip;
		virtual ::String toString( );
		Dynamic toString_dyn();

		static Dynamic host_resolve;
		static Dynamic &host_resolve_dyn() { return host_resolve;}
		static Dynamic host_to_string;
		static Dynamic &host_to_string_dyn() { return host_to_string;}
};

} // end namespace sys
} // end namespace net

#endif /* INCLUDED_sys_net_Host */ 
