package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class HTTPRequest extends haxor.thread.Task
{
	public    HTTPRequest(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    HTTPRequest(java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.String p_data)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.HTTPRequest.__hx_ctor_haxor_platform_android_HTTPRequest(this, p_url, p_method, p_binary, p_data);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_HTTPRequest(haxor.platform.android.HTTPRequest __temp_me54549, java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.String p_data)
	{
		haxor.thread.Task.__hx_ctor_haxor_thread_Task(__temp_me54549, true, null);
		if (( haxe.lang.StringExt.indexOf(p_url, "./", null) >= 0 )) 
		{
			p_url = haxe.root.StringTools.replace(p_url, "./", haxor.net.Web.root);
		}
		
		__temp_me54549.url = p_url;
		__temp_me54549.binary = p_binary;
		__temp_me54549.method = p_method.toUpperCase();
		__temp_me54549.data = p_data;
		__temp_me54549.contentType = "";
		__temp_me54549.bytesTotal = 0;
		__temp_me54549.bytesLoaded = 0;
		haxor.core.Console.Log(( "HTTPRequest> " + __temp_me54549.url ), 4);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.HTTPRequest(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.HTTPRequest(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toBool(arr.__get(2)), haxe.lang.Runtime.toString(arr.__get(3)));
	}
	
	
	public  java.lang.String url;
	
	public  boolean binary;
	
	public  java.net.HttpURLConnection request;
	
	public  java.lang.String data;
	
	public  java.lang.String method;
	
	public  java.lang.String contentType;
	
	public  java.io.ByteArrayOutputStream response;
	
	public  int bytesLoaded;
	
	public  int bytesTotal;
	
	public  java.lang.Exception error;
	
	public  byte[] m_buffer;
	
	public  java.io.InputStream m_stream;
	
	@Override public   void OnStart()
	{
		try 
		{
			this.request = ((java.net.HttpURLConnection) (haxe.lang.Runtime.callField(((java.lang.Object) (new java.net.URL(haxe.lang.Runtime.toString(this.url))) ), "openConnection", null)) );
			this.request.setRequestMethod(haxe.lang.Runtime.toString(this.method));
			this.contentType = this.request.getHeaderField(haxe.lang.Runtime.toString("Content-Type"));
			this.request.connect();
			this.m_stream = this.request.getInputStream();
			this.bytesTotal = ((int) (this.request.getContentLength()) );
		}
		catch (java.lang.Exception err)
		{
			this.error = err;
			this.OnError();
			this.Cancel();
			return ;
		}
		
		
		this.response = new java.io.ByteArrayOutputStream();
		this.m_buffer = new byte[((int) (1024) )];
	}
	
	
	@Override public   void OnStep()
	{
		int step = 0;
		try 
		{
			step = this.m_stream.read(((byte[]) (this.m_buffer) ));
		}
		catch (java.lang.Exception err)
		{
			this.error = err;
			this.OnError();
			this.Cancel();
			return ;
		}
		
		
		if (( step == 0 )) 
		{
			return ;
		}
		
		if (( step < 0 )) 
		{
			this.bytesLoaded = this.bytesTotal;
			this.set_progress(1.0);
			return ;
		}
		
		this.response.write(((byte[]) (this.m_buffer) ), ((int) (0) ), ((int) (step) ));
		this.bytesLoaded += step;
		double t = ((double) (this.bytesTotal) );
		double l = ((double) (this.bytesLoaded) );
		double r = 0.0;
		if (( t <= 0.0 )) 
		{
			r = 0.0;
		}
		 else 
		{
			r = ( l / t );
		}
		
		if (( r >= 1.0 )) 
		{
			r = 1.0;
		}
		
		this.set_progress(( r * 0.999 ));
	}
	
	
	@Override public   void OnComplete()
	{
		this.request.disconnect();
		haxor.core.Console.Log("complete!", null);
		try 
		{
			this.response.flush();
		}
		catch (java.lang.Exception err)
		{
			this.error = err;
			this.OnError();
			this.Cancel();
			return ;
		}
		
		
		haxor.core.Console.Log(( this.response.size() + " bytes" ), null);
		haxor.core.Console.Log(haxe.lang.StringExt.substr(this.response.toString(), 0, 100), null);
	}
	
	
	public   void OnError()
	{
		haxor.core.Console.Log(( ( "HTTPRequest> Error [" + this.error.getMessage() ) + "]" ), null);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef54816 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef54816 = false;
						this.bytesTotal = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef54816 = false;
						this.bytesLoaded = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54816) 
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
			boolean __temp_executeDef54817 = true;
			switch (field.hashCode())
			{
				case -1490720878:
				{
					if (field.equals("m_stream")) 
					{
						__temp_executeDef54817 = false;
						this.m_stream = ((java.io.InputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef54817 = false;
						this.url = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef54817 = false;
						this.m_buffer = ((byte[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1388966911:
				{
					if (field.equals("binary")) 
					{
						__temp_executeDef54817 = false;
						this.binary = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 96784904:
				{
					if (field.equals("error")) 
					{
						__temp_executeDef54817 = false;
						this.error = ((java.lang.Exception) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef54817 = false;
						this.request = ((java.net.HttpURLConnection) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef54817 = false;
						this.bytesTotal = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef54817 = false;
						this.data = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef54817 = false;
						this.bytesLoaded = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef54817 = false;
						this.method = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef54817 = false;
						this.response = ((java.io.ByteArrayOutputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -389131437:
				{
					if (field.equals("contentType")) 
					{
						__temp_executeDef54817 = false;
						this.contentType = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54817) 
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
			boolean __temp_executeDef54818 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54818 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef54818 = false;
						return this.url;
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef54818 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case -1388966911:
				{
					if (field.equals("binary")) 
					{
						__temp_executeDef54818 = false;
						return this.binary;
					}
					
					break;
				}
				
				
				case -1929089685:
				{
					if (field.equals("OnStep")) 
					{
						__temp_executeDef54818 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStep"))) );
					}
					
					break;
				}
				
				
				case 1095692943:
				{
					if (field.equals("request")) 
					{
						__temp_executeDef54818 = false;
						return this.request;
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef54818 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef54818 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case -1490720878:
				{
					if (field.equals("m_stream")) 
					{
						__temp_executeDef54818 = false;
						return this.m_stream;
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef54818 = false;
						return this.method;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef54818 = false;
						return this.m_buffer;
					}
					
					break;
				}
				
				
				case -389131437:
				{
					if (field.equals("contentType")) 
					{
						__temp_executeDef54818 = false;
						return this.contentType;
					}
					
					break;
				}
				
				
				case 96784904:
				{
					if (field.equals("error")) 
					{
						__temp_executeDef54818 = false;
						return this.error;
					}
					
					break;
				}
				
				
				case -340323263:
				{
					if (field.equals("response")) 
					{
						__temp_executeDef54818 = false;
						return this.response;
					}
					
					break;
				}
				
				
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef54818 = false;
						return this.bytesTotal;
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef54818 = false;
						return this.bytesLoaded;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54818) 
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
			boolean __temp_executeDef54819 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef54819 = false;
						return ((double) (this.bytesTotal) );
					}
					
					break;
				}
				
				
				case -326983600:
				{
					if (field.equals("bytesLoaded")) 
					{
						__temp_executeDef54819 = false;
						return ((double) (this.bytesLoaded) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54819) 
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
			int __temp_hash54821 = field.hashCode();
			boolean __temp_executeDef54820 = true;
			switch (__temp_hash54821)
			{
				case -130994088:case -1929089685:case 327758243:
				{
					if (( (( ( __temp_hash54821 == -130994088 ) && field.equals("OnComplete") )) || ( (( ( __temp_hash54821 == -1929089685 ) && field.equals("OnStep") )) || field.equals("OnStart") ) )) 
					{
						__temp_executeDef54820 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54820 = false;
						this.OnError();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54820) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_stream");
		baseArr.push("m_buffer");
		baseArr.push("error");
		baseArr.push("bytesTotal");
		baseArr.push("bytesLoaded");
		baseArr.push("response");
		baseArr.push("contentType");
		baseArr.push("method");
		baseArr.push("data");
		baseArr.push("request");
		baseArr.push("binary");
		baseArr.push("url");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


