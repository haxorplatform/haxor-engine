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
import haxor.core.Enums.AnimationWrap;
import haxor.core.Enums.ClearFlag;
import haxor.core.Enums.InputState;
import haxor.core.Enums.ShaderFeature;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Resource;
import haxor.graphics.Gizmo;
import haxor.graphics.material.Material;
import haxor.graphics.material.shader.FlexShader;
import haxor.graphics.mesh.Model;
import haxor.graphics.Screen;
import haxor.graphics.texture.TextureCube;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.AABB2;
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
	private function set_x(v:Float32):Float32 { m_x = v;  return v; }
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
	
	public function Update(p_pan:Vector2):Void
	{
		element.style.left = Mathf.Floor(m_x + p_pan.x) + "px";
		element.style.top = Mathf.Floor(m_y + p_pan.y) + "px";	
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
	public var drag : ControlPoint;
	
	public var dot_template : DivElement;
	
	public var pan : Vector2;
	
	public var points : Array<Array<ControlPoint>>;
	
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
			
		});
		
		curve = new Curve(3);
		
		panel 		= cast Browser.document.getElementById("panel");
		controls        = cast Browser.document.getElementById("controls");
		canvas 	  		= cast Browser.document.getElementById("graph");		
		dot_template    = cast Browser.document.getElementById("dot-template");		
		dot_template.style.display = "none";
		
		block = false;
		
		points = [[],[],[]];
		
		panel.addEventListener("mousedown", OnContainerMouse);
		Browser.window.onmouseup = OnContainerMouse;
		
		g = canvas.getContext2d();
		
		pan = new Vector2();
		pan.x = panel.clientWidth * 0.5;
		pan.y = panel.clientHeight * 0.5;
		
	}
	
	public function OnUpdate():Void
	{		
		if (g == null) return;
		var mp : Vector2 = Input.mouse.clone;
		mp.x -= pan.x;
		mp.y -= pan.y;
		block = false;
		
		if (target != null)
		{
			switch(target.id)
			{
				case "pan":
				
				if(Input.Pressed(KeyCode.ShiftKey))
				{	
					if (Input.Hit(KeyCode.Mouse0)) AddDot(mp.x, mp.y, 0);					
					if (Input.Hit(KeyCode.Mouse2)) AddDot(mp.x, mp.y, 1);
					if (Input.Hit(KeyCode.Mouse1)) AddDot(mp.x, mp.y, 2);
					
					
				}
				else
				if (Input.Pressed(KeyCode.Mouse0))
				{
					block = true;
					pan.x += Input.deltaMouse.x;
					pan.y += Input.deltaMouse.y;
				}
				
				case "control-point":
					if (drag != null)
					{
						drag.x = mp.x;
						drag.y = mp.y;
					}
				
				
			}
		}
		
	}
	
	public function OnRender():Void
	{
		if (curve == null) return;
		var w : Float32 = cast panel.clientWidth;
		var h : Float32 = cast panel.clientHeight;
		var hw : Float32 = w * 0.5;
		var hh : Float32 = h * 0.5;
		
		var tx : Float32 = 0.0;
		var ty : Float32 = 0.0;
		var gs : Float32 = 50.0;
		
		canvas.width  = cast w;
		canvas.height = cast h;
		
		g.transform(1, 0, 0, -1, 0, 0);
		g.translate(0.5, 0.5);
		
		g.setFillColor(0.2, 0.2, 0.2, 1.0);
		g.fillRect(0, 0, w, -h);
		
		var g_offx : Int = cast (Mathf.Frac(pan.x / gs) * gs);
		var g_offy : Int = cast (Mathf.Frac(pan.y / gs) * gs);
		
		g.setLineWidth(0.05);
		g.setStrokeColor(0.4, 0.4, 0.4, 1.0);		
		g.beginPath();				
		for (i in  0...(cast (w/gs)))
		for (j in  0...(cast (h/gs)))
		{
			var px : Float32 = i * gs;
			var py : Float32 = j * gs;			
			px = Mathf.Floor(px + g_offx);			
			py = Mathf.Floor(py + g_offy);			
			var ipx : Int = cast px;
			var ipy : Int = cast py;
			
			if (ipx > w) continue;
			if (ipy > h) continue;
			
			g.moveTo(0.0, -ipy);
			g.lineTo(w  , -ipy);
			g.moveTo(ipx,0.0);
			g.lineTo(ipx, -h);
		}
		g.closePath();		
		g.stroke();
		
		g.setLineWidth(2.0);
		g.setStrokeColor(1.0, 1.0, 1.0, 0.5);		
		g.beginPath();		
		g.moveTo(-w, -pan.y);
		g.lineTo( w, -pan.y);
		g.moveTo(pan.x, h);
		g.lineTo(pan.x,-h);		
		g.closePath();		
		g.stroke();
		
		tx += pan.x;
		ty += pan.y;
		
		tx = Mathf.Floor(tx);
		ty = Mathf.Floor(ty);
		g.transform(1, 0, 0, -1, tx, -ty);
		
		for (i in 0...points.length)
		{
			for (j in 0...points[i].length)
			{
				var cp :ControlPoint = points[i][j];
				cp.Update(pan);
				curve.Update(j, cp.x, cp.y, i);
			}
		}
		curve.Refresh();
		
		curve.SetWrap(AnimationWrap.Loop, AnimationWrap.Clamp, 1);
		curve.SetWrap(AnimationWrap.Oscilate, AnimationWrap.Oscilate, 2);
		
		PlotCurve(g, curve, 0, Color.red30);
		PlotCurve(g, curve, 1, Color.green30);
		PlotCurve(g, curve, 2, Color.blue30);
		
	}
	
	private function OnContainerMouse(p_event : MouseEvent):Void
	{		
		var t : Element = cast p_event.target;
		if (t == null) return;
		
		switch(p_event.type)
		{
			case "mousedown":
				if (block) return;				
				target = t;				
				if (t.id == "control-point")
				{
					for (i in 0...points.length)
					for (j in 0...points[i].length) if (points[i][j].element == t) drag = points[i][j];
				}
			case "mouseup":
				drag = null;
		}
		
	}
	
	public function AddDot(p_x:Float32, p_y:Float32,p_attrib:Int):Void
	{
		var d : DivElement = cast dot_template.cloneNode(true);
		d.id = "control-point";
		d.style.display = "block";
		
		controls.appendChild(d);
		
		var cp : ControlPoint = new ControlPoint(d);
		cp.x = cast p_x;
		cp.y = cast p_y;
		points[p_attrib].push(cp);
		cp.Update(pan);		
		curve.Add(cp.x, cp.y,p_attrib);		
	}
	
	private function PlotCurve(ctx:CanvasRenderingContext2D,c:Curve, a:Int, cl:Color):Void
	{
		if (c == null) return;
		if (c.keys[a].length <= 1) return;
		var x0 : Float32 = c.keys[a][0].key;
		var x1 : Float32 = c.keys[a][c.keys[a].length-1].key;
		var d0 : Float32 = x0 - Screen.width*0.5;
		var d1 : Float32 = x1 + Screen.width*0.5;
		var bb : AABB2 = c.GetBounds(a);
		ctx.setLineWidth(2.0);		
		var q : Int = 500;
		for (i in 1...q)
		{
			var r0 : Float32 = (i - 1) / (q-1);
			var r1 : Float32 = (i) / (q-1);
			var k0 : Float32 = Mathf.Lerp(d0, d1, r0);
			var k1 : Float32 = Mathf.Lerp(d0, d1, r1);
		
			ctx.setStrokeColor(cl.r, cl.g, cl.b, 0.8);			
			if (k0 < x0) ctx.setStrokeColor(cl.r, cl.g, cl.b, 0.4);
			if (k1 > x1) ctx.setStrokeColor(cl.r, cl.g, cl.b, 0.4);
			
			if(k0 <= x1) if(k1 >= x1) continue;
			if(k0 <= x0) if(k1 >= x0) continue;

			
			ctx.beginPath();
			
			
			
			var v0 : Float32 = c.Sample(k0,a);
			var v1 : Float32 = c.Sample(k1,a);
			ctx.moveTo(k0,v0);
			ctx.lineTo(k1, v1);
			
			ctx.closePath();
			ctx.stroke();
		}		
		
		
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