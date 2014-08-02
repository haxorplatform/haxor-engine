#ifndef INCLUDED_haxor_platform_windows_Entry
#define INCLUDED_haxor_platform_windows_Entry

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,platform,windows,Entry)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  Entry_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Entry_obj OBJ_;
		Entry_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Entry_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Entry_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Entry"); }

		static Void Initialize( );
		static Dynamic Initialize_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_Entry */ 
