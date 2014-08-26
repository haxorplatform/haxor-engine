/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.core;
import haxor.graphics.Graphics;
import js.html.Audio;
import js.html.AudioElement;
import js.html.Float32Array;
import js.html.Image;
import js.html.ImageData;
import js.html.MediaElement;
import js.html.svg.AnimatedTransformList;
import js.html.VideoElement;
import js.html.XMLHttpRequest;
import haxor.graphics.Material;
import haxor.graphics.Shader;
import haxor.importer.ColladaFile;
import haxor.importer.MaterialFile;
import haxor.media.Sound;
import haxor.net.Web;
import haxor.texture.KernelTexture;
import haxor.texture.Texture;
import haxor.texture.Texture.TextureWrap;
import haxor.texture.Texture2D;
import haxor.texture.TextureCube;
import haxor.texture.TextureHTML;
import haxor.ui.UISkin;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Asset
{
	static private var m_database : Map<String,Dynamic> = new Map<String,Dynamic>();
	
	static private var m_url 	  : Map<String,Dynamic> = new Map<String,String>();
	
	static private var m_progress : Map<String,Float> = new Map<String,Float>();
	
	static private var m_materials : Array<String> = [];
	
	static public var dependenceCount(get_dependenceCount, never):Int;
	static private function get_dependenceCount():Int { return m_dependences.length; }
	
	static private var m_dependences : Array<String> = [];
	
	static private var m_isdependence : Map<String,Bool> = new Map<String,Bool>();
	
	static private var m_dependenceEnabled : Bool = false;
	
	static private var m_dependenceProgress(get_m_dependenceProgress, never) : Float;
	static private function get_m_dependenceProgress():Float 
	{
		if (m_dependences.length <= 0) return 1.0;
		var p : Float = 0;
		var t : Float = m_dependences.length;
		for (i in 0...m_dependences.length)
		{
			p += GetProgress(m_dependences[i]);
		}
		
		return p / t;
	}
	
	/**
	 * 
	 * @param	p_id
	 * @return
	 */
	static public function Get(p_id : String) : Dynamic { return m_database.exists(p_id) ? (m_database.get(p_id)) : null; }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_asset
	 * @return
	 */
	static public function Add(p_id : String,p_asset : Dynamic) : Void { m_database.set(p_id,p_asset); }
	
	/**
	 * 
	 * @param	p_id
	 * @return
	 */
	static public function GetURL(p_id : String) :String { return m_url.exists(p_id) ? m_url.get(p_id) : ""; }
	
	/**
	 * 
	 * @param	p_id
	 * @return
	 */
	static public function GetProgress(p_id : String) : Float { return m_progress.exists(p_id) ? m_progress.get(p_id) : 0.0; }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadShader(p_id : String, p_url : String) : XMLHttpRequest
	{	
		AssetInit(p_id,p_url);		
		return Web.LoadShader(p_url, function(d : Shader, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadXML(p_id : String, p_url : String) : XMLHttpRequest
	{	
		AssetInit(p_id,p_url);		
		return Web.LoadXML(p_url, function(d : Xml, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadJSON(p_id : String, p_url : String) : XMLHttpRequest
	{	
		AssetInit(p_id,p_url);		
		return Web.LoadJSON(p_url, function(d : Dynamic, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function Load(p_id : String, p_url : String) : XMLHttpRequest
	{	
		AssetInit(p_id,p_url);		
		return Web.Load(p_url, function(d : String, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadTextureHTML(p_id : String, p_url : String) : Image
	{		
		AssetInit(p_id, p_url);
		return Web.LoadTextureHTML(p_url, function(d : TextureHTML, p : Float):Void {	AssetProgress(p_id, d, p); } );
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadTexture2D(p_id : String, p_url : String) : Image { AssetInit(p_id, p_url); return Web.LoadTexture2D(p_url, function(d : Texture2D, p : Float):Void { AssetProgress(p_id, d, p); }); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadImage(p_id : String, p_url : String) : Image { AssetInit(p_id, p_url); return Web.LoadImage(p_url, function(d : Image, p : Float):Void { AssetProgress(p_id, d, p); } ); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadAudio(p_id : String, p_url : String) : MediaElement { AssetInit(p_id, p_url); return Web.LoadAudio(p_url, function(d : MediaElement, p : Float):Void { AssetProgress(p_id, d, p); } ); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadSound(p_id : String, p_url : String) : MediaElement { AssetInit(p_id, p_url); return Web.LoadSound(p_url, function(d : Sound, p : Float):Void { AssetProgress(p_id, d, p); } ); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadImageData(p_id : String, p_url : String) : Image { AssetInit(p_id, p_url); return Web.LoadImageData(p_url, function(d : ImageData, p : Float):Void { AssetProgress(p_id, d, p); }); }
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadTextureCube(p_id : String, p_url : String) : Image
	{			
		AssetInit(p_id, p_url); 
		return Web.LoadTexture2D(p_url, function(d : Texture2D, p : Float):Void
		{		
			var c : TextureCube = p < 1.0 ? null : TextureCube.FromCrossTexture(d);
			if (p >= 1.0) Resource.Destroy(d);
			AssetProgress(p_id, c, p);
		});
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadUISkin(p_id : String, p_url : String):XMLHttpRequest
	{
		AssetInit(p_id, p_url); 
		return Web.LoadXML(p_url, function(d : Xml, p : Float):Void
		{
			if (p < 1.0) AssetProgress(p_id, null, p);
			else
			{
				BeginDependences();
				var skn : UISkin = new UISkin(d);
				EndDependences();
				AssetProgress(p_id, skn, p);
			}
		});
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadVideoHTML(p_id : String, p_url : String) : VideoElement
	{		
		AssetInit(p_id, p_url);
		return Web.LoadVideoHTML(p_url, function(d : TextureHTML, p : Float):Void { AssetProgress(p_id, d, p);	});
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadCollada(p_id : String, p_url : String) : XMLHttpRequest
	{		
		AssetInit(p_id, p_url); 
		return Web.LoadCollada(p_url, function(d : ColladaFile, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	/**
	 * 
	 * @param	p_id
	 * @param	p_url
	 */
	static public function LoadMaterial(p_id : String, p_url : String) : XMLHttpRequest
	{		
		AssetInit(p_id, p_url);
		m_materials.push(p_id);
		return Web.LoadMaterial(p_url, function(d : MaterialFile, p : Float):Void { AssetProgress(p_id, d, p); });
	}
	
	static private function AssetInit(p_id:String,p_url:String):Void
	{
		if (m_dependenceEnabled)
		{
			//trace("Asset> Adding dependence [" + p_id + "] url[" + p_url + "]");
			m_dependences.push(p_id);
		}
		m_isdependence.set(p_id, m_dependenceEnabled);
		m_progress.set(p_id, 0);
		m_url.set(p_id, p_url);
	}
	
	static private function AssetProgress(p_id : String, p_asset : Dynamic, p_progress : Float):Void
	{
		var p : Float = p_progress >= 1.0 ? 1.0 : p_progress;
		m_progress.set(p_id, p);				
		if (p >= 1.0)
		{	
			m_database.set(p_id,p_asset);
		}
		
		if (m_isdependence.get(p_id))
		{
			var a : Application = Engine.application;
			
			if (a.loader != null)
			{
				a.loader.OnElementProgress(p_id, p);				
				a.loader.OnProgress(m_dependenceProgress);				
				if (p >= 1.0) a.loader.OnElementComplete(p_id);
			}
			a.OnDependenceProgress(p_id, p);
			a.OnProgress(m_dependenceProgress);
			if (p >= 1.0)a.OnDependenceLoad(p_id);
		}
	}
	
	static private function Create():Void
	{
		for (i in 0...m_materials.length)
		{
			var mf : MaterialFile = Get(m_materials[i]);
			if (mf == null) continue;
			Add(m_materials[i], mf.GetAsset());
		}
		
		if (Graphics.c3d != null)
		{
			var rf32 : Float32Array = new Float32Array(512 * 512 * 4);
			for (i in 0...rf32.length) rf32[i] = Math.random();
			var random_texture : KernelTexture = new KernelTexture(512, 512, TextureFormat.Float4);
			random_texture.wrap = TextureWrap.RepeatX | TextureWrap.RepeatY;
			random_texture.WriteRange(rf32);
			Add("haxor/texture/random", random_texture);
		}
	}
	
	static private function BeginDependences():Void { m_dependenceEnabled = true; Web.m_autoload = true; }
	
	static private function EndDependences():Void {	m_dependenceEnabled = false; Web.m_autoload = true;  }
}