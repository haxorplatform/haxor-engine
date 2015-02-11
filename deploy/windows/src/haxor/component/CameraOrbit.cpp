#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_CameraOrbit
#include <haxor/component/CameraOrbit.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
namespace haxor{
namespace component{

Void CameraOrbit_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.CameraOrbit","new",0xc5a52f1a,"haxor.component.CameraOrbit.new","haxor/component/CameraOrbit.hx",21,0xdbbd8c58)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(21)
	super::__construct(p_name);
}
;
	return null();
}

//CameraOrbit_obj::~CameraOrbit_obj() { }

Dynamic CameraOrbit_obj::__CreateEmpty() { return  new CameraOrbit_obj; }
hx::ObjectPtr< CameraOrbit_obj > CameraOrbit_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< CameraOrbit_obj > result = new CameraOrbit_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic CameraOrbit_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CameraOrbit_obj > result = new CameraOrbit_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *CameraOrbit_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	return super::__ToInterface(inType);
}

::haxor::component::Transform CameraOrbit_obj::get_pivot( ){
	HX_STACK_FRAME("haxor.component.CameraOrbit","get_pivot",0x368fcd53,"haxor.component.CameraOrbit.get_pivot","haxor/component/CameraOrbit.hx",38,0xdbbd8c58)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	if (((this->m_pivot == null()))){
		HX_STACK_LINE(41)
		::haxor::core::Entity e = ::haxor::core::Entity_obj::__new(null());		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(42)
		this->m_pivot = e->m_transform;
		HX_STACK_LINE(43)
		::String _g = this->m_entity->get_name();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		this->m_pivot->set_name(_g);
		HX_STACK_LINE(44)
		this->m_pivot->set_parent(this->m_entity->m_transform->m_parent);
		HX_STACK_LINE(45)
		this->m_entity->m_transform->set_parent(this->m_pivot);
		HX_STACK_LINE(46)
		this->m_entity->set_name(HX_CSTRING("camera"));
		HX_STACK_LINE(47)
		::haxor::math::Vector3 _g1 = this->m_entity->m_transform->get_position();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(47)
		this->m_pivot->set_position(_g1);
	}
	HX_STACK_LINE(49)
	return this->m_pivot;
}


HX_DEFINE_DYNAMIC_FUNC0(CameraOrbit_obj,get_pivot,return )

Void CameraOrbit_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.CameraOrbit","OnBuild",0x2359e529,"haxor.component.CameraOrbit.OnBuild","haxor/component/CameraOrbit.hx",70,0xdbbd8c58)
		HX_STACK_THIS(this)
		HX_STACK_LINE(71)
		this->super::OnBuild();
		HX_STACK_LINE(72)
		this->distance = 0.0;
		HX_STACK_LINE(73)
		::haxor::component::Transform _g = this->get_pivot();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		this->m_pivot = _g;
		HX_STACK_LINE(74)
		this->follow = false;
	}
return null();
}


Void CameraOrbit_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.component.CameraOrbit","OnStart",0xec7a7e5d,"haxor.component.CameraOrbit.OnStart","haxor/component/CameraOrbit.hx",79,0xdbbd8c58)
		HX_STACK_THIS(this)
		HX_STACK_LINE(80)
		this->m_distance = this->distance;
		HX_STACK_LINE(81)
		::haxor::math::Vector2 _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(81)
		if (((this->angle == null()))){
			HX_STACK_LINE(81)
			_g = ::haxor::math::Vector2_obj::__new((int)0,(int)0);
		}
		else{
			HX_STACK_LINE(81)
			::haxor::math::Vector2 _this = this->angle;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(81)
			_g = ::haxor::math::Vector2_obj::__new(_this->x,_this->y);
		}
		HX_STACK_LINE(81)
		this->m_angle = _g;
		HX_STACK_LINE(82)
		::haxor::math::Quaternion _g1 = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		this->m_rotation = _g1;
		HX_STACK_LINE(84)
		::haxor::math::Vector3 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(84)
		{
			HX_STACK_LINE(84)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(84)
			int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(84)
			p = _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
		}
		HX_STACK_LINE(85)
		p->Set((int)0,(int)0,this->m_distance);
		HX_STACK_LINE(86)
		this->m_entity->m_transform->set_localPosition(p);
	}
return null();
}


Void CameraOrbit_obj::OnUpdate( ){
{
		HX_STACK_FRAME("haxor.component.CameraOrbit","OnUpdate",0x7fbf37ae,"haxor.component.CameraOrbit.OnUpdate","haxor/component/CameraOrbit.hx",91,0xdbbd8c58)
		HX_STACK_THIS(this)
		HX_STACK_LINE(92)
		Float blend;		HX_STACK_VAR(blend,"blend");
		HX_STACK_LINE(92)
		if (((this->smooth <= (int)0))){
			HX_STACK_LINE(92)
			blend = 1.0;
		}
		else{
			HX_STACK_LINE(92)
			blend = (::haxor::core::Time_obj::m_delta * this->smooth);
		}
		HX_STACK_LINE(93)
		{
			HX_STACK_LINE(93)
			Float p_a = this->m_angle->x;		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(93)
			this->m_angle->x = (p_a + (((this->angle->x - p_a)) * blend));
		}
		HX_STACK_LINE(94)
		{
			HX_STACK_LINE(94)
			Float p_a = this->m_angle->y;		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(94)
			this->m_angle->y = (p_a + (((this->angle->y - p_a)) * blend));
		}
		HX_STACK_LINE(95)
		{
			HX_STACK_LINE(95)
			Float p_a = this->m_distance;		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(95)
			this->m_distance = (p_a + (((this->distance - p_a)) * blend));
		}
		HX_STACK_LINE(97)
		::haxor::math::Quaternion q;		HX_STACK_VAR(q,"q");
		HX_STACK_LINE(97)
		{
			HX_STACK_LINE(97)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(97)
			int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(97)
			q = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
		}
		HX_STACK_LINE(98)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)1,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(98)
		q->SetAxisAngle(_g1,this->m_angle->x);
		HX_STACK_LINE(99)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);		HX_STACK_VAR(_g3,"_g3");
		struct _Function_1_1{
			inline static ::haxor::math::Quaternion Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/CameraOrbit.hx",99,0xdbbd8c58)
				{
					HX_STACK_LINE(99)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(99)
					int _g2 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(99)
					return _this->m_q->__get(_g2).StaticCast< ::haxor::math::Quaternion >();
				}
				return null();
			}
		};
		HX_STACK_LINE(99)
		::haxor::math::Quaternion _g4 = (_Function_1_1::Block())->SetAxisAngle(_g3,-(this->m_angle->y));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(99)
		q->Multiply(_g4,null());
		HX_STACK_LINE(100)
		this->get_pivot()->set_localRotation(q);
		HX_STACK_LINE(102)
		::haxor::math::Vector3 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(102)
		{
			HX_STACK_LINE(102)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(102)
			int _g5 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(102)
			p = _this->m_v3->__get(_g5).StaticCast< ::haxor::math::Vector3 >();
		}
		HX_STACK_LINE(103)
		p->Set((int)0,(int)0,this->m_distance);
		HX_STACK_LINE(104)
		this->m_entity->m_transform->set_localPosition(p);
		HX_STACK_LINE(106)
		if (((this->target != null()))){
			HX_STACK_LINE(108)
			if ((this->follow)){
				HX_STACK_LINE(110)
				::haxor::math::Vector3 p1 = this->get_pivot()->get_localPosition();		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(111)
				::haxor::math::Vector3 _g6 = this->target->get_localPosition();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(111)
				::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::Lerp(p1,_g6,(::haxor::core::Time_obj::m_delta * this->smooth),null());		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(111)
				p1 = _g7;
				HX_STACK_LINE(112)
				this->get_pivot()->set_localPosition(p1);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraOrbit_obj,OnUpdate,(void))

::haxor::component::CameraOrbit CameraOrbit_obj::Create( hx::Null< Float >  __o_p_distance,hx::Null< Float >  __o_p_angle_x,hx::Null< Float >  __o_p_angle_y){
Float p_distance = __o_p_distance.Default(1);
Float p_angle_x = __o_p_angle_x.Default(0);
Float p_angle_y = __o_p_angle_y.Default(0);
	HX_STACK_FRAME("haxor.component.CameraOrbit","Create",0xf0f2eca2,"haxor.component.CameraOrbit.Create","haxor/component/CameraOrbit.hx",24,0xdbbd8c58)
	HX_STACK_ARG(p_distance,"p_distance")
	HX_STACK_ARG(p_angle_x,"p_angle_x")
	HX_STACK_ARG(p_angle_y,"p_angle_y")
{
		HX_STACK_LINE(25)
		::haxor::core::Entity e = ::haxor::core::Entity_obj::__new(null());		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(26)
		e->set_name(HX_CSTRING("camera_orbit"));
		HX_STACK_LINE(27)
		::haxor::component::Camera c = e->AddComponent(hx::ClassOf< ::haxor::component::Camera >());		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(28)
		::haxor::math::Color _g = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(28)
		c->background = _g;
		HX_STACK_LINE(29)
		::haxor::component::CameraOrbit orbit = e->AddComponent(hx::ClassOf< ::haxor::component::CameraOrbit >());		HX_STACK_VAR(orbit,"orbit");
		HX_STACK_LINE(30)
		orbit->distance = p_distance;
		HX_STACK_LINE(31)
		orbit->smooth = (int)0;
		HX_STACK_LINE(32)
		::haxor::math::Vector2 _g1 = ::haxor::math::Vector2_obj::__new(p_angle_x,p_angle_y);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(32)
		orbit->angle = _g1;
		HX_STACK_LINE(33)
		return orbit;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CameraOrbit_obj,Create,return )


CameraOrbit_obj::CameraOrbit_obj()
{
}

void CameraOrbit_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CameraOrbit);
	HX_MARK_MEMBER_NAME(m_pivot,"m_pivot");
	HX_MARK_MEMBER_NAME(distance,"distance");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(smooth,"smooth");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(follow,"follow");
	HX_MARK_MEMBER_NAME(m_angle,"m_angle");
	HX_MARK_MEMBER_NAME(m_distance,"m_distance");
	HX_MARK_MEMBER_NAME(m_rotation,"m_rotation");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CameraOrbit_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_pivot,"m_pivot");
	HX_VISIT_MEMBER_NAME(distance,"distance");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(smooth,"smooth");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(follow,"follow");
	HX_VISIT_MEMBER_NAME(m_angle,"m_angle");
	HX_VISIT_MEMBER_NAME(m_distance,"m_distance");
	HX_VISIT_MEMBER_NAME(m_rotation,"m_rotation");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CameraOrbit_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"pivot") ) { return get_pivot(); }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"smooth") ) { return smooth; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"follow") ) { return follow; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_pivot") ) { return m_pivot; }
		if (HX_FIELD_EQ(inName,"m_angle") ) { return m_angle; }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance; }
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_pivot") ) { return get_pivot_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_distance") ) { return m_distance; }
		if (HX_FIELD_EQ(inName,"m_rotation") ) { return m_rotation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CameraOrbit_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"smooth") ) { smooth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"follow") ) { follow=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_pivot") ) { m_pivot=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_angle") ) { m_angle=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { distance=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_distance") ) { m_distance=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_rotation") ) { m_rotation=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CameraOrbit_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pivot"));
	outFields->push(HX_CSTRING("m_pivot"));
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("smooth"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("follow"));
	outFields->push(HX_CSTRING("m_angle"));
	outFields->push(HX_CSTRING("m_distance"));
	outFields->push(HX_CSTRING("m_rotation"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(CameraOrbit_obj,m_pivot),HX_CSTRING("m_pivot")},
	{hx::fsFloat,(int)offsetof(CameraOrbit_obj,distance),HX_CSTRING("distance")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(CameraOrbit_obj,angle),HX_CSTRING("angle")},
	{hx::fsFloat,(int)offsetof(CameraOrbit_obj,smooth),HX_CSTRING("smooth")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(CameraOrbit_obj,target),HX_CSTRING("target")},
	{hx::fsBool,(int)offsetof(CameraOrbit_obj,follow),HX_CSTRING("follow")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(CameraOrbit_obj,m_angle),HX_CSTRING("m_angle")},
	{hx::fsFloat,(int)offsetof(CameraOrbit_obj,m_distance),HX_CSTRING("m_distance")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(CameraOrbit_obj,m_rotation),HX_CSTRING("m_rotation")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_pivot"),
	HX_CSTRING("m_pivot"),
	HX_CSTRING("distance"),
	HX_CSTRING("angle"),
	HX_CSTRING("smooth"),
	HX_CSTRING("target"),
	HX_CSTRING("follow"),
	HX_CSTRING("m_angle"),
	HX_CSTRING("m_distance"),
	HX_CSTRING("m_rotation"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnUpdate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CameraOrbit_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CameraOrbit_obj::__mClass,"__mClass");
};

#endif

Class CameraOrbit_obj::__mClass;

void CameraOrbit_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.CameraOrbit"), hx::TCanCast< CameraOrbit_obj> ,sStaticFields,sMemberFields,
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

void CameraOrbit_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
