#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_MeshMode
#include <haxor/core/MeshMode.h>
#endif
namespace haxor{
namespace core{

Void MeshMode_obj::__construct()
{
	return null();
}

//MeshMode_obj::~MeshMode_obj() { }

Dynamic MeshMode_obj::__CreateEmpty() { return  new MeshMode_obj; }
hx::ObjectPtr< MeshMode_obj > MeshMode_obj::__new()
{  hx::ObjectPtr< MeshMode_obj > result = new MeshMode_obj();
	result->__construct();
	return result;}

Dynamic MeshMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshMode_obj > result = new MeshMode_obj();
	result->__construct();
	return result;}

int MeshMode_obj::StaticDraw;

int MeshMode_obj::StreamDraw;

int MeshMode_obj::DynamicDraw;


MeshMode_obj::MeshMode_obj()
{
}

Dynamic MeshMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic MeshMode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshMode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("StaticDraw"),
	HX_CSTRING("StreamDraw"),
	HX_CSTRING("DynamicDraw"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshMode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MeshMode_obj::StaticDraw,"StaticDraw");
	HX_MARK_MEMBER_NAME(MeshMode_obj::StreamDraw,"StreamDraw");
	HX_MARK_MEMBER_NAME(MeshMode_obj::DynamicDraw,"DynamicDraw");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MeshMode_obj::StaticDraw,"StaticDraw");
	HX_VISIT_MEMBER_NAME(MeshMode_obj::StreamDraw,"StreamDraw");
	HX_VISIT_MEMBER_NAME(MeshMode_obj::DynamicDraw,"DynamicDraw");
};

#endif

Class MeshMode_obj::__mClass;

void MeshMode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.MeshMode"), hx::TCanCast< MeshMode_obj> ,sStaticFields,sMemberFields,
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

void MeshMode_obj::__boot()
{
	StaticDraw= (int)35044;
	StreamDraw= (int)35040;
	DynamicDraw= (int)35048;
}

} // end namespace haxor
} // end namespace core
