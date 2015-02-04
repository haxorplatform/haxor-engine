package haxor.core;
import haxor.component.Behaviour;
import haxor.context.EngineContext;



/**
 * Base class for all haxor objects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
@:keepSub
class Resource implements IDisposable
{
	
	/**
	 * Schedule this resource to be destroyed.
	 * @param	p_target
	 */
	static public function Destroy(p_target : Resource):Void
	{
		if (p_target.__db != "") Asset.Remove(p_target.__db);
		EngineContext.Destroy(p_target);
	}
	
	/**
	 * Returns the reference to the application currently running.
	 */
	public var application(get_application, null):Application;
	private function get_application():Application { return cast BaseApplication.m_instance; }
	
	/**
	 * Returns the global unique id of this resource generated when the asset is created the first time.
	 * Assets that comes from the editor like meshes and textures probably will come with its own guid after loading.
	 */
	public var guid(get_guid, null):String;
	private inline function get_guid():String { return m_guid; }
	private var m_guid : String;
	
	
	/**
	 * Returns the unique id of this resource generated at runtime.
	 */
	public var uid(get_uid, null):Int;
	private function get_uid():Int { return m_uid; }
	private var m_uid : Int;
	
	/**
	 * Resource name.
	 */
	public var name(get_name, set_name):String;
	private function get_name():String { return m_name; }
	private function set_name(v:String):String { m_name = v; return v; }
	private var m_name : String;
	
	/**
	 * Flag that indicates if this resource is destroyed and must not be manipulated anymore.
	 */
	public var destroyed(get_destroyed, null):Bool;
	private inline function get_destroyed():Bool { return m_destroyed; }
	private var m_destroyed : Bool;
	
	/**
	 * Class related id.
	 */
	private var __cid : Int;
	
	/**
	 * Id of the location of this Resource in the global database accessible from the 'Asset' class.
	 */
	private var __db : String;
	
	/**
	 * Array of process ids.
	 */
	private var __pid : Array<Int>;
	
	
	/**
	 * Lookup for this resource type name.
	 */
	private var m_type_name : String;
	
	/**
	 * Lookup for this resource type name with packages.
	 */
	private var m_type_full_name : String;
	
	/**
	 * Lookup for this resource type.
	 */
	private var m_type_class : Class<Dynamic>;
	
	/**
	 * Lookup flag to check if this component is a behaviour.
	 */
	private var m_is_behaviour : Bool;
	
	
	/**
	 * Creates a new Resource with the passed name.
	 * @param	p_name Name of the resource.
	 */
	public function new(p_name:String = ""):Void
	{	
		m_uid  		= EngineContext.uid++;
		m_destroyed = false;
		__cid  		= 0;
		__db		= "";
		__pid  		= [ -1, -1, -1, -1, -1, -1,-1,-1,-1];
		m_name 		= p_name;
				
		m_is_behaviour = Std.is(this, Behaviour);
		
		
		m_type_class 		 = Type.getClass(this);
		m_type_full_name  	 = Type.getClassName(m_type_class);
		var nt:Array<String> = m_type_full_name.split("."); nt.reverse();		
		m_type_name       	 = nt[0];	
		
		m_name 				 = p_name == "" ? (m_type_name+m_uid) : p_name;
		
		m_guid		 = "";		
		m_guid 		+= StringTools.hex(Math.floor(0xfffffff * Math.random()));
		m_guid 		+= StringTools.hex(Math.floor(0xfffffff * Math.random()));
		m_guid 		+= StringTools.hex(Math.floor(0xfffffff * Math.random()));
		m_guid 		+= StringTools.hex(Math.floor(0xfffffff * Math.random()));
		
		EngineContext.resources.Add(this);		
	}
	
	/**
	 * Returns the reference for this object's Class instance.
	 * @return
	 */
	public inline function GetType():Class<Dynamic> { return m_type_class; }
	
	/**
	 * Returns this class type name without package.
	 * @return
	 */
	public inline function GetTypeName():String { return m_type_name; }
	
	/**
	 * Returns this class full type name which includes its packages.
	 * @return
	 */
	public inline function GetTypeFullName():String { return m_type_full_name; }
	
	/**
	 * Method called when the resource is destroyed by the engine.
	 */
	public function OnDestroy():Void { }
	
}