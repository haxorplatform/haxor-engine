package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Std
{
	public    Std()
	{
		{
		}
		
	}
	
	
	public static   boolean is(java.lang.Object v, java.lang.Object t)
	{
		if (( v == null )) 
		{
			return haxe.lang.Runtime.eq(t, java.lang.Object.class);
		}
		
		if (( t == null )) 
		{
			return false;
		}
		
		java.lang.Class clt = ((java.lang.Class) (t) );
		if (( ((java.lang.Object) (clt) ) == ((java.lang.Object) (null) ) )) 
		{
			return false;
		}
		
		java.lang.String name = clt.getName();
		{
			java.lang.String __temp_svar21823 = (name);
			int __temp_hash21825 = __temp_svar21823.hashCode();
			switch (__temp_hash21825)
			{
				case 761287205:case -1325958191:
				{
					if (( (( ( __temp_hash21825 == 761287205 ) && __temp_svar21823.equals("java.lang.Double") )) || __temp_svar21823.equals("double") )) 
					{
						return haxe.lang.Runtime.isDouble(v);
					}
					
					break;
				}
				
				
				case 1063877011:
				{
					if (__temp_svar21823.equals("java.lang.Object")) 
					{
						return true;
					}
					
					break;
				}
				
				
				case -2056817302:case 104431:
				{
					if (( (( ( __temp_hash21825 == -2056817302 ) && __temp_svar21823.equals("java.lang.Integer") )) || __temp_svar21823.equals("int") )) 
					{
						return haxe.lang.Runtime.isInt(v);
					}
					
					break;
				}
				
				
				case 344809556:case 64711720:
				{
					if (( (( ( __temp_hash21825 == 344809556 ) && __temp_svar21823.equals("java.lang.Boolean") )) || __temp_svar21823.equals("boolean") )) 
					{
						return v instanceof java.lang.Boolean;
					}
					
					break;
				}
				
				
			}
			
		}
		
		java.lang.Class clv = v.getClass();
		return clt.isAssignableFrom(((java.lang.Class) (clv) ));
	}
	
	
	public static   java.lang.String string(java.lang.Object s)
	{
		return ( haxe.lang.Runtime.toString(s) + "" );
	}
	
	
	public static   java.lang.Object parseInt(java.lang.String x)
	{
		
		if (x == null) return null;

		int ret = 0;
		int base = 10;
		int i = 0;
		int len = x.length();

		if (x.startsWith("0") && len > 2)
		{
			char c = x.charAt(1);
			if (c == 'x' || c == 'X')
			{
				i = 2;
				base = 16;
			}
		}

		boolean foundAny = false;
		boolean isNeg = false;
		for (; i < len; i++)
		{
			char c = x.charAt(i);
			if (!foundAny)
			{
				switch(c)
				{
					case '-':
						isNeg = true;
						continue;
          case '+':
					case '\n':
					case '\t':
					case '\r':
					case ' ':
						if (isNeg) return null;
						continue;
				}
			}

			if (c >= '0' && c <= '9')
			{
				if (!foundAny && c == '0')
				{
					foundAny = true;
					continue;
				}
				ret *= base; foundAny = true;

				ret += ((int) (c - '0'));
			} else if (base == 16) {
				if (c >= 'a' && c <= 'f') {
					ret *= base; foundAny = true;
					ret += ((int) (c - 'a')) + 10;
				} else if (c >= 'A' && c <= 'F') {
					ret *= base; foundAny = true;
					ret += ((int) (c - 'A')) + 10;
				} else {
					break;
				}
			} else {
				break;
			}
		}

		if (foundAny)
			return isNeg ? -ret : ret;
		else
			return null;
	
	}
	
	
}


