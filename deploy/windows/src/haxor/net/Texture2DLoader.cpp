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
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_net_HTTPRequestTask
#include <haxor/net/HTTPRequestTask.h>
#endif
#ifndef INCLUDED_haxor_net_Texture2DLoader
#include <haxor/net/Texture2DLoader.h>
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

Void Texture2DLoader_obj::__construct(::String p_url,bool p_apply,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.net.Texture2DLoader","new",0xbec50975,"haxor.net.Texture2DLoader.new","haxor/net/Texture2DLoader.hx",44,0x3127789d)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_apply,"p_apply")
HX_STACK_ARG(p_callback,"p_callback")
{
	HX_STACK_LINE(45)
	super::__construct(p_url,this->OnBitmapCallback_dyn());
	HX_STACK_LINE(46)
	this->m_t2d_callback = p_callback;
	HX_STACK_LINE(47)
	this->m_apply = p_apply;
}
;
	return null();
}

//Texture2DLoader_obj::~Texture2DLoader_obj() { }

Dynamic Texture2DLoader_obj::__CreateEmpty() { return  new Texture2DLoader_obj; }
hx::ObjectPtr< Texture2DLoader_obj > Texture2DLoader_obj::__new(::String p_url,bool p_apply,Dynamic p_callback)
{  hx::ObjectPtr< Texture2DLoader_obj > result = new Texture2DLoader_obj();
	result->__construct(p_url,p_apply,p_callback);
	return result;}

Dynamic Texture2DLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Texture2DLoader_obj > result = new Texture2DLoader_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Texture2DLoader_obj::OnBitmapCallback( ::haxor::graphics::texture::Bitmap p_data,Float p_progress){
{
		HX_STACK_FRAME("haxor.net.Texture2DLoader","OnBitmapCallback",0x4f54543e,"haxor.net.Texture2DLoader.OnBitmapCallback","haxor/net/Texture2DLoader.hx",55,0x3127789d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_progress,"p_progress")
		HX_STACK_LINE(55)
		Array< ::Dynamic > p_data1 = Array_obj< ::Dynamic >::__new().Add(p_data);		HX_STACK_VAR(p_data1,"p_data1");
		HX_STACK_LINE(55)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		if (((this->m_progress < 1.0))){
			HX_STACK_LINE(59)
			if (((this->m_t2d_callback_dyn() != null()))){
				HX_STACK_LINE(59)
				this->m_t2d_callback(null(),this->m_progress);
			}
		}
		else{
			HX_STACK_LINE(63)
			if (((p_data1->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >() == null()))){
				HX_STACK_LINE(63)
				return null();
			}

			HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,p_data1,Array< ::Dynamic >,_g)
			Void run(){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/net/Texture2DLoader.hx",66,0x3127789d)
				{
					HX_STACK_LINE(67)
					::haxor::graphics::texture::Texture2D t = ::haxor::graphics::texture::Texture2D_obj::FromBitmap(p_data1->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >(),_g->__get((int)0).StaticCast< ::haxor::net::Texture2DLoader >()->m_apply);		HX_STACK_VAR(t,"t");
					HX_STACK_LINE(68)
					_g->__get((int)0).StaticCast< ::haxor::net::Texture2DLoader >()->m_t2d_callback(t,1.0);
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(65)
			::haxor::thread::Activity_obj::RunOnce( Dynamic(new _Function_2_1(p_data1,_g)),false,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Texture2DLoader_obj,OnBitmapCallback,(void))

Void Texture2DLoader_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.net.Texture2DLoader","OnError",0x1024799e,"haxor.net.Texture2DLoader.OnError","haxor/net/Texture2DLoader.hx",74,0x3127789d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(74)
		this->super::OnError();
		HX_STACK_LINE(74)
		if (((this->m_t2d_callback_dyn() != null()))){
			HX_STACK_LINE(74)
			this->m_bitmap_callback(null(),1.0);
		}
	}
return null();
}



Texture2DLoader_obj::Texture2DLoader_obj()
{
}

void Texture2DLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Texture2DLoader);
	HX_MARK_MEMBER_NAME(m_t2d_callback,"m_t2d_callback");
	HX_MARK_MEMBER_NAME(m_apply,"m_apply");
	::haxor::platform::windows::net::BitmapLoader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Texture2DLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_t2d_callback,"m_t2d_callback");
	HX_VISIT_MEMBER_NAME(m_apply,"m_apply");
	::haxor::platform::windows::net::BitmapLoader_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Texture2DLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_apply") ) { return m_apply; }
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_t2d_callback") ) { return m_t2d_callback; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnBitmapCallback") ) { return OnBitmapCallback_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Texture2DLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_apply") ) { m_apply=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_t2d_callback") ) { m_t2d_callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Texture2DLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_apply"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Texture2DLoader_obj,m_t2d_callback),HX_CSTRING("m_t2d_callback")},
	{hx::fsBool,(int)offsetof(Texture2DLoader_obj,m_apply),HX_CSTRING("m_apply")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_t2d_callback"),
	HX_CSTRING("m_apply"),
	HX_CSTRING("OnBitmapCallback"),
	HX_CSTRING("OnError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Texture2DLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Texture2DLoader_obj::__mClass,"__mClass");
};

#endif

Class Texture2DLoader_obj::__mClass;

void Texture2DLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.net.Texture2DLoader"), hx::TCanCast< Texture2DLoader_obj> ,sStaticFields,sMemberFields,
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

void Texture2DLoader_obj::__boot()
{
}

} // end namespace haxor
} // end namespace net
