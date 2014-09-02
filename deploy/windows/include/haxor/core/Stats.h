#ifndef INCLUDED_haxor_core_Stats
#define INCLUDED_haxor_core_Stats

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,Stats)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Stats_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Stats_obj OBJ_;
		Stats_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Stats_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Stats_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Stats"); }

		static int visible;
		static int culled;
		static int triangles;
		static int total;
		static int get_total( );
		static Dynamic get_total_dyn();

		static int renderers;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void BeginRender( );
		static Dynamic BeginRender_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Stats */ 
