#include <hxcpp.h>

#include <haxor/platform/windows/Window.h>
#include <haxor/platform/windows/Entry.h>
#include <haxor/platform/graphics/OpenGL.h>
#include <haxor/platform/graphics/WinGL.h>
#include <haxor/platform/graphics/GraphicContext.h>
#include <haxor/platform/graphics/GraphicAPI.h>
#include <haxor/platform/graphics/GL.h>
#include <haxor/platform/OSWindow.h>
#include <haxor/io/UInt16Array.h>
#include <haxor/io/FloatArray.h>
#include <haxor/io/Buffer.h>
#include <haxor/graphics/mesh/MeshAttrib.h>
#include <haxor/graphics/mesh/Mesh.h>
#include <haxor/graphics/material/UberShader.h>
#include <haxor/graphics/material/Shader.h>
#include <haxor/graphics/material/Material.h>
#include <haxor/graphics/CursorMode.h>
#include <haxor/graphics/Screen.h>
#include <haxor/graphics/Graphics.h>
#include <haxor/graphics/BufferPrimitive.h>
#include <haxor/graphics/DepthTest.h>
#include <haxor/graphics/CullMode.h>
#include <haxor/graphics/MeshPrimitive.h>
#include <haxor/graphics/MeshMode.h>
#include <haxor/graphics/BlendMode.h>
#include <haxor/graphics/RenderQueue.h>
#include <haxor/core/Time.h>
#include <haxor/core/Scene.h>
#include <haxor/core/IResizeable.h>
#include <haxor/core/Entity.h>
#include <haxor/core/Engine.h>
#include <haxor/core/EngineState.h>
#include <haxor/core/Console.h>
#include <haxor/core/ApplicationProtocol.h>
#include <haxor/core/Platform.h>
#include <haxor/context/Process.h>
#include <haxor/context/MeshContext.h>
#include <haxor/context/MaterialContext.h>
#include <haxor/context/EngineContext.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Bytes.h>
#include <haxe/ds/StringMap.h>
#include <haxe/Timer.h>
#include <Xml.h>
#include <XmlType.h>
#include <Type.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <StringTools.h>
#include <Std.h>
#include <Reflect.h>
#include <IMap.h>
#include <Main.h>
#include <haxor/core/IUpdateable.h>
#include <haxor/core/IRenderable.h>
#include <haxor/core/Application.h>
#include <haxor/platform/windows/WinApplication.h>
#include <haxor/core/BaseApplication.h>
#include <haxor/component/Behaviour.h>
#include <haxor/component/Component.h>
#include <haxor/core/Resource.h>
#include <haxor/core/IDisposable.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxor::platform::windows::Window_obj::__register();
::haxor::platform::windows::Entry_obj::__register();
::haxor::platform::graphics::OpenGL_obj::__register();
::haxor::platform::graphics::WinGL_obj::__register();
::haxor::platform::graphics::GraphicContext_obj::__register();
::haxor::platform::graphics::GraphicAPI_obj::__register();
::haxor::platform::graphics::GL_obj::__register();
::haxor::platform::OSWindow_obj::__register();
::haxor::io::UInt16Array_obj::__register();
::haxor::io::FloatArray_obj::__register();
::haxor::io::Buffer_obj::__register();
::haxor::graphics::mesh::MeshAttrib_obj::__register();
::haxor::graphics::mesh::Mesh_obj::__register();
::haxor::graphics::material::UberShader_obj::__register();
::haxor::graphics::material::Shader_obj::__register();
::haxor::graphics::material::Material_obj::__register();
::haxor::graphics::CursorMode_obj::__register();
::haxor::graphics::Screen_obj::__register();
::haxor::graphics::Graphics_obj::__register();
::haxor::graphics::BufferPrimitive_obj::__register();
::haxor::graphics::DepthTest_obj::__register();
::haxor::graphics::CullMode_obj::__register();
::haxor::graphics::MeshPrimitive_obj::__register();
::haxor::graphics::MeshMode_obj::__register();
::haxor::graphics::BlendMode_obj::__register();
::haxor::graphics::RenderQueue_obj::__register();
::haxor::core::Time_obj::__register();
::haxor::core::Scene_obj::__register();
::haxor::core::IResizeable_obj::__register();
::haxor::core::Entity_obj::__register();
::haxor::core::Engine_obj::__register();
::haxor::core::EngineState_obj::__register();
::haxor::core::Console_obj::__register();
::haxor::core::ApplicationProtocol_obj::__register();
::haxor::core::Platform_obj::__register();
::haxor::context::Process_obj::__register();
::haxor::context::MeshContext_obj::__register();
::haxor::context::MaterialContext_obj::__register();
::haxor::context::EngineContext_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::Timer_obj::__register();
::Xml_obj::__register();
::XmlType_obj::__register();
::Type_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::StringTools_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::IMap_obj::__register();
::Main_obj::__register();
::haxor::core::IUpdateable_obj::__register();
::haxor::core::IRenderable_obj::__register();
::haxor::core::Application_obj::__register();
::haxor::platform::windows::WinApplication_obj::__register();
::haxor::core::BaseApplication_obj::__register();
::haxor::component::Behaviour_obj::__register();
::haxor::component::Component_obj::__register();
::haxor::core::Resource_obj::__register();
::haxor::core::IDisposable_obj::__register();
::Xml_obj::__init__();
::cpp::Lib_obj::__boot();
::Xml_obj::__boot();
::haxor::core::IDisposable_obj::__boot();
::haxor::core::Resource_obj::__boot();
::haxor::component::Component_obj::__boot();
::haxor::component::Behaviour_obj::__boot();
::haxor::core::BaseApplication_obj::__boot();
::haxor::platform::windows::WinApplication_obj::__boot();
::haxor::core::Application_obj::__boot();
::haxor::core::IRenderable_obj::__boot();
::haxor::core::IUpdateable_obj::__boot();
::Main_obj::__boot();
::IMap_obj::__boot();
::Reflect_obj::__boot();
::Std_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::Type_obj::__boot();
::XmlType_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxor::context::EngineContext_obj::__boot();
::haxor::context::MaterialContext_obj::__boot();
::haxor::context::MeshContext_obj::__boot();
::haxor::context::Process_obj::__boot();
::haxor::core::Platform_obj::__boot();
::haxor::core::ApplicationProtocol_obj::__boot();
::haxor::core::Console_obj::__boot();
::haxor::core::EngineState_obj::__boot();
::haxor::core::Engine_obj::__boot();
::haxor::core::Entity_obj::__boot();
::haxor::core::IResizeable_obj::__boot();
::haxor::core::Scene_obj::__boot();
::haxor::core::Time_obj::__boot();
::haxor::graphics::RenderQueue_obj::__boot();
::haxor::graphics::BlendMode_obj::__boot();
::haxor::graphics::MeshMode_obj::__boot();
::haxor::graphics::MeshPrimitive_obj::__boot();
::haxor::graphics::CullMode_obj::__boot();
::haxor::graphics::DepthTest_obj::__boot();
::haxor::graphics::BufferPrimitive_obj::__boot();
::haxor::graphics::Graphics_obj::__boot();
::haxor::graphics::Screen_obj::__boot();
::haxor::graphics::CursorMode_obj::__boot();
::haxor::graphics::material::Material_obj::__boot();
::haxor::graphics::material::Shader_obj::__boot();
::haxor::graphics::material::UberShader_obj::__boot();
::haxor::graphics::mesh::Mesh_obj::__boot();
::haxor::graphics::mesh::MeshAttrib_obj::__boot();
::haxor::io::Buffer_obj::__boot();
::haxor::io::FloatArray_obj::__boot();
::haxor::io::UInt16Array_obj::__boot();
::haxor::platform::OSWindow_obj::__boot();
::haxor::platform::graphics::GL_obj::__boot();
::haxor::platform::graphics::GraphicAPI_obj::__boot();
::haxor::platform::graphics::GraphicContext_obj::__boot();
::haxor::platform::graphics::WinGL_obj::__boot();
::haxor::platform::graphics::OpenGL_obj::__boot();
::haxor::platform::windows::Entry_obj::__boot();
::haxor::platform::windows::Window_obj::__boot();
}

