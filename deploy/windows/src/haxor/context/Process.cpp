#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

Void Process_obj::__construct(::String p_name,int p_size)
{
HX_STACK_FRAME("haxor.context.Process","new",0x44f4a996,"haxor.context.Process.new","haxor/context/Process.hx",51,0x5f329a1c)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_size,"p_size")
{
	HX_STACK_LINE(52)
	this->name = p_name;
	HX_STACK_LINE(53)
	int _g = (::haxor::context::Process_obj::m_cid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(53)
	this->_cid_ = _g;
	HX_STACK_LINE(54)
	this->list = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(55)
	this->m_length = (int)0;
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(56)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(56)
		while((true)){
			HX_STACK_LINE(56)
			if ((!(((_g1 < p_size))))){
				HX_STACK_LINE(56)
				break;
			}
			HX_STACK_LINE(56)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(58)
			this->list->__Field(HX_CSTRING("push"),true)(null());
		}
	}
}
;
	return null();
}

//Process_obj::~Process_obj() { }

Dynamic Process_obj::__CreateEmpty() { return  new Process_obj; }
hx::ObjectPtr< Process_obj > Process_obj::__new(::String p_name,int p_size)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(p_name,p_size);
	return result;}

Dynamic Process_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int Process_obj::get_length( ){
	HX_STACK_FRAME("haxor.context.Process","get_length",0xf24f5e39,"haxor.context.Process.get_length","haxor/context/Process.hx",31,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(31)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,get_length,return )

Void Process_obj::Add( ::haxor::core::Resource p_item){
{
		HX_STACK_FRAME("haxor.context.Process","Add",0x44d28337,"haxor.context.Process.Add","haxor/context/Process.hx",68,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(69)
		int iid = p_item->m_pid->__get(this->_cid_);		HX_STACK_VAR(iid,"iid");
		HX_STACK_LINE(70)
		if (((iid >= (int)0))){
			HX_STACK_LINE(70)
			return null();
		}
		HX_STACK_LINE(71)
		hx::IndexRef((this->list).mPtr,this->m_length) = p_item;
		HX_STACK_LINE(72)
		p_item->m_pid[this->_cid_] = (this->m_length)++;
		HX_STACK_LINE(73)
		::haxe::Log_obj::trace(((this->name + HX_CSTRING(" ")) + this->m_length),hx::SourceInfo(HX_CSTRING("Process.hx"),73,HX_CSTRING("haxor.context.Process"),HX_CSTRING("Add")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Process_obj,Add,(void))

::haxor::core::Resource Process_obj::Remove( ::haxor::core::Resource p_item){
	HX_STACK_FRAME("haxor.context.Process","Remove",0x2b7b5cee,"haxor.context.Process.Remove","haxor/context/Process.hx",81,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_item,"p_item")
	HX_STACK_LINE(83)
	int iid = p_item->m_pid->__get(this->_cid_);		HX_STACK_VAR(iid,"iid");
	HX_STACK_LINE(84)
	if (((iid < (int)0))){
		HX_STACK_LINE(84)
		return p_item;
	}
	HX_STACK_LINE(85)
	p_item->m_pid[this->_cid_] = (int)-1;
	HX_STACK_LINE(86)
	(this->m_length)--;
	HX_STACK_LINE(87)
	if (((this->m_length <= (int)0))){
		HX_STACK_LINE(87)
		return p_item;
	}
	HX_STACK_LINE(88)
	hx::IndexRef((this->list).mPtr,iid) = this->list->__GetItem(this->m_length);
	HX_STACK_LINE(89)
	p_item = this->list->__GetItem(iid);
	HX_STACK_LINE(90)
	p_item->m_pid[this->_cid_] = iid;
	HX_STACK_LINE(91)
	return p_item;
}


HX_DEFINE_DYNAMIC_FUNC1(Process_obj,Remove,return )

Void Process_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.Process","Clear",0x2cfaf423,"haxor.context.Process.Clear","haxor/context/Process.hx",98,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(99)
		this->m_length = (int)0;
		HX_STACK_LINE(100)
		this->list = Dynamic( Array_obj<Dynamic>::__new());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,Clear,(void))

int Process_obj::m_cid;


Process_obj::Process_obj()
{
}

void Process_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Process);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(_cid_,"_cid_");
	HX_MARK_MEMBER_NAME(m_remove_queue,"m_remove_queue");
	HX_MARK_END_CLASS();
}

void Process_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(_cid_,"_cid_");
	HX_VISIT_MEMBER_NAME(m_remove_queue,"m_remove_queue");
}

Dynamic Process_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
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
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_remove_queue") ) { return m_remove_queue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Process_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_cid") ) { m_cid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cid_") ) { _cid_=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_remove_queue") ) { m_remove_queue=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Process_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("list"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("_cid_"));
	outFields->push(HX_CSTRING("m_remove_queue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_cid"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Process_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Process_obj,list),HX_CSTRING("list")},
	{hx::fsInt,(int)offsetof(Process_obj,length),HX_CSTRING("length")},
	{hx::fsInt,(int)offsetof(Process_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsInt,(int)offsetof(Process_obj,_cid_),HX_CSTRING("_cid_")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Process_obj,m_remove_queue),HX_CSTRING("m_remove_queue")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("list"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("_cid_"),
	HX_CSTRING("m_remove_queue"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Process_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Process_obj::m_cid,"m_cid");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Process_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Process_obj::m_cid,"m_cid");
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
	m_cid= (int)0;
}

} // end namespace haxor
} // end namespace context
