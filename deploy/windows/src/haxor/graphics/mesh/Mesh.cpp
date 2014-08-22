#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
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
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void Mesh_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.mesh.Mesh","new",0xe14fd5e9,"haxor.graphics.mesh.Mesh.new","haxor/graphics/mesh/Mesh.hx",96,0xbfac53a6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(97)
	super::__construct(null());
	HX_STACK_LINE(98)
	int _g = (::haxor::context::EngineContext_obj::mesh->mid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(98)
	this->__cid = _g;
	HX_STACK_LINE(99)
	this->m_attribs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(100)
	this->m_indexed = false;
	HX_STACK_LINE(101)
	this->m_vcount = (int)0;
	HX_STACK_LINE(102)
	this->m_mode = (int)35048;
	HX_STACK_LINE(103)
	this->primitive = (int)4;
	HX_STACK_LINE(104)
	::haxor::graphics::mesh::MeshAttrib _g1 = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(104)
	this->m_topology_attrib = _g1;
	HX_STACK_LINE(105)
	this->m_topology_attrib->m_name = HX_CSTRING("$topology");
	HX_STACK_LINE(106)
	this->m_topology_attrib->offset = (int)1;
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
		HX_STACK_LINE(38)
		::haxor::context::EngineContext_obj::mesh->RemoveAttrib(this->m_topology_attrib);
	}
	else{
		HX_STACK_LINE(42)
		this->m_topology_attrib->data = v;
		HX_STACK_LINE(43)
		this->m_indexed = true;
		HX_STACK_LINE(44)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_topology_attrib,this->m_mode,true);
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

int Mesh_obj::get_mode( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_mode",0x6551d8c3,"haxor.graphics.mesh.Mesh.get_mode","haxor/graphics/mesh/Mesh.hx",62,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	return this->m_mode;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_mode,return )

int Mesh_obj::set_mode( int v){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","set_mode",0x13af3237,"haxor.graphics.mesh.Mesh.set_mode","haxor/graphics/mesh/Mesh.hx",64,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(65)
	if (((this->m_mode == v))){
		HX_STACK_LINE(65)
		return v;
	}
	HX_STACK_LINE(66)
	this->m_mode = v;
	HX_STACK_LINE(67)
	if ((this->m_indexed)){
		HX_STACK_LINE(67)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_topology_attrib,this->m_mode,true);
	}
	HX_STACK_LINE(68)
	{
		HX_STACK_LINE(68)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(68)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		while((true)){
			HX_STACK_LINE(68)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(68)
				break;
			}
			HX_STACK_LINE(68)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(68)
			::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >(),this->m_mode,false);
		}
	}
	HX_STACK_LINE(69)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_mode,return )

Array< ::String > Mesh_obj::get_attribs( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_attribs",0x96621089,"haxor.graphics.mesh.Mesh.get_attribs","haxor/graphics/mesh/Mesh.hx",82,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	Array< ::String > l = Array_obj< ::String >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(82)
	{
		HX_STACK_LINE(82)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		while((true)){
			HX_STACK_LINE(82)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(82)
				break;
			}
			HX_STACK_LINE(82)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(82)
			l->push(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name);
		}
	}
	HX_STACK_LINE(82)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_attribs,return )

int Mesh_obj::get_vcount( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_vcount",0x77c4f5f9,"haxor.graphics.mesh.Mesh.get_vcount","haxor/graphics/mesh/Mesh.hx",89,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(89)
	return this->m_vcount;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_vcount,return )

Void Mesh_obj::Clear( hx::Null< bool >  __o_p_from_gpu){
bool p_from_gpu = __o_p_from_gpu.Default(true);
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Clear",0xf7b81b36,"haxor.graphics.mesh.Mesh.Clear","haxor/graphics/mesh/Mesh.hx",117,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_from_gpu,"p_from_gpu")
{
		HX_STACK_LINE(118)
		{
			HX_STACK_LINE(118)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(118)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
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
				this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->data = null();
				HX_STACK_LINE(121)
				this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name = HX_CSTRING("");
				HX_STACK_LINE(122)
				if ((p_from_gpu)){
					HX_STACK_LINE(122)
					::haxor::context::EngineContext_obj::mesh->RemoveAttrib(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >());
				}
			}
		}
		HX_STACK_LINE(125)
		this->m_vcount = (int)0;
		HX_STACK_LINE(126)
		if ((p_from_gpu)){
			HX_STACK_LINE(128)
			this->set_topology(null());
		}
		else{
			HX_STACK_LINE(132)
			this->m_topology_attrib->data = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Clear,(void))

bool Mesh_obj::Exists( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Exists",0x8197e813,"haxor.graphics.mesh.Mesh.Exists","haxor/graphics/mesh/Mesh.hx",142,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(143)
	::haxor::graphics::mesh::MeshAttrib _g = this->GetAttribute(p_name);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(143)
	return (_g != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Exists,return )

Dynamic Mesh_obj::Get( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Get",0xe1323dff,"haxor.graphics.mesh.Mesh.Get","haxor/graphics/mesh/Mesh.hx",150,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(151)
	::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(152)
	if (((a == null()))){
		HX_STACK_LINE(152)
		return null();
	}
	else{
		HX_STACK_LINE(152)
		return a->data;
	}
	HX_STACK_LINE(152)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Get,return )

::haxor::graphics::mesh::MeshAttrib Mesh_obj::GetAttribute( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","GetAttribute",0x4e0eda1d,"haxor.graphics.mesh.Mesh.GetAttribute","haxor/graphics/mesh/Mesh.hx",161,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(162)
	{
		HX_STACK_LINE(162)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(162)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(162)
		while((true)){
			HX_STACK_LINE(162)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(162)
				break;
			}
			HX_STACK_LINE(162)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(162)
			if (((this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name == p_name))){
				HX_STACK_LINE(162)
				return this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >();
			}
		}
	}
	HX_STACK_LINE(163)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,GetAttribute,return )

Void Mesh_obj::Remove( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Remove",0xc640667b,"haxor.graphics.mesh.Mesh.Remove","haxor/graphics/mesh/Mesh.hx",172,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(173)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(174)
		if (((a == null()))){
			HX_STACK_LINE(174)
			return null();
		}
		HX_STACK_LINE(175)
		this->m_attribs->remove(a);
		HX_STACK_LINE(176)
		::haxor::context::EngineContext_obj::mesh->RemoveAttrib(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Remove,(void))

Void Mesh_obj::Set( ::String p_name,::haxor::io::Buffer p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(3);
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Set",0xe13b590b,"haxor.graphics.mesh.Mesh.Set","haxor/graphics/mesh/Mesh.hx",187,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(188)
		if (((p_data == null()))){
			HX_STACK_LINE(188)
			::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(188)
			::String _g1 = (HX_CSTRING("Mesh> [") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(188)
			::String _g2 = (_g1 + HX_CSTRING("] tried to set null array."));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(188)
			::haxor::core::Console_obj::Log(_g2,(int)1);
			HX_STACK_LINE(188)
			return null();
		}
		HX_STACK_LINE(189)
		if (((p_data->m_length <= (int)0))){
			HX_STACK_LINE(189)
			::String _g3 = this->get_name();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(189)
			::String _g4 = (HX_CSTRING("Mesh> [") + _g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(189)
			::String _g5 = (_g4 + HX_CSTRING("] tried to set empty array."));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(189)
			::haxor::core::Console_obj::Log(_g5,(int)1);
			HX_STACK_LINE(189)
			return null();
		}
		HX_STACK_LINE(190)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(191)
		if (((a == null()))){
			HX_STACK_LINE(193)
			::haxor::graphics::mesh::MeshAttrib _g6 = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(193)
			a = _g6;
			HX_STACK_LINE(194)
			a->m_name = p_name;
			HX_STACK_LINE(195)
			this->m_attribs->push(a);
		}
		HX_STACK_LINE(197)
		a->offset = p_offset;
		HX_STACK_LINE(198)
		a->data = p_data;
		HX_STACK_LINE(199)
		int _g7 = this->m_attribs->__get((int)0).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(199)
		this->m_vcount = _g7;
		HX_STACK_LINE(200)
		{
			HX_STACK_LINE(200)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(200)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(200)
			while((true)){
				HX_STACK_LINE(200)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(200)
					break;
				}
				HX_STACK_LINE(200)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(202)
				int c = this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(203)
				if (((this->m_vcount < c))){
					HX_STACK_LINE(203)
					this->m_vcount = this->m_vcount;
				}
				else{
					HX_STACK_LINE(203)
					this->m_vcount = c;
				}
			}
		}
		HX_STACK_LINE(205)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(a,this->m_mode,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Mesh_obj,Set,(void))

Void Mesh_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","OnDestroy",0x904e17c4,"haxor.graphics.mesh.Mesh.OnDestroy","haxor/graphics/mesh/Mesh.hx",213,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(213)
		this->Clear(null());
	}
return null();
}



Mesh_obj::Mesh_obj()
{
}

void Mesh_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mesh);
	HX_MARK_MEMBER_NAME(m_topology_attrib,"m_topology_attrib");
	HX_MARK_MEMBER_NAME(m_indexed,"m_indexed");
	HX_MARK_MEMBER_NAME(m_mode,"m_mode");
	HX_MARK_MEMBER_NAME(primitive,"primitive");
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
	HX_VISIT_MEMBER_NAME(m_mode,"m_mode");
	HX_VISIT_MEMBER_NAME(primitive,"primitive");
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
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return get_mode(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mode") ) { return m_mode; }
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
		if (HX_FIELD_EQ(inName,"get_mode") ) { return get_mode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mode") ) { return set_mode_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vcount") ) { return m_vcount; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_indexed") ) { return m_indexed; }
		if (HX_FIELD_EQ(inName,"primitive") ) { return primitive; }
		if (HX_FIELD_EQ(inName,"m_attribs") ) { return m_attribs; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
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
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return set_mode(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mode") ) { m_mode=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"attribs") ) { attribs=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"topology") ) { return set_topology(inValue); }
		if (HX_FIELD_EQ(inName,"m_vcount") ) { m_vcount=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_indexed") ) { m_indexed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"primitive") ) { primitive=inValue.Cast< int >(); return inValue; }
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
	outFields->push(HX_CSTRING("mode"));
	outFields->push(HX_CSTRING("m_mode"));
	outFields->push(HX_CSTRING("primitive"));
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
	{hx::fsInt,(int)offsetof(Mesh_obj,m_mode),HX_CSTRING("m_mode")},
	{hx::fsInt,(int)offsetof(Mesh_obj,primitive),HX_CSTRING("primitive")},
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
	HX_CSTRING("get_mode"),
	HX_CSTRING("set_mode"),
	HX_CSTRING("m_mode"),
	HX_CSTRING("primitive"),
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
	HX_CSTRING("OnDestroy"),
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
