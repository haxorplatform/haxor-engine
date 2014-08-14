#ifndef INCLUDED_haxe_remoting_Context
#define INCLUDED_haxe_remoting_Context

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(haxe,remoting,Context)
namespace haxe{
namespace remoting{


class HXCPP_CLASS_ATTRIBUTES  Context_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Context_obj OBJ_;
		Context_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Context_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Context_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Context"); }

		::haxe::ds::StringMap objects;
		virtual Dynamic call( Array< ::String > path,Dynamic params);
		Dynamic call_dyn();

};

} // end namespace haxe
} // end namespace remoting

#endif /* INCLUDED_haxe_remoting_Context */ 
