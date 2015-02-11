#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleAttribute
#include <haxor/component/ParticleAttribute.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleLife
#include <haxor/component/ParticleLife.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
namespace haxor{
namespace component{

Void ParticleLife_obj::__construct()
{
HX_STACK_FRAME("haxor.component.ParticleLife","new",0xed9d7df1,"haxor.component.ParticleLife.new","haxor/component/ParticleRenderer.hx",62,0x91e29536)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(63)
	::haxor::component::ParticleAttribute _g = ::haxor::component::ParticleAttribute_obj::__new(1.0,1.0,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(63)
	this->speed = _g;
	HX_STACK_LINE(64)
	::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(64)
	::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(64)
	::haxor::component::ParticleAttribute _g3 = ::haxor::component::ParticleAttribute_obj::__new(_g1,_g2,null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(64)
	this->motion = _g3;
	HX_STACK_LINE(65)
	::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(65)
	::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(65)
	::haxor::component::ParticleAttribute _g6 = ::haxor::component::ParticleAttribute_obj::__new(_g4,_g5,null(),null());		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(65)
	this->size = _g6;
	HX_STACK_LINE(66)
	::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(66)
	::haxor::math::Vector3 _g8 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(66)
	::haxor::component::ParticleAttribute _g9 = ::haxor::component::ParticleAttribute_obj::__new(_g7,_g8,null(),null());		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(66)
	this->rotation = _g9;
	HX_STACK_LINE(67)
	::haxor::graphics::texture::Texture2D _g10 = ::haxor::graphics::texture::Texture2D_obj::get_white();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(67)
	this->color = _g10;
}
;
	return null();
}

//ParticleLife_obj::~ParticleLife_obj() { }

Dynamic ParticleLife_obj::__CreateEmpty() { return  new ParticleLife_obj; }
hx::ObjectPtr< ParticleLife_obj > ParticleLife_obj::__new()
{  hx::ObjectPtr< ParticleLife_obj > result = new ParticleLife_obj();
	result->__construct();
	return result;}

Dynamic ParticleLife_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleLife_obj > result = new ParticleLife_obj();
	result->__construct();
	return result;}


ParticleLife_obj::ParticleLife_obj()
{
}

void ParticleLife_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleLife);
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(motion,"motion");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_END_CLASS();
}

void ParticleLife_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(motion,"motion");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(color,"color");
}

Dynamic ParticleLife_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"motion") ) { return motion; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleLife_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"motion") ) { motion=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleLife_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("motion"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("color"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleLife_obj,speed),HX_CSTRING("speed")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleLife_obj,motion),HX_CSTRING("motion")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleLife_obj,size),HX_CSTRING("size")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleLife_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(ParticleLife_obj,color),HX_CSTRING("color")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("speed"),
	HX_CSTRING("motion"),
	HX_CSTRING("size"),
	HX_CSTRING("rotation"),
	HX_CSTRING("color"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleLife_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleLife_obj::__mClass,"__mClass");
};

#endif

Class ParticleLife_obj::__mClass;

void ParticleLife_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleLife"), hx::TCanCast< ParticleLife_obj> ,sStaticFields,sMemberFields,
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

void ParticleLife_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
