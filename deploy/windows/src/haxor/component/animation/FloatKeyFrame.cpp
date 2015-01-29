#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_FloatKeyFrame
#include <haxor/component/animation/FloatKeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void FloatKeyFrame_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.FloatKeyFrame","new",0xcd42ab55,"haxor.component.animation.FloatKeyFrame.new","haxor/component/animation/KeyFrame.hx",59,0xae9e4966)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(59)
	super::__construct();
	HX_STACK_LINE(59)
	this->value = (int)0;
}
;
	return null();
}

//FloatKeyFrame_obj::~FloatKeyFrame_obj() { }

Dynamic FloatKeyFrame_obj::__CreateEmpty() { return  new FloatKeyFrame_obj; }
hx::ObjectPtr< FloatKeyFrame_obj > FloatKeyFrame_obj::__new()
{  hx::ObjectPtr< FloatKeyFrame_obj > result = new FloatKeyFrame_obj();
	result->__construct();
	return result;}

Dynamic FloatKeyFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatKeyFrame_obj > result = new FloatKeyFrame_obj();
	result->__construct();
	return result;}

::haxor::component::animation::KeyFrame FloatKeyFrame_obj::Blend( ::haxor::component::animation::KeyFrame b,Float r){
	HX_STACK_FRAME("haxor.component.animation.FloatKeyFrame","Blend",0x52b59a66,"haxor.component.animation.FloatKeyFrame.Blend","haxor/component/animation/KeyFrame.hx",68,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(69)
	this->changed = false;
	HX_STACK_LINE(70)
	::haxor::component::animation::FloatKeyFrame ka = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(ka,"ka");
	HX_STACK_LINE(71)
	::haxor::component::animation::FloatKeyFrame kb = b;		HX_STACK_VAR(kb,"kb");
	HX_STACK_LINE(72)
	Float va = ka->value;		HX_STACK_VAR(va,"va");
	HX_STACK_LINE(73)
	Float vb = kb->value;		HX_STACK_VAR(vb,"vb");
	HX_STACK_LINE(74)
	Float _g = ::Math_obj::abs((va - vb));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	if (((_g < 0.0001))){
		HX_STACK_LINE(74)
		return ka;
	}
	HX_STACK_LINE(75)
	::haxor::component::animation::FloatKeyFrame k = ::haxor::component::animation::FloatKeyFrame_obj::m_temp;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(76)
	{
		HX_STACK_LINE(76)
		Float p_a = ka->value;		HX_STACK_VAR(p_a,"p_a");
		HX_STACK_LINE(76)
		k->value = (p_a + (((kb->value - p_a)) * r));
	}
	HX_STACK_LINE(77)
	k->changed = true;
	HX_STACK_LINE(78)
	return k;
}


Dynamic FloatKeyFrame_obj::Sample( Dynamic v,hx::Null< Float >  __o_w){
Float w = __o_w.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.FloatKeyFrame","Sample",0x88258075,"haxor.component.animation.FloatKeyFrame.Sample","haxor/component/animation/KeyFrame.hx",87,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(w,"w")
{
		HX_STACK_LINE(87)
		if (((v == null()))){
			HX_STACK_LINE(87)
			return this->value;
		}
		else{
			HX_STACK_LINE(87)
			Float p_a = v;		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(87)
			return (p_a + (((this->value - p_a)) * w));
		}
		HX_STACK_LINE(87)
		return null();
	}
}


::haxor::component::animation::FloatKeyFrame FloatKeyFrame_obj::m_temp;


FloatKeyFrame_obj::FloatKeyFrame_obj()
{
}

Dynamic FloatKeyFrame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
		if (HX_FIELD_EQ(inName,"Blend") ) { return Blend_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_temp") ) { return m_temp; }
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatKeyFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_temp") ) { m_temp=inValue.Cast< ::haxor::component::animation::FloatKeyFrame >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatKeyFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_temp"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FloatKeyFrame_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("value"),
	HX_CSTRING("Blend"),
	HX_CSTRING("Sample"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatKeyFrame_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FloatKeyFrame_obj::m_temp,"m_temp");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatKeyFrame_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FloatKeyFrame_obj::m_temp,"m_temp");
};

#endif

Class FloatKeyFrame_obj::__mClass;

void FloatKeyFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.FloatKeyFrame"), hx::TCanCast< FloatKeyFrame_obj> ,sStaticFields,sMemberFields,
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

void FloatKeyFrame_obj::__boot()
{
	m_temp= ::haxor::component::animation::FloatKeyFrame_obj::__new();
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
