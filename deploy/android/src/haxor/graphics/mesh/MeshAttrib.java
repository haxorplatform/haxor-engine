package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshAttrib extends haxe.lang.HxObject
{
	public    MeshAttrib(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MeshAttrib()
	{
		haxor.graphics.mesh.MeshAttrib.__hx_ctor_haxor_graphics_mesh_MeshAttrib(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_MeshAttrib(haxor.graphics.mesh.MeshAttrib __temp_me151397)
	{
		{
			haxor.context.UID _this = haxor.context.EngineContext.mesh.aid;
			if (( _this.m_cache.length <= 0 )) 
			{
				__temp_me151397.__cid = _this.m_id++;
			}
			 else 
			{
				__temp_me151397.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		__temp_me151397._loc_ = -1;
		__temp_me151397.m_name = "";
		__temp_me151397.data = null;
		__temp_me151397.offset = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.MeshAttrib(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.MeshAttrib();
	}
	
	
	public  int __cid;
	
	public  int _loc_;
	
	
	
	public final   java.lang.String get_name()
	{
		return this.m_name;
	}
	
	
	public  java.lang.String m_name;
	
	public  haxor.io.Buffer data;
	
	public  int offset;
	
	
	
	public   int get_count()
	{
		if (( this.data == null )) 
		{
			return 0;
		}
		 else 
		{
			return ( this.data.m_length / this.offset );
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152157 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef152157 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef152157 = false;
						this.__cid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 91061758:
				{
					if (field.equals("_loc_")) 
					{
						__temp_executeDef152157 = false;
						this._loc_ = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152157) 
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
			boolean __temp_executeDef152158 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef152158 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef152158 = false;
						this.__cid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef152158 = false;
						this.data = ((haxor.io.Buffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 91061758:
				{
					if (field.equals("_loc_")) 
					{
						__temp_executeDef152158 = false;
						this._loc_ = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1083281635:
				{
					if (field.equals("m_name")) 
					{
						__temp_executeDef152158 = false;
						this.m_name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152158) 
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
			boolean __temp_executeDef152159 = true;
			switch (field.hashCode())
			{
				case 1131801318:
				{
					if (field.equals("get_count")) 
					{
						__temp_executeDef152159 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_count"))) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef152159 = false;
						return this.__cid;
					}
					
					break;
				}
				
				
				case 94851343:
				{
					if (field.equals("count")) 
					{
						__temp_executeDef152159 = false;
						return this.get_count();
					}
					
					break;
				}
				
				
				case 91061758:
				{
					if (field.equals("_loc_")) 
					{
						__temp_executeDef152159 = false;
						return this._loc_;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef152159 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef152159 = false;
						return this.get_name();
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef152159 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 1976486356:
				{
					if (field.equals("get_name")) 
					{
						__temp_executeDef152159 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_name"))) );
					}
					
					break;
				}
				
				
				case -1083281635:
				{
					if (field.equals("m_name")) 
					{
						__temp_executeDef152159 = false;
						return this.m_name;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152159) 
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
			boolean __temp_executeDef152160 = true;
			switch (field.hashCode())
			{
				case 94851343:
				{
					if (field.equals("count")) 
					{
						__temp_executeDef152160 = false;
						return ((double) (this.get_count()) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef152160 = false;
						return ((double) (this.__cid) );
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef152160 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
				case 91061758:
				{
					if (field.equals("_loc_")) 
					{
						__temp_executeDef152160 = false;
						return ((double) (this._loc_) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152160) 
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
			boolean __temp_executeDef152161 = true;
			switch (field.hashCode())
			{
				case 1131801318:
				{
					if (field.equals("get_count")) 
					{
						__temp_executeDef152161 = false;
						return this.get_count();
					}
					
					break;
				}
				
				
				case 1976486356:
				{
					if (field.equals("get_name")) 
					{
						__temp_executeDef152161 = false;
						return this.get_name();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152161) 
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
		baseArr.push("count");
		baseArr.push("offset");
		baseArr.push("data");
		baseArr.push("m_name");
		baseArr.push("name");
		baseArr.push("_loc_");
		baseArr.push("__cid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


