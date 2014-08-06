package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshContext extends haxe.lang.HxObject
{
	public    MeshContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MeshContext()
	{
		haxor.context.MeshContext.__hx_ctor_haxor_context_MeshContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_MeshContext(haxor.context.MeshContext __temp_me26090)
	{
		__temp_me26090.aid = 0;
		__temp_me26090.buffers = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 1000 ))
			{
				int i = _g++;
				__temp_me26090.buffers.push(haxor.platform.graphics.GL.NULL_ID);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.MeshContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.MeshContext();
	}
	
	
	public  int aid;
	
	public  haxe.root.Array<java.lang.Object> buffers;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26173 = true;
			switch (field.hashCode())
			{
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef26173 = false;
						this.aid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26173) 
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
			boolean __temp_executeDef26174 = true;
			switch (field.hashCode())
			{
				case 227996723:
				{
					if (field.equals("buffers")) 
					{
						__temp_executeDef26174 = false;
						this.buffers = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef26174 = false;
						this.aid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26174) 
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
			boolean __temp_executeDef26175 = true;
			switch (field.hashCode())
			{
				case 227996723:
				{
					if (field.equals("buffers")) 
					{
						__temp_executeDef26175 = false;
						return this.buffers;
					}
					
					break;
				}
				
				
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef26175 = false;
						return this.aid;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26175) 
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
			boolean __temp_executeDef26176 = true;
			switch (field.hashCode())
			{
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef26176 = false;
						return ((double) (this.aid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26176) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("buffers");
		baseArr.push("aid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


