package haxe.format;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class JsonPrinter extends haxe.lang.HxObject
{
	public    JsonPrinter(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    JsonPrinter(haxe.lang.Function replacer, java.lang.String space)
	{
		haxe.format.JsonPrinter.__hx_ctor_haxe_format_JsonPrinter(this, replacer, space);
	}
	
	
	public static   void __hx_ctor_haxe_format_JsonPrinter(haxe.format.JsonPrinter __temp_me160403, haxe.lang.Function replacer, java.lang.String space)
	{
		__temp_me160403.replacer = replacer;
		__temp_me160403.indent = space;
		__temp_me160403.pretty = ( space != null );
		__temp_me160403.nind = 0;
		__temp_me160403.buf = new haxe.root.StringBuf();
	}
	
	
	public static   java.lang.String print(java.lang.Object o, haxe.lang.Function replacer, java.lang.String space)
	{
		haxe.format.JsonPrinter printer = new haxe.format.JsonPrinter(((haxe.lang.Function) (replacer) ), haxe.lang.Runtime.toString(space));
		printer.write("", o);
		return printer.buf.toString();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.format.JsonPrinter(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.format.JsonPrinter(((haxe.lang.Function) (arr.__get(0)) ), haxe.lang.Runtime.toString(arr.__get(1)));
	}
	
	
	public  haxe.root.StringBuf buf;
	
	public  haxe.lang.Function replacer;
	
	public  java.lang.String indent;
	
	public  boolean pretty;
	
	public  int nind;
	
	public final   void ipad()
	{
		if (this.pretty) 
		{
			java.lang.String v = haxe.root.StringTools.lpad("", this.indent, ( this.nind * this.indent.length() ));
			this.buf.add(v);
		}
		
	}
	
	
	public final   void newl()
	{
		if (this.pretty) 
		{
			this.buf.addChar(10);
		}
		
	}
	
	
	public   void write(java.lang.Object k, java.lang.Object v)
	{
		if (( this.replacer != null )) 
		{
			v = ((java.lang.Object) (this.replacer.__hx_invoke2_o(0.0, k, 0.0, v)) );
		}
		
		{
			haxe.root.ValueType _g = haxe.root.Type.typeof(v);
			switch (haxe.root.Type.enumIndex(_g))
			{
				case 8:
				{
					this.buf.add("\"???\"");
					break;
				}
				
				
				case 4:
				{
					this.fieldsString(v, haxe.root.Reflect.fields(v));
					break;
				}
				
				
				case 1:
				{
					java.lang.String v1 = haxe.lang.Runtime.toString(v);
					this.buf.add(v1);
					break;
				}
				
				
				case 2:
				{
					java.lang.String v2 = null;
					if (haxe.lang.Runtime.isFinite(((double) (haxe.lang.Runtime.toDouble(v)) ))) 
					{
						v2 = haxe.lang.Runtime.toString(v);
					}
					 else 
					{
						v2 = "null";
					}
					
					this.buf.add(v2);
					break;
				}
				
				
				case 5:
				{
					this.buf.add("\"<fun>\"");
					break;
				}
				
				
				case 6:
				{
					java.lang.Class c = ((java.lang.Class) (_g.params.__get(0)) );
					if (( ((java.lang.Object) (c) ) == ((java.lang.Object) (java.lang.String.class) ) )) 
					{
						this.quote(haxe.lang.Runtime.toString(v));
					}
					 else 
					{
						if (( ((java.lang.Object) (c) ) == ((java.lang.Object) (haxe.root.Array.class) ) )) 
						{
							haxe.root.Array v3 = ((haxe.root.Array) (v) );
							this.buf.addChar(91);
							int len = v3.length;
							int last = ( len - 1 );
							{
								int _g1 = 0;
								while (( _g1 < ((int) (len) ) ))
								{
									int i = _g1++;
									if (( i > 0 )) 
									{
										this.buf.addChar(44);
									}
									 else 
									{
										this.nind++;
									}
									
									if (this.pretty) 
									{
										this.buf.addChar(10);
									}
									
									if (this.pretty) 
									{
										java.lang.String v4 = haxe.root.StringTools.lpad("", this.indent, ( this.nind * this.indent.length() ));
										this.buf.add(v4);
									}
									
									this.write(i, v3.__get(i));
									if (( i == last )) 
									{
										this.nind--;
										if (this.pretty) 
										{
											this.buf.addChar(10);
										}
										
										if (this.pretty) 
										{
											java.lang.String v5 = haxe.root.StringTools.lpad("", this.indent, ( this.nind * this.indent.length() ));
											this.buf.add(v5);
										}
										
									}
									
								}
								
							}
							
							this.buf.addChar(93);
						}
						 else 
						{
							if (( ((java.lang.Object) (c) ) == ((java.lang.Object) (haxe.ds.StringMap.class) ) )) 
							{
								haxe.ds.StringMap v6 = ((haxe.ds.StringMap) (v) );
								java.lang.Object o = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
								{
									java.lang.Object __temp_iterator160728 = v6.keys();
									while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator160728, "hasNext", null)))
									{
										java.lang.String k1 = haxe.lang.Runtime.toString(haxe.lang.Runtime.callField(__temp_iterator160728, "next", null));
										haxe.root.Reflect.setField(o, k1, v6.get(k1));
									}
									
								}
								
								this.fieldsString(o, haxe.root.Reflect.fields(o));
							}
							 else 
							{
								if (( ((java.lang.Object) (c) ) == ((java.lang.Object) (haxe.root.Date.class) ) )) 
								{
									haxe.root.Date v7 = ((haxe.root.Date) (v) );
									this.quote(v7.toString());
								}
								 else 
								{
									this.fieldsString(v, haxe.root.Reflect.fields(v));
								}
								
							}
							
						}
						
					}
					
					break;
				}
				
				
				case 7:
				{
					java.lang.Object i1 = haxe.root.Type.enumIndex(v);
					{
						java.lang.String v8 = haxe.lang.Runtime.toString(i1);
						this.buf.add(v8);
					}
					
					break;
				}
				
				
				case 3:
				{
					java.lang.String v9 = haxe.lang.Runtime.toString(v);
					this.buf.add(v9);
					break;
				}
				
				
				case 0:
				{
					this.buf.add("null");
					break;
				}
				
				
			}
			
		}
		
	}
	
	
	public final   void objString(java.lang.Object v)
	{
		this.fieldsString(v, haxe.root.Reflect.fields(v));
	}
	
	
	public   void fieldsString(java.lang.Object v, haxe.root.Array<java.lang.String> fields)
	{
		this.buf.addChar(123);
		int len = fields.length;
		int last = ( len - 1 );
		{
			int _g = 0;
			while (( _g < ((int) (len) ) ))
			{
				int i = _g++;
				java.lang.String f = fields.__get(i);
				java.lang.Object value = haxe.root.Reflect.field(v, f);
				if (haxe.root.Reflect.isFunction(value)) 
				{
					continue;
				}
				
				if (( i > 0 )) 
				{
					this.buf.addChar(44);
				}
				 else 
				{
					this.nind++;
				}
				
				if (this.pretty) 
				{
					this.buf.addChar(10);
				}
				
				if (this.pretty) 
				{
					java.lang.String v1 = haxe.root.StringTools.lpad("", this.indent, ( this.nind * this.indent.length() ));
					this.buf.add(v1);
				}
				
				this.quote(f);
				this.buf.addChar(58);
				if (this.pretty) 
				{
					this.buf.addChar(32);
				}
				
				this.write(f, value);
				if (( i == last )) 
				{
					this.nind--;
					if (this.pretty) 
					{
						this.buf.addChar(10);
					}
					
					if (this.pretty) 
					{
						java.lang.String v2 = haxe.root.StringTools.lpad("", this.indent, ( this.nind * this.indent.length() ));
						this.buf.add(v2);
					}
					
				}
				
			}
			
		}
		
		this.buf.addChar(125);
	}
	
	
	public   void quote(java.lang.String s)
	{
		this.buf.addChar(34);
		int i = 0;
		while (true)
		{
			int c = 0;
			{
				int index = i++;
				if (( index < s.length() )) 
				{
					c = ((int) (s.charAt(index)) );
				}
				 else 
				{
					c = -1;
				}
				
			}
			
			if (( c == -1 )) 
			{
				break;
			}
			
			switch (c)
			{
				case 34:
				{
					this.buf.add("\\\"");
					break;
				}
				
				
				case 92:
				{
					this.buf.add("\\\\");
					break;
				}
				
				
				case 10:
				{
					this.buf.add("\\n");
					break;
				}
				
				
				case 13:
				{
					this.buf.add("\\r");
					break;
				}
				
				
				case 9:
				{
					this.buf.add("\\t");
					break;
				}
				
				
				case 8:
				{
					this.buf.add("\\b");
					break;
				}
				
				
				case 12:
				{
					this.buf.add("\\f");
					break;
				}
				
				
				default:
				{
					this.buf.addChar(c);
					break;
				}
				
			}
			
		}
		
		this.buf.addChar(34);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160971 = true;
			switch (field.hashCode())
			{
				case 3381425:
				{
					if (field.equals("nind")) 
					{
						__temp_executeDef160971 = false;
						this.nind = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160971) 
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
			boolean __temp_executeDef160972 = true;
			switch (field.hashCode())
			{
				case 3381425:
				{
					if (field.equals("nind")) 
					{
						__temp_executeDef160972 = false;
						this.nind = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 97907:
				{
					if (field.equals("buf")) 
					{
						__temp_executeDef160972 = false;
						this.buf = ((haxe.root.StringBuf) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -980096906:
				{
					if (field.equals("pretty")) 
					{
						__temp_executeDef160972 = false;
						this.pretty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -430332866:
				{
					if (field.equals("replacer")) 
					{
						__temp_executeDef160972 = false;
						this.replacer = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1184239444:
				{
					if (field.equals("indent")) 
					{
						__temp_executeDef160972 = false;
						this.indent = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160972) 
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
			boolean __temp_executeDef160973 = true;
			switch (field.hashCode())
			{
				case 107953788:
				{
					if (field.equals("quote")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("quote"))) );
					}
					
					break;
				}
				
				
				case 97907:
				{
					if (field.equals("buf")) 
					{
						__temp_executeDef160973 = false;
						return this.buf;
					}
					
					break;
				}
				
				
				case -66446294:
				{
					if (field.equals("fieldsString")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("fieldsString"))) );
					}
					
					break;
				}
				
				
				case -430332866:
				{
					if (field.equals("replacer")) 
					{
						__temp_executeDef160973 = false;
						return this.replacer;
					}
					
					break;
				}
				
				
				case -1989270552:
				{
					if (field.equals("objString")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("objString"))) );
					}
					
					break;
				}
				
				
				case -1184239444:
				{
					if (field.equals("indent")) 
					{
						__temp_executeDef160973 = false;
						return this.indent;
					}
					
					break;
				}
				
				
				case 113399775:
				{
					if (field.equals("write")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("write"))) );
					}
					
					break;
				}
				
				
				case -980096906:
				{
					if (field.equals("pretty")) 
					{
						__temp_executeDef160973 = false;
						return this.pretty;
					}
					
					break;
				}
				
				
				case 3377868:
				{
					if (field.equals("newl")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("newl"))) );
					}
					
					break;
				}
				
				
				case 3381425:
				{
					if (field.equals("nind")) 
					{
						__temp_executeDef160973 = false;
						return this.nind;
					}
					
					break;
				}
				
				
				case 3238794:
				{
					if (field.equals("ipad")) 
					{
						__temp_executeDef160973 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ipad"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160973) 
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
			boolean __temp_executeDef160974 = true;
			switch (field.hashCode())
			{
				case 3381425:
				{
					if (field.equals("nind")) 
					{
						__temp_executeDef160974 = false;
						return ((double) (this.nind) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160974) 
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
			boolean __temp_executeDef160975 = true;
			switch (field.hashCode())
			{
				case 107953788:
				{
					if (field.equals("quote")) 
					{
						__temp_executeDef160975 = false;
						this.quote(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 3238794:
				{
					if (field.equals("ipad")) 
					{
						__temp_executeDef160975 = false;
						this.ipad();
					}
					
					break;
				}
				
				
				case -66446294:
				{
					if (field.equals("fieldsString")) 
					{
						__temp_executeDef160975 = false;
						this.fieldsString(dynargs.__get(0), ((haxe.root.Array<java.lang.String>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 3377868:
				{
					if (field.equals("newl")) 
					{
						__temp_executeDef160975 = false;
						this.newl();
					}
					
					break;
				}
				
				
				case -1989270552:
				{
					if (field.equals("objString")) 
					{
						__temp_executeDef160975 = false;
						this.objString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 113399775:
				{
					if (field.equals("write")) 
					{
						__temp_executeDef160975 = false;
						this.write(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160975) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("nind");
		baseArr.push("pretty");
		baseArr.push("indent");
		baseArr.push("replacer");
		baseArr.push("buf");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


