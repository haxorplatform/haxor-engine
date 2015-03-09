package examples.ubershader;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.ShaderFeature;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.graphics.Gizmo;
import haxor.graphics.material.Material;
import haxor.graphics.material.shader.FlexShader;
import haxor.graphics.mesh.Model;
import haxor.graphics.texture.TextureCube;
import haxor.math.Color;
import haxor.math.Vector3;
import haxor.net.Web;
import haxor.platform.Types.Float32;
import haxor.thread.Activity;
import js.html.Element;
import js.html.Event;
import js.html.SelectElement;



#if html
import js.Browser;
import js.html.DivElement;
import js.Stats;
import examples.utils.LoaderHTML;
#end




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
	
	public var orbit : CameraOrbit;
	
	public var model : Entity;
	
	public var mr : MeshRenderer;
	
	#if html
	var stats : js.Stats;	
	#end
	
	var loader : LoaderHTML;	
	
	/**
	 * Callback called when this component is created.
	 */
	override function OnBuild():Void
	{
		super.OnBuild();		
	}
	
	
	/**
	 * Callback called in the first update.
	 */
	override function OnStart():Void 
	{
		loader = new LoaderHTML();
	}
	
	/**
	 * Callback called when everything finished downloading. 
	 */
	override public function Initialize():Void 
	{
		
		Console.Log("Initialize");
		
		#if html
		loader.SetProgress(1.0);
		loader.Complete();
		stats = new js.Stats();
		stats.domElement.style.position = "absolute";
        stats.domElement.style.top = '0px';				
		stats.domElement.style.right = '0px';				
        Browser.document.body.appendChild(stats.domElement);		
		Activity.Run(function(t:Float32):Bool { stats.update(); return true; } );
		
		Browser.document.getElementById("select-cubemap").onchange = OnCubemapChange;
		
		#end		
		
		Activity.Delay(1.0, function()
		{		
			orbit = CameraOrbit.Create(8, -45, 45);
			//orbit = CameraOrbit.Create(-0.1, 2, -10);
			orbit.transform.localPosition = new Vector3(0, 9, 26);
			orbit.smooth = 5;		
			orbit.camera.background = Color.FromBytes(10, 0, 40);
			orbit.camera.clear = ClearFlag.SkyboxDepth;
			orbit.camera.near = 1.0;
			orbit.camera.far  = 200;
			orbit.camera.fov  = 40;		
			
			orbit.camera.skybox = cast Asset.Get("skybox/nvlobby");
			var orbit_input : CameraOrbitInput = orbit.entity.AddComponent(CameraOrbitInput);		
			orbit_input.zoomSpeed = 1;
			/*
			model = new Entity("model");
			mr = model.AddComponent(MeshRenderer);
			mr.mesh = Model.sphere;
			mr.material = Material.Opaque();
			mr.material.shader = new FlexShader("shader", ShaderFeature.ReflectionPixel | ShaderFeature.Tint);
			mr.material.SetTexture("ReflectionTexture", orbit.camera.skybox);
			mr.material.SetColor("ReflectionColor", Color.white);
			mr.material.SetFloat("ReflectionIntensity", 1.0);
			mr.material.SetColor("Tint", Color.black);
			//*/
		});
	}
	
	public function OnUpdate():Void
	{	
	
		
	}
	
	public function OnRender():Void
	{
		//Gizmo.Grid(50);				
	}
	
	/**
	 * 
	 * @return
	 */
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		Asset.LoadTextureCubeCross("skybox/nvlobby", "./texture/skybox/cross/nvlobby.jpg");
		Asset.LoadTextureCubeCross("skybox/storm", "./texture/skybox/cross/storm.jpg");
		Asset.LoadTextureCubeCross("skybox/bourke", "./texture/skybox/cross/bourke.jpg");
		
		return false;
	}
	
	override public function OnLoadProgress(p_id:String, p_progress:Float32):Void 
	{
		#if html
		loader.SetProgress(Asset.progress);
		#end
	}
	
	override public function OnLoadComplete(p_id:String, p_asset:Dynamic):Void 
	{
		
	}
	
	private function OnCubemapChange(ev:Event) 
	{ 
		var el : Dynamic = cast ev.target;
		var opt : String = el.options[el.selectedIndex].value;
		orbit.camera.skybox = cast Asset.Get(opt); 
		if(mr!=null) mr.material.SetTexture("ReflectionTexture", orbit.camera.skybox); 
	}
	
	private function OnModelChange(ev:Event) 
	{ 
		var el : Dynamic = cast ev.target;
		var opt : String = el.options[el.selectedIndex].value;
		Resource.Destroy(model);
		switch(opt)
		{
			case "sphere":
			case "cube":
			case "human":
				
		}
	}
	
}