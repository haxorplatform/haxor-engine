#include <hxcpp.h>

#ifndef INCLUDED_haxor_graphics_RenderQueue
#include <haxor/graphics/RenderQueue.h>
#endif
namespace haxor{
namespace graphics{

Void RenderQueue_obj::__construct()
{
	return null();
}

//RenderQueue_obj::~RenderQueue_obj() { }

Dynamic RenderQueue_obj::__CreateEmpty() { return  new RenderQueue_obj; }
hx::ObjectPtr< RenderQueue_obj > RenderQueue_obj::__new()
{  hx::ObjectPtr< RenderQueue_obj > result = new RenderQueue_obj();
	result->__construct();
	return result;}

Dynamic RenderQueue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RenderQueue_obj > result = new RenderQueue_obj();
	result->__construct();
	return result;}

int RenderQueue_obj::Background;

int RenderQueue_obj::Opaque;

int RenderQueue_obj::Transparent;

int RenderQueue_obj::Overlay;

int RenderQueue_obj::Interface;


RenderQueue_obj::RenderQueue_obj()
{
}

Dynamic RenderQueue_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic RenderQueue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void RenderQueue_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Background"),
	HX_CSTRING("Opaque"),
	HX_CSTRING("Transparent"),
	HX_CSTRING("Overlay"),
	HX_CSTRING("Interface"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RenderQueue_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(RenderQueue_obj::Background,"Background");
	HX_MARK_MEMBER_NAME(RenderQueue_obj::Opaque,"Opaque");
	HX_MARK_MEMBER_NAME(RenderQueue_obj::Transparent,"Transparent");
	HX_MARK_MEMBER_NAME(RenderQueue_obj::Overlay,"Overlay");
	HX_MARK_MEMBER_NAME(RenderQueue_obj::Interface,"Interface");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::Background,"Background");
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::Opaque,"Opaque");
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::Transparent,"Transparent");
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::Overlay,"Overlay");
	HX_VISIT_MEMBER_NAME(RenderQueue_obj::Interface,"Interface");
};

#endif

Class RenderQueue_obj::__mClass;

void RenderQueue_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.RenderQueue"), hx::TCanCast< RenderQueue_obj> ,sStaticFields,sMemberFields,
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

void RenderQueue_obj::__boot()
{
	Background= (int)0;
	Opaque= (int)1000;
	Transparent= (int)2000;
	Overlay= (int)3000;
	Interface= (int)4000;
}

} // end namespace haxor
} // end namespace graphics
