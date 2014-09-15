#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
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
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void Mesh_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.graphics.mesh.Mesh","new",0xe14fd5e9,"haxor.graphics.mesh.Mesh.new","haxor/graphics/mesh/Mesh.hx",107,0xbfac53a6)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(108)
	super::__construct(p_name);
	HX_STACK_LINE(109)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(109)
	{
		HX_STACK_LINE(109)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::mesh->mid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(109)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(109)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(109)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(109)
	this->__cid = _g;
	HX_STACK_LINE(110)
	this->m_attribs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(111)
	this->m_indexed = false;
	HX_STACK_LINE(112)
	this->m_vcount = (int)0;
	HX_STACK_LINE(113)
	::haxor::math::AABB3 _g1 = ::haxor::math::AABB3_obj::get_empty();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(113)
	this->m_bounds = _g1;
	HX_STACK_LINE(114)
	this->m_mode = (int)35044;
	HX_STACK_LINE(115)
	this->primitive = (int)4;
	HX_STACK_LINE(116)
	::haxor::graphics::mesh::MeshAttrib _g2 = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(116)
	this->m_topology_attrib = _g2;
	HX_STACK_LINE(117)
	this->m_topology_attrib->m_name = HX_CSTRING("$topology");
	HX_STACK_LINE(118)
	this->m_topology_attrib->offset = (int)1;
}
;
	return null();
}

//Mesh_obj::~Mesh_obj() { }

Dynamic Mesh_obj::__CreateEmpty() { return  new Mesh_obj; }
hx::ObjectPtr< Mesh_obj > Mesh_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Mesh_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mesh_obj > result = new Mesh_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::io::UInt16Array Mesh_obj::get_topology( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_topology",0x1ca3d60f,"haxor.graphics.mesh.Mesh.get_topology","haxor/graphics/mesh/Mesh.hx",31,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	if (((this->m_topology_attrib->data == null()))){
		HX_STACK_LINE(32)
		return ::haxor::io::UInt16Array_obj::__new((int)0);
	}
	HX_STACK_LINE(33)
	return this->m_topology_attrib->data;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_topology,return )

::haxor::io::UInt16Array Mesh_obj::set_topology( ::haxor::io::UInt16Array v){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","set_topology",0x319cf983,"haxor.graphics.mesh.Mesh.set_topology","haxor/graphics/mesh/Mesh.hx",36,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(37)
	if (((v == null()))){
		HX_STACK_LINE(39)
		this->m_topology_attrib->data = null();
		HX_STACK_LINE(40)
		this->m_indexed = false;
		HX_STACK_LINE(41)
		::haxor::context::EngineContext_obj::mesh->RemoveAttrib(this->m_topology_attrib);
	}
	else{
		HX_STACK_LINE(45)
		this->m_topology_attrib->data = v;
		HX_STACK_LINE(46)
		this->m_indexed = true;
		HX_STACK_LINE(47)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_topology_attrib,this->m_mode,true);
	}
	HX_STACK_LINE(49)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_topology,return )

bool Mesh_obj::get_indexed( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_indexed",0x3df3f291,"haxor.graphics.mesh.Mesh.get_indexed","haxor/graphics/mesh/Mesh.hx",58,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	return this->m_indexed;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_indexed,return )

int Mesh_obj::get_mode( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_mode",0x6551d8c3,"haxor.graphics.mesh.Mesh.get_mode","haxor/graphics/mesh/Mesh.hx",65,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return this->m_mode;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_mode,return )

int Mesh_obj::set_mode( int v){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","set_mode",0x13af3237,"haxor.graphics.mesh.Mesh.set_mode","haxor/graphics/mesh/Mesh.hx",67,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(68)
	if (((this->m_mode == v))){
		HX_STACK_LINE(68)
		return v;
	}
	HX_STACK_LINE(69)
	this->m_mode = v;
	HX_STACK_LINE(70)
	if ((this->m_indexed)){
		HX_STACK_LINE(70)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_topology_attrib,this->m_mode,true);
	}
	HX_STACK_LINE(71)
	{
		HX_STACK_LINE(71)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(71)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		while((true)){
			HX_STACK_LINE(71)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(71)
				break;
			}
			HX_STACK_LINE(71)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(71)
			::haxor::context::EngineContext_obj::mesh->UpdateAttrib(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >(),this->m_mode,false);
		}
	}
	HX_STACK_LINE(72)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_mode,return )

Array< ::String > Mesh_obj::get_attribs( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_attribs",0x96621089,"haxor.graphics.mesh.Mesh.get_attribs","haxor/graphics/mesh/Mesh.hx",85,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(85)
	Array< ::String > l = Array_obj< ::String >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(85)
	{
		HX_STACK_LINE(85)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(85)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(85)
		while((true)){
			HX_STACK_LINE(85)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(85)
				break;
			}
			HX_STACK_LINE(85)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(85)
			l->push(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name);
		}
	}
	HX_STACK_LINE(85)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_attribs,return )

int Mesh_obj::get_vcount( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_vcount",0x77c4f5f9,"haxor.graphics.mesh.Mesh.get_vcount","haxor/graphics/mesh/Mesh.hx",92,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(92)
	return this->m_vcount;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_vcount,return )

::haxor::math::AABB3 Mesh_obj::get_bounds( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","get_bounds",0x6562a3d5,"haxor.graphics.mesh.Mesh.get_bounds","haxor/graphics/mesh/Mesh.hx",99,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(99)
	return this->m_bounds;
}


HX_DEFINE_DYNAMIC_FUNC0(Mesh_obj,get_bounds,return )

::haxor::math::AABB3 Mesh_obj::set_bounds( ::haxor::math::AABB3 v){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","set_bounds",0x68e04249,"haxor.graphics.mesh.Mesh.set_bounds","haxor/graphics/mesh/Mesh.hx",100,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(100)
	return this->m_bounds->SetAABB3(v);
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,set_bounds,return )

Void Mesh_obj::Clear( hx::Null< bool >  __o_p_from_gpu){
bool p_from_gpu = __o_p_from_gpu.Default(true);
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Clear",0xf7b81b36,"haxor.graphics.mesh.Mesh.Clear","haxor/graphics/mesh/Mesh.hx",129,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_from_gpu,"p_from_gpu")
{
		HX_STACK_LINE(130)
		{
			HX_STACK_LINE(130)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(130)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(130)
			while((true)){
				HX_STACK_LINE(130)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(130)
					break;
				}
				HX_STACK_LINE(130)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(132)
				this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->data = null();
				HX_STACK_LINE(133)
				this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name = HX_CSTRING("");
				HX_STACK_LINE(134)
				if ((p_from_gpu)){
					HX_STACK_LINE(134)
					::haxor::context::EngineContext_obj::mesh->RemoveAttrib(this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >());
				}
			}
		}
		HX_STACK_LINE(137)
		this->m_vcount = (int)0;
		HX_STACK_LINE(138)
		if ((p_from_gpu)){
			HX_STACK_LINE(140)
			this->set_topology(null());
		}
		else{
			HX_STACK_LINE(144)
			this->m_topology_attrib->data = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Clear,(void))

bool Mesh_obj::Exists( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Exists",0x8197e813,"haxor.graphics.mesh.Mesh.Exists","haxor/graphics/mesh/Mesh.hx",154,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(155)
	::haxor::graphics::mesh::MeshAttrib _g = this->GetAttribute(p_name);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(155)
	return (_g != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Exists,return )

Dynamic Mesh_obj::Get( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Get",0xe1323dff,"haxor.graphics.mesh.Mesh.Get","haxor/graphics/mesh/Mesh.hx",162,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(163)
	::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(164)
	if (((a == null()))){
		HX_STACK_LINE(164)
		return null();
	}
	else{
		HX_STACK_LINE(164)
		return a->data;
	}
	HX_STACK_LINE(164)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Get,return )

::haxor::graphics::mesh::MeshAttrib Mesh_obj::GetAttribute( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","GetAttribute",0x4e0eda1d,"haxor.graphics.mesh.Mesh.GetAttribute","haxor/graphics/mesh/Mesh.hx",173,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(174)
	{
		HX_STACK_LINE(174)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(174)
		int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(174)
		while((true)){
			HX_STACK_LINE(174)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(174)
				break;
			}
			HX_STACK_LINE(174)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(174)
			if (((this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->m_name == p_name))){
				HX_STACK_LINE(174)
				return this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >();
			}
		}
	}
	HX_STACK_LINE(175)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,GetAttribute,return )

Void Mesh_obj::Remove( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Remove",0xc640667b,"haxor.graphics.mesh.Mesh.Remove","haxor/graphics/mesh/Mesh.hx",184,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(185)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(186)
		if (((a == null()))){
			HX_STACK_LINE(186)
			return null();
		}
		HX_STACK_LINE(187)
		this->m_attribs->remove(a);
		HX_STACK_LINE(188)
		::haxor::context::EngineContext_obj::mesh->RemoveAttrib(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mesh_obj,Remove,(void))

::haxor::graphics::mesh::MeshAttrib Mesh_obj::Set( ::String p_name,::haxor::io::Buffer p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","Set",0xe13b590b,"haxor.graphics.mesh.Mesh.Set","haxor/graphics/mesh/Mesh.hx",199,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(200)
		if (((p_data == null()))){
			HX_STACK_LINE(200)
			::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(200)
			::String _g1 = (HX_CSTRING("Mesh> [") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(200)
			::String _g2 = (_g1 + HX_CSTRING("] tried to set null array."));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(200)
			::haxor::core::Console_obj::Log(_g2,(int)1);
			HX_STACK_LINE(200)
			return null();
		}
		HX_STACK_LINE(202)
		::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_name);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(203)
		if (((a == null()))){
			HX_STACK_LINE(205)
			::haxor::graphics::mesh::MeshAttrib _g3 = ::haxor::graphics::mesh::MeshAttrib_obj::__new();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(205)
			a = _g3;
			HX_STACK_LINE(206)
			a->m_name = p_name;
			HX_STACK_LINE(207)
			this->m_attribs->push(a);
		}
		HX_STACK_LINE(209)
		if (((p_offset > (int)0))){
			HX_STACK_LINE(209)
			a->offset = p_offset;
		}
		HX_STACK_LINE(210)
		a->data = p_data;
		HX_STACK_LINE(211)
		int _g4 = this->m_attribs->__get((int)0).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(211)
		this->m_vcount = _g4;
		HX_STACK_LINE(212)
		{
			HX_STACK_LINE(212)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(212)
			int _g = this->m_attribs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(212)
			while((true)){
				HX_STACK_LINE(212)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(212)
					break;
				}
				HX_STACK_LINE(212)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(214)
				int c = this->m_attribs->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >()->get_count();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(215)
				if (((this->m_vcount < c))){
					HX_STACK_LINE(215)
					this->m_vcount = this->m_vcount;
				}
				else{
					HX_STACK_LINE(215)
					this->m_vcount = c;
				}
			}
		}
		HX_STACK_LINE(217)
		::haxor::context::EngineContext_obj::mesh->UpdateAttrib(a,this->m_mode,false);
		HX_STACK_LINE(218)
		return a;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Mesh_obj,Set,return )

::haxor::math::AABB3 Mesh_obj::GenerateAttribBounds( ::String p_attrib,::haxor::math::AABB3 p_result){
	HX_STACK_FRAME("haxor.graphics.mesh.Mesh","GenerateAttribBounds",0x096038ab,"haxor.graphics.mesh.Mesh.GenerateAttribBounds","haxor/graphics/mesh/Mesh.hx",227,0xbfac53a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_attrib,"p_attrib")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(228)
	::haxor::math::AABB3 b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(228)
	if (((p_result == null()))){
		HX_STACK_LINE(228)
		b = ::haxor::math::AABB3_obj::get_empty();
	}
	else{
		HX_STACK_LINE(228)
		b = p_result;
	}
	HX_STACK_LINE(229)
	::haxor::graphics::mesh::MeshAttrib a = this->GetAttribute(p_attrib);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(230)
	if (((a == null()))){
		HX_STACK_LINE(230)
		return b->Set((int)0,(int)0,(int)0,(int)0,(int)0,(int)0);
	}
	HX_STACK_LINE(231)
	int step = a->offset;		HX_STACK_VAR(step,"step");
	HX_STACK_LINE(232)
	if (((step <= (int)0))){
		HX_STACK_LINE(232)
		return b->Set((int)0,(int)0,(int)0,(int)0,(int)0,(int)0);
	}
	HX_STACK_LINE(233)
	int i = step;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(234)
	::haxor::io::FloatArray f = a->data;		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(235)
	Float vx;		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(235)
	if (((step > (int)0))){
		HX_STACK_LINE(235)
		vx = f->Get((int)0);
	}
	else{
		HX_STACK_LINE(235)
		vx = (int)0;
	}
	HX_STACK_LINE(236)
	Float vy;		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(236)
	if (((step > (int)1))){
		HX_STACK_LINE(236)
		vy = f->Get((int)1);
	}
	else{
		HX_STACK_LINE(236)
		vy = (int)0;
	}
	HX_STACK_LINE(237)
	Float vz;		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(237)
	if (((step > (int)2))){
		HX_STACK_LINE(237)
		vz = f->Get((int)2);
	}
	else{
		HX_STACK_LINE(237)
		vz = (int)0;
	}
	HX_STACK_LINE(238)
	b->Set(vx,vx,vy,vy,vz,vz);
	HX_STACK_LINE(239)
	while((true)){
		HX_STACK_LINE(239)
		if ((!(((i < f->m_length))))){
			HX_STACK_LINE(239)
			break;
		}
		HX_STACK_LINE(241)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(241)
		if (((step > (int)0))){
			HX_STACK_LINE(241)
			_g = f->Get(i);
		}
		else{
			HX_STACK_LINE(241)
			_g = (int)0;
		}
		HX_STACK_LINE(241)
		vx = _g;
		HX_STACK_LINE(242)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(242)
		if (((step > (int)1))){
			HX_STACK_LINE(242)
			_g1 = f->Get((i + (int)1));
		}
		else{
			HX_STACK_LINE(242)
			_g1 = (int)0;
		}
		HX_STACK_LINE(242)
		vy = _g1;
		HX_STACK_LINE(243)
		Float _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(243)
		if (((step > (int)2))){
			HX_STACK_LINE(243)
			_g2 = f->Get((i + (int)2));
		}
		else{
			HX_STACK_LINE(243)
			_g2 = (int)0;
		}
		HX_STACK_LINE(243)
		vz = _g2;
		HX_STACK_LINE(244)
		b->Encapsulate3(vx,vy,vz);
		HX_STACK_LINE(245)
		hx::AddEq(i,step);
	}
	HX_STACK_LINE(247)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC2(Mesh_obj,GenerateAttribBounds,return )

Void Mesh_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.mesh.Mesh","OnDestroy",0x904e17c4,"haxor.graphics.mesh.Mesh.OnDestroy","haxor/graphics/mesh/Mesh.hx",254,0xbfac53a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(255)
		this->Clear(null());
		HX_STACK_LINE(256)
		{
			HX_STACK_LINE(256)
			int v = this->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(256)
			::haxor::context::EngineContext_obj::mesh->mid->m_cache->push(v);
			HX_STACK_LINE(256)
			v;
		}
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
	HX_MARK_MEMBER_NAME(m_bounds,"m_bounds");
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
	HX_VISIT_MEMBER_NAME(m_bounds,"m_bounds");
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
		if (HX_FIELD_EQ(inName,"bounds") ) { return get_bounds(); }
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
		if (HX_FIELD_EQ(inName,"m_bounds") ) { return m_bounds; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_indexed") ) { return m_indexed; }
		if (HX_FIELD_EQ(inName,"primitive") ) { return primitive; }
		if (HX_FIELD_EQ(inName,"m_attribs") ) { return m_attribs; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_vcount") ) { return get_vcount_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bounds") ) { return get_bounds_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bounds") ) { return set_bounds_dyn(); }
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
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"GenerateAttribBounds") ) { return GenerateAttribBounds_dyn(); }
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
		if (HX_FIELD_EQ(inName,"bounds") ) { return set_bounds(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"attribs") ) { attribs=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"topology") ) { return set_topology(inValue); }
		if (HX_FIELD_EQ(inName,"m_vcount") ) { m_vcount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bounds") ) { m_bounds=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
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
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("m_bounds"));
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
	{hx::fsObject /*::haxor::math::AABB3*/ ,(int)offsetof(Mesh_obj,m_bounds),HX_CSTRING("m_bounds")},
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
	HX_CSTRING("get_bounds"),
	HX_CSTRING("set_bounds"),
	HX_CSTRING("m_bounds"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Exists"),
	HX_CSTRING("Get"),
	HX_CSTRING("GetAttribute"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Set"),
	HX_CSTRING("GenerateAttribBounds"),
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
