#ifndef INCLUDED_haxor_ds_PairTable
#define INCLUDED_haxor_ds_PairTable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,ds,PairTable)
namespace haxor{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  PairTable_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PairTable_obj OBJ_;
		PairTable_obj();
		Void __construct(int p_count,Dynamic p_default,hx::Null< bool >  __o_p_mirror);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PairTable_obj > __new(int p_count,Dynamic p_default,hx::Null< bool >  __o_p_mirror);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PairTable_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PairTable"); }

		virtual bool get_mirror( );
		Dynamic get_mirror_dyn();

		bool m_mirror;
		virtual int get_rows( );
		Dynamic get_rows_dyn();

		virtual int get_cols( );
		Dynamic get_cols_dyn();

		Dynamic m_table;
		virtual Dynamic Get( int p_x,int p_y);
		Dynamic Get_dyn();

		virtual Void Set( int p_x,int p_y,Dynamic p_value);
		Dynamic Set_dyn();

		virtual Dynamic Line( int p_index);
		Dynamic Line_dyn();

		virtual Void Iterate( Dynamic p_callback);
		Dynamic Iterate_dyn();

};

} // end namespace haxor
} // end namespace ds

#endif /* INCLUDED_haxor_ds_PairTable */ 
