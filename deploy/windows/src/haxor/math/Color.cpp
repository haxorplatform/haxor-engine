#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace math{

Void Color_obj::__construct(hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a)
{
HX_STACK_FRAME("haxor.math.Color","new",0x176a4e3b,"haxor.math.Color.new","haxor/math/Color.hx",217,0x18984df5)
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
	HX_STACK_LINE(218)
	this->r = p_r;
	HX_STACK_LINE(219)
	this->g = p_g;
	HX_STACK_LINE(220)
	this->b = p_b;
	HX_STACK_LINE(221)
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
	HX_STACK_FRAME("haxor.math.Color","get_clone",0xa57b43cf,"haxor.math.Color.get_clone","haxor/math/Color.hx",107,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(107)
	return ::haxor::math::Color_obj::__new(this->r,this->g,this->b,this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_clone,return )

int Color_obj::get_argb( ){
	HX_STACK_FRAME("haxor.math.Color","get_argb",0x659bb11a,"haxor.math.Color.get_argb","haxor/math/Color.hx",126,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(128)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(129)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(130)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(131)
	return (int((int((int((int(ab) << int((int)24))) | int((int(rb) << int((int)16))))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_argb,return )

int Color_obj::set_argb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_argb",0x13f90a8e,"haxor.math.Color.set_argb","haxor/math/Color.hx",134,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(135)
	this->a = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(136)
	this->g = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(137)
	this->b = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(138)
	this->r = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(139)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_argb,return )

::String Color_obj::get_css( ){
	HX_STACK_FRAME("haxor.math.Color","get_css",0xb01a53b5,"haxor.math.Color.get_css","haxor/math/Color.hx",146,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(146)
	int _g = ::Std_obj::_int((this->r * (int)255));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(146)
	::String _g1 = (HX_CSTRING("rgba(") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(146)
	::String _g2 = (_g1 + HX_CSTRING(","));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(146)
	int _g3 = ::Std_obj::_int((this->g * (int)255));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(146)
	::String _g4 = (_g2 + _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(146)
	::String _g5 = (_g4 + HX_CSTRING(","));		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(146)
	int _g6 = ::Std_obj::_int((this->b * (int)255));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(146)
	::String _g7 = (_g5 + _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(146)
	::String _g8 = (_g7 + HX_CSTRING(","));		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(146)
	::String _g9 = (_g8 + this->a);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(146)
	return (_g9 + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_css,return )

int Color_obj::get_rgba( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgba",0x70cff482,"haxor.math.Color.get_rgba","haxor/math/Color.hx",153,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(154)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(155)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(156)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(157)
	int ab = (this->a * 255.0);		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(158)
	return (int((int((int((int(rb) << int((int)24))) | int((int(gb) << int((int)16))))) | int((int(bb) << int((int)8))))) | int(ab));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgba,return )

int Color_obj::set_rgba( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgba",0x1f2d4df6,"haxor.math.Color.set_rgba","haxor/math/Color.hx",161,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(162)
	this->r = (((int((int(v) >> int((int)24))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(163)
	this->g = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(164)
	this->b = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(165)
	this->a = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(166)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgba,return )

int Color_obj::get_rgb( ){
	HX_STACK_FRAME("haxor.math.Color","get_rgb",0xb025aaff,"haxor.math.Color.get_rgb","haxor/math/Color.hx",174,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(175)
	int rb = (this->r * 255.0);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(176)
	int gb = (this->g * 255.0);		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(177)
	int bb = (this->b * 255.0);		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(178)
	return (int((int((int(rb) << int((int)16))) | int((int(gb) << int((int)8))))) | int(bb));
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_rgb,return )

int Color_obj::set_rgb( int v){
	HX_STACK_FRAME("haxor.math.Color","set_rgb",0xa3273c0b,"haxor.math.Color.set_rgb","haxor/math/Color.hx",181,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(182)
	this->r = (((int((int(v) >> int((int)16))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(183)
	this->g = (((int((int(v) >> int((int)8))) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(184)
	this->b = (((int(v) & int((int)255))) * 0.00392156863);
	HX_STACK_LINE(185)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,set_rgb,return )

::haxor::math::Color Color_obj::Set( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(1);
	HX_STACK_FRAME("haxor.math.Color","Set",0x1755d15d,"haxor.math.Color.Set","haxor/math/Color.hx",234,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(235)
		this->r = p_r;
		HX_STACK_LINE(236)
		this->g = p_g;
		HX_STACK_LINE(237)
		this->b = p_b;
		HX_STACK_LINE(238)
		this->a = p_a;
		HX_STACK_LINE(239)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Color_obj,Set,return )

::haxor::math::Color Color_obj::Set4( ::haxor::math::Color p_color){
	HX_STACK_FRAME("haxor.math.Color","Set4",0x53c16037,"haxor.math.Color.Set4","haxor/math/Color.hx",248,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_LINE(249)
	if (((p_color == null()))){
		HX_STACK_LINE(249)
		this->r = 0.0;
	}
	else{
		HX_STACK_LINE(249)
		this->r = p_color->r;
	}
	HX_STACK_LINE(250)
	if (((p_color == null()))){
		HX_STACK_LINE(250)
		this->g = 0.0;
	}
	else{
		HX_STACK_LINE(250)
		this->g = p_color->g;
	}
	HX_STACK_LINE(251)
	if (((p_color == null()))){
		HX_STACK_LINE(251)
		this->b = 0.0;
	}
	else{
		HX_STACK_LINE(251)
		this->b = p_color->b;
	}
	HX_STACK_LINE(252)
	if (((p_color == null()))){
		HX_STACK_LINE(252)
		this->a = 1.0;
	}
	else{
		HX_STACK_LINE(252)
		this->a = p_color->a;
	}
	HX_STACK_LINE(253)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Color_obj,Set4,return )

Array< Float > Color_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Color","ToArray",0x48bee959,"haxor.math.Color.ToArray","haxor/math/Color.hx",260,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(260)
	return Array_obj< Float >::__new().Add(this->r).Add(this->g).Add(this->b).Add(this->a);
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,ToArray,return )

::String Color_obj::ToString( ){
	HX_STACK_FRAME("haxor.math.Color","ToString",0xb78cf511,"haxor.math.Color.ToString","haxor/math/Color.hx",267,0x18984df5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(268)
	Array< Float > a = this->ToArray();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(269)
	Array< ::String > s = Array_obj< ::String >::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(270)
	{
		HX_STACK_LINE(270)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(270)
		int _g = a->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(270)
		while((true)){
			HX_STACK_LINE(270)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(270)
				break;
			}
			HX_STACK_LINE(270)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(270)
			int _g2 = ::Std_obj::_int((a->__get(i) * 100.0));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(270)
			a[i] = (Float(_g2) / Float((int)100));
			HX_STACK_LINE(270)
			s->push((  (((a->__get(i) >= (int)0))) ? ::String((HX_CSTRING(" ") + a->__get(i))) : ::String((a->__get(i) + HX_CSTRING(""))) ));
		}
	}
	HX_STACK_LINE(271)
	::String res = HX_CSTRING("[");		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(272)
	{
		HX_STACK_LINE(272)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(272)
		int _g = a->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(272)
		while((true)){
			HX_STACK_LINE(272)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(272)
				break;
			}
			HX_STACK_LINE(272)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(274)
			hx::AddEq(res,(s->__get(i) + ((  (((i < (a->length - (int)1)))) ? ::String(HX_CSTRING(",")) : ::String(HX_CSTRING("]")) ))));
		}
	}
	HX_STACK_LINE(276)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(Color_obj,ToString,return )

::haxor::math::Color Color_obj::red;

::haxor::math::Color Color_obj::get_red( ){
	HX_STACK_FRAME("haxor.math.Color","get_red",0xb025a943,"haxor.math.Color.get_red","haxor/math/Color.hx",12,0x18984df5)
	HX_STACK_LINE(12)
	return ::haxor::math::Color_obj::__new(1.0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_red,return )

::haxor::math::Color Color_obj::yellow;

::haxor::math::Color Color_obj::get_yellow( ){
	HX_STACK_FRAME("haxor.math.Color","get_yellow",0xe86ed2c2,"haxor.math.Color.get_yellow","haxor/math/Color.hx",16,0x18984df5)
	HX_STACK_LINE(16)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_yellow,return )

::haxor::math::Color Color_obj::green;

::haxor::math::Color Color_obj::get_green( ){
	HX_STACK_FRAME("haxor.math.Color","get_green",0xf7053f35,"haxor.math.Color.get_green","haxor/math/Color.hx",20,0x18984df5)
	HX_STACK_LINE(20)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_green,return )

::haxor::math::Color Color_obj::cyan;

::haxor::math::Color Color_obj::get_cyan( ){
	HX_STACK_FRAME("haxor.math.Color","get_cyan",0x66f368f1,"haxor.math.Color.get_cyan","haxor/math/Color.hx",24,0x18984df5)
	HX_STACK_LINE(24)
	return ::haxor::math::Color_obj::__new((int)0,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_cyan,return )

::haxor::math::Color Color_obj::blue;

::haxor::math::Color Color_obj::get_blue( ){
	HX_STACK_FRAME("haxor.math.Color","get_blue",0x66406668,"haxor.math.Color.get_blue","haxor/math/Color.hx",28,0x18984df5)
	HX_STACK_LINE(28)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_blue,return )

::haxor::math::Color Color_obj::magenta;

::haxor::math::Color Color_obj::get_magenta( ){
	HX_STACK_FRAME("haxor.math.Color","get_magenta",0x06786b1b,"haxor.math.Color.get_magenta","haxor/math/Color.hx",32,0x18984df5)
	HX_STACK_LINE(32)
	return ::haxor::math::Color_obj::__new((int)1,(int)0,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_magenta,return )

::haxor::math::Color Color_obj::black;

::haxor::math::Color Color_obj::get_black( ){
	HX_STACK_FRAME("haxor.math.Color","get_black",0x120a0631,"haxor.math.Color.get_black","haxor/math/Color.hx",36,0x18984df5)
	HX_STACK_LINE(36)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_black,return )

::haxor::math::Color Color_obj::white;

::haxor::math::Color Color_obj::get_white( ){
	HX_STACK_FRAME("haxor.math.Color","get_white",0x26d57b1b,"haxor.math.Color.get_white","haxor/math/Color.hx",40,0x18984df5)
	HX_STACK_LINE(40)
	return ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_white,return )

::haxor::math::Color Color_obj::empty;

::haxor::math::Color Color_obj::get_empty( ){
	HX_STACK_FRAME("haxor.math.Color","get_empty",0xccf26aff,"haxor.math.Color.get_empty","haxor/math/Color.hx",44,0x18984df5)
	HX_STACK_LINE(44)
	return ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_empty,return )

::haxor::math::Color Color_obj::gray10;

::haxor::math::Color Color_obj::get_gray10( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray10",0x2afc2cd0,"haxor.math.Color.get_gray10","haxor/math/Color.hx",48,0x18984df5)
	HX_STACK_LINE(48)
	return ::haxor::math::Color_obj::__new(0.1,0.1,0.1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray10,return )

::haxor::math::Color Color_obj::gray25;

::haxor::math::Color Color_obj::get_gray25( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray25",0x2afc2db4,"haxor.math.Color.get_gray25","haxor/math/Color.hx",52,0x18984df5)
	HX_STACK_LINE(52)
	return ::haxor::math::Color_obj::__new(0.25,0.25,0.25,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray25,return )

::haxor::math::Color Color_obj::gray50;

::haxor::math::Color Color_obj::get_gray50( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray50",0x2afc304c,"haxor.math.Color.get_gray50","haxor/math/Color.hx",56,0x18984df5)
	HX_STACK_LINE(56)
	return ::haxor::math::Color_obj::__new(0.5,0.5,0.5,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray50,return )

::haxor::math::Color Color_obj::gray75;

::haxor::math::Color Color_obj::get_gray75( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray75",0x2afc320f,"haxor.math.Color.get_gray75","haxor/math/Color.hx",60,0x18984df5)
	HX_STACK_LINE(60)
	return ::haxor::math::Color_obj::__new(0.75,0.75,0.75,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray75,return )

::haxor::math::Color Color_obj::gray90;

::haxor::math::Color Color_obj::get_gray90( ){
	HX_STACK_FRAME("haxor.math.Color","get_gray90",0x2afc33c8,"haxor.math.Color.get_gray90","haxor/math/Color.hx",64,0x18984df5)
	HX_STACK_LINE(64)
	return ::haxor::math::Color_obj::__new(0.9,0.9,0.9,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Color_obj,get_gray90,return )

::haxor::math::Color Color_obj::FromHex( ::String p_hex){
	HX_STACK_FRAME("haxor.math.Color","FromHex",0xaea542cc,"haxor.math.Color.FromHex","haxor/math/Color.hx",72,0x18984df5)
	HX_STACK_ARG(p_hex,"p_hex")
	HX_STACK_LINE(73)
	::haxor::math::Color c = ::haxor::math::Color_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(74)
	if (((p_hex.length == (int)10))){
		HX_STACK_LINE(74)
		Dynamic _g = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(74)
		c->set_argb(_g);
	}
	else{
		HX_STACK_LINE(74)
		Dynamic _g1 = ::Std_obj::parseInt(p_hex);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(74)
		c->set_rgb(_g1);
	}
	HX_STACK_LINE(75)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Color_obj,FromHex,return )

::haxor::math::Color Color_obj::FromBytes( hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a){
Float p_r = __o_p_r.Default(0);
Float p_g = __o_p_g.Default(0);
Float p_b = __o_p_b.Default(0);
Float p_a = __o_p_a.Default(255.0);
	HX_STACK_FRAME("haxor.math.Color","FromBytes",0x2d62a69c,"haxor.math.Color.FromBytes","haxor/math/Color.hx",88,0x18984df5)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
{
		HX_STACK_LINE(88)
		return ::haxor::math::Color_obj::__new((p_r * 0.00392156863),(p_g * 0.00392156863),(p_b * 0.00392156863),(p_a * 0.00392156863));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Color_obj,FromBytes,return )

::haxor::math::Color Color_obj::Lerp( ::haxor::math::Color a,::haxor::math::Color b,Float r){
	HX_STACK_FRAME("haxor.math.Color","Lerp",0x4f20e05c,"haxor.math.Color.Lerp","haxor/math/Color.hx",100,0x18984df5)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(r,"r")
	struct _Function_1_1{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",100,0x18984df5)
			{
				HX_STACK_LINE(100)
				Float p_a = a->r;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(100)
				return (p_a + (((b->r - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",100,0x18984df5)
			{
				HX_STACK_LINE(100)
				Float p_a = a->g;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(100)
				return (p_a + (((b->g - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_3{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",100,0x18984df5)
			{
				HX_STACK_LINE(100)
				Float p_a = a->b;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(100)
				return (p_a + (((b->b - p_a)) * r));
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static Float Block( Float &r,::haxor::math::Color &b,::haxor::math::Color &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Color.hx",100,0x18984df5)
			{
				HX_STACK_LINE(100)
				Float p_a = a->a;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(100)
				return (p_a + (((b->a - p_a)) * r));
			}
			return null();
		}
	};
	HX_STACK_LINE(100)
	return ::haxor::math::Color_obj::__new(_Function_1_1::Block(r,b,a),_Function_1_2::Block(r,b,a),_Function_1_3::Block(r,b,a),_Function_1_4::Block(r,b,a));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Color_obj,Lerp,return )


Color_obj::Color_obj()
{
}

void Color_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Color);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

void Color_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
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
		if (HX_FIELD_EQ(inName,"css") ) { return get_css(); }
		if (HX_FIELD_EQ(inName,"rgb") ) { return get_rgb(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cyan") ) { return inCallProp ? get_cyan() : cyan; }
		if (HX_FIELD_EQ(inName,"blue") ) { return inCallProp ? get_blue() : blue; }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"argb") ) { return get_argb(); }
		if (HX_FIELD_EQ(inName,"rgba") ) { return get_rgba(); }
		if (HX_FIELD_EQ(inName,"Set4") ) { return Set4_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"green") ) { return inCallProp ? get_green() : green; }
		if (HX_FIELD_EQ(inName,"black") ) { return inCallProp ? get_black() : black; }
		if (HX_FIELD_EQ(inName,"white") ) { return inCallProp ? get_white() : white; }
		if (HX_FIELD_EQ(inName,"empty") ) { return inCallProp ? get_empty() : empty; }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yellow") ) { return inCallProp ? get_yellow() : yellow; }
		if (HX_FIELD_EQ(inName,"gray10") ) { return inCallProp ? get_gray10() : gray10; }
		if (HX_FIELD_EQ(inName,"gray25") ) { return inCallProp ? get_gray25() : gray25; }
		if (HX_FIELD_EQ(inName,"gray50") ) { return inCallProp ? get_gray50() : gray50; }
		if (HX_FIELD_EQ(inName,"gray75") ) { return inCallProp ? get_gray75() : gray75; }
		if (HX_FIELD_EQ(inName,"gray90") ) { return inCallProp ? get_gray90() : gray90; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_red") ) { return get_red_dyn(); }
		if (HX_FIELD_EQ(inName,"magenta") ) { return inCallProp ? get_magenta() : magenta; }
		if (HX_FIELD_EQ(inName,"FromHex") ) { return FromHex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_css") ) { return get_css_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rgb") ) { return get_rgb_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rgb") ) { return set_rgb_dyn(); }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_cyan") ) { return get_cyan_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blue") ) { return get_blue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_argb") ) { return get_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"set_argb") ) { return set_argb_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rgba") ) { return get_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rgba") ) { return set_rgba_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_green") ) { return get_green_dyn(); }
		if (HX_FIELD_EQ(inName,"get_black") ) { return get_black_dyn(); }
		if (HX_FIELD_EQ(inName,"get_white") ) { return get_white_dyn(); }
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		if (HX_FIELD_EQ(inName,"FromBytes") ) { return FromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
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
		if (HX_FIELD_EQ(inName,"rgb") ) { return set_rgb(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cyan") ) { cyan=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blue") ) { blue=inValue.Cast< ::haxor::math::Color >(); return inValue; }
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Color_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("argb"));
	outFields->push(HX_CSTRING("css"));
	outFields->push(HX_CSTRING("rgba"));
	outFields->push(HX_CSTRING("rgb"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
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
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Color_obj,clone),HX_CSTRING("clone")},
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
	HX_CSTRING("get_argb"),
	HX_CSTRING("set_argb"),
	HX_CSTRING("get_css"),
	HX_CSTRING("get_rgba"),
	HX_CSTRING("set_rgba"),
	HX_CSTRING("get_rgb"),
	HX_CSTRING("set_rgb"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("Set"),
	HX_CSTRING("Set4"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Color_obj::__mClass,"__mClass");
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
