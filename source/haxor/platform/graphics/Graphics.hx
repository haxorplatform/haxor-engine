package haxor.platform.graphics;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Graphics extends

#if html
WebGL
#end

#if android
AndroidGL
#end

#if windows
OpenGL
#end

{

	
	
}