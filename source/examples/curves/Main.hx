package examples.curves;
import examples.curves.Main.ControlPoint;
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
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Color;
import haxor.math.Curve;
import haxor.math.Mathf;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.net.Web;
import haxor.platform.Types.Float32;
import haxor.thread.Activity;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.Element;
import js.html.Event;
import js.html.MouseEvent;
import js.html.SelectElement;



#if html
import js.Browser;
import js.html.DivElement;
import js.Stats;
import examples.utils.LoaderHTML;
#end


class ControlPoint
{
	public var element : DivElement;
	
	public var x(get_x, set_x):Float32;
	private function get_x():Float32 { return m_x; }
	private function set_x(v:Float32):Float32 { m_x = v; element.style.left = Mathf.Floor(v) + "px"; return v; }
	private var m_x:Float32;
	
	public var y(get_y, set_y):Float32;
	private function get_y():Float32 { return m_y; }
	private function set_y(v:Float32):Float32 { m_y = v; element.style.top = Mathf.Floor(v) + "px"; return v; }
	private var m_y:Float32;
	
	public function new(p_element:Element):Void
	{
		element = cast p_element;
		x = 0;
		y = 0;
	}
	
}

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
	
	public var curve : Curve;
	public var canvas : CanvasElement;
	public var g : CanvasRenderingContext2D;
	
	public var panel : DivElement;	
	public var controls  : DivElement;	
	public var target : Element;
	
	public var dot_template : DivElement;
	
	public var pan : Vector2;
	
	public var block : Bool;
	
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
		
		loader.SetProgress(1.0);
		loader.Complete();
		stats = new js.Stats();
		stats.domElement.style.position = "absolute";
        stats.domElement.style.top = '0px';				
		stats.domElement.style.right = '0px';				
        Browser.document.body.appendChild(stats.domElement);		
		Activity.Run(function(t:Float32):Bool { stats.update(); return true; } );
		
		Activity.Delay(1.0, function()
		{		
			orbit = CameraOrbit.Create(8, -45, 45);
			//orbit = CameraOrbit.Create(-0.1, 2, -10);
			orbit.transform.localPosition = new Vector3(0, 9, 26);
			orbit.smooth = 5;		
			orbit.camera.background = Color.FromBytes(10, 0, 40);
			//orbit.camera.clear = ClearFlag.SkyboxDepth;
			orbit.camera.near = 1.0;
			orbit.camera.far  = 200;
			orbit.camera.fov  = 40;		
			
			//orbit.camera.skybox = cast Asset.Get("skybox/nvlobby");
			var orbit_input : CameraOrbitInput = orbit.entity.AddComponent(CameraOrbitInput);		
			orbit_input.zoomSpeed = 1;
			
			curve = new Curve();
			
		});
		
		panel 		= cast Browser.document.getElementById("panel");
		controls        = cast Browser.document.getElementById("controls");
		canvas 	  		= cast Browser.document.getElementById("graph");		
		dot_template    = cast Browser.document.getElementById("dot-template");		
		dot_template.style.display = "none";
		
		block = false;
		
		panel.onmouseover = OnContainerMouse;
		
		g = canvas.getContext2d();
		pan = new Vector2();
	}
	
	public function OnUpdate():Void
	{			
		var mp : Vector2 = Input.mouse.clone;
		block = false;
		
		if (target != null)
		{
			switch(target.id)
			{
				case "pan":
				if (Input.Pressed(KeyCode.Mouse0))
				{
					block = true;
					pan.x += Input.deltaMouse.x;
					pan.y += Input.deltaMouse.y;
				}
			}
		}
		
	}
	
	public function OnRender():Void
	{
		var w : Float32 = cast canvas.clientWidth;
		var h : Float32 = cast canvas.clientHeight;
		
		var tx : Float32 = 0.0;
		var ty : Float32 = 0.0;
		var gs : Float32 = 10.0;
		
		canvas.width  = cast w;
		canvas.height = cast h;
		
		g.transform(1, 0, 0, 1, 0.0, 0.0);
		
		g.setFillColor(0.3, 0.2, 0.3, 1.0);
		g.fillRect(0, 0, w, h);
		
		g.beginPath();		
		
		for (i in  0...(cast (w/gs)))
		for (j in  0...(cast (h/gs)))
		{
			var px : Float32 = i * gs;
			px = px + Mathf.Frac(pan.x / gs) * gs;
			var py : Float32 = j * gs;
			py = py + Mathf.Frac(pan.y / gs) * gs;			
			g.moveTo(0.0, py);
			g.lineTo(w  , py);
			g.moveTo(px,0.0);
			g.lineTo(px,  h);
		}
		g.closePath();
		g.setLineWidth(1.0);
		g.setStrokeColor(1.0, 1.0, 1.0, 0.1);
		g.stroke();
		
		g.transform(1, 0, 0, 1, pan.x, pan.y);
	}
	
	private function OnContainerMouse(p_event : MouseEvent):Void
	{
		var t : Element = cast p_event.target;
		if (block) return;
		target = t;		
	}
	
	public function AddDot(p_x:Float32, p_y:Float32):Void
	{
		var d : DivElement = cast dot_template.cloneNode(true);
		d.id = "control-point";
		controls.appendChild(d);
		
		var cp : ControlPoint = new ControlPoint(d);
		cp.x = cast p_x;
		cp.y = cast p_y;
	}
	
	/**
	 * 
	 * @return
	 */
	override public function Load():Bool 
	{	
		Web.root = "http://www.haxor.xyz/resources/";
		
		return true;
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