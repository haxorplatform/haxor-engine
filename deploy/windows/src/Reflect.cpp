#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif

Void Reflect_obj::__construct()
{
	return null();
}

//Reflect_obj::~Reflect_obj() { }

Dynamic Reflect_obj::__CreateEmpty() { return  new Reflect_obj; }
hx::ObjectPtr< Reflect_obj > Reflect_obj::__new()
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

Dynamic Reflect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

bool Reflect_obj::isObject( Dynamic v){
	HX_STACK_FRAME("Reflect","isObject",0xd04960ba,"Reflect.isObject","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Reflect.hx",76,0xe7e96533)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(77)
	if (((v == null()))){
		HX_STACK_LINE(77)
		return false;
	}
	HX_STACK_LINE(78)
	int t = v->__GetType();		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(79)
	return (bool((bool((bool((t == ::vtObject)) || bool((t == ::vtClass)))) || bool((t == ::vtString)))) || bool((t == ::vtArray)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isObject,return )


Reflect_obj::Reflect_obj()
{
}

Dynamic Reflect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"isObject") ) { return isObject_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Reflect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Reflect_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isObject"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Reflect_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Reflect_obj::__mClass,"__mClass");
};

#endif

Class Reflect_obj::__mClass;

void Reflect_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Reflect"), hx::TCanCast< Reflect_obj> ,sStaticFields,sMemberFields,
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

void Reflect_obj::__boot()
{
}

