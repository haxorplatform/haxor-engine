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
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void MeshAttrib_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.mesh.MeshAttrib","new",0xc418c193,"haxor.graphics.mesh.MeshAttrib.new","haxor/graphics/mesh/Mesh.hx",308,0xbfac53a6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(309)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(309)
	{
		HX_STACK_LINE(309)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::mesh->aid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(309)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(309)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(309)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(309)
	this->__cid = _g;
	HX_STACK_LINE(310)
	this->_loc_ = (int)-1;
	HX_STACK_LINE(311)
	this->m_name = HX_CSTRING("");
	HX_STACK_LINE(312)
	this->data = null();
	HX_STACK_LINE(313)
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

::String MeshAttrib_obj::get_name( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshAttrib","get_name",0x449f03c1,"haxor.graphics.mesh.MeshAttrib.get_name","haxor/graphics/mesh/Mesh.hx",288,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(288)
	return this->m_name;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshAttrib_obj,get_name,return )

int MeshAttrib_obj::get_count( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshAttrib","get_count",0x7a62fa99,"haxor.graphics.mesh.MeshAttrib.get_count","haxor/graphics/mesh/Mesh.hx",305,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(305)
	if (((this->data == null()))){
		HX_STACK_LINE(305)
		return (int)0;
	}
	else{
		HX_STACK_LINE(305)
		return ::Std_obj::_int((Float(this->data->m_length) / Float(this->offset)));
	}
	HX_STACK_LINE(305)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshAttrib_obj,get_count,return )


MeshAttrib_obj::MeshAttrib_obj()
{
}

void MeshAttrib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshAttrib);
	HX_MARK_MEMBER_NAME(__cid,"__cid");
	HX_MARK_MEMBER_NAME(_loc_,"_loc_");
	HX_MARK_MEMBER_NAME(m_name,"m_name");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_END_CLASS();
}

void MeshAttrib_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__cid,"__cid");
	HX_VISIT_MEMBER_NAME(_loc_,"_loc_");
	HX_VISIT_MEMBER_NAME(m_name,"m_name");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(offset,"offset");
}

Dynamic MeshAttrib_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"__cid") ) { return __cid; }
		if (HX_FIELD_EQ(inName,"_loc_") ) { return _loc_; }
		if (HX_FIELD_EQ(inName,"count") ) { return get_count(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_name") ) { return m_name; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_count") ) { return get_count_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshAttrib_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::io::Buffer >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"__cid") ) { __cid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_loc_") ) { _loc_=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_name") ) { m_name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshAttrib_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__cid"));
	outFields->push(HX_CSTRING("_loc_"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("m_name"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("count"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MeshAttrib_obj,__cid),HX_CSTRING("__cid")},
	{hx::fsInt,(int)offsetof(MeshAttrib_obj,_loc_),HX_CSTRING("_loc_")},
	{hx::fsString,(int)offsetof(MeshAttrib_obj,m_name),HX_CSTRING("m_name")},
	{hx::fsObject /*::haxor::io::Buffer*/ ,(int)offsetof(MeshAttrib_obj,data),HX_CSTRING("data")},
	{hx::fsInt,(int)offsetof(MeshAttrib_obj,offset),HX_CSTRING("offset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__cid"),
	HX_CSTRING("_loc_"),
	HX_CSTRING("get_name"),
	HX_CSTRING("m_name"),
	HX_CSTRING("data"),
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
