#ifndef INCLUDED_haxor_core_ApplicationProtocol
#define INCLUDED_haxor_core_ApplicationProtocol

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,ApplicationProtocol)
namespace haxor{
namespace core{


class ApplicationProtocol_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ApplicationProtocol_obj OBJ_;

	public:
		ApplicationProtocol_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.ApplicationProtocol"); }
		::String __ToString() const { return HX_CSTRING("ApplicationProtocol.") + tag; }

		static ::haxor::core::ApplicationProtocol File;
		static inline ::haxor::core::ApplicationProtocol File_dyn() { return File; }
		static ::haxor::core::ApplicationProtocol HTTP;
		static inline ::haxor::core::ApplicationProtocol HTTP_dyn() { return HTTP; }
		static ::haxor::core::ApplicationProtocol HTTPS;
		static inline ::haxor::core::ApplicationProtocol HTTPS_dyn() { return HTTPS; }
		static ::haxor::core::ApplicationProtocol Unknown;
		static inline ::haxor::core::ApplicationProtocol Unknown_dyn() { return Unknown; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_ApplicationProtocol */ 
