package haxor.platform.html;
import haxor.platform.Types.Float32;




#if html
import js.Browser;
#end

/**
 * Class that describes the browser being used (HTML only).
 * Based on the "Bowser" lib [https://github.com/ded/bowser]
 */
class BrowserAgent
{
	/**
	 * User Agent
	 */
	public var agent : String;
	
	/**
	 * Browser name.
	 */
	public var name : String;
	
	/**
	 * Browser version.
	 */
	public var version : String;
	
	/**
	 * OS Version.
	 */
	public var OSVersion : String;
	
	/**
	 * OS Version.
	 */
	public var OSMajorVersion : String;
	
	/**
	 * Map ios device name to bool.
	 */
	public var iosdevice : Dynamic;
	
	/**
	 * Flag that indicates if the browser is running on tablet.
	 */
	public var tablet : Bool;
	
	/**
	 * Flag that indicates if the browser is running on phone.
	 */
	public var phone : Bool;
	
	/**
	 * Flag that indicates if the browser is either running on a phone or a tablet.
	 */
	public var mobile:Bool;
	
	/**
	 * Flag that indicates if this is an Opera browser.
	 */
	public var opera : Bool;
	
	/**
	 * Flag that indicates if the browser is IE.
	 */
	public var ie : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Windows Phone.
	 */
	public var windowsPhone : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Chrome.
	 */
	public var chrome : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Firefox.
	 */
	public var firefox : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Sailfish.
	 */
	public var sailfish : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Seamonkey.
	 */
	public var seamonkey : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Silk.
	 */
	public var silk : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Phantom.
	 */
	public var phantom : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Blackberry.
	 */
	public var blackberry : Bool;
	
	/**
	 * Flag that indicates if the browser is running on WebOS.
	 */
	public var webOS : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Bada.
	 */
	public var bada : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Tizen.
	 */
	public var tizen : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Safari.
	 */
	public var safari : Bool;
	
	/**
	 * Flag that indicates if the browser is running on WebKit.
	 */
	public var webkit : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Gecko.
	 */
	public var gecko : Bool;
	
	/**
	 * Flag that indicates if the browser is running on Android.
	 */
	public var android : Bool;
	
	/**
	 * Flag that indicates if the browser is running on iOS.
	 */
	public var ios : Bool;
	
	/**
	 * Creates the data structure.
	 */
	public function new():Void
	{
		agent      = "";
		name       = "";
		version    = "";
		OSVersion  = "";
		OSMajorVersion = "";
		phone      = false;
		tablet     = false;
		opera      = false;
		ie 		   = false;
		windowsPhone = false;
		chrome     = false;
		sailfish   = false;
		seamonkey  = false;
		silk	   = false;
		phantom    = false;
		blackberry = false;
		webOS      = false;
		bada	   = false;
		tizen	   = false;
		safari	   = false;
		webkit	   = false;
		gecko	   = false;
		android	   = false;
		ios		   = false;
		
		iosdevice = { };
		
		#if html
		agent = Browser.navigator.userAgent;
		var r : Dynamic = { };
		
		r.iosdevice   		= gfm(~/(ipod|iphone|ipad)/i).toLowerCase();
		r.likeAndroid 		= test(~/like android/i);
		r.android     		= android = (!r.likeAndroid) && test(~/android/i);
		r.versionIdentifier = gfm(~/version\/(\d+(\.\d+)?)/i);
		if (r.versionIdentifier == null) r.versionIdentifier = "";
		r.tablet 			= tablet = test(~/tablet/i);
        r.phone 			= phone  = (!tablet) && test(~/[^-]mobi/i);
		r.firefoxos 		= false;
		r.osversion 		= "";
		
		if (test(~/opera|opr/i)) 
		{      
			name    = "Opera";
			opera   = true;
			version = r.versionIdentifier=="" ? gfm(~/(?:opera|opr)[\s\/](\d+(\.\d+)?)/i) : r.versionIdentifier;
		}
		else
		if (test(~/windows phone/i)) 
		{      
			name 		 = "Windows Phone";
			windowsPhone = true;
			ie	 		 = true;
			version		 = gfm(~/iemobile\/(\d+(\.\d+)?)/i);
		}
		else
		if (test(~/msie|trident/i)) 
		{		
			name 	= "Internet Explorer";
			ie   	= true;
			version = gfm(~/(?:msie |rv:)(\d+(\.\d+)?)/i);
		}
		else
		if (test(~/chrome|crios|crmo/i)) 
		{			
			name    = "Chrome";
			chrome  = true;
			version = gfm(~/(?:chrome|crios|crmo)\/(\d+(\.\d+)?)/i);
		}
		else
		if (r.iosdevice) 
		{      
			name = r.iosdevice == "iphone" ? "iPhone" : (r.iosdevice == "ipad" ? "iPad" : "iPod");
			// WTF: version is not part of user agent in web apps
			if (r.versionIdentifier != null) r.version = r.versionIdentifier;		
		}
		else
		if (test(~/sailfish/i)) 
		{		
			name 	 = "Sailfish";
			sailfish = true;
			version  = gfm(~/sailfish\s?browser\/(\d+(\.\d+)?)/i);
		}
		else
		if (test(~/seamonkey\//i)) 
		{      
			name 	  = "SeaMonkey";
			seamonkey = true;
			version   = gfm(~/seamonkey\/(\d+(\.\d+)?)/i);
		}
		else
		if (test(~/firefox|iceweasel/i))
		{      
			name 	= "Firefox";
			firefox = true;
			version = gfm(~/(?:firefox|iceweasel)[ \/](\d+(\.\d+)?)/i);			
			if (test(~/\((mobile|tablet);[^\)]*rv:[\d\.]+\)/i)) 
			{
				r.firefoxos = true;
			}			
		}
		else
		if (test(~/silk/i)) 
		{		
			name 	= "Amazon Silk";
			silk    = true;
			version = gfm(~/silk\/(\d+(\.\d+)?)/i);
		}
		else
		if (r.android) 
		{      
			name    = "Android";
			version = r.versionIdentifier;
		}
		else
		if (test(~/phantom/i)) 
		{		
			name 	= "PhantomJS";
			phantom = true;
			version = gfm(~/phantomjs\/(\d+(\.\d+)?)/i);
		}    
		else
		if (test(~/blackberry|\bbb\d+/i) || test(~/rim\stablet/i)) 
		{      
			name 		= "BlackBerry";
			blackberry  = true;
			version 	= r.versionIdentifier == "" ? gfm(~/blackberry[\d]+\/(\d+(\.\d+)?)/i) : r.versionIdentifier;      
		}
		else
		if (test(~/(web|hpw)os/i)) 
		{     
			name    = "WebOS";
			webOS   = true;
			version = r.versionIdentifier == "" ? gfm(~/w(?:eb)?osbrowser\/(\d+(\.\d+)?)/i) : r.versionIdentifier;     
			if (test(~/touchpad\//i)) r.touchpad = true;
		}
		else
		if (test(~/bada/i)) 
		{		
			name 	= "Bada";
			bada 	= true;
			version = gfm(~/dolfin\/(\d+(\.\d+)?)/i);
		}
		else
		if (test(~/tizen/i)) 
		{		
			name    = "Tizen";
			tizen   = true;
			version = r.versionIdentifier=="" ? gfm(~/(?:tizen\s?)?browser\/(\d+(\.\d+)?)/i) : r.versionIdentifier;
		}
		else
		if (test(~/safari/i)) 
		{     
			name    = "Safari";
			safari  = true;
			version = r.versionIdentifier;     
		}
		
		if (test(~/(apple)?webkit/i)) 
		{
			name 	= name == "" ? "Webkit" : name;
			webkit  = true;
			if (version == "")
			if(r.versionIdentifier!="") version = r.versionIdentifier;			
		}
		else
		if (!opera)
		if(test(~/gecko\//i)) 
		{
			name    = name == "" ? "Gecko" : name;
			gecko   = true;
			version = version == "" ? gfm(~/gecko\/(\d+(\.\d+)?)/i) : version;
		}
		
		if (android || silk) 
		{
			android = true;
		}
		else
		if (r.iosdevice!="") 
		{
			iosdevice[r.iosdevice] = true;
			ios = true;
		}
		
		if (r.iosdevice != "")
		{
			OSVersion = gfm(~/os (\d+([_\s]\d+)*) like mac os x/i);
			OSVersion = replace(~/[_\s]/g,OSVersion,".");
		}
		else
		if (android) 		{ OSVersion = gfm(~/android[ \/-](\d+(\.\d+)*)/i); }
		else 
		if (windowsPhone) 	{ OSVersion = gfm(~/windows phone (?:os)?\s?(\d+(\.\d+)*)/i); }
		else 
		if (webOS) 			{ OSVersion = gfm(~/(?:web|hpw)os\/(\d+(\.\d+)*)/i); }
		else 
		if (blackberry) 	{ OSVersion = gfm(~/rim\stablet\sos\s(\d+(\.\d+)*)/i); } 
		else 
		if (bada) 			{ OSVersion = gfm(~/bada\/(\d+(\.\d+)*)/i); } 
		else 
		if (tizen) 			{ OSVersion = gfm(~/tizen[\/\s](\d+(\.\d+)*)/i); }
		
		if (OSVersion!="") r.osversion = OSVersion;
		
		OSMajorVersion = StringTools.trim(OSVersion.split(".")[0]);
		
		if (tablet || iosdevice == "ipad" || (android && (OSMajorVersion == "3" || (OSMajorVersion == "4" && !phone))) || silk) 
		{
			tablet = true;
		}
		else 
		if (phone || iosdevice == "iphone" || iosdevice == "ipod" || android || blackberry || webOS || bada) 
		{
			phone = true;
		}
		
		var v    : Float32 = Std.parseFloat(version);
		var os_v : Float32 = OSVersion == "" ? 0 : (Std.parseFloat(OSVersion.split(".")[0]));
		
		if(
		  (ie         && (v >= 10.0))   ||
		  (chrome     && (v >= 20.0))   ||
		  (firefox    && (v >= 20.0))   ||
		  (safari     && (v >= 6.0 ))   ||
		  (opera      && (v >= 10.0))   ||
		  (ios        && (os_v >= 6.0)) ||
		  (blackberry && (v >= 10.1)))
		{
			r.a = true;
		}
		else
		if(
		  (ie         && (v < 10.0))   ||
		  (chrome     && (v < 20.0))   ||
		  (firefox    && (v < 20.0))   ||
		  (safari     && (v < 6.0 ))   ||
		  (opera      && (v < 10.0))   ||
		  (ios        && (os_v < 6.0)))
        {
			r.c = true;
		}
		else
		{
			r.x = true;
		}
		
		mobile = tablet || phone;
		
		trace(r);
		trace(this);
		#end
	}
	
	#if html
	/**
	 * helper
	 * @param	regex
	 * @return
	 */
	private function test(regex:EReg):Bool { return regex.match(agent); }
	
	/**
	 * helper
	 * @param	regex
	 * @param	str
	 * @param	sub
	 * @return
	 */
	private function replace(regex:EReg,str:String,sub:String):String { return regex.replace(str,sub); }
	
	/**
	 * helper.
	 * @param	ua
	 * @param	regex
	 */
	private function gfm(regex : EReg) : String
	{
		var match : Array<String> = regex.split(agent);
		if (match == null)     return "";
		if (match.length <= 0) return "";
		if (match[1] == null)  return "";
		return match[1];      
    }
	#end
}