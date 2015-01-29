#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaNode
#include <haxor/io/file/ColladaNode.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaVisualScene
#include <haxor/io/file/ColladaVisualScene.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaVisualScene_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaVisualScene","new",0x24d68802,"haxor.io.file.ColladaVisualScene.new","haxor/io/file/ColladaFile.hx",1371,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1376)
	this->children = null();
	HX_STACK_LINE(1375)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1374)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1373)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1380)
	this->children = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//ColladaVisualScene_obj::~ColladaVisualScene_obj() { }

Dynamic ColladaVisualScene_obj::__CreateEmpty() { return  new ColladaVisualScene_obj; }
hx::ObjectPtr< ColladaVisualScene_obj > ColladaVisualScene_obj::__new()
{  hx::ObjectPtr< ColladaVisualScene_obj > result = new ColladaVisualScene_obj();
	result->__construct();
	return result;}

Dynamic ColladaVisualScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaVisualScene_obj > result = new ColladaVisualScene_obj();
	result->__construct();
	return result;}

Void ColladaVisualScene_obj::Traverse( Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.io.file.ColladaVisualScene","Traverse",0x9f3296f0,"haxor.io.file.ColladaVisualScene.Traverse","haxor/io/file/ColladaFile.hx",1385,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(1385)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1385)
		int _g = this->children->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1385)
		while((true)){
			HX_STACK_LINE(1385)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1385)
				break;
			}
			HX_STACK_LINE(1385)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1385)
			this->TraverseStep(this->children->__get(i).StaticCast< ::haxor::io::file::ColladaNode >(),p_callback);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaVisualScene_obj,Traverse,(void))

Void ColladaVisualScene_obj::TraverseStep( ::haxor::io::file::ColladaNode p_node,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.io.file.ColladaVisualScene","TraverseStep",0xa295e25c,"haxor.io.file.ColladaVisualScene.TraverseStep","haxor/io/file/ColladaFile.hx",1389,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_node,"p_node")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(1390)
		if (((p_callback != null()))){
			HX_STACK_LINE(1390)
			p_callback(p_node).Cast< Void >();
		}
		HX_STACK_LINE(1391)
		{
			HX_STACK_LINE(1391)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1391)
			int _g = p_node->children->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1391)
			while((true)){
				HX_STACK_LINE(1391)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1391)
					break;
				}
				HX_STACK_LINE(1391)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1391)
				this->TraverseStep(p_node->children->__get(i).StaticCast< ::haxor::io::file::ColladaNode >(),p_callback);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ColladaVisualScene_obj,TraverseStep,(void))


ColladaVisualScene_obj::ColladaVisualScene_obj()
{
}

void ColladaVisualScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaVisualScene);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(children,"children");
	HX_MARK_END_CLASS();
}

void ColladaVisualScene_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(children,"children");
}

Dynamic ColladaVisualScene_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"children") ) { return children; }
		if (HX_FIELD_EQ(inName,"Traverse") ) { return Traverse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TraverseStep") ) { return TraverseStep_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaVisualScene_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"children") ) { children=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaVisualScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("children"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaVisualScene_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(ColladaVisualScene_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaVisualScene_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaVisualScene_obj,children),HX_CSTRING("children")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("children"),
	HX_CSTRING("Traverse"),
	HX_CSTRING("TraverseStep"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaVisualScene_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaVisualScene_obj::__mClass,"__mClass");
};

#endif

Class ColladaVisualScene_obj::__mClass;

void ColladaVisualScene_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaVisualScene"), hx::TCanCast< ColladaVisualScene_obj> ,sStaticFields,sMemberFields,
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

void ColladaVisualScene_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
