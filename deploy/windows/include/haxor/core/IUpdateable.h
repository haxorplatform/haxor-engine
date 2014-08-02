#ifndef INCLUDED_haxor_core_IUpdateable
#define INCLUDED_haxor_core_IUpdateable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IUpdateable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  IUpdateable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IUpdateable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnUpdate( )=0;
		Dynamic OnUpdate_dyn();
};

#define DELEGATE_haxor_core_IUpdateable \
virtual Void OnUpdate( ) { return mDelegate->OnUpdate();}  \
virtual Dynamic OnUpdate_dyn() { return mDelegate->OnUpdate_dyn();}  \


template<typename IMPL>
class IUpdateable_delegate_ : public IUpdateable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IUpdateable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_IUpdateable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_IUpdateable */ 
