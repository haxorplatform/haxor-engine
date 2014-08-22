package haxor.thread;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Task extends haxor.thread.Activity
{
	public    Task(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Task(java.lang.Object p_threaded, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.thread.Task.__hx_ctor_haxor_thread_Task(this, p_threaded, p_callback);
	}
	
	
	public static   void __hx_ctor_haxor_thread_Task(haxor.thread.Task __temp_me55750, java.lang.Object p_threaded, haxe.lang.Function p_callback)
	{
		boolean __temp_p_threaded55749 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		haxe.lang.Function cb = p_callback;
		if (( cb == null )) 
		{
			cb = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (__temp_me55750) ), haxe.lang.Runtime.toString("OnExecute"))) );
		}
		
		haxor.thread.Activity.__hx_ctor_haxor_thread_Activity(__temp_me55750, cb, __temp_p_threaded55749, null);
		__temp_me55750.m_active = false;
		__temp_me55750.m_progress = 0.0;
		__temp_me55750.m_has_progress = false;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.thread.Task(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.thread.Task(((java.lang.Object) (arr.__get(0)) ), ((haxe.lang.Function) (arr.__get(1)) ));
	}
	
	
	
	
	public final   double get_progress()
	{
		return this.m_progress;
	}
	
	
	public   double set_progress(double v)
	{
		if (( java.lang.Math.abs(( v - this.m_progress )) > 0.0 )) 
		{
			this.m_progress = v;
			this.m_has_progress = true;
		}
		
		return v;
	}
	
	
	public  double m_progress;
	
	public  boolean m_has_progress;
	
	public  boolean active;
	
	public final   boolean get_active()
	{
		return this.m_active;
	}
	
	
	public  boolean m_active;
	
	public   void OnStart()
	{
		{
		}
		
	}
	
	
	public   void OnStep()
	{
		{
		}
		
	}
	
	
	public   void OnComplete()
	{
		{
		}
		
	}
	
	
	public   void OnProgress()
	{
		{
		}
		
	}
	
	
	public   boolean OnExecute(double p_time)
	{
		if ( ! (this.m_active) ) 
		{
			this.m_active = true;
			this.OnStart();
		}
		
		this.OnStep();
		if (this.m_has_progress) 
		{
			this.OnProgress();
			this.m_has_progress = false;
		}
		
		if (( this.m_progress >= 1.0 )) 
		{
			this.OnComplete();
			return false;
		}
		
		return true;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56009 = true;
			switch (field.hashCode())
			{
				case -855695937:
				{
					if (field.equals("m_progress")) 
					{
						__temp_executeDef56009 = false;
						this.m_progress = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1001078227:
				{
					if (field.equals("progress")) 
					{
						__temp_executeDef56009 = false;
						this.set_progress(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56009) 
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
			boolean __temp_executeDef56010 = true;
			switch (field.hashCode())
			{
				case -2021681384:
				{
					if (field.equals("m_active")) 
					{
						__temp_executeDef56010 = false;
						this.m_active = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1001078227:
				{
					if (field.equals("progress")) 
					{
						__temp_executeDef56010 = false;
						this.set_progress(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1422950650:
				{
					if (field.equals("active")) 
					{
						__temp_executeDef56010 = false;
						this.active = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -855695937:
				{
					if (field.equals("m_progress")) 
					{
						__temp_executeDef56010 = false;
						this.m_progress = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1080495932:
				{
					if (field.equals("m_has_progress")) 
					{
						__temp_executeDef56010 = false;
						this.m_has_progress = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56010) 
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
			boolean __temp_executeDef56011 = true;
			switch (field.hashCode())
			{
				case 2020677750:
				{
					if (field.equals("OnExecute")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnExecute"))) );
					}
					
					break;
				}
				
				
				case -1001078227:
				{
					if (field.equals("progress")) 
					{
						__temp_executeDef56011 = false;
						return this.get_progress();
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnProgress"))) );
					}
					
					break;
				}
				
				
				case 1370834166:
				{
					if (field.equals("get_progress")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_progress"))) );
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case -1375140502:
				{
					if (field.equals("set_progress")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_progress"))) );
					}
					
					break;
				}
				
				
				case -1929089685:
				{
					if (field.equals("OnStep")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStep"))) );
					}
					
					break;
				}
				
				
				case -855695937:
				{
					if (field.equals("m_progress")) 
					{
						__temp_executeDef56011 = false;
						return this.m_progress;
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case -1080495932:
				{
					if (field.equals("m_has_progress")) 
					{
						__temp_executeDef56011 = false;
						return this.m_has_progress;
					}
					
					break;
				}
				
				
				case -2021681384:
				{
					if (field.equals("m_active")) 
					{
						__temp_executeDef56011 = false;
						return this.m_active;
					}
					
					break;
				}
				
				
				case -1422950650:
				{
					if (field.equals("active")) 
					{
						__temp_executeDef56011 = false;
						if (handleProperties) 
						{
							return this.get_active();
						}
						 else 
						{
							return this.active;
						}
						
					}
					
					break;
				}
				
				
				case 657727503:
				{
					if (field.equals("get_active")) 
					{
						__temp_executeDef56011 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_active"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56011) 
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
			boolean __temp_executeDef56012 = true;
			switch (field.hashCode())
			{
				case -855695937:
				{
					if (field.equals("m_progress")) 
					{
						__temp_executeDef56012 = false;
						return this.m_progress;
					}
					
					break;
				}
				
				
				case -1001078227:
				{
					if (field.equals("progress")) 
					{
						__temp_executeDef56012 = false;
						return this.get_progress();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56012) 
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
			boolean __temp_executeDef56013 = true;
			switch (field.hashCode())
			{
				case 2020677750:
				{
					if (field.equals("OnExecute")) 
					{
						__temp_executeDef56013 = false;
						return this.OnExecute(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1370834166:
				{
					if (field.equals("get_progress")) 
					{
						__temp_executeDef56013 = false;
						return this.get_progress();
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef56013 = false;
						this.OnProgress();
					}
					
					break;
				}
				
				
				case -1375140502:
				{
					if (field.equals("set_progress")) 
					{
						__temp_executeDef56013 = false;
						return this.set_progress(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef56013 = false;
						this.OnComplete();
					}
					
					break;
				}
				
				
				case 657727503:
				{
					if (field.equals("get_active")) 
					{
						__temp_executeDef56013 = false;
						return this.get_active();
					}
					
					break;
				}
				
				
				case -1929089685:
				{
					if (field.equals("OnStep")) 
					{
						__temp_executeDef56013 = false;
						this.OnStep();
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef56013 = false;
						this.OnStart();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56013) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_active");
		baseArr.push("active");
		baseArr.push("m_has_progress");
		baseArr.push("m_progress");
		baseArr.push("progress");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


