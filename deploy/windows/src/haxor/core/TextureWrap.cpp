#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_TextureWrap
#include <haxor/core/TextureWrap.h>
#endif
namespace haxor{
namespace core{

Void TextureWrap_obj::__construct()
{
	return null();
}

//TextureWrap_obj::~TextureWrap_obj() { }

Dynamic TextureWrap_obj::__CreateEmpty() { return  new TextureWrap_obj; }
hx::ObjectPtr< TextureWrap_obj > TextureWrap_obj::__new()
{  hx::ObjectPtr< TextureWrap_obj > result = new TextureWrap_obj();
	result->__construct();
	return result;}

Dynamic TextureWrap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureWrap_obj > result = new TextureWrap_obj();
	result->__construct();
	return result;}

int TextureWrap_obj::ClampX;

int TextureWrap_obj::RepeatX;

int TextureWrap_obj::ClampY;

int TextureWrap_obj::RepeatY;

int TextureWrap_obj::ClampZ;

int TextureWrap_obj::RepeatZ;


TextureWrap_obj::TextureWrap_obj()
{
}

Dynamic TextureWrap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"ClampX") ) { return ClampX; }
		if (HX_FIELD_EQ(inName,"ClampY") ) { return ClampY; }
		if (HX_FIELD_EQ(inName,"ClampZ") ) { return ClampZ; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"RepeatX") ) { return RepeatX; }
		if (HX_FIELD_EQ(inName,"RepeatY") ) { return RepeatY; }
		if (HX_FIELD_EQ(inName,"RepeatZ") ) { return RepeatZ; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureWrap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"ClampX") ) { ClampX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ClampY") ) { ClampY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ClampZ") ) { ClampZ=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"RepeatX") ) { RepeatX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RepeatY") ) { RepeatY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RepeatZ") ) { RepeatZ=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureWrap_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ClampX"),
	HX_CSTRING("RepeatX"),
	HX_CSTRING("ClampY"),
	HX_CSTRING("RepeatY"),
	HX_CSTRING("ClampZ"),
	HX_CSTRING("RepeatZ"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureWrap_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::ClampX,"ClampX");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::RepeatX,"RepeatX");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::ClampY,"ClampY");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::RepeatY,"RepeatY");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::ClampZ,"ClampZ");
	HX_MARK_MEMBER_NAME(TextureWrap_obj::RepeatZ,"RepeatZ");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::ClampX,"ClampX");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::RepeatX,"RepeatX");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::ClampY,"ClampY");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::RepeatY,"RepeatY");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::ClampZ,"ClampZ");
	HX_VISIT_MEMBER_NAME(TextureWrap_obj::RepeatZ,"RepeatZ");
};

#endif

Class TextureWrap_obj::__mClass;

void TextureWrap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.TextureWrap"), hx::TCanCast< TextureWrap_obj> ,sStaticFields,sMemberFields,
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

void TextureWrap_obj::__boot()
{
	ClampX= (int)1;
	RepeatX= (int)2;
	ClampY= (int)4;
	RepeatY= (int)8;
	ClampZ= (int)16;
	RepeatZ= (int)32;
}

} // end namespace haxor
} // end namespace core
