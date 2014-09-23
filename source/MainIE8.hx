package ;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.dom.LayoutFlag;
import haxor.dom.Sprite;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.AABB2;
import haxor.thread.Activity;


#if html
import haxor.dom.Container;
#end




/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class MainIE8 extends Application implements IUpdateable implements IRenderable
{
	
	static public function main():Void 
	{ 
		EntryPoint.Initialize();
	}
	
	#if html
	var field : js.html.DivElement;
	#end
	
	override public function Load():Bool 
	{			
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
		var c : Container = new Container("content");
		
		c.element.style.background = "#f00";
		c.stage.AddChild(c);
		c.width  = 200;
		c.height = 200;
		
		c.px = 100;
		c.py = 100;
		
		c.x = 350;
		c.y = 150;
		
		var logo : Sprite = new Sprite("assets/img/lamp.jpg");
		
		c.AddChild(logo);
		
		logo.layout.FitSize();
		logo.layout.margin = logo.layout.margin.Set(15, 15, 15, 15);
		
		logo.layout.flag |= LayoutFlag.PivotXY | LayoutFlag.PositionXY;		
		logo.layout.x  = 0.5;		
		logo.layout.y  = 0.5;
		logo.layout.px = 0.5;
		logo.layout.py = 0.5;
		
		Activity.Run(function(t:Float):Bool
		{
			if (Input.Down(KeyCode.Space)) logo.pattern = !logo.pattern;
			c.rotation = t * 60;
			return true;
		});
		
		#if html
		field = cast js.Browser.document.getElementById("field");
		#end		
	}
	
	var log : String = "";
	
	public function OnUpdate():Void
	{	
		
		#if html
		if (field != null) field.innerText = log;
		#end				
	}
	
	public function OnRender():Void
	{	
		
		
	}
	
	
}