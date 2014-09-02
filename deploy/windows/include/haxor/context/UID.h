#ifndef INCLUDED_haxor_context_UID
#define INCLUDED_haxor_context_UID

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,UID)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  UID_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef UID_obj OBJ_;
		UID_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UID_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UID_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UID"); }

		virtual int get_id( );
		Dynamic get_id_dyn();

		virtual int set_id( int v);
		Dynamic set_id_dyn();

		int m_id;
		Array< int > m_cache;
		virtual int get_next( );
		Dynamic get_next_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_UID */ 
