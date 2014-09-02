#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
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
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void Quaternion_obj::__construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w)
{
HX_STACK_FRAME("haxor.math.Quaternion","new",0x5b4754ea,"haxor.math.Quaternion.new","haxor/math/Quaternion.hx",332,0x6b269d66)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_x,"p_x")
HX_STACK_ARG(__o_p_y,"p_y")
HX_STACK_ARG(__o_p_z,"p_z")
HX_STACK_ARG(__o_p_w,"p_w")
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
Float p_w = __o_p_w.Default(1.0);
{
	HX_STACK_LINE(333)
	this->x = p_x;
	HX_STACK_LINE(333)
	this->y = p_y;
	HX_STACK_LINE(333)
	this->z = p_z;
	HX_STACK_LINE(333)
	this->w = p_w;
}
;
	return null();
}

//Quaternion_obj::~Quaternion_obj() { }

Dynamic Quaternion_obj::__CreateEmpty() { return  new Quaternion_obj; }
hx::ObjectPtr< Quaternion_obj > Quaternion_obj::__new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w)
{  hx::ObjectPtr< Quaternion_obj > result = new Quaternion_obj();
	result->__construct(__o_p_x,__o_p_y,__o_p_z,__o_p_w);
	return result;}

Dynamic Quaternion_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Quaternion_obj > result = new Quaternion_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::haxor::math::Matrix4 Quaternion_obj::get_matrix( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_matrix",0xbdc626c0,"haxor.math.Quaternion.get_matrix","haxor/math/Quaternion.hx",270,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(270)
	return ::haxor::math::Matrix4_obj::FromQuaternion(hx::ObjectPtr<OBJ_>(this),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_matrix,return )

::haxor::math::Matrix4 Quaternion_obj::set_matrix( ::haxor::math::Matrix4 v){
	HX_STACK_FRAME("haxor.math.Quaternion","set_matrix",0xc143c534,"haxor.math.Quaternion.set_matrix","haxor/math/Quaternion.hx",271,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(271)
	::haxor::math::Quaternion_obj::FromMatrix4(v,hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(271)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,set_matrix,return )

::haxor::math::Vector3 Quaternion_obj::get_euler( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_euler",0xc7cabdca,"haxor.math.Quaternion.get_euler","haxor/math/Quaternion.hx",277,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(277)
	return ::haxor::math::Quaternion_obj::ToEuler(hx::ObjectPtr<OBJ_>(this),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_euler,return )

::haxor::math::Vector3 Quaternion_obj::set_euler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Quaternion","set_euler",0xab1ba9d6,"haxor.math.Quaternion.set_euler","haxor/math/Quaternion.hx",278,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(278)
	::haxor::math::Quaternion_obj::FromEuler(v,hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(278)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,set_euler,return )

::haxor::math::Quaternion Quaternion_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_clone",0x9b0cf7be,"haxor.math.Quaternion.get_clone","haxor/math/Quaternion.hx",284,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(284)
	return ::haxor::math::Quaternion_obj::__new(this->x,this->y,this->z,this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_clone,return )

::haxor::math::Vector4 Quaternion_obj::get_xyzw( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_xyzw",0x2c7658bd,"haxor.math.Quaternion.get_xyzw","haxor/math/Quaternion.hx",290,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(290)
	return ::haxor::math::Vector4_obj::__new(this->x,this->y,this->z,this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_xyzw,return )

Float Quaternion_obj::get_length( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_length",0xa1058565,"haxor.math.Quaternion.get_length","haxor/math/Quaternion.hx",296,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(296)
	return ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)) + (this->w * this->w)));
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_length,return )

::haxor::math::Quaternion Quaternion_obj::get_normalized( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_normalized",0x11090036,"haxor.math.Quaternion.get_normalized","haxor/math/Quaternion.hx",302,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(302)
	return ::haxor::math::Quaternion_obj::__new(this->x,this->y,this->z,this->w)->Normalize();
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_normalized,return )

::haxor::math::Quaternion Quaternion_obj::Set( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
Float p_w = __o_p_w.Default(1.0);
	HX_STACK_FRAME("haxor.math.Quaternion","Set",0x5b32d80c,"haxor.math.Quaternion.Set","haxor/math/Quaternion.hx",344,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
	HX_STACK_ARG(p_w,"p_w")
{
		HX_STACK_LINE(344)
		this->x = p_x;
		HX_STACK_LINE(344)
		this->y = p_y;
		HX_STACK_LINE(344)
		this->z = p_z;
		HX_STACK_LINE(344)
		this->w = p_w;
		HX_STACK_LINE(344)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Quaternion_obj,Set,return )

::haxor::math::Quaternion Quaternion_obj::SetQuaternion( ::haxor::math::Quaternion p_q){
	HX_STACK_FRAME("haxor.math.Quaternion","SetQuaternion",0xd518f04a,"haxor.math.Quaternion.SetQuaternion","haxor/math/Quaternion.hx",351,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_q,"p_q")
	HX_STACK_LINE(351)
	this->x = p_q->x;
	HX_STACK_LINE(351)
	this->y = p_q->y;
	HX_STACK_LINE(351)
	this->z = p_q->z;
	HX_STACK_LINE(351)
	this->w = p_q->w;
	HX_STACK_LINE(351)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,SetQuaternion,return )

::haxor::math::Quaternion Quaternion_obj::Normalize( ){
	HX_STACK_FRAME("haxor.math.Quaternion","Normalize",0x5c749f77,"haxor.math.Quaternion.Normalize","haxor/math/Quaternion.hx",358,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(359)
	Float l = ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)) + (this->w * this->w)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(360)
	if (((l <= (int)0))){
		HX_STACK_LINE(362)
		Float _g = this->z = 0.0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(362)
		Float _g1 = this->y = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(362)
		this->x = _g1;
		HX_STACK_LINE(362)
		this->w = 1.0;
		HX_STACK_LINE(363)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(365)
	Float _g2 = l = (Float(1.0) / Float(l));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(365)
	hx::MultEq(this->x,_g2);
	HX_STACK_LINE(366)
	hx::MultEq(this->y,l);
	HX_STACK_LINE(367)
	hx::MultEq(this->z,l);
	HX_STACK_LINE(368)
	hx::MultEq(this->w,l);
	HX_STACK_LINE(369)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,Normalize,return )

::haxor::math::Quaternion Quaternion_obj::get_conjugate( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_conjugate",0xd3d35ef9,"haxor.math.Quaternion.get_conjugate","haxor/math/Quaternion.hx",376,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(376)
	return ::haxor::math::Quaternion_obj::__new(-(this->x),-(this->y),-(this->z),this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_conjugate,return )

::haxor::math::Quaternion Quaternion_obj::get_inverse( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_inverse",0xfa25ca51,"haxor.math.Quaternion.get_inverse","haxor/math/Quaternion.hx",382,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(382)
	return ::haxor::math::Quaternion_obj::Inverse(hx::ObjectPtr<OBJ_>(this),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_inverse,return )

::haxor::math::Quaternion Quaternion_obj::Invert( ){
	HX_STACK_FRAME("haxor.math.Quaternion","Invert",0x2ebbc8ec,"haxor.math.Quaternion.Invert","haxor/math/Quaternion.hx",388,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(388)
	this->x = -(this->x);
	HX_STACK_LINE(388)
	this->y = -(this->y);
	HX_STACK_LINE(388)
	this->z = -(this->z);
	HX_STACK_LINE(388)
	this->w = -(this->w);
	HX_STACK_LINE(388)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,Invert,return )

::haxor::math::Quaternion Quaternion_obj::Scale( Float p_v){
	HX_STACK_FRAME("haxor.math.Quaternion","Scale",0xae417974,"haxor.math.Quaternion.Scale","haxor/math/Quaternion.hx",395,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(395)
	hx::MultEq(this->x,p_v);
	HX_STACK_LINE(395)
	hx::MultEq(this->y,p_v);
	HX_STACK_LINE(395)
	hx::MultEq(this->z,p_v);
	HX_STACK_LINE(395)
	hx::MultEq(this->w,p_v);
	HX_STACK_LINE(395)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,Scale,return )

::haxor::math::Quaternion Quaternion_obj::Multiply( ::haxor::math::Quaternion p_v,hx::Null< bool >  __o_p_normalize){
bool p_normalize = __o_p_normalize.Default(false);
	HX_STACK_FRAME("haxor.math.Quaternion","Multiply",0xd14c657a,"haxor.math.Quaternion.Multiply","haxor/math/Quaternion.hx",404,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_normalize,"p_normalize")
{
		HX_STACK_LINE(405)
		Float vx = ((((this->w * p_v->x) + (this->x * p_v->w)) + (this->y * p_v->z)) - (this->z * p_v->y));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(406)
		Float vy = ((((this->w * p_v->y) + (this->y * p_v->w)) + (this->z * p_v->x)) - (this->x * p_v->z));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(407)
		Float vz = ((((this->w * p_v->z) + (this->z * p_v->w)) + (this->x * p_v->y)) - (this->y * p_v->x));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(408)
		Float vw = ((((this->w * p_v->w) - (this->x * p_v->x)) - (this->y * p_v->y)) - (this->z * p_v->z));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(409)
		this->x = vx;
		HX_STACK_LINE(409)
		this->y = vy;
		HX_STACK_LINE(409)
		this->z = vz;
		HX_STACK_LINE(409)
		this->w = vw;
		HX_STACK_LINE(410)
		if ((p_normalize)){
			HX_STACK_LINE(410)
			return this->Normalize();
		}
		else{
			HX_STACK_LINE(410)
			return hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(410)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Multiply,return )

::haxor::math::Vector3 Quaternion_obj::Transform( ::haxor::math::Vector3 p_v){
	HX_STACK_FRAME("haxor.math.Quaternion","Transform",0xf6669556,"haxor.math.Quaternion.Transform","haxor/math/Quaternion.hx",419,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(420)
	Float l = ::Math_obj::sqrt((((p_v->x * p_v->x) + (p_v->y * p_v->y)) + (p_v->z * p_v->z)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(421)
	Float nl;		HX_STACK_VAR(nl,"nl");
	HX_STACK_LINE(421)
	if (((l <= 0.0))){
		HX_STACK_LINE(421)
		nl = 0.0;
	}
	else{
		HX_STACK_LINE(421)
		nl = (Float(1.0) / Float(l));
	}
	HX_STACK_LINE(422)
	hx::MultEq(p_v->x,nl);
	HX_STACK_LINE(423)
	hx::MultEq(p_v->y,nl);
	HX_STACK_LINE(424)
	hx::MultEq(p_v->z,nl);
	struct _Function_1_1{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",425,0x6b269d66)
			{
				HX_STACK_LINE(425)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(425)
				int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(425)
				return _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(425)
	::haxor::math::Quaternion qv = (_Function_1_1::Block())->Set(p_v->x,p_v->y,p_v->z,(int)0);		HX_STACK_VAR(qv,"qv");
	struct _Function_1_2{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",426,0x6b269d66)
			{
				HX_STACK_LINE(426)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(426)
				int _g1 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(426)
				return _this->m_q->__get(_g1).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(426)
	::haxor::math::Quaternion a = (_Function_1_2::Block())->SetQuaternion(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(a,"a");
	struct _Function_1_3{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",427,0x6b269d66)
			{
				HX_STACK_LINE(427)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(427)
				int _g2 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(427)
				return _this->m_q->__get(_g2).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(427)
	::haxor::math::Quaternion c = (_Function_1_3::Block())->Set(-(this->x),-(this->y),-(this->z),this->w);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(428)
	::haxor::math::Quaternion _g3 = qv->Multiply(c,null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(428)
	a->Multiply(_g3,null());
	HX_STACK_LINE(429)
	p_v->x = (a->x * l);
	HX_STACK_LINE(430)
	p_v->y = (a->y * l);
	HX_STACK_LINE(431)
	p_v->z = (a->z * l);
	HX_STACK_LINE(432)
	return p_v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,Transform,return )

::haxor::math::Quaternion Quaternion_obj::Delta( ::haxor::math::Quaternion p_q){
	HX_STACK_FRAME("haxor.math.Quaternion","Delta",0x0c9992e2,"haxor.math.Quaternion.Delta","haxor/math/Quaternion.hx",440,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_q,"p_q")
	HX_STACK_LINE(440)
	::haxor::math::Quaternion _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(440)
	{
		HX_STACK_LINE(440)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(440)
		int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(440)
		_g1 = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
	}
	HX_STACK_LINE(440)
	::haxor::math::Quaternion _g2 = ::haxor::math::Quaternion_obj::DeltaRotation(hx::ObjectPtr<OBJ_>(this),p_q,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(440)
	return this->SetQuaternion(_g2);
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,Delta,return )

::haxor::math::Quaternion Quaternion_obj::SetAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle){
	HX_STACK_FRAME("haxor.math.Quaternion","SetAxisAngle",0xa588d5c6,"haxor.math.Quaternion.SetAxisAngle","haxor/math/Quaternion.hx",449,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_axis,"p_axis")
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(450)
	p_angle = ((p_angle * 0.5) * 0.01745329251994329576923690768489);
	HX_STACK_LINE(451)
	Float l = ::Math_obj::sqrt((((p_axis->x * p_axis->x) + (p_axis->y * p_axis->y)) + (p_axis->z * p_axis->z)));		HX_STACK_VAR(l,"l");
	struct _Function_1_1{
		inline static Float Block( Float &l){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",452,0x6b269d66)
			{
				HX_STACK_LINE(452)
				Float p_a = (l - 1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(452)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(452)
	if (((_Function_1_1::Block(l) > 0.0001))){
		HX_STACK_LINE(452)
		p_axis->Normalize();
	}
	HX_STACK_LINE(453)
	Float s = ::Math_obj::sin(p_angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(454)
	Float _g = ::Math_obj::cos(p_angle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(454)
	return this->Set((p_axis->x * s),(p_axis->y * s),(p_axis->z * s),_g);
}


HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,SetAxisAngle,return )

Array< Float > Quaternion_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Quaternion","ToArray",0x69b67388,"haxor.math.Quaternion.ToArray","haxor/math/Quaternion.hx",461,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(461)
	return Array_obj< Float >::__new().Add(this->x).Add(this->y).Add(this->z).Add(this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,ToArray,return )

::String Quaternion_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Quaternion","ToString",0x6f2e5402,"haxor.math.Quaternion.ToString","haxor/math/Quaternion.hx",467,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(467)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(467)
		{
			HX_STACK_LINE(467)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(467)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(467)
			{
				HX_STACK_LINE(467)
				Float p_v = (this->x * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(467)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(467)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(467)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(467)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(467)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(467)
		{
			HX_STACK_LINE(467)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(467)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(467)
			{
				HX_STACK_LINE(467)
				Float p_v = (this->y * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(467)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(467)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(467)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(467)
		::String _g7 = (_g6 + HX_CSTRING(","));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(467)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(467)
		{
			HX_STACK_LINE(467)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(467)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(467)
			{
				HX_STACK_LINE(467)
				Float p_v = (this->z * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(467)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(467)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(467)
		::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(467)
		::String _g11 = (_g10 + HX_CSTRING(","));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(467)
		Float _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(467)
		{
			HX_STACK_LINE(467)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(467)
			Float _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(467)
			{
				HX_STACK_LINE(467)
				Float p_v = (this->w * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(467)
				_g12 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(467)
			_g13 = (Float(_g12) / Float(d));
		}
		HX_STACK_LINE(467)
		::String _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(467)
		return (_g14 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,ToString,return )

::haxor::math::Quaternion Quaternion_obj::temp;

::haxor::math::Quaternion Quaternion_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_temp",0x29c245d3,"haxor.math.Quaternion.get_temp","haxor/math/Quaternion.hx",15,0x6b269d66)
	HX_STACK_LINE(15)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(15)
	int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	return _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_temp,return )

::haxor::math::Quaternion Quaternion_obj::identity;

::haxor::math::Quaternion Quaternion_obj::get_identity( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_identity",0xaae9937d,"haxor.math.Quaternion.get_identity","haxor/math/Quaternion.hx",21,0x6b269d66)
	HX_STACK_LINE(21)
	return ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_identity,return )

::haxor::math::Quaternion Quaternion_obj::FromEuler( ::haxor::math::Vector3 p_euler,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","FromEuler",0xda7d2b89,"haxor.math.Quaternion.FromEuler","haxor/math/Quaternion.hx",30,0x6b269d66)
	HX_STACK_ARG(p_euler,"p_euler")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(31)
	::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(31)
	if (((p_result == null()))){
		HX_STACK_LINE(31)
		r = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(31)
		r = p_result;
	}
	HX_STACK_LINE(32)
	::haxor::math::Vector3 c;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(32)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		c = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(33)
	::haxor::math::Vector3 s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(33)
	{
		HX_STACK_LINE(33)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(33)
		int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(33)
		s = _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(34)
	Float k = 0.0087266462599716477;		HX_STACK_VAR(k,"k");
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",35,0x6b269d66)
			{
				HX_STACK_LINE(35)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(35)
				int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(35)
				return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(35)
	::haxor::math::Vector3 e = (_Function_1_1::Block())->Set((p_euler->x * k),(p_euler->y * k),(p_euler->z * k));		HX_STACK_VAR(e,"e");
	HX_STACK_LINE(36)
	Float _g3 = ::Math_obj::cos(e->x);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(36)
	Float _g4 = ::Math_obj::cos(e->y);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(36)
	Float _g5 = ::Math_obj::cos(e->z);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(36)
	c->Set(_g3,_g4,_g5);
	HX_STACK_LINE(37)
	Float _g6 = ::Math_obj::sin(e->x);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(37)
	Float _g7 = ::Math_obj::sin(e->y);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(37)
	Float _g8 = ::Math_obj::sin(e->z);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(37)
	s->Set(_g6,_g7,_g8);
	HX_STACK_LINE(38)
	r->x = (((s->x * c->y) * c->z) - ((c->x * s->y) * s->z));
	HX_STACK_LINE(39)
	r->y = (((c->x * s->y) * c->z) + ((s->x * c->y) * s->z));
	HX_STACK_LINE(40)
	r->z = (((c->x * c->y) * s->z) - ((s->x * s->y) * c->z));
	HX_STACK_LINE(41)
	r->w = (((c->x * c->y) * c->z) + ((s->x * s->y) * s->z));
	HX_STACK_LINE(42)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,FromEuler,return )

::haxor::math::Vector3 Quaternion_obj::ToEuler( ::haxor::math::Quaternion p_quaternion,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","ToEuler",0xb947df58,"haxor.math.Quaternion.ToEuler","haxor/math/Quaternion.hx",54,0x6b269d66)
	HX_STACK_ARG(p_quaternion,"p_quaternion")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(55)
	::haxor::math::Quaternion q = p_quaternion;		HX_STACK_VAR(q,"q");
	HX_STACK_LINE(56)
	::haxor::math::Vector3 r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(56)
	if (((p_result == null()))){
		HX_STACK_LINE(56)
		r = ::haxor::math::Vector3_obj::__new(null(),null(),null());
	}
	else{
		HX_STACK_LINE(56)
		r = p_result;
	}
	HX_STACK_LINE(57)
	Float test = ((q->x * q->y) + (q->z * q->w));		HX_STACK_VAR(test,"test");
	HX_STACK_LINE(58)
	if (((test > 0.499))){
		HX_STACK_LINE(60)
		Float _g = ::Math_obj::atan2(q->x,q->w);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		Float _g1 = ((int)2 * _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(60)
		Float _g2 = (_g1 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(60)
		r->y = _g2;
		HX_STACK_LINE(61)
		r->z = ((::Math_obj::PI * 0.5) * 57.295779513082320876798154814105);
		HX_STACK_LINE(62)
		r->x = (int)0;
		HX_STACK_LINE(63)
		return r;
	}
	HX_STACK_LINE(65)
	if (((test < -0.499))){
		HX_STACK_LINE(67)
		Float _g3 = ::Math_obj::atan2(q->x,q->w);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(67)
		Float _g4 = (-2. * _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(67)
		r->y = _g4;
		HX_STACK_LINE(68)
		r->z = ((-(::Math_obj::PI) * 0.5) * 57.295779513082320876798154814105);
		HX_STACK_LINE(69)
		r->x = (int)0;
		HX_STACK_LINE(70)
		return r;
	}
	HX_STACK_LINE(73)
	Float sqx = (q->x * q->x);		HX_STACK_VAR(sqx,"sqx");
	HX_STACK_LINE(74)
	Float sqy = (q->y * q->y);		HX_STACK_VAR(sqy,"sqy");
	HX_STACK_LINE(75)
	Float sqz = (q->z * q->z);		HX_STACK_VAR(sqz,"sqz");
	HX_STACK_LINE(76)
	Float _g5 = ::Math_obj::atan2((((2.0 * q->y) * q->w) - ((2.0 * q->x) * q->z)),((1.0 - (2.0 * sqy)) - (2.0 * sqz)));		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(76)
	Float _g6 = (_g5 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(76)
	r->y = _g6;
	HX_STACK_LINE(77)
	Float _g7 = ::Math_obj::asin((2.0 * test));		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(77)
	Float _g8 = (_g7 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(77)
	r->z = _g8;
	HX_STACK_LINE(78)
	Float _g9 = ::Math_obj::atan2((((2.0 * q->x) * q->w) - ((2.0 * q->y) * q->z)),((1.0 - (2.0 * sqx)) - (2.0 * sqz)));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(78)
	Float _g10 = (_g9 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(78)
	r->x = _g10;
	HX_STACK_LINE(79)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,ToEuler,return )

::haxor::math::Quaternion Quaternion_obj::FromMatrix4( ::haxor::math::Matrix4 p_matrix,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","FromMatrix4",0x46145cf3,"haxor.math.Quaternion.FromMatrix4","haxor/math/Quaternion.hx",89,0x6b269d66)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(90)
	::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(90)
	if (((p_result == null()))){
		HX_STACK_LINE(90)
		r = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(90)
		r = p_result;
	}
	HX_STACK_LINE(91)
	::haxor::math::Matrix4 v = p_matrix;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(92)
	Float fourXSquaredMinus1 = ((v->m00 - v->m11) - v->m22);		HX_STACK_VAR(fourXSquaredMinus1,"fourXSquaredMinus1");
	HX_STACK_LINE(93)
	Float fourYSquaredMinus1 = ((v->m11 - v->m00) - v->m22);		HX_STACK_VAR(fourYSquaredMinus1,"fourYSquaredMinus1");
	HX_STACK_LINE(94)
	Float fourZSquaredMinus1 = ((v->m22 - v->m00) - v->m11);		HX_STACK_VAR(fourZSquaredMinus1,"fourZSquaredMinus1");
	HX_STACK_LINE(95)
	Float fourWSquaredMinus1 = ((v->m00 + v->m11) + v->m22);		HX_STACK_VAR(fourWSquaredMinus1,"fourWSquaredMinus1");
	HX_STACK_LINE(96)
	int biggestIndex = (int)0;		HX_STACK_VAR(biggestIndex,"biggestIndex");
	HX_STACK_LINE(97)
	Float fourBiggestSquaredMinus1 = fourWSquaredMinus1;		HX_STACK_VAR(fourBiggestSquaredMinus1,"fourBiggestSquaredMinus1");
	HX_STACK_LINE(98)
	if (((fourXSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(98)
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		HX_STACK_LINE(98)
		biggestIndex = (int)1;
	}
	HX_STACK_LINE(99)
	if (((fourYSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(99)
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		HX_STACK_LINE(99)
		biggestIndex = (int)2;
	}
	HX_STACK_LINE(100)
	if (((fourZSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(100)
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		HX_STACK_LINE(100)
		biggestIndex = (int)3;
	}
	HX_STACK_LINE(101)
	Float _g = ::Math_obj::sqrt((fourBiggestSquaredMinus1 + 1.0));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(101)
	Float biggestVal = (_g * 0.5);		HX_STACK_VAR(biggestVal,"biggestVal");
	HX_STACK_LINE(102)
	Float mult = (Float(0.25) / Float(biggestVal));		HX_STACK_VAR(mult,"mult");
	HX_STACK_LINE(103)
	switch( (int)(biggestIndex)){
		case (int)0: {
			HX_STACK_LINE(105)
			r->w = biggestVal;
			HX_STACK_LINE(105)
			r->x = (((v->m21 - v->m12)) * mult);
			HX_STACK_LINE(105)
			r->y = (((v->m02 - v->m20)) * mult);
			HX_STACK_LINE(105)
			r->z = (((v->m10 - v->m01)) * mult);
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(106)
			r->w = (((v->m21 - v->m12)) * mult);
			HX_STACK_LINE(106)
			r->x = biggestVal;
			HX_STACK_LINE(106)
			r->y = (((v->m10 + v->m01)) * mult);
			HX_STACK_LINE(106)
			r->z = (((v->m02 + v->m20)) * mult);
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(107)
			r->w = (((v->m02 - v->m20)) * mult);
			HX_STACK_LINE(107)
			r->x = (((v->m10 + v->m01)) * mult);
			HX_STACK_LINE(107)
			r->y = biggestVal;
			HX_STACK_LINE(107)
			r->z = (((v->m21 + v->m12)) * mult);
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(108)
			r->w = (((v->m10 - v->m01)) * mult);
			HX_STACK_LINE(108)
			r->x = (((v->m02 + v->m20)) * mult);
			HX_STACK_LINE(108)
			r->y = (((v->m21 + v->m12)) * mult);
			HX_STACK_LINE(108)
			r->z = biggestVal;
		}
		;break;
	}
	HX_STACK_LINE(110)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,FromMatrix4,return )

Float Quaternion_obj::Dot( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b){
	HX_STACK_FRAME("haxor.math.Quaternion","Dot",0x5b277ef3,"haxor.math.Quaternion.Dot","haxor/math/Quaternion.hx",119,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(119)
	return ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Dot,return )

::haxor::math::Quaternion Quaternion_obj::DeltaRotation( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","DeltaRotation",0x96d23e40,"haxor.math.Quaternion.DeltaRotation","haxor/math/Quaternion.hx",128,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(129)
	::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(129)
	if (((p_result == null()))){
		HX_STACK_LINE(129)
		r = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(129)
		r = p_result;
	}
	HX_STACK_LINE(130)
	::haxor::math::Quaternion_obj::Inverse(p_a,r);
	HX_STACK_LINE(131)
	r->Multiply(p_b,null());
	HX_STACK_LINE(132)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Quaternion_obj,DeltaRotation,return )

::haxor::math::Quaternion Quaternion_obj::Inverse( ::haxor::math::Quaternion p_q,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","Inverse",0xb594051a,"haxor.math.Quaternion.Inverse","haxor/math/Quaternion.hx",141,0x6b269d66)
	HX_STACK_ARG(p_q,"p_q")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(142)
	Float d = ((((p_q->x * p_q->x) + (p_q->y * p_q->y)) + (p_q->z * p_q->z)) + (p_q->w * p_q->w));		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(143)
	if (((d <= 0.0))){
		HX_STACK_LINE(143)
		d = 0.0;
	}
	else{
		HX_STACK_LINE(143)
		d = (Float(1.0) / Float(d));
	}
	HX_STACK_LINE(144)
	::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(144)
	if (((p_result == null()))){
		HX_STACK_LINE(144)
		r = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(144)
		r = p_result;
	}
	HX_STACK_LINE(145)
	return r->Set((-(p_q->x) * d),(-(p_q->y) * d),(-(p_q->z) * d),(p_q->w * d));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Inverse,return )

::haxor::math::Quaternion Quaternion_obj::Lerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","Lerp",0x6ca9b2cd,"haxor.math.Quaternion.Lerp","haxor/math/Quaternion.hx",156,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(157)
	::haxor::math::Quaternion c;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(157)
	if (((p_result == null()))){
		HX_STACK_LINE(157)
		c = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(157)
		c = p_result;
	}
	HX_STACK_LINE(158)
	::haxor::math::Quaternion ca = ::haxor::math::Quaternion_obj::__new(p_a->x,p_a->y,p_a->z,p_a->w);		HX_STACK_VAR(ca,"ca");
	HX_STACK_LINE(159)
	Float dot = ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(160)
	if (((dot < 0.0))){
		HX_STACK_LINE(162)
		ca->w = -(ca->w);
		HX_STACK_LINE(163)
		ca->x = -(ca->x);
		HX_STACK_LINE(164)
		ca->y = -(ca->y);
		HX_STACK_LINE(165)
		ca->z = -(ca->z);
	}
	HX_STACK_LINE(167)
	c->x = (ca->x + (((p_b->x - ca->x)) * p_ratio));
	HX_STACK_LINE(168)
	c->y = (ca->y + (((p_b->y - ca->y)) * p_ratio));
	HX_STACK_LINE(169)
	c->z = (ca->z + (((p_b->z - ca->z)) * p_ratio));
	HX_STACK_LINE(170)
	c->w = (ca->w + (((p_b->w - ca->w)) * p_ratio));
	HX_STACK_LINE(171)
	c->Normalize();
	HX_STACK_LINE(172)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quaternion_obj,Lerp,return )

::haxor::math::Quaternion Quaternion_obj::Slerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Quaternion","Slerp",0xb4377354,"haxor.math.Quaternion.Slerp","haxor/math/Quaternion.hx",183,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_LINE(195)
	::haxor::math::Quaternion qm = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(qm,"qm");
	struct _Function_1_1{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",196,0x6b269d66)
			{
				HX_STACK_LINE(196)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(196)
				int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(196)
				return _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(196)
	::haxor::math::Quaternion z = (_Function_1_1::Block())->SetQuaternion(p_b);		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(197)
	Float cosTheta = ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));		HX_STACK_VAR(cosTheta,"cosTheta");
	HX_STACK_LINE(200)
	if (((cosTheta < 0.0))){
		HX_STACK_LINE(202)
		z->Invert();
		HX_STACK_LINE(203)
		cosTheta = -(cosTheta);
	}
	HX_STACK_LINE(207)
	if (((cosTheta > 0.9999))){
		struct _Function_2_1{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",211,0x6b269d66)
				{
					HX_STACK_LINE(211)
					Float p_a1 = p_a->x;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(211)
					return (p_a1 + (((z->x - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",212,0x6b269d66)
				{
					HX_STACK_LINE(212)
					Float p_a1 = p_a->y;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(212)
					return (p_a1 + (((z->y - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_3{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",213,0x6b269d66)
				{
					HX_STACK_LINE(213)
					Float p_a1 = p_a->z;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(213)
					return (p_a1 + (((z->z - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_4{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",214,0x6b269d66)
				{
					HX_STACK_LINE(214)
					Float p_a1 = p_a->w;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(214)
					return (p_a1 + (((z->w - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		HX_STACK_LINE(210)
		qm->Set(_Function_2_1::Block(p_a,z,p_ratio),_Function_2_2::Block(p_a,z,p_ratio),_Function_2_3::Block(p_a,z,p_ratio),_Function_2_4::Block(p_a,z,p_ratio));
	}
	else{
		HX_STACK_LINE(219)
		Float angle = ::Math_obj::acos(cosTheta);		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(220)
		Float _g1 = ::Math_obj::sin(angle);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(220)
		Float s = (Float(1.0) / Float(_g1));		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(221)
		Float s0 = ::Math_obj::sin((((1.0 - p_ratio)) * angle));		HX_STACK_VAR(s0,"s0");
		HX_STACK_LINE(222)
		Float s1 = ::Math_obj::sin((p_ratio * angle));		HX_STACK_VAR(s1,"s1");
		HX_STACK_LINE(223)
		qm->x = ((((s0 * p_a->x) + (s1 * z->x))) * s);
		HX_STACK_LINE(224)
		qm->y = ((((s0 * p_a->y) + (s1 * z->y))) * s);
		HX_STACK_LINE(225)
		qm->z = ((((s0 * p_a->z) + (s1 * z->z))) * s);
		HX_STACK_LINE(226)
		qm->w = ((((s0 * p_a->w) + (s1 * z->w))) * s);
	}
	HX_STACK_LINE(228)
	return qm;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Quaternion_obj,Slerp,return )

::haxor::math::Quaternion Quaternion_obj::FromAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle){
	HX_STACK_FRAME("haxor.math.Quaternion","FromAxisAngle",0x08461192,"haxor.math.Quaternion.FromAxisAngle","haxor/math/Quaternion.hx",238,0x6b269d66)
	HX_STACK_ARG(p_axis,"p_axis")
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(239)
	p_angle = ((p_angle * 0.5) * 0.01745329251994329576923690768489);
	HX_STACK_LINE(240)
	Float l = ::Math_obj::sqrt((((p_axis->x * p_axis->x) + (p_axis->y * p_axis->y)) + (p_axis->z * p_axis->z)));		HX_STACK_VAR(l,"l");
	struct _Function_1_1{
		inline static Float Block( Float &l){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",241,0x6b269d66)
			{
				HX_STACK_LINE(241)
				Float p_a = (l - 1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(241)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(241)
	if (((_Function_1_1::Block(l) > 0.0001))){
		HX_STACK_LINE(241)
		p_axis->Normalize();
	}
	HX_STACK_LINE(242)
	Float s = ::Math_obj::sin(p_angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(243)
	Float _g = ::Math_obj::cos(p_angle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(243)
	return ::haxor::math::Quaternion_obj::__new((p_axis->x * s),(p_axis->y * s),(p_axis->z * s),_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,FromAxisAngle,return )

::haxor::math::Quaternion Quaternion_obj::LookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","LookAt",0xf0985708,"haxor.math.Quaternion.LookAt","haxor/math/Quaternion.hx",254,0x6b269d66)
	HX_STACK_ARG(p_eye,"p_eye")
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(255)
	::haxor::math::Matrix4 _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(255)
	{
		HX_STACK_LINE(255)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(255)
		int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(255)
		_g1 = _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
	}
	HX_STACK_LINE(255)
	::haxor::math::Matrix4 _g2 = ::haxor::math::Matrix4_obj::LookAt(p_eye,p_at,p_up,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(255)
	return ::haxor::math::Quaternion_obj::FromMatrix4(_g2,p_result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quaternion_obj,LookAt,return )

::haxor::math::Quaternion Quaternion_obj::LookRotation( ::haxor::math::Vector3 p_forward,::haxor::math::Vector3 p_up){
	HX_STACK_FRAME("haxor.math.Quaternion","LookRotation",0x0f4e7d13,"haxor.math.Quaternion.LookRotation","haxor/math/Quaternion.hx",264,0x6b269d66)
	HX_STACK_ARG(p_forward,"p_forward")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_LINE(264)
	::haxor::math::Matrix4 _this;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(264)
	{
		HX_STACK_LINE(264)
		::haxor::math::Matrix4 p_result;		HX_STACK_VAR(p_result,"p_result");
		HX_STACK_LINE(264)
		{
			HX_STACK_LINE(264)
			::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
			HX_STACK_LINE(264)
			int _g = _this1->m_nq = hx::Mod(((_this1->m_nm4 + (int)1)),_this1->m_m4->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(264)
			p_result = _this1->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
		}
		struct _Function_2_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",264,0x6b269d66)
				{
					HX_STACK_LINE(264)
					::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
					HX_STACK_LINE(264)
					int _g1 = _this1->m_nv3 = hx::Mod(((_this1->m_nv3 + (int)1)),_this1->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(264)
					return _this1->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(264)
		::haxor::math::Vector3 _g2 = (_Function_2_1::Block())->Set((int)0,(int)0,(int)0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(264)
		_this = ::haxor::math::Matrix4_obj::LookAt(_g2,p_forward,p_up,p_result);
	}
	struct _Function_1_1{
		inline static ::haxor::math::Matrix4 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",264,0x6b269d66)
			{
				HX_STACK_LINE(264)
				::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(264)
				int _g3 = _this1->m_nq = hx::Mod(((_this1->m_nm4 + (int)1)),_this1->m_m4->length);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(264)
				return _this1->m_m4->__get(_g3).StaticCast< ::haxor::math::Matrix4 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(264)
	::haxor::math::Matrix4 _g4 = (_Function_1_1::Block())->SetMatrix4(_this)->ToRotation();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(264)
	return ::haxor::math::Quaternion_obj::FromMatrix4(_g4,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,LookRotation,return )

::haxor::math::Quaternion Quaternion_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.math.Quaternion","Parse",0xf2c83b1d,"haxor.math.Quaternion.Parse","haxor/math/Quaternion.hx",475,0x6b269d66)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(476)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(478)
		::String _g = ::StringTools_obj::trim(tk->__get((int)0));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(478)
		Float _g1 = ::Std_obj::parseFloat(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(479)
		::String _g2 = ::StringTools_obj::trim(tk->__get((int)1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(479)
		Float _g3 = ::Std_obj::parseFloat(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(480)
		::String _g4 = ::StringTools_obj::trim(tk->__get((int)2));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(480)
		Float _g5 = ::Std_obj::parseFloat(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(481)
		::String _g6 = ::StringTools_obj::trim(tk->__get((int)3));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(481)
		Float _g7 = ::Std_obj::parseFloat(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(477)
		return ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0)->Set(_g1,_g3,_g5,_g7);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Parse,return )


Quaternion_obj::Quaternion_obj()
{
}

void Quaternion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Quaternion);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(xyzw,"xyzw");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(normalized,"normalized");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(conjugate,"conjugate");
	HX_MARK_MEMBER_NAME(inverse,"inverse");
	HX_MARK_END_CLASS();
}

void Quaternion_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(xyzw,"xyzw");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(normalized,"normalized");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(conjugate,"conjugate");
	HX_VISIT_MEMBER_NAME(inverse,"inverse");
}

Dynamic Quaternion_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		if (HX_FIELD_EQ(inName,"w") ) { return w; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Dot") ) { return Dot_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"xyzw") ) { return inCallProp ? get_xyzw() : xyzw; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Slerp") ) { return Slerp_dyn(); }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		if (HX_FIELD_EQ(inName,"euler") ) { return get_euler(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"Scale") ) { return Scale_dyn(); }
		if (HX_FIELD_EQ(inName,"Delta") ) { return Delta_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"LookAt") ) { return LookAt_dyn(); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return get_matrix(); }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Invert") ) { return Invert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ToEuler") ) { return ToEuler_dyn(); }
		if (HX_FIELD_EQ(inName,"Inverse") ) { return Inverse_dyn(); }
		if (HX_FIELD_EQ(inName,"inverse") ) { return inCallProp ? get_inverse() : inverse; }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"identity") ) { return inCallProp ? get_identity() : identity; }
		if (HX_FIELD_EQ(inName,"get_xyzw") ) { return get_xyzw_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FromEuler") ) { return FromEuler_dyn(); }
		if (HX_FIELD_EQ(inName,"get_euler") ) { return get_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"set_euler") ) { return set_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		if (HX_FIELD_EQ(inName,"conjugate") ) { return inCallProp ? get_conjugate() : conjugate; }
		if (HX_FIELD_EQ(inName,"Transform") ) { return Transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_matrix") ) { return get_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"set_matrix") ) { return set_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"normalized") ) { return inCallProp ? get_normalized() : normalized; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"FromMatrix4") ) { return FromMatrix4_dyn(); }
		if (HX_FIELD_EQ(inName,"get_inverse") ) { return get_inverse_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_identity") ) { return get_identity_dyn(); }
		if (HX_FIELD_EQ(inName,"LookRotation") ) { return LookRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"SetAxisAngle") ) { return SetAxisAngle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DeltaRotation") ) { return DeltaRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"FromAxisAngle") ) { return FromAxisAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"SetQuaternion") ) { return SetQuaternion_dyn(); }
		if (HX_FIELD_EQ(inName,"get_conjugate") ) { return get_conjugate_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_normalized") ) { return get_normalized_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Quaternion_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xyzw") ) { xyzw=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"euler") ) { return set_euler(inValue); }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { return set_matrix(inValue); }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"inverse") ) { inverse=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { identity=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"conjugate") ) { conjugate=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"normalized") ) { normalized=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Quaternion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("euler"));
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("xyzw"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("normalized"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("w"));
	outFields->push(HX_CSTRING("conjugate"));
	outFields->push(HX_CSTRING("inverse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("identity"),
	HX_CSTRING("get_identity"),
	HX_CSTRING("FromEuler"),
	HX_CSTRING("ToEuler"),
	HX_CSTRING("FromMatrix4"),
	HX_CSTRING("Dot"),
	HX_CSTRING("DeltaRotation"),
	HX_CSTRING("Inverse"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Slerp"),
	HX_CSTRING("FromAxisAngle"),
	HX_CSTRING("LookAt"),
	HX_CSTRING("LookRotation"),
	HX_CSTRING("Parse"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Quaternion_obj,clone),HX_CSTRING("clone")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Quaternion_obj,xyzw),HX_CSTRING("xyzw")},
	{hx::fsFloat,(int)offsetof(Quaternion_obj,length),HX_CSTRING("length")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Quaternion_obj,normalized),HX_CSTRING("normalized")},
	{hx::fsFloat,(int)offsetof(Quaternion_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Quaternion_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(Quaternion_obj,z),HX_CSTRING("z")},
	{hx::fsFloat,(int)offsetof(Quaternion_obj,w),HX_CSTRING("w")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Quaternion_obj,conjugate),HX_CSTRING("conjugate")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(Quaternion_obj,inverse),HX_CSTRING("inverse")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_matrix"),
	HX_CSTRING("set_matrix"),
	HX_CSTRING("get_euler"),
	HX_CSTRING("set_euler"),
	HX_CSTRING("clone"),
	HX_CSTRING("get_clone"),
	HX_CSTRING("xyzw"),
	HX_CSTRING("get_xyzw"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("normalized"),
	HX_CSTRING("get_normalized"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	HX_CSTRING("w"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetQuaternion"),
	HX_CSTRING("Normalize"),
	HX_CSTRING("conjugate"),
	HX_CSTRING("get_conjugate"),
	HX_CSTRING("inverse"),
	HX_CSTRING("get_inverse"),
	HX_CSTRING("Invert"),
	HX_CSTRING("Scale"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Transform"),
	HX_CSTRING("Delta"),
	HX_CSTRING("SetAxisAngle"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Quaternion_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Quaternion_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(Quaternion_obj::identity,"identity");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Quaternion_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Quaternion_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(Quaternion_obj::identity,"identity");
};

#endif

Class Quaternion_obj::__mClass;

void Quaternion_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Quaternion"), hx::TCanCast< Quaternion_obj> ,sStaticFields,sMemberFields,
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

void Quaternion_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
