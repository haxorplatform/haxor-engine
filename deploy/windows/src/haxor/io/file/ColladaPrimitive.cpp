#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaFile
#include <haxor/io/file/ColladaFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaInput
#include <haxor/io/file/ColladaInput.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaPrimitive
#include <haxor/io/file/ColladaPrimitive.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaPrimitive_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","new",0x06746abd,"haxor.io.file.ColladaPrimitive.new","haxor/io/file/ColladaFile.hx",1083,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1089)
	this->indexes = null();
	HX_STACK_LINE(1088)
	this->vcount = null();
	HX_STACK_LINE(1087)
	this->inputs = null();
	HX_STACK_LINE(1086)
	this->material = HX_CSTRING("");
	HX_STACK_LINE(1085)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1107)
	this->inputs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1108)
	this->vcount = Array_obj< int >::__new();
	HX_STACK_LINE(1109)
	this->indexes = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1110)
	this->m_triangles = null();
}
;
	return null();
}

//ColladaPrimitive_obj::~ColladaPrimitive_obj() { }

Dynamic ColladaPrimitive_obj::__CreateEmpty() { return  new ColladaPrimitive_obj; }
hx::ObjectPtr< ColladaPrimitive_obj > ColladaPrimitive_obj::__new()
{  hx::ObjectPtr< ColladaPrimitive_obj > result = new ColladaPrimitive_obj();
	result->__construct();
	return result;}

Dynamic ColladaPrimitive_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaPrimitive_obj > result = new ColladaPrimitive_obj();
	result->__construct();
	return result;}

Array< ::Dynamic > ColladaPrimitive_obj::get_triangles( ){
	HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","get_triangles",0xcc17151f,"haxor.io.file.ColladaPrimitive.get_triangles","haxor/io/file/ColladaFile.hx",1093,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1094)
	if (((this->m_triangles != null()))){
		HX_STACK_LINE(1094)
		return this->m_triangles;
	}
	HX_STACK_LINE(1095)
	Array< ::Dynamic > _g = ::haxor::io::file::ColladaFile_obj::GenerateTriangles(this->type,this->indexes,this->vcount);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1095)
	this->m_triangles = _g;
	HX_STACK_LINE(1096)
	return this->m_triangles;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaPrimitive_obj,get_triangles,return )

int ColladaPrimitive_obj::get_offset( ){
	HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","get_offset",0x6ea1229f,"haxor.io.file.ColladaPrimitive.get_offset","haxor/io/file/ColladaFile.hx",1103,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1103)
	int mo = (int)0;		HX_STACK_VAR(mo,"mo");
	HX_STACK_LINE(1103)
	{
		HX_STACK_LINE(1103)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1103)
		int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1103)
		while((true)){
			HX_STACK_LINE(1103)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1103)
				break;
			}
			HX_STACK_LINE(1103)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1103)
			int _g2 = ::Math_obj::max(mo,(this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->offset + (int)1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1103)
			mo = _g2;
		}
	}
	HX_STACK_LINE(1103)
	return mo;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaPrimitive_obj,get_offset,return )

::haxor::io::file::ColladaInput ColladaPrimitive_obj::GetInput( ::String p_semantic,hx::Null< int >  __o_p_set){
int p_set = __o_p_set.Default(-1);
	HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","GetInput",0xe2484437,"haxor.io.file.ColladaPrimitive.GetInput","haxor/io/file/ColladaFile.hx",1114,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_semantic,"p_semantic")
	HX_STACK_ARG(p_set,"p_set")
{
		HX_STACK_LINE(1115)
		{
			HX_STACK_LINE(1115)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1115)
			int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1115)
			while((true)){
				HX_STACK_LINE(1115)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1115)
					break;
				}
				HX_STACK_LINE(1115)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1117)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == p_semantic))){
					HX_STACK_LINE(1119)
					if (((p_set < (int)0))){
						HX_STACK_LINE(1119)
						return this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >();
					}
					else{
						HX_STACK_LINE(1121)
						if (((p_set == this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->set))){
							HX_STACK_LINE(1121)
							return this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >();
						}
					}
				}
			}
		}
		HX_STACK_LINE(1124)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaPrimitive_obj,GetInput,return )

Dynamic ColladaPrimitive_obj::GetTriangulatedVectorArray( ::String p_semantic,hx::Null< int >  __o_p_set,hx::Null< bool >  __o_p_debug){
int p_set = __o_p_set.Default(-1);
bool p_debug = __o_p_debug.Default(false);
	HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","GetTriangulatedVectorArray",0xde1f7a6b,"haxor.io.file.ColladaPrimitive.GetTriangulatedVectorArray","haxor/io/file/ColladaFile.hx",1128,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_semantic,"p_semantic")
	HX_STACK_ARG(p_set,"p_set")
	HX_STACK_ARG(p_debug,"p_debug")
{
		HX_STACK_LINE(1129)
		::haxor::io::file::ColladaInput ci = this->GetInput(p_semantic,p_set);		HX_STACK_VAR(ci,"ci");
		HX_STACK_LINE(1130)
		if (((ci == null()))){
			HX_STACK_LINE(1130)
			return Dynamic( Array_obj<Dynamic>::__new());
		}
		HX_STACK_LINE(1132)
		Dynamic vec = ci->GetVectorArray();		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(1133)
		int off = ci->offset;		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(1134)
		Dynamic res = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(1136)
		if (((vec->__Field(HX_CSTRING("length"),true) <= (int)0))){
			HX_STACK_LINE(1136)
			return Dynamic( Array_obj<Dynamic>::__new());
		}
		HX_STACK_LINE(1137)
		if (((off < (int)0))){
			HX_STACK_LINE(1137)
			return Dynamic( Array_obj<Dynamic>::__new());
		}
		HX_STACK_LINE(1139)
		{
			HX_STACK_LINE(1139)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1139)
			int _g = this->get_triangles()->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1139)
			while((true)){
				HX_STACK_LINE(1139)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1139)
					break;
				}
				HX_STACK_LINE(1139)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1141)
				Array< ::Dynamic > _g2 = this->get_triangles();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1141)
				Array< int > tuple = _g2->__get(i).StaticCast< Array< int > >();		HX_STACK_VAR(tuple,"tuple");
				HX_STACK_LINE(1142)
				int idx = tuple->__get(off);		HX_STACK_VAR(idx,"idx");
				HX_STACK_LINE(1143)
				res->__Field(HX_CSTRING("push"),true)(vec->__GetItem(idx));
			}
		}
		HX_STACK_LINE(1149)
		return res;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(ColladaPrimitive_obj,GetTriangulatedVectorArray,return )

Dynamic ColladaPrimitive_obj::GetVectorArray( ::String p_semantic,hx::Null< int >  __o_p_set){
int p_set = __o_p_set.Default(-1);
	HX_STACK_FRAME("haxor.io.file.ColladaPrimitive","GetVectorArray",0xc1a8e9c3,"haxor.io.file.ColladaPrimitive.GetVectorArray","haxor/io/file/ColladaFile.hx",1153,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_semantic,"p_semantic")
	HX_STACK_ARG(p_set,"p_set")
{
		HX_STACK_LINE(1154)
		Dynamic res = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(1156)
		{
			HX_STACK_LINE(1156)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1156)
			int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1156)
			while((true)){
				HX_STACK_LINE(1156)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1156)
					break;
				}
				HX_STACK_LINE(1156)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1158)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == p_semantic))){
					HX_STACK_LINE(1160)
					if (((p_set < (int)0))){
						HX_STACK_LINE(1160)
						Dynamic _g2 = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->GetVectorArray();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(1160)
						res = _g2;
						HX_STACK_LINE(1160)
						break;
					}
					else{
						HX_STACK_LINE(1162)
						if (((p_set == this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->set))){
							HX_STACK_LINE(1162)
							Dynamic _g11 = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->GetVectorArray();		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(1162)
							res = _g11;
							HX_STACK_LINE(1162)
							break;
						}
					}
				}
			}
		}
		HX_STACK_LINE(1166)
		if (((p_semantic == HX_CSTRING("color")))){
			HX_STACK_LINE(1166)
			if (((p_set < (int)0))){
				HX_STACK_LINE(1168)
				Dynamic l = this->GetVectorArray(HX_CSTRING("color"),(int)0);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(1169)
				if (((l->__Field(HX_CSTRING("length"),true) > (int)0))){
					HX_STACK_LINE(1171)
					int len = ::Math_obj::min(l->__Field(HX_CSTRING("length"),true),res->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(1172)
					{
						HX_STACK_LINE(1172)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(1172)
						while((true)){
							HX_STACK_LINE(1172)
							if ((!(((_g < len))))){
								HX_STACK_LINE(1172)
								break;
							}
							HX_STACK_LINE(1172)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(1172)
							res->__GetItem(i)->__FieldRef(HX_CSTRING("a")) = l->__GetItem(i)->__Field(HX_CSTRING("r"),true);
						}
					}
				}
			}
		}
		HX_STACK_LINE(1176)
		return res;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaPrimitive_obj,GetVectorArray,return )


ColladaPrimitive_obj::ColladaPrimitive_obj()
{
}

void ColladaPrimitive_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaPrimitive);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(material,"material");
	HX_MARK_MEMBER_NAME(inputs,"inputs");
	HX_MARK_MEMBER_NAME(vcount,"vcount");
	HX_MARK_MEMBER_NAME(indexes,"indexes");
	HX_MARK_MEMBER_NAME(m_triangles,"m_triangles");
	HX_MARK_END_CLASS();
}

void ColladaPrimitive_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(material,"material");
	HX_VISIT_MEMBER_NAME(inputs,"inputs");
	HX_VISIT_MEMBER_NAME(vcount,"vcount");
	HX_VISIT_MEMBER_NAME(indexes,"indexes");
	HX_VISIT_MEMBER_NAME(m_triangles,"m_triangles");
}

Dynamic ColladaPrimitive_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inputs") ) { return inputs; }
		if (HX_FIELD_EQ(inName,"vcount") ) { return vcount; }
		if (HX_FIELD_EQ(inName,"offset") ) { return get_offset(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { return material; }
		if (HX_FIELD_EQ(inName,"GetInput") ) { return GetInput_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"triangles") ) { return get_triangles(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_offset") ) { return get_offset_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_triangles") ) { return m_triangles; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_triangles") ) { return get_triangles_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GetVectorArray") ) { return GetVectorArray_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"GetTriangulatedVectorArray") ) { return GetTriangulatedVectorArray_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaPrimitive_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inputs") ) { inputs=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vcount") ) { vcount=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { indexes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { material=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_triangles") ) { m_triangles=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaPrimitive_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("material"));
	outFields->push(HX_CSTRING("inputs"));
	outFields->push(HX_CSTRING("vcount"));
	outFields->push(HX_CSTRING("indexes"));
	outFields->push(HX_CSTRING("triangles"));
	outFields->push(HX_CSTRING("m_triangles"));
	outFields->push(HX_CSTRING("offset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaPrimitive_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(ColladaPrimitive_obj,material),HX_CSTRING("material")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaPrimitive_obj,inputs),HX_CSTRING("inputs")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(ColladaPrimitive_obj,vcount),HX_CSTRING("vcount")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaPrimitive_obj,indexes),HX_CSTRING("indexes")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaPrimitive_obj,m_triangles),HX_CSTRING("m_triangles")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("material"),
	HX_CSTRING("inputs"),
	HX_CSTRING("vcount"),
	HX_CSTRING("indexes"),
	HX_CSTRING("get_triangles"),
	HX_CSTRING("m_triangles"),
	HX_CSTRING("get_offset"),
	HX_CSTRING("GetInput"),
	HX_CSTRING("GetTriangulatedVectorArray"),
	HX_CSTRING("GetVectorArray"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaPrimitive_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaPrimitive_obj::__mClass,"__mClass");
};

#endif

Class ColladaPrimitive_obj::__mClass;

void ColladaPrimitive_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaPrimitive"), hx::TCanCast< ColladaPrimitive_obj> ,sStaticFields,sMemberFields,
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

void ColladaPrimitive_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file