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
#ifndef INCLUDED_haxor_component_Light
#include <haxor/component/Light.h>
#endif
#ifndef INCLUDED_haxor_component_MeshRenderer
#include <haxor/component/MeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_PointLight
#include <haxor/component/PointLight.h>
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
#ifndef INCLUDED_haxor_io_file_Asset
#include <haxor/io/file/Asset.h>
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
HX_STACK_FRAME("haxor.io.file.ColladaFile","new",0x10d85e4a,"haxor.io.file.ColladaFile.new","haxor/io/file/ColladaFile.hx",127,0xa1888587)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_src,"p_src")
{
	HX_STACK_LINE(128)
	this->xmlns = HX_CSTRING("");
	HX_STACK_LINE(129)
	this->version = HX_CSTRING("");
	HX_STACK_LINE(130)
	::haxor::io::file::ColladaAssetData _g = ::haxor::io::file::ColladaAssetData_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(130)
	this->data = _g;
	HX_STACK_LINE(131)
	this->geometries = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(132)
	this->images = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(133)
	this->controllers = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(134)
	this->materials = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(135)
	this->animations = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(136)
	this->lights = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(137)
	this->scene = null();
	HX_STACK_LINE(138)
	Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(138)
	Float _g2 = (_g1 * (int)16777215);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(138)
	int _g3 = ::Std_obj::_int(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(138)
	this->m_id = _g3;
	HX_STACK_LINE(140)
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
	HX_STACK_FRAME("haxor.io.file.ColladaFile","get_asset",0x0a6d9fb1,"haxor.io.file.ColladaFile.get_asset","haxor/io/file/ColladaFile.hx",146,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(145)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(147)
	Array< ::Dynamic > re = Array_obj< ::Dynamic >::__new().Add(::haxor::core::Entity_obj::__new(null()));		HX_STACK_VAR(re,"re");
	HX_STACK_LINE(148)
	re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(HX_CSTRING("collada_asset"));
	HX_STACK_LINE(149)
	if (((this->scene == null()))){
		HX_STACK_LINE(151)
		::haxor::core::Console_obj::LogError(HX_CSTRING("ColladaFile> Trying to get asset of NULL scene."),null());
		HX_STACK_LINE(152)
		return re->__get((int)0).StaticCast< ::haxor::core::Entity >();
	}
	HX_STACK_LINE(155)
	if (((this->scene->name != HX_CSTRING("")))){
		HX_STACK_LINE(155)
		re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(this->scene->name);
	}
	else{
		HX_STACK_LINE(156)
		if (((this->scene->id != HX_CSTRING("")))){
			HX_STACK_LINE(156)
			re->__get((int)0).StaticCast< ::haxor::core::Entity >()->set_name(this->scene->id);
		}
	}
	HX_STACK_LINE(158)
	Array< ::Dynamic > hm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(hm,"hm");
	HX_STACK_LINE(159)
	Array< ::Dynamic > cm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(cm,"cm");
	HX_STACK_LINE(160)
	Array< ::Dynamic > mm = Array_obj< ::Dynamic >::__new().Add(::haxe::ds::ObjectMap_obj::__new());		HX_STACK_VAR(mm,"mm");
	HX_STACK_LINE(162)
	Array< ::Dynamic > joint_transforms = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(joint_transforms,"joint_transforms");
	HX_STACK_LINE(163)
	Array< ::Dynamic > joint_nodes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(joint_nodes,"joint_nodes");
	HX_STACK_LINE(164)
	Array< ::Dynamic > skinned_meshes = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(skinned_meshes,"skinned_meshes");
	HX_STACK_LINE(166)
	{
		HX_STACK_LINE(166)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(166)
		int _g = this->materials->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(166)
		while((true)){
			HX_STACK_LINE(166)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(166)
				break;
			}
			HX_STACK_LINE(166)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(168)
			::haxor::io::file::ColladaMaterial m = this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(170)
			::String mn = m->name;		HX_STACK_VAR(mn,"mn");
			HX_STACK_LINE(171)
			{
				HX_STACK_LINE(171)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(171)
				while((true)){
					HX_STACK_LINE(171)
					if ((!(((_g2 < (int)10))))){
						HX_STACK_LINE(171)
						break;
					}
					HX_STACK_LINE(171)
					int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(171)
					::String _g4 = ::StringTools_obj::replace(mn,(HX_CSTRING("_") + i1),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(171)
					mn = _g4;
				}
			}
			HX_STACK_LINE(172)
			::String _g11 = ::StringTools_obj::replace(mn,HX_CSTRING("_"),HX_CSTRING("/"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(172)
			mn = _g11;
			HX_STACK_LINE(173)
			::haxor::graphics::material::Material mat = ::haxor::io::file::Asset_obj::Get(mn);		HX_STACK_VAR(mat,"mat");
			HX_STACK_LINE(175)
			if (((mat == null()))){
				HX_STACK_LINE(177)
				::haxor::graphics::material::Material _g2 = ::haxor::graphics::material::Material_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(177)
				mat = _g2;
				HX_STACK_LINE(178)
				mat->set_name(mn);
				HX_STACK_LINE(179)
				Dynamic _g31 = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("haxor/unlit/FlatTexture"));		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(179)
				mat->set_shader(_g31);
				HX_STACK_LINE(180)
				::haxor::io::file::Asset_obj::Add(mn,mat);
			}
			HX_STACK_LINE(182)
			mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(m,mat);
		}
	}

	HX_BEGIN_LOCAL_FUNC_S8(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,joint_nodes,Array< ::Dynamic >,skinned_meshes,Array< ::Dynamic >,hm,Array< ::Dynamic >,re,Array< ::Dynamic >,joint_transforms,Array< ::Dynamic >,cm,Array< ::Dynamic >,_g3,Array< ::Dynamic >,mm)
	Void run(::haxor::io::file::ColladaNode n){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/io/file/ColladaFile.hx",186,0xa1888587)
		HX_STACK_ARG(n,"n")
		{
			HX_STACK_LINE(187)
			::haxor::core::Entity pe;		HX_STACK_VAR(pe,"pe");
			HX_STACK_LINE(187)
			if (((n->parent == null()))){
				HX_STACK_LINE(187)
				pe = re->__get((int)0).StaticCast< ::haxor::core::Entity >();
			}
			else{
				struct _Function_3_1{
					inline static bool Block( Array< ::Dynamic > &hm,::haxor::io::file::ColladaNode &n){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",187,0xa1888587)
						{
							HX_STACK_LINE(187)
							int _g = ::__hxcpp_obj_id(n->parent);		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(187)
							return hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g);
						}
						return null();
					}
				};
				HX_STACK_LINE(187)
				if ((_Function_3_1::Block(hm,n))){
					HX_STACK_LINE(187)
					pe = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(n->parent);
				}
				else{
					HX_STACK_LINE(187)
					pe = re->__get((int)0).StaticCast< ::haxor::core::Entity >();
				}
			}
			HX_STACK_LINE(188)
			::haxor::core::Entity ne = null();		HX_STACK_VAR(ne,"ne");
			HX_STACK_LINE(189)
			if (((n->name == HX_CSTRING("EnvironmentAmbientLight")))){
				HX_STACK_LINE(189)
				return null();
			}
			HX_STACK_LINE(190)
			ne = ::haxor::core::Entity_obj::__new(null());
			HX_STACK_LINE(191)
			ne->set_name((HX_CSTRING("node") + ne->get_uid()));
			HX_STACK_LINE(192)
			if (((n->sid != HX_CSTRING("")))){
				HX_STACK_LINE(192)
				ne->set_name(n->sid);
			}
			else{
				HX_STACK_LINE(193)
				if (((n->id != HX_CSTRING("")))){
					HX_STACK_LINE(193)
					ne->set_name(n->id);
				}
				else{
					HX_STACK_LINE(194)
					if (((n->name != HX_CSTRING("")))){
						HX_STACK_LINE(194)
						ne->set_name(n->name);
					}
				}
			}
			HX_STACK_LINE(195)
			if (((n->type == HX_CSTRING("joint")))){
				HX_STACK_LINE(197)
				joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(ne->m_transform);
				HX_STACK_LINE(198)
				joint_nodes->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(n);
			}
			HX_STACK_LINE(200)
			ne->m_transform->set_parent(pe->m_transform);
			HX_STACK_LINE(201)
			ne->m_transform->set_localPosition(n->position);
			HX_STACK_LINE(202)
			ne->m_transform->set_localRotation(n->rotation);
			HX_STACK_LINE(203)
			ne->m_transform->set_localScale(n->scale);
			HX_STACK_LINE(205)
			if (((n->data != HX_CSTRING("")))){
				HX_STACK_LINE(207)
				::haxor::component::DataComponent ad = ne->AddComponent(hx::ClassOf< ::haxor::component::DataComponent >());		HX_STACK_VAR(ad,"ad");
				HX_STACK_LINE(208)
				try
				{
				HX_STACK_CATCHABLE(Dynamic, 0);
				{
					HX_STACK_LINE(210)
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
			HX_STACK_LINE(265)
			hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(n,ne);
			HX_STACK_LINE(266)
			{
				HX_STACK_LINE(266)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(266)
				int _g = n->instances->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(266)
				while(((_g1 < _g))){
					HX_STACK_LINE(266)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(268)
					::haxor::io::file::ColladaInstance ci = n->instances->__get(i).StaticCast< ::haxor::io::file::ColladaInstance >();		HX_STACK_VAR(ci,"ci");
					HX_STACK_LINE(269)
					::haxor::component::MeshRenderer mr = null();		HX_STACK_VAR(mr,"mr");
					HX_STACK_LINE(270)
					::haxor::io::file::ColladaMaterial cmat = null();		HX_STACK_VAR(cmat,"cmat");
					HX_STACK_LINE(271)
					::haxor::io::file::ColladaGeometry cg = null();		HX_STACK_VAR(cg,"cg");
					HX_STACK_LINE(272)
					::haxor::io::file::ColladaController cc = null();		HX_STACK_VAR(cc,"cc");
					HX_STACK_LINE(273)
					::String cg_target = HX_CSTRING("");		HX_STACK_VAR(cg_target,"cg_target");
					HX_STACK_LINE(275)
					{
						HX_STACK_LINE(275)
						::String _g2 = ci->type;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(275)
						::String _switch_1 = (_g2);
						if (  ( _switch_1==HX_CSTRING("light"))){
							HX_STACK_LINE(279)
							::haxor::io::file::ColladaLight cl = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindLightById(ci->target);		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(281)
							if (((cl == null()))){
								HX_STACK_LINE(281)
								continue;
							}
							HX_STACK_LINE(283)
							{
								HX_STACK_LINE(283)
								::String _g4 = cl->type;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(283)
								::String _switch_2 = (_g4);
								if (  ( _switch_2==HX_CSTRING("ambient"))){
								}
								else if (  ( _switch_2==HX_CSTRING("point"))){
									HX_STACK_LINE(287)
									::haxor::component::PointLight pl = ne->AddComponent(hx::ClassOf< ::haxor::component::PointLight >());		HX_STACK_VAR(pl,"pl");
									HX_STACK_LINE(288)
									pl->color->SetColor(cl->color);
									HX_STACK_LINE(289)
									pl->intensity = cl->intensity;
									HX_STACK_LINE(290)
									pl->radius = (cl->radius * 2.0);
									HX_STACK_LINE(291)
									pl->atten = cl->atten;
								}
								else if (  ( _switch_2==HX_CSTRING("directional"))){
								}
							}
							HX_STACK_LINE(299)
							continue;
						}
						else if (  ( _switch_1==HX_CSTRING("geometry"))){
							HX_STACK_LINE(302)
							cg_target = ci->target;
						}
						else if (  ( _switch_1==HX_CSTRING("controller"))){
							HX_STACK_LINE(304)
							cc = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindControllerById(ci->target);
							HX_STACK_LINE(305)
							if (((cc != null()))){
								HX_STACK_LINE(307)
								cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->set(ne->m_transform,cc);
								HX_STACK_LINE(308)
								cg_target = cc->source;
							}
						}
					}
					HX_STACK_LINE(314)
					cg = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindGeometryById(cg_target);
					HX_STACK_LINE(315)
					if (((cg != null()))){
						HX_STACK_LINE(317)
						int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(317)
						int _g2 = cg->mesh->primitives->length;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(317)
						while(((_g4 < _g2))){
							HX_STACK_LINE(317)
							int i1 = (_g4)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(319)
							::String mn = cg->mesh->primitives->__get(i1).StaticCast< ::haxor::io::file::ColladaPrimitive >()->material;		HX_STACK_VAR(mn,"mn");
							HX_STACK_LINE(320)
							cmat = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->FindMaterialById(mn);
							HX_STACK_LINE(322)
							mr = _g3->__get((int)0).StaticCast< ::haxor::io::file::ColladaFile >()->CreateMeshRenderer(ne,cg_target,cg->mesh->primitives->__get(i1).StaticCast< ::haxor::io::file::ColladaPrimitive >(),(  (((cc == null()))) ? ::Class(hx::ClassOf< ::haxor::component::MeshRenderer >()) : ::Class(hx::ClassOf< ::haxor::component::SkinnedMeshRenderer >()) ),cc);
							HX_STACK_LINE(324)
							if (((cc != null()))){
								HX_STACK_LINE(324)
								skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->push(mr);
							}
							HX_STACK_LINE(325)
							if (((cmat != null()))){
								struct _Function_7_1{
									inline static bool Block( ::haxor::io::file::ColladaMaterial &cmat,Array< ::Dynamic > &mm){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",327,0xa1888587)
										{
											HX_STACK_LINE(327)
											int _g5 = ::__hxcpp_obj_id(cmat);		HX_STACK_VAR(_g5,"_g5");
											HX_STACK_LINE(327)
											return mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g5);
										}
										return null();
									}
								};
								HX_STACK_LINE(327)
								mr->set_material((  ((_Function_7_1::Block(cmat,mm))) ? ::haxor::graphics::material::Material(mm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(cmat)) : ::haxor::graphics::material::Material(mr->m_material) ));
							}
							else{
								HX_STACK_LINE(331)
								{
									HX_STACK_LINE(331)
									int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
									HX_STACK_LINE(331)
									while(((_g5 < (int)10))){
										HX_STACK_LINE(331)
										int i2 = (_g5)++;		HX_STACK_VAR(i2,"i2");
										HX_STACK_LINE(331)
										mn = ::StringTools_obj::replace(mn,(HX_CSTRING("_") + i2),HX_CSTRING(""));
									}
								}
								HX_STACK_LINE(332)
								mn = ::StringTools_obj::replace(mn,HX_CSTRING("_"),HX_CSTRING("/"));
								HX_STACK_LINE(333)
								::haxor::graphics::material::Material mat = ::haxor::io::file::Asset_obj::Get(mn);		HX_STACK_VAR(mat,"mat");
								HX_STACK_LINE(334)
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

	HX_STACK_LINE(185)
	this->scene->Traverse( Dynamic(new _Function_1_1(joint_nodes,skinned_meshes,hm,re,joint_transforms,cm,_g3,mm)));
	HX_STACK_LINE(341)
	{
		HX_STACK_LINE(341)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(341)
		int _g = skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(341)
		while((true)){
			HX_STACK_LINE(341)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(341)
				break;
			}
			HX_STACK_LINE(341)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(343)
			::haxor::component::SkinnedMeshRenderer skr = skinned_meshes->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(i).StaticCast< ::haxor::component::SkinnedMeshRenderer >();		HX_STACK_VAR(skr,"skr");
			HX_STACK_LINE(344)
			::haxor::io::file::ColladaController cc;		HX_STACK_VAR(cc,"cc");
			struct _Function_3_1{
				inline static bool Block( ::haxor::component::SkinnedMeshRenderer &skr,Array< ::Dynamic > &cm){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",344,0xa1888587)
					{
						HX_STACK_LINE(344)
						int _g2 = ::__hxcpp_obj_id(skr->m_entity->m_transform);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(344)
						return cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->__Internal->exists(_g2);
					}
					return null();
				}
			};
			HX_STACK_LINE(344)
			if ((_Function_3_1::Block(skr,cm))){
				HX_STACK_LINE(344)
				cc = cm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(skr->m_entity->m_transform);
			}
			else{
				HX_STACK_LINE(344)
				cc = null();
			}
			HX_STACK_LINE(345)
			if (((cc == null()))){
				HX_STACK_LINE(345)
				continue;
			}
			HX_STACK_LINE(346)
			skr->set_joints(Array_obj< ::Dynamic >::__new());
			HX_STACK_LINE(348)
			{
				HX_STACK_LINE(348)
				int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(348)
				int _g2 = cc->joints->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(348)
				while((true)){
					HX_STACK_LINE(348)
					if ((!(((_g31 < _g2))))){
						HX_STACK_LINE(348)
						break;
					}
					HX_STACK_LINE(348)
					int j = (_g31)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(349)
					int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(349)
					int _g4 = joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->length;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(349)
					while((true)){
						HX_STACK_LINE(349)
						if ((!(((_g5 < _g4))))){
							HX_STACK_LINE(349)
							break;
						}
						HX_STACK_LINE(349)
						int k = (_g5)++;		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(351)
						::String _g41 = joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(k).StaticCast< ::haxor::component::Transform >()->get_name();		HX_STACK_VAR(_g41,"_g41");
						HX_STACK_LINE(351)
						if (((_g41 == cc->joints->__get(j)))){
							HX_STACK_LINE(355)
							skr->m_joints->push(joint_transforms->__get((int)0).StaticCast< Array< ::Dynamic > >()->__get(k).StaticCast< ::haxor::component::Transform >());
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(361)
	Dynamic nit = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->keys();		HX_STACK_VAR(nit,"nit");
	HX_STACK_LINE(362)
	while((true)){
		HX_STACK_LINE(362)
		if ((!(nit->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(362)
			break;
		}
		HX_STACK_LINE(364)
		::haxor::io::file::ColladaNode n = nit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(365)
		::haxor::core::Entity e = hm->__get((int)0).StaticCast< ::haxe::ds::ObjectMap >()->get(n);		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(366)
		if (((e == re->__get((int)0).StaticCast< ::haxor::core::Entity >()))){
			HX_STACK_LINE(366)
			continue;
		}
		HX_STACK_LINE(367)
		e->set_name(n->name);
	}
	HX_STACK_LINE(369)
	this->AddAnimations(re->__get((int)0).StaticCast< ::haxor::core::Entity >(),null());
	HX_STACK_LINE(370)
	if (((this->data->axis == HX_CSTRING("z_up")))){
		HX_STACK_LINE(372)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(372)
		::haxor::math::Quaternion _g6 = ::haxor::math::Quaternion_obj::FromAxisAngle(_g5,-90.0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(372)
		re->__get((int)0).StaticCast< ::haxor::core::Entity >()->m_transform->set_rotation(_g6);
	}
	HX_STACK_LINE(374)
	return re->__get((int)0).StaticCast< ::haxor::core::Entity >();
}


Void ColladaFile_obj::AddAnimations( ::haxor::core::Entity p_entity,hx::Null< bool >  __o_p_exact){
bool p_exact = __o_p_exact.Default(true);
	HX_STACK_FRAME("haxor.io.file.ColladaFile","AddAnimations",0xdf3aa4ba,"haxor.io.file.ColladaFile.AddAnimations","haxor/io/file/ColladaFile.hx",384,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_entity,"p_entity")
	HX_STACK_ARG(p_exact,"p_exact")
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,AddAnimations,(void))

::haxor::component::MeshRenderer ColladaFile_obj::CreateMeshRenderer( ::haxor::core::Entity e,::String msh,::haxor::io::file::ColladaPrimitive cp,::Class t,::haxor::io::file::ColladaController cc){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","CreateMeshRenderer",0xe09e0ae2,"haxor.io.file.ColladaFile.CreateMeshRenderer","haxor/io/file/ColladaFile.hx",437,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(e,"e")
	HX_STACK_ARG(msh,"msh")
	HX_STACK_ARG(cp,"cp")
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(cc,"cc")
	HX_STACK_LINE(438)
	::haxor::component::MeshRenderer r = e->AddComponent(t);		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(440)
	::String mid = ((msh + HX_CSTRING("_")) + this->m_id);		HX_STACK_VAR(mid,"mid");
	HX_STACK_LINE(442)
	::haxor::graphics::mesh::Mesh3 m = ::haxor::io::file::Asset_obj::Get(mid);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(444)
	if (((m != null()))){
		HX_STACK_LINE(446)
		r->set_mesh(m);
		HX_STACK_LINE(447)
		return r;
	}
	HX_STACK_LINE(450)
	Array< ::Dynamic > mv = cp->GetTriangulatedVectorArray(HX_CSTRING("vertex"),null(),null());		HX_STACK_VAR(mv,"mv");
	HX_STACK_LINE(451)
	Array< ::Dynamic > mn = cp->GetTriangulatedVectorArray(HX_CSTRING("normal"),null(),null());		HX_STACK_VAR(mn,"mn");
	HX_STACK_LINE(452)
	Array< ::Dynamic > mc = cp->GetTriangulatedVectorArray(HX_CSTRING("color"),null(),null());		HX_STACK_VAR(mc,"mc");
	HX_STACK_LINE(453)
	Array< ::Dynamic > muv0 = cp->GetTriangulatedVectorArray(HX_CSTRING("texcoord"),(int)0,null());		HX_STACK_VAR(muv0,"muv0");
	HX_STACK_LINE(454)
	Array< ::Dynamic > muv1 = cp->GetTriangulatedVectorArray(HX_CSTRING("texcoord"),(int)1,null());		HX_STACK_VAR(muv1,"muv1");
	HX_STACK_LINE(455)
	Array< ::Dynamic > mbn = cp->GetTriangulatedVectorArray(HX_CSTRING("texbinormal"),null(),null());		HX_STACK_VAR(mbn,"mbn");
	HX_STACK_LINE(456)
	Array< ::Dynamic > mtg = cp->GetTriangulatedVectorArray(HX_CSTRING("textangent"),null(),null());		HX_STACK_VAR(mtg,"mtg");
	HX_STACK_LINE(458)
	bool is_skinned = ::Std_obj::is(r,hx::ClassOf< ::haxor::component::SkinnedMeshRenderer >());		HX_STACK_VAR(is_skinned,"is_skinned");
	HX_STACK_LINE(460)
	::haxor::graphics::mesh::Mesh3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(460)
	if ((is_skinned)){
		HX_STACK_LINE(460)
		_g = ::haxor::graphics::mesh::SkinnedMesh3_obj::__new(null());
	}
	else{
		HX_STACK_LINE(460)
		_g = ::haxor::graphics::mesh::Mesh3_obj::__new(null());
	}
	HX_STACK_LINE(460)
	m = _g;
	HX_STACK_LINE(461)
	m->set_name(mid);
	HX_STACK_LINE(463)
	::haxor::io::file::Asset_obj::Add(mid,m);
	HX_STACK_LINE(465)
	if (((mc->length > (int)0))){
		HX_STACK_LINE(465)
		m->set_color(mc);
	}
	HX_STACK_LINE(466)
	if (((muv0->length > (int)0))){
		HX_STACK_LINE(466)
		m->set_uv0(muv0);
	}
	HX_STACK_LINE(467)
	if (((muv1->length > (int)0))){
		HX_STACK_LINE(467)
		m->set_uv1(muv1);
	}
	HX_STACK_LINE(469)
	if ((is_skinned)){
		HX_STACK_LINE(471)
		if (((cc != null()))){
			HX_STACK_LINE(473)
			cc->GenerateBonesAndWeights();
			HX_STACK_LINE(475)
			::haxor::graphics::mesh::SkinnedMesh3 skm = m;		HX_STACK_VAR(skm,"skm");
			HX_STACK_LINE(476)
			Array< ::Dynamic > mvw = cc->GetTriangulatedWeights(cp);		HX_STACK_VAR(mvw,"mvw");
			HX_STACK_LINE(477)
			Array< ::Dynamic > mbi = cc->GetTriangulatedBones(cp);		HX_STACK_VAR(mbi,"mbi");
			HX_STACK_LINE(478)
			Array< ::Dynamic > mbm = cc->GetBinds();		HX_STACK_VAR(mbm,"mbm");
			HX_STACK_LINE(479)
			skm->set_binds(mbm);
			HX_STACK_LINE(480)
			skm->set_weight(mvw);
			HX_STACK_LINE(481)
			skm->set_bone(mbi);
			HX_STACK_LINE(482)
			::haxor::math::Matrix4 bsm = cc->GetBSM();		HX_STACK_VAR(bsm,"bsm");
			HX_STACK_LINE(484)
			{
				HX_STACK_LINE(484)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(484)
				int _g2 = mv->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(484)
				while((true)){
					HX_STACK_LINE(484)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(484)
						break;
					}
					HX_STACK_LINE(484)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(484)
					{
						HX_STACK_LINE(484)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(484)
						{
							HX_STACK_LINE(484)
							::haxor::math::Vector3 _this = mv->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(484)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(484)
						Float vx = ((((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z)) + bsm->m03);		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(484)
						Float vy = ((((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z)) + bsm->m13);		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(484)
						Float vz = ((((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z)) + bsm->m23);		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(484)
						p_point->x = vx;
						HX_STACK_LINE(484)
						p_point->y = vy;
						HX_STACK_LINE(484)
						p_point->z = vz;
						HX_STACK_LINE(484)
						mv[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(485)
			{
				HX_STACK_LINE(485)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(485)
				int _g2 = mn->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(485)
				while((true)){
					HX_STACK_LINE(485)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(485)
						break;
					}
					HX_STACK_LINE(485)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(485)
					{
						HX_STACK_LINE(485)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(485)
						{
							HX_STACK_LINE(485)
							::haxor::math::Vector3 _this = mn->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(485)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(485)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(485)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(485)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(485)
						p_point->x = vx;
						HX_STACK_LINE(485)
						p_point->y = vy;
						HX_STACK_LINE(485)
						p_point->z = vz;
						HX_STACK_LINE(485)
						mn[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(486)
			{
				HX_STACK_LINE(486)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(486)
				int _g2 = mbn->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(486)
				while((true)){
					HX_STACK_LINE(486)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(486)
						break;
					}
					HX_STACK_LINE(486)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(486)
					{
						HX_STACK_LINE(486)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(486)
						{
							HX_STACK_LINE(486)
							::haxor::math::Vector3 _this = mbn->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(486)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(486)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(486)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(486)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(486)
						p_point->x = vx;
						HX_STACK_LINE(486)
						p_point->y = vy;
						HX_STACK_LINE(486)
						p_point->z = vz;
						HX_STACK_LINE(486)
						mbn[i] = p_point;
					}
				}
			}
			HX_STACK_LINE(487)
			{
				HX_STACK_LINE(487)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(487)
				int _g2 = mtg->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(487)
				while((true)){
					HX_STACK_LINE(487)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(487)
						break;
					}
					HX_STACK_LINE(487)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(487)
					{
						HX_STACK_LINE(487)
						::haxor::math::Vector3 p_point;		HX_STACK_VAR(p_point,"p_point");
						HX_STACK_LINE(487)
						{
							HX_STACK_LINE(487)
							::haxor::math::Vector3 _this = mtg->__get(i).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(487)
							p_point = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(487)
						Float vx = (((bsm->m00 * p_point->x) + (bsm->m01 * p_point->y)) + (bsm->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(487)
						Float vy = (((bsm->m10 * p_point->x) + (bsm->m11 * p_point->y)) + (bsm->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(487)
						Float vz = (((bsm->m20 * p_point->x) + (bsm->m21 * p_point->y)) + (bsm->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(487)
						p_point->x = vx;
						HX_STACK_LINE(487)
						p_point->y = vy;
						HX_STACK_LINE(487)
						p_point->z = vz;
						HX_STACK_LINE(487)
						mtg[i] = p_point;
					}
				}
			}
		}
	}
	HX_STACK_LINE(491)
	if (((mv->length > (int)0))){
		HX_STACK_LINE(491)
		m->set_vertex(mv);
	}
	HX_STACK_LINE(492)
	if (((mn->length > (int)0))){
		HX_STACK_LINE(492)
		m->set_normal(mn);
	}
	HX_STACK_LINE(493)
	if (((mbn->length > (int)0))){
		HX_STACK_LINE(493)
		m->set_binormal(mbn);
	}
	HX_STACK_LINE(494)
	if (((mtg->length > (int)0))){
		HX_STACK_LINE(494)
		m->set_tangent(mtg);
	}
	HX_STACK_LINE(498)
	m->GenerateBounds();
	HX_STACK_LINE(499)
	r->set_mesh(m);
	HX_STACK_LINE(500)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC5(ColladaFile_obj,CreateMeshRenderer,return )

::haxor::io::file::ColladaLight ColladaFile_obj::FindLightById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindLightById",0x8cc7c059,"haxor.io.file.ColladaFile.FindLightById","haxor/io/file/ColladaFile.hx",503,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(503)
	{
		HX_STACK_LINE(503)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(503)
		int _g = this->lights->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(503)
		while((true)){
			HX_STACK_LINE(503)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(503)
				break;
			}
			HX_STACK_LINE(503)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(503)
			if (((this->lights->__get(i).StaticCast< ::haxor::io::file::ColladaLight >()->id == p_id))){
				HX_STACK_LINE(503)
				return this->lights->__get(i).StaticCast< ::haxor::io::file::ColladaLight >();
			}
		}
	}
	HX_STACK_LINE(503)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindLightById,return )

::haxor::io::file::ColladaGeometry ColladaFile_obj::FindGeometryById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindGeometryById",0xe813db33,"haxor.io.file.ColladaFile.FindGeometryById","haxor/io/file/ColladaFile.hx",505,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(505)
	{
		HX_STACK_LINE(505)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(505)
		int _g = this->geometries->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(505)
		while((true)){
			HX_STACK_LINE(505)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(505)
				break;
			}
			HX_STACK_LINE(505)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(505)
			if (((this->geometries->__get(i).StaticCast< ::haxor::io::file::ColladaGeometry >()->id == p_id))){
				HX_STACK_LINE(505)
				return this->geometries->__get(i).StaticCast< ::haxor::io::file::ColladaGeometry >();
			}
		}
	}
	HX_STACK_LINE(505)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindGeometryById,return )

::haxor::io::file::ColladaController ColladaFile_obj::FindControllerById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindControllerById",0x0fb6ffdd,"haxor.io.file.ColladaFile.FindControllerById","haxor/io/file/ColladaFile.hx",507,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(507)
	{
		HX_STACK_LINE(507)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(507)
		int _g = this->controllers->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(507)
		while((true)){
			HX_STACK_LINE(507)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(507)
				break;
			}
			HX_STACK_LINE(507)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(507)
			if (((this->controllers->__get(i).StaticCast< ::haxor::io::file::ColladaController >()->id == p_id))){
				HX_STACK_LINE(507)
				return this->controllers->__get(i).StaticCast< ::haxor::io::file::ColladaController >();
			}
		}
	}
	HX_STACK_LINE(507)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindControllerById,return )

::haxor::io::file::ColladaNode ColladaFile_obj::FindNodeById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindNodeById",0x2743f703,"haxor.io.file.ColladaFile.FindNodeById","haxor/io/file/ColladaFile.hx",509,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(509)
	Array< ::String > p_id1 = Array_obj< ::String >::__new().Add(p_id);		HX_STACK_VAR(p_id1,"p_id1");
	HX_STACK_LINE(511)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new().Add(null());		HX_STACK_VAR(res,"res");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,res,Array< ::String >,p_id1)
	Void run(::haxor::io::file::ColladaNode it){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/io/file/ColladaFile.hx",514,0xa1888587)
		HX_STACK_ARG(it,"it")
		{
			HX_STACK_LINE(514)
			if (((it->id == p_id1->__get((int)0)))){
				HX_STACK_LINE(514)
				res[(int)0] = it;
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(512)
	this->scene->Traverse( Dynamic(new _Function_1_1(res,p_id1)));
	HX_STACK_LINE(516)
	return res->__get((int)0).StaticCast< ::haxor::io::file::ColladaNode >();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindNodeById,return )

::haxor::io::file::ColladaMaterial ColladaFile_obj::FindMaterialById( ::String p_id){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","FindMaterialById",0x6edcd3a8,"haxor.io.file.ColladaFile.FindMaterialById","haxor/io/file/ColladaFile.hx",520,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_LINE(521)
	{
		HX_STACK_LINE(521)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(521)
		int _g = this->materials->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(521)
		while((true)){
			HX_STACK_LINE(521)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(521)
				break;
			}
			HX_STACK_LINE(521)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(523)
			if (((this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >()->id == p_id))){
				HX_STACK_LINE(523)
				return this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();
			}
			else{
				HX_STACK_LINE(525)
				if (((this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >()->name == p_id))){
					HX_STACK_LINE(525)
					return this->materials->__get(i).StaticCast< ::haxor::io::file::ColladaMaterial >();
				}
			}
		}
	}
	HX_STACK_LINE(527)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,FindMaterialById,return )

Void ColladaFile_obj::Parse( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","Parse",0xf5b65c7d,"haxor.io.file.ColladaFile.Parse","haxor/io/file/ColladaFile.hx",532,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(532)
		::String _g = n->get_nodeName();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(532)
		::String _switch_3 = (_g);
		if (  ( _switch_3==HX_CSTRING("COLLADA"))){
			HX_STACK_LINE(535)
			::String _g1 = this->_a(n,HX_CSTRING("xmlns"),HX_CSTRING(""));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(535)
			this->xmlns = _g1;
			HX_STACK_LINE(536)
			::String _g11 = this->_a(n,HX_CSTRING("version"),HX_CSTRING("0.0"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(536)
			this->version = _g11;
		}
		else if (  ( _switch_3==HX_CSTRING("asset"))){
			HX_STACK_LINE(539)
			Dynamic _g2 = this->_p(n,HX_CSTRING("contributor.author.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(539)
			this->data->author = _g2;
			HX_STACK_LINE(540)
			Dynamic _g3 = this->_p(n,HX_CSTRING("contributor.authoring_tool.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(540)
			this->data->tool = _g3;
			HX_STACK_LINE(541)
			Dynamic _g4 = this->_p(n,HX_CSTRING("contributor.source_data.$text"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(541)
			this->data->source = _g4;
			HX_STACK_LINE(542)
			Dynamic _g5 = this->_p(n,HX_CSTRING("up_axis.$text"),HX_CSTRING("y_up"),null(),null())->__Field(HX_CSTRING("toLowerCase"),true)();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(542)
			this->data->axis = _g5;
			HX_STACK_LINE(543)
			Dynamic _g6 = this->_p(n,HX_CSTRING("created.$text"),HX_CSTRING("00/00/00"),null(),null());		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(543)
			this->data->creation = _g6;
			HX_STACK_LINE(544)
			Dynamic _g7 = this->_p(n,HX_CSTRING("modified.$text"),HX_CSTRING("00/00/00"),null(),null());		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(544)
			this->data->modification = _g7;
			HX_STACK_LINE(545)
			Dynamic _g8 = this->_p(n,HX_CSTRING("unit.@name"),HX_CSTRING("none"),null(),null());		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(545)
			this->data->unitName = _g8;
			HX_STACK_LINE(546)
			Dynamic _g9 = this->_p(n,HX_CSTRING("unit.@meter"),HX_CSTRING("0.0"),null(),null());		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(546)
			Float _g10 = ::Std_obj::parseFloat(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(546)
			this->data->unitValue = _g10;
		}
		else if (  ( _switch_3==HX_CSTRING("library_effects"))){
		}
		else if (  ( _switch_3==HX_CSTRING("library_materials"))){
			HX_STACK_LINE(549)
			this->ParseMaterialLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("scene"))){
		}
		else if (  ( _switch_3==HX_CSTRING("library_geometries"))){
			HX_STACK_LINE(552)
			this->ParseGeometryLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("library_controllers"))){
			HX_STACK_LINE(553)
			this->ParseControllerLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("library_images"))){
			HX_STACK_LINE(554)
			this->ParseImageLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("library_visual_scenes"))){
			HX_STACK_LINE(555)
			this->ParseSceneLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("library_animations"))){
			HX_STACK_LINE(556)
			this->ParseAnimationLibrary(n);
		}
		else if (  ( _switch_3==HX_CSTRING("library_lights"))){
			HX_STACK_LINE(557)
			this->ParseLightLibrary(n);
		}
	}
return null();
}


Void ColladaFile_obj::ParseLightLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseLightLibrary",0x528214e2,"haxor.io.file.ColladaFile.ParseLightLibrary","haxor/io/file/ColladaFile.hx",563,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(564)
		Dynamic it = n->elementsNamed(HX_CSTRING("light"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(565)
		::haxor::io::file::ColladaLight l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(566)
		Dynamic lit;		HX_STACK_VAR(lit,"lit");
		HX_STACK_LINE(567)
		::Xml ln;		HX_STACK_VAR(ln,"ln");
		HX_STACK_LINE(568)
		while((true)){
			HX_STACK_LINE(568)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(568)
				break;
			}
			HX_STACK_LINE(570)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(570)
			n = _g;
			HX_STACK_LINE(571)
			::haxor::io::file::ColladaLight _g1 = ::haxor::io::file::ColladaLight_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(571)
			l = _g1;
			HX_STACK_LINE(572)
			Dynamic _g2 = this->_p(n,HX_CSTRING("@id"),(HX_CSTRING("light") + this->lights->length),null(),null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(572)
			l->id = _g2;
			HX_STACK_LINE(573)
			Dynamic _g3 = this->_p(n,HX_CSTRING("@name"),l->id,null(),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(573)
			l->name = _g3;
			HX_STACK_LINE(575)
			this->lights->push(l);
			HX_STACK_LINE(577)
			Dynamic _g4 = n->elementsNamed(HX_CSTRING("technique_common"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(577)
			lit = _g4;
			HX_STACK_LINE(578)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(578)
				continue;
			}
			HX_STACK_LINE(578)
			Dynamic _g5 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elements"),true)();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(578)
			lit = _g5;
			HX_STACK_LINE(579)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(579)
				continue;
			}
			HX_STACK_LINE(579)
			::Xml _g6 = lit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(579)
			ln = _g6;
			HX_STACK_LINE(581)
			::String _g7 = ln->get_nodeName().toLowerCase();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(581)
			l->type = _g7;
			HX_STACK_LINE(583)
			Array< Float > ca = Array_obj< Float >::__new().Add((int)1).Add((int)1).Add((int)1).Add((int)1);		HX_STACK_VAR(ca,"ca");
			HX_STACK_LINE(584)
			{
				HX_STACK_LINE(584)
				::String _g8 = l->type;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(584)
				::String _switch_4 = (_g8);
				if (  ( _switch_4==HX_CSTRING("point"))){
					HX_STACK_LINE(586)
					Dynamic _g81 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g81,"_g81");
					HX_STACK_LINE(586)
					Array< Float > _g9 = this->_f32a(_g81);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(586)
					ca = _g9;
				}
				else if (  ( _switch_4==HX_CSTRING("ambient"))){
					HX_STACK_LINE(587)
					Dynamic _g10 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(587)
					Array< Float > _g11 = this->_f32a(_g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(587)
					ca = _g11;
				}
				else if (  ( _switch_4==HX_CSTRING("directional"))){
					HX_STACK_LINE(588)
					Dynamic _g12 = this->_p(ln,HX_CSTRING("color.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(588)
					Array< Float > _g13 = this->_f32a(_g12);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(588)
					ca = _g13;
				}
			}
			HX_STACK_LINE(591)
			l->color->Set(ca->__get((int)0),ca->__get((int)1),ca->__get((int)2),(  (((ca->length >= (int)4))) ? Float(ca->__get((int)3)) : Float(1.0) ));
			HX_STACK_LINE(593)
			Dynamic _g14 = n->elementsNamed(HX_CSTRING("extra"));		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(593)
			lit = _g14;
			HX_STACK_LINE(594)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(594)
				continue;
			}
			HX_STACK_LINE(594)
			Dynamic _g15 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elementsNamed"),true)(HX_CSTRING("technique"));		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(594)
			lit = _g15;
			HX_STACK_LINE(595)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(595)
				continue;
			}
			HX_STACK_LINE(595)
			Dynamic _g16 = lit->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("elementsNamed"),true)(HX_CSTRING("max_light"));		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(595)
			lit = _g16;
			HX_STACK_LINE(596)
			if ((!(lit->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(596)
				continue;
			}
			HX_STACK_LINE(596)
			::Xml _g17 = lit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(596)
			ln = _g17;
			HX_STACK_LINE(598)
			{
				HX_STACK_LINE(598)
				::String _g8 = l->type;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(598)
				::String _switch_5 = (_g8);
				if (  ( _switch_5==HX_CSTRING("point"))){
					HX_STACK_LINE(601)
					Dynamic _g18 = this->_p(ln,HX_CSTRING("decay_radius.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(601)
					Float _g19 = ::Std_obj::parseFloat(_g18);		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(601)
					l->radius = _g19;
					HX_STACK_LINE(602)
					Dynamic _g20 = this->_p(ln,HX_CSTRING("multiplier.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(602)
					Float _g21 = ::Std_obj::parseFloat(_g20);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(602)
					l->intensity = _g21;
					HX_STACK_LINE(603)
					Dynamic _g22 = this->_p(ln,HX_CSTRING("decay_type.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(603)
					int atten_type = ::Std_obj::parseInt(_g22);		HX_STACK_VAR(atten_type,"atten_type");
					HX_STACK_LINE(604)
					if (((atten_type == (int)0))){
						HX_STACK_LINE(604)
						l->atten = 0.0;
					}
					else{
						HX_STACK_LINE(604)
						if (((atten_type == (int)1))){
							HX_STACK_LINE(604)
							l->atten = 1.0;
						}
						else{
							HX_STACK_LINE(604)
							l->atten = 2.0;
						}
					}
				}
				else if (  ( _switch_5==HX_CSTRING("ambient"))){
				}
				else if (  ( _switch_5==HX_CSTRING("directional"))){
					HX_STACK_LINE(608)
					Dynamic _g23 = this->_p(ln,HX_CSTRING("multiplier.$text"),HX_CSTRING("1.0"),null(),null());		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(608)
					Float _g24 = ::Std_obj::parseFloat(_g23);		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(608)
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
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseAnimationLibrary",0x3998caf4,"haxor.io.file.ColladaFile.ParseAnimationLibrary","haxor/io/file/ColladaFile.hx",616,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(617)
		Dynamic it = n->elementsNamed(HX_CSTRING("animation"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(618)
		int anim_id = (int)0;		HX_STACK_VAR(anim_id,"anim_id");
		HX_STACK_LINE(619)
		while((true)){
			HX_STACK_LINE(619)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(619)
				break;
			}
			HX_STACK_LINE(621)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(621)
			n = _g;
			HX_STACK_LINE(622)
			if ((n->elementsNamed(HX_CSTRING("animation"))->__Field(HX_CSTRING("hasNext"),true)())){
				HX_STACK_LINE(622)
				::Xml _g1 = n->elementsNamed(HX_CSTRING("animation"))->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(622)
				n = _g1;
			}
			HX_STACK_LINE(624)
			::haxor::io::file::ColladaAnimation ca = ::haxor::io::file::ColladaAnimation_obj::__new();		HX_STACK_VAR(ca,"ca");
			HX_STACK_LINE(626)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(626)
			ca->id = _g2;
			HX_STACK_LINE(627)
			::String _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(627)
			if (((ca->id == HX_CSTRING("")))){
				HX_STACK_LINE(627)
				int _g3 = (anim_id)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(627)
				_g4 = (HX_CSTRING("Clip") + _g3);
			}
			else{
				HX_STACK_LINE(627)
				_g4 = ca->id;
			}
			HX_STACK_LINE(627)
			ca->id = _g4;
			HX_STACK_LINE(628)
			::String _g5 = this->_a(n,HX_CSTRING("name"),ca->id);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(628)
			ca->name = _g5;
			HX_STACK_LINE(630)
			Dynamic source_iterator = n->elementsNamed(HX_CSTRING("source"));		HX_STACK_VAR(source_iterator,"source_iterator");
			HX_STACK_LINE(631)
			Dynamic sampler_iterator = n->elementsNamed(HX_CSTRING("sampler"));		HX_STACK_VAR(sampler_iterator,"sampler_iterator");
			HX_STACK_LINE(632)
			Array< ::Dynamic > source_list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(source_list,"source_list");
			HX_STACK_LINE(633)
			Array< ::Dynamic > sampler_list = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(sampler_list,"sampler_list");
			HX_STACK_LINE(635)
			while((true)){
				HX_STACK_LINE(635)
				if ((!(source_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(635)
					break;
				}
				HX_STACK_LINE(635)
				::Xml _g6 = source_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(635)
				source_list->push(_g6);
			}
			HX_STACK_LINE(636)
			while((true)){
				HX_STACK_LINE(636)
				if ((!(sampler_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(636)
					break;
				}
				HX_STACK_LINE(636)
				::Xml _g7 = sampler_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(636)
				sampler_list->push(_g7);
			}
			HX_STACK_LINE(638)
			Dynamic channel_list = n->elementsNamed(HX_CSTRING("channel"));		HX_STACK_VAR(channel_list,"channel_list");
			HX_STACK_LINE(641)
			while((true)){
				HX_STACK_LINE(641)
				if ((!(channel_list->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(641)
					break;
				}
				HX_STACK_LINE(643)
				::Xml chn = channel_list->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(chn,"chn");
				HX_STACK_LINE(644)
				::haxor::io::file::ColladaAnimationChannel cch = ::haxor::io::file::ColladaAnimationChannel_obj::__new();		HX_STACK_VAR(cch,"cch");
				HX_STACK_LINE(645)
				::String _g8 = this->_a(chn,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(645)
				cch->source = _g8;
				HX_STACK_LINE(646)
				::String _g9 = this->_a(chn,HX_CSTRING("target"),HX_CSTRING(""));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(646)
				cch->target = _g9;
				HX_STACK_LINE(648)
				{
					HX_STACK_LINE(648)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(648)
					int _g3 = sampler_list->length;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(648)
					while((true)){
						HX_STACK_LINE(648)
						if ((!(((_g1 < _g3))))){
							HX_STACK_LINE(648)
							break;
						}
						HX_STACK_LINE(648)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(650)
						::String sampler_id = this->_a(sampler_list->__get(i).StaticCast< ::Xml >(),HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(sampler_id,"sampler_id");
						HX_STACK_LINE(651)
						if (((sampler_id != cch->source))){
							HX_STACK_LINE(651)
							continue;
						}
						HX_STACK_LINE(652)
						Dynamic input_iterator = sampler_list->__get(i).StaticCast< ::Xml >()->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(input_iterator,"input_iterator");
						HX_STACK_LINE(653)
						::String keyframe_time_source = HX_CSTRING("");		HX_STACK_VAR(keyframe_time_source,"keyframe_time_source");
						HX_STACK_LINE(654)
						::String keyframe_value_source = HX_CSTRING("");		HX_STACK_VAR(keyframe_value_source,"keyframe_value_source");
						HX_STACK_LINE(656)
						while((true)){
							HX_STACK_LINE(656)
							if ((!(input_iterator->__Field(HX_CSTRING("hasNext"),true)()))){
								HX_STACK_LINE(656)
								break;
							}
							HX_STACK_LINE(658)
							::Xml chsi = input_iterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(chsi,"chsi");
							HX_STACK_LINE(659)
							{
								HX_STACK_LINE(659)
								::String _g21 = this->_a(chsi,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(659)
								::String _switch_6 = (_g21);
								if (  ( _switch_6==HX_CSTRING("input"))){
									HX_STACK_LINE(661)
									::String _g10 = this->_a(chsi,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(661)
									keyframe_time_source = _g10;
								}
								else if (  ( _switch_6==HX_CSTRING("output"))){
									HX_STACK_LINE(662)
									::String _g11 = this->_a(chsi,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(662)
									keyframe_value_source = _g11;
								}
							}
						}
						HX_STACK_LINE(666)
						if (((keyframe_time_source == HX_CSTRING("")))){
							HX_STACK_LINE(666)
							continue;
						}
						HX_STACK_LINE(667)
						if (((keyframe_value_source == HX_CSTRING("")))){
							HX_STACK_LINE(667)
							continue;
						}
						HX_STACK_LINE(669)
						::Xml kf_time_node = null();		HX_STACK_VAR(kf_time_node,"kf_time_node");
						HX_STACK_LINE(670)
						::Xml kf_value_node = null();		HX_STACK_VAR(kf_value_node,"kf_value_node");
						HX_STACK_LINE(672)
						{
							HX_STACK_LINE(672)
							int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
							HX_STACK_LINE(672)
							int _g21 = source_list->length;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(672)
							while((true)){
								HX_STACK_LINE(672)
								if ((!(((_g31 < _g21))))){
									HX_STACK_LINE(672)
									break;
								}
								HX_STACK_LINE(672)
								int j = (_g31)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(674)
								::Xml sn = source_list->__get(j).StaticCast< ::Xml >();		HX_STACK_VAR(sn,"sn");
								HX_STACK_LINE(675)
								::String _g12 = this->_a(sn,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g12,"_g12");
								HX_STACK_LINE(675)
								if (((_g12 == keyframe_time_source))){
									HX_STACK_LINE(675)
									kf_time_node = sn;
								}
								HX_STACK_LINE(676)
								::String _g13 = this->_a(sn,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g13,"_g13");
								HX_STACK_LINE(676)
								if (((_g13 == keyframe_value_source))){
									HX_STACK_LINE(676)
									kf_value_node = sn;
								}
							}
						}
						HX_STACK_LINE(679)
						if (((kf_time_node == null()))){
							HX_STACK_LINE(679)
							continue;
						}
						HX_STACK_LINE(680)
						if (((kf_value_node == null()))){
							HX_STACK_LINE(680)
							continue;
						}
						HX_STACK_LINE(682)
						Dynamic _g14 = this->_p(kf_time_node,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g14,"_g14");
						HX_STACK_LINE(682)
						Array< Float > kf_time_buffer = this->_f32a(_g14);		HX_STACK_VAR(kf_time_buffer,"kf_time_buffer");
						HX_STACK_LINE(683)
						Dynamic _g15 = this->_p(kf_value_node,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(683)
						Array< Float > kf_value_buffer = this->_f32a(_g15);		HX_STACK_VAR(kf_value_buffer,"kf_value_buffer");
						HX_STACK_LINE(684)
						Dynamic _g16 = this->_p(kf_value_node,HX_CSTRING("technique_common.accessor.@stride"),HX_CSTRING("0"),null(),null());		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(684)
						int kf_value_stride = ::Std_obj::parseInt(_g16);		HX_STACK_VAR(kf_value_stride,"kf_value_stride");
						HX_STACK_LINE(686)
						{
							HX_STACK_LINE(686)
							int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
							HX_STACK_LINE(686)
							int _g21 = kf_time_buffer->length;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(686)
							while((true)){
								HX_STACK_LINE(686)
								if ((!(((_g31 < _g21))))){
									HX_STACK_LINE(686)
									break;
								}
								HX_STACK_LINE(686)
								int j = (_g31)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(688)
								::haxor::io::file::ColladaAnimationKeyFrame kf = ::haxor::io::file::ColladaAnimationKeyFrame_obj::__new();		HX_STACK_VAR(kf,"kf");
								HX_STACK_LINE(689)
								kf->time = kf_time_buffer->__get(j);
								HX_STACK_LINE(690)
								{
									HX_STACK_LINE(690)
									int _g41 = (int)0;		HX_STACK_VAR(_g41,"_g41");
									HX_STACK_LINE(690)
									while((true)){
										HX_STACK_LINE(690)
										if ((!(((_g41 < kf_value_stride))))){
											HX_STACK_LINE(690)
											break;
										}
										HX_STACK_LINE(690)
										int k = (_g41)++;		HX_STACK_VAR(k,"k");
										HX_STACK_LINE(692)
										Dynamic _g17 = kf_value_buffer->shift();		HX_STACK_VAR(_g17,"_g17");
										HX_STACK_LINE(692)
										kf->values->push(_g17);
									}
								}
								HX_STACK_LINE(694)
								cch->keyframes->push(kf);
							}
						}
					}
				}
				HX_STACK_LINE(697)
				ca->channels->push(cch);
			}
			HX_STACK_LINE(699)
			this->animations->push(ca);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseAnimationLibrary,(void))

Void ColladaFile_obj::ParseMaterialLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseMaterialLibrary",0xf4892517,"haxor.io.file.ColladaFile.ParseMaterialLibrary","haxor/io/file/ColladaFile.hx",705,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(706)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(707)
		while((true)){
			HX_STACK_LINE(707)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(707)
				break;
			}
			HX_STACK_LINE(709)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(709)
			n = _g;
			HX_STACK_LINE(710)
			{
				HX_STACK_LINE(710)
				::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(710)
				::String _switch_7 = (_g1);
				if (  ( _switch_7==HX_CSTRING("material"))){
					HX_STACK_LINE(713)
					::haxor::io::file::ColladaMaterial mat = ::haxor::io::file::ColladaMaterial_obj::__new();		HX_STACK_VAR(mat,"mat");
					HX_STACK_LINE(714)
					::String _g11 = this->_a(n,HX_CSTRING("id"),HX_CSTRING(""));		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(714)
					mat->id = _g11;
					HX_STACK_LINE(715)
					::String _g2 = this->_a(n,HX_CSTRING("name"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(715)
					mat->name = _g2;
					HX_STACK_LINE(716)
					if (((mat->id == HX_CSTRING("")))){
						HX_STACK_LINE(716)
						mat->id = mat->name;
					}
					HX_STACK_LINE(717)
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
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseSceneLibrary",0x30a6672c,"haxor.io.file.ColladaFile.ParseSceneLibrary","haxor/io/file/ColladaFile.hx",723,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(724)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(725)
		while((true)){
			HX_STACK_LINE(725)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(725)
				break;
			}
			HX_STACK_LINE(727)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(727)
			n = _g;
			HX_STACK_LINE(728)
			{
				HX_STACK_LINE(728)
				::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(728)
				::String _switch_8 = (_g1);
				if (  ( _switch_8==HX_CSTRING("visual_scene"))){
					HX_STACK_LINE(728)
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
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseVisualScene",0x0bd770ef,"haxor.io.file.ColladaFile.ParseVisualScene","haxor/io/file/ColladaFile.hx",733,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(734)
		if (((this->scene != null()))){
			HX_STACK_LINE(734)
			return null();
		}
		HX_STACK_LINE(735)
		::haxor::io::file::ColladaVisualScene _g = ::haxor::io::file::ColladaVisualScene_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(735)
		this->scene = _g;
		HX_STACK_LINE(736)
		::String _g1 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("collada_scene"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(736)
		this->scene->id = _g1;
		HX_STACK_LINE(737)
		::String _g2 = this->_a(n,HX_CSTRING("name"),this->scene->id);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(737)
		this->scene->name = _g2;
		HX_STACK_LINE(738)
		::String _g3 = n->get_nodeName();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(738)
		this->scene->type = _g3;
		HX_STACK_LINE(739)
		this->TraverseVisualSceneNodes(this->scene,null(),n);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseVisualScene,(void))

Void ColladaFile_obj::TraverseVisualSceneNodes( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","TraverseVisualSceneNodes",0x5c90d9ed,"haxor.io.file.ColladaFile.TraverseVisualSceneNodes","haxor/io/file/ColladaFile.hx",743,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(scn,"scn")
		HX_STACK_ARG(p,"p")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(744)
		::haxor::io::file::ColladaNode cn = null();		HX_STACK_VAR(cn,"cn");
		HX_STACK_LINE(745)
		::String _g = n->get_nodeName();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(745)
		if (((_g == HX_CSTRING("node")))){
			HX_STACK_LINE(745)
			::haxor::io::file::ColladaNode _g1 = this->ParseVisualSceneNode(scn,p,n);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(745)
			cn = _g1;
		}
		HX_STACK_LINE(746)
		Dynamic cn_it = n->elementsNamed(HX_CSTRING("node"));		HX_STACK_VAR(cn_it,"cn_it");
		HX_STACK_LINE(747)
		while((true)){
			HX_STACK_LINE(747)
			if ((!(cn_it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(747)
				break;
			}
			HX_STACK_LINE(747)
			::Xml _g2 = cn_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(747)
			this->TraverseVisualSceneNodes(scn,cn,_g2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,TraverseVisualSceneNodes,(void))

::haxor::io::file::ColladaNode ColladaFile_obj::ParseVisualSceneNode( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseVisualSceneNode",0xf4f74a91,"haxor.io.file.ColladaFile.ParseVisualSceneNode","haxor/io/file/ColladaFile.hx",751,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(scn,"scn")
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(752)
	::haxor::io::file::ColladaNode cn = ::haxor::io::file::ColladaNode_obj::__new();		HX_STACK_VAR(cn,"cn");
	HX_STACK_LINE(753)
	cn->scene = scn;
	HX_STACK_LINE(755)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(755)
	Float _g1 = (_g * (int)16777215);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(755)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(755)
	::String _g3 = (HX_CSTRING("node") + _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(755)
	::String _g4 = this->_a(n,HX_CSTRING("sid"),_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(755)
	cn->sid = _g4;
	HX_STACK_LINE(756)
	::String _g5 = this->_a(n,HX_CSTRING("id"),cn->sid);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(756)
	cn->id = _g5;
	HX_STACK_LINE(757)
	::String _g6 = this->_a(n,HX_CSTRING("name"),cn->sid);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(757)
	cn->name = _g6;
	HX_STACK_LINE(758)
	if (((cn->sid == HX_CSTRING("")))){
		HX_STACK_LINE(758)
		cn->sid = cn->id;
	}
	HX_STACK_LINE(759)
	::String _g7 = this->_a(n,HX_CSTRING("type"),HX_CSTRING("NODE")).toLowerCase();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(759)
	cn->type = _g7;
	HX_STACK_LINE(760)
	Dynamic _g8 = this->_p(n,HX_CSTRING("matrix.$text"),HX_CSTRING("1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1"),null(),null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(760)
	Array< Float > _g9 = this->_f32a(_g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(760)
	cn->matrix = _g9;
	HX_STACK_LINE(761)
	cn->parent = p;
	HX_STACK_LINE(762)
	cn->GenerateTranform();
	HX_STACK_LINE(764)
	Dynamic iit = n->elements();		HX_STACK_VAR(iit,"iit");
	HX_STACK_LINE(765)
	while((true)){
		HX_STACK_LINE(765)
		if ((!(iit->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(765)
			break;
		}
		HX_STACK_LINE(767)
		::Xml nin = iit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(nin,"nin");
		HX_STACK_LINE(768)
		::haxor::io::file::ColladaInstance ni = null();		HX_STACK_VAR(ni,"ni");
		HX_STACK_LINE(769)
		{
			HX_STACK_LINE(769)
			::String _g10 = nin->get_nodeName();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(769)
			::String _switch_9 = (_g10);
			if (  ( _switch_9==HX_CSTRING("instance_geometry"))){
				HX_STACK_LINE(772)
				::haxor::io::file::ColladaInstance _g101 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g101,"_g101");
				HX_STACK_LINE(772)
				ni = _g101;
				HX_STACK_LINE(773)
				ni->type = HX_CSTRING("geometry");
				HX_STACK_LINE(774)
				::String _g11 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(774)
				ni->target = _g11;
			}
			else if (  ( _switch_9==HX_CSTRING("instance_controller"))){
				HX_STACK_LINE(778)
				::haxor::io::file::ColladaInstance _g12 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(778)
				ni = _g12;
				HX_STACK_LINE(779)
				ni->type = HX_CSTRING("controller");
				HX_STACK_LINE(780)
				::String _g13 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(780)
				ni->target = _g13;
			}
			else if (  ( _switch_9==HX_CSTRING("instance_light"))){
				HX_STACK_LINE(783)
				::haxor::io::file::ColladaInstance _g14 = ::haxor::io::file::ColladaInstance_obj::__new();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(783)
				ni = _g14;
				HX_STACK_LINE(784)
				ni->type = HX_CSTRING("light");
				HX_STACK_LINE(785)
				::String _g15 = this->_a(nin,HX_CSTRING("url"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(785)
				ni->target = _g15;
			}
			else if (  ( _switch_9==HX_CSTRING("extra"))){
				HX_STACK_LINE(788)
				Dynamic _g16 = this->_p(nin,HX_CSTRING("technique.user_properties.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(788)
				cn->data = _g16;
				HX_STACK_LINE(789)
				int _g17 = cn->data.indexOf(HX_CSTRING(";"),null());		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(789)
				if (((_g17 < (int)0))){
					HX_STACK_LINE(789)
					cn->data = HX_CSTRING("");
				}
			}
		}
		HX_STACK_LINE(793)
		if (((ni != null()))){
			HX_STACK_LINE(793)
			cn->instances->push(ni);
		}
	}
	HX_STACK_LINE(796)
	if (((p == null()))){
		HX_STACK_LINE(796)
		scn->children->push(cn);
	}
	else{
		HX_STACK_LINE(796)
		p->children->push(cn);
	}
	HX_STACK_LINE(797)
	return cn;
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,ParseVisualSceneNode,return )

Void ColladaFile_obj::ParseInstanceMaterials( ::haxor::io::file::ColladaInstance ci,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseInstanceMaterials",0xd76ce25a,"haxor.io.file.ColladaFile.ParseInstanceMaterials","haxor/io/file/ColladaFile.hx",801,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ci,"ci")
		HX_STACK_ARG(n,"n")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseInstanceMaterials,(void))

Void ColladaFile_obj::ParseControllerLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseControllerLibrary",0xcdf6c882,"haxor.io.file.ColladaFile.ParseControllerLibrary","haxor/io/file/ColladaFile.hx",806,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(807)
		Dynamic it = n->elementsNamed(HX_CSTRING("controller"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(808)
		::haxor::io::file::ColladaController c = null();		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(809)
		while((true)){
			HX_STACK_LINE(809)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(809)
				break;
			}
			HX_STACK_LINE(811)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(811)
			n = _g;
			HX_STACK_LINE(812)
			::haxor::io::file::ColladaController _g1 = ::haxor::io::file::ColladaController_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(812)
			c = _g1;
			HX_STACK_LINE(813)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(813)
			c->id = _g2;
			HX_STACK_LINE(814)
			::String _g3 = this->_a(n,HX_CSTRING("name"),c->id);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(814)
			c->name = _g3;
			HX_STACK_LINE(815)
			this->ParseController(c,n);
			HX_STACK_LINE(816)
			this->controllers->push(c);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseControllerLibrary,(void))

Void ColladaFile_obj::ParseController( ::haxor::io::file::ColladaController c,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseController",0x4bcb5779,"haxor.io.file.ColladaFile.ParseController","haxor/io/file/ColladaFile.hx",821,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(822)
		::Xml _g = n->firstElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(822)
		n = _g;
		HX_STACK_LINE(823)
		if (((n == null()))){
			HX_STACK_LINE(823)
			return null();
		}
		HX_STACK_LINE(824)
		::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(824)
		::String _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(824)
		if (((_g1 == null()))){
			HX_STACK_LINE(824)
			_g2 = HX_CSTRING("none");
		}
		else{
			HX_STACK_LINE(824)
			_g2 = n->get_nodeName().toLowerCase();
		}
		HX_STACK_LINE(824)
		c->type = _g2;
		HX_STACK_LINE(825)
		{
			HX_STACK_LINE(825)
			::String _g3 = c->type;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(825)
			::String _switch_10 = (_g3);
			if (  ( _switch_10==HX_CSTRING("skin"))){
				HX_STACK_LINE(827)
				this->ParseControllerSkin(c,n);
			}
			else if (  ( _switch_10==HX_CSTRING("morph"))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseController,(void))

Void ColladaFile_obj::ParseControllerSkin( ::haxor::io::file::ColladaController c,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseControllerSkin",0x4c6d4a96,"haxor.io.file.ColladaFile.ParseControllerSkin","haxor/io/file/ColladaFile.hx",833,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(834)
		::String _g = this->_a(n,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(834)
		c->source = _g;
		HX_STACK_LINE(835)
		Dynamic _g1 = this->_p(n,HX_CSTRING("bind_shape_matrix.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(835)
		Array< Float > _g2 = this->_f32a(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(835)
		c->matrix = _g2;
		HX_STACK_LINE(837)
		::String source = HX_CSTRING("");		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(838)
		::Xml sn = null();		HX_STACK_VAR(sn,"sn");
		HX_STACK_LINE(840)
		Dynamic _g3 = this->_p(n,HX_CSTRING("joints"),null(),null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(840)
		::Xml jn;		HX_STACK_VAR(jn,"jn");
		HX_STACK_LINE(840)
		if (((_g3 == null()))){
			HX_STACK_LINE(840)
			jn = null();
		}
		else{
			HX_STACK_LINE(840)
			jn = this->_p(n,HX_CSTRING("joints"),null(),null(),null())->__Field(HX_CSTRING("next"),true)();
		}
		HX_STACK_LINE(842)
		if (((jn != null()))){
			HX_STACK_LINE(844)
			Dynamic jn_it = jn->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(jn_it,"jn_it");
			HX_STACK_LINE(845)
			while((true)){
				HX_STACK_LINE(845)
				if ((!(jn_it->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(845)
					break;
				}
				HX_STACK_LINE(847)
				::Xml jni = jn_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(jni,"jni");
				HX_STACK_LINE(848)
				::String _g4 = this->_a(jni,HX_CSTRING("source"),HX_CSTRING("")).substr((int)1,null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(848)
				source = _g4;
				HX_STACK_LINE(849)
				if (((source == HX_CSTRING("")))){
					HX_STACK_LINE(849)
					continue;
				}
				HX_STACK_LINE(850)
				::Xml _g5 = this->_f(n,HX_CSTRING("source"),HX_CSTRING("id"),source);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(850)
				sn = _g5;
				HX_STACK_LINE(851)
				if (((sn == null()))){
					HX_STACK_LINE(851)
					continue;
				}
				HX_STACK_LINE(853)
				{
					HX_STACK_LINE(853)
					::String _g6 = this->_a(jni,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(853)
					::String _switch_11 = (_g6);
					if (  ( _switch_11==HX_CSTRING("joint"))){
						HX_STACK_LINE(855)
						Dynamic _g61 = this->_p(sn,HX_CSTRING("Name_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g61,"_g61");
						HX_STACK_LINE(855)
						::String _g7 = ::StringTools_obj::replace(_g61,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(855)
						Array< ::String > _g8 = ::StringTools_obj::trim(_g7).split(HX_CSTRING(" "));		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(855)
						c->joints = _g8;
					}
					else if (  ( _switch_11==HX_CSTRING("inv_bind_matrix"))){
						HX_STACK_LINE(858)
						Dynamic _g9 = this->_p(sn,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(858)
						Array< Float > ml = this->_f32a(_g9);		HX_STACK_VAR(ml,"ml");
						HX_STACK_LINE(859)
						while((true)){
							HX_STACK_LINE(859)
							if ((!(((ml->length > (int)0))))){
								HX_STACK_LINE(859)
								break;
							}
							HX_STACK_LINE(861)
							Array< Float > mtx = Array_obj< Float >::__new();		HX_STACK_VAR(mtx,"mtx");
							HX_STACK_LINE(862)
							{
								HX_STACK_LINE(862)
								int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
								HX_STACK_LINE(862)
								while((true)){
									HX_STACK_LINE(862)
									if ((!(((_g11 < (int)16))))){
										HX_STACK_LINE(862)
										break;
									}
									HX_STACK_LINE(862)
									int i = (_g11)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(862)
									Dynamic _g10 = ml->shift();		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(862)
									mtx->push(_g10);
								}
							}
							HX_STACK_LINE(863)
							c->binds->push(mtx);
						}
					}
				}
			}
		}
		HX_STACK_LINE(869)
		Dynamic _g11 = this->_p(n,HX_CSTRING("vertex_weights"),null(),null(),null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(869)
		::Xml vwn;		HX_STACK_VAR(vwn,"vwn");
		HX_STACK_LINE(869)
		if (((_g11 == null()))){
			HX_STACK_LINE(869)
			vwn = null();
		}
		else{
			HX_STACK_LINE(869)
			vwn = this->_p(n,HX_CSTRING("vertex_weights"),null(),null(),null())->__Field(HX_CSTRING("next"),true)();
		}
		HX_STACK_LINE(870)
		if (((vwn != null()))){
			HX_STACK_LINE(872)
			Array< ::Dynamic > _g12 = this->ParseInputList(n,vwn);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(872)
			c->inputs = _g12;
			HX_STACK_LINE(873)
			Dynamic _g13 = this->_p(vwn,HX_CSTRING("vcount.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(873)
			Array< int > _g14 = this->_i16a(_g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(873)
			c->vcount = _g14;
			HX_STACK_LINE(874)
			::String vwb = this->_p(vwn,HX_CSTRING("v.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(vwb,"vwb");
			HX_STACK_LINE(875)
			int _g15 = c->get_offset();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(875)
			Array< ::Dynamic > _g16 = this->_i16ta(vwb,_g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(875)
			c->indexes = _g16;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseControllerSkin,(void))

Void ColladaFile_obj::ParseImageLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseImageLibrary",0xe21890fd,"haxor.io.file.ColladaFile.ParseImageLibrary","haxor/io/file/ColladaFile.hx",881,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(882)
		Dynamic it = n->elementsNamed(HX_CSTRING("image"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(883)
		::haxor::io::file::ColladaImage img = null();		HX_STACK_VAR(img,"img");
		HX_STACK_LINE(884)
		while((true)){
			HX_STACK_LINE(884)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(884)
				break;
			}
			HX_STACK_LINE(886)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(886)
			n = _g;
			HX_STACK_LINE(887)
			::haxor::io::file::ColladaImage _g1 = ::haxor::io::file::ColladaImage_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(887)
			img = _g1;
			HX_STACK_LINE(888)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(888)
			img->id = _g2;
			HX_STACK_LINE(889)
			::String _g3 = this->_a(n,HX_CSTRING("name"),img->id);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(889)
			img->name = _g3;
			HX_STACK_LINE(890)
			::String _g4 = this->_a(n,HX_CSTRING("format"),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(890)
			img->format = _g4;
			HX_STACK_LINE(891)
			::String _g5 = this->_a(n,HX_CSTRING("width"),HX_CSTRING("-1"));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(891)
			Dynamic _g6 = ::Std_obj::parseInt(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(891)
			img->width = _g6;
			HX_STACK_LINE(892)
			::String _g7 = this->_a(n,HX_CSTRING("height"),HX_CSTRING("-1"));		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(892)
			Dynamic _g8 = ::Std_obj::parseInt(_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(892)
			img->height = _g8;
			HX_STACK_LINE(893)
			::String _g9 = this->_a(n,HX_CSTRING("depth"),HX_CSTRING("-1"));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(893)
			Dynamic _g10 = ::Std_obj::parseInt(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(893)
			img->depth = _g10;
			HX_STACK_LINE(895)
			this->images->push(img);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseImageLibrary,(void))

Void ColladaFile_obj::ParseGeometryLibrary( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseGeometryLibrary",0xd411266c,"haxor.io.file.ColladaFile.ParseGeometryLibrary","haxor/io/file/ColladaFile.hx",900,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(901)
		Dynamic it = n->elementsNamed(HX_CSTRING("geometry"));		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(902)
		::haxor::io::file::ColladaGeometry g = null();		HX_STACK_VAR(g,"g");
		HX_STACK_LINE(903)
		while((true)){
			HX_STACK_LINE(903)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(903)
				break;
			}
			HX_STACK_LINE(905)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(905)
			n = _g;
			HX_STACK_LINE(906)
			::haxor::io::file::ColladaGeometry _g1 = ::haxor::io::file::ColladaGeometry_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(906)
			g = _g1;
			HX_STACK_LINE(907)
			::String _g2 = this->_a(n,HX_CSTRING("id"),HX_CSTRING("none"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(907)
			g->id = _g2;
			HX_STACK_LINE(908)
			::String _g3 = this->_a(n,HX_CSTRING("name"),HX_CSTRING("none"));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(908)
			g->name = _g3;
			HX_STACK_LINE(909)
			this->ParseGeometry(g,n);
			HX_STACK_LINE(910)
			this->geometries->push(g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,ParseGeometryLibrary,(void))

Void ColladaFile_obj::ParseGeometry( ::haxor::io::file::ColladaGeometry g,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseGeometry",0x09ad604f,"haxor.io.file.ColladaFile.ParseGeometry","haxor/io/file/ColladaFile.hx",915,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(g,"g")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(916)
		::Xml _g = n->firstElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(916)
		n = _g;
		HX_STACK_LINE(917)
		if (((n == null()))){
			HX_STACK_LINE(917)
			return null();
		}
		HX_STACK_LINE(918)
		::haxor::io::file::ColladaMesh _g1 = ::haxor::io::file::ColladaMesh_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(918)
		g->mesh = _g1;
		HX_STACK_LINE(919)
		::String _g2 = n->get_nodeName();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(919)
		::String _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(919)
		if (((_g2 == null()))){
			HX_STACK_LINE(919)
			_g3 = HX_CSTRING("none");
		}
		else{
			HX_STACK_LINE(919)
			_g3 = n->get_nodeName().toLowerCase();
		}
		HX_STACK_LINE(919)
		g->mesh->type = _g3;
		HX_STACK_LINE(920)
		{
			HX_STACK_LINE(920)
			::String _g4 = g->mesh->type;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(920)
			::String _switch_12 = (_g4);
			if (  ( _switch_12==HX_CSTRING("mesh"))){
				HX_STACK_LINE(922)
				this->ParseMesh(g->mesh,n);
			}
			else if (  ( _switch_12==HX_CSTRING("convex_mesh"))){
			}
			else if (  ( _switch_12==HX_CSTRING("spline"))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseGeometry,(void))

Void ColladaFile_obj::ParseMesh( ::haxor::io::file::ColladaMesh m,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseMesh",0x125d550a,"haxor.io.file.ColladaFile.ParseMesh","haxor/io/file/ColladaFile.hx",929,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(930)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(931)
		::Xml p = n;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(932)
		while((true)){
			HX_STACK_LINE(932)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(932)
				break;
			}
			HX_STACK_LINE(934)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(934)
			n = _g;
			HX_STACK_LINE(935)
			::String _g1 = n->get_nodeName();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(935)
			if (((_g1 == HX_CSTRING("vertices")))){
				HX_STACK_LINE(935)
				continue;
			}
			HX_STACK_LINE(936)
			::String _g2 = n->get_nodeName();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(936)
			if (((_g2 == HX_CSTRING("source")))){
				HX_STACK_LINE(936)
				continue;
			}
			HX_STACK_LINE(937)
			::haxor::io::file::ColladaPrimitive cp = ::haxor::io::file::ColladaPrimitive_obj::__new();		HX_STACK_VAR(cp,"cp");
			HX_STACK_LINE(939)
			::String _g3 = n->get_nodeName();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(939)
			cp->type = _g3;
			HX_STACK_LINE(940)
			::String _g4 = this->_a(n,HX_CSTRING("material"),HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(940)
			cp->material = _g4;
			HX_STACK_LINE(941)
			this->ParsePrimitive(cp,p,n);
			HX_STACK_LINE(942)
			m->primitives->push(cp);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseMesh,(void))

Void ColladaFile_obj::ParsePrimitive( ::haxor::io::file::ColladaPrimitive cp,::Xml p,::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","ParsePrimitive",0x1426146a,"haxor.io.file.ColladaFile.ParsePrimitive","haxor/io/file/ColladaFile.hx",947,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cp,"cp")
		HX_STACK_ARG(p,"p")
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(948)
		Array< ::Dynamic > _g = this->ParseInputList(p,n);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(948)
		cp->inputs = _g;
		HX_STACK_LINE(949)
		Dynamic p_it = n->elementsNamed(HX_CSTRING("p"));		HX_STACK_VAR(p_it,"p_it");
		HX_STACK_LINE(950)
		Dynamic vc_it = n->elementsNamed(HX_CSTRING("vcount"));		HX_STACK_VAR(vc_it,"vc_it");
		HX_STACK_LINE(951)
		if ((vc_it->__Field(HX_CSTRING("hasNext"),true)())){
			HX_STACK_LINE(953)
			::Xml ncitn = vc_it->__Field(HX_CSTRING("next"),true)()->__Field(HX_CSTRING("firstChild"),true)();		HX_STACK_VAR(ncitn,"ncitn");
			HX_STACK_LINE(954)
			Array< int > _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(954)
			if (((ncitn == null()))){
				HX_STACK_LINE(954)
				_g2 = Array_obj< int >::__new();
			}
			else{
				HX_STACK_LINE(954)
				::String _g1 = ncitn->toString();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(954)
				_g2 = this->_i16a(_g1);
			}
			HX_STACK_LINE(954)
			cp->vcount = _g2;
		}
		HX_STACK_LINE(957)
		while((true)){
			HX_STACK_LINE(957)
			if ((!(p_it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(957)
				break;
			}
			HX_STACK_LINE(959)
			::Xml vn = p_it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(vn,"vn");
			HX_STACK_LINE(960)
			::Xml _g3 = vn->firstChild();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(960)
			::String vb;		HX_STACK_VAR(vb,"vb");
			HX_STACK_LINE(960)
			if (((_g3 != null()))){
				HX_STACK_LINE(960)
				vb = vn->firstChild()->toString();
			}
			else{
				HX_STACK_LINE(960)
				vb = HX_CSTRING("0");
			}
			HX_STACK_LINE(961)
			int off = cp->get_offset();		HX_STACK_VAR(off,"off");
			HX_STACK_LINE(962)
			Array< ::Dynamic > ti = this->_i16ta(vb,off);		HX_STACK_VAR(ti,"ti");
			HX_STACK_LINE(963)
			cp->indexes->push(ti);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,ParsePrimitive,(void))

Array< ::Dynamic > ColladaFile_obj::ParseInputList( ::Xml p,::Xml n){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","ParseInputList",0xfbab654b,"haxor.io.file.ColladaFile.ParseInputList","haxor/io/file/ColladaFile.hx",982,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(983)
	Array< ::Dynamic > l = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(984)
	Dynamic it = n->elementsNamed(HX_CSTRING("input"));		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(985)
	while((true)){
		HX_STACK_LINE(985)
		if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(985)
			break;
		}
		HX_STACK_LINE(987)
		::Xml pi = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(pi,"pi");
		HX_STACK_LINE(988)
		::haxor::io::file::ColladaInput ci = ::haxor::io::file::ColladaInput_obj::__new();		HX_STACK_VAR(ci,"ci");
		HX_STACK_LINE(989)
		::String source = this->_a(pi,HX_CSTRING("source"),HX_CSTRING(""));		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(990)
		::String _g = this->_a(pi,HX_CSTRING("semantic"),HX_CSTRING("")).toLowerCase();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(990)
		ci->semantic = _g;
		HX_STACK_LINE(991)
		::String _g1 = this->_a(pi,HX_CSTRING("offset"),HX_CSTRING("-1"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(991)
		Dynamic _g2 = ::Std_obj::parseInt(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(991)
		ci->offset = _g2;
		HX_STACK_LINE(992)
		::String _g3 = this->_a(pi,HX_CSTRING("set"),HX_CSTRING("-1"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(992)
		Dynamic _g4 = ::Std_obj::parseInt(_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(992)
		ci->set = _g4;
		HX_STACK_LINE(993)
		if (((ci->semantic == HX_CSTRING("joint")))){
			HX_STACK_LINE(993)
			l->push(ci);
			HX_STACK_LINE(993)
			continue;
		}
		HX_STACK_LINE(994)
		if (((ci->semantic == HX_CSTRING("vertex")))){
			HX_STACK_LINE(996)
			Dynamic _g5 = this->_p(p,HX_CSTRING("vertices.input.@source"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(996)
			source = _g5;
		}
		HX_STACK_LINE(998)
		if (((source == HX_CSTRING("")))){
			HX_STACK_LINE(998)
			continue;
		}
		HX_STACK_LINE(999)
		::String _g6 = source.substr((int)1,null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(999)
		source = _g6;
		HX_STACK_LINE(1000)
		::Xml sn = this->_f(p,HX_CSTRING("source"),HX_CSTRING("id"),source);		HX_STACK_VAR(sn,"sn");
		HX_STACK_LINE(1001)
		if (((sn == null()))){
			HX_STACK_LINE(1001)
			continue;
		}
		HX_STACK_LINE(1002)
		::String stride_str = this->_p(sn,HX_CSTRING("technique_common.accessor.@stride"),HX_CSTRING("0"),null(),null());		HX_STACK_VAR(stride_str,"stride_str");
		HX_STACK_LINE(1003)
		Dynamic _g7 = ::Std_obj::parseInt(stride_str);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(1003)
		ci->stride = _g7;
		HX_STACK_LINE(1004)
		Dynamic _g8 = this->_p(sn,HX_CSTRING("float_array.$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(1004)
		Array< Float > _g9 = this->_f32a(_g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(1004)
		ci->values = _g9;
		HX_STACK_LINE(1005)
		l->push(ci);
	}
	HX_STACK_LINE(1007)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,ParseInputList,return )

Void ColladaFile_obj::TraverseStep( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.ColladaFile","TraverseStep",0x039b0314,"haxor.io.file.ColladaFile.TraverseStep","haxor/io/file/ColladaFile.hx",1011,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(1012)
		this->Parse(n);
		HX_STACK_LINE(1013)
		Dynamic l = n->elements();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1014)
		while((true)){
			HX_STACK_LINE(1014)
			if ((!(l->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(1014)
				break;
			}
			HX_STACK_LINE(1014)
			::Xml _g = l->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1014)
			this->TraverseStep(_g);
		}
	}
return null();
}


Array< Float > ColladaFile_obj::_f32a( ::String v){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_f32a",0x9bd71a85,"haxor.io.file.ColladaFile._f32a","haxor/io/file/ColladaFile.hx",1018,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(1019)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1019)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1020)
	Array< Float > a = Array_obj< Float >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1022)
	{
		HX_STACK_LINE(1022)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1022)
		int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1022)
		while((true)){
			HX_STACK_LINE(1022)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(1022)
				break;
			}
			HX_STACK_LINE(1022)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1022)
			Float _g11 = ::Std_obj::parseFloat(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1022)
			a->push(_g11);
		}
	}
	HX_STACK_LINE(1024)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,_f32a,return )

Array< int > ColladaFile_obj::_i16a( ::String v){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_i16a",0x9dd13d5c,"haxor.io.file.ColladaFile._i16a","haxor/io/file/ColladaFile.hx",1028,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(1029)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1029)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1030)
	Array< int > a = Array_obj< int >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1031)
	{
		HX_STACK_LINE(1031)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1031)
		int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1031)
		while((true)){
			HX_STACK_LINE(1031)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(1031)
				break;
			}
			HX_STACK_LINE(1031)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1031)
			Dynamic _g11 = ::Std_obj::parseInt(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1031)
			a->push(_g11);
		}
	}
	HX_STACK_LINE(1032)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaFile_obj,_i16a,return )

Array< ::Dynamic > ColladaFile_obj::_i16ta( ::String v,int s){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","_i16ta",0x79448412,"haxor.io.file.ColladaFile._i16ta","haxor/io/file/ColladaFile.hx",1036,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(1037)
	::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1037)
	Array< ::String > l = ::StringTools_obj::trim(_g).split(HX_CSTRING(" "));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1038)
	::String tl = HX_CSTRING("");		HX_STACK_VAR(tl,"tl");
	HX_STACK_LINE(1039)
	Array< ::Dynamic > a = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(1040)
	Array< int > bf;		HX_STACK_VAR(bf,"bf");
	HX_STACK_LINE(1041)
	int k = (int)0;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(1043)
	while((true)){
		HX_STACK_LINE(1043)
		if ((!(((k < l->length))))){
			HX_STACK_LINE(1043)
			break;
		}
		HX_STACK_LINE(1045)
		bf = Array_obj< int >::__new();
		HX_STACK_LINE(1046)
		{
			HX_STACK_LINE(1046)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1046)
			while((true)){
				HX_STACK_LINE(1046)
				if ((!(((_g1 < s))))){
					HX_STACK_LINE(1046)
					break;
				}
				HX_STACK_LINE(1046)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(1046)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(1046)
				::String _g2 = l->__get(_g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1046)
				Dynamic _g3 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1046)
				bf->push(_g3);
			}
		}
		HX_STACK_LINE(1047)
		a->push(bf);
	}
	HX_STACK_LINE(1049)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaFile_obj,_i16ta,return )

Array< ::Dynamic > ColladaFile_obj::GenerateTriangles( ::String p_type,Array< ::Dynamic > p_indexes,Array< int > p_vcount){
	HX_STACK_FRAME("haxor.io.file.ColladaFile","GenerateTriangles",0x4b1fb600,"haxor.io.file.ColladaFile.GenerateTriangles","haxor/io/file/ColladaFile.hx",32,0xa1888587)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_ARG(p_indexes,"p_indexes")
	HX_STACK_ARG(p_vcount,"p_vcount")
	HX_STACK_LINE(33)
	Array< ::Dynamic > triangles = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(triangles,"triangles");
	HX_STACK_LINE(34)
	::String _switch_13 = (p_type);
	if (  ( _switch_13==HX_CSTRING("triangles"))){
		HX_STACK_LINE(36)
		if (((p_indexes->length <= (int)0))){
			HX_STACK_LINE(36)
			triangles = Array_obj< ::Dynamic >::__new();
		}
		else{
			HX_STACK_LINE(36)
			triangles = p_indexes->__get((int)0).StaticCast< Array< ::Dynamic > >();
		}
	}
	else if (  ( _switch_13==HX_CSTRING("polygons"))){
		HX_STACK_LINE(38)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(38)
		int _g = p_indexes->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(38)
		while((true)){
			HX_STACK_LINE(38)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(38)
				break;
			}
			HX_STACK_LINE(38)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(40)
			Array< ::Dynamic > tris = ::haxor::io::file::ColladaFile_obj::TriangulatePolygon(p_indexes->__get(i).StaticCast< Array< ::Dynamic > >(),p_indexes->__get(i).StaticCast< Array< ::Dynamic > >()->length,null());		HX_STACK_VAR(tris,"tris");
			HX_STACK_LINE(41)
			while((true)){
				HX_STACK_LINE(41)
				if ((!(((tris->length > (int)0))))){
					HX_STACK_LINE(41)
					break;
				}
				HX_STACK_LINE(41)
				Array< int > _g2 = tris->shift().StaticCast< Array< int > >();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(41)
				triangles->push(_g2);
			}
		}
	}
	else if (  ( _switch_13==HX_CSTRING("polylist"))){
		HX_STACK_LINE(44)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(45)
		{
			HX_STACK_LINE(45)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(45)
			int _g = p_vcount->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(45)
			while((true)){
				HX_STACK_LINE(45)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(45)
					break;
				}
				HX_STACK_LINE(45)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(47)
				int o = p_vcount->__get(i);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(48)
				Array< ::Dynamic > tris = ::haxor::io::file::ColladaFile_obj::TriangulatePolygon(p_indexes->__get((int)0).StaticCast< Array< ::Dynamic > >(),o,k);		HX_STACK_VAR(tris,"tris");
				HX_STACK_LINE(49)
				while((true)){
					HX_STACK_LINE(49)
					if ((!(((tris->length > (int)0))))){
						HX_STACK_LINE(49)
						break;
					}
					HX_STACK_LINE(49)
					Array< int > _g11 = tris->shift().StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(49)
					triangles->push(_g11);
				}
				HX_STACK_LINE(50)
				hx::AddEq(k,o);
			}
		}
	}
	HX_STACK_LINE(53)
	return triangles;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ColladaFile_obj,GenerateTriangles,return )

Array< ::Dynamic > ColladaFile_obj::TriangulatePolygon( Array< ::Dynamic > t,int c,hx::Null< int >  __o_o){
int o = __o_o.Default(0);
	HX_STACK_FRAME("haxor.io.file.ColladaFile","TriangulatePolygon",0x3fc0d024,"haxor.io.file.ColladaFile.TriangulatePolygon","haxor/io/file/ColladaFile.hx",57,0xa1888587)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(o,"o")
{
		HX_STACK_LINE(58)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(59)
		int i0 = (int)0;		HX_STACK_VAR(i0,"i0");
		HX_STACK_LINE(60)
		int i1 = (int)1;		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(61)
		int i2 = (int)2;		HX_STACK_VAR(i2,"i2");
		HX_STACK_LINE(62)
		Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(63)
		while((true)){
			HX_STACK_LINE(63)
			if ((!(((i2 < c))))){
				HX_STACK_LINE(63)
				break;
			}
			HX_STACK_LINE(65)
			Array< int > _g = t->__get((i0 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(65)
			res->push(_g);
			HX_STACK_LINE(65)
			Array< int > _g1 = t->__get((i1 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(65)
			res->push(_g1);
			HX_STACK_LINE(65)
			Array< int > _g2 = t->__get((i2 + o)).StaticCast< Array< int > >()->copy();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(65)
			res->push(_g2);
			HX_STACK_LINE(66)
			(i1)++;
			HX_STACK_LINE(66)
			(i2)++;
		}
		HX_STACK_LINE(68)
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
