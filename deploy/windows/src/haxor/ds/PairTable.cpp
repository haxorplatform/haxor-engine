#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_PairTable
#include <haxor/ds/PairTable.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace ds{

Void PairTable_obj::__construct(int p_count,Dynamic p_default,hx::Null< bool >  __o_p_mirror)
{
HX_STACK_FRAME("haxor.ds.PairTable","new",0xa64462f3,"haxor.ds.PairTable.new","haxor/ds/PairTable.hx",39,0xfd9d227d)
HX_STACK_THIS(this)
HX_STACK_ARG(p_count,"p_count")
HX_STACK_ARG(p_default,"p_default")
HX_STACK_ARG(__o_p_mirror,"p_mirror")
bool p_mirror = __o_p_mirror.Default(false);
{
	HX_STACK_LINE(40)
	this->m_mirror = p_mirror;
	HX_STACK_LINE(41)
	this->m_table = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(43)
	int lc;		HX_STACK_VAR(lc,"lc");
	HX_STACK_LINE(43)
	if ((p_mirror)){
		HX_STACK_LINE(43)
		lc = (int)0;
	}
	else{
		HX_STACK_LINE(43)
		lc = p_count;
	}
	HX_STACK_LINE(44)
	{
		HX_STACK_LINE(44)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		while((true)){
			HX_STACK_LINE(44)
			if ((!(((_g < p_count))))){
				HX_STACK_LINE(44)
				break;
			}
			HX_STACK_LINE(44)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(46)
			Dynamic l = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(47)
			this->m_table->__Field(HX_CSTRING("push"),true)(l);
			HX_STACK_LINE(48)
			{
				HX_STACK_LINE(48)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(48)
				while((true)){
					HX_STACK_LINE(48)
					if ((!(((_g1 < lc))))){
						HX_STACK_LINE(48)
						break;
					}
					HX_STACK_LINE(48)
					int j = (_g1)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(50)
					l->__Field(HX_CSTRING("push"),true)(p_default);
				}
			}
			HX_STACK_LINE(52)
			if ((p_mirror)){
				HX_STACK_LINE(52)
				(lc)++;
			}
		}
	}
}
;
	return null();
}

//PairTable_obj::~PairTable_obj() { }

Dynamic PairTable_obj::__CreateEmpty() { return  new PairTable_obj; }
hx::ObjectPtr< PairTable_obj > PairTable_obj::__new(int p_count,Dynamic p_default,hx::Null< bool >  __o_p_mirror)
{  hx::ObjectPtr< PairTable_obj > result = new PairTable_obj();
	result->__construct(p_count,p_default,__o_p_mirror);
	return result;}

Dynamic PairTable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PairTable_obj > result = new PairTable_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool PairTable_obj::get_mirror( ){
	HX_STACK_FRAME("haxor.ds.PairTable","get_mirror",0xdb4f17d5,"haxor.ds.PairTable.get_mirror","haxor/ds/PairTable.hx",14,0xfd9d227d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(14)
	return this->m_mirror;
}


HX_DEFINE_DYNAMIC_FUNC0(PairTable_obj,get_mirror,return )

int PairTable_obj::get_rows( ){
	HX_STACK_FRAME("haxor.ds.PairTable","get_rows",0x809de92f,"haxor.ds.PairTable.get_rows","haxor/ds/PairTable.hx",21,0xfd9d227d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_table->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(PairTable_obj,get_rows,return )

int PairTable_obj::get_cols( ){
	HX_STACK_FRAME("haxor.ds.PairTable","get_cols",0x76b3ac49,"haxor.ds.PairTable.get_cols","haxor/ds/PairTable.hx",27,0xfd9d227d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(27)
	return this->m_table->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(PairTable_obj,get_cols,return )

Dynamic PairTable_obj::Get( int p_x,int p_y){
	HX_STACK_FRAME("haxor.ds.PairTable","Get",0xa626cb09,"haxor.ds.PairTable.Get","haxor/ds/PairTable.hx",63,0xfd9d227d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_LINE(64)
	if ((this->get_mirror())){
		HX_STACK_LINE(65)
		int _g = ::Math_obj::max(p_x,p_y);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(65)
		Dynamic _g1 = this->m_table->__GetItem(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(65)
		int _g2 = ::Math_obj::min(p_x,p_y);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(65)
		return _g1->__GetItem(_g2);
	}
	HX_STACK_LINE(66)
	return this->m_table->__GetItem(p_x)->__GetItem(p_y);
}


HX_DEFINE_DYNAMIC_FUNC2(PairTable_obj,Get,return )

Void PairTable_obj::Set( int p_x,int p_y,Dynamic p_value){
{
		HX_STACK_FRAME("haxor.ds.PairTable","Set",0xa62fe615,"haxor.ds.PairTable.Set","haxor/ds/PairTable.hx",76,0xfd9d227d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(77)
		if ((this->get_mirror())){
			HX_STACK_LINE(78)
			int _g = ::Math_obj::max(p_x,p_y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			Dynamic _g1 = this->m_table->__GetItem(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(78)
			int _g2 = ::Math_obj::min(p_x,p_y);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(78)
			hx::IndexRef((_g1).mPtr,_g2) = p_value;
			HX_STACK_LINE(78)
			return null();
		}
		HX_STACK_LINE(79)
		hx::IndexRef((this->m_table->__GetItem(p_x)).mPtr,p_y) = p_value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PairTable_obj,Set,(void))

Dynamic PairTable_obj::Line( int p_index){
	HX_STACK_FRAME("haxor.ds.PairTable","Line",0xbf1bf221,"haxor.ds.PairTable.Line","haxor/ds/PairTable.hx",87,0xfd9d227d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(87)
	return this->m_table->__GetItem(p_index);
}


HX_DEFINE_DYNAMIC_FUNC1(PairTable_obj,Line,return )

Void PairTable_obj::Iterate( Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.ds.PairTable","Iterate",0x32aa79ed,"haxor.ds.PairTable.Iterate","haxor/ds/PairTable.hx",96,0xfd9d227d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(96)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(96)
		int _g = this->m_table->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(96)
		while((true)){
			HX_STACK_LINE(96)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(96)
				break;
			}
			HX_STACK_LINE(96)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(98)
			Dynamic l = this->m_table->__GetItem(i);		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(99)
			{
				HX_STACK_LINE(99)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(99)
				int _g2 = l->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(99)
				while((true)){
					HX_STACK_LINE(99)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(99)
						break;
					}
					HX_STACK_LINE(99)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(101)
					p_callback(j,i,l->__GetItem(j)).Cast< Void >();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PairTable_obj,Iterate,(void))


PairTable_obj::PairTable_obj()
{
}

void PairTable_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PairTable);
	HX_MARK_MEMBER_NAME(m_mirror,"m_mirror");
	HX_MARK_MEMBER_NAME(m_table,"m_table");
	HX_MARK_END_CLASS();
}

void PairTable_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_mirror,"m_mirror");
	HX_VISIT_MEMBER_NAME(m_table,"m_table");
}

Dynamic PairTable_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rows") ) { return get_rows(); }
		if (HX_FIELD_EQ(inName,"cols") ) { return get_cols(); }
		if (HX_FIELD_EQ(inName,"Line") ) { return Line_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mirror") ) { return get_mirror(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_table") ) { return m_table; }
		if (HX_FIELD_EQ(inName,"Iterate") ) { return Iterate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_mirror") ) { return m_mirror; }
		if (HX_FIELD_EQ(inName,"get_rows") ) { return get_rows_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cols") ) { return get_cols_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_mirror") ) { return get_mirror_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PairTable_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_table") ) { m_table=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_mirror") ) { m_mirror=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PairTable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mirror"));
	outFields->push(HX_CSTRING("m_mirror"));
	outFields->push(HX_CSTRING("rows"));
	outFields->push(HX_CSTRING("cols"));
	outFields->push(HX_CSTRING("m_table"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(PairTable_obj,m_mirror),HX_CSTRING("m_mirror")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(PairTable_obj,m_table),HX_CSTRING("m_table")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_mirror"),
	HX_CSTRING("m_mirror"),
	HX_CSTRING("get_rows"),
	HX_CSTRING("get_cols"),
	HX_CSTRING("m_table"),
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
	HX_CSTRING("Line"),
	HX_CSTRING("Iterate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PairTable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PairTable_obj::__mClass,"__mClass");
};

#endif

Class PairTable_obj::__mClass;

void PairTable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.PairTable"), hx::TCanCast< PairTable_obj> ,sStaticFields,sMemberFields,
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

void PairTable_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
