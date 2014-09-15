package ;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.input.Input;
import haxor.input.KeyCode;


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
		
		c.stage.AddChild(c);
		c.width = 200;
		c.height = 200;
		
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