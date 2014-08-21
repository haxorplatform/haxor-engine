#if android
package haxor.platform.android;
import java.NativeArray;
import haxor.core.Engine;
import java.lang.Thread;
import java.lang.Throwable;
import haxor.core.Time;
import haxor.graphics.GL;
import haxor.context.EngineContext;
import haxor.core.Entity;
import haxor.graphics.Screen;
import haxor.core.Console;
import haxor.core.BaseApplication;
import android.app.Activity;
import android.opengl.GLSurfaceView;
import java.lang.Runnable;
import android.os.Handler;
import android.os.Bundle;
import java.javax.microedition.khronos.opengles.GL10;
import java.javax.microedition.khronos.egl.EGLConfig;
import java.lang.StackTraceElement;

/**
 * Entry point class that controls the initialization of Android projects. 
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Entry extends Activity implements GLSurfaceView_Renderer implements Runnable implements Thread_UncaughtExceptionHandler
{
	
	/**
	 * Not needed in android dev.
	 */
	static public function Initialize():Void {  }
	
	private var m_application : AndroidApplication;
	
	private var m_handler : Handler;
	
	private var m_active : Bool;
	
	/**
	 * Callback when the android application is created. This event is used to setup the Application class once!
	 * @param	savedInstanceState
	 */
	@:overload()
	override public function onCreate(savedInstanceState : Bundle) : Void
    {
        super.onCreate(savedInstanceState);
		
		Console.Initialize();
		
		untyped __java__('
			requestWindowFeature(android.view.Window.FEATURE_NO_TITLE);
			getWindow().setFlags(android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN, android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN); 
			//android.view.View decorView = getWindow().getDecorView();
			// Hide both the navigation bar and the status bar.
			// SYSTEM_UI_FLAG_FULLSCREEN is only available on Android 4.1 and higher, but as
			// a general rule, you should design your app to hide the status bar whenever you
			// hide the navigation bar.
			//int uiOptions = android.view.View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | android.view.View.SYSTEM_UI_FLAG_FULLSCREEN;
			//decorView.setSystemUiVisibility(uiOptions);
		');
		
		Thread.setDefaultUncaughtExceptionHandler(this);
		
		var app_class_type : String = untyped __java__("getString(R.string.app_type)");
		
		var vl : String = untyped __java__("getString(R.string.verbose)");
		if (vl != null)
		{
			vl = vl == "" ? "0" : vl;
			Console.verbose = Std.parseInt(vl);
		}
		
		if (app_class_type == "")
		{
			Console.Log("Haxor> Application type not found. Default to [Main]");
			app_class_type = "Main";
		}
		
		Console.Log("Haxor> Android Platform Init verbose[" + Console.verbose+"] application[" + app_class_type+"]", 1);
		
		var app_class : Class<Dynamic> = Type.resolveClass(app_class_type);
		
		if (app_class == null) 
		{
			Console.Log("Haxor> Error Class [" + app_class_type+"] not found! Try adding 'import " + app_class_type+"' in your Main file."); 
			return; 
		}
		
		Engine.Initialize();
				
		var e: Entity = new Entity("application");
		m_application = e.AddComponent(cast app_class);
		
		if (!Std.is(m_application, BaseApplication))
		{ 
			Console.Log("Haxor> Error. Class [" + app_class_type+"] does not extends Application!"); 
			return; 
		}
		
		GL.Initialize(m_application);
		GL.m_gl.Initialize(this);
						
		m_handler 	= new Handler();
		m_handler.postDelayed(this,cast 0);
		
		
		
		
    }
	
	/**
	 * Handles and report global exceptions within the Thread.
	 * @param	thread
	 * @param	ex
	 */
	public function uncaughtException(thread : Thread,ex :  Throwable):Void
	{
		Console.Log("Haxor> Error. " + ex.getMessage()+"\n");
		var st : NativeArray<StackTraceElement> = ex.getStackTrace();
		for (i in 0...st.length)
		{
			Console.Log(st[i].toString());
		}
	}
	
	@:overload()
	override public function onStart() : Void
	{
		super.onStart();		
		Console.Log("OnStart", 5);		
	}
	
	@:overload()
	override public function onPause() : Void
	{
		super.onPause();
		
		Console.Log("OnPause",5);
		//m_application.OnUnfocus();
		m_active = false;
	}
	
	@:overload()
	override public function onResume() : Void
	{
		super.onResume();		
		Console.Log("OnResume",5);
		m_active = true;
		//m_application.OnFocus();		
		if(m_active)m_handler.postDelayed(this,cast 0);
	}
	
	@:overload()
	override public function onDestroy():Void
	{
		Console.Log("OnDestroy", 5);
		m_active = false;
		super.onDestroy();		
	}
	
	@:overload()
	override public function onStop():Void
	{
		Console.Log("OnStop",5);		
		m_active = false;
		super.onStop();		
	}
		
	
	public function run():Void
	{		
		m_application.Update();			
		if(m_active)m_handler.postDelayed(this,cast 0);
	}
	
	public function onDrawFrame(gl:GL10):Void
	{	
		if(m_active)m_application.Render();	
	}
	
	public function onSurfaceChanged(gl:GL10, width:Int, height:Int):Void
	{
		if (width <= 0)  return;
		if (height <= 0) return;
		m_application.m_screen_width  = cast width;
		m_application.m_screen_height = cast height;
		//if(m_active)m_application.OnResize();
	}
	
	public function onSurfaceCreated(gl:GL10, config:EGLConfig):Void
	{
		Console.Log("OnCreated", 5);
		
		GL.m_gl.CheckExtensions();
		
		EngineContext.Build();
		
		m_active 	= true;
		
		if (m_application.Load())
		{
			m_application.LoadComplete();
		}
	}
}

#end