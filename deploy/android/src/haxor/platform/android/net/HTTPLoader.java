package haxor.platform.android.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class HTTPLoader<T> extends haxor.platform.android.net.HTTPRequest
{
	public    HTTPLoader(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    HTTPLoader(java.lang.String p_url, boolean p_binary, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.net.HTTPLoader.__hx_ctor_haxor_platform_android_net_HTTPLoader(this, p_url, p_binary, p_callback);
	}
	
	
	public static  <T_c> void __hx_ctor_haxor_platform_android_net_HTTPLoader(haxor.platform.android.net.HTTPLoader<T_c> __temp_me56230, java.lang.String p_url, boolean p_binary, haxe.lang.Function p_callback)
	{
		haxor.platform.android.net.HTTPRequest.__hx_ctor_haxor_platform_android_net_HTTPRequest(__temp_me56230, p_url, "GET", p_binary, null);
		__temp_me56230.callback = p_callback;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.net.HTTPLoader<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.net.HTTPLoader<java.lang.Object>(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toBool(arr.__get(1)), ((haxe.lang.Function) (arr.__get(2)) ));
	}
	
	
	public  haxe.lang.Function callback;
	
	@Override public   void OnStart()
	{
		super.OnStart();
		if (( this.callback != null )) 
		{
			this.callback.__hx_invoke2_o(0.0, null, 0.0, haxe.lang.Runtime.undefined);
		}
		
	}
	
	
	@Override public   void OnProgress()
	{
		if (( this.callback != null )) 
		{
			this.callback.__hx_invoke2_o(0.0, null, ( this.m_progress * 0.9999 ), haxe.lang.Runtime.undefined);
		}
		
	}
	
	
	@Override public   void OnComplete()
	{
		if (( this.callback == null )) 
		{
			return ;
		}
		
		if (this.binary) 
		{
			byte[] bl = this.response.toByteArray();
			haxor.io.Buffer b = new haxor.io.Buffer(((int) (bl.length) ));
			b.m_buffer.put(((byte[]) (bl) ));
			b.m_buffer.position(((int) (0) ));
			if (( this.callback != null )) 
			{
				this.callback.__hx_invoke2_o(0.0, ((T) (((java.lang.Object) (b) )) ), 1.0, haxe.lang.Runtime.undefined);
			}
			
		}
		 else 
		{
			if (( this.callback != null )) 
			{
				this.callback.__hx_invoke2_o(0.0, ((T) (((java.lang.Object) (this.response.toString()) )) ), 1.0, haxe.lang.Runtime.undefined);
			}
			
		}
		
	}
	
	
	@Override public   void OnError()
	{
		super.OnError();
		if (( this.callback != null )) 
		{
			this.callback.__hx_invoke2_o(0.0, null, 1.0, haxe.lang.Runtime.undefined);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56581 = true;
			switch (field.hashCode())
			{
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef56581 = false;
						this.callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56581) 
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
			boolean __temp_executeDef56582 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef56582 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef56582 = false;
						return this.callback;
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef56582 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef56582 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef56582 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnProgress"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56582) 
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
		baseArr.push("callback");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


