package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.Enums.TextureFilter;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.math.Color;

/**
 * Class that describes a numeric data texture that can be used as input/output of pseudo-compute shaders.
 * @author Eduardo Pons
 */
class ComputeTexture extends Texture2D
{	
	
	/**
	 * Locks this texture uploading until the last one is free.
	 */
	private var m_lock : Bool;
	
	/**
	 * Flag that indicates if this texture has changes.
	 */
	private var m_dirty : Bool;
	
	/**
	 * Creates a new Compute texture with the informed dimensions and format.
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : PixelFormat) 
	{
		super(p_width,p_height,p_format);		
		minFilter = TextureFilter.Nearest;
		magFilter = TextureFilter.Nearest;
		m_lock = false;
		m_dirty = false;
	}
	
	/**
	 * Writes values in this texture.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_v0
	 * @param	p_v1
	 * @param	p_v2
	 * @param	p_v3
	 */
	public inline function Write(p_x : Int, p_y :Int, p_v0 : Dynamic = 0, p_v1 : Dynamic = 0, p_v2 : Dynamic = 0, p_v3 : Dynamic = 0):Void 
	{ 
		data.SetPixel(p_x, p_y, Color.temp.Set(p_v0, p_v1, p_v2, p_v3); 
		m_dirty = true;
		Refresh();
	}
	
	/**
	 * Writes a list of values in this texture.
	 * @param	p_values
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function WriteRange(p_values : Array<Float>,p_x:Int=0, p_y:Int=0, p_width:Int=-1, p_height:Int=-1):Void
	{
		var w : Int = p_width < 0 ? m_width : p_width;
		var h : Int = p_height < 0 ? m_height : p_height;
		data.SetRange(p_x, p_y, w, h, p_values);		
		Refresh();
		m_dirty = true;
	}
	
	private function Refresh():Void
	{
		if (m_lock) return;
		m_lock = true;
		Upload(10, OnUploadComplete);
	}
	
	/**
	 * Method called after the last upload is complete.
	 */
	private function OnUploadComplete():Void
	{
		m_lock = false;
		if (m_dirty) Refresh();
		m_dirty = false;
	}
	
}