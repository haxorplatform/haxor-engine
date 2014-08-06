#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#define INCLUDED_haxor_platform_graphics_GraphicContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicAPI)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  GraphicContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GraphicContext_obj OBJ_;
		GraphicContext_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GraphicContext_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GraphicContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphicContext"); }

		::haxor::platform::graphics::GraphicAPI api;
		virtual ::haxor::platform::graphics::GraphicAPI get_api( );
		Dynamic get_api_dyn();

		::haxor::platform::graphics::GraphicAPI m_api;
		::haxor::core::BaseApplication m_application;
		virtual Void CheckExtensions( );
		Dynamic CheckExtensions_dyn();

		virtual Void Focus( );
		Dynamic Focus_dyn();

		virtual Void Flush( );
		Dynamic Flush_dyn();

		virtual int CreateBuffer( );
		Dynamic CreateBuffer_dyn();

		virtual Void DeleteBuffer( int p_id);
		Dynamic DeleteBuffer_dyn();

		virtual Void Destroy( );
		Dynamic Destroy_dyn();

		virtual Void Resize( );
		Dynamic Resize_dyn();

		virtual Void Clear( Float p_r,Float p_g,Float p_b,Float p_a,Float p_depth);
		Dynamic Clear_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_GraphicContext */ 
