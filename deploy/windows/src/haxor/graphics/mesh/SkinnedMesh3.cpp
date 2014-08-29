#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_SkinnedMesh3
#include <haxor/graphics/mesh/SkinnedMesh3.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void SkinnedMesh3_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","new",0x2fa1d812,"haxor.graphics.mesh.SkinnedMesh3.new","haxor/graphics/mesh/MeshLayout.hx",136,0x92e5291c)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(136)
	super::__construct(p_name);
}
;
	return null();
}

//SkinnedMesh3_obj::~SkinnedMesh3_obj() { }

Dynamic SkinnedMesh3_obj::__CreateEmpty() { return  new SkinnedMesh3_obj; }
hx::ObjectPtr< SkinnedMesh3_obj > SkinnedMesh3_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< SkinnedMesh3_obj > result = new SkinnedMesh3_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic SkinnedMesh3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkinnedMesh3_obj > result = new SkinnedMesh3_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< ::Dynamic > SkinnedMesh3_obj::get_binds( ){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","get_binds",0x94a3459f,"haxor.graphics.mesh.SkinnedMesh3.get_binds","haxor/graphics/mesh/MeshLayout.hx",139,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(139)
	return this->m_binds;
}


HX_DEFINE_DYNAMIC_FUNC0(SkinnedMesh3_obj,get_binds,return )

Array< ::Dynamic > SkinnedMesh3_obj::set_binds( Array< ::Dynamic > v){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","set_binds",0x77f431ab,"haxor.graphics.mesh.SkinnedMesh3.set_binds","haxor/graphics/mesh/MeshLayout.hx",140,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(140)
	Array< ::Dynamic > _g = v->copy();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(140)
	this->m_binds = _g;
	HX_STACK_LINE(140)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(SkinnedMesh3_obj,set_binds,return )

Array< ::Dynamic > SkinnedMesh3_obj::get_bone( ){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","get_bone",0x01d511db,"haxor.graphics.mesh.SkinnedMesh3.get_bone","haxor/graphics/mesh/MeshLayout.hx",144,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return this->m_bone;
}


HX_DEFINE_DYNAMIC_FUNC0(SkinnedMesh3_obj,get_bone,return )

Array< ::Dynamic > SkinnedMesh3_obj::set_bone( Array< ::Dynamic > v){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","set_bone",0xb0326b4f,"haxor.graphics.mesh.SkinnedMesh3.set_bone","haxor/graphics/mesh/MeshLayout.hx",145,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(145)
	Array< ::Dynamic > _g = this->UpdateAttribute(HX_CSTRING("bone"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(145)
	return this->m_bone = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(SkinnedMesh3_obj,set_bone,return )

Array< ::Dynamic > SkinnedMesh3_obj::get_weight( ){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","get_weight",0x8ed213cf,"haxor.graphics.mesh.SkinnedMesh3.get_weight","haxor/graphics/mesh/MeshLayout.hx",149,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(149)
	return this->m_weight;
}


HX_DEFINE_DYNAMIC_FUNC0(SkinnedMesh3_obj,get_weight,return )

Array< ::Dynamic > SkinnedMesh3_obj::set_weight( Array< ::Dynamic > v){
	HX_STACK_FRAME("haxor.graphics.mesh.SkinnedMesh3","set_weight",0x924fb243,"haxor.graphics.mesh.SkinnedMesh3.set_weight","haxor/graphics/mesh/MeshLayout.hx",150,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(150)
	Array< ::Dynamic > _g = this->UpdateAttribute(HX_CSTRING("weight"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(150)
	return this->m_weight = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(SkinnedMesh3_obj,set_weight,return )


SkinnedMesh3_obj::SkinnedMesh3_obj()
{
}

void SkinnedMesh3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkinnedMesh3);
	HX_MARK_MEMBER_NAME(m_binds,"m_binds");
	HX_MARK_MEMBER_NAME(m_bone,"m_bone");
	HX_MARK_MEMBER_NAME(m_weight,"m_weight");
	::haxor::graphics::mesh::MeshLayout_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SkinnedMesh3_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_binds,"m_binds");
	HX_VISIT_MEMBER_NAME(m_bone,"m_bone");
	HX_VISIT_MEMBER_NAME(m_weight,"m_weight");
	::haxor::graphics::mesh::MeshLayout_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SkinnedMesh3_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { return get_bone(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"binds") ) { return get_binds(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bone") ) { return m_bone; }
		if (HX_FIELD_EQ(inName,"weight") ) { return get_weight(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_binds") ) { return m_binds; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_bone") ) { return get_bone_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bone") ) { return set_bone_dyn(); }
		if (HX_FIELD_EQ(inName,"m_weight") ) { return m_weight; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_binds") ) { return get_binds_dyn(); }
		if (HX_FIELD_EQ(inName,"set_binds") ) { return set_binds_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_weight") ) { return get_weight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_weight") ) { return set_weight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkinnedMesh3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { return set_bone(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"binds") ) { return set_binds(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bone") ) { m_bone=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weight") ) { return set_weight(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_binds") ) { m_binds=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_weight") ) { m_weight=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkinnedMesh3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("binds"));
	outFields->push(HX_CSTRING("m_binds"));
	outFields->push(HX_CSTRING("bone"));
	outFields->push(HX_CSTRING("m_bone"));
	outFields->push(HX_CSTRING("weight"));
	outFields->push(HX_CSTRING("m_weight"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkinnedMesh3_obj,m_binds),HX_CSTRING("m_binds")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkinnedMesh3_obj,m_bone),HX_CSTRING("m_bone")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkinnedMesh3_obj,m_weight),HX_CSTRING("m_weight")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_binds"),
	HX_CSTRING("set_binds"),
	HX_CSTRING("m_binds"),
	HX_CSTRING("get_bone"),
	HX_CSTRING("set_bone"),
	HX_CSTRING("m_bone"),
	HX_CSTRING("get_weight"),
	HX_CSTRING("set_weight"),
	HX_CSTRING("m_weight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkinnedMesh3_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkinnedMesh3_obj::__mClass,"__mClass");
};

#endif

Class SkinnedMesh3_obj::__mClass;

void SkinnedMesh3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.SkinnedMesh3"), hx::TCanCast< SkinnedMesh3_obj> ,sStaticFields,sMemberFields,
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

void SkinnedMesh3_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
