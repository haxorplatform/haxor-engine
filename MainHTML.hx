#if html

package ;
import haxor.core.Scene;
import haxor.platform.html.graphics.mesh.MeshReader;
import haxor.platform.html.graphics.mesh.MeshWriter;
import haxor.io.serialization.Formatter;
import haxor.component.Behaviour;
import haxe.rtti.Meta;
import haxor.context.ShaderContext;
import haxor.io.serialization.HaxorFormatter;
import haxe.Json;
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

class DataBehaviour extends Behaviour
{
	@serialize
	public var nodes : Array<Transform>;
	
	@serialize
	public var ids : Array<Int>;
	
	override function OnBuild():Void 
	{
		nodes = [];
		ids = [];
		for (i in 0...3)
		{
			var e : Entity = new Entity("C" + i);
			e.transform.parent = transform;
			nodes.push(e.transform);
			ids.push(e.uid);
		}
	}
}

class MainHTML extends Application implements IRenderable implements IUpdateable
{	
	static public function main():Void {  EntryPoint.Initialize(); }
	
	var scn : Scene;
	
	var root : Entity;
	
	var scnstr : String;
	var scene_file:String;
	
	override public function Initialize():Void 
	{
		Console.Log(platform + "> Application Initialize");
		
		root = new Entity("roots");
		
		scnstr = "";
		scene_file = "";
		
		var s0 : Shader = Shader.FlatTexture;
		var s1 : Shader = Shader.Flat;
		
		var mat0 : Material;
		var mat1 : Material;
		
		mat0 = new Material("Mat0");
		mat0.shader = s0;
		mat0.SetTexture("DiffuseTexture", Texture2D.random);
		mat0.SetColor("Tint", Color.red50);
		
		mat1 = new Material("Mat1");
		mat1.shader = s1;		
		mat1.SetColor("Tint", Color.green50);
		
		var db0 : DataBehaviour;
		var db1 : DataBehaviour;
		
		db0 = (new Entity("Data0")).AddComponent(DataBehaviour); db0.transform.parent = root.transform;
		db0 = (new Entity("Data1")).AddComponent(DataBehaviour); db0.transform.parent = root.transform;
		db1 = (new Entity("Data2")).AddComponent(DataBehaviour);
		db1.transform.parent = db0.transform;
		
		var sphere : MeshRenderer;
		
		for (i in 0...3)
		{
			sphere = (new Entity("sphere")).AddComponent(MeshRenderer);
			sphere.mesh = Model.sphere;
			sphere.material = (i & 1) == 0 ? mat0 : mat1;
			sphere.transform.position = new Vector3( -1.5 + (i * 0.8), 0.0, 0.0);
			sphere.transform.localScale = Vector3.one.Scale(0.25 + (i * 0.1));
			sphere.transform.parent = root.transform;
		}
		
		var o : CameraOrbit = CameraOrbit.Create(4.0, 45, 45);				
		o.camera.background = new Color(0.2, 0.2, 0.2);
		var ci : CameraOrbitInput = o.AddComponent(CameraOrbitInput);
		
		o.pivot.parent = root.transform;
	
		trace(Transform.root.OutputHierarchy(false, false));
		
		scn = new Scene("root");
		
		Timer.delay(function() { trace(EngineContext.resources.length); }, 1000 );
		
		
	}
	
	public function OnUpdate():Void
	{
		if (Input.Down(KeyCode.Delete))
		{
			Resource.Destroy(root);
			Timer.delay(function() { trace(EngineContext.resources.length); }, 1000 );
		}
		
		if (Input.Down(KeyCode.S))
		{
			scn.Save(Transform.root);
			var fmt : HaxorFormatter = new HaxorFormatter();
			scene_file = fmt.Serialize(scn);			
			Timer.delay(function() { trace(EngineContext.resources.length); }, 1000 );
		}
		
		if (Input.Down(KeyCode.L))
		{
			if (scene_file == "") return;
			var fmt : HaxorFormatter = new HaxorFormatter();
			
			var nscn : Scene = fmt.Deserialize(scene_file);
			
			nscn.Load(function(p:Float32)
			{
				trace(p);
				if (p >= 1.0)
				{
					var t : Transform = Transform.root.GetChildByName("roots", true);
					if (t != null) root = t.entity;
					Timer.delay(function() { trace(EngineContext.resources.length); }, 1000 );
				}
			});
		}
	}
	
	public function OnRender():Void
	{
		Gizmo.Grid(100.0);
	}
}

#end