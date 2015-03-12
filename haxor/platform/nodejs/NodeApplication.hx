#if nodejs
package haxor.platform.nodejs;
import haxor.core.BaseApplication;
import haxor.platform.Types.Float32;



/**
 * Class that defines a base Application for NodeJS projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class NodeApplication extends BaseApplication
{
	
	/**
	 * Overrides and returns HTML
	 * @return
	 */
	override function get_platform():Platform { return Platform.NodeJS; }
		
	/**
	 * Constructor.
	 * @param	p_tag [application] element found on the HTML source.
	 */
	private function new() 
	{
		super();						
	}
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerWidth():Float32{ return 0; }
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerHeight():Float32 { return 0; }
	
	
}
#end