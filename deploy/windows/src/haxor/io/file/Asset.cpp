#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_io_file_Asset
#include <haxor/io/file/Asset.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void Asset_obj::__construct()
{
	return null();
}

//Asset_obj::~Asset_obj() { }

Dynamic Asset_obj::__CreateEmpty() { return  new Asset_obj; }
hx::ObjectPtr< Asset_obj > Asset_obj::__new()
{  hx::ObjectPtr< Asset_obj > result = new Asset_obj();
	result->__construct();
	return result;}

Dynamic Asset_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Asset_obj > result = new Asset_obj();
	result->__construct();
	return result;}

::haxe::ds::StringMap Asset_obj::m_database;

Dynamic Asset_obj::Get( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.Asset","Get",0x944d9cc2,"haxor.io.file.Asset.Get","haxor/io/file/Asset.hx",21,0x618f92a5)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(21)
	if ((::haxor::io::file::Asset_obj::m_database->exists(p_id))){
		HX_STACK_LINE(21)
		return ::haxor::io::file::Asset_obj::m_database->get(p_id);
	}
	else{
		HX_STACK_LINE(21)
		return null();
	}
	HX_STACK_LINE(21)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Asset_obj,Get,return )

Dynamic Asset_obj::Remove( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.Asset","Remove",0x58f86398,"haxor.io.file.Asset.Remove","haxor/io/file/Asset.hx",28,0x618f92a5)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(28)
	if ((::haxor::io::file::Asset_obj::m_database->exists(p_id))){
		HX_STACK_LINE(28)
		Dynamic a = ::haxor::io::file::Asset_obj::m_database->get(p_id);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(28)
		::haxor::io::file::Asset_obj::m_database->remove(p_id);
		HX_STACK_LINE(28)
		return a;
	}
	HX_STACK_LINE(28)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Asset_obj,Remove,return )

Void Asset_obj::Add( ::String p_id,Dynamic p_asset){
{
		HX_STACK_FRAME("haxor.io.file.Asset","Add",0x94490e4d,"haxor.io.file.Asset.Add","haxor/io/file/Asset.hx",36,0x618f92a5)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_asset,"p_asset")
		HX_STACK_LINE(36)
		{
			HX_STACK_LINE(36)
			Dynamic value = p_asset;		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(36)
			::haxor::io::file::Asset_obj::m_database->set(p_id,value);
		}
		HX_STACK_LINE(36)
		if ((::Std_obj::is(p_asset,hx::ClassOf< ::haxor::core::Resource >()))){
			HX_STACK_LINE(36)
			(hx::TCast< haxor::core::Resource >::cast(p_asset))->__db = p_id;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,Add,(void))


Asset_obj::Asset_obj()
{
}

Dynamic Asset_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_database") ) { return m_database; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Asset_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"m_database") ) { m_database=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Asset_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_database"),
	HX_CSTRING("Get"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Add"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Asset_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Asset_obj::m_database,"m_database");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Asset_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Asset_obj::m_database,"m_database");
};

#endif

Class Asset_obj::__mClass;

void Asset_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.Asset"), hx::TCanCast< Asset_obj> ,sStaticFields,sMemberFields,
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

void Asset_obj::__boot()
{
	m_database= ::haxe::ds::StringMap_obj::__new();
}

} // end namespace haxor
} // end namespace io
} // end namespace file
