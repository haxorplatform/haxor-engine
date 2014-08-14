#include <hxcpp.h>

#ifndef INCLUDED_haxor_graphics_MeshPrimitive
#include <haxor/graphics/MeshPrimitive.h>
#endif
namespace haxor{
namespace graphics{

Void MeshPrimitive_obj::__construct()
{
	return null();
}

//MeshPrimitive_obj::~MeshPrimitive_obj() { }

Dynamic MeshPrimitive_obj::__CreateEmpty() { return  new MeshPrimitive_obj; }
hx::ObjectPtr< MeshPrimitive_obj > MeshPrimitive_obj::__new()
{  hx::ObjectPtr< MeshPrimitive_obj > result = new MeshPrimitive_obj();
	result->__construct();
	return result;}

Dynamic MeshPrimitive_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshPrimitive_obj > result = new MeshPrimitive_obj();
	result->__construct();
	return result;}

int MeshPrimitive_obj::Points;

int MeshPrimitive_obj::Triangles;

int MeshPrimitive_obj::TriangleStrip;

int MeshPrimitive_obj::TriangleFan;

int MeshPrimitive_obj::Lines;

int MeshPrimitive_obj::LineLoop;

int MeshPrimitive_obj::LineStrip;


MeshPrimitive_obj::MeshPrimitive_obj()
{
}

Dynamic MeshPrimitive_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic MeshPrimitive_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshPrimitive_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Points"),
	HX_CSTRING("Triangles"),
	HX_CSTRING("TriangleStrip"),
	HX_CSTRING("TriangleFan"),
	HX_CSTRING("Lines"),
	HX_CSTRING("LineLoop"),
	HX_CSTRING("LineStrip"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::Points,"Points");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::Triangles,"Triangles");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::TriangleStrip,"TriangleStrip");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::TriangleFan,"TriangleFan");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::Lines,"Lines");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::LineLoop,"LineLoop");
	HX_MARK_MEMBER_NAME(MeshPrimitive_obj::LineStrip,"LineStrip");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::Points,"Points");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::Triangles,"Triangles");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::TriangleStrip,"TriangleStrip");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::TriangleFan,"TriangleFan");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::Lines,"Lines");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::LineLoop,"LineLoop");
	HX_VISIT_MEMBER_NAME(MeshPrimitive_obj::LineStrip,"LineStrip");
};

#endif

Class MeshPrimitive_obj::__mClass;

void MeshPrimitive_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.MeshPrimitive"), hx::TCanCast< MeshPrimitive_obj> ,sStaticFields,sMemberFields,
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

void MeshPrimitive_obj::__boot()
{
	Points= (int)0;
	Triangles= (int)4;
	TriangleStrip= (int)5;
	TriangleFan= (int)6;
	Lines= (int)1;
	LineLoop= (int)2;
	LineStrip= (int)3;
}

} // end namespace haxor
} // end namespace graphics
