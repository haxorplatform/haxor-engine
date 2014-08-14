#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
namespace cpp{
namespace vm{

Void Thread_obj::__construct(Dynamic h)
{
HX_STACK_FRAME("cpp.vm.Thread","new",0x66262c28,"cpp.vm.Thread.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/vm/Thread.hx",31,0x56a056f5)
HX_STACK_THIS(this)
HX_STACK_ARG(h,"h")
{
	HX_STACK_LINE(31)
	this->handle = h;
}
;
	return null();
}

//Thread_obj::~Thread_obj() { }

Dynamic Thread_obj::__CreateEmpty() { return  new Thread_obj; }
hx::ObjectPtr< Thread_obj > Thread_obj::__new(Dynamic h)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(h);
	return result;}

Dynamic Thread_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Thread_obj > result = new Thread_obj();
	result->__construct(inArgs[0]);
	return result;}

::cpp::vm::Thread Thread_obj::create( Dynamic callb){
	HX_STACK_FRAME("cpp.vm.Thread","create",0xb01a9834,"cpp.vm.Thread.create","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/vm/Thread.hx",52,0x56a056f5)
	HX_STACK_ARG(callb,"callb")
	HX_STACK_LINE(53)
	Dynamic _g = ::__hxcpp_thread_create(callb);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(53)
	return ::cpp::vm::Thread_obj::__new(_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Thread_obj,create,return )


Thread_obj::Thread_obj()
{
}

void Thread_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Thread);
	HX_MARK_MEMBER_NAME(handle,"handle");
	HX_MARK_END_CLASS();
}

void Thread_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(handle,"handle");
}

Dynamic Thread_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"handle") ) { return handle; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Thread_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"handle") ) { handle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Thread_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("handle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Thread_obj,handle),HX_CSTRING("handle")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("handle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Thread_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Thread_obj::__mClass,"__mClass");
};

#endif

Class Thread_obj::__mClass;

void Thread_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.vm.Thread"), hx::TCanCast< Thread_obj> ,sStaticFields,sMemberFields,
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

void Thread_obj::__boot()
{
}

} // end namespace cpp
} // end namespace vm
