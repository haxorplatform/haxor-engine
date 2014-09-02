#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_ds_SAPInterval
#include <haxor/ds/SAPInterval.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace ds{

Void SAPInterval_obj::__construct()
{
HX_STACK_FRAME("haxor.ds.SAPInterval","new",0x243f83a6,"haxor.ds.SAPInterval.new","haxor/ds/SAP.hx",434,0xbaeeb06f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(435)
	this->min = 0.0;
	HX_STACK_LINE(436)
	this->max = 0.0;
	HX_STACK_LINE(437)
	this->id = (int)0;
}
;
	return null();
}

//SAPInterval_obj::~SAPInterval_obj() { }

Dynamic SAPInterval_obj::__CreateEmpty() { return  new SAPInterval_obj; }
hx::ObjectPtr< SAPInterval_obj > SAPInterval_obj::__new()
{  hx::ObjectPtr< SAPInterval_obj > result = new SAPInterval_obj();
	result->__construct();
	return result;}

Dynamic SAPInterval_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAPInterval_obj > result = new SAPInterval_obj();
	result->__construct();
	return result;}

Void SAPInterval_obj::Set( Float p_min,Float p_max){
{
		HX_STACK_FRAME("haxor.ds.SAPInterval","Set",0x242b06c8,"haxor.ds.SAPInterval.Set","haxor/ds/SAP.hx",445,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(445)
		this->min = p_min;
		HX_STACK_LINE(445)
		this->max = p_max;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAPInterval_obj,Set,(void))

bool SAPInterval_obj::Overlap( ::haxor::ds::SAPInterval p_interval){
	HX_STACK_FRAME("haxor.ds.SAPInterval","Overlap",0x73af39ad,"haxor.ds.SAPInterval.Overlap","haxor/ds/SAP.hx",452,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_interval,"p_interval")
	HX_STACK_LINE(452)
	if (((p_interval->min > this->min))){
		HX_STACK_LINE(452)
		return (p_interval->min <= this->max);
	}
	HX_STACK_LINE(452)
	return (p_interval->max >= this->min);
}


HX_DEFINE_DYNAMIC_FUNC1(SAPInterval_obj,Overlap,return )

::String SAPInterval_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.ds.SAPInterval","ToString",0xb8e73bc6,"haxor.ds.SAPInterval.ToString","haxor/ds/SAP.hx",458,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(458)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(458)
		{
			HX_STACK_LINE(458)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(458)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(458)
			{
				HX_STACK_LINE(458)
				Float p_v = (this->min * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(458)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(458)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(458)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(458)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(458)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(458)
		{
			HX_STACK_LINE(458)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(458)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(458)
			{
				HX_STACK_LINE(458)
				Float p_v = (this->max * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(458)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(458)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(458)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(458)
		return (_g6 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(SAPInterval_obj,ToString,return )


SAPInterval_obj::SAPInterval_obj()
{
}

void SAPInterval_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SAPInterval);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(min,"min");
	HX_MARK_MEMBER_NAME(max,"max");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_MEMBER_NAME(prev,"prev");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_END_CLASS();
}

void SAPInterval_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(min,"min");
	HX_VISIT_MEMBER_NAME(max,"max");
	HX_VISIT_MEMBER_NAME(next,"next");
	HX_VISIT_MEMBER_NAME(prev,"prev");
	HX_VISIT_MEMBER_NAME(data,"data");
}

Dynamic SAPInterval_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return min; }
		if (HX_FIELD_EQ(inName,"max") ) { return max; }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		if (HX_FIELD_EQ(inName,"prev") ) { return prev; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Overlap") ) { return Overlap_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SAPInterval_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { min=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"max") ) { max=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::haxor::ds::SAPInterval >(); return inValue; }
		if (HX_FIELD_EQ(inName,"prev") ) { prev=inValue.Cast< ::haxor::ds::SAPInterval >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAPInterval_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("min"));
	outFields->push(HX_CSTRING("max"));
	outFields->push(HX_CSTRING("next"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(SAPInterval_obj,id),HX_CSTRING("id")},
	{hx::fsFloat,(int)offsetof(SAPInterval_obj,min),HX_CSTRING("min")},
	{hx::fsFloat,(int)offsetof(SAPInterval_obj,max),HX_CSTRING("max")},
	{hx::fsObject /*::haxor::ds::SAPInterval*/ ,(int)offsetof(SAPInterval_obj,next),HX_CSTRING("next")},
	{hx::fsObject /*::haxor::ds::SAPInterval*/ ,(int)offsetof(SAPInterval_obj,prev),HX_CSTRING("prev")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SAPInterval_obj,data),HX_CSTRING("data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("min"),
	HX_CSTRING("max"),
	HX_CSTRING("next"),
	HX_CSTRING("prev"),
	HX_CSTRING("data"),
	HX_CSTRING("Set"),
	HX_CSTRING("Overlap"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SAPInterval_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SAPInterval_obj::__mClass,"__mClass");
};

#endif

Class SAPInterval_obj::__mClass;

void SAPInterval_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.SAPInterval"), hx::TCanCast< SAPInterval_obj> ,sStaticFields,sMemberFields,
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

void SAPInterval_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
