package haxor.graphics.texture;
import haxor.context.EngineContext;
import haxor.core.Enums.PixelFormat;
import haxor.core.Enums.TextureType;
import haxor.core.Enums.TextureWrap;
import haxor.io.FloatArray;
import haxor.math.Color;
import haxor.math.Random;

/**
 * Class that represents a 2D texture.
 * @author Eduardo Pons
 */
class Texture2D extends Texture
{	
	/**
	 * Texture with random numbers.
	 */
	static public var random(get_random, never):Texture2D;
	static private function get_random():Texture2D
	{
		if (m_random != null) return m_random;		
		m_random = new Texture2D(128, 128, PixelFormat.Float4);
		m_random.guid = "f5b6613296264289886170b6";		
		m_random.name = "Random";		
		m_random.wrap = TextureWrap.RepeatX | TextureWrap.RepeatY | TextureWrap.RepeatZ;
		var f32 : FloatArray = cast m_random.data.buffer;
		for (i in 0...f32.length) f32.Set(i, Math.random());
		m_random.Upload(10);
		return m_random;
	}
	static private var m_random : Texture2D;
	
	/**
	 * Template texture with a single white pixel.
	 */
	static public var white(get_white, never):Texture2D;
	static private function get_white():Texture2D
	{
		if (m_white != null) return m_white;
		m_white = new Texture2D(1, 1, PixelFormat.RGB8);
		m_white.guid = "426a40e6e13240aba5bfced6";
		m_white.name = "White";
		m_white.data.Fill(Color.white);
		m_white.Apply();
		return m_white;
	}
	static private var m_white : Texture2D;
	
	/**
	 * Template texture with a single black pixel.
	 */
	static public var black(get_black, never):Texture2D;
	static private function get_black():Texture2D
	{
		if (m_black != null) return m_black;
		m_black = new Texture2D(1, 1, PixelFormat.RGB8);
		m_black.guid = "025017810c2e4299ba074cc9";
		m_black.name = "Black";
		m_black.data.Fill(Color.black);
		m_black.Apply();
		return m_black;
	}
	static private var m_black : Texture2D;
	
	/**
	 * Template texture with a single black pixel.
	 */
	static public var gray50(get_gray50, never):Texture2D;
	static private function get_gray50():Texture2D
	{
		if (m_gray50 != null) return m_gray50;
		m_gray50 = new Texture2D(1, 1, PixelFormat.RGB8);
		m_gray50.guid = "964313fee53d4e1eab9fb43b";
		m_gray50.name = "Gray50";
		m_gray50.data.Fill(Color.gray50);
		m_gray50.Apply();
		return m_gray50;
	}
	static private var m_gray50 : Texture2D;
	
	/**
	 * Template texture with a single black pixel.
	 */
	static public var gray25(get_gray25, never):Texture2D;
	static private function get_gray25():Texture2D
	{
		if (m_gray25 != null) return m_gray25;
		m_gray25 = new Texture2D(1, 1, PixelFormat.RGB8);
		m_gray25.guid = "5dccf7a1f560400dbe301243";				
		m_gray25.name = "Gray25";
		m_gray25.data.Fill(Color.gray25);
		m_gray25.Apply();
		return m_gray25;
	}
	static private var m_gray25 : Texture2D;
	
	
	
	/**
	 * Template texture with a single red pixel.
	 */
	static public var red(get_red, never):Texture2D;
	static private function get_red():Texture2D
	{
		if (m_red != null) return m_red;
		m_red = new Texture2D(1, 1, PixelFormat.RGB8);
		m_red.guid = "9073897a35f14fc3afeaef7a";
		m_red.name = "Red";		
		m_red.data.Fill(Color.red);
		m_red.Apply();
		return m_red;
	}
	static private var m_red : Texture2D;
	
	/**
	 * Template texture with a single green pixel.
	 */
	static public var green(get_green, never):Texture2D;
	static private function get_green():Texture2D
	{
		if (m_green != null) return m_green;
		m_green = new Texture2D(1, 1, PixelFormat.RGB8);
		m_green.guid = "9a31dce6b7964314b9673d56";
		m_green.name = "Green";
		m_green.data.Fill(Color.green);
		m_green.Apply();
		return m_green;
	}
	static private var m_green : Texture2D;
	
	/**
	 * Creates a new Texture2D from a bitmap reference.
	 * The pixels are all set but the user must choose if the texture will automatically applied or wait for the best moment to Apply or Upload.
	 * @param	p_bitmap
	 * @return
	 */
	static public function FromBitmap(p_bitmap : Bitmap,p_apply:Bool=true):Texture2D
	{
		var t : Texture2D = new Texture2D(0, 0, p_bitmap.format);
		t.m_data 	= p_bitmap;
		t.m_width 	= p_bitmap.width;
		t.m_height 	= p_bitmap.height;
		EngineContext.texture.Create(t);		
		t.Apply();
		return t;
	}
	
	/**
	 * Reference to the bitmap which contains the pixels for this Texture.
	 */
	@serialize
	public var data(get_data, null):Bitmap;
	private inline function get_data():Bitmap { return m_data; }
	private inline function set_data(v:Bitmap):Bitmap 
	{ 
		m_data   = v;
		m_width  = v.width;
		m_height = v.height;
		EngineContext.texture.UpdateParameters(this); 
		Apply();
		return m_data; 		
	}
	private var m_data : Bitmap;
	
	/**
	 * Returns the enum for this texture type.
	 * @return
	 */
	override function get_type():TextureType { return TextureType.Texture2D; }
	
	/**
	 * 
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : Int)
	{
		super();
		m_format = p_format;
		m_width  = p_width;
		m_height = p_height;
		if (p_width <= 0)  return;
		if (p_height <= 0) return;
		m_data 	 = new Bitmap(p_width, p_height, p_format);		
		EngineContext.texture.Create(this);
	}
	
	/**
	 * Sends the pixels of this texture in async mode.
	 * It is possible to tell the speed of the upload by the number of steps before finishing the task.
	 * @param	p_on_complete
	 */
	public function Upload(p_steps : Int=200,p_on_complete:Void->Void=null):Void
	{
		EngineContext.texture.UploadTexture(this,0,0,width,height, p_steps,p_on_complete);
	}
	
}