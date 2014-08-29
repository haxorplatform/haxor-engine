#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_BlendMode
#include <haxor/core/BlendMode.h>
#endif
namespace haxor{
namespace core{

Void BlendMode_obj::__construct()
{
	return null();
}

//BlendMode_obj::~BlendMode_obj() { }

Dynamic BlendMode_obj::__CreateEmpty() { return  new BlendMode_obj; }
hx::ObjectPtr< BlendMode_obj > BlendMode_obj::__new()
{  hx::ObjectPtr< BlendMode_obj > result = new BlendMode_obj();
	result->__construct();
	return result;}

Dynamic BlendMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlendMode_obj > result = new BlendMode_obj();
	result->__construct();
	return result;}

int BlendMode_obj::Zero;

int BlendMode_obj::One;

int BlendMode_obj::SrcColor;

int BlendMode_obj::OneMinusSrcColor;

int BlendMode_obj::SrcAlpha;

int BlendMode_obj::OneMinusSrcAlpha;

int BlendMode_obj::DstAlpha;

int BlendMode_obj::OneMinusDstAlpha;

int BlendMode_obj::DstColor;

int BlendMode_obj::OneMinusDstColor;

int BlendMode_obj::SrcAlphaSaturate;


BlendMode_obj::BlendMode_obj()
{
}

Dynamic BlendMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic BlendMode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BlendMode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Zero"),
	HX_CSTRING("One"),
	HX_CSTRING("SrcColor"),
	HX_CSTRING("OneMinusSrcColor"),
	HX_CSTRING("SrcAlpha"),
	HX_CSTRING("OneMinusSrcAlpha"),
	HX_CSTRING("DstAlpha"),
	HX_CSTRING("OneMinusDstAlpha"),
	HX_CSTRING("DstColor"),
	HX_CSTRING("OneMinusDstColor"),
	HX_CSTRING("SrcAlphaSaturate"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlendMode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BlendMode_obj::Zero,"Zero");
	HX_MARK_MEMBER_NAME(BlendMode_obj::One,"One");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SrcColor,"SrcColor");
	HX_MARK_MEMBER_NAME(BlendMode_obj::OneMinusSrcColor,"OneMinusSrcColor");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SrcAlpha,"SrcAlpha");
	HX_MARK_MEMBER_NAME(BlendMode_obj::OneMinusSrcAlpha,"OneMinusSrcAlpha");
	HX_MARK_MEMBER_NAME(BlendMode_obj::DstAlpha,"DstAlpha");
	HX_MARK_MEMBER_NAME(BlendMode_obj::OneMinusDstAlpha,"OneMinusDstAlpha");
	HX_MARK_MEMBER_NAME(BlendMode_obj::DstColor,"DstColor");
	HX_MARK_MEMBER_NAME(BlendMode_obj::OneMinusDstColor,"OneMinusDstColor");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SrcAlphaSaturate,"SrcAlphaSaturate");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BlendMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::Zero,"Zero");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::One,"One");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::SrcColor,"SrcColor");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::OneMinusSrcColor,"OneMinusSrcColor");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::SrcAlpha,"SrcAlpha");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::OneMinusSrcAlpha,"OneMinusSrcAlpha");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::DstAlpha,"DstAlpha");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::OneMinusDstAlpha,"OneMinusDstAlpha");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::DstColor,"DstColor");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::OneMinusDstColor,"OneMinusDstColor");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::SrcAlphaSaturate,"SrcAlphaSaturate");
};

#endif

Class BlendMode_obj::__mClass;

void BlendMode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.BlendMode"), hx::TCanCast< BlendMode_obj> ,sStaticFields,sMemberFields,
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

void BlendMode_obj::__boot()
{
	Zero= (int)0;
	One= (int)1;
	SrcColor= (int)768;
	OneMinusSrcColor= (int)769;
	SrcAlpha= (int)770;
	OneMinusSrcAlpha= (int)771;
	DstAlpha= (int)772;
	OneMinusDstAlpha= (int)773;
	DstColor= (int)774;
	OneMinusDstColor= (int)775;
	SrcAlphaSaturate= (int)776;
}

} // end namespace haxor
} // end namespace core
