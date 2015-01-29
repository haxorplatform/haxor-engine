#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Vector3KeyFrame
#include <haxor/component/animation/Vector3KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void Vector3KeyFrame_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.Vector3KeyFrame","new",0x5b261609,"haxor.component.animation.Vector3KeyFrame.new","haxor/component/animation/KeyFrame.hx",105,0xae9e4966)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(105)
	super::__construct();
	HX_STACK_LINE(105)
	::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(105)
	this->value = _g;
}
;
	return null();
}

//Vector3KeyFrame_obj::~Vector3KeyFrame_obj() { }

Dynamic Vector3KeyFrame_obj::__CreateEmpty() { return  new Vector3KeyFrame_obj; }
hx::ObjectPtr< Vector3KeyFrame_obj > Vector3KeyFrame_obj::__new()
{  hx::ObjectPtr< Vector3KeyFrame_obj > result = new Vector3KeyFrame_obj();
	result->__construct();
	return result;}

Dynamic Vector3KeyFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector3KeyFrame_obj > result = new Vector3KeyFrame_obj();
	result->__construct();
	return result;}

::haxor::component::animation::KeyFrame Vector3KeyFrame_obj::Blend( ::haxor::component::animation::KeyFrame b,Float r){
	HX_STACK_FRAME("haxor.component.animation.Vector3KeyFrame","Blend",0xb0501a1a,"haxor.component.animation.Vector3KeyFrame.Blend","haxor/component/animation/KeyFrame.hx",114,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(115)
	this->changed = false;
	HX_STACK_LINE(116)
	::haxor::component::animation::Vector3KeyFrame ka = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(ka,"ka");
	HX_STACK_LINE(117)
	::haxor::component::animation::Vector3KeyFrame kb = b;		HX_STACK_VAR(kb,"kb");
	HX_STACK_LINE(118)
	::haxor::math::Vector3 va = ka->value;		HX_STACK_VAR(va,"va");
	HX_STACK_LINE(119)
	::haxor::math::Vector3 vb = kb->value;		HX_STACK_VAR(vb,"vb");
	HX_STACK_LINE(120)
	Float _g = ::Math_obj::abs((va->x - vb->x));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(120)
	if (((_g < 0.0001))){
		HX_STACK_LINE(121)
		Float _g1 = ::Math_obj::abs((va->y - vb->y));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(121)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(122)
			Float _g2 = ::Math_obj::abs((va->z - vb->z));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(122)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(122)
				return ka;
			}
		}
	}
	HX_STACK_LINE(123)
	::haxor::component::animation::Vector3KeyFrame k = ::haxor::component::animation::Vector3KeyFrame_obj::m_temp;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(124)
	::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::Lerp(va,vb,r,k->value);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(124)
	k->value = _g3;
	HX_STACK_LINE(126)
	k->changed = true;
	HX_STACK_LINE(127)
	return k;
}


Dynamic Vector3KeyFrame_obj::Sample( Dynamic v,hx::Null< Float >  __o_w){
Float w = __o_w.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.Vector3KeyFrame","Sample",0x11babe41,"haxor.component.animation.Vector3KeyFrame.Sample","haxor/component/animation/KeyFrame.hx",136,0xae9e4966)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(w,"w")
{
		HX_STACK_LINE(136)
		if (((v == null()))){
			HX_STACK_LINE(136)
			return this->value;
		}
		else{
			HX_STACK_LINE(136)
			::haxor::math::Vector3 _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(136)
			{
				HX_STACK_LINE(136)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(136)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(136)
				_g1 = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			HX_STACK_LINE(136)
			return ::haxor::math::Vector3_obj::Lerp(v,this->value,w,_g1);
		}
		HX_STACK_LINE(136)
		return null();
	}
}


::haxor::component::animation::Vector3KeyFrame Vector3KeyFrame_obj::m_temp;


Vector3KeyFrame_obj::Vector3KeyFrame_obj()
{
}

void Vector3KeyFrame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector3KeyFrame);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void Vector3KeyFrame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic Vector3KeyFrame_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Vector3KeyFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_temp") ) { m_temp=inValue.Cast< ::haxor::component::animation::Vector3KeyFrame >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector3KeyFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_temp"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3KeyFrame_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("value"),
	HX_CSTRING("Blend"),
	HX_CSTRING("Sample"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector3KeyFrame_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vector3KeyFrame_obj::m_temp,"m_temp");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector3KeyFrame_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vector3KeyFrame_obj::m_temp,"m_temp");
};

#endif

Class Vector3KeyFrame_obj::__mClass;

void Vector3KeyFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.Vector3KeyFrame"), hx::TCanCast< Vector3KeyFrame_obj> ,sStaticFields,sMemberFields,
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

void Vector3KeyFrame_obj::__boot()
{
	m_temp= ::haxor::component::animation::Vector3KeyFrame_obj::__new();
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
