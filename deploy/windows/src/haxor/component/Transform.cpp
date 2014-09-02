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
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
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
HX_STACK_FRAME("haxor.component.Transform","new",0xe78712a1,"haxor.component.Transform.new","haxor/component/Transform.hx",17,0x28912231)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(17)
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
	HX_STACK_FRAME("haxor.component.Transform","get_right",0x14115134,"haxor.component.Transform.get_right","haxor/component/Transform.hx",61,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(61)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(61)
	::haxor::math::Vector3 _this = this->m_right;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(61)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_right,return )

::haxor::math::Vector3 Transform_obj::set_right( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_right",0xf7623d40,"haxor.component.Transform.set_right","haxor/component/Transform.hx",62,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(62)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_right,return )

::haxor::math::Vector3 Transform_obj::get_up( ){
	HX_STACK_FRAME("haxor.component.Transform","get_up",0xc8e8da03,"haxor.component.Transform.get_up","haxor/component/Transform.hx",69,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(69)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(69)
	::haxor::math::Vector3 _this = this->m_up;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(69)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_up,return )

::haxor::math::Vector3 Transform_obj::set_up( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_up",0x95312e77,"haxor.component.Transform.set_up","haxor/component/Transform.hx",70,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(70)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_up,return )

::haxor::math::Vector3 Transform_obj::get_forward( ){
	HX_STACK_FRAME("haxor.component.Transform","get_forward",0x0a562d1d,"haxor.component.Transform.get_forward","haxor/component/Transform.hx",77,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(77)
	::haxor::math::Vector3 _this = this->m_forward;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(77)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z)->Invert();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_forward,return )

::haxor::math::Vector3 Transform_obj::set_forward( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_forward",0x14c33429,"haxor.component.Transform.set_forward","haxor/component/Transform.hx",78,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(78)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_forward,return )

::haxor::component::Transform Transform_obj::get_parent( ){
	HX_STACK_FRAME("haxor.component.Transform","get_parent",0x1a6d6cd2,"haxor.component.Transform.get_parent","haxor/component/Transform.hx",86,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(86)
	return this->m_parent;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_parent,return )

::haxor::component::Transform Transform_obj::set_parent( ::haxor::component::Transform v){
	HX_STACK_FRAME("haxor.component.Transform","set_parent",0x1deb0b46,"haxor.component.Transform.set_parent","haxor/component/Transform.hx",88,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(90)
	::haxor::math::Vector3 wp = this->get_position();		HX_STACK_VAR(wp,"wp");
	HX_STACK_LINE(91)
	::haxor::math::Quaternion wr = this->get_rotation();		HX_STACK_VAR(wr,"wr");
	HX_STACK_LINE(92)
	::haxor::math::Vector3 ws = this->get_scale();		HX_STACK_VAR(ws,"ws");
	HX_STACK_LINE(94)
	if (((this->m_parent != null()))){
		HX_STACK_LINE(94)
		this->m_parent->m_hierarchy->remove(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(95)
	if (((v == null()))){
		HX_STACK_LINE(95)
		this->m_parent = ::haxor::component::Transform_obj::m_root;
	}
	else{
		HX_STACK_LINE(95)
		this->m_parent = v;
	}
	HX_STACK_LINE(96)
	this->m_parent->m_hierarchy->push(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(103)
	return this->m_parent;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_parent,return )

int Transform_obj::get_childCount( ){
	HX_STACK_FRAME("haxor.component.Transform","get_childCount",0xba5f113b,"haxor.component.Transform.get_childCount","haxor/component/Transform.hx",111,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(111)
	return this->m_hierarchy->length;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_childCount,return )

::haxor::math::Vector3 Transform_obj::get_localPosition( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localPosition",0xf7eb668c,"haxor.component.Transform.get_localPosition","haxor/component/Transform.hx",117,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(117)
	::haxor::math::Vector3 _this = this->m_localPosition;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(117)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localPosition,return )

::haxor::math::Vector3 Transform_obj::set_localPosition( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localPosition",0x1b593e98,"haxor.component.Transform.set_localPosition","haxor/component/Transform.hx",119,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(120)
	Float dx = (v->x - this->m_localPosition->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(120)
	Float dy = (v->y - this->m_localPosition->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(120)
	Float dz = (v->z - this->m_localPosition->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(121)
	Float _g = ::Math_obj::abs(dx);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(121)
	if (((_g < 0.0001))){
		HX_STACK_LINE(121)
		Float _g1 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(121)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(121)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(121)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(121)
				return v;
			}
		}
	}
	HX_STACK_LINE(122)
	this->m_localPosition->Set3(v);
	HX_STACK_LINE(122)
	this->m_lmt_dirty = true;
	HX_STACK_LINE(123)
	this->Invalidate();
	HX_STACK_LINE(124)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localPosition,return )

::haxor::math::Quaternion Transform_obj::get_localRotation( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localRotation",0x35770321,"haxor.component.Transform.get_localRotation","haxor/component/Transform.hx",132,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(132)
	::haxor::math::Quaternion _this = this->m_localRotation;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(132)
	return ::haxor::math::Quaternion_obj::__new(_this->x,_this->y,_this->z,_this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localRotation,return )

::haxor::math::Quaternion Transform_obj::set_localRotation( ::haxor::math::Quaternion v){
	HX_STACK_FRAME("haxor.component.Transform","set_localRotation",0x58e4db2d,"haxor.component.Transform.set_localRotation","haxor/component/Transform.hx",134,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(135)
	Float dx = (v->x - this->m_localRotation->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(135)
	Float dy = (v->y - this->m_localRotation->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(135)
	Float dz = (v->z - this->m_localRotation->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(135)
	Float dw = (v->w - this->m_localRotation->w);		HX_STACK_VAR(dw,"dw");
	HX_STACK_LINE(136)
	Float _g = ::Math_obj::abs(dx);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(136)
	if (((_g < 0.0001))){
		HX_STACK_LINE(136)
		Float _g1 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(136)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(136)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(136)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(136)
				Float _g3 = ::Math_obj::abs(dw);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(136)
				if (((_g3 < 0.0001))){
					HX_STACK_LINE(136)
					return v;
				}
			}
		}
	}
	HX_STACK_LINE(137)
	this->m_localRotation->SetQuaternion(v);
	HX_STACK_LINE(137)
	this->m_lmrs_dirty = true;
	HX_STACK_LINE(138)
	this->Invalidate();
	HX_STACK_LINE(139)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localRotation,return )

::haxor::math::Vector3 Transform_obj::get_localEuler( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localEuler",0x7e94d7a6,"haxor.component.Transform.get_localEuler","haxor/component/Transform.hx",147,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(147)
	return this->m_localRotation->get_euler();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localEuler,return )

::haxor::math::Vector3 Transform_obj::set_localEuler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localEuler",0x9eb4c01a,"haxor.component.Transform.set_localEuler","haxor/component/Transform.hx",148,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(148)
	::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(148)
	{
		HX_STACK_LINE(148)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(148)
		int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(148)
		_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
	}
	HX_STACK_LINE(148)
	::haxor::math::Quaternion _g2 = ::haxor::math::Quaternion_obj::FromEuler(v,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(148)
	this->set_localRotation(_g2);
	HX_STACK_LINE(148)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localEuler,return )

::haxor::math::Vector3 Transform_obj::get_localScale( ){
	HX_STACK_FRAME("haxor.component.Transform","get_localScale",0x8242ccc7,"haxor.component.Transform.get_localScale","haxor/component/Transform.hx",155,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(155)
	::haxor::math::Vector3 _this = this->m_localScale;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(155)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_localScale,return )

::haxor::math::Vector3 Transform_obj::set_localScale( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_localScale",0xa262b53b,"haxor.component.Transform.set_localScale","haxor/component/Transform.hx",157,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(158)
	Float dx = (v->x - this->m_localScale->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(158)
	Float dy = (v->y - this->m_localScale->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(158)
	Float dz = (v->z - this->m_localScale->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(159)
	Float _g = ::Math_obj::abs(dx);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(159)
	if (((_g < 0.0001))){
		HX_STACK_LINE(159)
		Float _g1 = ::Math_obj::abs(dy);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(159)
		if (((_g1 < 0.0001))){
			HX_STACK_LINE(159)
			Float _g2 = ::Math_obj::abs(dz);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(159)
			if (((_g2 < 0.0001))){
				HX_STACK_LINE(159)
				return v;
			}
		}
	}
	HX_STACK_LINE(160)
	this->m_localScale->Set3(v);
	HX_STACK_LINE(160)
	this->m_lmrs_dirty = true;
	HX_STACK_LINE(161)
	this->Invalidate();
	HX_STACK_LINE(162)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_localScale,return )

::haxor::math::Vector3 Transform_obj::get_position( ){
	HX_STACK_FRAME("haxor.component.Transform","get_position",0xa0514251,"haxor.component.Transform.get_position","haxor/component/Transform.hx",170,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(170)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(170)
	this->UpdateWSP();
	HX_STACK_LINE(170)
	::haxor::math::Vector3 _this = this->m_position;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(170)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_position,return )

::haxor::math::Vector3 Transform_obj::set_position( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_position",0xb54a65c5,"haxor.component.Transform.set_position","haxor/component/Transform.hx",171,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(171)
	::haxor::math::Vector3 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(171)
	{
		HX_STACK_LINE(171)
		::haxor::math::Matrix4 _this = this->m_parent->get_WorldMatrixInverse();		HX_STACK_VAR(_this,"_this");
		struct _Function_2_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",171,0x28912231)
				{
					HX_STACK_LINE(171)
					::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
					HX_STACK_LINE(171)
					int _g = _this1->m_nv3 = hx::Mod(((_this1->m_nv3 + (int)1)),_this1->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(171)
					return _this1->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(171)
		::haxor::math::Vector3 p_point = (_Function_2_1::Block())->Set3(v);		HX_STACK_VAR(p_point,"p_point");
		HX_STACK_LINE(171)
		Float vx = ((((_this->m00 * p_point->x) + (_this->m01 * p_point->y)) + (_this->m02 * p_point->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(171)
		Float vy = ((((_this->m10 * p_point->x) + (_this->m11 * p_point->y)) + (_this->m12 * p_point->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(171)
		Float vz = ((((_this->m20 * p_point->x) + (_this->m21 * p_point->y)) + (_this->m22 * p_point->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(171)
		p_point->x = vx;
		HX_STACK_LINE(171)
		p_point->y = vy;
		HX_STACK_LINE(171)
		p_point->z = vz;
		HX_STACK_LINE(171)
		_g1 = p_point;
	}
	HX_STACK_LINE(171)
	this->set_localPosition(_g1);
	HX_STACK_LINE(171)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_position,return )

::haxor::math::Quaternion Transform_obj::get_rotation( ){
	HX_STACK_FRAME("haxor.component.Transform","get_rotation",0xdddcdee6,"haxor.component.Transform.get_rotation","haxor/component/Transform.hx",178,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(178)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(178)
	this->UpdateWSRS();
	HX_STACK_LINE(178)
	::haxor::math::Quaternion _this = this->m_rotation;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(178)
	return ::haxor::math::Quaternion_obj::__new(_this->x,_this->y,_this->z,_this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_rotation,return )

::haxor::math::Quaternion Transform_obj::set_rotation( ::haxor::math::Quaternion v){
	HX_STACK_FRAME("haxor.component.Transform","set_rotation",0xf2d6025a,"haxor.component.Transform.set_rotation","haxor/component/Transform.hx",180,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(181)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(182)
	this->UpdateWSRS();
	HX_STACK_LINE(183)
	::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(183)
	{
		HX_STACK_LINE(183)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(183)
		int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(183)
		_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
	}
	HX_STACK_LINE(183)
	::haxor::math::Quaternion iq = ::haxor::math::Quaternion_obj::Inverse(this->m_rotation,_g1);		HX_STACK_VAR(iq,"iq");
	struct _Function_1_1{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",184,0x28912231)
			{
				HX_STACK_LINE(184)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(184)
				int _g2 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(184)
				return _this->m_q->__get(_g2).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(184)
	::haxor::math::Quaternion _g3 = (_Function_1_1::Block())->SetQuaternion(v)->Multiply(iq,null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(184)
	this->set_localRotation(_g3);
	HX_STACK_LINE(185)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_rotation,return )

::haxor::math::Vector3 Transform_obj::get_euler( ){
	HX_STACK_FRAME("haxor.component.Transform","get_euler",0x9fce1ec1,"haxor.component.Transform.get_euler","haxor/component/Transform.hx",193,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(193)
	return this->get_rotation()->get_euler();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_euler,return )

::haxor::math::Vector3 Transform_obj::set_euler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.Transform","set_euler",0x831f0acd,"haxor.component.Transform.set_euler","haxor/component/Transform.hx",194,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(194)
	::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(194)
	{
		HX_STACK_LINE(194)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(194)
		int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(194)
		_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
	}
	HX_STACK_LINE(194)
	::haxor::math::Quaternion _g2 = ::haxor::math::Quaternion_obj::FromEuler(v,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(194)
	this->set_rotation(_g2);
	HX_STACK_LINE(194)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,set_euler,return )

::haxor::math::Vector3 Transform_obj::get_scale( ){
	HX_STACK_FRAME("haxor.component.Transform","get_scale",0xa37c13e2,"haxor.component.Transform.get_scale","haxor/component/Transform.hx",200,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(200)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(200)
	this->UpdateWSRS();
	HX_STACK_LINE(200)
	::haxor::math::Vector3 _this = this->m_scale;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(200)
	return ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_scale,return )

::haxor::math::Matrix4 Transform_obj::get_WorldMatrix( ){
	HX_STACK_FRAME("haxor.component.Transform","get_WorldMatrix",0xea38396b,"haxor.component.Transform.get_WorldMatrix","haxor/component/Transform.hx",207,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(207)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(207)
	return this->m_worldMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_WorldMatrix,return )

::haxor::math::Matrix4 Transform_obj::get_WorldMatrixInverse( ){
	HX_STACK_FRAME("haxor.component.Transform","get_WorldMatrixInverse",0x7b890d85,"haxor.component.Transform.get_WorldMatrixInverse","haxor/component/Transform.hx",214,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(214)
	this->UpdateWorldMatrix();
	HX_STACK_LINE(214)
	if ((this->m_inverse_dirty)){
		HX_STACK_LINE(214)
		::haxor::math::Matrix4_obj::GetInverseTransform(this->m_worldMatrix,this->m_worldMatrixInverse);
		HX_STACK_LINE(214)
		this->m_inverse_dirty = false;
	}
	HX_STACK_LINE(214)
	return this->m_worldMatrixInverse;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,get_WorldMatrixInverse,return )

Void Transform_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Transform","OnBuild",0xfa819830,"haxor.component.Transform.OnBuild","haxor/component/Transform.hx",267,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(268)
		this->super::OnBuild();
		HX_STACK_LINE(270)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(270)
		{
			HX_STACK_LINE(270)
			::haxor::context::UID _this = ::haxor::context::EngineContext_obj::transform->tid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(270)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(270)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(270)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(270)
		this->__cid = _g;
		HX_STACK_LINE(271)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(271)
		this->m_localPosition = _g1;
		HX_STACK_LINE(272)
		::haxor::math::Quaternion _g2 = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(272)
		this->m_localRotation = _g2;
		HX_STACK_LINE(273)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(273)
		this->m_localScale = _g3;
		HX_STACK_LINE(275)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(275)
		this->m_position = _g4;
		HX_STACK_LINE(276)
		::haxor::math::Quaternion _g5 = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(276)
		this->m_rotation = _g5;
		HX_STACK_LINE(277)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(277)
		this->m_scale = _g6;
		HX_STACK_LINE(279)
		this->m_lmt_dirty = false;
		HX_STACK_LINE(280)
		this->m_lmrs_dirty = false;
		HX_STACK_LINE(281)
		this->m_dirty = false;
		HX_STACK_LINE(282)
		this->m_inverse_dirty = false;
		HX_STACK_LINE(283)
		this->m_wsp_dirty = false;
		HX_STACK_LINE(284)
		this->m_wsrs_dirty = false;
		HX_STACK_LINE(287)
		this->m_uniform_dirty = true;
		HX_STACK_LINE(289)
		::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(289)
		this->m_right = _g7;
		HX_STACK_LINE(290)
		::haxor::math::Vector3 _g8 = ::haxor::math::Vector3_obj::__new((int)0,(int)1,(int)0);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(290)
		this->m_up = _g8;
		HX_STACK_LINE(291)
		::haxor::math::Vector3 _g9 = ::haxor::math::Vector3_obj::get_forward();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(291)
		this->m_forward = _g9;
		HX_STACK_LINE(292)
		::haxor::math::Matrix4 _g10 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(292)
		this->m_localMatrix = _g10;
		HX_STACK_LINE(293)
		::haxor::math::Matrix4 _g11 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(293)
		this->m_worldMatrixInverse = _g11;
		HX_STACK_LINE(294)
		::haxor::math::Matrix4 _g12 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(294)
		this->m_worldMatrix = _g12;
		HX_STACK_LINE(295)
		this->m_hierarchy = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(296)
		if (((::haxor::component::Transform_obj::m_root != null()))){
			HX_STACK_LINE(296)
			this->set_parent(null());
		}
		else{
			HX_STACK_LINE(296)
			::haxor::component::Transform_obj::m_root = hx::ObjectPtr<OBJ_>(this);
		}
	}
return null();
}


Void Transform_obj::UpdateLMT( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateLMT",0x0bb5dd2b,"haxor.component.Transform.UpdateLMT","haxor/component/Transform.hx",303,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(304)
		this->m_localMatrix->m03 = this->m_localPosition->x;
		HX_STACK_LINE(305)
		this->m_localMatrix->m13 = this->m_localPosition->y;
		HX_STACK_LINE(306)
		this->m_localMatrix->m23 = this->m_localPosition->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateLMT,(void))

Void Transform_obj::UpdateWSP( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateWSP",0x0bbe3b2c,"haxor.component.Transform.UpdateWSP","haxor/component/Transform.hx",314,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(314)
		if ((this->m_wsp_dirty)){
			HX_STACK_LINE(316)
			this->m_position->x = this->m_worldMatrix->m03;
			HX_STACK_LINE(317)
			this->m_position->y = this->m_worldMatrix->m13;
			HX_STACK_LINE(318)
			this->m_position->z = this->m_worldMatrix->m23;
			HX_STACK_LINE(319)
			this->m_wsp_dirty = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateWSP,(void))

Void Transform_obj::UpdateLMRS( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateLMRS",0x336ba70a,"haxor.component.Transform.UpdateLMRS","haxor/component/Transform.hx",327,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(328)
		Float sx = this->m_localScale->x;		HX_STACK_VAR(sx,"sx");
		HX_STACK_LINE(329)
		Float sy = this->m_localScale->y;		HX_STACK_VAR(sy,"sy");
		HX_STACK_LINE(330)
		Float sz = this->m_localScale->z;		HX_STACK_VAR(sz,"sz");
		HX_STACK_LINE(331)
		::haxor::math::Matrix4 _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(331)
		{
			HX_STACK_LINE(331)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(331)
			int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(331)
			_g1 = _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
		}
		HX_STACK_LINE(331)
		::haxor::math::Matrix4 r = ::haxor::math::Matrix4_obj::FromQuaternion(this->m_localRotation,_g1);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(332)
		::haxor::math::Matrix4 l = this->m_localMatrix;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(333)
		l->m00 = (r->m00 * sx);
		HX_STACK_LINE(333)
		l->m01 = (r->m01 * sy);
		HX_STACK_LINE(333)
		l->m02 = (r->m02 * sz);
		HX_STACK_LINE(334)
		l->m10 = (r->m10 * sx);
		HX_STACK_LINE(334)
		l->m11 = (r->m11 * sy);
		HX_STACK_LINE(334)
		l->m12 = (r->m12 * sz);
		HX_STACK_LINE(335)
		l->m20 = (r->m20 * sx);
		HX_STACK_LINE(335)
		l->m21 = (r->m21 * sy);
		HX_STACK_LINE(335)
		l->m22 = (r->m22 * sz);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateLMRS,(void))

Void Transform_obj::UpdateWSRS( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateWSRS",0x3ab58d65,"haxor.component.Transform.UpdateWSRS","haxor/component/Transform.hx",343,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(343)
		if ((this->m_wsrs_dirty)){
			HX_STACK_LINE(345)
			::haxor::math::Matrix4 m = this->m_worldMatrix;		HX_STACK_VAR(m,"m");
			struct _Function_2_1{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",347,0x28912231)
					{
						HX_STACK_LINE(347)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(347)
						int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(347)
						return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(347)
			::haxor::math::Vector3 c0 = (_Function_2_1::Block())->Set(m->m00,m->m10,m->m20);		HX_STACK_VAR(c0,"c0");
			struct _Function_2_2{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",348,0x28912231)
					{
						HX_STACK_LINE(348)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(348)
						int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(348)
						return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(348)
			::haxor::math::Vector3 c1 = (_Function_2_2::Block())->Set(m->m01,m->m11,m->m21);		HX_STACK_VAR(c1,"c1");
			struct _Function_2_3{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",349,0x28912231)
					{
						HX_STACK_LINE(349)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(349)
						int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(349)
						return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(349)
			::haxor::math::Vector3 c2 = (_Function_2_3::Block())->Set(m->m02,m->m12,m->m22);		HX_STACK_VAR(c2,"c2");
			HX_STACK_LINE(351)
			Float l0 = ::Math_obj::sqrt((((c0->x * c0->x) + (c0->y * c0->y)) + (c0->z * c0->z)));		HX_STACK_VAR(l0,"l0");
			HX_STACK_LINE(351)
			Float l1 = ::Math_obj::sqrt((((c1->x * c1->x) + (c1->y * c1->y)) + (c1->z * c1->z)));		HX_STACK_VAR(l1,"l1");
			HX_STACK_LINE(351)
			Float l2 = ::Math_obj::sqrt((((c2->x * c2->x) + (c2->y * c2->y)) + (c2->z * c2->z)));		HX_STACK_VAR(l2,"l2");
			HX_STACK_LINE(353)
			this->m_scale->x = l0;
			HX_STACK_LINE(353)
			this->m_scale->y = l1;
			HX_STACK_LINE(353)
			this->m_scale->z = l2;
			HX_STACK_LINE(355)
			if (((l0 <= 0.0))){
				HX_STACK_LINE(355)
				l0 = 0.0;
			}
			else{
				HX_STACK_LINE(355)
				l0 = (Float(1.0) / Float(l0));
			}
			HX_STACK_LINE(355)
			if (((l1 <= 0.0))){
				HX_STACK_LINE(355)
				l1 = 0.0;
			}
			else{
				HX_STACK_LINE(355)
				l1 = (Float(1.0) / Float(l1));
			}
			HX_STACK_LINE(355)
			if (((l2 <= 0.0))){
				HX_STACK_LINE(355)
				l2 = 0.0;
			}
			else{
				HX_STACK_LINE(355)
				l2 = (Float(1.0) / Float(l2));
			}
			HX_STACK_LINE(357)
			c0->Scale(l0);
			HX_STACK_LINE(357)
			c1->Scale(l1);
			HX_STACK_LINE(357)
			c2->Scale(l2);
			struct _Function_2_4{
				inline static ::haxor::math::Matrix4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/Transform.hx",359,0x28912231)
					{
						HX_STACK_LINE(359)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(359)
						int _g3 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(359)
						return _this->m_m4->__get(_g3).StaticCast< ::haxor::math::Matrix4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(359)
			::haxor::math::Matrix4 r = (_Function_2_4::Block())->Set(c0->x,c1->x,c2->x,0.0,c0->y,c1->y,c2->y,0.0,c0->z,c1->z,c2->z,0.0,0.0,0.0,0.0,1.0);		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(365)
			::haxor::math::Quaternion_obj::FromMatrix4(r,this->m_rotation);
			HX_STACK_LINE(367)
			this->m_wsrs_dirty = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateWSRS,(void))

Void Transform_obj::UpdateWorldMatrix( ){
{
		HX_STACK_FRAME("haxor.component.Transform","UpdateWorldMatrix",0x3aab888b,"haxor.component.Transform.UpdateWorldMatrix","haxor/component/Transform.hx",375,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(376)
		bool need_concat = this->m_dirty;		HX_STACK_VAR(need_concat,"need_concat");
		HX_STACK_LINE(378)
		if ((this->m_lmt_dirty)){
			HX_STACK_LINE(378)
			this->UpdateLMT();
			HX_STACK_LINE(378)
			this->m_lmt_dirty = false;
			HX_STACK_LINE(378)
			need_concat = true;
		}
		HX_STACK_LINE(379)
		if ((this->m_lmrs_dirty)){
			HX_STACK_LINE(379)
			this->UpdateLMRS();
			HX_STACK_LINE(379)
			this->m_lmrs_dirty = false;
			HX_STACK_LINE(379)
			need_concat = true;
		}
		HX_STACK_LINE(381)
		if (((this->m_parent != null()))){
			HX_STACK_LINE(383)
			if ((this->m_dirty)){
				HX_STACK_LINE(383)
				this->m_parent->UpdateWorldMatrix();
			}
			HX_STACK_LINE(384)
			this->m_dirty = false;
			HX_STACK_LINE(385)
			if ((need_concat)){
				HX_STACK_LINE(385)
				::haxor::component::Transform_obj::TransformConcat(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,UpdateWorldMatrix,(void))

Void Transform_obj::Invalidate( ){
{
		HX_STACK_FRAME("haxor.component.Transform","Invalidate",0xba43157a,"haxor.component.Transform.Invalidate","haxor/component/Transform.hx",393,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(396)
		this->m_uniform_dirty = true;
		HX_STACK_LINE(397)
		this->m_dirty = true;
		HX_STACK_LINE(400)
		::haxor::context::EngineContext_obj::transform->OnChange(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(403)
		{
			HX_STACK_LINE(403)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(403)
			int _g = this->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(403)
			while((true)){
				HX_STACK_LINE(403)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(403)
					break;
				}
				HX_STACK_LINE(403)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(403)
				this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >()->Invalidate();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,Invalidate,(void))

Void Transform_obj::LookAt( ::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,hx::Null< Float >  __o_p_smooth){
Float p_smooth = __o_p_smooth.Default(0.0);
	HX_STACK_FRAME("haxor.component.Transform","LookAt",0xbc02c5b1,"haxor.component.Transform.LookAt","haxor/component/Transform.hx",412,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_smooth,"p_smooth")
{
		HX_STACK_LINE(413)
		::haxor::math::Vector3 p = this->m_entity->m_transform->get_position();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(414)
		::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(414)
		{
			HX_STACK_LINE(414)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(414)
			int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(414)
			r = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
		}
		HX_STACK_LINE(415)
		::haxor::math::Quaternion q;		HX_STACK_VAR(q,"q");
		HX_STACK_LINE(415)
		{
			HX_STACK_LINE(415)
			::haxor::math::Quaternion p_result;		HX_STACK_VAR(p_result,"p_result");
			HX_STACK_LINE(415)
			{
				HX_STACK_LINE(415)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(415)
				int _g1 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(415)
				p_result = _this->m_q->__get(_g1).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(415)
			::haxor::math::Matrix4 _g3;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(415)
			{
				HX_STACK_LINE(415)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(415)
				int _g2 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(415)
				_g3 = _this->m_m4->__get(_g2).StaticCast< ::haxor::math::Matrix4 >();
			}
			HX_STACK_LINE(415)
			::haxor::math::Matrix4 _g4 = ::haxor::math::Matrix4_obj::LookAt(p,p_at,p_up,_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(415)
			q = ::haxor::math::Quaternion_obj::FromMatrix4(_g4,p_result);
		}
		HX_STACK_LINE(416)
		if (((p_smooth > (int)0))){
			HX_STACK_LINE(418)
			::haxor::math::Quaternion _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(418)
			{
				HX_STACK_LINE(418)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(418)
				int _g5 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(418)
				_g6 = _this->m_q->__get(_g5).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(418)
			::haxor::math::Quaternion _g7 = ::haxor::math::Quaternion_obj::Lerp(r,q,(p_smooth * ::haxor::core::Time_obj::m_delta),_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(418)
			r = _g7;
		}
		else{
			HX_STACK_LINE(422)
			r = q;
		}
		HX_STACK_LINE(424)
		this->m_entity->m_transform->set_rotation(r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Transform_obj,LookAt,(void))

::haxor::component::Transform Transform_obj::GetChild( int p_index){
	HX_STACK_FRAME("haxor.component.Transform","GetChild",0x2a326765,"haxor.component.Transform.GetChild","haxor/component/Transform.hx",431,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(431)
	return this->m_hierarchy->__get(p_index).StaticCast< ::haxor::component::Transform >();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,GetChild,return )

::haxor::component::Transform Transform_obj::GetChildByName( ::String p_name){
	HX_STACK_FRAME("haxor.component.Transform","GetChildByName",0xa9542107,"haxor.component.Transform.GetChildByName","haxor/component/Transform.hx",438,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(439)
	{
		HX_STACK_LINE(439)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(439)
		int _g = this->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(439)
		while((true)){
			HX_STACK_LINE(439)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(439)
				break;
			}
			HX_STACK_LINE(439)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(439)
			::String _g2 = this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >()->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(439)
			if (((_g2 == p_name))){
				HX_STACK_LINE(439)
				return this->m_hierarchy->__get(i).StaticCast< ::haxor::component::Transform >();
			}
		}
	}
	HX_STACK_LINE(440)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,GetChildByName,return )

::haxor::component::Transform Transform_obj::Navigate( ::String p_path){
	HX_STACK_FRAME("haxor.component.Transform","Navigate",0xc17f2d70,"haxor.component.Transform.Navigate","haxor/component/Transform.hx",449,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_path,"p_path")
	HX_STACK_LINE(450)
	Array< ::String > tk = p_path.split(HX_CSTRING("."));		HX_STACK_VAR(tk,"tk");
	HX_STACK_LINE(451)
	::haxor::component::Transform t = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(452)
	while((true)){
		HX_STACK_LINE(452)
		if ((!(((tk->length > (int)0))))){
			HX_STACK_LINE(452)
			break;
		}
		HX_STACK_LINE(454)
		::String p = tk->shift();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(455)
		::haxor::component::Transform _g = t->GetChildByName(p);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(455)
		t = _g;
		HX_STACK_LINE(456)
		if (((t == null()))){
			HX_STACK_LINE(456)
			return null();
		}
	}
	HX_STACK_LINE(458)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,Navigate,return )

::haxor::component::Transform Transform_obj::Search( ::String p_name,hx::Null< bool >  __o_p_exact){
bool p_exact = __o_p_exact.Default(true);
	HX_STACK_FRAME("haxor.component.Transform","Search",0xbd44efe7,"haxor.component.Transform.Search","haxor/component/Transform.hx",467,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_exact,"p_exact")
{
		HX_STACK_LINE(467)
		Array< bool > p_exact1 = Array_obj< bool >::__new().Add(p_exact);		HX_STACK_VAR(p_exact1,"p_exact1");
		HX_STACK_LINE(467)
		Array< ::String > p_name1 = Array_obj< ::String >::__new().Add(p_name);		HX_STACK_VAR(p_name1,"p_name1");
		HX_STACK_LINE(467)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(469)
		Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new().Add(null());		HX_STACK_VAR(res,"res");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< ::String >,p_name1,Array< ::Dynamic >,_g,Array< ::Dynamic >,res,Array< bool >,p_exact1)
		bool run(::haxor::component::Transform it,int d){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/Transform.hx",471,0x28912231)
			HX_STACK_ARG(it,"it")
			HX_STACK_ARG(d,"d")
			{
				HX_STACK_LINE(472)
				if (((it == _g->__get((int)0).StaticCast< ::haxor::component::Transform >()))){
					HX_STACK_LINE(472)
					return true;
				}
				HX_STACK_LINE(473)
				if (((res->__get((int)0).StaticCast< ::haxor::component::Transform >() != null()))){
					HX_STACK_LINE(473)
					return true;
				}
				HX_STACK_LINE(474)
				if ((p_exact1->__get((int)0))){
					HX_STACK_LINE(476)
					if (((it->get_name() == p_name1->__get((int)0)))){
						HX_STACK_LINE(476)
						res[(int)0] = it;
					}
				}
				else{
					HX_STACK_LINE(480)
					if (((it->get_name().indexOf(p_name1->__get((int)0),null()) >= (int)0))){
						HX_STACK_LINE(480)
						res[(int)0] = it;
					}
				}
				HX_STACK_LINE(482)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(470)
		this->Traverse( Dynamic(new _Function_1_1(p_name1,_g,res,p_exact1)));
		HX_STACK_LINE(484)
		return res->__get((int)0).StaticCast< ::haxor::component::Transform >();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Transform_obj,Search,return )

Array< ::Dynamic > Transform_obj::GetPathToRoot( ){
	HX_STACK_FRAME("haxor.component.Transform","GetPathToRoot",0x4d13a659,"haxor.component.Transform.GetPathToRoot","haxor/component/Transform.hx",492,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(493)
	::haxor::component::Transform p = this->m_parent;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(494)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(495)
	while((true)){
		HX_STACK_LINE(495)
		if ((!(((p != null()))))){
			HX_STACK_LINE(495)
			break;
		}
		HX_STACK_LINE(497)
		res->push(p);
		HX_STACK_LINE(498)
		p = p->m_parent;
	}
	HX_STACK_LINE(500)
	res->reverse();
	HX_STACK_LINE(501)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,GetPathToRoot,return )

::String Transform_obj::OutputHierarchy( ){
	HX_STACK_FRAME("haxor.component.Transform","OutputHierarchy",0x02eb15d5,"haxor.component.Transform.OutputHierarchy","haxor/component/Transform.hx",509,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_LINE(510)
	Array< int > d0 = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(d0,"d0");
	HX_STACK_LINE(511)
	Array< ::String > hs = Array_obj< ::String >::__new().Add(HX_CSTRING(""));		HX_STACK_VAR(hs,"hs");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::String >,hs,Array< int >,d0)
	bool run(::haxor::component::Transform t,int d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/component/Transform.hx",513,0x28912231)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(514)
			::String tab = HX_CSTRING("");		HX_STACK_VAR(tab,"tab");
			HX_STACK_LINE(515)
			int td = d;		HX_STACK_VAR(td,"td");
			HX_STACK_LINE(516)
			int d1 = ::Math_obj::max((int)0,(td - d0->__get((int)0)));		HX_STACK_VAR(d1,"d1");
			HX_STACK_LINE(517)
			{
				HX_STACK_LINE(517)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(517)
				while(((_g < d1))){
					HX_STACK_LINE(517)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(517)
					hx::AddEq(tab,HX_CSTRING(" "));
				}
			}
			HX_STACK_LINE(518)
			hx::AddEq(hs[(int)0],((((((tab + t->get_name()) + HX_CSTRING(" ")) + t->get_position()->ToString(null())) + t->get_rotation()->ToString(null())) + t->get_scale()->ToString(null())) + HX_CSTRING("\n")));
			HX_STACK_LINE(519)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(512)
	this->Traverse( Dynamic(new _Function_1_1(hs,d0)));
	HX_STACK_LINE(521)
	return hs->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,OutputHierarchy,return )

Void Transform_obj::Traverse( Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.component.Transform","Traverse",0xf10c2bf1,"haxor.component.Transform.Traverse","haxor/component/Transform.hx",529,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(529)
		this->TraverseStep(hx::ObjectPtr<OBJ_>(this),(int)0,p_callback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,Traverse,(void))

Void Transform_obj::TraverseStep( ::haxor::component::Transform p_child,int p_depth,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.component.Transform","TraverseStep",0x9cc48bdd,"haxor.component.Transform.TraverseStep","haxor/component/Transform.hx",536,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_child,"p_child")
		HX_STACK_ARG(p_depth,"p_depth")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(536)
		if ((p_callback(p_child,p_depth).Cast< bool >())){
			HX_STACK_LINE(536)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(536)
			int _g = p_child->m_hierarchy->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(536)
			while((true)){
				HX_STACK_LINE(536)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(536)
					break;
				}
				HX_STACK_LINE(536)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(536)
				::haxor::component::Transform _g2 = p_child->GetChild(i);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(536)
				this->TraverseStep(_g2,(p_depth + (int)1),p_callback);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Transform_obj,TraverseStep,(void))

Void Transform_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Transform","OnDestroy",0x8507ae7c,"haxor.component.Transform.OnDestroy","haxor/component/Transform.hx",543,0x28912231)
		HX_STACK_THIS(this)
		HX_STACK_LINE(543)
		int v = this->__cid;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(543)
		::haxor::context::EngineContext_obj::transform->tid->m_cache->push(v);
		HX_STACK_LINE(543)
		v;
	}
return null();
}


::String Transform_obj::ToString( hx::Null< bool >  __o_p_use_local,hx::Null< int >  __o_p_places){
bool p_use_local = __o_p_use_local.Default(false);
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.component.Transform","ToString",0xbd107eeb,"haxor.component.Transform.ToString","haxor/component/Transform.hx",552,0x28912231)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_use_local,"p_use_local")
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(553)
		::haxor::math::Vector3 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(553)
		if ((p_use_local)){
			HX_STACK_LINE(553)
			p = this->get_localPosition();
		}
		else{
			HX_STACK_LINE(553)
			p = this->get_position();
		}
		HX_STACK_LINE(554)
		::haxor::math::Vector3 e;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(554)
		if ((p_use_local)){
			HX_STACK_LINE(554)
			e = this->get_localEuler();
		}
		else{
			HX_STACK_LINE(554)
			e = this->get_euler();
		}
		HX_STACK_LINE(555)
		::haxor::math::Vector3 s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(555)
		if ((p_use_local)){
			HX_STACK_LINE(555)
			s = this->get_localScale();
		}
		else{
			HX_STACK_LINE(555)
			s = this->get_scale();
		}
		HX_STACK_LINE(556)
		::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(556)
		::String _g1 = (_g + HX_CSTRING(" "));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(556)
		::String _g2 = p->ToString(p_places);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(556)
		::String _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(556)
		::String _g4 = (_g3 + HX_CSTRING(""));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(556)
		::String _g5 = e->ToString(p_places);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(556)
		::String _g6 = (_g4 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(556)
		::String _g7 = (_g6 + HX_CSTRING(""));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(556)
		::String _g8 = s->ToString(p_places);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(556)
		return (_g7 + _g8);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Transform_obj,ToString,return )

Void Transform_obj::TransformConcat( ::haxor::component::Transform t){
{
		HX_STACK_FRAME("haxor.component.Transform","TransformConcat",0x219fab41,"haxor.component.Transform.TransformConcat","haxor/component/Transform.hx",25,0x28912231)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(27)
		::haxor::math::Matrix4 v = t->m_parent->m_worldMatrix;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(30)
		::haxor::math::Matrix4 m = t->m_worldMatrix;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(31)
		m->m00 = v->m00;
		HX_STACK_LINE(31)
		m->m01 = v->m01;
		HX_STACK_LINE(31)
		m->m02 = v->m02;
		HX_STACK_LINE(31)
		m->m03 = v->m03;
		HX_STACK_LINE(32)
		m->m10 = v->m10;
		HX_STACK_LINE(32)
		m->m11 = v->m11;
		HX_STACK_LINE(32)
		m->m12 = v->m12;
		HX_STACK_LINE(32)
		m->m13 = v->m13;
		HX_STACK_LINE(33)
		m->m20 = v->m20;
		HX_STACK_LINE(33)
		m->m21 = v->m21;
		HX_STACK_LINE(33)
		m->m22 = v->m22;
		HX_STACK_LINE(33)
		m->m23 = v->m23;
		HX_STACK_LINE(35)
		m->MultiplyTransform(t->m_localMatrix);
		HX_STACK_LINE(38)
		t->m_wsp_dirty = true;
		HX_STACK_LINE(39)
		t->m_wsrs_dirty = true;
		HX_STACK_LINE(42)
		t->m_right->Set(m->m00,m->m10,m->m20)->Normalize();
		HX_STACK_LINE(43)
		t->m_up->Set(m->m01,m->m11,m->m21)->Normalize();
		HX_STACK_LINE(44)
		t->m_forward->Set(m->m02,m->m12,m->m22)->Normalize();
		HX_STACK_LINE(47)
		t->m_inverse_dirty = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,TransformConcat,(void))

::haxor::component::Transform Transform_obj::get_root( ){
	HX_STACK_FRAME("haxor.component.Transform","get_root",0x76599bca,"haxor.component.Transform.get_root","haxor/component/Transform.hx",54,0x28912231)
	HX_STACK_LINE(54)
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
	HX_MARK_MEMBER_NAME(m_localPosition,"m_localPosition");
	HX_MARK_MEMBER_NAME(m_localRotation,"m_localRotation");
	HX_MARK_MEMBER_NAME(m_localScale,"m_localScale");
	HX_MARK_MEMBER_NAME(m_position,"m_position");
	HX_MARK_MEMBER_NAME(m_rotation,"m_rotation");
	HX_MARK_MEMBER_NAME(m_scale,"m_scale");
	HX_MARK_MEMBER_NAME(m_worldMatrix,"m_worldMatrix");
	HX_MARK_MEMBER_NAME(m_worldMatrixInverse,"m_worldMatrixInverse");
	HX_MARK_MEMBER_NAME(m_localMatrix,"m_localMatrix");
	HX_MARK_MEMBER_NAME(m_lmt_dirty,"m_lmt_dirty");
	HX_MARK_MEMBER_NAME(m_lmrs_dirty,"m_lmrs_dirty");
	HX_MARK_MEMBER_NAME(m_uniform_dirty,"m_uniform_dirty");
	HX_MARK_MEMBER_NAME(m_dirty,"m_dirty");
	HX_MARK_MEMBER_NAME(m_inverse_dirty,"m_inverse_dirty");
	HX_MARK_MEMBER_NAME(m_wsp_dirty,"m_wsp_dirty");
	HX_MARK_MEMBER_NAME(m_wsrs_dirty,"m_wsrs_dirty");
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
	HX_VISIT_MEMBER_NAME(m_localPosition,"m_localPosition");
	HX_VISIT_MEMBER_NAME(m_localRotation,"m_localRotation");
	HX_VISIT_MEMBER_NAME(m_localScale,"m_localScale");
	HX_VISIT_MEMBER_NAME(m_position,"m_position");
	HX_VISIT_MEMBER_NAME(m_rotation,"m_rotation");
	HX_VISIT_MEMBER_NAME(m_scale,"m_scale");
	HX_VISIT_MEMBER_NAME(m_worldMatrix,"m_worldMatrix");
	HX_VISIT_MEMBER_NAME(m_worldMatrixInverse,"m_worldMatrixInverse");
	HX_VISIT_MEMBER_NAME(m_localMatrix,"m_localMatrix");
	HX_VISIT_MEMBER_NAME(m_lmt_dirty,"m_lmt_dirty");
	HX_VISIT_MEMBER_NAME(m_lmrs_dirty,"m_lmrs_dirty");
	HX_VISIT_MEMBER_NAME(m_uniform_dirty,"m_uniform_dirty");
	HX_VISIT_MEMBER_NAME(m_dirty,"m_dirty");
	HX_VISIT_MEMBER_NAME(m_inverse_dirty,"m_inverse_dirty");
	HX_VISIT_MEMBER_NAME(m_wsp_dirty,"m_wsp_dirty");
	HX_VISIT_MEMBER_NAME(m_wsrs_dirty,"m_wsrs_dirty");
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
		if (HX_FIELD_EQ(inName,"LookAt") ) { return LookAt_dyn(); }
		if (HX_FIELD_EQ(inName,"Search") ) { return Search_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_right") ) { return m_right; }
		if (HX_FIELD_EQ(inName,"forward") ) { return get_forward(); }
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
		if (HX_FIELD_EQ(inName,"UpdateLMT") ) { return UpdateLMT_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateWSP") ) { return UpdateWSP_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_parent") ) { return get_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_parent") ) { return set_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"childCount") ) { return inCallProp ? get_childCount() : childCount; }
		if (HX_FIELD_EQ(inName,"localEuler") ) { return get_localEuler(); }
		if (HX_FIELD_EQ(inName,"localScale") ) { return get_localScale(); }
		if (HX_FIELD_EQ(inName,"m_position") ) { return m_position; }
		if (HX_FIELD_EQ(inName,"m_rotation") ) { return m_rotation; }
		if (HX_FIELD_EQ(inName,"UpdateLMRS") ) { return UpdateLMRS_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateWSRS") ) { return UpdateWSRS_dyn(); }
		if (HX_FIELD_EQ(inName,"Invalidate") ) { return Invalidate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_forward") ) { return get_forward_dyn(); }
		if (HX_FIELD_EQ(inName,"set_forward") ) { return set_forward_dyn(); }
		if (HX_FIELD_EQ(inName,"WorldMatrix") ) { return get_WorldMatrix(); }
		if (HX_FIELD_EQ(inName,"m_lmt_dirty") ) { return m_lmt_dirty; }
		if (HX_FIELD_EQ(inName,"m_wsp_dirty") ) { return m_wsp_dirty; }
		if (HX_FIELD_EQ(inName,"m_hierarchy") ) { return m_hierarchy; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localScale") ) { return m_localScale; }
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return set_position_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_lmrs_dirty") ) { return m_lmrs_dirty; }
		if (HX_FIELD_EQ(inName,"m_wsrs_dirty") ) { return m_wsrs_dirty; }
		if (HX_FIELD_EQ(inName,"TraverseStep") ) { return TraverseStep_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"localPosition") ) { return get_localPosition(); }
		if (HX_FIELD_EQ(inName,"localRotation") ) { return get_localRotation(); }
		if (HX_FIELD_EQ(inName,"m_worldMatrix") ) { return m_worldMatrix; }
		if (HX_FIELD_EQ(inName,"m_localMatrix") ) { return m_localMatrix; }
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
		if (HX_FIELD_EQ(inName,"TransformConcat") ) { return TransformConcat_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localPosition") ) { return m_localPosition; }
		if (HX_FIELD_EQ(inName,"m_localRotation") ) { return m_localRotation; }
		if (HX_FIELD_EQ(inName,"get_WorldMatrix") ) { return get_WorldMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"m_uniform_dirty") ) { return m_uniform_dirty; }
		if (HX_FIELD_EQ(inName,"m_inverse_dirty") ) { return m_inverse_dirty; }
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
		if (HX_FIELD_EQ(inName,"localEuler") ) { return set_localEuler(inValue); }
		if (HX_FIELD_EQ(inName,"localScale") ) { return set_localScale(inValue); }
		if (HX_FIELD_EQ(inName,"m_position") ) { m_position=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_rotation") ) { m_rotation=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_lmt_dirty") ) { m_lmt_dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_wsp_dirty") ) { m_wsp_dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_hierarchy") ) { m_hierarchy=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localScale") ) { m_localScale=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_lmrs_dirty") ) { m_lmrs_dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_wsrs_dirty") ) { m_wsrs_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"localPosition") ) { return set_localPosition(inValue); }
		if (HX_FIELD_EQ(inName,"localRotation") ) { return set_localRotation(inValue); }
		if (HX_FIELD_EQ(inName,"m_worldMatrix") ) { m_worldMatrix=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localMatrix") ) { m_localMatrix=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_localPosition") ) { m_localPosition=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localRotation") ) { m_localRotation=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_uniform_dirty") ) { m_uniform_dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_inverse_dirty") ) { m_inverse_dirty=inValue.Cast< bool >(); return inValue; }
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
	outFields->push(HX_CSTRING("localPosition"));
	outFields->push(HX_CSTRING("m_localPosition"));
	outFields->push(HX_CSTRING("localRotation"));
	outFields->push(HX_CSTRING("m_localRotation"));
	outFields->push(HX_CSTRING("localEuler"));
	outFields->push(HX_CSTRING("localScale"));
	outFields->push(HX_CSTRING("m_localScale"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("m_position"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("m_rotation"));
	outFields->push(HX_CSTRING("euler"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("m_scale"));
	outFields->push(HX_CSTRING("WorldMatrix"));
	outFields->push(HX_CSTRING("m_worldMatrix"));
	outFields->push(HX_CSTRING("WorldMatrixInverse"));
	outFields->push(HX_CSTRING("m_worldMatrixInverse"));
	outFields->push(HX_CSTRING("m_localMatrix"));
	outFields->push(HX_CSTRING("m_lmt_dirty"));
	outFields->push(HX_CSTRING("m_lmrs_dirty"));
	outFields->push(HX_CSTRING("m_uniform_dirty"));
	outFields->push(HX_CSTRING("m_dirty"));
	outFields->push(HX_CSTRING("m_inverse_dirty"));
	outFields->push(HX_CSTRING("m_wsp_dirty"));
	outFields->push(HX_CSTRING("m_wsrs_dirty"));
	outFields->push(HX_CSTRING("m_hierarchy"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TransformConcat"),
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
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_localPosition),HX_CSTRING("m_localPosition")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Transform_obj,m_localRotation),HX_CSTRING("m_localRotation")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_localScale),HX_CSTRING("m_localScale")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_position),HX_CSTRING("m_position")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Transform_obj,m_rotation),HX_CSTRING("m_rotation")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Transform_obj,m_scale),HX_CSTRING("m_scale")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Transform_obj,m_worldMatrix),HX_CSTRING("m_worldMatrix")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Transform_obj,m_worldMatrixInverse),HX_CSTRING("m_worldMatrixInverse")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Transform_obj,m_localMatrix),HX_CSTRING("m_localMatrix")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_lmt_dirty),HX_CSTRING("m_lmt_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_lmrs_dirty),HX_CSTRING("m_lmrs_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_uniform_dirty),HX_CSTRING("m_uniform_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_dirty),HX_CSTRING("m_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_inverse_dirty),HX_CSTRING("m_inverse_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_wsp_dirty),HX_CSTRING("m_wsp_dirty")},
	{hx::fsBool,(int)offsetof(Transform_obj,m_wsrs_dirty),HX_CSTRING("m_wsrs_dirty")},
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
	HX_CSTRING("get_localPosition"),
	HX_CSTRING("set_localPosition"),
	HX_CSTRING("m_localPosition"),
	HX_CSTRING("get_localRotation"),
	HX_CSTRING("set_localRotation"),
	HX_CSTRING("m_localRotation"),
	HX_CSTRING("get_localEuler"),
	HX_CSTRING("set_localEuler"),
	HX_CSTRING("get_localScale"),
	HX_CSTRING("set_localScale"),
	HX_CSTRING("m_localScale"),
	HX_CSTRING("get_position"),
	HX_CSTRING("set_position"),
	HX_CSTRING("m_position"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("m_rotation"),
	HX_CSTRING("get_euler"),
	HX_CSTRING("set_euler"),
	HX_CSTRING("get_scale"),
	HX_CSTRING("m_scale"),
	HX_CSTRING("get_WorldMatrix"),
	HX_CSTRING("m_worldMatrix"),
	HX_CSTRING("get_WorldMatrixInverse"),
	HX_CSTRING("m_worldMatrixInverse"),
	HX_CSTRING("m_localMatrix"),
	HX_CSTRING("m_lmt_dirty"),
	HX_CSTRING("m_lmrs_dirty"),
	HX_CSTRING("m_uniform_dirty"),
	HX_CSTRING("m_dirty"),
	HX_CSTRING("m_inverse_dirty"),
	HX_CSTRING("m_wsp_dirty"),
	HX_CSTRING("m_wsrs_dirty"),
	HX_CSTRING("m_hierarchy"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("UpdateLMT"),
	HX_CSTRING("UpdateWSP"),
	HX_CSTRING("UpdateLMRS"),
	HX_CSTRING("UpdateWSRS"),
	HX_CSTRING("UpdateWorldMatrix"),
	HX_CSTRING("Invalidate"),
	HX_CSTRING("LookAt"),
	HX_CSTRING("GetChild"),
	HX_CSTRING("GetChildByName"),
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
