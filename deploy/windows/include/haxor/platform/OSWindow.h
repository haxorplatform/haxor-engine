#ifndef INCLUDED_haxor_platform_OSWindow
#define INCLUDED_haxor_platform_OSWindow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,platform,OSWindow)
namespace haxor{
namespace platform{


class HXCPP_CLASS_ATTRIBUTES  OSWindow_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef OSWindow_obj OBJ_;
		OSWindow_obj();
		Void __construct(::String p_title,int p_x,int p_y,int p_width,int p_height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< OSWindow_obj > __new(::String p_title,int p_x,int p_y,int p_width,int p_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~OSWindow_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("OSWindow"); }

		virtual int get_x( );
		Dynamic get_x_dyn();

		virtual int set_x( int v);
		Dynamic set_x_dyn();

		int m_x;
		int m_fs_x;
		virtual int get_y( );
		Dynamic get_y_dyn();

		virtual int set_y( int v);
		Dynamic set_y_dyn();

		int m_y;
		int m_fs_y;
		virtual int get_width( );
		Dynamic get_width_dyn();

		virtual int set_width( int v);
		Dynamic set_width_dyn();

		int m_width;
		int m_fs_width;
		virtual int get_height( );
		Dynamic get_height_dyn();

		virtual int set_height( int v);
		Dynamic set_height_dyn();

		int m_height;
		int m_fs_height;
		virtual ::String get_title( );
		Dynamic get_title_dyn();

		virtual ::String set_title( ::String v);
		Dynamic set_title_dyn();

		::String m_title;
		bool focused;
		virtual bool get_focused( );
		Dynamic get_focused_dyn();

		bool m_focused;
		virtual bool get_fullscreen( );
		Dynamic get_fullscreen_dyn();

		virtual bool set_fullscreen( bool v);
		Dynamic set_fullscreen_dyn();

		bool m_fullscreen;
		int mouseX;
		virtual int get_mouseX( );
		Dynamic get_mouseX_dyn();

		int m_mouseX;
		int mouseY;
		virtual int get_mouseY( );
		Dynamic get_mouseY_dyn();

		int m_mouseY;
		bool m_cursor_lock;
		int m_cursor_flag;
		virtual Void Run( );
		Dynamic Run_dyn();

		virtual Void EnableCursor( );
		Dynamic EnableCursor_dyn();

		virtual Void DisableCursor( );
		Dynamic DisableCursor_dyn();

		virtual Void LockCursor( );
		Dynamic LockCursor_dyn();

		virtual Void UnlockCursor( );
		Dynamic UnlockCursor_dyn();

		virtual Void OnResize( );
		Dynamic OnResize_dyn();

		virtual Void OnFullscreen( );
		Dynamic OnFullscreen_dyn();

		virtual Void OnTitleChange( );
		Dynamic OnTitleChange_dyn();

};

} // end namespace haxor
} // end namespace platform

#endif /* INCLUDED_haxor_platform_OSWindow */ 
