#ifndef INCLUDED_haxor_ds_IUSetItem
#define INCLUDED_haxor_ds_IUSetItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,ds,IUSetItem)
namespace haxor{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  IUSetItem_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IUSetItem_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
};

#define DELEGATE_haxor_ds_IUSetItem \


template<typename IMPL>
class IUSetItem_delegate_ : public IUSetItem_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IUSetItem_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxor_ds_IUSetItem
};

} // end namespace haxor
} // end namespace ds

#endif /* INCLUDED_haxor_ds_IUSetItem */ 
