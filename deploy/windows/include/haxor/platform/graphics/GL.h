#ifndef INCLUDED_haxor_platform_graphics_GL
#define INCLUDED_haxor_platform_graphics_GL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,graphics,GL)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,OpenGL)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  GL_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GL_obj OBJ_;
		GL_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GL_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("GL"); }

		static int NULL_ID;
		static ::haxor::platform::graphics::OpenGL m_gl;
		static Void Initialize( ::haxor::core::BaseApplication p_application);
		static Dynamic Initialize_dyn();

		static Void Resize( );
		static Dynamic Resize_dyn();

		static Void Clear( Float p_r,Float p_g,Float p_b,Float p_a,Float p_depth);
		static Dynamic Clear_dyn();

		static int CreateBuffer( );
		static Dynamic CreateBuffer_dyn();

		static Void DeleteBuffer( int p_id);
		static Dynamic DeleteBuffer_dyn();

		static Void Flush( );
		static Dynamic Flush_dyn();

		static Void Focus( );
		static Dynamic Focus_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_GL */ 
