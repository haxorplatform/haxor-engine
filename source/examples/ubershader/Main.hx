package examples.ubershader;
import haxor.component.Camera;
import haxor.component.CameraOrbit;
import haxor.component.Transform;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.graphics.texture.TextureCube;
import haxor.net.Web;
import haxor.platform.Types.Float32;
import haxor.thread.Activity;



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
	
	public var cam : Camera;
	
	public var orbit : CameraOrbit;
	
	public var player : Transform;
	
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
        Browser.document.body.appendChild(stats.domElement);		
		Activity.Run(function(t:Float32):Bool { stats.update(); return true; });
		#end		
		
		var tc : TextureCube = new TextureCube();
		tc.LoadCrossTexture(cast Asset.Get("skybox/nvlobby"));
	}
	
	public function OnUpdate():Void
	{	
	
		
	}
	
	public function OnRender():Void
	{
						
	}
	
	/**
	 * 
	 * @return
	 */
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		Asset.LoadTexture2D("skybox/nvlobby", "./texture/skybox/cross/nvlobby.jpg");
		
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
	
}