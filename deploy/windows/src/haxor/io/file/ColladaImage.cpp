#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaImage
#include <haxor/io/file/ColladaImage.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaImage_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaImage","new",0x8e25c971,"haxor.io.file.ColladaImage.new","haxor/io/file/ColladaFile.hx",1231,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1240)
	this->data = null();
	HX_STACK_LINE(1239)
	this->depth = (int)0;
	HX_STACK_LINE(1238)
	this->height = (int)0;
	HX_STACK_LINE(1237)
	this->width = (int)0;
	HX_STACK_LINE(1236)
	this->source = HX_CSTRING("");
	HX_STACK_LINE(1235)
	this->format = HX_CSTRING("");
	HX_STACK_LINE(1234)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1233)
	this->id = HX_CSTRING("");
}
;
	return null();
}

//ColladaImage_obj::~ColladaImage_obj() { }

Dynamic ColladaImage_obj::__CreateEmpty() { return  new ColladaImage_obj; }
hx::ObjectPtr< ColladaImage_obj > ColladaImage_obj::__new()
{  hx::ObjectPtr< ColladaImage_obj > result = new ColladaImage_obj();
	result->__construct();
	return result;}

Dynamic ColladaImage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaImage_obj > result = new ColladaImage_obj();
	result->__construct();
	return result;}


ColladaImage_obj::ColladaImage_obj()
{
}

void ColladaImage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaImage);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(depth,"depth");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_END_CLASS();
}

void ColladaImage_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(depth,"depth");
	HX_VISIT_MEMBER_NAME(data,"data");
}

Dynamic ColladaImage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"depth") ) { return depth; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { return format; }
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaImage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::graphics::texture::Bitmap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"depth") ) { depth=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaImage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("format"));
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("depth"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaImage_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaImage_obj,name),HX_CSTRING("name")},
	{hx::fsString,(int)offsetof(ColladaImage_obj,format),HX_CSTRING("format")},
	{hx::fsString,(int)offsetof(ColladaImage_obj,source),HX_CSTRING("source")},
	{hx::fsInt,(int)offsetof(ColladaImage_obj,width),HX_CSTRING("width")},
	{hx::fsInt,(int)offsetof(ColladaImage_obj,height),HX_CSTRING("height")},
	{hx::fsInt,(int)offsetof(ColladaImage_obj,depth),HX_CSTRING("depth")},
	{hx::fsObject /*::haxor::graphics::texture::Bitmap*/ ,(int)offsetof(ColladaImage_obj,data),HX_CSTRING("data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("format"),
	HX_CSTRING("source"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("depth"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaImage_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaImage_obj::__mClass,"__mClass");
};

#endif

Class ColladaImage_obj::__mClass;

void ColladaImage_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaImage"), hx::TCanCast< ColladaImage_obj> ,sStaticFields,sMemberFields,
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

void ColladaImage_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
