#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
	HX_STACK_FRAME("haxor.core.Time","get_clock",0x2ddb14a7,"haxor.core.Time.get_clock","haxor/core/Time.hx",20,0xdc68dfee)
	HX_STACK_LINE(20)
	return ::haxor::core::Time_obj::m_clock;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_clock,return )

Float Time_obj::m_clock;

Float Time_obj::m_clock_dt;

Float Time_obj::m_clock_0;

Float Time_obj::delta;

Float Time_obj::get_delta( ){
	HX_STACK_FRAME("haxor.core.Time","get_delta",0xbc9ef2d1,"haxor.core.Time.get_delta","haxor/core/Time.hx",29,0xdc68dfee)
	HX_STACK_LINE(29)
	return ::haxor::core::Time_obj::m_delta;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_delta,return )

Float Time_obj::m_delta;

Float Time_obj::framedelta;

Float Time_obj::get_framedelta( ){
	HX_STACK_FRAME("haxor.core.Time","get_framedelta",0xc3b4af32,"haxor.core.Time.get_framedelta","haxor/core/Time.hx",36,0xdc68dfee)
	HX_STACK_LINE(36)
	return ::haxor::core::Time_obj::m_frame_delta;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_framedelta,return )

Float Time_obj::m_frame_delta;

Float Time_obj::elapsed;

Float Time_obj::get_elapsed( ){
	HX_STACK_FRAME("haxor.core.Time","get_elapsed",0xf673cb55,"haxor.core.Time.get_elapsed","haxor/core/Time.hx",43,0xdc68dfee)
	HX_STACK_LINE(43)
	return ::haxor::core::Time_obj::m_elapsed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_elapsed,return )

Float Time_obj::m_elapsed;

int Time_obj::fps;

int Time_obj::get_fps( ){
	HX_STACK_FRAME("haxor.core.Time","get_fps",0xd8113a82,"haxor.core.Time.get_fps","haxor/core/Time.hx",50,0xdc68dfee)
	HX_STACK_LINE(50)
	return ::haxor::core::Time_obj::m_fps;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_fps,return )

int Time_obj::m_fps;

int Time_obj::ups;

int Time_obj::get_ups( ){
	HX_STACK_FRAME("haxor.core.Time","get_ups",0xd81c9c51,"haxor.core.Time.get_ups","haxor/core/Time.hx",57,0xdc68dfee)
	HX_STACK_LINE(57)
	return ::haxor::core::Time_obj::m_ups;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,get_ups,return )

int Time_obj::m_ups;

int Time_obj::frame;

int Time_obj::get_frame( ){
	HX_STACK_FRAME("haxor.core.Time","get_frame",0xebfb8306,"haxor.core.Time.get_frame","haxor/core/Time.hx",64,0xdc68dfee)
	HX_STACK_LINE(64)
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

Void Time_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Time","Initialize",0xd67638ae,"haxor.core.Time.Initialize","haxor/core/Time.hx",84,0xdc68dfee)
		HX_STACK_LINE(85)
		::haxor::core::Time_obj::m_clock = 0.0;
		HX_STACK_LINE(86)
		::haxor::core::Time_obj::m_clock_dt = 0.0;
		HX_STACK_LINE(87)
		::haxor::core::Time_obj::m_clock_0 = 0.0;
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(88)
			Float _g1 = (_g * 1000.0);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(88)
			Float _g2 = (_g1 - ::haxor::core::Time_obj::m_clock_0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(88)
			::haxor::core::Time_obj::m_clock = _g2;
		}
		HX_STACK_LINE(89)
		::haxor::core::Time_obj::m_clock_0 = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(90)
		{
			HX_STACK_LINE(90)
			Float _g3 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(90)
			Float _g4 = (_g3 * 1000.0);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(90)
			Float _g5 = (_g4 - ::haxor::core::Time_obj::m_clock_0);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(90)
			::haxor::core::Time_obj::m_clock = _g5;
		}
		HX_STACK_LINE(92)
		::haxor::core::Time_obj::m_start_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(93)
		::haxor::core::Time_obj::m_last_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(94)
		::haxor::core::Time_obj::m_last_frame_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(95)
		::haxor::core::Time_obj::m_stats_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(96)
		::haxor::core::Time_obj::m_elapsed = 0.0;
		HX_STACK_LINE(97)
		::haxor::core::Time_obj::m_delta = 0.0;
		HX_STACK_LINE(98)
		::haxor::core::Time_obj::m_frame_delta = 0.0;
		HX_STACK_LINE(99)
		::haxor::core::Time_obj::m_ups = (int)0;
		HX_STACK_LINE(100)
		::haxor::core::Time_obj::m_fps = (int)0;
		HX_STACK_LINE(101)
		::haxor::core::Time_obj::m_updates = 0.0;
		HX_STACK_LINE(102)
		::haxor::core::Time_obj::m_frame_count = 0.0;
		HX_STACK_LINE(103)
		::haxor::core::Time_obj::m_frame = (int)0;
		HX_STACK_LINE(104)
		{
			HX_STACK_LINE(104)
			Float _g6 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(104)
			Float _g7 = (_g6 * 1000.0);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(104)
			Float _g8 = (_g7 - ::haxor::core::Time_obj::m_clock_0);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(104)
			::haxor::core::Time_obj::m_clock = _g8;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Initialize,(void))

Void Time_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Time","Update",0xded60667,"haxor.core.Time.Update","haxor/core/Time.hx",108,0xdc68dfee)
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			Float _g1 = (_g * 1000.0);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(109)
			Float _g2 = (_g1 - ::haxor::core::Time_obj::m_clock_0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(109)
			::haxor::core::Time_obj::m_clock = _g2;
		}
		HX_STACK_LINE(110)
		::haxor::core::Time_obj::m_clock_dt = (::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_last_clock);
		HX_STACK_LINE(111)
		if (((::haxor::core::Time_obj::m_clock_dt <= (int)0))){
			HX_STACK_LINE(111)
			::haxor::core::Time_obj::m_clock_dt = 1.0;
		}
		HX_STACK_LINE(112)
		::haxor::core::Time_obj::m_last_clock = ::haxor::core::Time_obj::m_clock;
		HX_STACK_LINE(113)
		::haxor::core::Time_obj::m_delta = (::haxor::core::Time_obj::m_clock_dt * 0.001);
		HX_STACK_LINE(115)
		::haxor::core::Time_obj::m_elapsed = (::haxor::core::Time_obj::m_clock * 0.001);
		HX_STACK_LINE(116)
		hx::AddEq(::haxor::core::Time_obj::m_updates,1.0);
		HX_STACK_LINE(118)
		if ((((::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_stats_clock) >= 1000.0))){
			HX_STACK_LINE(120)
			hx::AddEq(::haxor::core::Time_obj::m_stats_clock,(::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_stats_clock));
			HX_STACK_LINE(121)
			::haxor::core::Time_obj::m_ups = ::haxor::core::Time_obj::m_updates;
			HX_STACK_LINE(122)
			::haxor::core::Time_obj::m_fps = ::haxor::core::Time_obj::m_frame_count;
			HX_STACK_LINE(123)
			::haxor::core::Time_obj::m_updates = 0.0;
			HX_STACK_LINE(124)
			::haxor::core::Time_obj::m_frame_count = 0.0;
			HX_STACK_LINE(125)
			::haxor::core::Console_obj::Log((HX_CSTRING("FPS: ") + ::haxor::core::Time_obj::m_fps),(int)7);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Update,(void))

Void Time_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Time","Render",0x5cf9ebb4,"haxor.core.Time.Render","haxor/core/Time.hx",133,0xdc68dfee)
		HX_STACK_LINE(134)
		hx::AddEq(::haxor::core::Time_obj::m_frame_count,1.0);
		HX_STACK_LINE(135)
		(::haxor::core::Time_obj::m_frame)++;
		HX_STACK_LINE(136)
		::haxor::core::Time_obj::m_frame_delta = (((::haxor::core::Time_obj::m_clock - ::haxor::core::Time_obj::m_last_frame_clock)) * 0.001);
		HX_STACK_LINE(137)
		::haxor::core::Time_obj::m_last_frame_clock = ::haxor::core::Time_obj::m_clock;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Time_obj,Render,(void))

Void Time_obj::UpdateClock( ){
{
		HX_STACK_FRAME("haxor.core.Time","UpdateClock",0xc7e6dde7,"haxor.core.Time.UpdateClock","haxor/core/Time.hx",144,0xdc68dfee)
		HX_STACK_LINE(154)
		Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(154)
		Float _g1 = (_g * 1000.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(154)
		Float _g2 = (_g1 - ::haxor::core::Time_obj::m_clock_0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(154)
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
		if (HX_FIELD_EQ(inName,"m_clock_0") ) { return m_clock_0; }
		if (HX_FIELD_EQ(inName,"get_delta") ) { return get_delta_dyn(); }
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { return m_elapsed; }
		if (HX_FIELD_EQ(inName,"get_frame") ) { return get_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"m_updates") ) { return m_updates; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_clock_dt") ) { return m_clock_dt; }
		if (HX_FIELD_EQ(inName,"framedelta") ) { return inCallProp ? get_framedelta() : framedelta; }
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
		if (HX_FIELD_EQ(inName,"m_frame_delta") ) { return m_frame_delta; }
		if (HX_FIELD_EQ(inName,"m_frame_count") ) { return m_frame_count; }
		if (HX_FIELD_EQ(inName,"m_stats_clock") ) { return m_stats_clock; }
		if (HX_FIELD_EQ(inName,"m_start_clock") ) { return m_start_clock; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_framedelta") ) { return get_framedelta_dyn(); }
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
		if (HX_FIELD_EQ(inName,"m_clock_0") ) { m_clock_0=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { m_elapsed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_updates") ) { m_updates=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_clock_dt") ) { m_clock_dt=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framedelta") ) { framedelta=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_clock") ) { m_last_clock=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_frame_delta") ) { m_frame_delta=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_frame_count") ) { m_frame_count=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_stats_clock") ) { m_stats_clock=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_start_clock") ) { m_start_clock=inValue.Cast< Float >(); return inValue; }
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
	HX_CSTRING("m_clock_dt"),
	HX_CSTRING("m_clock_0"),
	HX_CSTRING("delta"),
	HX_CSTRING("get_delta"),
	HX_CSTRING("m_delta"),
	HX_CSTRING("framedelta"),
	HX_CSTRING("get_framedelta"),
	HX_CSTRING("m_frame_delta"),
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
	HX_MARK_MEMBER_NAME(Time_obj::m_clock_dt,"m_clock_dt");
	HX_MARK_MEMBER_NAME(Time_obj::m_clock_0,"m_clock_0");
	HX_MARK_MEMBER_NAME(Time_obj::delta,"delta");
	HX_MARK_MEMBER_NAME(Time_obj::m_delta,"m_delta");
	HX_MARK_MEMBER_NAME(Time_obj::framedelta,"framedelta");
	HX_MARK_MEMBER_NAME(Time_obj::m_frame_delta,"m_frame_delta");
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
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Time_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Time_obj::clock,"clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_clock,"m_clock");
	HX_VISIT_MEMBER_NAME(Time_obj::m_clock_dt,"m_clock_dt");
	HX_VISIT_MEMBER_NAME(Time_obj::m_clock_0,"m_clock_0");
	HX_VISIT_MEMBER_NAME(Time_obj::delta,"delta");
	HX_VISIT_MEMBER_NAME(Time_obj::m_delta,"m_delta");
	HX_VISIT_MEMBER_NAME(Time_obj::framedelta,"framedelta");
	HX_VISIT_MEMBER_NAME(Time_obj::m_frame_delta,"m_frame_delta");
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
