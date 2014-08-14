#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
namespace haxe{
namespace ds{

Void IntMap_obj::__construct()
{
HX_STACK_FRAME("haxe.ds.IntMap","new",0x7222c4b6,"haxe.ds.IntMap.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/IntMap.hx",28,0x370c2ca8)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	Dynamic _g = ::__int_hash_create();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	this->h = _g;
}
;
	return null();
}

//IntMap_obj::~IntMap_obj() { }

Dynamic IntMap_obj::__CreateEmpty() { return  new IntMap_obj; }
hx::ObjectPtr< IntMap_obj > IntMap_obj::__new()
{  hx::ObjectPtr< IntMap_obj > result = new IntMap_obj();
	result->__construct();
	return result;}

Dynamic IntMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntMap_obj > result = new IntMap_obj();
	result->__construct();
	return result;}

hx::Object *IntMap_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::IMap_obj)) return operator ::IMap_obj *();
	return super::__ToInterface(inType);
}

Void IntMap_obj::set( int key,Dynamic value){
{
		HX_STACK_FRAME("haxe.ds.IntMap","set",0x72268ff8,"haxe.ds.IntMap.set","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/IntMap.hx",33,0x370c2ca8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(key,"key")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(33)
		::__int_hash_set(this->h,key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IntMap_obj,set,(void))

Dynamic IntMap_obj::get( int key){
	HX_STACK_FRAME("haxe.ds.IntMap","get",0x721d74ec,"haxe.ds.IntMap.get","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/IntMap.hx",37,0x370c2ca8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(37)
	return ::__int_hash_get(this->h,key);
}


HX_DEFINE_DYNAMIC_FUNC1(IntMap_obj,get,return )

Dynamic IntMap_obj::keys( ){
	HX_STACK_FRAME("haxe.ds.IntMap","keys",0x6a4db8de,"haxe.ds.IntMap.keys","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/IntMap.hx",48,0x370c2ca8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	Array< int > a = ::__int_hash_keys(this->h);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(50)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(IntMap_obj,keys,return )

Dynamic IntMap_obj::iterator( ){
	HX_STACK_FRAME("haxe.ds.IntMap","iterator",0x4dc7ddd8,"haxe.ds.IntMap.iterator","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/haxe/ds/IntMap.hx",53,0x370c2ca8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	Dynamic a = ::__int_hash_values(this->h);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(55)
	return a->__Field(HX_CSTRING("iterator"),true)();
}


HX_DEFINE_DYNAMIC_FUNC0(IntMap_obj,iterator,return )


IntMap_obj::IntMap_obj()
{
}

void IntMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IntMap);
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_END_CLASS();
}

void IntMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(h,"h");
}

Dynamic IntMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IntMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IntMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("h"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(IntMap_obj,h),HX_CSTRING("h")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("h"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("keys"),
	HX_CSTRING("iterator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IntMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IntMap_obj::__mClass,"__mClass");
};

#endif

Class IntMap_obj::__mClass;

void IntMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.ds.IntMap"), hx::TCanCast< IntMap_obj> ,sStaticFields,sMemberFields,
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

void IntMap_obj::__boot()
{
}

} // end namespace haxe
} // end namespace ds
