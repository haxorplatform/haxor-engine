#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_net_HTTPRequestTask
#include <haxor/net/HTTPRequestTask.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_BitmapLoader
#include <haxor/platform/windows/net/BitmapLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPLoader
#include <haxor/platform/windows/net/HTTPLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPRequest
#include <haxor/platform/windows/net/HTTPRequest.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
namespace haxor{
namespace platform{
namespace windows{
namespace net{

Void BitmapLoader_obj::__construct(::String p_url,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.platform.windows.net.BitmapLoader","new",0x6ef557df,"haxor.platform.windows.net.BitmapLoader.new","haxor/platform/windows/net/BitmapLoader.hx",44,0x5c286a4f)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_callback,"p_callback")
{
	HX_STACK_LINE(45)
	super::__construct(p_url,true,this->OnBufferCallback_dyn());
	HX_STACK_LINE(46)
	this->m_bitmap_callback = p_callback;
}
;
	return null();
}

//BitmapLoader_obj::~BitmapLoader_obj() { }

Dynamic BitmapLoader_obj::__CreateEmpty() { return  new BitmapLoader_obj; }
hx::ObjectPtr< BitmapLoader_obj > BitmapLoader_obj::__new(::String p_url,Dynamic p_callback)
{  hx::ObjectPtr< BitmapLoader_obj > result = new BitmapLoader_obj();
	result->__construct(p_url,p_callback);
	return result;}

Dynamic BitmapLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapLoader_obj > result = new BitmapLoader_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BitmapLoader_obj::OnBufferCallback( ::haxor::io::Buffer p_data,Float p_progress){
{
		HX_STACK_FRAME("haxor.platform.windows.net.BitmapLoader","OnBufferCallback",0x79d571a5,"haxor.platform.windows.net.BitmapLoader.OnBufferCallback","haxor/platform/windows/net/BitmapLoader.hx",52,0x5c286a4f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_progress,"p_progress")
		HX_STACK_LINE(52)
		if (((this->m_progress < 1.0))){
			HX_STACK_LINE(54)
			if (((this->m_bitmap_callback_dyn() != null()))){
				HX_STACK_LINE(54)
				this->m_bitmap_callback(null(),(this->m_progress * 0.999));
			}
		}
		else{
			HX_STACK_LINE(58)
			if (((p_data == null()))){
				HX_STACK_LINE(58)
				return null();
			}
			HX_STACK_LINE(60)
			::haxe::io::Bytes file_bl = p_data->m_buffer;		HX_STACK_VAR(file_bl,"file_bl");
			HX_STACK_LINE(61)
			int file_len = p_data->m_length;		HX_STACK_VAR(file_len,"file_len");
			HX_STACK_LINE(62)
			int w = (int)0;		HX_STACK_VAR(w,"w");
			HX_STACK_LINE(63)
			int h = (int)0;		HX_STACK_VAR(h,"h");
			HX_STACK_LINE(64)
			int byte_length = (int)0;		HX_STACK_VAR(byte_length,"byte_length");
			HX_STACK_LINE(65)
			int cc = (int)0;		HX_STACK_VAR(cc,"cc");
			HX_STACK_LINE(67)
			
			unsigned char * img_buffer = (stbi_uc * ) stbi_load_from_memory( & file_bl->b[0], file_len, & w, & h, & cc, 0);			
			;
			HX_STACK_LINE(72)
			byte_length = ((w * h) * cc);
			HX_STACK_LINE(73)
			::haxor::io::Buffer buffer = ::haxor::io::Buffer_obj::__new(byte_length);		HX_STACK_VAR(buffer,"buffer");
			HX_STACK_LINE(74)
			::haxe::io::Bytes bytes = buffer->m_buffer;		HX_STACK_VAR(bytes,"bytes");
			HX_STACK_LINE(76)
			
			for (int i = 0; i < byte_length;i++) bytes->b[i] = img_buffer[i];
			stbi_image_free(img_buffer);
			;
			HX_STACK_LINE(81)
			::haxor::core::PixelFormat fmt = ::haxor::core::PixelFormat_obj::RGBA8;		HX_STACK_VAR(fmt,"fmt");
			HX_STACK_LINE(82)
			switch( (int)(cc)){
				case (int)1: {
					HX_STACK_LINE(84)
					fmt = ::haxor::core::PixelFormat_obj::Alpha8;
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(85)
					fmt = ::haxor::core::PixelFormat_obj::RGB8;
				}
				;break;
			}
			HX_STACK_LINE(87)
			::haxor::graphics::texture::Bitmap b = ::haxor::graphics::texture::Bitmap_obj::__new(w,h,fmt);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(88)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(89)
			::haxor::math::Color c;		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(89)
			{
				HX_STACK_LINE(89)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(89)
				int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(89)
				c = _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
			}
			HX_STACK_LINE(90)
			while((true)){
				HX_STACK_LINE(90)
				int _g1 = buffer->get_bytesPerElement();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(90)
				int _g2 = (buffer->m_length * _g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(90)
				if ((!(((k < _g2))))){
					HX_STACK_LINE(90)
					break;
				}
				HX_STACK_LINE(92)
				int pix = (Float(k) / Float(cc));		HX_STACK_VAR(pix,"pix");
				HX_STACK_LINE(93)
				int px = hx::Mod(pix,b->m_width);		HX_STACK_VAR(px,"px");
				HX_STACK_LINE(94)
				int py = (Float(pix) / Float(b->m_width));		HX_STACK_VAR(py,"py");
				HX_STACK_LINE(95)
				int ipix = ((((px + ((((b->m_height - (int)1) - py)) * b->m_width))) * cc) + hx::Mod(k,cc));		HX_STACK_VAR(ipix,"ipix");
				HX_STACK_LINE(96)
				int v = buffer->GetByte(ipix);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(97)
				b->get_buffer()->SetByte(k,v);
				HX_STACK_LINE(98)
				(k)++;
			}
			HX_STACK_LINE(100)
			if (((this->m_bitmap_callback_dyn() != null()))){
				HX_STACK_LINE(100)
				this->m_bitmap_callback(b,1.0);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapLoader_obj,OnBufferCallback,(void))

Void BitmapLoader_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.BitmapLoader","OnError",0xe20d4508,"haxor.platform.windows.net.BitmapLoader.OnError","haxor/platform/windows/net/BitmapLoader.hx",104,0x5c286a4f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(104)
		this->super::OnError();
		HX_STACK_LINE(104)
		if (((this->m_bitmap_callback_dyn() != null()))){
			HX_STACK_LINE(104)
			this->m_bitmap_callback(null(),1.0);
		}
	}
return null();
}



BitmapLoader_obj::BitmapLoader_obj()
{
}

void BitmapLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapLoader);
	HX_MARK_MEMBER_NAME(m_bitmap_callback,"m_bitmap_callback");
	::haxor::platform::windows::net::HTTPLoader_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BitmapLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_bitmap_callback,"m_bitmap_callback");
	::haxor::platform::windows::net::HTTPLoader_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BitmapLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnBufferCallback") ) { return OnBufferCallback_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_bitmap_callback") ) { return m_bitmap_callback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"m_bitmap_callback") ) { m_bitmap_callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(BitmapLoader_obj,m_bitmap_callback),HX_CSTRING("m_bitmap_callback")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_bitmap_callback"),
	HX_CSTRING("OnBufferCallback"),
	HX_CSTRING("OnError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapLoader_obj::__mClass,"__mClass");
};

#endif

Class BitmapLoader_obj::__mClass;

void BitmapLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.net.BitmapLoader"), hx::TCanCast< BitmapLoader_obj> ,sStaticFields,sMemberFields,
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

void BitmapLoader_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace net
