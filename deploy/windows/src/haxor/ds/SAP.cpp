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
HX_STACK_FRAME("haxor.ds.SAP","new",0x1bdf50c1,"haxor.ds.SAP.new","haxor/ds/SAP.hx",61,0xbaeeb06f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_bias,"p_bias")
HX_STACK_ARG(__o_p_has_query,"p_has_query")
Float p_bias = __o_p_bias.Default(0.0);
bool p_has_query = __o_p_has_query.Default(true);
{
	HX_STACK_LINE(62)
	this->m_has_query = p_has_query;
	HX_STACK_LINE(63)
	::haxor::ds::SAPList _g = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(63)
	this->x = _g;
	HX_STACK_LINE(64)
	::haxor::ds::SAPList _g1 = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(64)
	this->y = _g1;
	HX_STACK_LINE(65)
	::haxor::ds::SAPList _g2 = ::haxor::ds::SAPList_obj::__new(p_bias,this->m_has_query);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(65)
	this->z = _g2;
	HX_STACK_LINE(66)
	this->inside = Array_obj< int >::__new();
	HX_STACK_LINE(67)
	this->outside = Array_obj< int >::__new();
	HX_STACK_LINE(68)
	this->countIn = (int)0;
	HX_STACK_LINE(69)
	this->countOut = (int)0;
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
		HX_STACK_FRAME("haxor.ds.SAP","Create",0xf9660d5b,"haxor.ds.SAP.Create","haxor/ds/SAP.hx",77,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(78)
		this->x->Create(p_id);
		HX_STACK_LINE(79)
		this->y->Create(p_id);
		HX_STACK_LINE(80)
		this->z->Create(p_id);
		HX_STACK_LINE(81)
		while((true)){
			HX_STACK_LINE(81)
			if ((!(((this->inside->length <= p_id))))){
				HX_STACK_LINE(81)
				break;
			}
			HX_STACK_LINE(83)
			this->inside->push((int)-1);
			HX_STACK_LINE(84)
			this->outside->push((int)-1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Create,(void))

Void SAP_obj::Update( int p_id,Dynamic p_data,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
{
		HX_STACK_FRAME("haxor.ds.SAP","Update",0x045c2c68,"haxor.ds.SAP.Update","haxor/ds/SAP.hx",95,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(96)
		this->x->Update(p_id,p_data,p_min->x,p_max->x);
		HX_STACK_LINE(97)
		this->y->Update(p_id,p_data,p_min->y,p_max->y);
		HX_STACK_LINE(98)
		this->z->Update(p_id,p_data,p_min->z,p_max->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAP_obj,Update,(void))

Void SAP_obj::Remove( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAP","Remove",0x81df42a3,"haxor.ds.SAP.Remove","haxor/ds/SAP.hx",106,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(107)
		{
			HX_STACK_LINE(107)
			::haxor::ds::SAPList _this = this->x;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(107)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(108)
		{
			HX_STACK_LINE(108)
			::haxor::ds::SAPList _this = this->y;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(108)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			::haxor::ds::SAPList _this = this->z;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(109)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Remove,(void))

bool SAP_obj::Overlap( int p_a,int p_b){
	HX_STACK_FRAME("haxor.ds.SAP","Overlap",0xd78b3048,"haxor.ds.SAP.Overlap","haxor/ds/SAP.hx",119,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(120)
	::haxor::ds::SAPInterval ax = this->x->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(ax,"ax");
	HX_STACK_LINE(121)
	::haxor::ds::SAPInterval bx = this->x->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(bx,"bx");
	HX_STACK_LINE(123)
	if ((!(ax->Overlap(bx)))){
		HX_STACK_LINE(123)
		return true;
	}
	HX_STACK_LINE(124)
	::haxor::ds::SAPInterval ay = this->y->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(ay,"ay");
	HX_STACK_LINE(125)
	::haxor::ds::SAPInterval by = this->y->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(by,"by");
	HX_STACK_LINE(126)
	if ((!(ay->Overlap(by)))){
		HX_STACK_LINE(126)
		return true;
	}
	HX_STACK_LINE(127)
	::haxor::ds::SAPInterval az = this->z->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(az,"az");
	HX_STACK_LINE(128)
	::haxor::ds::SAPInterval bz = this->z->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(bz,"bz");
	HX_STACK_LINE(129)
	if ((!(az->Overlap(bz)))){
		HX_STACK_LINE(129)
		return true;
	}
	HX_STACK_LINE(130)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SAP_obj,Overlap,return )

Void SAP_obj::Query( int p_id,hx::Null< bool >  __o_p_outside){
bool p_outside = __o_p_outside.Default(false);
	HX_STACK_FRAME("haxor.ds.SAP","Query",0xa6cd1589,"haxor.ds.SAP.Query","haxor/ds/SAP.hx",138,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_ARG(p_outside,"p_outside")
{
		HX_STACK_LINE(139)
		if ((!(this->m_has_query))){
			HX_STACK_LINE(139)
			return null();
		}
		HX_STACK_LINE(140)
		this->countIn = (int)0;
		HX_STACK_LINE(141)
		this->countOut = (int)0;
		HX_STACK_LINE(144)
		::haxor::ds::SAPInterval tx;		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(145)
		::haxor::ds::SAPInterval ty;		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(146)
		::haxor::ds::SAPInterval tz;		HX_STACK_VAR(tz,"tz");
		HX_STACK_LINE(148)
		::haxor::ds::SAPInterval it;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(150)
		::haxor::ds::SAPInterval nx;		HX_STACK_VAR(nx,"nx");
		HX_STACK_LINE(151)
		::haxor::ds::SAPInterval ny;		HX_STACK_VAR(ny,"ny");
		HX_STACK_LINE(152)
		::haxor::ds::SAPInterval nz;		HX_STACK_VAR(nz,"nz");
		HX_STACK_LINE(156)
		tx = this->x->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(157)
		ty = this->y->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(158)
		tz = this->z->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(161)
		it = tx->next;
		HX_STACK_LINE(162)
		while((true)){
			HX_STACK_LINE(162)
			if ((!(((it != null()))))){
				HX_STACK_LINE(162)
				break;
			}
			HX_STACK_LINE(165)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(168)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(171)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(173)
						int _g = (this->countIn)++;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(173)
						this->inside[_g] = it->id;
					}
					else{
						HX_STACK_LINE(177)
						if ((p_outside)){
							HX_STACK_LINE(177)
							int _g1 = (this->countOut)++;		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(177)
							this->outside[_g1] = it->id;
						}
					}
				}
				else{
					HX_STACK_LINE(182)
					if ((p_outside)){
						HX_STACK_LINE(182)
						int _g2 = (this->countOut)++;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(182)
						this->outside[_g2] = it->id;
					}
				}
			}
			else{
				HX_STACK_LINE(187)
				if ((p_outside)){
					HX_STACK_LINE(187)
					int _g3 = (this->countOut)++;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(187)
					this->outside[_g3] = it->id;
				}
			}
			HX_STACK_LINE(189)
			it = it->next;
		}
		HX_STACK_LINE(193)
		it = tx->prev;
		HX_STACK_LINE(194)
		while((true)){
			HX_STACK_LINE(194)
			if ((!(((it != null()))))){
				HX_STACK_LINE(194)
				break;
			}
			HX_STACK_LINE(197)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(200)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(203)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(205)
						int _g4 = (this->countIn)++;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(205)
						this->inside[_g4] = it->id;
					}
					else{
						HX_STACK_LINE(209)
						if ((p_outside)){
							HX_STACK_LINE(209)
							int _g5 = (this->countOut)++;		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(209)
							this->outside[_g5] = it->id;
						}
					}
				}
				else{
					HX_STACK_LINE(214)
					if ((p_outside)){
						HX_STACK_LINE(214)
						int _g6 = (this->countOut)++;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(214)
						this->outside[_g6] = it->id;
					}
				}
			}
			else{
				HX_STACK_LINE(219)
				if ((p_outside)){
					HX_STACK_LINE(219)
					int _g7 = (this->countOut)++;		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(219)
					this->outside[_g7] = it->id;
				}
			}
			HX_STACK_LINE(221)
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
	HX_MARK_MEMBER_NAME(inside,"inside");
	HX_MARK_MEMBER_NAME(outside,"outside");
	HX_MARK_MEMBER_NAME(countIn,"countIn");
	HX_MARK_MEMBER_NAME(countOut,"countOut");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(m_has_query,"m_has_query");
	HX_MARK_END_CLASS();
}

void SAP_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inside,"inside");
	HX_VISIT_MEMBER_NAME(outside,"outside");
	HX_VISIT_MEMBER_NAME(countIn,"countIn");
	HX_VISIT_MEMBER_NAME(countOut,"countOut");
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
		if (HX_FIELD_EQ(inName,"inside") ) { return inside; }
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"outside") ) { return outside; }
		if (HX_FIELD_EQ(inName,"countIn") ) { return countIn; }
		if (HX_FIELD_EQ(inName,"Overlap") ) { return Overlap_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"countOut") ) { return countOut; }
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
	case 6:
		if (HX_FIELD_EQ(inName,"inside") ) { inside=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"outside") ) { outside=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"countIn") ) { countIn=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"countOut") ) { countOut=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { m_has_query=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAP_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("inside"));
	outFields->push(HX_CSTRING("outside"));
	outFields->push(HX_CSTRING("countIn"));
	outFields->push(HX_CSTRING("countOut"));
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
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SAP_obj,inside),HX_CSTRING("inside")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SAP_obj,outside),HX_CSTRING("outside")},
	{hx::fsInt,(int)offsetof(SAP_obj,countIn),HX_CSTRING("countIn")},
	{hx::fsInt,(int)offsetof(SAP_obj,countOut),HX_CSTRING("countOut")},
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,x),HX_CSTRING("x")},
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,y),HX_CSTRING("y")},
	{hx::fsObject /*::haxor::ds::SAPList*/ ,(int)offsetof(SAP_obj,z),HX_CSTRING("z")},
	{hx::fsBool,(int)offsetof(SAP_obj,m_has_query),HX_CSTRING("m_has_query")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("inside"),
	HX_CSTRING("outside"),
	HX_CSTRING("countIn"),
	HX_CSTRING("countOut"),
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
