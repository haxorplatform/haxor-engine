#ifndef INCLUDED_haxor_io_file_ColladaFile
#define INCLUDED_haxor_io_file_ColladaFile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/file/AssetXML.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,Entity)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,io,file,AssetFile)
HX_DECLARE_CLASS3(haxor,io,file,AssetXML)
HX_DECLARE_CLASS3(haxor,io,file,ColladaAnimation)
HX_DECLARE_CLASS3(haxor,io,file,ColladaAssetData)
HX_DECLARE_CLASS3(haxor,io,file,ColladaController)
HX_DECLARE_CLASS3(haxor,io,file,ColladaFile)
HX_DECLARE_CLASS3(haxor,io,file,ColladaGeometry)
HX_DECLARE_CLASS3(haxor,io,file,ColladaImage)
HX_DECLARE_CLASS3(haxor,io,file,ColladaInput)
HX_DECLARE_CLASS3(haxor,io,file,ColladaInstance)
HX_DECLARE_CLASS3(haxor,io,file,ColladaLight)
HX_DECLARE_CLASS3(haxor,io,file,ColladaMaterial)
HX_DECLARE_CLASS3(haxor,io,file,ColladaMesh)
HX_DECLARE_CLASS3(haxor,io,file,ColladaNode)
HX_DECLARE_CLASS3(haxor,io,file,ColladaPrimitive)
HX_DECLARE_CLASS3(haxor,io,file,ColladaVisualScene)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaFile_obj : public ::haxor::io::file::AssetXML_obj{
	public:
		typedef ::haxor::io::file::AssetXML_obj super;
		typedef ColladaFile_obj OBJ_;
		ColladaFile_obj();
		Void __construct(::String p_name,::String p_src);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaFile_obj > __new(::String p_name,::String p_src);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaFile_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaFile"); }

		::String xmlns;
		::String version;
		::haxor::io::file::ColladaAssetData data;
		Array< ::Dynamic > geometries;
		Array< ::Dynamic > images;
		Array< ::Dynamic > controllers;
		Array< ::Dynamic > materials;
		Array< ::Dynamic > lights;
		Array< ::Dynamic > animations;
		::haxor::io::file::ColladaVisualScene scene;
		int m_id;
		virtual Dynamic get_asset( );

		virtual Void AddAnimations( ::haxor::core::Entity p_entity,hx::Null< bool >  p_exact);
		Dynamic AddAnimations_dyn();

		virtual ::haxor::component::MeshRenderer CreateMeshRenderer( ::haxor::core::Entity e,::String msh,::haxor::io::file::ColladaPrimitive cp,::Class t,::haxor::io::file::ColladaController cc);
		Dynamic CreateMeshRenderer_dyn();

		virtual ::haxor::io::file::ColladaLight FindLightById( ::String p_id);
		Dynamic FindLightById_dyn();

		virtual ::haxor::io::file::ColladaGeometry FindGeometryById( ::String p_id);
		Dynamic FindGeometryById_dyn();

		virtual ::haxor::io::file::ColladaController FindControllerById( ::String p_id);
		Dynamic FindControllerById_dyn();

		virtual ::haxor::io::file::ColladaNode FindNodeById( ::String p_id);
		Dynamic FindNodeById_dyn();

		virtual ::haxor::io::file::ColladaMaterial FindMaterialById( ::String p_id);
		Dynamic FindMaterialById_dyn();

		virtual Void Parse( ::Xml n);

		virtual Void ParseLightLibrary( ::Xml n);
		Dynamic ParseLightLibrary_dyn();

		virtual Void ParseAnimationLibrary( ::Xml n);
		Dynamic ParseAnimationLibrary_dyn();

		virtual Void ParseMaterialLibrary( ::Xml n);
		Dynamic ParseMaterialLibrary_dyn();

		virtual Void ParseSceneLibrary( ::Xml n);
		Dynamic ParseSceneLibrary_dyn();

		virtual Void ParseVisualScene( ::Xml n);
		Dynamic ParseVisualScene_dyn();

		virtual Void TraverseVisualSceneNodes( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n);
		Dynamic TraverseVisualSceneNodes_dyn();

		virtual ::haxor::io::file::ColladaNode ParseVisualSceneNode( ::haxor::io::file::ColladaVisualScene scn,::haxor::io::file::ColladaNode p,::Xml n);
		Dynamic ParseVisualSceneNode_dyn();

		virtual Void ParseInstanceMaterials( ::haxor::io::file::ColladaInstance ci,::Xml n);
		Dynamic ParseInstanceMaterials_dyn();

		virtual Void ParseControllerLibrary( ::Xml n);
		Dynamic ParseControllerLibrary_dyn();

		virtual Void ParseController( ::haxor::io::file::ColladaController c,::Xml n);
		Dynamic ParseController_dyn();

		virtual Void ParseControllerSkin( ::haxor::io::file::ColladaController c,::Xml n);
		Dynamic ParseControllerSkin_dyn();

		virtual Void ParseImageLibrary( ::Xml n);
		Dynamic ParseImageLibrary_dyn();

		virtual Void ParseGeometryLibrary( ::Xml n);
		Dynamic ParseGeometryLibrary_dyn();

		virtual Void ParseGeometry( ::haxor::io::file::ColladaGeometry g,::Xml n);
		Dynamic ParseGeometry_dyn();

		virtual Void ParseMesh( ::haxor::io::file::ColladaMesh m,::Xml n);
		Dynamic ParseMesh_dyn();

		virtual Void ParsePrimitive( ::haxor::io::file::ColladaPrimitive cp,::Xml p,::Xml n);
		Dynamic ParsePrimitive_dyn();

		virtual Array< ::Dynamic > ParseInputList( ::Xml p,::Xml n);
		Dynamic ParseInputList_dyn();

		virtual Void TraverseStep( ::Xml n);

		virtual Array< Float > _f32a( ::String v);
		Dynamic _f32a_dyn();

		virtual Array< int > _i16a( ::String v);
		Dynamic _i16a_dyn();

		virtual Array< ::Dynamic > _i16ta( ::String v,int s);
		Dynamic _i16ta_dyn();

		static Array< ::Dynamic > GenerateTriangles( ::String p_type,Array< ::Dynamic > p_indexes,Array< int > p_vcount);
		static Dynamic GenerateTriangles_dyn();

		static Array< ::Dynamic > TriangulatePolygon( Array< ::Dynamic > t,int c,hx::Null< int >  o);
		static Dynamic TriangulatePolygon_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaFile */ 
