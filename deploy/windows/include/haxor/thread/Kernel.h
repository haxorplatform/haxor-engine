#ifndef INCLUDED_haxor_thread_Kernel
#define INCLUDED_haxor_thread_Kernel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/material/Material.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,PixelFormat)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh3)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
HX_DECLARE_CLASS3(haxor,graphics,texture,RenderTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,thread,Kernel)
namespace haxor{
namespace thread{


class HXCPP_CLASS_ATTRIBUTES  Kernel_obj : public ::haxor::graphics::material::Material_obj{
	public:
		typedef ::haxor::graphics::material::Material_obj super;
		typedef Kernel_obj OBJ_;
		Kernel_obj();
		Void __construct(int p_width,int p_height,hx::Null< bool >  __o_p_readable,::haxor::core::PixelFormat p_format);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Kernel_obj > __new(int p_width,int p_height,hx::Null< bool >  __o_p_readable,::haxor::core::PixelFormat p_format);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Kernel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Kernel"); }

		virtual ::haxor::io::Buffer get_result( );
		Dynamic get_result_dyn();

		::haxor::io::Buffer m_result;
		bool enabled;
		virtual ::haxor::graphics::texture::RenderTexture get_output( );
		Dynamic get_output_dyn();

		::haxor::graphics::texture::RenderTexture m_output;
		::haxor::graphics::mesh::Mesh3 m_plane;
		virtual Void Resize( hx::Null< int >  p_width,hx::Null< int >  p_height);
		Dynamic Resize_dyn();

		virtual Void Execute( );
		Dynamic Execute_dyn();

		virtual Void Update( hx::Null< int >  p_x,hx::Null< int >  p_y,hx::Null< int >  p_width,hx::Null< int >  p_height);
		Dynamic Update_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace thread

#endif /* INCLUDED_haxor_thread_Kernel */ 
