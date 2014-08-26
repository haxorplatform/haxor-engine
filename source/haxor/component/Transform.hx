package haxor.component;
import haxor.context.EngineContext;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import js.html.idb.Transaction;


/**
 * Component that handles all Transformation matrix of Entities.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Transform extends Component
{
	
	/**
	 * Root transform of the current scene.
	 */
	static public var root(get_root, never) : Transform;		
	static function get_root():Transform { return m_root; }
	static private var m_root : Transform;
	
	/**
	 * Right world axis vector
	 */
	public var right(get_right, never):Vector3;	
	private function get_right():Vector3 { RefreshWM(); return m_right.clone; }
	private function set_right(v:Vector3):Vector3 { return v; }
	private var m_right : Vector3;
		
	/**
	 * Up world axis vector
	 */
	public var up(get_up, never):Vector3;		
	private function get_up():Vector3 { RefreshWM(); return m_up.clone; }
	private function set_up(v:Vector3):Vector3 { return v; }
	private var m_up : Vector3;
	
	/**
	 * Forward world axis vector
	 */
	public var forward(get_forward, never):Vector3;
	private function get_forward():Vector3 { RefreshWM(); return m_forward.clone; }
	private function set_forward(v:Vector3):Vector3 { return v; }
	private var m_forward : Vector3;
	
	
	/**
	 * Parent Transform of this instance. If set to null the parent will be the  root transform.
	 */
	public var parent(get_parent, set_parent):Transform;	
	private inline function get_parent():Transform { return m_parent; }
	private function set_parent(v:Transform):Transform
	{		
		if (m_parent != null) m_parent.m_hierarchy.remove(this);
		m_parent = v == null ? m_root : v;		
		m_parent.m_hierarchy.push(this);
		return m_parent;
	}
	private var m_parent : Transform;
	
	/**
	 * Returns the number of children.
	 */
	public var childCount(get_childCount, null):Int;
	private inline function get_childCount():Int { return m_hierarchy.length; }
	
	/**
	 * Sets the Transform position in world space.
	 */
	public var position(get_position, set_position):Vector3;		
	private function get_position():Vector3 { return Vector3.zero.Set(m_position.x,m_position.y,m_position.z); }
	private function set_position(v:Vector3):Vector3
	{ 
		var dx : Float = (v.x-m_position.x); var dy : Float = (v.y-m_position.y); var dz : Float = (v.z-m_position.z);
		if (Math.abs(dx) < Mathf.Epsilon)
		if (Math.abs(dy) < Mathf.Epsilon)
		if (Math.abs(dz) < Mathf.Epsilon) return v;			
		Translate(dx, dy, dz);				
		return v;
	}
	private var m_position : Vector3;
	
	/**
	 * Sets the Transform position in its parent local space.
	 */
	public var localPosition(get_localPosition, set_localPosition):Vector3;		
	private function get_localPosition():Vector3 {  if (parent == null) return position; var wm : Matrix4 = parent.WorldMatrix;	return parent.WorldMatrixInverse.Transform3x4(Vector3.temp.Set3(m_position)); }
	private function set_localPosition(v:Vector3):Vector3 { if (parent == null) return v; position = parent.WorldMatrix.Transform3x4(v); return v; }
	
	
	/**
	 * Sets the Transform euler angles in world space.
	 */
	public var euler(get_euler, set_euler):Vector3;		
	private function get_euler():Vector3 { return Vector3.zero.Set(m_euler.x,m_euler.y,m_euler.z); }
	private function set_euler(v:Vector3):Vector3
	{ 
		var dx : Float = (v.x-m_euler.x); var dy : Float = (v.y-m_euler.y); var dz : Float = (v.z-m_euler.z);
		if (Math.abs(dx) < Mathf.Epsilon)
		if (Math.abs(dy) < Mathf.Epsilon)
		if (Math.abs(dz) < Mathf.Epsilon) return v;			
		Rotate(dx, dy, dz);		
		return v;
	}
	private var m_euler : Vector3;
	
	/**
	 * Sets the Transform euler angles in its parent local space.
	 */
	public var localEuler(get_localEuler, set_localEuler):Vector3;		
	private function get_localEuler():Vector3 { if (parent == null) return euler; return Vector3.zero.Set(m_euler.x - parent.m_euler.x, m_euler.y - parent.m_euler.y, m_euler.z - parent.m_euler.z); }
	private function set_localEuler(v:Vector3):Vector3 { if (parent == null) return v; euler = Vector3.temp.Set3(parent.m_euler).Add(v); return v; }
	
	
	/**
	 * Sets the Transform rotation in world space.
	 */
	public var rotation(get_rotation, set_rotation):Quaternion;		
	private function get_rotation():Quaternion { return Quaternion.FromEuler(m_euler); }
	private function set_rotation(v:Quaternion):Quaternion { euler = Quaternion.ToEuler(v, Vector3.temp); return v;	}
	
	/**
	 * Sets the Transform rotation in its parent local space.
	 */
	public var localRotation(get_localRotation, set_localRotation):Quaternion;		
	private function get_localRotation():Quaternion { if (parent == null) return rotation; return Quaternion.FromEuler(Vector3.temp.Set(m_euler.x-parent.m_euler.x,m_euler.y-parent.m_euler.y,m_euler.z-parent.m_euler.z)); }
	private function set_localRotation(v:Quaternion):Quaternion { localEuler = Quaternion.ToEuler(v, Vector3.temp); return v; }
	
	/**
	 * Sets the Transform scale in world space.
	 */
	public var scale(get_scale, never):Vector3;		
	private function get_scale():Vector3 
	{ 
		//RefreshWM();
		return m_scale.clone;
		/*
		var wm : Matrix4 = WorldMatrix;
		var d0:Float = Math.sqrt(wm.m00 * wm.m00 + wm.m10 * wm.m10 + wm.m20 * wm.m20);
		var d1:Float = Math.sqrt(wm.m01 * wm.m01 + wm.m11 * wm.m11 + wm.m21 * wm.m21);
		var d2:Float = Math.sqrt(wm.m02 * wm.m02 + wm.m12 * wm.m12 + wm.m22 * wm.m22);
		return Vector3.zero.Set(d0,d1,d2); 
		//*/
	}
	private var m_scale : Vector3;
	
	/**
	 * Sets the Transform euler angles in its parent local space.
	 */
	public var localScale(get_localScale, set_localScale):Vector3;		
	private function get_localScale():Vector3 { return m_localScale.clone; }
	private function set_localScale(v:Vector3):Vector3 
	{ 
		var dx : Float = (v.x - m_localScale.x); 
		var dy : Float = (v.y - m_localScale.y); 
		var dz : Float = (v.z - m_localScale.z);		
		if (Math.abs(dx) < Mathf.Epsilon)
		if (Math.abs(dy) < Mathf.Epsilon)
		if (Math.abs(dz) < Mathf.Epsilon) return v;	
		m_localScale.Set3(v);
		var ps : Vector3;
		
		ps = parent == null ? Vector3.temp.Set(1, 1, 1) : parent.m_scale;
		m_scale.x = m_localScale.x * ps.x; 
		m_scale.y = m_localScale.y * ps.y; 
		m_scale.z = m_localScale.z * ps.z;
		
		Traverse(function(t:Transform):Bool
		{
			if (t == this) return true;
			var pp : Vector3 = t.parent == null ? Vector3.temp.Set(0, 0, 0) : t.parent.m_position;
			ps = t.parent==null ? Vector3.temp.Set(1,1,1) : t.parent.m_scale;
			t.m_scale.x = t.m_localScale.x * ps.x; 
			t.m_scale.y = t.m_localScale.y * ps.y; 
			t.m_scale.z = t.m_localScale.z * ps.z;			
			var v : Vector3    = Vector3.temp.Set3(t.m_position).Sub(pp);
			v.Multiply(ps);
			v.Add(pp);
			t.position = v;			
			EngineContext.transform.OnChange(t);
			return true;
		});	
		
		m_dirty = true;
		return v;
	}
	private var m_localScale : Vector3;
	
	
	/**
	 * World space transform matrix.
	 */
	public var WorldMatrix(get_WorldMatrix, never) : Matrix4;			
	private function get_WorldMatrix() : Matrix4 { RefreshWM(); return m_worldMatrix; }	
	private var m_worldMatrix : Matrix4;
	
	/**
	 * World space inverse matrix.
	 */
	public var WorldMatrixInverse(get_WorldMatrixInverse, never) : Matrix4;			
	private function get_WorldMatrixInverse() : Matrix4 { RefreshWM(); return m_worldMatrixInverse; }
	private var m_worldMatrixInverse : Matrix4;
	
	/**
	 * Flag that indicates if the WorldTransform must be rebuilt.
	 */
	private var m_dirty : Bool;
	
	/**
	 * List of children.
	 */
	private var m_hierarchy : Array<Transform>;	
	
	
	/**
	 * Creates a new Transform
	 */
	function new() 
	{
		super();
		
		__cid = EngineContext.transform.tid.id;
		
		m_position   = Vector3.zero;
		m_euler	   	 = Vector3.zero;
		m_localScale = Vector3.one;	
		m_scale		 = Vector3.one;	
		m_dirty 	= false;
		
		m_right		= Vector3.right;
		m_up		= Vector3.up;
		m_forward	= Vector3.forward;
		
		//m_localMatrix 			= Matrix4.identity;
		m_worldMatrixInverse    = Matrix4.identity;
		m_worldMatrix 			= Matrix4.identity;
		
		m_hierarchy   		 = [];
		
		if (m_root != null) parent = null;	else m_root = this;		
	}
	
	/**
	 * Translate this Transform position by the specified delta. Returns its own reference.
	 * @param	p_dx
	 * @param	p_dy
	 * @param	p_dz
	 * @return
	 */
	public function Translate(p_dx:Float, p_dy:Float, p_dz:Float):Transform
	{
		m_position.Add3(p_dx, p_dy, p_dz);
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Translate(p_dx, p_dy, p_dz);		
		m_dirty = true;
		EngineContext.transform.OnChange(this);
		return this;
	}
	
	/**
	 * Rotates this Transform by the specified delta.
	 * @param	p_dx
	 * @param	p_dy
	 * @param	p_dz
	 * @return
	 */
	public function Rotate(p_dx : Float, p_dy:Float, p_dz : Float):Transform
	{
		m_euler.Add3(p_dx, p_dy, p_dz);
		for (i in 0...m_hierarchy.length)
		{
			var c : Transform = m_hierarchy[i];						
			var q : Quaternion = Quaternion.FromEuler(m_euler, Quaternion.temp);			
			var v : Vector3    = Vector3.temp.Set3(c.m_position).Sub(m_position);						
			q.Rotate(v);			
			v.Add(m_position);									
			c.position = v;			
			c.Rotate(p_dx, p_dy, p_dz);			
		}
		m_dirty = true;
		EngineContext.transform.OnChange(this);
		return this;
	}
	
	/**
	 * Shortcut for the UpdateWorldMatrix check/update code.
	 */
	private inline function RefreshWM():Void { if (m_dirty) { UpdateWorldMatrix(); } }
	
	/**
	 * Method invoked when this Transform suffered changes and must be updated.
	 */
	private function UpdateWorldMatrix():Void
	{
		var q : Quaternion = Quaternion.FromEuler(m_euler, Quaternion.temp);			
		var sx:Float = m_scale.x; 		var sy:Float = m_scale.y; 		var sz:Float = m_scale.z;		
		var px:Float = m_position.x;	var py:Float = m_position.y;	var pz:Float = m_position.z;		
		var rx : Float = q.x; 			var ry : Float = q.y; 			var rz : Float = q.z; 			var rw : Float = q.w;				
		var x2:Float = rx * rx;
		var y2:Float = ry * ry;
		var z2:Float = rz * rz;		
		var xy:Float = rx * ry;
		var xz:Float = rx * rz;
		var yz:Float = ry * rz;
		var xw:Float = rw * rx;
		var yw:Float = rw * ry;
		var zw:Float = rw * rz;		
		var r : Matrix4 = Matrix4.temp;		
		r.m00 = 1.0 - 2.0 * ( y2 + z2 ); r.m01 =       2.0 * ( xy - zw ); r.m02 =       2.0 * ( xz + yw );		
		r.m10 =       2.0 * ( xy + zw ); r.m11 = 1.0 - 2.0 * ( x2 + z2 ); r.m12 =       2.0 * ( yz - xw );		
		r.m20 =       2.0 * ( xz - yw ); r.m21 =       2.0 * ( yz + xw ); r.m22 = 1.0 - 2.0 * ( x2 + y2 );
		
		m_right.Set  (r.m00, r.m10, r.m20);
		m_up.Set	 (r.m01, r.m11, r.m21);
		m_forward.Set(r.m02, r.m12, r.m22);
		
		var l : Matrix4 = m_worldMatrix;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz; l.m03 = px;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz; l.m13 = py;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz; l.m23 = pz;	
		
		m_scale.x = sx;
		m_scale.y = sy;
		m_scale.z = sz;
		
		Matrix4.GetInverseTransform(m_worldMatrix, m_worldMatrixInverse);
		m_dirty = false;		
	}

	/**
	 * Returns a child at a given index.
	 * @param	p_index
	 */
	public function GetChild(p_index : Int) : Transform { return m_hierarchy[p_index]; }
	
	/**
	 * Returns a child with the specified name.
	 * @param	p_index
	 */
	public function GetChildByName(p_name : String) : Transform 
	{
		for (i in 0...m_hierarchy.length) if (m_hierarchy[i].name == p_name) return m_hierarchy[i];
		return null;		
	}
	
	/**
	 * Locks the update of matrix for this Transform and its children.
	 */
	public function Lock():Void
	{
		//m_lock = true;
		//for (i in 0...m_hierarchy.length) m_hierarchy[i].Lock();
	}
	
	/**
	 * Unlocks the update of matrix for this Transform and its children and apply the changes.
	 */
	public function Unlock():Void
	{
		//m_lock = false;
		//for (i in 0...m_hierarchy.length) m_hierarchy[i].Unlock();
	}
	
	/**
	 * Navigates the dot separated path and searches for the specified child.
	 * @param	p_path
	 * @return
	 */
	public function Navigate(p_path:String):Transform
	{
		var tk :Array<String> = p_path.split(".");
		var t : Transform = this;
		while (tk.length > 0)
		{
			var p :String = tk.shift();
			t = t.GetChildByName(p);
			if (t == null) return null;
		}
		return t;
	}
	
	/**
	 * Searches all hierarchy for a child with the specified name. If not exact the search will use 'indexof' to match the name.
	 * @param	p_name
	 * @param	p_exact
	 * @return
	 */
	public function Search(p_name : String,p_exact : Bool=true) : Transform
	{
		var res : Transform = null;
		Traverse(function(it : Transform):Bool
		{
			if (it == this) 	return true;
			if (res != null) 	return true;
			if (p_exact) 
			{
				if (it.name == p_name) res = it;		
			}
			else
			{
				if (it.name.indexOf(p_name) >= 0) res = it;
			}
			return true;
		});
		return res;
	}
	
	/**
	 * List of transform from this instance to root.
	 * @return
	 */
	public function GetPathToRoot():Array<Transform>
	{
		var p : Transform = parent;
		var res : Array<Transform> = [];		
		while (p != null)
		{
			res.push(p);
			p = p.parent;
		}
		res.reverse();
		return res;
	}
	
	/**
	 * Prints the hierarchy of this transform.
	 * @return
	 */
	public function OutputHierarchy():String
	{
		var d0 : Int = 0;// cast m_depth;
		var hs : String = "";
		Traverse(function(t : Transform):Bool
		{
			var tab : String = "";
			var td : Int = 0;// cast t.m_depth;
			var d	: Int = Mathf.MaxInt(0, td - d0);
			for (i in 0...d) tab += " ";
			hs += tab + t.name + " " + t.position.ToString() + t.rotation.ToString() + t.scale.ToString() + "\n";
			return true;
		});
		return hs;		
	}
	
	/**
	 * Perform a DepthFirstSearch in this transform hierarchy, calling the specified method in each child.
	 * If the method returns false, the search stops.
	 * @param	p_callback
	 */
	public function Traverse(p_callback : Transform -> Bool):Void { TraverseStep(this, p_callback); }
	
	/**
	 * Auxiliar function for the Traverse method.
	 * @param	p_child
	 * @param	p_callback
	 */
	private function TraverseStep(p_child : Transform, p_callback : Transform -> Bool):Void { if(p_callback(p_child)) for (i in 0...p_child.childCount) TraverseStep(p_child.GetChild(i), p_callback); }
	
	/**
	 * Callback called when this Transform is destroyed.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.transform.tid.id = __cid;
	}
	
	/**
	 * Returns the string representation of this Transform.
	 * @param	p_places
	 * @return
	 */
	public function ToString(p_use_local:Bool=false,p_places:Int=2):String
	{
		var p : Vector3 = p_use_local ? localPosition : m_position;
		var e : Vector3 = p_use_local ? localEuler	  : m_euler;
		var s : Vector3 = p_use_local ? localScale    : scale;
		return name+" " + p.ToString(p_places) + "" + e.ToString(p_places) + "" + s.ToString(p_places);
	}
}