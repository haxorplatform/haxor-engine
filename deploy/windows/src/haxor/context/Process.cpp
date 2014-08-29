#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace context{

Void Process_obj::__construct(::String p_name,int p_size,hx::Null< bool >  __o_p_update_cid)
{
HX_STACK_FRAME("haxor.context.Process","new",0x44f4a996,"haxor.context.Process.new","haxor/context/Process.hx",29,0x5f329a1c)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_size,"p_size")
HX_STACK_ARG(__o_p_update_cid,"p_update_cid")
bool p_update_cid = __o_p_update_cid.Default(true);
{
	HX_STACK_LINE(30)
	super::__construct(p_name,p_update_cid);
	HX_STACK_LINE(31)
	this->list = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(32)
	this->m_length = (int)0;
	HX_STACK_LINE(33)
	{
		HX_STACK_LINE(33)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(33)
		while((true)){
			HX_STACK_LINE(33)
			if ((!(((_g < p_size))))){
				HX_STACK_LINE(33)
				break;
			}
			HX_STACK_LINE(33)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(35)
			this->list->__Field(HX_CSTRING("push"),true)(null());
		}
	}
}
;
	return null();
}

//Process_obj::~Process_obj() { }

Dynamic Process_obj::__CreateEmpty() { return  new Process_obj; }
hx::ObjectPtr< Process_obj > Process_obj::__new(::String p_name,int p_size,hx::Null< bool >  __o_p_update_cid)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(p_name,p_size,__o_p_update_cid);
	return result;}

Dynamic Process_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

int Process_obj::get_length( ){
	HX_STACK_FRAME("haxor.context.Process","get_length",0xf24f5e39,"haxor.context.Process.get_length","haxor/context/Process.hx",20,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	return this->m_length;
}


Void Process_obj::Add( ::haxor::core::Resource p_item){
{
		HX_STACK_FRAME("haxor.context.Process","Add",0x44d28337,"haxor.context.Process.Add","haxor/context/Process.hx",45,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(46)
		int iid = p_item->m_pid->__get(this->__cid);		HX_STACK_VAR(iid,"iid");
		HX_STACK_LINE(47)
		if (((iid >= (int)0))){
			HX_STACK_LINE(47)
			return null();
		}
		HX_STACK_LINE(48)
		if (((this->m_length >= this->list->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(48)
			this->list->__Field(HX_CSTRING("push"),true)(null());
		}
		HX_STACK_LINE(49)
		hx::IndexRef((this->list).mPtr,this->m_length) = p_item;
		HX_STACK_LINE(50)
		p_item->m_pid[this->__cid] = (this->m_length)++;
	}
return null();
}


::haxor::core::Resource Process_obj::Remove( ::haxor::core::Resource p_item){
	HX_STACK_FRAME("haxor.context.Process","Remove",0x2b7b5cee,"haxor.context.Process.Remove","haxor/context/Process.hx",58,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_item,"p_item")
	HX_STACK_LINE(59)
	int iid = p_item->m_pid->__get(this->__cid);		HX_STACK_VAR(iid,"iid");
	HX_STACK_LINE(60)
	if (((iid < (int)0))){
		HX_STACK_LINE(60)
		return p_item;
	}
	HX_STACK_LINE(61)
	p_item->m_pid[this->__cid] = (int)-1;
	HX_STACK_LINE(62)
	(this->m_length)--;
	HX_STACK_LINE(63)
	if (((this->m_length <= (int)0))){
		HX_STACK_LINE(63)
		return p_item;
	}
	HX_STACK_LINE(64)
	hx::IndexRef((this->list).mPtr,iid) = this->list->__GetItem(this->m_length);
	HX_STACK_LINE(65)
	p_item = this->list->__GetItem(iid);
	HX_STACK_LINE(66)
	p_item->m_pid[this->__cid] = iid;
	HX_STACK_LINE(67)
	return p_item;
}


Void Process_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.Process","Clear",0x2cfaf423,"haxor.context.Process.Clear","haxor/context/Process.hx",74,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(75)
		this->m_length = (int)0;
		HX_STACK_LINE(76)
		this->list = Dynamic( Array_obj<Dynamic>::__new());
	}
return null();
}



Process_obj::Process_obj()
{
}

void Process_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Process);
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	::haxor::context::BaseProcess_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Process_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	::haxor::context::BaseProcess_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Process_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Process_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Process_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("list"));
	outFields->push(HX_CSTRING("m_length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Process_obj,list),HX_CSTRING("list")},
	{hx::fsInt,(int)offsetof(Process_obj,m_length),HX_CSTRING("m_length")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("list"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Process_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Process_obj::__mClass,"__mClass");
};

#endif

Class Process_obj::__mClass;

void Process_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.Process"), hx::TCanCast< Process_obj> ,sStaticFields,sMemberFields,
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

void Process_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
