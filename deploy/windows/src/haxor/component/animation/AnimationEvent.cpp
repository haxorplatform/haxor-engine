#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_animation_AnimationEvent
#include <haxor/component/animation/AnimationEvent.h>
#endif
namespace haxor{
namespace component{
namespace animation{

Void AnimationEvent_obj::__construct(int p_frame,Dynamic p_listener,hx::Null< int >  __o_p_repeat,Dynamic p_args)
{
HX_STACK_FRAME("haxor.component.animation.AnimationEvent","new",0x979d12af,"haxor.component.animation.AnimationEvent.new","haxor/component/animation/AnimationEvent.hx",38,0x40761a7e)
HX_STACK_THIS(this)
HX_STACK_ARG(p_frame,"p_frame")
HX_STACK_ARG(p_listener,"p_listener")
HX_STACK_ARG(__o_p_repeat,"p_repeat")
HX_STACK_ARG(p_args,"p_args")
int p_repeat = __o_p_repeat.Default(0);
{
	HX_STACK_LINE(39)
	this->frame = p_frame;
	HX_STACK_LINE(40)
	this->listener = p_listener;
	HX_STACK_LINE(41)
	if (((p_args == null()))){
		HX_STACK_LINE(41)
		this->args = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(41)
		this->args = p_args;
	}
	HX_STACK_LINE(42)
	this->repeat = p_repeat;
}
;
	return null();
}

//AnimationEvent_obj::~AnimationEvent_obj() { }

Dynamic AnimationEvent_obj::__CreateEmpty() { return  new AnimationEvent_obj; }
hx::ObjectPtr< AnimationEvent_obj > AnimationEvent_obj::__new(int p_frame,Dynamic p_listener,hx::Null< int >  __o_p_repeat,Dynamic p_args)
{  hx::ObjectPtr< AnimationEvent_obj > result = new AnimationEvent_obj();
	result->__construct(p_frame,p_listener,__o_p_repeat,p_args);
	return result;}

Dynamic AnimationEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationEvent_obj > result = new AnimationEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

bool AnimationEvent_obj::Dispatch( ){
	HX_STACK_FRAME("haxor.component.animation.AnimationEvent","Dispatch",0x7c2e8a2b,"haxor.component.animation.AnimationEvent.Dispatch","haxor/component/animation/AnimationEvent.hx",50,0x40761a7e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	if (((this->listener_dyn() != null()))){
		HX_STACK_LINE(53)
		this->listener(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(54)
		if (((this->repeat <= (int)0))){
			HX_STACK_LINE(54)
			return true;
		}
		HX_STACK_LINE(55)
		(this->repeat)--;
		HX_STACK_LINE(56)
		if (((this->repeat <= (int)0))){
			HX_STACK_LINE(56)
			return false;
		}
		HX_STACK_LINE(57)
		return true;
	}
	HX_STACK_LINE(59)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationEvent_obj,Dispatch,return )


AnimationEvent_obj::AnimationEvent_obj()
{
}

void AnimationEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationEvent);
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(args,"args");
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(repeat,"repeat");
	HX_MARK_END_CLASS();
}

void AnimationEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(args,"args");
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(repeat,"repeat");
}

Dynamic AnimationEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		if (HX_FIELD_EQ(inName,"Dispatch") ) { return Dispatch_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { args=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"repeat") ) { repeat=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("args"));
	outFields->push(HX_CSTRING("repeat"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(AnimationEvent_obj,frame),HX_CSTRING("frame")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(AnimationEvent_obj,args),HX_CSTRING("args")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(AnimationEvent_obj,listener),HX_CSTRING("listener")},
	{hx::fsInt,(int)offsetof(AnimationEvent_obj,repeat),HX_CSTRING("repeat")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("frame"),
	HX_CSTRING("args"),
	HX_CSTRING("listener"),
	HX_CSTRING("repeat"),
	HX_CSTRING("Dispatch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::__mClass,"__mClass");
};

#endif

Class AnimationEvent_obj::__mClass;

void AnimationEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.animation.AnimationEvent"), hx::TCanCast< AnimationEvent_obj> ,sStaticFields,sMemberFields,
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

void AnimationEvent_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace animation
