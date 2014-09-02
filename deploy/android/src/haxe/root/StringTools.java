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
	
	
	public static   void __hx_ctor__StringTools(haxe.root.StringTools __temp_me164130)
	{
		{
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
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.StringTools(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.StringTools();
	}
	
	
}


