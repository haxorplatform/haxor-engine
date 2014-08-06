package haxor.core;
import haxor.core.BaseApplication.EntryPoint;

#if html
import js.Browser;
import haxor.platform.html.HTMLApplication.ApplicationProtocol;
import haxor.platform.html.Entry;
#end

#if android
import haxor.platform.android.Entry;
#end

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Application extends

#if html
haxor.platform.html.HTMLApplication
#end

#if android
haxor.platform.android.AndroidApplication
#end

#if windows
haxor.platform.windows.WinApplication
#end

{
	
	
	
	
		
}