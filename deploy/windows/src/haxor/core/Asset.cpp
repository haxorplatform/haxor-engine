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
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_Asset
#include <haxor/core/Asset.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaFile
#include <haxor/io/file/ColladaFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_MaterialFile
#include <haxor/io/file/MaterialFile.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
namespace haxor{
namespace core{

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

::haxe::ds::StringMap Asset_obj::m_load_progress;

Float Asset_obj::get_progress( ){
	HX_STACK_FRAME("haxor.core.Asset","get_progress",0x9e518c97,"haxor.core.Asset.get_progress","haxor/core/Asset.hx",38,0xf4b04511)
	HX_STACK_LINE(39)
	Float l = 0.0;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(40)
	Float t = 0.0;		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(41)
	Dynamic it = ::haxor::core::Asset_obj::m_load_progress->keys();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(42)
	while((true)){
		HX_STACK_LINE(42)
		if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(42)
			break;
		}
		HX_STACK_LINE(44)
		::String k = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(45)
		Dynamic _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(45)
		if ((::haxor::core::Asset_obj::m_load_progress->exists(k))){
			HX_STACK_LINE(45)
			_g = ::haxor::core::Asset_obj::m_load_progress->get(k);
		}
		else{
			HX_STACK_LINE(45)
			_g = 0.0;
		}
		HX_STACK_LINE(45)
		hx::AddEq(l,_g);
		HX_STACK_LINE(46)
		hx::AddEq(t,1.0);
	}
	HX_STACK_LINE(48)
	if (((t <= 0.0))){
		HX_STACK_LINE(48)
		return 0.0;
	}
	else{
		HX_STACK_LINE(48)
		return (Float(l) / Float(t));
	}
	HX_STACK_LINE(48)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Asset_obj,get_progress,return )

Dynamic Asset_obj::Get( ::String p_id){
	HX_STACK_FRAME("haxor.core.Asset","Get",0xd02cf7b5,"haxor.core.Asset.Get","haxor/core/Asset.hx",56,0xf4b04511)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(56)
	if ((::haxor::core::Asset_obj::m_database->exists(p_id))){
		HX_STACK_LINE(56)
		return ::haxor::core::Asset_obj::m_database->get(p_id);
	}
	else{
		HX_STACK_LINE(56)
		return null();
	}
	HX_STACK_LINE(56)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Asset_obj,Get,return )

Dynamic Asset_obj::Remove( ::String p_id){
	HX_STACK_FRAME("haxor.core.Asset","Remove",0xb04c2285,"haxor.core.Asset.Remove","haxor/core/Asset.hx",63,0xf4b04511)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(63)
	if ((::haxor::core::Asset_obj::m_database->exists(p_id))){
		HX_STACK_LINE(63)
		Dynamic a = ::haxor::core::Asset_obj::m_database->get(p_id);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(63)
		::haxor::core::Asset_obj::m_database->remove(p_id);
		HX_STACK_LINE(63)
		return a;
	}
	HX_STACK_LINE(63)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Asset_obj,Remove,return )

Void Asset_obj::Add( ::String p_id,Dynamic p_asset){
{
		HX_STACK_FRAME("haxor.core.Asset","Add",0xd0286940,"haxor.core.Asset.Add","haxor/core/Asset.hx",71,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_asset,"p_asset")
		HX_STACK_LINE(71)
		{
			HX_STACK_LINE(71)
			Dynamic value = p_asset;		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(71)
			::haxor::core::Asset_obj::m_database->set(p_id,value);
		}
		HX_STACK_LINE(71)
		if ((::Std_obj::is(p_asset,hx::ClassOf< ::haxor::core::Resource >()))){
			HX_STACK_LINE(71)
			(hx::TCast< haxor::core::Resource >::cast(p_asset))->__db = p_id;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,Add,(void))

Void Asset_obj::LoadTexture2D( ::String p_id,::String p_url){
{
		HX_STACK_FRAME("haxor.core.Asset","LoadTexture2D",0xc1d72646,"haxor.core.Asset.LoadTexture2D","haxor/core/Asset.hx",78,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_LINE(78)
		Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");
		HX_STACK_LINE(80)
		::haxor::core::Asset_obj::m_load_progress->set(p_id1->__get((int)0),0.0);

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,p_id1)
		Void run(::haxor::graphics::texture::Texture2D d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Asset.hx",81,0xf4b04511)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(81)
				::haxor::core::Asset_obj::UpdateProgress(p_id1->__get((int)0),p,d);
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(81)
		::haxor::net::Web_obj::LoadTexture2D(p_url,true, Dynamic(new _Function_1_1(p_id1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,LoadTexture2D,(void))

Void Asset_obj::LoadCollada( ::String p_id,::String p_url){
{
		HX_STACK_FRAME("haxor.core.Asset","LoadCollada",0x5ee48a0b,"haxor.core.Asset.LoadCollada","haxor/core/Asset.hx",89,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_LINE(89)
		Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,p_id1)
		Void run(::haxor::io::file::ColladaFile d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Asset.hx",89,0xf4b04511)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(89)
				::haxor::core::Asset_obj::UpdateProgress(p_id1->__get((int)0),p,d);
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(89)
		::haxor::net::Web_obj::LoadCollada(p_url, Dynamic(new _Function_1_1(p_id1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,LoadCollada,(void))

Void Asset_obj::LoadShader( ::String p_id,::String p_url){
{
		HX_STACK_FRAME("haxor.core.Asset","LoadShader",0x3a5628ac,"haxor.core.Asset.LoadShader","haxor/core/Asset.hx",96,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_LINE(96)
		Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,p_id1)
		Void run(::haxor::graphics::material::Shader d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Asset.hx",96,0xf4b04511)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(96)
				::haxor::core::Asset_obj::UpdateProgress(p_id1->__get((int)0),p,d);
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(96)
		::haxor::net::Web_obj::LoadShader(p_url, Dynamic(new _Function_1_1(p_id1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,LoadShader,(void))

Void Asset_obj::LoadMaterial( ::String p_id,::String p_url){
{
		HX_STACK_FRAME("haxor.core.Asset","LoadMaterial",0xd52d75ee,"haxor.core.Asset.LoadMaterial","haxor/core/Asset.hx",103,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_LINE(103)
		Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,p_id1)
		Void run(::haxor::io::file::MaterialFile d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Asset.hx",103,0xf4b04511)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(103)
				::haxor::core::Asset_obj::UpdateProgress(p_id1->__get((int)0),p,d);
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(103)
		::haxor::net::Web_obj::LoadMaterial(p_url, Dynamic(new _Function_1_1(p_id1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Asset_obj,LoadMaterial,(void))

Dynamic Asset_obj::Instantiate( ::haxor::core::Resource p_target){
	HX_STACK_FRAME("haxor.core.Asset","Instantiate",0x9680f0c9,"haxor.core.Asset.Instantiate","haxor/core/Asset.hx",110,0xf4b04511)
	HX_STACK_ARG(p_target,"p_target")
	HX_STACK_LINE(110)
	return p_target->Clone();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Asset_obj,Instantiate,return )

Void Asset_obj::UpdateProgress( ::String p_id,Float p_progress,Dynamic p_asset){
{
		HX_STACK_FRAME("haxor.core.Asset","UpdateProgress",0x4e5a1a17,"haxor.core.Asset.UpdateProgress","haxor/core/Asset.hx",119,0xf4b04511)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_progress,"p_progress")
		HX_STACK_ARG(p_asset,"p_asset")
		HX_STACK_LINE(120)
		::haxor::core::BaseApplication app = ::haxor::core::BaseApplication_obj::m_instance;		HX_STACK_VAR(app,"app");
		HX_STACK_LINE(122)
		::haxor::core::Asset_obj::m_load_progress->set(p_id,p_progress);
		HX_STACK_LINE(124)
		app->OnLoadProgress(p_id,p_progress);
		HX_STACK_LINE(125)
		if (((p_progress >= 1.0))){
			HX_STACK_LINE(127)
			::haxor::core::Asset_obj::Add(p_id,p_asset);
			HX_STACK_LINE(128)
			app->OnLoadComplete(p_id,p_asset);
			HX_STACK_LINE(129)
			Float _g = ::haxor::core::Asset_obj::get_progress();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(129)
			if (((_g >= 1.0))){
				HX_STACK_LINE(131)
				Dynamic kl = ::haxor::core::Asset_obj::m_database->keys();		HX_STACK_VAR(kl,"kl");
				HX_STACK_LINE(132)
				while((true)){
					HX_STACK_LINE(132)
					if ((!(kl->__Field(HX_CSTRING("hasNext"),true)()))){
						HX_STACK_LINE(132)
						break;
					}
					HX_STACK_LINE(134)
					::String aik = kl->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(aik,"aik");
					HX_STACK_LINE(135)
					::haxor::io::file::MaterialFile mf = ::haxor::core::Asset_obj::m_database->get(aik);		HX_STACK_VAR(mf,"mf");
					HX_STACK_LINE(136)
					if ((::Std_obj::is(mf,hx::ClassOf< ::haxor::io::file::MaterialFile >()))){
						HX_STACK_LINE(136)
						Dynamic _g1 = mf->get_asset();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(136)
						::haxor::core::Asset_obj::Add(aik,_g1);
					}
				}
				HX_STACK_LINE(138)
				::haxor::core::BaseApplication_obj::m_instance->LoadComplete();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Asset_obj,UpdateProgress,(void))


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
	case 8:
		if (HX_FIELD_EQ(inName,"progress") ) { return get_progress(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_database") ) { return m_database; }
		if (HX_FIELD_EQ(inName,"LoadShader") ) { return LoadShader_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"LoadCollada") ) { return LoadCollada_dyn(); }
		if (HX_FIELD_EQ(inName,"Instantiate") ) { return Instantiate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_progress") ) { return get_progress_dyn(); }
		if (HX_FIELD_EQ(inName,"LoadMaterial") ) { return LoadMaterial_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LoadTexture2D") ) { return LoadTexture2D_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UpdateProgress") ) { return UpdateProgress_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_load_progress") ) { return m_load_progress; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Asset_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"m_database") ) { m_database=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_load_progress") ) { m_load_progress=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Asset_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_database"),
	HX_CSTRING("m_load_progress"),
	HX_CSTRING("get_progress"),
	HX_CSTRING("Get"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Add"),
	HX_CSTRING("LoadTexture2D"),
	HX_CSTRING("LoadCollada"),
	HX_CSTRING("LoadShader"),
	HX_CSTRING("LoadMaterial"),
	HX_CSTRING("Instantiate"),
	HX_CSTRING("UpdateProgress"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Asset_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Asset_obj::m_database,"m_database");
	HX_MARK_MEMBER_NAME(Asset_obj::m_load_progress,"m_load_progress");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Asset_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Asset_obj::m_database,"m_database");
	HX_VISIT_MEMBER_NAME(Asset_obj::m_load_progress,"m_load_progress");
};

#endif

Class Asset_obj::__mClass;

void Asset_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Asset"), hx::TCanCast< Asset_obj> ,sStaticFields,sMemberFields,
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
	m_load_progress= ::haxe::ds::StringMap_obj::__new();
}

} // end namespace haxor
} // end namespace core
