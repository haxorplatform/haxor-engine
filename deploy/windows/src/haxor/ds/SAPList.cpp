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
HX_STACK_FRAME("haxor.ds.SAPList","new",0x07a243bf,"haxor.ds.SAPList.new","haxor/ds/SAP.hx",255,0xbaeeb06f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_bias,"p_bias")
HX_STACK_ARG(__o_p_has_query,"p_has_query")
Float p_bias = __o_p_bias.Default(0.0);
bool p_has_query = __o_p_has_query.Default(true);
{
	HX_STACK_LINE(256)
	this->list = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(257)
	{
		HX_STACK_LINE(257)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(257)
		while((true)){
			HX_STACK_LINE(257)
			if ((!(((_g < (int)5000))))){
				HX_STACK_LINE(257)
				break;
			}
			HX_STACK_LINE(257)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(257)
			this->list->push(null());
		}
	}
	HX_STACK_LINE(258)
	this->m_has_query = p_has_query;
	HX_STACK_LINE(259)
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
		HX_STACK_FRAME("haxor.ds.SAPList","Create",0xf06a8d1d,"haxor.ds.SAPList.Create","haxor/ds/SAP.hx",267,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(268)
		while((true)){
			HX_STACK_LINE(268)
			if ((!(((this->list->length <= p_id))))){
				HX_STACK_LINE(268)
				break;
			}
			HX_STACK_LINE(268)
			this->list->push(null());
		}
		HX_STACK_LINE(269)
		if (((this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >() == null()))){
			HX_STACK_LINE(269)
			this->list[p_id] = ::haxor::ds::SAPInterval_obj::__new();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Create,(void))

Void SAPList_obj::Update( int p_id,Dynamic p_data,Float p_min,Float p_max){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Update",0xfb60ac2a,"haxor.ds.SAPList.Update","haxor/ds/SAP.hx",279,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(280)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->id = p_id;
		HX_STACK_LINE(281)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->data = p_data;
		HX_STACK_LINE(282)
		Float d = ((((p_max - p_min)) * this->m_bias) * 0.5);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(283)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->Set((p_min - d),(p_max + d));
		HX_STACK_LINE(284)
		if ((this->m_has_query)){
			HX_STACK_LINE(284)
			this->Relocate(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAPList_obj,Update,(void))

Void SAPList_obj::Add( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Add",0x07801d60,"haxor.ds.SAPList.Add","haxor/ds/SAP.hx",292,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(293)
		if (((this->start == null()))){
			HX_STACK_LINE(293)
			this->start = p_item;
			HX_STACK_LINE(293)
			::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(293)
			p_item->next = _g;
			HX_STACK_LINE(293)
			return null();
		}
		HX_STACK_LINE(294)
		if (((p_item == this->start))){
			HX_STACK_LINE(294)
			return null();
		}
		HX_STACK_LINE(295)
		::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(296)
		while((true)){
			HX_STACK_LINE(296)
			if ((!(((it != null()))))){
				HX_STACK_LINE(296)
				break;
			}
			HX_STACK_LINE(298)
			if (((p_item->min < it->min))){
				HX_STACK_LINE(298)
				this->Insert(p_item,it);
				HX_STACK_LINE(298)
				return null();
			}
			HX_STACK_LINE(299)
			if (((it->next == null()))){
				HX_STACK_LINE(299)
				this->Insert(p_item,it);
				HX_STACK_LINE(299)
				return null();
			}
			HX_STACK_LINE(300)
			it = it->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Add,(void))

Void SAPList_obj::Insert( ::haxor::ds::SAPInterval p_item,::haxor::ds::SAPInterval p_at){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Insert",0x1238695a,"haxor.ds.SAPList.Insert","haxor/ds/SAP.hx",310,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_ARG(p_at,"p_at")
		HX_STACK_LINE(311)
		if (((p_item == p_at))){
			HX_STACK_LINE(311)
			return null();
		}
		HX_STACK_LINE(314)
		if (((p_item->min > p_at->min))){
			HX_STACK_LINE(316)
			p_item->next = p_at->next;
			HX_STACK_LINE(317)
			p_item->prev = p_at;
			HX_STACK_LINE(318)
			p_at->next = p_item;
			HX_STACK_LINE(319)
			if (((p_item->next != null()))){
				HX_STACK_LINE(319)
				p_item->next->prev = p_item;
			}
		}
		else{
			HX_STACK_LINE(323)
			p_item->next = p_at;
			HX_STACK_LINE(324)
			p_item->prev = p_at->prev;
			HX_STACK_LINE(325)
			p_at->prev = p_item;
			HX_STACK_LINE(326)
			if (((p_item->prev != null()))){
				HX_STACK_LINE(326)
				p_item->prev->next = p_item;
			}
			HX_STACK_LINE(328)
			if (((p_at == this->start))){
				HX_STACK_LINE(328)
				this->start = p_item;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAPList_obj,Insert,(void))

Void SAPList_obj::Relocate( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Relocate",0xd837d7e6,"haxor.ds.SAPList.Relocate","haxor/ds/SAP.hx",338,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(340)
		if (((p_item->prev == null()))){
			HX_STACK_LINE(341)
			if (((p_item->next == null()))){
				HX_STACK_LINE(343)
				this->Add(p_item);
				HX_STACK_LINE(344)
				return null();
			}
		}
		HX_STACK_LINE(347)
		::haxor::ds::SAPInterval it = p_item;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(348)
		int nav = (int)0;		HX_STACK_VAR(nav,"nav");
		HX_STACK_LINE(349)
		::haxor::ds::SAPInterval location = null();		HX_STACK_VAR(location,"location");
		HX_STACK_LINE(352)
		while((true)){
			HX_STACK_LINE(352)
			if ((!(((it != null()))))){
				HX_STACK_LINE(352)
				break;
			}
			HX_STACK_LINE(354)
			::haxor::ds::SAPInterval n = it->next;		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(355)
			::haxor::ds::SAPInterval p = it->prev;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(356)
			if (((n == null()))){
				HX_STACK_LINE(356)
				if (((p == null()))){
					HX_STACK_LINE(356)
					break;
				}
			}
			HX_STACK_LINE(357)
			if (((p != null()))){
				HX_STACK_LINE(357)
				if (((p_item->min < p->min))){
					HX_STACK_LINE(357)
					nav = (int)-1;
					HX_STACK_LINE(357)
					location = p;
				}
			}
			HX_STACK_LINE(358)
			if (((n != null()))){
				HX_STACK_LINE(358)
				if (((p_item->min > n->min))){
					HX_STACK_LINE(358)
					nav = (int)1;
					HX_STACK_LINE(358)
					location = n;
				}
			}
			HX_STACK_LINE(359)
			if (((nav == (int)0))){
				HX_STACK_LINE(359)
				break;
			}
			HX_STACK_LINE(360)
			if (((nav < (int)0))){
				HX_STACK_LINE(360)
				it = p;
			}
			else{
				HX_STACK_LINE(360)
				it = n;
			}
			HX_STACK_LINE(361)
			nav = (int)0;
		}
		HX_STACK_LINE(364)
		if (((location != null()))){
			HX_STACK_LINE(367)
			this->Remove(p_item);
			HX_STACK_LINE(369)
			this->Insert(p_item,location);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Relocate,(void))

Void SAPList_obj::RemoveById( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAPList","RemoveById",0x36617e97,"haxor.ds.SAPList.RemoveById","haxor/ds/SAP.hx",379,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(379)
		this->Remove(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,RemoveById,(void))

Void SAPList_obj::Remove( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Remove",0x78e3c265,"haxor.ds.SAPList.Remove","haxor/ds/SAP.hx",387,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(388)
		if ((!(this->m_has_query))){
			HX_STACK_LINE(388)
			return null();
		}
		HX_STACK_LINE(389)
		::haxor::ds::SAPInterval p = p_item->prev;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(390)
		::haxor::ds::SAPInterval n = p_item->next;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(391)
		if (((p != null()))){
			HX_STACK_LINE(391)
			p->next = n;
		}
		HX_STACK_LINE(392)
		if (((n != null()))){
			HX_STACK_LINE(392)
			n->prev = p;
		}
		HX_STACK_LINE(393)
		::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(393)
		p_item->next = _g;
		HX_STACK_LINE(395)
		if (((p_item == this->start))){
			HX_STACK_LINE(395)
			this->start = n;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Remove,(void))

::String SAPList_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.ds.SAPList","ToString",0xd678810d,"haxor.ds.SAPList.ToString","haxor/ds/SAP.hx",403,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(404)
		::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(405)
		if ((this->m_has_query)){
			HX_STACK_LINE(407)
			::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
			HX_STACK_LINE(408)
			while((true)){
				HX_STACK_LINE(408)
				if ((!(((it != null()))))){
					HX_STACK_LINE(408)
					break;
				}
				HX_STACK_LINE(410)
				::String _g = it->ToString(p_places);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(410)
				hx::AddEq(s,_g);
				HX_STACK_LINE(411)
				it = it->next;
			}
		}
		else{
			HX_STACK_LINE(416)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(416)
			int _g = this->list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(416)
			while((true)){
				HX_STACK_LINE(416)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(416)
					break;
				}
				HX_STACK_LINE(416)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(416)
				::String _g11 = this->list->__get(i).StaticCast< ::haxor::ds::SAPInterval >()->ToString(p_places);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(416)
				hx::AddEq(s,_g11);
			}
		}
		HX_STACK_LINE(418)
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
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
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
		if (HX_FIELD_EQ(inName,"Insert") ) { return Insert_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Relocate") ) { return Relocate_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"RemoveById") ) { return RemoveById_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_has_query") ) { return m_has_query; }
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
	HX_CSTRING("Add"),
	HX_CSTRING("Insert"),
	HX_CSTRING("Relocate"),
	HX_CSTRING("RemoveById"),
	HX_CSTRING("Remove"),
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
