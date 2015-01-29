#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_component_animation_ClipTrack
#include <haxor/component/animation/ClipTrack.h>
#endif
#ifndef INCLUDED_haxor_component_animation_FloatKeyFrame
#include <haxor/component/animation/FloatKeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_QuaternionKeyFrame
#include <haxor/component/animation/QuaternionKeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Vector3KeyFrame
#include <haxor/component/animation/Vector3KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
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

Void ClipTrack_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.ClipTrack","new",0x3cd5a926,"haxor.component.animation.ClipTrack.new","haxor/component/animation/ClipTrack.hx",44,0x6f03274d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(45)
	this->target = null();
	HX_STACK_LINE(46)
	this->keyframes = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(47)
	this->property = HX_CSTRING("");
	HX_STACK_LINE(48)
	this->m_head = (int)0;
	HX_STACK_LINE(49)
	this->m_length = (int)0;
}
;
	return null();
}

//ClipTrack_obj::~ClipTrack_obj() { }

Dynamic ClipTrack_obj::__CreateEmpty() { return  new ClipTrack_obj; }
hx::ObjectPtr< ClipTrack_obj > ClipTrack_obj::__new()
{  hx::ObjectPtr< ClipTrack_obj > result = new ClipTrack_obj();
	result->__construct();
	return result;}

Dynamic ClipTrack_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ClipTrack_obj > result = new ClipTrack_obj();
	result->__construct();
	return result;}

Float ClipTrack_obj::get_length( ){
	HX_STACK_FRAME("haxor.component.animation.ClipTrack","get_length",0x227c70a9,"haxor.component.animation.ClipTrack.get_length","haxor/component/animation/ClipTrack.hx",35,0x6f03274d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(35)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(ClipTrack_obj,get_length,return )

::haxor::component::animation::KeyFrame ClipTrack_obj::Add( Float p_time,Dynamic p_value){
	HX_STACK_FRAME("haxor.component.animation.ClipTrack","Add",0x3cb382c7,"haxor.component.animation.ClipTrack.Add","haxor/component/animation/ClipTrack.hx",59,0x6f03274d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_ARG(p_value,"p_value")
	HX_STACK_LINE(60)
	::haxor::component::animation::KeyFrame k = null();		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(61)
	if ((::Std_obj::is(p_value,hx::ClassOf< ::Float >()))){
		HX_STACK_LINE(61)
		::haxor::component::animation::FloatKeyFrame _g = ::haxor::component::animation::FloatKeyFrame_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		::haxor::component::animation::FloatKeyFrame nk = k = _g;		HX_STACK_VAR(nk,"nk");
		HX_STACK_LINE(61)
		nk->time = p_time;
		HX_STACK_LINE(61)
		nk->value = p_value;
	}
	else{
		HX_STACK_LINE(62)
		if ((::Std_obj::is(p_value,hx::ClassOf< ::haxor::math::Vector3 >()))){
			HX_STACK_LINE(62)
			::haxor::component::animation::Vector3KeyFrame _g1 = ::haxor::component::animation::Vector3KeyFrame_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(62)
			::haxor::component::animation::Vector3KeyFrame nk = k = _g1;		HX_STACK_VAR(nk,"nk");
			HX_STACK_LINE(62)
			nk->time = p_time;
			HX_STACK_LINE(62)
			nk->value = p_value;
		}
		else{
			HX_STACK_LINE(63)
			if ((::Std_obj::is(p_value,hx::ClassOf< ::haxor::math::Quaternion >()))){
				HX_STACK_LINE(63)
				::haxor::component::animation::QuaternionKeyFrame _g2 = ::haxor::component::animation::QuaternionKeyFrame_obj::__new();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(63)
				::haxor::component::animation::QuaternionKeyFrame nk = k = _g2;		HX_STACK_VAR(nk,"nk");
				HX_STACK_LINE(63)
				nk->time = p_time;
				HX_STACK_LINE(63)
				nk->value = p_value;
			}
		}
	}
	HX_STACK_LINE(65)
	if (((k != null()))){
		HX_STACK_LINE(67)
		this->keyframes->push(k);
		HX_STACK_LINE(68)
		Float _g3 = ::Math_obj::max(k->time,this->m_length);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(68)
		this->m_length = _g3;
	}
	HX_STACK_LINE(71)
	return k;
}


HX_DEFINE_DYNAMIC_FUNC2(ClipTrack_obj,Add,return )

int ClipTrack_obj::Sample( Float p_time,hx::Null< Float >  __o_p_weight){
Float p_weight = __o_p_weight.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.ClipTrack","Sample",0x64f43b44,"haxor.component.animation.ClipTrack.Sample","haxor/component/animation/ClipTrack.hx",81,0x6f03274d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_ARG(p_weight,"p_weight")
{
		HX_STACK_LINE(82)
		if (((this->keyframes->length <= (int)0))){
			HX_STACK_LINE(82)
			return (int)0;
		}
		HX_STACK_LINE(83)
		if (((this->keyframes->length <= (int)1))){
			HX_STACK_LINE(83)
			{
				HX_STACK_LINE(83)
				Dynamic o = this->target;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(83)
				Dynamic value = this->keyframes->__get((int)0).StaticCast< ::haxor::component::animation::KeyFrame >()->Sample(null(),null());		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(83)
				if (((o != null()))){
					HX_STACK_LINE(83)
					o->__SetField(this->property,value,true);
				}
			}
			HX_STACK_LINE(83)
			return (int)0;
		}
		HX_STACK_LINE(85)
		int mid = ::Std_obj::_int((Float(this->keyframes->length) / Float((int)2)));		HX_STACK_VAR(mid,"mid");
		HX_STACK_LINE(86)
		int step = ::Std_obj::_int((Float(this->keyframes->length) / Float((int)2)));		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(87)
		int i0 = (int)-1;		HX_STACK_VAR(i0,"i0");
		HX_STACK_LINE(90)
		{
			HX_STACK_LINE(90)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(90)
			int _g = this->keyframes->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(90)
			while((true)){
				HX_STACK_LINE(90)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(90)
					break;
				}
				HX_STACK_LINE(90)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(93)
				int _g2;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(93)
				{
					HX_STACK_LINE(93)
					int p_max = (this->keyframes->length - (int)1);		HX_STACK_VAR(p_max,"p_max");
					HX_STACK_LINE(93)
					_g2 = ::Std_obj::_int((  (((mid <= (int)0))) ? Float((int)0) : Float((  (((mid >= p_max))) ? Float(p_max) : Float(mid) )) ));
				}
				HX_STACK_LINE(93)
				i0 = _g2;
				HX_STACK_LINE(94)
				int i1;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(94)
				{
					HX_STACK_LINE(94)
					int p_v = (mid + (int)1);		HX_STACK_VAR(p_v,"p_v");
					HX_STACK_LINE(94)
					int p_max = (this->keyframes->length - (int)1);		HX_STACK_VAR(p_max,"p_max");
					HX_STACK_LINE(94)
					i1 = ::Std_obj::_int((  (((p_v <= (int)0))) ? Float((int)0) : Float((  (((p_v >= p_max))) ? Float(p_max) : Float(p_v) )) ));
				}
				HX_STACK_LINE(95)
				::haxor::component::animation::KeyFrame k0 = this->keyframes->__get(i0).StaticCast< ::haxor::component::animation::KeyFrame >();		HX_STACK_VAR(k0,"k0");
				HX_STACK_LINE(96)
				::haxor::component::animation::KeyFrame k1 = this->keyframes->__get(i1).StaticCast< ::haxor::component::animation::KeyFrame >();		HX_STACK_VAR(k1,"k1");
				HX_STACK_LINE(98)
				if (((p_time < k0->time))){
					HX_STACK_LINE(98)
					step = (Float(step) / Float((int)2));
					HX_STACK_LINE(98)
					hx::SubEq(mid,step);
					HX_STACK_LINE(98)
					continue;
				}
				HX_STACK_LINE(99)
				if (((p_time > k1->time))){
					HX_STACK_LINE(99)
					step = (Float(step) / Float((int)2));
					HX_STACK_LINE(99)
					hx::AddEq(mid,step);
					HX_STACK_LINE(99)
					continue;
				}
				HX_STACK_LINE(101)
				Float dt = (k1->time - k0->time);		HX_STACK_VAR(dt,"dt");
				HX_STACK_LINE(102)
				Float r;		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(102)
				if (((dt <= (int)0))){
					HX_STACK_LINE(102)
					r = 0.0;
				}
				else{
					HX_STACK_LINE(102)
					r = (Float(((p_time - k0->time))) / Float(dt));
				}
				HX_STACK_LINE(103)
				if (((r <= 0.0))){
					HX_STACK_LINE(103)
					r = 0.0;
				}
				else{
					HX_STACK_LINE(103)
					if (((r >= 1.0))){
						HX_STACK_LINE(103)
						r = 1.0;
					}
					else{
						HX_STACK_LINE(103)
						r = r;
					}
				}
				HX_STACK_LINE(104)
				::haxor::component::animation::KeyFrame nk = k0->Blend(k1,r);		HX_STACK_VAR(nk,"nk");
				HX_STACK_LINE(105)
				if ((nk->changed)){
					HX_STACK_LINE(107)
					Dynamic v;		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(107)
					{
						HX_STACK_LINE(107)
						Dynamic o = this->target;		HX_STACK_VAR(o,"o");
						HX_STACK_LINE(107)
						if (((o == null()))){
							HX_STACK_LINE(107)
							v = null();
						}
						else{
							HX_STACK_LINE(107)
							v = o->__Field(this->property,true);
						}
					}
					HX_STACK_LINE(108)
					{
						HX_STACK_LINE(108)
						Dynamic o = this->target;		HX_STACK_VAR(o,"o");
						HX_STACK_LINE(108)
						Dynamic value = nk->Sample(v,p_weight);		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(108)
						if (((o != null()))){
							HX_STACK_LINE(108)
							o->__SetField(this->property,value,true);
						}
					}
				}
				HX_STACK_LINE(110)
				break;
			}
		}
		HX_STACK_LINE(112)
		return i0;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(ClipTrack_obj,Sample,return )

::haxor::component::animation::ClipTrack ClipTrack_obj::Split( int p_start,int p_end){
	HX_STACK_FRAME("haxor.component.animation.ClipTrack","Split",0xd7da7100,"haxor.component.animation.ClipTrack.Split","haxor/component/animation/ClipTrack.hx",122,0x6f03274d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_start,"p_start")
	HX_STACK_ARG(p_end,"p_end")
	HX_STACK_LINE(123)
	::haxor::component::animation::ClipTrack nct = ::haxor::component::animation::ClipTrack_obj::__new();		HX_STACK_VAR(nct,"nct");
	HX_STACK_LINE(124)
	nct->target = this->target;
	HX_STACK_LINE(125)
	nct->property = this->property;
	HX_STACK_LINE(126)
	int i0 = ::Math_obj::min(p_start,(this->keyframes->length - (int)1));		HX_STACK_VAR(i0,"i0");
	HX_STACK_LINE(127)
	int i1 = ::Math_obj::min(p_end,(this->keyframes->length - (int)1));		HX_STACK_VAR(i1,"i1");
	HX_STACK_LINE(128)
	::haxor::component::animation::KeyFrame kf = this->keyframes->__get(i0).StaticCast< ::haxor::component::animation::KeyFrame >();		HX_STACK_VAR(kf,"kf");
	HX_STACK_LINE(129)
	if (((kf == null()))){
		HX_STACK_LINE(129)
		return nct;
	}
	HX_STACK_LINE(130)
	Float t0 = kf->time;		HX_STACK_VAR(t0,"t0");
	HX_STACK_LINE(131)
	{
		HX_STACK_LINE(131)
		int _g = i0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(131)
		while((true)){
			HX_STACK_LINE(131)
			if ((!(((_g < i1))))){
				HX_STACK_LINE(131)
				break;
			}
			HX_STACK_LINE(131)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(133)
			kf = this->keyframes->__get(i).StaticCast< ::haxor::component::animation::KeyFrame >();
			HX_STACK_LINE(134)
			if (((kf != null()))){
				HX_STACK_LINE(134)
				Dynamic _g1 = kf->Sample(null(),null());		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(134)
				nct->Add((kf->time - t0),_g1);
			}
		}
	}
	HX_STACK_LINE(136)
	return nct;
}


HX_DEFINE_DYNAMIC_FUNC2(ClipTrack_obj,Split,return )

Void ClipTrack_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.component.animation.ClipTrack","Clear",0x9ec6f7b3,"haxor.component.animation.ClipTrack.Clear","haxor/component/animation/ClipTrack.hx",143,0x6f03274d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(144)
		this->keyframes = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(145)
		this->m_length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClipTrack_obj,Clear,(void))


ClipTrack_obj::ClipTrack_obj()
{
}

void ClipTrack_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ClipTrack);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(property,"property");
	HX_MARK_MEMBER_NAME(keyframes,"keyframes");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(m_head,"m_head");
	HX_MARK_END_CLASS();
}

void ClipTrack_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(property,"property");
	HX_VISIT_MEMBER_NAME(keyframes,"keyframes");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(m_head,"m_head");
}

Dynamic ClipTrack_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Split") ) { return Split_dyn(); }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		if (HX_FIELD_EQ(inName,"m_head") ) { return m_head; }
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"property") ) { return property; }
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keyframes") ) { return keyframes; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ClipTrack_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_head") ) { m_head=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"property") ) { property=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keyframes") ) { keyframes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ClipTrack_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("property"));
	outFields->push(HX_CSTRING("keyframes"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("m_head"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ClipTrack_obj,target),HX_CSTRING("target")},
	{hx::fsString,(int)offsetof(ClipTrack_obj,property),HX_CSTRING("property")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ClipTrack_obj,keyframes),HX_CSTRING("keyframes")},
	{hx::fsFloat,(int)offsetof(ClipTrack_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsInt,(int)offsetof(ClipTrack_obj,m_head),HX_CSTRING("m_head")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("target"),
	HX_CSTRING("property"),
	HX_CSTRING("keyframes"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("m_head"),
	HX_CSTRING("Add"),
	HX_CSTRING("Sample"),
	HX_CSTRING("Split"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ClipTrack_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ClipTrack_obj::__mClass,"__mClass");
};

#endif

Class ClipTrack_obj::__mClass;

void ClipTrack_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.ClipTrack"), hx::TCanCast< ClipTrack_obj> ,sStaticFields,sMemberFields,
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

void ClipTrack_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
