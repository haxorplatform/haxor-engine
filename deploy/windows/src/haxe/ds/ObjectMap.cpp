#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
namespace haxe{
namespace ds{

Void ObjectMap_obj::__construct()
{
HX_STACK_FRAME("haxe.ds.ObjectMap","new",0x27af5498,"haxe.ds.ObjectMap.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/ObjectMap.hx",29,0x71824d6a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	::haxe::ds::IntMap _g = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->__Internal = _g;
	HX_STACK_LINE(31)
	::haxe::ds::IntMap _g1 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	this->__KeyRefs = _g1;
}
;
	return null();
}

//ObjectMap_obj::~ObjectMap_obj() { }

Dynamic ObjectMap_obj::__CreateEmpty() { return  new ObjectMap_obj; }
hx::ObjectPtr< ObjectMap_obj > ObjectMap_obj::__new()
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct();
	return result;}

Dynamic ObjectMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct();
	return result;}

hx::Object *ObjectMap_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::IMap_obj)) return operator ::IMap_obj *();
	return super::__ToInterface(inType);
}

Void ObjectMap_obj::set( Dynamic key,Dynamic value){
{
		HX_STACK_FRAME("haxe.ds.ObjectMap","set",0x27b31fda,"haxe.ds.ObjectMap.set","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/ObjectMap.hx",34,0x71824d6a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(key,"key")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(35)
		int id = ::__hxcpp_obj_id(key);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(36)
		this->__Internal->set(id,value);
		HX_STACK_LINE(37)
		this->__KeyRefs->set(id,key);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ObjectMap_obj,set,(void))

Dynamic ObjectMap_obj::get( Dynamic key){
	HX_STACK_FRAME("haxe.ds.ObjectMap","get",0x27aa04ce,"haxe.ds.ObjectMap.get","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/ObjectMap.hx",40,0x71824d6a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(41)
	int _g = ::__hxcpp_obj_id(key);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	return this->__Internal->get(_g);
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,get,return )

Dynamic ObjectMap_obj::keys( ){
	HX_STACK_FRAME("haxe.ds.ObjectMap","keys",0x8fbf0ebc,"haxe.ds.ObjectMap.keys","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/ObjectMap.hx",55,0x71824d6a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->__KeyRefs->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectMap_obj,keys,return )


ObjectMap_obj::ObjectMap_obj()
{
}

void ObjectMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectMap);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_MEMBER_NAME(__KeyRefs,"__KeyRefs");
	HX_MARK_END_CLASS();
}

void ObjectMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__Internal,"__Internal");
	HX_VISIT_MEMBER_NAME(__KeyRefs,"__KeyRefs");
}

Dynamic ObjectMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"__KeyRefs") ) { return __KeyRefs; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"__KeyRefs") ) { __KeyRefs=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__Internal"));
	outFields->push(HX_CSTRING("__KeyRefs"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::IntMap*/ ,(int)offsetof(ObjectMap_obj,__Internal),HX_CSTRING("__Internal")},
	{hx::fsObject /*::haxe::ds::IntMap*/ ,(int)offsetof(ObjectMap_obj,__KeyRefs),HX_CSTRING("__KeyRefs")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__Internal"),
	HX_CSTRING("__KeyRefs"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("keys"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectMap_obj::__mClass,"__mClass");
};

#endif

Class ObjectMap_obj::__mClass;

void ObjectMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.ds.ObjectMap"), hx::TCanCast< ObjectMap_obj> ,sStaticFields,sMemberFields,
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

void ObjectMap_obj::__boot()
{
}

} // end namespace haxe
} // end namespace ds
