/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import haxor.component.Animation;
import haxor.component.AssetData;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.component.Component;
import haxor.component.MeshRenderer;
import haxor.component.Renderer;
import haxor.component.RigidBody;
import haxor.component.Transform;
import haxor.math.AABB3;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Entity extends Resource
{
	
	var m_components:Array<Component>;
	
	/**
	 * 
	 */
	public var transform(get_transform, never):Transform;		
	var m_transform : Transform;
	function get_transform():Transform { return m_transform; }
	
	
	
	/**
	 * 
	 */
	public var camera(get_camera, never):Camera;
	function get_camera():Camera { return cast GetComponent(Camera); }
	
	/**
	 * 
	 */
	public var data(get_data, never):AssetData;
	function get_data():AssetData { return cast GetComponent(AssetData); }
	
	/**
	 * 
	 */
	public var animation(get_animation, never):Animation;
	function get_animation():Animation { return cast GetComponent(Animation); }
	
	/**
	 * 
	 */
	public var renderer(get_renderer, never) : Renderer;	
	function get_renderer():Renderer { return cast GetComponent(Renderer); }
	
	/**
	 * 
	 */
	public var rigidbody(get_rigidbody, never) : RigidBody;		
	private var m_rigidbody : RigidBody;
	function get_rigidbody():RigidBody 
	{ 
		if (m_rigidbody != null) if (!m_rigidbody.destroyed) return m_rigidbody;
		m_rigidbody = cast GetComponent(RigidBody); 
		return m_rigidbody;
	}

	/**
	 * 
	 */
	public var enabled(get_enabled, set_enabled):Bool;
	var m_enabled : Bool;	
	function get_enabled():Bool { return m_enabled; }
	function set_enabled(v:Bool):Bool 
	{
		if (m_enabled == v) return v;
		m_enabled = v;  
		for (i in 0...m_components.length) if (Std.is(m_components[i], Behaviour)) Reflect.field(m_components[i], "CheckEnabled");
		RecursiveEnableStep(v, transform);
		return v; 
	}
	
	function RecursiveEnableStep(p_flag : Bool, p_transform : Transform):Void
	{
		for (i in 0...p_transform.childCount)
		{
			p_transform.entity.enabled = p_flag;			
		}
	}
	
	/**
	 * 
	 */
	public var layer : Int;
	
	/**
	 * 
	 */
	public function new() 
	{
		super();
		layer = 1;
		m_enabled = true;
		m_components = new Array<Component>();
		m_transform = cast AddComponent(Transform);
	}
	
	
	public var bounds(get_bounds, never):AABB3;
	private function get_bounds():AABB3
	{
		var b : AABB3 = new AABB3();
		var cl : Array<Component>;
		var mr : MeshRenderer;
		cl = GetComponents(MeshRenderer);
		for (i in 0...cl.length) { mr = cast cl[i]; if (mr.mesh != null) b.Add(mr.mesh.bounds); }
		cl = GetComponentsInChildren(MeshRenderer);
		for (i in 0...cl.length) { mr = cast cl[i]; if (mr.mesh != null) b.Add(mr.mesh.bounds); }
		return b;
	}
	
	/**
	 * 
	 * @param	Class<Component> p_type
	 * @return
	 */
	public function AddComponent(p_type : Class<Component>) : Dynamic
	{
		var c:Component = Type.createInstance(p_type, [this]);
		if (Std.is(c, Behaviour)) { var b : Behaviour = cast c; b.enabled = enabled; }
		m_components.push(c);
		return c;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponent(p_type : Class<Component>) : Dynamic
	{
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) return m_components[i];
		return null;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponents(p_type : Class<Component>) : Array<Component>
	{
		var res : Array<Component> = [];
		for (i in 0...m_components.length) if (Std.is(m_components[i], p_type)) res.push(m_components[i]);
		return res;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentInChildren(p_type : Class<Component>) : Dynamic
	{
		var res : Array<Component> = [];
		var res : Component = null;
		transform.Traverse(function(t : Transform):Bool
		{
			if (res != null) return true;
			var l : Array<Component> = t.entity.GetComponents(p_type);
			if (l.length > 0) { res = l[0]; return true; }			
			return true;
		});
		return res;
	}
	
	/**
	 * 
	 * @param	p_type
	 * @return
	 */
	public function GetComponentsInChildren(p_type : Class<Component>) : Array<Component>
	{
		var res : Array<Component> = [];
		transform.Traverse(function(t : Transform):Bool
		{
			var l : Array<Component> = t.entity.GetComponents(p_type);
			for (i in 0...l.length) res.push(l[i]);
			return true;
		});
		return res;
	}
		
	/**
	 * 
	 */
	override public function OnDestroy():Void 
	{
		for (i in 0...m_components.length) 
		{
			Resource.Destroy(m_components[i]);
			m_components[i] = null;
		}		
		
		for (i in 0...m_transform.childCount)
		{
			Resource.Destroy(m_transform.GetChild(i).entity);
		}
	}
	
}