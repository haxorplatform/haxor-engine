#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_io_BaseArray
#include <haxor/io/BaseArray.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void MeshAttrib_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.mesh.MeshAttrib","new",0xc418c193,"haxor.graphics.mesh.MeshAttrib.new","haxor/graphics/mesh/Mesh.hx",218,0xbfac53a6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(219)
	int _g = (::haxor::context::EngineContext_obj::mesh->aid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(219)
	this->id = _g;
	HX_STACK_LINE(220)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(221)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(222)
	this->data = null();
	HX_STACK_LINE(223)
	this->offset = (int)0;
}
;
	return null();
}

//MeshAttrib_obj::~MeshAttrib_obj() { }

Dynamic MeshAttrib_obj::__CreateEmpty() { return  new MeshAttrib_obj; }
hx::ObjectPtr< MeshAttrib_obj > MeshAttrib_obj::__new()
{  hx::ObjectPtr< MeshAttrib_obj > result = new MeshAttrib_obj();
	result->__construct();
	return result;}

Dynamic MeshAttrib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshAttrib_obj > result = new MeshAttrib_obj();
	result->__construct();
	return result;}

int MeshAttrib_obj::get_count( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshAttrib","get_count",0x7a62fa99,"haxor.graphics.mesh.MeshAttrib.get_count","haxor/graphics/mesh/Mesh.hx",215,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(215)
	if (((this->data == null()))){
		HX_STACK_LINE(215)
		return (int)0;
	}
	else{
		HX_STACK_LINE(215)
		int _g = this->data->get_length();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(215)
		Float _g1 = (Float(_g) / Float(this->offset));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(215)
		return ::Std_obj::_int(_g1);
	}
	HX_STACK_LINE(215)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshAttrib_obj,get_count,return )


MeshAttrib_obj::MeshAttrib_obj()
{
}

void MeshAttrib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshAttrib);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_END_CLASS();
}

void MeshAttrib_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(offset,"offset");
}

Dynamic MeshAttrib_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return get_count(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_count") ) { return get_count_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshAttrib_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::io::BaseArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshAttrib_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("count"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MeshAttrib_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(MeshAttrib_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::haxor::io::BaseArray*/ ,(int)offsetof(MeshAttrib_obj,data),HX_CSTRING("data")},
	{hx::fsString,(int)offsetof(MeshAttrib_obj,type),HX_CSTRING("type")},
	{hx::fsInt,(int)offsetof(MeshAttrib_obj,offset),HX_CSTRING("offset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("data"),
	HX_CSTRING("type"),
	HX_CSTRING("offset"),
	HX_CSTRING("get_count"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshAttrib_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshAttrib_obj::__mClass,"__mClass");
};

#endif

Class MeshAttrib_obj::__mClass;

void MeshAttrib_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.MeshAttrib"), hx::TCanCast< MeshAttrib_obj> ,sStaticFields,sMemberFields,
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

void MeshAttrib_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
