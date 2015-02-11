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
#ifndef INCLUDED_haxor_component_physics_BoxCollider
#include <haxor/component/physics/BoxCollider.h>
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

Void BoxCollider_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.physics.BoxCollider","new",0xf63f432d,"haxor.component.physics.BoxCollider.new","haxor/component/physics/BoxCollider.hx",19,0xa2600d66)
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

//BoxCollider_obj::~BoxCollider_obj() { }

Dynamic BoxCollider_obj::__CreateEmpty() { return  new BoxCollider_obj; }
hx::ObjectPtr< BoxCollider_obj > BoxCollider_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< BoxCollider_obj > result = new BoxCollider_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic BoxCollider_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxCollider_obj > result = new BoxCollider_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::math::Vector3 BoxCollider_obj::get_center( ){
	HX_STACK_FRAME("haxor.component.physics.BoxCollider","get_center",0xa80ec671,"haxor.component.physics.BoxCollider.get_center","haxor/component/physics/BoxCollider.hx",25,0xa2600d66)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",25,0xa2600d66)
			{
				HX_STACK_LINE(25)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(25)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(25)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(25)
	return (_Function_1_1::Block())->Set(this->m_center->x,this->m_center->y,this->m_center->z);
}


HX_DEFINE_DYNAMIC_FUNC0(BoxCollider_obj,get_center,return )

::haxor::math::Vector3 BoxCollider_obj::set_center( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.physics.BoxCollider","set_center",0xab8c64e5,"haxor.component.physics.BoxCollider.set_center","haxor/component/physics/BoxCollider.hx",26,0xa2600d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(26)
	this->m_center->Set(v->x,v->y,v->z);
	HX_STACK_LINE(26)
	this->Refresh();
	HX_STACK_LINE(26)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxCollider_obj,set_center,return )

::haxor::math::Vector3 BoxCollider_obj::get_size( ){
	HX_STACK_FRAME("haxor.component.physics.BoxCollider","get_size",0x288ea25d,"haxor.component.physics.BoxCollider.get_size","haxor/component/physics/BoxCollider.hx",33,0xa2600d66)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",33,0xa2600d66)
			{
				HX_STACK_LINE(33)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(33)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(33)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(33)
	return (_Function_1_1::Block())->Set(this->m_size->x,this->m_size->y,this->m_size->z);
}


HX_DEFINE_DYNAMIC_FUNC0(BoxCollider_obj,get_size,return )

::haxor::math::Vector3 BoxCollider_obj::set_size( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.physics.BoxCollider","set_size",0xd6ebfbd1,"haxor.component.physics.BoxCollider.set_size","haxor/component/physics/BoxCollider.hx",34,0xa2600d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(34)
	this->m_size->Set(v->x,v->y,v->z);
	HX_STACK_LINE(34)
	this->Refresh();
	HX_STACK_LINE(34)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxCollider_obj,set_size,return )

Void BoxCollider_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.physics.BoxCollider","OnBuild",0x9d2afebc,"haxor.component.physics.BoxCollider.OnBuild","haxor/component/physics/BoxCollider.hx",41,0xa2600d66)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		this->m_type = ::haxor::core::ColliderType_obj::Box;
		HX_STACK_LINE(43)
		this->super::OnBuild();
		HX_STACK_LINE(44)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		this->m_center = _g;
		HX_STACK_LINE(45)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(45)
		this->m_size = _g1;
	}
return null();
}


Void BoxCollider_obj::GenerateSphere( ){
{
		HX_STACK_FRAME("haxor.component.physics.BoxCollider","GenerateSphere",0x1f168295,"haxor.component.physics.BoxCollider.GenerateSphere","haxor/component/physics/BoxCollider.hx",52,0xa2600d66)
		HX_STACK_THIS(this)
		HX_STACK_LINE(53)
		::haxor::math::Vector4 v = this->m_sphere;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(54)
		::haxor::math::Matrix4 wm = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",55,0xa2600d66)
				{
					HX_STACK_LINE(55)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(55)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(55)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(55)
		::haxor::math::Vector3 c = (_Function_1_1::Block())->Set(this->m_center->x,this->m_center->y,this->m_center->z);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			Float vx = ((((wm->m00 * c->x) + (wm->m01 * c->y)) + (wm->m02 * c->z)) + wm->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(56)
			Float vy = ((((wm->m10 * c->x) + (wm->m11 * c->y)) + (wm->m12 * c->z)) + wm->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(56)
			Float vz = ((((wm->m20 * c->x) + (wm->m21 * c->y)) + (wm->m22 * c->z)) + wm->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(56)
			c->x = vx;
			HX_STACK_LINE(56)
			c->y = vy;
			HX_STACK_LINE(56)
			c->z = vz;
			HX_STACK_LINE(56)
			c;
		}
		HX_STACK_LINE(57)
		v->x = c->x;
		HX_STACK_LINE(58)
		v->y = c->y;
		HX_STACK_LINE(59)
		v->z = c->z;
		HX_STACK_LINE(60)
		::haxor::math::Matrix4 _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			::haxor::math::Matrix4 _this;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(60)
			{
				HX_STACK_LINE(60)
				::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(60)
				int _g1 = _this1->m_nq = hx::Mod(((_this1->m_nm4 + (int)1)),_this1->m_m4->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(60)
				_this = _this1->m_m4->__get(_g1).StaticCast< ::haxor::math::Matrix4 >();
			}
			HX_STACK_LINE(60)
			_g2 = _this->Set((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
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
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			::haxor::math::Vector3 _this = this->m_size;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(61)
			_g5 = ::Math_obj::sqrt((((_this->x * _this->x) + (_this->y * _this->y)) + (_this->z * _this->z)));
		}
		HX_STACK_LINE(61)
		Float _g6 = (_g4 * _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(61)
		v->w = _g6;
	}
return null();
}


Void BoxCollider_obj::GenerateAABB( ){
{
		HX_STACK_FRAME("haxor.component.physics.BoxCollider","GenerateAABB",0x74eda008,"haxor.component.physics.BoxCollider.GenerateAABB","haxor/component/physics/BoxCollider.hx",68,0xa2600d66)
		HX_STACK_THIS(this)
		HX_STACK_LINE(69)
		::haxor::math::AABB3 b = this->m_aabb;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(70)
		::haxor::math::Matrix4 wm = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",71,0xa2600d66)
				{
					HX_STACK_LINE(71)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(71)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(71)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(71)
		::haxor::math::Vector3 c = (_Function_1_1::Block())->Set(this->m_center->x,this->m_center->y,this->m_center->z);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(72)
		Float hx = (this->m_size->x * 0.5);		HX_STACK_VAR(hx,"hx");
		HX_STACK_LINE(73)
		Float hy = (this->m_size->y * 0.5);		HX_STACK_VAR(hy,"hy");
		HX_STACK_LINE(74)
		Float hz = (this->m_size->z * 0.5);		HX_STACK_VAR(hz,"hz");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",75,0xa2600d66)
				{
					HX_STACK_LINE(75)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(75)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(75)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(75)
		::haxor::math::Vector3 vx = (_Function_1_2::Block())->Set((hx * wm->m00),(hx * wm->m10),(hx * wm->m20));		HX_STACK_VAR(vx,"vx");
		struct _Function_1_3{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",76,0xa2600d66)
				{
					HX_STACK_LINE(76)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(76)
					int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(76)
					return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(76)
		::haxor::math::Vector3 vy = (_Function_1_3::Block())->Set((hy * wm->m01),(hy * wm->m11),(hy * wm->m21));		HX_STACK_VAR(vy,"vy");
		struct _Function_1_4{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/BoxCollider.hx",77,0xa2600d66)
				{
					HX_STACK_LINE(77)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(77)
					int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(77)
					return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(77)
		::haxor::math::Vector3 vz = (_Function_1_4::Block())->Set((hz * wm->m02),(hz * wm->m12),(hz * wm->m22));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			Float vx1 = ((((wm->m00 * c->x) + (wm->m01 * c->y)) + (wm->m02 * c->z)) + wm->m03);		HX_STACK_VAR(vx1,"vx1");
			HX_STACK_LINE(78)
			Float vy1 = ((((wm->m10 * c->x) + (wm->m11 * c->y)) + (wm->m12 * c->z)) + wm->m13);		HX_STACK_VAR(vy1,"vy1");
			HX_STACK_LINE(78)
			Float vz1 = ((((wm->m20 * c->x) + (wm->m21 * c->y)) + (wm->m22 * c->z)) + wm->m23);		HX_STACK_VAR(vz1,"vz1");
			HX_STACK_LINE(78)
			c->x = vx1;
			HX_STACK_LINE(78)
			c->y = vy1;
			HX_STACK_LINE(78)
			c->z = vz1;
			HX_STACK_LINE(78)
			c;
		}
		HX_STACK_LINE(79)
		Float _g4 = b->set_xMax(c->x);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(79)
		b->set_xMin(_g4);
		HX_STACK_LINE(80)
		Float _g5 = b->set_yMax(c->y);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(80)
		b->set_yMin(_g5);
		HX_STACK_LINE(81)
		Float _g6 = b->set_zMax(c->z);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(81)
		b->set_zMin(_g6);
		HX_STACK_LINE(82)
		b->Encapsulate3((((c->x + vx->x) + vy->x) + vz->x),(((c->y + vx->y) + vy->y) + vz->y),(((c->z + vx->z) + vy->z) + vz->z));
		HX_STACK_LINE(83)
		b->Encapsulate3((((c->x - vx->x) + vy->x) + vz->x),(((c->y - vx->y) + vy->y) + vz->y),(((c->z - vx->z) + vy->z) + vz->z));
		HX_STACK_LINE(84)
		b->Encapsulate3((((c->x + vx->x) - vy->x) + vz->x),(((c->y + vx->y) - vy->y) + vz->y),(((c->z + vx->z) - vy->z) + vz->z));
		HX_STACK_LINE(85)
		b->Encapsulate3((((c->x - vx->x) - vy->x) + vz->x),(((c->y - vx->y) - vy->y) + vz->y),(((c->z - vx->z) - vy->z) + vz->z));
		HX_STACK_LINE(86)
		b->Encapsulate3((((c->x + vx->x) + vy->x) - vz->x),(((c->y + vx->y) + vy->y) - vz->y),(((c->z + vx->z) + vy->z) - vz->z));
		HX_STACK_LINE(87)
		b->Encapsulate3((((c->x - vx->x) + vy->x) - vz->x),(((c->y - vx->y) + vy->y) - vz->y),(((c->z - vx->z) + vy->z) - vz->z));
		HX_STACK_LINE(88)
		b->Encapsulate3((((c->x + vx->x) - vy->x) - vz->x),(((c->y + vx->y) - vy->y) - vz->y),(((c->z + vx->z) - vy->z) - vz->z));
		HX_STACK_LINE(89)
		b->Encapsulate3((((c->x - vx->x) - vy->x) - vz->x),(((c->y - vx->y) - vy->y) - vz->y),(((c->z - vx->z) - vy->z) - vz->z));
	}
return null();
}



BoxCollider_obj::BoxCollider_obj()
{
}

void BoxCollider_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxCollider);
	HX_MARK_MEMBER_NAME(m_center,"m_center");
	HX_MARK_MEMBER_NAME(m_size,"m_size");
	::haxor::component::physics::Collider_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BoxCollider_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_center,"m_center");
	HX_VISIT_MEMBER_NAME(m_size,"m_size");
	::haxor::component::physics::Collider_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BoxCollider_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return get_center(); }
		if (HX_FIELD_EQ(inName,"m_size") ) { return m_size; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_center") ) { return m_center; }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_center") ) { return get_center_dyn(); }
		if (HX_FIELD_EQ(inName,"set_center") ) { return set_center_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GenerateAABB") ) { return GenerateAABB_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GenerateSphere") ) { return GenerateSphere_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoxCollider_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return set_size(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return set_center(inValue); }
		if (HX_FIELD_EQ(inName,"m_size") ) { m_size=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_center") ) { m_center=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoxCollider_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("m_center"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("m_size"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(BoxCollider_obj,m_center),HX_CSTRING("m_center")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(BoxCollider_obj,m_size),HX_CSTRING("m_size")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_center"),
	HX_CSTRING("set_center"),
	HX_CSTRING("m_center"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_size"),
	HX_CSTRING("m_size"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("GenerateSphere"),
	HX_CSTRING("GenerateAABB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoxCollider_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoxCollider_obj::__mClass,"__mClass");
};

#endif

Class BoxCollider_obj::__mClass;

void BoxCollider_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.physics.BoxCollider"), hx::TCanCast< BoxCollider_obj> ,sStaticFields,sMemberFields,
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

void BoxCollider_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace physics
