#ifndef INCLUDED_haxor_context_MaterialContext
#define INCLUDED_haxor_context_MaterialContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS2(haxor,context,MaterialContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,material,MaterialUniform)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshAttrib)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  MaterialContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MaterialContext_obj OBJ_;
		MaterialContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MaterialContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MaterialContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MaterialContext"); }

		Array< ::String > uniform_globals;
		Array< ::Dynamic > globals;
		::haxor::context::UID mid;
		::haxor::context::UID sid;
		::haxor::context::UID uid;
		Array< int > vertex_shaders;
		Array< int > fragment_shaders;
		::haxor::graphics::material::Shader error_shader;
		Array< int > programs;
		Array< ::Dynamic > camera;
		Array< ::Dynamic > transform;
		Array< bool > viewmatrix;
		Array< bool > projmatrix;
		Array< ::Dynamic > locations;
		int slot;
		Array< ::Dynamic > uniforms;
		::haxor::graphics::material::Material current;
		bool ztest;
		int zfunc;
		bool zwrite;
		bool blend;
		int queue;
		int blendSrc;
		int blendDst;
		bool invert;
		int cull;
		bool pointSmooth;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void SetPointSmooth( bool p_flag);
		Dynamic SetPointSmooth_dyn();

		virtual Void UpdateFlags( ::haxor::graphics::material::Material m);
		Dynamic UpdateFlags_dyn();

		virtual Void InitializeMaterial( ::haxor::graphics::material::Material m);
		Dynamic InitializeMaterial_dyn();

		virtual Void InitializeShader( ::haxor::graphics::material::Shader s);
		Dynamic InitializeShader_dyn();

		virtual Void CreateUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u);
		Dynamic CreateUniform_dyn();

		virtual Void DestroyUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u);
		Dynamic DestroyUniform_dyn();

		virtual ::String CreateCompileShader( ::haxor::graphics::material::Shader s,int t,Array< int > c);
		Dynamic CreateCompileShader_dyn();

		virtual Void UpdateShader( ::haxor::graphics::material::Material m,::haxor::graphics::material::Shader s0,::haxor::graphics::material::Shader s1);
		Dynamic UpdateShader_dyn();

		virtual Void UpdateMaterial( ::haxor::graphics::material::Material m);
		Dynamic UpdateMaterial_dyn();

		virtual int GetAttribLocation( ::haxor::graphics::mesh::MeshAttrib a);
		Dynamic GetAttribLocation_dyn();

		virtual Void Bind( ::haxor::graphics::material::Material m,::haxor::component::Transform t,::haxor::component::Camera c);
		Dynamic Bind_dyn();

		virtual Void UseMaterial( ::haxor::graphics::material::Material m);
		Dynamic UseMaterial_dyn();

		virtual Void UpdateMaterialUniforms( ::haxor::component::Transform t,::haxor::component::Camera c,bool p_changed);
		Dynamic UpdateMaterialUniforms_dyn();

		virtual Void UploadUniforms( bool ut,bool ucv,bool ucp,::haxor::component::Transform t,::haxor::component::Camera c);
		Dynamic UploadUniforms_dyn();

		virtual Void UploadUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u);
		Dynamic UploadUniform_dyn();

		virtual Void ApplyUniform( int loc,::haxor::graphics::material::MaterialUniform u);
		Dynamic ApplyUniform_dyn();

		virtual Void UploadGlobalUniform( ::haxor::graphics::material::MaterialUniform u,bool ut,bool ucv,bool ucp,::haxor::component::Transform t,::haxor::component::Camera c);
		Dynamic UploadGlobalUniform_dyn();

		virtual Void Unbind( );
		Dynamic Unbind_dyn();

		virtual Void DestroyMaterial( ::haxor::graphics::material::Material m);
		Dynamic DestroyMaterial_dyn();

		virtual Void DestroyShader( ::haxor::graphics::material::Shader s);
		Dynamic DestroyShader_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_MaterialContext */ 
