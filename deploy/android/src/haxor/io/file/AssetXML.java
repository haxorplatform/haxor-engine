package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AssetXML extends haxor.io.file.AssetFile
{
	public    AssetXML(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    AssetXML(java.lang.String p_name, java.lang.String p_src)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.io.file.AssetXML.__hx_ctor_haxor_io_file_AssetXML(this, p_name, p_src);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_AssetXML(haxor.io.file.AssetXML __temp_me255512, java.lang.String p_name, java.lang.String p_src)
	{
		haxor.io.file.AssetFile.__hx_ctor_haxor_io_file_AssetFile(__temp_me255512, p_name);
		__temp_me255512.x = haxe.root.Xml.parse(p_src);
		__temp_me255512.TraverseStep(__temp_me255512.x.firstElement());
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.AssetXML(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.AssetXML(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)));
	}
	
	
	public  haxe.root.Xml x;
	
	public   void Parse(haxe.root.Xml n)
	{
		{
		}
		
	}
	
	
	public   void TraverseStep(haxe.root.Xml n)
	{
		this.Parse(n);
		java.lang.Object l = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(l, "hasNext", null)))
		{
			this.TraverseStep(((haxe.root.Xml) (haxe.lang.Runtime.callField(l, "next", null)) ));
		}
		
	}
	
	
	public   java.lang.String _a(haxe.root.Xml n, java.lang.String a, java.lang.Object v)
	{
		if (n.exists(a)) 
		{
			return n.get(a);
		}
		 else 
		{
			return haxe.lang.Runtime.toString(v);
		}
		
	}
	
	
	public   java.lang.String _tla(haxe.root.Xml n, java.lang.String a, java.lang.Object v)
	{
		if (n.exists(a)) 
		{
			java.lang.String __temp_stmt256247 = null;
			{
				java.lang.String s = n.get(a);
				__temp_stmt256247 = s.trim();
			}
			
			return __temp_stmt256247.toLowerCase();
		}
		 else 
		{
			return haxe.lang.Runtime.toString(v);
		}
		
	}
	
	
	public   java.lang.Object _p(haxe.root.Xml n, java.lang.String p, java.lang.Object v, java.lang.Object t, java.lang.Object tl)
	{
		boolean __temp_tl255511 = ( (( tl == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(tl)) );
		boolean __temp_t255510 = ( (( t == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(t)) );
		haxe.root.Array<java.lang.String> l = haxe.lang.StringExt.split(p, ".");
		haxe.root.Xml it = n;
		{
			int _g1 = 0;
			int _g = l.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				java.lang.String tk = l.__get(i);
				{
					java.lang.String __temp_svar256248 = (tk);
					boolean __temp_executeDef256249 = true;
					switch (__temp_svar256248.hashCode())
					{
						case 36803409:
						{
							if (__temp_svar256248.equals("$text")) 
							{
								__temp_executeDef256249 = false;
								if (( it.firstChild() == null )) 
								{
									return v;
								}
								
								java.lang.String txt = it.firstChild().toString();
								if (__temp_t255510) 
								{
									txt = txt.trim();
								}
								
								if (__temp_tl255511) 
								{
									txt = txt.toLowerCase();
								}
								
								return txt;
							}
							
							break;
						}
						
						
					}
					
					if (__temp_executeDef256249) 
					{
						if (haxe.lang.Runtime.valEq(haxe.lang.StringExt.charAt(tk, 0), "@")) 
						{
							if (__temp_t255510) 
							{
								if (__temp_tl255511) 
								{
									return this._tla(it, haxe.lang.StringExt.substr(tk, 1, null), v);
								}
								
							}
							
							return this._a(it, haxe.lang.StringExt.substr(tk, 1, null), v);
						}
						
						java.lang.Object eit = it.elementsNamed(tk);
						if (( eit == null )) 
						{
							return v;
						}
						
						if (( i == ( l.length - 1 ) )) 
						{
							return eit;
						}
						
						if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(eit, "hasNext", null))) ) 
						{
							return v;
						}
						
						it = ((haxe.root.Xml) (haxe.lang.Runtime.callField(eit, "next", null)) );
					}
					
				}
				
			}
			
		}
		
		return v;
	}
	
	
	public   haxe.root.Xml _f(haxe.root.Xml n, java.lang.String p, java.lang.String a, java.lang.String t)
	{
		java.lang.Object f = this._p(n, p, "", null, null);
		java.lang.Object it = null;
		if (haxe.lang.Runtime.eq(f, "")) 
		{
			it = null;
		}
		 else 
		{
			it = ((java.lang.Object) (f) );
		}
		
		if (( it == null )) 
		{
			return null;
		}
		
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			haxe.root.Xml e = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			if (haxe.lang.Runtime.valEq(this._a(e, a, ""), t)) 
			{
				return e;
			}
			
		}
		
		return null;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256250 = true;
			switch (field.hashCode())
			{
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256250 = false;
						this.x = ((haxe.root.Xml) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256250) 
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
			boolean __temp_executeDef256251 = true;
			switch (field.hashCode())
			{
				case 3047:
				{
					if (field.equals("_f")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_f"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256251 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 3057:
				{
					if (field.equals("_p")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_p"))) );
					}
					
					break;
				}
				
				
				case 76884627:
				{
					if (field.equals("Parse")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Parse"))) );
					}
					
					break;
				}
				
				
				case 2945066:
				{
					if (field.equals("_tla")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_tla"))) );
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseStep"))) );
					}
					
					break;
				}
				
				
				case 3042:
				{
					if (field.equals("_a")) 
					{
						__temp_executeDef256251 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_a"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256251) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef256252 = true;
			switch (field.hashCode())
			{
				case 3047:
				{
					if (field.equals("_f")) 
					{
						__temp_executeDef256252 = false;
						return this._f(((haxe.root.Xml) (dynargs.__get(0)) ), haxe.lang.Runtime.toString(dynargs.__get(1)), haxe.lang.Runtime.toString(dynargs.__get(2)), haxe.lang.Runtime.toString(dynargs.__get(3)));
					}
					
					break;
				}
				
				
				case 76884627:
				{
					if (field.equals("Parse")) 
					{
						__temp_executeDef256252 = false;
						this.Parse(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 3057:
				{
					if (field.equals("_p")) 
					{
						__temp_executeDef256252 = false;
						return this._p(((haxe.root.Xml) (dynargs.__get(0)) ), haxe.lang.Runtime.toString(dynargs.__get(1)), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4));
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef256252 = false;
						this.TraverseStep(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2945066:
				{
					if (field.equals("_tla")) 
					{
						__temp_executeDef256252 = false;
						return this._tla(((haxe.root.Xml) (dynargs.__get(0)) ), haxe.lang.Runtime.toString(dynargs.__get(1)), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 3042:
				{
					if (field.equals("_a")) 
					{
						__temp_executeDef256252 = false;
						return this._a(((haxe.root.Xml) (dynargs.__get(0)) ), haxe.lang.Runtime.toString(dynargs.__get(1)), dynargs.__get(2));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256252) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("x");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


