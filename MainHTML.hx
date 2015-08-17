#if html

package ;
import haxor.context.ShaderContext;
import haxor.io.serialization.haxor.HaxorFormatter;
import haxe.Json;
import haxor.io.serialization.Formatter;
import js.html.EventTarget;
import haxor.platform.html.input.DragDrop;
import js.html.Uint8Array;
import js.html.ArrayBuffer;
import js.html.FileReader;
import js.html.File;
import js.html.Event;
import haxe.Timer;
import haxor.component.animation.Animation;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.MeshRenderer;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.context.UID;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Entity;
import haxor.core.Enums.AnimationWrap;
import haxor.core.Enums.CameraMode;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.ForceMode;
import haxor.core.Enums.InputState;
import haxor.core.IFixedUpdateable;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.core.RenderStats;
import haxor.core.Time;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureFilter;
import haxor.ds.SAP;
import haxor.ds.USet;
import haxor.graphics.Gizmo;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout;
import haxor.graphics.mesh.Model;
import haxor.graphics.Screen;
import haxor.graphics.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.input.Input;
import haxor.input.Joystick;
import haxor.input.KeyCode;
import haxor.io.Buffer;
import haxor.io.file.ColladaFile;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.math.AABB2;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Random;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.net.Web;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext.GraphicAPI;
import haxor.physics.broadphase.SAPBroadPhase;
import haxor.physics.Collision;
import haxor.physics.Physics;
import haxor.physics.PhysicsMaterial;
import haxor.platform.html.graphics.ImageReader;
import haxor.platform.Types.Float32;
import haxor.platform.Types.MeshBufferId;
import haxor.thread.Activity;
import js.Browser;

class MainHTML extends Application implements IRenderable
{	
	static public function main():Void {  EntryPoint.Initialize(); }
	
	override public function Initialize():Void 
	{
		Console.Log(platform + "> Application Initialize");
		
		var s0 : Shader = Shader.FlatTexture;
		
		trace(HaxorFormatter.ToString(s0));
		
		var mat : Material = new Material("Flat");
		mat.shader = s0;
		mat.SetTexture("DiffuseTexture", Texture2D.random);
		mat.SetColor("Tint", Color.red50);
		
		var sphere : MeshRenderer = (new Entity("sphere")).AddComponent(MeshRenderer);
		sphere.mesh = Model.sphere;
		sphere.material = Resource.Instantiate(mat);
		
		trace(sphere.material.name);
		
		var o : CameraOrbit = CameraOrbit.Create(4.0, 45, 45);				
		o.camera.background = new Color(0.2, 0.2, 0.2);
		var ci : CameraOrbitInput = o.AddComponent(CameraOrbitInput);
	
		
	}
	
	public function OnRender():Void
	{
		Gizmo.Grid(100.0);
	}
}

#end