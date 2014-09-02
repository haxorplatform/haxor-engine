#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_SAPInterval
#include <haxor/ds/SAPInterval.h>
#endif
#ifndef INCLUDED_haxor_ds_SAPList
#include <haxor/ds/SAPList.h>
#endif
namespace haxor{
namespace ds{

Void SAPList_obj::__construct()
{
HX_STACK_FRAME("haxor.ds.SAPList","new",0x07a243bf,"haxor.ds.SAPList.new","haxor/ds/SAP.hx",237,0xbaeeb06f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(237)
	this->list = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//SAPList_obj::~SAPList_obj() { }

Dynamic SAPList_obj::__CreateEmpty() { return  new SAPList_obj; }
hx::ObjectPtr< SAPList_obj > SAPList_obj::__new()
{  hx::ObjectPtr< SAPList_obj > result = new SAPList_obj();
	result->__construct();
	return result;}

Dynamic SAPList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAPList_obj > result = new SAPList_obj();
	result->__construct();
	return result;}

Void SAPList_obj::Create( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Create",0xf06a8d1d,"haxor.ds.SAPList.Create","haxor/ds/SAP.hx",246,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(246)
		while((true)){
			HX_STACK_LINE(246)
			if ((!(((this->list->length <= p_id))))){
				HX_STACK_LINE(246)
				break;
			}
			HX_STACK_LINE(248)
			::haxor::ds::SAPInterval it = ::haxor::ds::SAPInterval_obj::__new();		HX_STACK_VAR(it,"it");
			HX_STACK_LINE(249)
			it->id = this->list->length;
			HX_STACK_LINE(250)
			this->list->push(it);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Create,(void))

Void SAPList_obj::Update( int p_id,Dynamic p_data,Float p_min,Float p_max){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Update",0xfb60ac2a,"haxor.ds.SAPList.Update","haxor/ds/SAP.hx",261,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(262)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->id = p_id;
		HX_STACK_LINE(263)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->data = p_data;
		HX_STACK_LINE(264)
		this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >()->Set(p_min,p_max);
		HX_STACK_LINE(265)
		this->Relocate(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SAPList_obj,Update,(void))

Void SAPList_obj::Add( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Add",0x07801d60,"haxor.ds.SAPList.Add","haxor/ds/SAP.hx",273,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(274)
		if (((this->start == null()))){
			HX_STACK_LINE(274)
			this->start = p_item;
			HX_STACK_LINE(274)
			::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(274)
			p_item->next = _g;
			HX_STACK_LINE(274)
			return null();
		}
		HX_STACK_LINE(275)
		if (((p_item == this->start))){
			HX_STACK_LINE(275)
			return null();
		}
		HX_STACK_LINE(276)
		::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(277)
		while((true)){
			HX_STACK_LINE(277)
			if ((!(((it != null()))))){
				HX_STACK_LINE(277)
				break;
			}
			HX_STACK_LINE(279)
			if (((p_item->min < it->min))){
				HX_STACK_LINE(279)
				this->Insert(p_item,it);
				HX_STACK_LINE(279)
				return null();
			}
			HX_STACK_LINE(280)
			if (((it->next == null()))){
				HX_STACK_LINE(280)
				this->Insert(p_item,it);
				HX_STACK_LINE(280)
				return null();
			}
			HX_STACK_LINE(281)
			it = it->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Add,(void))

Void SAPList_obj::Insert( ::haxor::ds::SAPInterval p_item,::haxor::ds::SAPInterval p_at){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Insert",0x1238695a,"haxor.ds.SAPList.Insert","haxor/ds/SAP.hx",291,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_ARG(p_at,"p_at")
		HX_STACK_LINE(292)
		if (((p_item == p_at))){
			HX_STACK_LINE(292)
			return null();
		}
		HX_STACK_LINE(295)
		if (((p_item->min > p_at->min))){
			HX_STACK_LINE(297)
			p_item->next = p_at->next;
			HX_STACK_LINE(298)
			p_item->prev = p_at;
			HX_STACK_LINE(299)
			p_at->next = p_item;
			HX_STACK_LINE(300)
			if (((p_item->next != null()))){
				HX_STACK_LINE(300)
				p_item->next->prev = p_item;
			}
		}
		else{
			HX_STACK_LINE(304)
			p_item->next = p_at;
			HX_STACK_LINE(305)
			p_item->prev = p_at->prev;
			HX_STACK_LINE(306)
			p_at->prev = p_item;
			HX_STACK_LINE(307)
			if (((p_item->prev != null()))){
				HX_STACK_LINE(307)
				p_item->prev->next = p_item;
			}
			HX_STACK_LINE(309)
			if (((p_at == this->start))){
				HX_STACK_LINE(309)
				this->start = p_item;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAPList_obj,Insert,(void))

Void SAPList_obj::Relocate( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Relocate",0xd837d7e6,"haxor.ds.SAPList.Relocate","haxor/ds/SAP.hx",319,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(321)
		if (((p_item->prev == null()))){
			HX_STACK_LINE(322)
			if (((p_item->next == null()))){
				HX_STACK_LINE(324)
				this->Add(p_item);
				HX_STACK_LINE(325)
				return null();
			}
		}
		HX_STACK_LINE(328)
		::haxor::ds::SAPInterval it = p_item;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(329)
		int nav = (int)0;		HX_STACK_VAR(nav,"nav");
		HX_STACK_LINE(330)
		::haxor::ds::SAPInterval location = null();		HX_STACK_VAR(location,"location");
		HX_STACK_LINE(333)
		while((true)){
			HX_STACK_LINE(333)
			if ((!(((it != null()))))){
				HX_STACK_LINE(333)
				break;
			}
			HX_STACK_LINE(335)
			::haxor::ds::SAPInterval n = it->next;		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(336)
			::haxor::ds::SAPInterval p = it->prev;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(337)
			if (((n == null()))){
				HX_STACK_LINE(337)
				if (((p == null()))){
					HX_STACK_LINE(337)
					break;
				}
			}
			HX_STACK_LINE(338)
			if (((p != null()))){
				HX_STACK_LINE(338)
				if (((p_item->min < p->min))){
					HX_STACK_LINE(338)
					nav = (int)-1;
					HX_STACK_LINE(338)
					location = p;
				}
			}
			HX_STACK_LINE(339)
			if (((n != null()))){
				HX_STACK_LINE(339)
				if (((p_item->min > n->min))){
					HX_STACK_LINE(339)
					nav = (int)1;
					HX_STACK_LINE(339)
					location = n;
				}
			}
			HX_STACK_LINE(340)
			if (((nav == (int)0))){
				HX_STACK_LINE(340)
				break;
			}
			HX_STACK_LINE(341)
			if (((nav < (int)0))){
				HX_STACK_LINE(341)
				it = p;
			}
			else{
				HX_STACK_LINE(341)
				it = n;
			}
			HX_STACK_LINE(342)
			nav = (int)0;
		}
		HX_STACK_LINE(345)
		if (((location != null()))){
			HX_STACK_LINE(348)
			this->Remove(p_item);
			HX_STACK_LINE(350)
			this->Insert(p_item,location);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Relocate,(void))

Void SAPList_obj::RemoveById( int p_id){
{
		HX_STACK_FRAME("haxor.ds.SAPList","RemoveById",0x36617e97,"haxor.ds.SAPList.RemoveById","haxor/ds/SAP.hx",360,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(360)
		this->Remove(this->list->__get(p_id).StaticCast< ::haxor::ds::SAPInterval >());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,RemoveById,(void))

Void SAPList_obj::Remove( ::haxor::ds::SAPInterval p_item){
{
		HX_STACK_FRAME("haxor.ds.SAPList","Remove",0x78e3c265,"haxor.ds.SAPList.Remove","haxor/ds/SAP.hx",368,0xbaeeb06f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_item,"p_item")
		HX_STACK_LINE(369)
		::haxor::ds::SAPInterval p = p_item->prev;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(370)
		::haxor::ds::SAPInterval n = p_item->next;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(371)
		if (((p != null()))){
			HX_STACK_LINE(371)
			p->next = n;
		}
		HX_STACK_LINE(372)
		if (((n != null()))){
			HX_STACK_LINE(372)
			n->prev = p;
		}
		HX_STACK_LINE(373)
		::haxor::ds::SAPInterval _g = p_item->prev = null();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(373)
		p_item->next = _g;
		HX_STACK_LINE(375)
		if (((p_item == this->start))){
			HX_STACK_LINE(375)
			this->start = n;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SAPList_obj,Remove,(void))

::String SAPList_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.ds.SAPList","ToString",0xd678810d,"haxor.ds.SAPList.ToString","haxor/ds/SAP.hx",383,0xbaeeb06f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(384)
		::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(385)
		::haxor::ds::SAPInterval it = this->start;		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(386)
		while((true)){
			HX_STACK_LINE(386)
			if ((!(((it != null()))))){
				HX_STACK_LINE(386)
				break;
			}
			HX_STACK_LINE(388)
			::String _g = it->ToString(p_places);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(388)
			hx::AddEq(s,_g);
			HX_STACK_LINE(389)
			it = it->next;
		}
		HX_STACK_LINE(391)
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
	HX_MARK_END_CLASS();
}

void SAPList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(list,"list");
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAPList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("list"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::ds::SAPInterval*/ ,(int)offsetof(SAPList_obj,start),HX_CSTRING("start")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SAPList_obj,list),HX_CSTRING("list")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("start"),
	HX_CSTRING("list"),
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
