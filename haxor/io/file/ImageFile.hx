package haxor.io.file;
import haxor.io.Buffer;

/**
 * Simple descriptor class for an image file.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ImageFile
{
	
	/**
	 * Image format.
	 */
	public var format : String;
	
	/**
	 * Data Buffer.
	 */
	public var data	  : Buffer;
	
	/**
	 * CTOR.
	 * @param	p_format
	 * @param	p_data
	 */
	public function new(p_format:String="",p_data:Buffer=null)
	{		
		format = p_format;
		data   = p_data == null ? new Buffer(0) : p_data;
	}
	
}