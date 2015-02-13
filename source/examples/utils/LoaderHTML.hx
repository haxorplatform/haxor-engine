package examples.utils;


import haxe.Timer;

#if html
import js.Browser;
import js.html.DivElement;
import js.html.SpanElement;
#end

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class LoaderHTML
{
	#if html
	private var m_container : DivElement;	
	private var m_fill : SpanElement;
	#end
	
	public function new() 
	{
		#if html
		m_container = cast Browser.document.getElementById("loader");
		m_fill 	    = cast Browser.document.getElementById("progress");
		m_fill.style.transition = "width 1.0s ease-out";
		#end
	}
	
	/**
	 * Hides and remove the loader.
	 */
	public function Complete():Void
	{
		#if html
		Timer.delay(function():Void
		{
			m_container.style.opacity = "0.0";
			Timer.delay(function():Void { m_container.remove(); }, 600);
		},1500);
		#end
	}
	
	
	/**
	 * Sets the progress ratio of the loader.
	 * @param	p_r
	 */
	public function SetProgress(p_r : Float):Void
	{
		#if html
		m_fill.style.width = Math.floor(p_r * 100) + "%";
		#end
	}
	
}