package haxor.io.file;
import haxor.core.Resource;
import haxor.graphics.texture.Texture2D;
import haxor.platform.Types.Float32;
import haxor.io.file.AssetJson;

/**
 * Base class that describes an Asset in the Editor context.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AssetFile extends Resource
{
	/**
	 * Getter for the parsed asset after conversion from File data to Haxor's internal format.
	 */
	public var asset(get_asset, null):Dynamic;
	private function get_asset():Dynamic { return null; }
	
	/**
	 * Returns a list of images files if any.
	 */
	public var images(get, never):Array<ImageFile>;
	private function get_images() : Array<ImageFile> { return []; }
	
	/**
	 * Creates a new AssetFile class.
	 * @param	p_name
	 */
	public function new(p_name : String) 
	{	
		super(p_name);		
	}
	
	/**
	 * Auxiliar method to convert a string with separator in an Array<Float32>
	 * @param	v
	 * @param	sep
	 * @return
	 */
	private function stof32a(v : String,sep:String=" ") : Array<Float32>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(sep);
		var a : Array<Float32> = [];
		for (i in 0...l.length) a.push(Std.parseFloat(l[i]));
		return a;
	}
	
	/**
	 * Auxiliar method to convert a string with separator in an Array<Int>
	 * @param	v
	 * @param	sep
	 * @return
	 */
	private function stoi16a(v : String,sep:String=" ") : Array<Int>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(sep);		
		var a : Array<Int> = [];
		for (i in 0...l.length) a.push(Std.parseInt(l[i]));
		return a;
	}
	
	/**
	 * Auxiliar method to convert a string with separator in an Array<Array<Int>>, meaning an Array to N-Tuples.
	 * Ex: '0 1 2 3 4 5 6' would output [[0,1,2],[3,4,5]] using stoi16ta(str,3," ").
	 * @param	v
	 * @param	sep
	 * @return
	 */
	private function stoi16ta(v : String,s:Int,sep:String=" ") : Array< Array<Int> >
	{		
		var l  : Array<String>  = StringTools.trim(StringTools.replace(v, "\n", " ")).split(sep);
		var tl : String 		= "";
		var a : Array< Array<Int> > 		= [];
		var bf : Array<Int>;
		var k :Int = 0;
		
		while(k < l.length)
		{			
			bf = [];
			for (j in 0...s) bf.push(Std.parseInt(l[k++]));
			a.push(bf);
		}
		return a;
	}
	
	private function assert(v:Dynamic, d:Dynamic):Dynamic { return v == null ? d : v; }
	
	
}