#ifndef INCLUDED_haxor_core_IResizeable
#define INCLUDED_haxor_core_IResizeable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IResizeable)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  IResizeable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IResizeable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void OnResize( Float p_width,Float p_height)=0;
		Dynamic OnResize_dyn();
};

#define DELEGATE_haxor_core_IResizeable \
virtual Void OnResize( Float p_width,Float p_height) { return mDelegate->OnResize(p_width,p_height);}  \
virtual Dynamic OnResize_dyn() { return mDelegate->OnResize_dyn();}  \


template<typename IMPL>
class IResizeable_delegate_ : public IResizeable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IResizeable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_core_IResizeable
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_IResizeable */ 
