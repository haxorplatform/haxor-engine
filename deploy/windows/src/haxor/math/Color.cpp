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
HX_STACK_FRAME("haxor.math.Color","new",0x176a4e3b,"haxor.math.Color.new","haxor/math/Color.hx",297,0x18984df5)
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
	HX_STACK_LINE(298)
	this->r = p_r;
	HX_STACK_LINE(299)
	this->g = p_g;
	HX_STACK_LINE(300)
	this->b = p_b;
	HX_STACK_LINE(301)
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
	HX_STACK_FRAME("haxor.math.Color","get_clone",0xa57b43cf,"haxor.math.Color.get_clone","haxor/math/Color.hx",173,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(173)
	return ::haxor::math::Color_obj::__new(this->r,this->g,this->b,this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_clone,return )

::haxor::math::Vector3 Color_obj::get_xyz( ){
	HX_STACK_FRAME("haxor.math.Color","get_xyz",0xb02a484b,"haxor.math.Color.get_xyz","haxor/math/Color.hx",179,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(179)
	return ::haxor::math::Vector3_obj::__new(this->r,this->g,this->b);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_xyz,return )

::haxor::math::Vector4 Color_obj::get_xyzw( ){
	HX_STACK_FRAME("haxor.math.Color","get_xyzw",0x74d4f9cc,"haxor.math.Color.get_xyzw","haxor/math/Color.hx",185,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(185)
	return ::haxor::math::Vector4_obj::__new(this->r,this->g,this->b,this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_xyzw,return )

int Color_obj::get_argb( ){
	HX_STACK_FRAME("haxor.math.Color","get_argb",0x659bb11a,"haxor.math.Color.get_argb","haxor/math/Color.hx",192,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(193)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(194)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(195)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(196)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(197)
	return (int((int((int((int(ab) << int((int)24))) | int((int(rb) << int((int)16))))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_argb,return )

int Color_obj::set_argb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_argb",0x13f90a8e,"haxor.math.Color.set_argb","haxor/math/Color.hx",200,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(201)
	this->a = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(202)
	this->r = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(203)
	this->g = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(204)
	this->b = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(205)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_argb,return )

::String Color_obj::get_css( ){
	HX_STACK_FRAME("haxor.math.Color","get_css",0xb01a53b5,"haxor.math.Color.get_css","haxor/math/Color.hx",214,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(214)
	int _g = ::Std_obj::_int((this->r * (int)255));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(214)
	::String _g1 = (HX_CSTRING("rgba(") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(214)
	::String _g2 = (_g1 + HX_CSTRING(","));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(214)
	int _g3 = ::Std_obj::_int((this->g * (int)255));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(214)
	::String _g4 = (_g2 + _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(214)
	::String _g5 = (_g4 + HX_CSTRING(","));		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(214)
	int _g6 = ::Std_obj::_int((this->b * (int)255));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(214)
	::String _g7 = (_g5 + _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(214)
	::String _g8 = (_g7 + HX_CSTRING(","));		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(214)
	::String _g9 = (_g8 + this->a);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(214)
	return (_g9 + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_css,return )

int Color_obj::get_rgba( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgba",0x70cff482,"haxor.math.Color.get_rgba","haxor/math/Color.hx",221,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(222)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(223)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(224)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(225)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(226)
	return (int((int((int((int(rb) << int((int)24))) | int((int(gb) << int((int)16))))) | int((int(bb) << int((int)8))))) | int(ab));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgba,return )

int Color_obj::set_rgba( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgba",0x1f2d4df6,"haxor.math.Color.set_rgba","haxor/math/Color.hx",229,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(230)
	this->r = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(231)
	this->g = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(232)
	this->b = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(233)
	this->a = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(234)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgba,return )

int Color_obj::get_rgb( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgb",0xb025aaff,"haxor.math.Color.get_rgb","haxor/math/Color.hx",242,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(243)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(244)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(245)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(246)
	return (int((int((int(rb) << int((int)16))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgb,return )

int Color_obj::set_rgb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgb",0xa3273c0b,"haxor.math.Color.set_rgb","haxor/math/Color.hx",249,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(250)
	this->r = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(251)
	this->g = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(252)
	this->b = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(253)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgb,return )

Float Color_obj::get_luminance( ){
	HX_STACK_FRAME("haxor.math.Color","get_luminance",0x1126896a,"haxor.math.Color.get_luminance","haxor/math/Color.hx",260,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(260)
	return (((this->r * 0.3) + (this->g * 0.59)) + (this->b * 0.11));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_luminance,return )

::haxor::math::Color Color_obj::get_negative( ){
	HX_STACK_FRAME("haxor.math.Color","get_negative",0x38c24943,"haxor.math.Color.get_negative","haxor/math/Color.hx",266,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(266)
	return ::haxor::math::Color_obj::__new((1.0 - this->r),(1.0 - this->g),(1.0 - this->b),(1.0 - this->a));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_negative,return )

::haxor::math::Color Color_obj::Set( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(1);
	HX_STACK_FRAME("haxor.math.Color","Set",0x1755d15d,"haxor.math.Color.Set","haxor/math/Color.hx",314,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(315)
		this->r = p_r;
		HX_STACK_LINE(316)
		this->g = p_g;
		HX_STACK_LINE(317)
		this->b = p_b;
		HX_STACK_LINE(318)
		this->a = p_a;
		HX_STACK_LINE(319)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Color_obj,Set,return )

::haxor::math::Color Color_obj::Set3( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Color","Set3",0x53c16036,"haxor.math.Color.Set3","haxor/math/Color.hx",327,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(327)
	this->r = v->x;
	HX_STACK_LINE(327)
	this->g = v->y;
	HX_STACK_LINE(327)
	this->b = v->z;
	HX_STACK_LINE(327)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Set3,return )

::haxor::math::Color Color_obj::Set4( ::haxor::math::Vector4 v){
	HX_STACK_FRAME("haxor.math.Color","Set4",0x53c16037,"haxor.math.Color.Set4","haxor/math/Color.hx",334,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(334)
	this->r = v->x;
	HX_STACK_LINE(334)
	this->g = v->y;
	HX_STACK_LINE(334)
	this->b = v->z;
	HX_STACK_LINE(334)
	this->a = v->w;
	HX_STACK_LINE(334)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Set4,return )

::haxor::math::Color Color_obj::SetColor( ::haxor::math::Color p_color){
	HX_STACK_FRAME("haxor.math.Color","SetColor",0xd7aefec6,"haxor.math.Color.SetColor","haxor/math/Color.hx",341,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_LINE(341)
	this->r = p_color->r;
	HX_STACK_LINE(341)
	this->g = p_color->g;
	HX_STACK_LINE(341)
	this->b = p_color->b;
	HX_STACK_LINE(341)
	this->a = p_color->a;
	HX_STACK_LINE(341)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,SetColor,return )

::haxor::math::Color Color_obj::SetRGB( ::haxor::math::Color p_color){
	HX_STACK_FRAME("haxor.math.Color","SetRGB",0xcf1a1db0,"haxor.math.Color.SetRGB","haxor/math/Color.hx",348,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_LINE(348)
	this->r = p_color->r;
	HX_STACK_LINE(348)
	this->g = p_color->g;
	HX_STACK_LINE(348)
	this->b = p_color->b;
	HX_STACK_LINE(348)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,SetRGB,return )

::haxor::math::Color Color_obj::SetAlpha( ::haxor::math::Color p_color){
	HX_STACK_FRAME("haxor.math.Color","SetAlpha",0xaee934c1,"haxor.math.Color.SetAlpha","haxor/math/Color.hx",355,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_LINE(355)
	this->a = p_color->a;
	HX_STACK_LINE(355)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,SetAlpha,return )

Float Color_obj::Get( int p){
	HX_STACK_FRAME("haxor.math.Color","Get",0x174cb651,"haxor.math.Color.Get","haxor/math/Color.hx",362,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(362)
	if (((p == (int)0))){
		HX_STACK_LINE(362)
		return this->r;
	}
	else{
		HX_STACK_LINE(362)
		if (((p == (int)1))){
			HX_STACK_LINE(362)
			return this->g;
		}
		else{
			HX_STACK_LINE(362)
			if (((p == (int)2))){
				HX_STACK_LINE(362)
				return this->b;
			}
			else{
				HX_STACK_LINE(362)
				return this->a;
			}
		}
	}
	HX_STACK_LINE(362)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Get,return )

::haxor::math::Color Color_obj::Add( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Add",0x174827dc,"haxor.math.Color.Add","haxor/math/Color.hx",369,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(369)
	hx::AddEq(this->r,p_v->r);
	HX_STACK_LINE(369)
	hx::AddEq(this->g,p_v->g);
	HX_STACK_LINE(369)
	hx::AddEq(this->b,p_v->b);
	HX_STACK_LINE(369)
	hx::AddEq(this->a,p_v->a);
	HX_STACK_LINE(369)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Add,return )

::haxor::math::Color Color_obj::Sub( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Sub",0x1755df3b,"haxor.math.Color.Sub","haxor/math/Color.hx",376,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(376)
	hx::SubEq(this->r,p_v->r);
	HX_STACK_LINE(376)
	hx::SubEq(this->g,p_v->g);
	HX_STACK_LINE(376)
	hx::SubEq(this->b,p_v->b);
	HX_STACK_LINE(376)
	hx::SubEq(this->a,p_v->a);
	HX_STACK_LINE(376)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Sub,return )

::haxor::math::Color Color_obj::Multiply( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","Multiply",0x19ab0689,"haxor.math.Color.Multiply","haxor/math/Color.hx",383,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(383)
	hx::MultEq(this->r,p_v->r);
	HX_STACK_LINE(383)
	hx::MultEq(this->g,p_v->g);
	HX_STACK_LINE(383)
	hx::MultEq(this->b,p_v->b);
	HX_STACK_LINE(383)
	hx::MultEq(this->a,p_v->a);
	HX_STACK_LINE(383)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Multiply,return )

::haxor::math::Color Color_obj::MultiplyRGB( ::haxor::math::Color p_v){
	HX_STACK_FRAME("haxor.math.Color","MultiplyRGB",0x55496c04,"haxor.math.Color.MultiplyRGB","haxor/math/Color.hx",390,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(390)
	hx::MultEq(this->r,p_v->r);
	HX_STACK_LINE(390)
	hx::MultEq(this->g,p_v->g);
	HX_STACK_LINE(390)
	hx::MultEq(this->b,p_v->b);
	HX_STACK_LINE(390)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,MultiplyRGB,return )

::haxor::math::Color Color_obj::Scale( Float p_s){
	HX_STACK_FRAME("haxor.math.Color","Scale",0xf4122905,"haxor.math.Color.Scale","haxor/math/Color.hx",397,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(397)
	hx::MultEq(this->r,p_s);
	HX_STACK_LINE(397)
	hx::MultEq(this->g,p_s);
	HX_STACK_LINE(397)
	hx::MultEq(this->b,p_s);
	HX_STACK_LINE(397)
	hx::MultEq(this->a,p_s);
	HX_STACK_LINE(397)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Scale,return )

::haxor::math::Color Color_obj::ScaleRGB( Float p_s){
	HX_STACK_FRAME("haxor.math.Color","ScaleRGB",0x8079ff08,"haxor.math.Color.ScaleRGB","haxor/math/Color.hx",404,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(404)
	hx::MultEq(this->r,p_s);
	HX_STACK_LINE(404)
	hx::MultEq(this->g,p_s);
	HX_STACK_LINE(404)
	hx::MultEq(this->b,p_s);
	HX_STACK_LINE(404)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,ScaleRGB,return )

Array< Float > Color_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Color","ToArray",0x48bee959,"haxor.math.Color.ToArray","haxor/math/Color.hx",410,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(410)
	return Array_obj< Float >::__new().Add(this->r).Add(this->g).Add(this->b).Add(this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,ToArray,return )

::String Color_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Color","ToString",0xb78cf511,"haxor.math.Color.ToString","haxor/math/Color.hx",416,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(416)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(416)
		{
			HX_STACK_LINE(416)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(416)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(416)
			{
				HX_STACK_LINE(416)
				Float p_v = (this->r * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(416)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(416)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(416)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(416)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(416)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(416)
		{
			HX_STACK_LINE(416)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(416)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(416)
			{
				HX_STACK_LINE(416)
				Float p_v = (this->g * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(416)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(416)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(416)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(416)
		::String _g7 = (_g6 + HX_CSTRING(","));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(416)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(416)
		{
			HX_STACK_LINE(416)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(416)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(416)
			{
				HX_STACK_LINE(416)
				Float p_v = (this->b * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(416)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(416)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(416)
		::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(416)
		::String _g11 = (_g10 + HX_CSTRING(","));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(416)
		Float _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(416)
		{
			HX_STACK_LINE(416)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(416)
			Float _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(416)
			{
				HX_STACK_LINE(416)
				Float p_v = (this->a * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(416)
				_g12 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(416)
			_g13 = (Float(_g12) / Float(d));
		}
		HX_STACK_LINE(416)
		::String _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(416)
		return (_g14 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,ToString,return )

::haxor::math::Color Color_obj::temp;

::haxor::math::Color Color_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Color","get_temp",0x7220e6e2,"haxor.math.Color.get_temp","haxor/math/Color.hx",15,0x18984df5)
	HX_STACK_LINE(15)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(15)
	int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_temp,return )

::haxor::math::Color Color_obj::red;

::haxor::math::Color Color_obj::get_red( ){
	HX_STACK_FRAME("haxor.math.Color","get_red",0xb025a943,"haxor.math.Color.get_red","haxor/math/Color.hx",20,0x18984df5)
	HX_STACK_LINE(20)
	return ::haxor::math::Color_obj::__new(1.0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_red,return )

::haxor::math::Color Color_obj::yellow;

::haxor::math::Color Color_obj::get_yellow( ){
	HX_STACK_FRAME("haxor.math.Color","get_yellow",0xe86ed2c2,"haxor.math.Color.get_yellow","haxor/math/Color.hx",24,0x18984df5)
	HX_STACK_LINE(24)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_yellow,return )

::haxor::math::Color Color_obj::green;

::haxor::math::Color Color_obj::get_green( ){
	HX_STACK_FRAME("haxor.math.Color","get_green",0xf7053f35,"haxor.math.Color.get_green","haxor/math/Color.hx",28,0x18984df5)
	HX_STACK_LINE(28)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_green,return )

::haxor::math::Color Color_obj::cyan;

::haxor::math::Color Color_obj::get_cyan( ){
	HX_STACK_FRAME("haxor.math.Color","get_cyan",0x66f368f1,"haxor.math.Color.get_cyan","haxor/math/Color.hx",32,0x18984df5)
	HX_STACK_LINE(32)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_cyan,return )

::haxor::math::Color Color_obj::blue;

::haxor::math::Color Color_obj::get_blue( ){
	HX_STACK_FRAME("haxor.math.Color","get_blue",0x66406668,"haxor.math.Color.get_blue","haxor/math/Color.hx",36,0x18984df5)
	HX_STACK_LINE(36)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_blue,return )

::haxor::math::Color Color_obj::magenta;

::haxor::math::Color Color_obj::get_magenta( ){
	HX_STACK_FRAME("haxor.math.Color","get_magenta",0x06786b1b,"haxor.math.Color.get_magenta","haxor/math/Color.hx",40,0x18984df5)
	HX_STACK_LINE(40)
	return ::haxor::math::Color_obj::__new((int)1,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_magenta,return )

::haxor::math::Color Color_obj::black;

::haxor::math::Color Color_obj::get_black( ){
	HX_STACK_FRAME("haxor.math.Color","get_black",0x120a0631,"haxor.math.Color.get_black","haxor/math/Color.hx",44,0x18984df5)
	HX_STACK_LINE(44)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_black,return )

::haxor::math::Color Color_obj::white;

::haxor::math::Color Color_obj::get_white( ){
	HX_STACK_FRAME("haxor.math.Color","get_white",0x26d57b1b,"haxor.math.Color.get_white","haxor/math/Color.hx",48,0x18984df5)
	HX_STACK_LINE(48)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_white,return )

::haxor::math::Color Color_obj::empty;

::haxor::math::Color Color_obj::get_empty( ){
	HX_STACK_FRAME("haxor.math.Color","get_empty",0xccf26aff,"haxor.math.Color.get_empty","haxor/math/Color.hx",52,0x18984df5)
	HX_STACK_LINE(52)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_empty,return )

::haxor::math::Color Color_obj::gray10;

::haxor::math::Color Color_obj::get_gray10( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray10",0x2afc2cd0,"haxor.math.Color.get_gray10","haxor/math/Color.hx",56,0x18984df5)
	HX_STACK_LINE(56)
	return ::haxor::math::Color_obj::__new(0.1,0.1,0.1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray10,return )

::haxor::math::Color Color_obj::gray25;

::haxor::math::Color Color_obj::get_gray25( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray25",0x2afc2db4,"haxor.math.Color.get_gray25","haxor/math/Color.hx",60,0x18984df5)
	HX_STACK_LINE(60)
	return ::haxor::math::Color_obj::__new(0.25,0.25,0.25,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray25,return )

::haxor::math::Color Color_obj::gray50;

::haxor::math::Color Color_obj::get_gray50( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray50",0x2afc304c,"haxor.math.Color.get_gray50","haxor/math/Color.hx",64,0x18984df5)
	HX_STACK_LINE(64)
	return ::haxor::math::Color_obj::__new(0.5,0.5,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray50,return )

::haxor::math::Color Color_obj::gray75;

::haxor::math::Color Color_obj::get_gray75( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray75",0x2afc320f,"haxor.math.Color.get_gray75","haxor/math/Color.hx",68,0x18984df5)
	HX_STACK_LINE(68)
	return ::haxor::math::Color_obj::__new(0.75,0.75,0.75,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray75,return )

::haxor::math::Color Color_obj::gray90;

::haxor::math::Color Color_obj::get_gray90( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray90",0x2afc33c8,"haxor.math.Color.get_gray90","haxor/math/Color.hx",72,0x18984df5)
	HX_STACK_LINE(72)
	return ::haxor::math::Color_obj::__new(0.9,0.9,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray90,return )

::haxor::math::Color Color_obj::red50;

::haxor::math::Color Color_obj::get_red50( ){
	HX_STACK_FRAME("haxor.math.Color","get_red50",0x43d4ee5e,"haxor.math.Color.get_red50","haxor/math/Color.hx",77,0x18984df5)
	HX_STACK_LINE(77)
	return ::haxor::math::Color_obj::__new(0.9,0.5,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_red50,return )

::haxor::math::Color Color_obj::green50;

::haxor::math::Color Color_obj::get_green50( ){
	HX_STACK_FRAME("haxor.math.Color","get_green50",0xb23b64d0,"haxor.math.Color.get_green50","haxor/math/Color.hx",82,0x18984df5)
	HX_STACK_LINE(82)
	return ::haxor::math::Color_obj::__new(0.5,0.9,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_green50,return )

::haxor::math::Color Color_obj::blue50;

::haxor::math::Color Color_obj::get_blue50( ){
	HX_STACK_FRAME("haxor.math.Color","get_blue50",0xc3f4fec3,"haxor.math.Color.get_blue50","haxor/math/Color.hx",87,0x18984df5)
	HX_STACK_LINE(87)
	return ::haxor::math::Color_obj::__new(0.5,0.5,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_blue50,return )

::haxor::math::Color Color_obj::yellow50;

::haxor::math::Color Color_obj::get_yellow50( ){
	HX_STACK_FRAME("haxor.math.Color","get_yellow50",0xffdab59d,"haxor.math.Color.get_yellow50","haxor/math/Color.hx",92,0x18984df5)
	HX_STACK_LINE(92)
	return ::haxor::math::Color_obj::__new(0.9,0.9,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_yellow50,return )

::haxor::math::Color Color_obj::magenta50;

::haxor::math::Color Color_obj::get_magenta50( ){
	HX_STACK_FRAME("haxor.math.Color","get_magenta50",0xe5bdd636,"haxor.math.Color.get_magenta50","haxor/math/Color.hx",97,0x18984df5)
	HX_STACK_LINE(97)
	return ::haxor::math::Color_obj::__new(0.9,0.5,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_magenta50,return )

::haxor::math::Color Color_obj::red30;

::haxor::math::Color Color_obj::get_red30( ){
	HX_STACK_FRAME("haxor.math.Color","get_red30",0x43d4eca0,"haxor.math.Color.get_red30","haxor/math/Color.hx",102,0x18984df5)
	HX_STACK_LINE(102)
	return ::haxor::math::Color_obj::__new(0.9,0.3,0.3,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_red30,return )

::haxor::math::Color Color_obj::green30;

::haxor::math::Color Color_obj::get_green30( ){
	HX_STACK_FRAME("haxor.math.Color","get_green30",0xb23b6312,"haxor.math.Color.get_green30","haxor/math/Color.hx",107,0x18984df5)
	HX_STACK_LINE(107)
	return ::haxor::math::Color_obj::__new(0.3,0.9,0.3,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_green30,return )

::haxor::math::Color Color_obj::blue30;

::haxor::math::Color Color_obj::get_blue30( ){
	HX_STACK_FRAME("haxor.math.Color","get_blue30",0xc3f4fd05,"haxor.math.Color.get_blue30","haxor/math/Color.hx",112,0x18984df5)
	HX_STACK_LINE(112)
	return ::haxor::math::Color_obj::__new(0.3,0.3,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_blue30,return )

::haxor::math::Color Color_obj::FromHex( ::String p_hex){
	HX_STACK_FRAME("haxor.math.Color","FromHex",0xaea542cc,"haxor.math.Color.FromHex","haxor/math/Color.hx",120,0x18984df5)
	HX_STACK_ARG(p_hex,"p_hex")
	HX_STACK_LINE(121)
	::haxor::math::Color c = ::haxor::math::Color_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(122)
	if (((p_hex.length == (int)10))){
		HX_STACK_LINE(122)
		Dynamic _g = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(122)
		c->set_argb(_g);
	}
	else{
		HX_STACK_LINE(122)
		Dynamic _g1 = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(122)
		c->set_rgb(_g1);
	}
	HX_STACK_LINE(123)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,FromHex,return )

::haxor::math::Color Color_obj::FromBytes( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(255.0);
	HX_STACK_FRAME("haxor.math.Color","FromBytes",0x2d62a69c,"haxor.math.Color.FromBytes","haxor/math/Color.hx",136,0x18984df5)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(136)
		return ::haxor::math::Color_obj::__new((p_r * 0.00392156863),(p_g * 0.00392156863),(p_b * 0.00392156863),(p_a * 0.00392156863));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Color_obj,FromBytes,return )

::haxor::math::Color Color_obj::Lerp( ::haxor::math::Color a,::haxor::math::Color b,Float r){
	HX_STACK_FRAME("haxor.math.Color","Lerp",0x4f20e05c,"haxor.math.Color.Lerp","haxor/math/Color.hx",148,0x18984df5)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	struct _Function_1_1{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",148,0x18984df5)
			{
				HX_STACK_LINE(148)
				Float p_a = a->r;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(148)
				return (p_a + (((b->r - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",148,0x18984df5)
			{
				HX_STACK_LINE(148)
				Float p_a = a->g;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(148)
				return (p_a + (((b->g - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_3{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",148,0x18984df5)
			{
				HX_STACK_LINE(148)
				Float p_a = a->b;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(148)
				return (p_a + (((b->b - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",148,0x18984df5)
			{
				HX_STACK_LINE(148)
				Float p_a = a->a;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(148)
				return (p_a + (((b->a - p_a)) * r));
			}
			return null();
		}
	};
	HX_STACK_LINE(148)
	return ::haxor::math::Color_obj::__new(_Function_1_1::Block(r,b,a),_Function_1_2::Block(r,b,a),_Function_1_3::Block(r,b,a),_Function_1_4::Block(r,b,a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Color_obj,Lerp,return )

::haxor::math::Color Color_obj::Sample( Array< ::Dynamic > g,Float r){
	HX_STACK_FRAME("haxor.math.Color","Sample",0x7cf6314f,"haxor.math.Color.Sample","haxor/math/Color.hx",158,0x18984df5)
	HX_STACK_ARG(g,"g")
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(159)
	Float pos = (g->length - (int)1);		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(160)
	hx::MultEq(pos,(r * 0.9999));
	HX_STACK_LINE(161)
	int i0 = ::Std_obj::_int(pos);		HX_STACK_VAR(i0,"i0");
	HX_STACK_LINE(162)
	int i1 = hx::Mod(((i0 + (int)1)),g->length);		HX_STACK_VAR(i1,"i1");
	HX_STACK_LINE(163)
	Float _g = ::Math_obj::ffloor(pos);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(163)
	Float _g1 = (pos - _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(163)
	r = _g1;
	HX_STACK_LINE(164)
	::haxor::math::Color c0 = g->__get(i0).StaticCast< ::haxor::math::Color >();		HX_STACK_VAR(c0,"c0");
	HX_STACK_LINE(165)
	::haxor::math::Color c1 = g->__get(i1).StaticCast< ::haxor::math::Color >();		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(166)
	return ::haxor::math::Color_obj::Lerp(c0,c1,r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Color_obj,Sample,return )

::haxor::math::Color Color_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.math.Color","Parse",0x3898eaae,"haxor.math.Color.Parse","haxor/math/Color.hx",424,0x18984df5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(425)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(427)
		::String _g = ::StringTools_obj::trim(tk->__get((int)0));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(427)
		Float _g1 = ::Std_obj::parseFloat(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(428)
		::String _g2 = ::StringTools_obj::trim(tk->__get((int)1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(428)
		Float _g3 = ::Std_obj::parseFloat(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(429)
		::String _g4 = ::StringTools_obj::trim(tk->__get((int)2));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(429)
		Float _g5 = ::Std_obj::parseFloat(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(430)
		::String _g6 = ::StringTools_obj::trim(tk->__get((int)3));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(430)
		Float _g7 = ::Std_obj::parseFloat(_g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(426)
		return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1)->Set(_g1,_g3,_g5,_g7);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Color_obj,Parse,return )


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
		if (HX_FIELD_EQ(inName,"red50") ) { return inCallProp ? get_red50() : red50; }
		if (HX_FIELD_EQ(inName,"red30") ) { return inCallProp ? get_red30() : red30; }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
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
		if (HX_FIELD_EQ(inName,"blue50") ) { return inCallProp ? get_blue50() : blue50; }
		if (HX_FIELD_EQ(inName,"blue30") ) { return inCallProp ? get_blue30() : blue30; }
		if (HX_FIELD_EQ(inName,"Sample") ) { return Sample_dyn(); }
		if (HX_FIELD_EQ(inName,"SetRGB") ) { return SetRGB_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_red") ) { return get_red_dyn(); }
		if (HX_FIELD_EQ(inName,"magenta") ) { return inCallProp ? get_magenta() : magenta; }
		if (HX_FIELD_EQ(inName,"green50") ) { return inCallProp ? get_green50() : green50; }
		if (HX_FIELD_EQ(inName,"green30") ) { return inCallProp ? get_green30() : green30; }
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
		if (HX_FIELD_EQ(inName,"yellow50") ) { return inCallProp ? get_yellow50() : yellow50; }
		if (HX_FIELD_EQ(inName,"get_xyzw") ) { return get_xyzw_dyn(); }
		if (HX_FIELD_EQ(inName,"get_argb") ) { return get_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"set_argb") ) { return set_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rgba") ) { return get_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rgba") ) { return set_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"negative") ) { return inCallProp ? get_negative() : negative; }
		if (HX_FIELD_EQ(inName,"SetColor") ) { return SetColor_dyn(); }
		if (HX_FIELD_EQ(inName,"SetAlpha") ) { return SetAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"ScaleRGB") ) { return ScaleRGB_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_green") ) { return get_green_dyn(); }
		if (HX_FIELD_EQ(inName,"get_black") ) { return get_black_dyn(); }
		if (HX_FIELD_EQ(inName,"get_white") ) { return get_white_dyn(); }
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_red50") ) { return get_red50_dyn(); }
		if (HX_FIELD_EQ(inName,"magenta50") ) { return inCallProp ? get_magenta50() : magenta50; }
		if (HX_FIELD_EQ(inName,"get_red30") ) { return get_red30_dyn(); }
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
		if (HX_FIELD_EQ(inName,"get_blue50") ) { return get_blue50_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blue30") ) { return get_blue30_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_magenta") ) { return get_magenta_dyn(); }
		if (HX_FIELD_EQ(inName,"get_green50") ) { return get_green50_dyn(); }
		if (HX_FIELD_EQ(inName,"get_green30") ) { return get_green30_dyn(); }
		if (HX_FIELD_EQ(inName,"MultiplyRGB") ) { return MultiplyRGB_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_yellow50") ) { return get_yellow50_dyn(); }
		if (HX_FIELD_EQ(inName,"get_negative") ) { return get_negative_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_magenta50") ) { return get_magenta50_dyn(); }
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
		if (HX_FIELD_EQ(inName,"red50") ) { red50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"red30") ) { red30=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yellow") ) { yellow=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray10") ) { gray10=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray25") ) { gray25=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray50") ) { gray50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray75") ) { gray75=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gray90") ) { gray90=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blue50") ) { blue50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blue30") ) { blue30=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"magenta") ) { magenta=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"green50") ) { green50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"green30") ) { green30=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"yellow50") ) { yellow50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"negative") ) { negative=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"magenta50") ) { magenta50=inValue.Cast< ::haxor::math::Color >(); return inValue; }
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
	HX_CSTRING("red50"),
	HX_CSTRING("get_red50"),
	HX_CSTRING("green50"),
	HX_CSTRING("get_green50"),
	HX_CSTRING("blue50"),
	HX_CSTRING("get_blue50"),
	HX_CSTRING("yellow50"),
	HX_CSTRING("get_yellow50"),
	HX_CSTRING("magenta50"),
	HX_CSTRING("get_magenta50"),
	HX_CSTRING("red30"),
	HX_CSTRING("get_red30"),
	HX_CSTRING("green30"),
	HX_CSTRING("get_green30"),
	HX_CSTRING("blue30"),
	HX_CSTRING("get_blue30"),
	HX_CSTRING("FromHex"),
	HX_CSTRING("FromBytes"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Sample"),
	HX_CSTRING("Parse"),
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
	HX_CSTRING("SetRGB"),
	HX_CSTRING("SetAlpha"),
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
	HX_MARK_MEMBER_NAME(Color_obj::red50,"red50");
	HX_MARK_MEMBER_NAME(Color_obj::green50,"green50");
	HX_MARK_MEMBER_NAME(Color_obj::blue50,"blue50");
	HX_MARK_MEMBER_NAME(Color_obj::yellow50,"yellow50");
	HX_MARK_MEMBER_NAME(Color_obj::magenta50,"magenta50");
	HX_MARK_MEMBER_NAME(Color_obj::red30,"red30");
	HX_MARK_MEMBER_NAME(Color_obj::green30,"green30");
	HX_MARK_MEMBER_NAME(Color_obj::blue30,"blue30");
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
	HX_VISIT_MEMBER_NAME(Color_obj::red50,"red50");
	HX_VISIT_MEMBER_NAME(Color_obj::green50,"green50");
	HX_VISIT_MEMBER_NAME(Color_obj::blue50,"blue50");
	HX_VISIT_MEMBER_NAME(Color_obj::yellow50,"yellow50");
	HX_VISIT_MEMBER_NAME(Color_obj::magenta50,"magenta50");
	HX_VISIT_MEMBER_NAME(Color_obj::red30,"red30");
	HX_VISIT_MEMBER_NAME(Color_obj::green30,"green30");
	HX_VISIT_MEMBER_NAME(Color_obj::blue30,"blue30");
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
