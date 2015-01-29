#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaAnimation
#include <haxor/io/file/ColladaAnimation.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAnimationChannel
#include <haxor/io/file/ColladaAnimationChannel.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaAnimation_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaAnimation","new",0xb3bfc39a,"haxor.io.file.ColladaAnimation.new","haxor/io/file/ColladaFile.hx",1488,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1492)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1490)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1498)
	this->channels = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//ColladaAnimation_obj::~ColladaAnimation_obj() { }

Dynamic ColladaAnimation_obj::__CreateEmpty() { return  new ColladaAnimation_obj; }
hx::ObjectPtr< ColladaAnimation_obj > ColladaAnimation_obj::__new()
{  hx::ObjectPtr< ColladaAnimation_obj > result = new ColladaAnimation_obj();
	result->__construct();
	return result;}

Dynamic ColladaAnimation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaAnimation_obj > result = new ColladaAnimation_obj();
	result->__construct();
	return result;}


ColladaAnimation_obj::ColladaAnimation_obj()
{
}

void ColladaAnimation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaAnimation);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(channels,"channels");
	HX_MARK_END_CLASS();
}

void ColladaAnimation_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(channels,"channels");
}

Dynamic ColladaAnimation_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"channels") ) { return channels; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaAnimation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"channels") ) { channels=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaAnimation_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("channels"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaAnimation_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaAnimation_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaAnimation_obj,channels),HX_CSTRING("channels")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("channels"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaAnimation_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaAnimation_obj::__mClass,"__mClass");
};

#endif

Class ColladaAnimation_obj::__mClass;

void ColladaAnimation_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaAnimation"), hx::TCanCast< ColladaAnimation_obj> ,sStaticFields,sMemberFields,
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

void ColladaAnimation_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
