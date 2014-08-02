/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import haxor.component.Transform;
import haxor.graphics.Shader;
import haxor.net.Web;
import haxor.texture.Texture2D;
import haxor.texture.TextureCube;
import haxor.texture.TextureHTML;
import haxor.ui.Stage;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Resource implements IDisposable
{
	//=========== static ===========
	
	static var m_hashCode:Int = 0;
	
	/**
	 * Duplicates the Resource (only available for Materials for now)
	 * @param	p_target
	 * @return
	 */
	static public function Instantiate(p_target : Resource):Dynamic
	{
		return p_target.Clone();
	}
	
	static public function Destroy(p_target:Resource):Void 
	{
		if (p_target == null)
		{			
			Console.LogError("Haxor> Trying to Destroy NULL object!");
			return;
		}		
		
		if (Std.is(p_target, Transform))
		{			
			Console.LogError("Haxor> Removing an Entity transform is not allowed.");
			return;
		}		
		Engine.AddDisposable(p_target);
	}
		
	//=========== static ===========

	/**
	 * 
	 */
	public var name(get_name, set_name) : String;
	var m_name : String;	
	private function get_name():String { return m_name; }	
	private function set_name(v:String):String { m_name = v; return m_name; }	
	
	/**
	 * 
	 */
	public var id(get_id, never) : Int;	
	private function get_id():Int { return m_id; }
	private var m_id : Int;	
	
	/**
	 * 
	 */
	public var application(get_application, never) : Application;
	private function get_application():Application { return Engine.application; }
	
	/**
	 * 
	 */
	public var destroyed(get_destroyed, null):Bool;		
	private function get_destroyed():Bool { return m_destroyed; }
	private var m_destroyed : Bool;			
	
	/**
	 * 
	 * @return
	 */
	public function GetType() : Class<Dynamic> { return m_typeClass; }
	private var m_typeClass : Class<Dynamic>;
	
	
	/**
	 * 
	 * @return
	 */
	public function GetTypeFullName() : String { return m_typeFullName;	}
	private var m_typeFullName:String;
	
	/**
	 * 
	 * @return
	 */
	public function GetTypeName() : String { return m_typeName;	}
	private var m_typeName:String;
	
	
	
	public function new() 
	{		
		m_id = (m_hashCode++);
		m_destroyed = false;
		var nt:Array<String> = Type.getClassName(Type.getClass(this)).split(".");
		nt.reverse();
		m_name = nt[0] + StringTools.hex(m_id);
		m_typeFullName  = Type.getClassName(Type.getClass(this));
		m_typeName      = nt[0];
		m_typeClass = Type.getClass(this);		
	}

	private function Clone():Dynamic
	{
		return null;
	}
	
	/**
	 * 
	 */
	public function OnDestroy():Void {	}
	
}