#ifndef INCLUDED_haxor_core_ColliderType
#define INCLUDED_haxor_core_ColliderType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,ColliderType)
namespace haxor{
namespace core{


class ColliderType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ColliderType_obj OBJ_;

	public:
		ColliderType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.ColliderType"); }
		::String __ToString() const { return HX_CSTRING("ColliderType.") + tag; }

		static ::haxor::core::ColliderType Box;
		static inline ::haxor::core::ColliderType Box_dyn() { return Box; }
		static ::haxor::core::ColliderType Capsule;
		static inline ::haxor::core::ColliderType Capsule_dyn() { return Capsule; }
		static ::haxor::core::ColliderType Mesh;
		static inline ::haxor::core::ColliderType Mesh_dyn() { return Mesh; }
		static ::haxor::core::ColliderType Plane;
		static inline ::haxor::core::ColliderType Plane_dyn() { return Plane; }
		static ::haxor::core::ColliderType Point;
		static inline ::haxor::core::ColliderType Point_dyn() { return Point; }
		static ::haxor::core::ColliderType Sphere;
		static inline ::haxor::core::ColliderType Sphere_dyn() { return Sphere; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_ColliderType */ 
