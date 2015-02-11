#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_component_physics_SphereCollider
#include <haxor/component/physics/SphereCollider.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_ColliderType
#include <haxor/core/ColliderType.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace physics{

Void SphereCollider_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.physics.SphereCollider","new",0xce3e3bf7,"haxor.component.physics.SphereCollider.new","haxor/component/physics/SphereCollider.hx",19,0x678c16b6)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(19)
	super::__construct(p_name);
}
;
	return null();
}

//SphereCollider_obj::~SphereCollider_obj() { }

Dynamic SphereCollider_obj::__CreateEmpty() { return  new SphereCollider_obj; }
hx::ObjectPtr< SphereCollider_obj > SphereCollider_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< SphereCollider_obj > result = new SphereCollider_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic SphereCollider_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SphereCollider_obj > result = new SphereCollider_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::math::Vector3 SphereCollider_obj::get_center( ){
	HX_STACK_FRAME("haxor.component.physics.SphereCollider","get_center",0xec2cdae7,"haxor.component.physics.SphereCollider.get_center","haxor/component/physics/SphereCollider.hx",26,0x678c16b6)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/SphereCollider.hx",26,0x678c16b6)
			{
				HX_STACK_LINE(26)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(26)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(26)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(26)
	return (_Function_1_1::Block())->Set(this->m_center->x,this->m_center->y,this->m_center->z);
}


HX_DEFINE_DYNAMIC_FUNC0(SphereCollider_obj,get_center,return )

::haxor::math::Vector3 SphereCollider_obj::set_center( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.physics.SphereCollider","set_center",0xefaa795b,"haxor.component.physics.SphereCollider.set_center","haxor/component/physics/SphereCollider.hx",27,0x678c16b6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(27)
	this->m_center->Set(v->x,v->y,v->z);
	HX_STACK_LINE(27)
	this->Refresh();
	HX_STACK_LINE(27)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(SphereCollider_obj,set_center,return )

Float SphereCollider_obj::get_radius( ){
	HX_STACK_FRAME("haxor.component.physics.SphereCollider","get_radius",0x97488564,"haxor.component.physics.SphereCollider.get_radius","haxor/component/physics/SphereCollider.hx",34,0x678c16b6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	return this->m_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(SphereCollider_obj,get_radius,return )

Float SphereCollider_obj::set_radius( Float v){
	HX_STACK_FRAME("haxor.component.physics.SphereCollider","set_radius",0x9ac623d8,"haxor.component.physics.SphereCollider.set_radius","haxor/component/physics/SphereCollider.hx",35,0x678c16b6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(35)
	this->m_radius = v;
	HX_STACK_LINE(35)
	this->Refresh();
	HX_STACK_LINE(35)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(SphereCollider_obj,set_radius,return )

Void SphereCollider_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.physics.SphereCollider","OnBuild",0xfaf72486,"haxor.component.physics.SphereCollider.OnBuild","haxor/component/physics/SphereCollider.hx",42,0x678c16b6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(43)
		this->m_type = ::haxor::core::ColliderType_obj::Sphere;
		HX_STACK_LINE(44)
		this->super::OnBuild();
		HX_STACK_LINE(45)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(45)
		this->m_center = _g;
		HX_STACK_LINE(46)
		this->m_radius = 1.0;
		HX_STACK_LINE(47)
		this->Refresh();
	}
return null();
}


Void SphereCollider_obj::GenerateSphere( ){
{
		HX_STACK_FRAME("haxor.component.physics.SphereCollider","GenerateSphere",0xbf170a0b,"haxor.component.physics.SphereCollider.GenerateSphere","haxor/component/physics/SphereCollider.hx",54,0x678c16b6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(55)
		::haxor::math::Vector4 res = this->m_sphere;		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(56)
		::haxor::math::Matrix4 wm = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/SphereCollider.hx",57,0x678c16b6)
				{
					HX_STACK_LINE(57)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(57)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(57)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(57)
		::haxor::math::Vector3 c = (_Function_1_1::Block())->Set3(this->m_center);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(58)
		{
			HX_STACK_LINE(58)
			Float vx = ((((wm->m00 * c->x) + (wm->m01 * c->y)) + (wm->m02 * c->z)) + wm->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(58)
			Float vy = ((((wm->m10 * c->x) + (wm->m11 * c->y)) + (wm->m12 * c->z)) + wm->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(58)
			Float vz = ((((wm->m20 * c->x) + (wm->m21 * c->y)) + (wm->m22 * c->z)) + wm->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(58)
			c->x = vx;
			HX_STACK_LINE(58)
			c->y = vy;
			HX_STACK_LINE(58)
			c->z = vz;
			HX_STACK_LINE(58)
			c;
		}
		HX_STACK_LINE(59)
		res->Set3(c);
		HX_STACK_LINE(60)
		::haxor::math::Matrix4 _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(60)
			int _g1 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(60)
			_g2 = _this->m_m4->__get(_g1).StaticCast< ::haxor::math::Matrix4 >();
		}
		HX_STACK_LINE(60)
		::haxor::math::Matrix4 _g3 = ::haxor::math::Matrix4_obj::GetScale(wm,_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(60)
		wm = _g3;
		HX_STACK_LINE(61)
		Float _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			Float b = ::Math_obj::max(wm->m11,wm->m22);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(61)
			_g4 = ::Math_obj::max(wm->m00,b);
		}
		HX_STACK_LINE(61)
		Float _g5 = (_g4 * this->m_radius);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(61)
		res->w = _g5;
	}
return null();
}


Void SphereCollider_obj::GenerateAABB( ){
{
		HX_STACK_FRAME("haxor.component.physics.SphereCollider","GenerateAABB",0x8c123dfe,"haxor.component.physics.SphereCollider.GenerateAABB","haxor/component/physics/SphereCollider.hx",69,0x678c16b6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(70)
		::haxor::math::AABB3 b = this->m_aabb;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(71)
		::haxor::math::Matrix4 wm = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		HX_STACK_LINE(72)
		Float _g = this->get_radius();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(72)
		Float r = (_g * 0.5773507);		HX_STACK_VAR(r,"r");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/SphereCollider.hx",73,0x678c16b6)
				{
					HX_STACK_LINE(73)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(73)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(73)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(73)
		::haxor::math::Vector3 c = (_Function_1_1::Block())->Set(r,r,r);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(74)
		{
			HX_STACK_LINE(74)
			Float vx = (((wm->m00 * c->x) + (wm->m01 * c->y)) + (wm->m02 * c->z));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(74)
			Float vy = (((wm->m10 * c->x) + (wm->m11 * c->y)) + (wm->m12 * c->z));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(74)
			Float vz = (((wm->m20 * c->x) + (wm->m21 * c->y)) + (wm->m22 * c->z));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(74)
			c->x = vx;
			HX_STACK_LINE(74)
			c->y = vy;
			HX_STACK_LINE(74)
			c->z = vz;
			HX_STACK_LINE(74)
			c;
		}
		HX_STACK_LINE(75)
		Float _g2 = ::Math_obj::sqrt((((c->x * c->x) + (c->y * c->y)) + (c->z * c->z)));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(75)
		Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(75)
		r = _g3;
		HX_STACK_LINE(76)
		c->Set3(this->m_center);
		HX_STACK_LINE(77)
		{
			HX_STACK_LINE(77)
			Float vx = ((((wm->m00 * c->x) + (wm->m01 * c->y)) + (wm->m02 * c->z)) + wm->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(77)
			Float vy = ((((wm->m10 * c->x) + (wm->m11 * c->y)) + (wm->m12 * c->z)) + wm->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(77)
			Float vz = ((((wm->m20 * c->x) + (wm->m21 * c->y)) + (wm->m22 * c->z)) + wm->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(77)
			c->x = vx;
			HX_STACK_LINE(77)
			c->y = vy;
			HX_STACK_LINE(77)
			c->z = vz;
			HX_STACK_LINE(77)
			c;
		}
		HX_STACK_LINE(78)
		b->Set((-(r) + c->x),(r + c->x),(-(r) + c->y),(r + c->y),(-(r) + c->z),(r + c->z));
	}
return null();
}



SphereCollider_obj::SphereCollider_obj()
{
}

void SphereCollider_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SphereCollider);
	HX_MARK_MEMBER_NAME(m_center,"m_center");
	HX_MARK_MEMBER_NAME(m_radius,"m_radius");
	::haxor::component::physics::Collider_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SphereCollider_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_center,"m_center");
	HX_VISIT_MEMBER_NAME(m_radius,"m_radius");
	::haxor::component::physics::Collider_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SphereCollider_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return get_center(); }
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_center") ) { return m_center; }
		if (HX_FIELD_EQ(inName,"m_radius") ) { return m_radius; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_center") ) { return get_center_dyn(); }
		if (HX_FIELD_EQ(inName,"set_center") ) { return set_center_dyn(); }
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GenerateAABB") ) { return GenerateAABB_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GenerateSphere") ) { return GenerateSphere_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SphereCollider_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return set_center(inValue); }
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_center") ) { m_center=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_radius") ) { m_radius=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SphereCollider_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("m_center"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("m_radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(SphereCollider_obj,m_center),HX_CSTRING("m_center")},
	{hx::fsFloat,(int)offsetof(SphereCollider_obj,m_radius),HX_CSTRING("m_radius")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_center"),
	HX_CSTRING("set_center"),
	HX_CSTRING("m_center"),
	HX_CSTRING("get_radius"),
	HX_CSTRING("set_radius"),
	HX_CSTRING("m_radius"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("GenerateSphere"),
	HX_CSTRING("GenerateAABB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SphereCollider_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SphereCollider_obj::__mClass,"__mClass");
};

#endif

Class SphereCollider_obj::__mClass;

void SphereCollider_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.physics.SphereCollider"), hx::TCanCast< SphereCollider_obj> ,sStaticFields,sMemberFields,
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

void SphereCollider_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace physics
