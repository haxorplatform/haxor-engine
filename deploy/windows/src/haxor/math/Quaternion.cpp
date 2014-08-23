#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
HX_STACK_FRAME("haxor.math.Quaternion","new",0x5b4754ea,"haxor.math.Quaternion.new","haxor/math/Quaternion.hx",259,0x6b269d66)
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
	HX_STACK_LINE(260)
	this->x = p_x;
	HX_STACK_LINE(261)
	this->y = p_y;
	HX_STACK_LINE(262)
	this->z = p_z;
	HX_STACK_LINE(263)
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
	HX_STACK_FRAME("haxor.math.Quaternion","get_matrix",0xbdc626c0,"haxor.math.Quaternion.get_matrix","haxor/math/Quaternion.hx",177,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(177)
	return ::haxor::math::Matrix4_obj::FromQuaternion(hx::ObjectPtr<OBJ_>(this),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_matrix,return )

::haxor::math::Matrix4 Quaternion_obj::set_matrix( ::haxor::math::Matrix4 v){
	HX_STACK_FRAME("haxor.math.Quaternion","set_matrix",0xc143c534,"haxor.math.Quaternion.set_matrix","haxor/math/Quaternion.hx",178,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(178)
	::haxor::math::Quaternion_obj::FromMatrix(v,hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(178)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,set_matrix,return )

::haxor::math::Vector3 Quaternion_obj::get_euler( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_euler",0xc7cabdca,"haxor.math.Quaternion.get_euler","haxor/math/Quaternion.hx",185,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(187)
	Float _g = ::Math_obj::atan2((2.0 * (((this->y * this->z) + (this->w * this->x)))),((((this->w * this->w) - (this->x * this->x)) - (this->y * this->y)) + (this->z * this->z)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(187)
	Float _g1 = (_g * 57.295779513082320876798154814105);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(188)
	Float _g2 = ::Math_obj::asin((-2. * (((this->x * this->z) - (this->w * this->y)))));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(188)
	Float _g3 = (_g2 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(189)
	Float _g4 = ::Math_obj::atan2((2.0 * (((this->x * this->y) + (this->w * this->z)))),((((this->w * this->w) + (this->x * this->x)) - (this->y * this->y)) - (this->z * this->z)));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(189)
	Float _g5 = (_g4 * 57.295779513082320876798154814105);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(186)
	return ::haxor::math::Vector3_obj::__new(_g1,_g3,_g5);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_euler,return )

::haxor::math::Vector3 Quaternion_obj::set_euler( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Quaternion","set_euler",0xab1ba9d6,"haxor.math.Quaternion.set_euler","haxor/math/Quaternion.hx",193,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(194)
	::haxor::math::Vector3 c;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(194)
	{
		HX_STACK_LINE(194)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(194)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(194)
		c = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(195)
	::haxor::math::Vector3 s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(195)
	{
		HX_STACK_LINE(195)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(195)
		int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(195)
		s = _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(196)
	Float k = 0.0087266462599716477;		HX_STACK_VAR(k,"k");
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",197,0x6b269d66)
			{
				HX_STACK_LINE(197)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(197)
				int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(197)
				return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(197)
	::haxor::math::Vector3 e = (_Function_1_1::Block())->Set((v->x * k),(v->y * k),(v->z * k));		HX_STACK_VAR(e,"e");
	HX_STACK_LINE(198)
	Float _g3 = ::Math_obj::cos(e->x);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(198)
	Float _g4 = ::Math_obj::cos(e->y);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(198)
	Float _g5 = ::Math_obj::cos(e->z);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(198)
	c->Set(_g3,_g4,_g5);
	HX_STACK_LINE(199)
	Float _g6 = ::Math_obj::sin(e->x);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(199)
	Float _g7 = ::Math_obj::sin(e->y);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(199)
	Float _g8 = ::Math_obj::sin(e->z);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(199)
	s->Set(_g6,_g7,_g8);
	HX_STACK_LINE(200)
	this->x = (((s->x * c->y) * c->z) - ((c->x * s->y) * s->z));
	HX_STACK_LINE(201)
	this->y = (((c->x * s->y) * c->z) + ((s->x * c->y) * s->z));
	HX_STACK_LINE(202)
	this->z = (((c->x * c->y) * s->z) - ((s->x * s->y) * c->z));
	HX_STACK_LINE(203)
	this->w = (((c->x * c->y) * c->z) + ((s->x * s->y) * s->z));
	HX_STACK_LINE(204)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,set_euler,return )

::haxor::math::Quaternion Quaternion_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_clone",0x9b0cf7be,"haxor.math.Quaternion.get_clone","haxor/math/Quaternion.hx",211,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(211)
	return ::haxor::math::Quaternion_obj::__new(this->x,this->y,this->z,this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_clone,return )

::haxor::math::Vector4 Quaternion_obj::get_xyzw( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_xyzw",0x2c7658bd,"haxor.math.Quaternion.get_xyzw","haxor/math/Quaternion.hx",217,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(217)
	return ::haxor::math::Vector4_obj::__new(this->x,this->y,this->z,this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_xyzw,return )

Float Quaternion_obj::get_length( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_length",0xa1058565,"haxor.math.Quaternion.get_length","haxor/math/Quaternion.hx",223,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(223)
	return ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)) + (this->w * this->w)));
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_length,return )

::haxor::math::Quaternion Quaternion_obj::get_normalized( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_normalized",0x11090036,"haxor.math.Quaternion.get_normalized","haxor/math/Quaternion.hx",229,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(229)
	return ::haxor::math::Quaternion_obj::__new(this->x,this->y,this->z,this->w)->Normalize();
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_normalized,return )

::haxor::math::Quaternion Quaternion_obj::Set( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
Float p_w = __o_p_w.Default(1.0);
	HX_STACK_FRAME("haxor.math.Quaternion","Set",0x5b32d80c,"haxor.math.Quaternion.Set","haxor/math/Quaternion.hx",274,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
	HX_STACK_ARG(p_w,"p_w")
{
		HX_STACK_LINE(274)
		this->x = p_x;
		HX_STACK_LINE(274)
		this->y = p_y;
		HX_STACK_LINE(274)
		this->z = p_z;
		HX_STACK_LINE(274)
		this->w = p_w;
		HX_STACK_LINE(274)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Quaternion_obj,Set,return )

::haxor::math::Quaternion Quaternion_obj::SetQuaternion( ::haxor::math::Quaternion p_q){
	HX_STACK_FRAME("haxor.math.Quaternion","SetQuaternion",0xd518f04a,"haxor.math.Quaternion.SetQuaternion","haxor/math/Quaternion.hx",281,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_q,"p_q")
	HX_STACK_LINE(281)
	this->x = p_q->x;
	HX_STACK_LINE(281)
	this->y = p_q->y;
	HX_STACK_LINE(281)
	this->z = p_q->z;
	HX_STACK_LINE(281)
	this->w = p_q->w;
	HX_STACK_LINE(281)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,SetQuaternion,return )

::haxor::math::Quaternion Quaternion_obj::Normalize( ){
	HX_STACK_FRAME("haxor.math.Quaternion","Normalize",0x5c749f77,"haxor.math.Quaternion.Normalize","haxor/math/Quaternion.hx",288,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(289)
	Float l = ::Math_obj::sqrt(((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)) + (this->w * this->w)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(290)
	if (((l <= (int)0))){
		HX_STACK_LINE(292)
		Float _g = this->z = 0.0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(292)
		Float _g1 = this->y = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(292)
		this->x = _g1;
		HX_STACK_LINE(292)
		this->w = 1.0;
		HX_STACK_LINE(293)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(295)
	Float _g2 = l = (Float(1.0) / Float(l));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(295)
	hx::MultEq(this->x,_g2);
	HX_STACK_LINE(296)
	hx::MultEq(this->y,l);
	HX_STACK_LINE(297)
	hx::MultEq(this->z,l);
	HX_STACK_LINE(298)
	hx::MultEq(this->w,l);
	HX_STACK_LINE(299)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,Normalize,return )

::haxor::math::Quaternion Quaternion_obj::get_conjugate( ){
	HX_STACK_FRAME("haxor.math.Quaternion","get_conjugate",0xd3d35ef9,"haxor.math.Quaternion.get_conjugate","haxor/math/Quaternion.hx",306,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(306)
	return ::haxor::math::Quaternion_obj::__new(-(this->x),-(this->y),-(this->z),this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,get_conjugate,return )

::haxor::math::Quaternion Quaternion_obj::Invert( ){
	HX_STACK_FRAME("haxor.math.Quaternion","Invert",0x2ebbc8ec,"haxor.math.Quaternion.Invert","haxor/math/Quaternion.hx",312,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(312)
	this->x = -(this->x);
	HX_STACK_LINE(312)
	this->y = -(this->y);
	HX_STACK_LINE(312)
	this->z = -(this->z);
	HX_STACK_LINE(312)
	this->w = -(this->w);
	HX_STACK_LINE(312)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,Invert,return )

::haxor::math::Quaternion Quaternion_obj::Scale( Float p_v){
	HX_STACK_FRAME("haxor.math.Quaternion","Scale",0xae417974,"haxor.math.Quaternion.Scale","haxor/math/Quaternion.hx",319,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(319)
	hx::MultEq(this->x,p_v);
	HX_STACK_LINE(319)
	hx::MultEq(this->y,p_v);
	HX_STACK_LINE(319)
	hx::MultEq(this->z,p_v);
	HX_STACK_LINE(319)
	hx::MultEq(this->w,p_v);
	HX_STACK_LINE(319)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,Scale,return )

::haxor::math::Quaternion Quaternion_obj::Multiply( ::haxor::math::Quaternion p_v,hx::Null< bool >  __o_p_normalize){
bool p_normalize = __o_p_normalize.Default(true);
	HX_STACK_FRAME("haxor.math.Quaternion","Multiply",0xd14c657a,"haxor.math.Quaternion.Multiply","haxor/math/Quaternion.hx",328,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_normalize,"p_normalize")
{
		HX_STACK_LINE(329)
		Float vx = ((((this->w * p_v->x) + (this->x * p_v->w)) + (this->y * p_v->z)) - (this->z * p_v->y));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(330)
		Float vy = ((((this->w * p_v->y) + (this->y * p_v->w)) + (this->z * p_v->x)) - (this->x * p_v->z));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(331)
		Float vz = ((((this->w * p_v->z) + (this->z * p_v->w)) + (this->x * p_v->y)) - (this->y * p_v->x));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(332)
		Float vw = ((((this->w * p_v->w) - (this->x * p_v->x)) - (this->y * p_v->y)) - (this->z * p_v->z));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(333)
		this->x = vx;
		HX_STACK_LINE(333)
		this->y = vy;
		HX_STACK_LINE(333)
		this->z = vz;
		HX_STACK_LINE(333)
		this->w = vw;
		HX_STACK_LINE(334)
		if ((p_normalize)){
			HX_STACK_LINE(334)
			return this->Normalize();
		}
		else{
			HX_STACK_LINE(334)
			return hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(334)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Multiply,return )

::haxor::math::Vector3 Quaternion_obj::Multiply3( ::haxor::math::Vector3 p_v){
	HX_STACK_FRAME("haxor.math.Quaternion","Multiply3",0x518c6579,"haxor.math.Quaternion.Multiply3","haxor/math/Quaternion.hx",343,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(344)
	Float l = ::Math_obj::sqrt((((p_v->x * p_v->x) + (p_v->y * p_v->y)) + (p_v->z * p_v->z)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(345)
	Float nl = (Float(1.0) / Float(l));		HX_STACK_VAR(nl,"nl");
	HX_STACK_LINE(346)
	hx::MultEq(p_v->x,nl);
	HX_STACK_LINE(347)
	hx::MultEq(p_v->y,nl);
	HX_STACK_LINE(348)
	hx::MultEq(p_v->z,nl);
	HX_STACK_LINE(349)
	::haxor::math::Quaternion qv = ::haxor::math::Quaternion_obj::__new(p_v->x,p_v->y,p_v->z,(int)0);		HX_STACK_VAR(qv,"qv");
	HX_STACK_LINE(350)
	::haxor::math::Quaternion a = ::haxor::math::Quaternion_obj::__new(this->x,this->y,this->z,this->w);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(351)
	::haxor::math::Quaternion _g = ::haxor::math::Quaternion_obj::__new(-(this->x),-(this->y),-(this->z),this->w);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(351)
	::haxor::math::Quaternion _g1 = qv->Multiply(_g,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(351)
	a->Multiply(_g1,null());
	HX_STACK_LINE(352)
	p_v->x = (a->x * l);
	HX_STACK_LINE(353)
	p_v->y = (a->y * l);
	HX_STACK_LINE(354)
	p_v->z = (a->z * l);
	HX_STACK_LINE(355)
	return p_v;
}


HX_DEFINE_DYNAMIC_FUNC1(Quaternion_obj,Multiply3,return )

::haxor::math::Quaternion Quaternion_obj::SetAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle){
	HX_STACK_FRAME("haxor.math.Quaternion","SetAxisAngle",0xa588d5c6,"haxor.math.Quaternion.SetAxisAngle","haxor/math/Quaternion.hx",365,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_axis,"p_axis")
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(366)
	p_angle = ((p_angle * 0.5) * 0.01745329251994329576923690768489);
	HX_STACK_LINE(367)
	Float l = ::Math_obj::sqrt((((p_axis->x * p_axis->x) + (p_axis->y * p_axis->y)) + (p_axis->z * p_axis->z)));		HX_STACK_VAR(l,"l");
	struct _Function_1_1{
		inline static Float Block( Float &l){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",368,0x6b269d66)
			{
				HX_STACK_LINE(368)
				Float p_a = (l - 1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(368)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(368)
	if (((_Function_1_1::Block(l) > 0.0001))){
		HX_STACK_LINE(368)
		p_axis->Normalize();
	}
	HX_STACK_LINE(369)
	Float s = ::Math_obj::sin(p_angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(370)
	Float _g = ::Math_obj::cos(p_angle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(370)
	this->Set((p_axis->x * s),(p_axis->y * s),(p_axis->z * s),_g);
	HX_STACK_LINE(371)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,SetAxisAngle,return )

Array< Float > Quaternion_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Quaternion","ToArray",0x69b67388,"haxor.math.Quaternion.ToArray","haxor/math/Quaternion.hx",378,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_LINE(378)
	return Array_obj< Float >::__new().Add(this->x).Add(this->y).Add(this->z).Add(this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Quaternion_obj,ToArray,return )

::String Quaternion_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Quaternion","ToString",0x6f2e5402,"haxor.math.Quaternion.ToString","haxor/math/Quaternion.hx",384,0x6b269d66)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(384)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(384)
		{
			HX_STACK_LINE(384)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(384)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(384)
			{
				HX_STACK_LINE(384)
				Float p_v = (this->x * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(384)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(384)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(384)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(384)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(384)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(384)
		{
			HX_STACK_LINE(384)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(384)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(384)
			{
				HX_STACK_LINE(384)
				Float p_v = (this->y * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(384)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(384)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(384)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(384)
		::String _g7 = (_g6 + HX_CSTRING(","));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(384)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(384)
		{
			HX_STACK_LINE(384)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(384)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(384)
			{
				HX_STACK_LINE(384)
				Float p_v = (this->z * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(384)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(384)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(384)
		::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(384)
		::String _g11 = (_g10 + HX_CSTRING(","));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(384)
		Float _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(384)
		{
			HX_STACK_LINE(384)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(384)
			Float _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(384)
			{
				HX_STACK_LINE(384)
				Float p_v = (this->w * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(384)
				_g12 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(384)
			_g13 = (Float(_g12) / Float(d));
		}
		HX_STACK_LINE(384)
		::String _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(384)
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

::haxor::math::Quaternion Quaternion_obj::FromMatrix( ::haxor::math::Matrix4 p_matrix,::haxor::math::Quaternion p_result){
	HX_STACK_FRAME("haxor.math.Quaternion","FromMatrix",0x0733c021,"haxor.math.Quaternion.FromMatrix","haxor/math/Quaternion.hx",30,0x6b269d66)
	HX_STACK_ARG(p_matrix,"p_matrix")
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
	::haxor::math::Matrix4 v = p_matrix;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(33)
	Float fourXSquaredMinus1 = ((v->m00 - v->m11) - v->m22);		HX_STACK_VAR(fourXSquaredMinus1,"fourXSquaredMinus1");
	HX_STACK_LINE(34)
	Float fourYSquaredMinus1 = ((v->m11 - v->m00) - v->m22);		HX_STACK_VAR(fourYSquaredMinus1,"fourYSquaredMinus1");
	HX_STACK_LINE(35)
	Float fourZSquaredMinus1 = ((v->m22 - v->m00) - v->m11);		HX_STACK_VAR(fourZSquaredMinus1,"fourZSquaredMinus1");
	HX_STACK_LINE(36)
	Float fourWSquaredMinus1 = ((v->m00 + v->m11) + v->m22);		HX_STACK_VAR(fourWSquaredMinus1,"fourWSquaredMinus1");
	HX_STACK_LINE(37)
	int biggestIndex = (int)0;		HX_STACK_VAR(biggestIndex,"biggestIndex");
	HX_STACK_LINE(38)
	Float fourBiggestSquaredMinus1 = fourWSquaredMinus1;		HX_STACK_VAR(fourBiggestSquaredMinus1,"fourBiggestSquaredMinus1");
	HX_STACK_LINE(39)
	if (((fourXSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(39)
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		HX_STACK_LINE(39)
		biggestIndex = (int)1;
	}
	HX_STACK_LINE(40)
	if (((fourYSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(40)
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		HX_STACK_LINE(40)
		biggestIndex = (int)2;
	}
	HX_STACK_LINE(41)
	if (((fourZSquaredMinus1 > fourBiggestSquaredMinus1))){
		HX_STACK_LINE(41)
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		HX_STACK_LINE(41)
		biggestIndex = (int)3;
	}
	HX_STACK_LINE(42)
	Float _g = ::Math_obj::sqrt((fourBiggestSquaredMinus1 + 1.0));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(42)
	Float biggestVal = (_g * 0.5);		HX_STACK_VAR(biggestVal,"biggestVal");
	HX_STACK_LINE(43)
	Float mult = (Float(0.25) / Float(biggestVal));		HX_STACK_VAR(mult,"mult");
	HX_STACK_LINE(44)
	switch( (int)(biggestIndex)){
		case (int)0: {
			HX_STACK_LINE(46)
			r->w = biggestVal;
			HX_STACK_LINE(46)
			r->x = (((v->m21 - v->m12)) * mult);
			HX_STACK_LINE(46)
			r->y = (((v->m02 - v->m20)) * mult);
			HX_STACK_LINE(46)
			r->z = (((v->m10 - v->m01)) * mult);
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(47)
			r->w = (((v->m21 - v->m12)) * mult);
			HX_STACK_LINE(47)
			r->x = biggestVal;
			HX_STACK_LINE(47)
			r->y = (((v->m10 + v->m01)) * mult);
			HX_STACK_LINE(47)
			r->z = (((v->m02 + v->m20)) * mult);
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(48)
			r->w = (((v->m02 - v->m20)) * mult);
			HX_STACK_LINE(48)
			r->x = (((v->m10 + v->m01)) * mult);
			HX_STACK_LINE(48)
			r->y = biggestVal;
			HX_STACK_LINE(48)
			r->z = (((v->m21 + v->m12)) * mult);
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(49)
			r->w = (((v->m10 - v->m01)) * mult);
			HX_STACK_LINE(49)
			r->x = (((v->m02 + v->m20)) * mult);
			HX_STACK_LINE(49)
			r->y = (((v->m21 + v->m12)) * mult);
			HX_STACK_LINE(49)
			r->z = biggestVal;
		}
		;break;
	}
	HX_STACK_LINE(51)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,FromMatrix,return )

Float Quaternion_obj::Dot( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b){
	HX_STACK_FRAME("haxor.math.Quaternion","Dot",0x5b277ef3,"haxor.math.Quaternion.Dot","haxor/math/Quaternion.hx",60,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(60)
	return ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,Dot,return )

::haxor::math::Quaternion Quaternion_obj::Lerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Quaternion","Lerp",0x6ca9b2cd,"haxor.math.Quaternion.Lerp","haxor/math/Quaternion.hx",70,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_LINE(71)
	::haxor::math::Quaternion c = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(72)
	::haxor::math::Quaternion ca = ::haxor::math::Quaternion_obj::__new(p_a->x,p_a->y,p_a->z,p_a->w);		HX_STACK_VAR(ca,"ca");
	HX_STACK_LINE(73)
	Float dot = ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(74)
	if (((dot < 0.0))){
		HX_STACK_LINE(76)
		ca->w = -(ca->w);
		HX_STACK_LINE(77)
		ca->x = -(ca->x);
		HX_STACK_LINE(78)
		ca->y = -(ca->y);
		HX_STACK_LINE(79)
		ca->z = -(ca->z);
	}
	HX_STACK_LINE(81)
	c->x = (ca->x + (((p_b->x - ca->x)) * p_ratio));
	HX_STACK_LINE(82)
	c->y = (ca->y + (((p_b->y - ca->y)) * p_ratio));
	HX_STACK_LINE(83)
	c->z = (ca->z + (((p_b->z - ca->z)) * p_ratio));
	HX_STACK_LINE(84)
	c->w = (ca->w + (((p_b->w - ca->w)) * p_ratio));
	HX_STACK_LINE(85)
	c->Normalize();
	HX_STACK_LINE(86)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Quaternion_obj,Lerp,return )

::haxor::math::Quaternion Quaternion_obj::Slerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Quaternion","Slerp",0xb4377354,"haxor.math.Quaternion.Slerp","haxor/math/Quaternion.hx",97,0x6b269d66)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_LINE(99)
	::haxor::math::Quaternion qm = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(qm,"qm");
	struct _Function_1_1{
		inline static ::haxor::math::Quaternion Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",100,0x6b269d66)
			{
				HX_STACK_LINE(100)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(100)
				int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(100)
				return _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
			}
			return null();
		}
	};
	HX_STACK_LINE(100)
	::haxor::math::Quaternion z = (_Function_1_1::Block())->SetQuaternion(p_b);		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(101)
	Float cosTheta = ((((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z)) + (p_a->w * p_b->w));		HX_STACK_VAR(cosTheta,"cosTheta");
	HX_STACK_LINE(104)
	if (((cosTheta < 0.0))){
		HX_STACK_LINE(106)
		z->Invert();
		HX_STACK_LINE(107)
		cosTheta = -(cosTheta);
	}
	HX_STACK_LINE(111)
	if (((cosTheta > 0.9999))){
		struct _Function_2_1{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",115,0x6b269d66)
				{
					HX_STACK_LINE(115)
					Float p_a1 = p_a->x;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(115)
					return (p_a1 + (((z->x - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",116,0x6b269d66)
				{
					HX_STACK_LINE(116)
					Float p_a1 = p_a->y;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(116)
					return (p_a1 + (((z->y - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_3{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",117,0x6b269d66)
				{
					HX_STACK_LINE(117)
					Float p_a1 = p_a->z;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(117)
					return (p_a1 + (((z->z - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		struct _Function_2_4{
			inline static Float Block( ::haxor::math::Quaternion &p_a,::haxor::math::Quaternion &z,Float &p_ratio){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",118,0x6b269d66)
				{
					HX_STACK_LINE(118)
					Float p_a1 = p_a->w;		HX_STACK_VAR(p_a1,"p_a1");
					HX_STACK_LINE(118)
					return (p_a1 + (((z->w - p_a1)) * p_ratio));
				}
				return null();
			}
		};
		HX_STACK_LINE(114)
		qm->Set(_Function_2_1::Block(p_a,z,p_ratio),_Function_2_2::Block(p_a,z,p_ratio),_Function_2_3::Block(p_a,z,p_ratio),_Function_2_4::Block(p_a,z,p_ratio));
	}
	else{
		HX_STACK_LINE(123)
		Float angle = ::Math_obj::acos(cosTheta);		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(124)
		Float _g1 = ::Math_obj::sin(angle);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(124)
		Float s = (Float(1.0) / Float(_g1));		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(125)
		Float s0 = ::Math_obj::sin((((1.0 - p_ratio)) * angle));		HX_STACK_VAR(s0,"s0");
		HX_STACK_LINE(126)
		Float s1 = ::Math_obj::sin((p_ratio * angle));		HX_STACK_VAR(s1,"s1");
		HX_STACK_LINE(127)
		qm->x = ((((s0 * p_a->x) + (s1 * z->x))) * s);
		HX_STACK_LINE(128)
		qm->y = ((((s0 * p_a->y) + (s1 * z->y))) * s);
		HX_STACK_LINE(129)
		qm->z = ((((s0 * p_a->z) + (s1 * z->z))) * s);
		HX_STACK_LINE(130)
		qm->w = ((((s0 * p_a->w) + (s1 * z->w))) * s);
	}
	HX_STACK_LINE(132)
	return qm;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Quaternion_obj,Slerp,return )

::haxor::math::Quaternion Quaternion_obj::FromAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle){
	HX_STACK_FRAME("haxor.math.Quaternion","FromAxisAngle",0x08461192,"haxor.math.Quaternion.FromAxisAngle","haxor/math/Quaternion.hx",142,0x6b269d66)
	HX_STACK_ARG(p_axis,"p_axis")
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(143)
	p_angle = ((p_angle * 0.5) * 0.01745329251994329576923690768489);
	HX_STACK_LINE(144)
	Float l = ::Math_obj::sqrt((((p_axis->x * p_axis->x) + (p_axis->y * p_axis->y)) + (p_axis->z * p_axis->z)));		HX_STACK_VAR(l,"l");
	struct _Function_1_1{
		inline static Float Block( Float &l){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",145,0x6b269d66)
			{
				HX_STACK_LINE(145)
				Float p_a = (l - 1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(145)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(145)
	if (((_Function_1_1::Block(l) > 0.0001))){
		HX_STACK_LINE(145)
		p_axis->Normalize();
	}
	HX_STACK_LINE(146)
	Float s = ::Math_obj::sin(p_angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(147)
	Float _g = ::Math_obj::cos(p_angle);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(147)
	return ::haxor::math::Quaternion_obj::__new((p_axis->x * s),(p_axis->y * s),(p_axis->z * s),_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,FromAxisAngle,return )

::haxor::math::Quaternion Quaternion_obj::LookAt( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up){
	HX_STACK_FRAME("haxor.math.Quaternion","LookAt",0xf0985708,"haxor.math.Quaternion.LookAt","haxor/math/Quaternion.hx",159,0x6b269d66)
	HX_STACK_ARG(p_from,"p_from")
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_LINE(159)
	return ::haxor::math::Matrix4_obj::LookAt(p_from,p_at,p_up,null())->get_quaternion();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Quaternion_obj,LookAt,return )

::haxor::math::Quaternion Quaternion_obj::LookRotation( ::haxor::math::Vector3 p_forward,::haxor::math::Vector3 p_up){
	HX_STACK_FRAME("haxor.math.Quaternion","LookRotation",0x0f4e7d13,"haxor.math.Quaternion.LookRotation","haxor/math/Quaternion.hx",169,0x6b269d66)
	HX_STACK_ARG(p_forward,"p_forward")
	HX_STACK_ARG(p_up,"p_up")
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Quaternion.hx",170,0x6b269d66)
			{
				HX_STACK_LINE(170)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(170)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(170)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(170)
	::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(170)
	return ::haxor::math::Matrix4_obj::LookAt(_g1,p_forward,p_up,null())->get_quaternion();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Quaternion_obj,LookRotation,return )


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
		if (HX_FIELD_EQ(inName,"euler") ) { return get_euler(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"Scale") ) { return Scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"LookAt") ) { return LookAt_dyn(); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return get_matrix(); }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Invert") ) { return Invert_dyn(); }
		break;
	case 7:
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
		if (HX_FIELD_EQ(inName,"get_euler") ) { return get_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"set_euler") ) { return set_euler_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		if (HX_FIELD_EQ(inName,"conjugate") ) { return inCallProp ? get_conjugate() : conjugate; }
		if (HX_FIELD_EQ(inName,"Multiply3") ) { return Multiply3_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromMatrix") ) { return FromMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"get_matrix") ) { return get_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"set_matrix") ) { return set_matrix_dyn(); }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"normalized") ) { return inCallProp ? get_normalized() : normalized; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_identity") ) { return get_identity_dyn(); }
		if (HX_FIELD_EQ(inName,"LookRotation") ) { return LookRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"SetAxisAngle") ) { return SetAxisAngle_dyn(); }
		break;
	case 13:
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
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("identity"),
	HX_CSTRING("get_identity"),
	HX_CSTRING("FromMatrix"),
	HX_CSTRING("Dot"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Slerp"),
	HX_CSTRING("FromAxisAngle"),
	HX_CSTRING("LookAt"),
	HX_CSTRING("LookRotation"),
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
	HX_CSTRING("Invert"),
	HX_CSTRING("Scale"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Multiply3"),
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
