package haxe.crypto;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Base64 extends haxe.lang.HxObject
{
	static 
	{
		haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
	}
	public    Base64(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Base64()
	{
		haxe.crypto.Base64.__hx_ctor_haxe_crypto_Base64(this);
	}
	
	
	public static   void __hx_ctor_haxe_crypto_Base64(haxe.crypto.Base64 __temp_me160390)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String CHARS;
	
	public static  haxe.io.Bytes BYTES;
	
	public static   java.lang.String encode(haxe.io.Bytes bytes, java.lang.Object complement)
	{
		boolean __temp_complement160388 = ( (( complement == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(complement)) );
		java.lang.String str = new haxe.crypto.BaseCode(((haxe.io.Bytes) (haxe.crypto.Base64.BYTES) )).encodeBytes(bytes).toString();
		if (__temp_complement160388) 
		{
			int _g1 = 0;
			int _g = ( (( 3 - ( ( bytes.length * 4 ) % 3 ) )) % 3 );
			while (( _g1 < _g ))
			{
				int i = _g1++;
				str += "=";
			}
			
		}
		
		return str;
	}
	
	
	public static   haxe.io.Bytes decode(java.lang.String str, java.lang.Object complement)
	{
		boolean __temp_complement160389 = ( (( complement == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(complement)) );
		if (__temp_complement160389) 
		{
			while (haxe.lang.Runtime.eq(haxe.lang.StringExt.charCodeAt(str, ( str.length() - 1 )), 61))
			{
				str = haxe.lang.StringExt.substr(str, 0, -1);
			}
			
		}
		
		return new haxe.crypto.BaseCode(((haxe.io.Bytes) (haxe.crypto.Base64.BYTES) )).decodeBytes(haxe.io.Bytes.ofString(str));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.crypto.Base64(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.crypto.Base64();
	}
	
	
}


