#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_component_animation_AnimationClip
#include <haxor/component/animation/AnimationClip.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void Animation_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.Animation","new",0xefc3230f,"haxor.component.animation.Animation.new","haxor/component/animation/Animation.hx",86,0xcccd1d84)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(87)
	super::__construct(null());
	HX_STACK_LINE(88)
	::haxor::component::animation::Animation_obj::m_list->push(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(89)
	this->clips = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(90)
	this->m_time = (int)0;
	HX_STACK_LINE(91)
	this->reverse = false;
	HX_STACK_LINE(92)
	this->m_clock = ::haxor::core::Time_obj::m_elapsed;
	HX_STACK_LINE(93)
	this->m_fade_elapsed = 0.0;
	HX_STACK_LINE(94)
	this->m_fade_duration = 0.0;
}
;
	return null();
}

//Animation_obj::~Animation_obj() { }

Dynamic Animation_obj::__CreateEmpty() { return  new Animation_obj; }
hx::ObjectPtr< Animation_obj > Animation_obj::__new()
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct();
	return result;}

Dynamic Animation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct();
	return result;}

Float Animation_obj::get_time( ){
	HX_STACK_FRAME("haxor.component.animation.Animation","get_time",0xc6f31a87,"haxor.component.animation.Animation.get_time","haxor/component/animation/Animation.hx",59,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_LINE(59)
	return this->m_time;
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_time,return )

Float Animation_obj::set_time( Float v){
	HX_STACK_FRAME("haxor.component.animation.Animation","set_time",0x755073fb,"haxor.component.animation.Animation.set_time","haxor/component/animation/Animation.hx",61,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(62)
	this->m_time = v;
	HX_STACK_LINE(63)
	{
		HX_STACK_LINE(63)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(63)
		int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(63)
		while((true)){
			HX_STACK_LINE(63)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(63)
				break;
			}
			HX_STACK_LINE(63)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(63)
			this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >()->Sample(this->m_time,null());
		}
	}
	HX_STACK_LINE(64)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,set_time,return )

bool Animation_obj::get_playing( ){
	HX_STACK_FRAME("haxor.component.animation.Animation","get_playing",0x0d2a8934,"haxor.component.animation.Animation.get_playing","haxor/component/animation/Animation.hx",72,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	{
		HX_STACK_LINE(72)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(72)
		int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(72)
		while((true)){
			HX_STACK_LINE(72)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(72)
				break;
			}
			HX_STACK_LINE(72)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(72)
			if ((this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >()->playing)){
				HX_STACK_LINE(72)
				return true;
			}
		}
	}
	HX_STACK_LINE(72)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_playing,return )

bool Animation_obj::Contains( ::haxor::component::animation::AnimationClip p_clip){
	HX_STACK_FRAME("haxor.component.animation.Animation","Contains",0x0068a930,"haxor.component.animation.Animation.Contains","haxor/component/animation/Animation.hx",103,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_clip,"p_clip")
	HX_STACK_LINE(104)
	{
		HX_STACK_LINE(104)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(104)
		int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(104)
		while((true)){
			HX_STACK_LINE(104)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(104)
				break;
			}
			HX_STACK_LINE(104)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(104)
			if (((this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >() == p_clip))){
				HX_STACK_LINE(104)
				return true;
			}
		}
	}
	HX_STACK_LINE(105)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,Contains,return )

Void Animation_obj::Add( ::haxor::component::animation::AnimationClip p_clip){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Add",0xefa0fcb0,"haxor.component.animation.Animation.Add","haxor/component/animation/Animation.hx",113,0xcccd1d84)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_clip,"p_clip")
		HX_STACK_LINE(114)
		if ((this->Contains(p_clip))){
			HX_STACK_LINE(114)
			return null();
		}
		HX_STACK_LINE(116)
		this->clips->push(p_clip);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,Add,(void))

Void Animation_obj::Remove( ::haxor::component::animation::AnimationClip p_clip){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Remove",0x00395515,"haxor.component.animation.Animation.Remove","haxor/component/animation/Animation.hx",124,0xcccd1d84)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_clip,"p_clip")
		HX_STACK_LINE(125)
		if ((!(this->Contains(p_clip)))){
			HX_STACK_LINE(125)
			return null();
		}
		HX_STACK_LINE(126)
		this->clips->remove(p_clip);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,Remove,(void))

::haxor::component::animation::AnimationClip Animation_obj::Get( ::String p_clip_name){
	HX_STACK_FRAME("haxor.component.animation.Animation","Get",0xefa58b25,"haxor.component.animation.Animation.Get","haxor/component/animation/Animation.hx",135,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_clip_name,"p_clip_name")
	HX_STACK_LINE(136)
	{
		HX_STACK_LINE(136)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(136)
		int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(136)
		while((true)){
			HX_STACK_LINE(136)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(136)
				break;
			}
			HX_STACK_LINE(136)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(136)
			::String _g2 = this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >()->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(136)
			if (((_g2 == p_clip_name))){
				HX_STACK_LINE(136)
				return this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >();
			}
		}
	}
	HX_STACK_LINE(137)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,Get,return )

Void Animation_obj::Fade( ::haxor::component::animation::AnimationClip p_clip,hx::Null< Float >  __o_p_time,hx::Null< Float >  __o_p_fade){
Float p_time = __o_p_time.Default(0.0);
Float p_fade = __o_p_fade.Default(0.0);
	HX_STACK_FRAME("haxor.component.animation.Animation","Fade",0xc087e80d,"haxor.component.animation.Animation.Fade","haxor/component/animation/Animation.hx",147,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_clip,"p_clip")
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_ARG(p_fade,"p_fade")
{
		HX_STACK_LINE(148)
		this->Play(p_clip,p_time);
		HX_STACK_LINE(149)
		this->m_fade_elapsed = 0.0;
		HX_STACK_LINE(150)
		this->m_fade_duration = p_fade;
		HX_STACK_LINE(151)
		this->m_fade_clip = p_clip;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Animation_obj,Fade,(void))

Void Animation_obj::Play( ::haxor::component::animation::AnimationClip p_clip,hx::Null< Float >  __o_p_time){
Float p_time = __o_p_time.Default(0.0);
	HX_STACK_FRAME("haxor.component.animation.Animation","Play",0xc72c6085,"haxor.component.animation.Animation.Play","haxor/component/animation/Animation.hx",161,0xcccd1d84)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_clip,"p_clip")
	HX_STACK_ARG(p_time,"p_time")
{
		HX_STACK_LINE(162)
		if ((!(this->Contains(p_clip)))){
			HX_STACK_LINE(162)
			return null();
		}
		HX_STACK_LINE(163)
		this->m_time = p_time;
		HX_STACK_LINE(164)
		p_clip->Sample(p_time,null());
		HX_STACK_LINE(165)
		p_clip->playing = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Animation_obj,Play,(void))

Void Animation_obj::Stop( ::haxor::component::animation::AnimationClip p_clip){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Stop",0xc92e2293,"haxor.component.animation.Animation.Stop","haxor/component/animation/Animation.hx",174,0xcccd1d84)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_clip,"p_clip")
		HX_STACK_LINE(175)
		if (((p_clip == null()))){
			HX_STACK_LINE(175)
			{
				HX_STACK_LINE(175)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(175)
				int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(175)
				while((true)){
					HX_STACK_LINE(175)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(175)
						break;
					}
					HX_STACK_LINE(175)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(175)
					this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >()->playing = false;
				}
			}
			HX_STACK_LINE(175)
			return null();
		}
		HX_STACK_LINE(176)
		if ((!(this->Contains(p_clip)))){
			HX_STACK_LINE(176)
			return null();
		}
		HX_STACK_LINE(177)
		p_clip->playing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,Stop,(void))

Void Animation_obj::Animate( ){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Animate",0xb93dd8b0,"haxor.component.animation.Animation.Animate","haxor/component/animation/Animation.hx",184,0xcccd1d84)
		HX_STACK_THIS(this)
		HX_STACK_LINE(185)
		bool is_playing = false;		HX_STACK_VAR(is_playing,"is_playing");
		HX_STACK_LINE(187)
		if (((this->m_fade_elapsed >= this->m_fade_duration))){
			HX_STACK_LINE(187)
			this->m_fade_elapsed = this->m_fade_duration;
		}
		HX_STACK_LINE(189)
		Float w;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(189)
		if (((this->m_fade_duration <= 0.0))){
			HX_STACK_LINE(189)
			w = 1.0;
		}
		else{
			HX_STACK_LINE(189)
			w = (Float(this->m_fade_elapsed) / Float(this->m_fade_duration));
		}
		HX_STACK_LINE(192)
		Float spd = 1.0;		HX_STACK_VAR(spd,"spd");
		HX_STACK_LINE(193)
		{
			HX_STACK_LINE(193)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(193)
			int _g = this->clips->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(193)
			while((true)){
				HX_STACK_LINE(193)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(193)
					break;
				}
				HX_STACK_LINE(193)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(195)
				::haxor::component::animation::AnimationClip c = this->clips->__get(i).StaticCast< ::haxor::component::animation::AnimationClip >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(196)
				if ((c->playing)){
					HX_STACK_LINE(198)
					Float _g2 = this->get_time();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(198)
					c->Sample(_g2,w);
					HX_STACK_LINE(199)
					spd = c->speed;
					HX_STACK_LINE(200)
					is_playing = true;
				}
			}
		}
		HX_STACK_LINE(204)
		if (((w >= 1.0))){
			HX_STACK_LINE(206)
			this->m_fade_clip = null();
			HX_STACK_LINE(207)
			Float _g1 = this->m_fade_elapsed = 0.0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(207)
			this->m_fade_duration = _g1;
		}
		HX_STACK_LINE(212)
		Float dt = (::haxor::core::Time_obj::m_elapsed - this->m_clock);		HX_STACK_VAR(dt,"dt");
		HX_STACK_LINE(213)
		this->m_clock = ::haxor::core::Time_obj::m_elapsed;
		HX_STACK_LINE(215)
		if ((is_playing)){
			HX_STACK_LINE(217)
			hx::AddEq(this->m_time,(((  ((this->reverse)) ? Float(-(dt)) : Float(dt) )) * spd));
			HX_STACK_LINE(218)
			hx::AddEq(this->m_fade_elapsed,dt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,Animate,(void))

Array< ::Dynamic > Animation_obj::m_list;

int Animation_obj::m_iterator;

Void Animation_obj::Update( ){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Update",0x82b63eda,"haxor.component.animation.Animation.Update","haxor/component/animation/Animation.hx",25,0xcccd1d84)
		HX_STACK_LINE(25)
		if (((::haxor::component::animation::Animation_obj::m_list->length > (int)0))){
			HX_STACK_LINE(27)
			Float _g = ::Math_obj::max((Float(::haxor::component::animation::Animation_obj::m_list->length) / Float((int)2)),(int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(27)
			int steps = ::Std_obj::_int(_g);		HX_STACK_VAR(steps,"steps");
			HX_STACK_LINE(28)
			{
				HX_STACK_LINE(28)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(28)
				while((true)){
					HX_STACK_LINE(28)
					if ((!(((_g1 < steps))))){
						HX_STACK_LINE(28)
						break;
					}
					HX_STACK_LINE(28)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(30)
					::haxor::component::animation::Animation_obj::m_list->__get(::haxor::component::animation::Animation_obj::m_iterator).StaticCast< ::haxor::component::animation::Animation >()->Animate();
					HX_STACK_LINE(31)
					::haxor::component::animation::Animation_obj::m_iterator = hx::Mod(((::haxor::component::animation::Animation_obj::m_iterator + (int)1)),::haxor::component::animation::Animation_obj::m_list->length);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,Update,(void))

Void Animation_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.component.animation.Animation","Initialize",0x91e726a1,"haxor.component.animation.Animation.Initialize","haxor/component/animation/Animation.hx",40,0xcccd1d84)
		HX_STACK_LINE(41)
		::haxor::component::animation::Animation_obj::m_list = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(42)
		::haxor::component::animation::Animation_obj::m_iterator = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,Initialize,(void))


Animation_obj::Animation_obj()
{
}

void Animation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animation);
	HX_MARK_MEMBER_NAME(clips,"clips");
	HX_MARK_MEMBER_NAME(m_clock,"m_clock");
	HX_MARK_MEMBER_NAME(m_time,"m_time");
	HX_MARK_MEMBER_NAME(reverse,"reverse");
	HX_MARK_MEMBER_NAME(m_fade_elapsed,"m_fade_elapsed");
	HX_MARK_MEMBER_NAME(m_fade_duration,"m_fade_duration");
	HX_MARK_MEMBER_NAME(m_fade_clip,"m_fade_clip");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Animation_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clips,"clips");
	HX_VISIT_MEMBER_NAME(m_clock,"m_clock");
	HX_VISIT_MEMBER_NAME(m_time,"m_time");
	HX_VISIT_MEMBER_NAME(reverse,"reverse");
	HX_VISIT_MEMBER_NAME(m_fade_elapsed,"m_fade_elapsed");
	HX_VISIT_MEMBER_NAME(m_fade_duration,"m_fade_duration");
	HX_VISIT_MEMBER_NAME(m_fade_clip,"m_fade_clip");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Animation_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return get_time(); }
		if (HX_FIELD_EQ(inName,"Fade") ) { return Fade_dyn(); }
		if (HX_FIELD_EQ(inName,"Play") ) { return Play_dyn(); }
		if (HX_FIELD_EQ(inName,"Stop") ) { return Stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clips") ) { return clips; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { return m_list; }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"m_time") ) { return m_time; }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_clock") ) { return m_clock; }
		if (HX_FIELD_EQ(inName,"playing") ) { return get_playing(); }
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse; }
		if (HX_FIELD_EQ(inName,"Animate") ) { return Animate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_time") ) { return get_time_dyn(); }
		if (HX_FIELD_EQ(inName,"set_time") ) { return set_time_dyn(); }
		if (HX_FIELD_EQ(inName,"Contains") ) { return Contains_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_iterator") ) { return m_iterator; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_playing") ) { return get_playing_dyn(); }
		if (HX_FIELD_EQ(inName,"m_fade_clip") ) { return m_fade_clip; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_fade_elapsed") ) { return m_fade_elapsed; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_fade_duration") ) { return m_fade_duration; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return set_time(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clips") ) { clips=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { m_list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_time") ) { m_time=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_clock") ) { m_clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"reverse") ) { reverse=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_iterator") ) { m_iterator=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_fade_clip") ) { m_fade_clip=inValue.Cast< ::haxor::component::animation::AnimationClip >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_fade_elapsed") ) { m_fade_elapsed=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_fade_duration") ) { m_fade_duration=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animation_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clips"));
	outFields->push(HX_CSTRING("m_clock"));
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("m_time"));
	outFields->push(HX_CSTRING("playing"));
	outFields->push(HX_CSTRING("reverse"));
	outFields->push(HX_CSTRING("m_fade_elapsed"));
	outFields->push(HX_CSTRING("m_fade_duration"));
	outFields->push(HX_CSTRING("m_fade_clip"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_list"),
	HX_CSTRING("m_iterator"),
	HX_CSTRING("Update"),
	HX_CSTRING("Initialize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Animation_obj,clips),HX_CSTRING("clips")},
	{hx::fsFloat,(int)offsetof(Animation_obj,m_clock),HX_CSTRING("m_clock")},
	{hx::fsFloat,(int)offsetof(Animation_obj,m_time),HX_CSTRING("m_time")},
	{hx::fsBool,(int)offsetof(Animation_obj,reverse),HX_CSTRING("reverse")},
	{hx::fsFloat,(int)offsetof(Animation_obj,m_fade_elapsed),HX_CSTRING("m_fade_elapsed")},
	{hx::fsFloat,(int)offsetof(Animation_obj,m_fade_duration),HX_CSTRING("m_fade_duration")},
	{hx::fsObject /*::haxor::component::animation::AnimationClip*/ ,(int)offsetof(Animation_obj,m_fade_clip),HX_CSTRING("m_fade_clip")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clips"),
	HX_CSTRING("m_clock"),
	HX_CSTRING("get_time"),
	HX_CSTRING("set_time"),
	HX_CSTRING("m_time"),
	HX_CSTRING("get_playing"),
	HX_CSTRING("reverse"),
	HX_CSTRING("m_fade_elapsed"),
	HX_CSTRING("m_fade_duration"),
	HX_CSTRING("m_fade_clip"),
	HX_CSTRING("Contains"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Get"),
	HX_CSTRING("Fade"),
	HX_CSTRING("Play"),
	HX_CSTRING("Stop"),
	HX_CSTRING("Animate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Animation_obj::m_list,"m_list");
	HX_MARK_MEMBER_NAME(Animation_obj::m_iterator,"m_iterator");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Animation_obj::m_list,"m_list");
	HX_VISIT_MEMBER_NAME(Animation_obj::m_iterator,"m_iterator");
};

#endif

Class Animation_obj::__mClass;

void Animation_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.Animation"), hx::TCanCast< Animation_obj> ,sStaticFields,sMemberFields,
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

void Animation_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
