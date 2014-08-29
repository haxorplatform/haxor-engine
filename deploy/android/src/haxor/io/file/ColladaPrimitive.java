package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaPrimitive extends haxe.lang.HxObject
{
	public    ColladaPrimitive(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaPrimitive()
	{
		haxor.io.file.ColladaPrimitive.__hx_ctor_haxor_io_file_ColladaPrimitive(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaPrimitive(haxor.io.file.ColladaPrimitive __temp_me80714)
	{
		__temp_me80714.indexes = null;
		__temp_me80714.vcount = null;
		__temp_me80714.inputs = null;
		__temp_me80714.material = "";
		__temp_me80714.type = "";
		__temp_me80714.inputs = new haxe.root.Array<haxor.io.file.ColladaInput>(new haxor.io.file.ColladaInput[]{});
		__temp_me80714.vcount = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me80714.indexes = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me80714.m_triangles = null;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaPrimitive(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaPrimitive();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String material;
	
	public  haxe.root.Array<haxor.io.file.ColladaInput> inputs;
	
	public  haxe.root.Array<java.lang.Object> vcount;
	
	public  haxe.root.Array<haxe.root.Array> indexes;
	
	
	
	public   haxe.root.Array<haxe.root.Array> get_triangles()
	{
		if (( this.m_triangles != null )) 
		{
			return this.m_triangles;
		}
		
		this.m_triangles = haxor.io.file.ColladaFile.GenerateTriangles(this.type, this.indexes, this.vcount);
		return this.m_triangles;
	}
	
	
	public  haxe.root.Array<haxe.root.Array> m_triangles;
	
	
	
	public   int get_offset()
	{
		int mo = 0;
		{
			int _g1 = 0;
			int _g = this.inputs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				mo = ((int) (java.lang.Math.max(((double) (mo) ), ((double) (( this.inputs.__get(i).offset + 1 )) ))) );
			}
			
		}
		
		return mo;
	}
	
	
	public   haxor.io.file.ColladaInput GetInput(java.lang.String p_semantic, java.lang.Object p_set)
	{
		int __temp_p_set80710 = ( (( p_set == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_set)) )) );
		{
			int _g1 = 0;
			int _g = this.inputs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.inputs.__get(i).semantic, p_semantic)) 
				{
					if (( __temp_p_set80710 < 0 )) 
					{
						return this.inputs.__get(i);
					}
					 else 
					{
						if (( __temp_p_set80710 == this.inputs.__get(i).set )) 
						{
							return this.inputs.__get(i);
						}
						
					}
					
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   java.lang.Object GetTriangulatedVectorArray(java.lang.String p_semantic, java.lang.Object p_set, java.lang.Object p_debug)
	{
		boolean __temp_p_debug80712 = ( (( p_debug == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_debug)) );
		int __temp_p_set80711 = ( (( p_set == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_set)) )) );
		haxor.io.file.ColladaInput ci = this.GetInput(p_semantic, __temp_p_set80711);
		if (( ci == null )) 
		{
			return new haxe.root.Array(new java.lang.Object[]{});
		}
		
		java.lang.Object vec = ci.GetVectorArray();
		int off = ci.offset;
		java.lang.Object res = new haxe.root.Array(new java.lang.Object[]{});
		if (( haxe.lang.Runtime.compare(haxe.lang.Runtime.getField(vec, "length", true), 0) <= 0 )) 
		{
			return new haxe.root.Array(new java.lang.Object[]{});
		}
		
		if (( off < 0 )) 
		{
			return new haxe.root.Array(new java.lang.Object[]{});
		}
		
		{
			int _g1 = 0;
			int _g = this.get_triangles().length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxe.root.Array<java.lang.Object> tuple = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.get_triangles().__get(i)) )) );
				int idx = ((int) (haxe.lang.Runtime.toInt(tuple.__get(off))) );
				haxe.lang.Runtime.callField(res, "push", new haxe.root.Array(new java.lang.Object[]{((java.lang.Object) (haxe.lang.Runtime.callField(vec, "__get", new haxe.root.Array(new java.lang.Object[]{idx}))) )}));
			}
			
		}
		
		return res;
	}
	
	
	public   java.lang.Object GetVectorArray(java.lang.String p_semantic, java.lang.Object p_set)
	{
		int __temp_p_set80713 = ( (( p_set == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_set)) )) );
		java.lang.Object res = new haxe.root.Array(new java.lang.Object[]{});
		{
			int _g1 = 0;
			int _g = this.inputs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.inputs.__get(i).semantic, p_semantic)) 
				{
					if (( __temp_p_set80713 < 0 )) 
					{
						res = this.inputs.__get(i).GetVectorArray();
						break;
					}
					 else 
					{
						if (( __temp_p_set80713 == this.inputs.__get(i).set )) 
						{
							res = this.inputs.__get(i).GetVectorArray();
							break;
						}
						
					}
					
				}
				
			}
			
		}
		
		if (haxe.lang.Runtime.valEq(p_semantic, "color")) 
		{
			if (( __temp_p_set80713 < 0 )) 
			{
				java.lang.Object l = this.GetVectorArray("color", 0);
				if (( haxe.lang.Runtime.compare(haxe.lang.Runtime.getField(l, "length", true), 0) > 0 )) 
				{
					int len = ((int) (java.lang.Math.min(((double) (haxe.lang.Runtime.toDouble(haxe.lang.Runtime.getField(l, "length", true))) ), ((double) (haxe.lang.Runtime.toDouble(haxe.lang.Runtime.getField(res, "length", true))) ))) );
					{
						int _g2 = 0;
						while (( _g2 < len ))
						{
							int i1 = _g2++;
							haxe.lang.Runtime.setField(((java.lang.Object) (haxe.lang.Runtime.callField(res, "__get", new haxe.root.Array(new java.lang.Object[]{i1}))) ), "a", haxe.lang.Runtime.getField(((java.lang.Object) (haxe.lang.Runtime.callField(l, "__get", new haxe.root.Array(new java.lang.Object[]{i1}))) ), "r", true));
						}
						
					}
					
				}
				
			}
			
		}
		
		return res;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81522 = true;
			switch (field.hashCode())
			{
				case -602124775:
				{
					if (field.equals("m_triangles")) 
					{
						__temp_executeDef81522 = false;
						this.m_triangles = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef81522 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 1943292160:
				{
					if (field.equals("indexes")) 
					{
						__temp_executeDef81522 = false;
						this.indexes = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef81522 = false;
						this.material = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef81522 = false;
						this.vcount = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1183866391:
				{
					if (field.equals("inputs")) 
					{
						__temp_executeDef81522 = false;
						this.inputs = ((haxe.root.Array<haxor.io.file.ColladaInput>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81522) 
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
			boolean __temp_executeDef81523 = true;
			switch (field.hashCode())
			{
				case -1088027200:
				{
					if (field.equals("GetVectorArray")) 
					{
						__temp_executeDef81523 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetVectorArray"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef81523 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case -1960121496:
				{
					if (field.equals("GetTriangulatedVectorArray")) 
					{
						__temp_executeDef81523 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetTriangulatedVectorArray"))) );
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef81523 = false;
						return this.material;
					}
					
					break;
				}
				
				
				case 2020827700:
				{
					if (field.equals("GetInput")) 
					{
						__temp_executeDef81523 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetInput"))) );
					}
					
					break;
				}
				
				
				case -1183866391:
				{
					if (field.equals("inputs")) 
					{
						__temp_executeDef81523 = false;
						return this.inputs;
					}
					
					break;
				}
				
				
				case 1060898204:
				{
					if (field.equals("get_offset")) 
					{
						__temp_executeDef81523 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_offset"))) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef81523 = false;
						return this.vcount;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef81523 = false;
						return this.get_offset();
					}
					
					break;
				}
				
				
				case 1943292160:
				{
					if (field.equals("indexes")) 
					{
						__temp_executeDef81523 = false;
						return this.indexes;
					}
					
					break;
				}
				
				
				case -602124775:
				{
					if (field.equals("m_triangles")) 
					{
						__temp_executeDef81523 = false;
						return this.m_triangles;
					}
					
					break;
				}
				
				
				case -814008469:
				{
					if (field.equals("triangles")) 
					{
						__temp_executeDef81523 = false;
						return this.get_triangles();
					}
					
					break;
				}
				
				
				case -299168318:
				{
					if (field.equals("get_triangles")) 
					{
						__temp_executeDef81523 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_triangles"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81523) 
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
			boolean __temp_executeDef81524 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef81524 = false;
						return ((double) (this.get_offset()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81524) 
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
			boolean __temp_executeDef81525 = true;
			switch (field.hashCode())
			{
				case -1088027200:
				{
					if (field.equals("GetVectorArray")) 
					{
						__temp_executeDef81525 = false;
						return this.GetVectorArray(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -299168318:
				{
					if (field.equals("get_triangles")) 
					{
						__temp_executeDef81525 = false;
						return this.get_triangles();
					}
					
					break;
				}
				
				
				case -1960121496:
				{
					if (field.equals("GetTriangulatedVectorArray")) 
					{
						__temp_executeDef81525 = false;
						return this.GetTriangulatedVectorArray(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 1060898204:
				{
					if (field.equals("get_offset")) 
					{
						__temp_executeDef81525 = false;
						return this.get_offset();
					}
					
					break;
				}
				
				
				case 2020827700:
				{
					if (field.equals("GetInput")) 
					{
						__temp_executeDef81525 = false;
						return this.GetInput(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81525) 
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
		baseArr.push("offset");
		baseArr.push("m_triangles");
		baseArr.push("triangles");
		baseArr.push("indexes");
		baseArr.push("vcount");
		baseArr.push("inputs");
		baseArr.push("material");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


