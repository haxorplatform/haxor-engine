#ifndef INCLUDED_haxe_remoting_Connection
#define INCLUDED_haxe_remoting_Connection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,remoting,Connection)
namespace haxe{
namespace remoting{


class HXCPP_CLASS_ATTRIBUTES  Connection_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Connection_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
};

#define DELEGATE_haxe_remoting_Connection \


template<typename IMPL>
class Connection_delegate_ : public Connection_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Connection_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_haxe_remoting_Connection
};

} // end namespace haxe
} // end namespace remoting

#endif /* INCLUDED_haxe_remoting_Connection */ 
