#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_ClearFlag
#include <haxor/core/ClearFlag.h>
#endif
namespace haxor{
namespace core{

Void ClearFlag_obj::__construct()
{
	return null();
}

//ClearFlag_obj::~ClearFlag_obj() { }

Dynamic ClearFlag_obj::__CreateEmpty() { return  new ClearFlag_obj; }
hx::ObjectPtr< ClearFlag_obj > ClearFlag_obj::__new()
{  hx::ObjectPtr< ClearFlag_obj > result = new ClearFlag_obj();
	result->__construct();
	return result;}

Dynamic ClearFlag_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ClearFlag_obj > result = new ClearFlag_obj();
	result->__construct();
	return result;}

int ClearFlag_obj::None;

int ClearFlag_obj::Color;

int ClearFlag_obj::Depth;

int ClearFlag_obj::Skybox;

int ClearFlag_obj::ColorDepth;

int ClearFlag_obj::SkyboxDepth;


ClearFlag_obj::ClearFlag_obj()
{
}

Dynamic ClearFlag_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"None") ) { return None; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Color") ) { return Color; }
		if (HX_FIELD_EQ(inName,"Depth") ) { return Depth; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Skybox") ) { return Skybox; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ColorDepth") ) { return ColorDepth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SkyboxDepth") ) { return SkyboxDepth; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ClearFlag_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"None") ) { None=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Color") ) { Color=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Depth") ) { Depth=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Skybox") ) { Skybox=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ColorDepth") ) { ColorDepth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SkyboxDepth") ) { SkyboxDepth=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ClearFlag_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("Color"),
	HX_CSTRING("Depth"),
	HX_CSTRING("Skybox"),
	HX_CSTRING("ColorDepth"),
	HX_CSTRING("SkyboxDepth"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ClearFlag_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::None,"None");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::Color,"Color");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::Depth,"Depth");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::Skybox,"Skybox");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::ColorDepth,"ColorDepth");
	HX_MARK_MEMBER_NAME(ClearFlag_obj::SkyboxDepth,"SkyboxDepth");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::None,"None");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::Color,"Color");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::Depth,"Depth");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::Skybox,"Skybox");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::ColorDepth,"ColorDepth");
	HX_VISIT_MEMBER_NAME(ClearFlag_obj::SkyboxDepth,"SkyboxDepth");
};

#endif

Class ClearFlag_obj::__mClass;

void ClearFlag_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.ClearFlag"), hx::TCanCast< ClearFlag_obj> ,sStaticFields,sMemberFields,
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

void ClearFlag_obj::__boot()
{
	None= (int)0;
	Color= (int)1;
	Depth= (int)2;
	Skybox= (int)4;
	ColorDepth= (int)3;
	SkyboxDepth= (int)6;
}

} // end namespace haxor
} // end namespace core
