#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void AssetFile_obj::__construct(::String p_name)
{
HX_STACK_FRAME("haxor.io.file.AssetFile","new",0x9fd51248,"haxor.io.file.AssetFile.new","haxor/io/file/AssetFile.hx",24,0xfd53a109)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
{
	HX_STACK_LINE(24)
	super::__construct(p_name);
}
;
	return null();
}

//AssetFile_obj::~AssetFile_obj() { }

Dynamic AssetFile_obj::__CreateEmpty() { return  new AssetFile_obj; }
hx::ObjectPtr< AssetFile_obj > AssetFile_obj::__new(::String p_name)
{  hx::ObjectPtr< AssetFile_obj > result = new AssetFile_obj();
	result->__construct(p_name);
	return result;}

Dynamic AssetFile_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetFile_obj > result = new AssetFile_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic AssetFile_obj::get_asset( ){
	HX_STACK_FRAME("haxor.io.file.AssetFile","get_asset",0xc2be662f,"haxor.io.file.AssetFile.get_asset","haxor/io/file/AssetFile.hx",16,0xfd53a109)
	HX_STACK_THIS(this)
	HX_STACK_LINE(16)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AssetFile_obj,get_asset,return )

Array< Float > AssetFile_obj::stof32a( ::String v,::String __o_sep){
::String sep = __o_sep.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.io.file.AssetFile","stof32a",0xd1438fd2,"haxor.io.file.AssetFile.stof32a","haxor/io/file/AssetFile.hx",34,0xfd53a109)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(sep,"sep")
{
		HX_STACK_LINE(35)
		::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(35)
		Array< ::String > l = ::StringTools_obj::trim(_g).split(sep);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(36)
		Array< Float > a = Array_obj< Float >::__new();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(37)
			int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(37)
			while((true)){
				HX_STACK_LINE(37)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(37)
					break;
				}
				HX_STACK_LINE(37)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(37)
				Float _g11 = ::Std_obj::parseFloat(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(37)
				a->push(_g11);
			}
		}
		HX_STACK_LINE(38)
		return a;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(AssetFile_obj,stof32a,return )

Array< int > AssetFile_obj::stoi16a( ::String v,::String __o_sep){
::String sep = __o_sep.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.io.file.AssetFile","stoi16a",0xd33db2a9,"haxor.io.file.AssetFile.stoi16a","haxor/io/file/AssetFile.hx",48,0xfd53a109)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(sep,"sep")
{
		HX_STACK_LINE(49)
		::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(49)
		Array< ::String > l = ::StringTools_obj::trim(_g).split(sep);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(50)
		Array< int > a = Array_obj< int >::__new();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(51)
			int _g2 = l->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(51)
			while((true)){
				HX_STACK_LINE(51)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(51)
					break;
				}
				HX_STACK_LINE(51)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(51)
				Dynamic _g11 = ::Std_obj::parseInt(l->__get(i));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(51)
				a->push(_g11);
			}
		}
		HX_STACK_LINE(52)
		return a;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(AssetFile_obj,stoi16a,return )

Array< ::Dynamic > AssetFile_obj::stoi16ta( ::String v,int s,::String __o_sep){
::String sep = __o_sep.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.io.file.AssetFile","stoi16ta",0x02beb225,"haxor.io.file.AssetFile.stoi16ta","haxor/io/file/AssetFile.hx",63,0xfd53a109)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(sep,"sep")
{
		HX_STACK_LINE(64)
		::String _g = ::StringTools_obj::replace(v,HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		Array< ::String > l = ::StringTools_obj::trim(_g).split(sep);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(65)
		::String tl = HX_CSTRING("");		HX_STACK_VAR(tl,"tl");
		HX_STACK_LINE(66)
		Array< ::Dynamic > a = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(67)
		Array< int > bf;		HX_STACK_VAR(bf,"bf");
		HX_STACK_LINE(68)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(70)
		while((true)){
			HX_STACK_LINE(70)
			if ((!(((k < l->length))))){
				HX_STACK_LINE(70)
				break;
			}
			HX_STACK_LINE(72)
			bf = Array_obj< int >::__new();
			HX_STACK_LINE(73)
			{
				HX_STACK_LINE(73)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(73)
				while((true)){
					HX_STACK_LINE(73)
					if ((!(((_g1 < s))))){
						HX_STACK_LINE(73)
						break;
					}
					HX_STACK_LINE(73)
					int j = (_g1)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(73)
					int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(73)
					::String _g2 = l->__get(_g11);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(73)
					Dynamic _g3 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(73)
					bf->push(_g3);
				}
			}
			HX_STACK_LINE(74)
			a->push(bf);
		}
		HX_STACK_LINE(76)
		return a;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(AssetFile_obj,stoi16ta,return )


AssetFile_obj::AssetFile_obj()
{
}

void AssetFile_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AssetFile);
	HX_MARK_MEMBER_NAME(asset,"asset");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AssetFile_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(asset,"asset");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AssetFile_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"asset") ) { return inCallProp ? get_asset() : asset; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"stof32a") ) { return stof32a_dyn(); }
		if (HX_FIELD_EQ(inName,"stoi16a") ) { return stoi16a_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stoi16ta") ) { return stoi16ta_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_asset") ) { return get_asset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AssetFile_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"asset") ) { asset=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AssetFile_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("asset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(AssetFile_obj,asset),HX_CSTRING("asset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("asset"),
	HX_CSTRING("get_asset"),
	HX_CSTRING("stof32a"),
	HX_CSTRING("stoi16a"),
	HX_CSTRING("stoi16ta"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AssetFile_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AssetFile_obj::__mClass,"__mClass");
};

#endif

Class AssetFile_obj::__mClass;

void AssetFile_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.AssetFile"), hx::TCanCast< AssetFile_obj> ,sStaticFields,sMemberFields,
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

void AssetFile_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
