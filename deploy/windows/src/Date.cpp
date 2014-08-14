#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Date_obj::__construct(int year,int month,int day,int hour,int min,int sec)
{
HX_STACK_FRAME("Date","new",0x9aa26240,"Date.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Date.hx",26,0x998eeb7e)
HX_STACK_THIS(this)
HX_STACK_ARG(year,"year")
HX_STACK_ARG(month,"month")
HX_STACK_ARG(day,"day")
HX_STACK_ARG(hour,"hour")
HX_STACK_ARG(min,"min")
HX_STACK_ARG(sec,"sec")
{
	HX_STACK_LINE(27)
	Float _g = ::__hxcpp_new_date(year,month,day,hour,min,sec);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	this->mSeconds = _g;
}
;
	return null();
}

//Date_obj::~Date_obj() { }

Dynamic Date_obj::__CreateEmpty() { return  new Date_obj; }
hx::ObjectPtr< Date_obj > Date_obj::__new(int year,int month,int day,int hour,int min,int sec)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(year,month,day,hour,min,sec);
	return result;}

Dynamic Date_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Date_obj > result = new Date_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::String Date_obj::toString( ){
	HX_STACK_FRAME("Date","toString",0xd2a372cc,"Date.toString","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Date.hx",48,0x998eeb7e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return ::__hxcpp_to_string(this->mSeconds);
}


HX_DEFINE_DYNAMIC_FUNC0(Date_obj,toString,return )

::Date Date_obj::fromString( ::String s){
	HX_STACK_FRAME("Date","fromString",0x5ead97fb,"Date.fromString","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Date.hx",63,0x998eeb7e)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(64)
	{
		HX_STACK_LINE(64)
		int _g = s.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		switch( (int)(_g)){
			case (int)8: {
				HX_STACK_LINE(66)
				Array< ::String > k = s.split(HX_CSTRING(":"));		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(67)
				Dynamic _g1 = ::Std_obj::parseInt(k->__get((int)0));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(67)
				Dynamic _g11 = ::Std_obj::parseInt(k->__get((int)1));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(67)
				Dynamic _g2 = ::Std_obj::parseInt(k->__get((int)2));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(67)
				::Date d = ::Date_obj::__new((int)0,(int)0,(int)0,_g1,_g11,_g2);		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(68)
				return d;
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(70)
				Array< ::String > k = s.split(HX_CSTRING("-"));		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(71)
				Dynamic _g3 = ::Std_obj::parseInt(k->__get((int)0));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(71)
				Dynamic _g4 = ::Std_obj::parseInt(k->__get((int)1));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(71)
				int _g5 = (_g4 - (int)1);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(71)
				Dynamic _g6 = ::Std_obj::parseInt(k->__get((int)2));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(71)
				return ::Date_obj::__new(_g3,_g5,_g6,(int)0,(int)0,(int)0);
			}
			;break;
			case (int)19: {
				HX_STACK_LINE(73)
				Array< ::String > k = s.split(HX_CSTRING(" "));		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(74)
				Array< ::String > y = k->__get((int)0).split(HX_CSTRING("-"));		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(75)
				Array< ::String > t = k->__get((int)1).split(HX_CSTRING(":"));		HX_STACK_VAR(t,"t");
				HX_STACK_LINE(76)
				Dynamic _g7 = ::Std_obj::parseInt(y->__get((int)0));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(76)
				Dynamic _g8 = ::Std_obj::parseInt(y->__get((int)1));		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(76)
				int _g9 = (_g8 - (int)1);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(76)
				Dynamic _g10 = ::Std_obj::parseInt(y->__get((int)2));		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(77)
				Dynamic _g11 = ::Std_obj::parseInt(t->__get((int)0));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(77)
				Dynamic _g12 = ::Std_obj::parseInt(t->__get((int)1));		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(77)
				Dynamic _g13 = ::Std_obj::parseInt(t->__get((int)2));		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(76)
				return ::Date_obj::__new(_g7,_g9,_g10,_g11,_g12,_g13);
			}
			;break;
			default: {
				HX_STACK_LINE(79)
				HX_STACK_DO_THROW((HX_CSTRING("Invalid date format : ") + s));
			}
		}
	}
	HX_STACK_LINE(81)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Date_obj,fromString,return )


Date_obj::Date_obj()
{
}

Dynamic Date_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mSeconds") ) { return mSeconds; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromString") ) { return fromString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Date_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mSeconds") ) { mSeconds=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Date_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mSeconds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromString"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Date_obj,mSeconds),HX_CSTRING("mSeconds")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mSeconds"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Date_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Date_obj::__mClass,"__mClass");
};

#endif

Class Date_obj::__mClass;

void Date_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Date"), hx::TCanCast< Date_obj> ,sStaticFields,sMemberFields,
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

void Date_obj::__boot()
{
}

