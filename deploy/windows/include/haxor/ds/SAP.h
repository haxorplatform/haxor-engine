#ifndef INCLUDED_haxor_ds_SAP
#define INCLUDED_haxor_ds_SAP

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,ds,SAP)
HX_DECLARE_CLASS2(haxor,ds,SAPList)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  SAP_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SAP_obj OBJ_;
		SAP_obj();
		Void __construct(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SAP_obj > __new(hx::Null< Float >  __o_p_bias,hx::Null< bool >  __o_p_has_query);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SAP_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SAP"); }

		::haxor::ds::SAPList x;
		::haxor::ds::SAPList y;
		::haxor::ds::SAPList z;
		bool m_has_query;
		virtual Void Create( int p_id);
		Dynamic Create_dyn();

		virtual Void Update( int p_id,Dynamic p_data,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max);
		Dynamic Update_dyn();

		virtual Void Remove( int p_id);
		Dynamic Remove_dyn();

		virtual bool Overlap( int p_a,int p_b);
		Dynamic Overlap_dyn();

		virtual Void Query( int p_id,Dynamic p_on_fetch);
		Dynamic Query_dyn();

};

} // end namespace haxor
} // end namespace ds

#endif /* INCLUDED_haxor_ds_SAP */ 
