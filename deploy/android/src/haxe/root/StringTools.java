package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class StringTools extends haxe.lang.HxObject
{
	public    StringTools(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    StringTools()
	{
		haxe.root.StringTools.__hx_ctor__StringTools(this);
	}
	
	
	public static   void __hx_ctor__StringTools(haxe.root.StringTools __temp_me160380)
	{
		{
		}
		
	}
	
	
	public static   java.lang.String urlEncode(java.lang.String s)
	{
		try 
		{
			return java.net.URLEncoder.encode(s, "UTF-8");
		}
		catch (java.lang.Throwable __temp_catchallException160792)
		{
			java.lang.Object __temp_catchall160793 = __temp_catchallException160792;
			if (( __temp_catchall160793 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall160793 = ((haxe.lang.HaxeException) (__temp_catchallException160792) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall160793;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static   java.lang.String urlDecode(java.lang.String s)
	{
		try 
		{
			return java.net.URLDecoder.decode(s, "UTF-8");
		}
		catch (java.lang.Throwable __temp_catchallException160794)
		{
			java.lang.Object __temp_catchall160795 = __temp_catchallException160794;
			if (( __temp_catchall160795 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall160795 = ((haxe.lang.HaxeException) (__temp_catchallException160794) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall160795;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static   java.lang.String htmlEscape(java.lang.String s, java.lang.Object quotes)
	{
		s = haxe.lang.StringExt.split(haxe.lang.StringExt.split(haxe.lang.StringExt.split(s, "&").join("&amp;"), "<").join("&lt;"), ">").join("&gt;");
		if (haxe.lang.Runtime.toBool((quotes))) 
		{
			return haxe.lang.StringExt.split(haxe.lang.StringExt.split(s, "\"").join("&quot;"), "\'").join("&#039;");
		}
		 else 
		{
			return s;
		}
		
	}
	
	
	public static   java.lang.String htmlUnescape(java.lang.String s)
	{
		return haxe.lang.StringExt.split(haxe.lang.StringExt.split(haxe.lang.StringExt.split(haxe.lang.StringExt.split(haxe.lang.StringExt.split(s, "&gt;").join(">"), "&lt;").join("<"), "&quot;").join("\""), "&#039;").join("\'"), "&amp;").join("&");
	}
	
	
	public static   boolean startsWith(java.lang.String s, java.lang.String start)
	{
		return s.startsWith(start);
	}
	
	
	public static   boolean endsWith(java.lang.String s, java.lang.String end)
	{
		return s.endsWith(end);
	}
	
	
	public static   boolean isSpace(java.lang.String s, int pos)
	{
		java.lang.Object c = haxe.lang.StringExt.charCodeAt(s, pos);
		return ( ( ( haxe.lang.Runtime.compare(c, 8) > 0 ) && ( haxe.lang.Runtime.compare(c, 14) < 0 ) ) || haxe.lang.Runtime.eq(c, 32) );
	}
	
	
	public static   java.lang.String ltrim(java.lang.String s)
	{
		int l = s.length();
		int r = 0;
		while (( ( r < l ) && haxe.root.StringTools.isSpace(s, r) ))
		{
			r++;
		}
		
		if (( r > 0 )) 
		{
			return haxe.lang.StringExt.substr(s, r, ( l - r ));
		}
		 else 
		{
			return s;
		}
		
	}
	
	
	public static   java.lang.String rtrim(java.lang.String s)
	{
		int l = s.length();
		int r = 0;
		while (( ( r < l ) && haxe.root.StringTools.isSpace(s, ( ( l - r ) - 1 )) ))
		{
			r++;
		}
		
		if (( r > 0 )) 
		{
			return haxe.lang.StringExt.substr(s, 0, ( l - r ));
		}
		 else 
		{
			return s;
		}
		
	}
	
	
	public static   java.lang.String trim(java.lang.String s)
	{
		return s.trim();
	}
	
	
	public static   java.lang.String lpad(java.lang.String s, java.lang.String c, int l)
	{
		if (( c.length() <= 0 )) 
		{
			return s;
		}
		
		while (( s.length() < l ))
		{
			s = ( c + s );
		}
		
		return s;
	}
	
	
	public static   java.lang.String rpad(java.lang.String s, java.lang.String c, int l)
	{
		if (( c.length() <= 0 )) 
		{
			return s;
		}
		
		while (( s.length() < l ))
		{
			s = ( s + c );
		}
		
		return s;
	}
	
	
	public static   java.lang.String replace(java.lang.String s, java.lang.String sub, java.lang.String by)
	{
		if (( sub.length() == 0 )) 
		{
			return haxe.lang.StringExt.split(s, sub).join(by);
		}
		 else 
		{
			return s.replace(sub, by);
		}
		
	}
	
	
	public static   java.lang.String hex(int n, java.lang.Object digits)
	{
		java.lang.String s = "";
		java.lang.String hexChars = "0123456789ABCDEF";
		do 
		{
			s = ( haxe.lang.StringExt.charAt(hexChars, ( n & 15 )) + s );
			n >>>= 4;
		}
		while (( n > 0 ));
		if (( ! (( digits == null )) )) 
		{
			while (( haxe.lang.Runtime.compare(s.length(), digits) < 0 ))
			{
				s = ( "0" + s );
			}
			
		}
		
		return s;
	}
	
	
	public static   int fastCodeAt(java.lang.String s, int index)
	{
		if (( index < s.length() )) 
		{
			return ((int) (s.charAt(index)) );
		}
		 else 
		{
			return -1;
		}
		
	}
	
	
	public static   boolean isEof(int c)
	{
		return ( c == -1 );
	}
	
	
	public static   char _charAt(java.lang.String str, int idx)
	{
		return str.charAt(idx);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.StringTools(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.StringTools();
	}
	
	
}


