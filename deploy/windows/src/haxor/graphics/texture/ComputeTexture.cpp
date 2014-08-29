#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_TextureFilter
#include <haxor/core/TextureFilter.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_ComputeTexture
#include <haxor/graphics/texture/ComputeTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void ComputeTexture_obj::__construct(int p_width,int p_height,::haxor::core::PixelFormat p_format)
{
HX_STACK_FRAME("haxor.graphics.texture.ComputeTexture","new",0xdb1d7d80,"haxor.graphics.texture.ComputeTexture.new","haxor/graphics/texture/ComputeTexture.hx",33,0x6a506cef)
HX_STACK_THIS(this)
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
HX_STACK_ARG(p_format,"p_format")
{
	HX_STACK_LINE(34)
	super::__construct(p_width,p_height,p_format);
	HX_STACK_LINE(35)
	this->set_minFilter(::haxor::core::TextureFilter_obj::Nearest);
	HX_STACK_LINE(36)
	this->set_magFilter(::haxor::core::TextureFilter_obj::Nearest);
	HX_STACK_LINE(37)
	this->m_lock = false;
	HX_STACK_LINE(38)
	this->m_dirty = false;
}
;
	return null();
}

//ComputeTexture_obj::~ComputeTexture_obj() { }

Dynamic ComputeTexture_obj::__CreateEmpty() { return  new ComputeTexture_obj; }
hx::ObjectPtr< ComputeTexture_obj > ComputeTexture_obj::__new(int p_width,int p_height,::haxor::core::PixelFormat p_format)
{  hx::ObjectPtr< ComputeTexture_obj > result = new ComputeTexture_obj();
	result->__construct(p_width,p_height,p_format);
	return result;}

Dynamic ComputeTexture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ComputeTexture_obj > result = new ComputeTexture_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void ComputeTexture_obj::Write( int p_x,int p_y,Dynamic __o_p_v0,Dynamic __o_p_v1,Dynamic __o_p_v2,Dynamic __o_p_v3){
Dynamic p_v0 = __o_p_v0.Default(0);
Dynamic p_v1 = __o_p_v1.Default(0);
Dynamic p_v2 = __o_p_v2.Default(0);
Dynamic p_v3 = __o_p_v3.Default(0);
	HX_STACK_FRAME("haxor.graphics.texture.ComputeTexture","Write",0xc5ee11df,"haxor.graphics.texture.ComputeTexture.Write","haxor/graphics/texture/ComputeTexture.hx",51,0x6a506cef)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_v0,"p_v0")
	HX_STACK_ARG(p_v1,"p_v1")
	HX_STACK_ARG(p_v2,"p_v2")
	HX_STACK_ARG(p_v3,"p_v3")
{
		struct _Function_1_1{
			inline static ::haxor::math::Color Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/texture/ComputeTexture.hx",52,0x6a506cef)
				{
					HX_STACK_LINE(52)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(52)
					int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(52)
					return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
				}
				return null();
			}
		};
		HX_STACK_LINE(52)
		::haxor::math::Color _g1 = (_Function_1_1::Block())->Set(p_v0,p_v1,p_v2,p_v3);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(52)
		this->m_data->SetPixel(p_x,p_y,_g1);
		HX_STACK_LINE(53)
		this->m_dirty = true;
		HX_STACK_LINE(54)
		this->Refresh();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(ComputeTexture_obj,Write,(void))

Void ComputeTexture_obj::WriteRange( Array< Float > p_values,hx::Null< int >  __o_p_x,hx::Null< int >  __o_p_y,hx::Null< int >  __o_p_width,hx::Null< int >  __o_p_height){
int p_x = __o_p_x.Default(0);
int p_y = __o_p_y.Default(0);
int p_width = __o_p_width.Default(-1);
int p_height = __o_p_height.Default(-1);
	HX_STACK_FRAME("haxor.graphics.texture.ComputeTexture","WriteRange",0xad56db5e,"haxor.graphics.texture.ComputeTexture.WriteRange","haxor/graphics/texture/ComputeTexture.hx",66,0x6a506cef)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_values,"p_values")
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
{
		HX_STACK_LINE(67)
		int w;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(67)
		if (((p_width < (int)0))){
			HX_STACK_LINE(67)
			w = this->m_width;
		}
		else{
			HX_STACK_LINE(67)
			w = p_width;
		}
		HX_STACK_LINE(68)
		int h;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(68)
		if (((p_height < (int)0))){
			HX_STACK_LINE(68)
			h = this->m_height;
		}
		else{
			HX_STACK_LINE(68)
			h = p_height;
		}
		HX_STACK_LINE(69)
		this->m_data->SetRange(p_x,p_y,w,h,p_values,null());
		HX_STACK_LINE(70)
		this->Refresh();
		HX_STACK_LINE(71)
		this->m_dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ComputeTexture_obj,WriteRange,(void))

Void ComputeTexture_obj::Refresh( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.ComputeTexture","Refresh",0xece8bedb,"haxor.graphics.texture.ComputeTexture.Refresh","haxor/graphics/texture/ComputeTexture.hx",78,0x6a506cef)
		HX_STACK_THIS(this)
		HX_STACK_LINE(79)
		if ((this->m_lock)){
			HX_STACK_LINE(79)
			return null();
		}
		HX_STACK_LINE(80)
		this->m_lock = true;
		HX_STACK_LINE(81)
		this->Upload((int)10,this->OnUploadComplete_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ComputeTexture_obj,Refresh,(void))

Void ComputeTexture_obj::OnUploadComplete( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.ComputeTexture","OnUploadComplete",0xaf887859,"haxor.graphics.texture.ComputeTexture.OnUploadComplete","haxor/graphics/texture/ComputeTexture.hx",88,0x6a506cef)
		HX_STACK_THIS(this)
		HX_STACK_LINE(89)
		this->m_lock = false;
		HX_STACK_LINE(90)
		if ((this->m_dirty)){
			HX_STACK_LINE(90)
			this->Refresh();
		}
		HX_STACK_LINE(91)
		this->m_dirty = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ComputeTexture_obj,OnUploadComplete,(void))


ComputeTexture_obj::ComputeTexture_obj()
{
}

Dynamic ComputeTexture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"Write") ) { return Write_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { return m_lock; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_dirty") ) { return m_dirty; }
		if (HX_FIELD_EQ(inName,"Refresh") ) { return Refresh_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"WriteRange") ) { return WriteRange_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnUploadComplete") ) { return OnUploadComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ComputeTexture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { m_lock=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_dirty") ) { m_dirty=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ComputeTexture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_lock"));
	outFields->push(HX_CSTRING("m_dirty"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(ComputeTexture_obj,m_lock),HX_CSTRING("m_lock")},
	{hx::fsBool,(int)offsetof(ComputeTexture_obj,m_dirty),HX_CSTRING("m_dirty")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_lock"),
	HX_CSTRING("m_dirty"),
	HX_CSTRING("Write"),
	HX_CSTRING("WriteRange"),
	HX_CSTRING("Refresh"),
	HX_CSTRING("OnUploadComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ComputeTexture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ComputeTexture_obj::__mClass,"__mClass");
};

#endif

Class ComputeTexture_obj::__mClass;

void ComputeTexture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.ComputeTexture"), hx::TCanCast< ComputeTexture_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void ComputeTexture_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
