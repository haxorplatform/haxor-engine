#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
namespace haxor{
namespace context{

Void UID_obj::__construct()
{
HX_STACK_FRAME("haxor.context.UID","new",0x5223f4b7,"haxor.context.UID.new","haxor/context/UID.hx",20,0xa116651b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(21)
	this->m_id = (int)0;
	HX_STACK_LINE(22)
	this->m_cache = Array_obj< int >::__new();
}
;
	return null();
}

//UID_obj::~UID_obj() { }

Dynamic UID_obj::__CreateEmpty() { return  new UID_obj; }
hx::ObjectPtr< UID_obj > UID_obj::__new()
{  hx::ObjectPtr< UID_obj > result = new UID_obj();
	result->__construct();
	return result;}

Dynamic UID_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UID_obj > result = new UID_obj();
	result->__construct();
	return result;}

int UID_obj::get_id( ){
	HX_STACK_FRAME("haxor.context.UID","get_id",0x588fdf2d,"haxor.context.UID.get_id","haxor/context/UID.hx",14,0xa116651b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(14)
	if (((this->m_cache->length <= (int)0))){
		HX_STACK_LINE(14)
		return (this->m_id)++;
	}
	else{
		HX_STACK_LINE(14)
		return this->m_cache->shift();
	}
	HX_STACK_LINE(14)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(UID_obj,get_id,return )

int UID_obj::set_id( int v){
	HX_STACK_FRAME("haxor.context.UID","set_id",0x24d833a1,"haxor.context.UID.set_id","haxor/context/UID.hx",15,0xa116651b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(15)
	this->m_cache->push(v);
	HX_STACK_LINE(15)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(UID_obj,set_id,return )


UID_obj::UID_obj()
{
}

void UID_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UID);
	HX_MARK_MEMBER_NAME(m_id,"m_id");
	HX_MARK_MEMBER_NAME(m_cache,"m_cache");
	HX_MARK_END_CLASS();
}

void UID_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_id,"m_id");
	HX_VISIT_MEMBER_NAME(m_cache,"m_cache");
}

Dynamic UID_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_id") ) { return m_id; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		if (HX_FIELD_EQ(inName,"set_id") ) { return set_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_cache") ) { return m_cache; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UID_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return set_id(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_id") ) { m_id=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_cache") ) { m_cache=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UID_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("m_id"));
	outFields->push(HX_CSTRING("m_cache"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(UID_obj,m_id),HX_CSTRING("m_id")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(UID_obj,m_cache),HX_CSTRING("m_cache")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_id"),
	HX_CSTRING("set_id"),
	HX_CSTRING("m_id"),
	HX_CSTRING("m_cache"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UID_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UID_obj::__mClass,"__mClass");
};

#endif

Class UID_obj::__mClass;

void UID_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.UID"), hx::TCanCast< UID_obj> ,sStaticFields,sMemberFields,
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

void UID_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
