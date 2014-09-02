package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Entry extends android.app.Activity implements haxe.lang.IHxObject, java.lang.Thread.UncaughtExceptionHandler, java.lang.Runnable, android.opengl.GLSurfaceView.Renderer
{
	public    Entry(haxe.lang.EmptyObject empty)
	{
		super();
	}
	
	
	public    Entry()
	{
		super();
	}
	
	
	public static   void Initialize()
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.Entry(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.Entry();
	}
	
	
	public  haxor.platform.android.AndroidApplication m_application;
	
	public  android.os.Handler m_handler;
	
	public  boolean m_active;
	
	public  haxor.platform.android.input.AndroidInputHandler input;
	
	@Override public   void onCreate(android.os.Bundle savedInstanceState)
	{
		super.onCreate(((android.os.Bundle) (savedInstanceState) ));
		haxor.core.Console.Initialize();
		
			requestWindowFeature(android.view.Window.FEATURE_NO_TITLE);
			getWindow().setFlags(android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN, android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN); 
			requestWindowFeature(android.view.Window.FEATURE_NO_TITLE);
			android.view.View decorView = getWindow().getDecorView();
			// Hide both the navigation bar and the status bar.
			// SYSTEM_UI_FLAG_FULLSCREEN is only available on Android 4.1 and higher, but as
			// a general rule, you should design your app to hide the status bar whenever you
			// hide the navigation bar.
			//int uiOptions = android.view.View.SYSTEM_UI_FLAG_HIDE_NAVIGATION;
			//| android.view.View.SYSTEM_UI_FLAG_FULLSCREEN;
			//decorView.setSystemUiVisibility(uiOptions);
		;
		java.lang.Thread.setDefaultUncaughtExceptionHandler(((java.lang.Thread.UncaughtExceptionHandler) (this) ));
		java.lang.String app_class_type = getString(R.string.app_type);
		java.lang.String vl = getString(R.string.verbose);
		if (( vl != null )) 
		{
			if (haxe.lang.Runtime.valEq(vl, "")) 
			{
				vl = "0";
			}
			 else 
			{
				vl = vl;
			}
			
			haxor.core.Console.verbose = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(vl))) );
		}
		
		if (haxe.lang.Runtime.valEq(app_class_type, "")) 
		{
			haxor.core.Console.Log("Haxor> Application type not found. Default to [Main]", null);
			app_class_type = "Main";
		}
		
		haxor.core.Console.Log(( ( ( ( "Haxor> Android Platform Init verbose[" + haxor.core.Console.verbose ) + "] application[" ) + app_class_type ) + "]" ), 1);
		java.lang.Class app_class = haxe.root.Type.resolveClass(app_class_type);
		if (( ((java.lang.Object) (app_class) ) == ((java.lang.Object) (null) ) )) 
		{
			haxor.core.Console.Log(( ( ( ( "Haxor> Error Class [" + app_class_type ) + "] not found! Try adding \'import " ) + app_class_type ) + "\' in your Main file." ), null);
			return ;
		}
		
		haxor.core.Engine.Initialize();
		haxor.core.Console.Log("new entity", null);
		haxor.core.Entity e = new haxor.core.Entity(haxe.lang.Runtime.toString("application"));
		haxor.core.Console.Log("add application", null);
		this.m_application = ((haxor.platform.android.AndroidApplication) (e.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (app_class) )) ))) );
		haxor.core.Console.Log("add application complete", null);
		if ( ! (( this.m_application instanceof haxor.core.BaseApplication )) ) 
		{
			haxor.core.Console.Log(( ( "Haxor> Error. Class [" + app_class_type ) + "] does not extends Application!" ), null);
			return ;
		}
		
		haxor.graphics.GL.Initialize(this.m_application);
		haxor.graphics.GL.m_gl.Initialize(this, null);
		this.input = new haxor.platform.android.input.AndroidInputHandler();
		haxor.input.Input.m_handler = this.input;
	}
	
	
	public   void uncaughtException(java.lang.Thread thread, java.lang.Throwable ex)
	{
		haxor.core.Console.Log(( ( "Haxor> Error. " + ex.getMessage() ) + "\n" ), null);
		java.lang.StackTraceElement[] st = ex.getStackTrace();
		{
			int _g1 = 0;
			int _g = st.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Console.Log(st[i].toString(), null);
			}
			
		}
		
	}
	
	
	@Override public   boolean onTouchEvent(android.view.MotionEvent p_event)
	{
		if (( this.input != null )) 
		{
			this.input.OnTouchEvent(p_event);
		}
		
		return super.onTouchEvent(((android.view.MotionEvent) (p_event) ));
	}
	
	
	@Override public   void onStart()
	{
		super.onStart();
		haxor.core.Console.Log("OnStart", 5);
	}
	
	
	@Override public   void onPause()
	{
		super.onPause();
		haxor.core.Console.Log("OnPause", 5);
		this.m_active = false;
	}
	
	
	@Override public   void onResume()
	{
		super.onResume();
		haxor.core.Console.Log("OnResume", 5);
		this.m_active = true;
	}
	
	
	@Override public   void onDestroy()
	{
		haxor.core.Console.Log("OnDestroy", 5);
		this.m_active = false;
		super.onDestroy();
	}
	
	
	@Override public   void onStop()
	{
		haxor.core.Console.Log("OnStop", 5);
		this.m_active = false;
		super.onStop();
	}
	
	
	public   void run()
	{
		{
		}
		
	}
	
	
	public   void onDrawFrame(javax.microedition.khronos.opengles.GL10 gl)
	{
		if (this.m_active) 
		{
			this.m_application.Update();
			this.m_application.Render();
		}
		
	}
	
	
	public   void onSurfaceChanged(javax.microedition.khronos.opengles.GL10 gl, int width, int height)
	{
		if (( width <= 0 )) 
		{
			return ;
		}
		
		if (( height <= 0 )) 
		{
			return ;
		}
		
		this.m_application.m_screen_width = ((double) (width) );
		this.m_application.m_screen_height = ((double) (height) );
	}
	
	
	public   void onSurfaceCreated(javax.microedition.khronos.opengles.GL10 gl, javax.microedition.khronos.egl.EGLConfig config)
	{
		haxor.core.Console.Log("OnCreated", 5);
		gl.glClearColor(((float) (0.0) ), ((float) (0.0) ), ((float) (0.0) ), ((float) (1.0) ));
		gl.glClear(((int) (16384) ));
		haxor.graphics.GL.m_gl.CheckExtensions();
		haxor.context.EngineContext.Build();
		this.m_active = true;
		if (this.m_application.Load()) 
		{
			this.m_application.LoadComplete();
		}
		
	}
	
	
	public   boolean __hx_deleteField(java.lang.String field)
	{
		return false;
	}
	
	
	public   java.lang.Object __hx_lookupField(java.lang.String field, boolean throwErrors, boolean isCheck)
	{
		if (isCheck) 
		{
			return haxe.lang.Runtime.undefined;
		}
		 else 
		{
			if (throwErrors) 
			{
				throw haxe.lang.HaxeException.wrap("Field not found.");
			}
			 else 
			{
				return null;
			}
			
		}
		
	}
	
	
	public   double __hx_lookupField_f(java.lang.String field, boolean throwErrors)
	{
		if (throwErrors) 
		{
			throw haxe.lang.HaxeException.wrap("Field not found or incompatible field type.");
		}
		 else 
		{
			return 0.0;
		}
		
	}
	
	
	public   java.lang.Object __hx_lookupSetField(java.lang.String field, java.lang.Object value)
	{
		throw haxe.lang.HaxeException.wrap("Cannot access field for writing.");
	}
	
	
	public   double __hx_lookupSetField_f(java.lang.String field, double value)
	{
		throw haxe.lang.HaxeException.wrap("Cannot access field for writing or incompatible type.");
	}
	
	
	public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			{
				return this.__hx_lookupSetField_f(field, value);
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161614 = true;
			switch (field.hashCode())
			{
				case 100358090:
				{
					if (field.equals("input")) 
					{
						__temp_executeDef161614 = false;
						this.input = ((haxor.platform.android.input.AndroidInputHandler) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef161614 = false;
						this.m_application = ((haxor.platform.android.AndroidApplication) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -2021681384:
				{
					if (field.equals("m_active")) 
					{
						__temp_executeDef161614 = false;
						this.m_active = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -687980168:
				{
					if (field.equals("m_handler")) 
					{
						__temp_executeDef161614 = false;
						this.m_handler = ((android.os.Handler) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161614) 
			{
				return this.__hx_lookupSetField(field, value);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161615 = true;
			switch (field.hashCode())
			{
				case 1316941135:
				{
					if (field.equals("obtainStyledAttributes")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("obtainStyledAttributes"))) );
					}
					
					break;
				}
				
				
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef161615 = false;
						return this.m_application;
					}
					
					break;
				}
				
				
				case 804029191:
				{
					if (field.equals("getString")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getString"))) );
					}
					
					break;
				}
				
				
				case -687980168:
				{
					if (field.equals("m_handler")) 
					{
						__temp_executeDef161615 = false;
						return this.m_handler;
					}
					
					break;
				}
				
				
				case -75125341:
				{
					if (field.equals("getText")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getText"))) );
					}
					
					break;
				}
				
				
				case -2021681384:
				{
					if (field.equals("m_active")) 
					{
						__temp_executeDef161615 = false;
						return this.m_active;
					}
					
					break;
				}
				
				
				case -1182174803:
				{
					if (field.equals("unregisterComponentCallbacks")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("unregisterComponentCallbacks"))) );
					}
					
					break;
				}
				
				
				case 100358090:
				{
					if (field.equals("input")) 
					{
						__temp_executeDef161615 = false;
						return this.input;
					}
					
					break;
				}
				
				
				case 153870420:
				{
					if (field.equals("registerComponentCallbacks")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("registerComponentCallbacks"))) );
					}
					
					break;
				}
				
				
				case 1046116283:
				{
					if (field.equals("onCreate")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreate"))) );
					}
					
					break;
				}
				
				
				case -1682247576:
				{
					if (field.equals("getBaseContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getBaseContext"))) );
					}
					
					break;
				}
				
				
				case 931175290:
				{
					if (field.equals("uncaughtException")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("uncaughtException"))) );
					}
					
					break;
				}
				
				
				case 287807097:
				{
					if (field.equals("getAssets")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getAssets"))) );
					}
					
					break;
				}
				
				
				case 1719579098:
				{
					if (field.equals("onTouchEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onTouchEvent"))) );
					}
					
					break;
				}
				
				
				case 482608509:
				{
					if (field.equals("getPackageManager")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPackageManager"))) );
					}
					
					break;
				}
				
				
				case -1336895037:
				{
					if (field.equals("onStart")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onStart"))) );
					}
					
					break;
				}
				
				
				case 1618976105:
				{
					if (field.equals("getContentResolver")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getContentResolver"))) );
					}
					
					break;
				}
				
				
				case -1340212393:
				{
					if (field.equals("onPause")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPause"))) );
					}
					
					break;
				}
				
				
				case -37915296:
				{
					if (field.equals("getMainLooper")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getMainLooper"))) );
					}
					
					break;
				}
				
				
				case 1463983852:
				{
					if (field.equals("onResume")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onResume"))) );
					}
					
					break;
				}
				
				
				case 1852215349:
				{
					if (field.equals("getApplicationContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getApplicationContext"))) );
					}
					
					break;
				}
				
				
				case -1401315045:
				{
					if (field.equals("onDestroy")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onDestroy"))) );
					}
					
					break;
				}
				
				
				case -1598090635:
				{
					if (field.equals("getClassLoader")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getClassLoader"))) );
					}
					
					break;
				}
				
				
				case -1012956543:
				{
					if (field.equals("onStop")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onStop"))) );
					}
					
					break;
				}
				
				
				case 268490427:
				{
					if (field.equals("getPackageName")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPackageName"))) );
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("run"))) );
					}
					
					break;
				}
				
				
				case -1710913560:
				{
					if (field.equals("getApplicationInfo")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getApplicationInfo"))) );
					}
					
					break;
				}
				
				
				case 92828522:
				{
					if (field.equals("onDrawFrame")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onDrawFrame"))) );
					}
					
					break;
				}
				
				
				case 1083904387:
				{
					if (field.equals("getPackageResourcePath")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPackageResourcePath"))) );
					}
					
					break;
				}
				
				
				case -655259386:
				{
					if (field.equals("onSurfaceChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onSurfaceChanged"))) );
					}
					
					break;
				}
				
				
				case 1084591074:
				{
					if (field.equals("getPackageCodePath")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPackageCodePath"))) );
					}
					
					break;
				}
				
				
				case -365648582:
				{
					if (field.equals("onSurfaceCreated")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onSurfaceCreated"))) );
					}
					
					break;
				}
				
				
				case -926474083:
				{
					if (field.equals("getSharedPreferences")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getSharedPreferences"))) );
					}
					
					break;
				}
				
				
				case -1319473805:
				{
					if (field.equals("startIntentSender")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startIntentSender"))) );
					}
					
					break;
				}
				
				
				case -1508512636:
				{
					if (field.equals("openFileInput")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("openFileInput"))) );
					}
					
					break;
				}
				
				
				case -346076689:
				{
					if (field.equals("startActivities")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivities"))) );
					}
					
					break;
				}
				
				
				case 659102599:
				{
					if (field.equals("openFileOutput")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("openFileOutput"))) );
					}
					
					break;
				}
				
				
				case -1528850031:
				{
					if (field.equals("startActivity")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivity"))) );
					}
					
					break;
				}
				
				
				case 1764172231:
				{
					if (field.equals("deleteFile")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("deleteFile"))) );
					}
					
					break;
				}
				
				
				case -1399675440:
				{
					if (field.equals("getSystemService")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getSystemService"))) );
					}
					
					break;
				}
				
				
				case -310813865:
				{
					if (field.equals("getFileStreamPath")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getFileStreamPath"))) );
					}
					
					break;
				}
				
				
				case -282942360:
				{
					if (field.equals("onApplyThemeResource")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onApplyThemeResource"))) );
					}
					
					break;
				}
				
				
				case -735773638:
				{
					if (field.equals("fileList")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("fileList"))) );
					}
					
					break;
				}
				
				
				case 512252306:
				{
					if (field.equals("getIntent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getIntent"))) );
					}
					
					break;
				}
				
				
				case 1343252492:
				{
					if (field.equals("getFilesDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getFilesDir"))) );
					}
					
					break;
				}
				
				
				case 297635230:
				{
					if (field.equals("setIntent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setIntent"))) );
					}
					
					break;
				}
				
				
				case -1819058441:
				{
					if (field.equals("getExternalFilesDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getExternalFilesDir"))) );
					}
					
					break;
				}
				
				
				case 913984538:
				{
					if (field.equals("getApplication")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getApplication"))) );
					}
					
					break;
				}
				
				
				case 672376852:
				{
					if (field.equals("getObbDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getObbDir"))) );
					}
					
					break;
				}
				
				
				case 2056036882:
				{
					if (field.equals("isChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isChild"))) );
					}
					
					break;
				}
				
				
				case 1644385057:
				{
					if (field.equals("getCacheDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getCacheDir"))) );
					}
					
					break;
				}
				
				
				case 700591008:
				{
					if (field.equals("getParent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getParent"))) );
					}
					
					break;
				}
				
				
				case -1517925876:
				{
					if (field.equals("getExternalCacheDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getExternalCacheDir"))) );
					}
					
					break;
				}
				
				
				case 1400060391:
				{
					if (field.equals("getWindowManager")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getWindowManager"))) );
					}
					
					break;
				}
				
				
				case -1249364649:
				{
					if (field.equals("getDir")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDir"))) );
					}
					
					break;
				}
				
				
				case 908263142:
				{
					if (field.equals("getWindow")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getWindow"))) );
					}
					
					break;
				}
				
				
				case -1511505468:
				{
					if (field.equals("openOrCreateDatabase")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("openOrCreateDatabase"))) );
					}
					
					break;
				}
				
				
				case -531855260:
				{
					if (field.equals("getLoaderManager")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getLoaderManager"))) );
					}
					
					break;
				}
				
				
				case -263511994:
				{
					if (field.equals("deleteDatabase")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("deleteDatabase"))) );
					}
					
					break;
				}
				
				
				case -1222787755:
				{
					if (field.equals("getCurrentFocus")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getCurrentFocus"))) );
					}
					
					break;
				}
				
				
				case 1167476406:
				{
					if (field.equals("getDatabasePath")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDatabasePath"))) );
					}
					
					break;
				}
				
				
				case -1186339443:
				{
					if (field.equals("onRestoreInstanceState")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onRestoreInstanceState"))) );
					}
					
					break;
				}
				
				
				case -459145031:
				{
					if (field.equals("databaseList")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("databaseList"))) );
					}
					
					break;
				}
				
				
				case 204442875:
				{
					if (field.equals("onPostCreate")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPostCreate"))) );
					}
					
					break;
				}
				
				
				case 1465089868:
				{
					if (field.equals("getWallpaper")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getWallpaper"))) );
					}
					
					break;
				}
				
				
				case -1861181648:
				{
					if (field.equals("onRestart")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onRestart"))) );
					}
					
					break;
				}
				
				
				case 179180263:
				{
					if (field.equals("peekWallpaper")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("peekWallpaper"))) );
					}
					
					break;
				}
				
				
				case 622310444:
				{
					if (field.equals("onPostResume")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPostResume"))) );
					}
					
					break;
				}
				
				
				case 1668935462:
				{
					if (field.equals("getWallpaperDesiredMinimumWidth")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getWallpaperDesiredMinimumWidth"))) );
					}
					
					break;
				}
				
				
				case -918269635:
				{
					if (field.equals("onNewIntent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onNewIntent"))) );
					}
					
					break;
				}
				
				
				case -235603001:
				{
					if (field.equals("getWallpaperDesiredMinimumHeight")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getWallpaperDesiredMinimumHeight"))) );
					}
					
					break;
				}
				
				
				case -1491459488:
				{
					if (field.equals("onSaveInstanceState")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onSaveInstanceState"))) );
					}
					
					break;
				}
				
				
				case -1280884800:
				{
					if (field.equals("setWallpaper")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setWallpaper"))) );
					}
					
					break;
				}
				
				
				case 186555060:
				{
					if (field.equals("onUserLeaveHint")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onUserLeaveHint"))) );
					}
					
					break;
				}
				
				
				case 64372277:
				{
					if (field.equals("clearWallpaper")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("clearWallpaper"))) );
					}
					
					break;
				}
				
				
				case -1562281103:
				{
					if (field.equals("onCreateThumbnail")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateThumbnail"))) );
					}
					
					break;
				}
				
				
				case -1411698151:
				{
					if (field.equals("sendBroadcast")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendBroadcast"))) );
					}
					
					break;
				}
				
				
				case 1420304705:
				{
					if (field.equals("onCreateDescription")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateDescription"))) );
					}
					
					break;
				}
				
				
				case -839041412:
				{
					if (field.equals("sendOrderedBroadcast")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendOrderedBroadcast"))) );
					}
					
					break;
				}
				
				
				case -1173492971:
				{
					if (field.equals("onProvideAssistData")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onProvideAssistData"))) );
					}
					
					break;
				}
				
				
				case -1290704234:
				{
					if (field.equals("sendBroadcastAsUser")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendBroadcastAsUser"))) );
					}
					
					break;
				}
				
				
				case 1356972381:
				{
					if (field.equals("onConfigurationChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onConfigurationChanged"))) );
					}
					
					break;
				}
				
				
				case 1937989817:
				{
					if (field.equals("sendOrderedBroadcastAsUser")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendOrderedBroadcastAsUser"))) );
					}
					
					break;
				}
				
				
				case -1459179776:
				{
					if (field.equals("getChangingConfigurations")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getChangingConfigurations"))) );
					}
					
					break;
				}
				
				
				case -932916176:
				{
					if (field.equals("sendStickyBroadcast")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendStickyBroadcast"))) );
					}
					
					break;
				}
				
				
				case -1245042166:
				{
					if (field.equals("getLastNonConfigurationInstance")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getLastNonConfigurationInstance"))) );
					}
					
					break;
				}
				
				
				case 150234245:
				{
					if (field.equals("sendStickyOrderedBroadcast")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendStickyOrderedBroadcast"))) );
					}
					
					break;
				}
				
				
				case 1369329346:
				{
					if (field.equals("onRetainNonConfigurationInstance")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onRetainNonConfigurationInstance"))) );
					}
					
					break;
				}
				
				
				case 166794164:
				{
					if (field.equals("removeStickyBroadcast")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeStickyBroadcast"))) );
					}
					
					break;
				}
				
				
				case -1244087722:
				{
					if (field.equals("onLowMemory")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onLowMemory"))) );
					}
					
					break;
				}
				
				
				case -150413459:
				{
					if (field.equals("sendStickyBroadcastAsUser")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendStickyBroadcastAsUser"))) );
					}
					
					break;
				}
				
				
				case 694704898:
				{
					if (field.equals("onTrimMemory")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onTrimMemory"))) );
					}
					
					break;
				}
				
				
				case 1646140418:
				{
					if (field.equals("sendStickyOrderedBroadcastAsUser")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sendStickyOrderedBroadcastAsUser"))) );
					}
					
					break;
				}
				
				
				case -511943417:
				{
					if (field.equals("getFragmentManager")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getFragmentManager"))) );
					}
					
					break;
				}
				
				
				case -824153103:
				{
					if (field.equals("removeStickyBroadcastAsUser")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeStickyBroadcastAsUser"))) );
					}
					
					break;
				}
				
				
				case 336447348:
				{
					if (field.equals("onAttachFragment")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onAttachFragment"))) );
					}
					
					break;
				}
				
				
				case -1039717966:
				{
					if (field.equals("registerReceiver")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("registerReceiver"))) );
					}
					
					break;
				}
				
				
				case 814154857:
				{
					if (field.equals("managedQuery")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("managedQuery"))) );
					}
					
					break;
				}
				
				
				case 1102112331:
				{
					if (field.equals("unregisterReceiver")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("unregisterReceiver"))) );
					}
					
					break;
				}
				
				
				case -1229553702:
				{
					if (field.equals("startManagingCursor")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startManagingCursor"))) );
					}
					
					break;
				}
				
				
				case 1849706483:
				{
					if (field.equals("startService")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startService"))) );
					}
					
					break;
				}
				
				
				case 2131946362:
				{
					if (field.equals("stopManagingCursor")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("stopManagingCursor"))) );
					}
					
					break;
				}
				
				
				case 699379795:
				{
					if (field.equals("stopService")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("stopService"))) );
					}
					
					break;
				}
				
				
				case 1341702384:
				{
					if (field.equals("findViewById")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("findViewById"))) );
					}
					
					break;
				}
				
				
				case 1418030008:
				{
					if (field.equals("bindService")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("bindService"))) );
					}
					
					break;
				}
				
				
				case 188662599:
				{
					if (field.equals("getActionBar")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getActionBar"))) );
					}
					
					break;
				}
				
				
				case -1531153537:
				{
					if (field.equals("unbindService")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("unbindService"))) );
					}
					
					break;
				}
				
				
				case 1493874940:
				{
					if (field.equals("setContentView")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setContentView"))) );
					}
					
					break;
				}
				
				
				case -1057779028:
				{
					if (field.equals("startInstrumentation")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startInstrumentation"))) );
					}
					
					break;
				}
				
				
				case 232075101:
				{
					if (field.equals("addContentView")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addContentView"))) );
					}
					
					break;
				}
				
				
				case 686218487:
				{
					if (field.equals("checkPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkPermission"))) );
					}
					
					break;
				}
				
				
				case -981406758:
				{
					if (field.equals("setFinishOnTouchOutside")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFinishOnTouchOutside"))) );
					}
					
					break;
				}
				
				
				case 1635525003:
				{
					if (field.equals("checkCallingPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkCallingPermission"))) );
					}
					
					break;
				}
				
				
				case -43737053:
				{
					if (field.equals("setDefaultKeyMode")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setDefaultKeyMode"))) );
					}
					
					break;
				}
				
				
				case 680571322:
				{
					if (field.equals("checkCallingOrSelfPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkCallingOrSelfPermission"))) );
					}
					
					break;
				}
				
				
				case 520351938:
				{
					if (field.equals("onKeyDown")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onKeyDown"))) );
					}
					
					break;
				}
				
				
				case -1031360687:
				{
					if (field.equals("enforcePermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforcePermission"))) );
					}
					
					break;
				}
				
				
				case 1605657351:
				{
					if (field.equals("onKeyLongPress")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onKeyLongPress"))) );
					}
					
					break;
				}
				
				
				case -1024076303:
				{
					if (field.equals("enforceCallingPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforceCallingPermission"))) );
					}
					
					break;
				}
				
				
				case -1344707909:
				{
					if (field.equals("onKeyUp")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onKeyUp"))) );
					}
					
					break;
				}
				
				
				case -1062272608:
				{
					if (field.equals("enforceCallingOrSelfPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforceCallingOrSelfPermission"))) );
					}
					
					break;
				}
				
				
				case -129342928:
				{
					if (field.equals("onKeyMultiple")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onKeyMultiple"))) );
					}
					
					break;
				}
				
				
				case 2009377951:
				{
					if (field.equals("grantUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("grantUriPermission"))) );
					}
					
					break;
				}
				
				
				case -1111243300:
				{
					if (field.equals("onBackPressed")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onBackPressed"))) );
					}
					
					break;
				}
				
				
				case -745473163:
				{
					if (field.equals("revokeUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("revokeUriPermission"))) );
					}
					
					break;
				}
				
				
				case -1125672858:
				{
					if (field.equals("onKeyShortcut")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onKeyShortcut"))) );
					}
					
					break;
				}
				
				
				case -1704998113:
				{
					if (field.equals("checkCallingUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkCallingUriPermission"))) );
					}
					
					break;
				}
				
				
				case -2096275793:
				{
					if (field.equals("onTrackballEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onTrackballEvent"))) );
					}
					
					break;
				}
				
				
				case -866740080:
				{
					if (field.equals("checkCallingOrSelfUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkCallingOrSelfUriPermission"))) );
					}
					
					break;
				}
				
				
				case 383432300:
				{
					if (field.equals("onGenericMotionEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onGenericMotionEvent"))) );
					}
					
					break;
				}
				
				
				case -135772109:
				{
					if (field.equals("checkUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkUriPermission"))) );
					}
					
					break;
				}
				
				
				case -1963844248:
				{
					if (field.equals("onUserInteraction")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onUserInteraction"))) );
					}
					
					break;
				}
				
				
				case -330828551:
				{
					if (field.equals("enforceCallingUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforceCallingUriPermission"))) );
					}
					
					break;
				}
				
				
				case -1470901650:
				{
					if (field.equals("onWindowAttributesChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onWindowAttributesChanged"))) );
					}
					
					break;
				}
				
				
				case -70617366:
				{
					if (field.equals("enforceCallingOrSelfUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforceCallingOrSelfUriPermission"))) );
					}
					
					break;
				}
				
				
				case 1879450554:
				{
					if (field.equals("onContentChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onContentChanged"))) );
					}
					
					break;
				}
				
				
				case 1703419801:
				{
					if (field.equals("enforceUriPermission")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enforceUriPermission"))) );
					}
					
					break;
				}
				
				
				case -1528005877:
				{
					if (field.equals("onWindowFocusChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onWindowFocusChanged"))) );
					}
					
					break;
				}
				
				
				case -362061147:
				{
					if (field.equals("createPackageContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("createPackageContext"))) );
					}
					
					break;
				}
				
				
				case -61833202:
				{
					if (field.equals("onAttachedToWindow")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onAttachedToWindow"))) );
					}
					
					break;
				}
				
				
				case -1430292747:
				{
					if (field.equals("createConfigurationContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("createConfigurationContext"))) );
					}
					
					break;
				}
				
				
				case -2005472885:
				{
					if (field.equals("onDetachedFromWindow")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onDetachedFromWindow"))) );
					}
					
					break;
				}
				
				
				case 1322564265:
				{
					if (field.equals("createDisplayContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("createDisplayContext"))) );
					}
					
					break;
				}
				
				
				case 1790234574:
				{
					if (field.equals("hasWindowFocus")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("hasWindowFocus"))) );
					}
					
					break;
				}
				
				
				case 873989413:
				{
					if (field.equals("isRestricted")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isRestricted"))) );
					}
					
					break;
				}
				
				
				case -27421163:
				{
					if (field.equals("dispatchKeyEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchKeyEvent"))) );
					}
					
					break;
				}
				
				
				case 1237840316:
				{
					if (field.equals("applyOverrideConfiguration")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("applyOverrideConfiguration"))) );
					}
					
					break;
				}
				
				
				case -120595857:
				{
					if (field.equals("dispatchKeyShortcutEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchKeyShortcutEvent"))) );
					}
					
					break;
				}
				
				
				case -1794099687:
				{
					if (field.equals("attachBaseContext")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("attachBaseContext"))) );
					}
					
					break;
				}
				
				
				case -1201364299:
				{
					if (field.equals("dispatchTouchEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchTouchEvent"))) );
					}
					
					break;
				}
				
				
				case -1992675473:
				{
					if (field.equals("getResources")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getResources"))) );
					}
					
					break;
				}
				
				
				case -1668716022:
				{
					if (field.equals("dispatchTrackballEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchTrackballEvent"))) );
					}
					
					break;
				}
				
				
				case 1405040263:
				{
					if (field.equals("setTheme")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setTheme"))) );
					}
					
					break;
				}
				
				
				case -1302619065:
				{
					if (field.equals("dispatchGenericMotionEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchGenericMotionEvent"))) );
					}
					
					break;
				}
				
				
				case 1966152723:
				{
					if (field.equals("getTheme")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTheme"))) );
					}
					
					break;
				}
				
				
				case -1799963504:
				{
					if (field.equals("dispatchPopulateAccessibilityEvent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dispatchPopulateAccessibilityEvent"))) );
					}
					
					break;
				}
				
				
				case 371289675:
				{
					if (field.equals("getParentActivityIntent")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getParentActivityIntent"))) );
					}
					
					break;
				}
				
				
				case -80264882:
				{
					if (field.equals("onCreatePanelView")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreatePanelView"))) );
					}
					
					break;
				}
				
				
				case 734140363:
				{
					if (field.equals("navigateUpToFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("navigateUpToFromChild"))) );
					}
					
					break;
				}
				
				
				case -80536568:
				{
					if (field.equals("onCreatePanelMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreatePanelMenu"))) );
					}
					
					break;
				}
				
				
				case -983058553:
				{
					if (field.equals("navigateUpTo")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("navigateUpTo"))) );
					}
					
					break;
				}
				
				
				case -75258692:
				{
					if (field.equals("onPreparePanel")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPreparePanel"))) );
					}
					
					break;
				}
				
				
				case -708684318:
				{
					if (field.equals("shouldUpRecreateTask")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("shouldUpRecreateTask"))) );
					}
					
					break;
				}
				
				
				case -1501207065:
				{
					if (field.equals("onMenuOpened")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onMenuOpened"))) );
					}
					
					break;
				}
				
				
				case 212266186:
				{
					if (field.equals("onActionModeFinished")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onActionModeFinished"))) );
					}
					
					break;
				}
				
				
				case -1239149108:
				{
					if (field.equals("onMenuItemSelected")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onMenuItemSelected"))) );
					}
					
					break;
				}
				
				
				case -67491543:
				{
					if (field.equals("onActionModeStarted")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onActionModeStarted"))) );
					}
					
					break;
				}
				
				
				case 1263193393:
				{
					if (field.equals("onPanelClosed")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPanelClosed"))) );
					}
					
					break;
				}
				
				
				case 2071350888:
				{
					if (field.equals("onWindowStartingActionMode")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onWindowStartingActionMode"))) );
					}
					
					break;
				}
				
				
				case -1596160798:
				{
					if (field.equals("invalidateOptionsMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("invalidateOptionsMenu"))) );
					}
					
					break;
				}
				
				
				case -543019269:
				{
					if (field.equals("startActionMode")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActionMode"))) );
					}
					
					break;
				}
				
				
				case -1491259806:
				{
					if (field.equals("onCreateOptionsMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateOptionsMenu"))) );
					}
					
					break;
				}
				
				
				case -1617961863:
				{
					if (field.equals("setImmersive")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setImmersive"))) );
					}
					
					break;
				}
				
				
				case -1716174379:
				{
					if (field.equals("onPrepareOptionsMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPrepareOptionsMenu"))) );
					}
					
					break;
				}
				
				
				case -1978929999:
				{
					if (field.equals("isImmersive")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isImmersive"))) );
					}
					
					break;
				}
				
				
				case 631391277:
				{
					if (field.equals("onOptionsItemSelected")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onOptionsItemSelected"))) );
					}
					
					break;
				}
				
				
				case 3095028:
				{
					if (field.equals("dump")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dump"))) );
					}
					
					break;
				}
				
				
				case 908285739:
				{
					if (field.equals("onNavigateUp")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onNavigateUp"))) );
					}
					
					break;
				}
				
				
				case 414896384:
				{
					if (field.equals("onCreateView")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateView"))) );
					}
					
					break;
				}
				
				
				case 2041958567:
				{
					if (field.equals("onNavigateUpFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onNavigateUpFromChild"))) );
					}
					
					break;
				}
				
				
				case -1839722072:
				{
					if (field.equals("runOnUiThread")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("runOnUiThread"))) );
					}
					
					break;
				}
				
				
				case 1341989308:
				{
					if (field.equals("onCreateNavigateUpTaskStack")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateNavigateUpTaskStack"))) );
					}
					
					break;
				}
				
				
				case 1116694285:
				{
					if (field.equals("getVolumeControlStream")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getVolumeControlStream"))) );
					}
					
					break;
				}
				
				
				case -644869585:
				{
					if (field.equals("onPrepareNavigateUpTaskStack")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPrepareNavigateUpTaskStack"))) );
					}
					
					break;
				}
				
				
				case -1865144703:
				{
					if (field.equals("setVolumeControlStream")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setVolumeControlStream"))) );
					}
					
					break;
				}
				
				
				case 1889345738:
				{
					if (field.equals("onOptionsMenuClosed")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onOptionsMenuClosed"))) );
					}
					
					break;
				}
				
				
				case -1505790081:
				{
					if (field.equals("setSecondaryProgress")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setSecondaryProgress"))) );
					}
					
					break;
				}
				
				
				case 2118525043:
				{
					if (field.equals("openOptionsMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("openOptionsMenu"))) );
					}
					
					break;
				}
				
				
				case 988242095:
				{
					if (field.equals("setProgress")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setProgress"))) );
					}
					
					break;
				}
				
				
				case -1876267003:
				{
					if (field.equals("closeOptionsMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("closeOptionsMenu"))) );
					}
					
					break;
				}
				
				
				case -2111537609:
				{
					if (field.equals("setProgressBarIndeterminate")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setProgressBarIndeterminate"))) );
					}
					
					break;
				}
				
				
				case -1253184269:
				{
					if (field.equals("onCreateContextMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateContextMenu"))) );
					}
					
					break;
				}
				
				
				case -1664506711:
				{
					if (field.equals("setProgressBarIndeterminateVisibility")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setProgressBarIndeterminateVisibility"))) );
					}
					
					break;
				}
				
				
				case 1098769576:
				{
					if (field.equals("registerForContextMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("registerForContextMenu"))) );
					}
					
					break;
				}
				
				
				case 656974614:
				{
					if (field.equals("setProgressBarVisibility")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setProgressBarVisibility"))) );
					}
					
					break;
				}
				
				
				case 1334053505:
				{
					if (field.equals("unregisterForContextMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("unregisterForContextMenu"))) );
					}
					
					break;
				}
				
				
				case 341659737:
				{
					if (field.equals("onChildTitleChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onChildTitleChanged"))) );
					}
					
					break;
				}
				
				
				case -1938366716:
				{
					if (field.equals("openContextMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("openContextMenu"))) );
					}
					
					break;
				}
				
				
				case -858812229:
				{
					if (field.equals("onTitleChanged")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onTitleChanged"))) );
					}
					
					break;
				}
				
				
				case -1638191466:
				{
					if (field.equals("closeContextMenu")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("closeContextMenu"))) );
					}
					
					break;
				}
				
				
				case -2097116191:
				{
					if (field.equals("getTitleColor")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTitleColor"))) );
					}
					
					break;
				}
				
				
				case -923278914:
				{
					if (field.equals("onContextItemSelected")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onContextItemSelected"))) );
					}
					
					break;
				}
				
				
				case 1966196898:
				{
					if (field.equals("getTitle")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTitle"))) );
					}
					
					break;
				}
				
				
				case -248582501:
				{
					if (field.equals("onContextMenuClosed")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onContextMenuClosed"))) );
					}
					
					break;
				}
				
				
				case -1322984979:
				{
					if (field.equals("setTitleColor")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setTitleColor"))) );
					}
					
					break;
				}
				
				
				case -1231984413:
				{
					if (field.equals("onCreateDialog")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onCreateDialog"))) );
					}
					
					break;
				}
				
				
				case 1405084438:
				{
					if (field.equals("setTitle")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setTitle"))) );
					}
					
					break;
				}
				
				
				case 1625405840:
				{
					if (field.equals("onPrepareDialog")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onPrepareDialog"))) );
					}
					
					break;
				}
				
				
				case 1349592514:
				{
					if (field.equals("getPreferences")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getPreferences"))) );
					}
					
					break;
				}
				
				
				case 343003813:
				{
					if (field.equals("showDialog")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("showDialog"))) );
					}
					
					break;
				}
				
				
				case 588448114:
				{
					if (field.equals("getComponentName")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getComponentName"))) );
					}
					
					break;
				}
				
				
				case -256832398:
				{
					if (field.equals("dismissDialog")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("dismissDialog"))) );
					}
					
					break;
				}
				
				
				case -1926606354:
				{
					if (field.equals("getLocalClassName")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getLocalClassName"))) );
					}
					
					break;
				}
				
				
				case -1293521172:
				{
					if (field.equals("removeDialog")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeDialog"))) );
					}
					
					break;
				}
				
				
				case -1839775080:
				{
					if (field.equals("moveTaskToBack")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("moveTaskToBack"))) );
					}
					
					break;
				}
				
				
				case 1691320007:
				{
					if (field.equals("onSearchRequested")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onSearchRequested"))) );
					}
					
					break;
				}
				
				
				case -1203468463:
				{
					if (field.equals("isTaskRoot")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isTaskRoot"))) );
					}
					
					break;
				}
				
				
				case -1880505174:
				{
					if (field.equals("startSearch")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startSearch"))) );
					}
					
					break;
				}
				
				
				case 815142006:
				{
					if (field.equals("getTaskId")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTaskId"))) );
					}
					
					break;
				}
				
				
				case -1592164992:
				{
					if (field.equals("triggerSearch")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("triggerSearch"))) );
					}
					
					break;
				}
				
				
				case 2003595768:
				{
					if (field.equals("getRequestedOrientation")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getRequestedOrientation"))) );
					}
					
					break;
				}
				
				
				case -2090796143:
				{
					if (field.equals("takeKeyEvents")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("takeKeyEvents"))) );
					}
					
					break;
				}
				
				
				case -239099644:
				{
					if (field.equals("setRequestedOrientation")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setRequestedOrientation"))) );
					}
					
					break;
				}
				
				
				case -92666217:
				{
					if (field.equals("requestWindowFeature")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("requestWindowFeature"))) );
					}
					
					break;
				}
				
				
				case 1999993080:
				{
					if (field.equals("createPendingResult")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("createPendingResult"))) );
					}
					
					break;
				}
				
				
				case 1755155232:
				{
					if (field.equals("setFeatureDrawableResource")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFeatureDrawableResource"))) );
					}
					
					break;
				}
				
				
				case -1656256565:
				{
					if (field.equals("onActivityResult")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("onActivityResult"))) );
					}
					
					break;
				}
				
				
				case -19899622:
				{
					if (field.equals("setFeatureDrawableUri")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFeatureDrawableUri"))) );
					}
					
					break;
				}
				
				
				case -105029392:
				{
					if (field.equals("finishActivityFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("finishActivityFromChild"))) );
					}
					
					break;
				}
				
				
				case 135951602:
				{
					if (field.equals("setFeatureDrawable")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFeatureDrawable"))) );
					}
					
					break;
				}
				
				
				case -869293886:
				{
					if (field.equals("finishActivity")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("finishActivity"))) );
					}
					
					break;
				}
				
				
				case -1962306676:
				{
					if (field.equals("setFeatureDrawableAlpha")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFeatureDrawableAlpha"))) );
					}
					
					break;
				}
				
				
				case -1328467905:
				{
					if (field.equals("finishFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("finishFromChild"))) );
					}
					
					break;
				}
				
				
				case -1395437173:
				{
					if (field.equals("getLayoutInflater")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getLayoutInflater"))) );
					}
					
					break;
				}
				
				
				case 1392170715:
				{
					if (field.equals("finishAffinity")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("finishAffinity"))) );
					}
					
					break;
				}
				
				
				case 787950656:
				{
					if (field.equals("getMenuInflater")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getMenuInflater"))) );
					}
					
					break;
				}
				
				
				case -1274442605:
				{
					if (field.equals("finish")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("finish"))) );
					}
					
					break;
				}
				
				
				case 1573355445:
				{
					if (field.equals("startActivityForResult")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivityForResult"))) );
					}
					
					break;
				}
				
				
				case -796853009:
				{
					if (field.equals("recreate")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("recreate"))) );
					}
					
					break;
				}
				
				
				case -341841389:
				{
					if (field.equals("startIntentSenderForResult")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startIntentSenderForResult"))) );
					}
					
					break;
				}
				
				
				case 527193556:
				{
					if (field.equals("isChangingConfigurations")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isChangingConfigurations"))) );
					}
					
					break;
				}
				
				
				case 1958974435:
				{
					if (field.equals("startActivityIfNeeded")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivityIfNeeded"))) );
					}
					
					break;
				}
				
				
				case -1129785329:
				{
					if (field.equals("isDestroyed")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isDestroyed"))) );
					}
					
					break;
				}
				
				
				case -1588251967:
				{
					if (field.equals("startNextMatchingActivity")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startNextMatchingActivity"))) );
					}
					
					break;
				}
				
				
				case 1769775205:
				{
					if (field.equals("isFinishing")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isFinishing"))) );
					}
					
					break;
				}
				
				
				case 585556225:
				{
					if (field.equals("startActivityFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivityFromChild"))) );
					}
					
					break;
				}
				
				
				case -854558288:
				{
					if (field.equals("setVisible")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setVisible"))) );
					}
					
					break;
				}
				
				
				case -866373557:
				{
					if (field.equals("startActivityFromFragment")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startActivityFromFragment"))) );
					}
					
					break;
				}
				
				
				case 1770569149:
				{
					if (field.equals("getCallingActivity")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getCallingActivity"))) );
					}
					
					break;
				}
				
				
				case -1329640609:
				{
					if (field.equals("startIntentSenderFromChild")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("startIntentSenderFromChild"))) );
					}
					
					break;
				}
				
				
				case -1666360360:
				{
					if (field.equals("getCallingPackage")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getCallingPackage"))) );
					}
					
					break;
				}
				
				
				case 1293072352:
				{
					if (field.equals("overridePendingTransition")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("overridePendingTransition"))) );
					}
					
					break;
				}
				
				
				case 546971423:
				{
					if (field.equals("setResult")) 
					{
						__temp_executeDef161615 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setResult"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161615) 
			{
				return this.__hx_lookupField(field, throwErrors, isCheck);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			{
				return this.__hx_lookupField_f(field, throwErrors);
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			int __temp_hash161618 = field.hashCode();
			boolean __temp_executeDef161617 = true;
			switch (__temp_hash161618)
			{
				case 1316941135:case 804029191:case -75125341:case -1182174803:case 153870420:case -1682247576:case 287807097:case 482608509:case 1618976105:case -37915296:case 1852215349:case -1598090635:case 268490427:case -1710913560:case 1083904387:case 1084591074:case -926474083:case -1508512636:case 659102599:case 1764172231:case -310813865:case -735773638:case 1343252492:case -1819058441:case 672376852:case 1644385057:case -1517925876:case -1249364649:case -1511505468:case -263511994:case 1167476406:case -459145031:case 1465089868:case 179180263:case 1668935462:case -235603001:case -1280884800:case 64372277:case -1411698151:case -839041412:case -1290704234:case 1937989817:case -932916176:case 150234245:case 166794164:case -150413459:case 1646140418:case -824153103:case -1039717966:case 1102112331:case 1849706483:case 699379795:case 1418030008:case -1531153537:case -1057779028:case 686218487:case 1635525003:case 680571322:case -1031360687:case -1024076303:case -1062272608:case 2009377951:case -745473163:case -1704998113:case -866740080:case -135772109:case -330828551:case -70617366:case 1703419801:case -362061147:case -1430292747:case 1322564265:case 873989413:case 1237840316:case -1794099687:case -1992675473:case 1405040263:case 1966152723:case 371289675:case 734140363:case -983058553:case -708684318:case 212266186:case -67491543:case 2071350888:case -543019269:case -1617961863:case -1978929999:case 3095028:case 414896384:case -1839722072:case 1116694285:case -1865144703:case -1505790081:case 988242095:case -2111537609:case -1664506711:case 656974614:case 341659737:case -858812229:case -2097116191:case 1966196898:case -1322984979:case 1405084438:case 1349592514:case 588448114:case -1926606354:case -1839775080:case -1203468463:case 815142006:case 2003595768:case -239099644:case 1999993080:case -1656256565:case -105029392:case -869293886:case -1328467905:case 1392170715:case -1274442605:case -796853009:case 527193556:case -1129785329:case 1769775205:case -854558288:case 1770569149:case -1666360360:case 546971423:case 1293072352:case -1329640609:case -866373557:case 585556225:case -1588251967:case 1958974435:case -341841389:case 1573355445:case 787950656:case -1395437173:case -1962306676:case 135951602:case -19899622:case 1755155232:case -92666217:case -2090796143:case -1592164992:case -1880505174:case 1691320007:case -1293521172:case -256832398:case 343003813:case 1625405840:case -1231984413:case -248582501:case -923278914:case -1638191466:case -1938366716:case 1334053505:case 1098769576:case -1253184269:case -1876267003:case 2118525043:case 1889345738:case -644869585:case 1341989308:case 2041958567:case 908285739:case 631391277:case -1716174379:case -1491259806:case -1596160798:case 1263193393:case -1239149108:case -1501207065:case -75258692:case -80536568:case -80264882:case -1799963504:case -1302619065:case -1668716022:case -1201364299:case -120595857:case -27421163:case 1790234574:case -2005472885:case -61833202:case -1528005877:case 1879450554:case -1470901650:case -1963844248:case 383432300:case -2096275793:case -1125672858:case -1111243300:case -129342928:case -1344707909:case 1605657351:case 520351938:case -43737053:case -981406758:case 232075101:case 1493874940:case 188662599:case 1341702384:case 2131946362:case -1229553702:case 814154857:case 336447348:case -511943417:case 694704898:case -1244087722:case 1369329346:case -1245042166:case -1459179776:case 1356972381:case -1173492971:case 1420304705:case -1562281103:case 186555060:case -1491459488:case -918269635:case 622310444:case -1861181648:case 204442875:case -1186339443:case -1222787755:case -531855260:case 908263142:case 1400060391:case 700591008:case 2056036882:case 913984538:case 297635230:case 512252306:case -282942360:case -1399675440:case -1528850031:case -346076689:case -1319473805:case -1012956543:case -1401315045:case 1463983852:case -1340212393:case -1336895037:case 1719579098:case 1046116283:
				{
					if (( (( ( __temp_hash161618 == 1316941135 ) && field.equals("obtainStyledAttributes") )) || ( (( ( __temp_hash161618 == 804029191 ) && field.equals("getString") )) || ( (( ( __temp_hash161618 == -75125341 ) && field.equals("getText") )) || ( (( ( __temp_hash161618 == -1182174803 ) && field.equals("unregisterComponentCallbacks") )) || ( (( ( __temp_hash161618 == 153870420 ) && field.equals("registerComponentCallbacks") )) || ( (( ( __temp_hash161618 == -1682247576 ) && field.equals("getBaseContext") )) || ( (( ( __temp_hash161618 == 287807097 ) && field.equals("getAssets") )) || ( (( ( __temp_hash161618 == 482608509 ) && field.equals("getPackageManager") )) || ( (( ( __temp_hash161618 == 1618976105 ) && field.equals("getContentResolver") )) || ( (( ( __temp_hash161618 == -37915296 ) && field.equals("getMainLooper") )) || ( (( ( __temp_hash161618 == 1852215349 ) && field.equals("getApplicationContext") )) || ( (( ( __temp_hash161618 == -1598090635 ) && field.equals("getClassLoader") )) || ( (( ( __temp_hash161618 == 268490427 ) && field.equals("getPackageName") )) || ( (( ( __temp_hash161618 == -1710913560 ) && field.equals("getApplicationInfo") )) || ( (( ( __temp_hash161618 == 1083904387 ) && field.equals("getPackageResourcePath") )) || ( (( ( __temp_hash161618 == 1084591074 ) && field.equals("getPackageCodePath") )) || ( (( ( __temp_hash161618 == -926474083 ) && field.equals("getSharedPreferences") )) || ( (( ( __temp_hash161618 == -1508512636 ) && field.equals("openFileInput") )) || ( (( ( __temp_hash161618 == 659102599 ) && field.equals("openFileOutput") )) || ( (( ( __temp_hash161618 == 1764172231 ) && field.equals("deleteFile") )) || ( (( ( __temp_hash161618 == -310813865 ) && field.equals("getFileStreamPath") )) || ( (( ( __temp_hash161618 == -735773638 ) && field.equals("fileList") )) || ( (( ( __temp_hash161618 == 1343252492 ) && field.equals("getFilesDir") )) || ( (( ( __temp_hash161618 == -1819058441 ) && field.equals("getExternalFilesDir") )) || ( (( ( __temp_hash161618 == 672376852 ) && field.equals("getObbDir") )) || ( (( ( __temp_hash161618 == 1644385057 ) && field.equals("getCacheDir") )) || ( (( ( __temp_hash161618 == -1517925876 ) && field.equals("getExternalCacheDir") )) || ( (( ( __temp_hash161618 == -1249364649 ) && field.equals("getDir") )) || ( (( ( __temp_hash161618 == -1511505468 ) && field.equals("openOrCreateDatabase") )) || ( (( ( __temp_hash161618 == -263511994 ) && field.equals("deleteDatabase") )) || ( (( ( __temp_hash161618 == 1167476406 ) && field.equals("getDatabasePath") )) || ( (( ( __temp_hash161618 == -459145031 ) && field.equals("databaseList") )) || ( (( ( __temp_hash161618 == 1465089868 ) && field.equals("getWallpaper") )) || ( (( ( __temp_hash161618 == 179180263 ) && field.equals("peekWallpaper") )) || ( (( ( __temp_hash161618 == 1668935462 ) && field.equals("getWallpaperDesiredMinimumWidth") )) || ( (( ( __temp_hash161618 == -235603001 ) && field.equals("getWallpaperDesiredMinimumHeight") )) || ( (( ( __temp_hash161618 == -1280884800 ) && field.equals("setWallpaper") )) || ( (( ( __temp_hash161618 == 64372277 ) && field.equals("clearWallpaper") )) || ( (( ( __temp_hash161618 == -1411698151 ) && field.equals("sendBroadcast") )) || ( (( ( __temp_hash161618 == -839041412 ) && field.equals("sendOrderedBroadcast") )) || ( (( ( __temp_hash161618 == -1290704234 ) && field.equals("sendBroadcastAsUser") )) || ( (( ( __temp_hash161618 == 1937989817 ) && field.equals("sendOrderedBroadcastAsUser") )) || ( (( ( __temp_hash161618 == -932916176 ) && field.equals("sendStickyBroadcast") )) || ( (( ( __temp_hash161618 == 150234245 ) && field.equals("sendStickyOrderedBroadcast") )) || ( (( ( __temp_hash161618 == 166794164 ) && field.equals("removeStickyBroadcast") )) || ( (( ( __temp_hash161618 == -150413459 ) && field.equals("sendStickyBroadcastAsUser") )) || ( (( ( __temp_hash161618 == 1646140418 ) && field.equals("sendStickyOrderedBroadcastAsUser") )) || ( (( ( __temp_hash161618 == -824153103 ) && field.equals("removeStickyBroadcastAsUser") )) || ( (( ( __temp_hash161618 == -1039717966 ) && field.equals("registerReceiver") )) || ( (( ( __temp_hash161618 == 1102112331 ) && field.equals("unregisterReceiver") )) || ( (( ( __temp_hash161618 == 1849706483 ) && field.equals("startService") )) || ( (( ( __temp_hash161618 == 699379795 ) && field.equals("stopService") )) || ( (( ( __temp_hash161618 == 1418030008 ) && field.equals("bindService") )) || ( (( ( __temp_hash161618 == -1531153537 ) && field.equals("unbindService") )) || ( (( ( __temp_hash161618 == -1057779028 ) && field.equals("startInstrumentation") )) || ( (( ( __temp_hash161618 == 686218487 ) && field.equals("checkPermission") )) || ( (( ( __temp_hash161618 == 1635525003 ) && field.equals("checkCallingPermission") )) || ( (( ( __temp_hash161618 == 680571322 ) && field.equals("checkCallingOrSelfPermission") )) || ( (( ( __temp_hash161618 == -1031360687 ) && field.equals("enforcePermission") )) || ( (( ( __temp_hash161618 == -1024076303 ) && field.equals("enforceCallingPermission") )) || ( (( ( __temp_hash161618 == -1062272608 ) && field.equals("enforceCallingOrSelfPermission") )) || ( (( ( __temp_hash161618 == 2009377951 ) && field.equals("grantUriPermission") )) || ( (( ( __temp_hash161618 == -745473163 ) && field.equals("revokeUriPermission") )) || ( (( ( __temp_hash161618 == -1704998113 ) && field.equals("checkCallingUriPermission") )) || ( (( ( __temp_hash161618 == -866740080 ) && field.equals("checkCallingOrSelfUriPermission") )) || ( (( ( __temp_hash161618 == -135772109 ) && field.equals("checkUriPermission") )) || ( (( ( __temp_hash161618 == -330828551 ) && field.equals("enforceCallingUriPermission") )) || ( (( ( __temp_hash161618 == -70617366 ) && field.equals("enforceCallingOrSelfUriPermission") )) || ( (( ( __temp_hash161618 == 1703419801 ) && field.equals("enforceUriPermission") )) || ( (( ( __temp_hash161618 == -362061147 ) && field.equals("createPackageContext") )) || ( (( ( __temp_hash161618 == -1430292747 ) && field.equals("createConfigurationContext") )) || ( (( ( __temp_hash161618 == 1322564265 ) && field.equals("createDisplayContext") )) || ( (( ( __temp_hash161618 == 873989413 ) && field.equals("isRestricted") )) || ( (( ( __temp_hash161618 == 1237840316 ) && field.equals("applyOverrideConfiguration") )) || ( (( ( __temp_hash161618 == -1794099687 ) && field.equals("attachBaseContext") )) || ( (( ( __temp_hash161618 == -1992675473 ) && field.equals("getResources") )) || ( (( ( __temp_hash161618 == 1405040263 ) && field.equals("setTheme") )) || ( (( ( __temp_hash161618 == 1966152723 ) && field.equals("getTheme") )) || ( (( ( __temp_hash161618 == 371289675 ) && field.equals("getParentActivityIntent") )) || ( (( ( __temp_hash161618 == 734140363 ) && field.equals("navigateUpToFromChild") )) || ( (( ( __temp_hash161618 == -983058553 ) && field.equals("navigateUpTo") )) || ( (( ( __temp_hash161618 == -708684318 ) && field.equals("shouldUpRecreateTask") )) || ( (( ( __temp_hash161618 == 212266186 ) && field.equals("onActionModeFinished") )) || ( (( ( __temp_hash161618 == -67491543 ) && field.equals("onActionModeStarted") )) || ( (( ( __temp_hash161618 == 2071350888 ) && field.equals("onWindowStartingActionMode") )) || ( (( ( __temp_hash161618 == -543019269 ) && field.equals("startActionMode") )) || ( (( ( __temp_hash161618 == -1617961863 ) && field.equals("setImmersive") )) || ( (( ( __temp_hash161618 == -1978929999 ) && field.equals("isImmersive") )) || ( (( ( __temp_hash161618 == 3095028 ) && field.equals("dump") )) || ( (( ( __temp_hash161618 == 414896384 ) && field.equals("onCreateView") )) || ( (( ( __temp_hash161618 == -1839722072 ) && field.equals("runOnUiThread") )) || ( (( ( __temp_hash161618 == 1116694285 ) && field.equals("getVolumeControlStream") )) || ( (( ( __temp_hash161618 == -1865144703 ) && field.equals("setVolumeControlStream") )) || ( (( ( __temp_hash161618 == -1505790081 ) && field.equals("setSecondaryProgress") )) || ( (( ( __temp_hash161618 == 988242095 ) && field.equals("setProgress") )) || ( (( ( __temp_hash161618 == -2111537609 ) && field.equals("setProgressBarIndeterminate") )) || ( (( ( __temp_hash161618 == -1664506711 ) && field.equals("setProgressBarIndeterminateVisibility") )) || ( (( ( __temp_hash161618 == 656974614 ) && field.equals("setProgressBarVisibility") )) || ( (( ( __temp_hash161618 == 341659737 ) && field.equals("onChildTitleChanged") )) || ( (( ( __temp_hash161618 == -858812229 ) && field.equals("onTitleChanged") )) || ( (( ( __temp_hash161618 == -2097116191 ) && field.equals("getTitleColor") )) || ( (( ( __temp_hash161618 == 1966196898 ) && field.equals("getTitle") )) || ( (( ( __temp_hash161618 == -1322984979 ) && field.equals("setTitleColor") )) || ( (( ( __temp_hash161618 == 1405084438 ) && field.equals("setTitle") )) || ( (( ( __temp_hash161618 == 1349592514 ) && field.equals("getPreferences") )) || ( (( ( __temp_hash161618 == 588448114 ) && field.equals("getComponentName") )) || ( (( ( __temp_hash161618 == -1926606354 ) && field.equals("getLocalClassName") )) || ( (( ( __temp_hash161618 == -1839775080 ) && field.equals("moveTaskToBack") )) || ( (( ( __temp_hash161618 == -1203468463 ) && field.equals("isTaskRoot") )) || ( (( ( __temp_hash161618 == 815142006 ) && field.equals("getTaskId") )) || ( (( ( __temp_hash161618 == 2003595768 ) && field.equals("getRequestedOrientation") )) || ( (( ( __temp_hash161618 == -239099644 ) && field.equals("setRequestedOrientation") )) || ( (( ( __temp_hash161618 == 1999993080 ) && field.equals("createPendingResult") )) || ( (( ( __temp_hash161618 == -1656256565 ) && field.equals("onActivityResult") )) || ( (( ( __temp_hash161618 == -105029392 ) && field.equals("finishActivityFromChild") )) || ( (( ( __temp_hash161618 == -869293886 ) && field.equals("finishActivity") )) || ( (( ( __temp_hash161618 == -1328467905 ) && field.equals("finishFromChild") )) || ( (( ( __temp_hash161618 == 1392170715 ) && field.equals("finishAffinity") )) || ( (( ( __temp_hash161618 == -1274442605 ) && field.equals("finish") )) || ( (( ( __temp_hash161618 == -796853009 ) && field.equals("recreate") )) || ( (( ( __temp_hash161618 == 527193556 ) && field.equals("isChangingConfigurations") )) || ( (( ( __temp_hash161618 == -1129785329 ) && field.equals("isDestroyed") )) || ( (( ( __temp_hash161618 == 1769775205 ) && field.equals("isFinishing") )) || ( (( ( __temp_hash161618 == -854558288 ) && field.equals("setVisible") )) || ( (( ( __temp_hash161618 == 1770569149 ) && field.equals("getCallingActivity") )) || ( (( ( __temp_hash161618 == -1666360360 ) && field.equals("getCallingPackage") )) || ( (( ( __temp_hash161618 == 546971423 ) && field.equals("setResult") )) || ( (( ( __temp_hash161618 == 1293072352 ) && field.equals("overridePendingTransition") )) || ( (( ( __temp_hash161618 == -1329640609 ) && field.equals("startIntentSenderFromChild") )) || ( (( ( __temp_hash161618 == -866373557 ) && field.equals("startActivityFromFragment") )) || ( (( ( __temp_hash161618 == 585556225 ) && field.equals("startActivityFromChild") )) || ( (( ( __temp_hash161618 == -1588251967 ) && field.equals("startNextMatchingActivity") )) || ( (( ( __temp_hash161618 == 1958974435 ) && field.equals("startActivityIfNeeded") )) || ( (( ( __temp_hash161618 == -341841389 ) && field.equals("startIntentSenderForResult") )) || ( (( ( __temp_hash161618 == 1573355445 ) && field.equals("startActivityForResult") )) || ( (( ( __temp_hash161618 == 787950656 ) && field.equals("getMenuInflater") )) || ( (( ( __temp_hash161618 == -1395437173 ) && field.equals("getLayoutInflater") )) || ( (( ( __temp_hash161618 == -1962306676 ) && field.equals("setFeatureDrawableAlpha") )) || ( (( ( __temp_hash161618 == 135951602 ) && field.equals("setFeatureDrawable") )) || ( (( ( __temp_hash161618 == -19899622 ) && field.equals("setFeatureDrawableUri") )) || ( (( ( __temp_hash161618 == 1755155232 ) && field.equals("setFeatureDrawableResource") )) || ( (( ( __temp_hash161618 == -92666217 ) && field.equals("requestWindowFeature") )) || ( (( ( __temp_hash161618 == -2090796143 ) && field.equals("takeKeyEvents") )) || ( (( ( __temp_hash161618 == -1592164992 ) && field.equals("triggerSearch") )) || ( (( ( __temp_hash161618 == -1880505174 ) && field.equals("startSearch") )) || ( (( ( __temp_hash161618 == 1691320007 ) && field.equals("onSearchRequested") )) || ( (( ( __temp_hash161618 == -1293521172 ) && field.equals("removeDialog") )) || ( (( ( __temp_hash161618 == -256832398 ) && field.equals("dismissDialog") )) || ( (( ( __temp_hash161618 == 343003813 ) && field.equals("showDialog") )) || ( (( ( __temp_hash161618 == 1625405840 ) && field.equals("onPrepareDialog") )) || ( (( ( __temp_hash161618 == -1231984413 ) && field.equals("onCreateDialog") )) || ( (( ( __temp_hash161618 == -248582501 ) && field.equals("onContextMenuClosed") )) || ( (( ( __temp_hash161618 == -923278914 ) && field.equals("onContextItemSelected") )) || ( (( ( __temp_hash161618 == -1638191466 ) && field.equals("closeContextMenu") )) || ( (( ( __temp_hash161618 == -1938366716 ) && field.equals("openContextMenu") )) || ( (( ( __temp_hash161618 == 1334053505 ) && field.equals("unregisterForContextMenu") )) || ( (( ( __temp_hash161618 == 1098769576 ) && field.equals("registerForContextMenu") )) || ( (( ( __temp_hash161618 == -1253184269 ) && field.equals("onCreateContextMenu") )) || ( (( ( __temp_hash161618 == -1876267003 ) && field.equals("closeOptionsMenu") )) || ( (( ( __temp_hash161618 == 2118525043 ) && field.equals("openOptionsMenu") )) || ( (( ( __temp_hash161618 == 1889345738 ) && field.equals("onOptionsMenuClosed") )) || ( (( ( __temp_hash161618 == -644869585 ) && field.equals("onPrepareNavigateUpTaskStack") )) || ( (( ( __temp_hash161618 == 1341989308 ) && field.equals("onCreateNavigateUpTaskStack") )) || ( (( ( __temp_hash161618 == 2041958567 ) && field.equals("onNavigateUpFromChild") )) || ( (( ( __temp_hash161618 == 908285739 ) && field.equals("onNavigateUp") )) || ( (( ( __temp_hash161618 == 631391277 ) && field.equals("onOptionsItemSelected") )) || ( (( ( __temp_hash161618 == -1716174379 ) && field.equals("onPrepareOptionsMenu") )) || ( (( ( __temp_hash161618 == -1491259806 ) && field.equals("onCreateOptionsMenu") )) || ( (( ( __temp_hash161618 == -1596160798 ) && field.equals("invalidateOptionsMenu") )) || ( (( ( __temp_hash161618 == 1263193393 ) && field.equals("onPanelClosed") )) || ( (( ( __temp_hash161618 == -1239149108 ) && field.equals("onMenuItemSelected") )) || ( (( ( __temp_hash161618 == -1501207065 ) && field.equals("onMenuOpened") )) || ( (( ( __temp_hash161618 == -75258692 ) && field.equals("onPreparePanel") )) || ( (( ( __temp_hash161618 == -80536568 ) && field.equals("onCreatePanelMenu") )) || ( (( ( __temp_hash161618 == -80264882 ) && field.equals("onCreatePanelView") )) || ( (( ( __temp_hash161618 == -1799963504 ) && field.equals("dispatchPopulateAccessibilityEvent") )) || ( (( ( __temp_hash161618 == -1302619065 ) && field.equals("dispatchGenericMotionEvent") )) || ( (( ( __temp_hash161618 == -1668716022 ) && field.equals("dispatchTrackballEvent") )) || ( (( ( __temp_hash161618 == -1201364299 ) && field.equals("dispatchTouchEvent") )) || ( (( ( __temp_hash161618 == -120595857 ) && field.equals("dispatchKeyShortcutEvent") )) || ( (( ( __temp_hash161618 == -27421163 ) && field.equals("dispatchKeyEvent") )) || ( (( ( __temp_hash161618 == 1790234574 ) && field.equals("hasWindowFocus") )) || ( (( ( __temp_hash161618 == -2005472885 ) && field.equals("onDetachedFromWindow") )) || ( (( ( __temp_hash161618 == -61833202 ) && field.equals("onAttachedToWindow") )) || ( (( ( __temp_hash161618 == -1528005877 ) && field.equals("onWindowFocusChanged") )) || ( (( ( __temp_hash161618 == 1879450554 ) && field.equals("onContentChanged") )) || ( (( ( __temp_hash161618 == -1470901650 ) && field.equals("onWindowAttributesChanged") )) || ( (( ( __temp_hash161618 == -1963844248 ) && field.equals("onUserInteraction") )) || ( (( ( __temp_hash161618 == 383432300 ) && field.equals("onGenericMotionEvent") )) || ( (( ( __temp_hash161618 == -2096275793 ) && field.equals("onTrackballEvent") )) || ( (( ( __temp_hash161618 == -1125672858 ) && field.equals("onKeyShortcut") )) || ( (( ( __temp_hash161618 == -1111243300 ) && field.equals("onBackPressed") )) || ( (( ( __temp_hash161618 == -129342928 ) && field.equals("onKeyMultiple") )) || ( (( ( __temp_hash161618 == -1344707909 ) && field.equals("onKeyUp") )) || ( (( ( __temp_hash161618 == 1605657351 ) && field.equals("onKeyLongPress") )) || ( (( ( __temp_hash161618 == 520351938 ) && field.equals("onKeyDown") )) || ( (( ( __temp_hash161618 == -43737053 ) && field.equals("setDefaultKeyMode") )) || ( (( ( __temp_hash161618 == -981406758 ) && field.equals("setFinishOnTouchOutside") )) || ( (( ( __temp_hash161618 == 232075101 ) && field.equals("addContentView") )) || ( (( ( __temp_hash161618 == 1493874940 ) && field.equals("setContentView") )) || ( (( ( __temp_hash161618 == 188662599 ) && field.equals("getActionBar") )) || ( (( ( __temp_hash161618 == 1341702384 ) && field.equals("findViewById") )) || ( (( ( __temp_hash161618 == 2131946362 ) && field.equals("stopManagingCursor") )) || ( (( ( __temp_hash161618 == -1229553702 ) && field.equals("startManagingCursor") )) || ( (( ( __temp_hash161618 == 814154857 ) && field.equals("managedQuery") )) || ( (( ( __temp_hash161618 == 336447348 ) && field.equals("onAttachFragment") )) || ( (( ( __temp_hash161618 == -511943417 ) && field.equals("getFragmentManager") )) || ( (( ( __temp_hash161618 == 694704898 ) && field.equals("onTrimMemory") )) || ( (( ( __temp_hash161618 == -1244087722 ) && field.equals("onLowMemory") )) || ( (( ( __temp_hash161618 == 1369329346 ) && field.equals("onRetainNonConfigurationInstance") )) || ( (( ( __temp_hash161618 == -1245042166 ) && field.equals("getLastNonConfigurationInstance") )) || ( (( ( __temp_hash161618 == -1459179776 ) && field.equals("getChangingConfigurations") )) || ( (( ( __temp_hash161618 == 1356972381 ) && field.equals("onConfigurationChanged") )) || ( (( ( __temp_hash161618 == -1173492971 ) && field.equals("onProvideAssistData") )) || ( (( ( __temp_hash161618 == 1420304705 ) && field.equals("onCreateDescription") )) || ( (( ( __temp_hash161618 == -1562281103 ) && field.equals("onCreateThumbnail") )) || ( (( ( __temp_hash161618 == 186555060 ) && field.equals("onUserLeaveHint") )) || ( (( ( __temp_hash161618 == -1491459488 ) && field.equals("onSaveInstanceState") )) || ( (( ( __temp_hash161618 == -918269635 ) && field.equals("onNewIntent") )) || ( (( ( __temp_hash161618 == 622310444 ) && field.equals("onPostResume") )) || ( (( ( __temp_hash161618 == -1861181648 ) && field.equals("onRestart") )) || ( (( ( __temp_hash161618 == 204442875 ) && field.equals("onPostCreate") )) || ( (( ( __temp_hash161618 == -1186339443 ) && field.equals("onRestoreInstanceState") )) || ( (( ( __temp_hash161618 == -1222787755 ) && field.equals("getCurrentFocus") )) || ( (( ( __temp_hash161618 == -531855260 ) && field.equals("getLoaderManager") )) || ( (( ( __temp_hash161618 == 908263142 ) && field.equals("getWindow") )) || ( (( ( __temp_hash161618 == 1400060391 ) && field.equals("getWindowManager") )) || ( (( ( __temp_hash161618 == 700591008 ) && field.equals("getParent") )) || ( (( ( __temp_hash161618 == 2056036882 ) && field.equals("isChild") )) || ( (( ( __temp_hash161618 == 913984538 ) && field.equals("getApplication") )) || ( (( ( __temp_hash161618 == 297635230 ) && field.equals("setIntent") )) || ( (( ( __temp_hash161618 == 512252306 ) && field.equals("getIntent") )) || ( (( ( __temp_hash161618 == -282942360 ) && field.equals("onApplyThemeResource") )) || ( (( ( __temp_hash161618 == -1399675440 ) && field.equals("getSystemService") )) || ( (( ( __temp_hash161618 == -1528850031 ) && field.equals("startActivity") )) || ( (( ( __temp_hash161618 == -346076689 ) && field.equals("startActivities") )) || ( (( ( __temp_hash161618 == -1319473805 ) && field.equals("startIntentSender") )) || ( (( ( __temp_hash161618 == -1012956543 ) && field.equals("onStop") )) || ( (( ( __temp_hash161618 == -1401315045 ) && field.equals("onDestroy") )) || ( (( ( __temp_hash161618 == 1463983852 ) && field.equals("onResume") )) || ( (( ( __temp_hash161618 == -1340212393 ) && field.equals("onPause") )) || ( (( ( __temp_hash161618 == -1336895037 ) && field.equals("onStart") )) || ( (( ( __temp_hash161618 == 1719579098 ) && field.equals("onTouchEvent") )) || field.equals("onCreate") ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )) 
					{
						__temp_executeDef161617 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 931175290:
				{
					if (field.equals("uncaughtException")) 
					{
						__temp_executeDef161617 = false;
						this.uncaughtException(((java.lang.Thread) (dynargs.__get(0)) ), ((java.lang.Throwable) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -365648582:
				{
					if (field.equals("onSurfaceCreated")) 
					{
						__temp_executeDef161617 = false;
						this.onSurfaceCreated(((javax.microedition.khronos.opengles.GL10) (dynargs.__get(0)) ), ((javax.microedition.khronos.egl.EGLConfig) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef161617 = false;
						this.run();
					}
					
					break;
				}
				
				
				case -655259386:
				{
					if (field.equals("onSurfaceChanged")) 
					{
						__temp_executeDef161617 = false;
						this.onSurfaceChanged(((javax.microedition.khronos.opengles.GL10) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 92828522:
				{
					if (field.equals("onDrawFrame")) 
					{
						__temp_executeDef161617 = false;
						this.onDrawFrame(((javax.microedition.khronos.opengles.GL10) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161617) 
			{
				return ((haxe.lang.Function) (this.__hx_getField(field, true, false, false)) ).__hx_invokeDynamic(dynargs);
			}
			
		}
		
		return null;
	}
	
	
	public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("input");
		baseArr.push("m_active");
		baseArr.push("m_handler");
		baseArr.push("m_application");
	}
	
	
}


