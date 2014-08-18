#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace context{

Void BaseProcess_obj::__construct(::String p_name)
{
HX_STACK_FRAME("haxor.context.BaseProcess","new",0x99559f85,"haxor.context.BaseProcess.new","haxor/context/Process.hx",112,0x5f329a1c)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
{
	HX_STACK_LINE(113)
	this->name = p_name;
	HX_STACK_LINE(114)
	::haxor::core::Console_obj::Log(((HX_CSTRING("\tProcess [") + p_name) + HX_CSTRING("] created.")),(int)4);
	HX_STACK_LINE(115)
	int _g = (::haxor::context::BaseProcess_obj::m_cid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(115)
	this->_cid_ = _g;
}
;
	return null();
}

//BaseProcess_obj::~BaseProcess_obj() { }

Dynamic BaseProcess_obj::__CreateEmpty() { return  new BaseProcess_obj; }
hx::ObjectPtr< BaseProcess_obj > BaseProcess_obj::__new(::String p_name)
{  hx::ObjectPtr< BaseProcess_obj > result = new BaseProcess_obj();
	result->__construct(p_name);
	return result;}

Dynamic BaseProcess_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseProcess_obj > result = new BaseProcess_obj();
	result->__construct(inArgs[0]);
	return result;}

int BaseProcess_obj::get_length( ){
	HX_STACK_FRAME("haxor.context.BaseProcess","get_length",0x973f942a,"haxor.context.BaseProcess.get_length","haxor/context/Process.hx",105,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(105)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseProcess_obj,get_length,return )

Void BaseProcess_obj::Add( ::haxor::core::Resource p_item){
{
		HX_STACK_FRAME("haxor.context.BaseProcess","Add",0x99337926,"haxor.context.BaseProcess.Add","haxor/context/Process.hx",122,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseProcess_obj,Add,(void))

::haxor::core::Resource BaseProcess_obj::Remove( ::haxor::core::Resource p_item){
	HX_STACK_FRAME("haxor.context.BaseProcess","Remove",0x625b865f,"haxor.context.BaseProcess.Remove","haxor/context/Process.hx",129,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_item,"p_item")
	HX_STACK_LINE(129)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseProcess_obj,Remove,return )

Void BaseProcess_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.BaseProcess","Clear",0x13f883d2,"haxor.context.BaseProcess.Clear","haxor/context/Process.hx",134,0x5f329a1c)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseProcess_obj,Clear,(void))

int BaseProcess_obj::m_cid;


BaseProcess_obj::BaseProcess_obj()
{
}

void BaseProcess_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseProcess);
	HX_MARK_MEMBER_NAME(_cid_,"_cid_");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void BaseProcess_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_cid_,"_cid_");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic BaseProcess_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_cid") ) { return m_cid; }
		if (HX_FIELD_EQ(inName,"_cid_") ) { return _cid_; }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseProcess_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_cid") ) { m_cid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cid_") ) { _cid_=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseProcess_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_cid_"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_cid"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(BaseProcess_obj,_cid_),HX_CSTRING("_cid_")},
	{hx::fsString,(int)offsetof(BaseProcess_obj,name),HX_CSTRING("name")},
	{hx::fsInt,(int)offsetof(BaseProcess_obj,length),HX_CSTRING("length")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_cid_"),
	HX_CSTRING("name"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseProcess_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BaseProcess_obj::m_cid,"m_cid");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseProcess_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BaseProcess_obj::m_cid,"m_cid");
};

#endif

Class BaseProcess_obj::__mClass;

void BaseProcess_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.BaseProcess"), hx::TCanCast< BaseProcess_obj> ,sStaticFields,sMemberFields,
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

void BaseProcess_obj::__boot()
{
	m_cid= (int)0;
}

} // end namespace haxor
} // end namespace context
