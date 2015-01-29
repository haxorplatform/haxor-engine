#ifndef INCLUDED_haxor_core_ILateUpdateable
#define INCLUDED_haxor_core_ILateUpdateable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,ILateUpdateable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  ILateUpdateable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef ILateUpdateable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnLateUpdate( )=0;
		Dynamic OnLateUpdate_dyn();
};

#define DELEGATE_haxor_core_ILateUpdateable \
virtual Void OnLateUpdate( ) { return mDelegate->OnLateUpdate();}  \
virtual Dynamic OnLateUpdate_dyn() { return mDelegate->OnLateUpdate_dyn();}  \


template<typename IMPL>
class ILateUpdateable_delegate_ : public ILateUpdateable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		ILateUpdateable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_ILateUpdateable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_ILateUpdateable */ 
