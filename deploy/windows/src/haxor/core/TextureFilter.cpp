#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_TextureFilter
#include <haxor/core/TextureFilter.h>
#endif
namespace haxor{
namespace core{

::haxor::core::TextureFilter TextureFilter_obj::Linear;

::haxor::core::TextureFilter TextureFilter_obj::LinearMipmapLinear;

::haxor::core::TextureFilter TextureFilter_obj::LinearMipmapNearest;

::haxor::core::TextureFilter TextureFilter_obj::Nearest;

::haxor::core::TextureFilter TextureFilter_obj::NearestMipmapLinear;

::haxor::core::TextureFilter TextureFilter_obj::NearestMipmapNearest;

::haxor::core::TextureFilter TextureFilter_obj::Trilinear;

HX_DEFINE_CREATE_ENUM(TextureFilter_obj)

int TextureFilter_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Linear")) return 1;
	if (inName==HX_CSTRING("LinearMipmapLinear")) return 5;
	if (inName==HX_CSTRING("LinearMipmapNearest")) return 4;
	if (inName==HX_CSTRING("Nearest")) return 0;
	if (inName==HX_CSTRING("NearestMipmapLinear")) return 3;
	if (inName==HX_CSTRING("NearestMipmapNearest")) return 2;
	if (inName==HX_CSTRING("Trilinear")) return 6;
	return super::__FindIndex(inName);
}

int TextureFilter_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Linear")) return 0;
	if (inName==HX_CSTRING("LinearMipmapLinear")) return 0;
	if (inName==HX_CSTRING("LinearMipmapNearest")) return 0;
	if (inName==HX_CSTRING("Nearest")) return 0;
	if (inName==HX_CSTRING("NearestMipmapLinear")) return 0;
	if (inName==HX_CSTRING("NearestMipmapNearest")) return 0;
	if (inName==HX_CSTRING("Trilinear")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextureFilter_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Linear")) return Linear;
	if (inName==HX_CSTRING("LinearMipmapLinear")) return LinearMipmapLinear;
	if (inName==HX_CSTRING("LinearMipmapNearest")) return LinearMipmapNearest;
	if (inName==HX_CSTRING("Nearest")) return Nearest;
	if (inName==HX_CSTRING("NearestMipmapLinear")) return NearestMipmapLinear;
	if (inName==HX_CSTRING("NearestMipmapNearest")) return NearestMipmapNearest;
	if (inName==HX_CSTRING("Trilinear")) return Trilinear;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Nearest"),
	HX_CSTRING("Linear"),
	HX_CSTRING("NearestMipmapNearest"),
	HX_CSTRING("NearestMipmapLinear"),
	HX_CSTRING("LinearMipmapNearest"),
	HX_CSTRING("LinearMipmapLinear"),
	HX_CSTRING("Trilinear"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureFilter_obj::Linear,"Linear");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::LinearMipmapLinear,"LinearMipmapLinear");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::LinearMipmapNearest,"LinearMipmapNearest");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::Nearest,"Nearest");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::NearestMipmapLinear,"NearestMipmapLinear");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::NearestMipmapNearest,"NearestMipmapNearest");
	HX_MARK_MEMBER_NAME(TextureFilter_obj::Trilinear,"Trilinear");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::Linear,"Linear");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::LinearMipmapLinear,"LinearMipmapLinear");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::LinearMipmapNearest,"LinearMipmapNearest");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::Nearest,"Nearest");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::NearestMipmapLinear,"NearestMipmapLinear");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::NearestMipmapNearest,"NearestMipmapNearest");
	HX_VISIT_MEMBER_NAME(TextureFilter_obj::Trilinear,"Trilinear");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class TextureFilter_obj::__mClass;

Dynamic __Create_TextureFilter_obj() { return new TextureFilter_obj; }

void TextureFilter_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.TextureFilter"), hx::TCanCast< TextureFilter_obj >,sStaticFields,sMemberFields,
	&__Create_TextureFilter_obj, &__Create,
	&super::__SGetClass(), &CreateTextureFilter_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void TextureFilter_obj::__boot()
{
hx::Static(Linear) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("Linear"),1);
hx::Static(LinearMipmapLinear) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("LinearMipmapLinear"),5);
hx::Static(LinearMipmapNearest) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("LinearMipmapNearest"),4);
hx::Static(Nearest) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("Nearest"),0);
hx::Static(NearestMipmapLinear) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("NearestMipmapLinear"),3);
hx::Static(NearestMipmapNearest) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("NearestMipmapNearest"),2);
hx::Static(Trilinear) = hx::CreateEnum< TextureFilter_obj >(HX_CSTRING("Trilinear"),6);
}


} // end namespace haxor
} // end namespace core
