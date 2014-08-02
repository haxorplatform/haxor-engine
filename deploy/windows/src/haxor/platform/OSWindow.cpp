#include <hxcpp.h>

#ifndef INCLUDED_haxor_platform_OSWindow
#include <haxor/platform/OSWindow.h>
#endif
namespace haxor{
namespace platform{

Void OSWindow_obj::__construct(::String p_title,int p_x,int p_y,int p_width,int p_height)
{
HX_STACK_FRAME("haxor.platform.OSWindow","new",0xa5578695,"haxor.platform.OSWindow.new","haxor/platform/OSWindow.hx",102,0x2bd5f69b)
HX_STACK_THIS(this)
HX_STACK_ARG(p_title,"p_title")
HX_STACK_ARG(p_x,"p_x")
HX_STACK_ARG(p_y,"p_y")
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
{
	HX_STACK_LINE(103)
	this->m_x = p_x;
	HX_STACK_LINE(104)
	this->m_y = p_y;
	HX_STACK_LINE(105)
	this->m_width = p_width;
	HX_STACK_LINE(106)
	this->m_height = p_height;
	HX_STACK_LINE(107)
	this->m_title = p_title;
	HX_STACK_LINE(108)
	this->m_focused = true;
	HX_STACK_LINE(109)
	this->m_fullscreen = false;
	HX_STACK_LINE(110)
	this->m_cursor_lock = false;
	HX_STACK_LINE(111)
	this->m_cursor_flag = (int)0;
	HX_STACK_LINE(112)
	this->m_mouseX = (int)0;
	HX_STACK_LINE(113)
	this->m_mouseY = (int)0;
}
;
	return null();
}

//OSWindow_obj::~OSWindow_obj() { }

Dynamic OSWindow_obj::__CreateEmpty() { return  new OSWindow_obj; }
hx::ObjectPtr< OSWindow_obj > OSWindow_obj::__new(::String p_title,int p_x,int p_y,int p_width,int p_height)
{  hx::ObjectPtr< OSWindow_obj > result = new OSWindow_obj();
	result->__construct(p_title,p_x,p_y,p_width,p_height);
	return result;}

Dynamic OSWindow_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< OSWindow_obj > result = new OSWindow_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

int OSWindow_obj::get_x( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_x",0x476612c4,"haxor.platform.OSWindow.get_x","haxor/platform/OSWindow.hx",14,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(14)
	return this->m_x;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_x,return )

int OSWindow_obj::set_x( int v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_x",0x303508d0,"haxor.platform.OSWindow.set_x","haxor/platform/OSWindow.hx",15,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(15)
	this->m_x = v;
	HX_STACK_LINE(15)
	this->OnResize();
	HX_STACK_LINE(15)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_x,return )

int OSWindow_obj::get_y( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_y",0x476612c5,"haxor.platform.OSWindow.get_y","haxor/platform/OSWindow.hx",23,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(23)
	return this->m_y;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_y,return )

int OSWindow_obj::set_y( int v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_y",0x303508d1,"haxor.platform.OSWindow.set_y","haxor/platform/OSWindow.hx",24,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(24)
	this->m_y = v;
	HX_STACK_LINE(24)
	this->OnResize();
	HX_STACK_LINE(24)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_y,return )

int OSWindow_obj::get_width( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_width",0xb5adde52,"haxor.platform.OSWindow.get_width","haxor/platform/OSWindow.hx",32,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	return this->m_width;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_width,return )

int OSWindow_obj::set_width( int v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_width",0x98feca5e,"haxor.platform.OSWindow.set_width","haxor/platform/OSWindow.hx",33,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(33)
	this->m_width = v;
	HX_STACK_LINE(33)
	this->OnResize();
	HX_STACK_LINE(33)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_width,return )

int OSWindow_obj::get_height( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_height",0xf8c4221b,"haxor.platform.OSWindow.get_height","haxor/platform/OSWindow.hx",41,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(41)
	return this->m_height;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_height,return )

int OSWindow_obj::set_height( int v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_height",0xfc41c08f,"haxor.platform.OSWindow.set_height","haxor/platform/OSWindow.hx",42,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(42)
	this->m_height = v;
	HX_STACK_LINE(42)
	this->OnResize();
	HX_STACK_LINE(42)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_height,return )

::String OSWindow_obj::get_title( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_title",0xfb863de4,"haxor.platform.OSWindow.get_title","haxor/platform/OSWindow.hx",51,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return this->m_title;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_title,return )

::String OSWindow_obj::set_title( ::String v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_title",0xded729f0,"haxor.platform.OSWindow.set_title","haxor/platform/OSWindow.hx",53,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(54)
	this->m_title = v;
	HX_STACK_LINE(55)
	this->OnTitleChange();
	HX_STACK_LINE(56)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_title,return )

bool OSWindow_obj::get_focused( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_focused",0xf4223183,"haxor.platform.OSWindow.get_focused","haxor/platform/OSWindow.hx",64,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(64)
	return this->m_focused;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_focused,return )

bool OSWindow_obj::get_fullscreen( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_fullscreen",0xe8177e6f,"haxor.platform.OSWindow.get_fullscreen","haxor/platform/OSWindow.hx",71,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(71)
	return this->m_fullscreen;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_fullscreen,return )

bool OSWindow_obj::set_fullscreen( bool v){
	HX_STACK_FRAME("haxor.platform.OSWindow","set_fullscreen",0x083766e3,"haxor.platform.OSWindow.set_fullscreen","haxor/platform/OSWindow.hx",72,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(72)
	if (((this->m_fullscreen == v))){
		HX_STACK_LINE(72)
		return v;
	}
	HX_STACK_LINE(72)
	this->m_fullscreen = v;
	HX_STACK_LINE(72)
	this->OnFullscreen();
	HX_STACK_LINE(72)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(OSWindow_obj,set_fullscreen,return )

int OSWindow_obj::get_mouseX( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_mouseX",0xc28664c7,"haxor.platform.OSWindow.get_mouseX","haxor/platform/OSWindow.hx",79,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(79)
	return this->m_mouseX;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_mouseX,return )

int OSWindow_obj::get_mouseY( ){
	HX_STACK_FRAME("haxor.platform.OSWindow","get_mouseY",0xc28664c8,"haxor.platform.OSWindow.get_mouseY","haxor/platform/OSWindow.hx",86,0x2bd5f69b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(86)
	return this->m_mouseY;
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,get_mouseY,return )

Void OSWindow_obj::Run( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","Run",0xa5425560,"haxor.platform.OSWindow.Run","haxor/platform/OSWindow.hx",120,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,Run,(void))

Void OSWindow_obj::EnableCursor( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","EnableCursor",0x94c99d04,"haxor.platform.OSWindow.EnableCursor","haxor/platform/OSWindow.hx",125,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,EnableCursor,(void))

Void OSWindow_obj::DisableCursor( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","DisableCursor",0xf0fd8533,"haxor.platform.OSWindow.DisableCursor","haxor/platform/OSWindow.hx",130,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,DisableCursor,(void))

Void OSWindow_obj::LockCursor( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","LockCursor",0x86308fac,"haxor.platform.OSWindow.LockCursor","haxor/platform/OSWindow.hx",135,0x2bd5f69b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(135)
		this->m_cursor_lock = true;
		HX_STACK_LINE(135)
		this->m_cursor_flag = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,LockCursor,(void))

Void OSWindow_obj::UnlockCursor( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","UnlockCursor",0xa0f0b805,"haxor.platform.OSWindow.UnlockCursor","haxor/platform/OSWindow.hx",140,0x2bd5f69b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(140)
		this->m_cursor_lock = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,UnlockCursor,(void))

Void OSWindow_obj::OnResize( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","OnResize",0x368cb63e,"haxor.platform.OSWindow.OnResize","haxor/platform/OSWindow.hx",145,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,OnResize,(void))

Void OSWindow_obj::OnFullscreen( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","OnFullscreen",0x7d4a8385,"haxor.platform.OSWindow.OnFullscreen","haxor/platform/OSWindow.hx",150,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,OnFullscreen,(void))

Void OSWindow_obj::OnTitleChange( ){
{
		HX_STACK_FRAME("haxor.platform.OSWindow","OnTitleChange",0xede8349e,"haxor.platform.OSWindow.OnTitleChange","haxor/platform/OSWindow.hx",155,0x2bd5f69b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(OSWindow_obj,OnTitleChange,(void))


OSWindow_obj::OSWindow_obj()
{
}

void OSWindow_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(OSWindow);
	HX_MARK_MEMBER_NAME(m_x,"m_x");
	HX_MARK_MEMBER_NAME(m_fs_x,"m_fs_x");
	HX_MARK_MEMBER_NAME(m_y,"m_y");
	HX_MARK_MEMBER_NAME(m_fs_y,"m_fs_y");
	HX_MARK_MEMBER_NAME(m_width,"m_width");
	HX_MARK_MEMBER_NAME(m_fs_width,"m_fs_width");
	HX_MARK_MEMBER_NAME(m_height,"m_height");
	HX_MARK_MEMBER_NAME(m_fs_height,"m_fs_height");
	HX_MARK_MEMBER_NAME(m_title,"m_title");
	HX_MARK_MEMBER_NAME(focused,"focused");
	HX_MARK_MEMBER_NAME(m_focused,"m_focused");
	HX_MARK_MEMBER_NAME(m_fullscreen,"m_fullscreen");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(m_mouseX,"m_mouseX");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(m_mouseY,"m_mouseY");
	HX_MARK_MEMBER_NAME(m_cursor_lock,"m_cursor_lock");
	HX_MARK_MEMBER_NAME(m_cursor_flag,"m_cursor_flag");
	HX_MARK_END_CLASS();
}

void OSWindow_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_x,"m_x");
	HX_VISIT_MEMBER_NAME(m_fs_x,"m_fs_x");
	HX_VISIT_MEMBER_NAME(m_y,"m_y");
	HX_VISIT_MEMBER_NAME(m_fs_y,"m_fs_y");
	HX_VISIT_MEMBER_NAME(m_width,"m_width");
	HX_VISIT_MEMBER_NAME(m_fs_width,"m_fs_width");
	HX_VISIT_MEMBER_NAME(m_height,"m_height");
	HX_VISIT_MEMBER_NAME(m_fs_height,"m_fs_height");
	HX_VISIT_MEMBER_NAME(m_title,"m_title");
	HX_VISIT_MEMBER_NAME(focused,"focused");
	HX_VISIT_MEMBER_NAME(m_focused,"m_focused");
	HX_VISIT_MEMBER_NAME(m_fullscreen,"m_fullscreen");
	HX_VISIT_MEMBER_NAME(mouseX,"mouseX");
	HX_VISIT_MEMBER_NAME(m_mouseX,"m_mouseX");
	HX_VISIT_MEMBER_NAME(mouseY,"mouseY");
	HX_VISIT_MEMBER_NAME(m_mouseY,"m_mouseY");
	HX_VISIT_MEMBER_NAME(m_cursor_lock,"m_cursor_lock");
	HX_VISIT_MEMBER_NAME(m_cursor_flag,"m_cursor_flag");
}

Dynamic OSWindow_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_x") ) { return m_x; }
		if (HX_FIELD_EQ(inName,"m_y") ) { return m_y; }
		if (HX_FIELD_EQ(inName,"Run") ) { return Run_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"title") ) { return get_title(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_fs_x") ) { return m_fs_x; }
		if (HX_FIELD_EQ(inName,"m_fs_y") ) { return m_fs_y; }
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return inCallProp ? get_mouseX() : mouseX; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return inCallProp ? get_mouseY() : mouseY; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { return m_width; }
		if (HX_FIELD_EQ(inName,"m_title") ) { return m_title; }
		if (HX_FIELD_EQ(inName,"focused") ) { return inCallProp ? get_focused() : focused; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { return m_height; }
		if (HX_FIELD_EQ(inName,"m_mouseX") ) { return m_mouseX; }
		if (HX_FIELD_EQ(inName,"m_mouseY") ) { return m_mouseY; }
		if (HX_FIELD_EQ(inName,"OnResize") ) { return OnResize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_title") ) { return get_title_dyn(); }
		if (HX_FIELD_EQ(inName,"set_title") ) { return set_title_dyn(); }
		if (HX_FIELD_EQ(inName,"m_focused") ) { return m_focused; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_fs_width") ) { return m_fs_width; }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return get_fullscreen(); }
		if (HX_FIELD_EQ(inName,"get_mouseX") ) { return get_mouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mouseY") ) { return get_mouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"LockCursor") ) { return LockCursor_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_fs_height") ) { return m_fs_height; }
		if (HX_FIELD_EQ(inName,"get_focused") ) { return get_focused_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_fullscreen") ) { return m_fullscreen; }
		if (HX_FIELD_EQ(inName,"EnableCursor") ) { return EnableCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"UnlockCursor") ) { return UnlockCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"OnFullscreen") ) { return OnFullscreen_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_cursor_lock") ) { return m_cursor_lock; }
		if (HX_FIELD_EQ(inName,"m_cursor_flag") ) { return m_cursor_flag; }
		if (HX_FIELD_EQ(inName,"DisableCursor") ) { return DisableCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTitleChange") ) { return OnTitleChange_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_fullscreen") ) { return get_fullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fullscreen") ) { return set_fullscreen_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic OSWindow_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_x") ) { m_x=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_y") ) { m_y=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		if (HX_FIELD_EQ(inName,"title") ) { return set_title(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_fs_x") ) { m_fs_x=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fs_y") ) { m_fs_y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { m_width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_title") ) { m_title=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"focused") ) { focused=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { m_height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mouseX") ) { m_mouseX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mouseY") ) { m_mouseY=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_focused") ) { m_focused=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_fs_width") ) { m_fs_width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return set_fullscreen(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_fs_height") ) { m_fs_height=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_fullscreen") ) { m_fullscreen=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_cursor_lock") ) { m_cursor_lock=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cursor_flag") ) { m_cursor_flag=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void OSWindow_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("m_x"));
	outFields->push(HX_CSTRING("m_fs_x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("m_y"));
	outFields->push(HX_CSTRING("m_fs_y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("m_width"));
	outFields->push(HX_CSTRING("m_fs_width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("m_height"));
	outFields->push(HX_CSTRING("m_fs_height"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("m_title"));
	outFields->push(HX_CSTRING("focused"));
	outFields->push(HX_CSTRING("m_focused"));
	outFields->push(HX_CSTRING("fullscreen"));
	outFields->push(HX_CSTRING("m_fullscreen"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("m_mouseX"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("m_mouseY"));
	outFields->push(HX_CSTRING("m_cursor_lock"));
	outFields->push(HX_CSTRING("m_cursor_flag"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_x),HX_CSTRING("m_x")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_fs_x),HX_CSTRING("m_fs_x")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_y),HX_CSTRING("m_y")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_fs_y),HX_CSTRING("m_fs_y")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_width),HX_CSTRING("m_width")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_fs_width),HX_CSTRING("m_fs_width")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_height),HX_CSTRING("m_height")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_fs_height),HX_CSTRING("m_fs_height")},
	{hx::fsString,(int)offsetof(OSWindow_obj,m_title),HX_CSTRING("m_title")},
	{hx::fsBool,(int)offsetof(OSWindow_obj,focused),HX_CSTRING("focused")},
	{hx::fsBool,(int)offsetof(OSWindow_obj,m_focused),HX_CSTRING("m_focused")},
	{hx::fsBool,(int)offsetof(OSWindow_obj,m_fullscreen),HX_CSTRING("m_fullscreen")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,mouseX),HX_CSTRING("mouseX")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_mouseX),HX_CSTRING("m_mouseX")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,mouseY),HX_CSTRING("mouseY")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_mouseY),HX_CSTRING("m_mouseY")},
	{hx::fsBool,(int)offsetof(OSWindow_obj,m_cursor_lock),HX_CSTRING("m_cursor_lock")},
	{hx::fsInt,(int)offsetof(OSWindow_obj,m_cursor_flag),HX_CSTRING("m_cursor_flag")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("m_x"),
	HX_CSTRING("m_fs_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("m_y"),
	HX_CSTRING("m_fs_y"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("m_width"),
	HX_CSTRING("m_fs_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("m_height"),
	HX_CSTRING("m_fs_height"),
	HX_CSTRING("get_title"),
	HX_CSTRING("set_title"),
	HX_CSTRING("m_title"),
	HX_CSTRING("focused"),
	HX_CSTRING("get_focused"),
	HX_CSTRING("m_focused"),
	HX_CSTRING("get_fullscreen"),
	HX_CSTRING("set_fullscreen"),
	HX_CSTRING("m_fullscreen"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("get_mouseX"),
	HX_CSTRING("m_mouseX"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("get_mouseY"),
	HX_CSTRING("m_mouseY"),
	HX_CSTRING("m_cursor_lock"),
	HX_CSTRING("m_cursor_flag"),
	HX_CSTRING("Run"),
	HX_CSTRING("EnableCursor"),
	HX_CSTRING("DisableCursor"),
	HX_CSTRING("LockCursor"),
	HX_CSTRING("UnlockCursor"),
	HX_CSTRING("OnResize"),
	HX_CSTRING("OnFullscreen"),
	HX_CSTRING("OnTitleChange"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OSWindow_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OSWindow_obj::__mClass,"__mClass");
};

#endif

Class OSWindow_obj::__mClass;

void OSWindow_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.OSWindow"), hx::TCanCast< OSWindow_obj> ,sStaticFields,sMemberFields,
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

void OSWindow_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
