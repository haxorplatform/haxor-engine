package haxor.graphics;
import haxor.io.Buffer;
import haxor.platform.Types.ArrayBuffer;

/**
 * Class that describes a generic converter from a RAW byte buffer containing some image file to a Bitmap instance containing RAW pixel data.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ImageReader
{

	/**
	 * Base class must not be instantiated.
	 */
	function new() { }
	
	/**
	 * Reads the buffer asynchronously and invokes the callback after finish. If needed the image can flipped in the Y axis to match some GL libraries standard.
	 * @param	p_buffer
	 * @param	p_on_complete
	 * @param	p_flip_y
	 */
	public function ReadAsync(p_buffer : ArrayBuffer, p_on_complete : Bitmap->Void, p_flip_y:Bool = false):Void { }
	
	/**
	 * Reads the buffer synchronously and returns the generated Bitmap. If needed the image can flipped in the Y axis to match some GL libraries standard.
	 * @param	p_buffer
	 * @param	p_flip_y
	 * @return
	 */
	public function Read(p_buffer : ArrayBuffer,p_flip_y:Bool = false):Bitmap { } 
	
}