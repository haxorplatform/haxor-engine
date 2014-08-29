package sys.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Process extends haxe.lang.HxObject
{
	public    Process(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Process(java.lang.String cmd, haxe.root.Array<java.lang.String> args)
	{
		sys.io.Process.__hx_ctor_sys_io_Process(this, cmd, args);
	}
	
	
	public static   void __hx_ctor_sys_io_Process(sys.io.Process __temp_me80848, java.lang.String cmd, haxe.root.Array<java.lang.String> args)
	{
		java.lang.String[] pargs = new java.lang.String[((int) (( args.length + 1 )) )];
		pargs[0] = cmd;
		{
			int _g1 = 0;
			int _g = args.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				pargs[( i + 1 )] = args.__get(i);
			}
			
		}
		
		try 
		{
			__temp_me80848.proc = new java.lang.ProcessBuilder(((java.lang.String[]) (pargs) )).start();
		}
		catch (java.lang.Throwable __temp_catchallException81745)
		{
			java.lang.Object __temp_catchall81746 = __temp_catchallException81745;
			if (( __temp_catchall81746 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall81746 = ((haxe.lang.HaxeException) (__temp_catchallException81745) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall81746;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
		java.lang.Process p = __temp_me80848.proc;
		__temp_me80848.stderr = new sys.io._Process.ProcessInput(((java.io.InputStream) (p.getErrorStream()) ));
		__temp_me80848.stdout = new sys.io._Process.ProcessInput(((java.io.InputStream) (p.getInputStream()) ));
		__temp_me80848.stdin = new haxe.java.io.NativeOutput(((java.io.OutputStream) (p.getOutputStream()) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new sys.io.Process(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new sys.io.Process(haxe.lang.Runtime.toString(arr.__get(0)), ((haxe.root.Array<java.lang.String>) (arr.__get(1)) ));
	}
	
	
	public  haxe.io.Input stdout;
	
	public  haxe.io.Input stderr;
	
	public  haxe.io.Output stdin;
	
	public  java.lang.Process proc;
	
	public   int getPid()
	{
		if (haxe.root.Reflect.hasField(this.proc, "pid")) 
		{
			return ((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.getField(this.proc, "pid", false))) );
		}
		
		return -1;
	}
	
	
	public   int exitCode()
	{
		(((sys.io._Process.ProcessInput) (this.stdout) )).bufferContents();
		(((sys.io._Process.ProcessInput) (this.stderr) )).bufferContents();
		try 
		{
			this.proc.waitFor();
		}
		catch (java.lang.Throwable __temp_catchallException81740)
		{
			java.lang.Object __temp_catchall81741 = __temp_catchallException81740;
			if (( __temp_catchall81741 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall81741 = ((haxe.lang.HaxeException) (__temp_catchallException81740) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall81741;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
		return this.proc.exitValue();
	}
	
	
	public   void close()
	{
		this.proc.destroy();
	}
	
	
	public   void kill()
	{
		this.proc.destroy();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81742 = true;
			switch (field.hashCode())
			{
				case 3449686:
				{
					if (field.equals("proc")) 
					{
						__temp_executeDef81742 = false;
						this.proc = ((java.lang.Process) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -892396981:
				{
					if (field.equals("stdout")) 
					{
						__temp_executeDef81742 = false;
						this.stdout = ((haxe.io.Input) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109760136:
				{
					if (field.equals("stdin")) 
					{
						__temp_executeDef81742 = false;
						this.stdin = ((haxe.io.Output) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -892406686:
				{
					if (field.equals("stderr")) 
					{
						__temp_executeDef81742 = false;
						this.stderr = ((haxe.io.Input) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81742) 
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
			boolean __temp_executeDef81743 = true;
			switch (field.hashCode())
			{
				case 3291998:
				{
					if (field.equals("kill")) 
					{
						__temp_executeDef81743 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("kill"))) );
					}
					
					break;
				}
				
				
				case -892396981:
				{
					if (field.equals("stdout")) 
					{
						__temp_executeDef81743 = false;
						return this.stdout;
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef81743 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case -892406686:
				{
					if (field.equals("stderr")) 
					{
						__temp_executeDef81743 = false;
						return this.stderr;
					}
					
					break;
				}
				
				
				case -2123228117:
				{
					if (field.equals("exitCode")) 
					{
						__temp_executeDef81743 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exitCode"))) );
					}
					
					break;
				}
				
				
				case 109760136:
				{
					if (field.equals("stdin")) 
					{
						__temp_executeDef81743 = false;
						return this.stdin;
					}
					
					break;
				}
				
				
				case -1249353131:
				{
					if (field.equals("getPid")) 
					{
						__temp_executeDef81743 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPid"))) );
					}
					
					break;
				}
				
				
				case 3449686:
				{
					if (field.equals("proc")) 
					{
						__temp_executeDef81743 = false;
						return this.proc;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81743) 
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
			boolean __temp_executeDef81744 = true;
			switch (field.hashCode())
			{
				case 3291998:
				{
					if (field.equals("kill")) 
					{
						__temp_executeDef81744 = false;
						this.kill();
					}
					
					break;
				}
				
				
				case -1249353131:
				{
					if (field.equals("getPid")) 
					{
						__temp_executeDef81744 = false;
						return this.getPid();
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef81744 = false;
						this.close();
					}
					
					break;
				}
				
				
				case -2123228117:
				{
					if (field.equals("exitCode")) 
					{
						__temp_executeDef81744 = false;
						return this.exitCode();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81744) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("proc");
		baseArr.push("stdin");
		baseArr.push("stderr");
		baseArr.push("stdout");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


