#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_core_ClearFlag
#include <haxor/core/ClearFlag.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
namespace haxor{
namespace graphics{

Void Graphics_obj::__construct()
{
	return null();
}

//Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new()
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct();
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct();
	return result;}

::haxor::math::AABB2 Graphics_obj::m_last_viewport;

Void Graphics_obj::Viewport( ::haxor::math::AABB2 p_viewport){
{
		HX_STACK_FRAME("haxor.graphics.Graphics","Viewport",0x9c269ab2,"haxor.graphics.Graphics.Viewport","haxor/graphics/Graphics.hx",31,0x1a55985c)
		HX_STACK_ARG(p_viewport,"p_viewport")
		HX_STACK_LINE(32)
		::haxor::math::AABB2 vp = p_viewport;		HX_STACK_VAR(vp,"vp");
		HX_STACK_LINE(33)
		bool dirty = false;		HX_STACK_VAR(dirty,"dirty");
		HX_STACK_LINE(34)
		Float _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(34)
		{
			HX_STACK_LINE(34)
			Float _g = vp->get_xMin();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(34)
			Float _g1 = ::haxor::graphics::Graphics_obj::m_last_viewport->get_xMin();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(34)
			Float p_a = (_g - _g1);		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(34)
			if (((p_a < (int)0))){
				HX_STACK_LINE(34)
				_g2 = -(p_a);
			}
			else{
				HX_STACK_LINE(34)
				_g2 = p_a;
			}
		}
		HX_STACK_LINE(34)
		if (((_g2 > 0.0))){
			HX_STACK_LINE(34)
			dirty = true;
		}
		else{
			HX_STACK_LINE(35)
			Float _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(35)
			{
				HX_STACK_LINE(35)
				Float _g3 = vp->get_yMin();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(35)
				Float _g4 = ::haxor::graphics::Graphics_obj::m_last_viewport->get_yMin();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(35)
				Float p_a = (_g3 - _g4);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(35)
				if (((p_a < (int)0))){
					HX_STACK_LINE(35)
					_g5 = -(p_a);
				}
				else{
					HX_STACK_LINE(35)
					_g5 = p_a;
				}
			}
			HX_STACK_LINE(35)
			if (((_g5 > 0.0))){
				HX_STACK_LINE(35)
				dirty = true;
			}
			else{
				HX_STACK_LINE(36)
				Float _g12;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(36)
				{
					HX_STACK_LINE(36)
					Float _g8;		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(36)
					{
						HX_STACK_LINE(36)
						Float _g6 = vp->get_xMax();		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(36)
						Float _g7 = vp->get_xMin();		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(36)
						Float p_a = (_g6 - _g7);		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(36)
						if (((p_a < (int)0))){
							HX_STACK_LINE(36)
							_g8 = -(p_a);
						}
						else{
							HX_STACK_LINE(36)
							_g8 = p_a;
						}
					}
					HX_STACK_LINE(36)
					Float _g11;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(36)
					{
						HX_STACK_LINE(36)
						::haxor::math::AABB2 _this = ::haxor::graphics::Graphics_obj::m_last_viewport;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(36)
						{
							HX_STACK_LINE(36)
							Float _g9 = _this->get_xMax();		HX_STACK_VAR(_g9,"_g9");
							HX_STACK_LINE(36)
							Float _g10 = _this->get_xMin();		HX_STACK_VAR(_g10,"_g10");
							HX_STACK_LINE(36)
							Float p_a = (_g9 - _g10);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(36)
							if (((p_a < (int)0))){
								HX_STACK_LINE(36)
								_g11 = -(p_a);
							}
							else{
								HX_STACK_LINE(36)
								_g11 = p_a;
							}
						}
					}
					HX_STACK_LINE(36)
					Float p_a = (_g8 - _g11);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(36)
					if (((p_a < (int)0))){
						HX_STACK_LINE(36)
						_g12 = -(p_a);
					}
					else{
						HX_STACK_LINE(36)
						_g12 = p_a;
					}
				}
				HX_STACK_LINE(36)
				if (((_g12 > 0.0))){
					HX_STACK_LINE(36)
					dirty = true;
				}
				else{
					HX_STACK_LINE(37)
					Float _g19;		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(37)
					{
						HX_STACK_LINE(37)
						Float _g15;		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(37)
						{
							HX_STACK_LINE(37)
							Float _g13 = vp->get_yMax();		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(37)
							Float _g14 = vp->get_yMin();		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(37)
							Float p_a = (_g13 - _g14);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(37)
							if (((p_a < (int)0))){
								HX_STACK_LINE(37)
								_g15 = -(p_a);
							}
							else{
								HX_STACK_LINE(37)
								_g15 = p_a;
							}
						}
						HX_STACK_LINE(37)
						Float _g18;		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(37)
						{
							HX_STACK_LINE(37)
							::haxor::math::AABB2 _this = ::haxor::graphics::Graphics_obj::m_last_viewport;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(37)
							{
								HX_STACK_LINE(37)
								Float _g16 = _this->get_yMax();		HX_STACK_VAR(_g16,"_g16");
								HX_STACK_LINE(37)
								Float _g17 = _this->get_yMin();		HX_STACK_VAR(_g17,"_g17");
								HX_STACK_LINE(37)
								Float p_a = (_g16 - _g17);		HX_STACK_VAR(p_a,"p_a");
								HX_STACK_LINE(37)
								if (((p_a < (int)0))){
									HX_STACK_LINE(37)
									_g18 = -(p_a);
								}
								else{
									HX_STACK_LINE(37)
									_g18 = p_a;
								}
							}
						}
						HX_STACK_LINE(37)
						Float p_a = (_g15 - _g18);		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(37)
						if (((p_a < (int)0))){
							HX_STACK_LINE(37)
							_g19 = -(p_a);
						}
						else{
							HX_STACK_LINE(37)
							_g19 = p_a;
						}
					}
					HX_STACK_LINE(37)
					if (((_g19 > 0.0))){
						HX_STACK_LINE(37)
						dirty = true;
					}
				}
			}
		}
		HX_STACK_LINE(39)
		if ((dirty)){
			HX_STACK_LINE(41)
			::haxor::graphics::Graphics_obj::m_last_viewport->SetAABB2(vp);
			HX_STACK_LINE(42)
			{
				HX_STACK_LINE(42)
				int p_x = vp->get_xMin();		HX_STACK_VAR(p_x,"p_x");
				HX_STACK_LINE(42)
				int p_y = vp->get_yMin();		HX_STACK_VAR(p_y,"p_y");
				HX_STACK_LINE(42)
				int p_width;		HX_STACK_VAR(p_width,"p_width");
				struct _Function_3_1{
					inline static Float Block( ::haxor::math::AABB2 &vp){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/Graphics.hx",42,0x1a55985c)
						{
							HX_STACK_LINE(42)
							Float _g20 = vp->get_xMax();		HX_STACK_VAR(_g20,"_g20");
							HX_STACK_LINE(42)
							Float _g21 = vp->get_xMin();		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(42)
							Float p_a = (_g20 - _g21);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(42)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(42)
				p_width = _Function_3_1::Block(vp);
				HX_STACK_LINE(42)
				int p_height;		HX_STACK_VAR(p_height,"p_height");
				struct _Function_3_2{
					inline static Float Block( ::haxor::math::AABB2 &vp){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/Graphics.hx",42,0x1a55985c)
						{
							HX_STACK_LINE(42)
							Float _g22 = vp->get_yMax();		HX_STACK_VAR(_g22,"_g22");
							HX_STACK_LINE(42)
							Float _g23 = vp->get_yMin();		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(42)
							Float p_a = (_g22 - _g23);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(42)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(42)
				p_height = _Function_3_2::Block(vp);
				HX_STACK_LINE(42)
				::haxor::graphics::GL_obj::m_gl->Viewport(p_x,p_y,p_width,p_height);
			}
			HX_STACK_LINE(43)
			{
				HX_STACK_LINE(43)
				int p_x = vp->get_xMin();		HX_STACK_VAR(p_x,"p_x");
				HX_STACK_LINE(43)
				int p_y = vp->get_yMin();		HX_STACK_VAR(p_y,"p_y");
				HX_STACK_LINE(43)
				int p_width;		HX_STACK_VAR(p_width,"p_width");
				struct _Function_3_1{
					inline static Float Block( ::haxor::math::AABB2 &vp){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/Graphics.hx",43,0x1a55985c)
						{
							HX_STACK_LINE(43)
							Float _g24 = vp->get_xMax();		HX_STACK_VAR(_g24,"_g24");
							HX_STACK_LINE(43)
							Float _g25 = vp->get_xMin();		HX_STACK_VAR(_g25,"_g25");
							HX_STACK_LINE(43)
							Float p_a = (_g24 - _g25);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(43)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(43)
				p_width = _Function_3_1::Block(vp);
				HX_STACK_LINE(43)
				int p_height;		HX_STACK_VAR(p_height,"p_height");
				struct _Function_3_2{
					inline static Float Block( ::haxor::math::AABB2 &vp){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/Graphics.hx",43,0x1a55985c)
						{
							HX_STACK_LINE(43)
							Float _g26 = vp->get_yMax();		HX_STACK_VAR(_g26,"_g26");
							HX_STACK_LINE(43)
							Float _g27 = vp->get_yMin();		HX_STACK_VAR(_g27,"_g27");
							HX_STACK_LINE(43)
							Float p_a = (_g26 - _g27);		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(43)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(43)
				p_height = _Function_3_2::Block(vp);
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->Scissor(p_x,p_y,p_width,p_height);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,Viewport,(void))

Void Graphics_obj::Clear( ::haxor::component::Camera p_camera){
{
		HX_STACK_FRAME("haxor.graphics.Graphics","Clear",0x675b7bc1,"haxor.graphics.Graphics.Clear","haxor/graphics/Graphics.hx",52,0x1a55985c)
		HX_STACK_ARG(p_camera,"p_camera")
		HX_STACK_LINE(53)
		::haxor::component::Camera c = p_camera;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(54)
		::haxor::graphics::Graphics_obj::Viewport(p_camera->m_pixelViewport);
		HX_STACK_LINE(55)
		if (((c->clear != ::haxor::core::ClearFlag_obj::None))){
			HX_STACK_LINE(57)
			int flag = (int)0;		HX_STACK_VAR(flag,"flag");
			HX_STACK_LINE(58)
			if (((((int(c->clear) & int(::haxor::core::ClearFlag_obj::Color))) != (int)0))){
				HX_STACK_LINE(58)
				hx::OrEq(flag,(int)16384);
			}
			HX_STACK_LINE(59)
			if (((((int(c->clear) & int(::haxor::core::ClearFlag_obj::Skybox))) != (int)0))){
				HX_STACK_LINE(59)
				hx::OrEq(flag,(int)16384);
			}
			HX_STACK_LINE(60)
			if (((((int(c->clear) & int(::haxor::core::ClearFlag_obj::Depth))) != (int)0))){
				HX_STACK_LINE(60)
				hx::OrEq(flag,(int)256);
			}
			HX_STACK_LINE(61)
			::haxor::graphics::GL_obj::m_gl->ClearColor(c->background->r,c->background->g,c->background->b,c->background->a);
			HX_STACK_LINE(62)
			::haxor::graphics::GL_obj::m_gl->ClearDepth(1.0);
			HX_STACK_LINE(63)
			::haxor::graphics::GL_obj::m_gl->Clear(flag);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,Clear,(void))

Void Graphics_obj::Render( ::haxor::graphics::mesh::Mesh p_mesh,::haxor::graphics::material::Material p_material,::haxor::component::Transform p_transform,::haxor::component::Camera p_camera){
{
		HX_STACK_FRAME("haxor.graphics.Graphics","Render",0x06324ea2,"haxor.graphics.Graphics.Render","haxor/graphics/Graphics.hx",84,0x1a55985c)
		HX_STACK_ARG(p_mesh,"p_mesh")
		HX_STACK_ARG(p_material,"p_material")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_ARG(p_camera,"p_camera")
		HX_STACK_LINE(85)
		::haxor::context::EngineContext_obj::material->Bind(p_material,p_transform,p_camera,p_mesh);
		HX_STACK_LINE(86)
		::haxor::context::EngineContext_obj::mesh->Bind(p_mesh);
		HX_STACK_LINE(87)
		::haxor::context::EngineContext_obj::mesh->Draw(p_mesh);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,Render,(void))

Void Graphics_obj::DrawTexture( ::haxor::graphics::texture::Texture p_texture,hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,::haxor::math::Color p_color){
Float p_x = __o_p_x.Default(0.0);
Float p_y = __o_p_y.Default(0.0);
Float p_width = __o_p_width.Default(256);
Float p_height = __o_p_height.Default(256);
	HX_STACK_FRAME("haxor.graphics.Graphics","DrawTexture",0x9028b66b,"haxor.graphics.Graphics.DrawTexture","haxor/graphics/Graphics.hx",100,0x1a55985c)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
	HX_STACK_ARG(p_color,"p_color")
{
		HX_STACK_LINE(101)
		if (((p_texture == null()))){
			HX_STACK_LINE(101)
			return null();
		}
		HX_STACK_LINE(102)
		::haxor::graphics::material::Material mat = ::haxor::context::EngineContext_obj::gizmo->texture_material;		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(103)
		mat->SetFloat2(HX_CSTRING("Screen"),::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(104)
		mat->SetFloat4(HX_CSTRING("Rect"),p_x,p_y,p_width,p_height);
		HX_STACK_LINE(105)
		mat->SetTexture(HX_CSTRING("Texture"),p_texture);
		HX_STACK_LINE(106)
		::haxor::math::Color c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(106)
		if (((p_color == null()))){
			struct _Function_2_1{
				inline static ::haxor::math::Color Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/graphics/Graphics.hx",106,0x1a55985c)
					{
						HX_STACK_LINE(106)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(106)
						int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(106)
						return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
					}
					return null();
				}
			};
			HX_STACK_LINE(106)
			c = (_Function_2_1::Block())->Set((int)1,(int)1,(int)1,(int)1);
		}
		else{
			HX_STACK_LINE(106)
			c = p_color;
		}
		HX_STACK_LINE(107)
		mat->SetFloat4(HX_CSTRING("Tint"),c->r,c->g,c->b,c->a);
		HX_STACK_LINE(108)
		::haxor::graphics::Graphics_obj::Render(::haxor::context::EngineContext_obj::gizmo->texture,mat,null(),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,DrawTexture,(void))

Void Graphics_obj::ReadPixels( int p_x,int p_y,int p_width,int p_height,::haxor::io::Buffer p_buffer){
{
		HX_STACK_FRAME("haxor.graphics.Graphics","ReadPixels",0x63504c6f,"haxor.graphics.Graphics.ReadPixels","haxor/graphics/Graphics.hx",121,0x1a55985c)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_buffer,"p_buffer")
		HX_STACK_LINE(121)
		::haxor::graphics::GL_obj::m_gl->ReadPixels(p_x,p_y,p_width,p_height,(int)6408,(int)5121,p_buffer);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Graphics_obj,ReadPixels,(void))


Graphics_obj::Graphics_obj()
{
}

Dynamic Graphics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Viewport") ) { return Viewport_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ReadPixels") ) { return ReadPixels_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"DrawTexture") ) { return DrawTexture_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_last_viewport") ) { return m_last_viewport; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"m_last_viewport") ) { m_last_viewport=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_last_viewport"),
	HX_CSTRING("Viewport"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Render"),
	HX_CSTRING("DrawTexture"),
	HX_CSTRING("ReadPixels"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Graphics_obj::m_last_viewport,"m_last_viewport");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Graphics_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Graphics_obj::m_last_viewport,"m_last_viewport");
};

#endif

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Graphics_obj::__boot()
{
	m_last_viewport= ::haxor::math::AABB2_obj::get_empty();
}

} // end namespace haxor
} // end namespace graphics
