package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaInput extends haxe.lang.HxObject
{
	public    ColladaInput(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaInput()
	{
		haxor.io.file.ColladaInput.__hx_ctor_haxor_io_file_ColladaInput(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaInput(haxor.io.file.ColladaInput __temp_me164326)
	{
		__temp_me164326.stride = 0;
		__temp_me164326.values = null;
		__temp_me164326.set = -1;
		__temp_me164326.offset = 0;
		__temp_me164326.semantic = "";
		__temp_me164326.values = new haxe.root.Array(new java.lang.Object[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaInput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaInput();
	}
	
	
	public  java.lang.String semantic;
	
	public  int offset;
	
	public  int set;
	
	public  haxe.root.Array values;
	
	public  int stride;
	
	public   java.lang.Object GetVectorArray()
	{
		if (( this.stride <= 0 )) 
		{
			return new haxe.root.Array(new java.lang.Object[]{});
		}
		
		java.lang.Object res = new haxe.root.Array(new java.lang.Object[]{});
		int i = 0;
		while (( i < this.values.length ))
		{
			java.lang.Object v = null;
			{
				int _g = this.stride;
				switch (_g)
				{
					case 1:
					{
						v = this.values.__get(i);
						break;
					}
					
					
					case 2:
					{
						v = new haxor.math.Vector2(((java.lang.Object) (this.values.__get(i)) ), ((java.lang.Object) (this.values.__get(( i + 1 ))) ));
						break;
					}
					
					
					case 3:
					{
						if (haxe.lang.Runtime.valEq(this.semantic, "color")) 
						{
							v = new haxor.math.Color(((java.lang.Object) (this.values.__get(i)) ), ((java.lang.Object) (this.values.__get(( i + 1 ))) ), ((java.lang.Object) (this.values.__get(( i + 2 ))) ), ((java.lang.Object) (null) ));
						}
						 else 
						{
							v = new haxor.math.Vector3(((java.lang.Object) (this.values.__get(i)) ), ((java.lang.Object) (this.values.__get(( i + 1 ))) ), ((java.lang.Object) (this.values.__get(( i + 2 ))) ));
						}
						
						break;
					}
					
					
					case 4:
					{
						if (haxe.lang.Runtime.valEq(this.semantic, "color")) 
						{
							v = new haxor.math.Color(((java.lang.Object) (this.values.__get(i)) ), ((java.lang.Object) (this.values.__get(( i + 1 ))) ), ((java.lang.Object) (this.values.__get(( i + 2 ))) ), ((java.lang.Object) (this.values.__get(( i + 3 ))) ));
						}
						 else 
						{
							v = new haxor.math.Vector4(((java.lang.Object) (this.values.__get(i)) ), ((java.lang.Object) (this.values.__get(( i + 1 ))) ), ((java.lang.Object) (this.values.__get(( i + 2 ))) ), ((java.lang.Object) (this.values.__get(( i + 3 ))) ));
						}
						
						break;
					}
					
					
				}
				
			}
			
			if (( v == null )) 
			{
				continue;
			}
			
			haxe.lang.Runtime.callField(res, "push", new haxe.root.Array(new java.lang.Object[]{v}));
			i += this.stride;
		}
		
		return res;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef165112 = true;
			switch (field.hashCode())
			{
				case -891986215:
				{
					if (field.equals("stride")) 
					{
						__temp_executeDef165112 = false;
						this.stride = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef165112 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef165112 = false;
						this.set = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165112) 
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
			boolean __temp_executeDef165113 = true;
			switch (field.hashCode())
			{
				case -891986215:
				{
					if (field.equals("stride")) 
					{
						__temp_executeDef165113 = false;
						this.stride = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1216835014:
				{
					if (field.equals("semantic")) 
					{
						__temp_executeDef165113 = false;
						this.semantic = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -823812830:
				{
					if (field.equals("values")) 
					{
						__temp_executeDef165113 = false;
						this.values = ((haxe.root.Array) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef165113 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef165113 = false;
						this.set = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165113) 
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
			boolean __temp_executeDef165114 = true;
			switch (field.hashCode())
			{
				case -1088027200:
				{
					if (field.equals("GetVectorArray")) 
					{
						__temp_executeDef165114 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetVectorArray"))) );
					}
					
					break;
				}
				
				
				case 1216835014:
				{
					if (field.equals("semantic")) 
					{
						__temp_executeDef165114 = false;
						return this.semantic;
					}
					
					break;
				}
				
				
				case -891986215:
				{
					if (field.equals("stride")) 
					{
						__temp_executeDef165114 = false;
						return this.stride;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef165114 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case -823812830:
				{
					if (field.equals("values")) 
					{
						__temp_executeDef165114 = false;
						return this.values;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef165114 = false;
						return this.set;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165114) 
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
			boolean __temp_executeDef165115 = true;
			switch (field.hashCode())
			{
				case -891986215:
				{
					if (field.equals("stride")) 
					{
						__temp_executeDef165115 = false;
						return ((double) (this.stride) );
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef165115 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef165115 = false;
						return ((double) (this.set) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165115) 
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
			boolean __temp_executeDef165116 = true;
			switch (field.hashCode())
			{
				case -1088027200:
				{
					if (field.equals("GetVectorArray")) 
					{
						__temp_executeDef165116 = false;
						return this.GetVectorArray();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165116) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("stride");
		baseArr.push("values");
		baseArr.push("set");
		baseArr.push("offset");
		baseArr.push("semantic");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


