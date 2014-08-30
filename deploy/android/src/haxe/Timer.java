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
	
	
	public    Timer(int time_ms)
	{
		haxe.Timer.__hx_ctor_haxe_Timer(this, time_ms);
	}
	
	
	public static   void __hx_ctor_haxe_Timer(haxe.Timer __temp_me151282, int time_ms)
	{
		__temp_me151282.run = ( (( haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current != null )) ? (haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current) : (haxe.Timer___hx_ctor_haxe_Timer_113__Fun.__hx_current = ((haxe.Timer___hx_ctor_haxe_Timer_113__Fun) (new haxe.Timer___hx_ctor_haxe_Timer_113__Fun()) )) );
		__temp_me151282.timer = new java.util.Timer();
		__temp_me151282.timer.scheduleAtFixedRate(((java.util.TimerTask) (__temp_me151282.task = new haxe._Timer.TimerTask(((haxe.Timer) (__temp_me151282) ))) ), ((long) (time_ms) ), ((long) (time_ms) ));
	}
	
	
	public static   haxe.Timer delay(haxe.lang.Function f, int time_ms)
	{
		haxe.root.Array<haxe.lang.Function> f1 = new haxe.root.Array<haxe.lang.Function>(new haxe.lang.Function[]{f});
		haxe.root.Array<haxe.Timer> t = new haxe.root.Array<haxe.Timer>(new haxe.Timer[]{new haxe.Timer(((int) (time_ms) ))});
		t.__get(0).run = new haxe.Timer_delay_128__Fun(((haxe.root.Array<haxe.lang.Function>) (f1) ), ((haxe.root.Array<haxe.Timer>) (t) ));
		return t.__get(0);
	}
	
	
	public static  <T> T measure(haxe.lang.Function f, java.lang.Object pos)
	{
		double t0 = haxe.Timer.stamp();
		T r = ((T) (f.__hx_invoke0_o()) );
		haxe.Log.trace.__hx_invoke2_o(0.0, ( haxe.lang.Runtime.toString(( haxe.Timer.stamp() - t0 )) + "s" ), 0.0, pos);
		return r;
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
		return new haxe.Timer(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	public  java.util.Timer timer;
	
	public  java.util.TimerTask task;
	
	public   void stop()
	{
		this.timer.cancel();
		this.timer = null;
		this.task = null;
	}
	
	
	public  haxe.lang.Function run;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151701 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef151701 = false;
						this.run = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 110364485:
				{
					if (field.equals("timer")) 
					{
						__temp_executeDef151701 = false;
						this.timer = ((java.util.Timer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3552645:
				{
					if (field.equals("task")) 
					{
						__temp_executeDef151701 = false;
						this.task = ((java.util.TimerTask) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151701) 
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
			boolean __temp_executeDef151702 = true;
			switch (field.hashCode())
			{
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef151702 = false;
						return this.run;
					}
					
					break;
				}
				
				
				case 110364485:
				{
					if (field.equals("timer")) 
					{
						__temp_executeDef151702 = false;
						return this.timer;
					}
					
					break;
				}
				
				
				case 3540994:
				{
					if (field.equals("stop")) 
					{
						__temp_executeDef151702 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("stop"))) );
					}
					
					break;
				}
				
				
				case 3552645:
				{
					if (field.equals("task")) 
					{
						__temp_executeDef151702 = false;
						return this.task;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151702) 
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
			boolean __temp_executeDef151703 = true;
			switch (field.hashCode())
			{
				case 3540994:
				{
					if (field.equals("stop")) 
					{
						__temp_executeDef151703 = false;
						this.stop();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151703) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("run");
		baseArr.push("task");
		baseArr.push("timer");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


