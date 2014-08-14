#ifndef INCLUDED_haxor_core_Console
#define INCLUDED_haxor_core_Console

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
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

		static ::haxe::ds::StringMap m_benchmarks;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static int verbose;
		static Void Breakpoint( );
		static Dynamic Breakpoint_dyn();

		static Void Log( ::String p_msg,hx::Null< int >  p_level);
		static Dynamic Log_dyn();

		static Void LogImage( ::String p_url,int p_height);
		static Dynamic LogImage_dyn();

		static Void LogWarning( ::String p_msg,Dynamic p_obj);
		static Dynamic LogWarning_dyn();

		static Void LogError( ::String p_msg,Dynamic p_obj);
		static Dynamic LogError_dyn();

		static Void ClearStyle( );
		static Dynamic ClearStyle_dyn();

		static Void Clear( );
		static Dynamic Clear_dyn();

		static Void TimeStart( ::String p_id);
		static Dynamic TimeStart_dyn();

		static Void TimeEnd( ::String p_id);
		static Dynamic TimeEnd_dyn();

		static Void StackTrace( );
		static Dynamic StackTrace_dyn();

		static Void SetStyle( ::String p_size,::String p_color,::String p_background,::String p_font);
		static Dynamic SetStyle_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Console */ 
