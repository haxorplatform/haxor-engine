#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_SAPInterval
#include <haxor/ds/SAPInterval.h>
#endif
#ifndef INCLUDED_haxor_ds_SAPList
#include <haxor/ds/SAPList.h>
#endif
namespace haxor{
namespace ds{

Void SAPList_obj::__construct(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query)
{
HX_STACK_FRAME("haxor.ds.SAPList","new",0x07a243bf,"haxor.ds.SAPList.new","haxor/ds/SAP.hx",204,0xbaeeb06f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_bias,"p_bias")
HX_STACK_ARG(__o_p_has_query,"p_has_query")
Float p_bias = __o_p_bias.Default(0.0);
bool p_has_query = __o_p_has_query.Default(true);
{
	HX_STACK_LINE(205)
	this->list = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(206)
	{
		HX_STACK_LINE(206)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(206)
		while((true)){
			HX_STACK_LINE(206)
			if ((!(((_g < (int)1000))))){
				HX_STACK_LINE(206)
				break;
			}
			HX_STACK_LINE(206)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(206)
			this->list->push(null());
		}
	}
	HX_STACK_LINE(207)
	this->m_has_query = p_has_query;
	HX_STACK_LINE(208)
	this->m_bias = p_bias;
}
;
	return null();
}

//SAPList_obj::~SAPList_obj() { }

Dynamic SAPList_obj::__CreateEmpty() { return  new SAPList_obj; }
hx::ObjectPtr< SAPList_obj > SAPList_obj::__new(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query)
{  hx::ObjectPtr< SAPList_obj > result = new SAPList_obj();
	result->__construct(__o_p_bias,__o_p_has_query);
	return result;}

Dynamic SAPList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAPList_obj > result = new SAPList_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void SAPList_obj::Create( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Create",0xf06a8d1d,"haxor.ds.SAPList.Create","haxor/ds/SAP.hx",216,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(217)
		while((true)){
			HX_STACK_LINE(217)
			if ((!(((this->list->length <= p_id))))){
				HX_STACK_LINE(217)
				break;
			}
			HX_STACK_LINE(217)
			this->list->push(null());
		}
		HX_STACK_LINE(218)
		if (((this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >() == null()))){
			HX_STACK_LINE(218)
			this->list[p_id] = ::haxor::ds::SAPInterval_obj::__new();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Create,(void))

Void SAPList_obj::Update( int p_id,Dynamic p_data,Float p_min,Float p_max){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Update",0xfb60ac2a,"haxor.ds.SAPList.Update","haxor/ds/SAP.hx",228,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(229)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->id = p_id;
		HX_STACK_LINE(230)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->data = p_data;
		HX_STACK_LINE(231)
		Float d = ((((p_max - p_min)) * this->m_bias) * 0.5);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(232)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->Set((p_min - d),(p_max + d));
		HX_STACK_LINE(233)
		if ((this->m_has_query)){
			HX_STACK_LINE(233)
			this->RelocateInterval(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAPList_obj,Update,(void))

Void SAPList_obj::AddInterval( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","AddInterval",0xfd1ab2c5,"haxor.ds.SAPList.AddInterval","haxor/ds/SAP.hx",241,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(242)
		if (((this->start == null()))){
			HX_STACK_LINE(242)
			this->start = p_item;
			HX_STACK_LINE(242)
			::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(242)
			p_item->next = _g;
			HX_STACK_LINE(242)
			return null();
		}
		HX_STACK_LINE(243)
		if (((p_item == this->start))){
			HX_STACK_LINE(243)
			return null();
		}
		HX_STACK_LINE(244)
		::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(245)
		while((true)){
			HX_STACK_LINE(245)
			if ((!(((it != null()))))){
				HX_STACK_LINE(245)
				break;
			}
			HX_STACK_LINE(247)
			if (((p_item->min < it->min))){
				HX_STACK_LINE(247)
				this->InsertInterval(p_item,it);
				HX_STACK_LINE(247)
				return null();
			}
			HX_STACK_LINE(248)
			if (((it->next == null()))){
				HX_STACK_LINE(248)
				this->InsertInterval(p_item,it);
				HX_STACK_LINE(248)
				return null();
			}
			HX_STACK_LINE(249)
			it = it->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,AddInterval,(void))

Void SAPList_obj::InsertInterval( ::haxor::ds::SAPInterval p_item,::haxor::ds::SAPInterval p_at){
{
		HX_STACK_FRAME("haxor.ds.SAPList","InsertInterval",0x395688bf,"haxor.ds.SAPList.InsertInterval","haxor/ds/SAP.hx",259,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_ARG(p_at,"p_at")
		HX_STACK_LINE(260)
		if (((p_item == p_at))){
			HX_STACK_LINE(260)
			return null();
		}
		HX_STACK_LINE(263)
		if (((p_item->min > p_at->min))){
			HX_STACK_LINE(265)
			p_item->next = p_at->next;
			HX_STACK_LINE(266)
			p_item->prev = p_at;
			HX_STACK_LINE(267)
			p_at->next = p_item;
			HX_STACK_LINE(268)
			if (((p_item->next != null()))){
				HX_STACK_LINE(268)
				p_item->next->prev = p_item;
			}
		}
		else{
			HX_STACK_LINE(272)
			p_item->next = p_at;
			HX_STACK_LINE(273)
			p_item->prev = p_at->prev;
			HX_STACK_LINE(274)
			p_at->prev = p_item;
			HX_STACK_LINE(275)
			if (((p_item->prev != null()))){
				HX_STACK_LINE(275)
				p_item->prev->next = p_item;
			}
			HX_STACK_LINE(277)
			if (((p_at == this->start))){
				HX_STACK_LINE(277)
				this->start = p_item;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAPList_obj,InsertInterval,(void))

Void SAPList_obj::RelocateInterval( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","RelocateInterval",0xad79634b,"haxor.ds.SAPList.RelocateInterval","haxor/ds/SAP.hx",287,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(289)
		if (((p_item->prev == null()))){
			HX_STACK_LINE(290)
			if (((p_item->next == null()))){
				HX_STACK_LINE(292)
				this->AddInterval(p_item);
				HX_STACK_LINE(293)
				return null();
			}
		}
		HX_STACK_LINE(296)
		::haxor::ds::SAPInterval it = p_item;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(297)
		int nav = (int)0;		HX_STACK_VAR(nav,"nav");
		HX_STACK_LINE(298)
		::haxor::ds::SAPInterval location = null();		HX_STACK_VAR(location,"location");
		HX_STACK_LINE(301)
		while((true)){
			HX_STACK_LINE(301)
			if ((!(((it != null()))))){
				HX_STACK_LINE(301)
				break;
			}
			HX_STACK_LINE(303)
			::haxor::ds::SAPInterval n = it->next;		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(304)
			::haxor::ds::SAPInterval p = it->prev;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(305)
			if (((n == null()))){
				HX_STACK_LINE(305)
				if (((p == null()))){
					HX_STACK_LINE(305)
					break;
				}
			}
			HX_STACK_LINE(306)
			if (((p != null()))){
				HX_STACK_LINE(306)
				if (((p_item->min < p->min))){
					HX_STACK_LINE(306)
					nav = (int)-1;
					HX_STACK_LINE(306)
					location = p;
				}
			}
			HX_STACK_LINE(307)
			if (((n != null()))){
				HX_STACK_LINE(307)
				if (((p_item->min > n->min))){
					HX_STACK_LINE(307)
					nav = (int)1;
					HX_STACK_LINE(307)
					location = n;
				}
			}
			HX_STACK_LINE(308)
			if (((nav == (int)0))){
				HX_STACK_LINE(308)
				break;
			}
			HX_STACK_LINE(309)
			if (((nav < (int)0))){
				HX_STACK_LINE(309)
				it = p;
			}
			else{
				HX_STACK_LINE(309)
				it = n;
			}
			HX_STACK_LINE(310)
			nav = (int)0;
		}
		HX_STACK_LINE(313)
		if (((location != null()))){
			HX_STACK_LINE(316)
			this->RemoveInterval(p_item);
			HX_STACK_LINE(318)
			this->InsertInterval(p_item,location);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,RelocateInterval,(void))

Void SAPList_obj::Remove( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Remove",0x78e3c265,"haxor.ds.SAPList.Remove","haxor/ds/SAP.hx",328,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(328)
		this->RemoveInterval(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Remove,(void))

Void SAPList_obj::RemoveInterval( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","RemoveInterval",0xc0e264ca,"haxor.ds.SAPList.RemoveInterval","haxor/ds/SAP.hx",336,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(337)
		if ((!(this->m_has_query))){
			HX_STACK_LINE(337)
			return null();
		}
		HX_STACK_LINE(338)
		::haxor::ds::SAPInterval p = p_item->prev;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(339)
		::haxor::ds::SAPInterval n = p_item->next;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(340)
		if (((p != null()))){
			HX_STACK_LINE(340)
			p->next = n;
		}
		HX_STACK_LINE(341)
		if (((n != null()))){
			HX_STACK_LINE(341)
			n->prev = p;
		}
		HX_STACK_LINE(342)
		::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(342)
		p_item->next = _g;
		HX_STACK_LINE(344)
		if (((p_item == this->start))){
			HX_STACK_LINE(344)
			this->start = n;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,RemoveInterval,(void))

Void SAPList_obj::Iterate( Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Iterate",0x3e36b0b9,"haxor.ds.SAPList.Iterate","haxor/ds/SAP.hx",352,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(353)
		::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(354)
		while((true)){
			HX_STACK_LINE(354)
			if ((!(((it != null()))))){
				HX_STACK_LINE(354)
				break;
			}
			HX_STACK_LINE(356)
			p_callback(it).Cast< Void >();
			HX_STACK_LINE(357)
			it = it->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Iterate,(void))

::String SAPList_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.ds.SAPList","ToString",0xd678810d,"haxor.ds.SAPList.ToString","haxor/ds/SAP.hx",367,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(368)
		::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(369)
		if ((this->m_has_query)){
			HX_STACK_LINE(371)
			::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
			HX_STACK_LINE(372)
			while((true)){
				HX_STACK_LINE(372)
				if ((!(((it != null()))))){
					HX_STACK_LINE(372)
					break;
				}
				HX_STACK_LINE(374)
				::String _g = it->ToString(p_places);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(374)
				hx::AddEq(s,_g);
				HX_STACK_LINE(375)
				it = it->next;
			}
		}
		else{
			HX_STACK_LINE(380)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(380)
			int _g = this->list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(380)
			while((true)){
				HX_STACK_LINE(380)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(380)
					break;
				}
				HX_STACK_LINE(380)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(380)
				::String _g11 = this->list->__get(i).StaticCast< ::haxor::ds::SAPInterval >()->ToString(p_places);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(380)
				hx::AddEq(s,_g11);
			}
		}
		HX_STACK_LINE(382)
		return s;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,ToString,return )


SAPList_obj::SAPList_obj()
{
}

void SAPList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SAPList);
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(m_has_query,"m_has_query");
	HX_MARK_MEMBER_NAME(m_bias,"m_bias");
	HX_MARK_END_CLASS();
}

void SAPList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(m_has_query,"m_has_query");
	HX_VISIT_MEMBER_NAME(m_bias,"m_bias");
}

Dynamic SAPList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bias") ) { return m_bias; }
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Iterate") ) { return Iterate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { return m_has_query; }
		if (HX_FIELD_EQ(inName,"AddInterval") ) { return AddInterval_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"InsertInterval") ) { return InsertInterval_dyn(); }
		if (HX_FIELD_EQ(inName,"RemoveInterval") ) { return RemoveInterval_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"RelocateInterval") ) { return RelocateInterval_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SAPList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< ::haxor::ds::SAPInterval >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bias") ) { m_bias=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { m_has_query=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAPList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("list"));
	outFields->push(HX_CSTRING("m_has_query"));
	outFields->push(HX_CSTRING("m_bias"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::ds::SAPInterval*/ ,(int)offsetof(SAPList_obj,start),HX_CSTRING("start")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SAPList_obj,list),HX_CSTRING("list")},
	{hx::fsBool,(int)offsetof(SAPList_obj,m_has_query),HX_CSTRING("m_has_query")},
	{hx::fsFloat,(int)offsetof(SAPList_obj,m_bias),HX_CSTRING("m_bias")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("start"),
	HX_CSTRING("list"),
	HX_CSTRING("m_has_query"),
	HX_CSTRING("m_bias"),
	HX_CSTRING("Create"),
	HX_CSTRING("Update"),
	HX_CSTRING("AddInterval"),
	HX_CSTRING("InsertInterval"),
	HX_CSTRING("RelocateInterval"),
	HX_CSTRING("Remove"),
	HX_CSTRING("RemoveInterval"),
	HX_CSTRING("Iterate"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SAPList_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SAPList_obj::__mClass,"__mClass");
};

#endif

Class SAPList_obj::__mClass;

void SAPList_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.SAPList"), hx::TCanCast< SAPList_obj> ,sStaticFields,sMemberFields,
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

void SAPList_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
