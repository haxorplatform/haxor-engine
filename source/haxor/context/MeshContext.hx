package haxor.context;
import haxor.platform.graphics.GL;
import haxor.platform.Types.MeshBufferId;

/**
 * Class that handles Mesh related internal structures.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MeshContext
{
	
	/**
	 * Unique attribute ids.
	 */
	public var aid : Int;
	
	/**
	 * List of created buffers.
	 */
	public var buffers : Array<MeshBufferId>;

	/**
	 * Creates the Mesh context to handle internal structures.
	 */
	public function new() 
	{
		aid = 0;
		buffers = [];		
		for (i in 0...1000) buffers.push(GL.NULL_ID);
		
	}
	
}