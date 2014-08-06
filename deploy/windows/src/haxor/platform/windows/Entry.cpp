#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_Application
#include <haxor/core/Application.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Engine
#include <haxor/core/Engine.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_platform_OSWindow
#include <haxor/platform/OSWindow.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Entry
#include <haxor/platform/windows/Entry.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Window
#include <haxor/platform/windows/Window.h>
#endif
namespace haxor{
namespace platform{
namespace windows{

Void Entry_obj::__construct()
{
	return null();
}

//Entry_obj::~Entry_obj() { }

Dynamic Entry_obj::__CreateEmpty() { return  new Entry_obj; }
hx::ObjectPtr< Entry_obj > Entry_obj::__new()
{  hx::ObjectPtr< Entry_obj > result = new Entry_obj();
	result->__construct();
	return result;}

Dynamic Entry_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Entry_obj > result = new Entry_obj();
	result->__construct();
	return result;}

Void Entry_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Entry","Initialize",0x071ef046,"haxor.platform.windows.Entry.Initialize","haxor/platform/windows/Entry.hx",35,0x9902f0c7)
		HX_STACK_LINE(36)
		::String app_class_type = HX_CSTRING("");		HX_STACK_VAR(app_class_type,"app_class_type");
		HX_STACK_LINE(38)
		::String app_title = HX_CSTRING("Haxor");		HX_STACK_VAR(app_title,"app_title");
		HX_STACK_LINE(40)
		Array< ::String > args = ::Sys_obj::args();		HX_STACK_VAR(args,"args");
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(42)
			int _g = args->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			while((true)){
				HX_STACK_LINE(42)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(42)
					break;
				}
				HX_STACK_LINE(42)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(45)
				int _g2 = args->__get(i).toLowerCase().indexOf(HX_CSTRING("-v"),null());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(45)
				if (((_g2 >= (int)0))){
					HX_STACK_LINE(47)
					int vl = (args->__get(i).length - (int)1);		HX_STACK_VAR(vl,"vl");
					HX_STACK_LINE(48)
					::haxor::core::Console_obj::verbose = vl;
				}
				HX_STACK_LINE(51)
				::String _g11 = args->__get(i).toLowerCase();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(51)
				if (((_g11 == HX_CSTRING("-hx")))){
					HX_STACK_LINE(53)
					int p = (i + (int)1);		HX_STACK_VAR(p,"p");
					HX_STACK_LINE(54)
					if (((p >= args->length))){
						HX_STACK_LINE(54)
						app_class_type = HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(54)
						app_class_type = args->__get(p);
					}
				}
				HX_STACK_LINE(57)
				::String _g21 = args->__get(i).toLowerCase();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(57)
				if (((_g21 == HX_CSTRING("-t")))){
					HX_STACK_LINE(59)
					int p = (i + (int)1);		HX_STACK_VAR(p,"p");
					HX_STACK_LINE(60)
					if (((p >= args->length))){
						HX_STACK_LINE(60)
						app_title = HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(60)
						app_title = args->__get(p);
					}
				}
			}
		}
		HX_STACK_LINE(64)
		if (((app_class_type == HX_CSTRING("")))){
			HX_STACK_LINE(66)
			::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Application type not found. Default to [Main]"),null());
			HX_STACK_LINE(67)
			app_class_type = HX_CSTRING("Main");
		}
		HX_STACK_LINE(70)
		::haxor::core::Console_obj::Log(((((HX_CSTRING("Haxor> Windows Platform Init verbose[") + ::haxor::core::Console_obj::verbose) + HX_CSTRING("] application[")) + app_class_type) + HX_CSTRING("]")),(int)1);
		HX_STACK_LINE(72)
		::Class app_class = ::Type_obj::resolveClass(app_class_type);		HX_STACK_VAR(app_class,"app_class");
		HX_STACK_LINE(74)
		if (((app_class == null()))){
			HX_STACK_LINE(76)
			::haxor::core::Console_obj::Log(((((HX_CSTRING("Haxor> Error. Class [") + app_class_type) + HX_CSTRING("] not found! Try adding 'import ")) + app_class_type) + HX_CSTRING("' in your Main file.")),null());
			HX_STACK_LINE(77)
			::Sys_obj::command(HX_CSTRING("pause"),null());
			HX_STACK_LINE(78)
			return null();
		}
		HX_STACK_LINE(81)
		::haxor::core::Engine_obj::Initialize();
		HX_STACK_LINE(83)
		::haxor::core::Application app;		HX_STACK_VAR(app,"app");
		HX_STACK_LINE(84)
		::haxor::core::Entity e = ::haxor::core::Entity_obj::__new(HX_CSTRING("application"));		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(85)
		Dynamic _g3 = e->AddComponent(app_class);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(85)
		app = _g3;
		HX_STACK_LINE(87)
		if ((!(::Std_obj::is(app,hx::ClassOf< ::haxor::core::BaseApplication >())))){
			HX_STACK_LINE(89)
			::haxor::core::Console_obj::Log(((HX_CSTRING("Haxor> Error. Class [") + app_class_type) + HX_CSTRING("] does not extends Application!")),null());
			HX_STACK_LINE(90)
			return null();
		}
		HX_STACK_LINE(93)
		::haxor::platform::windows::Window wnd = ::haxor::platform::windows::Window_obj::__new(app,app_title,(int)0,(int)0,(int)800,(int)600);		HX_STACK_VAR(wnd,"wnd");
		HX_STACK_LINE(95)
		::haxor::platform::graphics::GL_obj::Initialize(app);
		HX_STACK_LINE(96)
		::haxor::platform::graphics::GL_obj::m_gl->Initialize(wnd);
		HX_STACK_LINE(98)
		if ((app->Load())){
			HX_STACK_LINE(98)
			app->LoadComplete();
		}
		HX_STACK_LINE(100)
		wnd->Run();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Entry_obj,Initialize,(void))


Entry_obj::Entry_obj()
{
}

Dynamic Entry_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Entry_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Entry_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Initialize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Entry_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Entry_obj::__mClass,"__mClass");
};

#endif

Class Entry_obj::__mClass;

void Entry_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.Entry"), hx::TCanCast< Entry_obj> ,sStaticFields,sMemberFields,
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

void Entry_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
