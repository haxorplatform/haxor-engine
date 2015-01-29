#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaAnimationKeyFrame
#include <haxor/io/file/ColladaAnimationKeyFrame.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaAnimationKeyFrame_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaAnimationKeyFrame","new",0x78a134c8,"haxor.io.file.ColladaAnimationKeyFrame.new","haxor/io/file/ColladaFile.hx",1527,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1528)
	this->time = 0.0;
	HX_STACK_LINE(1529)
	this->values = Array_obj< Float >::__new();
}
;
	return null();
}

//ColladaAnimationKeyFrame_obj::~ColladaAnimationKeyFrame_obj() { }

Dynamic ColladaAnimationKeyFrame_obj::__CreateEmpty() { return  new ColladaAnimationKeyFrame_obj; }
hx::ObjectPtr< ColladaAnimationKeyFrame_obj > ColladaAnimationKeyFrame_obj::__new()
{  hx::ObjectPtr< ColladaAnimationKeyFrame_obj > result = new ColladaAnimationKeyFrame_obj();
	result->__construct();
	return result;}

Dynamic ColladaAnimationKeyFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaAnimationKeyFrame_obj > result = new ColladaAnimationKeyFrame_obj();
	result->__construct();
	return result;}


ColladaAnimationKeyFrame_obj::ColladaAnimationKeyFrame_obj()
{
}

void ColladaAnimationKeyFrame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaAnimationKeyFrame);
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(values,"values");
	HX_MARK_END_CLASS();
}

void ColladaAnimationKeyFrame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(time,"time");
	HX_VISIT_MEMBER_NAME(values,"values");
}

Dynamic ColladaAnimationKeyFrame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"values") ) { return values; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaAnimationKeyFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"values") ) { values=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaAnimationKeyFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("values"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(ColladaAnimationKeyFrame_obj,time),HX_CSTRING("time")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ColladaAnimationKeyFrame_obj,values),HX_CSTRING("values")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("time"),
	HX_CSTRING("values"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaAnimationKeyFrame_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaAnimationKeyFrame_obj::__mClass,"__mClass");
};

#endif

Class ColladaAnimationKeyFrame_obj::__mClass;

void ColladaAnimationKeyFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaAnimationKeyFrame"), hx::TCanCast< ColladaAnimationKeyFrame_obj> ,sStaticFields,sMemberFields,
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

void ColladaAnimationKeyFrame_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
