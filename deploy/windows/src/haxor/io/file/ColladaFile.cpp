#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_DataComponent
#include <haxor/component/DataComponent.h>
#endif
#ifndef INCLUDED_haxor_component_MeshRenderer
#include <haxor/component/MeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_SkinnedMeshRenderer
#include <haxor/component/SkinnedMeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_component_animation_AnimationClip
#include <haxor/component/animation/AnimationClip.h>
#endif
#ifndef INCLUDED_haxor_component_animation_ClipTrack
#include <haxor/component/animation/ClipTrack.h>
#endif
#ifndef INCLUDED_haxor_component_animation_KeyFrame
#include <haxor/component/animation/KeyFrame.h>
#endif
#ifndef INCLUDED_haxor_component_light_Light
#include <haxor/component/light/Light.h>
#endif
#ifndef INCLUDED_haxor_component_light_PointLight
#include <haxor/component/light/PointLight.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_Asset
#include <haxor/core/Asset.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
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
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAnimation
#include <haxor/io/file/ColladaAnimation.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAnimationChannel
#include <haxor/io/file/ColladaAnimationChannel.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAnimationKeyFrame
#include <haxor/io/file/ColladaAnimationKeyFrame.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaAssetData
#include <haxor/io/file/ColladaAssetData.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaController
#include <haxor/io/file/ColladaController.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaFile
#include <haxor/io/file/ColladaFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaGeometry
#include <haxor/io/file/ColladaGeometry.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaImage
#include <haxor/io/file/ColladaImage.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaInput
#include <haxor/io/file/ColladaInput.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaInstance
#include <haxor/io/file/ColladaInstance.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaLight
#include <haxor/io/file/ColladaLight.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaMaterial
#include <haxor/io/file/ColladaMaterial.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaMesh
#include <haxor/io/file/ColladaMesh.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaNode
#include <haxor/io/file/ColladaNode.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaPrimitive
#include <haxor/io/file/ColladaPrimitive.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaVisualScene
#include <haxor/io/file/ColladaVisualScene.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaFile_obj::__construct(::String p_name,::String p_src)
{
HX_STACK_FRAME("haxor.io.file.ColladaFile","new",0x10d85e4a,"haxor.io.file.ColladaFile.new","haxor/io/file/ColladaFile.hx",132,0xa1888587)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_src,"p_src")
{
	HX_STACK_LINE(133)
	this->xmlns = HX_CSTRING("");
	HX_STACK_LINE(134)
	this->version = HX_CSTRING("");
	HX_STACK_LINE(135)
	::haxor::io::file::ColladaAssetData _g = ::haxor::io::file::ColladaAssetData_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(135)
	this->data = _g;
	HX_STACK_LINE(136)
	this->geometries = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(137)
	this->images = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(138)
	this->controllers = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(139)
	this->materials = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(140)
	this->animations = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(141)
	this->lights = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(142)
	this->scene = null();
	HX_STACK_LINE(143)
	Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(143)
	Float _g2 = (_g1 * (int)16777215);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(143)
	int _g3 = ::Std_obj::_int(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(143)
	this->m_id = _g3;
	HX_STACK_LINE(145)
	super::__construct(p_name,p_src);
}
;
	return null();
}

//ColladaFile_obj::~ColladaFile_obj() { }

Dynamic ColladaFile_obj::__CreateEmpty() { return  new ColladaFile_obj; }
hx::ObjectPtr< ColladaFile_obj > ColladaFile_obj::__new(::String p_name,::String p_src)
{  hx::ObjectPtr< ColladaFile_obj > result = new ColladaFile_obj();
	result->__construct(p_name,p_src);
	return result;}

Dynamic ColladaFile_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaFile_obj > result = new ColladaFile_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic ColladaFile_obj::get_asset( ){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","get_asset",0x0a6d9fb1,"haxor.io.file.ColladaFile.get_asset","haxor/io/file/ColladaFile.hx",151,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(150)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(152)
	Array< ::Dynamic > re = Array_obj< ::Dynamic >::__new().Add(::haxor::core::Entity_obj::__new(null()));		HX_STACK_VAR(re,"re");
	HX_STACK_LINE(153)
	re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(HX_CSTRING("collada_asset"));
	HX_STACK_LINE(154)
	if (((this->scene == null()))){
		HX_STACK_LINE(156)
		::haxor::core::Console_obj::LogError(HX_CSTRING("ColladaFile> Trying to get asset of NULL scene."),null());
		HX_STACK_LINE(157)
		return re->__get((int)0).StaticCast< ::haxor::core::Entity >();
	}
	HX_STACK_LINE(160)
	if (((this->scene->name != HX_CSTRING("")))){
		HX_STACK_LINE(160)
		re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(this->scene->name);
	}
	else{
		HX_STACK_LINE(161)
		if (((this->scene->id != HX_CSTRING("")))){
			HX_STACK_LINE(161)
			re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(this->scene->id);
		}
	}
	HX_STACK_LINE(163)
	Array< ::Dynamic > hm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(hm,"hm");
	HX_STACK_LINE(164)
	Array< ::Dynamic > cm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(cm,"cm");
	HX_STACK_LINE(165)
	Array< ::Dynamic > mm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(mm,"mm");
	HX_STACK_LINE(167)
	Array< ::Dynamic > joint_transforms = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(joint_transforms,"joint_transforms");
	HX_STACK_LINE(168)
	Array< ::Dynamic > joint_nodes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(joint_nodes,"joint_nodes");
	HX_STACK_LINE(169)
	Array< ::Dynamic > skinned_meshes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(skinned_meshes,"skinned_meshes");
	HX_STACK_LINE(171)
	{
		HX_STACK_LINE(171)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(171)
		int _g = this->materials->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(171)
		while((true)){
			HX_STACK_LINE(171)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(171)
				break;
			}
			HX_STACK_LINE(171)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(173)
			::haxor::io::file::ColladaMaterial m = this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(175)
			::String mn = m->name;		HX_STACK_VAR(mn,"mn");
			HX_STACK_LINE(176)
			{
				HX_STACK_LINE(176)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(176)
				while((true)){
					HX_STACK_LINE(176)
					if ((!(((_g2 < (int)10))))){
						HX_STACK_LINE(176)
						break;
					}
					HX_STACK_LINE(176)
					int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(176)
					::String _g4 = ::StringTools_obj::replace(mn,(HX_CSTRING("_") + i1),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(176)
					mn = _g4;
				}
			}
			HX_STACK_LINE(177)
			::String _g11 = ::StringTools_obj::replace(mn,HX_CSTRING("_"),HX_CSTRING("/"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(177)
			mn = _g11;
			HX_STACK_LINE(178)
			::haxor::graphics::material::Material mat = ::haxor::core::Asset_obj::Get(mn);		HX_STACK_VAR(mat,"mat");
			HX_STACK_LINE(180)
			if (((mat == null()))){
				HX_STACK_LINE(182)
				::haxor::graphics::material::Material _g2 = ::haxor::graphics::material::Material_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(182)
				mat = _g2;
				HX_STACK_LINE(183)
				mat->set_name(mn);
				HX_STACK_LINE(184)
				::haxor::graphics::material::Shader _g4;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(184)
				if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
					HX_STACK_LINE(184)
					::haxor::graphics::material::Shader _g31 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(184)
					_g4 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g31;
				}
				else{
					HX_STACK_LINE(184)
					_g4 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
				}
				HX_STACK_LINE(184)
				mat->set_shader(_g4);
				HX_STACK_LINE(185)
				::haxor::core::Asset_obj::Add(mn,mat);
			}
			HX_STACK_LINE(187)
			mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(m,mat);
		}
	}

	HX_BEGIN_LOCAL_FUNC_S8(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,joint_nodes,Array< ::Dynamic >,skinned_meshes,Array< ::Dynamic >,hm,Array< ::Dynamic >,re,Array< ::Dynamic >,joint_transforms,Array< ::Dynamic >,cm,Array< ::Dynamic >,_g3,Array< ::Dynamic >,mm)
	Void run(::haxor::io::file::ColladaNode n){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/io/file/ColladaFile.hx",191,0xa1888587)
		HX_STACK_ARG(n,"n")
		{
			HX_STACK_LINE(192)
			::haxor::core::Entity pe;		HX_STACK_VAR(pe,"pe");
			HX_STACK_LINE(192)
			if (((n->parent == null()))){
				HX_STACK_LINE(192)
				pe = re->__get((int)0).StaticCast< ::haxor::core::Entity >();
			}
			else{
				struct _Function_3_1{
					inline static bool Block( Array< ::Dynamic > &hm,::haxor::io::file::ColladaNode &n){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",192,0xa1888587)
						{
							HX_STACK_LINE(192)
							int _g = ::__hxcpp_obj_id(n->parent);		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(192)
							return hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g);
						}
						return null();
					}
				};
				HX_STACK_LINE(192)
				if ((_Function_3_1::Block(hm,n))){
					HX_STACK_LINE(192)
					pe = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(n->parent);
				}
				else{
					HX_STACK_LINE(192)
					pe = re->__get((int)0).StaticCast< ::haxor::core::Entity >();
				}
			}
			HX_STACK_LINE(193)
			::haxor::core::Entity ne = null();		HX_STACK_VAR(ne,"ne");
			HX_STACK_LINE(194)
			if (((n->name == HX_CSTRING("EnvironmentAmbientLight")))){
				HX_STACK_LINE(194)
				return null();
			}
			HX_STACK_LINE(195)
			ne = ::haxor::core::Entity_obj::__new(null());
			HX_STACK_LINE(196)
			ne->set_name((HX_CSTRING("node") + ne->get_uid()));
			HX_STACK_LINE(197)
			if (((n->sid != HX_CSTRING("")))){
				HX_STACK_LINE(197)
				ne->set_name(n->sid);
			}
			else{
				HX_STACK_LINE(198)
				if (((n->id != HX_CSTRING("")))){
					HX_STACK_LINE(198)
					ne->set_name(n->id);
				}
				else{
					HX_STACK_LINE(199)
					if (((n->name != HX_CSTRING("")))){
						HX_STACK_LINE(199)
						ne->set_name(n->name);
					}
				}
			}
			HX_STACK_LINE(200)
			if (((n->type == HX_CSTRING("joint")))){
				HX_STACK_LINE(202)
				joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(ne->m_transform);
				HX_STACK_LINE(203)
				joint_nodes->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(n);
			}
			HX_STACK_LINE(205)
			ne->m_transform->set_parent(pe->m_transform);
			HX_STACK_LINE(206)
			ne->m_transform->set_localPosition(n->position);
			HX_STACK_LINE(207)
			ne->m_transform->set_localRotation(n->rotation);
			HX_STACK_LINE(208)
			ne->m_transform->set_localScale(n->scale);
			HX_STACK_LINE(210)
			if (((n->data != HX_CSTRING("")))){
				HX_STACK_LINE(212)
				::haxor::component::DataComponent ad = ne->AddComponent(hx::ClassOf< ::haxor::component::DataComponent >());		HX_STACK_VAR(ad,"ad");
				HX_STACK_LINE(213)
				try
				{
				HX_STACK_CATCHABLE(Dynamic, 0);
				{
					HX_STACK_LINE(215)
					ad->data = ::haxe::format::JsonParser_obj::__new(n->data)->parseRec();
				}
				}
				catch(Dynamic __e){
					{
						HX_STACK_BEGIN_CATCH
						Dynamic err = __e;{
						}
					}
				}
			}
			HX_STACK_LINE(270)
			hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(n,ne);
			HX_STACK_LINE(271)
			{
				HX_STACK_LINE(271)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(271)
				int _g = n->instances->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(271)
				while(((_g1 < _g))){
					HX_STACK_LINE(271)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(273)
					::haxor::io::file::ColladaInstance ci = n->instances->__get(i).StaticCast< ::haxor::io::file::ColladaInstance >();		HX_STACK_VAR(ci,"ci");
					HX_STACK_LINE(274)
					::haxor::component::MeshRenderer mr = null();		HX_STACK_VAR(mr,"mr");
					HX_STACK_LINE(275)
					::haxor::io::file::ColladaMaterial cmat = null();		HX_STACK_VAR(cmat,"cmat");
					HX_STACK_LINE(276)
					::haxor::io::file::ColladaGeometry cg = null();		HX_STACK_VAR(cg,"cg");
					HX_STACK_LINE(277)
					::haxor::io::file::ColladaController cc = null();		HX_STACK_VAR(cc,"cc");
					HX_STACK_LINE(278)
					::String cg_target = HX_CSTRING("");		HX_STACK_VAR(cg_target,"cg_target");
					HX_STACK_LINE(280)
					{
						HX_STACK_LINE(280)
						::String _g2 = ci->type;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(280)
						::String _switch_1 = (_g2);
						if (  ( _switch_1==HX_CSTRING("light"))){
							HX_STACK_LINE(284)
							::haxor::io::file::ColladaLight cl = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindLightById(ci->target);		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(286)
							if (((cl == null()))){
								HX_STACK_LINE(286)
								continue;
							}
							HX_STACK_LINE(288)
							{
								HX_STACK_LINE(288)
								::String _g4 = cl->type;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(288)
								::String _switch_2 = (_g4);
								if (  ( _switch_2==HX_CSTRING("ambient"))){
								}
								else if (  ( _switch_2==HX_CSTRING("point"))){
									HX_STACK_LINE(292)
									::haxor::component::light::PointLight pl = ne->AddComponent(hx::ClassOf< ::haxor::component::light::PointLight >());		HX_STACK_VAR(pl,"pl");
									HX_STACK_LINE(293)
									pl->color->SetColor(cl->color);
									HX_STACK_LINE(294)
									pl->intensity = cl->intensity;
									HX_STACK_LINE(295)
									pl->radius = (cl->radius * 2.0);
									HX_STACK_LINE(296)
									pl->atten = cl->atten;
								}
								else if (  ( _switch_2==HX_CSTRING("directional"))){
								}
							}
							HX_STACK_LINE(304)
							continue;
						}
						else if (  ( _switch_1==HX_CSTRING("geometry"))){
							HX_STACK_LINE(307)
							cg_target = ci->target;
						}
						else if (  ( _switch_1==HX_CSTRING("controller"))){
							HX_STACK_LINE(309)
							cc = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindControllerById(ci->target);
							HX_STACK_LINE(310)
							if (((cc != null()))){
								HX_STACK_LINE(312)
								cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(ne->m_transform,cc);
								HX_STACK_LINE(313)
								cg_target = cc->source;
							}
						}
					}
					HX_STACK_LINE(319)
					cg = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindGeometryById(cg_target);
					HX_STACK_LINE(320)
					if (((cg != null()))){
						HX_STACK_LINE(322)
						int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(322)
						int _g2 = cg->mesh->primitives->length;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(322)
						while(((_g4 < _g2))){
							HX_STACK_LINE(322)
							int i1 = (_g4)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(324)
							::String mn = cg->mesh->primitives->__get(i1).StaticCast< ::haxor::io::file::ColladaPrimitive >()->material;		HX_STACK_VAR(mn,"mn");
							HX_STACK_LINE(325)
							cmat = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindMaterialById(mn);
							HX_STACK_LINE(327)
							mr = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->CreateMeshRenderer(ne,cg_target,cg->mesh->primitives->__get(i1).StaticCast< ::haxor::io::file::ColladaPrimitive >(),(  (((cc == null()))) ? ::Class(hx::ClassOf< ::haxor::component::MeshRenderer >()) : ::Class(hx::ClassOf< ::haxor::component::SkinnedMeshRenderer >()) ),cc);
							HX_STACK_LINE(329)
							if (((cc != null()))){
								HX_STACK_LINE(329)
								skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(mr);
							}
							HX_STACK_LINE(330)
							if (((cmat != null()))){
								struct _Function_7_1{
									inline static bool Block( ::haxor::io::file::ColladaMaterial &cmat,Array< ::Dynamic > &mm){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",332,0xa1888587)
										{
											HX_STACK_LINE(332)
											int _g5 = ::__hxcpp_obj_id(cmat);		HX_STACK_VAR(_g5,"_g5");
											HX_STACK_LINE(332)
											return mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g5);
										}
										return null();
									}
								};
								HX_STACK_LINE(332)
								mr->set_material((  ((_Function_7_1::Block(cmat,mm))) ? ::haxor::graphics::material::Material(mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(cmat)) : ::haxor::graphics::material::Material(mr->m_material) ));
							}
							else{
								HX_STACK_LINE(336)
								{
									HX_STACK_LINE(336)
									int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
									HX_STACK_LINE(336)
									while(((_g5 < (int)10))){
										HX_STACK_LINE(336)
										int i2 = (_g5)++;		HX_STACK_VAR(i2,"i2");
										HX_STACK_LINE(336)
										mn = ::StringTools_obj::replace(mn,(HX_CSTRING("_") + i2),HX_CSTRING(""));
									}
								}
								HX_STACK_LINE(337)
								mn = ::StringTools_obj::replace(mn,HX_CSTRING("_"),HX_CSTRING("/"));
								HX_STACK_LINE(338)
								::haxor::graphics::material::Material mat = ::haxor::core::Asset_obj::Get(mn);		HX_STACK_VAR(mat,"mat");
								HX_STACK_LINE(339)
								mr->set_material(mat);
							}
						}
					}
				}
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(190)
	this->scene->Traverse( Dynamic(new _Function_1_1(joint_nodes,skinned_meshes,hm,re,joint_transforms,cm,_g3,mm)));
	HX_STACK_LINE(346)
	{
		HX_STACK_LINE(346)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(346)
		int _g = skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(346)
		while((true)){
			HX_STACK_LINE(346)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(346)
				break;
			}
			HX_STACK_LINE(346)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(348)
			::haxor::component::SkinnedMeshRenderer skr = skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(i).StaticCast< ::haxor::component::SkinnedMeshRenderer >();		HX_STACK_VAR(skr,"skr");
			HX_STACK_LINE(349)
			::haxor::io::file::ColladaController cc;		HX_STACK_VAR(cc,"cc");
			struct _Function_3_1{
				inline static bool Block( ::haxor::component::SkinnedMeshRenderer &skr,Array< ::Dynamic > &cm){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",349,0xa1888587)
					{
						HX_STACK_LINE(349)
						int _g2 = ::__hxcpp_obj_id(skr->m_entity->m_transform);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(349)
						return cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g2);
					}
					return null();
				}
			};
			HX_STACK_LINE(349)
			if ((_Function_3_1::Block(skr,cm))){
				HX_STACK_LINE(349)
				cc = cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(skr->m_entity->m_transform);
			}
			else{
				HX_STACK_LINE(349)
				cc = null();
			}
			HX_STACK_LINE(350)
			if (((cc == null()))){
				HX_STACK_LINE(350)
				continue;
			}
			HX_STACK_LINE(351)
			skr->set_joints(Array_obj< ::Dynamic >::__new());
			HX_STACK_LINE(353)
			{
				HX_STACK_LINE(353)
				int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(353)
				int _g2 = cc->joints->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(353)
				while((true)){
					HX_STACK_LINE(353)
					if ((!(((_g31 < _g2))))){
						HX_STACK_LINE(353)
						break;
					}
					HX_STACK_LINE(353)
					int j = (_g31)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(354)
					int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(354)
					int _g4 = joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->length;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(354)
					while((true)){
						HX_STACK_LINE(354)
						if ((!(((_g5 < _g4))))){
							HX_STACK_LINE(354)
							break;
						}
						HX_STACK_LINE(354)
						int k = (_g5)++;		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(356)
						::String _g51 = joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(k).StaticCast< ::haxor::component::Transform >()->get_name();		HX_STACK_VAR(_g51,"_g51");
						HX_STACK_LINE(356)
						if (((_g51 == cc->joints->__get(j)))){
							HX_STACK_LINE(360)
							skr->m_joints->push(joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(k).StaticCast< ::haxor::component::Transform >());
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(366)
	Dynamic nit = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->keys();		HX_STACK_VAR(nit,"nit");
	HX_STACK_LINE(367)
	while((true)){
		HX_STACK_LINE(367)
		if ((!(nit->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(367)
			break;
		}
		HX_STACK_LINE(369)
		::haxor::io::file::ColladaNode n = nit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(370)
		::haxor::core::Entity e = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(n);		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(371)
		if (((e == re->__get((int)0).StaticCast< ::haxor::core::Entity >()))){
			HX_STACK_LINE(371)
			continue;
		}
		HX_STACK_LINE(372)
		e->set_name(n->name);
	}
	HX_STACK_LINE(374)
	this->AddAnimations(re->__get((int)0).StaticCast< ::haxor::core::Entity >(),null());
	HX_STACK_LINE(375)
	if (((this->data->axis == HX_CSTRING("z_up")))){
		HX_STACK_LINE(377)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(377)
		::haxor::math::Quaternion _g7 = ::haxor::math::Quaternion_obj::FromAxisAngle(_g6,-90.0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(377)
		re->__get((int)0).StaticCast< ::haxor::core::Entity >()->m_transform->set_rotation(_g7);
	}
	HX_STACK_LINE(379)
	return re->__get((int)0).StaticCast< ::haxor::core::Entity >();
}


Void ColladaFile_obj::AddAnimations( ::haxor::core::Entity p_entity,hx::Null< bool >  __o_p_exact){
bool p_exact = __o_p_exact.Default(false);
	HX_STACK_FRAME("haxor.io.file.ColladaFile","AddAnimations",0xdf3aa4ba,"haxor.io.file.ColladaFile.AddAnimations","haxor/io/file/ColladaFile.hx",389,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_entity,"p_entity")
	HX_STACK_ARG(p_exact,"p_exact")
{
		HX_STACK_LINE(390)
		if (((this->animations->length <= (int)0))){
			HX_STACK_LINE(390)
			return null();
		}
		HX_STACK_LINE(391)
		::haxor::core::Entity re = p_entity;		HX_STACK_VAR(re,"re");
		HX_STACK_LINE(392)
		::haxor::component::animation::Animation a = re->get_animation();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(393)
		if (((a == null()))){
			HX_STACK_LINE(393)
			::haxor::component::animation::Animation _g = re->AddComponent(hx::ClassOf< ::haxor::component::animation::Animation >());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(393)
			a = _g;
		}
		HX_STACK_LINE(395)
		{
			HX_STACK_LINE(395)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(395)
			int _g = this->animations->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(395)
			while((true)){
				HX_STACK_LINE(395)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(395)
					break;
				}
				HX_STACK_LINE(395)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(397)
				::haxor::io::file::ColladaAnimation ca = this->animations->__get(i).StaticCast< ::haxor::io::file::ColladaAnimation >();		HX_STACK_VAR(ca,"ca");
				HX_STACK_LINE(398)
				::haxor::component::animation::AnimationClip clip = ::haxor::component::animation::AnimationClip_obj::__new();		HX_STACK_VAR(clip,"clip");
				struct _Function_3_1{
					inline static ::String Block( int &i,::haxor::io::file::ColladaAnimation &ca){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",399,0xa1888587)
						{
							HX_STACK_LINE(399)
							return (  (((ca->name == HX_CSTRING("")))) ? ::String((HX_CSTRING("clip") + i)) : ::String(ca->name) );
						}
						return null();
					}
				};
				HX_STACK_LINE(399)
				clip->set_name((  (((ca->id == HX_CSTRING("")))) ? ::String(_Function_3_1::Block(i,ca)) : ::String(ca->id) ));
				HX_STACK_LINE(401)
				{
					HX_STACK_LINE(401)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(401)
					int _g2 = ca->channels->length;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(401)
					while((true)){
						HX_STACK_LINE(401)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(401)
							break;
						}
						HX_STACK_LINE(401)
						int j = (_g3)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(403)
						::haxor::io::file::ColladaAnimationChannel cch = ca->channels->__get(j).StaticCast< ::haxor::io::file::ColladaAnimationChannel >();		HX_STACK_VAR(cch,"cch");
						HX_STACK_LINE(404)
						Array< ::String > _g11 = cch->target.split(HX_CSTRING("/"));		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(404)
						::String src_node = _g11->__get((int)0);		HX_STACK_VAR(src_node,"src_node");
						HX_STACK_LINE(405)
						Array< ::String > _g21 = cch->target.split(HX_CSTRING("/"));		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(405)
						::String src_target = _g21->__get((int)1);		HX_STACK_VAR(src_target,"src_target");
						HX_STACK_LINE(407)
						::String _g31 = ::StringTools_obj::replace(src_node,HX_CSTRING("node-"),HX_CSTRING(""));		HX_STACK_VAR(_g31,"_g31");
						HX_STACK_LINE(407)
						src_node = _g31;
						HX_STACK_LINE(409)
						::haxor::component::Transform nt = re->m_transform->Search(src_node,p_exact);		HX_STACK_VAR(nt,"nt");
						HX_STACK_LINE(413)
						if (((nt == null()))){
							HX_STACK_LINE(413)
							continue;
						}
						HX_STACK_LINE(415)
						::haxor::core::Entity n = nt->m_entity;		HX_STACK_VAR(n,"n");
						HX_STACK_LINE(418)
						::String _switch_3 = (src_target);
						if (  ( _switch_3==HX_CSTRING("matrix"))){
							HX_STACK_LINE(421)
							::haxor::component::animation::ClipTrack position_track = clip->Add(n->m_transform,HX_CSTRING("localPosition"));		HX_STACK_VAR(position_track,"position_track");
							HX_STACK_LINE(422)
							::haxor::component::animation::ClipTrack rotation_track = clip->Add(n->m_transform,HX_CSTRING("localRotation"));		HX_STACK_VAR(rotation_track,"rotation_track");
							HX_STACK_LINE(423)
							::haxor::component::animation::ClipTrack scale_track = clip->Add(n->m_transform,HX_CSTRING("localScale"));		HX_STACK_VAR(scale_track,"scale_track");
							HX_STACK_LINE(424)
							::haxor::math::Matrix4 tmpm0;		HX_STACK_VAR(tmpm0,"tmpm0");
							HX_STACK_LINE(424)
							{
								HX_STACK_LINE(424)
								::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(424)
								int _g4 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(424)
								tmpm0 = _this->m_m4->__get(_g4).StaticCast< ::haxor::math::Matrix4 >();
							}
							HX_STACK_LINE(425)
							::haxor::math::Matrix4 tmpm1;		HX_STACK_VAR(tmpm1,"tmpm1");
							HX_STACK_LINE(425)
							{
								HX_STACK_LINE(425)
								::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(425)
								int _g5 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(425)
								tmpm1 = _this->m_m4->__get(_g5).StaticCast< ::haxor::math::Matrix4 >();
							}
							HX_STACK_LINE(426)
							{
								HX_STACK_LINE(426)
								int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(426)
								int _g4 = cch->keyframes->length;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(426)
								while((true)){
									HX_STACK_LINE(426)
									if ((!(((_g5 < _g4))))){
										HX_STACK_LINE(426)
										break;
									}
									HX_STACK_LINE(426)
									int k = (_g5)++;		HX_STACK_VAR(k,"k");
									HX_STACK_LINE(428)
									::haxor::io::file::ColladaAnimationKeyFrame kf = cch->keyframes->__get(k).StaticCast< ::haxor::io::file::ColladaAnimationKeyFrame >();		HX_STACK_VAR(kf,"kf");
									HX_STACK_LINE(429)
									::haxor::math::Matrix4 m = ::haxor::math::Matrix4_obj::FromArray(kf->values,tmpm0);		HX_STACK_VAR(m,"m");
									HX_STACK_LINE(430)
									::haxor::math::Matrix4 sm = ::haxor::math::Matrix4_obj::GetScale(m,tmpm1);		HX_STACK_VAR(sm,"sm");
									struct _Function_8_1{
										inline static ::haxor::math::Vector3 Block( ){
											HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",431,0xa1888587)
											{
												HX_STACK_LINE(431)
												::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(431)
												int _g6 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g6,"_g6");
												HX_STACK_LINE(431)
												return _this->m_v3->__get(_g6).StaticCast< ::haxor::math::Vector3 >();
											}
											return null();
										}
									};
									HX_STACK_LINE(431)
									::haxor::math::Vector3 pos = (_Function_8_1::Block())->Set(m->m03,m->m13,m->m23);		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(432)
									::haxor::math::Quaternion _g8;		HX_STACK_VAR(_g8,"_g8");
									HX_STACK_LINE(432)
									{
										HX_STACK_LINE(432)
										::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
										HX_STACK_LINE(432)
										int _g7 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g7,"_g7");
										HX_STACK_LINE(432)
										_g8 = _this->m_q->__get(_g7).StaticCast< ::haxor::math::Quaternion >();
									}
									HX_STACK_LINE(432)
									::haxor::math::Quaternion rot = ::haxor::math::Quaternion_obj::FromMatrix4(m,_g8);		HX_STACK_VAR(rot,"rot");
									struct _Function_8_2{
										inline static ::haxor::math::Vector3 Block( ){
											HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",433,0xa1888587)
											{
												HX_STACK_LINE(433)
												::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
												HX_STACK_LINE(433)
												int _g9 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g9,"_g9");
												HX_STACK_LINE(433)
												return _this->m_v3->__get(_g9).StaticCast< ::haxor::math::Vector3 >();
											}
											return null();
										}
									};
									HX_STACK_LINE(433)
									::haxor::math::Vector3 scl = (_Function_8_2::Block())->Set(sm->m00,sm->m11,sm->m22);		HX_STACK_VAR(scl,"scl");
									HX_STACK_LINE(434)
									position_track->Add(kf->time,pos);
									HX_STACK_LINE(435)
									rotation_track->Add(kf->time,rot);
									HX_STACK_LINE(436)
									scale_track->Add(kf->time,scl);
								}
							}
						}
					}
				}
				HX_STACK_LINE(442)
				a->Add(clip);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,AddAnimations,(void))

::haxor::component::MeshRenderer ColladaFile_obj::CreateMeshRenderer( ::haxor::core::Entity e,::String msh,::haxor::io::file::ColladaPrimitive cp,::Class t,::haxor::io::file::ColladaController cc){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","CreateMeshRenderer",0xe09e0ae2,"haxor.io.file.ColladaFile.CreateMeshRenderer","haxor/io/file/ColladaFile.hx",448,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(e,"e")
	HX_STACK_ARG(msh,"msh")
	HX_STACK_ARG(cp,"cp")
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(cc,"cc")
	HX_STACK_LINE(449)
	::haxor::component::MeshRenderer r = e->AddComponent(t);		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(451)
	::String mid = ((msh + HX_CSTRING("_")) + this->m_id);		HX_STACK_VAR(mid,"mid");
	HX_STACK_LINE(453)
	::haxor::graphics::mesh::Mesh3 m = ::haxor::core::Asset_obj::Get(mid);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(455)
	if (((m != null()))){
		HX_STACK_LINE(457)
		r->set_mesh(m);
		HX_STACK_LINE(458)
		return r;
	}
	HX_STACK_LINE(461)
	Array< ::Dynamic > mv = cp->GetTriangulatedVectorArray(HX_CSTRING("vertex"),null(),null());		HX_STACK_VAR(mv,"mv");
	HX_STACK_LINE(462)
	Array< ::Dynamic > mn = cp->GetTriangulatedVectorArray(HX_CSTRING("normal"),null(),null());		HX_STACK_VAR(mn,"mn");
	HX_STACK_LINE(463)
	Array< ::Dynamic > mc = cp->GetTriangulatedVectorArray(HX_CSTRING("color"),null(),null());		HX_STACK_VAR(mc,"mc");
	HX_STACK_LINE(464)
	Array< ::Dynamic > muv0 = cp->GetTriangulatedVectorArray(HX_CSTRING("texcoord"),(int)0,null());		HX_STACK_VAR(muv0,"muv0");
	HX_STACK_LINE(465)
	Array< ::Dynamic > muv1 = cp->GetTriangulatedVectorArray(HX_CSTRING("texcoord"),(int)1,null());		HX_STACK_VAR(muv1,"muv1");
	HX_STACK_LINE(466)
	Array< ::Dynamic > mbn = cp->GetTriangulatedVectorArray(HX_CSTRING("texbinormal"),null(),null());		HX_STACK_VAR(mbn,"mbn");
	HX_STACK_LINE(467)
	Array< ::Dynamic > mtg = cp->GetTriangulatedVectorArray(HX_CSTRING("textangent"),null(),null());		HX_STACK_VAR(mtg,"mtg");
	HX_STACK_LINE(469)
	bool is_skinned = ::Std_obj::is(r,hx::ClassOf< ::haxor::component::SkinnedMeshRenderer >());		HX_STACK_VAR(is_skinned,"is_skinned");
	HX_STACK_LINE(471)
	::haxor::graphics::mesh::Mesh3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(471)
	if ((is_skinned)){
		HX_STACK_LINE(471)
		_g = ::haxor::graphics::mesh::SkinnedMesh3_obj::__new(null());
	}
	else{
		HX_STACK_LINE(471)
		_g = ::haxor::graphics::mesh::Mesh3_obj::__new(null());
	}
	HX_STACK_LINE(471)
	m = _g;
	HX_STACK_LINE(472)
	m->set_name(mid);
	HX_STACK_LINE(474)
	::haxor::core::Asset_obj::Add(mid,m);
	HX_STACK_LINE(476)
	if (((mc->length > (int)0))){
		HX_STACK_LINE(476)
		m->set_color(mc);
	}
	HX_STACK_LINE(477)
	if (((muv0->length > (int)0))){
		HX_STACK_LINE(477)
		m->set_uv0(muv0);
	}
	HX_STACK_LINE(478)
	if (((muv1->length > (int)0))){
		HX_STACK_LINE(478)
		m->set_uv1(muv1);
	}
	HX_STACK_LINE(480)
	if ((is_skinned)){
		HX_STACK_LINE(482)
		if (((cc != null()))){
			HX_STACK_LINE(484)
			cc->GenerateBonesAndWeights();
			HX_STACK_LINE(486)
			::haxor::graphics::mesh::SkinnedMesh3 skm = m;		HX_STACK_VAR(skm,"skm");
			HX_STACK_LINE(487)
			Array< ::Dynamic > mvw = cc->GetTriangulatedWeights(cp);		HX_STACK_VAR(mvw,"mvw");
			HX_STACK_LINE(488)
			Array< ::Dynamic > mbi = cc->GetTriangulatedBones(cp);		HX_STACK_VAR(mbi,"mbi");
			HX_STACK_LINE(489)
			Array< ::Dynamic > mbm = cc->GetBinds();		HX_STACK_VAR(mbm,"mbm");
			HX_STACK_LINE(490)
			skm->set_binds(mbm);
			HX_STACK_LINE(491)
			skm->set_weight(mvw);
			HX_STACK_LINE(492)
			skm->set_bone(mbi);
			HX_STACK_LINE(493)
			::haxor::math::Matrix4 bsm = cc->GetBSM();		HX_STACK_VAR(bsm,"bsm");
			HX_STACK_LINE(494)
			{
				HX_STACK_LINE(494)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(494)
				int _g2 = mv->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(494)
				while((true)){
					HX_STACK_LINE(494)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(494)
						break;
					}
					HX_STACK_LINE(494)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(494)
					{
						HX_STACK_LINE(494)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(494)
						{
							HX_STACK_LINE(494)
							::haxor::math::Vector3 _this = mv->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(494)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(494)
						Float vx = ((((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z)) + bsm->m03);		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(494)
						Float vy = ((((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z)) + bsm->m13);		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(494)
						Float vz = ((((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z)) + bsm->m23);		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(494)
						p_point->x = vx;
						HX_STACK_LINE(494)
						p_point->y = vy;
						HX_STACK_LINE(494)
						p_point->z = vz;
						HX_STACK_LINE(494)
						mv[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(495)
			{
				HX_STACK_LINE(495)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(495)
				int _g2 = mn->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(495)
				while((true)){
					HX_STACK_LINE(495)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(495)
						break;
					}
					HX_STACK_LINE(495)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(495)
					{
						HX_STACK_LINE(495)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(495)
						{
							HX_STACK_LINE(495)
							::haxor::math::Vector3 _this = mn->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(495)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(495)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(495)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(495)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(495)
						p_point->x = vx;
						HX_STACK_LINE(495)
						p_point->y = vy;
						HX_STACK_LINE(495)
						p_point->z = vz;
						HX_STACK_LINE(495)
						mn[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(496)
			{
				HX_STACK_LINE(496)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(496)
				int _g2 = mbn->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(496)
				while((true)){
					HX_STACK_LINE(496)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(496)
						break;
					}
					HX_STACK_LINE(496)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(496)
					{
						HX_STACK_LINE(496)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(496)
						{
							HX_STACK_LINE(496)
							::haxor::math::Vector3 _this = mbn->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(496)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(496)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(496)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(496)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(496)
						p_point->x = vx;
						HX_STACK_LINE(496)
						p_point->y = vy;
						HX_STACK_LINE(496)
						p_point->z = vz;
						HX_STACK_LINE(496)
						mbn[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(497)
			{
				HX_STACK_LINE(497)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(497)
				int _g2 = mtg->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(497)
				while((true)){
					HX_STACK_LINE(497)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(497)
						break;
					}
					HX_STACK_LINE(497)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(497)
					{
						HX_STACK_LINE(497)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(497)
						{
							HX_STACK_LINE(497)
							::haxor::math::Vector3 _this = mtg->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(497)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(497)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(497)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(497)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(497)
						p_point->x = vx;
						HX_STACK_LINE(497)
						p_point->y = vy;
						HX_STACK_LINE(497)
						p_point->z = vz;
						HX_STACK_LINE(497)
						mtg[i] = p_point;
					}
				}
			}
		}
	}
	HX_STACK_LINE(501)
	if (((mv->length > (int)0))){
		HX_STACK_LINE(501)
		m->set_vertex(mv);
	}
	HX_STACK_LINE(502)
	if (((mn->length > (int)0))){
		HX_STACK_LINE(502)
		m->set_normal(mn);
	}
	HX_STACK_LINE(503)
	if (((mbn->length > (int)0))){
		HX_STACK_LINE(503)
		m->set_binormal(mbn);
	}
	HX_STACK_LINE(504)
	if (((mtg->length > (int)0))){
		HX_STACK_LINE(504)
		m->set_tangent(mtg);
	}
	HX_STACK_LINE(508)
	m->GenerateBounds();
	HX_STACK_LINE(509)
	r->set_mesh(m);
	HX_STACK_LINE(510)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC5(ColladaFile_obj,CreateMeshRenderer,return )

::haxor::io::file::ColladaLight ColladaFile_obj::FindLightById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindLightById",0x8cc7c059,"haxor.io.file.ColladaFile.FindLightById","haxor/io/file/ColladaFile.hx",513,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(513)
	{
		HX_STACK_LINE(513)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(513)
		int _g = this->lights->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(513)
		while((true)){
			HX_STACK_LINE(513)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(513)
				break;
			}
			HX_STACK_LINE(513)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(513)
			if (((this->lights->__get(i).StaticCast< ::haxor::io::file::ColladaLight >()->id == p_id))){
				HX_STACK_LINE(513)
				return this->lights->__get(i).StaticCast< ::haxor::io::file::ColladaLight >();
			}
		}
	}
	HX_STACK_LINE(513)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindLightById,return )

::haxor::io::file::ColladaGeometry ColladaFile_obj::FindGeometryById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindGeometryById",0xe813db33,"haxor.io.file.ColladaFile.FindGeometryById","haxor/io/file/ColladaFile.hx",515,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(515)
	{
		HX_STACK_LINE(515)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(515)
		int _g = this->geometries->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(515)
		while((true)){
			HX_STACK_LINE(515)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(515)
				break;
			}
			HX_STACK_LINE(515)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(515)
			if (((this->geometries->__get(i).StaticCast< ::haxor::io::file::ColladaGeometry >()->id == p_id))){
				HX_STACK_LINE(515)
				return this->geometries->__get(i).StaticCast< ::haxor::io::file::ColladaGeometry >();
			}
		}
	}
	HX_STACK_LINE(515)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindGeometryById,return )

::haxor::io::file::ColladaController ColladaFile_obj::FindControllerById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindControllerById",0x0fb6ffdd,"haxor.io.file.ColladaFile.FindControllerById","haxor/io/file/ColladaFile.hx",517,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(517)
	{
		HX_STACK_LINE(517)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(517)
		int _g = this->controllers->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(517)
		while((true)){
			HX_STACK_LINE(517)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(517)
				break;
			}
			HX_STACK_LINE(517)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(517)
			if (((this->controllers->__get(i).StaticCast< ::haxor::io::file::ColladaController >()->id == p_id))){
				HX_STACK_LINE(517)
				return this->controllers->__get(i).StaticCast< ::haxor::io::file::ColladaController >();
			}
		}
	}
	HX_STACK_LINE(517)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindControllerById,return )

::haxor::io::file::ColladaNode ColladaFile_obj::FindNodeById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindNodeById",0x2743f703,"haxor.io.file.ColladaFile.FindNodeById","haxor/io/file/ColladaFile.hx",519,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(519)
	Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");
	HX_STACK_LINE(521)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new().Add(null());		HX_STACK_VAR(res,"res");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,res,Array< ::String >,p_id1)
	Void run(::haxor::io::file::ColladaNode it){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/io/file/ColladaFile.hx",524,0xa1888587)
		HX_STACK_ARG(it,"it")
		{
			HX_STACK_LINE(524)
			if (((it->id == p_id1->__get((int)0)))){
				HX_STACK_LINE(524)
				res[(int)0] = it;
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(522)
	this->scene->Traverse( Dynamic(new _Function_1_1(res,p_id1)));
	HX_STACK_LINE(526)
	return res->__get((int)0).StaticCast< ::haxor::io::file::ColladaNode >();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindNodeById,return )

::haxor::io::file::ColladaMaterial ColladaFile_obj::FindMaterialById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindMaterialById",0x6edcd3a8,"haxor.io.file.ColladaFile.FindMaterialById","haxor/io/file/ColladaFile.hx",530,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(531)
	{
		HX_STACK_LINE(531)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(531)
		int _g = this->materials->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(531)
		while((true)){
			HX_STACK_LINE(531)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(531)
				break;
			}
			HX_STACK_LINE(531)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(533)
			if (((this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >()->id == p_id))){
				HX_STACK_LINE(533)
				return this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();
			}
			else{
				HX_STACK_LINE(535)
				if (((this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >()->name == p_id))){
					HX_STACK_LINE(535)
					return this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();
				}
			}
		}
	}
	HX_STACK_LINE(537)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindMaterialById,return )

Void ColladaFile_obj::Parse( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","Parse",0xf5b65c7d,"haxor.io.file.ColladaFile.Parse","haxor/io/file/ColladaFile.hx",542,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(542)
		::String _g = n->get_nodeName();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(542)
		::String _switch_4 = (_g);
		if (  ( _switch_4==HX_CSTRING("COLLADA"))){
			HX_STACK_LINE(545)
			::String _g1 = this->_a(n,HX_CSTRING("xmlns"),HX_CSTRING(""));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(545)
			this->xmlns = _g1;
			HX_STACK_LINE(546)
			::String _g11 = this->_a(n,HX_CSTRING("version"),HX_CSTRING("0.0"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(546)
			this->version = _g11;
		}
		else if (  ( _switch_4==HX_CSTRING("asset"))){
			HX_STACK_LINE(549)
			Dynamic _g2 = this->_p(n,HX_CSTRING("contributor.author.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(549)
			this->data->author = _g2;
			HX_STACK_LINE(550)
			Dynamic _g3 = this->_p(n,HX_CSTRING("contributor.authoring_tool.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(550)
			this->data->tool = _g3;
			HX_STACK_LINE(551)
			Dynamic _g4 = this->_p(n,HX_CSTRING("contributor.source_data.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(551)
			this->data->source = _g4;
			HX_STACK_LINE(552)
			Dynamic _g5 = this->_p(n,HX_CSTRING("up_axis.$text"),HX_CSTRING("y_up"),null(),null())->__Field(HX_CSTRING("toLowerCase"),true)();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(552)
			this->data->axis = _g5;
			HX_STACK_LINE(553)
			Dynamic _g6 = this->_p(n,HX_CSTRING("created.$text"),HX_CSTRING("00/00/00"),null(),null());		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(553)
			this->data->creation = _g6;
			HX_STACK_LINE(554)
			Dynamic _g7 = this->_p(n,HX_CSTRING("modified.$text"),HX_CSTRING("00/00/00"),null(),null());		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(554)
			this->data->modification = _g7;
			HX_STACK_LINE(555)
			Dynamic _g8 = this->_p(n,HX_CSTRING("unit.@name"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(555)
			this->data->unitName = _g8;
			HX_STACK_LINE(556)
			Dynamic _g9 = this->_p(n,HX_CSTRING("unit.@meter"),HX_CSTRING("0.0"),null(),null());		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(556)
			Float _g10 = ::Std_obj::parseFloat(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(556)
			this->data->unitValue = _g10;
		}
		else if (  ( _switch_4==HX_CSTRING("library_effects"))){
		}
		else if (  ( _switch_4==HX_CSTRING("library_materials"))){
			HX_STACK_LINE(559)
			this->ParseMaterialLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("scene"))){
		}
		else if (  ( _switch_4==HX_CSTRING("library_geometries"))){
			HX_STACK_LINE(562)
			this->ParseGeometryLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("library_controllers"))){
			HX_STACK_LINE(563)
			this->ParseControllerLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("library_images"))){
			HX_STACK_LINE(564)
			this->ParseImageLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("library_visual_scenes"))){
			HX_STACK_LINE(565)
			this->ParseSceneLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("library_animations"))){
			HX_STACK_LINE(566)
			this->ParseAnimationLibrary(n);
		}
		else if (  ( _switch_4==HX_CSTRING("library_lights"))){
			HX_STACK_LINE(567)
			this->ParseLightLibrary(n);
		}
	}
return null();
}


Void ColladaFile_obj::ParseLightLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseLightLibrary",0x528214e2,"haxor.io.file.ColladaFile.ParseLightLibrary","haxor/io/file/ColladaFile.hx",573,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(574)
		Dynamic it = n->elementsNamed(HX_CSTRING("light"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(575)
		::haxor::io::file::ColladaLight l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(576)
		Dynamic lit;		HX_STACK_VAR(lit,"lit");
		HX_STACK_LINE(577)
		::Xml ln;		HX_STACK_VAR(ln,"ln");
		HX_STACK_LINE(578)
		while((true)){
			HX_STACK_LINE(578)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(578)
				break;
			}
			HX_STACK_LINE(580)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(580)
			n = _g;
			HX_STACK_LINE(581)
			::haxor::io::file::ColladaLight _g1 = ::haxor::io::file::ColladaLight_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(581)
			l = _g1;
			HX_STACK_LINE(582)
			Dynamic _g2 = this->_p(n,HX_CSTRING("@id"),(HX_CSTRING("light") + this->lights->length),null(),null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(582)
			l->id = _g2;
			HX_STACK_LINE(583)
			Dynamic _g3 = this->_p(n,HX_CSTRING("@name"),l->id,null(),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(583)
			l->name = _g3;
			HX_STACK_LINE(585)
			this->lights->push(l);
			HX_STACK_LINE(587)
			Dynamic _g4 = n->elementsNamed(HX_CSTRING("technique_common"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(587)
			lit = _g4;
			HX_STACK_LINE(588)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(588)
				continue;
			}
			HX_STACK_LINE(588)
			Dynamic _g5 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elements"),true)();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(588)
			lit = _g5;
			HX_STACK_LINE(589)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(589)
				continue;
			}
			HX_STACK_LINE(589)
			::Xml _g6 = lit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(589)
			ln = _g6;
			HX_STACK_LINE(591)
			::String _g7 = ln->get_nodeName().toLowerCase();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(591)
			l->type = _g7;
			HX_STACK_LINE(593)
			Array< Float > ca = Array_obj< Float >::__new().Add((int)1).Add((int)1).Add((int)1).Add((int)1);		HX_STACK_VAR(ca,"ca");
			HX_STACK_LINE(594)
			{
				HX_STACK_LINE(594)
				::String _g8 = l->type;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(594)
				::String _switch_5 = (_g8);
				if (  ( _switch_5==HX_CSTRING("point"))){
					HX_STACK_LINE(596)
					Dynamic _g81 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g81,"_g81");
					HX_STACK_LINE(596)
					Array< Float > _g9 = this->_f32a(_g81);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(596)
					ca = _g9;
				}
				else if (  ( _switch_5==HX_CSTRING("ambient"))){
					HX_STACK_LINE(597)
					Dynamic _g10 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(597)
					Array< Float > _g11 = this->_f32a(_g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(597)
					ca = _g11;
				}
				else if (  ( _switch_5==HX_CSTRING("directional"))){
					HX_STACK_LINE(598)
					Dynamic _g12 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(598)
					Array< Float > _g13 = this->_f32a(_g12);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(598)
					ca = _g13;
				}
			}
			HX_STACK_LINE(601)
			l->color->Set(ca->__get((int)0),ca->__get((int)1),ca->__get((int)2),(  (((ca->length >= (int)4))) ? Float(ca->__get((int)3)) : Float(1.0) ));
			HX_STACK_LINE(603)
			Dynamic _g14 = n->elementsNamed(HX_CSTRING("extra"));		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(603)
			lit = _g14;
			HX_STACK_LINE(604)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(604)
				continue;
			}
			HX_STACK_LINE(604)
			Dynamic _g15 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elementsNamed"),true)(HX_CSTRING("technique"));		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(604)
			lit = _g15;
			HX_STACK_LINE(605)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(605)
				continue;
			}
			HX_STACK_LINE(605)
			Dynamic _g16 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elementsNamed"),true)(HX_CSTRING("max_light"));		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(605)
			lit = _g16;
			HX_STACK_LINE(606)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(606)
				continue;
			}
			HX_STACK_LINE(606)
			::Xml _g17 = lit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(606)
			ln = _g17;
			HX_STACK_LINE(608)
			{
				HX_STACK_LINE(608)
				::String _g8 = l->type;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(608)
				::String _switch_6 = (_g8);
				if (  ( _switch_6==HX_CSTRING("point"))){
					HX_STACK_LINE(611)
					Dynamic _g18 = this->_p(ln,HX_CSTRING("decay_radius.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(611)
					Float _g19 = ::Std_obj::parseFloat(_g18);		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(611)
					l->radius = _g19;
					HX_STACK_LINE(612)
					Dynamic _g20 = this->_p(ln,HX_CSTRING("multiplier.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(612)
					Float _g21 = ::Std_obj::parseFloat(_g20);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(612)
					l->intensity = _g21;
					HX_STACK_LINE(613)
					Dynamic _g22 = this->_p(ln,HX_CSTRING("decay_type.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(613)
					int atten_type = ::Std_obj::parseInt(_g22);		HX_STACK_VAR(atten_type,"atten_type");
					HX_STACK_LINE(614)
					if (((atten_type == (int)0))){
						HX_STACK_LINE(614)
						l->atten = 0.0;
					}
					else{
						HX_STACK_LINE(614)
						if (((atten_type == (int)1))){
							HX_STACK_LINE(614)
							l->atten = 1.0;
						}
						else{
							HX_STACK_LINE(614)
							l->atten = 2.0;
						}
					}
				}
				else if (  ( _switch_6==HX_CSTRING("ambient"))){
				}
				else if (  ( _switch_6==HX_CSTRING("directional"))){
					HX_STACK_LINE(618)
					Dynamic _g23 = this->_p(ln,HX_CSTRING("multiplier.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(618)
					Float _g24 = ::Std_obj::parseFloat(_g23);		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(618)
					l->intensity = _g24;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseLightLibrary,(void))

Void ColladaFile_obj::ParseAnimationLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseAnimationLibrary",0x3998caf4,"haxor.io.file.ColladaFile.ParseAnimationLibrary","haxor/io/file/ColladaFile.hx",626,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(627)
		Dynamic it = n->elementsNamed(HX_CSTRING("animation"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(628)
		int anim_id = (int)0;		HX_STACK_VAR(anim_id,"anim_id");
		HX_STACK_LINE(629)
		while((true)){
			HX_STACK_LINE(629)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(629)
				break;
			}
			HX_STACK_LINE(631)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(631)
			n = _g;
			HX_STACK_LINE(632)
			if ((n->elementsNamed(HX_CSTRING("animation"))->__Field(HX_CSTRING("hasNext"),true)())){
				HX_STACK_LINE(632)
				::Xml _g1 = n->elementsNamed(HX_CSTRING("animation"))->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(632)
				n = _g1;
			}
			HX_STACK_LINE(634)
			::haxor::io::file::ColladaAnimation ca = ::haxor::io::file::ColladaAnimation_obj::__new();		HX_STACK_VAR(ca,"ca");
			HX_STACK_LINE(636)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(636)
			ca->id = _g2;
			HX_STACK_LINE(637)
			::String _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(637)
			if (((ca->id == HX_CSTRING("")))){
				HX_STACK_LINE(637)
				int _g3 = (anim_id)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(637)
				_g4 = (HX_CSTRING("Clip") + _g3);
			}
			else{
				HX_STACK_LINE(637)
				_g4 = ca->id;
			}
			HX_STACK_LINE(637)
			ca->id = _g4;
			HX_STACK_LINE(638)
			::String _g5 = this->_a(n,HX_CSTRING("name"),ca->id);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(638)
			ca->name = _g5;
			HX_STACK_LINE(640)
			Dynamic source_iterator = n->elementsNamed(HX_CSTRING("source"));		HX_STACK_VAR(source_iterator,"source_iterator");
			HX_STACK_LINE(641)
			Dynamic sampler_iterator = n->elementsNamed(HX_CSTRING("sampler"));		HX_STACK_VAR(sampler_iterator,"sampler_iterator");
			HX_STACK_LINE(642)
			Array< ::Dynamic > source_list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(source_list,"source_list");
			HX_STACK_LINE(643)
			Array< ::Dynamic > sampler_list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(sampler_list,"sampler_list");
			HX_STACK_LINE(645)
			while((true)){
				HX_STACK_LINE(645)
				if ((!(source_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(645)
					break;
				}
				HX_STACK_LINE(645)
				::Xml _g6 = source_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(645)
				source_list->push(_g6);
			}
			HX_STACK_LINE(646)
			while((true)){
				HX_STACK_LINE(646)
				if ((!(sampler_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(646)
					break;
				}
				HX_STACK_LINE(646)
				::Xml _g7 = sampler_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(646)
				sampler_list->push(_g7);
			}
			HX_STACK_LINE(648)
			Dynamic channel_list = n->elementsNamed(HX_CSTRING("channel"));		HX_STACK_VAR(channel_list,"channel_list");
			HX_STACK_LINE(651)
			while((true)){
				HX_STACK_LINE(651)
				if ((!(channel_list->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(651)
					break;
				}
				HX_STACK_LINE(653)
				::Xml chn = channel_list->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(chn,"chn");
				HX_STACK_LINE(654)
				::haxor::io::file::ColladaAnimationChannel cch = ::haxor::io::file::ColladaAnimationChannel_obj::__new();		HX_STACK_VAR(cch,"cch");
				HX_STACK_LINE(655)
				::String _g8 = this->_a(chn,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(655)
				cch->source = _g8;
				HX_STACK_LINE(656)
				::String _g9 = this->_a(chn,HX_CSTRING("target"),HX_CSTRING(""));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(656)
				cch->target = _g9;
				HX_STACK_LINE(658)
				{
					HX_STACK_LINE(658)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(658)
					int _g3 = sampler_list->length;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(658)
					while((true)){
						HX_STACK_LINE(658)
						if ((!(((_g1 < _g3))))){
							HX_STACK_LINE(658)
							break;
						}
						HX_STACK_LINE(658)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(660)
						::String sampler_id = this->_a(sampler_list->__get(i).StaticCast< ::Xml >(),HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(sampler_id,"sampler_id");
						HX_STACK_LINE(661)
						if (((sampler_id != cch->source))){
							HX_STACK_LINE(661)
							continue;
						}
						HX_STACK_LINE(662)
						Dynamic input_iterator = sampler_list->__get(i).StaticCast< ::Xml >()->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(input_iterator,"input_iterator");
						HX_STACK_LINE(663)
						::String keyframe_time_source = HX_CSTRING("");		HX_STACK_VAR(keyframe_time_source,"keyframe_time_source");
						HX_STACK_LINE(664)
						::String keyframe_value_source = HX_CSTRING("");		HX_STACK_VAR(keyframe_value_source,"keyframe_value_source");
						HX_STACK_LINE(666)
						while((true)){
							HX_STACK_LINE(666)
							if ((!(input_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
								HX_STACK_LINE(666)
								break;
							}
							HX_STACK_LINE(668)
							::Xml chsi = input_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(chsi,"chsi");
							HX_STACK_LINE(669)
							{
								HX_STACK_LINE(669)
								::String _g21 = this->_a(chsi,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(669)
								::String _switch_7 = (_g21);
								if (  ( _switch_7==HX_CSTRING("input"))){
									HX_STACK_LINE(671)
									::String _g10 = this->_a(chsi,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(671)
									keyframe_time_source = _g10;
								}
								else if (  ( _switch_7==HX_CSTRING("output"))){
									HX_STACK_LINE(672)
									::String _g11 = this->_a(chsi,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(672)
									keyframe_value_source = _g11;
								}
							}
						}
						HX_STACK_LINE(676)
						if (((keyframe_time_source == HX_CSTRING("")))){
							HX_STACK_LINE(676)
							continue;
						}
						HX_STACK_LINE(677)
						if (((keyframe_value_source == HX_CSTRING("")))){
							HX_STACK_LINE(677)
							continue;
						}
						HX_STACK_LINE(679)
						::Xml kf_time_node = null();		HX_STACK_VAR(kf_time_node,"kf_time_node");
						HX_STACK_LINE(680)
						::Xml kf_value_node = null();		HX_STACK_VAR(kf_value_node,"kf_value_node");
						HX_STACK_LINE(682)
						{
							HX_STACK_LINE(682)
							int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
							HX_STACK_LINE(682)
							int _g21 = source_list->length;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(682)
							while((true)){
								HX_STACK_LINE(682)
								if ((!(((_g31 < _g21))))){
									HX_STACK_LINE(682)
									break;
								}
								HX_STACK_LINE(682)
								int j = (_g31)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(684)
								::Xml sn = source_list->__get(j).StaticCast< ::Xml >();		HX_STACK_VAR(sn,"sn");
								HX_STACK_LINE(685)
								::String _g12 = this->_a(sn,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g12,"_g12");
								HX_STACK_LINE(685)
								if (((_g12 == keyframe_time_source))){
									HX_STACK_LINE(685)
									kf_time_node = sn;
								}
								HX_STACK_LINE(686)
								::String _g13 = this->_a(sn,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g13,"_g13");
								HX_STACK_LINE(686)
								if (((_g13 == keyframe_value_source))){
									HX_STACK_LINE(686)
									kf_value_node = sn;
								}
							}
						}
						HX_STACK_LINE(689)
						if (((kf_time_node == null()))){
							HX_STACK_LINE(689)
							continue;
						}
						HX_STACK_LINE(690)
						if (((kf_value_node == null()))){
							HX_STACK_LINE(690)
							continue;
						}
						HX_STACK_LINE(692)
						Dynamic _g14 = this->_p(kf_time_node,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g14,"_g14");
						HX_STACK_LINE(692)
						Array< Float > kf_time_buffer = this->_f32a(_g14);		HX_STACK_VAR(kf_time_buffer,"kf_time_buffer");
						HX_STACK_LINE(693)
						Dynamic _g15 = this->_p(kf_value_node,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(693)
						Array< Float > kf_value_buffer = this->_f32a(_g15);		HX_STACK_VAR(kf_value_buffer,"kf_value_buffer");
						HX_STACK_LINE(694)
						Dynamic _g16 = this->_p(kf_value_node,HX_CSTRING("technique_common.accessor.@stride"),HX_CSTRING("0"),null(),null());		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(694)
						int kf_value_stride = ::Std_obj::parseInt(_g16);		HX_STACK_VAR(kf_value_stride,"kf_value_stride");
						HX_STACK_LINE(696)
						{
							HX_STACK_LINE(696)
							int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
							HX_STACK_LINE(696)
							int _g21 = kf_time_buffer->length;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(696)
							while((true)){
								HX_STACK_LINE(696)
								if ((!(((_g31 < _g21))))){
									HX_STACK_LINE(696)
									break;
								}
								HX_STACK_LINE(696)
								int j = (_g31)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(698)
								::haxor::io::file::ColladaAnimationKeyFrame kf = ::haxor::io::file::ColladaAnimationKeyFrame_obj::__new();		HX_STACK_VAR(kf,"kf");
								HX_STACK_LINE(699)
								kf->time = kf_time_buffer->__get(j);
								HX_STACK_LINE(700)
								{
									HX_STACK_LINE(700)
									int _g41 = (int)0;		HX_STACK_VAR(_g41,"_g41");
									HX_STACK_LINE(700)
									while((true)){
										HX_STACK_LINE(700)
										if ((!(((_g41 < kf_value_stride))))){
											HX_STACK_LINE(700)
											break;
										}
										HX_STACK_LINE(700)
										int k = (_g41)++;		HX_STACK_VAR(k,"k");
										HX_STACK_LINE(702)
										Dynamic _g17 = kf_value_buffer->shift();		HX_STACK_VAR(_g17,"_g17");
										HX_STACK_LINE(702)
										kf->values->push(_g17);
									}
								}
								HX_STACK_LINE(704)
								cch->keyframes->push(kf);
							}
						}
					}
				}
				HX_STACK_LINE(707)
				ca->channels->push(cch);
			}
			HX_STACK_LINE(709)
			this->animations->push(ca);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseAnimationLibrary,(void))

Void ColladaFile_obj::ParseMaterialLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseMaterialLibrary",0xf4892517,"haxor.io.file.ColladaFile.ParseMaterialLibrary","haxor/io/file/ColladaFile.hx",715,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(716)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(717)
		while((true)){
			HX_STACK_LINE(717)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(717)
				break;
			}
			HX_STACK_LINE(719)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(719)
			n = _g;
			HX_STACK_LINE(720)
			{
				HX_STACK_LINE(720)
				::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(720)
				::String _switch_8 = (_g1);
				if (  ( _switch_8==HX_CSTRING("material"))){
					HX_STACK_LINE(723)
					::haxor::io::file::ColladaMaterial mat = ::haxor::io::file::ColladaMaterial_obj::__new();		HX_STACK_VAR(mat,"mat");
					HX_STACK_LINE(724)
					::String _g11 = this->_a(n,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(724)
					mat->id = _g11;
					HX_STACK_LINE(725)
					::String _g2 = this->_a(n,HX_CSTRING("name"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(725)
					mat->name = _g2;
					HX_STACK_LINE(726)
					if (((mat->id == HX_CSTRING("")))){
						HX_STACK_LINE(726)
						mat->id = mat->name;
					}
					HX_STACK_LINE(727)
					this->materials->push(mat);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseMaterialLibrary,(void))

Void ColladaFile_obj::ParseSceneLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseSceneLibrary",0x30a6672c,"haxor.io.file.ColladaFile.ParseSceneLibrary","haxor/io/file/ColladaFile.hx",733,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(734)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(735)
		while((true)){
			HX_STACK_LINE(735)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(735)
				break;
			}
			HX_STACK_LINE(737)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(737)
			n = _g;
			HX_STACK_LINE(738)
			{
				HX_STACK_LINE(738)
				::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(738)
				::String _switch_9 = (_g1);
				if (  ( _switch_9==HX_CSTRING("visual_scene"))){
					HX_STACK_LINE(738)
					this->ParseVisualScene(n);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseSceneLibrary,(void))

Void ColladaFile_obj::ParseVisualScene( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseVisualScene",0x0bd770ef,"haxor.io.file.ColladaFile.ParseVisualScene","haxor/io/file/ColladaFile.hx",743,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(744)
		if (((this->scene != null()))){
			HX_STACK_LINE(744)
			return null();
		}
		HX_STACK_LINE(745)
		::haxor::io::file::ColladaVisualScene _g = ::haxor::io::file::ColladaVisualScene_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(745)
		this->scene = _g;
		HX_STACK_LINE(746)
		::String _g1 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("collada_scene"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(746)
		this->scene->id = _g1;
		HX_STACK_LINE(747)
		::String _g2 = this->_a(n,HX_CSTRING("name"),this->scene->id);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(747)
		this->scene->name = _g2;
		HX_STACK_LINE(748)
		::String _g3 = n->get_nodeName();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(748)
		this->scene->type = _g3;
		HX_STACK_LINE(749)
		this->TraverseVisualSceneNodes(this->scene,null(),n);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseVisualScene,(void))

Void ColladaFile_obj::TraverseVisualSceneNodes( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","TraverseVisualSceneNodes",0x5c90d9ed,"haxor.io.file.ColladaFile.TraverseVisualSceneNodes","haxor/io/file/ColladaFile.hx",753,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(scn,"scn")
		HX_STACK_ARG(p,"p")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(754)
		::haxor::io::file::ColladaNode cn = null();		HX_STACK_VAR(cn,"cn");
		HX_STACK_LINE(755)
		::String _g = n->get_nodeName();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(755)
		if (((_g == HX_CSTRING("node")))){
			HX_STACK_LINE(755)
			::haxor::io::file::ColladaNode _g1 = this->ParseVisualSceneNode(scn,p,n);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(755)
			cn = _g1;
		}
		HX_STACK_LINE(756)
		Dynamic cn_it = n->elementsNamed(HX_CSTRING("node"));		HX_STACK_VAR(cn_it,"cn_it");
		HX_STACK_LINE(757)
		while((true)){
			HX_STACK_LINE(757)
			if ((!(cn_it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(757)
				break;
			}
			HX_STACK_LINE(757)
			::Xml _g2 = cn_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(757)
			this->TraverseVisualSceneNodes(scn,cn,_g2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,TraverseVisualSceneNodes,(void))

::haxor::io::file::ColladaNode ColladaFile_obj::ParseVisualSceneNode( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseVisualSceneNode",0xf4f74a91,"haxor.io.file.ColladaFile.ParseVisualSceneNode","haxor/io/file/ColladaFile.hx",761,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(scn,"scn")
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(762)
	::haxor::io::file::ColladaNode cn = ::haxor::io::file::ColladaNode_obj::__new();		HX_STACK_VAR(cn,"cn");
	HX_STACK_LINE(763)
	cn->scene = scn;
	HX_STACK_LINE(765)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(765)
	Float _g1 = (_g * (int)16777215);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(765)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(765)
	::String _g3 = (HX_CSTRING("node") + _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(765)
	::String _g4 = this->_a(n,HX_CSTRING("sid"),_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(765)
	cn->sid = _g4;
	HX_STACK_LINE(766)
	::String _g5 = this->_a(n,HX_CSTRING("id"),cn->sid);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(766)
	cn->id = _g5;
	HX_STACK_LINE(767)
	::String _g6 = this->_a(n,HX_CSTRING("name"),cn->sid);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(767)
	cn->name = _g6;
	HX_STACK_LINE(768)
	if (((cn->sid == HX_CSTRING("")))){
		HX_STACK_LINE(768)
		cn->sid = cn->id;
	}
	HX_STACK_LINE(769)
	::String _g7 = this->_a(n,HX_CSTRING("type"),HX_CSTRING("NODE")).toLowerCase();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(769)
	cn->type = _g7;
	HX_STACK_LINE(770)
	Dynamic _g8 = this->_p(n,HX_CSTRING("matrix.$text"),HX_CSTRING("1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1"),null(),null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(770)
	Array< Float > _g9 = this->_f32a(_g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(770)
	cn->matrix = _g9;
	HX_STACK_LINE(771)
	cn->parent = p;
	HX_STACK_LINE(772)
	cn->GenerateTranform();
	HX_STACK_LINE(774)
	Dynamic iit = n->elements();		HX_STACK_VAR(iit,"iit");
	HX_STACK_LINE(775)
	while((true)){
		HX_STACK_LINE(775)
		if ((!(iit->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(775)
			break;
		}
		HX_STACK_LINE(777)
		::Xml nin = iit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(nin,"nin");
		HX_STACK_LINE(778)
		::haxor::io::file::ColladaInstance ni = null();		HX_STACK_VAR(ni,"ni");
		HX_STACK_LINE(779)
		{
			HX_STACK_LINE(779)
			::String _g10 = nin->get_nodeName();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(779)
			::String _switch_10 = (_g10);
			if (  ( _switch_10==HX_CSTRING("instance_geometry"))){
				HX_STACK_LINE(782)
				::haxor::io::file::ColladaInstance _g101 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g101,"_g101");
				HX_STACK_LINE(782)
				ni = _g101;
				HX_STACK_LINE(783)
				ni->type = HX_CSTRING("geometry");
				HX_STACK_LINE(784)
				::String _g11 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(784)
				ni->target = _g11;
			}
			else if (  ( _switch_10==HX_CSTRING("instance_controller"))){
				HX_STACK_LINE(788)
				::haxor::io::file::ColladaInstance _g12 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(788)
				ni = _g12;
				HX_STACK_LINE(789)
				ni->type = HX_CSTRING("controller");
				HX_STACK_LINE(790)
				::String _g13 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(790)
				ni->target = _g13;
			}
			else if (  ( _switch_10==HX_CSTRING("instance_light"))){
				HX_STACK_LINE(793)
				::haxor::io::file::ColladaInstance _g14 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(793)
				ni = _g14;
				HX_STACK_LINE(794)
				ni->type = HX_CSTRING("light");
				HX_STACK_LINE(795)
				::String _g15 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(795)
				ni->target = _g15;
			}
			else if (  ( _switch_10==HX_CSTRING("extra"))){
				HX_STACK_LINE(798)
				Dynamic _g16 = this->_p(nin,HX_CSTRING("technique.user_properties.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(798)
				cn->data = _g16;
				HX_STACK_LINE(799)
				int _g17 = cn->data.indexOf(HX_CSTRING(";"),null());		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(799)
				if (((_g17 < (int)0))){
					HX_STACK_LINE(799)
					cn->data = HX_CSTRING("");
				}
			}
		}
		HX_STACK_LINE(803)
		if (((ni != null()))){
			HX_STACK_LINE(803)
			cn->instances->push(ni);
		}
	}
	HX_STACK_LINE(806)
	if (((p == null()))){
		HX_STACK_LINE(806)
		scn->children->push(cn);
	}
	else{
		HX_STACK_LINE(806)
		p->children->push(cn);
	}
	HX_STACK_LINE(807)
	return cn;
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,ParseVisualSceneNode,return )

Void ColladaFile_obj::ParseInstanceMaterials( ::haxor::io::file::ColladaInstance ci,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseInstanceMaterials",0xd76ce25a,"haxor.io.file.ColladaFile.ParseInstanceMaterials","haxor/io/file/ColladaFile.hx",811,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ci,"ci")
		HX_STACK_ARG(n,"n")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseInstanceMaterials,(void))

Void ColladaFile_obj::ParseControllerLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseControllerLibrary",0xcdf6c882,"haxor.io.file.ColladaFile.ParseControllerLibrary","haxor/io/file/ColladaFile.hx",816,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(817)
		Dynamic it = n->elementsNamed(HX_CSTRING("controller"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(818)
		::haxor::io::file::ColladaController c = null();		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(819)
		while((true)){
			HX_STACK_LINE(819)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(819)
				break;
			}
			HX_STACK_LINE(821)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(821)
			n = _g;
			HX_STACK_LINE(822)
			::haxor::io::file::ColladaController _g1 = ::haxor::io::file::ColladaController_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(822)
			c = _g1;
			HX_STACK_LINE(823)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(823)
			c->id = _g2;
			HX_STACK_LINE(824)
			::String _g3 = this->_a(n,HX_CSTRING("name"),c->id);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(824)
			c->name = _g3;
			HX_STACK_LINE(825)
			this->ParseController(c,n);
			HX_STACK_LINE(826)
			this->controllers->push(c);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseControllerLibrary,(void))

Void ColladaFile_obj::ParseController( ::haxor::io::file::ColladaController c,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseController",0x4bcb5779,"haxor.io.file.ColladaFile.ParseController","haxor/io/file/ColladaFile.hx",831,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(832)
		::Xml _g = n->firstElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(832)
		n = _g;
		HX_STACK_LINE(833)
		if (((n == null()))){
			HX_STACK_LINE(833)
			return null();
		}
		HX_STACK_LINE(834)
		::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(834)
		::String _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(834)
		if (((_g1 == null()))){
			HX_STACK_LINE(834)
			_g2 = HX_CSTRING("none");
		}
		else{
			HX_STACK_LINE(834)
			_g2 = n->get_nodeName().toLowerCase();
		}
		HX_STACK_LINE(834)
		c->type = _g2;
		HX_STACK_LINE(835)
		{
			HX_STACK_LINE(835)
			::String _g3 = c->type;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(835)
			::String _switch_11 = (_g3);
			if (  ( _switch_11==HX_CSTRING("skin"))){
				HX_STACK_LINE(837)
				this->ParseControllerSkin(c,n);
			}
			else if (  ( _switch_11==HX_CSTRING("morph"))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseController,(void))

Void ColladaFile_obj::ParseControllerSkin( ::haxor::io::file::ColladaController c,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseControllerSkin",0x4c6d4a96,"haxor.io.file.ColladaFile.ParseControllerSkin","haxor/io/file/ColladaFile.hx",843,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(844)
		::String _g = this->_a(n,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(844)
		c->source = _g;
		HX_STACK_LINE(845)
		Dynamic _g1 = this->_p(n,HX_CSTRING("bind_shape_matrix.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(845)
		Array< Float > _g2 = this->_f32a(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(845)
		c->matrix = _g2;
		HX_STACK_LINE(847)
		::String source = HX_CSTRING("");		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(848)
		::Xml sn = null();		HX_STACK_VAR(sn,"sn");
		HX_STACK_LINE(850)
		Dynamic _g3 = this->_p(n,HX_CSTRING("joints"),null(),null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(850)
		::Xml jn;		HX_STACK_VAR(jn,"jn");
		HX_STACK_LINE(850)
		if (((_g3 == null()))){
			HX_STACK_LINE(850)
			jn = null();
		}
		else{
			HX_STACK_LINE(850)
			jn = this->_p(n,HX_CSTRING("joints"),null(),null(),null())->__Field(HX_CSTRING("next"),true)();
		}
		HX_STACK_LINE(852)
		if (((jn != null()))){
			HX_STACK_LINE(854)
			Dynamic jn_it = jn->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(jn_it,"jn_it");
			HX_STACK_LINE(855)
			while((true)){
				HX_STACK_LINE(855)
				if ((!(jn_it->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(855)
					break;
				}
				HX_STACK_LINE(857)
				::Xml jni = jn_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(jni,"jni");
				HX_STACK_LINE(858)
				::String _g4 = this->_a(jni,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(858)
				source = _g4;
				HX_STACK_LINE(859)
				if (((source == HX_CSTRING("")))){
					HX_STACK_LINE(859)
					continue;
				}
				HX_STACK_LINE(860)
				::Xml _g5 = this->_f(n,HX_CSTRING("source"),HX_CSTRING("id"),source);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(860)
				sn = _g5;
				HX_STACK_LINE(861)
				if (((sn == null()))){
					HX_STACK_LINE(861)
					continue;
				}
				HX_STACK_LINE(863)
				{
					HX_STACK_LINE(863)
					::String _g6 = this->_a(jni,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(863)
					::String _switch_12 = (_g6);
					if (  ( _switch_12==HX_CSTRING("joint"))){
						HX_STACK_LINE(865)
						Dynamic _g61 = this->_p(sn,HX_CSTRING("Name_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g61,"_g61");
						HX_STACK_LINE(865)
						::String _g7 = ::StringTools_obj::replace(_g61,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(865)
						Array< ::String > _g8 = ::StringTools_obj::trim(_g7).split(HX_CSTRING(" "));		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(865)
						c->joints = _g8;
					}
					else if (  ( _switch_12==HX_CSTRING("inv_bind_matrix"))){
						HX_STACK_LINE(868)
						Dynamic _g9 = this->_p(sn,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(868)
						Array< Float > ml = this->_f32a(_g9);		HX_STACK_VAR(ml,"ml");
						HX_STACK_LINE(869)
						while((true)){
							HX_STACK_LINE(869)
							if ((!(((ml->length > (int)0))))){
								HX_STACK_LINE(869)
								break;
							}
							HX_STACK_LINE(871)
							Array< Float > mtx = Array_obj< Float >::__new();		HX_STACK_VAR(mtx,"mtx");
							HX_STACK_LINE(872)
							{
								HX_STACK_LINE(872)
								int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(872)
								while((true)){
									HX_STACK_LINE(872)
									if ((!(((_g11 < (int)16))))){
										HX_STACK_LINE(872)
										break;
									}
									HX_STACK_LINE(872)
									int i = (_g11)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(872)
									Dynamic _g10 = ml->shift();		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(872)
									mtx->push(_g10);
								}
							}
							HX_STACK_LINE(873)
							c->binds->push(mtx);
						}
					}
				}
			}
		}
		HX_STACK_LINE(879)
		Dynamic _g11 = this->_p(n,HX_CSTRING("vertex_weights"),null(),null(),null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(879)
		::Xml vwn;		HX_STACK_VAR(vwn,"vwn");
		HX_STACK_LINE(879)
		if (((_g11 == null()))){
			HX_STACK_LINE(879)
			vwn = null();
		}
		else{
			HX_STACK_LINE(879)
			vwn = this->_p(n,HX_CSTRING("vertex_weights"),null(),null(),null())->__Field(HX_CSTRING("next"),true)();
		}
		HX_STACK_LINE(880)
		if (((vwn != null()))){
			HX_STACK_LINE(882)
			Array< ::Dynamic > _g12 = this->ParseInputList(n,vwn);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(882)
			c->inputs = _g12;
			HX_STACK_LINE(883)
			Dynamic _g13 = this->_p(vwn,HX_CSTRING("vcount.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(883)
			Array< int > _g14 = this->_i16a(_g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(883)
			c->vcount = _g14;
			HX_STACK_LINE(884)
			::String vwb = this->_p(vwn,HX_CSTRING("v.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(vwb,"vwb");
			HX_STACK_LINE(885)
			int _g15 = c->get_offset();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(885)
			Array< ::Dynamic > _g16 = this->_i16ta(vwb,_g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(885)
			c->indexes = _g16;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseControllerSkin,(void))

Void ColladaFile_obj::ParseImageLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseImageLibrary",0xe21890fd,"haxor.io.file.ColladaFile.ParseImageLibrary","haxor/io/file/ColladaFile.hx",891,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(892)
		Dynamic it = n->elementsNamed(HX_CSTRING("image"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(893)
		::haxor::io::file::ColladaImage img = null();		HX_STACK_VAR(img,"img");
		HX_STACK_LINE(894)
		while((true)){
			HX_STACK_LINE(894)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(894)
				break;
			}
			HX_STACK_LINE(896)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(896)
			n = _g;
			HX_STACK_LINE(897)
			::haxor::io::file::ColladaImage _g1 = ::haxor::io::file::ColladaImage_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(897)
			img = _g1;
			HX_STACK_LINE(898)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(898)
			img->id = _g2;
			HX_STACK_LINE(899)
			::String _g3 = this->_a(n,HX_CSTRING("name"),img->id);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(899)
			img->name = _g3;
			HX_STACK_LINE(900)
			::String _g4 = this->_a(n,HX_CSTRING("format"),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(900)
			img->format = _g4;
			HX_STACK_LINE(901)
			::String _g5 = this->_a(n,HX_CSTRING("width"),HX_CSTRING("-1"));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(901)
			Dynamic _g6 = ::Std_obj::parseInt(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(901)
			img->width = _g6;
			HX_STACK_LINE(902)
			::String _g7 = this->_a(n,HX_CSTRING("height"),HX_CSTRING("-1"));		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(902)
			Dynamic _g8 = ::Std_obj::parseInt(_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(902)
			img->height = _g8;
			HX_STACK_LINE(903)
			::String _g9 = this->_a(n,HX_CSTRING("depth"),HX_CSTRING("-1"));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(903)
			Dynamic _g10 = ::Std_obj::parseInt(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(903)
			img->depth = _g10;
			HX_STACK_LINE(905)
			this->images->push(img);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseImageLibrary,(void))

Void ColladaFile_obj::ParseGeometryLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseGeometryLibrary",0xd411266c,"haxor.io.file.ColladaFile.ParseGeometryLibrary","haxor/io/file/ColladaFile.hx",910,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(911)
		Dynamic it = n->elementsNamed(HX_CSTRING("geometry"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(912)
		::haxor::io::file::ColladaGeometry g = null();		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(913)
		while((true)){
			HX_STACK_LINE(913)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(913)
				break;
			}
			HX_STACK_LINE(915)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(915)
			n = _g;
			HX_STACK_LINE(916)
			::haxor::io::file::ColladaGeometry _g1 = ::haxor::io::file::ColladaGeometry_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(916)
			g = _g1;
			HX_STACK_LINE(917)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(917)
			g->id = _g2;
			HX_STACK_LINE(918)
			::String _g3 = this->_a(n,HX_CSTRING("name"),HX_CSTRING("none"));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(918)
			g->name = _g3;
			HX_STACK_LINE(919)
			this->ParseGeometry(g,n);
			HX_STACK_LINE(920)
			this->geometries->push(g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseGeometryLibrary,(void))

Void ColladaFile_obj::ParseGeometry( ::haxor::io::file::ColladaGeometry g,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseGeometry",0x09ad604f,"haxor.io.file.ColladaFile.ParseGeometry","haxor/io/file/ColladaFile.hx",925,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(g,"g")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(926)
		::Xml _g = n->firstElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(926)
		n = _g;
		HX_STACK_LINE(927)
		if (((n == null()))){
			HX_STACK_LINE(927)
			return null();
		}
		HX_STACK_LINE(928)
		::haxor::io::file::ColladaMesh _g1 = ::haxor::io::file::ColladaMesh_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(928)
		g->mesh = _g1;
		HX_STACK_LINE(929)
		::String _g2 = n->get_nodeName();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(929)
		::String _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(929)
		if (((_g2 == null()))){
			HX_STACK_LINE(929)
			_g3 = HX_CSTRING("none");
		}
		else{
			HX_STACK_LINE(929)
			_g3 = n->get_nodeName().toLowerCase();
		}
		HX_STACK_LINE(929)
		g->mesh->type = _g3;
		HX_STACK_LINE(930)
		{
			HX_STACK_LINE(930)
			::String _g4 = g->mesh->type;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(930)
			::String _switch_13 = (_g4);
			if (  ( _switch_13==HX_CSTRING("mesh"))){
				HX_STACK_LINE(932)
				this->ParseMesh(g->mesh,n);
			}
			else if (  ( _switch_13==HX_CSTRING("convex_mesh"))){
			}
			else if (  ( _switch_13==HX_CSTRING("spline"))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseGeometry,(void))

Void ColladaFile_obj::ParseMesh( ::haxor::io::file::ColladaMesh m,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseMesh",0x125d550a,"haxor.io.file.ColladaFile.ParseMesh","haxor/io/file/ColladaFile.hx",939,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(940)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(941)
		::Xml p = n;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(942)
		while((true)){
			HX_STACK_LINE(942)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(942)
				break;
			}
			HX_STACK_LINE(944)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(944)
			n = _g;
			HX_STACK_LINE(945)
			::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(945)
			if (((_g1 == HX_CSTRING("vertices")))){
				HX_STACK_LINE(945)
				continue;
			}
			HX_STACK_LINE(946)
			::String _g2 = n->get_nodeName();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(946)
			if (((_g2 == HX_CSTRING("source")))){
				HX_STACK_LINE(946)
				continue;
			}
			HX_STACK_LINE(947)
			::haxor::io::file::ColladaPrimitive cp = ::haxor::io::file::ColladaPrimitive_obj::__new();		HX_STACK_VAR(cp,"cp");
			HX_STACK_LINE(949)
			::String _g3 = n->get_nodeName();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(949)
			cp->type = _g3;
			HX_STACK_LINE(950)
			::String _g4 = this->_a(n,HX_CSTRING("material"),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(950)
			cp->material = _g4;
			HX_STACK_LINE(951)
			this->ParsePrimitive(cp,p,n);
			HX_STACK_LINE(952)
			m->primitives->push(cp);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseMesh,(void))

Void ColladaFile_obj::ParsePrimitive( ::haxor::io::file::ColladaPrimitive cp,::Xml p,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParsePrimitive",0x1426146a,"haxor.io.file.ColladaFile.ParsePrimitive","haxor/io/file/ColladaFile.hx",957,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cp,"cp")
		HX_STACK_ARG(p,"p")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(958)
		Array< ::Dynamic > _g = this->ParseInputList(p,n);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(958)
		cp->inputs = _g;
		HX_STACK_LINE(959)
		Dynamic p_it = n->elementsNamed(HX_CSTRING("p"));		HX_STACK_VAR(p_it,"p_it");
		HX_STACK_LINE(960)
		Dynamic vc_it = n->elementsNamed(HX_CSTRING("vcount"));		HX_STACK_VAR(vc_it,"vc_it");
		HX_STACK_LINE(961)
		if ((vc_it->__Field(HX_CSTRING("hasNext"),true)())){
			HX_STACK_LINE(963)
			::Xml ncitn = vc_it->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("firstChild"),true)();		HX_STACK_VAR(ncitn,"ncitn");
			HX_STACK_LINE(964)
			Array< int > _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(964)
			if (((ncitn == null()))){
				HX_STACK_LINE(964)
				_g2 = Array_obj< int >::__new();
			}
			else{
				HX_STACK_LINE(964)
				::String _g1 = ncitn->toString();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(964)
				_g2 = this->_i16a(_g1);
			}
			HX_STACK_LINE(964)
			cp->vcount = _g2;
		}
		HX_STACK_LINE(967)
		while((true)){
			HX_STACK_LINE(967)
			if ((!(p_it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(967)
				break;
			}
			HX_STACK_LINE(969)
			::Xml vn = p_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(vn,"vn");
			HX_STACK_LINE(970)
			::Xml _g3 = vn->firstChild();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(970)
			::String vb;		HX_STACK_VAR(vb,"vb");
			HX_STACK_LINE(970)
			if (((_g3 != null()))){
				HX_STACK_LINE(970)
				vb = vn->firstChild()->toString();
			}
			else{
				HX_STACK_LINE(970)
				vb = HX_CSTRING("0");
			}
			HX_STACK_LINE(971)
			int off = cp->get_offset();		HX_STACK_VAR(off,"off");
			HX_STACK_LINE(972)
			Array< ::Dynamic > ti = this->_i16ta(vb,off);		HX_STACK_VAR(ti,"ti");
			HX_STACK_LINE(973)
			cp->indexes->push(ti);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,ParsePrimitive,(void))

Array< ::Dynamic > ColladaFile_obj::ParseInputList( ::Xml p,::Xml n){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseInputList",0xfbab654b,"haxor.io.file.ColladaFile.ParseInputList","haxor/io/file/ColladaFile.hx",992,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(993)
	Array< ::Dynamic > l = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(994)
	Dynamic it = n->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(995)
	while((true)){
		HX_STACK_LINE(995)
		if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(995)
			break;
		}
		HX_STACK_LINE(997)
		::Xml pi = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(pi,"pi");
		HX_STACK_LINE(998)
		::haxor::io::file::ColladaInput ci = ::haxor::io::file::ColladaInput_obj::__new();		HX_STACK_VAR(ci,"ci");
		HX_STACK_LINE(999)
		::String source = this->_a(pi,HX_CSTRING("source"),HX_CSTRING(""));		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(1000)
		::String _g = this->_a(pi,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1000)
		ci->semantic = _g;
		HX_STACK_LINE(1001)
		::String _g1 = this->_a(pi,HX_CSTRING("offset"),HX_CSTRING("-1"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1001)
		Dynamic _g2 = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1001)
		ci->offset = _g2;
		HX_STACK_LINE(1002)
		::String _g3 = this->_a(pi,HX_CSTRING("set"),HX_CSTRING("-1"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(1002)
		Dynamic _g4 = ::Std_obj::parseInt(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(1002)
		ci->set = _g4;
		HX_STACK_LINE(1003)
		if (((ci->semantic == HX_CSTRING("joint")))){
			HX_STACK_LINE(1003)
			l->push(ci);
			HX_STACK_LINE(1003)
			continue;
		}
		HX_STACK_LINE(1004)
		if (((ci->semantic == HX_CSTRING("vertex")))){
			HX_STACK_LINE(1006)
			Dynamic _g5 = this->_p(p,HX_CSTRING("vertices.input.@source"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1006)
			source = _g5;
		}
		HX_STACK_LINE(1008)
		if (((source == HX_CSTRING("")))){
			HX_STACK_LINE(1008)
			continue;
		}
		HX_STACK_LINE(1009)
		::String _g6 = source.substr((int)1,null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(1009)
		source = _g6;
		HX_STACK_LINE(1010)
		::Xml sn = this->_f(p,HX_CSTRING("source"),HX_CSTRING("id"),source);		HX_STACK_VAR(sn,"sn");
		HX_STACK_LINE(1011)
		if (((sn == null()))){
			HX_STACK_LINE(1011)
			continue;
		}
		HX_STACK_LINE(1012)
		::String stride_str = this->_p(sn,HX_CSTRING("technique_common.accessor.@stride"),HX_CSTRING("0"),null(),null());		HX_STACK_VAR(stride_str,"stride_str");
		HX_STACK_LINE(1013)
		Dynamic _g7 = ::Std_obj::parseInt(stride_str);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(1013)
		ci->stride = _g7;
		HX_STACK_LINE(1014)
		Dynamic _g8 = this->_p(sn,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(1014)
		Array< Float > _g9 = this->_f32a(_g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(1014)
		ci->values = _g9;
		HX_STACK_LINE(1015)
		l->push(ci);
	}
	HX_STACK_LINE(1017)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseInputList,return )

Void ColladaFile_obj::TraverseStep( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","TraverseStep",0x039b0314,"haxor.io.file.ColladaFile.TraverseStep","haxor/io/file/ColladaFile.hx",1021,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(1022)
		this->Parse(n);
		HX_STACK_LINE(1023)
		Dynamic l = n->elements();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1024)
		while((true)){
			HX_STACK_LINE(1024)
			if ((!(l->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(1024)
				break;
			}
			HX_STACK_LINE(1024)
			::Xml _g = l->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1024)
			this->TraverseStep(_g);
		}
	}
return null();
}


Array< Float > ColladaFile_obj::_f32a( ::String v){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_f32a",0x9bd71a85,"haxor.io.file.ColladaFile._f32a","haxor/io/file/ColladaFile.hx",1028,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(1029)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1029)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1030)
	Array< Float > a = Array_obj< Float >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1032)
	{
		HX_STACK_LINE(1032)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1032)
		int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1032)
		while((true)){
			HX_STACK_LINE(1032)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(1032)
				break;
			}
			HX_STACK_LINE(1032)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1032)
			Float _g11 = ::Std_obj::parseFloat(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1032)
			a->push(_g11);
		}
	}
	HX_STACK_LINE(1034)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,_f32a,return )

Array< int > ColladaFile_obj::_i16a( ::String v){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_i16a",0x9dd13d5c,"haxor.io.file.ColladaFile._i16a","haxor/io/file/ColladaFile.hx",1038,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(1039)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1039)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1040)
	Array< int > a = Array_obj< int >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1041)
	{
		HX_STACK_LINE(1041)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1041)
		int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1041)
		while((true)){
			HX_STACK_LINE(1041)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(1041)
				break;
			}
			HX_STACK_LINE(1041)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1041)
			Dynamic _g11 = ::Std_obj::parseInt(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1041)
			a->push(_g11);
		}
	}
	HX_STACK_LINE(1042)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,_i16a,return )

Array< ::Dynamic > ColladaFile_obj::_i16ta( ::String v,int s){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_i16ta",0x79448412,"haxor.io.file.ColladaFile._i16ta","haxor/io/file/ColladaFile.hx",1046,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(1047)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1047)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1048)
	::String tl = HX_CSTRING("");		HX_STACK_VAR(tl,"tl");
	HX_STACK_LINE(1049)
	Array< ::Dynamic > a = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1050)
	Array< int > bf;		HX_STACK_VAR(bf,"bf");
	HX_STACK_LINE(1051)
	int k = (int)0;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(1053)
	while((true)){
		HX_STACK_LINE(1053)
		if ((!(((k < l->length))))){
			HX_STACK_LINE(1053)
			break;
		}
		HX_STACK_LINE(1055)
		bf = Array_obj< int >::__new();
		HX_STACK_LINE(1056)
		{
			HX_STACK_LINE(1056)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1056)
			while((true)){
				HX_STACK_LINE(1056)
				if ((!(((_g1 < s))))){
					HX_STACK_LINE(1056)
					break;
				}
				HX_STACK_LINE(1056)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(1056)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(1056)
				::String _g2 = l->__get(_g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1056)
				Dynamic _g3 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1056)
				bf->push(_g3);
			}
		}
		HX_STACK_LINE(1057)
		a->push(bf);
	}
	HX_STACK_LINE(1059)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,_i16ta,return )

Array< ::Dynamic > ColladaFile_obj::GenerateTriangles( ::String p_type,Array< ::Dynamic > p_indexes,Array< int > p_vcount){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","GenerateTriangles",0x4b1fb600,"haxor.io.file.ColladaFile.GenerateTriangles","haxor/io/file/ColladaFile.hx",37,0xa1888587)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_ARG(p_indexes,"p_indexes")
	HX_STACK_ARG(p_vcount,"p_vcount")
	HX_STACK_LINE(38)
	Array< ::Dynamic > triangles = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(triangles,"triangles");
	HX_STACK_LINE(39)
	::String _switch_14 = (p_type);
	if (  ( _switch_14==HX_CSTRING("triangles"))){
		HX_STACK_LINE(41)
		if (((p_indexes->length <= (int)0))){
			HX_STACK_LINE(41)
			triangles = Array_obj< ::Dynamic >::__new();
		}
		else{
			HX_STACK_LINE(41)
			triangles = p_indexes->__get((int)0).StaticCast< Array< ::Dynamic > >();
		}
	}
	else if (  ( _switch_14==HX_CSTRING("polygons"))){
		HX_STACK_LINE(43)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(43)
		int _g = p_indexes->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		while((true)){
			HX_STACK_LINE(43)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(43)
				break;
			}
			HX_STACK_LINE(43)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(45)
			Array< ::Dynamic > tris = ::haxor::io::file::ColladaFile_obj::TriangulatePolygon(p_indexes->__get(i).StaticCast< Array< ::Dynamic > >(),p_indexes->__get(i).StaticCast< Array< ::Dynamic > >()->length,null());		HX_STACK_VAR(tris,"tris");
			HX_STACK_LINE(46)
			while((true)){
				HX_STACK_LINE(46)
				if ((!(((tris->length > (int)0))))){
					HX_STACK_LINE(46)
					break;
				}
				HX_STACK_LINE(46)
				Array< int > _g2 = tris->shift().StaticCast< Array< int > >();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(46)
				triangles->push(_g2);
			}
		}
	}
	else if (  ( _switch_14==HX_CSTRING("polylist"))){
		HX_STACK_LINE(49)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(50)
		{
			HX_STACK_LINE(50)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(50)
			int _g = p_vcount->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(50)
			while((true)){
				HX_STACK_LINE(50)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(50)
					break;
				}
				HX_STACK_LINE(50)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(52)
				int o = p_vcount->__get(i);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(53)
				Array< ::Dynamic > tris = ::haxor::io::file::ColladaFile_obj::TriangulatePolygon(p_indexes->__get((int)0).StaticCast< Array< ::Dynamic > >(),o,k);		HX_STACK_VAR(tris,"tris");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((tris->length > (int)0))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					Array< int > _g11 = tris->shift().StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(54)
					triangles->push(_g11);
				}
				HX_STACK_LINE(55)
				hx::AddEq(k,o);
			}
		}
	}
	HX_STACK_LINE(58)
	return triangles;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,GenerateTriangles,return )

Array< ::Dynamic > ColladaFile_obj::TriangulatePolygon( Array< ::Dynamic > t,int c,hx::Null< int >  __o_o){
int o = __o_o.Default(0);
	HX_STACK_FRAME("haxor.io.file.ColladaFile","TriangulatePolygon",0x3fc0d024,"haxor.io.file.ColladaFile.TriangulatePolygon","haxor/io/file/ColladaFile.hx",62,0xa1888587)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(o,"o")
{
		HX_STACK_LINE(63)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(64)
		int i0 = (int)0;		HX_STACK_VAR(i0,"i0");
		HX_STACK_LINE(65)
		int i1 = (int)1;		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(66)
		int i2 = (int)2;		HX_STACK_VAR(i2,"i2");
		HX_STACK_LINE(67)
		Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(68)
		while((true)){
			HX_STACK_LINE(68)
			if ((!(((i2 < c))))){
				HX_STACK_LINE(68)
				break;
			}
			HX_STACK_LINE(70)
			Array< int > _g = t->__get((i0 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(70)
			res->push(_g);
			HX_STACK_LINE(70)
			Array< int > _g1 = t->__get((i1 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(70)
			res->push(_g1);
			HX_STACK_LINE(70)
			Array< int > _g2 = t->__get((i2 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(70)
			res->push(_g2);
			HX_STACK_LINE(71)
			(i1)++;
			HX_STACK_LINE(71)
			(i2)++;
		}
		HX_STACK_LINE(73)
		return res;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,TriangulatePolygon,return )


ColladaFile_obj::ColladaFile_obj()
{
}

void ColladaFile_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaFile);
	HX_MARK_MEMBER_NAME(xmlns,"xmlns");
	HX_MARK_MEMBER_NAME(version,"version");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(geometries,"geometries");
	HX_MARK_MEMBER_NAME(images,"images");
	HX_MARK_MEMBER_NAME(controllers,"controllers");
	HX_MARK_MEMBER_NAME(materials,"materials");
	HX_MARK_MEMBER_NAME(lights,"lights");
	HX_MARK_MEMBER_NAME(animations,"animations");
	HX_MARK_MEMBER_NAME(scene,"scene");
	HX_MARK_MEMBER_NAME(m_id,"m_id");
	::haxor::io::file::AssetXML_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ColladaFile_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(xmlns,"xmlns");
	HX_VISIT_MEMBER_NAME(version,"version");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(geometries,"geometries");
	HX_VISIT_MEMBER_NAME(images,"images");
	HX_VISIT_MEMBER_NAME(controllers,"controllers");
	HX_VISIT_MEMBER_NAME(materials,"materials");
	HX_VISIT_MEMBER_NAME(lights,"lights");
	HX_VISIT_MEMBER_NAME(animations,"animations");
	HX_VISIT_MEMBER_NAME(scene,"scene");
	HX_VISIT_MEMBER_NAME(m_id,"m_id");
	::haxor::io::file::AssetXML_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ColladaFile_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"m_id") ) { return m_id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"xmlns") ) { return xmlns; }
		if (HX_FIELD_EQ(inName,"scene") ) { return scene; }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		if (HX_FIELD_EQ(inName,"_f32a") ) { return _f32a_dyn(); }
		if (HX_FIELD_EQ(inName,"_i16a") ) { return _i16a_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"images") ) { return images; }
		if (HX_FIELD_EQ(inName,"lights") ) { return lights; }
		if (HX_FIELD_EQ(inName,"_i16ta") ) { return _i16ta_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"version") ) { return version; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"materials") ) { return materials; }
		if (HX_FIELD_EQ(inName,"get_asset") ) { return get_asset_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseMesh") ) { return ParseMesh_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"geometries") ) { return geometries; }
		if (HX_FIELD_EQ(inName,"animations") ) { return animations; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"controllers") ) { return controllers; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"FindNodeById") ) { return FindNodeById_dyn(); }
		if (HX_FIELD_EQ(inName,"TraverseStep") ) { return TraverseStep_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"AddAnimations") ) { return AddAnimations_dyn(); }
		if (HX_FIELD_EQ(inName,"FindLightById") ) { return FindLightById_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseGeometry") ) { return ParseGeometry_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ParsePrimitive") ) { return ParsePrimitive_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseInputList") ) { return ParseInputList_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ParseController") ) { return ParseController_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"FindGeometryById") ) { return FindGeometryById_dyn(); }
		if (HX_FIELD_EQ(inName,"FindMaterialById") ) { return FindMaterialById_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseVisualScene") ) { return ParseVisualScene_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"GenerateTriangles") ) { return GenerateTriangles_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseLightLibrary") ) { return ParseLightLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseSceneLibrary") ) { return ParseSceneLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseImageLibrary") ) { return ParseImageLibrary_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"TriangulatePolygon") ) { return TriangulatePolygon_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateMeshRenderer") ) { return CreateMeshRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"FindControllerById") ) { return FindControllerById_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"ParseControllerSkin") ) { return ParseControllerSkin_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"ParseMaterialLibrary") ) { return ParseMaterialLibrary_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseVisualSceneNode") ) { return ParseVisualSceneNode_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseGeometryLibrary") ) { return ParseGeometryLibrary_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"ParseAnimationLibrary") ) { return ParseAnimationLibrary_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"ParseInstanceMaterials") ) { return ParseInstanceMaterials_dyn(); }
		if (HX_FIELD_EQ(inName,"ParseControllerLibrary") ) { return ParseControllerLibrary_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"TraverseVisualSceneNodes") ) { return TraverseVisualSceneNodes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaFile_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::io::file::ColladaAssetData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_id") ) { m_id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"xmlns") ) { xmlns=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scene") ) { scene=inValue.Cast< ::haxor::io::file::ColladaVisualScene >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"images") ) { images=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lights") ) { lights=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"version") ) { version=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"materials") ) { materials=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"geometries") ) { geometries=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"animations") ) { animations=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"controllers") ) { controllers=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaFile_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("xmlns"));
	outFields->push(HX_CSTRING("version"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("geometries"));
	outFields->push(HX_CSTRING("images"));
	outFields->push(HX_CSTRING("controllers"));
	outFields->push(HX_CSTRING("materials"));
	outFields->push(HX_CSTRING("lights"));
	outFields->push(HX_CSTRING("animations"));
	outFields->push(HX_CSTRING("scene"));
	outFields->push(HX_CSTRING("m_id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("GenerateTriangles"),
	HX_CSTRING("TriangulatePolygon"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaFile_obj,xmlns),HX_CSTRING("xmlns")},
	{hx::fsString,(int)offsetof(ColladaFile_obj,version),HX_CSTRING("version")},
	{hx::fsObject /*::haxor::io::file::ColladaAssetData*/ ,(int)offsetof(ColladaFile_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,geometries),HX_CSTRING("geometries")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,images),HX_CSTRING("images")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,controllers),HX_CSTRING("controllers")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,materials),HX_CSTRING("materials")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,lights),HX_CSTRING("lights")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaFile_obj,animations),HX_CSTRING("animations")},
	{hx::fsObject /*::haxor::io::file::ColladaVisualScene*/ ,(int)offsetof(ColladaFile_obj,scene),HX_CSTRING("scene")},
	{hx::fsInt,(int)offsetof(ColladaFile_obj,m_id),HX_CSTRING("m_id")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("xmlns"),
	HX_CSTRING("version"),
	HX_CSTRING("data"),
	HX_CSTRING("geometries"),
	HX_CSTRING("images"),
	HX_CSTRING("controllers"),
	HX_CSTRING("materials"),
	HX_CSTRING("lights"),
	HX_CSTRING("animations"),
	HX_CSTRING("scene"),
	HX_CSTRING("m_id"),
	HX_CSTRING("get_asset"),
	HX_CSTRING("AddAnimations"),
	HX_CSTRING("CreateMeshRenderer"),
	HX_CSTRING("FindLightById"),
	HX_CSTRING("FindGeometryById"),
	HX_CSTRING("FindControllerById"),
	HX_CSTRING("FindNodeById"),
	HX_CSTRING("FindMaterialById"),
	HX_CSTRING("Parse"),
	HX_CSTRING("ParseLightLibrary"),
	HX_CSTRING("ParseAnimationLibrary"),
	HX_CSTRING("ParseMaterialLibrary"),
	HX_CSTRING("ParseSceneLibrary"),
	HX_CSTRING("ParseVisualScene"),
	HX_CSTRING("TraverseVisualSceneNodes"),
	HX_CSTRING("ParseVisualSceneNode"),
	HX_CSTRING("ParseInstanceMaterials"),
	HX_CSTRING("ParseControllerLibrary"),
	HX_CSTRING("ParseController"),
	HX_CSTRING("ParseControllerSkin"),
	HX_CSTRING("ParseImageLibrary"),
	HX_CSTRING("ParseGeometryLibrary"),
	HX_CSTRING("ParseGeometry"),
	HX_CSTRING("ParseMesh"),
	HX_CSTRING("ParsePrimitive"),
	HX_CSTRING("ParseInputList"),
	HX_CSTRING("TraverseStep"),
	HX_CSTRING("_f32a"),
	HX_CSTRING("_i16a"),
	HX_CSTRING("_i16ta"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaFile_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaFile_obj::__mClass,"__mClass");
};

#endif

Class ColladaFile_obj::__mClass;

void ColladaFile_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaFile"), hx::TCanCast< ColladaFile_obj> ,sStaticFields,sMemberFields,
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

void ColladaFile_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
