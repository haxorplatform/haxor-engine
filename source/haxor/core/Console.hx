/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.core;
import haxor.math.Color;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Console
{
	
	static private var _console(get__console, never):Dynamic;
	static private function get__console():Dynamic { return m_console;  }
	static var m_console : Dynamic = untyped __js__("console");
	
	static private var m_style : String = "";
	
	static public function SetStyle(p_size : String = "12px", p_color : Color = null,p_background : Color = null, p_font : String = "'Lucida Console', Monaco, monospace"):Void
	{
		p_color = p_color == null ? Color.black : p_color;
		p_background = p_background == null ? Color.empty : p_background;
		m_style = "background-color: " + p_background.css + "; font-size: " + p_size + "; color: " + p_color.css + "; font-family: " + p_font+";";
	}
	
	static public function LogImage(p_url : String,p_height : Int):Void
	{
		var s : String = "background: transparent url(" + p_url + ") no-repeat; font-size: " + (p_height-3) + "px;";
		_console.log("%c                                                                                                                                                            ",s);
	}
	
	static public function ClearStyle():Void
	{
		m_style = "";
	}
	
	static public function Clear():Void
	{
		if (_console == null) return;
		_console.clear();
	}
	
	static public function ProfileStart(p_msg : String):Void
	{
		if (_console == null) return;
		_console.profile(p_msg);
	}
	
	static public function ProfileEnd(p_msg : String):Void
	{
		if (_console == null) return;
		_console.profileEnd(p_msg);
	}

	static public function Log(p_msg : String, p_obj : Array<Dynamic> = null) : Void
	{
		if (_console == null) return;
		if (p_obj == null) p_obj = [];
		var s : String = m_style;
		
		p_msg = "%c" + p_msg;
		switch(p_obj.length)
		{
			case 0: _console.log(p_msg,s);
			case 1: _console.log(p_msg, p_obj[0],s);
			case 2: _console.log(p_msg,p_obj[0],p_obj[1],s);
			case 3: _console.log(p_msg,p_obj[0],p_obj[1],p_obj[2],s);
			case 4: _console.log(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],s);
			case 5: _console.log(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],p_obj[4],s);
		}
	}
	
	static public function LogWarning(p_msg : String, p_obj : Array<Dynamic> = null) : Void
	{
		if (_console == null) return;		
		if (p_obj == null) p_obj = [];
		switch(p_obj.length)
		{
			case 0:  _console.warn(p_msg);
			case 1:  _console.warn(p_msg, p_obj[0]);
			case 2:  _console.warn(p_msg,p_obj[0],p_obj[1]);
			case 3:  _console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2]);
			case 4:  _console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
			case 5:  _console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],p_obj[4]);
		}
	}
	
	inline static public function LogError(p_msg : String) : Void
	{
		if (_console != null) _console.error(p_msg);		
	}
	
	inline static public function StackTrace() : Void
	{
		if (_console != null) _console.trace();
	}
	
	/**
	 * 
	 */
	inline static public function Breakpoint():Void { untyped __js__("debugger");  }
	
	
	
}