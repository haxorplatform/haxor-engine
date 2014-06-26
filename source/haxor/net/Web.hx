/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net;
import js.Browser;
import js.html.Audio;
import js.html.AudioElement;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.CSSStyleDeclaration;
import js.html.Event;
import js.html.Image;
import js.html.ImageData;
import js.html.MediaElement;
import js.html.Uint8Array;
import js.html.VideoElement;
import js.html.XMLHttpRequest;
import js.html.XMLHttpRequestProgressEvent;
import haxor.core.Application;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.JSON;
import haxor.graphics.Material;
import haxor.graphics.Shader;
import haxor.importer.ColladaFile;
import haxor.importer.MaterialFile;
import haxor.media.Sound;
import haxor.texture.Texture;
import haxor.texture.Texture2D;
import haxor.texture.TextureCube;
import haxor.texture.TextureHTML;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Web
{
	static var m_autoload : Bool = true;
	
	/**
	 * 
	 */
	static public var root : String = "";
	
	static private function InternalLoad(p_url:String, p_binary:Bool):XMLHttpRequest
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var req : XMLHttpRequest = new XMLHttpRequest();		
		if (req.withCredentials) req.withCredentials = false;
		if (req.overrideMimeType != null) { req.overrideMimeType(p_binary ? "application/octet-stream" : "text/plain"); }
		//req.responseType = p_binary ? "arraybuffer" : "";
		req.open("get", p_url, true);
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String -> Float -> Void):XMLHttpRequest
	{	
		//if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		
		var req : XMLHttpRequest = InternalLoad(p_url, false);
		
		req.onprogress = function(e : XMLHttpRequestProgressEvent)
		{
			var f:Float = e.total<=0 ? 0 : (e.loaded / (e.total+5));
			p_callback(null, f);
		};
		req.onload = function(e : XMLHttpRequestProgressEvent)
		{			
			p_callback(req.responseText,1.0);
		};
		req.onerror = function(e:XMLHttpRequestProgressEvent)
		{
			//Console.LogError("Web> Failed to load ["+p_url+"]");
			p_callback(null,1.0);
		};		
		
		//if(req.overrideMimeType != null) req.overrideMimeType("text/plain");
		//req.open("get", p_url, true);		
		if(m_autoload) req.send();
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadBinary(p_url:String, p_callback : Uint8Array -> Float -> Void):XMLHttpRequest
	{
		var req : XMLHttpRequest = InternalLoad(p_url, true);
		
		req.onprogress = function(e : XMLHttpRequestProgressEvent)
		{
			var f:Float = e.total<=0 ? 0 : (e.loaded / (e.total+5));
			p_callback(null, f);
		};
		req.onload = function(e : XMLHttpRequestProgressEvent)
		{			
			var a : Uint8Array = req.response == null ? null : (new Uint8Array(req.response));
			p_callback(a,1.0);
		};
		req.onerror = function(e:XMLHttpRequestProgressEvent)
		{
			//Console.LogError("Web> Failed to load ["+p_url+"]");
			p_callback(null,1.0);
		};		
		
		//if(req.overrideMimeType != null) req.overrideMimeType("text/plain");
		//req.open("get", p_url, true);		
		if(m_autoload) req.send();
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadXML(p_url:String, p_callback : Xml -> Float -> Void) : XMLHttpRequest
	{
		var res : Xml;
		var req : XMLHttpRequest;
		req = Load(p_url, function(d : String,p : Float)
		{
			res = p >= 1.0 ? (d == null ? null : Xml.parse(d)) : null;
			p_callback(res,p);
		});		
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadCollada(p_url:String, p_callback : ColladaFile -> Float -> Void) : XMLHttpRequest
	{
		var res : ColladaFile;
		var req : XMLHttpRequest;
		req = Load(p_url, function(d : String, p : Float):Void
		{			
			res = p >= 1.0 ? (d == null ? null : new ColladaFile(d)) : null;
			p_callback(res, p);
		});
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadMaterial(p_url:String, p_callback : MaterialFile -> Float -> Void) : XMLHttpRequest
	{
		var res : MaterialFile;
		var req : XMLHttpRequest;
		req = Load(p_url, function(d : String, p : Float):Void
		{			
			res = p >= 1.0 ? (d == null ? null : new MaterialFile(d)) : null;
			p_callback(res, p);
		});
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadJSON(p_url:String, p_callback : Dynamic -> Float -> Void) : XMLHttpRequest
	{
		var res : Xml;
		var req : XMLHttpRequest;
		req = Load(p_url, function(d : String,p : Float)
		{
			res = p >= 1.0 ? (d == null ? null : JSON.FromJSON(d)) : null;
			p_callback(res,p);
		});						
		return req;
	}
	
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */ 
	static public function LoadShader(p_url:String, p_callback : Shader -> Float -> Void) : XMLHttpRequest
	{
		var res : Shader;
		var req : XMLHttpRequest;
		req = Load(p_url, function(d : String,p : Float)
		{			
			res = p >= 1.0 ? (d == null ? Shader.error : new Shader(d)) : null;
			p_callback(res,p);
		});				
		return req;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadTextureHTML(p_url:String, p_callback : TextureHTML -> Float -> Void):Image
	{
		var img = new Image();	
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		
		img.onload = function (e : Event)
		{
			var tex : TextureHTML = new TextureHTML(img);			
			p_callback(tex,1);
		}		
		img.onerror = function(e : Event)
		{
			p_callback(null, 1.0);
		};
		img.crossOrigin = "anonymous";
		
		if (m_autoload)
		{
			img.src = p_url;
			p_callback(null, 0);
		}
		return img;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadVideoHTML(p_url:String, p_callback : TextureHTML -> Float -> Void):VideoElement
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		//trace("LoadVideoHTML> Loading from ["+p_url+"]");
		var vid : VideoElement = Browser.document.createVideoElement();
		vid.style.display = "none";		
		
		Browser.document.body.appendChild(vid);
		vid.onload = function (e : Event)
		{
			//trace("LoadVideoHTML> OnLoad");	
		}		
		vid.onerror = function(e : Event)
		{
			//trace("LoadVideoHTML> Error " + e);
			p_callback(null, 1.0);
		};		
		
		vid.addEventListener("canplaythrough", function(e : Event)
		{			
			if (vid == null) return;
			//trace("LoadVideoHTML> Can Play Video");
			vid.play();
			var tex : TextureHTML = new TextureHTML(vid);
			p_callback(tex, 1);				
			vid = null;
		}, true);		
		vid.autoplay = true;	
		vid.preload = "auto";	
		if (m_autoload)
		{
			vid.src = p_url;
			p_callback(null, 0);
		}
		return vid;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadTexture2D(p_url:String, p_callback : Texture2D -> Float -> Void):Image
	{
		p_callback(null, 0.0);
		return LoadImageData(p_url, function(d : ImageData, p : Float):Void
		{
			var cc : Int = p < 1.0 ? 0 : (cast (d.data.byteLength / (d.width * d.height)));
			var tex : Texture2D = p < 1.0 ? null : Texture2D.FromByteArray(d.width, d.height,cc == 4 ? TextureFormat.RGBA8 : TextureFormat.RGB8,cc, d.data,true);
			p_callback(tex, p);
		});				
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadAudio(p_url:String, p_callback : MediaElement -> Float -> Void):MediaElement
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var a : MediaElement = null;
		if (Browser.navigator.userAgent.indexOf("Chrome") < 0)
		{
			a = Browser.window.document.createVideoElement();
			Browser.window.document.body.appendChild(a);
		}
		else
		{
			a = Browser.window.document.createAudioElement();
			Browser.window.document.body.appendChild(a);
		}
		a.style.display = "none";
		a.preload = "auto";
		a.addEventListener("canplaythrough", function(e:Event)
		{
			if (a == null) return;	
			p_callback(a, 1.0);
			a = null;
		}, false );		
		a.onerror  = function(e : Event) {	p_callback(null, 1.0); };		
		a.controls = false;
		if (m_autoload)
		{
			a.src = p_url;
			a.load();
			p_callback(null, 0);
		}
		return a;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadSound(p_url:String, p_callback : Sound -> Float -> Void):MediaElement
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var a : MediaElement = null;
		if (Browser.navigator.userAgent.indexOf("Chrome") < 0)
		{
			a = Browser.window.document.createVideoElement();
			Browser.window.document.body.appendChild(a);
		}
		else
		{
			a = Browser.window.document.createAudioElement();
			Browser.window.document.body.appendChild(a);
		}
		a.style.display = "none";
		//new Audio();
		a.controls = false;
		a.preload = "auto";		
		
		//trace("Web> Loading Sound from [" + p_url + "]");
		
		a.addEventListener("canplaythrough", function(e:Event)
		{
			if (a == null) return;			
			//trace("Web> Can Play Sound");
			var snd : Sound = new Sound(a);			
			p_callback(snd, 1);
			a = null;
		}, false );
			
		a.onerror = function(e : Event)
		{
			p_callback(null, 1.0);
		};		
		if (m_autoload)
		{
			a.src = p_url;
			a.load();
			p_callback(null, 0);
		}
		return a;
	}
	
	
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadImage(p_url:String, p_callback : Image -> Float -> Void):Image
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var img = new Image();	
		img.onload = function (e : Event) {	p_callback(img, 1.0);  }		
		img.onerror = function(e : Event) {	p_callback(null, 1.0); };		
		img.crossOrigin = "Anonymous";
		if (m_autoload)
		{
			img.src = p_url;
			p_callback(null, 0);
		}		
		return img;
	}
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 * @return
	 */
	static public function LoadImageData(p_url:String, p_callback : ImageData -> Float -> Void):Image
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var img = new Image();		
		img.onload = function (e : Event) 
		{
			var canvas : CanvasElement = Browser.document.createCanvasElement();
			canvas.width  = img.width;
			canvas.height = img.height;			
			var ctx :  CanvasRenderingContext2D = canvas.getContext2d();
			ctx.drawImage(img, 0, 0,img.width,img.height);
			var d : ImageData = ctx.getImageData(0, 0, img.width, img.height);
			p_callback(d, 1.0);
		}		
		img.onerror = function(e : Event) { p_callback(null, 1.0); };		
		img.crossOrigin = "Anonymous";
		if (m_autoload)
		{
			img.src = p_url;
			p_callback(null, 0.0);
		}
		return img;
	}
	
}