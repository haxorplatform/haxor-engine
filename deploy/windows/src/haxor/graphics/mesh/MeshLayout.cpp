#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
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
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void MeshLayout_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","new",0x2a1bb8f3,"haxor.graphics.mesh.MeshLayout.new","haxor/graphics/mesh/MeshLayout.hx",80,0x92e5291c)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(81)
	super::__construct(p_name);
	HX_STACK_LINE(82)
	this->m_vertex = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(83)
	this->m_normal = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(84)
	this->m_color = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(85)
	this->m_uv0 = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(86)
	this->m_uv1 = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(87)
	this->m_tangent = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(88)
	this->m_binormal = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

//MeshLayout_obj::~MeshLayout_obj() { }

Dynamic MeshLayout_obj::__CreateEmpty() { return  new MeshLayout_obj; }
hx::ObjectPtr< MeshLayout_obj > MeshLayout_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< MeshLayout_obj > result = new MeshLayout_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic MeshLayout_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshLayout_obj > result = new MeshLayout_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic MeshLayout_obj::get_vertex( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_vertex",0xce4beafa,"haxor.graphics.mesh.MeshLayout.get_vertex","haxor/graphics/mesh/MeshLayout.hx",26,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(26)
	return this->m_vertex;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_vertex,return )

Dynamic MeshLayout_obj::set_vertex( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_vertex",0xd1c9896e,"haxor.graphics.mesh.MeshLayout.set_vertex","haxor/graphics/mesh/MeshLayout.hx",27,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(27)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("vertex"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	return this->m_vertex = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_vertex,return )

Dynamic MeshLayout_obj::get_normal( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_normal",0x5d6d81bd,"haxor.graphics.mesh.MeshLayout.get_normal","haxor/graphics/mesh/MeshLayout.hx",34,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	return this->m_normal;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_normal,return )

Dynamic MeshLayout_obj::set_normal( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_normal",0x60eb2031,"haxor.graphics.mesh.MeshLayout.set_normal","haxor/graphics/mesh/MeshLayout.hx",35,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(35)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("normal"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(35)
	return this->m_normal = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_normal,return )

Array< ::Dynamic > MeshLayout_obj::get_color( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_color",0x1b7ee68d,"haxor.graphics.mesh.MeshLayout.get_color","haxor/graphics/mesh/MeshLayout.hx",43,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	return this->m_color;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_color,return )

Array< ::Dynamic > MeshLayout_obj::set_color( Array< ::Dynamic > v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_color",0xfecfd299,"haxor.graphics.mesh.MeshLayout.set_color","haxor/graphics/mesh/MeshLayout.hx",44,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(44)
	Array< ::Dynamic > _g = this->UpdateAttribute(HX_CSTRING("color"),v,true);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	return this->m_color = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_color,return )

Dynamic MeshLayout_obj::get_uv0( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_uv0",0xda912559,"haxor.graphics.mesh.MeshLayout.get_uv0","haxor/graphics/mesh/MeshLayout.hx",51,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return this->m_uv0;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_uv0,return )

Dynamic MeshLayout_obj::set_uv0( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_uv0",0xcd92b665,"haxor.graphics.mesh.MeshLayout.set_uv0","haxor/graphics/mesh/MeshLayout.hx",52,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(52)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("uv0"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(52)
	return this->m_uv0 = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_uv0,return )

Dynamic MeshLayout_obj::get_uv1( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_uv1",0xda91255a,"haxor.graphics.mesh.MeshLayout.get_uv1","haxor/graphics/mesh/MeshLayout.hx",59,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(59)
	return this->m_uv1;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_uv1,return )

Dynamic MeshLayout_obj::set_uv1( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_uv1",0xcd92b666,"haxor.graphics.mesh.MeshLayout.set_uv1","haxor/graphics/mesh/MeshLayout.hx",60,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(60)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("uv1"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(60)
	return this->m_uv1 = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_uv1,return )

Dynamic MeshLayout_obj::get_tangent( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_tangent",0x7157306f,"haxor.graphics.mesh.MeshLayout.get_tangent","haxor/graphics/mesh/MeshLayout.hx",67,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(67)
	return this->m_tangent;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_tangent,return )

Dynamic MeshLayout_obj::set_tangent( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_tangent",0x7bc4377b,"haxor.graphics.mesh.MeshLayout.set_tangent","haxor/graphics/mesh/MeshLayout.hx",68,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(68)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("tangent"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(68)
	return this->m_tangent = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_tangent,return )

Dynamic MeshLayout_obj::get_binormal( ){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","get_binormal",0xa5de7844,"haxor.graphics.mesh.MeshLayout.get_binormal","haxor/graphics/mesh/MeshLayout.hx",75,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_LINE(75)
	return this->m_binormal;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,get_binormal,return )

Dynamic MeshLayout_obj::set_binormal( Dynamic v){
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","set_binormal",0xbad79bb8,"haxor.graphics.mesh.MeshLayout.set_binormal","haxor/graphics/mesh/MeshLayout.hx",76,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(76)
	Dynamic _g = this->UpdateAttribute(HX_CSTRING("binormal"),v,false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	return this->m_binormal = _g;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshLayout_obj,set_binormal,return )

Void MeshLayout_obj::GenerateBounds( ){
{
		HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","GenerateBounds",0x0109cdf7,"haxor.graphics.mesh.MeshLayout.GenerateBounds","haxor/graphics/mesh/MeshLayout.hx",96,0x92e5291c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(96)
		this->GenerateAttribBounds(HX_CSTRING("vertex"),this->m_bounds);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MeshLayout_obj,GenerateBounds,(void))

Dynamic MeshLayout_obj::UpdateAttribute( ::String p_name,Dynamic p_list,hx::Null< bool >  __o_p_is_color){
bool p_is_color = __o_p_is_color.Default(false);
	HX_STACK_FRAME("haxor.graphics.mesh.MeshLayout","UpdateAttribute",0x629341c6,"haxor.graphics.mesh.MeshLayout.UpdateAttribute","haxor/graphics/mesh/MeshLayout.hx",104,0x92e5291c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_list,"p_list")
	HX_STACK_ARG(p_is_color,"p_is_color")
{
		HX_STACK_LINE(105)
		if (((p_list == null()))){
			HX_STACK_LINE(105)
			this->Remove(p_name);
			HX_STACK_LINE(105)
			return Dynamic( Array_obj<Dynamic>::__new());
		}
		HX_STACK_LINE(106)
		if (((p_list->__Field(HX_CSTRING("length"),true) <= (int)0))){
			HX_STACK_LINE(106)
			this->Remove(p_name);
			HX_STACK_LINE(106)
			return Dynamic( Array_obj<Dynamic>::__new());
		}
		HX_STACK_LINE(107)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(108)
		int off = (int)1;		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(109)
		if ((::Std_obj::is(p_list->__GetItem((int)0),hx::ClassOf< ::haxor::math::Vector2 >()))){
			HX_STACK_LINE(109)
			off = (int)2;
		}
		HX_STACK_LINE(110)
		if ((::Std_obj::is(p_list->__GetItem((int)0),hx::ClassOf< ::haxor::math::Vector3 >()))){
			HX_STACK_LINE(110)
			off = (int)3;
		}
		HX_STACK_LINE(111)
		if ((::Std_obj::is(p_list->__GetItem((int)0),hx::ClassOf< ::haxor::math::Vector4 >()))){
			HX_STACK_LINE(111)
			off = (int)4;
		}
		HX_STACK_LINE(112)
		if ((::Std_obj::is(p_list->__GetItem((int)0),hx::ClassOf< ::haxor::math::Color >()))){
			HX_STACK_LINE(112)
			off = (int)4;
		}
		HX_STACK_LINE(113)
		if (((a == null()))){
			HX_STACK_LINE(113)
			::haxor::io::FloatArray _g = ::haxor::io::FloatArray_obj::__new((int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(113)
			::haxor::graphics::mesh::MeshAttrib _g1 = this->Set(p_name,_g,off);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(113)
			a = _g1;
		}
		HX_STACK_LINE(115)
		int p = (int)0;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(116)
		::haxor::io::FloatArray _g2 = ::haxor::io::FloatArray_obj::__new((p_list->__Field(HX_CSTRING("length"),true) * off));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(116)
		::haxor::io::FloatArray f = a->data = _g2;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(118)
		{
			HX_STACK_LINE(118)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(118)
			int _g = p_list->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(118)
			while((true)){
				HX_STACK_LINE(118)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(118)
					break;
				}
				HX_STACK_LINE(118)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(120)
				Dynamic it = p_list->__GetItem(i);		HX_STACK_VAR(it,"it");
				HX_STACK_LINE(121)
				switch( (int)(off)){
					case (int)1: {
						HX_STACK_LINE(123)
						Float v = it;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(123)
						int _g3 = (p)++;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(123)
						f->Set(_g3,v);
					}
					;break;
					case (int)2: {
						HX_STACK_LINE(124)
						::haxor::math::Vector2 v2 = it;		HX_STACK_VAR(v2,"v2");
						HX_STACK_LINE(124)
						int _g4 = (p)++;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(124)
						f->Set(_g4,v2->x);
						HX_STACK_LINE(124)
						int _g5 = (p)++;		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(124)
						f->Set(_g5,v2->y);
					}
					;break;
					case (int)3: {
						HX_STACK_LINE(125)
						::haxor::math::Vector3 v3 = it;		HX_STACK_VAR(v3,"v3");
						HX_STACK_LINE(125)
						int _g6 = (p)++;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(125)
						f->Set(_g6,v3->x);
						HX_STACK_LINE(125)
						int _g7 = (p)++;		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(125)
						f->Set(_g7,v3->y);
						HX_STACK_LINE(125)
						int _g8 = (p)++;		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(125)
						f->Set(_g8,v3->z);
					}
					;break;
					case (int)4: {
						HX_STACK_LINE(127)
						if ((p_is_color)){
							HX_STACK_LINE(128)
							::haxor::math::Color c = it;		HX_STACK_VAR(c,"c");
							HX_STACK_LINE(128)
							int _g9 = (p)++;		HX_STACK_VAR(_g9,"_g9");
							HX_STACK_LINE(128)
							f->Set(_g9,c->r);
							HX_STACK_LINE(128)
							int _g10 = (p)++;		HX_STACK_VAR(_g10,"_g10");
							HX_STACK_LINE(128)
							f->Set(_g10,c->g);
							HX_STACK_LINE(128)
							int _g11 = (p)++;		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(128)
							f->Set(_g11,c->b);
							HX_STACK_LINE(128)
							int _g12 = (p)++;		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(128)
							f->Set(_g12,c->a);
						}
						else{
							HX_STACK_LINE(130)
							::haxor::math::Vector4 v4 = it;		HX_STACK_VAR(v4,"v4");
							HX_STACK_LINE(130)
							int _g13 = (p)++;		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(130)
							f->Set(_g13,v4->x);
							HX_STACK_LINE(130)
							int _g14 = (p)++;		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(130)
							f->Set(_g14,v4->y);
							HX_STACK_LINE(130)
							int _g15 = (p)++;		HX_STACK_VAR(_g15,"_g15");
							HX_STACK_LINE(130)
							f->Set(_g15,v4->z);
							HX_STACK_LINE(130)
							int _g16 = (p)++;		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(130)
							f->Set(_g16,v4->w);
						}
					}
					;break;
				}
			}
		}
		HX_STACK_LINE(134)
		this->Set(p_name,f,off);
		HX_STACK_LINE(136)
		return p_list;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(MeshLayout_obj,UpdateAttribute,return )


MeshLayout_obj::MeshLayout_obj()
{
}

void MeshLayout_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshLayout);
	HX_MARK_MEMBER_NAME(m_vertex,"m_vertex");
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_color,"m_color");
	HX_MARK_MEMBER_NAME(m_uv0,"m_uv0");
	HX_MARK_MEMBER_NAME(m_uv1,"m_uv1");
	HX_MARK_MEMBER_NAME(m_tangent,"m_tangent");
	HX_MARK_MEMBER_NAME(m_binormal,"m_binormal");
	::haxor::graphics::mesh::Mesh_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MeshLayout_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_vertex,"m_vertex");
	HX_VISIT_MEMBER_NAME(m_normal,"m_normal");
	HX_VISIT_MEMBER_NAME(m_color,"m_color");
	HX_VISIT_MEMBER_NAME(m_uv0,"m_uv0");
	HX_VISIT_MEMBER_NAME(m_uv1,"m_uv1");
	HX_VISIT_MEMBER_NAME(m_tangent,"m_tangent");
	HX_VISIT_MEMBER_NAME(m_binormal,"m_binormal");
	::haxor::graphics::mesh::Mesh_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MeshLayout_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uv0") ) { return get_uv0(); }
		if (HX_FIELD_EQ(inName,"uv1") ) { return get_uv1(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return get_color(); }
		if (HX_FIELD_EQ(inName,"m_uv0") ) { return m_uv0; }
		if (HX_FIELD_EQ(inName,"m_uv1") ) { return m_uv1; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"vertex") ) { return get_vertex(); }
		if (HX_FIELD_EQ(inName,"normal") ) { return get_normal(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_color") ) { return m_color; }
		if (HX_FIELD_EQ(inName,"get_uv0") ) { return get_uv0_dyn(); }
		if (HX_FIELD_EQ(inName,"set_uv0") ) { return set_uv0_dyn(); }
		if (HX_FIELD_EQ(inName,"get_uv1") ) { return get_uv1_dyn(); }
		if (HX_FIELD_EQ(inName,"set_uv1") ) { return set_uv1_dyn(); }
		if (HX_FIELD_EQ(inName,"tangent") ) { return get_tangent(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_vertex") ) { return m_vertex; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		if (HX_FIELD_EQ(inName,"binormal") ) { return get_binormal(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"m_tangent") ) { return m_tangent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_vertex") ) { return get_vertex_dyn(); }
		if (HX_FIELD_EQ(inName,"set_vertex") ) { return set_vertex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_normal") ) { return get_normal_dyn(); }
		if (HX_FIELD_EQ(inName,"set_normal") ) { return set_normal_dyn(); }
		if (HX_FIELD_EQ(inName,"m_binormal") ) { return m_binormal; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_tangent") ) { return get_tangent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_tangent") ) { return set_tangent_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_binormal") ) { return get_binormal_dyn(); }
		if (HX_FIELD_EQ(inName,"set_binormal") ) { return set_binormal_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GenerateBounds") ) { return GenerateBounds_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"UpdateAttribute") ) { return UpdateAttribute_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshLayout_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uv0") ) { return set_uv0(inValue); }
		if (HX_FIELD_EQ(inName,"uv1") ) { return set_uv1(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return set_color(inValue); }
		if (HX_FIELD_EQ(inName,"m_uv0") ) { m_uv0=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_uv1") ) { m_uv1=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"vertex") ) { return set_vertex(inValue); }
		if (HX_FIELD_EQ(inName,"normal") ) { return set_normal(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_color") ) { m_color=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tangent") ) { return set_tangent(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_vertex") ) { m_vertex=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"binormal") ) { return set_binormal(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_tangent") ) { m_tangent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_binormal") ) { m_binormal=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshLayout_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("vertex"));
	outFields->push(HX_CSTRING("m_vertex"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("m_color"));
	outFields->push(HX_CSTRING("uv0"));
	outFields->push(HX_CSTRING("m_uv0"));
	outFields->push(HX_CSTRING("uv1"));
	outFields->push(HX_CSTRING("m_uv1"));
	outFields->push(HX_CSTRING("tangent"));
	outFields->push(HX_CSTRING("m_tangent"));
	outFields->push(HX_CSTRING("binormal"));
	outFields->push(HX_CSTRING("m_binormal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_vertex),HX_CSTRING("m_vertex")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_normal),HX_CSTRING("m_normal")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MeshLayout_obj,m_color),HX_CSTRING("m_color")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_uv0),HX_CSTRING("m_uv0")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_uv1),HX_CSTRING("m_uv1")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_tangent),HX_CSTRING("m_tangent")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(MeshLayout_obj,m_binormal),HX_CSTRING("m_binormal")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_vertex"),
	HX_CSTRING("set_vertex"),
	HX_CSTRING("m_vertex"),
	HX_CSTRING("get_normal"),
	HX_CSTRING("set_normal"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_color"),
	HX_CSTRING("m_color"),
	HX_CSTRING("get_uv0"),
	HX_CSTRING("set_uv0"),
	HX_CSTRING("m_uv0"),
	HX_CSTRING("get_uv1"),
	HX_CSTRING("set_uv1"),
	HX_CSTRING("m_uv1"),
	HX_CSTRING("get_tangent"),
	HX_CSTRING("set_tangent"),
	HX_CSTRING("m_tangent"),
	HX_CSTRING("get_binormal"),
	HX_CSTRING("set_binormal"),
	HX_CSTRING("m_binormal"),
	HX_CSTRING("GenerateBounds"),
	HX_CSTRING("UpdateAttribute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshLayout_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshLayout_obj::__mClass,"__mClass");
};

#endif

Class MeshLayout_obj::__mClass;

void MeshLayout_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.MeshLayout"), hx::TCanCast< MeshLayout_obj> ,sStaticFields,sMemberFields,
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

void MeshLayout_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
