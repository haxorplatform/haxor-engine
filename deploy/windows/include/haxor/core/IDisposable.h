#ifndef INCLUDED_haxor_core_IDisposable
#define INCLUDED_haxor_core_IDisposable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  IDisposable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IDisposable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnDestroy( )=0;
		Dynamic OnDestroy_dyn();
};

#define DELEGATE_haxor_core_IDisposable \
virtual Void OnDestroy( ) { return mDelegate->OnDestroy();}  \
virtual Dynamic OnDestroy_dyn() { return mDelegate->OnDestroy_dyn();}  \


template<typename IMPL>
class IDisposable_delegate_ : public IDisposable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IDisposable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_IDisposable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_IDisposable */ 
