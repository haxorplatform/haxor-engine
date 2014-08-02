#ifndef INCLUDED_haxor_context_Process
#define INCLUDED_haxor_context_Process

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,Process)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  Process_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Process_obj OBJ_;
		Process_obj();
		Void __construct(::String p_name,int p_size);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Process_obj > __new(::String p_name,int p_size);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Process_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Process"); }

		::String name;
		Dynamic list;
		int length;
		virtual int get_length( );
		Dynamic get_length_dyn();

		int m_length;
		int _cid_;
		Dynamic m_remove_queue;
		virtual Void Add( ::haxor::core::Resource p_item);
		Dynamic Add_dyn();

		virtual ::haxor::core::Resource Remove( ::haxor::core::Resource p_item);
		Dynamic Remove_dyn();

		virtual Void Clear( );
		Dynamic Clear_dyn();

		static int m_cid;
};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_Process */ 
