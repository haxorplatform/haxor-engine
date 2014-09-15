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
#ifndef INCLUDED_haxor_core_Stats
#include <haxor/core/Stats.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
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
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace context{

Void MeshContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.MeshContext","new",0x9085c6a9,"haxor.context.MeshContext.new","haxor/context/MeshContext.hx",16,0xf23de969)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	this->attribs = Array_obj< ::String >::__new().Add(HX_CSTRING("vertex")).Add(HX_CSTRING("normal")).Add(HX_CSTRING("uv0")).Add(HX_CSTRING("uv1")).Add(HX_CSTRING("uv2")).Add(HX_CSTRING("color")).Add(HX_CSTRING("weight")).Add(HX_CSTRING("bone"));
	HX_STACK_LINE(59)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(59)
	this->aid = _g;
	HX_STACK_LINE(60)
	::haxor::context::UID _g1 = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(60)
	this->mid = _g1;
	HX_STACK_LINE(61)
	this->buffers = Array_obj< int >::__new();
	HX_STACK_LINE(62)
	this->activated = Array_obj< bool >::__new();
	HX_STACK_LINE(65)
	{
		HX_STACK_LINE(65)
		int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(65)
		while((true)){
			HX_STACK_LINE(65)
			if ((!(((_g2 < (int)32))))){
				HX_STACK_LINE(65)
				break;
			}
			HX_STACK_LINE(65)
			int i = (_g2)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(65)
			this->activated->push(false);
		}
	}
	HX_STACK_LINE(67)
	int max_buffers = (int)512;		HX_STACK_VAR(max_buffers,"max_buffers");
	HX_STACK_LINE(69)
	{
		HX_STACK_LINE(69)
		int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(69)
		while((true)){
			HX_STACK_LINE(69)
			if ((!(((_g2 < max_buffers))))){
				HX_STACK_LINE(69)
				break;
			}
			HX_STACK_LINE(69)
			int i = (_g2)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(71)
			this->buffers->push(::haxor::graphics::GL_obj::INVALID);
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

Void MeshContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.MeshContext","Initialize",0xf4678a47,"haxor.context.MeshContext.Initialize","haxor/context/MeshContext.hx",80,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_LINE(80)
		::haxor::core::Console_obj::Log(HX_CSTRING("MeshContext> Initialize."),(int)3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MeshContext_obj,Initialize,(void))

Void MeshContext_obj::Bind( ::haxor::graphics::mesh::Mesh p_mesh){
{
		HX_STACK_FRAME("haxor.context.MeshContext","Bind",0xc775ab74,"haxor.context.MeshContext.Bind","haxor/context/MeshContext.hx",89,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_mesh,"p_mesh")
		HX_STACK_LINE(89)
		if (((p_mesh != this->current))){
			HX_STACK_LINE(91)
			this->Unbind();
			HX_STACK_LINE(92)
			this->current = p_mesh;
			HX_STACK_LINE(94)
			if (((this->current != null()))){
				HX_STACK_LINE(97)
				this->ActivateAttributes();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MeshContext_obj,Bind,(void))

Void MeshContext_obj::ActivateAttributes( ){
{
		HX_STACK_FRAME("haxor.context.MeshContext","ActivateAttributes",0x6a542e61,"haxor.context.MeshContext.ActivateAttributes","haxor/context/MeshContext.hx",109,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_LINE(110)
		::haxor::graphics::mesh::MeshAttrib a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(111)
		Array< ::Dynamic > al = this->current->m_attribs;		HX_STACK_VAR(al,"al");
		HX_STACK_LINE(112)
		int id;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(113)
		int type;		HX_STACK_VAR(type,"type");
		HX_STACK_LINE(114)
		bool has_color = false;		HX_STACK_VAR(has_color,"has_color");
		HX_STACK_LINE(116)
		{
			HX_STACK_LINE(116)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(116)
			int _g = al->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(116)
			while((true)){
				HX_STACK_LINE(116)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(116)
					break;
				}
				HX_STACK_LINE(116)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(118)
				a = al->__get(i).StaticCast< ::haxor::graphics::mesh::MeshAttrib >();
				HX_STACK_LINE(119)
				int loc = a->_loc_;		HX_STACK_VAR(loc,"loc");
				HX_STACK_LINE(120)
				if (((loc == (int)5))){
					HX_STACK_LINE(120)
					has_color = true;
				}
				HX_STACK_LINE(121)
				if (((loc < (int)0))){
					HX_STACK_LINE(125)
					int _g2 = ::haxor::context::EngineContext_obj::material->GetAttribLocation(a);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(125)
					loc = _g2;
					HX_STACK_LINE(126)
					if (((loc < (int)0))){
						HX_STACK_LINE(126)
						continue;
					}
				}
				HX_STACK_LINE(128)
				type = (int)5126;
				HX_STACK_LINE(130)
				if ((!(this->activated->__get(loc)))){
					HX_STACK_LINE(132)
					this->activated[loc] = true;
					HX_STACK_LINE(133)
					int _g11 = ::Math_obj::max(this->active_max,loc);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(133)
					this->active_max = _g11;
					HX_STACK_LINE(134)
					::haxor::graphics::GL_obj::m_gl->EnableVertexAttrib(loc);
				}
				HX_STACK_LINE(136)
				::haxor::graphics::GL_obj::m_gl->BindBuffer((int)34962,this->buffers->__get(a->__cid));
				HX_STACK_LINE(137)
				::haxor::graphics::GL_obj::m_gl->VertexAttribPointer(loc,a->offset,type,false,(int)0,(int)0);
			}
		}
		HX_STACK_LINE(141)
		if ((!(has_color))){
			HX_STACK_LINE(143)
			if ((this->activated->__get((int)5))){
				HX_STACK_LINE(143)
				::haxor::graphics::GL_obj::m_gl->DisableVertexAttrib((int)5);
				HX_STACK_LINE(143)
				this->activated[(int)5] = false;
			}
			HX_STACK_LINE(144)
			::haxor::graphics::GL_obj::m_gl->VertexAttrib4f((int)5,1.0,1.0,1.0,1.0);
		}
		HX_STACK_LINE(147)
		if ((this->current->m_indexed)){
			HX_STACK_LINE(149)
			a = this->current->m_topology_attrib;
			HX_STACK_LINE(150)
			::haxor::graphics::GL_obj::m_gl->BindBuffer((int)34963,this->buffers->__get(a->__cid));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MeshContext_obj,ActivateAttributes,(void))

Void MeshContext_obj::Unbind( ){
{
		HX_STACK_FRAME("haxor.context.MeshContext","Unbind",0x42acce0d,"haxor.context.MeshContext.Unbind","haxor/context/MeshContext.hx",158,0xf23de969)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MeshContext_obj,Unbind,(void))

Void MeshContext_obj::Draw( ::haxor::graphics::mesh::Mesh m){
{
		HX_STACK_FRAME("haxor.context.MeshContext","Draw",0xc8cee1bb,"haxor.context.MeshContext.Draw","haxor/context/MeshContext.hx",176,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(176)
		if ((m->m_indexed)){
			HX_STACK_LINE(178)
			::haxor::graphics::GL_obj::m_gl->DrawElements(m->primitive,m->m_topology_attrib->data->m_length,(int)5123,(int)0);
			HX_STACK_LINE(181)
			hx::AddEq(::haxor::core::Stats_obj::triangles,(Float(m->m_topology_attrib->data->m_length) / Float((int)3)));
		}
		else{
			HX_STACK_LINE(191)
			::haxor::graphics::GL_obj::m_gl->DrawArrays(m->primitive,(int)0,m->m_vcount);
			HX_STACK_LINE(194)
			int off = (int)3;		HX_STACK_VAR(off,"off");
			HX_STACK_LINE(195)
			if (((m->primitive == (int)1))){
				HX_STACK_LINE(195)
				off = (int)2;
			}
			HX_STACK_LINE(196)
			hx::AddEq(::haxor::core::Stats_obj::triangles,(Float(m->m_vcount) / Float(off)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MeshContext_obj,Draw,(void))

Void MeshContext_obj::RemoveAttrib( ::haxor::graphics::mesh::MeshAttrib p_attrib){
{
		HX_STACK_FRAME("haxor.context.MeshContext","RemoveAttrib",0xdd784765,"haxor.context.MeshContext.RemoveAttrib","haxor/context/MeshContext.hx",211,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_attrib,"p_attrib")
		HX_STACK_LINE(212)
		int id = this->buffers->__get(p_attrib->__cid);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(213)
		if (((id == ::haxor::graphics::GL_obj::INVALID))){
			HX_STACK_LINE(213)
			return null();
		}
		HX_STACK_LINE(214)
		::haxor::graphics::GL_obj::m_gl->DeleteBuffer(id);
		HX_STACK_LINE(215)
		this->buffers[p_attrib->__cid] = ::haxor::graphics::GL_obj::INVALID;
		HX_STACK_LINE(216)
		{
			HX_STACK_LINE(216)
			int v = p_attrib->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(216)
			this->aid->m_cache->push(v);
			HX_STACK_LINE(216)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MeshContext_obj,RemoveAttrib,(void))

Void MeshContext_obj::UpdateAttrib( ::haxor::graphics::mesh::MeshAttrib a,int p_mode,bool p_is_index){
{
		HX_STACK_FRAME("haxor.context.MeshContext","UpdateAttrib",0x6e0e52ea,"haxor.context.MeshContext.UpdateAttrib","haxor/context/MeshContext.hx",224,0xf23de969)
		HX_STACK_THIS(this)
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_ARG(p_is_index,"p_is_index")
		HX_STACK_LINE(225)
		int id = this->buffers->__get(a->__cid);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(226)
		int target_flag;		HX_STACK_VAR(target_flag,"target_flag");
		HX_STACK_LINE(226)
		if ((p_is_index)){
			HX_STACK_LINE(226)
			target_flag = (int)34963;
		}
		else{
			HX_STACK_LINE(226)
			target_flag = (int)34962;
		}
		HX_STACK_LINE(229)
		int _g = this->attribs->indexOf(a->m_name,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(229)
		a->_loc_ = _g;
		HX_STACK_LINE(231)
		if (((id == ::haxor::graphics::GL_obj::INVALID))){
			HX_STACK_LINE(233)
			int _g1 = ::haxor::graphics::GL_obj::m_gl->CreateBuffer();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(233)
			id = _g1;
			HX_STACK_LINE(234)
			this->buffers[a->__cid] = id;
		}
		HX_STACK_LINE(237)
		::haxor::graphics::GL_obj::m_gl->BindBuffer(target_flag,id);
		HX_STACK_LINE(238)
		::haxor::graphics::GL_obj::m_gl->BufferData(target_flag,a->data,p_mode);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MeshContext_obj,UpdateAttrib,(void))


MeshContext_obj::MeshContext_obj()
{
}

void MeshContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshContext);
	HX_MARK_MEMBER_NAME(aid,"aid");
	HX_MARK_MEMBER_NAME(mid,"mid");
	HX_MARK_MEMBER_NAME(attribs,"attribs");
	HX_MARK_MEMBER_NAME(buffers,"buffers");
	HX_MARK_MEMBER_NAME(activated,"activated");
	HX_MARK_MEMBER_NAME(active_max,"active_max");
	HX_MARK_MEMBER_NAME(current,"current");
	HX_MARK_END_CLASS();
}

void MeshContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(aid,"aid");
	HX_VISIT_MEMBER_NAME(mid,"mid");
	HX_VISIT_MEMBER_NAME(attribs,"attribs");
	HX_VISIT_MEMBER_NAME(buffers,"buffers");
	HX_VISIT_MEMBER_NAME(activated,"activated");
	HX_VISIT_MEMBER_NAME(active_max,"active_max");
	HX_VISIT_MEMBER_NAME(current,"current");
}

Dynamic MeshContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"aid") ) { return aid; }
		if (HX_FIELD_EQ(inName,"mid") ) { return mid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		if (HX_FIELD_EQ(inName,"Draw") ) { return Draw_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"attribs") ) { return attribs; }
		if (HX_FIELD_EQ(inName,"buffers") ) { return buffers; }
		if (HX_FIELD_EQ(inName,"current") ) { return current; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"activated") ) { return activated; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"active_max") ) { return active_max; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"RemoveAttrib") ) { return RemoveAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateAttrib") ) { return UpdateAttrib_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"ActivateAttributes") ) { return ActivateAttributes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"aid") ) { aid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mid") ) { mid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"attribs") ) { attribs=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buffers") ) { buffers=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"activated") ) { activated=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"active_max") ) { active_max=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("aid"));
	outFields->push(HX_CSTRING("mid"));
	outFields->push(HX_CSTRING("attribs"));
	outFields->push(HX_CSTRING("buffers"));
	outFields->push(HX_CSTRING("activated"));
	outFields->push(HX_CSTRING("active_max"));
	outFields->push(HX_CSTRING("current"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(MeshContext_obj,aid),HX_CSTRING("aid")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(MeshContext_obj,mid),HX_CSTRING("mid")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(MeshContext_obj,attribs),HX_CSTRING("attribs")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MeshContext_obj,buffers),HX_CSTRING("buffers")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(MeshContext_obj,activated),HX_CSTRING("activated")},
	{hx::fsInt,(int)offsetof(MeshContext_obj,active_max),HX_CSTRING("active_max")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(MeshContext_obj,current),HX_CSTRING("current")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("aid"),
	HX_CSTRING("mid"),
	HX_CSTRING("attribs"),
	HX_CSTRING("buffers"),
	HX_CSTRING("activated"),
	HX_CSTRING("active_max"),
	HX_CSTRING("current"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Bind"),
	HX_CSTRING("ActivateAttributes"),
	HX_CSTRING("Unbind"),
	HX_CSTRING("Draw"),
	HX_CSTRING("RemoveAttrib"),
	HX_CSTRING("UpdateAttrib"),
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
