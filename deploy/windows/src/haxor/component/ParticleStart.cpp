#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleAttribute
#include <haxor/component/ParticleAttribute.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleStart
#include <haxor/component/ParticleStart.h>
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

Void ParticleStart_obj::__construct()
{
HX_STACK_FRAME("haxor.component.ParticleStart","new",0xbc7392f1,"haxor.component.ParticleStart.new","haxor/component/ParticleRenderer.hx",43,0x91e29536)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(44)
	::haxor::component::ParticleAttribute _g = ::haxor::component::ParticleAttribute_obj::__new(1.0,1.0,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	this->life = _g;
	HX_STACK_LINE(45)
	::haxor::component::ParticleAttribute _g1 = ::haxor::component::ParticleAttribute_obj::__new(1.0,1.0,null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(45)
	this->speed = _g1;
	HX_STACK_LINE(46)
	::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(46)
	::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(46)
	::haxor::component::ParticleAttribute _g4 = ::haxor::component::ParticleAttribute_obj::__new(_g2,_g3,null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(46)
	this->size = _g4;
	HX_STACK_LINE(47)
	::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(47)
	::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(47)
	::haxor::component::ParticleAttribute _g7 = ::haxor::component::ParticleAttribute_obj::__new(_g5,_g6,null(),null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(47)
	this->rotation = _g7;
	HX_STACK_LINE(48)
	::haxor::graphics::texture::Texture2D _g8 = ::haxor::graphics::texture::Texture2D_obj::get_white();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(48)
	this->color = _g8;
}
;
	return null();
}

//ParticleStart_obj::~ParticleStart_obj() { }

Dynamic ParticleStart_obj::__CreateEmpty() { return  new ParticleStart_obj; }
hx::ObjectPtr< ParticleStart_obj > ParticleStart_obj::__new()
{  hx::ObjectPtr< ParticleStart_obj > result = new ParticleStart_obj();
	result->__construct();
	return result;}

Dynamic ParticleStart_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleStart_obj > result = new ParticleStart_obj();
	result->__construct();
	return result;}


ParticleStart_obj::ParticleStart_obj()
{
}

void ParticleStart_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleStart);
	HX_MARK_MEMBER_NAME(life,"life");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_END_CLASS();
}

void ParticleStart_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(life,"life");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(size,"size");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(color,"color");
}

Dynamic ParticleStart_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"life") ) { return life; }
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleStart_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"life") ) { life=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleStart_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("life"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("color"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleStart_obj,life),HX_CSTRING("life")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleStart_obj,speed),HX_CSTRING("speed")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleStart_obj,size),HX_CSTRING("size")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleStart_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(ParticleStart_obj,color),HX_CSTRING("color")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("life"),
	HX_CSTRING("speed"),
	HX_CSTRING("size"),
	HX_CSTRING("rotation"),
	HX_CSTRING("color"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleStart_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleStart_obj::__mClass,"__mClass");
};

#endif

Class ParticleStart_obj::__mClass;

void ParticleStart_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleStart"), hx::TCanCast< ParticleStart_obj> ,sStaticFields,sMemberFields,
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

void ParticleStart_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
