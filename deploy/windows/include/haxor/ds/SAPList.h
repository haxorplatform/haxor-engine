#ifndef INCLUDED_haxor_ds_SAPList
#define INCLUDED_haxor_ds_SAPList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,ds,SAPInterval)
HX_DECLARE_CLASS2(haxor,ds,SAPList)
namespace haxor{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  SAPList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SAPList_obj OBJ_;
		SAPList_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SAPList_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SAPList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SAPList"); }

		::haxor::ds::SAPInterval start;
		Array< ::Dynamic > list;
		virtual Void Create( int p_id);
		Dynamic Create_dyn();

		virtual Void Update( int p_id,Dynamic p_data,Float p_min,Float p_max);
		Dynamic Update_dyn();

		virtual Void Add( ::haxor::ds::SAPInterval p_item);
		Dynamic Add_dyn();

		virtual Void Insert( ::haxor::ds::SAPInterval p_item,::haxor::ds::SAPInterval p_at);
		Dynamic Insert_dyn();

		virtual Void Relocate( ::haxor::ds::SAPInterval p_item);
		Dynamic Relocate_dyn();

		virtual Void RemoveById( int p_id);
		Dynamic RemoveById_dyn();

		virtual Void Remove( ::haxor::ds::SAPInterval p_item);
		Dynamic Remove_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

};

} // end namespace haxor
} // end namespace ds

#endif /* INCLUDED_haxor_ds_SAPList */ 