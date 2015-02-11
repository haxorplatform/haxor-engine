#ifndef INCLUDED_haxor_core_IFixedUpdateable
#define INCLUDED_haxor_core_IFixedUpdateable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IFixedUpdateable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  IFixedUpdateable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IFixedUpdateable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnFixedUpdate( )=0;
		Dynamic OnFixedUpdate_dyn();
};

#define DELEGATE_haxor_core_IFixedUpdateable \
virtual Void OnFixedUpdate( ) { return mDelegate->OnFixedUpdate();}  \
virtual Dynamic OnFixedUpdate_dyn() { return mDelegate->OnFixedUpdate_dyn();}  \


template<typename IMPL>
class IFixedUpdateable_delegate_ : public IFixedUpdateable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IFixedUpdateable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_IFixedUpdateable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_IFixedUpdateable */ 
