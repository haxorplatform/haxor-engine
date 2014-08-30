package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TransformContext extends haxe.lang.HxObject
{
	public    TransformContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    TransformContext()
	{
		haxor.context.TransformContext.__hx_ctor_haxor_context_TransformContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_TransformContext(haxor.context.TransformContext __temp_me151351)
	{
		__temp_me151351.tid = new haxor.context.UID();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.TransformContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.TransformContext();
	}
	
	
	public  haxor.context.UID tid;
	
	public   void Initialize()
	{
		{
		}
		
	}
	
	
	public   void OnChange(haxor.component.Transform t)
	{
		t.m_uniform_dirty = true;
		haxe.root.Array<haxor.component.Component> cl = t.m_entity.m_components;
		{
			int _g1 = 0;
			int _g = cl.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				cl.__get(i).OnTransformUpdate();
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152082 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef152082 = false;
						this.tid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152082) 
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
			boolean __temp_executeDef152083 = true;
			switch (field.hashCode())
			{
				case 1101418127:
				{
					if (field.equals("OnChange")) 
					{
						__temp_executeDef152083 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnChange"))) );
					}
					
					break;
				}
				
				
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef152083 = false;
						return this.tid;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef152083 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152083) 
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
			boolean __temp_executeDef152084 = true;
			switch (field.hashCode())
			{
				case 1101418127:
				{
					if (field.equals("OnChange")) 
					{
						__temp_executeDef152084 = false;
						this.OnChange(((haxor.component.Transform) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef152084 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152084) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("tid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


