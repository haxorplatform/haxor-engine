#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleAttribute
#include <haxor/component/ParticleAttribute.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleSheet
#include <haxor/component/ParticleSheet.h>
#endif
#ifndef INCLUDED_haxor_core_AnimationWrap
#include <haxor/core/AnimationWrap.h>
#endif
namespace haxor{
namespace component{

Void ParticleSheet_obj::__construct()
{
HX_STACK_FRAME("haxor.component.ParticleSheet","new",0x81c863ae,"haxor.component.ParticleSheet.new","haxor/component/ParticleRenderer.hx",83,0x91e29536)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(85)
	this->width = 0.0;
	HX_STACK_LINE(86)
	this->height = 0.0;
	HX_STACK_LINE(87)
	this->length = (int)0;
	HX_STACK_LINE(88)
	this->fps = 60.0;
	HX_STACK_LINE(89)
	::haxor::component::ParticleAttribute _g = ::haxor::component::ParticleAttribute_obj::__new(0.0,0.0,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(89)
	this->frame = _g;
	HX_STACK_LINE(90)
	this->wrap = ::haxor::core::AnimationWrap_obj::Clamp;
	HX_STACK_LINE(91)
	this->reverse = false;
}
;
	return null();
}

//ParticleSheet_obj::~ParticleSheet_obj() { }

Dynamic ParticleSheet_obj::__CreateEmpty() { return  new ParticleSheet_obj; }
hx::ObjectPtr< ParticleSheet_obj > ParticleSheet_obj::__new()
{  hx::ObjectPtr< ParticleSheet_obj > result = new ParticleSheet_obj();
	result->__construct();
	return result;}

Dynamic ParticleSheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleSheet_obj > result = new ParticleSheet_obj();
	result->__construct();
	return result;}


ParticleSheet_obj::ParticleSheet_obj()
{
}

void ParticleSheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleSheet);
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(fps,"fps");
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(wrap,"wrap");
	HX_MARK_MEMBER_NAME(reverse,"reverse");
	HX_MARK_END_CLASS();
}

void ParticleSheet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(fps,"fps");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(wrap,"wrap");
	HX_VISIT_MEMBER_NAME(reverse,"reverse");
}

Dynamic ParticleSheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return fps; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { return wrap; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleSheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { wrap=inValue.Cast< ::haxor::core::AnimationWrap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { reverse=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleSheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("fps"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("wrap"));
	outFields->push(HX_CSTRING("reverse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(ParticleSheet_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(ParticleSheet_obj,height),HX_CSTRING("height")},
	{hx::fsInt,(int)offsetof(ParticleSheet_obj,length),HX_CSTRING("length")},
	{hx::fsFloat,(int)offsetof(ParticleSheet_obj,fps),HX_CSTRING("fps")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleSheet_obj,frame),HX_CSTRING("frame")},
	{hx::fsObject /*::haxor::core::AnimationWrap*/ ,(int)offsetof(ParticleSheet_obj,wrap),HX_CSTRING("wrap")},
	{hx::fsBool,(int)offsetof(ParticleSheet_obj,reverse),HX_CSTRING("reverse")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("length"),
	HX_CSTRING("fps"),
	HX_CSTRING("frame"),
	HX_CSTRING("wrap"),
	HX_CSTRING("reverse"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleSheet_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleSheet_obj::__mClass,"__mClass");
};

#endif

Class ParticleSheet_obj::__mClass;

void ParticleSheet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleSheet"), hx::TCanCast< ParticleSheet_obj> ,sStaticFields,sMemberFields,
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

void ParticleSheet_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
