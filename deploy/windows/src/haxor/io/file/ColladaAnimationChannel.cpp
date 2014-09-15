#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaAnimationChannel
#include <haxor/io/file/ColladaAnimationChannel.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAnimationKeyFrame
#include <haxor/io/file/ColladaAnimationKeyFrame.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaAnimationChannel_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaAnimationChannel","new",0xf7a2596d,"haxor.io.file.ColladaAnimationChannel.new","haxor/io/file/ColladaFile.hx",1502,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1506)
	this->target = HX_CSTRING("");
	HX_STACK_LINE(1504)
	this->source = HX_CSTRING("");
	HX_STACK_LINE(1512)
	this->keyframes = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//ColladaAnimationChannel_obj::~ColladaAnimationChannel_obj() { }

Dynamic ColladaAnimationChannel_obj::__CreateEmpty() { return  new ColladaAnimationChannel_obj; }
hx::ObjectPtr< ColladaAnimationChannel_obj > ColladaAnimationChannel_obj::__new()
{  hx::ObjectPtr< ColladaAnimationChannel_obj > result = new ColladaAnimationChannel_obj();
	result->__construct();
	return result;}

Dynamic ColladaAnimationChannel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaAnimationChannel_obj > result = new ColladaAnimationChannel_obj();
	result->__construct();
	return result;}


ColladaAnimationChannel_obj::ColladaAnimationChannel_obj()
{
}

void ColladaAnimationChannel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaAnimationChannel);
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(keyframes,"keyframes");
	HX_MARK_END_CLASS();
}

void ColladaAnimationChannel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(keyframes,"keyframes");
}

Dynamic ColladaAnimationChannel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keyframes") ) { return keyframes; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaAnimationChannel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keyframes") ) { keyframes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaAnimationChannel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("keyframes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaAnimationChannel_obj,source),HX_CSTRING("source")},
	{hx::fsString,(int)offsetof(ColladaAnimationChannel_obj,target),HX_CSTRING("target")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaAnimationChannel_obj,keyframes),HX_CSTRING("keyframes")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("source"),
	HX_CSTRING("target"),
	HX_CSTRING("keyframes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaAnimationChannel_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaAnimationChannel_obj::__mClass,"__mClass");
};

#endif

Class ColladaAnimationChannel_obj::__mClass;

void ColladaAnimationChannel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaAnimationChannel"), hx::TCanCast< ColladaAnimationChannel_obj> ,sStaticFields,sMemberFields,
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

void ColladaAnimationChannel_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
