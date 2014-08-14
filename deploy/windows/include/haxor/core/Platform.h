#ifndef INCLUDED_haxor_core_Platform
#define INCLUDED_haxor_core_Platform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,Platform)
namespace haxor{
namespace core{


class Platform_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Platform_obj OBJ_;

	public:
		Platform_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.Platform"); }
		::String __ToString() const { return HX_CSTRING("Platform.") + tag; }

		static ::haxor::core::Platform Android;
		static inline ::haxor::core::Platform Android_dyn() { return Android; }
		static ::haxor::core::Platform HTML;
		static inline ::haxor::core::Platform HTML_dyn() { return HTML; }
		static ::haxor::core::Platform Linux;
		static inline ::haxor::core::Platform Linux_dyn() { return Linux; }
		static ::haxor::core::Platform MacOS;
		static inline ::haxor::core::Platform MacOS_dyn() { return MacOS; }
		static ::haxor::core::Platform NodeJS;
		static inline ::haxor::core::Platform NodeJS_dyn() { return NodeJS; }
		static ::haxor::core::Platform Unknown;
		static inline ::haxor::core::Platform Unknown_dyn() { return Unknown; }
		static ::haxor::core::Platform Windows;
		static inline ::haxor::core::Platform Windows_dyn() { return Windows; }
		static ::haxor::core::Platform iOS;
		static inline ::haxor::core::Platform iOS_dyn() { return iOS; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Platform */ 
