package haxe;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Json extends haxe.lang.HxObject
{
	public    Json(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Json()
	{
		haxe.Json.__hx_ctor_haxe_Json(this);
	}
	
	
	public static   void __hx_ctor_haxe_Json(haxe.Json __temp_me151280)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object parse(java.lang.String text)
	{
		return new haxe.format.JsonParser(haxe.lang.Runtime.toString(text)).parseRec();
	}
	
	
	public static   java.lang.String stringify(java.lang.Object value, haxe.lang.Function replacer, java.lang.String space)
	{
		return haxe.format.JsonPrinter.print(value, replacer, space);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.Json(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.Json();
	}
	
	
}


