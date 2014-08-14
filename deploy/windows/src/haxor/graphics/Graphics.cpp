#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace graphics{

Void Graphics_obj::__construct()
{
	return null();
}

//Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new()
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct();
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct();
	return result;}

Void Graphics_obj::RenderMesh( ::haxor::graphics::mesh::Mesh p_mesh,::haxor::graphics::material::Material p_material){
{
		HX_STACK_FRAME("haxor.graphics.Graphics","RenderMesh",0xc28dbdaf,"haxor.graphics.Graphics.RenderMesh","haxor/graphics/Graphics.hx",20,0x1a55985c)
		HX_STACK_ARG(p_mesh,"p_mesh")
		HX_STACK_ARG(p_material,"p_material")
		HX_STACK_LINE(21)
		{
			HX_STACK_LINE(21)
			::haxor::context::MaterialContext _this = ::haxor::context::EngineContext_obj::material;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(21)
			if (((p_material != _this->current))){
				HX_STACK_LINE(21)
				_this->current = p_material;
				HX_STACK_LINE(21)
				if (((p_material != null()))){
					HX_STACK_LINE(21)
					_this->UpdateFlags(p_material);
					HX_STACK_LINE(21)
					::haxor::platform::graphics::GL_obj::m_gl->UseProgram(_this->programs->__get(p_material->_cid_));
				}
			}
		}
		HX_STACK_LINE(22)
		{
			HX_STACK_LINE(22)
			::haxor::context::MeshContext _this = ::haxor::context::EngineContext_obj::mesh;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(22)
			if (((p_mesh != _this->current))){
				HX_STACK_LINE(22)
				_this->current = p_mesh;
				HX_STACK_LINE(22)
				::haxor::graphics::mesh::MeshAttrib a;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(22)
				if (((_this->current != null()))){
					HX_STACK_LINE(22)
					Array< ::Dynamic > al = _this->current->m_attribs;		HX_STACK_VAR(al,"al");
					HX_STACK_LINE(22)
					int id;		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(22)
					int type;		HX_STACK_VAR(type,"type");
					HX_STACK_LINE(22)
					bool has_color = false;		HX_STACK_VAR(has_color,"has_color");
					HX_STACK_LINE(22)
					{
						HX_STACK_LINE(22)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(22)
						int _g = al->length;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(22)
						while((true)){
							HX_STACK_LINE(22)
							if ((!(((_g1 < _g))))){
								HX_STACK_LINE(22)
								break;
							}
							HX_STACK_LINE(22)
							int i = (_g1)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(22)
							a = al->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >();
							HX_STACK_LINE(22)
							int loc = a->_loc_;		HX_STACK_VAR(loc,"loc");
							HX_STACK_LINE(22)
							if (((loc == (int)5))){
								HX_STACK_LINE(22)
								has_color = true;
							}
							HX_STACK_LINE(22)
							if (((loc < (int)0))){
								HX_STACK_LINE(22)
								int _g2 = ::haxor::context::EngineContext_obj::material->GetAttribLocation(a);		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(22)
								loc = _g2;
								HX_STACK_LINE(22)
								if (((loc < (int)0))){
									HX_STACK_LINE(22)
									continue;
								}
							}
							HX_STACK_LINE(22)
							type = (int)5126;
							HX_STACK_LINE(22)
							if ((!(_this->activated->__get(loc)))){
								HX_STACK_LINE(22)
								_this->activated[loc] = true;
								HX_STACK_LINE(22)
								int _g11 = ::Math_obj::max(_this->active_max,loc);		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(22)
								_this->active_max = _g11;
								HX_STACK_LINE(22)
								::haxor::platform::graphics::GL_obj::m_gl->EnableVertexAttrib(loc);
							}
							HX_STACK_LINE(22)
							::haxor::platform::graphics::GL_obj::m_gl->BindBuffer((int)34962,_this->buffers->__get(a->_cid_));
							HX_STACK_LINE(22)
							::haxor::platform::graphics::GL_obj::m_gl->VertexAttribPointer(loc,a->offset,type,false,(int)0,(int)0);
						}
					}
					HX_STACK_LINE(22)
					if ((!(has_color))){
						HX_STACK_LINE(22)
						::haxor::platform::graphics::GL_obj::m_gl->VertexAttrib4f((int)5,1.0,1.0,1.0,0.5);
					}
					HX_STACK_LINE(22)
					if ((_this->current->m_indexed)){
						HX_STACK_LINE(22)
						a = _this->current->m_topology_attrib;
						HX_STACK_LINE(22)
						::haxor::platform::graphics::GL_obj::m_gl->BindBuffer((int)34963,_this->buffers->__get(a->_cid_));
					}
					HX_STACK_LINE(22)
					Dynamic();
				}
			}
		}
		HX_STACK_LINE(23)
		if ((p_mesh->m_indexed)){
			HX_STACK_LINE(23)
			::haxor::platform::graphics::GL_obj::m_gl->DrawElements(p_mesh->primitive,p_mesh->m_topology_attrib->data->m_length,(int)5123,(int)0);
			HX_STACK_LINE(23)
			Dynamic();
		}
		else{
			HX_STACK_LINE(23)
			::haxor::platform::graphics::GL_obj::m_gl->DrawArrays(p_mesh->primitive,(int)0,p_mesh->m_vcount);
			HX_STACK_LINE(23)
			Dynamic();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,RenderMesh,(void))


Graphics_obj::Graphics_obj()
{
}

Dynamic Graphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"RenderMesh") ) { return RenderMesh_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("RenderMesh"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
};

#endif

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
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

void Graphics_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
