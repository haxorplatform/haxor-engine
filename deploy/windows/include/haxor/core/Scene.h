#ifndef INCLUDED_haxor_core_Scene
#define INCLUDED_haxor_core_Scene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,core,Scene)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Scene_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Scene_obj OBJ_;
		Scene_obj();
		Void __construct(::String p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Scene_obj > __new(::String p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Scene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Scene"); }

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Scene */ 
