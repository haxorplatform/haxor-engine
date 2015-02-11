#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxor_ds_Pool
#include <haxor/ds/Pool.h>
#endif
namespace haxor{
namespace ds{

Void Pool_obj::__construct(::Class p_type,hx::Null< int >  __o_p_count)
{
HX_STACK_FRAME("haxor.ds.Pool","new",0x026c9c81,"haxor.ds.Pool.new","haxor/ds/Pool.hx",30,0xbfd10b6f)
HX_STACK_THIS(this)
HX_STACK_ARG(p_type,"p_type")
HX_STACK_ARG(__o_p_count,"p_count")
int p_count = __o_p_count.Default(0);
{
	HX_STACK_LINE(31)
	this->m_type = p_type;
	HX_STACK_LINE(32)
	this->m_top = (int)0;
	HX_STACK_LINE(33)
	this->m_list = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(34)
	{
		HX_STACK_LINE(34)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(34)
		while((true)){
			HX_STACK_LINE(34)
			if ((!(((_g < p_count))))){
				HX_STACK_LINE(34)
				break;
			}
			HX_STACK_LINE(34)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(34)
			this->Generate();
		}
	}
}
;
	return null();
}

//Pool_obj::~Pool_obj() { }

Dynamic Pool_obj::__CreateEmpty() { return  new Pool_obj; }
hx::ObjectPtr< Pool_obj > Pool_obj::__new(::Class p_type,hx::Null< int >  __o_p_count)
{  hx::ObjectPtr< Pool_obj > result = new Pool_obj();
	result->__construct(p_type,__o_p_count);
	return result;}

Dynamic Pool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Pool_obj > result = new Pool_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic Pool_obj::Get( ){
	HX_STACK_FRAME("haxor.ds.Pool","Get",0x024f0497,"haxor.ds.Pool.Get","haxor/ds/Pool.hx",41,0xbfd10b6f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(41)
	if (((this->m_top <= (int)0))){
		HX_STACK_LINE(41)
		this->Generate();
	}
	HX_STACK_LINE(41)
	int _g = --(this->m_top);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	return this->m_list->__GetItem(_g);
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,Get,return )

Void Pool_obj::Put( Dynamic v){
{
		HX_STACK_FRAME("haxor.ds.Pool","Put",0x0255e6d0,"haxor.ds.Pool.Put","haxor/ds/Pool.hx",47,0xbfd10b6f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(47)
		int _g = (this->m_top)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(47)
		hx::IndexRef((this->m_list).mPtr,_g) = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Pool_obj,Put,(void))

Void Pool_obj::Generate( ){
{
		HX_STACK_FRAME("haxor.ds.Pool","Generate",0x199eb794,"haxor.ds.Pool.Generate","haxor/ds/Pool.hx",54,0xbfd10b6f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(55)
		Dynamic d = ::Type_obj::createInstance(this->m_type,Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(56)
		this->m_list->__Field(HX_CSTRING("unshift"),true)(d);
		HX_STACK_LINE(57)
		(this->m_top)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Pool_obj,Generate,(void))


Pool_obj::Pool_obj()
{
}

void Pool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Pool);
	HX_MARK_MEMBER_NAME(m_list,"m_list");
	HX_MARK_MEMBER_NAME(m_top,"m_top");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_END_CLASS();
}

void Pool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_list,"m_list");
	HX_VISIT_MEMBER_NAME(m_top,"m_top");
	HX_VISIT_MEMBER_NAME(m_type,"m_type");
}

Dynamic Pool_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Put") ) { return Put_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_top") ) { return m_top; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { return m_list; }
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Generate") ) { return Generate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Pool_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"m_top") ) { m_top=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { m_list=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< ::Class >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Pool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_list"));
	outFields->push(HX_CSTRING("m_top"));
	outFields->push(HX_CSTRING("m_type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Pool_obj,m_list),HX_CSTRING("m_list")},
	{hx::fsInt,(int)offsetof(Pool_obj,m_top),HX_CSTRING("m_top")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(Pool_obj,m_type),HX_CSTRING("m_type")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_list"),
	HX_CSTRING("m_top"),
	HX_CSTRING("m_type"),
	HX_CSTRING("Get"),
	HX_CSTRING("Put"),
	HX_CSTRING("Generate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Pool_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Pool_obj::__mClass,"__mClass");
};

#endif

Class Pool_obj::__mClass;

void Pool_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.Pool"), hx::TCanCast< Pool_obj> ,sStaticFields,sMemberFields,
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

void Pool_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
