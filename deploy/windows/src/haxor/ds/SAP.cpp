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

Void SAP_obj::__construct()
{
HX_STACK_FRAME("haxor.ds.SAP","new",0x1bdf50c1,"haxor.ds.SAP.new","haxor/ds/SAP.hx",54,0xbaeeb06f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(55)
	::haxor::ds::SAPList _g = ::haxor::ds::SAPList_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(55)
	this->x = _g;
	HX_STACK_LINE(56)
	::haxor::ds::SAPList _g1 = ::haxor::ds::SAPList_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(56)
	this->y = _g1;
	HX_STACK_LINE(57)
	::haxor::ds::SAPList _g2 = ::haxor::ds::SAPList_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(57)
	this->z = _g2;
	HX_STACK_LINE(58)
	this->inside = Array_obj< int >::__new();
	HX_STACK_LINE(59)
	this->outside = Array_obj< int >::__new();
	HX_STACK_LINE(60)
	this->countIn = (int)0;
	HX_STACK_LINE(61)
	this->countOut = (int)0;
}
;
	return null();
}

//SAP_obj::~SAP_obj() { }

Dynamic SAP_obj::__CreateEmpty() { return  new SAP_obj; }
hx::ObjectPtr< SAP_obj > SAP_obj::__new()
{  hx::ObjectPtr< SAP_obj > result = new SAP_obj();
	result->__construct();
	return result;}

Dynamic SAP_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAP_obj > result = new SAP_obj();
	result->__construct();
	return result;}

Void SAP_obj::Create( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAP","Create",0xf9660d5b,"haxor.ds.SAP.Create","haxor/ds/SAP.hx",69,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(70)
		this->x->Create(p_id);
		HX_STACK_LINE(71)
		this->y->Create(p_id);
		HX_STACK_LINE(72)
		this->z->Create(p_id);
		HX_STACK_LINE(73)
		while((true)){
			HX_STACK_LINE(73)
			if ((!(((this->inside->length <= p_id))))){
				HX_STACK_LINE(73)
				break;
			}
			HX_STACK_LINE(75)
			this->inside->push((int)-1);
			HX_STACK_LINE(76)
			this->outside->push((int)-1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Create,(void))

Void SAP_obj::Update( int p_id,Dynamic p_data,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
{
		HX_STACK_FRAME("haxor.ds.SAP","Update",0x045c2c68,"haxor.ds.SAP.Update","haxor/ds/SAP.hx",87,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(88)
		this->x->Update(p_id,p_data,p_min->x,p_max->x);
		HX_STACK_LINE(89)
		this->y->Update(p_id,p_data,p_min->y,p_max->y);
		HX_STACK_LINE(90)
		this->z->Update(p_id,p_data,p_min->z,p_max->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAP_obj,Update,(void))

Void SAP_obj::Remove( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAP","Remove",0x81df42a3,"haxor.ds.SAP.Remove","haxor/ds/SAP.hx",98,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			::haxor::ds::SAPList _this = this->x;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(99)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			::haxor::ds::SAPList _this = this->y;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(100)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
		HX_STACK_LINE(101)
		{
			HX_STACK_LINE(101)
			::haxor::ds::SAPList _this = this->z;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(101)
			_this->Remove(_this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAP_obj,Remove,(void))

bool SAP_obj::Overlap( int p_a,int p_b){
	HX_STACK_FRAME("haxor.ds.SAP","Overlap",0xd78b3048,"haxor.ds.SAP.Overlap","haxor/ds/SAP.hx",111,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(112)
	::haxor::ds::SAPInterval ax = this->x->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(ax,"ax");
	HX_STACK_LINE(113)
	::haxor::ds::SAPInterval bx = this->x->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(bx,"bx");
	HX_STACK_LINE(115)
	if ((!(ax->Overlap(bx)))){
		HX_STACK_LINE(115)
		return true;
	}
	HX_STACK_LINE(116)
	::haxor::ds::SAPInterval ay = this->y->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(ay,"ay");
	HX_STACK_LINE(117)
	::haxor::ds::SAPInterval by = this->y->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(by,"by");
	HX_STACK_LINE(118)
	if ((!(ay->Overlap(by)))){
		HX_STACK_LINE(118)
		return true;
	}
	HX_STACK_LINE(119)
	::haxor::ds::SAPInterval az = this->z->list->__get(p_a).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(az,"az");
	HX_STACK_LINE(120)
	::haxor::ds::SAPInterval bz = this->z->list->__get(p_b).StaticCast< ::haxor::ds::SAPInterval >();		HX_STACK_VAR(bz,"bz");
	HX_STACK_LINE(121)
	if ((!(az->Overlap(bz)))){
		HX_STACK_LINE(121)
		return true;
	}
	HX_STACK_LINE(122)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SAP_obj,Overlap,return )

Void SAP_obj::Query( int p_id,hx::Null< bool >  __o_p_outside){
bool p_outside = __o_p_outside.Default(false);
	HX_STACK_FRAME("haxor.ds.SAP","Query",0xa6cd1589,"haxor.ds.SAP.Query","haxor/ds/SAP.hx",130,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_ARG(p_outside,"p_outside")
{
		HX_STACK_LINE(131)
		this->countIn = (int)0;
		HX_STACK_LINE(132)
		this->countOut = (int)0;
		HX_STACK_LINE(135)
		::haxor::ds::SAPInterval tx;		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(136)
		::haxor::ds::SAPInterval ty;		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(137)
		::haxor::ds::SAPInterval tz;		HX_STACK_VAR(tz,"tz");
		HX_STACK_LINE(139)
		::haxor::ds::SAPInterval it;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(141)
		::haxor::ds::SAPInterval nx;		HX_STACK_VAR(nx,"nx");
		HX_STACK_LINE(142)
		::haxor::ds::SAPInterval ny;		HX_STACK_VAR(ny,"ny");
		HX_STACK_LINE(143)
		::haxor::ds::SAPInterval nz;		HX_STACK_VAR(nz,"nz");
		HX_STACK_LINE(147)
		tx = this->x->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(148)
		ty = this->y->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(149)
		tz = this->z->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >();
		HX_STACK_LINE(152)
		it = tx->next;
		HX_STACK_LINE(153)
		while((true)){
			HX_STACK_LINE(153)
			if ((!(((it != null()))))){
				HX_STACK_LINE(153)
				break;
			}
			HX_STACK_LINE(156)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(159)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(162)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(164)
						int _g = (this->countIn)++;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(164)
						this->inside[_g] = it->id;
					}
					else{
						HX_STACK_LINE(168)
						if ((p_outside)){
							HX_STACK_LINE(168)
							int _g1 = (this->countOut)++;		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(168)
							this->outside[_g1] = it->id;
						}
					}
				}
				else{
					HX_STACK_LINE(173)
					if ((p_outside)){
						HX_STACK_LINE(173)
						int _g2 = (this->countOut)++;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(173)
						this->outside[_g2] = it->id;
					}
				}
			}
			else{
				HX_STACK_LINE(178)
				if ((p_outside)){
					HX_STACK_LINE(178)
					int _g3 = (this->countOut)++;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(178)
					this->outside[_g3] = it->id;
				}
			}
			HX_STACK_LINE(180)
			it = it->next;
		}
		HX_STACK_LINE(184)
		it = tx->prev;
		HX_STACK_LINE(185)
		while((true)){
			HX_STACK_LINE(185)
			if ((!(((it != null()))))){
				HX_STACK_LINE(185)
				break;
			}
			HX_STACK_LINE(188)
			if ((it->Overlap(tx))){
				HX_STACK_LINE(191)
				if ((this->y->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(ty))){
					HX_STACK_LINE(194)
					if ((this->z->list->__get(it->id).StaticCast< ::haxor::ds::SAPInterval >()->Overlap(tz))){
						HX_STACK_LINE(196)
						int _g4 = (this->countIn)++;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(196)
						this->inside[_g4] = it->id;
					}
					else{
						HX_STACK_LINE(200)
						if ((p_outside)){
							HX_STACK_LINE(200)
							int _g5 = (this->countOut)++;		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(200)
							this->outside[_g5] = it->id;
						}
					}
				}
				else{
					HX_STACK_LINE(205)
					if ((p_outside)){
						HX_STACK_LINE(205)
						int _g6 = (this->countOut)++;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(205)
						this->outside[_g6] = it->id;
					}
				}
			}
			else{
				HX_STACK_LINE(210)
				if ((p_outside)){
					HX_STACK_LINE(210)
					int _g7 = (this->countOut)++;		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(210)
					this->outside[_g7] = it->id;
				}
			}
			HX_STACK_LINE(212)
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
