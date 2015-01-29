#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_QuaternionKeyFrame
#include <haxor/component/animation/QuaternionKeyFrame.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void QuaternionKeyFrame_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.QuaternionKeyFrame","new",0xa6874005,"haxor.component.animation.QuaternionKeyFrame.new","haxor/component/animation/KeyFrame.hx",155,0xae9e4966)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(155)
	super::__construct();
	HX_STACK_LINE(155)
	::haxor::math::Quaternion _g = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(155)
	this->value = _g;
}
;
	return null();
}

//QuaternionKeyFrame_obj::~QuaternionKeyFrame_obj() { }

Dynamic QuaternionKeyFrame_obj::__CreateEmpty() { return  new QuaternionKeyFrame_obj; }
hx::ObjectPtr< QuaternionKeyFrame_obj > QuaternionKeyFrame_obj::__new()
{  hx::ObjectPtr< QuaternionKeyFrame_obj > result = new QuaternionKeyFrame_obj();
	result->__construct();
	return result;}

Dynamic QuaternionKeyFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< QuaternionKeyFrame_obj > result = new QuaternionKeyFrame_obj();
	result->__construct();
	return result;}

::haxor::component::animation::KeyFrame QuaternionKeyFrame_obj::Blend( ::haxor::component::animation::KeyFrame b,Float r){
	HX_STACK_FRAME("haxor.component.animation.QuaternionKeyFrame","Blend",0x75ccbb16,"haxor.component.animation.QuaternionKeyFrame.Blend","haxor/component/animation/KeyFrame.hx",164,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(165)
	this->changed = true;
	HX_STACK_LINE(166)
	::haxor::component::animation::QuaternionKeyFrame ka = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(ka,"ka");
	HX_STACK_LINE(167)
	::haxor::component::animation::QuaternionKeyFrame kb = b;		HX_STACK_VAR(kb,"kb");
	HX_STACK_LINE(168)
	::haxor::math::Quaternion va = ka->value;		HX_STACK_VAR(va,"va");
	HX_STACK_LINE(169)
	::haxor::math::Quaternion vb = kb->value;		HX_STACK_VAR(vb,"vb");
	HX_STACK_LINE(170)
	Float _g = ::Math_obj::abs((va->x - vb->x));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(170)
	if (((_g < 0.0001))){
		HX_STACK_LINE(171)
		Float _g1 = ::Math_obj::abs((va->y - vb->y));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(171)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(172)
			Float _g2 = ::Math_obj::abs((va->z - vb->z));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(172)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(173)
				Float _g3 = ::Math_obj::abs((va->w - vb->w));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(173)
				if (((_g3 < 0.0001))){
					HX_STACK_LINE(173)
					return ka;
				}
			}
		}
	}
	HX_STACK_LINE(174)
	::haxor::component::animation::QuaternionKeyFrame k = ::haxor::component::animation::QuaternionKeyFrame_obj::m_temp;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(175)
	::haxor::math::Quaternion _g4 = ::haxor::math::Quaternion_obj::Lerp(va,vb,r,k->value);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(175)
	k->value = _g4;
	HX_STACK_LINE(177)
	k->changed = true;
	HX_STACK_LINE(178)
	return k;
}


Dynamic QuaternionKeyFrame_obj::Sample( Dynamic v,hx::Null< Float >  __o_w){
Float w = __o_w.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.QuaternionKeyFrame","Sample",0x194af9c5,"haxor.component.animation.QuaternionKeyFrame.Sample","haxor/component/animation/KeyFrame.hx",187,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(w,"w")
{
		HX_STACK_LINE(187)
		if (((v == null()))){
			HX_STACK_LINE(187)
			return this->value;
		}
		else{
			HX_STACK_LINE(187)
			::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(187)
			{
				HX_STACK_LINE(187)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(187)
				int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(187)
				_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(187)
			return ::haxor::math::Quaternion_obj::Lerp(v,this->value,w,_g1);
		}
		HX_STACK_LINE(187)
		return null();
	}
}


::haxor::component::animation::QuaternionKeyFrame QuaternionKeyFrame_obj::m_temp;


QuaternionKeyFrame_obj::QuaternionKeyFrame_obj()
{
}

void QuaternionKeyFrame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(QuaternionKeyFrame);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void QuaternionKeyFrame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic QuaternionKeyFrame_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic QuaternionKeyFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_temp") ) { m_temp=inValue.Cast< ::haxor::component::animation::QuaternionKeyFrame >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void QuaternionKeyFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_temp"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(QuaternionKeyFrame_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("value"),
	HX_CSTRING("Blend"),
	HX_CSTRING("Sample"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(QuaternionKeyFrame_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(QuaternionKeyFrame_obj::m_temp,"m_temp");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(QuaternionKeyFrame_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(QuaternionKeyFrame_obj::m_temp,"m_temp");
};

#endif

Class QuaternionKeyFrame_obj::__mClass;

void QuaternionKeyFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.QuaternionKeyFrame"), hx::TCanCast< QuaternionKeyFrame_obj> ,sStaticFields,sMemberFields,
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

void QuaternionKeyFrame_obj::__boot()
{
	m_temp= ::haxor::component::animation::QuaternionKeyFrame_obj::__new();
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
