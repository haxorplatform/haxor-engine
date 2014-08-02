#if windows
package haxor.platform.graphics;
import haxor.platform.OSWindow;
import haxor.core.Console;
import haxor.platform.windows.Window;
import cpp.Lib;



@:headerCode('
#include <windows.h>
#include <gl/gl.h>                                // Header File For The OpenGL32 Library
#include <gl/glu.h>                               // Header File For The GLu32 Library


')

@:cppFileCode('
HGLRC   hrc;                           // Permanent Rendering Context
HDC     hdc;                           // Private GDI Device Context
PIXELFORMATDESCRIPTOR pfd;			   // pfd Tells Windows How We Want Things To Be
int     pf;
')

@:headerClassCode('
#undef RegisterClass




')

@:buildXml('
<target id="haxe" tool="linker" toolid="${haxelink}" output="${HAXE_OUTPUT}${DBG}">  
  <lib name="gdi32.lib" if="windows"/>
  <lib name="opengl32.lib" if="windows"/>
  <lib name="kernel32.lib" if="windows"/>
</target>

')


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class WinGL extends GraphicContext
{
	
	/**
	 * Returns the Windows window reference.
	 */
	public var window(get_window, null):Window;
	private function get_window():Window { return cast m_window; }
	private var m_window : OSWindow;
	
	/**
	 * Initializes the OpenGL context passing its creation flags.
	 */
	public function Initialize(p_window : Window):Bool
	{	
		Console.Log("Graphics> Initialize. hwnd["+p_window+"]",1);
		
		untyped __cpp__('		
		{
			if (p_window->hwnd == NULL) 
			{ 
				printf("Graphics> Invalid Window Handler."); 
				return false; 
			}
			printf("  Window Handler [0x%x]\\n", p_window->hwnd);
			hdc  = GetDC(p_window->hwnd);
			printf("  Device Context [0x%x]\\n", hdc);
			if (hdc == NULL) 
			{ 
				printf("Graphics> Could not create Device Context!\\n"); 
				return false; 
			}
			
			PIXELFORMATDESCRIPTOR l_pfd =                  
			{
				sizeof(PIXELFORMATDESCRIPTOR),  // Size Of This Pixel Format Descriptor
				1,                              // Version Number
				PFD_DRAW_TO_WINDOW |            // Format Must Support Window
				PFD_SUPPORT_OPENGL |            // Format Must Support OpenGL
				PFD_DOUBLEBUFFER,               // Must Support Double Buffering
				PFD_TYPE_RGBA,                  // Request An RGBA Format
				32,                             // Select Our Color Depth
				0, 0, 0, 0, 0, 0,               // Color Bits Ignored
				0,                              // No Alpha Buffer
				0,                              // Shift Bit Ignored
				0,                              // No Accumulation Buffer
				0, 0, 0, 0,                     // Accumulation Bits Ignored
				16,                             // 16Bit Z-Buffer (Depth Buffer)
				0,                              // No Stencil Buffer
				0,                              // No Auxiliary Buffer
				PFD_MAIN_PLANE,                 // Main Drawing Layer
				0,                              // Reserved
				0, 0, 0                         // Layer Masks Ignored
			};
			
			pf = ChoosePixelFormat(hdc, &l_pfd);
			
			pfd = l_pfd;
			
			if (!pf) 
			{ 
				printf("Graphics> Failed to choose pixel format!\\n"); 
				return false; 
			}
			
			printf("  Pixel Format [%d]\\n", pf);
			
			if (!SetPixelFormat(hdc, pf, & pfd)) 
			{ 
				printf("Graphics> Failed to set pixel format!\\n"); 
				return false;
			}
			
			hrc = wglCreateContext(hdc);
			int  err = GetLastError();
			
			if (!hrc)
			{ 
				printf("Graphics> Failed to create Rendering context !\\n"); 				
				return false; 
			}
			
			printf("  Rendering Context [0x%x]\\n", hrc);
			
		}
		');
		
		return true;
	}

	
	/**
	 * Checks for available extensions and constants and activate them.
	 */
	override public function CheckExtensions():Void 
	{
		untyped __cpp__('
		if (hdc == NULL) return null();
		');
		Console.Log("Graphics> Available Extensions:",1);				
	}
	
	/**
	 * Activates the context.
	 */
	override public function Focus():Void 
	{
		untyped __cpp__('
		wglMakeCurrent(hdc, hrc);
		');
	}
	
	/**
	 * Issues the drawing commnands.
	 */
	override public function Flush():Void 
	{		
		untyped __cpp__('
		SwapBuffers(hdc);
		');
	}
	
	
}

#end