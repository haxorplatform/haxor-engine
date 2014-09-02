package haxor.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class HTTPRequestTask<T, U> extends haxor.thread.Task
{
	public    HTTPRequestTask(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    HTTPRequestTask(java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.Object p_data)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.net.HTTPRequestTask.__hx_ctor_haxor_net_HTTPRequestTask(this, p_url, p_method, p_binary, p_data);
	}
	
	
	public static  <T_c, U_c> void __hx_ctor_haxor_net_HTTPRequestTask(haxor.net.HTTPRequestTask<T_c, U_c> __temp_me160694, java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.Object p_data)
	{
		haxor.thread.Task.__hx_ctor_haxor_thread_Task(__temp_me160694, null, null);
		if (( haxe.lang.StringExt.indexOf(p_url, "./", null) >= 0 )) 
		{
			p_url = haxe.root.StringTools.replace(p_url, "./", haxor.net.Web.root);
		}
		
		__temp_me160694.url = p_url;
		__temp_me160694.binary = p_binary;
		__temp_me160694.method = p_method;
		__temp_me160694.data = p_data;
		__temp_me160694.bytesLoaded = 0;
		__temp_me160694.bytesTotal = 0;
		__temp_me160694.error = "";
		haxor.core.Console.Log(( "HTTPRequest> " + __temp_me160694.url ), 4);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.net.HTTPRequestTask<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.net.HTTPRequestTask<java.lang.Object, java.lang.Object>(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toBool(arr.__get(2)), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	public  java.lang.String url;
	
	public  T request;
	
	public  U response;
	
	public  boolean binary;
	
	public  java.lang.String method;
	
	public  java.lang.Object data;
	
	public  int bytesLoaded;
	
	public  int bytesTotal;
	
	public  java.lang.String error;
	
	@Override public   void OnStart()
	{
		{
		}
		
	}
	
	
	public   void OnError()
	{
		haxor.core.Console.LogError(( ( "HTTPRequest> Error [" + this.error ) + "]" ), null);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161598 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef161598 = false;
						this.bytesTotal = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef161598 = false;
						this.request = ((T) (((java.lang.Object) (value) )) );
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (value) ))) );
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef161598 = false;
						this.bytesLoaded = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef161598 = false;
						this.response = ((U) (((java.lang.Object) (value) )) );
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (value) ))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef161598 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161598) 
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
			boolean __temp_executeDef161599 = true;
			switch (field.hashCode())
			{
				case 96784904:
				{
					if (field.equals("error")) 
					{
						__temp_executeDef161599 = false;
						this.error = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef161599 = false;
						this.url = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef161599 = false;
						this.bytesTotal = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef161599 = false;
						this.request = ((T) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef161599 = false;
						this.bytesLoaded = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef161599 = false;
						this.response = ((U) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef161599 = false;
						this.data = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1388966911:
				{
					if (field.equals("binary")) 
					{
						__temp_executeDef161599 = false;
						this.binary = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef161599 = false;
						this.method = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161599) 
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
			boolean __temp_executeDef161600 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef161600 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef161600 = false;
						return this.url;
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef161600 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef161600 = false;
						return this.request;
					}
					
					break;
				}
				
				
				case 96784904:
				{
					if (field.equals("error")) 
					{
						__temp_executeDef161600 = false;
						return this.error;
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef161600 = false;
						return this.response;
					}
					
					break;
				}
				
				
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef161600 = false;
						return this.bytesTotal;
					}
					
					break;
				}
				
				
				case -1388966911:
				{
					if (field.equals("binary")) 
					{
						__temp_executeDef161600 = false;
						return this.binary;
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef161600 = false;
						return this.bytesLoaded;
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef161600 = false;
						return this.method;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef161600 = false;
						return this.data;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161600) 
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
			boolean __temp_executeDef161601 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef161601 = false;
						return ((double) (this.bytesTotal) );
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef161601 = false;
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (this.request) ))) );
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef161601 = false;
						return ((double) (this.bytesLoaded) );
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef161601 = false;
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (this.response) ))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef161601 = false;
						return ((double) (haxe.lang.Runtime.toDouble(this.data)) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161601) 
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
			boolean __temp_executeDef161602 = true;
			switch (field.hashCode())
			{
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef161602 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef161602 = false;
						this.OnError();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161602) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("error");
		baseArr.push("bytesTotal");
		baseArr.push("bytesLoaded");
		baseArr.push("data");
		baseArr.push("method");
		baseArr.push("binary");
		baseArr.push("response");
		baseArr.push("request");
		baseArr.push("url");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


