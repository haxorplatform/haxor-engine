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
		
		
		var img : Sprite = new Sprite("http://noticiajato.com.br/wp-content/uploads/2014/01/google-fiber-rabbit.jpg");
		img.stage.AddChild(img);
		img.width  = 256;
		img.height = 256;
		
		img.x = 50;
		img.y = 50;
		
		img.layout.flag = LayoutFlag.PositionXY;
		img.layout.x = 0.5;
		img.layout.y = 0.5;
		
		Activity.Run(function(t:Float):Bool
		{
			img.rotation = t * 90;
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