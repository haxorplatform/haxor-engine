#ifndef INCLUDED_haxor_io_file_ColladaController
#define INCLUDED_haxor_io_file_ColladaController

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaController)
HX_DECLARE_CLASS3(haxor,io,file,ColladaInput)
HX_DECLARE_CLASS3(haxor,io,file,ColladaPrimitive)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaController_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaController_obj OBJ_;
		ColladaController_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaController_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaController_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaController"); }

		::String type;
		::String source;
		::String id;
		::String name;
		Array< Float > matrix;
		Array< ::Dynamic > binds;
		Array< ::String > joints;
		Array< ::Dynamic > inputs;
		Array< int > vcount;
		Array< ::Dynamic > indexes;
		Array< ::Dynamic > weights;
		Array< ::Dynamic > bones;
		virtual int get_offset( );
		Dynamic get_offset_dyn();

		virtual ::haxor::math::Matrix4 GetBSM( );
		Dynamic GetBSM_dyn();

		virtual int GetJointIndex( ::String p_joint);
		Dynamic GetJointIndex_dyn();

		virtual Array< ::Dynamic > GetBinds( );
		Dynamic GetBinds_dyn();

		virtual Array< ::Dynamic > GetTriangulatedWeights( ::haxor::io::file::ColladaPrimitive cp);
		Dynamic GetTriangulatedWeights_dyn();

		virtual Array< ::Dynamic > GetTriangulatedBones( ::haxor::io::file::ColladaPrimitive cp);
		Dynamic GetTriangulatedBones_dyn();

		virtual Void GenerateBonesAndWeights( );
		Dynamic GenerateBonesAndWeights_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaController */ 
