#ifndef INCLUDED_haxor_core_IRenderable
#define INCLUDED_haxor_core_IRenderable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IRenderable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  IRenderable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IRenderable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnRender( )=0;
		Dynamic OnRender_dyn();
};

#define DELEGATE_haxor_core_IRenderable \
virtual Void OnRender( ) { return mDelegate->OnRender();}  \
virtual Dynamic OnRender_dyn() { return mDelegate->OnRender_dyn();}  \


template<typename IMPL>
class IRenderable_delegate_ : public IRenderable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IRenderable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_IRenderable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_IRenderable */ 
