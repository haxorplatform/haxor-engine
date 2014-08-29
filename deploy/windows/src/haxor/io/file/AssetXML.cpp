#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
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
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void AssetXML_obj::__construct(::String p_name,::String p_src)
{
HX_STACK_FRAME("haxor.io.file.AssetXML","new",0x9d0b4eaf,"haxor.io.file.AssetXML.new","haxor/io/file/AssetXML.hx",22,0xd2413fe0)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_src,"p_src")
{
	HX_STACK_LINE(23)
	super::__construct(p_name);
	HX_STACK_LINE(24)
	::Xml _g = ::Xml_obj::parse(p_src);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	this->x = _g;
	HX_STACK_LINE(25)
	::Xml _g1 = this->x->firstElement();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(25)
	this->TraverseStep(_g1);
}
;
	return null();
}

//AssetXML_obj::~AssetXML_obj() { }

Dynamic AssetXML_obj::__CreateEmpty() { return  new AssetXML_obj; }
hx::ObjectPtr< AssetXML_obj > AssetXML_obj::__new(::String p_name,::String p_src)
{  hx::ObjectPtr< AssetXML_obj > result = new AssetXML_obj();
	result->__construct(p_name,p_src);
	return result;}

Dynamic AssetXML_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetXML_obj > result = new AssetXML_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void AssetXML_obj::Parse( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.AssetXML","Parse",0x28d1f022,"haxor.io.file.AssetXML.Parse","haxor/io/file/AssetXML.hx",32,0xd2413fe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetXML_obj,Parse,(void))

Void AssetXML_obj::TraverseStep( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.AssetXML","TraverseStep",0x0eeb5e0f,"haxor.io.file.AssetXML.TraverseStep","haxor/io/file/AssetXML.hx",39,0xd2413fe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(40)
		this->Parse(n);
		HX_STACK_LINE(41)
		Dynamic l = n->elements();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(42)
		while((true)){
			HX_STACK_LINE(42)
			if ((!(l->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(42)
				break;
			}
			HX_STACK_LINE(42)
			::Xml _g = l->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			this->TraverseStep(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetXML_obj,TraverseStep,(void))

::String AssetXML_obj::_a( ::Xml n,::String a,Dynamic v){
	HX_STACK_FRAME("haxor.io.file.AssetXML","_a",0xa72953b3,"haxor.io.file.AssetXML._a","haxor/io/file/AssetXML.hx",52,0xd2413fe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(52)
	if ((n->exists(a))){
		HX_STACK_LINE(52)
		return n->get(a);
	}
	else{
		HX_STACK_LINE(52)
		return v;
	}
	HX_STACK_LINE(52)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AssetXML_obj,_a,return )

::String AssetXML_obj::_tla( ::Xml n,::String a,Dynamic v){
	HX_STACK_FRAME("haxor.io.file.AssetXML","_tla",0xc2faafbb,"haxor.io.file.AssetXML._tla","haxor/io/file/AssetXML.hx",61,0xd2413fe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(61)
	if ((n->exists(a))){
		HX_STACK_LINE(61)
		::String _g = n->get(a);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		return ::StringTools_obj::trim(_g).toLowerCase();
	}
	else{
		HX_STACK_LINE(61)
		return v;
	}
	HX_STACK_LINE(61)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AssetXML_obj,_tla,return )

Dynamic AssetXML_obj::_p( ::Xml n,::String p,Dynamic v,hx::Null< bool >  __o_t,hx::Null< bool >  __o_tl){
bool t = __o_t.Default(false);
bool tl = __o_tl.Default(false);
	HX_STACK_FRAME("haxor.io.file.AssetXML","_p",0xa72953c2,"haxor.io.file.AssetXML._p","haxor/io/file/AssetXML.hx",73,0xd2413fe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(tl,"tl")
{
		HX_STACK_LINE(74)
		Array< ::String > l = p.split(HX_CSTRING("."));		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(75)
		::Xml it = n;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(76)
			int _g = l->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(76)
			while((true)){
				HX_STACK_LINE(76)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(76)
					break;
				}
				HX_STACK_LINE(76)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(78)
				::String tk = l->__get(i);		HX_STACK_VAR(tk,"tk");
				HX_STACK_LINE(79)
				::String _switch_1 = (tk);
				if (  ( _switch_1==HX_CSTRING("$text"))){
					HX_STACK_LINE(82)
					::Xml _g2 = it->firstChild();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(82)
					if (((_g2 == null()))){
						HX_STACK_LINE(82)
						return v;
					}
					HX_STACK_LINE(83)
					::String txt = it->firstChild()->toString();		HX_STACK_VAR(txt,"txt");
					HX_STACK_LINE(84)
					if ((t)){
						HX_STACK_LINE(84)
						::String _g11 = ::StringTools_obj::trim(txt);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(84)
						txt = _g11;
					}
					HX_STACK_LINE(85)
					if ((tl)){
						HX_STACK_LINE(85)
						::String _g21 = txt.toLowerCase();		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(85)
						txt = _g21;
					}
					HX_STACK_LINE(86)
					return txt;
				}
				else  {
					HX_STACK_LINE(89)
					::String _g3 = tk.charAt((int)0);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(89)
					if (((_g3 == HX_CSTRING("@")))){
						HX_STACK_LINE(91)
						if ((t)){
							HX_STACK_LINE(91)
							if ((tl)){
								HX_STACK_LINE(91)
								::String _g4 = tk.substr((int)1,null());		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(91)
								return this->_tla(it,_g4,v);
							}
						}
						HX_STACK_LINE(92)
						::String _g5 = tk.substr((int)1,null());		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(92)
						return this->_a(it,_g5,v);
					}
					HX_STACK_LINE(94)
					Dynamic eit = it->elementsNamed(tk);		HX_STACK_VAR(eit,"eit");
					HX_STACK_LINE(95)
					if (((eit == null()))){
						HX_STACK_LINE(95)
						return v;
					}
					HX_STACK_LINE(96)
					if (((i == (l->length - (int)1)))){
						HX_STACK_LINE(96)
						return eit;
					}
					HX_STACK_LINE(97)
					if ((!(eit->__Field(HX_CSTRING("hasNext"),true)()))){
						HX_STACK_LINE(97)
						return v;
					}
					HX_STACK_LINE(98)
					::Xml _g6 = eit->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(98)
					it = _g6;
				}
;
;
			}
		}
		HX_STACK_LINE(101)
		return v;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(AssetXML_obj,_p,return )

::Xml AssetXML_obj::_f( ::Xml n,::String p,::String a,::String t){
	HX_STACK_FRAME("haxor.io.file.AssetXML","_f",0xa72953b8,"haxor.io.file.AssetXML._f","haxor/io/file/AssetXML.hx",113,0xd2413fe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(p,"p")
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(114)
	Dynamic f = this->_p(n,p,HX_CSTRING(""),null(),null());		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(115)
	Dynamic it;		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(115)
	if (((f == HX_CSTRING("")))){
		HX_STACK_LINE(115)
		it = null();
	}
	else{
		HX_STACK_LINE(115)
		it = f;
	}
	HX_STACK_LINE(116)
	if (((it == null()))){
		HX_STACK_LINE(116)
		return null();
	}
	HX_STACK_LINE(117)
	while((true)){
		HX_STACK_LINE(117)
		if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(117)
			break;
		}
		HX_STACK_LINE(117)
		::Xml e = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(117)
		::String _g = this->_a(e,a,HX_CSTRING(""));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		if (((_g == t))){
			HX_STACK_LINE(117)
			return e;
		}
	}
	HX_STACK_LINE(118)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AssetXML_obj,_f,return )


AssetXML_obj::AssetXML_obj()
{
}

void AssetXML_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AssetXML);
	HX_MARK_MEMBER_NAME(x,"x");
	::haxor::io::file::AssetFile_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AssetXML_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	::haxor::io::file::AssetFile_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AssetXML_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_a") ) { return _a_dyn(); }
		if (HX_FIELD_EQ(inName,"_p") ) { return _p_dyn(); }
		if (HX_FIELD_EQ(inName,"_f") ) { return _f_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_tla") ) { return _tla_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TraverseStep") ) { return TraverseStep_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AssetXML_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< ::Xml >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AssetXML_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Xml*/ ,(int)offsetof(AssetXML_obj,x),HX_CSTRING("x")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("Parse"),
	HX_CSTRING("TraverseStep"),
	HX_CSTRING("_a"),
	HX_CSTRING("_tla"),
	HX_CSTRING("_p"),
	HX_CSTRING("_f"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AssetXML_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AssetXML_obj::__mClass,"__mClass");
};

#endif

Class AssetXML_obj::__mClass;

void AssetXML_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.AssetXML"), hx::TCanCast< AssetXML_obj> ,sStaticFields,sMemberFields,
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

void AssetXML_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
