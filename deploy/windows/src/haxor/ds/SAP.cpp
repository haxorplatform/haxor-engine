#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_SAP
#include <haxor/ds/SAP.h>
#endif
#ifndef INCLUDED_haxor_ds_SAPInterval
#include <haxor/ds/SAPInterval.h>
#endif
#ifndef INCLUDED_haxor_ds_SAPList
#include <haxor/ds/SAPList.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
namespace haxor{
namespace ds{

Void SAP_obj::__construct(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query)
{
HX_STACK_FRAME("haxor.ds.SAP","new",0x1bdf50c1,"haxor.ds.SAP.new","haxor/ds/SAP.hx",41,0xbaeeb06f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_bias,"p_bias")
HX_STACK_ARG(__o_p_has_query,"p_has_query")
Float p_bias = __o_p_bias.Default(0.0);
bool p_has_query = __o_p_has_query.Default(true);
{
	HX_STACK_LINE(42)
	this->m_has_query = p_has_query;
	HX_STACK_LINE(43)
	::haxor::ds::SAPList _g = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	this->x = _g;
	HX_STACK_LINE(44)
	::haxor::ds::SAPList _g1 = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(44)
	this->y = _g1;
	HX_STACK_LINE(45)
	::haxor::ds::SAPList _g2 = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(45)
	this->z = _g2;
}
;
	return null();
}

//SAP_obj::~SAP_obj() { }

Dynamic SAP_obj::__CreateEmpty() { return  new SAP_obj; }
hx::ObjectPtr< SAP_obj > SAP_obj::__new(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query)
{  hx::ObjectPtr< SAP_obj > result = new SAP_obj();
	result->__construct(__o_p_bias,__o_p_has_query);
	return result;}

Dynamic SAP_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAP_obj > result = new SAP_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void SAP_obj::Create( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAP","Create",0xf9660d5b,"haxor.ds.SAP.Create","haxor/ds/SAP.hx",53,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(54)
		this->x->Create(p_id);
		HX_STACK_LINE(55)
		this->y->Create(p_id);
		HX_STACK_LINE(56)
		this->z->Create(p_id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Create,(void))

Void SAP_obj::Update( int p_id,Dynamic p_data,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
{
		HX_STACK_FRAME("haxor.ds.SAP","Update",0x045c2c68,"haxor.ds.SAP.Update","haxor/ds/SAP.hx",66,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(67)
		this->x->Update(p_id,p_data,p_min->x,p_max->x);
		HX_STACK_LINE(68)
		this->y->Update(p_id,p_data,p_min->y,p_max->y);
		HX_STACK_LINE(69)
		this->z->Update(p_id,p_data,p_min->z,p_max->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAP_obj,Update,(void))

Void SAP_obj::Remove( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAP","Remove",0x81df42a3,"haxor.ds.SAP.Remove","haxor/ds/SAP.hx",77,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			::haxor::ds::SAPList _this = this->x;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(78)
			_this->RemoveInterval(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			::haxor::ds::SAPList _this = this->y;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(79)
			_this->RemoveInterval(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(80)
		{
			HX_STACK_LINE(80)
			::haxor::ds::SAPList _this = this->z;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(80)
			_this->RemoveInterval(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Remove,(void))

bool SAP_obj::Overlap( int p_a,int p_b){
	HX_STACK_FRAME("haxor.ds.SAP","Overlap",0xd78b3048,"haxor.ds.SAP.Overlap","haxor/ds/SAP.hx",90,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(91)
	::haxor::ds::SAPInterval ia;		HX_STACK_VAR(ia,"ia");
	HX_STACK_LINE(92)
	::haxor::ds::SAPInterval ib;		HX_STACK_VAR(ib,"ib");
	HX_STACK_LINE(94)
	ia = this->x->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(95)
	ib = this->x->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(96)
	if ((!(ia->Overlap(ib)))){
		HX_STACK_LINE(96)
		return false;
	}
	HX_STACK_LINE(98)
	ia = this->y->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(99)
	ib = this->y->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(100)
	if ((!(ia->Overlap(ib)))){
		HX_STACK_LINE(100)
		return false;
	}
	HX_STACK_LINE(102)
	ia = this->z->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(103)
	ib = this->z->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();
	HX_STACK_LINE(104)
	if ((!(ia->Overlap(ib)))){
		HX_STACK_LINE(104)
		return false;
	}
	HX_STACK_LINE(105)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(SAP_obj,Overlap,return )

Void SAP_obj::Query( int p_id,Dynamic p_on_fetch){
{
		HX_STACK_FRAME("haxor.ds.SAP","Query",0xa6cd1589,"haxor.ds.SAP.Query","haxor/ds/SAP.hx",113,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_on_fetch,"p_on_fetch")
		HX_STACK_LINE(114)
		if ((!(this->m_has_query))){
			HX_STACK_LINE(114)
			return null();
		}
		HX_STACK_LINE(117)
		::haxor::ds::SAPInterval tx;		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(118)
		::haxor::ds::SAPInterval ty;		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(119)
		::haxor::ds::SAPInterval tz;		HX_STACK_VAR(tz,"tz");
		HX_STACK_LINE(121)
		::haxor::ds::SAPInterval it;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(123)
		::haxor::ds::SAPInterval nx;		HX_STACK_VAR(nx,"nx");
		HX_STACK_LINE(124)
		::haxor::ds::SAPInterval ny;		HX_STACK_VAR(ny,"ny");
		HX_STACK_LINE(125)
		::haxor::ds::SAPInterval nz;		HX_STACK_VAR(nz,"nz");
		HX_STACK_LINE(129)
		tx = this->x->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(130)
		ty = this->y->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(131)
		tz = this->z->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(134)
		it = tx->next;
		HX_STACK_LINE(135)
		while((true)){
			HX_STACK_LINE(135)
			if ((!(((it != null()))))){
				HX_STACK_LINE(135)
				break;
			}
			HX_STACK_LINE(138)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(141)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(144)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(146)
						if (((p_on_fetch != null()))){
							HX_STACK_LINE(146)
							p_on_fetch(tx->data,it->data).Cast< Void >();
						}
					}
				}
			}
			HX_STACK_LINE(150)
			it = it->next;
		}
		HX_STACK_LINE(154)
		it = tx->prev;
		HX_STACK_LINE(155)
		while((true)){
			HX_STACK_LINE(155)
			if ((!(((it != null()))))){
				HX_STACK_LINE(155)
				break;
			}
			HX_STACK_LINE(158)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(161)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(164)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(166)
						if (((p_on_fetch != null()))){
							HX_STACK_LINE(166)
							p_on_fetch(tx->data,it->data).Cast< Void >();
						}
					}
				}
			}
			HX_STACK_LINE(170)
			it = it->prev;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAP_obj,Query,(void))


SAP_obj::SAP_obj()
{
}

void SAP_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SAP);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(m_has_query,"m_has_query");
	HX_MARK_END_CLASS();
}

void SAP_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(m_has_query,"m_has_query");
}

Dynamic SAP_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Query") ) { return Query_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Overlap") ) { return Overlap_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { return m_has_query; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SAP_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< ::haxor::ds::SAPList >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< ::haxor::ds::SAPList >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< ::haxor::ds::SAPList >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { m_has_query=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAP_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("m_has_query"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,x),HX_CSTRING("x")},
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,y),HX_CSTRING("y")},
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,z),HX_CSTRING("z")},
	{hx::fsBool,(int)offsetof(SAP_obj,m_has_query),HX_CSTRING("m_has_query")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	HX_CSTRING("m_has_query"),
	HX_CSTRING("Create"),
	HX_CSTRING("Update"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Overlap"),
	HX_CSTRING("Query"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SAP_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SAP_obj::__mClass,"__mClass");
};

#endif

Class SAP_obj::__mClass;

void SAP_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.SAP"), hx::TCanCast< SAP_obj> ,sStaticFields,sMemberFields,
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

void SAP_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
