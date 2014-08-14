#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16__Buffer
#include <haxor/io/UInt16__Buffer.h>
#endif
namespace haxor{
namespace io{

Void UInt16__Buffer_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.UInt16__Buffer","new",0x484b310d,"haxor.io.UInt16__Buffer.new","haxor/io/UInt16__Buffer.hx",26,0xfae9c463)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(27)
	super::__construct((p_length * (int)2));
	HX_STACK_LINE(28)
	this->m_length = p_length;
}
;
	return null();
}

//UInt16__Buffer_obj::~UInt16__Buffer_obj() { }

Dynamic UInt16__Buffer_obj::__CreateEmpty() { return  new UInt16__Buffer_obj; }
hx::ObjectPtr< UInt16__Buffer_obj > UInt16__Buffer_obj::__new(int p_length)
{  hx::ObjectPtr< UInt16__Buffer_obj > result = new UInt16__Buffer_obj();
	result->__construct(p_length);
	return result;}

Dynamic UInt16__Buffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UInt16__Buffer_obj > result = new UInt16__Buffer_obj();
	result->__construct(inArgs[0]);
	return result;}

int UInt16__Buffer_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.UInt16__Buffer","Get",0x482d9923,"haxor.io.UInt16__Buffer.Get","haxor/io/UInt16__Buffer.hx",39,0xfae9c463)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(45)
	int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(46)
	
		int v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) m_buffer->b[0];
		ptr[1] = (char) m_buffer->b[1];		
		return v;
		;
	HX_STACK_LINE(53)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(UInt16__Buffer_obj,Get,return )

Void UInt16__Buffer_obj::Set( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.UInt16__Buffer","Set",0x4836b42f,"haxor.io.UInt16__Buffer.Set","haxor/io/UInt16__Buffer.hx",67,0xfae9c463)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(73)
		int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(74)
		
		int v   = p_value;
		char* ptr = (char*)(&v);
		m_buffer->b[p]   = ptr[0];
		m_buffer->b[p+1] = ptr[1];		
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16__Buffer_obj,Set,(void))


UInt16__Buffer_obj::UInt16__Buffer_obj()
{
}

Dynamic UInt16__Buffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UInt16__Buffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void UInt16__Buffer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UInt16__Buffer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UInt16__Buffer_obj::__mClass,"__mClass");
};

#endif

Class UInt16__Buffer_obj::__mClass;

void UInt16__Buffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.UInt16__Buffer"), hx::TCanCast< UInt16__Buffer_obj> ,sStaticFields,sMemberFields,
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

void UInt16__Buffer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
