#include <hxcpp.h>

#include <sys/net/Socket.h>
#include <sys/net/_Socket/SocketOutput.h>
#include <sys/net/_Socket/SocketInput.h>
#include <sys/net/Host.h>
#include <haxor/platform/windows/input/WinInputHandler.h>
#include <haxor/platform/windows/Window.h>
#include <haxor/platform/windows/Entry.h>
#include <haxor/platform/graphics/OpenGL.h>
#include <haxor/platform/windows/graphics/WinGL.h>
#include <haxor/platform/OSWindow.h>
#include <haxor/net/Web.h>
#include <haxor/net/Texture2DLoader.h>
#include <haxor/platform/windows/net/BitmapLoader.h>
#include <haxor/platform/windows/net/HTTPLoader.h>
#include <haxor/platform/windows/net/HTTPRequest.h>
#include <haxor/net/HTTPRequestTask.h>
#include <haxor/thread/Task.h>
#include <haxor/thread/Activity.h>
#include <haxor/math/Vector4.h>
#include <haxor/math/Vector2.h>
#include <haxor/math/Random.h>
#include <haxor/math/Mathf.h>
#include <haxor/math/AABB3.h>
#include <haxor/io/file/MaterialFileUniform.h>
#include <haxor/io/file/MaterialFile.h>
#include <haxor/io/file/ColladaLight.h>
#include <haxor/io/file/ColladaAnimationKeyFrame.h>
#include <haxor/io/file/ColladaAnimationChannel.h>
#include <haxor/io/file/ColladaAnimation.h>
#include <haxor/io/file/ColladaMaterial.h>
#include <haxor/io/file/ColladaInstance.h>
#include <haxor/io/file/ColladaNode.h>
#include <haxor/io/file/ColladaVisualScene.h>
#include <haxor/io/file/ColladaController.h>
#include <haxor/io/file/ColladaImage.h>
#include <haxor/io/file/ColladaInput.h>
#include <haxor/io/file/ColladaPrimitive.h>
#include <haxor/io/file/ColladaMesh.h>
#include <haxor/io/file/ColladaGeometry.h>
#include <haxor/io/file/ColladaAssetData.h>
#include <haxor/io/file/ColladaFile.h>
#include <haxor/io/file/AssetXML.h>
#include <haxor/io/file/AssetFile.h>
#include <haxor/io/file/Asset.h>
#include <haxor/io/UInt16Array.h>
#include <haxor/io/Int32Array.h>
#include <haxor/io/FloatArray.h>
#include <haxor/io/Buffer.h>
#include <haxor/input/Touch.h>
#include <haxor/input/KeyCode.h>
#include <haxor/input/Joystick.h>
#include <haxor/input/InputHandler.h>
#include <haxor/input/Input.h>
#include <haxor/graphics/texture/TextureCube.h>
#include <haxor/graphics/texture/RenderTexture.h>
#include <haxor/graphics/texture/ComputeTexture.h>
#include <haxor/graphics/texture/Texture2D.h>
#include <haxor/graphics/texture/Texture.h>
#include <haxor/graphics/texture/Bitmap.h>
#include <haxor/graphics/mesh/Model.h>
#include <haxor/graphics/mesh/Mesh4.h>
#include <haxor/graphics/mesh/Mesh2.h>
#include <haxor/graphics/mesh/Mesh23.h>
#include <haxor/graphics/mesh/Mesh2D.h>
#include <haxor/graphics/mesh/SkinnedMesh3.h>
#include <haxor/graphics/mesh/Mesh3.h>
#include <haxor/graphics/mesh/MeshLayout.h>
#include <haxor/graphics/mesh/MeshAttrib.h>
#include <haxor/graphics/mesh/Mesh.h>
#include <haxor/graphics/material/UberShader.h>
#include <haxor/graphics/material/Shader.h>
#include <haxor/graphics/material/MaterialUniform.h>
#include <haxor/graphics/material/Material.h>
#include <haxor/graphics/CursorMode.h>
#include <haxor/graphics/Screen.h>
#include <haxor/graphics/Graphics.h>
#include <haxor/math/AABB2.h>
#include <haxor/graphics/GraphicContext.h>
#include <haxor/graphics/GraphicAPI.h>
#include <haxor/graphics/Gizmo.h>
#include <haxor/graphics/GL.h>
#include <haxor/ds/SAPInterval.h>
#include <haxor/ds/SAPList.h>
#include <haxor/ds/SAP.h>
#include <haxor/core/Time.h>
#include <haxor/core/Scene.h>
#include <haxor/core/RenderStats.h>
#include <haxor/core/RenderEngine.h>
#include <haxor/core/IResizeable.h>
#include <haxor/core/ILateUpdateable.h>
#include <haxor/core/AnimationWrap.h>
#include <haxor/core/InputState.h>
#include <haxor/core/ClearFlag.h>
#include <haxor/core/TextureType.h>
#include <haxor/core/TextureWrap.h>
#include <haxor/core/TextureFilter.h>
#include <haxor/core/PixelFormat.h>
#include <haxor/core/DepthTest.h>
#include <haxor/core/CullMode.h>
#include <haxor/core/MeshPrimitive.h>
#include <haxor/core/MeshMode.h>
#include <haxor/core/BlendMode.h>
#include <haxor/core/RenderQueue.h>
#include <haxor/core/Entity.h>
#include <haxor/core/Engine.h>
#include <haxor/core/EngineState.h>
#include <haxor/core/Console.h>
#include <haxor/core/ApplicationProtocol.h>
#include <haxor/core/Platform.h>
#include <haxor/context/UID.h>
#include <haxor/context/TransformContext.h>
#include <haxor/context/TextureContext.h>
#include <haxor/context/ShaderContext.h>
#include <haxor/context/RendererContext.h>
#include <haxor/context/Process.h>
#include <haxor/context/BaseProcess.h>
#include <haxor/context/MeshContext.h>
#include <haxor/context/MaterialContext.h>
#include <haxor/context/PointGizmo.h>
#include <haxor/context/LineGizmo.h>
#include <haxor/context/AxisGizmo.h>
#include <haxor/context/WireCubeGizmo.h>
#include <haxor/context/WireSphereGizmo.h>
#include <haxor/context/Gizmo.h>
#include <haxor/math/Matrix4.h>
#include <haxor/context/GizmoContext.h>
#include <haxor/context/EngineContext.h>
#include <haxor/context/DataContext.h>
#include <haxor/context/CameraContext.h>
#include <haxor/component/light/PointLight.h>
#include <haxor/component/light/Light.h>
#include <haxor/math/Color.h>
#include <haxor/component/animation/QuaternionKeyFrame.h>
#include <haxor/math/Quaternion.h>
#include <haxor/component/animation/Vector3KeyFrame.h>
#include <haxor/math/Vector3.h>
#include <haxor/component/animation/FloatKeyFrame.h>
#include <haxor/component/animation/KeyFrame.h>
#include <haxor/component/animation/ClipTrack.h>
#include <haxor/component/animation/AnimationEvent.h>
#include <haxor/component/animation/AnimationClip.h>
#include <haxor/component/animation/Animation.h>
#include <haxor/component/Transform.h>
#include <haxor/component/SkinnedMeshRenderer.h>
#include <haxor/component/MeshRenderer.h>
#include <haxor/component/Renderer.h>
#include <haxor/component/DataComponent.h>
#include <haxor/component/CameraOrbitInput.h>
#include <haxor/component/CameraOrbit.h>
#include <haxor/component/Camera.h>
#include <haxe/io/Input.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesOutput.h>
#include <haxe/io/Output.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/format/JsonParser.h>
#include <haxe/ds/StringMap.h>
#include <haxe/ds/ObjectMap.h>
#include <haxe/ds/IntMap.h>
#include <haxe/crypto/BaseCode.h>
#include <haxe/crypto/Base64.h>
#include <haxe/io/Bytes.h>
#include <haxe/Timer.h>
#include <haxe/Log.h>
#include <haxe/Http.h>
#include <cpp/vm/Thread.h>
#include <Xml.h>
#include <XmlType.h>
#include <Type.h>
#include <Sys.h>
#include <StringTools.h>
#include <StringBuf.h>
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
#include <List.h>
#include <Lambda.h>
#include <EReg.h>
#include <cpp/Lib.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::sys::net::Socket_obj::__register();
::sys::net::_Socket::SocketOutput_obj::__register();
::sys::net::_Socket::SocketInput_obj::__register();
::sys::net::Host_obj::__register();
::haxor::platform::windows::input::WinInputHandler_obj::__register();
::haxor::platform::windows::Window_obj::__register();
::haxor::platform::windows::Entry_obj::__register();
::haxor::platform::graphics::OpenGL_obj::__register();
::haxor::platform::windows::graphics::WinGL_obj::__register();
::haxor::platform::OSWindow_obj::__register();
::haxor::net::Web_obj::__register();
::haxor::net::Texture2DLoader_obj::__register();
::haxor::platform::windows::net::BitmapLoader_obj::__register();
::haxor::platform::windows::net::HTTPLoader_obj::__register();
::haxor::platform::windows::net::HTTPRequest_obj::__register();
::haxor::net::HTTPRequestTask_obj::__register();
::haxor::thread::Task_obj::__register();
::haxor::thread::Activity_obj::__register();
::haxor::math::Vector4_obj::__register();
::haxor::math::Vector2_obj::__register();
::haxor::math::Random_obj::__register();
::haxor::math::Mathf_obj::__register();
::haxor::math::AABB3_obj::__register();
::haxor::io::file::MaterialFileUniform_obj::__register();
::haxor::io::file::MaterialFile_obj::__register();
::haxor::io::file::ColladaLight_obj::__register();
::haxor::io::file::ColladaAnimationKeyFrame_obj::__register();
::haxor::io::file::ColladaAnimationChannel_obj::__register();
::haxor::io::file::ColladaAnimation_obj::__register();
::haxor::io::file::ColladaMaterial_obj::__register();
::haxor::io::file::ColladaInstance_obj::__register();
::haxor::io::file::ColladaNode_obj::__register();
::haxor::io::file::ColladaVisualScene_obj::__register();
::haxor::io::file::ColladaController_obj::__register();
::haxor::io::file::ColladaImage_obj::__register();
::haxor::io::file::ColladaInput_obj::__register();
::haxor::io::file::ColladaPrimitive_obj::__register();
::haxor::io::file::ColladaMesh_obj::__register();
::haxor::io::file::ColladaGeometry_obj::__register();
::haxor::io::file::ColladaAssetData_obj::__register();
::haxor::io::file::ColladaFile_obj::__register();
::haxor::io::file::AssetXML_obj::__register();
::haxor::io::file::AssetFile_obj::__register();
::haxor::io::file::Asset_obj::__register();
::haxor::io::UInt16Array_obj::__register();
::haxor::io::Int32Array_obj::__register();
::haxor::io::FloatArray_obj::__register();
::haxor::io::Buffer_obj::__register();
::haxor::input::Touch_obj::__register();
::haxor::input::KeyCode_obj::__register();
::haxor::input::Joystick_obj::__register();
::haxor::input::InputHandler_obj::__register();
::haxor::input::Input_obj::__register();
::haxor::graphics::texture::TextureCube_obj::__register();
::haxor::graphics::texture::RenderTexture_obj::__register();
::haxor::graphics::texture::ComputeTexture_obj::__register();
::haxor::graphics::texture::Texture2D_obj::__register();
::haxor::graphics::texture::Texture_obj::__register();
::haxor::graphics::texture::Bitmap_obj::__register();
::haxor::graphics::mesh::Model_obj::__register();
::haxor::graphics::mesh::Mesh4_obj::__register();
::haxor::graphics::mesh::Mesh2_obj::__register();
::haxor::graphics::mesh::Mesh23_obj::__register();
::haxor::graphics::mesh::Mesh2D_obj::__register();
::haxor::graphics::mesh::SkinnedMesh3_obj::__register();
::haxor::graphics::mesh::Mesh3_obj::__register();
::haxor::graphics::mesh::MeshLayout_obj::__register();
::haxor::graphics::mesh::MeshAttrib_obj::__register();
::haxor::graphics::mesh::Mesh_obj::__register();
::haxor::graphics::material::UberShader_obj::__register();
::haxor::graphics::material::Shader_obj::__register();
::haxor::graphics::material::MaterialUniform_obj::__register();
::haxor::graphics::material::Material_obj::__register();
::haxor::graphics::CursorMode_obj::__register();
::haxor::graphics::Screen_obj::__register();
::haxor::graphics::Graphics_obj::__register();
::haxor::math::AABB2_obj::__register();
::haxor::graphics::GraphicContext_obj::__register();
::haxor::graphics::GraphicAPI_obj::__register();
::haxor::graphics::Gizmo_obj::__register();
::haxor::graphics::GL_obj::__register();
::haxor::ds::SAPInterval_obj::__register();
::haxor::ds::SAPList_obj::__register();
::haxor::ds::SAP_obj::__register();
::haxor::core::Time_obj::__register();
::haxor::core::Scene_obj::__register();
::haxor::core::RenderStats_obj::__register();
::haxor::core::RenderEngine_obj::__register();
::haxor::core::IResizeable_obj::__register();
::haxor::core::ILateUpdateable_obj::__register();
::haxor::core::AnimationWrap_obj::__register();
::haxor::core::InputState_obj::__register();
::haxor::core::ClearFlag_obj::__register();
::haxor::core::TextureType_obj::__register();
::haxor::core::TextureWrap_obj::__register();
::haxor::core::TextureFilter_obj::__register();
::haxor::core::PixelFormat_obj::__register();
::haxor::core::DepthTest_obj::__register();
::haxor::core::CullMode_obj::__register();
::haxor::core::MeshPrimitive_obj::__register();
::haxor::core::MeshMode_obj::__register();
::haxor::core::BlendMode_obj::__register();
::haxor::core::RenderQueue_obj::__register();
::haxor::core::Entity_obj::__register();
::haxor::core::Engine_obj::__register();
::haxor::core::EngineState_obj::__register();
::haxor::core::Console_obj::__register();
::haxor::core::ApplicationProtocol_obj::__register();
::haxor::core::Platform_obj::__register();
::haxor::context::UID_obj::__register();
::haxor::context::TransformContext_obj::__register();
::haxor::context::TextureContext_obj::__register();
::haxor::context::ShaderContext_obj::__register();
::haxor::context::RendererContext_obj::__register();
::haxor::context::Process_obj::__register();
::haxor::context::BaseProcess_obj::__register();
::haxor::context::MeshContext_obj::__register();
::haxor::context::MaterialContext_obj::__register();
::haxor::context::PointGizmo_obj::__register();
::haxor::context::LineGizmo_obj::__register();
::haxor::context::AxisGizmo_obj::__register();
::haxor::context::WireCubeGizmo_obj::__register();
::haxor::context::WireSphereGizmo_obj::__register();
::haxor::context::Gizmo_obj::__register();
::haxor::math::Matrix4_obj::__register();
::haxor::context::GizmoContext_obj::__register();
::haxor::context::EngineContext_obj::__register();
::haxor::context::DataContext_obj::__register();
::haxor::context::CameraContext_obj::__register();
::haxor::component::light::PointLight_obj::__register();
::haxor::component::light::Light_obj::__register();
::haxor::math::Color_obj::__register();
::haxor::component::animation::QuaternionKeyFrame_obj::__register();
::haxor::math::Quaternion_obj::__register();
::haxor::component::animation::Vector3KeyFrame_obj::__register();
::haxor::math::Vector3_obj::__register();
::haxor::component::animation::FloatKeyFrame_obj::__register();
::haxor::component::animation::KeyFrame_obj::__register();
::haxor::component::animation::ClipTrack_obj::__register();
::haxor::component::animation::AnimationEvent_obj::__register();
::haxor::component::animation::AnimationClip_obj::__register();
::haxor::component::animation::Animation_obj::__register();
::haxor::component::Transform_obj::__register();
::haxor::component::SkinnedMeshRenderer_obj::__register();
::haxor::component::MeshRenderer_obj::__register();
::haxor::component::Renderer_obj::__register();
::haxor::component::DataComponent_obj::__register();
::haxor::component::CameraOrbitInput_obj::__register();
::haxor::component::CameraOrbit_obj::__register();
::haxor::component::Camera_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesOutput_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ds::ObjectMap_obj::__register();
::haxe::ds::IntMap_obj::__register();
::haxe::crypto::BaseCode_obj::__register();
::haxe::crypto::Base64_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Log_obj::__register();
::haxe::Http_obj::__register();
::cpp::vm::Thread_obj::__register();
::Xml_obj::__register();
::XmlType_obj::__register();
::Type_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
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
::List_obj::__register();
::Lambda_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::Xml_obj::__init__();
::sys::net::Host_obj::__init__();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::Xml_obj::__boot();
::cpp::vm::Thread_obj::__boot();
::haxe::Log_obj::__boot();
::Lambda_obj::__boot();
::List_obj::__boot();
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
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::Type_obj::__boot();
::XmlType_obj::__boot();
::haxe::Http_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::crypto::Base64_obj::__boot();
::haxe::crypto::BaseCode_obj::__boot();
::haxe::ds::IntMap_obj::__boot();
::haxe::ds::ObjectMap_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::format::JsonParser_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Output_obj::__boot();
::haxe::io::BytesOutput_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxor::component::Camera_obj::__boot();
::haxor::component::CameraOrbit_obj::__boot();
::haxor::component::CameraOrbitInput_obj::__boot();
::haxor::component::DataComponent_obj::__boot();
::haxor::component::Renderer_obj::__boot();
::haxor::component::MeshRenderer_obj::__boot();
::haxor::component::SkinnedMeshRenderer_obj::__boot();
::haxor::component::Transform_obj::__boot();
::haxor::component::animation::Animation_obj::__boot();
::haxor::component::animation::AnimationClip_obj::__boot();
::haxor::component::animation::AnimationEvent_obj::__boot();
::haxor::component::animation::ClipTrack_obj::__boot();
::haxor::component::animation::KeyFrame_obj::__boot();
::haxor::component::animation::FloatKeyFrame_obj::__boot();
::haxor::math::Vector3_obj::__boot();
::haxor::component::animation::Vector3KeyFrame_obj::__boot();
::haxor::math::Quaternion_obj::__boot();
::haxor::component::animation::QuaternionKeyFrame_obj::__boot();
::haxor::math::Color_obj::__boot();
::haxor::component::light::Light_obj::__boot();
::haxor::component::light::PointLight_obj::__boot();
::haxor::context::CameraContext_obj::__boot();
::haxor::context::DataContext_obj::__boot();
::haxor::context::EngineContext_obj::__boot();
::haxor::context::GizmoContext_obj::__boot();
::haxor::math::Matrix4_obj::__boot();
::haxor::context::Gizmo_obj::__boot();
::haxor::context::WireSphereGizmo_obj::__boot();
::haxor::context::WireCubeGizmo_obj::__boot();
::haxor::context::AxisGizmo_obj::__boot();
::haxor::context::LineGizmo_obj::__boot();
::haxor::context::PointGizmo_obj::__boot();
::haxor::context::MaterialContext_obj::__boot();
::haxor::context::MeshContext_obj::__boot();
::haxor::context::BaseProcess_obj::__boot();
::haxor::context::Process_obj::__boot();
::haxor::context::RendererContext_obj::__boot();
::haxor::context::ShaderContext_obj::__boot();
::haxor::context::TextureContext_obj::__boot();
::haxor::context::TransformContext_obj::__boot();
::haxor::context::UID_obj::__boot();
::haxor::core::Platform_obj::__boot();
::haxor::core::ApplicationProtocol_obj::__boot();
::haxor::core::Console_obj::__boot();
::haxor::core::EngineState_obj::__boot();
::haxor::core::Engine_obj::__boot();
::haxor::core::Entity_obj::__boot();
::haxor::core::RenderQueue_obj::__boot();
::haxor::core::BlendMode_obj::__boot();
::haxor::core::MeshMode_obj::__boot();
::haxor::core::MeshPrimitive_obj::__boot();
::haxor::core::CullMode_obj::__boot();
::haxor::core::DepthTest_obj::__boot();
::haxor::core::PixelFormat_obj::__boot();
::haxor::core::TextureFilter_obj::__boot();
::haxor::core::TextureWrap_obj::__boot();
::haxor::core::TextureType_obj::__boot();
::haxor::core::ClearFlag_obj::__boot();
::haxor::core::InputState_obj::__boot();
::haxor::core::AnimationWrap_obj::__boot();
::haxor::core::ILateUpdateable_obj::__boot();
::haxor::core::IResizeable_obj::__boot();
::haxor::core::RenderEngine_obj::__boot();
::haxor::core::RenderStats_obj::__boot();
::haxor::core::Scene_obj::__boot();
::haxor::core::Time_obj::__boot();
::haxor::ds::SAP_obj::__boot();
::haxor::ds::SAPList_obj::__boot();
::haxor::ds::SAPInterval_obj::__boot();
::haxor::graphics::GL_obj::__boot();
::haxor::graphics::Gizmo_obj::__boot();
::haxor::graphics::GraphicAPI_obj::__boot();
::haxor::graphics::GraphicContext_obj::__boot();
::haxor::math::AABB2_obj::__boot();
::haxor::graphics::Graphics_obj::__boot();
::haxor::graphics::Screen_obj::__boot();
::haxor::graphics::CursorMode_obj::__boot();
::haxor::graphics::material::Material_obj::__boot();
::haxor::graphics::material::MaterialUniform_obj::__boot();
::haxor::graphics::material::Shader_obj::__boot();
::haxor::graphics::material::UberShader_obj::__boot();
::haxor::graphics::mesh::Mesh_obj::__boot();
::haxor::graphics::mesh::MeshAttrib_obj::__boot();
::haxor::graphics::mesh::MeshLayout_obj::__boot();
::haxor::graphics::mesh::Mesh3_obj::__boot();
::haxor::graphics::mesh::SkinnedMesh3_obj::__boot();
::haxor::graphics::mesh::Mesh2D_obj::__boot();
::haxor::graphics::mesh::Mesh23_obj::__boot();
::haxor::graphics::mesh::Mesh2_obj::__boot();
::haxor::graphics::mesh::Mesh4_obj::__boot();
::haxor::graphics::mesh::Model_obj::__boot();
::haxor::graphics::texture::Bitmap_obj::__boot();
::haxor::graphics::texture::Texture_obj::__boot();
::haxor::graphics::texture::Texture2D_obj::__boot();
::haxor::graphics::texture::ComputeTexture_obj::__boot();
::haxor::graphics::texture::RenderTexture_obj::__boot();
::haxor::graphics::texture::TextureCube_obj::__boot();
::haxor::input::Input_obj::__boot();
::haxor::input::InputHandler_obj::__boot();
::haxor::input::Joystick_obj::__boot();
::haxor::input::KeyCode_obj::__boot();
::haxor::input::Touch_obj::__boot();
::haxor::io::Buffer_obj::__boot();
::haxor::io::FloatArray_obj::__boot();
::haxor::io::Int32Array_obj::__boot();
::haxor::io::UInt16Array_obj::__boot();
::haxor::io::file::Asset_obj::__boot();
::haxor::io::file::AssetFile_obj::__boot();
::haxor::io::file::AssetXML_obj::__boot();
::haxor::io::file::ColladaFile_obj::__boot();
::haxor::io::file::ColladaAssetData_obj::__boot();
::haxor::io::file::ColladaGeometry_obj::__boot();
::haxor::io::file::ColladaMesh_obj::__boot();
::haxor::io::file::ColladaPrimitive_obj::__boot();
::haxor::io::file::ColladaInput_obj::__boot();
::haxor::io::file::ColladaImage_obj::__boot();
::haxor::io::file::ColladaController_obj::__boot();
::haxor::io::file::ColladaVisualScene_obj::__boot();
::haxor::io::file::ColladaNode_obj::__boot();
::haxor::io::file::ColladaInstance_obj::__boot();
::haxor::io::file::ColladaMaterial_obj::__boot();
::haxor::io::file::ColladaAnimation_obj::__boot();
::haxor::io::file::ColladaAnimationChannel_obj::__boot();
::haxor::io::file::ColladaAnimationKeyFrame_obj::__boot();
::haxor::io::file::ColladaLight_obj::__boot();
::haxor::io::file::MaterialFile_obj::__boot();
::haxor::io::file::MaterialFileUniform_obj::__boot();
::haxor::math::AABB3_obj::__boot();
::haxor::math::Mathf_obj::__boot();
::haxor::math::Random_obj::__boot();
::haxor::math::Vector2_obj::__boot();
::haxor::math::Vector4_obj::__boot();
::haxor::thread::Activity_obj::__boot();
::haxor::thread::Task_obj::__boot();
::haxor::net::HTTPRequestTask_obj::__boot();
::haxor::platform::windows::net::HTTPRequest_obj::__boot();
::haxor::platform::windows::net::HTTPLoader_obj::__boot();
::haxor::platform::windows::net::BitmapLoader_obj::__boot();
::haxor::net::Texture2DLoader_obj::__boot();
::haxor::net::Web_obj::__boot();
::haxor::platform::OSWindow_obj::__boot();
::haxor::platform::windows::graphics::WinGL_obj::__boot();
::haxor::platform::graphics::OpenGL_obj::__boot();
::haxor::platform::windows::Entry_obj::__boot();
::haxor::platform::windows::Window_obj::__boot();
::haxor::platform::windows::input::WinInputHandler_obj::__boot();
::sys::net::Host_obj::__boot();
::sys::net::_Socket::SocketInput_obj::__boot();
::sys::net::_Socket::SocketOutput_obj::__boot();
::sys::net::Socket_obj::__boot();
}

