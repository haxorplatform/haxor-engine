#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_io_BaseArray
#include <haxor/io/BaseArray.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
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

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",28,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(28)
	super::__construct();
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

hx::Object *Main_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	if (inType==typeid( ::haxor::core::IRenderable_obj)) return operator ::haxor::core::IRenderable_obj *();
	return super::__ToInterface(inType);
}

bool Main_obj::Load( ){
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",36,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	return true;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",40,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(41)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(43)
		::haxor::core::Console_obj::Log(HX_CSTRING("mesh create"),null());
		HX_STACK_LINE(47)
		::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new();		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(50)
		::haxor::io::FloatArray f32 = ::haxor::io::FloatArray_obj::Create(Array_obj< Float >::__new().Add(0.0).Add(1.1).Add(2.2).Add(3.3));		HX_STACK_VAR(f32,"f32");
		HX_STACK_LINE(51)
		::haxor::io::UInt16Array i16 = ::haxor::io::UInt16Array_obj::Create(Array_obj< int >::__new().Add((int)2).Add((int)3).Add((int)4).Add((int)5));		HX_STACK_VAR(i16,"i16");
		HX_STACK_LINE(53)
		hx::__ArrayImplRef(f32->b,(int)0) = 1.1;
		HX_STACK_LINE(54)
		::haxor::core::Console_obj::Log((f32->b->__get((int)0) + HX_CSTRING("!!!")),null());
		HX_STACK_LINE(56)
		m->Set(HX_CSTRING("factor"),f32,(int)1);
		HX_STACK_LINE(57)
		m->Set(HX_CSTRING("idx"),i16,(int)1);
		HX_STACK_LINE(59)
		::haxor::io::UInt16Array _g = ::haxor::io::UInt16Array_obj::Create(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)2).Add((int)1).Add((int)3));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(59)
		m->set_topology(_g);
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(61)
			int _g2 = m->get_attribs()->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(61)
			while((true)){
				HX_STACK_LINE(61)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(61)
					break;
				}
				HX_STACK_LINE(61)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(63)
				Array< ::String > _g11 = m->get_attribs();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(63)
				::String _g21 = _g11->__get(i);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(63)
				::haxor::graphics::mesh::MeshAttrib a = m->GetAttribute(_g21);		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(64)
				int _g3 = a->data->get_length();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(64)
				::String _g4 = ((((((a->name + HX_CSTRING(" ")) + a->type) + HX_CSTRING(" ")) + a->offset) + HX_CSTRING(" ")) + _g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(64)
				::haxe::Log_obj::trace(_g4,hx::SourceInfo(HX_CSTRING("Main.hx"),64,HX_CSTRING("Main"),HX_CSTRING("Initialize")));
			}
		}
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",72,0x087e5c05)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",81,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(81)
		::haxor::platform::graphics::GL_obj::m_gl->Clear(1.0,0.0,1.0,1.0,1.0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",31,0x087e5c05)
		HX_STACK_LINE(31)
		::haxor::platform::windows::Entry_obj::Initialize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("OnRender"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

