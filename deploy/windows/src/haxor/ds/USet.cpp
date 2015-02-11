#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_USet
#include <haxor/ds/USet.h>
#endif
namespace haxor{
namespace ds{

Void USet_obj::__construct()
{
HX_STACK_FRAME("haxor.ds.USet","new",0x2fb2e252,"haxor.ds.USet.new","haxor/ds/USet.hx",36,0xa1062abe)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(37)
	this->m_list = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(38)
	this->m_length = (int)0;
}
;
	return null();
}

//USet_obj::~USet_obj() { }

Dynamic USet_obj::__CreateEmpty() { return  new USet_obj; }
hx::ObjectPtr< USet_obj > USet_obj::__new()
{  hx::ObjectPtr< USet_obj > result = new USet_obj();
	result->__construct();
	return result;}

Dynamic USet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< USet_obj > result = new USet_obj();
	result->__construct();
	return result;}

int USet_obj::get_length( ){
	HX_STACK_FRAME("haxor.ds.USet","get_length",0x0553f4fd,"haxor.ds.USet.get_length","haxor/ds/USet.hx",22,0xa1062abe)
	HX_STACK_THIS(this)
	HX_STACK_LINE(22)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(USet_obj,get_length,return )

Void USet_obj::Add( Dynamic p_item){
{
		HX_STACK_FRAME("haxor.ds.USet","Add",0x2f90bbf3,"haxor.ds.USet.Add","haxor/ds/USet.hx",46,0xa1062abe)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(47)
		if (((p_item->__Field(HX_CSTRING("usid"),true) >= (int)0))){
			HX_STACK_LINE(47)
			return null();
		}
		HX_STACK_LINE(49)
		if (((this->m_length >= this->m_list->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(51)
			this->m_list->__Field(HX_CSTRING("push"),true)(p_item);
		}
		else{
			HX_STACK_LINE(55)
			hx::IndexRef((this->m_list).mPtr,this->m_length) = p_item;
		}
		HX_STACK_LINE(57)
		int _g = (this->m_length)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		p_item->__FieldRef(HX_CSTRING("usid")) = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(USet_obj,Add,(void))

Void USet_obj::Remove( Dynamic p_item){
{
		HX_STACK_FRAME("haxor.ds.USet","Remove",0x8bb441b2,"haxor.ds.USet.Remove","haxor/ds/USet.hx",65,0xa1062abe)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(66)
		int oid = p_item->__Field(HX_CSTRING("usid"),true);		HX_STACK_VAR(oid,"oid");
		HX_STACK_LINE(67)
		if (((oid < (int)0))){
			HX_STACK_LINE(67)
			return null();
		}
		HX_STACK_LINE(68)
		if (((this->m_length <= (int)0))){
			HX_STACK_LINE(68)
			return null();
		}
		HX_STACK_LINE(69)
		Dynamic last = this->m_list->__GetItem((this->m_length - (int)1));		HX_STACK_VAR(last,"last");
		HX_STACK_LINE(70)
		hx::IndexRef((this->m_list).mPtr,oid) = last;
		HX_STACK_LINE(71)
		last->__FieldRef(HX_CSTRING("usid")) = oid;
		HX_STACK_LINE(72)
		p_item->__FieldRef(HX_CSTRING("usid")) = (int)-1;
		HX_STACK_LINE(73)
		(this->m_length)--;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(USet_obj,Remove,(void))

Dynamic USet_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.ds.USet","Get",0x2f954a68,"haxor.ds.USet.Get","haxor/ds/USet.hx",81,0xa1062abe)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(81)
	return this->m_list->__GetItem(p_index);
}


HX_DEFINE_DYNAMIC_FUNC1(USet_obj,Get,return )

Void USet_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.ds.USet","Clear",0xee45d3df,"haxor.ds.USet.Clear","haxor/ds/USet.hx",86,0xa1062abe)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		this->m_length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(USet_obj,Clear,(void))


USet_obj::USet_obj()
{
}

void USet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(USet);
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(m_list,"m_list");
	HX_MARK_END_CLASS();
}

void USet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(m_list,"m_list");
}

Dynamic USet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		if (HX_FIELD_EQ(inName,"m_list") ) { return m_list; }
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

Dynamic USet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { m_list=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void USet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("m_list"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(USet_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(USet_obj,m_list),HX_CSTRING("m_list")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("m_list"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Get"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(USet_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(USet_obj::__mClass,"__mClass");
};

#endif

Class USet_obj::__mClass;

void USet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.USet"), hx::TCanCast< USet_obj> ,sStaticFields,sMemberFields,
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

void USet_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
