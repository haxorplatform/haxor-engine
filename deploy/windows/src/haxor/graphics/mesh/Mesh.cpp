#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
#ifndef INCLUDED_haxor_io_BaseArray
#include <haxor/io/BaseArray.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void Mesh_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.mesh.Mesh","new",0xe14fd5e9,"haxor.graphics.mesh.Mesh.new","haxor/graphics/mesh/Mesh.hx",76,0xbfac53a6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(77)
	super::__construct(null());
	HX_STACK_LINE(78)
	this->m_attribs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(79)
	this->m_indexed = false;
	HX_STACK_LINE(80)
	this->m_vcount = (int)0;
	HX_STACK_LINE(81)
	::haxor::graphics::mesh::MeshAttrib _g = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(81)
	this->m_topology_attrib = _g;
	HX_STACK_LINE(82)
	this->m_topology_attrib->name = HX_CSTRING("$topology");
	HX_STACK_LINE(83)
	this->m_topology_attrib->offset = (int)1;
	HX_STACK_LINE(84)
	this->m_topology_attrib->type = HX_CSTRING("int");
}
;
	return null();
}

//Mesh_obj::~Mesh_obj() { }

Dynamic Mesh_obj::__CreateEmpty() { return  new Mesh_obj; }
hx::ObjectPtr< Mesh_obj > Mesh_obj::__new()
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct();
	return result;}

Dynamic Mesh_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct();
	return result;}

::haxor::io::UInt16Array Mesh_obj::get_topology( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_topology",0x1ca3d60f,"haxor.graphics.mesh.Mesh.get_topology","haxor/graphics/mesh/Mesh.hx",28,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(29)
	if (((this->m_topology_attrib->data == null()))){
		HX_STACK_LINE(29)
		return ::haxor::io::UInt16Array_obj::__new((int)0);
	}
	HX_STACK_LINE(30)
	return this->m_topology_attrib->data;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_topology,return )

::haxor::io::UInt16Array Mesh_obj::set_topology( ::haxor::io::UInt16Array v){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","set_topology",0x319cf983,"haxor.graphics.mesh.Mesh.set_topology","haxor/graphics/mesh/Mesh.hx",33,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(34)
	if (((v == null()))){
		HX_STACK_LINE(36)
		this->m_topology_attrib->data = null();
		HX_STACK_LINE(37)
		this->m_indexed = false;
	}
	else{
		HX_STACK_LINE(42)
		this->m_topology_attrib->data = v;
		HX_STACK_LINE(43)
		this->m_indexed = true;
	}
	HX_STACK_LINE(46)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_topology,return )

bool Mesh_obj::get_indexed( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_indexed",0x3df3f291,"haxor.graphics.mesh.Mesh.get_indexed","haxor/graphics/mesh/Mesh.hx",55,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_indexed;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_indexed,return )

Array< ::String > Mesh_obj::get_attribs( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_attribs",0x96621089,"haxor.graphics.mesh.Mesh.get_attribs","haxor/graphics/mesh/Mesh.hx",62,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	Array< ::String > l = Array_obj< ::String >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(62)
	{
		HX_STACK_LINE(62)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(62)
		while((true)){
			HX_STACK_LINE(62)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(62)
				break;
			}
			HX_STACK_LINE(62)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(62)
			l->push(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->name);
		}
	}
	HX_STACK_LINE(62)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_attribs,return )

int Mesh_obj::get_vcount( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_vcount",0x77c4f5f9,"haxor.graphics.mesh.Mesh.get_vcount","haxor/graphics/mesh/Mesh.hx",69,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(69)
	return this->m_vcount;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_vcount,return )

Void Mesh_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Clear",0xf7b81b36,"haxor.graphics.mesh.Mesh.Clear","haxor/graphics/mesh/Mesh.hx",91,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(92)
		{
			HX_STACK_LINE(92)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(92)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(92)
			while((true)){
				HX_STACK_LINE(92)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(92)
					break;
				}
				HX_STACK_LINE(92)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
			}
		}
		HX_STACK_LINE(96)
		this->m_attribs = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(97)
		this->m_vcount = (int)0;
		HX_STACK_LINE(98)
		this->set_topology(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,Clear,(void))

bool Mesh_obj::Exists( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Exists",0x8197e813,"haxor.graphics.mesh.Mesh.Exists","haxor/graphics/mesh/Mesh.hx",107,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(108)
	::haxor::graphics::mesh::MeshAttrib _g = this->GetAttribute(p_name);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(108)
	return (_g != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Exists,return )

Dynamic Mesh_obj::Get( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Get",0xe1323dff,"haxor.graphics.mesh.Mesh.Get","haxor/graphics/mesh/Mesh.hx",115,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(116)
	::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(117)
	if (((a == null()))){
		HX_STACK_LINE(117)
		return null();
	}
	else{
		HX_STACK_LINE(117)
		return a->data;
	}
	HX_STACK_LINE(117)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Get,return )

::haxor::graphics::mesh::MeshAttrib Mesh_obj::GetAttribute( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","GetAttribute",0x4e0eda1d,"haxor.graphics.mesh.Mesh.GetAttribute","haxor/graphics/mesh/Mesh.hx",126,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(127)
	{
		HX_STACK_LINE(127)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(127)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(127)
		while((true)){
			HX_STACK_LINE(127)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(127)
				break;
			}
			HX_STACK_LINE(127)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(127)
			if (((this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->name == p_name))){
				HX_STACK_LINE(127)
				return this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >();
			}
		}
	}
	HX_STACK_LINE(128)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,GetAttribute,return )

Void Mesh_obj::Remove( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Remove",0xc640667b,"haxor.graphics.mesh.Mesh.Remove","haxor/graphics/mesh/Mesh.hx",137,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(138)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(139)
		if (((a == null()))){
			HX_STACK_LINE(139)
			return null();
		}
		HX_STACK_LINE(140)
		this->m_attribs->remove(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Remove,(void))

Void Mesh_obj::Set( ::String p_name,::haxor::io::BaseArray p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(3);
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Set",0xe13b590b,"haxor.graphics.mesh.Mesh.Set","haxor/graphics/mesh/Mesh.hx",152,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(153)
		if (((p_data == null()))){
			HX_STACK_LINE(153)
			::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(153)
			::String _g1 = (HX_CSTRING("Mesh> [") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(153)
			::String _g2 = (_g1 + HX_CSTRING("] tried to set null array."));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(153)
			::haxor::core::Console_obj::Log(_g2,(int)1);
			HX_STACK_LINE(153)
			return null();
		}
		HX_STACK_LINE(154)
		int _g3 = p_data->get_length();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(154)
		if (((_g3 <= (int)0))){
			HX_STACK_LINE(154)
			::String _g4 = this->get_name();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(154)
			::String _g5 = (HX_CSTRING("Mesh> [") + _g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(154)
			::String _g6 = (_g5 + HX_CSTRING("] tried to set empty array."));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(154)
			::haxor::core::Console_obj::Log(_g6,(int)1);
			HX_STACK_LINE(154)
			return null();
		}
		HX_STACK_LINE(155)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(156)
		if (((a == null()))){
			HX_STACK_LINE(158)
			::haxor::graphics::mesh::MeshAttrib _g7 = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(158)
			a = _g7;
			HX_STACK_LINE(159)
			a->name = p_name;
			HX_STACK_LINE(160)
			this->m_attribs->push(a);
		}
		HX_STACK_LINE(162)
		a->offset = p_offset;
		HX_STACK_LINE(163)
		a->data = p_data;
		HX_STACK_LINE(164)
		int _g8 = this->m_attribs->__get((int)0).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(164)
		this->m_vcount = _g8;
		HX_STACK_LINE(165)
		{
			HX_STACK_LINE(165)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(165)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(165)
			while((true)){
				HX_STACK_LINE(165)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(165)
					break;
				}
				HX_STACK_LINE(165)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(167)
				int c = this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(168)
				if (((this->m_vcount < c))){
					HX_STACK_LINE(168)
					this->m_vcount = this->m_vcount;
				}
				else{
					HX_STACK_LINE(168)
					this->m_vcount = c;
				}
			}
		}
		HX_STACK_LINE(170)
		int bid = ::haxor::platform::graphics::GL_obj::CreateBuffer();		HX_STACK_VAR(bid,"bid");
		HX_STACK_LINE(171)
		::haxor::core::Console_obj::Log((HX_CSTRING(">>> ") + bid),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Mesh_obj,Set,(void))


Mesh_obj::Mesh_obj()
{
}

void Mesh_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mesh);
	HX_MARK_MEMBER_NAME(m_topology_attrib,"m_topology_attrib");
	HX_MARK_MEMBER_NAME(m_indexed,"m_indexed");
	HX_MARK_MEMBER_NAME(attribs,"attribs");
	HX_MARK_MEMBER_NAME(m_attribs,"m_attribs");
	HX_MARK_MEMBER_NAME(m_vcount,"m_vcount");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Mesh_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_topology_attrib,"m_topology_attrib");
	HX_VISIT_MEMBER_NAME(m_indexed,"m_indexed");
	HX_VISIT_MEMBER_NAME(attribs,"attribs");
	HX_VISIT_MEMBER_NAME(m_attribs,"m_attribs");
	HX_VISIT_MEMBER_NAME(m_vcount,"m_vcount");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Mesh_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"vcount") ) { return get_vcount(); }
		if (HX_FIELD_EQ(inName,"Exists") ) { return Exists_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexed") ) { return get_indexed(); }
		if (HX_FIELD_EQ(inName,"attribs") ) { return inCallProp ? get_attribs() : attribs; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"topology") ) { return get_topology(); }
		if (HX_FIELD_EQ(inName,"m_vcount") ) { return m_vcount; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_indexed") ) { return m_indexed; }
		if (HX_FIELD_EQ(inName,"m_attribs") ) { return m_attribs; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_vcount") ) { return get_vcount_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_indexed") ) { return get_indexed_dyn(); }
		if (HX_FIELD_EQ(inName,"get_attribs") ) { return get_attribs_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_topology") ) { return get_topology_dyn(); }
		if (HX_FIELD_EQ(inName,"set_topology") ) { return set_topology_dyn(); }
		if (HX_FIELD_EQ(inName,"GetAttribute") ) { return GetAttribute_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_topology_attrib") ) { return m_topology_attrib; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mesh_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"attribs") ) { attribs=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"topology") ) { return set_topology(inValue); }
		if (HX_FIELD_EQ(inName,"m_vcount") ) { m_vcount=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_indexed") ) { m_indexed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_attribs") ) { m_attribs=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_topology_attrib") ) { m_topology_attrib=inValue.Cast< ::haxor::graphics::mesh::MeshAttrib >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mesh_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("topology"));
	outFields->push(HX_CSTRING("m_topology_attrib"));
	outFields->push(HX_CSTRING("indexed"));
	outFields->push(HX_CSTRING("m_indexed"));
	outFields->push(HX_CSTRING("attribs"));
	outFields->push(HX_CSTRING("m_attribs"));
	outFields->push(HX_CSTRING("vcount"));
	outFields->push(HX_CSTRING("m_vcount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::MeshAttrib*/ ,(int)offsetof(Mesh_obj,m_topology_attrib),HX_CSTRING("m_topology_attrib")},
	{hx::fsBool,(int)offsetof(Mesh_obj,m_indexed),HX_CSTRING("m_indexed")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(Mesh_obj,attribs),HX_CSTRING("attribs")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Mesh_obj,m_attribs),HX_CSTRING("m_attribs")},
	{hx::fsInt,(int)offsetof(Mesh_obj,m_vcount),HX_CSTRING("m_vcount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_topology"),
	HX_CSTRING("set_topology"),
	HX_CSTRING("m_topology_attrib"),
	HX_CSTRING("get_indexed"),
	HX_CSTRING("m_indexed"),
	HX_CSTRING("attribs"),
	HX_CSTRING("get_attribs"),
	HX_CSTRING("m_attribs"),
	HX_CSTRING("get_vcount"),
	HX_CSTRING("m_vcount"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Exists"),
	HX_CSTRING("Get"),
	HX_CSTRING("GetAttribute"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Set"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mesh_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mesh_obj::__mClass,"__mClass");
};

#endif

Class Mesh_obj::__mClass;

void Mesh_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.Mesh"), hx::TCanCast< Mesh_obj> ,sStaticFields,sMemberFields,
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

void Mesh_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
