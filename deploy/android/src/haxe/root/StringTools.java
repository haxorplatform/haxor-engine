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
	
	
	public static   void __hx_ctor__StringTools(haxe.root.StringTools __temp_me54461)
	{
		{
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
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.StringTools(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.StringTools();
	}
	
	
}


