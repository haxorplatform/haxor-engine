#ifndef INCLUDED_haxor_context_BaseProcess
#define INCLUDED_haxor_context_BaseProcess

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,BaseProcess)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  BaseProcess_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BaseProcess_obj OBJ_;
		BaseProcess_obj();
		Void __construct(::String p_name,hx::Null< bool >  __o_p_update_cid);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BaseProcess_obj > __new(::String p_name,hx::Null< bool >  __o_p_update_cid);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BaseProcess_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseProcess"); }

		int __cid;
		::String name;
		int length;
		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual Void Add( ::haxor::core::Resource p_item);
		Dynamic Add_dyn();

		virtual Void Remove( ::haxor::core::Resource p_item);
		Dynamic Remove_dyn();

		virtual Void Clear( );
		Dynamic Clear_dyn();

		static int m_cid;
};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_BaseProcess */ 
