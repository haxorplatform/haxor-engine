#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_ColliderType
#include <haxor/core/ColliderType.h>
#endif
namespace haxor{
namespace core{

::haxor::core::ColliderType ColliderType_obj::Box;

::haxor::core::ColliderType ColliderType_obj::Capsule;

::haxor::core::ColliderType ColliderType_obj::Mesh;

::haxor::core::ColliderType ColliderType_obj::Plane;

::haxor::core::ColliderType ColliderType_obj::Point;

::haxor::core::ColliderType ColliderType_obj::Sphere;

HX_DEFINE_CREATE_ENUM(ColliderType_obj)

int ColliderType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Box")) return 2;
	if (inName==HX_CSTRING("Capsule")) return 4;
	if (inName==HX_CSTRING("Mesh")) return 5;
	if (inName==HX_CSTRING("Plane")) return 1;
	if (inName==HX_CSTRING("Point")) return 0;
	if (inName==HX_CSTRING("Sphere")) return 3;
	return super::__FindIndex(inName);
}

int ColliderType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Box")) return 0;
	if (inName==HX_CSTRING("Capsule")) return 0;
	if (inName==HX_CSTRING("Mesh")) return 0;
	if (inName==HX_CSTRING("Plane")) return 0;
	if (inName==HX_CSTRING("Point")) return 0;
	if (inName==HX_CSTRING("Sphere")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ColliderType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Box")) return Box;
	if (inName==HX_CSTRING("Capsule")) return Capsule;
	if (inName==HX_CSTRING("Mesh")) return Mesh;
	if (inName==HX_CSTRING("Plane")) return Plane;
	if (inName==HX_CSTRING("Point")) return Point;
	if (inName==HX_CSTRING("Sphere")) return Sphere;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Point"),
	HX_CSTRING("Plane"),
	HX_CSTRING("Box"),
	HX_CSTRING("Sphere"),
	HX_CSTRING("Capsule"),
	HX_CSTRING("Mesh"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColliderType_obj::Box,"Box");
	HX_MARK_MEMBER_NAME(ColliderType_obj::Capsule,"Capsule");
	HX_MARK_MEMBER_NAME(ColliderType_obj::Mesh,"Mesh");
	HX_MARK_MEMBER_NAME(ColliderType_obj::Plane,"Plane");
	HX_MARK_MEMBER_NAME(ColliderType_obj::Point,"Point");
	HX_MARK_MEMBER_NAME(ColliderType_obj::Sphere,"Sphere");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColliderType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Box,"Box");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Capsule,"Capsule");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Mesh,"Mesh");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Plane,"Plane");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Point,"Point");
	HX_VISIT_MEMBER_NAME(ColliderType_obj::Sphere,"Sphere");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class ColliderType_obj::__mClass;

Dynamic __Create_ColliderType_obj() { return new ColliderType_obj; }

void ColliderType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.ColliderType"), hx::TCanCast< ColliderType_obj >,sStaticFields,sMemberFields,
	&__Create_ColliderType_obj, &__Create,
	&super::__SGetClass(), &CreateColliderType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ColliderType_obj::__boot()
{
hx::Static(Box) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Box"),2);
hx::Static(Capsule) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Capsule"),4);
hx::Static(Mesh) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Mesh"),5);
hx::Static(Plane) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Plane"),1);
hx::Static(Point) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Point"),0);
hx::Static(Sphere) = hx::CreateEnum< ColliderType_obj >(HX_CSTRING("Sphere"),3);
}


} // end namespace haxor
} // end namespace core
