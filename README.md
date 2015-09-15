![](https://dl.dropboxusercontent.com/u/20655747/haxor/img/github-splash.png)

## Setup  

* Install Haxe `3.2.0` http://haxe.org/download/version/3.2.0-rc.2/.
* Git install using `haxelib` command.
 * `haxelib git haxor https://github.com/haxorplatform/haxor-engine.git 1.0`
* Link the `haxor` library in `Flashdevelop` or command line `haxe` compiler.
 
## Usage  
While we are still doing some documentation, the most basic program should be like this:

```haxe
import haxor.core.Application;
import haxor.core.Console;
import haxor.platform.html.Entry;

class MainApp extends Application
{

 	//Entry Point
 	static function main():Void 
 	{
 		Browser.window.onload = function()
 		{			
 		  //<div id="haxor-content"></div>
 		  Entry.Create("MainApp", "haxor-content", "haxor-content", "app-name", 4);
 		};		
 	}
	
 	//Init.
 	override public function Initialize():Void 
 	{
 	  Console.Log("Hello World");
 	}
	
	}
```
 
## Build/Run

### HTML
* Create a `index.html`file with the container `<div id='haxor-content'>`.
* Build your app
  * `haxe -lib haxor -js path/to/app.js -D html -D js-es5 -D js-flatten -main pack.to.MainApp`
* Run your page and check the console for Haxor's initialization procedures.

### Android  
TBD

### Windows  
TBD

### iOS  
TBD

## Flags/Caveats

### Windows  
 * `-subsystem: console` enables cmdline.
 * `-D HXCPP_FLOAT32` uses `float` instead of `double`

## Dependencies

### Windows / C++
 * `hxcpp`
 * `ndll/Windows/` folder in hxssl
 * `glew32.lib`
 * `glew32.dll`
 * `bin` folder in hxcpp
