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
HX_STACK_FRAME("haxor.context.Process","new",0x44f4a996,"haxor.context.Process.new","haxor/context/Process.hx",31,0x5f329a1c)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_size,"p_size")
HX_STACK_ARG(__o_p_update_cid,"p_update_cid")
bool p_update_cid = __o_p_update_cid.Default(true);
{
	HX_STACK_LINE(32)
	super::__construct(p_name,p_update_cid);
	HX_STACK_LINE(33)
	this->list = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(34)
	this->m_length = (int)0;
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
	HX_STACK_FRAME("haxor.context.Process","get_length",0xf24f5e39,"haxor.context.Process.get_length","haxor/context/Process.hx",21,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_length;
}


Void Process_obj::Add( ::haxor::core::Resource p_item){
{
		HX_STACK_FRAME("haxor.context.Process","Add",0x44d28337,"haxor.context.Process.Add","haxor/context/Process.hx",49,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(50)
		int iid = p_item->__pid->__get(this->__cid);		HX_STACK_VAR(iid,"iid");
		HX_STACK_LINE(51)
		if (((iid >= (int)0))){
			HX_STACK_LINE(51)
			return null();
		}
		HX_STACK_LINE(52)
		if (((this->m_length >= this->list->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(52)
			this->list->__Field(HX_CSTRING("push"),true)(null());
		}
		HX_STACK_LINE(53)
		hx::IndexRef((this->list).mPtr,this->m_length) = p_item;
		HX_STACK_LINE(54)
		p_item->__pid[this->__cid] = (this->m_length)++;
	}
return null();
}


::haxor::core::Resource Process_obj::Remove( ::haxor::core::Resource p_item){
	HX_STACK_FRAME("haxor.context.Process","Remove",0x2b7b5cee,"haxor.context.Process.Remove","haxor/context/Process.hx",62,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_item,"p_item")
	HX_STACK_LINE(63)
	int iid = p_item->__pid->__get(this->__cid);		HX_STACK_VAR(iid,"iid");
	HX_STACK_LINE(64)
	if (((iid < (int)0))){
		HX_STACK_LINE(64)
		return p_item;
	}
	HX_STACK_LINE(65)
	p_item->__pid[this->__cid] = (int)-1;
	HX_STACK_LINE(66)
	(this->m_length)--;
	HX_STACK_LINE(67)
	if (((this->m_length <= (int)0))){
		HX_STACK_LINE(67)
		return p_item;
	}
	HX_STACK_LINE(68)
	hx::IndexRef((this->list).mPtr,iid) = this->list->__GetItem(this->m_length);
	HX_STACK_LINE(69)
	p_item = this->list->__GetItem(iid);
	HX_STACK_LINE(70)
	p_item->__pid[this->__cid] = iid;
	HX_STACK_LINE(71)
	return p_item;
}


Void Process_obj::Swap( Dynamic p_a,Dynamic p_b,hx::Null< bool >  __o_p_index_only){
bool p_index_only = __o_p_index_only.Default(false);
	HX_STACK_FRAME("haxor.context.Process","Swap",0xff548cbd,"haxor.context.Process.Swap","haxor/context/Process.hx",80,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_index_only,"p_index_only")
{
		HX_STACK_LINE(81)
		::haxor::core::Resource ra = p_a;		HX_STACK_VAR(ra,"ra");
		HX_STACK_LINE(82)
		::haxor::core::Resource rb = p_b;		HX_STACK_VAR(rb,"rb");
		HX_STACK_LINE(83)
		int ia = ra->__pid->__get(this->__cid);		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(84)
		if (((ia < (int)0))){
			HX_STACK_LINE(84)
			return null();
		}
		HX_STACK_LINE(85)
		int ib = rb->__pid->__get(this->__cid);		HX_STACK_VAR(ib,"ib");
		HX_STACK_LINE(86)
		if (((ib < (int)0))){
			HX_STACK_LINE(86)
			return null();
		}
		HX_STACK_LINE(88)
		if ((!(p_index_only))){
			HX_STACK_LINE(90)
			hx::IndexRef((this->list).mPtr,ia) = p_b;
			HX_STACK_LINE(91)
			hx::IndexRef((this->list).mPtr,ib) = p_a;
		}
		HX_STACK_LINE(94)
		rb->__pid[this->__cid] = ia;
		HX_STACK_LINE(95)
		ra->__pid[this->__cid] = ib;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Process_obj,Swap,(void))

Void Process_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.Process","Clear",0x2cfaf423,"haxor.context.Process.Clear","haxor/context/Process.hx",102,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(103)
		this->m_length = (int)0;
		HX_STACK_LINE(104)
		this->list = Dynamic( Array_obj<Dynamic>::__new());
	}
return null();
}


Void Process_obj::Sort( Dynamic p_method){
{
		HX_STACK_FRAME("haxor.context.Process","Sort",0xff4e8988,"haxor.context.Process.Sort","haxor/context/Process.hx",112,0x5f329a1c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_method,"p_method")
		HX_STACK_LINE(113)
		this->list->__Field(HX_CSTRING("sort"),true)(p_method);
		HX_STACK_LINE(114)
		{
			HX_STACK_LINE(114)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(114)
			int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(114)
			while((true)){
				HX_STACK_LINE(114)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(114)
					break;
				}
				HX_STACK_LINE(114)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(116)
				::haxor::core::Resource it = this->list->__GetItem(i);		HX_STACK_VAR(it,"it");
				HX_STACK_LINE(117)
				if (((it != null()))){
					HX_STACK_LINE(117)
					it->__pid[this->__cid] = i;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Process_obj,Sort,(void))

::String Process_obj::ToString( ){
	HX_STACK_FRAME("haxor.context.Process","ToString",0x12128fd6,"haxor.context.Process.ToString","haxor/context/Process.hx",126,0x5f329a1c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	::String log = HX_CSTRING("");		HX_STACK_VAR(log,"log");
	HX_STACK_LINE(128)
	{
		HX_STACK_LINE(128)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(128)
		int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(128)
		while((true)){
			HX_STACK_LINE(128)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(128)
				break;
			}
			HX_STACK_LINE(128)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(130)
			::haxor::core::Resource it = this->list->__GetItem(i);		HX_STACK_VAR(it,"it");
			HX_STACK_LINE(131)
			::String _g2 = it->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(131)
			::String _g11 = (HX_CSTRING("[") + _g2);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(131)
			::String _g21 = (_g11 + HX_CSTRING(","));		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(131)
			::String _g3 = (_g21 + it->__pid->__get(this->__cid));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(131)
			::String _g4 = (_g3 + HX_CSTRING("]"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(131)
			hx::AddEq(log,_g4);
		}
	}
	HX_STACK_LINE(133)
	return log;
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,ToString,return )


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
		if (HX_FIELD_EQ(inName,"Swap") ) { return Swap_dyn(); }
		if (HX_FIELD_EQ(inName,"Sort") ) { return Sort_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
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
	HX_CSTRING("Swap"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Sort"),
	HX_CSTRING("ToString"),
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
