#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaAssetData
#include <haxor/io/file/ColladaAssetData.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaAssetData_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaAssetData","new",0x28364bd0,"haxor.io.file.ColladaAssetData.new","haxor/io/file/ColladaFile.hx",1056,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1065)
	this->axis = HX_CSTRING("y_up");
	HX_STACK_LINE(1064)
	this->unitValue = 0.0;
	HX_STACK_LINE(1063)
	this->unitName = HX_CSTRING("");
	HX_STACK_LINE(1062)
	this->modification = HX_CSTRING("");
	HX_STACK_LINE(1061)
	this->creation = HX_CSTRING("");
	HX_STACK_LINE(1060)
	this->source = HX_CSTRING("");
	HX_STACK_LINE(1059)
	this->tool = HX_CSTRING("");
	HX_STACK_LINE(1058)
	this->author = HX_CSTRING("");
}
;
	return null();
}

//ColladaAssetData_obj::~ColladaAssetData_obj() { }

Dynamic ColladaAssetData_obj::__CreateEmpty() { return  new ColladaAssetData_obj; }
hx::ObjectPtr< ColladaAssetData_obj > ColladaAssetData_obj::__new()
{  hx::ObjectPtr< ColladaAssetData_obj > result = new ColladaAssetData_obj();
	result->__construct();
	return result;}

Dynamic ColladaAssetData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaAssetData_obj > result = new ColladaAssetData_obj();
	result->__construct();
	return result;}


ColladaAssetData_obj::ColladaAssetData_obj()
{
}

void ColladaAssetData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaAssetData);
	HX_MARK_MEMBER_NAME(author,"author");
	HX_MARK_MEMBER_NAME(tool,"tool");
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(creation,"creation");
	HX_MARK_MEMBER_NAME(modification,"modification");
	HX_MARK_MEMBER_NAME(unitName,"unitName");
	HX_MARK_MEMBER_NAME(unitValue,"unitValue");
	HX_MARK_MEMBER_NAME(axis,"axis");
	HX_MARK_END_CLASS();
}

void ColladaAssetData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(author,"author");
	HX_VISIT_MEMBER_NAME(tool,"tool");
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(creation,"creation");
	HX_VISIT_MEMBER_NAME(modification,"modification");
	HX_VISIT_MEMBER_NAME(unitName,"unitName");
	HX_VISIT_MEMBER_NAME(unitValue,"unitValue");
	HX_VISIT_MEMBER_NAME(axis,"axis");
}

Dynamic ColladaAssetData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"tool") ) { return tool; }
		if (HX_FIELD_EQ(inName,"axis") ) { return axis; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"author") ) { return author; }
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"creation") ) { return creation; }
		if (HX_FIELD_EQ(inName,"unitName") ) { return unitName; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"unitValue") ) { return unitValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"modification") ) { return modification; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaAssetData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"tool") ) { tool=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"axis") ) { axis=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"author") ) { author=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"creation") ) { creation=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"unitName") ) { unitName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"unitValue") ) { unitValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"modification") ) { modification=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaAssetData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("author"));
	outFields->push(HX_CSTRING("tool"));
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("creation"));
	outFields->push(HX_CSTRING("modification"));
	outFields->push(HX_CSTRING("unitName"));
	outFields->push(HX_CSTRING("unitValue"));
	outFields->push(HX_CSTRING("axis"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,author),HX_CSTRING("author")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,tool),HX_CSTRING("tool")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,source),HX_CSTRING("source")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,creation),HX_CSTRING("creation")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,modification),HX_CSTRING("modification")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,unitName),HX_CSTRING("unitName")},
	{hx::fsFloat,(int)offsetof(ColladaAssetData_obj,unitValue),HX_CSTRING("unitValue")},
	{hx::fsString,(int)offsetof(ColladaAssetData_obj,axis),HX_CSTRING("axis")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("author"),
	HX_CSTRING("tool"),
	HX_CSTRING("source"),
	HX_CSTRING("creation"),
	HX_CSTRING("modification"),
	HX_CSTRING("unitName"),
	HX_CSTRING("unitValue"),
	HX_CSTRING("axis"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaAssetData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaAssetData_obj::__mClass,"__mClass");
};

#endif

Class ColladaAssetData_obj::__mClass;

void ColladaAssetData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaAssetData"), hx::TCanCast< ColladaAssetData_obj> ,sStaticFields,sMemberFields,
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

void ColladaAssetData_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
