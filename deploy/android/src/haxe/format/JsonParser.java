package haxe.format;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class JsonParser extends haxe.lang.HxObject
{
	public    JsonParser(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    JsonParser(java.lang.String str)
	{
		haxe.format.JsonParser.__hx_ctor_haxe_format_JsonParser(this, str);
	}
	
	
	public static   void __hx_ctor_haxe_format_JsonParser(haxe.format.JsonParser __temp_me255339, java.lang.String str)
	{
		__temp_me255339.str = str;
		__temp_me255339.pos = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.format.JsonParser(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.format.JsonParser(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  java.lang.String str;
	
	public  int pos;
	
	public   java.lang.Object parseRec()
	{
		while (true)
		{
			int c = 0;
			{
				java.lang.String s = this.str;
				int index = this.pos++;
				if (( index < s.length() )) 
				{
					c = ((int) (s.charAt(index)) );
				}
				 else 
				{
					c = -1;
				}
				
			}
			
			switch (c)
			{
				case 32:case 13:case 10:case 9:
				{
					{
					}
					
					break;
				}
				
				
				case 123:
				{
					java.lang.Object obj = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
					java.lang.String field = null;
					java.lang.Object comma = null;
					while (true)
					{
						int c1 = 0;
						{
							java.lang.String s1 = this.str;
							int index1 = this.pos++;
							if (( index1 < s1.length() )) 
							{
								c1 = ((int) (s1.charAt(index1)) );
							}
							 else 
							{
								c1 = -1;
							}
							
						}
						
						switch (c1)
						{
							case 32:case 13:case 10:case 9:
							{
								{
								}
								
								break;
							}
							
							
							case 125:
							{
								if (( ( field != null ) || haxe.lang.Runtime.eq(comma, false) )) 
								{
									this.invalidChar();
								}
								
								return obj;
							}
							
							
							case 58:
							{
								if (( field == null )) 
								{
									this.invalidChar();
								}
								
								haxe.root.Reflect.setField(obj, field, this.parseRec());
								field = null;
								comma = true;
								break;
							}
							
							
							case 44:
							{
								if (haxe.lang.Runtime.toBool((comma))) 
								{
									comma = false;
								}
								 else 
								{
									this.invalidChar();
								}
								
								break;
							}
							
							
							case 34:
							{
								if (haxe.lang.Runtime.toBool((comma))) 
								{
									this.invalidChar();
								}
								
								field = this.parseString();
								break;
							}
							
							
							default:
							{
								this.invalidChar();
								break;
							}
							
						}
						
					}
					
				}
				
				
				case 91:
				{
					haxe.root.Array arr = new haxe.root.Array(new java.lang.Object[]{});
					java.lang.Object comma1 = null;
					while (true)
					{
						int c2 = 0;
						{
							java.lang.String s2 = this.str;
							int index2 = this.pos++;
							if (( index2 < s2.length() )) 
							{
								c2 = ((int) (s2.charAt(index2)) );
							}
							 else 
							{
								c2 = -1;
							}
							
						}
						
						switch (c2)
						{
							case 32:case 13:case 10:case 9:
							{
								{
								}
								
								break;
							}
							
							
							case 93:
							{
								if (haxe.lang.Runtime.eq(comma1, false)) 
								{
									this.invalidChar();
								}
								
								return arr;
							}
							
							
							case 44:
							{
								if (haxe.lang.Runtime.toBool((comma1))) 
								{
									comma1 = false;
								}
								 else 
								{
									this.invalidChar();
								}
								
								break;
							}
							
							
							default:
							{
								if (haxe.lang.Runtime.toBool((comma1))) 
								{
									this.invalidChar();
								}
								
								this.pos--;
								arr.push(this.parseRec());
								comma1 = true;
								break;
							}
							
						}
						
					}
					
				}
				
				
				case 116:
				{
					int save = this.pos;
					int __temp_stmt255799 = 0;
					{
						java.lang.String s3 = this.str;
						int index3 = this.pos++;
						__temp_stmt255799 = ( (( index3 < s3.length() )) ? (((int) (s3.charAt(index3)) )) : (-1) );
					}
					
					boolean __temp_stmt255798 = ( __temp_stmt255799 != 114 );
					boolean __temp_boolv255800 = false;
					if ( ! (__temp_stmt255798) ) 
					{
						int __temp_stmt255801 = 0;
						{
							java.lang.String s4 = this.str;
							int index4 = this.pos++;
							__temp_stmt255801 = ( (( index4 < s4.length() )) ? (((int) (s4.charAt(index4)) )) : (-1) );
						}
						
						__temp_boolv255800 = ( __temp_stmt255801 != 117 );
					}
					
					boolean __temp_stmt255797 = ( __temp_stmt255798 || __temp_boolv255800 );
					boolean __temp_boolv255802 = false;
					if ( ! (__temp_stmt255797) ) 
					{
						int __temp_stmt255803 = 0;
						{
							java.lang.String s5 = this.str;
							int index5 = this.pos++;
							__temp_stmt255803 = ( (( index5 < s5.length() )) ? (((int) (s5.charAt(index5)) )) : (-1) );
						}
						
						__temp_boolv255802 = ( __temp_stmt255803 != 101 );
					}
					
					boolean __temp_stmt255796 = ( __temp_stmt255797 || __temp_boolv255802 );
					if (__temp_stmt255796) 
					{
						this.pos = save;
						this.invalidChar();
					}
					
					return true;
				}
				
				
				case 102:
				{
					int save1 = this.pos;
					int __temp_stmt255808 = 0;
					{
						java.lang.String s6 = this.str;
						int index6 = this.pos++;
						__temp_stmt255808 = ( (( index6 < s6.length() )) ? (((int) (s6.charAt(index6)) )) : (-1) );
					}
					
					boolean __temp_stmt255807 = ( __temp_stmt255808 != 97 );
					boolean __temp_boolv255809 = false;
					if ( ! (__temp_stmt255807) ) 
					{
						int __temp_stmt255810 = 0;
						{
							java.lang.String s7 = this.str;
							int index7 = this.pos++;
							__temp_stmt255810 = ( (( index7 < s7.length() )) ? (((int) (s7.charAt(index7)) )) : (-1) );
						}
						
						__temp_boolv255809 = ( __temp_stmt255810 != 108 );
					}
					
					boolean __temp_stmt255806 = ( __temp_stmt255807 || __temp_boolv255809 );
					boolean __temp_boolv255811 = false;
					if ( ! (__temp_stmt255806) ) 
					{
						int __temp_stmt255812 = 0;
						{
							java.lang.String s8 = this.str;
							int index8 = this.pos++;
							__temp_stmt255812 = ( (( index8 < s8.length() )) ? (((int) (s8.charAt(index8)) )) : (-1) );
						}
						
						__temp_boolv255811 = ( __temp_stmt255812 != 115 );
					}
					
					boolean __temp_stmt255805 = ( __temp_stmt255806 || __temp_boolv255811 );
					boolean __temp_boolv255813 = false;
					if ( ! (__temp_stmt255805) ) 
					{
						int __temp_stmt255814 = 0;
						{
							java.lang.String s9 = this.str;
							int index9 = this.pos++;
							__temp_stmt255814 = ( (( index9 < s9.length() )) ? (((int) (s9.charAt(index9)) )) : (-1) );
						}
						
						__temp_boolv255813 = ( __temp_stmt255814 != 101 );
					}
					
					boolean __temp_stmt255804 = ( __temp_stmt255805 || __temp_boolv255813 );
					if (__temp_stmt255804) 
					{
						this.pos = save1;
						this.invalidChar();
					}
					
					return false;
				}
				
				
				case 110:
				{
					int save2 = this.pos;
					int __temp_stmt255818 = 0;
					{
						java.lang.String s10 = this.str;
						int index10 = this.pos++;
						__temp_stmt255818 = ( (( index10 < s10.length() )) ? (((int) (s10.charAt(index10)) )) : (-1) );
					}
					
					boolean __temp_stmt255817 = ( __temp_stmt255818 != 117 );
					boolean __temp_boolv255819 = false;
					if ( ! (__temp_stmt255817) ) 
					{
						int __temp_stmt255820 = 0;
						{
							java.lang.String s11 = this.str;
							int index11 = this.pos++;
							__temp_stmt255820 = ( (( index11 < s11.length() )) ? (((int) (s11.charAt(index11)) )) : (-1) );
						}
						
						__temp_boolv255819 = ( __temp_stmt255820 != 108 );
					}
					
					boolean __temp_stmt255816 = ( __temp_stmt255817 || __temp_boolv255819 );
					boolean __temp_boolv255821 = false;
					if ( ! (__temp_stmt255816) ) 
					{
						int __temp_stmt255822 = 0;
						{
							java.lang.String s12 = this.str;
							int index12 = this.pos++;
							__temp_stmt255822 = ( (( index12 < s12.length() )) ? (((int) (s12.charAt(index12)) )) : (-1) );
						}
						
						__temp_boolv255821 = ( __temp_stmt255822 != 108 );
					}
					
					boolean __temp_stmt255815 = ( __temp_stmt255816 || __temp_boolv255821 );
					if (__temp_stmt255815) 
					{
						this.pos = save2;
						this.invalidChar();
					}
					
					return null;
				}
				
				
				case 34:
				{
					return this.parseString();
				}
				
				
				case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 45:
				{
					int c3 = c;
					int start = ( this.pos - 1 );
					boolean minus = ( c3 == 45 );
					boolean digit =  ! (minus) ;
					boolean zero = ( c3 == 48 );
					boolean point = false;
					boolean e = false;
					boolean pm = false;
					boolean end = false;
					while (true)
					{
						{
							java.lang.String s13 = this.str;
							int index13 = this.pos++;
							if (( index13 < s13.length() )) 
							{
								c3 = ((int) (s13.charAt(index13)) );
							}
							 else 
							{
								c3 = -1;
							}
							
						}
						
						switch (c3)
						{
							case 48:
							{
								if (( zero &&  ! (point)  )) 
								{
									this.invalidNumber(start);
								}
								
								if (minus) 
								{
									minus = false;
									zero = true;
								}
								
								digit = true;
								break;
							}
							
							
							case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:
							{
								if (( zero &&  ! (point)  )) 
								{
									this.invalidNumber(start);
								}
								
								if (minus) 
								{
									minus = false;
								}
								
								digit = true;
								zero = false;
								break;
							}
							
							
							case 46:
							{
								if (( minus || point )) 
								{
									this.invalidNumber(start);
								}
								
								digit = false;
								point = true;
								break;
							}
							
							
							case 101:case 69:
							{
								if (( ( minus || zero ) || e )) 
								{
									this.invalidNumber(start);
								}
								
								digit = false;
								e = true;
								break;
							}
							
							
							case 43:case 45:
							{
								if ((  ! (e)  || pm )) 
								{
									this.invalidNumber(start);
								}
								
								digit = false;
								pm = true;
								break;
							}
							
							
							default:
							{
								if ( ! (digit) ) 
								{
									this.invalidNumber(start);
								}
								
								this.pos--;
								end = true;
								break;
							}
							
						}
						
						if (end) 
						{
							break;
						}
						
					}
					
					double f = haxe.root.Std.parseFloat(haxe.lang.StringExt.substr(this.str, start, ( this.pos - start )));
					int i = ((int) (f) );
					if (( i == f )) 
					{
						return i;
					}
					 else 
					{
						return f;
					}
					
				}
				
				
				default:
				{
					this.invalidChar();
					break;
				}
				
			}
			
		}
		
	}
	
	
	public   java.lang.String parseString()
	{
		int start = this.pos;
		haxe.root.StringBuf buf = new haxe.root.StringBuf();
		while (true)
		{
			int c = 0;
			{
				java.lang.String s = this.str;
				int index = this.pos++;
				if (( index < s.length() )) 
				{
					c = ((int) (s.charAt(index)) );
				}
				 else 
				{
					c = -1;
				}
				
			}
			
			if (( c == 34 )) 
			{
				break;
			}
			
			if (( c == 92 )) 
			{
				buf.addSub(this.str, start, ( ( this.pos - start ) - 1 ));
				{
					java.lang.String s1 = this.str;
					int index1 = this.pos++;
					if (( index1 < s1.length() )) 
					{
						c = ((int) (s1.charAt(index1)) );
					}
					 else 
					{
						c = -1;
					}
					
				}
				
				switch (c)
				{
					case 114:
					{
						buf.addChar(13);
						break;
					}
					
					
					case 110:
					{
						buf.addChar(10);
						break;
					}
					
					
					case 116:
					{
						buf.addChar(9);
						break;
					}
					
					
					case 98:
					{
						buf.addChar(8);
						break;
					}
					
					
					case 102:
					{
						buf.addChar(12);
						break;
					}
					
					
					case 47:case 92:case 34:
					{
						buf.addChar(c);
						break;
					}
					
					
					case 117:
					{
						java.lang.Object uc = haxe.root.Std.parseInt(( "0x" + haxe.lang.StringExt.substr(this.str, this.pos, 4) ));
						this.pos += 4;
						buf.addChar(((int) (haxe.lang.Runtime.toInt(uc)) ));
						break;
					}
					
					
					default:
					{
						throw haxe.lang.HaxeException.wrap(( ( ( "Invalid escape sequence \\" + Character.toString((char) c) ) + " at position " ) + (( this.pos - 1 )) ));
					}
					
				}
				
				start = this.pos;
			}
			 else 
			{
				if (( c == -1 )) 
				{
					throw haxe.lang.HaxeException.wrap("Unclosed string");
				}
				
			}
			
		}
		
		buf.addSub(this.str, start, ( ( this.pos - start ) - 1 ));
		return buf.toString();
	}
	
	
	public   void invalidChar()
	{
		this.pos--;
		int __temp_stmt255823 = 0;
		{
			java.lang.String s = this.str;
			int index = this.pos;
			__temp_stmt255823 = ( (( index < s.length() )) ? (((int) (s.charAt(index)) )) : (-1) );
		}
		
		throw haxe.lang.HaxeException.wrap(( ( ( "Invalid char " + __temp_stmt255823 ) + " at position " ) + this.pos ));
	}
	
	
	public   void invalidNumber(int start)
	{
		throw haxe.lang.HaxeException.wrap(( ( ( "Invalid number at position " + start ) + ": " ) + haxe.lang.StringExt.substr(this.str, start, ( this.pos - start )) ));
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255824 = true;
			switch (field.hashCode())
			{
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef255824 = false;
						this.pos = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255824) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255825 = true;
			switch (field.hashCode())
			{
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef255825 = false;
						this.pos = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 114225:
				{
					if (field.equals("str")) 
					{
						__temp_executeDef255825 = false;
						this.str = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255825) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255826 = true;
			switch (field.hashCode())
			{
				case -1321720800:
				{
					if (field.equals("invalidNumber")) 
					{
						__temp_executeDef255826 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("invalidNumber"))) );
					}
					
					break;
				}
				
				
				case 114225:
				{
					if (field.equals("str")) 
					{
						__temp_executeDef255826 = false;
						return this.str;
					}
					
					break;
				}
				
				
				case -953670163:
				{
					if (field.equals("invalidChar")) 
					{
						__temp_executeDef255826 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("invalidChar"))) );
					}
					
					break;
				}
				
				
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef255826 = false;
						return this.pos;
					}
					
					break;
				}
				
				
				case -678275932:
				{
					if (field.equals("parseString")) 
					{
						__temp_executeDef255826 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("parseString"))) );
					}
					
					break;
				}
				
				
				case 1187792093:
				{
					if (field.equals("parseRec")) 
					{
						__temp_executeDef255826 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("parseRec"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255826) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255827 = true;
			switch (field.hashCode())
			{
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef255827 = false;
						return ((double) (this.pos) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255827) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef255828 = true;
			switch (field.hashCode())
			{
				case -1321720800:
				{
					if (field.equals("invalidNumber")) 
					{
						__temp_executeDef255828 = false;
						this.invalidNumber(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1187792093:
				{
					if (field.equals("parseRec")) 
					{
						__temp_executeDef255828 = false;
						return this.parseRec();
					}
					
					break;
				}
				
				
				case -953670163:
				{
					if (field.equals("invalidChar")) 
					{
						__temp_executeDef255828 = false;
						this.invalidChar();
					}
					
					break;
				}
				
				
				case -678275932:
				{
					if (field.equals("parseString")) 
					{
						__temp_executeDef255828 = false;
						return this.parseString();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255828) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("pos");
		baseArr.push("str");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


