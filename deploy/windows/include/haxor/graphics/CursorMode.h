#ifndef INCLUDED_haxor_graphics_CursorMode
#define INCLUDED_haxor_graphics_CursorMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,CursorMode)
namespace haxor{
namespace graphics{


class CursorMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CursorMode_obj OBJ_;

	public:
		CursorMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.graphics.CursorMode"); }
		::String __ToString() const { return HX_CSTRING("CursorMode.") + tag; }

		static ::haxor::graphics::CursorMode Hide;
		static inline ::haxor::graphics::CursorMode Hide_dyn() { return Hide; }
		static ::haxor::graphics::CursorMode Lock;
		static inline ::haxor::graphics::CursorMode Lock_dyn() { return Lock; }
		static ::haxor::graphics::CursorMode Show;
		static inline ::haxor::graphics::CursorMode Show_dyn() { return Show; }
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_CursorMode */ 
