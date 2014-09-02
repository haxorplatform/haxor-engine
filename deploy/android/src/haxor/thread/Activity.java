package haxor.thread;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Activity extends haxor.core.Resource implements java.lang.Runnable, haxor.core.IRenderable, haxor.core.IUpdateable
{
	static 
	{
		haxor.thread.Activity.__meta__ = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fields"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"run"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"overload"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{null}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	public    Activity(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Activity(haxe.lang.Function p_callback, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.thread.Activity.__hx_ctor_haxor_thread_Activity(this, p_callback, p_threaded, p_graphics_context);
	}
	
	
	public static   void __hx_ctor_haxor_thread_Activity(haxor.thread.Activity __temp_me160691, haxe.lang.Function p_callback, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me160691, null);
		boolean __temp_p_graphics_context160690 = ( (( p_graphics_context == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_graphics_context)) );
		boolean __temp_p_threaded160689 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		if (( p_callback == null )) 
		{
			return ;
		}
		
		__temp_me160691.m_time_start = haxor.core.Time.m_elapsed;
		__temp_me160691.m_elapsed = 0.0;
		__temp_me160691.m_callback = p_callback;
		__temp_me160691.m_cancelled = false;
		if (__temp_p_graphics_context160690) 
		{
			__temp_p_threaded160689 = false;
		}
		
		if ( ! (__temp_p_threaded160689) ) 
		{
			if (__temp_p_graphics_context160690) 
			{
				haxor.context.EngineContext.render.Add(__temp_me160691);
			}
			 else 
			{
				haxor.context.EngineContext.update.Add(__temp_me160691);
			}
			
		}
		 else 
		{
			java.lang.Thread thread = new java.lang.Thread(((java.lang.Runnable) (__temp_me160691) ));
			thread.start();
		}
		
	}
	
	
	public static  java.lang.Object __meta__;
	
	public static   haxor.thread.Activity Iterate(int p_offset, int p_length, haxe.lang.Function p_callback, java.lang.Object p_step, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		boolean __temp_p_graphics_context160682 = ( (( p_graphics_context == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_graphics_context)) );
		boolean __temp_p_threaded160681 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		int __temp_p_step160680 = ( (( p_step == null )) ? (((int) (1) )) : (((int) (haxe.lang.Runtime.toInt(p_step)) )) );
		haxe.root.Array<java.lang.Object> p_step1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_p_step160680});
		haxe.root.Array<haxe.lang.Function> p_callback1 = new haxe.root.Array<haxe.lang.Function>(new haxe.lang.Function[]{p_callback});
		haxe.root.Array<java.lang.Object> p_length1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{p_length});
		haxe.root.Array<java.lang.Object> it = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{p_offset});
		return new haxor.thread.Activity(((haxe.lang.Function) (new haxor.thread.Activity_Iterate_41__Fun(((haxe.root.Array<java.lang.Object>) (p_step1) ), ((haxe.root.Array<java.lang.Object>) (p_length1) ), ((haxe.root.Array<java.lang.Object>) (it) ), ((haxe.root.Array<haxe.lang.Function>) (p_callback1) ))) ), ((java.lang.Object) (__temp_p_threaded160681) ), ((java.lang.Object) (__temp_p_graphics_context160682) ));
	}
	
	
	public static   haxor.thread.Activity Delay(double p_time, haxe.lang.Function p_callback, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		boolean __temp_p_graphics_context160684 = ( (( p_graphics_context == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_graphics_context)) );
		boolean __temp_p_threaded160683 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		haxe.root.Array<haxe.lang.Function> p_callback1 = new haxe.root.Array<haxe.lang.Function>(new haxe.lang.Function[]{p_callback});
		haxe.root.Array<java.lang.Object> p_time1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (p_time) )});
		return new haxor.thread.Activity(((haxe.lang.Function) (new haxor.thread.Activity_Delay_62__Fun(((haxe.root.Array<java.lang.Object>) (p_time1) ), ((haxe.root.Array<haxe.lang.Function>) (p_callback1) ))) ), ((java.lang.Object) (__temp_p_threaded160683) ), ((java.lang.Object) (__temp_p_graphics_context160684) ));
	}
	
	
	public static   haxor.thread.Activity Run(haxe.lang.Function p_callback, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		boolean __temp_p_graphics_context160686 = ( (( p_graphics_context == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_graphics_context)) );
		boolean __temp_p_threaded160685 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		return new haxor.thread.Activity(((haxe.lang.Function) (p_callback) ), ((java.lang.Object) (__temp_p_threaded160685) ), ((java.lang.Object) (__temp_p_graphics_context160686) ));
	}
	
	
	public static   haxor.thread.Activity RunOnce(haxe.lang.Function p_callback, java.lang.Object p_threaded, java.lang.Object p_graphics_context)
	{
		boolean __temp_p_graphics_context160688 = ( (( p_graphics_context == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_graphics_context)) );
		boolean __temp_p_threaded160687 = ( (( p_threaded == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_threaded)) );
		haxe.root.Array<haxe.lang.Function> p_callback1 = new haxe.root.Array<haxe.lang.Function>(new haxe.lang.Function[]{p_callback});
		return new haxor.thread.Activity(((haxe.lang.Function) (new haxor.thread.Activity_RunOnce_93__Fun(((haxe.root.Array<haxe.lang.Function>) (p_callback1) ))) ), ((java.lang.Object) (__temp_p_threaded160687) ), ((java.lang.Object) (__temp_p_graphics_context160688) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.thread.Activity(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.thread.Activity(((haxe.lang.Function) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ));
	}
	
	
	public  haxe.lang.Function m_callback;
	
	public  double m_time_start;
	
	public  double elapsed;
	
	public final   double get_elapsed()
	{
		return this.m_elapsed;
	}
	
	
	public  double m_elapsed;
	
	public  boolean m_cancelled;
	
	public   void Cancel()
	{
		this.m_cancelled = true;
	}
	
	
	public   void OnUpdate()
	{
		this.OnRun();
	}
	
	
	public   void OnRender()
	{
		this.OnRun();
	}
	
	
	public   void OnRun()
	{
		if (this.m_cancelled) 
		{
			haxor.core.Resource.Destroy(this);
			return ;
		}
		
		this.m_elapsed = ( haxor.core.Time.m_elapsed - this.m_time_start );
		if ( ! (haxe.lang.Runtime.toBool(this.m_callback.__hx_invoke1_o(this.m_elapsed, haxe.lang.Runtime.undefined))) ) 
		{
			haxor.core.Resource.Destroy(this);
		}
		
	}
	
	
	public   void run()
	{
		while (true)
		{
			if (this.m_cancelled) 
			{
				break;
			}
			
			if ( ! (haxe.lang.Runtime.toBool(this.m_callback.__hx_invoke1_o(this.m_elapsed, haxe.lang.Runtime.undefined))) ) 
			{
				break;
			}
			
			this.m_elapsed += 0.0001;
			haxe.root.Sys.sleep(0.0001);
		}
		
		haxor.core.Resource.Destroy(this);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161587 = true;
			switch (field.hashCode())
			{
				case 1247755178:
				{
					if (field.equals("m_elapsed")) 
					{
						__temp_executeDef161587 = false;
						this.m_elapsed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -885576830:
				{
					if (field.equals("m_time_start")) 
					{
						__temp_executeDef161587 = false;
						this.m_time_start = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1666428548:
				{
					if (field.equals("elapsed")) 
					{
						__temp_executeDef161587 = false;
						this.elapsed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161587) 
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
			boolean __temp_executeDef161588 = true;
			switch (field.hashCode())
			{
				case 688472063:
				{
					if (field.equals("m_cancelled")) 
					{
						__temp_executeDef161588 = false;
						this.m_cancelled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -26838057:
				{
					if (field.equals("m_callback")) 
					{
						__temp_executeDef161588 = false;
						this.m_callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1247755178:
				{
					if (field.equals("m_elapsed")) 
					{
						__temp_executeDef161588 = false;
						this.m_elapsed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -885576830:
				{
					if (field.equals("m_time_start")) 
					{
						__temp_executeDef161588 = false;
						this.m_time_start = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1666428548:
				{
					if (field.equals("elapsed")) 
					{
						__temp_executeDef161588 = false;
						this.elapsed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161588) 
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
			boolean __temp_executeDef161589 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("run"))) );
					}
					
					break;
				}
				
				
				case -26838057:
				{
					if (field.equals("m_callback")) 
					{
						__temp_executeDef161589 = false;
						return this.m_callback;
					}
					
					break;
				}
				
				
				case 76317708:
				{
					if (field.equals("OnRun")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRun"))) );
					}
					
					break;
				}
				
				
				case -885576830:
				{
					if (field.equals("m_time_start")) 
					{
						__temp_executeDef161589 = false;
						return this.m_time_start;
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case -1666428548:
				{
					if (field.equals("elapsed")) 
					{
						__temp_executeDef161589 = false;
						if (handleProperties) 
						{
							return this.get_elapsed();
						}
						 else 
						{
							return this.elapsed;
						}
						
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -1589915245:
				{
					if (field.equals("get_elapsed")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_elapsed"))) );
					}
					
					break;
				}
				
				
				case 2011110042:
				{
					if (field.equals("Cancel")) 
					{
						__temp_executeDef161589 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Cancel"))) );
					}
					
					break;
				}
				
				
				case 1247755178:
				{
					if (field.equals("m_elapsed")) 
					{
						__temp_executeDef161589 = false;
						return this.m_elapsed;
					}
					
					break;
				}
				
				
				case 688472063:
				{
					if (field.equals("m_cancelled")) 
					{
						__temp_executeDef161589 = false;
						return this.m_cancelled;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161589) 
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
			boolean __temp_executeDef161590 = true;
			switch (field.hashCode())
			{
				case 1247755178:
				{
					if (field.equals("m_elapsed")) 
					{
						__temp_executeDef161590 = false;
						return this.m_elapsed;
					}
					
					break;
				}
				
				
				case -885576830:
				{
					if (field.equals("m_time_start")) 
					{
						__temp_executeDef161590 = false;
						return this.m_time_start;
					}
					
					break;
				}
				
				
				case -1666428548:
				{
					if (field.equals("elapsed")) 
					{
						__temp_executeDef161590 = false;
						if (handleProperties) 
						{
							return this.get_elapsed();
						}
						 else 
						{
							return this.elapsed;
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161590) 
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
			boolean __temp_executeDef161591 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef161591 = false;
						this.run();
					}
					
					break;
				}
				
				
				case -1589915245:
				{
					if (field.equals("get_elapsed")) 
					{
						__temp_executeDef161591 = false;
						return this.get_elapsed();
					}
					
					break;
				}
				
				
				case 76317708:
				{
					if (field.equals("OnRun")) 
					{
						__temp_executeDef161591 = false;
						this.OnRun();
					}
					
					break;
				}
				
				
				case 2011110042:
				{
					if (field.equals("Cancel")) 
					{
						__temp_executeDef161591 = false;
						this.Cancel();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef161591 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef161591 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161591) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_cancelled");
		baseArr.push("m_elapsed");
		baseArr.push("elapsed");
		baseArr.push("m_time_start");
		baseArr.push("m_callback");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


