#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_PixelFormat
#include <haxor/graphics/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void Bitmap_obj::__construct(int p_width,int p_height,::haxor::graphics::PixelFormat p_format)
{
HX_STACK_FRAME("haxor.graphics.texture.Bitmap","new",0x6aeebecb,"haxor.graphics.texture.Bitmap.new","haxor/graphics/texture/Bitmap.hx",66,0x9c278704)
HX_STACK_THIS(this)
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
HX_STACK_ARG(p_format,"p_format")
{
	HX_STACK_LINE(67)
	super::__construct(null());
	HX_STACK_LINE(68)
	this->m_width = p_width;
	HX_STACK_LINE(69)
	this->m_height = p_height;
	HX_STACK_LINE(70)
	this->m_format = p_format;
	HX_STACK_LINE(71)
	this->m_float = false;
	HX_STACK_LINE(72)
	this->m_channels = (int)1;
	HX_STACK_LINE(73)
	switch( (int)(p_format->__Index())){
		case (int)1: {
			HX_STACK_LINE(75)
			this->m_channels = (int)1;
		}
		;break;
		case (int)0: {
			HX_STACK_LINE(76)
			this->m_channels = (int)1;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(77)
			this->m_channels = (int)3;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(78)
			this->m_channels = (int)4;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(79)
			this->m_channels = (int)1;
			HX_STACK_LINE(79)
			this->m_float = true;
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(80)
			this->m_channels = (int)1;
			HX_STACK_LINE(80)
			this->m_float = true;
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(81)
			this->m_channels = (int)1;
			HX_STACK_LINE(81)
			this->m_float = true;
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(82)
			this->m_channels = (int)3;
			HX_STACK_LINE(82)
			this->m_float = true;
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(83)
			this->m_channels = (int)3;
			HX_STACK_LINE(83)
			this->m_float = true;
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(84)
			this->m_channels = (int)4;
			HX_STACK_LINE(84)
			this->m_float = true;
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(85)
			this->m_channels = (int)4;
			HX_STACK_LINE(85)
			this->m_float = true;
		}
		;break;
	}
	HX_STACK_LINE(88)
	int len = ((this->m_width * this->m_height) * this->m_channels);		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(89)
	::haxor::io::Buffer _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(89)
	if ((this->m_float)){
		HX_STACK_LINE(89)
		_g = ::haxor::io::FloatArray_obj::__new(len);
	}
	else{
		HX_STACK_LINE(89)
		_g = ::haxor::io::Buffer_obj::__new(len);
	}
	HX_STACK_LINE(89)
	this->m_buffer = _g;
}
;
	return null();
}

//Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(int p_width,int p_height,::haxor::graphics::PixelFormat p_format)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(p_width,p_height,p_format);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::haxor::io::Buffer Bitmap_obj::get_buffer( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_buffer",0x0bf0b1be,"haxor.graphics.texture.Bitmap.get_buffer","haxor/graphics/texture/Bitmap.hx",20,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	return this->m_buffer;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_buffer,return )

bool Bitmap_obj::get_float( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_float",0xf63a329e,"haxor.graphics.texture.Bitmap.get_float","haxor/graphics/texture/Bitmap.hx",27,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(27)
	return this->m_float;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_float,return )

int Bitmap_obj::get_width( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_width",0xbe062308,"haxor.graphics.texture.Bitmap.get_width","haxor/graphics/texture/Bitmap.hx",34,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	return this->m_width;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_width,return )

int Bitmap_obj::get_height( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_height",0x3da7fca5,"haxor.graphics.texture.Bitmap.get_height","haxor/graphics/texture/Bitmap.hx",41,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(41)
	return this->m_height;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_height,return )

int Bitmap_obj::get_channels( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_channels",0x2cbfca8e,"haxor.graphics.texture.Bitmap.get_channels","haxor/graphics/texture/Bitmap.hx",48,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return this->m_channels;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_channels,return )

::haxor::graphics::PixelFormat Bitmap_obj::get_format( ){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","get_format",0x38ea83f5,"haxor.graphics.texture.Bitmap.get_format","haxor/graphics/texture/Bitmap.hx",55,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_format;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,get_format,return )

::haxor::math::Color Bitmap_obj::GetPixel( int p_x,int p_y){
	HX_STACK_FRAME("haxor.graphics.texture.Bitmap","GetPixel",0x9b627fe5,"haxor.graphics.texture.Bitmap.GetPixel","haxor/graphics/texture/Bitmap.hx",99,0x9c278704)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_LINE(100)
	if (((p_x < (int)0))){
		HX_STACK_LINE(100)
		return ::haxor::math::Color_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(101)
	if (((p_y < (int)0))){
		HX_STACK_LINE(101)
		return ::haxor::math::Color_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(102)
	if (((p_x >= this->m_width))){
		HX_STACK_LINE(102)
		return ::haxor::math::Color_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(103)
	if (((p_y >= this->m_height))){
		HX_STACK_LINE(103)
		return ::haxor::math::Color_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(104)
	int cc = this->m_channels;		HX_STACK_VAR(cc,"cc");
	HX_STACK_LINE(105)
	int pos = (((p_x + (p_y * this->m_width))) * cc);		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(106)
	if ((this->m_float)){
		HX_STACK_LINE(108)
		::haxor::math::Color c = ::haxor::math::Color_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(109)
		::haxor::io::FloatArray b = this->m_buffer;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(110)
		switch( (int)(cc)){
			case (int)1: {
				HX_STACK_LINE(112)
				Float _g = b->Get(pos);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(112)
				c->r = _g;
				HX_STACK_LINE(112)
				c->g = c->r;
				HX_STACK_LINE(112)
				c->b = c->r;
				HX_STACK_LINE(112)
				c->a = 1.0;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(113)
				Float _g1 = b->Get(pos);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(113)
				c->r = _g1;
				HX_STACK_LINE(113)
				Float _g2 = b->Get((pos + (int)1));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(113)
				c->g = _g2;
				HX_STACK_LINE(113)
				c->b = c->r;
				HX_STACK_LINE(113)
				c->a = 1.0;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(114)
				Float _g3 = b->Get(pos);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(114)
				c->r = _g3;
				HX_STACK_LINE(114)
				Float _g4 = b->Get((pos + (int)1));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(114)
				c->g = _g4;
				HX_STACK_LINE(114)
				Float _g5 = b->Get((pos + (int)2));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(114)
				c->b = _g5;
				HX_STACK_LINE(114)
				c->a = 1.0;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(115)
				Float _g6 = b->Get(pos);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(115)
				c->r = _g6;
				HX_STACK_LINE(115)
				Float _g7 = b->Get((pos + (int)1));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(115)
				c->g = _g7;
				HX_STACK_LINE(115)
				Float _g8 = b->Get((pos + (int)2));		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(115)
				c->b = _g8;
				HX_STACK_LINE(115)
				Float _g9 = b->Get((pos + (int)3));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(115)
				c->a = _g9;
			}
			;break;
		}
		HX_STACK_LINE(117)
		return c;
	}
	HX_STACK_LINE(119)
	::haxor::io::Buffer b = this->m_buffer;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(120)
	int rb = b->GetByte(pos);		HX_STACK_VAR(rb,"rb");
	HX_STACK_LINE(121)
	int gb;		HX_STACK_VAR(gb,"gb");
	HX_STACK_LINE(121)
	if (((cc >= (int)2))){
		HX_STACK_LINE(121)
		gb = b->GetByte((pos + (int)1));
	}
	else{
		HX_STACK_LINE(121)
		gb = rb;
	}
	HX_STACK_LINE(122)
	int bb;		HX_STACK_VAR(bb,"bb");
	HX_STACK_LINE(122)
	if (((cc >= (int)3))){
		HX_STACK_LINE(122)
		bb = b->GetByte((pos + (int)2));
	}
	else{
		HX_STACK_LINE(122)
		bb = rb;
	}
	HX_STACK_LINE(123)
	int ab;		HX_STACK_VAR(ab,"ab");
	HX_STACK_LINE(123)
	if (((cc >= (int)4))){
		HX_STACK_LINE(123)
		ab = b->GetByte((pos + (int)3));
	}
	else{
		HX_STACK_LINE(123)
		ab = rb;
	}
	HX_STACK_LINE(124)
	return ::haxor::math::Color_obj::FromBytes(rb,gb,bb,ab);
}


HX_DEFINE_DYNAMIC_FUNC2(Bitmap_obj,GetPixel,return )

Void Bitmap_obj::SetPixel( int p_x,int p_y,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.texture.Bitmap","SetPixel",0x49bfd959,"haxor.graphics.texture.Bitmap.SetPixel","haxor/graphics/texture/Bitmap.hx",134,0x9c278704)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(135)
		if (((p_x < (int)0))){
			HX_STACK_LINE(135)
			return null();
		}
		HX_STACK_LINE(136)
		if (((p_y < (int)0))){
			HX_STACK_LINE(136)
			return null();
		}
		HX_STACK_LINE(137)
		if (((p_x >= this->m_width))){
			HX_STACK_LINE(137)
			return null();
		}
		HX_STACK_LINE(138)
		if (((p_y >= this->m_height))){
			HX_STACK_LINE(138)
			return null();
		}
		HX_STACK_LINE(139)
		int cc = this->m_channels;		HX_STACK_VAR(cc,"cc");
		HX_STACK_LINE(140)
		int pos = (((p_x + (p_y * this->m_width))) * cc);		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(141)
		if ((this->m_float)){
			HX_STACK_LINE(143)
			::haxor::io::FloatArray b = this->m_buffer;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(144)
			b->Set(pos,p_color->r);
			HX_STACK_LINE(145)
			if (((cc >= (int)2))){
				HX_STACK_LINE(145)
				b->Set((pos + (int)1),p_color->g);
			}
			HX_STACK_LINE(146)
			if (((cc >= (int)3))){
				HX_STACK_LINE(146)
				b->Set((pos + (int)2),p_color->b);
			}
			HX_STACK_LINE(147)
			if (((cc >= (int)4))){
				HX_STACK_LINE(147)
				b->Set((pos + (int)3),p_color->a);
			}
			HX_STACK_LINE(148)
			return null();
		}
		HX_STACK_LINE(150)
		::haxor::io::Buffer b = this->m_buffer;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(151)
		b->SetByte(pos,(p_color->r * 255.0));
		HX_STACK_LINE(152)
		if (((cc >= (int)2))){
			HX_STACK_LINE(152)
			b->SetByte((pos + (int)1),(p_color->g * 255.0));
		}
		HX_STACK_LINE(153)
		if (((cc >= (int)3))){
			HX_STACK_LINE(153)
			b->SetByte((pos + (int)2),(p_color->b * 255.0));
		}
		HX_STACK_LINE(154)
		if (((cc >= (int)4))){
			HX_STACK_LINE(154)
			b->SetByte((pos + (int)3),(p_color->a * 255.0));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Bitmap_obj,SetPixel,(void))

Void Bitmap_obj::Fill( ::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.texture.Bitmap","Fill",0x0b8aa9d8,"haxor.graphics.texture.Bitmap.Fill","haxor/graphics/texture/Bitmap.hx",163,0x9c278704)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(163)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(163)
		int _g = this->m_width;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(163)
		while((true)){
			HX_STACK_LINE(163)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(163)
				break;
			}
			HX_STACK_LINE(163)
			int ix = (_g1)++;		HX_STACK_VAR(ix,"ix");
			HX_STACK_LINE(163)
			int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(163)
			int _g2 = this->m_height;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(163)
			while((true)){
				HX_STACK_LINE(163)
				if ((!(((_g3 < _g2))))){
					HX_STACK_LINE(163)
					break;
				}
				HX_STACK_LINE(163)
				int iy = (_g3)++;		HX_STACK_VAR(iy,"iy");
				HX_STACK_LINE(163)
				this->SetPixel(ix,iy,p_color);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,Fill,(void))


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(buffer,"buffer");
	HX_MARK_MEMBER_NAME(m_buffer,"m_buffer");
	HX_MARK_MEMBER_NAME(_float,"float");
	HX_MARK_MEMBER_NAME(m_float,"m_float");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(m_width,"m_width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(m_height,"m_height");
	HX_MARK_MEMBER_NAME(channels,"channels");
	HX_MARK_MEMBER_NAME(m_channels,"m_channels");
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(m_format,"m_format");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Bitmap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buffer,"buffer");
	HX_VISIT_MEMBER_NAME(m_buffer,"m_buffer");
	HX_VISIT_MEMBER_NAME(_float,"float");
	HX_VISIT_MEMBER_NAME(m_float,"m_float");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(m_width,"m_width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(m_height,"m_height");
	HX_VISIT_MEMBER_NAME(channels,"channels");
	HX_VISIT_MEMBER_NAME(m_channels,"m_channels");
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(m_format,"m_format");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Bitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Fill") ) { return Fill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"float") ) { return inCallProp ? get_float() : _float; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { return inCallProp ? get_buffer() : buffer; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"format") ) { return inCallProp ? get_format() : format; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_float") ) { return m_float; }
		if (HX_FIELD_EQ(inName,"m_width") ) { return m_width; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { return m_buffer; }
		if (HX_FIELD_EQ(inName,"m_height") ) { return m_height; }
		if (HX_FIELD_EQ(inName,"channels") ) { return inCallProp ? get_channels() : channels; }
		if (HX_FIELD_EQ(inName,"m_format") ) { return m_format; }
		if (HX_FIELD_EQ(inName,"GetPixel") ) { return GetPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"SetPixel") ) { return SetPixel_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_float") ) { return get_float_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_buffer") ) { return get_buffer_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"m_channels") ) { return m_channels; }
		if (HX_FIELD_EQ(inName,"get_format") ) { return get_format_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_channels") ) { return get_channels_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"float") ) { _float=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { buffer=inValue.Cast< ::haxor::io::Buffer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast< ::haxor::graphics::PixelFormat >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_float") ) { m_float=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_width") ) { m_width=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { m_buffer=inValue.Cast< ::haxor::io::Buffer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_height") ) { m_height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"channels") ) { channels=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_format") ) { m_format=inValue.Cast< ::haxor::graphics::PixelFormat >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_channels") ) { m_channels=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buffer"));
	outFields->push(HX_CSTRING("m_buffer"));
	outFields->push(HX_CSTRING("float"));
	outFields->push(HX_CSTRING("m_float"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("m_width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("m_height"));
	outFields->push(HX_CSTRING("channels"));
	outFields->push(HX_CSTRING("m_channels"));
	outFields->push(HX_CSTRING("format"));
	outFields->push(HX_CSTRING("m_format"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::io::Buffer*/ ,(int)offsetof(Bitmap_obj,buffer),HX_CSTRING("buffer")},
	{hx::fsObject /*::haxor::io::Buffer*/ ,(int)offsetof(Bitmap_obj,m_buffer),HX_CSTRING("m_buffer")},
	{hx::fsBool,(int)offsetof(Bitmap_obj,_float),HX_CSTRING("float")},
	{hx::fsBool,(int)offsetof(Bitmap_obj,m_float),HX_CSTRING("m_float")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,width),HX_CSTRING("width")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,m_width),HX_CSTRING("m_width")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,height),HX_CSTRING("height")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,m_height),HX_CSTRING("m_height")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,channels),HX_CSTRING("channels")},
	{hx::fsInt,(int)offsetof(Bitmap_obj,m_channels),HX_CSTRING("m_channels")},
	{hx::fsObject /*::haxor::graphics::PixelFormat*/ ,(int)offsetof(Bitmap_obj,format),HX_CSTRING("format")},
	{hx::fsObject /*::haxor::graphics::PixelFormat*/ ,(int)offsetof(Bitmap_obj,m_format),HX_CSTRING("m_format")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("buffer"),
	HX_CSTRING("get_buffer"),
	HX_CSTRING("m_buffer"),
	HX_CSTRING("float"),
	HX_CSTRING("get_float"),
	HX_CSTRING("m_float"),
	HX_CSTRING("width"),
	HX_CSTRING("get_width"),
	HX_CSTRING("m_width"),
	HX_CSTRING("height"),
	HX_CSTRING("get_height"),
	HX_CSTRING("m_height"),
	HX_CSTRING("channels"),
	HX_CSTRING("get_channels"),
	HX_CSTRING("m_channels"),
	HX_CSTRING("format"),
	HX_CSTRING("get_format"),
	HX_CSTRING("m_format"),
	HX_CSTRING("GetPixel"),
	HX_CSTRING("SetPixel"),
	HX_CSTRING("Fill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bitmap_obj::__mClass,"__mClass");
};

#endif

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
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

void Bitmap_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
