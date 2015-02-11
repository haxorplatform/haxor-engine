#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_ds_SAP
#include <haxor/ds/SAP.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_physics_broadphase_BroadPhase
#include <haxor/physics/broadphase/BroadPhase.h>
#endif
#ifndef INCLUDED_haxor_physics_broadphase_SAPBroadPhase
#include <haxor/physics/broadphase/SAPBroadPhase.h>
#endif
namespace haxor{
namespace physics{
namespace broadphase{

Void SAPBroadPhase_obj::__construct()
{
HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","new",0x29d23e6b,"haxor.physics.broadphase.SAPBroadPhase.new","haxor/physics/broadphase/SAPBroadPhase.hx",16,0x257b77a4)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(16)
	super::__construct();
}
;
	return null();
}

//SAPBroadPhase_obj::~SAPBroadPhase_obj() { }

Dynamic SAPBroadPhase_obj::__CreateEmpty() { return  new SAPBroadPhase_obj; }
hx::ObjectPtr< SAPBroadPhase_obj > SAPBroadPhase_obj::__new()
{  hx::ObjectPtr< SAPBroadPhase_obj > result = new SAPBroadPhase_obj();
	result->__construct();
	return result;}

Dynamic SAPBroadPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SAPBroadPhase_obj > result = new SAPBroadPhase_obj();
	result->__construct();
	return result;}

Void SAPBroadPhase_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","Initialize",0x27e26ec5,"haxor.physics.broadphase.SAPBroadPhase.Initialize","haxor/physics/broadphase/SAPBroadPhase.hx",28,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		::haxor::ds::SAP _g = ::haxor::ds::SAP_obj::__new(0.0,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		this->sap = _g;
	}
return null();
}


Void SAPBroadPhase_obj::Update( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","Update",0xd199a4fe,"haxor.physics.broadphase.SAPBroadPhase.Update","haxor/physics/broadphase/SAPBroadPhase.hx",37,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(38)
		if ((c->m_aabb_dirty)){
			HX_STACK_LINE(38)
			c->GenerateAABB();
			HX_STACK_LINE(38)
			c->m_aabb_dirty = false;
		}
		HX_STACK_LINE(39)
		::haxor::math::AABB3 bb = c->m_aabb;		HX_STACK_VAR(bb,"bb");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/broadphase/SAPBroadPhase.hx",40,0x257b77a4)
				{
					HX_STACK_LINE(40)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(40)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(40)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(40)
		::haxor::math::Vector3 vmin = (_Function_1_1::Block())->Set(bb->m_xMin,bb->m_yMin,bb->m_zMin);		HX_STACK_VAR(vmin,"vmin");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/broadphase/SAPBroadPhase.hx",41,0x257b77a4)
				{
					HX_STACK_LINE(41)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(41)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(41)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(41)
		::haxor::math::Vector3 vmax = (_Function_1_2::Block())->Set(bb->m_xMax,bb->m_yMax,bb->m_zMax);		HX_STACK_VAR(vmax,"vmax");
		HX_STACK_LINE(42)
		this->sap->Update(c->__cid,c,vmin,vmax);
	}
return null();
}


Void SAPBroadPhase_obj::Add( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","Add",0x29b0180c,"haxor.physics.broadphase.SAPBroadPhase.Add","haxor/physics/broadphase/SAPBroadPhase.hx",51,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(51)
		this->sap->Create(c->__cid);
	}
return null();
}


Void SAPBroadPhase_obj::Remove( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","Remove",0x4f1cbb39,"haxor.physics.broadphase.SAPBroadPhase.Remove","haxor/physics/broadphase/SAPBroadPhase.hx",60,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(60)
		this->sap->Remove(c->__cid);
	}
return null();
}


Void SAPBroadPhase_obj::Query( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","Query",0x499641b3,"haxor.physics.broadphase.SAPBroadPhase.Query","haxor/physics/broadphase/SAPBroadPhase.hx",69,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(69)
		this->sap->Query(c->__cid,this->OnSAPFetch_dyn());
	}
return null();
}


Void SAPBroadPhase_obj::OnSAPFetch( Dynamic a,Dynamic b){
{
		HX_STACK_FRAME("haxor.physics.broadphase.SAPBroadPhase","OnSAPFetch",0xe72ede6c,"haxor.physics.broadphase.SAPBroadPhase.OnSAPFetch","haxor/physics/broadphase/SAPBroadPhase.hx",78,0x257b77a4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(78)
		this->OnFetch(a,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SAPBroadPhase_obj,OnSAPFetch,(void))


SAPBroadPhase_obj::SAPBroadPhase_obj()
{
}

void SAPBroadPhase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SAPBroadPhase);
	HX_MARK_MEMBER_NAME(sap,"sap");
	::haxor::physics::broadphase::BroadPhase_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SAPBroadPhase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sap,"sap");
	::haxor::physics::broadphase::BroadPhase_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SAPBroadPhase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"sap") ) { return sap; }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Query") ) { return Query_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"OnSAPFetch") ) { return OnSAPFetch_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SAPBroadPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"sap") ) { sap=inValue.Cast< ::haxor::ds::SAP >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SAPBroadPhase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::ds::SAP*/ ,(int)offsetof(SAPBroadPhase_obj,sap),HX_CSTRING("sap")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("sap"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Update"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Query"),
	HX_CSTRING("OnSAPFetch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SAPBroadPhase_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SAPBroadPhase_obj::__mClass,"__mClass");
};

#endif

Class SAPBroadPhase_obj::__mClass;

void SAPBroadPhase_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.broadphase.SAPBroadPhase"), hx::TCanCast< SAPBroadPhase_obj> ,sStaticFields,sMemberFields,
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

void SAPBroadPhase_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
} // end namespace broadphase
