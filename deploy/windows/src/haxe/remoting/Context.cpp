#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_remoting_Context
#include <haxe/remoting/Context.h>
#endif
namespace haxe{
namespace remoting{

Void Context_obj::__construct()
{
	return null();
}

//Context_obj::~Context_obj() { }

Dynamic Context_obj::__CreateEmpty() { return  new Context_obj; }
hx::ObjectPtr< Context_obj > Context_obj::__new()
{  hx::ObjectPtr< Context_obj > result = new Context_obj();
	result->__construct();
	return result;}

Dynamic Context_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Context_obj > result = new Context_obj();
	result->__construct();
	return result;}

Dynamic Context_obj::call( Array< ::String > path,Dynamic params){
	HX_STACK_FRAME("haxe.remoting.Context","call",0xf0798760,"haxe.remoting.Context.call","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/remoting/Context.hx",36,0x3af4ab7f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_ARG(params,"params")
	HX_STACK_LINE(37)
	if (((path->length < (int)2))){
		HX_STACK_LINE(37)
		::String _g = path->join(HX_CSTRING("."));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(37)
		::String _g1 = (HX_CSTRING("Invalid path '") + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(37)
		HX_STACK_DO_THROW((_g1 + HX_CSTRING("'")));
	}
	HX_STACK_LINE(38)
	Dynamic inf = this->objects->get(path->__get((int)0));		HX_STACK_VAR(inf,"inf");
	HX_STACK_LINE(39)
	if (((inf == null()))){
		HX_STACK_LINE(40)
		HX_STACK_DO_THROW((HX_CSTRING("No such object ") + path->__get((int)0)));
	}
	HX_STACK_LINE(41)
	Dynamic o = inf->__Field(HX_CSTRING("obj"),true);		HX_STACK_VAR(o,"o");
	HX_STACK_LINE(42)
	Dynamic m = ::Reflect_obj::field(o,path->__get((int)1));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(43)
	if (((path->length > (int)2))){
		HX_STACK_LINE(44)
		if ((!(inf->__Field(HX_CSTRING("rec"),true)))){
			HX_STACK_LINE(44)
			::String _g2 = path->join(HX_CSTRING("."));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(44)
			HX_STACK_DO_THROW((HX_CSTRING("Can't access ") + _g2));
		}
		HX_STACK_LINE(45)
		{
			HX_STACK_LINE(45)
			int _g1 = (int)2;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			int _g = path->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(45)
			while((true)){
				HX_STACK_LINE(45)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(45)
					break;
				}
				HX_STACK_LINE(45)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(46)
				o = m;
				HX_STACK_LINE(47)
				Dynamic _g3 = ::Reflect_obj::field(o,path->__get(i));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(47)
				m = _g3;
			}
		}
	}
	HX_STACK_LINE(50)
	if ((!(::Reflect_obj::isFunction(m)))){
		HX_STACK_LINE(51)
		::String _g4 = path->join(HX_CSTRING("."));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(51)
		HX_STACK_DO_THROW((HX_CSTRING("No such method ") + _g4));
	}
	HX_STACK_LINE(52)
	return ::Reflect_obj::callMethod(o,m,params);
}


HX_DEFINE_DYNAMIC_FUNC2(Context_obj,call,return )


Context_obj::Context_obj()
{
}

void Context_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Context);
	HX_MARK_MEMBER_NAME(objects,"objects");
	HX_MARK_END_CLASS();
}

void Context_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(objects,"objects");
}

Dynamic Context_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { return objects; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Context_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { objects=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Context_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("objects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Context_obj,objects),HX_CSTRING("objects")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("objects"),
	HX_CSTRING("call"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Context_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Context_obj::__mClass,"__mClass");
};

#endif

Class Context_obj::__mClass;

void Context_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.remoting.Context"), hx::TCanCast< Context_obj> ,sStaticFields,sMemberFields,
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

void Context_obj::__boot()
{
}

} // end namespace haxe
} // end namespace remoting
