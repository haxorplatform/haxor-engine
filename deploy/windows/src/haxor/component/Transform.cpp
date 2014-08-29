#include <hxcpp.h>

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
#ifndef INCLUDED_haxor_context_TransformContext
#include <haxor/context/TransformContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{

Void Transform_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.Transform","new",0xe78712a1,"haxor.component.Transform.new","haxor/component/Transform.hx",16,0x28912231)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(16)
	super::__construct(p_name);
}
;
	return null();
}

//Transform_obj::~Transform_obj() { }

Dynamic Transform_obj::__CreateEmpty() { return  new Transform_obj; }
hx::ObjectPtr< Transform_obj > Transform_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::math::Vector3 Transform_obj::get_right( ){
	HX_STACK_FRAME("haxor.component.Transform","get_right",0x14115134,"haxor.component.Transform.get_right","haxor/component/Transform.hx",30,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(30)
	if ((this->m_dirty)){
		HX_STACK_LINE(30)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(30)
	::haxor::math::Vector3 _this = this->m_right;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(30)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_right,return )

::haxor::math::Vector3 Transform_obj::set_right( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_right",0xf7623d40,"haxor.component.Transform.set_right","haxor/component/Transform.hx",31,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(31)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_right,return )

::haxor::math::Vector3 Transform_obj::get_up( ){
	HX_STACK_FRAME("haxor.component.Transform","get_up",0xc8e8da03,"haxor.component.Transform.get_up","haxor/component/Transform.hx",38,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	if ((this->m_dirty)){
		HX_STACK_LINE(38)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(38)
	::haxor::math::Vector3 _this = this->m_up;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(38)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_up,return )

::haxor::math::Vector3 Transform_obj::set_up( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_up",0x95312e77,"haxor.component.Transform.set_up","haxor/component/Transform.hx",39,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(39)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_up,return )

::haxor::math::Vector3 Transform_obj::get_forward( ){
	HX_STACK_FRAME("haxor.component.Transform","get_forward",0x0a562d1d,"haxor.component.Transform.get_forward","haxor/component/Transform.hx",46,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(46)
	if ((this->m_dirty)){
		HX_STACK_LINE(46)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(46)
	::haxor::math::Vector3 _this = this->m_forward;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(46)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z)->Invert();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_forward,return )

::haxor::math::Vector3 Transform_obj::set_forward( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_forward",0x14c33429,"haxor.component.Transform.set_forward","haxor/component/Transform.hx",47,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(47)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_forward,return )

::haxor::component::Transform Transform_obj::get_parent( ){
	HX_STACK_FRAME("haxor.component.Transform","get_parent",0x1a6d6cd2,"haxor.component.Transform.get_parent","haxor/component/Transform.hx",55,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_parent,return )

::haxor::component::Transform Transform_obj::set_parent( ::haxor::component::Transform v){
	HX_STACK_FRAME("haxor.component.Transform","set_parent",0x1deb0b46,"haxor.component.Transform.set_parent","haxor/component/Transform.hx",57,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(58)
	if (((this->m_parent != null()))){
		HX_STACK_LINE(58)
		this->m_parent->m_hierarchy->remove(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(59)
	if (((v == null()))){
		HX_STACK_LINE(59)
		this->m_parent = ::haxor::component::Transform_obj::m_root;
	}
	else{
		HX_STACK_LINE(59)
		this->m_parent = v;
	}
	HX_STACK_LINE(60)
	this->m_parent->m_hierarchy->push(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(61)
	::haxor::math::Vector3 ps = this->m_parent->get_scale();		HX_STACK_VAR(ps,"ps");
	HX_STACK_LINE(62)
	if (((ps->x <= 0.0))){
		HX_STACK_LINE(62)
		ps->x = 0.0;
	}
	else{
		HX_STACK_LINE(62)
		ps->x = (Float(1.0) / Float(ps->x));
	}
	HX_STACK_LINE(63)
	if (((ps->y <= 0.0))){
		HX_STACK_LINE(63)
		ps->y = 0.0;
	}
	else{
		HX_STACK_LINE(63)
		ps->y = (Float(1.0) / Float(ps->y));
	}
	HX_STACK_LINE(64)
	if (((ps->z <= 0.0))){
		HX_STACK_LINE(64)
		ps->z = 0.0;
	}
	else{
		HX_STACK_LINE(64)
		ps->z = (Float(1.0) / Float(ps->z));
	}
	HX_STACK_LINE(65)
	hx::MultEq(this->m_localScale->x,ps->x);
	HX_STACK_LINE(66)
	hx::MultEq(this->m_localScale->y,ps->y);
	HX_STACK_LINE(67)
	hx::MultEq(this->m_localScale->z,ps->z);
	HX_STACK_LINE(68)
	this->set_localScale(this->m_localScale);
	HX_STACK_LINE(69)
	return this->m_parent;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_parent,return )

int Transform_obj::get_childCount( ){
	HX_STACK_FRAME("haxor.component.Transform","get_childCount",0xba5f113b,"haxor.component.Transform.get_childCount","haxor/component/Transform.hx",77,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return this->m_hierarchy->length;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_childCount,return )

::haxor::math::Vector3 Transform_obj::get_position( ){
	HX_STACK_FRAME("haxor.component.Transform","get_position",0xa0514251,"haxor.component.Transform.get_position","haxor/component/Transform.hx",83,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(this->m_position->x,this->m_position->y,this->m_position->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_position,return )

::haxor::math::Vector3 Transform_obj::set_position( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_position",0xb54a65c5,"haxor.component.Transform.set_position","haxor/component/Transform.hx",85,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(86)
	Float dx = (v->x - this->m_position->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(86)
	Float dy = (v->y - this->m_position->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(86)
	Float dz = (v->z - this->m_position->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(87)
	Float _g = ::Math_obj::abs(dx);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(87)
	if (((_g < 0.0001))){
		HX_STACK_LINE(88)
		Float _g1 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(89)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(89)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(89)
				return v;
			}
		}
	}
	HX_STACK_LINE(90)
	this->Translate(dx,dy,dz);
	HX_STACK_LINE(91)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_position,return )

::haxor::math::Vector3 Transform_obj::get_localPosition( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localPosition",0xf7eb668c,"haxor.component.Transform.get_localPosition","haxor/component/Transform.hx",99,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(99)
	if (((this->m_parent == null()))){
		HX_STACK_LINE(99)
		return this->get_position();
	}
	HX_STACK_LINE(99)
	::haxor::math::Matrix4 wm = this->m_parent->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
	HX_STACK_LINE(99)
	::haxor::math::Matrix4 _this = this->m_parent->get_WorldMatrixInverse();		HX_STACK_VAR(_this,"_this");
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",99,0x28912231)
			{
				HX_STACK_LINE(99)
				::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(99)
				int _g = _this1->m_nv3 = hx::Mod(((_this1->m_nv3 + (int)1)),_this1->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(99)
				return _this1->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(99)
	::haxor::math::Vector3 p_point = (_Function_1_1::Block())->Set3(this->m_position);		HX_STACK_VAR(p_point,"p_point");
	HX_STACK_LINE(99)
	Float vx = ((((_this->m00 * p_point->x) + (_this->m01 * p_point->y)) + (_this->m02 * p_point->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(99)
	Float vy = ((((_this->m10 * p_point->x) + (_this->m11 * p_point->y)) + (_this->m12 * p_point->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(99)
	Float vz = ((((_this->m20 * p_point->x) + (_this->m21 * p_point->y)) + (_this->m22 * p_point->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(99)
	p_point->x = vx;
	HX_STACK_LINE(99)
	p_point->y = vy;
	HX_STACK_LINE(99)
	p_point->z = vz;
	HX_STACK_LINE(99)
	return p_point;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localPosition,return )

::haxor::math::Vector3 Transform_obj::set_localPosition( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localPosition",0x1b593e98,"haxor.component.Transform.set_localPosition","haxor/component/Transform.hx",100,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(100)
	if (((this->m_parent == null()))){
		HX_STACK_LINE(100)
		return v;
	}
	HX_STACK_LINE(100)
	::haxor::math::Vector3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		::haxor::math::Matrix4 _this = this->m_parent->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(100)
		Float vx = ((((_this->m00 * v->x) + (_this->m01 * v->y)) + (_this->m02 * v->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(100)
		Float vy = ((((_this->m10 * v->x) + (_this->m11 * v->y)) + (_this->m12 * v->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(100)
		Float vz = ((((_this->m20 * v->x) + (_this->m21 * v->y)) + (_this->m22 * v->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(100)
		v->x = vx;
		HX_STACK_LINE(100)
		v->y = vy;
		HX_STACK_LINE(100)
		v->z = vz;
		HX_STACK_LINE(100)
		_g = v;
	}
	HX_STACK_LINE(100)
	this->set_position(_g);
	HX_STACK_LINE(100)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localPosition,return )

::haxor::math::Vector3 Transform_obj::get_euler( ){
	HX_STACK_FRAME("haxor.component.Transform","get_euler",0x9fce1ec1,"haxor.component.Transform.get_euler","haxor/component/Transform.hx",107,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(107)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(this->m_euler->x,this->m_euler->y,this->m_euler->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_euler,return )

::haxor::math::Vector3 Transform_obj::set_euler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_euler",0x831f0acd,"haxor.component.Transform.set_euler","haxor/component/Transform.hx",109,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(110)
	Float dx = (v->x - this->m_euler->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(110)
	Float dy = (v->y - this->m_euler->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(110)
	Float dz = (v->z - this->m_euler->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(111)
	Float _g = ::Math_obj::abs(dx);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(111)
	if (((_g < 0.0001))){
		HX_STACK_LINE(112)
		Float _g1 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(112)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(113)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(113)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(113)
				return v;
			}
		}
	}
	HX_STACK_LINE(114)
	this->Rotate(dx,dy,dz);
	HX_STACK_LINE(115)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_euler,return )

::haxor::math::Vector3 Transform_obj::get_localEuler( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localEuler",0x7e94d7a6,"haxor.component.Transform.get_localEuler","haxor/component/Transform.hx",123,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	if (((this->m_parent == null()))){
		HX_STACK_LINE(123)
		return this->get_euler();
	}
	HX_STACK_LINE(123)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set((this->m_euler->x - this->m_parent->m_euler->x),(this->m_euler->y - this->m_parent->m_euler->y),(this->m_euler->z - this->m_parent->m_euler->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localEuler,return )

::haxor::math::Vector3 Transform_obj::set_localEuler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localEuler",0x9eb4c01a,"haxor.component.Transform.set_localEuler","haxor/component/Transform.hx",124,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(124)
	if (((this->m_parent == null()))){
		HX_STACK_LINE(124)
		return v;
	}
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",124,0x28912231)
			{
				HX_STACK_LINE(124)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(124)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(124)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(124)
	::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set3(this->m_parent->m_euler)->Add(v);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(124)
	this->set_euler(_g1);
	HX_STACK_LINE(124)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localEuler,return )

::haxor::math::Quaternion Transform_obj::get_rotation( ){
	HX_STACK_FRAME("haxor.component.Transform","get_rotation",0xdddcdee6,"haxor.component.Transform.get_rotation","haxor/component/Transform.hx",131,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(131)
	return ::haxor::math::Quaternion_obj::FromEuler(this->m_euler,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_rotation,return )

::haxor::math::Quaternion Transform_obj::set_rotation( ::haxor::math::Quaternion v){
	HX_STACK_FRAME("haxor.component.Transform","set_rotation",0xf2d6025a,"haxor.component.Transform.set_rotation","haxor/component/Transform.hx",132,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(132)
	::haxor::math::Vector3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(132)
	{
		HX_STACK_LINE(132)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(132)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(132)
		_g1 = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(132)
	::haxor::math::Vector3 _g2 = ::haxor::math::Quaternion_obj::ToEuler(v,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(132)
	this->set_euler(_g2);
	HX_STACK_LINE(132)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_rotation,return )

::haxor::math::Quaternion Transform_obj::get_localRotation( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localRotation",0x35770321,"haxor.component.Transform.get_localRotation","haxor/component/Transform.hx",138,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	if (((this->m_parent == null()))){
		HX_STACK_LINE(138)
		return this->get_rotation();
	}
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",138,0x28912231)
			{
				HX_STACK_LINE(138)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(138)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(138)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(138)
	::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set((this->m_euler->x - this->m_parent->m_euler->x),(this->m_euler->y - this->m_parent->m_euler->y),(this->m_euler->z - this->m_parent->m_euler->z));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(138)
	return ::haxor::math::Quaternion_obj::FromEuler(_g1,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localRotation,return )

::haxor::math::Quaternion Transform_obj::set_localRotation( ::haxor::math::Quaternion v){
	HX_STACK_FRAME("haxor.component.Transform","set_localRotation",0x58e4db2d,"haxor.component.Transform.set_localRotation","haxor/component/Transform.hx",139,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(139)
	::haxor::math::Vector3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(139)
	{
		HX_STACK_LINE(139)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(139)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(139)
		_g1 = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(139)
	::haxor::math::Vector3 _g2 = ::haxor::math::Quaternion_obj::ToEuler(v,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(139)
	this->set_localEuler(_g2);
	HX_STACK_LINE(139)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localRotation,return )

::haxor::math::Vector3 Transform_obj::get_scale( ){
	HX_STACK_FRAME("haxor.component.Transform","get_scale",0xa37c13e2,"haxor.component.Transform.get_scale","haxor/component/Transform.hx",146,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(147)
	if ((this->m_dirty)){
		HX_STACK_LINE(147)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(148)
	::haxor::math::Vector3 _this = this->m_scale;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(148)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_scale,return )

::haxor::math::Vector3 Transform_obj::get_localScale( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localScale",0x8242ccc7,"haxor.component.Transform.get_localScale","haxor/component/Transform.hx",163,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(163)
	::haxor::math::Vector3 _this = this->m_localScale;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(163)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localScale,return )

::haxor::math::Vector3 Transform_obj::set_localScale( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localScale",0xa262b53b,"haxor.component.Transform.set_localScale","haxor/component/Transform.hx",165,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(164)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(166)
	Float dx = (v->x - this->m_localScale->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(167)
	Float dy = (v->y - this->m_localScale->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(168)
	Float dz = (v->z - this->m_localScale->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(169)
	Float _g1 = ::Math_obj::abs(dx);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(169)
	if (((_g1 < 0.0001))){
		HX_STACK_LINE(170)
		Float _g11 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(170)
		if (((_g11 < 0.0001))){
			HX_STACK_LINE(171)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(171)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(171)
				return v;
			}
		}
	}
	HX_STACK_LINE(172)
	this->m_localScale->Set3(v);
	HX_STACK_LINE(173)
	Array< ::Dynamic > ps = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(ps,"ps");
	HX_STACK_LINE(175)
	::haxor::math::Vector3 _g4;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(175)
	if (((this->m_parent == null()))){
		struct _Function_2_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",175,0x28912231)
				{
					HX_STACK_LINE(175)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(175)
					int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(175)
					return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(175)
		_g4 = (_Function_2_1::Block())->Set((int)1,(int)1,(int)1);
	}
	else{
		HX_STACK_LINE(175)
		_g4 = this->m_parent->m_scale;
	}
	HX_STACK_LINE(175)
	ps[(int)0] = _g4;
	HX_STACK_LINE(176)
	this->m_scale->x = (this->m_localScale->x * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->x);
	HX_STACK_LINE(177)
	this->m_scale->y = (this->m_localScale->y * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->y);
	HX_STACK_LINE(178)
	this->m_scale->z = (this->m_localScale->z * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->z);

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,ps,Array< ::Dynamic >,_g)
	bool run(::haxor::component::Transform t,int d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/Transform.hx",181,0x28912231)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(182)
			if (((t == _g->__get((int)0).StaticCast< ::haxor::component::Transform >()))){
				HX_STACK_LINE(182)
				return true;
			}
			HX_STACK_LINE(183)
			::haxor::math::Vector3 pp;		HX_STACK_VAR(pp,"pp");
			HX_STACK_LINE(183)
			if (((t->m_parent == null()))){
				struct _Function_3_1{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",183,0x28912231)
						{
							HX_STACK_LINE(183)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(183)
							return _this->m_v3->__get(_this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length)).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(183)
				pp = (_Function_3_1::Block())->Set((int)0,(int)0,(int)0);
			}
			else{
				HX_STACK_LINE(183)
				pp = t->m_parent->m_position;
			}
			HX_STACK_LINE(184)
			if (((t->m_parent == null()))){
				struct _Function_3_1{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",184,0x28912231)
						{
							HX_STACK_LINE(184)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(184)
							return _this->m_v3->__get(_this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length)).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(184)
				ps[(int)0] = (_Function_3_1::Block())->Set((int)1,(int)1,(int)1);
			}
			else{
				HX_STACK_LINE(184)
				ps[(int)0] = t->m_parent->m_scale;
			}
			HX_STACK_LINE(185)
			t->m_scale->x = (t->m_localScale->x * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->x);
			HX_STACK_LINE(186)
			t->m_scale->y = (t->m_localScale->y * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->y);
			HX_STACK_LINE(187)
			t->m_scale->z = (t->m_localScale->z * ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >()->z);
			struct _Function_2_1{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",188,0x28912231)
					{
						HX_STACK_LINE(188)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(188)
						return _this->m_v3->__get(_this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length)).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(188)
			::haxor::math::Vector3 v1 = (_Function_2_1::Block())->Set3(t->m_position)->Sub(pp);		HX_STACK_VAR(v1,"v1");
			HX_STACK_LINE(189)
			v1->Multiply(ps->__get((int)0).StaticCast< ::haxor::math::Vector3 >());
			HX_STACK_LINE(190)
			v1->Add(pp);
			HX_STACK_LINE(191)
			t->set_position(v1);
			HX_STACK_LINE(193)
			t->m_dirty = true;
			HX_STACK_LINE(194)
			::haxor::context::EngineContext_obj::transform->OnChange(t);
			HX_STACK_LINE(196)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(180)
	this->Traverse( Dynamic(new _Function_1_1(ps,_g)));
	HX_STACK_LINE(198)
	::haxor::context::EngineContext_obj::transform->OnChange(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(199)
	this->m_dirty = true;
	HX_STACK_LINE(200)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localScale,return )

::haxor::math::Matrix4 Transform_obj::get_WorldMatrix( ){
	HX_STACK_FRAME("haxor.component.Transform","get_WorldMatrix",0xea38396b,"haxor.component.Transform.get_WorldMatrix","haxor/component/Transform.hx",209,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(209)
	if ((this->m_dirty)){
		HX_STACK_LINE(209)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(209)
	return this->m_worldMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_WorldMatrix,return )

::haxor::math::Matrix4 Transform_obj::get_WorldMatrixInverse( ){
	HX_STACK_FRAME("haxor.component.Transform","get_WorldMatrixInverse",0x7b890d85,"haxor.component.Transform.get_WorldMatrixInverse","haxor/component/Transform.hx",216,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(216)
	if ((this->m_dirty)){
		HX_STACK_LINE(216)
		this->UpdateWorldMatrix();
	}
	HX_STACK_LINE(216)
	return this->m_worldMatrixInverse;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_WorldMatrixInverse,return )

Void Transform_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Transform","OnBuild",0xfa819830,"haxor.component.Transform.OnBuild","haxor/component/Transform.hx",239,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(240)
		this->super::OnBuild();
		HX_STACK_LINE(242)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(242)
		{
			HX_STACK_LINE(242)
			::haxor::context::UID _this = ::haxor::context::EngineContext_obj::transform->tid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(242)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(242)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(242)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(242)
		this->__cid = _g;
		HX_STACK_LINE(243)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(243)
		this->m_position = _g1;
		HX_STACK_LINE(244)
		::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(244)
		this->m_euler = _g2;
		HX_STACK_LINE(245)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(245)
		this->m_localScale = _g3;
		HX_STACK_LINE(246)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(246)
		this->m_scale = _g4;
		HX_STACK_LINE(247)
		this->m_dirty = false;
		HX_STACK_LINE(248)
		this->m_uniform_dirty = true;
		HX_STACK_LINE(249)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(249)
		this->m_right = _g5;
		HX_STACK_LINE(250)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)0,(int)1,(int)0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(250)
		this->m_up = _g6;
		HX_STACK_LINE(251)
		::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::get_forward();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(251)
		this->m_forward = _g7;
		HX_STACK_LINE(253)
		::haxor::math::Matrix4 _g8 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(253)
		this->m_worldMatrixInverse = _g8;
		HX_STACK_LINE(254)
		::haxor::math::Matrix4 _g9 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(254)
		this->m_worldMatrix = _g9;
		HX_STACK_LINE(255)
		this->m_hierarchy = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(256)
		if (((::haxor::component::Transform_obj::m_root != null()))){
			HX_STACK_LINE(256)
			this->set_parent(null());
		}
		else{
			HX_STACK_LINE(256)
			::haxor::component::Transform_obj::m_root = hx::ObjectPtr<OBJ_>(this);
		}
	}
return null();
}


::haxor::component::Transform Transform_obj::Translate( Float p_dx,Float p_dy,Float p_dz){
	HX_STACK_FRAME("haxor.component.Transform","Translate",0xd256a02f,"haxor.component.Transform.Translate","haxor/component/Transform.hx",267,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_dx,"p_dx")
	HX_STACK_ARG(p_dy,"p_dy")
	HX_STACK_ARG(p_dz,"p_dz")
	HX_STACK_LINE(268)
	this->m_position->Add3(p_dx,p_dy,p_dz);
	HX_STACK_LINE(269)
	{
		HX_STACK_LINE(269)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(269)
		int _g = this->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(269)
		while((true)){
			HX_STACK_LINE(269)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(269)
				break;
			}
			HX_STACK_LINE(269)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(269)
			this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >()->Translate(p_dx,p_dy,p_dz);
		}
	}
	HX_STACK_LINE(270)
	this->m_dirty = true;
	HX_STACK_LINE(271)
	::haxor::context::EngineContext_obj::transform->OnChange(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(272)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC3(Transform_obj,Translate,return )

::haxor::component::Transform Transform_obj::Rotate( Float p_dx,Float p_dy,Float p_dz){
	HX_STACK_FRAME("haxor.component.Transform","Rotate",0x256d96da,"haxor.component.Transform.Rotate","haxor/component/Transform.hx",283,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_dx,"p_dx")
	HX_STACK_ARG(p_dy,"p_dy")
	HX_STACK_ARG(p_dz,"p_dz")
	HX_STACK_LINE(284)
	this->m_euler->Add3(p_dx,p_dy,p_dz);
	HX_STACK_LINE(286)
	{
		HX_STACK_LINE(286)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(286)
		int _g = this->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(286)
		while((true)){
			HX_STACK_LINE(286)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(286)
				break;
			}
			HX_STACK_LINE(286)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(288)
			::haxor::component::Transform c = this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >();		HX_STACK_VAR(c,"c");
			struct _Function_3_1{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",289,0x28912231)
					{
						HX_STACK_LINE(289)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(289)
						int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(289)
						return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(289)
			::haxor::math::Vector3 de = (_Function_3_1::Block())->Set(p_dx,p_dy,p_dz);		HX_STACK_VAR(de,"de");
			HX_STACK_LINE(290)
			::haxor::math::Quaternion _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(290)
			{
				HX_STACK_LINE(290)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(290)
				int _g11 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(290)
				_g2 = _this->m_q->__get(_g11).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(290)
			::haxor::math::Quaternion q = ::haxor::math::Quaternion_obj::FromEuler(de,_g2);		HX_STACK_VAR(q,"q");
			struct _Function_3_2{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",291,0x28912231)
					{
						HX_STACK_LINE(291)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(291)
						int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(291)
						return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(291)
			::haxor::math::Vector3 v = (_Function_3_2::Block())->Set3(c->m_position)->Sub(this->m_position);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(292)
			q->Rotate(v);
			HX_STACK_LINE(293)
			v->Add(this->m_position);
			HX_STACK_LINE(294)
			c->set_position(v);
			HX_STACK_LINE(295)
			c->Rotate(p_dx,p_dy,p_dz);
		}
	}
	HX_STACK_LINE(297)
	this->m_dirty = true;
	HX_STACK_LINE(298)
	::haxor::context::EngineContext_obj::transform->OnChange(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(299)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC3(Transform_obj,Rotate,return )

Void Transform_obj::RefreshWM( ){
{
		HX_STACK_FRAME("haxor.component.Transform","RefreshWM",0xa3465b92,"haxor.component.Transform.RefreshWM","haxor/component/Transform.hx",305,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(305)
		if ((this->m_dirty)){
			HX_STACK_LINE(305)
			this->UpdateWorldMatrix();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,RefreshWM,(void))

Void Transform_obj::UpdateWorldMatrix( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateWorldMatrix",0x3aab888b,"haxor.component.Transform.UpdateWorldMatrix","haxor/component/Transform.hx",311,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(312)
		::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(312)
		{
			HX_STACK_LINE(312)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(312)
			int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(312)
			_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
		}
		HX_STACK_LINE(312)
		::haxor::math::Quaternion q = ::haxor::math::Quaternion_obj::FromEuler(this->m_euler,_g1);		HX_STACK_VAR(q,"q");
		HX_STACK_LINE(314)
		Float sx = this->m_scale->x;		HX_STACK_VAR(sx,"sx");
		HX_STACK_LINE(314)
		Float sy = this->m_scale->y;		HX_STACK_VAR(sy,"sy");
		HX_STACK_LINE(314)
		Float sz = this->m_scale->z;		HX_STACK_VAR(sz,"sz");
		HX_STACK_LINE(315)
		Float px = this->m_position->x;		HX_STACK_VAR(px,"px");
		HX_STACK_LINE(315)
		Float py = this->m_position->y;		HX_STACK_VAR(py,"py");
		HX_STACK_LINE(315)
		Float pz = this->m_position->z;		HX_STACK_VAR(pz,"pz");
		HX_STACK_LINE(317)
		::haxor::math::Matrix4 _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(317)
		{
			HX_STACK_LINE(317)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(317)
			int _g2 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(317)
			_g3 = _this->m_m4->__get(_g2).StaticCast< ::haxor::math::Matrix4 >();
		}
		HX_STACK_LINE(317)
		::haxor::math::Matrix4 r = ::haxor::math::Matrix4_obj::FromQuaternion(q,_g3);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(319)
		this->m_right->Set(r->m00,r->m10,r->m20);
		HX_STACK_LINE(320)
		this->m_up->Set(r->m01,r->m11,r->m21);
		HX_STACK_LINE(321)
		this->m_forward->Set(r->m02,r->m12,r->m22);
		HX_STACK_LINE(323)
		::haxor::math::Matrix4 l = this->m_worldMatrix;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(324)
		l->m00 = (r->m00 * sx);
		HX_STACK_LINE(324)
		l->m01 = (r->m01 * sy);
		HX_STACK_LINE(324)
		l->m02 = (r->m02 * sz);
		HX_STACK_LINE(324)
		l->m03 = px;
		HX_STACK_LINE(325)
		l->m10 = (r->m10 * sx);
		HX_STACK_LINE(325)
		l->m11 = (r->m11 * sy);
		HX_STACK_LINE(325)
		l->m12 = (r->m12 * sz);
		HX_STACK_LINE(325)
		l->m13 = py;
		HX_STACK_LINE(326)
		l->m20 = (r->m20 * sx);
		HX_STACK_LINE(326)
		l->m21 = (r->m21 * sy);
		HX_STACK_LINE(326)
		l->m22 = (r->m22 * sz);
		HX_STACK_LINE(326)
		l->m23 = pz;
		HX_STACK_LINE(328)
		this->m_scale->x = sx;
		HX_STACK_LINE(329)
		this->m_scale->y = sy;
		HX_STACK_LINE(330)
		this->m_scale->z = sz;
		HX_STACK_LINE(332)
		::haxor::math::Matrix4_obj::GetInverseTransform(this->m_worldMatrix,this->m_worldMatrixInverse);
		HX_STACK_LINE(333)
		this->m_dirty = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateWorldMatrix,(void))

::haxor::component::Transform Transform_obj::GetChild( int p_index){
	HX_STACK_FRAME("haxor.component.Transform","GetChild",0x2a326765,"haxor.component.Transform.GetChild","haxor/component/Transform.hx",340,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(340)
	return this->m_hierarchy->__get(p_index).StaticCast< ::haxor::component::Transform >();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,GetChild,return )

::haxor::component::Transform Transform_obj::GetChildByName( ::String p_name){
	HX_STACK_FRAME("haxor.component.Transform","GetChildByName",0xa9542107,"haxor.component.Transform.GetChildByName","haxor/component/Transform.hx",347,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(348)
	{
		HX_STACK_LINE(348)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(348)
		int _g = this->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(348)
		while((true)){
			HX_STACK_LINE(348)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(348)
				break;
			}
			HX_STACK_LINE(348)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(348)
			::String _g2 = this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >()->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(348)
			if (((_g2 == p_name))){
				HX_STACK_LINE(348)
				return this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >();
			}
		}
	}
	HX_STACK_LINE(349)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,GetChildByName,return )

Void Transform_obj::Lock( ){
{
		HX_STACK_FRAME("haxor.component.Transform","Lock",0x98377eaa,"haxor.component.Transform.Lock","haxor/component/Transform.hx",356,0x28912231)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,Lock,(void))

Void Transform_obj::Unlock( ){
{
		HX_STACK_FRAME("haxor.component.Transform","Unlock",0xbfd9f343,"haxor.component.Transform.Unlock","haxor/component/Transform.hx",365,0x28912231)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,Unlock,(void))

::haxor::component::Transform Transform_obj::Navigate( ::String p_path){
	HX_STACK_FRAME("haxor.component.Transform","Navigate",0xc17f2d70,"haxor.component.Transform.Navigate","haxor/component/Transform.hx",376,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_path,"p_path")
	HX_STACK_LINE(377)
	Array< ::String > tk = p_path.split(HX_CSTRING("."));		HX_STACK_VAR(tk,"tk");
	HX_STACK_LINE(378)
	::haxor::component::Transform t = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(379)
	while((true)){
		HX_STACK_LINE(379)
		if ((!(((tk->length > (int)0))))){
			HX_STACK_LINE(379)
			break;
		}
		HX_STACK_LINE(381)
		::String p = tk->shift();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(382)
		::haxor::component::Transform _g = t->GetChildByName(p);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(382)
		t = _g;
		HX_STACK_LINE(383)
		if (((t == null()))){
			HX_STACK_LINE(383)
			return null();
		}
	}
	HX_STACK_LINE(385)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,Navigate,return )

::haxor::component::Transform Transform_obj::Search( ::String p_name,hx::Null< bool >  __o_p_exact){
bool p_exact = __o_p_exact.Default(true);
	HX_STACK_FRAME("haxor.component.Transform","Search",0xbd44efe7,"haxor.component.Transform.Search","haxor/component/Transform.hx",394,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_exact,"p_exact")
{
		HX_STACK_LINE(394)
		Array< bool > p_exact1 = Array_obj< bool >::__new().Add(p_exact);		HX_STACK_VAR(p_exact1,"p_exact1");
		HX_STACK_LINE(394)
		Array< ::String > p_name1 = Array_obj< ::String >::__new().Add(p_name);		HX_STACK_VAR(p_name1,"p_name1");
		HX_STACK_LINE(394)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(396)
		Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new().Add(null());		HX_STACK_VAR(res,"res");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< ::String >,p_name1,Array< ::Dynamic >,_g,Array< ::Dynamic >,res,Array< bool >,p_exact1)
		bool run(::haxor::component::Transform it,int d){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/Transform.hx",398,0x28912231)
			HX_STACK_ARG(it,"it")
			HX_STACK_ARG(d,"d")
			{
				HX_STACK_LINE(399)
				if (((it == _g->__get((int)0).StaticCast< ::haxor::component::Transform >()))){
					HX_STACK_LINE(399)
					return true;
				}
				HX_STACK_LINE(400)
				if (((res->__get((int)0).StaticCast< ::haxor::component::Transform >() != null()))){
					HX_STACK_LINE(400)
					return true;
				}
				HX_STACK_LINE(401)
				if ((p_exact1->__get((int)0))){
					HX_STACK_LINE(403)
					if (((it->get_name() == p_name1->__get((int)0)))){
						HX_STACK_LINE(403)
						res[(int)0] = it;
					}
				}
				else{
					HX_STACK_LINE(407)
					if (((it->get_name().indexOf(p_name1->__get((int)0),null()) >= (int)0))){
						HX_STACK_LINE(407)
						res[(int)0] = it;
					}
				}
				HX_STACK_LINE(409)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(397)
		this->Traverse( Dynamic(new _Function_1_1(p_name1,_g,res,p_exact1)));
		HX_STACK_LINE(411)
		return res->__get((int)0).StaticCast< ::haxor::component::Transform >();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Transform_obj,Search,return )

Array< ::Dynamic > Transform_obj::GetPathToRoot( ){
	HX_STACK_FRAME("haxor.component.Transform","GetPathToRoot",0x4d13a659,"haxor.component.Transform.GetPathToRoot","haxor/component/Transform.hx",419,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(420)
	::haxor::component::Transform p = this->m_parent;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(421)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(422)
	while((true)){
		HX_STACK_LINE(422)
		if ((!(((p != null()))))){
			HX_STACK_LINE(422)
			break;
		}
		HX_STACK_LINE(424)
		res->push(p);
		HX_STACK_LINE(425)
		p = p->m_parent;
	}
	HX_STACK_LINE(427)
	res->reverse();
	HX_STACK_LINE(428)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,GetPathToRoot,return )

::String Transform_obj::OutputHierarchy( ){
	HX_STACK_FRAME("haxor.component.Transform","OutputHierarchy",0x02eb15d5,"haxor.component.Transform.OutputHierarchy","haxor/component/Transform.hx",436,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(437)
	Array< int > d0 = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(d0,"d0");
	HX_STACK_LINE(438)
	Array< ::String > hs = Array_obj< ::String >::__new().Add(HX_CSTRING(""));		HX_STACK_VAR(hs,"hs");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::String >,hs,Array< int >,d0)
	bool run(::haxor::component::Transform t,int d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/Transform.hx",440,0x28912231)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(441)
			::String tab = HX_CSTRING("");		HX_STACK_VAR(tab,"tab");
			HX_STACK_LINE(442)
			int td = d;		HX_STACK_VAR(td,"td");
			HX_STACK_LINE(443)
			int d1 = ::Math_obj::max((int)0,(td - d0->__get((int)0)));		HX_STACK_VAR(d1,"d1");
			HX_STACK_LINE(444)
			{
				HX_STACK_LINE(444)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(444)
				while(((_g < d1))){
					HX_STACK_LINE(444)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(444)
					hx::AddEq(tab,HX_CSTRING(" "));
				}
			}
			HX_STACK_LINE(445)
			hx::AddEq(hs[(int)0],((((((tab + t->get_name()) + HX_CSTRING(" ")) + t->get_position()->ToString(null())) + t->get_rotation()->ToString(null())) + t->get_scale()->ToString(null())) + HX_CSTRING("\n")));
			HX_STACK_LINE(446)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(439)
	this->Traverse( Dynamic(new _Function_1_1(hs,d0)));
	HX_STACK_LINE(448)
	return hs->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,OutputHierarchy,return )

Void Transform_obj::Traverse( Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.component.Transform","Traverse",0xf10c2bf1,"haxor.component.Transform.Traverse","haxor/component/Transform.hx",456,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(456)
		this->TraverseStep(hx::ObjectPtr<OBJ_>(this),(int)0,p_callback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,Traverse,(void))

Void Transform_obj::TraverseStep( ::haxor::component::Transform p_child,int p_depth,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.component.Transform","TraverseStep",0x9cc48bdd,"haxor.component.Transform.TraverseStep","haxor/component/Transform.hx",463,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_child,"p_child")
		HX_STACK_ARG(p_depth,"p_depth")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(463)
		if ((p_callback(p_child,p_depth).Cast< bool >())){
			HX_STACK_LINE(463)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(463)
			int _g = p_child->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(463)
			while((true)){
				HX_STACK_LINE(463)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(463)
					break;
				}
				HX_STACK_LINE(463)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(463)
				::haxor::component::Transform _g2 = p_child->GetChild(i);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(463)
				this->TraverseStep(_g2,(p_depth + (int)1),p_callback);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Transform_obj,TraverseStep,(void))

Void Transform_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Transform","OnDestroy",0x8507ae7c,"haxor.component.Transform.OnDestroy","haxor/component/Transform.hx",470,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(470)
		int v = this->__cid;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(470)
		::haxor::context::EngineContext_obj::transform->tid->m_cache->push(v);
		HX_STACK_LINE(470)
		v;
	}
return null();
}


::String Transform_obj::ToString( hx::Null< bool >  __o_p_use_local,hx::Null< int >  __o_p_places){
bool p_use_local = __o_p_use_local.Default(false);
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.component.Transform","ToString",0xbd107eeb,"haxor.component.Transform.ToString","haxor/component/Transform.hx",479,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_use_local,"p_use_local")
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(480)
		::haxor::math::Vector3 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(480)
		if ((p_use_local)){
			HX_STACK_LINE(480)
			p = this->get_localPosition();
		}
		else{
			HX_STACK_LINE(480)
			p = this->m_position;
		}
		HX_STACK_LINE(481)
		::haxor::math::Vector3 e;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(481)
		if ((p_use_local)){
			HX_STACK_LINE(481)
			e = this->get_localEuler();
		}
		else{
			HX_STACK_LINE(481)
			e = this->m_euler;
		}
		HX_STACK_LINE(482)
		::haxor::math::Vector3 s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(482)
		if ((p_use_local)){
			HX_STACK_LINE(482)
			s = this->get_localScale();
		}
		else{
			HX_STACK_LINE(482)
			s = this->get_scale();
		}
		HX_STACK_LINE(483)
		::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(483)
		::String _g1 = (_g + HX_CSTRING(" "));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(483)
		::String _g2 = p->ToString(p_places);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(483)
		::String _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(483)
		::String _g4 = (_g3 + HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(483)
		::String _g5 = e->ToString(p_places);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(483)
		::String _g6 = (_g4 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(483)
		::String _g7 = (_g6 + HX_CSTRING(""));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(483)
		::String _g8 = s->ToString(p_places);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(483)
		return (_g7 + _g8);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Transform_obj,ToString,return )

::haxor::component::Transform Transform_obj::get_root( ){
	HX_STACK_FRAME("haxor.component.Transform","get_root",0x76599bca,"haxor.component.Transform.get_root","haxor/component/Transform.hx",23,0x28912231)
	HX_STACK_LINE(23)
	return ::haxor::component::Transform_obj::m_root;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_root,return )

::haxor::component::Transform Transform_obj::m_root;


Transform_obj::Transform_obj()
{
}

void Transform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Transform);
	HX_MARK_MEMBER_NAME(m_right,"m_right");
	HX_MARK_MEMBER_NAME(m_up,"m_up");
	HX_MARK_MEMBER_NAME(m_forward,"m_forward");
	HX_MARK_MEMBER_NAME(m_parent,"m_parent");
	HX_MARK_MEMBER_NAME(childCount,"childCount");
	HX_MARK_MEMBER_NAME(m_position,"m_position");
	HX_MARK_MEMBER_NAME(m_euler,"m_euler");
	HX_MARK_MEMBER_NAME(m_scale,"m_scale");
	HX_MARK_MEMBER_NAME(m_localScale,"m_localScale");
	HX_MARK_MEMBER_NAME(m_worldMatrix,"m_worldMatrix");
	HX_MARK_MEMBER_NAME(m_worldMatrixInverse,"m_worldMatrixInverse");
	HX_MARK_MEMBER_NAME(m_dirty,"m_dirty");
	HX_MARK_MEMBER_NAME(m_uniform_dirty,"m_uniform_dirty");
	HX_MARK_MEMBER_NAME(m_hierarchy,"m_hierarchy");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Transform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_right,"m_right");
	HX_VISIT_MEMBER_NAME(m_up,"m_up");
	HX_VISIT_MEMBER_NAME(m_forward,"m_forward");
	HX_VISIT_MEMBER_NAME(m_parent,"m_parent");
	HX_VISIT_MEMBER_NAME(childCount,"childCount");
	HX_VISIT_MEMBER_NAME(m_position,"m_position");
	HX_VISIT_MEMBER_NAME(m_euler,"m_euler");
	HX_VISIT_MEMBER_NAME(m_scale,"m_scale");
	HX_VISIT_MEMBER_NAME(m_localScale,"m_localScale");
	HX_VISIT_MEMBER_NAME(m_worldMatrix,"m_worldMatrix");
	HX_VISIT_MEMBER_NAME(m_worldMatrixInverse,"m_worldMatrixInverse");
	HX_VISIT_MEMBER_NAME(m_dirty,"m_dirty");
	HX_VISIT_MEMBER_NAME(m_uniform_dirty,"m_uniform_dirty");
	HX_VISIT_MEMBER_NAME(m_hierarchy,"m_hierarchy");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Transform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"up") ) { return get_up(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { return get_root(); }
		if (HX_FIELD_EQ(inName,"m_up") ) { return m_up; }
		if (HX_FIELD_EQ(inName,"Lock") ) { return Lock_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		if (HX_FIELD_EQ(inName,"euler") ) { return get_euler(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return get_scale(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_root") ) { return m_root; }
		if (HX_FIELD_EQ(inName,"get_up") ) { return get_up_dyn(); }
		if (HX_FIELD_EQ(inName,"set_up") ) { return set_up_dyn(); }
		if (HX_FIELD_EQ(inName,"parent") ) { return get_parent(); }
		if (HX_FIELD_EQ(inName,"Rotate") ) { return Rotate_dyn(); }
		if (HX_FIELD_EQ(inName,"Unlock") ) { return Unlock_dyn(); }
		if (HX_FIELD_EQ(inName,"Search") ) { return Search_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_right") ) { return m_right; }
		if (HX_FIELD_EQ(inName,"forward") ) { return get_forward(); }
		if (HX_FIELD_EQ(inName,"m_euler") ) { return m_euler; }
		if (HX_FIELD_EQ(inName,"m_scale") ) { return m_scale; }
		if (HX_FIELD_EQ(inName,"m_dirty") ) { return m_dirty; }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_root") ) { return get_root_dyn(); }
		if (HX_FIELD_EQ(inName,"m_parent") ) { return m_parent; }
		if (HX_FIELD_EQ(inName,"position") ) { return get_position(); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return get_rotation(); }
		if (HX_FIELD_EQ(inName,"GetChild") ) { return GetChild_dyn(); }
		if (HX_FIELD_EQ(inName,"Navigate") ) { return Navigate_dyn(); }
		if (HX_FIELD_EQ(inName,"Traverse") ) { return Traverse_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"m_forward") ) { return m_forward; }
		if (HX_FIELD_EQ(inName,"get_euler") ) { return get_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"set_euler") ) { return set_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scale") ) { return get_scale_dyn(); }
		if (HX_FIELD_EQ(inName,"Translate") ) { return Translate_dyn(); }
		if (HX_FIELD_EQ(inName,"RefreshWM") ) { return RefreshWM_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_parent") ) { return get_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_parent") ) { return set_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"childCount") ) { return inCallProp ? get_childCount() : childCount; }
		if (HX_FIELD_EQ(inName,"m_position") ) { return m_position; }
		if (HX_FIELD_EQ(inName,"localEuler") ) { return get_localEuler(); }
		if (HX_FIELD_EQ(inName,"localScale") ) { return get_localScale(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_forward") ) { return get_forward_dyn(); }
		if (HX_FIELD_EQ(inName,"set_forward") ) { return set_forward_dyn(); }
		if (HX_FIELD_EQ(inName,"WorldMatrix") ) { return get_WorldMatrix(); }
		if (HX_FIELD_EQ(inName,"m_hierarchy") ) { return m_hierarchy; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return set_position_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localScale") ) { return m_localScale; }
		if (HX_FIELD_EQ(inName,"TraverseStep") ) { return TraverseStep_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"localPosition") ) { return get_localPosition(); }
		if (HX_FIELD_EQ(inName,"localRotation") ) { return get_localRotation(); }
		if (HX_FIELD_EQ(inName,"m_worldMatrix") ) { return m_worldMatrix; }
		if (HX_FIELD_EQ(inName,"GetPathToRoot") ) { return GetPathToRoot_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_childCount") ) { return get_childCount_dyn(); }
		if (HX_FIELD_EQ(inName,"get_localEuler") ) { return get_localEuler_dyn(); }
		if (HX_FIELD_EQ(inName,"set_localEuler") ) { return set_localEuler_dyn(); }
		if (HX_FIELD_EQ(inName,"get_localScale") ) { return get_localScale_dyn(); }
		if (HX_FIELD_EQ(inName,"set_localScale") ) { return set_localScale_dyn(); }
		if (HX_FIELD_EQ(inName,"GetChildByName") ) { return GetChildByName_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_WorldMatrix") ) { return get_WorldMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"m_uniform_dirty") ) { return m_uniform_dirty; }
		if (HX_FIELD_EQ(inName,"OutputHierarchy") ) { return OutputHierarchy_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_localPosition") ) { return get_localPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"set_localPosition") ) { return set_localPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"get_localRotation") ) { return get_localRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_localRotation") ) { return set_localRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateWorldMatrix") ) { return UpdateWorldMatrix_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"WorldMatrixInverse") ) { return get_WorldMatrixInverse(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"m_worldMatrixInverse") ) { return m_worldMatrixInverse; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"get_WorldMatrixInverse") ) { return get_WorldMatrixInverse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_up") ) { m_up=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"euler") ) { return set_euler(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_root") ) { m_root=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { return set_parent(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_right") ) { m_right=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_euler") ) { m_euler=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_scale") ) { m_scale=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_dirty") ) { m_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_parent") ) { m_parent=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { return set_position(inValue); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return set_rotation(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_forward") ) { m_forward=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"childCount") ) { childCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_position") ) { m_position=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localEuler") ) { return set_localEuler(inValue); }
		if (HX_FIELD_EQ(inName,"localScale") ) { return set_localScale(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_hierarchy") ) { m_hierarchy=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localScale") ) { m_localScale=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"localPosition") ) { return set_localPosition(inValue); }
		if (HX_FIELD_EQ(inName,"localRotation") ) { return set_localRotation(inValue); }
		if (HX_FIELD_EQ(inName,"m_worldMatrix") ) { m_worldMatrix=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_uniform_dirty") ) { m_uniform_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"m_worldMatrixInverse") ) { m_worldMatrixInverse=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("m_right"));
	outFields->push(HX_CSTRING("up"));
	outFields->push(HX_CSTRING("m_up"));
	outFields->push(HX_CSTRING("forward"));
	outFields->push(HX_CSTRING("m_forward"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("m_parent"));
	outFields->push(HX_CSTRING("childCount"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("m_position"));
	outFields->push(HX_CSTRING("localPosition"));
	outFields->push(HX_CSTRING("euler"));
	outFields->push(HX_CSTRING("m_euler"));
	outFields->push(HX_CSTRING("localEuler"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("localRotation"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("m_scale"));
	outFields->push(HX_CSTRING("localScale"));
	outFields->push(HX_CSTRING("m_localScale"));
	outFields->push(HX_CSTRING("WorldMatrix"));
	outFields->push(HX_CSTRING("m_worldMatrix"));
	outFields->push(HX_CSTRING("WorldMatrixInverse"));
	outFields->push(HX_CSTRING("m_worldMatrixInverse"));
	outFields->push(HX_CSTRING("m_dirty"));
	outFields->push(HX_CSTRING("m_uniform_dirty"));
	outFields->push(HX_CSTRING("m_hierarchy"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("get_root"),
	HX_CSTRING("m_root"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_right),HX_CSTRING("m_right")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_up),HX_CSTRING("m_up")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_forward),HX_CSTRING("m_forward")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Transform_obj,m_parent),HX_CSTRING("m_parent")},
	{hx::fsInt,(int)offsetof(Transform_obj,childCount),HX_CSTRING("childCount")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_position),HX_CSTRING("m_position")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_euler),HX_CSTRING("m_euler")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_scale),HX_CSTRING("m_scale")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_localScale),HX_CSTRING("m_localScale")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Transform_obj,m_worldMatrix),HX_CSTRING("m_worldMatrix")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Transform_obj,m_worldMatrixInverse),HX_CSTRING("m_worldMatrixInverse")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_dirty),HX_CSTRING("m_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_uniform_dirty),HX_CSTRING("m_uniform_dirty")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Transform_obj,m_hierarchy),HX_CSTRING("m_hierarchy")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_right"),
	HX_CSTRING("set_right"),
	HX_CSTRING("m_right"),
	HX_CSTRING("get_up"),
	HX_CSTRING("set_up"),
	HX_CSTRING("m_up"),
	HX_CSTRING("get_forward"),
	HX_CSTRING("set_forward"),
	HX_CSTRING("m_forward"),
	HX_CSTRING("get_parent"),
	HX_CSTRING("set_parent"),
	HX_CSTRING("m_parent"),
	HX_CSTRING("childCount"),
	HX_CSTRING("get_childCount"),
	HX_CSTRING("get_position"),
	HX_CSTRING("set_position"),
	HX_CSTRING("m_position"),
	HX_CSTRING("get_localPosition"),
	HX_CSTRING("set_localPosition"),
	HX_CSTRING("get_euler"),
	HX_CSTRING("set_euler"),
	HX_CSTRING("m_euler"),
	HX_CSTRING("get_localEuler"),
	HX_CSTRING("set_localEuler"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("get_localRotation"),
	HX_CSTRING("set_localRotation"),
	HX_CSTRING("get_scale"),
	HX_CSTRING("m_scale"),
	HX_CSTRING("get_localScale"),
	HX_CSTRING("set_localScale"),
	HX_CSTRING("m_localScale"),
	HX_CSTRING("get_WorldMatrix"),
	HX_CSTRING("m_worldMatrix"),
	HX_CSTRING("get_WorldMatrixInverse"),
	HX_CSTRING("m_worldMatrixInverse"),
	HX_CSTRING("m_dirty"),
	HX_CSTRING("m_uniform_dirty"),
	HX_CSTRING("m_hierarchy"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("Translate"),
	HX_CSTRING("Rotate"),
	HX_CSTRING("RefreshWM"),
	HX_CSTRING("UpdateWorldMatrix"),
	HX_CSTRING("GetChild"),
	HX_CSTRING("GetChildByName"),
	HX_CSTRING("Lock"),
	HX_CSTRING("Unlock"),
	HX_CSTRING("Navigate"),
	HX_CSTRING("Search"),
	HX_CSTRING("GetPathToRoot"),
	HX_CSTRING("OutputHierarchy"),
	HX_CSTRING("Traverse"),
	HX_CSTRING("TraverseStep"),
	HX_CSTRING("OnDestroy"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Transform_obj::m_root,"m_root");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Transform_obj::m_root,"m_root");
};

#endif

Class Transform_obj::__mClass;

void Transform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Transform"), hx::TCanCast< Transform_obj> ,sStaticFields,sMemberFields,
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

void Transform_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
