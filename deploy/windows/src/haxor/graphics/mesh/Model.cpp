#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
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
#ifndef INCLUDED_haxor_graphics_mesh_Model
#include <haxor/graphics/mesh/Model.h>
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

Void Model_obj::__construct()
{
	return null();
}

//Model_obj::~Model_obj() { }

Dynamic Model_obj::__CreateEmpty() { return  new Model_obj; }
hx::ObjectPtr< Model_obj > Model_obj::__new()
{  hx::ObjectPtr< Model_obj > result = new Model_obj();
	result->__construct();
	return result;}

Dynamic Model_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Model_obj > result = new Model_obj();
	result->__construct();
	return result;}

::haxor::graphics::mesh::Mesh Model_obj::screen;

::haxor::graphics::mesh::Mesh Model_obj::get_screen( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_screen",0xbbdd9664,"haxor.graphics.mesh.Model.get_screen","haxor/graphics/mesh/Model.hx",21,0x06348460)
	HX_STACK_LINE(22)
	if (((::haxor::graphics::mesh::Model_obj::m_screen != null()))){
		HX_STACK_LINE(22)
		return ::haxor::graphics::mesh::Model_obj::m_screen;
	}
	HX_STACK_LINE(23)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelScreen"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(24)
	Float s = 1.0;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(25)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(-(s)).Add(0.5).Add(s).Add(-(s)).Add(0.5).Add(s).Add(s).Add(0.5).Add(-(s)).Add(s).Add(0.5));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(26)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(27)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(28)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(29)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(29)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(29)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(29)
	m->set_bounds(_g2);
	HX_STACK_LINE(30)
	::haxor::io::UInt16Array _g3 = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(30)
	m->set_topology(_g3);
	HX_STACK_LINE(31)
	return ::haxor::graphics::mesh::Model_obj::m_screen = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_screen,return )

::haxor::graphics::mesh::Mesh Model_obj::m_screen;

::haxor::graphics::mesh::Mesh Model_obj::planeXY;

::haxor::graphics::mesh::Mesh Model_obj::get_planeXY( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_planeXY",0xfe9ed865,"haxor.graphics.mesh.Model.get_planeXY","haxor/graphics/mesh/Model.hx",40,0x06348460)
	HX_STACK_LINE(41)
	if (((::haxor::graphics::mesh::Model_obj::m_planeXY != null()))){
		HX_STACK_LINE(41)
		return ::haxor::graphics::mesh::Model_obj::m_planeXY;
	}
	HX_STACK_LINE(42)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelPlaneXY"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(43)
	Float s = 0.5;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(44)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(-(s)).Add(0.0).Add(s).Add(-(s)).Add(0.0).Add(s).Add(s).Add(0.0).Add(-(s)).Add(s).Add(0.0));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(45)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(46)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(47)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(48)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(48)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(48)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(48)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(48)
	m->set_bounds(_g2);
	HX_STACK_LINE(49)
	::haxor::io::UInt16Array _g3 = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(49)
	m->set_topology(_g3);
	HX_STACK_LINE(50)
	return ::haxor::graphics::mesh::Model_obj::m_planeXY = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_planeXY,return )

::haxor::graphics::mesh::Mesh Model_obj::m_planeXY;

::haxor::graphics::mesh::Mesh Model_obj::planeXZ;

::haxor::graphics::mesh::Mesh Model_obj::get_planeXZ( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_planeXZ",0xfe9ed866,"haxor.graphics.mesh.Model.get_planeXZ","haxor/graphics/mesh/Model.hx",59,0x06348460)
	HX_STACK_LINE(60)
	if (((::haxor::graphics::mesh::Model_obj::m_planeXZ != null()))){
		HX_STACK_LINE(60)
		return ::haxor::graphics::mesh::Model_obj::m_planeXZ;
	}
	HX_STACK_LINE(61)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelPlaneXZ"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(62)
	Float s = 0.5;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(63)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(0.0).Add(-(s)).Add(s).Add(0.0).Add(-(s)).Add(s).Add(0.0).Add(s).Add(-(s)).Add(0.0).Add(s));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(64)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(65)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(66)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(67)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(67)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(67)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(67)
	m->set_bounds(_g2);
	HX_STACK_LINE(68)
	::haxor::io::UInt16Array _g3 = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(68)
	m->set_topology(_g3);
	HX_STACK_LINE(69)
	return ::haxor::graphics::mesh::Model_obj::m_planeXZ = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_planeXZ,return )

::haxor::graphics::mesh::Mesh Model_obj::m_planeXZ;

::haxor::graphics::mesh::Mesh Model_obj::planeYZ;

::haxor::graphics::mesh::Mesh Model_obj::get_planeYZ( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_planeYZ",0xfe9ed945,"haxor.graphics.mesh.Model.get_planeYZ","haxor/graphics/mesh/Model.hx",78,0x06348460)
	HX_STACK_LINE(79)
	if (((::haxor::graphics::mesh::Model_obj::m_planeYZ != null()))){
		HX_STACK_LINE(79)
		return ::haxor::graphics::mesh::Model_obj::m_planeYZ;
	}
	HX_STACK_LINE(80)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelPlaneYZ"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(81)
	Float s = 0.5;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(82)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(-(s)).Add(-(s)).Add(0.0).Add(s).Add(-(s)).Add(0.0).Add(s).Add(s).Add(0.0).Add(-(s)).Add(s));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(83)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(84)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(85)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(86)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(86)
	{
		HX_STACK_LINE(86)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(86)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(86)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(86)
	m->set_bounds(_g2);
	HX_STACK_LINE(87)
	::haxor::io::UInt16Array _g3 = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(87)
	m->set_topology(_g3);
	HX_STACK_LINE(88)
	return ::haxor::graphics::mesh::Model_obj::m_planeYZ = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_planeYZ,return )

::haxor::graphics::mesh::Mesh Model_obj::m_planeYZ;

::haxor::graphics::mesh::Mesh Model_obj::cube;

::haxor::graphics::mesh::Mesh Model_obj::get_cube( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_cube",0x89ea69ed,"haxor.graphics.mesh.Model.get_cube","haxor/graphics/mesh/Model.hx",97,0x06348460)
	HX_STACK_LINE(98)
	if (((::haxor::graphics::mesh::Model_obj::m_cube != null()))){
		HX_STACK_LINE(98)
		return ::haxor::graphics::mesh::Model_obj::m_cube;
	}
	HX_STACK_LINE(99)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelCube"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(100)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AAAAvwAAAL8AAAC/AAAAvwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAL8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAC/"));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(101)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAA"));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(102)
	::haxor::io::FloatArray n = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAA"));		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(103)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(104)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(105)
	m->Set(HX_CSTRING("normal"),n,(int)3);
	HX_STACK_LINE(106)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(106)
	{
		HX_STACK_LINE(106)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(106)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(106)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(106)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(106)
	m->set_bounds(_g2);
	HX_STACK_LINE(107)
	return ::haxor::graphics::mesh::Model_obj::m_cube = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_cube,return )

::haxor::graphics::mesh::Mesh Model_obj::m_cube;

::haxor::graphics::mesh::Mesh Model_obj::tetrahedron;

::haxor::graphics::mesh::Mesh Model_obj::get_tetrahedron( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_tetrahedron",0x93278184,"haxor.graphics.mesh.Model.get_tetrahedron","haxor/graphics/mesh/Model.hx",116,0x06348460)
	HX_STACK_LINE(117)
	if (((::haxor::graphics::mesh::Model_obj::m_tetrahedron != null()))){
		HX_STACK_LINE(117)
		return ::haxor::graphics::mesh::Model_obj::m_tetrahedron;
	}
	HX_STACK_LINE(118)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelTetrahedron"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(119)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AAAAAAAAAAAAAAAAsb+cvpm/Bz8AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAAAAAAAArr+cvpu/B78AAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAAAAAAAAsb8cPwAAAAAAAAAArr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb8cPwAAAAAAAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAArr+cvpu/B78AAAAAAAAAAAAAAACX/1A/rr+cvpu/B78AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/rr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/"));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(120)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AAAAPwAAAAAAAAAAraqqPQAAAAAAAIA/AACAvgAAAAAAAIA/AAAAPwAAAAAAAAAAVlXVPgAAAAD+/38/raqqPQAAAAAAAIA/AAAAPwAAAAAAAAAAAABAPwAAAAAAAIA/VlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAACAvgAAAAAAAIA/raqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/VlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAA"));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(121)
	::haxor::io::FloatArray n = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAQrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbNvv4aDqbNyxrM+RbNvv4aDqbN2xrM+RLNvv4aDqbNyxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbPvPiWWT792xrM+SbPvPiWWT792xrM+RbPvPiWWT792xrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAA"));		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(122)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(123)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(124)
	m->Set(HX_CSTRING("normal"),n,(int)3);
	HX_STACK_LINE(125)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(125)
	{
		HX_STACK_LINE(125)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(125)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(125)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(125)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(125)
	m->set_bounds(_g2);
	HX_STACK_LINE(126)
	return ::haxor::graphics::mesh::Model_obj::m_tetrahedron = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_tetrahedron,return )

::haxor::graphics::mesh::Mesh Model_obj::m_tetrahedron;

::haxor::graphics::mesh::Mesh Model_obj::sphere;

::haxor::graphics::mesh::Mesh Model_obj::get_sphere( ){
	HX_STACK_FRAME("haxor.graphics.mesh.Model","get_sphere",0x31770a05,"haxor.graphics.mesh.Model.get_sphere","haxor/graphics/mesh/Model.hx",135,0x06348460)
	HX_STACK_LINE(136)
	if (((::haxor::graphics::mesh::Model_obj::m_sphere != null()))){
		HX_STACK_LINE(136)
		return ::haxor::graphics::mesh::Model_obj::m_sphere;
	}
	HX_STACK_LINE(137)
	::haxor::graphics::mesh::Mesh m = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$ModelSphere"));		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(138)
	::haxor::io::FloatArray v = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("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"));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(139)
	::haxor::io::FloatArray uv = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("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"));		HX_STACK_VAR(uv,"uv");
	HX_STACK_LINE(140)
	::haxor::io::FloatArray n = ::haxor::io::FloatArray_obj::FromBase64(HX_CSTRING("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"));		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(141)
	m->Set(HX_CSTRING("vertex"),v,(int)3);
	HX_STACK_LINE(142)
	m->Set(HX_CSTRING("uv0"),uv,(int)3);
	HX_STACK_LINE(143)
	m->Set(HX_CSTRING("normal"),n,(int)3);
	HX_STACK_LINE(144)
	::haxor::math::AABB3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(144)
	{
		HX_STACK_LINE(144)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(144)
		int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(144)
		_g1 = _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
	}
	HX_STACK_LINE(144)
	::haxor::math::AABB3 _g2 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(144)
	m->set_bounds(_g2);
	HX_STACK_LINE(145)
	return ::haxor::graphics::mesh::Model_obj::m_sphere = m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Model_obj,get_sphere,return )

::haxor::graphics::mesh::Mesh Model_obj::m_sphere;


Model_obj::Model_obj()
{
}

Dynamic Model_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"cube") ) { return inCallProp ? get_cube() : cube; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"screen") ) { return inCallProp ? get_screen() : screen; }
		if (HX_FIELD_EQ(inName,"m_cube") ) { return m_cube; }
		if (HX_FIELD_EQ(inName,"sphere") ) { return inCallProp ? get_sphere() : sphere; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"planeXY") ) { return inCallProp ? get_planeXY() : planeXY; }
		if (HX_FIELD_EQ(inName,"planeXZ") ) { return inCallProp ? get_planeXZ() : planeXZ; }
		if (HX_FIELD_EQ(inName,"planeYZ") ) { return inCallProp ? get_planeYZ() : planeYZ; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_screen") ) { return m_screen; }
		if (HX_FIELD_EQ(inName,"get_cube") ) { return get_cube_dyn(); }
		if (HX_FIELD_EQ(inName,"m_sphere") ) { return m_sphere; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_planeXY") ) { return m_planeXY; }
		if (HX_FIELD_EQ(inName,"m_planeXZ") ) { return m_planeXZ; }
		if (HX_FIELD_EQ(inName,"m_planeYZ") ) { return m_planeYZ; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_screen") ) { return get_screen_dyn(); }
		if (HX_FIELD_EQ(inName,"get_sphere") ) { return get_sphere_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_planeXY") ) { return get_planeXY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_planeXZ") ) { return get_planeXZ_dyn(); }
		if (HX_FIELD_EQ(inName,"get_planeYZ") ) { return get_planeYZ_dyn(); }
		if (HX_FIELD_EQ(inName,"tetrahedron") ) { return inCallProp ? get_tetrahedron() : tetrahedron; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_tetrahedron") ) { return m_tetrahedron; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_tetrahedron") ) { return get_tetrahedron_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Model_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"cube") ) { cube=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"screen") ) { screen=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cube") ) { m_cube=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sphere") ) { sphere=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"planeXY") ) { planeXY=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"planeXZ") ) { planeXZ=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"planeYZ") ) { planeYZ=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_screen") ) { m_screen=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sphere") ) { m_sphere=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_planeXY") ) { m_planeXY=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_planeXZ") ) { m_planeXZ=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_planeYZ") ) { m_planeYZ=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tetrahedron") ) { tetrahedron=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_tetrahedron") ) { m_tetrahedron=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Model_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("screen"),
	HX_CSTRING("get_screen"),
	HX_CSTRING("m_screen"),
	HX_CSTRING("planeXY"),
	HX_CSTRING("get_planeXY"),
	HX_CSTRING("m_planeXY"),
	HX_CSTRING("planeXZ"),
	HX_CSTRING("get_planeXZ"),
	HX_CSTRING("m_planeXZ"),
	HX_CSTRING("planeYZ"),
	HX_CSTRING("get_planeYZ"),
	HX_CSTRING("m_planeYZ"),
	HX_CSTRING("cube"),
	HX_CSTRING("get_cube"),
	HX_CSTRING("m_cube"),
	HX_CSTRING("tetrahedron"),
	HX_CSTRING("get_tetrahedron"),
	HX_CSTRING("m_tetrahedron"),
	HX_CSTRING("sphere"),
	HX_CSTRING("get_sphere"),
	HX_CSTRING("m_sphere"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Model_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Model_obj::screen,"screen");
	HX_MARK_MEMBER_NAME(Model_obj::m_screen,"m_screen");
	HX_MARK_MEMBER_NAME(Model_obj::planeXY,"planeXY");
	HX_MARK_MEMBER_NAME(Model_obj::m_planeXY,"m_planeXY");
	HX_MARK_MEMBER_NAME(Model_obj::planeXZ,"planeXZ");
	HX_MARK_MEMBER_NAME(Model_obj::m_planeXZ,"m_planeXZ");
	HX_MARK_MEMBER_NAME(Model_obj::planeYZ,"planeYZ");
	HX_MARK_MEMBER_NAME(Model_obj::m_planeYZ,"m_planeYZ");
	HX_MARK_MEMBER_NAME(Model_obj::cube,"cube");
	HX_MARK_MEMBER_NAME(Model_obj::m_cube,"m_cube");
	HX_MARK_MEMBER_NAME(Model_obj::tetrahedron,"tetrahedron");
	HX_MARK_MEMBER_NAME(Model_obj::m_tetrahedron,"m_tetrahedron");
	HX_MARK_MEMBER_NAME(Model_obj::sphere,"sphere");
	HX_MARK_MEMBER_NAME(Model_obj::m_sphere,"m_sphere");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Model_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Model_obj::screen,"screen");
	HX_VISIT_MEMBER_NAME(Model_obj::m_screen,"m_screen");
	HX_VISIT_MEMBER_NAME(Model_obj::planeXY,"planeXY");
	HX_VISIT_MEMBER_NAME(Model_obj::m_planeXY,"m_planeXY");
	HX_VISIT_MEMBER_NAME(Model_obj::planeXZ,"planeXZ");
	HX_VISIT_MEMBER_NAME(Model_obj::m_planeXZ,"m_planeXZ");
	HX_VISIT_MEMBER_NAME(Model_obj::planeYZ,"planeYZ");
	HX_VISIT_MEMBER_NAME(Model_obj::m_planeYZ,"m_planeYZ");
	HX_VISIT_MEMBER_NAME(Model_obj::cube,"cube");
	HX_VISIT_MEMBER_NAME(Model_obj::m_cube,"m_cube");
	HX_VISIT_MEMBER_NAME(Model_obj::tetrahedron,"tetrahedron");
	HX_VISIT_MEMBER_NAME(Model_obj::m_tetrahedron,"m_tetrahedron");
	HX_VISIT_MEMBER_NAME(Model_obj::sphere,"sphere");
	HX_VISIT_MEMBER_NAME(Model_obj::m_sphere,"m_sphere");
};

#endif

Class Model_obj::__mClass;

void Model_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.Model"), hx::TCanCast< Model_obj> ,sStaticFields,sMemberFields,
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

void Model_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
