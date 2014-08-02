package ;


import haxor.core.Application;
import haxor.core.Console;
import haxor.core.IRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;




/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class Main extends Application implements IUpdateable implements IRenderable
{
	
	static function main() 
	{
		#if windows
		haxor.platform.windows.Entry.Initialize();
		#end
	}
	
	
	override public function Load():Bool 
	{	
		return true;
	}
	
	override public function Initialize():Void 
	{
		Console.Log("Initialize!");
		
	}
	
	
	
	public function OnUpdate():Void
	{		
		
	}
	
	public function OnRender():Void
	{
		
		Console.Log("ups["+Time.ups+"] fps["+Time.fps+"]");
		
		graphics.Clear(1.0, 0.0, 1.0);
	}
	
	
}