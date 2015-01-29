package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AnimationEvent extends haxe.lang.HxObject
{
	public    AnimationEvent(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    AnimationEvent(int p_frame, haxe.lang.Function p_listener, java.lang.Object p_repeat, haxe.root.Array p_args)
	{
		haxor.component.animation.AnimationEvent.__hx_ctor_haxor_component_animation_AnimationEvent(this, p_frame, p_listener, p_repeat, p_args);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_AnimationEvent(haxor.component.animation.AnimationEvent __temp_me57, int p_frame, haxe.lang.Function p_listener, java.lang.Object p_repeat, haxe.root.Array p_args)
	{
		int __temp_p_repeat56 = ( (( p_repeat == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_repeat)) )) );
		__temp_me57.frame = p_frame;
		__temp_me57.listener = p_listener;
		if (( p_args == null )) 
		{
			__temp_me57.args = new haxe.root.Array(new java.lang.Object[]{});
		}
		 else 
		{
			__temp_me57.args = p_args;
		}
		
		__temp_me57.repeat = __temp_p_repeat56;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.AnimationEvent(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.AnimationEvent(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((haxe.lang.Function) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((haxe.root.Array) (arr.__get(3)) ));
	}
	
	
	public  int frame;
	
	public  haxe.root.Array args;
	
	public  haxe.lang.Function listener;
	
	public  int repeat;
	
	public   boolean Dispatch()
	{
		if (( this.listener != null )) 
		{
			this.listener.__hx_invoke1_o(0.0, this);
			if (( this.repeat <= 0 )) 
			{
				return true;
			}
			
			this.repeat--;
			if (( this.repeat <= 0 )) 
			{
				return false;
			}
			
			return true;
		}
		
		return false;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef694 = true;
			switch (field.hashCode())
			{
				case -934531685:
				{
					if (field.equals("repeat")) 
					{
						__temp_executeDef694 = false;
						this.repeat = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 97692013:
				{
					if (field.equals("frame")) 
					{
						__temp_executeDef694 = false;
						this.frame = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef694) 
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
			boolean __temp_executeDef695 = true;
			switch (field.hashCode())
			{
				case -934531685:
				{
					if (field.equals("repeat")) 
					{
						__temp_executeDef695 = false;
						this.repeat = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 97692013:
				{
					if (field.equals("frame")) 
					{
						__temp_executeDef695 = false;
						this.frame = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1346159796:
				{
					if (field.equals("listener")) 
					{
						__temp_executeDef695 = false;
						this.listener = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3002589:
				{
					if (field.equals("args")) 
					{
						__temp_executeDef695 = false;
						this.args = ((haxe.root.Array) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef695) 
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
			boolean __temp_executeDef696 = true;
			switch (field.hashCode())
			{
				case 349415578:
				{
					if (field.equals("Dispatch")) 
					{
						__temp_executeDef696 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Dispatch"))) );
					}
					
					break;
				}
				
				
				case 97692013:
				{
					if (field.equals("frame")) 
					{
						__temp_executeDef696 = false;
						return this.frame;
					}
					
					break;
				}
				
				
				case -934531685:
				{
					if (field.equals("repeat")) 
					{
						__temp_executeDef696 = false;
						return this.repeat;
					}
					
					break;
				}
				
				
				case 3002589:
				{
					if (field.equals("args")) 
					{
						__temp_executeDef696 = false;
						return this.args;
					}
					
					break;
				}
				
				
				case 1346159796:
				{
					if (field.equals("listener")) 
					{
						__temp_executeDef696 = false;
						return this.listener;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef696) 
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
			boolean __temp_executeDef697 = true;
			switch (field.hashCode())
			{
				case -934531685:
				{
					if (field.equals("repeat")) 
					{
						__temp_executeDef697 = false;
						return ((double) (this.repeat) );
					}
					
					break;
				}
				
				
				case 97692013:
				{
					if (field.equals("frame")) 
					{
						__temp_executeDef697 = false;
						return ((double) (this.frame) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef697) 
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
			boolean __temp_executeDef698 = true;
			switch (field.hashCode())
			{
				case 349415578:
				{
					if (field.equals("Dispatch")) 
					{
						__temp_executeDef698 = false;
						return this.Dispatch();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef698) 
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
		baseArr.push("repeat");
		baseArr.push("listener");
		baseArr.push("args");
		baseArr.push("frame");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


