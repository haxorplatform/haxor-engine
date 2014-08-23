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
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
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

Void Color_obj::__construct(hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a)
{
HX_STACK_FRAME("haxor.math.Color","new",0x176a4e3b,"haxor.math.Color.new","haxor/math/Color.hx",254,0x18984df5)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_r,"p_r")
HX_STACK_ARG(__o_p_g,"p_g")
HX_STACK_ARG(__o_p_b,"p_b")
HX_STACK_ARG(__o_p_a,"p_a")
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(1);
{
	HX_STACK_LINE(255)
	this->r = p_r;
	HX_STACK_LINE(256)
	this->g = p_g;
	HX_STACK_LINE(257)
	this->b = p_b;
	HX_STACK_LINE(258)
	this->a = p_a;
}
;
	return null();
}

//Color_obj::~Color_obj() { }

Dynamic Color_obj::__CreateEmpty() { return  new Color_obj; }
hx::ObjectPtr< Color_obj > Color_obj::__new(hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a)
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct(__o_p_r,__o_p_g,__o_p_b,__o_p_a);
	return result;}

Dynamic Color_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Color_obj > result = new Color_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::haxor::math::Color Color_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Color","get_clone",0xa57b43cf,"haxor.math.Color.get_clone","haxor/math/Color.hx",132,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(132)
	return ::haxor::math::Color_obj::__new(this->r,this->g,this->b,this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_clone,return )

::haxor::math::Vector3 Color_obj::get_xyz( ){
	HX_STACK_FRAME("haxor.math.Color","get_xyz",0xb02a484b,"haxor.math.Color.get_xyz","haxor/math/Color.hx",138,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	return ::haxor::math::Vector3_obj::__new(this->r,this->g,this->b);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_xyz,return )

::haxor::math::Vector4 Color_obj::get_xyzw( ){
	HX_STACK_FRAME("haxor.math.Color","get_xyzw",0x74d4f9cc,"haxor.math.Color.get_xyzw","haxor/math/Color.hx",144,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return ::haxor::math::Vector4_obj::__new(this->r,this->g,this->b,this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_xyzw,return )

int Color_obj::get_argb( ){
	HX_STACK_FRAME("haxor.math.Color","get_argb",0x659bb11a,"haxor.math.Color.get_argb","haxor/math/Color.hx",151,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(152)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(153)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(154)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(155)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(156)
	return (int((int((int((int(ab) << int((int)24))) | int((int(rb) << int((int)16))))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_argb,return )

int Color_obj::set_argb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_argb",0x13f90a8e,"haxor.math.Color.set_argb","haxor/math/Color.hx",159,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(160)
	this->a = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(161)
	this->g = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(162)
	this->b = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(163)
	this->r = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(164)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_argb,return )

::String Color_obj::get_css( ){
	HX_STACK_FRAME("haxor.math.Color","get_css",0xb01a53b5,"haxor.math.Color.get_css","haxor/math/Color.hx",171,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(171)
	int _g = ::Std_obj::_int((this->r * (int)255));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(171)
	::String _g1 = (HX_CSTRING("rgba(") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(171)
	::String _g2 = (_g1 + HX_CSTRING(","));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(171)
	int _g3 = ::Std_obj::_int((this->g * (int)255));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(171)
	::String _g4 = (_g2 + _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(171)
	::String _g5 = (_g4 + HX_CSTRING(","));		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(171)
	int _g6 = ::Std_obj::_int((this->b * (int)255));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(171)
	::String _g7 = (_g5 + _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(171)
	::String _g8 = (_g7 + HX_CSTRING(","));		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(171)
	::String _g9 = (_g8 + this->a);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(171)
	return (_g9 + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_css,return )

int Color_obj::get_rgba( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgba",0x70cff482,"haxor.math.Color.get_rgba","haxor/math/Color.hx",178,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(179)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(180)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(181)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(182)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(183)
	return (int((int((int((int(rb) << int((int)24))) | int((int(gb) << int((int)16))))) | int((int(bb) << int((int)8))))) | int(ab));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgba,return )

int Color_obj::set_rgba( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgba",0x1f2d4df6,"haxor.math.Color.set_rgba","haxor/math/Color.hx",186,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(187)
	this->r = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(188)
	this->g = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(189)
	this->b = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(190)
	this->a = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(191)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgba,return )

int Color_obj::get_rgb( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgb",0xb025aaff,"haxor.math.Color.get_rgb","haxor/math/Color.hx",199,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(200)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(201)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(202)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(203)
	return (int((int((int(rb) << int((int)16))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgb,return )

int Color_obj::set_rgb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgb",0xa3273c0b,"haxor.math.Color.set_rgb","haxor/math/Color.hx",206,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(207)
	this->r = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(208)
	this->g = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(209)
	this->b = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(210)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgb,return )

Float Color_obj::get_luminance( ){
	HX_STACK_FRAME("haxor.math.Color","get_luminance",0x1126896a,"haxor.math.Color.get_luminance","haxor/math/Color.hx",217,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(217)
	return (((this->r * 0.3) + (this->g * 0.59)) + (this->b * 0.11));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_luminance,return )

::haxor::math::Color Color_obj::get_negative( ){
	HX_STACK_FRAME("haxor.math.Color","get_negative",0x38c24943,"haxor.math.Color.get_negative","haxor/math/Color.hx",223,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(223)
	return ::haxor::math::Color_obj::__new((1.0 - this->r),(1.0 - this->g),(1.0 - this->b),(1.0 - this->a));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_negative,return )

::haxor::math::Color Color_obj::Set( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(1);
	HX_STACK_FRAME("haxor.math.Color","Set",0x1755d15d,"haxor.math.Color.Set","haxor/math/Color.hx",271,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(272)
		this->r = p_r;
		HX_STACK_LINE(273)
		this->g = p_g;
		HX_STACK_LINE(274)
		this->b = p_b;
		HX_STACK_LINE(275)
		this->a = p_a;
		HX_STACK_LINE(276)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Color_obj,Set,return )

::haxor::math::Color Color_obj::Set3( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Color","Set3",0x53c16036,"haxor.math.Color.Set3","haxor/math/Color.hx",284,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(284)
	this->r = v->x;
	HX_STACK_LINE(284)
	this->g = v->y;
	HX_STACK_LINE(284)
	this->b = v->z;
	HX_STACK_LINE(284)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Set3,return )

::haxor::math::Color Color_obj::Set4( ::haxor::math::Vector4 v){
	HX_STACK_FRAME("haxor.math.Color","Set4",0x53c16037,"haxor.math.Color.Set4","haxor/math/Color.hx",291,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(291)
	this->r = v->x;
	HX_STACK_LINE(291)
	this->g = v->y;
	HX_STACK_LINE(291)
	this->b = v->z;
	HX_STACK_LINE(291)
	this->a = v->w;
	HX_STACK_LINE(291)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Set4,return )

::haxor::math::Color Color_obj::SetColor( ::haxor::math::Color p_color){
	HX_STACK_FRAME("haxor.math.Color","SetColor",0xd7aefec6,"haxor.math.Color.SetColor","haxor/math/Color.hx",298,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_LINE(298)
	this->r = p_color->r;
	HX_STACK_LINE(298)
	this->g = p_color->g;
	HX_STACK_LINE(298)
	this->b = p_color->b;
	HX_STACK_LINE(298)
	this->a = p_color->a;
	HX_STACK_LINE(298)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,SetColor,return )

Float Color_obj::Get( int p){
	HX_STACK_FRAME("haxor.math.Color","Get",0x174cb651,"haxor.math.Color.Get","haxor/math/Color.hx",305,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(305)
	if (((p == (int)0))){
		HX_STACK_LINE(305)
		return this->r;
	}
	else{
		HX_STACK_LINE(305)
		if (((p == (int)1))){
			HX_STACK_LINE(305)
			return this->g;
		}
		else{
			HX_STACK_LINE(305)
			if (((p == (int)2))){
				HX_STACK_LINE(305)
				return this->b;
			}
			else{
				HX_STACK_LINE(305)
				return this->a;
			}
		}
	}
	HX_STACK_LINE(305)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Get,return )

::haxor::math::Color Color_obj::Add( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Add",0x174827dc,"haxor.math.Color.Add","haxor/math/Color.hx",312,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(312)
	hx::AddEq(this->r,p_v->r);
	HX_STACK_LINE(312)
	hx::AddEq(this->g,p_v->g);
	HX_STACK_LINE(312)
	hx::AddEq(this->b,p_v->b);
	HX_STACK_LINE(312)
	hx::AddEq(this->a,p_v->a);
	HX_STACK_LINE(312)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Add,return )

::haxor::math::Color Color_obj::Sub( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Sub",0x1755df3b,"haxor.math.Color.Sub","haxor/math/Color.hx",319,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(319)
	hx::SubEq(this->r,p_v->r);
	HX_STACK_LINE(319)
	hx::SubEq(this->g,p_v->g);
	HX_STACK_LINE(319)
	hx::SubEq(this->b,p_v->b);
	HX_STACK_LINE(319)
	hx::SubEq(this->a,p_v->a);
	HX_STACK_LINE(319)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Sub,return )

::haxor::math::Color Color_obj::Multiply( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Multiply",0x19ab0689,"haxor.math.Color.Multiply","haxor/math/Color.hx",326,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(326)
	hx::MultEq(this->r,p_v->r);
	HX_STACK_LINE(326)
	hx::MultEq(this->g,p_v->g);
	HX_STACK_LINE(326)
	hx::MultEq(this->b,p_v->b);
	HX_STACK_LINE(326)
	hx::MultEq(this->a,p_v->a);
	HX_STACK_LINE(326)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Multiply,return )

::haxor::math::Color Color_obj::MultiplyRGB( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","MultiplyRGB",0x55496c04,"haxor.math.Color.MultiplyRGB","haxor/math/Color.hx",333,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(333)
	hx::MultEq(this->r,p_v->r);
	HX_STACK_LINE(333)
	hx::MultEq(this->g,p_v->g);
	HX_STACK_LINE(333)
	hx::MultEq(this->b,p_v->b);
	HX_STACK_LINE(333)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,MultiplyRGB,return )

::haxor::math::Color Color_obj::Scale( Float p_s){
	HX_STACK_FRAME("haxor.math.Color","Scale",0xf4122905,"haxor.math.Color.Scale","haxor/math/Color.hx",340,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(340)
	hx::MultEq(this->r,p_s);
	HX_STACK_LINE(340)
	hx::MultEq(this->g,p_s);
	HX_STACK_LINE(340)
	hx::MultEq(this->b,p_s);
	HX_STACK_LINE(340)
	hx::MultEq(this->a,p_s);
	HX_STACK_LINE(340)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Scale,return )

::haxor::math::Color Color_obj::ScaleRGB( Float p_s){
	HX_STACK_FRAME("haxor.math.Color","ScaleRGB",0x8079ff08,"haxor.math.Color.ScaleRGB","haxor/math/Color.hx",347,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(347)
	hx::MultEq(this->r,p_s);
	HX_STACK_LINE(347)
	hx::MultEq(this->g,p_s);
	HX_STACK_LINE(347)
	hx::MultEq(this->b,p_s);
	HX_STACK_LINE(347)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,ScaleRGB,return )

Array< Float > Color_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Color","ToArray",0x48bee959,"haxor.math.Color.ToArray","haxor/math/Color.hx",353,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(353)
	return Array_obj< Float >::__new().Add(this->r).Add(this->g).Add(this->b).Add(this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,ToArray,return )

::String Color_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Color","ToString",0xb78cf511,"haxor.math.Color.ToString","haxor/math/Color.hx",359,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(359)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(359)
		{
			HX_STACK_LINE(359)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(359)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				Float p_v = (this->r * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(359)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(359)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(359)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(359)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(359)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(359)
		{
			HX_STACK_LINE(359)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(359)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				Float p_v = (this->g * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(359)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(359)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(359)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(359)
		::String _g7 = (_g6 + HX_CSTRING(","));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(359)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(359)
		{
			HX_STACK_LINE(359)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(359)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				Float p_v = (this->b * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(359)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(359)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(359)
		::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(359)
		::String _g11 = (_g10 + HX_CSTRING(","));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(359)
		Float _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(359)
		{
			HX_STACK_LINE(359)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(359)
			Float _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				Float p_v = (this->a * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(359)
				_g12 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(359)
			_g13 = (Float(_g12) / Float(d));
		}
		HX_STACK_LINE(359)
		::String _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(359)
		return (_g14 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,ToString,return )

::haxor::math::Color Color_obj::temp;

::haxor::math::Color Color_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Color","get_temp",0x7220e6e2,"haxor.math.Color.get_temp","haxor/math/Color.hx",14,0x18984df5)
	HX_STACK_LINE(14)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(14)
	int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_temp,return )

::haxor::math::Color Color_obj::red;

::haxor::math::Color Color_obj::get_red( ){
	HX_STACK_FRAME("haxor.math.Color","get_red",0xb025a943,"haxor.math.Color.get_red","haxor/math/Color.hx",19,0x18984df5)
	HX_STACK_LINE(19)
	return ::haxor::math::Color_obj::__new(1.0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_red,return )

::haxor::math::Color Color_obj::yellow;

::haxor::math::Color Color_obj::get_yellow( ){
	HX_STACK_FRAME("haxor.math.Color","get_yellow",0xe86ed2c2,"haxor.math.Color.get_yellow","haxor/math/Color.hx",23,0x18984df5)
	HX_STACK_LINE(23)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_yellow,return )

::haxor::math::Color Color_obj::green;

::haxor::math::Color Color_obj::get_green( ){
	HX_STACK_FRAME("haxor.math.Color","get_green",0xf7053f35,"haxor.math.Color.get_green","haxor/math/Color.hx",27,0x18984df5)
	HX_STACK_LINE(27)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_green,return )

::haxor::math::Color Color_obj::cyan;

::haxor::math::Color Color_obj::get_cyan( ){
	HX_STACK_FRAME("haxor.math.Color","get_cyan",0x66f368f1,"haxor.math.Color.get_cyan","haxor/math/Color.hx",31,0x18984df5)
	HX_STACK_LINE(31)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_cyan,return )

::haxor::math::Color Color_obj::blue;

::haxor::math::Color Color_obj::get_blue( ){
	HX_STACK_FRAME("haxor.math.Color","get_blue",0x66406668,"haxor.math.Color.get_blue","haxor/math/Color.hx",35,0x18984df5)
	HX_STACK_LINE(35)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_blue,return )

::haxor::math::Color Color_obj::magenta;

::haxor::math::Color Color_obj::get_magenta( ){
	HX_STACK_FRAME("haxor.math.Color","get_magenta",0x06786b1b,"haxor.math.Color.get_magenta","haxor/math/Color.hx",39,0x18984df5)
	HX_STACK_LINE(39)
	return ::haxor::math::Color_obj::__new((int)1,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_magenta,return )

::haxor::math::Color Color_obj::black;

::haxor::math::Color Color_obj::get_black( ){
	HX_STACK_FRAME("haxor.math.Color","get_black",0x120a0631,"haxor.math.Color.get_black","haxor/math/Color.hx",43,0x18984df5)
	HX_STACK_LINE(43)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_black,return )

::haxor::math::Color Color_obj::white;

::haxor::math::Color Color_obj::get_white( ){
	HX_STACK_FRAME("haxor.math.Color","get_white",0x26d57b1b,"haxor.math.Color.get_white","haxor/math/Color.hx",47,0x18984df5)
	HX_STACK_LINE(47)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_white,return )

::haxor::math::Color Color_obj::empty;

::haxor::math::Color Color_obj::get_empty( ){
	HX_STACK_FRAME("haxor.math.Color","get_empty",0xccf26aff,"haxor.math.Color.get_empty","haxor/math/Color.hx",51,0x18984df5)
	HX_STACK_LINE(51)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_empty,return )

::haxor::math::Color Color_obj::gray10;

::haxor::math::Color Color_obj::get_gray10( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray10",0x2afc2cd0,"haxor.math.Color.get_gray10","haxor/math/Color.hx",55,0x18984df5)
	HX_STACK_LINE(55)
	return ::haxor::math::Color_obj::__new(0.1,0.1,0.1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray10,return )

::haxor::math::Color Color_obj::gray25;

::haxor::math::Color Color_obj::get_gray25( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray25",0x2afc2db4,"haxor.math.Color.get_gray25","haxor/math/Color.hx",59,0x18984df5)
	HX_STACK_LINE(59)
	return ::haxor::math::Color_obj::__new(0.25,0.25,0.25,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray25,return )

::haxor::math::Color Color_obj::gray50;

::haxor::math::Color Color_obj::get_gray50( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray50",0x2afc304c,"haxor.math.Color.get_gray50","haxor/math/Color.hx",63,0x18984df5)
	HX_STACK_LINE(63)
	return ::haxor::math::Color_obj::__new(0.5,0.5,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray50,return )

::haxor::math::Color Color_obj::gray75;

::haxor::math::Color Color_obj::get_gray75( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray75",0x2afc320f,"haxor.math.Color.get_gray75","haxor/math/Color.hx",67,0x18984df5)
	HX_STACK_LINE(67)
	return ::haxor::math::Color_obj::__new(0.75,0.75,0.75,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray75,return )

::haxor::math::Color Color_obj::gray90;

::haxor::math::Color Color_obj::get_gray90( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray90",0x2afc33c8,"haxor.math.Color.get_gray90","haxor/math/Color.hx",71,0x18984df5)
	HX_STACK_LINE(71)
	return ::haxor::math::Color_obj::__new(0.9,0.9,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray90,return )

::haxor::math::Color Color_obj::FromHex( ::String p_hex){
	HX_STACK_FRAME("haxor.math.Color","FromHex",0xaea542cc,"haxor.math.Color.FromHex","haxor/math/Color.hx",79,0x18984df5)
	HX_STACK_ARG(p_hex,"p_hex")
	HX_STACK_LINE(80)
	::haxor::math::Color c = ::haxor::math::Color_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(81)
	if (((p_hex.length == (int)10))){
		HX_STACK_LINE(81)
		Dynamic _g = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(81)
		c->set_argb(_g);
	}
	else{
		HX_STACK_LINE(81)
		Dynamic _g1 = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(81)
		c->set_rgb(_g1);
	}
	HX_STACK_LINE(82)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,FromHex,return )

::haxor::math::Color Color_obj::FromBytes( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(255.0);
	HX_STACK_FRAME("haxor.math.Color","FromBytes",0x2d62a69c,"haxor.math.Color.FromBytes","haxor/math/Color.hx",95,0x18984df5)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(95)
		return ::haxor::math::Color_obj::__new((p_r * 0.00392156863),(p_g * 0.00392156863),(p_b * 0.00392156863),(p_a * 0.00392156863));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Color_obj,FromBytes,return )

::haxor::math::Color Color_obj::Lerp( ::haxor::math::Color a,::haxor::math::Color b,Float r){
	HX_STACK_FRAME("haxor.math.Color","Lerp",0x4f20e05c,"haxor.math.Color.Lerp","haxor/math/Color.hx",107,0x18984df5)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	struct _Function_1_1{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",107,0x18984df5)
			{
				HX_STACK_LINE(107)
				Float p_a = a->r;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(107)
				return (p_a + (((b->r - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",107,0x18984df5)
			{
				HX_STACK_LINE(107)
				Float p_a = a->g;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(107)
				return (p_a + (((b->g - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_3{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",107,0x18984df5)
			{
				HX_STACK_LINE(107)
				Float p_a = a->b;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(107)
				return (p_a + (((b->b - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",107,0x18984df5)
			{
				HX_STACK_LINE(107)
				Float p_a = a->a;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(107)
				return (p_a + (((b->a - p_a)) * r));
			}
			return null();
		}
	};
	HX_STACK_LINE(107)
	return ::haxor::math::Color_obj::__new(_Function_1_1::Block(r,b,a),_Function_1_2::Block(r,b,a),_Function_1_3::Block(r,b,a),_Function_1_4::Block(r,b,a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Color_obj,Lerp,return )

::haxor::math::Color Color_obj::Sample( Array< ::Dynamic > g,Float r){
	HX_STACK_FRAME("haxor.math.Color","Sample",0x7cf6314f,"haxor.math.Color.Sample","haxor/math/Color.hx",117,0x18984df5)
	HX_STACK_ARG(g,"g")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(118)
	Float pos = (g->length - (int)1);		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(119)
	hx::MultEq(pos,(r * 0.9999));
	HX_STACK_LINE(120)
	int i0 = ::Std_obj::_int(pos);		HX_STACK_VAR(i0,"i0");
	HX_STACK_LINE(121)
	int i1 = hx::Mod(((i0 + (int)1)),g->length);		HX_STACK_VAR(i1,"i1");
	HX_STACK_LINE(122)
	Float _g = ::Math_obj::ffloor(pos);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(122)
	Float _g1 = (pos - _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(122)
	r = _g1;
	HX_STACK_LINE(123)
	::haxor::math::Color c0 = g->__get(i0).StaticCast< ::haxor::math::Color >();		HX_STACK_VAR(c0,"c0");
	HX_STACK_LINE(124)
	::haxor::math::Color c1 = g->__get(i1).StaticCast< ::haxor::math::Color >();		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(125)
	return ::haxor::math::Color_obj::Lerp(c0,c1,r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Color_obj,Sample,return )


Color_obj::Color_obj()
{
}

void Color_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Color);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(xyz,"xyz");
	HX_MARK_MEMBER_NAME(xyzw,"xyzw");
	HX_MARK_MEMBER_NAME(luminance,"luminance");
	HX_MARK_MEMBER_NAME(negative,"negative");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

void Color_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(xyz,"xyz");
	HX_VISIT_MEMBER_NAME(xyzw,"xyzw");
	HX_VISIT_MEMBER_NAME(luminance,"luminance");
	HX_VISIT_MEMBER_NAME(negative,"negative");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(g,"g");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
}

Dynamic Color_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"red") ) { return inCallProp ? get_red() : red; }
		if (HX_FIELD_EQ(inName,"xyz") ) { return inCallProp ? get_xyz() : xyz; }
		if (HX_FIELD_EQ(inName,"css") ) { return get_css(); }
		if (HX_FIELD_EQ(inName,"rgb") ) { return get_rgb(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Sub") ) { return Sub_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		if (HX_FIELD_EQ(inName,"cyan") ) { return inCallProp ? get_cyan() : cyan; }
		if (HX_FIELD_EQ(inName,"blue") ) { return inCallProp ? get_blue() : blue; }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"xyzw") ) { return inCallProp ? get_xyzw() : xyzw; }
		if (HX_FIELD_EQ(inName,"argb") ) { return get_argb(); }
		if (HX_FIELD_EQ(inName,"rgba") ) { return get_rgba(); }
		if (HX_FIELD_EQ(inName,"Set3") ) { return Set3_dyn(); }
		if (HX_FIELD_EQ(inName,"Set4") ) { return Set4_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"green") ) { return inCallProp ? get_green() : green; }
		if (HX_FIELD_EQ(inName,"black") ) { return inCallProp ? get_black() : black; }
		if (HX_FIELD_EQ(inName,"white") ) { return inCallProp ? get_white() : white; }
		if (HX_FIELD_EQ(inName,"empty") ) { return inCallProp ? get_empty() : empty; }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"Scale") ) { return Scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yellow") ) { return inCallProp ? get_yellow() : yellow; }
		if (HX_FIELD_EQ(inName,"gray10") ) { return inCallProp ? get_gray10() : gray10; }
		if (HX_FIELD_EQ(inName,"gray25") ) { return inCallProp ? get_gray25() : gray25; }
		if (HX_FIELD_EQ(inName,"gray50") ) { return inCallProp ? get_gray50() : gray50; }
		if (HX_FIELD_EQ(inName,"gray75") ) { return inCallProp ? get_gray75() : gray75; }
		if (HX_FIELD_EQ(inName,"gray90") ) { return inCallProp ? get_gray90() : gray90; }
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_red") ) { return get_red_dyn(); }
		if (HX_FIELD_EQ(inName,"magenta") ) { return inCallProp ? get_magenta() : magenta; }
		if (HX_FIELD_EQ(inName,"FromHex") ) { return FromHex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xyz") ) { return get_xyz_dyn(); }
		if (HX_FIELD_EQ(inName,"get_css") ) { return get_css_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rgb") ) { return get_rgb_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rgb") ) { return set_rgb_dyn(); }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cyan") ) { return get_cyan_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blue") ) { return get_blue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xyzw") ) { return get_xyzw_dyn(); }
		if (HX_FIELD_EQ(inName,"get_argb") ) { return get_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"set_argb") ) { return set_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rgba") ) { return get_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rgba") ) { return set_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"negative") ) { return inCallProp ? get_negative() : negative; }
		if (HX_FIELD_EQ(inName,"SetColor") ) { return SetColor_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"ScaleRGB") ) { return ScaleRGB_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_green") ) { return get_green_dyn(); }
		if (HX_FIELD_EQ(inName,"get_black") ) { return get_black_dyn(); }
		if (HX_FIELD_EQ(inName,"get_white") ) { return get_white_dyn(); }
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		if (HX_FIELD_EQ(inName,"FromBytes") ) { return FromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"luminance") ) { return inCallProp ? get_luminance() : luminance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_yellow") ) { return get_yellow_dyn(); }
		if (HX_FIELD_EQ(inName,"get_gray10") ) { return get_gray10_dyn(); }
		if (HX_FIELD_EQ(inName,"get_gray25") ) { return get_gray25_dyn(); }
		if (HX_FIELD_EQ(inName,"get_gray50") ) { return get_gray50_dyn(); }
		if (HX_FIELD_EQ(inName,"get_gray75") ) { return get_gray75_dyn(); }
		if (HX_FIELD_EQ(inName,"get_gray90") ) { return get_gray90_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_magenta") ) { return get_magenta_dyn(); }
		if (HX_FIELD_EQ(inName,"MultiplyRGB") ) { return MultiplyRGB_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_negative") ) { return get_negative_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_luminance") ) { return get_luminance_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Color_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"red") ) { red=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xyz") ) { xyz=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rgb") ) { return set_rgb(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cyan") ) { cyan=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blue") ) { blue=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xyzw") ) { xyzw=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"argb") ) { return set_argb(inValue); }
		if (HX_FIELD_EQ(inName,"rgba") ) { return set_rgba(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"green") ) { green=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"black") ) { black=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"white") ) { white=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"empty") ) { empty=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yellow") ) { yellow=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray10") ) { gray10=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray25") ) { gray25=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray50") ) { gray50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray75") ) { gray75=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray90") ) { gray90=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"magenta") ) { magenta=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"negative") ) { negative=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"luminance") ) { luminance=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Color_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("xyz"));
	outFields->push(HX_CSTRING("xyzw"));
	outFields->push(HX_CSTRING("argb"));
	outFields->push(HX_CSTRING("css"));
	outFields->push(HX_CSTRING("rgba"));
	outFields->push(HX_CSTRING("rgb"));
	outFields->push(HX_CSTRING("luminance"));
	outFields->push(HX_CSTRING("negative"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("red"),
	HX_CSTRING("get_red"),
	HX_CSTRING("yellow"),
	HX_CSTRING("get_yellow"),
	HX_CSTRING("green"),
	HX_CSTRING("get_green"),
	HX_CSTRING("cyan"),
	HX_CSTRING("get_cyan"),
	HX_CSTRING("blue"),
	HX_CSTRING("get_blue"),
	HX_CSTRING("magenta"),
	HX_CSTRING("get_magenta"),
	HX_CSTRING("black"),
	HX_CSTRING("get_black"),
	HX_CSTRING("white"),
	HX_CSTRING("get_white"),
	HX_CSTRING("empty"),
	HX_CSTRING("get_empty"),
	HX_CSTRING("gray10"),
	HX_CSTRING("get_gray10"),
	HX_CSTRING("gray25"),
	HX_CSTRING("get_gray25"),
	HX_CSTRING("gray50"),
	HX_CSTRING("get_gray50"),
	HX_CSTRING("gray75"),
	HX_CSTRING("get_gray75"),
	HX_CSTRING("gray90"),
	HX_CSTRING("get_gray90"),
	HX_CSTRING("FromHex"),
	HX_CSTRING("FromBytes"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Sample"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Color_obj,clone),HX_CSTRING("clone")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Color_obj,xyz),HX_CSTRING("xyz")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Color_obj,xyzw),HX_CSTRING("xyzw")},
	{hx::fsFloat,(int)offsetof(Color_obj,luminance),HX_CSTRING("luminance")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Color_obj,negative),HX_CSTRING("negative")},
	{hx::fsFloat,(int)offsetof(Color_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(Color_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(Color_obj,b),HX_CSTRING("b")},
	{hx::fsFloat,(int)offsetof(Color_obj,a),HX_CSTRING("a")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_clone"),
	HX_CSTRING("xyz"),
	HX_CSTRING("get_xyz"),
	HX_CSTRING("xyzw"),
	HX_CSTRING("get_xyzw"),
	HX_CSTRING("get_argb"),
	HX_CSTRING("set_argb"),
	HX_CSTRING("get_css"),
	HX_CSTRING("get_rgba"),
	HX_CSTRING("set_rgba"),
	HX_CSTRING("get_rgb"),
	HX_CSTRING("set_rgb"),
	HX_CSTRING("luminance"),
	HX_CSTRING("get_luminance"),
	HX_CSTRING("negative"),
	HX_CSTRING("get_negative"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("Set"),
	HX_CSTRING("Set3"),
	HX_CSTRING("Set4"),
	HX_CSTRING("SetColor"),
	HX_CSTRING("Get"),
	HX_CSTRING("Add"),
	HX_CSTRING("Sub"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("MultiplyRGB"),
	HX_CSTRING("Scale"),
	HX_CSTRING("ScaleRGB"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Color_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Color_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(Color_obj::red,"red");
	HX_MARK_MEMBER_NAME(Color_obj::yellow,"yellow");
	HX_MARK_MEMBER_NAME(Color_obj::green,"green");
	HX_MARK_MEMBER_NAME(Color_obj::cyan,"cyan");
	HX_MARK_MEMBER_NAME(Color_obj::blue,"blue");
	HX_MARK_MEMBER_NAME(Color_obj::magenta,"magenta");
	HX_MARK_MEMBER_NAME(Color_obj::black,"black");
	HX_MARK_MEMBER_NAME(Color_obj::white,"white");
	HX_MARK_MEMBER_NAME(Color_obj::empty,"empty");
	HX_MARK_MEMBER_NAME(Color_obj::gray10,"gray10");
	HX_MARK_MEMBER_NAME(Color_obj::gray25,"gray25");
	HX_MARK_MEMBER_NAME(Color_obj::gray50,"gray50");
	HX_MARK_MEMBER_NAME(Color_obj::gray75,"gray75");
	HX_MARK_MEMBER_NAME(Color_obj::gray90,"gray90");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Color_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Color_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(Color_obj::red,"red");
	HX_VISIT_MEMBER_NAME(Color_obj::yellow,"yellow");
	HX_VISIT_MEMBER_NAME(Color_obj::green,"green");
	HX_VISIT_MEMBER_NAME(Color_obj::cyan,"cyan");
	HX_VISIT_MEMBER_NAME(Color_obj::blue,"blue");
	HX_VISIT_MEMBER_NAME(Color_obj::magenta,"magenta");
	HX_VISIT_MEMBER_NAME(Color_obj::black,"black");
	HX_VISIT_MEMBER_NAME(Color_obj::white,"white");
	HX_VISIT_MEMBER_NAME(Color_obj::empty,"empty");
	HX_VISIT_MEMBER_NAME(Color_obj::gray10,"gray10");
	HX_VISIT_MEMBER_NAME(Color_obj::gray25,"gray25");
	HX_VISIT_MEMBER_NAME(Color_obj::gray50,"gray50");
	HX_VISIT_MEMBER_NAME(Color_obj::gray75,"gray75");
	HX_VISIT_MEMBER_NAME(Color_obj::gray90,"gray90");
};

#endif

Class Color_obj::__mClass;

void Color_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Color"), hx::TCanCast< Color_obj> ,sStaticFields,sMemberFields,
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

void Color_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
