package examples.particles;
import examples.utils.LoaderHTML;
import haxe.Timer;
import haxor.component.animation.Animation;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.light.Light;
import haxor.component.MeshRenderer;
import haxor.component.ParticleRenderer;
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
import haxor.core.BaseApplication.ApplicationProtocol;
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
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.RenderTexture;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.input.Input;
import haxor.input.Joystick;
import haxor.input.KeyCode;
import haxor.io.Buffer;
import haxor.io.file.ColladaFile;
import haxor.io.file.MaterialFile;
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
import haxor.platform.Types.Float32;
import haxor.platform.Types.MeshBufferId;
import haxor.thread.Activity;
import haxor.thread.Kernel;




/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class Main extends Application implements IUpdateable implements IRenderable
{
	
	static public function main():Void 
	{ 
		EntryPoint.Initialize();
	}
	
	
	#if html
	var ui : js.Stats;
	var field : js.html.DivElement;	
	#end
	
	var loader : LoaderHTML;	
	
	public var debug : Bool;
	
	public var orbit : CameraOrbit;
	
	public var particle : ParticleRenderer;
	
	public var angle : Float32;
	
	/**
	 * 
	 */
	private function LoadDebug():Void
	{
		#if html		
		field = cast js.Browser.document.getElementById("field");
		ui = new js.Stats();
		ui.domElement.style.position = "absolute";
        ui.domElement.style.top = '0px';		
        js.Browser.document.body.appendChild(ui.domElement);		
		Activity.Run(function(t:Float32):Bool { ui.update(); return true; });
		#end		
		debug = false;
		
		CreateParticle();
	}
	
	/**
	 * 
	 */
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");
		LoadDebug();		
		entity.enabled = true;	
		angle = 0;
	}
	
	override public function OnStart():Void
	{
		loader = new LoaderHTML();
		
		entity.enabled = false;
		
		orbit = CameraOrbit.Create(10, 45, 45);
		orbit.transform.localPosition = new Vector3(0, 0, 0);
		orbit.smooth = 5;		
		orbit.camera.background = Color.gray25;
		orbit.camera.near = 0.1;
		orbit.camera.far  = 500;
		orbit.camera.fov  = 40;
		
		var orbit_input : CameraOrbitInput = orbit.entity.AddComponent(CameraOrbitInput);		
		orbit_input.zoomSpeed = 0.2;
		
		
	}
	
	private function CreateParticle():Void
	{
		//Creates the particle renderer
		particle = (new Entity("emitter")).AddComponent(ParticleRenderer);
				
		//Creates a spherical emitter.
		var sphere_emitter : SphereEmitter = cast particle.emitter = new SphereEmitter(1.0);
		
		//Flag that tells if the starting velocity will be random or from center out.
		sphere_emitter.random = false;
		
		//Flag that tells if new particles are spawned from the emitter surface or interior.
		sphere_emitter.surface = false;
		
		//XYZ intervals that tells the velocity limits of the particle
		//For instance, with this attribute, it is possible to make a particle only move upwards by setting [0,0,0,1000,0,0].
		sphere_emitter.ranges = [ -1000, 1000, -1000,  1000, -1000, 1000];
		
		//Tells the max number of particles
		particle.count = 40;
		
		//Particles emitted per second
		particle.rate.start = particle.rate.end = 20;
		
		//This particle attribute tells  that the particle will start with size 'start' and increase until 'end' with an easing of t ^ 2.0
		particle.life.size.start = new Vector3(0.1,0.1,0.1);
		particle.life.size.end   = new Vector3(3.0,3.0,3.0);
		particle.life.size.curve = 2.0;
		
		//Flag that tells if the particles are bound by the emitter Transform
		//If 'false' if the emitter moves after the particle shows, the particle will keep going without being affected by the emitter.
		particle.local = false;
		
		//The emitter will keep launching particles
		particle.loop = true;
		
		//The particles will always face camera
		particle.billboard = true;
		
		//Particle will start with lifetime between 'start' and 'end' seconds		
		particle.start.life.start    = 1.0;
		particle.start.life.end      = 1.0;
		particle.start.life.random   = true;
		
		//Particle will start with speed multiplier between 'start' and 'end'
		particle.start.speed.start   = 0.1;
		particle.start.speed.end     = 2.0;
		particle.start.speed.random  = true;
		
		//Some gravity
		particle.force = new Vector3(0, 0.0, 0);
		
		//Yes you can create textures and manipulate pixels :)
		var color_fade : Texture2D = new Texture2D(4, 1, PixelFormat.RGBA8);
		
		//Sets the pixels
		color_fade.data.SetPixels([Color.white, Color.yellow, Color.red, Color.empty]);
		
		//Send changes to GPU
		color_fade.Apply();
		
		//Passes the color gradient that will be used to set the particle color over life
		particle.life.color = color_fade;
		
		
		//starts emitting
		particle.Play();
		
		var tex : Texture = Asset.Get("particle");
		tex.name = "particle";
		//Creates a material that handles rendering information like shader, depth test, render queue.
		var mat : Material = new Material();
		mat.name 	= "ParticleAdditive";
		mat.shader  = Shader.FlatParticle; 			//Gets the shader loaded in the 'Load' method		
		mat.SetTexture("Texture",tex); 			//Sets the 'DiffuseTexture' Uniform to the loaded texture.
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.One);				//Additive blending
		mat.blend = true;
		mat.zwrite = false;											//Disable ZWrite so particles blend with each other
		mat.cull = CullMode.None;
		//Sets the material
		particle.material = mat;
		
		
		Debug.transform = true;
	}
	
	public function OnUpdate():Void
	{			
		
		//if (game == null) return;
		var log : String = "";		
		log += "Stats";
		log += "\nSAP: " + Camera.SAPCulling;
		log += "\nVisible: " + RenderStats.visible;
		log += "\nCulled: " + RenderStats.culled;
		log += "\nActive: " + RenderStats.total;
		log += "\nRenderers: " + RenderStats.renderers;
		log += "\nTris: " + RenderStats.triangles;
		
		if (Input.Down(KeyCode.Q))  Camera.SAPCulling   = !Camera.SAPCulling;
		if (Input.Down(KeyCode.D2)) Debug.transform 	= !Debug.transform;		
		if (Input.Down(KeyCode.D3)) Debug.collider 		= !Debug.collider;		
		if (Input.Down(KeyCode.D4)) Debug.light 		= !Debug.light;		
		if (Input.Down(KeyCode.D5)) Debug.renderer 		= !Debug.renderer;		
		//if (Input.Down(KeyCode.D6)) Debug.particles 	= !Debug.particles;
		
		#if html
		
		if (Input.Down(KeyCode.D1))
		{
			debug = !debug;
			if (!debug)
			{
				field.innerText = "";				
			}
			orbit.follow = !debug;
			ui.domElement.style.display = debug ? "block" : "none";
		}		
		if(debug) if(field!=null) field.innerText = log;		
		#end
		
		var p : Vector3 = orbit.pivot.localPosition;
		var vz : Vector3 = orbit.pivot.forward;
		var vx : Vector3 = orbit.pivot.right;
		vz.y = 0; vz.Normalize();
		vx.y = 0; vx.Normalize();
		
		if (debug)
		{
			if (Input.Pressed(KeyCode.W)) p.Add(vz.Scale(Time.delta));
			if (Input.Pressed(KeyCode.S)) p.Sub(vz.Scale(Time.delta));			
			if (Input.Pressed(KeyCode.A)) p.Sub(vx.Scale(Time.delta));
			if (Input.Pressed(KeyCode.D)) p.Add(vx.Scale(Time.delta));
			orbit.pivot.localPosition = p;			
			
			p = particle.transform.localPosition;
			
			if (Input.Pressed(KeyCode.Up)) p.Add(vz.Scale(Time.delta*5.0));
			if (Input.Pressed(KeyCode.Down)) p.Sub(vz.Scale(Time.delta*5.0));			
			if (Input.Pressed(KeyCode.Left)) p.Sub(vx.Scale(Time.delta*5.0));
			if (Input.Pressed(KeyCode.Right)) p.Add(vx.Scale(Time.delta*5.0));
			
			particle.transform.localPosition = p;
		}
		
		#if windows		
		application.window.title = StringTools.replace(log+" FPS: "+Time.fps, "\n", " ");
		#end
		
		#if android
		Console.Log(StringTools.replace(log + " FPS: " + Time.fps, "\n", " "));
		#end
		
		angle += Time.delta * 45.0;		
		var s : Float32 = Mathf.Sin(angle * Mathf.Deg2Rad);
		//particle.transform.position = Vector3.Lerp(new Vector3( -2, 0, 0), new Vector3(2, 0, 0), s);
		
		
		var flag_emit : Bool = false;
		
		if (Input.Down(KeyCode.Space)) flag_emit = true;
		if (Input.touches.length > 0) if (Input.touches[0].down) flag_emit = true;
		if (Input.touches.length > 1) if (Input.touches[1].down) particle.Reset();
		if (flag_emit)
		{
			trace("EMIT");
			particle.Emit(1.0);
		}
		
		
	}
	
	public function OnRender():Void
	{
		//if(Debug.transform)
		{
			Gizmo.Grid(100.0, new Color(1, 1, 1, 0.1));
			Gizmo.Axis(Vector3.temp.Set(), Vector3.temp.Set(2, 2, 2));
		}
		
		var sh : Float = Screen.height;
		var th : Float = 2048.0;// sh * 0.9;
		var tex : Texture= particle.m_kernel.m_back;
		
		if(tex!=null)Graphics.DrawTexture(tex,0,100,300,300);		
		
		
	}
	
	/**
	 * 
	 * @return
	 */
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		if (protocol == ApplicationProtocol.File)
		{
			Asset.LoadTexture2D("particle", 	  "assets/particles/particle.png");	
		}
		else
		{
			Asset.LoadTexture2D("particle", 	  "./texture/particle/particle.png");	
		}
		
		#if html				
		#end
		/*
		//Falloff Ramp
		Asset.LoadTexture2D("player/ramp", 	  "./texture/misc/ramp00.jpg");				
		Asset.LoadTexture2D("player/diffuse", "assets/ethan/texture/EthanOcclusion.png");
		Asset.LoadTexture2D("player/normal", "assets/ethan/texture/EthanNormals.png");
		
		Asset.LoadCollada("player", 		 "assets/ethan/asset.dae");
		Asset.LoadCollada("player/animation/idle",  "assets/ethan/animation-idle.DAE");
		Asset.LoadCollada("player/animation/run",   "assets/ethan/animation-run.DAE");
				
		Asset.LoadTexture2D("BlobShadow", 	    "./texture/misc/shadow_blob.jpg");		
		
		Asset.LoadShader("haxor/unlit/FlatTexture", 								"./shader/unlit/FlatTexture.shader");						
		Asset.LoadShader("haxor/unlit/FlatTextureSkin", 							"./shader/unlit/FlatTextureSkin.shader");				
		Asset.LoadShader("haxor/unlit/FlatSkin", 									"./shader/unlit/FlatSkin.shader");				
		Asset.LoadShader("haxor/unlit/Flat", 										"./shader/unlit/Flat.shader");		
		Asset.LoadShader("haxor/lightmap/FlatTexture", 								"./shader/lightmap/FlatTexture.shader");								
		Asset.LoadShader("haxor/unlit/Particle", 									"./shader/unlit/Particle.shader");		
		
		Asset.LoadShader("haxor/diffuse/Flat",	 									"./shader/diffuse/Flat.shader");
		Asset.LoadShader("haxor/diffuse/Diffuse", 									"./shader/diffuse/Diffuse.shader");
		Asset.LoadShader("haxor/diffuse/DiffuseSkin", 								"./shader/diffuse/DiffuseSkin.shader");
		Asset.LoadShader("haxor/diffuse/ToonSkin", 									"./shader/diffuse/ToonSkin.shader");
		Asset.LoadShader("haxor/diffuse/ToonSkinFalloff", 							"./shader/diffuse/ToonSkinFalloff.shader");		
		Asset.LoadShader("haxor/screen/Displacement",								"./shader/screen/Displacement.shader");
		
		Asset.LoadShader("haxor/kernel/ParticleKernel", 							"./shader/kernel/ParticleKernel.shader");
		
		Asset.LoadMaterial("haxor/material/opaque/unlit/Flat", 		  				"./material/opaque/unlit/Flat.mat");		
		Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTexture", 				"./material/opaque/unlit/FlatTexture.mat");						   
		Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTextureSkin",			"./material/opaque/unlit/FlatTextureSkin.mat");				
		Asset.LoadMaterial("haxor/material/opaque/lightmap/FlatTexture", 			"./material/opaque/lightmap/FlatTexture.mat");		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/DiffuseSkin", 		  	"./material/opaque/diffuse/DiffuseSkin.mat");	
		Asset.LoadMaterial("haxor/material/opaque/diffuse/ToonSkin", 		  		"./material/opaque/diffuse/ToonSkin.mat");	
		Asset.LoadMaterial("haxor/material/transparent/unlit/Flat", 		  		"./material/transparent/unlit/Flat.mat");		
		Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTexture", 			"./material/transparent/unlit/FlatTexture.mat");						   
		Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTextureSkin", 		"./material/transparent/unlit/FlatTextureSkin.mat");		
		Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAdditive", 	"./material/transparent/unlit/ParticleAdditive.mat");
		Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAlpha", 		"./material/transparent/unlit/ParticleAlpha.mat");		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/Diffuse",	  				"./material/opaque/diffuse/Diffuse.mat");		
		Asset.LoadMaterial("haxor/material/opaque/diffuse/Flat",	  				"./material/opaque/diffuse/Flat.mat");				
		Asset.LoadMaterial("haxor/material/screen/Displacement",	  				"./material/screen/Displacement.mat");
		//*/
		return false;
	}
	
	override public function OnLoadProgress(p_id:String, p_progress:Float32):Void 
	{
		#if html
		var f = cast js.Browser.document.getElementById("field");
		//f.innerText = "Loading [" + p_id + "] " + Mathf.Ceil(Asset.progress * 100) + "%";		
		#end
		loader.SetProgress(Asset.progress);
	}
	
	override public function OnLoadComplete(p_id:String, p_asset:Dynamic):Void 
	{
		//trace("DungeonApp> [" + p_id + "] created!");
		#if html		
		var f = cast js.Browser.document.getElementById("field");
		//f.innerText = "Loading " + Mathf.Ceil(Asset.progress * 100)+"%";
		//if (Asset.progress >= 1.0) f.innerText = "";		
		#end
		if(Asset.progress >= 1.0) loader.Complete();
	}
	
}
