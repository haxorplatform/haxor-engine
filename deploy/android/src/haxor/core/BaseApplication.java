package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BaseApplication extends haxor.component.Behaviour
{
	public    BaseApplication(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    BaseApplication()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.core.BaseApplication.__hx_ctor_haxor_core_BaseApplication(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_BaseApplication(haxor.core.BaseApplication __temp_me1810)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me1810);
		haxor.core.BaseApplication.m_instance = __temp_me1810;
		__temp_me1810.m_scenes = new haxe.root.Array<haxor.core.Scene>(new haxor.core.Scene[]{});
		haxor.core.Time.Initialize();
		haxor.graphics.Screen.Initialize();
		haxor.graphics.Screen.m_application = __temp_me1810;
		__temp_me1810.set_fps(60);
		__temp_me1810.m_frame_ms = haxor.core.Time.m_clock;
		__temp_me1810.m_platform = haxor.core.Platform.Unknown;
		__temp_me1810.m_graphics = new haxor.platform.graphics.Graphics(((haxor.core.BaseApplication) (__temp_me1810) ));
		__temp_me1810.m_engine = new haxor.core.Engine(((haxor.core.BaseApplication) (__temp_me1810) ));
	}
	
	
	public static  haxor.core.BaseApplication m_instance;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.BaseApplication(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.BaseApplication();
	}
	
	
	
	
	public   haxor.core.ApplicationProtocol get_protocol()
	{
		return haxor.core.ApplicationProtocol.Unknown;
	}
	
	
	
	
	public   java.lang.String get_vendor()
	{
		if (( this.m_vendor != null )) 
		{
			return this.m_vendor;
		}
		
		return this.m_vendor = "";
	}
	
	
	public  java.lang.String m_vendor;
	
	
	
	public final   int get_fps()
	{
		return this.m_fps;
	}
	
	
	public   int set_fps(int v)
	{
		this.m_fps = v;
		double f = ((double) (v) );
		this.m_mspf = java.lang.Math.floor(( ( 1.0 / f ) * 1000.0 ));
		return v;
	}
	
	
	public  double m_mspf;
	
	public  int m_fps;
	
	public  haxor.core.Engine engine;
	
	public final   haxor.core.Engine get_engine()
	{
		return this.m_engine;
	}
	
	
	public  haxor.core.Engine m_engine;
	
	public  double m_frame_ms;
	
	public  haxor.platform.graphics.Graphics graphics;
	
	public final   haxor.platform.graphics.Graphics get_graphics()
	{
		return this.m_graphics;
	}
	
	
	public  haxor.platform.graphics.Graphics m_graphics;
	
	public  haxor.core.Platform platform;
	
	public   haxor.core.Platform get_platform()
	{
		return this.m_platform;
	}
	
	
	public  haxor.core.Platform m_platform;
	
	public  haxe.root.Array<haxor.core.Scene> m_scenes;
	
	public   void LoadScene(java.lang.String p_name, java.lang.Object p_clear)
	{
		boolean __temp_p_clear1809 = ( (( p_clear == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_clear)) );
	}
	
	
	public   boolean Load()
	{
		return true;
	}
	
	
	public   void Initialize()
	{
		{
		}
		
	}
	
	
	public   void LoadComplete()
	{
		haxor.core.Console.Log("Application> Initialize.", 3);
		this.Initialize();
	}
	
	
	public   void Update()
	{
		haxor.core.Time.Update();
		this.CheckResize();
		this.m_engine.Update();
		this.m_engine.Collect();
	}
	
	
	public   void Render()
	{
		double c = ( haxe.Timer.stamp() * 1000.0 );
		if (( ( c - this.m_frame_ms ) >= this.m_mspf )) 
		{
			haxor.core.Time.Render();
			this.m_frame_ms = c;
			this.m_graphics.Focus();
			this.m_engine.Render();
			this.m_graphics.Flush();
		}
		
	}
	
	
	public   void OnQuit()
	{
		{
		}
		
	}
	
	
	public   void OnFocus()
	{
		{
		}
		
	}
	
	
	public   void OnUnfocus()
	{
		{
		}
		
	}
	
	
	public   void CheckResize()
	{
		boolean has_resize = false;
		if (( java.lang.Math.abs(( haxor.graphics.Screen.m_width - this.GetContainerWidth() )) > 0.0 )) 
		{
			haxor.graphics.Screen.m_width = this.GetContainerWidth();
			has_resize = true;
		}
		
		if (( java.lang.Math.abs(( haxor.graphics.Screen.m_height - this.GetContainerHeight() )) > 0.0 )) 
		{
			haxor.graphics.Screen.m_height = this.GetContainerHeight();
			has_resize = true;
		}
		
		if (has_resize) 
		{
			this.OnResize();
		}
		
	}
	
	
	public   void OnResize()
	{
		haxor.core.Console.Log(( ( ( ( "Application> Resize [" + haxe.lang.Runtime.toString(haxor.graphics.Screen.m_width) ) + "," ) + haxe.lang.Runtime.toString(haxor.graphics.Screen.m_height) ) + "]" ), 4);
		this.m_graphics.Resize();
		this.m_engine.Resize();
	}
	
	
	public   void OnFullscreenEnter()
	{
		{
		}
		
	}
	
	
	public   void OnFullscreenExit()
	{
		{
		}
		
	}
	
	
	public   boolean OnFullscreenRequest(boolean v)
	{
		return false;
	}
	
	
	public   boolean OnPointerLockRequest(boolean v)
	{
		return false;
	}
	
	
	public   boolean OnPointerVisibilityRequest(boolean v)
	{
		return false;
	}
	
	
	public   void OnMousePosition(double p_x, double p_y)
	{
		{
		}
		
	}
	
	
	public   double GetContainerWidth()
	{
		return 0.0;
	}
	
	
	public   double GetContainerHeight()
	{
		return 0.0;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1872 = true;
			switch (field.hashCode())
			{
				case -1499590326:
				{
					if (field.equals("m_frame_ms")) 
					{
						__temp_executeDef1872 = false;
						this.m_frame_ms = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 101609:
				{
					if (field.equals("fps")) 
					{
						__temp_executeDef1872 = false;
						this.set_fps(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 103595543:
				{
					if (field.equals("m_fps")) 
					{
						__temp_executeDef1872 = false;
						this.m_fps = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083294034:
				{
					if (field.equals("m_mspf")) 
					{
						__temp_executeDef1872 = false;
						this.m_mspf = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1872) 
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
			boolean __temp_executeDef1873 = true;
			switch (field.hashCode())
			{
				case -1506799239:
				{
					if (field.equals("m_scenes")) 
					{
						__temp_executeDef1873 = false;
						this.m_scenes = ((haxe.root.Array<haxor.core.Scene>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1418805926:
				{
					if (field.equals("m_vendor")) 
					{
						__temp_executeDef1873 = false;
						this.m_vendor = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 2020066309:
				{
					if (field.equals("m_platform")) 
					{
						__temp_executeDef1873 = false;
						this.m_platform = ((haxor.core.Platform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 101609:
				{
					if (field.equals("fps")) 
					{
						__temp_executeDef1873 = false;
						this.set_fps(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 1874684019:
				{
					if (field.equals("platform")) 
					{
						__temp_executeDef1873 = false;
						this.platform = ((haxor.core.Platform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083294034:
				{
					if (field.equals("m_mspf")) 
					{
						__temp_executeDef1873 = false;
						this.m_mspf = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 246089245:
				{
					if (field.equals("m_graphics")) 
					{
						__temp_executeDef1873 = false;
						this.m_graphics = ((haxor.platform.graphics.Graphics) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103595543:
				{
					if (field.equals("m_fps")) 
					{
						__temp_executeDef1873 = false;
						this.m_fps = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 100706955:
				{
					if (field.equals("graphics")) 
					{
						__temp_executeDef1873 = false;
						this.graphics = ((haxor.platform.graphics.Graphics) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1298662846:
				{
					if (field.equals("engine")) 
					{
						__temp_executeDef1873 = false;
						this.engine = ((haxor.core.Engine) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1499590326:
				{
					if (field.equals("m_frame_ms")) 
					{
						__temp_executeDef1873 = false;
						this.m_frame_ms = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1897393580:
				{
					if (field.equals("m_engine")) 
					{
						__temp_executeDef1873 = false;
						this.m_engine = ((haxor.core.Engine) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1873) 
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
			boolean __temp_executeDef1874 = true;
			switch (field.hashCode())
			{
				case 1461662450:
				{
					if (field.equals("GetContainerHeight")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetContainerHeight"))) );
					}
					
					break;
				}
				
				
				case -989163880:
				{
					if (field.equals("protocol")) 
					{
						__temp_executeDef1874 = false;
						return this.get_protocol();
					}
					
					break;
				}
				
				
				case 199665307:
				{
					if (field.equals("GetContainerWidth")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetContainerWidth"))) );
					}
					
					break;
				}
				
				
				case 1382748513:
				{
					if (field.equals("get_protocol")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_protocol"))) );
					}
					
					break;
				}
				
				
				case 1415733551:
				{
					if (field.equals("OnMousePosition")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMousePosition"))) );
					}
					
					break;
				}
				
				
				case -820075192:
				{
					if (field.equals("vendor")) 
					{
						__temp_executeDef1874 = false;
						return this.get_vendor();
					}
					
					break;
				}
				
				
				case -1997769857:
				{
					if (field.equals("OnPointerVisibilityRequest")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPointerVisibilityRequest"))) );
					}
					
					break;
				}
				
				
				case 1260602961:
				{
					if (field.equals("get_vendor")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vendor"))) );
					}
					
					break;
				}
				
				
				case -945380154:
				{
					if (field.equals("OnPointerLockRequest")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPointerLockRequest"))) );
					}
					
					break;
				}
				
				
				case -1418805926:
				{
					if (field.equals("m_vendor")) 
					{
						__temp_executeDef1874 = false;
						return this.m_vendor;
					}
					
					break;
				}
				
				
				case -634713579:
				{
					if (field.equals("OnFullscreenRequest")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFullscreenRequest"))) );
					}
					
					break;
				}
				
				
				case 101609:
				{
					if (field.equals("fps")) 
					{
						__temp_executeDef1874 = false;
						return this.get_fps();
					}
					
					break;
				}
				
				
				case -212320424:
				{
					if (field.equals("OnFullscreenExit")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFullscreenExit"))) );
					}
					
					break;
				}
				
				
				case -74796928:
				{
					if (field.equals("get_fps")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_fps"))) );
					}
					
					break;
				}
				
				
				case 2007713758:
				{
					if (field.equals("OnFullscreenEnter")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFullscreenEnter"))) );
					}
					
					break;
				}
				
				
				case 1985312652:
				{
					if (field.equals("set_fps")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_fps"))) );
					}
					
					break;
				}
				
				
				case 1528616851:
				{
					if (field.equals("OnResize")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnResize"))) );
					}
					
					break;
				}
				
				
				case -1083294034:
				{
					if (field.equals("m_mspf")) 
					{
						__temp_executeDef1874 = false;
						return this.m_mspf;
					}
					
					break;
				}
				
				
				case -1900924996:
				{
					if (field.equals("CheckResize")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckResize"))) );
					}
					
					break;
				}
				
				
				case 103595543:
				{
					if (field.equals("m_fps")) 
					{
						__temp_executeDef1874 = false;
						return this.m_fps;
					}
					
					break;
				}
				
				
				case -1244160288:
				{
					if (field.equals("OnUnfocus")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUnfocus"))) );
					}
					
					break;
				}
				
				
				case -1298662846:
				{
					if (field.equals("engine")) 
					{
						__temp_executeDef1874 = false;
						if (handleProperties) 
						{
							return this.get_engine();
						}
						 else 
						{
							return this.engine;
						}
						
					}
					
					break;
				}
				
				
				case 315605529:
				{
					if (field.equals("OnFocus")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnFocus"))) );
					}
					
					break;
				}
				
				
				case 782015307:
				{
					if (field.equals("get_engine")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_engine"))) );
					}
					
					break;
				}
				
				
				case -1929148178:
				{
					if (field.equals("OnQuit")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnQuit"))) );
					}
					
					break;
				}
				
				
				case -1897393580:
				{
					if (field.equals("m_engine")) 
					{
						__temp_executeDef1874 = false;
						return this.m_engine;
					}
					
					break;
				}
				
				
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Render"))) );
					}
					
					break;
				}
				
				
				case -1499590326:
				{
					if (field.equals("m_frame_ms")) 
					{
						__temp_executeDef1874 = false;
						return this.m_frame_ms;
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case 100706955:
				{
					if (field.equals("graphics")) 
					{
						__temp_executeDef1874 = false;
						if (handleProperties) 
						{
							return this.get_graphics();
						}
						 else 
						{
							return this.graphics;
						}
						
					}
					
					break;
				}
				
				
				case 848652383:
				{
					if (field.equals("LoadComplete")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LoadComplete"))) );
					}
					
					break;
				}
				
				
				case -1822347948:
				{
					if (field.equals("get_graphics")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_graphics"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 246089245:
				{
					if (field.equals("m_graphics")) 
					{
						__temp_executeDef1874 = false;
						return this.m_graphics;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 1874684019:
				{
					if (field.equals("platform")) 
					{
						__temp_executeDef1874 = false;
						if (handleProperties) 
						{
							return this.get_platform();
						}
						 else 
						{
							return this.platform;
						}
						
					}
					
					break;
				}
				
				
				case -913005786:
				{
					if (field.equals("LoadScene")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LoadScene"))) );
					}
					
					break;
				}
				
				
				case -48370884:
				{
					if (field.equals("get_platform")) 
					{
						__temp_executeDef1874 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_platform"))) );
					}
					
					break;
				}
				
				
				case -1506799239:
				{
					if (field.equals("m_scenes")) 
					{
						__temp_executeDef1874 = false;
						return this.m_scenes;
					}
					
					break;
				}
				
				
				case 2020066309:
				{
					if (field.equals("m_platform")) 
					{
						__temp_executeDef1874 = false;
						return this.m_platform;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1874) 
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
			boolean __temp_executeDef1875 = true;
			switch (field.hashCode())
			{
				case -1499590326:
				{
					if (field.equals("m_frame_ms")) 
					{
						__temp_executeDef1875 = false;
						return this.m_frame_ms;
					}
					
					break;
				}
				
				
				case 101609:
				{
					if (field.equals("fps")) 
					{
						__temp_executeDef1875 = false;
						return ((double) (this.get_fps()) );
					}
					
					break;
				}
				
				
				case 103595543:
				{
					if (field.equals("m_fps")) 
					{
						__temp_executeDef1875 = false;
						return ((double) (this.m_fps) );
					}
					
					break;
				}
				
				
				case -1083294034:
				{
					if (field.equals("m_mspf")) 
					{
						__temp_executeDef1875 = false;
						return this.m_mspf;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1875) 
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
			boolean __temp_executeDef1876 = true;
			switch (field.hashCode())
			{
				case 1461662450:
				{
					if (field.equals("GetContainerHeight")) 
					{
						__temp_executeDef1876 = false;
						return this.GetContainerHeight();
					}
					
					break;
				}
				
				
				case 1382748513:
				{
					if (field.equals("get_protocol")) 
					{
						__temp_executeDef1876 = false;
						return this.get_protocol();
					}
					
					break;
				}
				
				
				case 199665307:
				{
					if (field.equals("GetContainerWidth")) 
					{
						__temp_executeDef1876 = false;
						return this.GetContainerWidth();
					}
					
					break;
				}
				
				
				case 1260602961:
				{
					if (field.equals("get_vendor")) 
					{
						__temp_executeDef1876 = false;
						return this.get_vendor();
					}
					
					break;
				}
				
				
				case 1415733551:
				{
					if (field.equals("OnMousePosition")) 
					{
						__temp_executeDef1876 = false;
						this.OnMousePosition(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -74796928:
				{
					if (field.equals("get_fps")) 
					{
						__temp_executeDef1876 = false;
						return this.get_fps();
					}
					
					break;
				}
				
				
				case -1997769857:
				{
					if (field.equals("OnPointerVisibilityRequest")) 
					{
						__temp_executeDef1876 = false;
						return this.OnPointerVisibilityRequest(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1985312652:
				{
					if (field.equals("set_fps")) 
					{
						__temp_executeDef1876 = false;
						return this.set_fps(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -945380154:
				{
					if (field.equals("OnPointerLockRequest")) 
					{
						__temp_executeDef1876 = false;
						return this.OnPointerLockRequest(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 782015307:
				{
					if (field.equals("get_engine")) 
					{
						__temp_executeDef1876 = false;
						return this.get_engine();
					}
					
					break;
				}
				
				
				case -634713579:
				{
					if (field.equals("OnFullscreenRequest")) 
					{
						__temp_executeDef1876 = false;
						return this.OnFullscreenRequest(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1822347948:
				{
					if (field.equals("get_graphics")) 
					{
						__temp_executeDef1876 = false;
						return this.get_graphics();
					}
					
					break;
				}
				
				
				case -212320424:
				{
					if (field.equals("OnFullscreenExit")) 
					{
						__temp_executeDef1876 = false;
						this.OnFullscreenExit();
					}
					
					break;
				}
				
				
				case -48370884:
				{
					if (field.equals("get_platform")) 
					{
						__temp_executeDef1876 = false;
						return this.get_platform();
					}
					
					break;
				}
				
				
				case 2007713758:
				{
					if (field.equals("OnFullscreenEnter")) 
					{
						__temp_executeDef1876 = false;
						this.OnFullscreenEnter();
					}
					
					break;
				}
				
				
				case -913005786:
				{
					if (field.equals("LoadScene")) 
					{
						__temp_executeDef1876 = false;
						this.LoadScene(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1528616851:
				{
					if (field.equals("OnResize")) 
					{
						__temp_executeDef1876 = false;
						this.OnResize();
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef1876 = false;
						return this.Load();
					}
					
					break;
				}
				
				
				case -1900924996:
				{
					if (field.equals("CheckResize")) 
					{
						__temp_executeDef1876 = false;
						this.CheckResize();
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef1876 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -1244160288:
				{
					if (field.equals("OnUnfocus")) 
					{
						__temp_executeDef1876 = false;
						this.OnUnfocus();
					}
					
					break;
				}
				
				
				case 848652383:
				{
					if (field.equals("LoadComplete")) 
					{
						__temp_executeDef1876 = false;
						this.LoadComplete();
					}
					
					break;
				}
				
				
				case 315605529:
				{
					if (field.equals("OnFocus")) 
					{
						__temp_executeDef1876 = false;
						this.OnFocus();
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef1876 = false;
						this.Update();
					}
					
					break;
				}
				
				
				case -1929148178:
				{
					if (field.equals("OnQuit")) 
					{
						__temp_executeDef1876 = false;
						this.OnQuit();
					}
					
					break;
				}
				
				
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef1876 = false;
						this.Render();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1876) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_scenes");
		baseArr.push("m_platform");
		baseArr.push("platform");
		baseArr.push("m_graphics");
		baseArr.push("graphics");
		baseArr.push("m_frame_ms");
		baseArr.push("m_engine");
		baseArr.push("engine");
		baseArr.push("m_fps");
		baseArr.push("m_mspf");
		baseArr.push("fps");
		baseArr.push("m_vendor");
		baseArr.push("vendor");
		baseArr.push("protocol");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


