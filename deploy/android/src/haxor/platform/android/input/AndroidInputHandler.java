package haxor.platform.android.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AndroidInputHandler extends haxor.input.InputHandler
{
	public    AndroidInputHandler(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    AndroidInputHandler()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.input.AndroidInputHandler.__hx_ctor_haxor_platform_android_input_AndroidInputHandler(this);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_input_AndroidInputHandler(haxor.platform.android.input.AndroidInputHandler __temp_me151590)
	{
		__temp_me151590.m_tf = new haxe.root.Array<android.view.MotionEvent>(new android.view.MotionEvent[]{});
		__temp_me151590.m_tb = new haxe.root.Array<android.view.MotionEvent>(new android.view.MotionEvent[]{});
		haxor.input.InputHandler.__hx_ctor_haxor_input_InputHandler(__temp_me151590);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.input.AndroidInputHandler(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.input.AndroidInputHandler();
	}
	
	
	public  haxe.root.Array<android.view.MotionEvent> m_tf;
	
	public  haxe.root.Array<android.view.MotionEvent> m_tb;
	
	public   void OnTouchEvent(android.view.MotionEvent p_event)
	{
		this.ProcessTouchEvent(p_event);
	}
	
	
	@Override public   void UpdateInput()
	{
		{
		}
		
	}
	
	
	public   void ProcessTouchEvent(android.view.MotionEvent p_event)
	{
		if (( p_event == null )) 
		{
			return ;
		}
		
		int action = p_event.getActionMasked();
		int aid = p_event.getActionIndex();
		int id = p_event.getPointerId(((int) (aid) ));
		double px = 0.0;
		double py = 0.0;
		if (( aid >= 0 )) 
		{
			px = ((double) (p_event.getX(((int) (aid) ))) );
		}
		
		if (( aid >= 0 )) 
		{
			py = ((double) (p_event.getY(((int) (aid) ))) );
		}
		
		{
			int __temp_switch152494 = (action);
			if (( __temp_switch152494 == android.view.MotionEvent.ACTION_DOWN )) 
			{
				this.OnTouchStart(id, px, py, null, null, null, null);
			}
			 else 
			{
				if (( __temp_switch152494 == android.view.MotionEvent.ACTION_CANCEL )) 
				{
					this.OnTouchCancel(id);
				}
				 else 
				{
					if (( __temp_switch152494 == android.view.MotionEvent.ACTION_UP )) 
					{
						this.OnTouchEnd(id);
					}
					 else 
					{
						if (( __temp_switch152494 == android.view.MotionEvent.ACTION_POINTER_DOWN )) 
						{
							this.OnTouchStart(id, px, py, null, null, null, null);
						}
						 else 
						{
							if (( __temp_switch152494 == android.view.MotionEvent.ACTION_POINTER_UP )) 
							{
								this.OnTouchEnd(id);
							}
							 else 
							{
								if (( __temp_switch152494 == android.view.MotionEvent.ACTION_MOVE )) 
								{
									int _g1 = 0;
									int _g = p_event.getPointerCount();
									while (( _g1 < _g ))
									{
										int i = _g1++;
										if (( i >= p_event.getPointerCount() )) 
										{
											break;
										}
										
										id = p_event.getPointerId(((int) (i) ));
										int idx = p_event.findPointerIndex(((int) (id) ));
										if (( idx >= 0 )) 
										{
											px = ((double) (p_event.getX(((int) (idx) ))) );
										}
										
										if (( idx >= 0 )) 
										{
											py = ((double) (p_event.getY(((int) (idx) ))) );
										}
										
										this.OnTouchMove(id, px, py);
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   java.lang.String ActionToString(int a)
	{
		{
			int __temp_switch152495 = (a);
			if (( __temp_switch152495 == android.view.MotionEvent.ACTION_DOWN )) 
			{
				return "down";
			}
			 else 
			{
				if (( __temp_switch152495 == android.view.MotionEvent.ACTION_MOVE )) 
				{
					return "move";
				}
				 else 
				{
					if (( __temp_switch152495 == android.view.MotionEvent.ACTION_POINTER_DOWN )) 
					{
						return "pointer_down";
					}
					 else 
					{
						if (( __temp_switch152495 == android.view.MotionEvent.ACTION_UP )) 
						{
							return "up";
						}
						 else 
						{
							if (( __temp_switch152495 == android.view.MotionEvent.ACTION_POINTER_UP )) 
							{
								return "pointer_up";
							}
							 else 
							{
								if (( __temp_switch152495 == android.view.MotionEvent.ACTION_OUTSIDE )) 
								{
									return "outside";
								}
								 else 
								{
									if (( __temp_switch152495 == android.view.MotionEvent.ACTION_CANCEL )) 
									{
										return "cancel";
									}
									
								}
								
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
		return ( "#" + a );
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152496 = true;
			switch (field.hashCode())
			{
				case 3342208:
				{
					if (field.equals("m_tb")) 
					{
						__temp_executeDef152496 = false;
						this.m_tb = ((haxe.root.Array<android.view.MotionEvent>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3342212:
				{
					if (field.equals("m_tf")) 
					{
						__temp_executeDef152496 = false;
						this.m_tf = ((haxe.root.Array<android.view.MotionEvent>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152496) 
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
			boolean __temp_executeDef152497 = true;
			switch (field.hashCode())
			{
				case 1601727202:
				{
					if (field.equals("ActionToString")) 
					{
						__temp_executeDef152497 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ActionToString"))) );
					}
					
					break;
				}
				
				
				case 3342212:
				{
					if (field.equals("m_tf")) 
					{
						__temp_executeDef152497 = false;
						return this.m_tf;
					}
					
					break;
				}
				
				
				case 2120257098:
				{
					if (field.equals("ProcessTouchEvent")) 
					{
						__temp_executeDef152497 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ProcessTouchEvent"))) );
					}
					
					break;
				}
				
				
				case 3342208:
				{
					if (field.equals("m_tb")) 
					{
						__temp_executeDef152497 = false;
						return this.m_tb;
					}
					
					break;
				}
				
				
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef152497 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateInput"))) );
					}
					
					break;
				}
				
				
				case 1883899386:
				{
					if (field.equals("OnTouchEvent")) 
					{
						__temp_executeDef152497 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTouchEvent"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152497) 
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
			boolean __temp_executeDef152498 = true;
			switch (field.hashCode())
			{
				case 1073933409:
				{
					if (field.equals("UpdateInput")) 
					{
						__temp_executeDef152498 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1883899386:
				{
					if (field.equals("OnTouchEvent")) 
					{
						__temp_executeDef152498 = false;
						this.OnTouchEvent(((android.view.MotionEvent) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1601727202:
				{
					if (field.equals("ActionToString")) 
					{
						__temp_executeDef152498 = false;
						return this.ActionToString(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2120257098:
				{
					if (field.equals("ProcessTouchEvent")) 
					{
						__temp_executeDef152498 = false;
						this.ProcessTouchEvent(((android.view.MotionEvent) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152498) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_tb");
		baseArr.push("m_tf");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


