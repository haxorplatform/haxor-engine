#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void KeyFrame_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.KeyFrame","new",0xf7c78307,"haxor.component.animation.KeyFrame.new","haxor/component/animation/KeyFrame.hx",25,0xae9e4966)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(25)
	this->time = (int)0;
	HX_STACK_LINE(25)
	this->changed = false;
}
;
	return null();
}

//KeyFrame_obj::~KeyFrame_obj() { }

Dynamic KeyFrame_obj::__CreateEmpty() { return  new KeyFrame_obj; }
hx::ObjectPtr< KeyFrame_obj > KeyFrame_obj::__new()
{  hx::ObjectPtr< KeyFrame_obj > result = new KeyFrame_obj();
	result->__construct();
	return result;}

Dynamic KeyFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyFrame_obj > result = new KeyFrame_obj();
	result->__construct();
	return result;}

::haxor::component::animation::KeyFrame KeyFrame_obj::Blend( ::haxor::component::animation::KeyFrame b,Float r){
	HX_STACK_FRAME("haxor.component.animation.KeyFrame","Blend",0xc9e54298,"haxor.component.animation.KeyFrame.Blend","haxor/component/animation/KeyFrame.hx",33,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(33)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(KeyFrame_obj,Blend,return )

Dynamic KeyFrame_obj::Sample( Dynamic v,hx::Null< Float >  __o_w){
Float w = __o_w.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.KeyFrame","Sample",0x5aa90403,"haxor.component.animation.KeyFrame.Sample","haxor/component/animation/KeyFrame.hx",41,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(w,"w")
{
		HX_STACK_LINE(41)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(KeyFrame_obj,Sample,return )


KeyFrame_obj::KeyFrame_obj()
{
}

Dynamic KeyFrame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Blend") ) { return Blend_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"changed") ) { return changed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic KeyFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"changed") ) { changed=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KeyFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("changed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(KeyFrame_obj,time),HX_CSTRING("time")},
	{hx::fsBool,(int)offsetof(KeyFrame_obj,changed),HX_CSTRING("changed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("time"),
	HX_CSTRING("changed"),
	HX_CSTRING("Blend"),
	HX_CSTRING("Sample"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyFrame_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KeyFrame_obj::__mClass,"__mClass");
};

#endif

Class KeyFrame_obj::__mClass;

void KeyFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.KeyFrame"), hx::TCanCast< KeyFrame_obj> ,sStaticFields,sMemberFields,
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

void KeyFrame_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
