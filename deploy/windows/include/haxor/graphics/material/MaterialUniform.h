#ifndef INCLUDED_haxor_graphics_material_MaterialUniform
#define INCLUDED_haxor_graphics_material_MaterialUniform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,MaterialUniform)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace graphics{
namespace material{


class HXCPP_CLASS_ATTRIBUTES  MaterialUniform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MaterialUniform_obj OBJ_;
		MaterialUniform_obj();
		Void __construct(::String p_name,bool p_is_float,int p_length,int p_offset);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MaterialUniform_obj > __new(::String p_name,bool p_is_float,int p_length,int p_offset);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MaterialUniform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MaterialUniform"); }

		int __cid;
		bool __d;
		::String name;
		::haxor::io::Buffer data;
		int offset;
		bool transposed;
		::haxor::graphics::texture::Texture texture;
		bool isFloat;
		bool exists;
		virtual Void SetFloat( Float p_v);
		Dynamic SetFloat_dyn();

		virtual Void SetFloat2( Float p_x,Float p_y);
		Dynamic SetFloat2_dyn();

		virtual Void SetFloat3( Float p_x,Float p_y,Float p_z);
		Dynamic SetFloat3_dyn();

		virtual Void SetFloat4( Float p_x,Float p_y,Float p_z,Float p_w);
		Dynamic SetFloat4_dyn();

		virtual Void SetFloatArray( Array< Float > p_list);
		Dynamic SetFloatArray_dyn();

		virtual Void SetFloat2Array( Array< Float > p_list);
		Dynamic SetFloat2Array_dyn();

		virtual Void SetFloat3Array( Array< Float > p_list);
		Dynamic SetFloat3Array_dyn();

		virtual Void SetFloat4Array( Array< Float > p_list);
		Dynamic SetFloat4Array_dyn();

		virtual Void SetInt( int p_v);
		Dynamic SetInt_dyn();

		virtual Void SetInt2( int p_x,int p_y);
		Dynamic SetInt2_dyn();

		virtual Void SetInt3( int p_x,int p_y,int p_z);
		Dynamic SetInt3_dyn();

		virtual Void SetInt4( int p_x,int p_y,int p_z,int p_w);
		Dynamic SetInt4_dyn();

		virtual Void SetIntArray( Array< int > p_list);
		Dynamic SetIntArray_dyn();

		virtual Void SetInt2Array( Array< int > p_list);
		Dynamic SetInt2Array_dyn();

		virtual Void SetInt3Array( Array< int > p_list);
		Dynamic SetInt3Array_dyn();

		virtual Void SetInt4Array( Array< int > p_list);
		Dynamic SetInt4Array_dyn();

		virtual Void SetTexture( ::haxor::graphics::texture::Texture p_texture);
		Dynamic SetTexture_dyn();

		virtual Void SetMatrix4( ::haxor::math::Matrix4 m,hx::Null< bool >  t);
		Dynamic SetMatrix4_dyn();

		virtual Void SetVector2( ::haxor::math::Vector2 p_v);
		Dynamic SetVector2_dyn();

		virtual Void SetVector3( ::haxor::math::Vector3 p_v);
		Dynamic SetVector3_dyn();

		virtual Void SetVector4( ::haxor::math::Vector4 p_v);
		Dynamic SetVector4_dyn();

		virtual Void SetColor( ::haxor::math::Color p_color);
		Dynamic SetColor_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace material

#endif /* INCLUDED_haxor_graphics_material_MaterialUniform */ 
