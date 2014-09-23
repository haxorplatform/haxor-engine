package ;
import haxe.Timer;
import haxor.core.Application;
import haxor.core.BaseApplication.EntryPoint;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Mathf;
import haxor.math.Random;
import haxor.net.Web;
import haxor.platform.Types.Float32;
import js.Browser;
import js.html.DivElement;
import js.html.DocumentFragment;
import js.html.Element;
import js.html.ParagraphElement;


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
	
	
	var field : DivElement;	
	var log : String = "";
	
	
	
	override public function Load():Bool 
	{			
		return true;
	}
	
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");	
		
	
		
		field = cast Browser.document.getElementById("field");
		
		
	}
	
	public function OnUpdate():Void
	{	
		if (pl == null) return;

		if (field != null) field.innerText = log;		
	}
	
	public function OnRender():Void
	{	
		
		
	}
	
	
}