#ifndef INCLUDED_haxor_core_Resource
#define INCLUDED_haxor_core_Resource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/IDisposable.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Application)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,WinApplication)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Resource_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Resource_obj OBJ_;
		Resource_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Resource_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Resource_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::core::IDisposable_obj *()
			{ return new ::haxor::core::IDisposable_delegate_< Resource_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Resource"); }

		::haxor::core::Application application;
		virtual ::haxor::core::Application get_application( );
		Dynamic get_application_dyn();

		int uid;
		virtual int get_uid( );
		Dynamic get_uid_dyn();

		int m_uid;
		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual ::String set_name( ::String v);
		Dynamic set_name_dyn();

		::String m_name;
		bool destroyed;
		virtual bool get_destroyed( );
		Dynamic get_destroyed_dyn();

		bool m_destroyed;
		int __cid;
		Array< int > m_pid;
		::String m_type_name;
		::String m_type_full_name;
		::Class m_type_class;
		bool m_is_behaviour;
		virtual ::Class GetType( );
		Dynamic GetType_dyn();

		virtual ::String GetTypeName( );
		Dynamic GetTypeName_dyn();

		virtual ::String GetTypeFullName( );
		Dynamic GetTypeFullName_dyn();

		virtual Void OnDestroy( );
		Dynamic OnDestroy_dyn();

		static Void Destroy( ::haxor::core::Resource p_target);
		static Dynamic Destroy_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Resource */ 
