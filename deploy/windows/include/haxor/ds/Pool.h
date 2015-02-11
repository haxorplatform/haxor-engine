#ifndef INCLUDED_haxor_ds_Pool
#define INCLUDED_haxor_ds_Pool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,ds,Pool)
namespace haxor{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  Pool_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Pool_obj OBJ_;
		Pool_obj();
		Void __construct(::Class p_type,hx::Null< int >  __o_p_count);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Pool_obj > __new(::Class p_type,hx::Null< int >  __o_p_count);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Pool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Pool"); }

		Dynamic m_list;
		int m_top;
		::Class m_type;
		virtual Dynamic Get( );
		Dynamic Get_dyn();

		virtual Void Put( Dynamic v);
		Dynamic Put_dyn();

		virtual Void Generate( );
		Dynamic Generate_dyn();

};

} // end namespace haxor
} // end namespace ds

#endif /* INCLUDED_haxor_ds_Pool */ 
