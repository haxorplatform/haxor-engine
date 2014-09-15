#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
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
#ifndef INCLUDED_haxor_net_HTTPRequestTask
#include <haxor/net/HTTPRequestTask.h>
#endif
#ifndef INCLUDED_haxor_net_Texture2DLoader
#include <haxor/net/Texture2DLoader.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_BitmapLoader
#include <haxor/platform/windows/net/BitmapLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPLoader
#include <haxor/platform/windows/net/HTTPLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPRequest
#include <haxor/platform/windows/net/HTTPRequest.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
namespace haxor{
namespace net{

Void Web_obj::__construct()
{
	return null();
}

//Web_obj::~Web_obj() { }

Dynamic Web_obj::__CreateEmpty() { return  new Web_obj; }
hx::ObjectPtr< Web_obj > Web_obj::__new()
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

Dynamic Web_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

::String Web_obj::root;

Void Web_obj::Load( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","Load",0x1fa4e45d,"haxor.net.Web.Load","haxor/net/Web.hx",40,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(40)
		::haxor::platform::windows::net::HTTPLoader ld = ::haxor::platform::windows::net::HTTPLoader_obj::__new(p_url,false,p_callback);		HX_STACK_VAR(ld,"ld");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,Load,(void))

Void Web_obj::LoadImg( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","LoadImg",0x313237a6,"haxor.net.Web.LoadImg","haxor/net/Web.hx",47,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(47)
		::haxor::platform::windows::net::BitmapLoader ld = ::haxor::platform::windows::net::BitmapLoader_obj::__new(p_url,p_callback);		HX_STACK_VAR(ld,"ld");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,LoadImg,(void))

Void Web_obj::LoadTexture2D( ::String p_url,bool p_apply,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","LoadTexture2D",0x4ac82950,"haxor.net.Web.LoadTexture2D","haxor/net/Web.hx",54,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_apply,"p_apply")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(54)
		::haxor::net::Texture2DLoader ld = ::haxor::net::Texture2DLoader_obj::__new(p_url,p_apply,p_callback);		HX_STACK_VAR(ld,"ld");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Web_obj,LoadTexture2D,(void))

Void Web_obj::LoadCollada( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","LoadCollada",0x4c81d695,"haxor.net.Web.LoadCollada","haxor/net/Web.hx",61,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(61)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");
		HX_STACK_LINE(61)
		Array< ::String > p_url1 = Array_obj< ::String >::__new().Add(p_url);		HX_STACK_VAR(p_url1,"p_url1");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::String >,p_url1,Dynamic,p_callback1)
		Void run(::String d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/net/Web.hx",61,0x66abd769)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(61)
				if (((p < 1.0))){
					HX_STACK_LINE(61)
					p_callback1->__GetItem((int)0)(null(),p).Cast< Void >();
				}
				else{
					HX_STACK_LINE(61)
					p_callback1->__GetItem((int)0)((  (((d == null()))) ? ::haxor::io::file::ColladaFile(null()) : ::haxor::io::file::ColladaFile(::haxor::io::file::ColladaFile_obj::__new(p_url1->__get((int)0),d)) ),1.0).Cast< Void >();
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(61)
		::haxor::net::Web_obj::Load(p_url1->__get((int)0), Dynamic(new _Function_1_1(p_url1,p_callback1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,LoadCollada,(void))

Void Web_obj::LoadShader( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","LoadShader",0xfd693b62,"haxor.net.Web.LoadShader","haxor/net/Web.hx",68,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(68)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,p_callback1)
		Void run(::String d,Float p){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/net/Web.hx",68,0x66abd769)
			HX_STACK_ARG(d,"d")
			HX_STACK_ARG(p,"p")
			{
				HX_STACK_LINE(68)
				if (((p < 1.0))){
					HX_STACK_LINE(68)
					p_callback1->__GetItem((int)0)(null(),p).Cast< Void >();
				}
				else{
					HX_STACK_LINE(68)
					p_callback1->__GetItem((int)0)((  (((d == null()))) ? ::haxor::graphics::material::Shader(null()) : ::haxor::graphics::material::Shader(::haxor::graphics::material::Shader_obj::__new(d)) ),1.0).Cast< Void >();
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(68)
		::haxor::net::Web_obj::Load(p_url, Dynamic(new _Function_1_1(p_callback1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,LoadShader,(void))


Web_obj::Web_obj()
{
}

Dynamic Web_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { return root; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"LoadImg") ) { return LoadImg_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LoadShader") ) { return LoadShader_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"LoadCollada") ) { return LoadCollada_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LoadTexture2D") ) { return LoadTexture2D_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Web_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { root=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Web_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("root"),
	HX_CSTRING("Load"),
	HX_CSTRING("LoadImg"),
	HX_CSTRING("LoadTexture2D"),
	HX_CSTRING("LoadCollada"),
	HX_CSTRING("LoadShader"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Web_obj::root,"root");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Web_obj::root,"root");
};

#endif

Class Web_obj::__mClass;

void Web_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.net.Web"), hx::TCanCast< Web_obj> ,sStaticFields,sMemberFields,
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

void Web_obj::__boot()
{
	root= HX_CSTRING("");
}

} // end namespace haxor
} // end namespace net
