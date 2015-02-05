package haxor.core;
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.core.Resource;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.texture.Texture2D;
import haxor.io.file.ColladaFile;
import haxor.io.file.MaterialFile;
import haxor.net.Web;
import haxor.platform.Types.Float32;

/**
 * Class that handles Asset operation and access.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Asset
{
	/**
	 * Database with assets to be stored.
	 */
	static private var m_database : Map<String,Dynamic> = new Map<String,Dynamic>();
	
	/**
	 * Database o loading progress.
	 */
	static private var m_load_progress : Map<String,Float32> = new Map<String,Float32>();
	
	/**
	 * 
	 * @param	get_progress
	 * @param	never
	 * @return
	 */
	static public var progress(get_progress, never):Float32;
	static private function get_progress():Float32	
	{
		var l : Float32 = 0.0;
		var t : Float32 = 0.0;
		var it : Iterator<String> = m_load_progress.keys();
		while (it.hasNext())
		{
			var k : String = it.next();
			l += m_load_progress.exists(k) ? m_load_progress.get(k) : 0.0;
			t += 1.0;
		}
		return t <= 0.0 ? 0.0 :(l / t);
	}
	
	/**
	 * Retrieves a Resource from the global database.
	 * @param	p_id
	 * @return
	 */
	static public function Get(p_id : String) : Dynamic { return m_database.exists(p_id) ? (m_database.get(p_id)) : null; }
	
	/**
	 * Removes an entry from the global database.
	 * @param	p_id
	 * @return
	 */
	static public function Remove(p_id:String):Dynamic { if (m_database.exists(p_id)) { var a : Dynamic = m_database.get(p_id);	m_database.remove(p_id); return a; } return null; }
	
	/**
	 * Adds a Resource into the global database.
	 * @param	p_id
	 * @param	p_asset
	 * @return
	 */
	static public function Add(p_id : String, p_asset : Dynamic) : Void { m_database.set(p_id, p_asset); if (Std.is(p_asset, Resource)) { cast(p_asset, Resource).__db = p_id; } }

	/**
	 * Loads the texture from the web and adds its reference to the global database.
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadTexture2D(p_id : String, p_url : String) : Void 
	{
		m_load_progress.set(p_id, 0.0);
		Web.LoadTexture2D(p_url, true, function(d : Texture2D, p : Float32):Void { UpdateProgress(p_id, p, d);   } ); 
	}
	
	/**
	 * Loads a collada model from the web and adds its reference to the global databse.
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadCollada(p_id : String, p_url : String) : Void { Web.LoadCollada(p_url, function(d : ColladaFile, p : Float32):Void { UpdateProgress(p_id, p, d); } ); }
	
	/**
	 * Loads a shader file from the web and adds its reference to the global databse.
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadShader(p_id : String, p_url : String) : Void { Web.LoadShader(p_url, function(d : Shader, p : Float32):Void { UpdateProgress(p_id, p, d); }  ); }
	
	/**
	 * Loads a material XML file from the web and adds the generated material reference to the global databse.
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadMaterial(p_id : String, p_url : String) : Void { Web.LoadMaterial(p_url, function(d : MaterialFile, p : Float32):Void { UpdateProgress(p_id, p, d); } ); }
	
	/**
	 * Duplicates the Resource (only available for Materials for now)
	 * @param	p_target
	 * @return
	 */
	static public function Instantiate(p_target : Resource):Dynamic { return p_target.Clone(); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_progress
	 * @param	p_asset
	 */
	static private function UpdateProgress(p_id:String, p_progress : Float32, p_asset : Dynamic):Void
	{
		var app : BaseApplication = BaseApplication.m_instance;		
		
		m_load_progress.set(p_id, p_progress);
		
		app.OnLoadProgress(p_id, p_progress);
		if (p_progress >= 1.0)
		{
			Asset.Add(p_id, p_asset);
			app.OnLoadComplete(p_id, p_asset);
			if (progress >= 1.0)
			{
				var kl : Iterator<String> = m_database.keys();
				while (kl.hasNext())
				{
					var aik : String = kl.next();
					var mf : MaterialFile = cast m_database.get(aik);
					if (Std.is(mf, MaterialFile)) Asset.Add(aik, mf.asset);
				}
				BaseApplication.m_instance.LoadComplete();
			}
		}
	}
	
}