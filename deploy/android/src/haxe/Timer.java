package haxe;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Timer extends haxe.lang.HxObject
{
	public    Timer(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Timer()
	{
		haxe.Timer.__hx_ctor_haxe_Timer(this);
	}
	
	
	public static   void __hx_ctor_haxe_Timer(haxe.Timer __temp_me17)
	{
		{
			__temp_me17.run = ( (( haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current != null )) ? (haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current) : (haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current = ((haxe.Timer___hx_ctor_haxe_Timer_113__Fun) (new haxe.Timer___hx_ctor_haxe_Timer_113__Fun()) )) );
		}
		
	}
	
	
	public static   double stamp()
	{
		return haxe.root.Sys.time();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.Timer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.Timer();
	}
	
	
	public  haxe.lang.Function run;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef477 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef477 = false;
						this.run = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef477) 
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
			boolean __temp_executeDef478 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef478 = false;
						return this.run;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef478) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("run");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


