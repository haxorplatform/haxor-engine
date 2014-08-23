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
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
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

Void Vector2_obj::__construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y)
{
HX_STACK_FRAME("haxor.math.Vector2","new",0x45778267,"haxor.math.Vector2.new","haxor/math/Vector2.hx",119,0x4f419b49)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_x,"p_x")
HX_STACK_ARG(__o_p_y,"p_y")
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
{
	HX_STACK_LINE(120)
	this->x = p_x;
	HX_STACK_LINE(121)
	this->y = p_y;
}
;
	return null();
}

//Vector2_obj::~Vector2_obj() { }

Dynamic Vector2_obj::__CreateEmpty() { return  new Vector2_obj; }
hx::ObjectPtr< Vector2_obj > Vector2_obj::__new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y)
{  hx::ObjectPtr< Vector2_obj > result = new Vector2_obj();
	result->__construct(__o_p_x,__o_p_y);
	return result;}

Dynamic Vector2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector2_obj > result = new Vector2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::haxor::math::Vector2 Vector2_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_clone",0xdd17e0fb,"haxor.math.Vector2.get_clone","haxor/math/Vector2.hx",67,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(67)
	return ::haxor::math::Vector2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_clone,return )

::haxor::math::Vector2 Vector2_obj::get_xy( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_xy",0xa2880ca3,"haxor.math.Vector2.get_xy","haxor/math/Vector2.hx",72,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	return ::haxor::math::Vector2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_xy,return )

::haxor::math::Vector2 Vector2_obj::get_yx( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_yx",0xa2880d81,"haxor.math.Vector2.get_yx","haxor/math/Vector2.hx",77,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return ::haxor::math::Vector2_obj::__new(this->y,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_yx,return )

Float Vector2_obj::get_length( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_length",0x2886b188,"haxor.math.Vector2.get_length","haxor/math/Vector2.hx",83,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_length,return )

Float Vector2_obj::get_lengthSqr( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_lengthSqr",0xc822516c,"haxor.math.Vector2.get_lengthSqr","haxor/math/Vector2.hx",89,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(89)
	return ((this->x * this->x) + (this->y * this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_lengthSqr,return )

::haxor::math::Vector2 Vector2_obj::get_normalized( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_normalized",0xb59679d9,"haxor.math.Vector2.get_normalized","haxor/math/Vector2.hx",95,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return ::haxor::math::Vector2_obj::__new(this->x,this->y)->Normalize();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_normalized,return )

::haxor::math::Vector2 Vector2_obj::get_inverse( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_inverse",0x03ab3cce,"haxor.math.Vector2.get_inverse","haxor/math/Vector2.hx",101,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(101)
	::haxor::math::Vector2 _this = ::haxor::math::Vector2_obj::__new(this->x,this->y);		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(101)
	_this->x = -(_this->x);
	HX_STACK_LINE(101)
	_this->y = -(_this->y);
	HX_STACK_LINE(101)
	return _this;
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_inverse,return )

::haxor::math::Vector2 Vector2_obj::Set( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
	HX_STACK_FRAME("haxor.math.Vector2","Set",0x45630589,"haxor.math.Vector2.Set","haxor/math/Vector2.hx",131,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
{
		HX_STACK_LINE(131)
		this->x = p_x;
		HX_STACK_LINE(131)
		this->y = p_y;
		HX_STACK_LINE(131)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Set,return )

::haxor::math::Vector2 Vector2_obj::Set2( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.Vector2","Set2",0x7141d289,"haxor.math.Vector2.Set2","haxor/math/Vector2.hx",138,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(138)
	this->x = v->x;
	HX_STACK_LINE(138)
	this->y = v->y;
	HX_STACK_LINE(138)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Set2,return )

::haxor::math::Vector2 Vector2_obj::Set3( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Vector2","Set3",0x7141d28a,"haxor.math.Vector2.Set3","haxor/math/Vector2.hx",145,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(145)
	this->x = v->x;
	HX_STACK_LINE(145)
	this->y = v->y;
	HX_STACK_LINE(145)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Set3,return )

::haxor::math::Vector2 Vector2_obj::Set4( ::haxor::math::Vector4 v){
	HX_STACK_FRAME("haxor.math.Vector2","Set4",0x7141d28b,"haxor.math.Vector2.Set4","haxor/math/Vector2.hx",152,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(152)
	this->x = v->x;
	HX_STACK_LINE(152)
	this->y = v->y;
	HX_STACK_LINE(152)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Set4,return )

Float Vector2_obj::Get( int p){
	HX_STACK_FRAME("haxor.math.Vector2","Get",0x4559ea7d,"haxor.math.Vector2.Get","haxor/math/Vector2.hx",159,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(159)
	if (((p == (int)0))){
		HX_STACK_LINE(159)
		return this->x;
	}
	else{
		HX_STACK_LINE(159)
		return this->y;
	}
	HX_STACK_LINE(159)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Get,return )

::haxor::math::Vector2 Vector2_obj::Add( ::haxor::math::Vector2 p_v){
	HX_STACK_FRAME("haxor.math.Vector2","Add",0x45555c08,"haxor.math.Vector2.Add","haxor/math/Vector2.hx",166,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(166)
	hx::AddEq(this->x,p_v->x);
	HX_STACK_LINE(166)
	hx::AddEq(this->y,p_v->y);
	HX_STACK_LINE(166)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Add,return )

::haxor::math::Vector2 Vector2_obj::Sub( ::haxor::math::Vector2 p_v){
	HX_STACK_FRAME("haxor.math.Vector2","Sub",0x45631367,"haxor.math.Vector2.Sub","haxor/math/Vector2.hx",173,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(173)
	hx::SubEq(this->x,p_v->x);
	HX_STACK_LINE(173)
	hx::SubEq(this->y,p_v->y);
	HX_STACK_LINE(173)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Sub,return )

::haxor::math::Vector2 Vector2_obj::Multiply( ::haxor::math::Vector2 p_v){
	HX_STACK_FRAME("haxor.math.Vector2","Multiply",0x02f532dd,"haxor.math.Vector2.Multiply","haxor/math/Vector2.hx",180,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(180)
	hx::MultEq(this->x,p_v->x);
	HX_STACK_LINE(180)
	hx::MultEq(this->y,p_v->y);
	HX_STACK_LINE(180)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Multiply,return )

::haxor::math::Vector2 Vector2_obj::Scale( Float p_s){
	HX_STACK_FRAME("haxor.math.Vector2","Scale",0xa6f5c031,"haxor.math.Vector2.Scale","haxor/math/Vector2.hx",187,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(187)
	hx::MultEq(this->x,p_s);
	HX_STACK_LINE(187)
	hx::MultEq(this->y,p_s);
	HX_STACK_LINE(187)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Scale,return )

bool Vector2_obj::Step( ::haxor::math::Vector2 p_to,Float p_step){
	HX_STACK_FRAME("haxor.math.Vector2","Step",0x714d2785,"haxor.math.Vector2.Step","haxor/math/Vector2.hx",196,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_to,"p_to")
	HX_STACK_ARG(p_step,"p_step")
	HX_STACK_LINE(197)
	Float vx = (p_to->x - this->x);		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(198)
	Float vy = (p_to->y - this->y);		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(199)
	Float l = ::Math_obj::sqrt(((vx * vx) + (vy * vy)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(200)
	if (((l <= 0.0001))){
		HX_STACK_LINE(200)
		return false;
	}
	HX_STACK_LINE(201)
	Float s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(201)
	if (((p_step > l))){
		HX_STACK_LINE(201)
		s = l;
	}
	else{
		HX_STACK_LINE(201)
		s = p_step;
	}
	HX_STACK_LINE(202)
	l = (Float(s) / Float(l));
	HX_STACK_LINE(203)
	hx::MultEq(vx,l);
	HX_STACK_LINE(204)
	hx::MultEq(vy,l);
	HX_STACK_LINE(205)
	hx::AddEq(this->x,vx);
	HX_STACK_LINE(206)
	hx::AddEq(this->y,vy);
	HX_STACK_LINE(207)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Step,return )

::haxor::math::Vector2 Vector2_obj::Reflect( ::haxor::math::Vector2 p_normal){
	HX_STACK_FRAME("haxor.math.Vector2","Reflect",0x242d6da4,"haxor.math.Vector2.Reflect","haxor/math/Vector2.hx",216,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_normal,"p_normal")
	HX_STACK_LINE(217)
	Float _g = ::Math_obj::min(0.0,((p_normal->x * this->x) + (p_normal->y * this->y)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(217)
	Float d = (_g * 2.0);		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(218)
	hx::AddEq(this->x,(-(p_normal->x) * d));
	HX_STACK_LINE(219)
	hx::AddEq(this->y,(-(p_normal->y) * d));
	HX_STACK_LINE(220)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Reflect,return )

::haxor::math::Vector2 Vector2_obj::Invert( ){
	HX_STACK_FRAME("haxor.math.Vector2","Invert",0xd3c5678f,"haxor.math.Vector2.Invert","haxor/math/Vector2.hx",227,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(227)
	this->x = -(this->x);
	HX_STACK_LINE(227)
	this->y = -(this->y);
	HX_STACK_LINE(227)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,Invert,return )

::haxor::math::Vector2 Vector2_obj::Normalize( ){
	HX_STACK_FRAME("haxor.math.Vector2","Normalize",0x9e7f88b4,"haxor.math.Vector2.Normalize","haxor/math/Vector2.hx",234,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(235)
	Float l = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(236)
	if (((l <= (int)0))){
		HX_STACK_LINE(236)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(237)
	Float _g = l = (Float(1.0) / Float(l));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(237)
	hx::MultEq(this->x,_g);
	HX_STACK_LINE(238)
	hx::MultEq(this->y,l);
	HX_STACK_LINE(239)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,Normalize,return )

Array< Float > Vector2_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Vector2","ToArray",0x2d17a385,"haxor.math.Vector2.ToArray","haxor/math/Vector2.hx",246,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_LINE(246)
	return Array_obj< Float >::__new().Add(this->x).Add(this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,ToArray,return )

::String Vector2_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Vector2","ToString",0xa0d72165,"haxor.math.Vector2.ToString","haxor/math/Vector2.hx",252,0x4f419b49)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(252)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(252)
		{
			HX_STACK_LINE(252)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(252)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(252)
			{
				HX_STACK_LINE(252)
				Float p_v = (this->x * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(252)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(252)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(252)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(252)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(252)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(252)
		{
			HX_STACK_LINE(252)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(252)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(252)
			{
				HX_STACK_LINE(252)
				Float p_v = (this->y * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(252)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(252)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(252)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(252)
		return (_g6 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,ToString,return )

::haxor::math::Vector2 Vector2_obj::temp;

::haxor::math::Vector2 Vector2_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_temp",0x5b6b1336,"haxor.math.Vector2.get_temp","haxor/math/Vector2.hx",14,0x4f419b49)
	HX_STACK_LINE(14)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(14)
	int _g = _this->m_nv2 = hx::Mod(((_this->m_nv2 + (int)1)),_this->m_v2->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	return _this->m_v2->__get(_g).StaticCast< ::haxor::math::Vector2 >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_temp,return )

::haxor::math::Vector2 Vector2_obj::zero;

::haxor::math::Vector2 Vector2_obj::get_zero( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_zero",0x5f625f4a,"haxor.math.Vector2.get_zero","haxor/math/Vector2.hx",20,0x4f419b49)
	HX_STACK_LINE(20)
	return ::haxor::math::Vector2_obj::__new((int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_zero,return )

::haxor::math::Vector2 Vector2_obj::one;

::haxor::math::Vector2 Vector2_obj::get_one( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_one",0x947c2484,"haxor.math.Vector2.get_one","haxor/math/Vector2.hx",26,0x4f419b49)
	HX_STACK_LINE(26)
	return ::haxor::math::Vector2_obj::__new((int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_one,return )

::haxor::math::Vector2 Vector2_obj::right;

::haxor::math::Vector2 Vector2_obj::get_right( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_right",0x7e18d97a,"haxor.math.Vector2.get_right","haxor/math/Vector2.hx",32,0x4f419b49)
	HX_STACK_LINE(32)
	return ::haxor::math::Vector2_obj::__new((int)1,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_right,return )

::haxor::math::Vector2 Vector2_obj::up;

::haxor::math::Vector2 Vector2_obj::get_up( ){
	HX_STACK_FRAME("haxor.math.Vector2","get_up",0xa28809fd,"haxor.math.Vector2.get_up","haxor/math/Vector2.hx",38,0x4f419b49)
	HX_STACK_LINE(38)
	return ::haxor::math::Vector2_obj::__new((int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,get_up,return )

Float Vector2_obj::Dot( ::haxor::math::Vector2 p_a,::haxor::math::Vector2 p_b){
	HX_STACK_FRAME("haxor.math.Vector2","Dot",0x4557ac70,"haxor.math.Vector2.Dot","haxor/math/Vector2.hx",46,0x4f419b49)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(46)
	return ((p_a->x * p_b->x) + (p_a->y * p_b->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Dot,return )

::haxor::math::Vector2 Vector2_obj::Lerp( ::haxor::math::Vector2 p_a,::haxor::math::Vector2 p_b,Float p_r){
	HX_STACK_FRAME("haxor.math.Vector2","Lerp",0x6ca152b0,"haxor.math.Vector2.Lerp","haxor/math/Vector2.hx",57,0x4f419b49)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_LINE(57)
	return ::haxor::math::Vector2_obj::__new((p_a->x + (((p_b->x - p_a->x)) * p_r)),(p_a->y + (((p_b->y - p_a->y)) * p_r)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector2_obj,Lerp,return )


Vector2_obj::Vector2_obj()
{
}

void Vector2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector2);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(xy,"xy");
	HX_MARK_MEMBER_NAME(yx,"yx");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(lengthSqr,"lengthSqr");
	HX_MARK_MEMBER_NAME(normalized,"normalized");
	HX_MARK_MEMBER_NAME(inverse,"inverse");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

void Vector2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(xy,"xy");
	HX_VISIT_MEMBER_NAME(yx,"yx");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(lengthSqr,"lengthSqr");
	HX_VISIT_MEMBER_NAME(normalized,"normalized");
	HX_VISIT_MEMBER_NAME(inverse,"inverse");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
}

Dynamic Vector2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"up") ) { return inCallProp ? get_up() : up; }
		if (HX_FIELD_EQ(inName,"xy") ) { return inCallProp ? get_xy() : xy; }
		if (HX_FIELD_EQ(inName,"yx") ) { return inCallProp ? get_yx() : yx; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"one") ) { return inCallProp ? get_one() : one; }
		if (HX_FIELD_EQ(inName,"Dot") ) { return Dot_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Sub") ) { return Sub_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		if (HX_FIELD_EQ(inName,"zero") ) { return inCallProp ? get_zero() : zero; }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"Set2") ) { return Set2_dyn(); }
		if (HX_FIELD_EQ(inName,"Set3") ) { return Set3_dyn(); }
		if (HX_FIELD_EQ(inName,"Set4") ) { return Set4_dyn(); }
		if (HX_FIELD_EQ(inName,"Step") ) { return Step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? get_right() : right; }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"Scale") ) { return Scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_up") ) { return get_up_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xy") ) { return get_xy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yx") ) { return get_yx_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Invert") ) { return Invert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_one") ) { return get_one_dyn(); }
		if (HX_FIELD_EQ(inName,"inverse") ) { return inCallProp ? get_inverse() : inverse; }
		if (HX_FIELD_EQ(inName,"Reflect") ) { return Reflect_dyn(); }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zero") ) { return get_zero_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"lengthSqr") ) { return inCallProp ? get_lengthSqr() : lengthSqr; }
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"normalized") ) { return inCallProp ? get_normalized() : normalized; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_inverse") ) { return get_inverse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_lengthSqr") ) { return get_lengthSqr_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_normalized") ) { return get_normalized_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"up") ) { up=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xy") ) { xy=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yx") ) { yx=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"one") ) { one=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zero") ) { zero=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { right=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"inverse") ) { inverse=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"lengthSqr") ) { lengthSqr=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"normalized") ) { normalized=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("xy"));
	outFields->push(HX_CSTRING("yx"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("lengthSqr"));
	outFields->push(HX_CSTRING("normalized"));
	outFields->push(HX_CSTRING("inverse"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("zero"),
	HX_CSTRING("get_zero"),
	HX_CSTRING("one"),
	HX_CSTRING("get_one"),
	HX_CSTRING("right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("up"),
	HX_CSTRING("get_up"),
	HX_CSTRING("Dot"),
	HX_CSTRING("Lerp"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector2_obj,clone),HX_CSTRING("clone")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector2_obj,xy),HX_CSTRING("xy")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector2_obj,yx),HX_CSTRING("yx")},
	{hx::fsFloat,(int)offsetof(Vector2_obj,length),HX_CSTRING("length")},
	{hx::fsFloat,(int)offsetof(Vector2_obj,lengthSqr),HX_CSTRING("lengthSqr")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector2_obj,normalized),HX_CSTRING("normalized")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector2_obj,inverse),HX_CSTRING("inverse")},
	{hx::fsFloat,(int)offsetof(Vector2_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Vector2_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_clone"),
	HX_CSTRING("xy"),
	HX_CSTRING("get_xy"),
	HX_CSTRING("yx"),
	HX_CSTRING("get_yx"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("lengthSqr"),
	HX_CSTRING("get_lengthSqr"),
	HX_CSTRING("normalized"),
	HX_CSTRING("get_normalized"),
	HX_CSTRING("inverse"),
	HX_CSTRING("get_inverse"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("Set"),
	HX_CSTRING("Set2"),
	HX_CSTRING("Set3"),
	HX_CSTRING("Set4"),
	HX_CSTRING("Get"),
	HX_CSTRING("Add"),
	HX_CSTRING("Sub"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Scale"),
	HX_CSTRING("Step"),
	HX_CSTRING("Reflect"),
	HX_CSTRING("Invert"),
	HX_CSTRING("Normalize"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector2_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vector2_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(Vector2_obj::zero,"zero");
	HX_MARK_MEMBER_NAME(Vector2_obj::one,"one");
	HX_MARK_MEMBER_NAME(Vector2_obj::right,"right");
	HX_MARK_MEMBER_NAME(Vector2_obj::up,"up");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector2_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vector2_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(Vector2_obj::zero,"zero");
	HX_VISIT_MEMBER_NAME(Vector2_obj::one,"one");
	HX_VISIT_MEMBER_NAME(Vector2_obj::right,"right");
	HX_VISIT_MEMBER_NAME(Vector2_obj::up,"up");
};

#endif

Class Vector2_obj::__mClass;

void Vector2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Vector2"), hx::TCanCast< Vector2_obj> ,sStaticFields,sMemberFields,
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

void Vector2_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
