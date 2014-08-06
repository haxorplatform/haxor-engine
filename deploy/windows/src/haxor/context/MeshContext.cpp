#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
namespace haxor{
namespace context{

Void MeshContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.MeshContext","new",0x9085c6a9,"haxor.context.MeshContext.new","haxor/context/MeshContext.hx",26,0xf23de969)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(27)
	this->aid = (int)0;
	HX_STACK_LINE(28)
	this->buffers = Array_obj< int >::__new();
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		while((true)){
			HX_STACK_LINE(29)
			if ((!(((_g < (int)1000))))){
				HX_STACK_LINE(29)
				break;
			}
			HX_STACK_LINE(29)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(29)
			this->buffers->push(::haxor::platform::graphics::GL_obj::NULL_ID);
		}
	}
}
;
	return null();
}

//MeshContext_obj::~MeshContext_obj() { }

Dynamic MeshContext_obj::__CreateEmpty() { return  new MeshContext_obj; }
hx::ObjectPtr< MeshContext_obj > MeshContext_obj::__new()
{  hx::ObjectPtr< MeshContext_obj > result = new MeshContext_obj();
	result->__construct();
	return result;}

Dynamic MeshContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshContext_obj > result = new MeshContext_obj();
	result->__construct();
	return result;}


MeshContext_obj::MeshContext_obj()
{
}

void MeshContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshContext);
	HX_MARK_MEMBER_NAME(aid,"aid");
	HX_MARK_MEMBER_NAME(buffers,"buffers");
	HX_MARK_END_CLASS();
}

void MeshContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(aid,"aid");
	HX_VISIT_MEMBER_NAME(buffers,"buffers");
}

Dynamic MeshContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"aid") ) { return aid; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"buffers") ) { return buffers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"aid") ) { aid=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"buffers") ) { buffers=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("aid"));
	outFields->push(HX_CSTRING("buffers"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MeshContext_obj,aid),HX_CSTRING("aid")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MeshContext_obj,buffers),HX_CSTRING("buffers")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("aid"),
	HX_CSTRING("buffers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshContext_obj::__mClass,"__mClass");
};

#endif

Class MeshContext_obj::__mClass;

void MeshContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.MeshContext"), hx::TCanCast< MeshContext_obj> ,sStaticFields,sMemberFields,
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

void MeshContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
