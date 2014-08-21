package haxe.lang;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class StringRefl
{
	static 
	{
		haxe.lang.StringRefl.fields = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"length", "toUpperCase", "toLowerCase", "charAt", "charCodeAt", "indexOf", "lastIndexOf", "split", "substr", "substring"});
	}
	public    StringRefl()
	{
		{
		}
		
	}
	
	
	public static  haxe.root.Array<java.lang.String> fields;
	
	public static   java.lang.Object handleGetField(java.lang.String str, java.lang.String f, boolean throwErrors)
	{
		{
			java.lang.String __temp_svar54445 = (f);
			int __temp_hash54447 = __temp_svar54445.hashCode();
			boolean __temp_executeDef54446 = true;
			switch (__temp_hash54447)
			{
				case -1106363674:
				{
					if (__temp_svar54445.equals("length")) 
					{
						__temp_executeDef54446 = false;
						return str.length();
					}
					
					break;
				}
				
				
				case 530542161:case -891529231:case 109648666:case -467511597:case 1943291465:case 397153782:case -1361633751:case -1137582698:case -399551817:
				{
					if (( (( ( __temp_hash54447 == 530542161 ) && __temp_svar54445.equals("substring") )) || ( (( ( __temp_hash54447 == -891529231 ) && __temp_svar54445.equals("substr") )) || ( (( ( __temp_hash54447 == 109648666 ) && __temp_svar54445.equals("split") )) || ( (( ( __temp_hash54447 == -467511597 ) && __temp_svar54445.equals("lastIndexOf") )) || ( (( ( __temp_hash54447 == 1943291465 ) && __temp_svar54445.equals("indexOf") )) || ( (( ( __temp_hash54447 == 397153782 ) && __temp_svar54445.equals("charCodeAt") )) || ( (( ( __temp_hash54447 == -1361633751 ) && __temp_svar54445.equals("charAt") )) || ( (( ( __temp_hash54447 == -1137582698 ) && __temp_svar54445.equals("toLowerCase") )) || __temp_svar54445.equals("toUpperCase") ) ) ) ) ) ) ) )) 
					{
						__temp_executeDef54446 = false;
						return new haxe.lang.Closure(((java.lang.Object) (str) ), haxe.lang.Runtime.toString(f));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54446) 
			{
				if (throwErrors) 
				{
					throw haxe.lang.HaxeException.wrap(( ( "Field not found: \'" + f ) + "\' in String" ));
				}
				 else 
				{
					return null;
				}
				
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public static   java.lang.Object handleCallField(java.lang.String str, java.lang.String f, haxe.root.Array args)
	{
		haxe.root.Array _args = new haxe.root.Array(new java.lang.Object[]{str});
		if (( args == null )) 
		{
			args = _args;
		}
		 else 
		{
			args = _args.concat(args);
		}
		
		return haxe.lang.Runtime.slowCallField(haxe.lang.StringExt.class, f, args);
	}
	
	
}


