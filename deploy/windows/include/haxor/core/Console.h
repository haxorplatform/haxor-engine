#ifndef INCLUDED_haxor_core_Console
#define INCLUDED_haxor_core_Console

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,Console)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Console_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Console_obj OBJ_;
		Console_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Console_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Console_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Console"); }

		static int verbose;
		static Void Log( ::String p_msg,hx::Null< int >  p_level);
		static Dynamic Log_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Console */ 
