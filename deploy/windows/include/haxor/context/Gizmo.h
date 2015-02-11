#ifndef INCLUDED_haxor_context_Gizmo
#define INCLUDED_haxor_context_Gizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,Gizmo)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,texture,ComputeTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  Gizmo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Gizmo_obj OBJ_;
		Gizmo_obj();
		Void __construct(int p_type,int p_count);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Gizmo_obj > __new(int p_type,int p_count);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Gizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Gizmo"); }

		::haxor::graphics::texture::ComputeTexture data;
		::haxor::graphics::mesh::Mesh mesh;
		::haxor::graphics::material::Material material;
		int type;
		int m_render_count;
		int m_gizmo_count;
		virtual Void OnBuild( );
		Dynamic OnBuild_dyn();

		virtual Void Push( ::haxor::math::Color p_color,::haxor::math::Vector4 p_a,::haxor::math::Vector4 p_b,::haxor::math::Matrix4 p_transform);
		Dynamic Push_dyn();

		virtual Void Clear( );
		Dynamic Clear_dyn();

		virtual Void Render( );
		Dynamic Render_dyn();

		static int POINT;
		static int LINE;
		static int AXIS;
		static int WIRE_CUBE;
		static int WIRE_SPHERE;
		static int CANVAS;
		static int DATA_OFFSET;
		static int MAX_GIZMOS;
		static ::haxor::math::Matrix4 IDM;
		static ::haxor::graphics::material::Shader SHADER;
};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_Gizmo */ 
