#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void Output_obj::__construct()
{
	return null();
}

//Output_obj::~Output_obj() { }

Dynamic Output_obj::__CreateEmpty() { return  new Output_obj; }
hx::ObjectPtr< Output_obj > Output_obj::__new()
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Dynamic Output_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Void Output_obj::writeByte( int c){
{
		HX_STACK_FRAME("haxe.io.Output","writeByte",0xb4fe513a,"haxe.io.Output.writeByte","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/Output.hx",39,0x97892c70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(39)
		HX_STACK_DO_THROW(HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeByte,(void))

int Output_obj::writeBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_STACK_FRAME("haxe.io.Output","writeBytes",0xa988c1f9,"haxe.io.Output.writeBytes","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/Output.hx",42,0x97892c70)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(43)
	int k = len;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(44)
	Array< unsigned char > b = s->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(46)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_STACK_LINE(47)
		HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
	}
	HX_STACK_LINE(49)
	while((true)){
		HX_STACK_LINE(49)
		if ((!(((k > (int)0))))){
			HX_STACK_LINE(49)
			break;
		}
		HX_STACK_LINE(55)
		this->writeByte(b->__get(pos));
		HX_STACK_LINE(59)
		(pos)++;
		HX_STACK_LINE(60)
		(k)--;
	}
	HX_STACK_LINE(62)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeBytes,return )

Void Output_obj::close( ){
{
		HX_STACK_FRAME("haxe.io.Output","close",0xe726bfeb,"haxe.io.Output.close","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/Output.hx",68,0x97892c70)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,close,(void))

Void Output_obj::writeFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_STACK_FRAME("haxe.io.Output","writeFullBytes",0xc2c420ea,"haxe.io.Output.writeFullBytes","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/Output.hx",90,0x97892c70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_ARG(pos,"pos")
		HX_STACK_ARG(len,"len")
		HX_STACK_LINE(90)
		while((true)){
			HX_STACK_LINE(90)
			if ((!(((len > (int)0))))){
				HX_STACK_LINE(90)
				break;
			}
			HX_STACK_LINE(91)
			int k = this->writeBytes(s,pos,len);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(92)
			hx::AddEq(pos,k);
			HX_STACK_LINE(93)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeFullBytes,(void))

Void Output_obj::prepare( int nbytes){
{
		HX_STACK_FRAME("haxe.io.Output","prepare",0xcd01ec7a,"haxe.io.Output.prepare","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/Output.hx",288,0x97892c70)
		HX_STACK_THIS(this)
		HX_STACK_ARG(nbytes,"nbytes")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,prepare,(void))


Output_obj::Output_obj()
{
}

Dynamic Output_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prepare") ) { return prepare_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"writeFullBytes") ) { return writeFullBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Output_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Output_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("close"),
	HX_CSTRING("writeFullBytes"),
	HX_CSTRING("prepare"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Output_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Output_obj::__mClass,"__mClass");
};

#endif

Class Output_obj::__mClass;

void Output_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Output"), hx::TCanCast< Output_obj> ,sStaticFields,sMemberFields,
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

void Output_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
