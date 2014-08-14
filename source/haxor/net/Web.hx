package haxor.net;


#if html
typedef Web = haxor.platform.html.Web;
#end

#if android
typedef Web = haxor.platform.android.Web;
#end

#if windows
typedef Web = haxor.platform.windows.Web;
#end