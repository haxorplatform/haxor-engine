#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_BoxEmitter
#include <haxor/component/BoxEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
namespace haxor{
namespace component{

Void BoxEmitter_obj::__construct(hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth)
{
HX_STACK_FRAME("haxor.component.BoxEmitter","new",0xa425d172,"haxor.component.BoxEmitter.new","haxor/component/ParticleRenderer.hx",434,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_width,"p_width")
HX_STACK_ARG(__o_p_height,"p_height")
HX_STACK_ARG(__o_p_depth,"p_depth")
Float p_width = __o_p_width.Default(1.0);
Float p_height = __o_p_height.Default(1.0);
Float p_depth = __o_p_depth.Default(1.0);
{
	HX_STACK_LINE(435)
	super::__construct();
	HX_STACK_LINE(436)
	this->m_data[(int)0] = 1.0;
	HX_STACK_LINE(437)
	this->set_width(p_width);
	HX_STACK_LINE(438)
	this->set_height(p_height);
	HX_STACK_LINE(439)
	this->set_depth(p_depth);
}
;
	return null();
}

//BoxEmitter_obj::~BoxEmitter_obj() { }

Dynamic BoxEmitter_obj::__CreateEmpty() { return  new BoxEmitter_obj; }
hx::ObjectPtr< BoxEmitter_obj > BoxEmitter_obj::__new(hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth)
{  hx::ObjectPtr< BoxEmitter_obj > result = new BoxEmitter_obj();
	result->__construct(__o_p_width,__o_p_height,__o_p_depth);
	return result;}

Dynamic BoxEmitter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxEmitter_obj > result = new BoxEmitter_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Float BoxEmitter_obj::get_width( ){
	HX_STACK_FRAME("haxor.component.BoxEmitter","get_width",0xdd572cef,"haxor.component.BoxEmitter.get_width","haxor/component/ParticleRenderer.hx",422,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(422)
	return this->m_data->__get((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(BoxEmitter_obj,get_width,return )

Float BoxEmitter_obj::set_width( Float v){
	HX_STACK_FRAME("haxor.component.BoxEmitter","set_width",0xc0a818fb,"haxor.component.BoxEmitter.set_width","haxor/component/ParticleRenderer.hx",423,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(423)
	this->m_data[(int)3] = v;
	HX_STACK_LINE(423)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxEmitter_obj,set_width,return )

Float BoxEmitter_obj::get_height( ){
	HX_STACK_FRAME("haxor.component.BoxEmitter","get_height",0x853f9cde,"haxor.component.BoxEmitter.get_height","haxor/component/ParticleRenderer.hx",426,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(426)
	return this->m_data->__get((int)4);
}


HX_DEFINE_DYNAMIC_FUNC0(BoxEmitter_obj,get_height,return )

Float BoxEmitter_obj::set_height( Float v){
	HX_STACK_FRAME("haxor.component.BoxEmitter","set_height",0x88bd3b52,"haxor.component.BoxEmitter.set_height","haxor/component/ParticleRenderer.hx",427,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(427)
	this->m_data[(int)4] = v;
	HX_STACK_LINE(427)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxEmitter_obj,set_height,return )

Float BoxEmitter_obj::get_depth( ){
	HX_STACK_FRAME("haxor.component.BoxEmitter","get_depth",0xea1e67ec,"haxor.component.BoxEmitter.get_depth","haxor/component/ParticleRenderer.hx",430,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(430)
	return this->m_data->__get((int)5);
}


HX_DEFINE_DYNAMIC_FUNC0(BoxEmitter_obj,get_depth,return )

Float BoxEmitter_obj::set_depth( Float v){
	HX_STACK_FRAME("haxor.component.BoxEmitter","set_depth",0xcd6f53f8,"haxor.component.BoxEmitter.set_depth","haxor/component/ParticleRenderer.hx",431,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(431)
	this->m_data[(int)5] = v;
	HX_STACK_LINE(431)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxEmitter_obj,set_depth,return )


BoxEmitter_obj::BoxEmitter_obj()
{
}

Dynamic BoxEmitter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"depth") ) { return get_depth(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_depth") ) { return get_depth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_depth") ) { return set_depth_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoxEmitter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		if (HX_FIELD_EQ(inName,"depth") ) { return set_depth(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoxEmitter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("depth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_depth"),
	HX_CSTRING("set_depth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoxEmitter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoxEmitter_obj::__mClass,"__mClass");
};

#endif

Class BoxEmitter_obj::__mClass;

void BoxEmitter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.BoxEmitter"), hx::TCanCast< BoxEmitter_obj> ,sStaticFields,sMemberFields,
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

void BoxEmitter_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
