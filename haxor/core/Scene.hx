package haxor.core;
import haxe.Timer;
import haxor.component.Component;
import haxor.component.Transform;
import haxor.core.Scene.SceneDependency;
import haxor.graphics.Bitmap;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.texture.Texture;
import haxor.graphics.texture.Texture2D;
import haxor.graphics.texture.TextureCube;
import haxor.io.serialization.Formatter;
import haxor.io.serialization.Formatter.FormatterData;
import haxor.io.serialization.HaxorFormatter;
import haxor.math.Mathf;
import haxor.net.Web;
import haxor.platform.Types.Float32;
import haxor.thread.Activity;

/**
 * Class that describes a scene dependency.
 */
class SceneDependency
{
	@serialize
	public var guid 	: String;
		
	@serialize
	public var priority : Int;
	
	@serialize
	public var type : String;
	
	public function new()
	{
		guid 	 = "";
		priority = 0;
		type = "";
	}
}

/**
 * Class that describes a Scene. This class holds the serialized data and its dependencies.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Scene extends Resource
{
	/**
	 * List of classes by their priority order.
	 */
	static private var m_priority_classes : Array<Class<Dynamic>> = [Bitmap,Shader,Mesh,Texture2D,TextureCube,Material];
	
	/**
	 * List of dependencies of this scene.
	 */
	@serialize
	public var dependencies : Array<SceneDependency>;
	
	/**
	 * List of assets.
	 */
	@serialize
	public var assets : Array<FormatterData>;
	
	/**
	 * Load path.
	 */
	@serialize
	public var path : String;
	
	/**
	 * Flag that indicates the path for dependencies is online.
	 */
	public var online(get, never):Bool;
	private function get_online():Bool { return path.toLowerCase().indexOf("http") == 0; }
	
	/**
	 * Formatter instance.
	 */
	private var m_formatter : HaxorFormatter;
	
	/**
	 * List of retries callbacks.
	 */
	private var m_retries : Array<Void->Bool>;
	
	/**
	 * Load internals.
	 */
	private var m_operations : Float32;
	private var m_count:Float32;
	private var m_op_progress:Float32;
	private function GetProgress():Float32 { return ((m_count + m_op_progress) / m_operations); }
	private var m_load_lock:Bool;
	private var m_load_callback:Float32->Void;
	
	/**
	 * Creates a new scene.
	 * @param	p_name
	 */
	public function new(p_name : String) 
	{
		super(p_name);
		dependencies 	= [];
		assets		 	= [];
		m_retries		= [];
		m_load_lock 	= false;
		m_operations 	= 0;
		m_count 		= 0;
		path 			= "";
		
		m_formatter  = new HaxorFormatter();
		m_formatter.OnEncodeFieldCallback  = OnFieldEncode;
		m_formatter.OnDecodeFieldCallback  = OnFieldDecode;
	}
	
	/**
	 * Serializes the hierarchy and generates the dependencies.
	 * @param	p_root
	 */
	public function Save(p_root : Transform,p_path:String=""):Void
	{
		dependencies = [];
		assets		 = [];
		path		 = p_path;
		
		p_root.Traverse(function(t:Transform, d:Int):Bool
		{
			if (t == p_root) return true;
			var e : Entity 					= t.entity;
			var cl : Array<Component> 		= cast e.GetComponents(Component);			
			var rl : Array<Resource> 		= [e];
			
			for (i in 0...cl.length) rl.push(cl[i]);
			
			var sd : Dynamic = m_formatter.ToObject(e);
			
			assets.push(sd);
			
			return true;
		},true);
		
		//Remove repeated dependencies.		
		if (dependencies.length >= 2)
		{
			var rmi : Array<SceneDependency> = [];
			for (i in 0...dependencies.length)
			{
				var g0 : String = dependencies[i].guid;
				for (j in (i+1)...dependencies.length)
				{
					var g1 : String = dependencies[j].guid;
					if(g0==g1)rmi.push(dependencies[j]);
				}
			}
			while (rmi.length > 0) { dependencies.remove(rmi.pop()); }
		}
		
		dependencies.sort(DependencySort);		
	}
	
	/**
	 * Loads the dependencies and assemble the scene using the entities.
	 */
	public function Load(p_callback:Float32->Void):Void
	{
		m_operations 	= assets.length + dependencies.length;
		m_count 	 	= 0.0;
		m_retries 	 	= [];
		m_load_callback = p_callback;
		
		if (m_operations <= 0)
		{
			if (m_load_callback != null) m_load_callback(1.0);
			return;
		}
				
		//Console.Log("Scene> Load dependencies[" + dependencies.length + "] assets[" + assets.length + "] total[" + m_operations + "]", 1);
		
		if (m_load_callback != null) m_load_callback(0.0);
		
		ProcessDependency();
	}
	
	/**
	 * Process one dependency.
	 */
	private function ProcessDependency():Void
	{	
		if (dependencies.length <= 0)
		{			
			DecodeAssets();	
			return;
		}
		var d   : SceneDependency = dependencies[0];
		var res : Resource = Resource.FindByGUID(d.guid);
				
		
		//Dependency not found. Might be necessary load it from somewhere.
		if (res == null)
		{
			//Console.Log("Scene> [" + name+"] dependency[" + d.guid + ":" + d.type+"] is null!",1);
			//Checks which class it belongs.
			var c : Class<Dynamic> = Type.resolveClass(d.type);
			
			//If class not found.. so sorry :(
			if (c == null)
			{
				//Console.Log("Scene> dependency class ["+d.type+"] not found!",1);
				dependencies.shift();
				m_op_progress = 0.0;
				m_count++;
				if (m_load_callback != null) m_load_callback(GetProgress()*0.9);				
				ProcessDependency();
				return;
			}
			
			//Get all classes it derives from.
			var cl : Array<Dynamic> = Resource.GetClassPath(c);
			var is_mesh  : Bool = false;
			var is_tex2D : Bool = false;
			for (j in 0...cl.length)
			{
				c = cl[j];
				if (c == Texture2D) { is_tex2D = true; break; }
				if (c == Mesh) 		{ is_mesh  = true; break; }				
			}
			
			if (is_tex2D) { c = Texture2D; } else
			if (is_mesh)  { c = Mesh;      } else 
						  { c = Resource; }
						  
			//If scene has online content
			if (online)
			{
				DownloadResource(d.guid, c, function(r:Resource, p:Float32)
				{	
					//Console.Log("Scene> Dependency Download ["+d.guid+"] p["+p+"]",1);
					if (p >= 1.0)
					{						
						dependencies.shift();
						m_op_progress = 0.0;
						m_count++;
						if (m_load_callback != null) m_load_callback(GetProgress()*0.9);
						ProcessDependency();
					}					
					m_op_progress = p;
					if (m_load_callback != null) m_load_callback(GetProgress()*0.9);
				});
			}
			else
			{
				//Load from disk or bundle
				dependencies.shift();
				m_op_progress = 0.0;
				m_count++;
				if (m_load_callback != null) m_load_callback(GetProgress()*0.9);
				ProcessDependency();
			}
			
			
			
		}
		//Dependency found. When requested, will arrive
		else
		{
			//Console.Log("Scene> [" + name+"] dependency[" + d.guid + ":" + d.type+"] found!", 2);			
			dependencies.shift();			
			m_op_progress = 0.0;
			m_count++;
			if (m_load_callback != null) m_load_callback(GetProgress()*0.9);
			ProcessDependency();
		}		
	}
	
	/**
	 * Decodes the assets in the asset list.
	 */
	private function DecodeAssets():Void 
	{
		Console.Log("Scene> Decode Assets!",2);
		Activity.Run(function(t:Float32):Bool
		{
			if (assets.length <= 0)
			{
				OnSceneLoadComplete();
				return false;
			}
			var a : FormatterData = assets.shift();					
			var e : Entity = m_formatter.FromObject(a);			
			if (e != null) 
			{ 
				//Console.Log("Scene> Found Entity name[" + e.name+"] guid[" + e.guid + "]", 2); 
				//trace(e);
				 
			}
			else 
			{ 
				trace(a); 				
			}
			m_count++;			
			if (m_load_callback != null) m_load_callback(GetProgress()*0.9);
			return true;
		},false,true);		
	}
	
	/**
	 * Callback called when all assets and dependencies were processed.
	 */
	private function OnSceneLoadComplete()
	{		
		if (m_retries.length <= 0)
		{
			//Console.Log("Scene> Load Complete!",2);
			if (m_load_callback != null) m_load_callback(GetProgress());
			return;
		}
		else
		{
			//Console.Log("Scene> Recover Missing Refs count["+m_retries.length+"]",2);
			var count : Float32 = m_retries.length;
			var retries : Int = m_retries.length * 5;
			var it : Int = 0;
			Activity.Run(function(t:Float32):Bool
			{				
				var fn : Void->Bool = m_retries[it];
				if (fn())
				{
					m_retries.splice(it, 1);
					var r : Float32 = 1.0 - (m_retries.length / count);
					r = Mathf.Clamp01(0.9 + (0.1 * r))*0.999;
					if (m_load_callback != null) m_load_callback(r);
				}
				else
				{
					it = (it + 1) % m_retries.length;
				}				
				
				retries--;
				
				if ((m_retries.length <= 0) || (retries<=0))
				{
					if (m_load_callback != null) m_load_callback(1.0);
					return false;
				}
				return true;
			});
		}
	}
	
	/**
	 * Handles the download of resources when the scene has online content.
	 * @param	p_guid
	 * @param	p_type
	 * @param	p_callback
	 */
	private function DownloadResource(p_guid:String, p_type:Class<Dynamic>,p_callback:Dynamic->Float32->Void):Void
	{
		var c   : Class<Dynamic> = p_type;
		var url : String 		 = path + guid;
		if (c == Texture2D)
		{
			//Loads directly the texture asset.
			Web.LoadTexture2D(url, true, function(res:Texture2D, p:Float32):Void			
			{
				if (p >= 1.0)
				{
					if (res != null) res.guid = p_guid;					
				}
				p_callback(res, p);
			});
		}		
		else 
		if (c == Mesh)
		{
			//Loads directly the mesh asset.
			Web.LoadMesh(url, function(res:Mesh, p:Float32):Void			
			{
				if (p >= 1.0)
				{
					if (res != null) res.guid = p_guid;					
				}
				p_callback(res, p);
			});
		}
		else
		{
			//Loads the string serialized resource.
			Web.Load(url, function(res:String, p:Float32):Void
			{
				var r : Resource = null;
				if (p >= 1)
				{
					if (res != null)
					{
						var fmt : HaxorFormatter = new HaxorFormatter();				
						var d : Dynamic = fmt.Deserialize(res);
						if (Std.is(d, Resource)) r = cast d;
					}
				}
				if (r != null) r.guid = p_guid;
				p_callback(r, p);
			});
		}
	}
	
	/**
	 * Callback called when a field is decoded in the load process.
	 * @param	p_instance
	 * @param	p_field
	 * @param	p_value
	 * @param	p_index
	 */
	private function OnFieldEncode(p_instance:Dynamic, p_field:String, p_value:Dynamic, p_index:Int):Void
	{
		if (Std.is(p_value, Resource))
		{
			var res : Resource = p_value;
			var rp  : Int 	   = GetPriority(res);
			if (rp < 0) return;
			
			if (Std.is(res, Material))
			{
				m_formatter.ToObject(res);
			}
			
			var d 	: SceneDependency = new SceneDependency();
			d.guid 		= res.guid;
			d.priority 	= rp;
			d.type 		= res.GetTypeFullName();
			dependencies.push(d);
		}
	}
	
	/**
	 * Callback called when a field is decoded in the load process.
	 * @param	p_instance
	 * @param	p_field
	 * @param	p_value
	 * @param	p_encoded
	 * @param	p_index
	 */
	private function OnFieldDecode(p_instance:Dynamic, p_field:String, p_value:Dynamic, p_encoded:Dynamic, p_index:Int):Void
	{
		//A null thing is coming
		if (p_value == null)
		{
			//Encoded data is a special encoded string
			if (Std.is(p_encoded, String))
			{
				//String 2 first bytes describes a Resource
				if (m_formatter.EncodedStringIsType(p_encoded, Resource))
				{
					//This means the encoded resource GUID failed to hit the variable
					//The scene should try again because later in the decode the guid might exist.
					var fn : Void->Bool =
					function()
					{
						var guid : String    = m_formatter.FromEncodedString(p_encoded);
						var v    : Resource  = Resource.FindByGUID(guid);
						if (v == null) return false;
						if (Std.is(p_instance, Array))
						{
							var l : Array<Dynamic> = cast p_instance;
							l[p_index] = v;
						}
						else
						{
							Reflect.setProperty(p_instance, p_field, v);
						}
						return true;
					};		
					//Add to retries batch to retry later.
					m_retries.push(fn);
				}
			}
		}
	}
	
	/**
	 * Returns the priority of a given resource.
	 * @param	p_a
	 * @return
	 */
	private function GetPriority(p_a : Resource):Int
	{
		var priority_max : Int = 50;
		for (i in 0...m_priority_classes.length)
		{
			var c : Class<Dynamic> = m_priority_classes[i];
			if (Std.is(p_a, c)) return priority_max;
			priority_max--;
		}
		return -1;
	}
	
	/**
	 * Sorts 2 dependencies based on their priority.
	 */
	private function DependencySort(p_a : SceneDependency, p_b : SceneDependency):Int
	{
		if (p_a.priority > p_b.priority) return -1;
		if (p_a.priority < p_b.priority) return  1;
		if (p_a.guid > p_b.guid) return -1;
		if (p_a.guid < p_b.guid) return  1;
		return 0;
	}
}