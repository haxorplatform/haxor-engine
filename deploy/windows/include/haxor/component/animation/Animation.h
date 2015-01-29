#ifndef INCLUDED_haxor_component_animation_Animation
#define INCLUDED_haxor_component_animation_Animation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,animation,Animation)
HX_DECLARE_CLASS3(haxor,component,animation,AnimationClip)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace component{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  Animation_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef Animation_obj OBJ_;
		Animation_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Animation_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Animation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Animation"); }

		Array< ::Dynamic > clips;
		Float m_clock;
		virtual Float get_time( );
		Dynamic get_time_dyn();

		virtual Float set_time( Float v);
		Dynamic set_time_dyn();

		Float m_time;
		virtual bool get_playing( );
		Dynamic get_playing_dyn();

		bool reverse;
		Float m_fade_elapsed;
		Float m_fade_duration;
		::haxor::component::animation::AnimationClip m_fade_clip;
		virtual bool Contains( ::haxor::component::animation::AnimationClip p_clip);
		Dynamic Contains_dyn();

		virtual Void Add( ::haxor::component::animation::AnimationClip p_clip);
		Dynamic Add_dyn();

		virtual Void Remove( ::haxor::component::animation::AnimationClip p_clip);
		Dynamic Remove_dyn();

		virtual ::haxor::component::animation::AnimationClip Get( ::String p_clip_name);
		Dynamic Get_dyn();

		virtual Void Fade( ::haxor::component::animation::AnimationClip p_clip,hx::Null< Float >  p_time,hx::Null< Float >  p_fade);
		Dynamic Fade_dyn();

		virtual Void Play( ::haxor::component::animation::AnimationClip p_clip,hx::Null< Float >  p_time);
		Dynamic Play_dyn();

		virtual Void Stop( ::haxor::component::animation::AnimationClip p_clip);
		Dynamic Stop_dyn();

		virtual Void Animate( );
		Dynamic Animate_dyn();

		static Array< ::Dynamic > m_list;
		static int m_iterator;
		static Void Update( );
		static Dynamic Update_dyn();

		static Void Initialize( );
		static Dynamic Initialize_dyn();

};

} // end namespace haxor
} // end namespace component
} // end namespace animation

#endif /* INCLUDED_haxor_component_animation_Animation */ 
