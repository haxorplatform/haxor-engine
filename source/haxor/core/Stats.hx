package haxor.core;
import haxor.context.EngineContext;

/**
 * Class that holds execution information of the engine.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Stats
{
	/**
	 * Visible renderers.
	 */
	static public var visible : Int;
	
	/**
	 * Not visible renderers.
	 */
	static public var culled : Int;
	
	/**
	 * Triangles being rendered.
	 */
	static public var triangles : Int;
	
	/**
	 * Total of renderers in the current frame.
	 */
	static public var total(get_total, null) : Int;
	static private function get_total():Int { return visible + culled; }

	/**
	 * Number of created renderers.
	 */
	static public var renderers : Int;
	
	static private function Initialize():Void
	{
		visible   = 0;
		culled 	  = 0;
		triangles = 0;
		renderers = 0;
	}
	
	static private function BeginRender():Void 
	{ 
		visible   = 0;
		culled 	  = 0;
		triangles = 0;		
		renderers = EngineContext.renderer.rid.next;
	}
	
}
