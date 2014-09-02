package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class DataComponent extends haxor.component.Component
{
	public    DataComponent(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    DataComponent()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.DataComponent.__hx_ctor_haxor_component_DataComponent(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_DataComponent(haxor.component.DataComponent __temp_me164156)
	{
		haxor.component.Component.__hx_ctor_haxor_component_Component(__temp_me164156, null);
		__temp_me164156.data = new haxe.ds.StringMap();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.DataComponent(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.DataComponent();
	}
	
	
	public  java.lang.Object data;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164694 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef164694 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164694) 
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
			boolean __temp_executeDef164695 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef164695 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164695) 
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
			boolean __temp_executeDef164696 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef164696 = false;
						return this.data;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164696) 
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
			boolean __temp_executeDef164697 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef164697 = false;
						return ((double) (haxe.lang.Runtime.toDouble(this.data)) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164697) 
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
		baseArr.push("data");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


