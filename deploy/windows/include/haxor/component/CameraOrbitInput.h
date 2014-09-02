#ifndef INCLUDED_haxor_component_CameraOrbitInput
#define INCLUDED_haxor_component_CameraOrbitInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
#include <haxor/core/IUpdateable.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,CameraOrbit)
HX_DECLARE_CLASS2(haxor,component,CameraOrbitInput)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  CameraOrbitInput_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef CameraOrbitInput_obj OBJ_;
		CameraOrbitInput_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CameraOrbitInput_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CameraOrbitInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::core::IUpdateable_obj *()
			{ return new ::haxor::core::IUpdateable_delegate_< CameraOrbitInput_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("CameraOrbitInput"); }

		bool rotate;
		bool zoom;
		Float zoomSpeed;
		Float rotateSpeed;
		::haxor::component::CameraOrbit m_orbit;
		virtual Void OnStart( );

		virtual Void OnUpdate( );
		Dynamic OnUpdate_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_CameraOrbitInput */ 
