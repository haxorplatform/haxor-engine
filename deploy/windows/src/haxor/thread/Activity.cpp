#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
namespace haxor{
namespace thread{

Void Activity_obj::__construct(Dynamic p_callback,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context)
{
HX_STACK_FRAME("haxor.thread.Activity","new",0x9e73c259,"haxor.thread.Activity.new","haxor/thread/Activity.hx",127,0x19970d17)
HX_STACK_THIS(this)
HX_STACK_ARG(p_callback,"p_callback")
HX_STACK_ARG(__o_p_threaded,"p_threaded")
HX_STACK_ARG(__o_p_graphics_context,"p_graphics_context")
bool p_threaded = __o_p_threaded.Default(false);
bool p_graphics_context = __o_p_graphics_context.Default(false);
{
	HX_STACK_LINE(127)
	Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");
	HX_STACK_LINE(127)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(129)
	super::__construct(null());
	HX_STACK_LINE(130)
	if (((p_callback1->__GetItem((int)0) == null()))){
		HX_STACK_LINE(130)
		return null();
	}
	HX_STACK_LINE(132)
	this->m_time_start = ::haxor::core::Time_obj::m_elapsed;
	HX_STACK_LINE(133)
	this->m_elapsed = 0.0;
	HX_STACK_LINE(134)
	this->m_callback = p_callback1->__GetItem((int)0);
	HX_STACK_LINE(135)
	this->m_cancelled = false;
	HX_STACK_LINE(141)
	if ((p_graphics_context)){
		HX_STACK_LINE(141)
		p_threaded = false;
	}
	HX_STACK_LINE(143)
	if ((!(p_threaded))){
		HX_STACK_LINE(145)
		if ((p_graphics_context)){
			HX_STACK_LINE(147)
			::haxor::context::EngineContext_obj::render->Add(hx::ObjectPtr<OBJ_>(this));
		}
		else{
			HX_STACK_LINE(151)
			::haxor::context::EngineContext_obj::update->Add(hx::ObjectPtr<OBJ_>(this));
		}
	}
	else{

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g,Dynamic,p_callback1)
		Void run(){
			HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/thread/Activity.hx",159,0x19970d17)
			{
				HX_STACK_LINE(159)
				while((true)){
					HX_STACK_LINE(161)
					if ((_g->__get((int)0).StaticCast< ::haxor::thread::Activity >()->m_cancelled)){
						HX_STACK_LINE(161)
						break;
					}
					HX_STACK_LINE(162)
					if ((!(p_callback1->__GetItem((int)0)(_g->__get((int)0).StaticCast< ::haxor::thread::Activity >()->m_elapsed).Cast< bool >()))){
						HX_STACK_LINE(162)
						break;
					}
					HX_STACK_LINE(163)
					hx::AddEq(_g->__get((int)0).StaticCast< ::haxor::thread::Activity >()->m_elapsed,0.0001);
					HX_STACK_LINE(164)
					::Sys_obj::sleep(0.0001);
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(157)
		::cpp::vm::Thread_obj::create( Dynamic(new _Function_2_1(_g,p_callback1)));
	}
}
;
	return null();
}

//Activity_obj::~Activity_obj() { }

Dynamic Activity_obj::__CreateEmpty() { return  new Activity_obj; }
hx::ObjectPtr< Activity_obj > Activity_obj::__new(Dynamic p_callback,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context)
{  hx::ObjectPtr< Activity_obj > result = new Activity_obj();
	result->__construct(p_callback,__o_p_threaded,__o_p_graphics_context);
	return result;}

Dynamic Activity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Activity_obj > result = new Activity_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *Activity_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	if (inType==typeid( ::haxor::core::IRenderable_obj)) return operator ::haxor::core::IRenderable_obj *();
	return super::__ToInterface(inType);
}

Float Activity_obj::get_elapsed( ){
	HX_STACK_FRAME("haxor.thread.Activity","get_elapsed",0x06830b4c,"haxor.thread.Activity.get_elapsed","haxor/thread/Activity.hx",116,0x19970d17)
	HX_STACK_THIS(this)
	HX_STACK_LINE(116)
	return this->m_elapsed;
}


HX_DEFINE_DYNAMIC_FUNC0(Activity_obj,get_elapsed,return )

Void Activity_obj::Cancel( ){
{
		HX_STACK_FRAME("haxor.thread.Activity","Cancel",0x9d0b3141,"haxor.thread.Activity.Cancel","haxor/thread/Activity.hx",181,0x19970d17)
		HX_STACK_THIS(this)
		HX_STACK_LINE(181)
		this->m_cancelled = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Activity_obj,Cancel,(void))

Void Activity_obj::OnUpdate( ){
{
		HX_STACK_FRAME("haxor.thread.Activity","OnUpdate",0xa2b7800f,"haxor.thread.Activity.OnUpdate","haxor/thread/Activity.hx",187,0x19970d17)
		HX_STACK_THIS(this)
		HX_STACK_LINE(187)
		this->OnRun();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Activity_obj,OnUpdate,(void))

Void Activity_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.thread.Activity","OnRender",0x20db655c,"haxor.thread.Activity.OnRender","haxor/thread/Activity.hx",192,0x19970d17)
		HX_STACK_THIS(this)
		HX_STACK_LINE(192)
		this->OnRun();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Activity_obj,OnRender,(void))

Void Activity_obj::OnRun( ){
{
		HX_STACK_FRAME("haxor.thread.Activity","OnRun",0x21170d85,"haxor.thread.Activity.OnRun","haxor/thread/Activity.hx",198,0x19970d17)
		HX_STACK_THIS(this)
		HX_STACK_LINE(199)
		if ((this->m_cancelled)){
			HX_STACK_LINE(199)
			::haxor::core::Resource_obj::Destroy(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(199)
			return null();
		}
		HX_STACK_LINE(200)
		this->m_elapsed = (::haxor::core::Time_obj::m_elapsed - this->m_time_start);
		HX_STACK_LINE(201)
		if ((!(this->m_callback(this->m_elapsed)))){
			HX_STACK_LINE(203)
			::haxor::core::Resource_obj::Destroy(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Activity_obj,OnRun,(void))

::haxor::thread::Activity Activity_obj::Iterate( int p_offset,int p_length,Dynamic p_callback,hx::Null< int >  __o_p_step,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context){
int p_step = __o_p_step.Default(1);
bool p_threaded = __o_p_threaded.Default(false);
bool p_graphics_context = __o_p_graphics_context.Default(false);
	HX_STACK_FRAME("haxor.thread.Activity","Iterate",0x3a548453,"haxor.thread.Activity.Iterate","haxor/thread/Activity.hx",39,0x19970d17)
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_length,"p_length")
	HX_STACK_ARG(p_callback,"p_callback")
	HX_STACK_ARG(p_step,"p_step")
	HX_STACK_ARG(p_threaded,"p_threaded")
	HX_STACK_ARG(p_graphics_context,"p_graphics_context")
{
		HX_STACK_LINE(39)
		Array< int > p_step1 = Array_obj< int >::__new().Add(p_step);		HX_STACK_VAR(p_step1,"p_step1");
		HX_STACK_LINE(39)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");
		HX_STACK_LINE(39)
		Array< int > p_length1 = Array_obj< int >::__new().Add(p_length);		HX_STACK_VAR(p_length1,"p_length1");
		HX_STACK_LINE(41)
		Array< int > it = Array_obj< int >::__new().Add(p_offset);		HX_STACK_VAR(it,"it");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< int >,p_length1,Array< int >,p_step1,Array< int >,it,Dynamic,p_callback1)
		bool run(Float t){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/thread/Activity.hx",44,0x19970d17)
			HX_STACK_ARG(t,"t")
			{
				HX_STACK_LINE(45)
				bool finished = false;		HX_STACK_VAR(finished,"finished");
				HX_STACK_LINE(46)
				{
					HX_STACK_LINE(46)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(46)
					while(((_g < p_step1->__get((int)0)))){
						HX_STACK_LINE(46)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(48)
						if (((it->__get((int)0) >= p_length1->__get((int)0)))){
							HX_STACK_LINE(48)
							return false;
						}
						HX_STACK_LINE(49)
						if ((!(p_callback1->__GetItem((int)0)(it->__get((int)0)).Cast< bool >()))){
							HX_STACK_LINE(49)
							finished = true;
							HX_STACK_LINE(49)
							break;
						}
						HX_STACK_LINE(50)
						(it[(int)0])++;
					}
				}
				HX_STACK_LINE(52)
				return !(finished);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(43)
		return ::haxor::thread::Activity_obj::__new( Dynamic(new _Function_1_1(p_length1,p_step1,it,p_callback1)),p_threaded,p_graphics_context);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Activity_obj,Iterate,return )

::haxor::thread::Activity Activity_obj::Delay( Float p_time,Dynamic p_callback,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context){
bool p_threaded = __o_p_threaded.Default(false);
bool p_graphics_context = __o_p_graphics_context.Default(false);
	HX_STACK_FRAME("haxor.thread.Activity","Delay",0xc5cf699c,"haxor.thread.Activity.Delay","haxor/thread/Activity.hx",62,0x19970d17)
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_ARG(p_callback,"p_callback")
	HX_STACK_ARG(p_threaded,"p_threaded")
	HX_STACK_ARG(p_graphics_context,"p_graphics_context")
{
		HX_STACK_LINE(62)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");
		HX_STACK_LINE(62)
		Array< Float > p_time1 = Array_obj< Float >::__new().Add(p_time);		HX_STACK_VAR(p_time1,"p_time1");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< Float >,p_time1,Dynamic,p_callback1)
		bool run(Float t){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/thread/Activity.hx",65,0x19970d17)
			HX_STACK_ARG(t,"t")
			{
				HX_STACK_LINE(67)
				if (((t >= p_time1->__get((int)0)))){
					HX_STACK_LINE(69)
					p_callback1->__GetItem((int)0)().Cast< Void >();
					HX_STACK_LINE(70)
					return false;
				}
				HX_STACK_LINE(72)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(64)
		return ::haxor::thread::Activity_obj::__new( Dynamic(new _Function_1_1(p_time1,p_callback1)),p_threaded,p_graphics_context);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Activity_obj,Delay,return )

::haxor::thread::Activity Activity_obj::Run( Dynamic p_callback,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context){
bool p_threaded = __o_p_threaded.Default(false);
bool p_graphics_context = __o_p_graphics_context.Default(false);
	HX_STACK_FRAME("haxor.thread.Activity","Run",0x9e5e9124,"haxor.thread.Activity.Run","haxor/thread/Activity.hx",83,0x19970d17)
	HX_STACK_ARG(p_callback,"p_callback")
	HX_STACK_ARG(p_threaded,"p_threaded")
	HX_STACK_ARG(p_graphics_context,"p_graphics_context")
{
		HX_STACK_LINE(83)
		return ::haxor::thread::Activity_obj::__new(p_callback,p_threaded,p_graphics_context);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Activity_obj,Run,return )

::haxor::thread::Activity Activity_obj::RunOnce( Dynamic p_callback,hx::Null< bool >  __o_p_threaded,hx::Null< bool >  __o_p_graphics_context){
bool p_threaded = __o_p_threaded.Default(false);
bool p_graphics_context = __o_p_graphics_context.Default(false);
	HX_STACK_FRAME("haxor.thread.Activity","RunOnce",0x2e739cc5,"haxor.thread.Activity.RunOnce","haxor/thread/Activity.hx",93,0x19970d17)
	HX_STACK_ARG(p_callback,"p_callback")
	HX_STACK_ARG(p_threaded,"p_threaded")
	HX_STACK_ARG(p_graphics_context,"p_graphics_context")
{
		HX_STACK_LINE(93)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,p_callback1)
		bool run(Float t){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/thread/Activity.hx",96,0x19970d17)
			HX_STACK_ARG(t,"t")
			{
				HX_STACK_LINE(97)
				p_callback1->__GetItem((int)0)().Cast< Void >();
				HX_STACK_LINE(98)
				return false;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(95)
		return ::haxor::thread::Activity_obj::__new( Dynamic(new _Function_1_1(p_callback1)),p_threaded,p_graphics_context);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Activity_obj,RunOnce,return )


Activity_obj::Activity_obj()
{
}

void Activity_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Activity);
	HX_MARK_MEMBER_NAME(m_callback,"m_callback");
	HX_MARK_MEMBER_NAME(m_time_start,"m_time_start");
	HX_MARK_MEMBER_NAME(elapsed,"elapsed");
	HX_MARK_MEMBER_NAME(m_elapsed,"m_elapsed");
	HX_MARK_MEMBER_NAME(m_cancelled,"m_cancelled");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Activity_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_callback,"m_callback");
	HX_VISIT_MEMBER_NAME(m_time_start,"m_time_start");
	HX_VISIT_MEMBER_NAME(elapsed,"elapsed");
	HX_VISIT_MEMBER_NAME(m_elapsed,"m_elapsed");
	HX_VISIT_MEMBER_NAME(m_cancelled,"m_cancelled");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Activity_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Run") ) { return Run_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Delay") ) { return Delay_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRun") ) { return OnRun_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Cancel") ) { return Cancel_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Iterate") ) { return Iterate_dyn(); }
		if (HX_FIELD_EQ(inName,"RunOnce") ) { return RunOnce_dyn(); }
		if (HX_FIELD_EQ(inName,"elapsed") ) { return inCallProp ? get_elapsed() : elapsed; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { return m_elapsed; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_callback") ) { return m_callback; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_elapsed") ) { return get_elapsed_dyn(); }
		if (HX_FIELD_EQ(inName,"m_cancelled") ) { return m_cancelled; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_time_start") ) { return m_time_start; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Activity_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"elapsed") ) { elapsed=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_elapsed") ) { m_elapsed=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_callback") ) { m_callback=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_cancelled") ) { m_cancelled=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_time_start") ) { m_time_start=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Activity_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_time_start"));
	outFields->push(HX_CSTRING("elapsed"));
	outFields->push(HX_CSTRING("m_elapsed"));
	outFields->push(HX_CSTRING("m_cancelled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Iterate"),
	HX_CSTRING("Delay"),
	HX_CSTRING("Run"),
	HX_CSTRING("RunOnce"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Activity_obj,m_callback),HX_CSTRING("m_callback")},
	{hx::fsFloat,(int)offsetof(Activity_obj,m_time_start),HX_CSTRING("m_time_start")},
	{hx::fsFloat,(int)offsetof(Activity_obj,elapsed),HX_CSTRING("elapsed")},
	{hx::fsFloat,(int)offsetof(Activity_obj,m_elapsed),HX_CSTRING("m_elapsed")},
	{hx::fsBool,(int)offsetof(Activity_obj,m_cancelled),HX_CSTRING("m_cancelled")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_callback"),
	HX_CSTRING("m_time_start"),
	HX_CSTRING("elapsed"),
	HX_CSTRING("get_elapsed"),
	HX_CSTRING("m_elapsed"),
	HX_CSTRING("m_cancelled"),
	HX_CSTRING("Cancel"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("OnRender"),
	HX_CSTRING("OnRun"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Activity_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Activity_obj::__mClass,"__mClass");
};

#endif

Class Activity_obj::__mClass;

void Activity_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.thread.Activity"), hx::TCanCast< Activity_obj> ,sStaticFields,sMemberFields,
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

void Activity_obj::__boot()
{
}

} // end namespace haxor
} // end namespace thread
