#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_AnimationClip
#include <haxor/component/animation/AnimationClip.h>
#endif
#ifndef INCLUDED_haxor_component_animation_AnimationEvent
#include <haxor/component/animation/AnimationEvent.h>
#endif
#ifndef INCLUDED_haxor_component_animation_ClipTrack
#include <haxor/component/animation/ClipTrack.h>
#endif
#ifndef INCLUDED_haxor_core_AnimationWrap
#include <haxor/core/AnimationWrap.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_math_Mathf
#include <haxor/math/Mathf.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void AnimationClip_obj::__construct()
{
HX_STACK_FRAME("haxor.component.animation.AnimationClip","new",0x44e6c87f,"haxor.component.animation.AnimationClip.new","haxor/component/animation/AnimationClip.hx",48,0x00dcd394)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(49)
	super::__construct(null());
	HX_STACK_LINE(50)
	this->tracks = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(51)
	this->speed = 1.0;
	HX_STACK_LINE(52)
	this->playing = false;
	HX_STACK_LINE(53)
	this->m_length = (int)0;
	HX_STACK_LINE(54)
	this->wrap = ::haxor::core::AnimationWrap_obj::Clamp;
	HX_STACK_LINE(55)
	this->m_events = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(56)
	this->m_last_frame = (int)0;
}
;
	return null();
}

//AnimationClip_obj::~AnimationClip_obj() { }

Dynamic AnimationClip_obj::__CreateEmpty() { return  new AnimationClip_obj; }
hx::ObjectPtr< AnimationClip_obj > AnimationClip_obj::__new()
{  hx::ObjectPtr< AnimationClip_obj > result = new AnimationClip_obj();
	result->__construct();
	return result;}

Dynamic AnimationClip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationClip_obj > result = new AnimationClip_obj();
	result->__construct();
	return result;}

Float AnimationClip_obj::get_length( ){
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","get_length",0xace6de70,"haxor.component.animation.AnimationClip.get_length","haxor/component/animation/AnimationClip.hx",38,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationClip_obj,get_length,return )

Void AnimationClip_obj::AddEvent( int p_frame,Dynamic p_listener,hx::Null< int >  __o_p_repeat,Dynamic p_args){
int p_repeat = __o_p_repeat.Default(0);
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","AddEvent",0x998de1da,"haxor.component.animation.AnimationClip.AddEvent","haxor/component/animation/AnimationClip.hx",68,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_frame,"p_frame")
	HX_STACK_ARG(p_listener,"p_listener")
	HX_STACK_ARG(p_repeat,"p_repeat")
	HX_STACK_ARG(p_args,"p_args")
{
		HX_STACK_LINE(69)
		::haxor::component::animation::AnimationEvent e = ::haxor::component::animation::AnimationEvent_obj::__new(p_frame,p_listener,p_repeat,p_args);		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(70)
		this->m_events->push(e);

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(::haxor::component::animation::AnimationEvent a,::haxor::component::animation::AnimationEvent b){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/animation/AnimationClip.hx",73,0x00dcd394)
			HX_STACK_ARG(a,"a")
			HX_STACK_ARG(b,"b")
			{
				HX_STACK_LINE(73)
				if (((a->frame < b->frame))){
					HX_STACK_LINE(73)
					return (int)-1;
				}
				else{
					HX_STACK_LINE(73)
					return (int)1;
				}
				HX_STACK_LINE(73)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(71)
		this->m_events->sort( Dynamic(new _Function_1_1()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AnimationClip_obj,AddEvent,(void))

Void AnimationClip_obj::RemoveEvent( hx::Null< int >  __o_p_frame){
int p_frame = __o_p_frame.Default(-1);
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","RemoveEvent",0xe7b1ec35,"haxor.component.animation.AnimationClip.RemoveEvent","haxor/component/animation/AnimationClip.hx",82,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_frame,"p_frame")
{
		HX_STACK_LINE(83)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(84)
		while((true)){
			HX_STACK_LINE(84)
			if ((!(((i < this->m_events->length))))){
				HX_STACK_LINE(84)
				break;
			}
			HX_STACK_LINE(86)
			if (((bool((this->m_events->__get(i).StaticCast< ::haxor::component::animation::AnimationEvent >()->frame == p_frame)) || bool((p_frame < (int)0))))){
				HX_STACK_LINE(86)
				int _g = (i)--;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(86)
				::haxor::component::animation::AnimationEvent _g1 = this->m_events->__get(_g).StaticCast< ::haxor::component::animation::AnimationEvent >();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(86)
				this->m_events->remove(_g1);
			}
			HX_STACK_LINE(87)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationClip_obj,RemoveEvent,(void))

::haxor::component::animation::ClipTrack AnimationClip_obj::Add( Dynamic p_target,::String p_property){
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","Add",0x44c4a220,"haxor.component.animation.AnimationClip.Add","haxor/component/animation/AnimationClip.hx",98,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_target,"p_target")
	HX_STACK_ARG(p_property,"p_property")
	HX_STACK_LINE(99)
	::haxor::component::animation::ClipTrack ct = ::haxor::component::animation::ClipTrack_obj::__new();		HX_STACK_VAR(ct,"ct");
	HX_STACK_LINE(100)
	ct->target = p_target;
	HX_STACK_LINE(101)
	ct->property = p_property;
	HX_STACK_LINE(102)
	this->tracks->push(ct);
	HX_STACK_LINE(103)
	this->UpdateLength();
	HX_STACK_LINE(104)
	return ct;
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationClip_obj,Add,return )

Void AnimationClip_obj::Remove( Dynamic p_target,::String __o_p_property){
::String p_property = __o_p_property.Default(HX_CSTRING(""));
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","Remove",0x9d32b5a5,"haxor.component.animation.AnimationClip.Remove","haxor/component/animation/AnimationClip.hx",113,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_target,"p_target")
	HX_STACK_ARG(p_property,"p_property")
{
		HX_STACK_LINE(114)
		{
			HX_STACK_LINE(114)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(114)
			int _g = this->tracks->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(114)
			while((true)){
				HX_STACK_LINE(114)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(114)
					break;
				}
				HX_STACK_LINE(114)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(116)
				if (((this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >()->target == p_target))){
					HX_STACK_LINE(118)
					if (((p_property == HX_CSTRING("")))){
						HX_STACK_LINE(118)
						this->tracks->remove(this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >());
					}
					else{
						HX_STACK_LINE(120)
						if (((p_property == p_property))){
							HX_STACK_LINE(120)
							this->tracks->remove(this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >());
						}
					}
				}
			}
		}
		HX_STACK_LINE(123)
		this->UpdateLength();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationClip_obj,Remove,(void))

Void AnimationClip_obj::Sample( Float p_time,hx::Null< Float >  __o_p_weight){
Float p_weight = __o_p_weight.Default(1.0);
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","Sample",0xb5f4798b,"haxor.component.animation.AnimationClip.Sample","haxor/component/animation/AnimationClip.hx",132,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_ARG(p_weight,"p_weight")
{
		HX_STACK_LINE(133)
		if ((!(this->playing))){
			HX_STACK_LINE(133)
			return null();
		}
		HX_STACK_LINE(135)
		Float spd = ::Math_obj::max((int)0,this->speed);		HX_STACK_VAR(spd,"spd");
		HX_STACK_LINE(136)
		Float t = p_time;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			::haxor::core::AnimationWrap _g = this->wrap;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(137)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(139)
					Float _g1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(139)
					{
						HX_STACK_LINE(139)
						Float a = ::Math_obj::max(t,(int)0);		HX_STACK_VAR(a,"a");
						HX_STACK_LINE(139)
						Float b = this->get_length();		HX_STACK_VAR(b,"b");
						HX_STACK_LINE(139)
						_g1 = ::Math_obj::min(a,b);
					}
					HX_STACK_LINE(139)
					t = _g1;
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(140)
					Float _g1 = this->get_length();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(140)
					Float _g2 = ::haxor::math::Mathf_obj::Loop(t,(int)0,_g1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(140)
					t = _g2;
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(141)
					Float _g4;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(141)
					{
						HX_STACK_LINE(141)
						Float p_v1 = this->get_length();		HX_STACK_VAR(p_v1,"p_v1");
						struct _Function_4_1{
							inline static Float Block( Float &t){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/animation/AnimationClip.hx",141,0x00dcd394)
								{
									HX_STACK_LINE(141)
									Float p_a = ::haxor::math::Mathf_obj::Loop((t - 1.0),-1.0,1.0);		HX_STACK_VAR(p_a,"p_a");
									HX_STACK_LINE(141)
									return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
								}
								return null();
							}
						};
						HX_STACK_LINE(141)
						Float _g3 = -(_Function_4_1::Block(t));		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(141)
						Float w = (_g3 + 1.0);		HX_STACK_VAR(w,"w");
						HX_STACK_LINE(141)
						_g4 = (w + ((((int)0 - w)) * p_v1));
					}
					HX_STACK_LINE(141)
					t = _g4;
				}
				;break;
			}
		}
		HX_STACK_LINE(144)
		int frame = (int)-1;		HX_STACK_VAR(frame,"frame");
		HX_STACK_LINE(145)
		{
			HX_STACK_LINE(145)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(145)
			int _g = this->tracks->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(145)
			while((true)){
				HX_STACK_LINE(145)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(145)
					break;
				}
				HX_STACK_LINE(145)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(147)
				int _g5 = this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >()->Sample(t,p_weight);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(147)
				frame = _g5;
			}
		}
		HX_STACK_LINE(150)
		if (((frame >= (int)0))){
			HX_STACK_LINE(152)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(153)
			if (((this->m_last_frame != frame))){
				HX_STACK_LINE(155)
				while((true)){
					HX_STACK_LINE(155)
					if ((!(((i < this->m_events->length))))){
						HX_STACK_LINE(155)
						break;
					}
					HX_STACK_LINE(157)
					::haxor::component::animation::AnimationEvent ev = this->m_events->__get(i).StaticCast< ::haxor::component::animation::AnimationEvent >();		HX_STACK_VAR(ev,"ev");
					HX_STACK_LINE(158)
					int ef = ev->frame;		HX_STACK_VAR(ef,"ef");
					HX_STACK_LINE(159)
					if (((ef >= this->m_last_frame))){
						HX_STACK_LINE(160)
						if (((ef <= frame))){
							HX_STACK_LINE(162)
							if ((!(ev->Dispatch()))){
								HX_STACK_LINE(164)
								this->m_events->remove(ev);
								HX_STACK_LINE(164)
								(i)--;
							}
						}
					}
					HX_STACK_LINE(167)
					(i)++;
				}
				HX_STACK_LINE(169)
				this->m_last_frame = frame;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationClip_obj,Sample,(void))

::haxor::component::animation::AnimationClip AnimationClip_obj::Split( int p_start,int p_end){
	HX_STACK_FRAME("haxor.component.animation.AnimationClip","Split",0xddf4d899,"haxor.component.animation.AnimationClip.Split","haxor/component/animation/AnimationClip.hx",182,0x00dcd394)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_start,"p_start")
	HX_STACK_ARG(p_end,"p_end")
	HX_STACK_LINE(183)
	::haxor::component::animation::AnimationClip nc = ::haxor::component::animation::AnimationClip_obj::__new();		HX_STACK_VAR(nc,"nc");
	HX_STACK_LINE(184)
	nc->speed = this->speed;
	HX_STACK_LINE(185)
	nc->wrap = this->wrap;
	HX_STACK_LINE(186)
	nc->playing = this->playing;
	HX_STACK_LINE(188)
	{
		HX_STACK_LINE(188)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(188)
		int _g = this->tracks->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(188)
		while((true)){
			HX_STACK_LINE(188)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(188)
				break;
			}
			HX_STACK_LINE(188)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(190)
			::haxor::component::animation::ClipTrack ct = this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >();		HX_STACK_VAR(ct,"ct");
			HX_STACK_LINE(191)
			::haxor::component::animation::ClipTrack nct = ct->Split(p_start,p_end);		HX_STACK_VAR(nct,"nct");
			HX_STACK_LINE(192)
			nc->tracks->push(nct);
		}
	}
	HX_STACK_LINE(194)
	nc->UpdateLength();
	HX_STACK_LINE(195)
	return nc;
}


HX_DEFINE_DYNAMIC_FUNC2(AnimationClip_obj,Split,return )

Void AnimationClip_obj::UpdateLength( ){
{
		HX_STACK_FRAME("haxor.component.animation.AnimationClip","UpdateLength",0x6d3013f0,"haxor.component.animation.AnimationClip.UpdateLength","haxor/component/animation/AnimationClip.hx",199,0x00dcd394)
		HX_STACK_THIS(this)
		HX_STACK_LINE(200)
		this->m_length = (int)0;
		HX_STACK_LINE(201)
		{
			HX_STACK_LINE(201)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(201)
			int _g = this->tracks->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(201)
			while((true)){
				HX_STACK_LINE(201)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(201)
					break;
				}
				HX_STACK_LINE(201)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(201)
				Float _g2 = this->tracks->__get(i).StaticCast< ::haxor::component::animation::ClipTrack >()->get_length();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(201)
				Float _g11 = ::Math_obj::max(_g2,this->m_length);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(201)
				this->m_length = _g11;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationClip_obj,UpdateLength,(void))


AnimationClip_obj::AnimationClip_obj()
{
}

void AnimationClip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationClip);
	HX_MARK_MEMBER_NAME(tracks,"tracks");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(playing,"playing");
	HX_MARK_MEMBER_NAME(wrap,"wrap");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(m_events,"m_events");
	HX_MARK_MEMBER_NAME(m_last_frame,"m_last_frame");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AnimationClip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tracks,"tracks");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(playing,"playing");
	HX_VISIT_MEMBER_NAME(wrap,"wrap");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(m_events,"m_events");
	HX_VISIT_MEMBER_NAME(m_last_frame,"m_last_frame");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AnimationClip_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { return wrap; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"Split") ) { return Split_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tracks") ) { return tracks; }
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"playing") ) { return playing; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"m_events") ) { return m_events; }
		if (HX_FIELD_EQ(inName,"AddEvent") ) { return AddEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"RemoveEvent") ) { return RemoveEvent_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_frame") ) { return m_last_frame; }
		if (HX_FIELD_EQ(inName,"UpdateLength") ) { return UpdateLength_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationClip_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { wrap=inValue.Cast< ::haxor::core::AnimationWrap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tracks") ) { tracks=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"playing") ) { playing=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_events") ) { m_events=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_frame") ) { m_last_frame=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationClip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tracks"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("playing"));
	outFields->push(HX_CSTRING("wrap"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("m_events"));
	outFields->push(HX_CSTRING("m_last_frame"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AnimationClip_obj,tracks),HX_CSTRING("tracks")},
	{hx::fsFloat,(int)offsetof(AnimationClip_obj,speed),HX_CSTRING("speed")},
	{hx::fsBool,(int)offsetof(AnimationClip_obj,playing),HX_CSTRING("playing")},
	{hx::fsObject /*::haxor::core::AnimationWrap*/ ,(int)offsetof(AnimationClip_obj,wrap),HX_CSTRING("wrap")},
	{hx::fsFloat,(int)offsetof(AnimationClip_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(AnimationClip_obj,m_events),HX_CSTRING("m_events")},
	{hx::fsInt,(int)offsetof(AnimationClip_obj,m_last_frame),HX_CSTRING("m_last_frame")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("tracks"),
	HX_CSTRING("speed"),
	HX_CSTRING("playing"),
	HX_CSTRING("wrap"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("m_events"),
	HX_CSTRING("m_last_frame"),
	HX_CSTRING("AddEvent"),
	HX_CSTRING("RemoveEvent"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Sample"),
	HX_CSTRING("Split"),
	HX_CSTRING("UpdateLength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationClip_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationClip_obj::__mClass,"__mClass");
};

#endif

Class AnimationClip_obj::__mClass;

void AnimationClip_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.AnimationClip"), hx::TCanCast< AnimationClip_obj> ,sStaticFields,sMemberFields,
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

void AnimationClip_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
