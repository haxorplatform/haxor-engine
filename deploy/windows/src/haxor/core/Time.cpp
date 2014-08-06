#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
namespace haxor{
namespace core{

Void Time_obj::__construct()
{
	return null();
}

//Time_obj::~Time_obj() { }

Dynamic Time_obj::__CreateEmpty() { return  new Time_obj; }
hx::ObjectPtr< Time_obj > Time_obj::__new()
{  hx::ObjectPtr< Time_obj > result = new Time_obj();
	result->__construct();
	return result;}

Dynamic Time_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Time_obj > result = new Time_obj();
	result->__construct();
	return result;}

Float Time_obj::clock;

Float Time_obj::get_clock( ){
	HX_STACK_FRAME("haxor.core.Time","get_clock",0x2ddb14a7,"haxor.core.Time.get_clock","haxor/core/Time.hx",16,0xdc68dfee)
	HX_STACK_LINE(16)
	return ::haxor::core::Time_obj::m_clock;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_clock,return )

Float Time_obj::m_clock;

Float Time_obj::delta;

Float Time_obj::get_delta( ){
	HX_STACK_FRAME("haxor.core.Time","get_delta",0xbc9ef2d1,"haxor.core.Time.get_delta","haxor/core/Time.hx",23,0xdc68dfee)
	HX_STACK_LINE(23)
	return ::haxor::core::Time_obj::m_delta;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_delta,return )

Float Time_obj::m_delta;

Float Time_obj::elapsed;

Float Time_obj::get_elapsed( ){
	HX_STACK_FRAME("haxor.core.Time","get_elapsed",0xf673cb55,"haxor.core.Time.get_elapsed","haxor/core/Time.hx",30,0xdc68dfee)
	HX_STACK_LINE(30)
	return ::haxor::core::Time_obj::m_elapsed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_elapsed,return )

Float Time_obj::m_elapsed;

int Time_obj::fps;

int Time_obj::get_fps( ){
	HX_STACK_FRAME("haxor.core.Time","get_fps",0xd8113a82,"haxor.core.Time.get_fps","haxor/core/Time.hx",37,0xdc68dfee)
	HX_STACK_LINE(37)
	return ::haxor::core::Time_obj::m_fps;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_fps,return )

int Time_obj::m_fps;

int Time_obj::ups;

int Time_obj::get_ups( ){
	HX_STACK_FRAME("haxor.core.Time","get_ups",0xd81c9c51,"haxor.core.Time.get_ups","haxor/core/Time.hx",44,0xdc68dfee)
	HX_STACK_LINE(44)
	return ::haxor::core::Time_obj::m_ups;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_ups,return )

int Time_obj::m_ups;

int Time_obj::frame;

int Time_obj::get_frame( ){
	HX_STACK_FRAME("haxor.core.Time","get_frame",0xebfb8306,"haxor.core.Time.get_frame","haxor/core/Time.hx",51,0xdc68dfee)
	HX_STACK_LINE(51)
	return ::haxor::core::Time_obj::m_frame;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_frame,return )

int Time_obj::m_frame;

Float Time_obj::m_frame_count;

Float Time_obj::m_updates;

Float Time_obj::m_stats_clock;

Float Time_obj::m_start_clock;

Float Time_obj::m_last_clock;

Float Time_obj::m_last_frame_clock;

Float Time_obj::m_frame_delta;

Void Time_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Time","Initialize",0xd67638ae,"haxor.core.Time.Initialize","haxor/core/Time.hx",71,0xdc68dfee)
		HX_STACK_LINE(72)
		Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(72)
		Float c = (_g * 0.001);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(78)
		::haxor::core::Time_obj::m_clock = c;
		HX_STACK_LINE(79)
		::haxor::core::Time_obj::m_start_clock = c;
		HX_STACK_LINE(80)
		::haxor::core::Time_obj::m_last_clock = c;
		HX_STACK_LINE(81)
		::haxor::core::Time_obj::m_last_frame_clock = c;
		HX_STACK_LINE(82)
		::haxor::core::Time_obj::m_stats_clock = c;
		HX_STACK_LINE(83)
		::haxor::core::Time_obj::m_elapsed = (c * 1000.0);
		HX_STACK_LINE(84)
		::haxor::core::Time_obj::m_delta = 0.0;
		HX_STACK_LINE(85)
		::haxor::core::Time_obj::m_frame_delta = 0.0;
		HX_STACK_LINE(86)
		::haxor::core::Time_obj::m_ups = (int)0;
		HX_STACK_LINE(87)
		::haxor::core::Time_obj::m_fps = (int)0;
		HX_STACK_LINE(88)
		::haxor::core::Time_obj::m_updates = 0.0;
		HX_STACK_LINE(89)
		::haxor::core::Time_obj::m_frame_count = 0.0;
		HX_STACK_LINE(90)
		::haxor::core::Time_obj::m_frame = (int)0;
		HX_STACK_LINE(91)
		{
			HX_STACK_LINE(91)
			Float _g1 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(91)
			Float _g2 = (_g1 * 1000.0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(91)
			Float _g3 = (_g2 - ::haxor::core::Time_obj::m_start_clock);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(91)
			::haxor::core::Time_obj::m_clock = _g3;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Initialize,(void))

Void Time_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Time","Update",0xded60667,"haxor.core.Time.Update","haxor/core/Time.hx",95,0xdc68dfee)
		HX_STACK_LINE(96)
		{
			HX_STACK_LINE(96)
			Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(96)
			Float _g1 = (_g * 1000.0);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(96)
			Float _g2 = (_g1 - ::haxor::core::Time_obj::m_start_clock);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(96)
			::haxor::core::Time_obj::m_clock = _g2;
		}
		HX_STACK_LINE(97)
		::haxor::core::Time_obj::m_delta = (((::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_last_clock)) * 0.001);
		HX_STACK_LINE(98)
		::haxor::core::Time_obj::m_last_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(99)
		::haxor::core::Time_obj::m_elapsed = (::haxor::core::Time_obj::m_clock * 0.001);
		HX_STACK_LINE(100)
		hx::AddEq(::haxor::core::Time_obj::m_updates,1.0);
		HX_STACK_LINE(102)
		if ((((::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_stats_clock) >= 1000.0))){
			HX_STACK_LINE(104)
			::haxor::core::Time_obj::m_stats_clock = ::haxor::core::Time_obj::m_clock;
			HX_STACK_LINE(105)
			::haxor::core::Time_obj::m_ups = ::haxor::core::Time_obj::m_updates;
			HX_STACK_LINE(106)
			::haxor::core::Time_obj::m_fps = ::haxor::core::Time_obj::m_frame_count;
			HX_STACK_LINE(107)
			::haxor::core::Time_obj::m_updates = 0.0;
			HX_STACK_LINE(108)
			::haxor::core::Time_obj::m_frame_count = 0.0;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Update,(void))

Void Time_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Time","Render",0x5cf9ebb4,"haxor.core.Time.Render","haxor/core/Time.hx",116,0xdc68dfee)
		HX_STACK_LINE(117)
		hx::AddEq(::haxor::core::Time_obj::m_frame_count,1.0);
		HX_STACK_LINE(118)
		(::haxor::core::Time_obj::m_frame)++;
		HX_STACK_LINE(119)
		::haxor::core::Time_obj::m_frame_delta = (((::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_last_frame_clock)) * 0.001);
		HX_STACK_LINE(120)
		::haxor::core::Time_obj::m_last_frame_clock = ::haxor::core::Time_obj::m_clock;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Render,(void))

Void Time_obj::UpdateClock( ){
{
		HX_STACK_FRAME("haxor.core.Time","UpdateClock",0xc7e6dde7,"haxor.core.Time.UpdateClock","haxor/core/Time.hx",127,0xdc68dfee)
		HX_STACK_LINE(130)
		Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(130)
		Float _g1 = (_g * 1000.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(130)
		Float _g2 = (_g1 - ::haxor::core::Time_obj::m_start_clock);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(130)
		::haxor::core::Time_obj::m_clock = _g2;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,UpdateClock,(void))


Time_obj::Time_obj()
{
}

Dynamic Time_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return inCallProp ? get_fps() : fps; }
		if (HX_FIELD_EQ(inName,"ups") ) { return inCallProp ? get_ups() : ups; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clock") ) { return inCallProp ? get_clock() : clock; }
		if (HX_FIELD_EQ(inName,"delta") ) { return inCallProp ? get_delta() : delta; }
		if (HX_FIELD_EQ(inName,"m_fps") ) { return m_fps; }
		if (HX_FIELD_EQ(inName,"m_ups") ) { return m_ups; }
		if (HX_FIELD_EQ(inName,"frame") ) { return inCallProp ? get_frame() : frame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_clock") ) { return m_clock; }
		if (HX_FIELD_EQ(inName,"m_delta") ) { return m_delta; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { return inCallProp ? get_elapsed() : elapsed; }
		if (HX_FIELD_EQ(inName,"get_fps") ) { return get_fps_dyn(); }
		if (HX_FIELD_EQ(inName,"get_ups") ) { return get_ups_dyn(); }
		if (HX_FIELD_EQ(inName,"m_frame") ) { return m_frame; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_clock") ) { return get_clock_dyn(); }
		if (HX_FIELD_EQ(inName,"get_delta") ) { return get_delta_dyn(); }
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { return m_elapsed; }
		if (HX_FIELD_EQ(inName,"get_frame") ) { return get_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"m_updates") ) { return m_updates; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_elapsed") ) { return get_elapsed_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateClock") ) { return UpdateClock_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_clock") ) { return m_last_clock; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_frame_count") ) { return m_frame_count; }
		if (HX_FIELD_EQ(inName,"m_stats_clock") ) { return m_stats_clock; }
		if (HX_FIELD_EQ(inName,"m_start_clock") ) { return m_start_clock; }
		if (HX_FIELD_EQ(inName,"m_frame_delta") ) { return m_frame_delta; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_last_frame_clock") ) { return m_last_frame_clock; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Time_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ups") ) { ups=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clock") ) { clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delta") ) { delta=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fps") ) { m_fps=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ups") ) { m_ups=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_clock") ) { m_clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_delta") ) { m_delta=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { elapsed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_frame") ) { m_frame=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { m_elapsed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_updates") ) { m_updates=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_clock") ) { m_last_clock=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_frame_count") ) { m_frame_count=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_stats_clock") ) { m_stats_clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_start_clock") ) { m_start_clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_frame_delta") ) { m_frame_delta=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_last_frame_clock") ) { m_last_frame_clock=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Time_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("clock"),
	HX_CSTRING("get_clock"),
	HX_CSTRING("m_clock"),
	HX_CSTRING("delta"),
	HX_CSTRING("get_delta"),
	HX_CSTRING("m_delta"),
	HX_CSTRING("elapsed"),
	HX_CSTRING("get_elapsed"),
	HX_CSTRING("m_elapsed"),
	HX_CSTRING("fps"),
	HX_CSTRING("get_fps"),
	HX_CSTRING("m_fps"),
	HX_CSTRING("ups"),
	HX_CSTRING("get_ups"),
	HX_CSTRING("m_ups"),
	HX_CSTRING("frame"),
	HX_CSTRING("get_frame"),
	HX_CSTRING("m_frame"),
	HX_CSTRING("m_frame_count"),
	HX_CSTRING("m_updates"),
	HX_CSTRING("m_stats_clock"),
	HX_CSTRING("m_start_clock"),
	HX_CSTRING("m_last_clock"),
	HX_CSTRING("m_last_frame_clock"),
	HX_CSTRING("m_frame_delta"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Update"),
	HX_CSTRING("Render"),
	HX_CSTRING("UpdateClock"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Time_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Time_obj::clock,"clock");
	HX_MARK_MEMBER_NAME(Time_obj::m_clock,"m_clock");
	HX_MARK_MEMBER_NAME(Time_obj::delta,"delta");
	HX_MARK_MEMBER_NAME(Time_obj::m_delta,"m_delta");
	HX_MARK_MEMBER_NAME(Time_obj::elapsed,"elapsed");
	HX_MARK_MEMBER_NAME(Time_obj::m_elapsed,"m_elapsed");
	HX_MARK_MEMBER_NAME(Time_obj::fps,"fps");
	HX_MARK_MEMBER_NAME(Time_obj::m_fps,"m_fps");
	HX_MARK_MEMBER_NAME(Time_obj::ups,"ups");
	HX_MARK_MEMBER_NAME(Time_obj::m_ups,"m_ups");
	HX_MARK_MEMBER_NAME(Time_obj::frame,"frame");
	HX_MARK_MEMBER_NAME(Time_obj::m_frame,"m_frame");
	HX_MARK_MEMBER_NAME(Time_obj::m_frame_count,"m_frame_count");
	HX_MARK_MEMBER_NAME(Time_obj::m_updates,"m_updates");
	HX_MARK_MEMBER_NAME(Time_obj::m_stats_clock,"m_stats_clock");
	HX_MARK_MEMBER_NAME(Time_obj::m_start_clock,"m_start_clock");
	HX_MARK_MEMBER_NAME(Time_obj::m_last_clock,"m_last_clock");
	HX_MARK_MEMBER_NAME(Time_obj::m_last_frame_clock,"m_last_frame_clock");
	HX_MARK_MEMBER_NAME(Time_obj::m_frame_delta,"m_frame_delta");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Time_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Time_obj::clock,"clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_clock,"m_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::delta,"delta");
	HX_VISIT_MEMBER_NAME(Time_obj::m_delta,"m_delta");
	HX_VISIT_MEMBER_NAME(Time_obj::elapsed,"elapsed");
	HX_VISIT_MEMBER_NAME(Time_obj::m_elapsed,"m_elapsed");
	HX_VISIT_MEMBER_NAME(Time_obj::fps,"fps");
	HX_VISIT_MEMBER_NAME(Time_obj::m_fps,"m_fps");
	HX_VISIT_MEMBER_NAME(Time_obj::ups,"ups");
	HX_VISIT_MEMBER_NAME(Time_obj::m_ups,"m_ups");
	HX_VISIT_MEMBER_NAME(Time_obj::frame,"frame");
	HX_VISIT_MEMBER_NAME(Time_obj::m_frame,"m_frame");
	HX_VISIT_MEMBER_NAME(Time_obj::m_frame_count,"m_frame_count");
	HX_VISIT_MEMBER_NAME(Time_obj::m_updates,"m_updates");
	HX_VISIT_MEMBER_NAME(Time_obj::m_stats_clock,"m_stats_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_start_clock,"m_start_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_last_clock,"m_last_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_last_frame_clock,"m_last_frame_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_frame_delta,"m_frame_delta");
};

#endif

Class Time_obj::__mClass;

void Time_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Time"), hx::TCanCast< Time_obj> ,sStaticFields,sMemberFields,
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

void Time_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
