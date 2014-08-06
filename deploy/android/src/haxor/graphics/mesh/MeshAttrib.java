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
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_MeshAttrib(haxor.graphics.mesh.MeshAttrib __temp_me26101)
	{
		__temp_me26101.id = haxor.context.EngineContext.mesh.aid++;
		__temp_me26101.name = "";
		__temp_me26101.type = "";
		__temp_me26101.data = null;
		__temp_me26101.offset = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.MeshAttrib(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.MeshAttrib();
	}
	
	
	public  int id;
	
	public  java.lang.String name;
	
	public  haxor.io.BaseArray data;
	
	public  java.lang.String type;
	
	public  int offset;
	
	
	
	public   int get_count()
	{
		if (( this.data == null )) 
		{
			return 0;
		}
		 else 
		{
			double x = ( ((double) (this.data.get_length()) ) / this.offset );
			return ((int) (x) );
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26190 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef26190 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef26190 = false;
						this.id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26190) 
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
			boolean __temp_executeDef26191 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef26191 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef26191 = false;
						this.id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef26191 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef26191 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef26191 = false;
						this.data = ((haxor.io.BaseArray) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26191) 
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
			boolean __temp_executeDef26192 = true;
			switch (field.hashCode())
			{
				case 1131801318:
				{
					if (field.equals("get_count")) 
					{
						__temp_executeDef26192 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_count"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef26192 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 94851343:
				{
					if (field.equals("count")) 
					{
						__temp_executeDef26192 = false;
						return this.get_count();
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef26192 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef26192 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef26192 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef26192 = false;
						return this.type;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26192) 
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
			boolean __temp_executeDef26193 = true;
			switch (field.hashCode())
			{
				case 94851343:
				{
					if (field.equals("count")) 
					{
						__temp_executeDef26193 = false;
						return ((double) (this.get_count()) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef26193 = false;
						return ((double) (this.id) );
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef26193 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26193) 
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
			boolean __temp_executeDef26194 = true;
			switch (field.hashCode())
			{
				case 1131801318:
				{
					if (field.equals("get_count")) 
					{
						__temp_executeDef26194 = false;
						return this.get_count();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26194) 
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
		baseArr.push("type");
		baseArr.push("data");
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


