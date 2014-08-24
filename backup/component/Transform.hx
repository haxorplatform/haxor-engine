package haxor.component;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;


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
		
	private var m_depth : Int;
	
	private var m_dirty:Bool;
	
	private var m_concat : Bool;
	
	private var m_hierarchy : Array<Transform>;	
	
	private var m_lock : Bool;
	
	/**
	 * Right world axis vector
	 */
	public var right(get_right, null):Vector3;	
	private function get_right():Vector3 { return Vector3.zero.Set(m_worldMatrix.m00, m_worldMatrix.m10, m_worldMatrix.m20); }
	private function set_right(v:Vector3):Vector3 { return v; }
	
	/**
	 * Up world axis vector
	 */
	public var up(get_up, null):Vector3;		
	private function get_up():Vector3 { return Vector3.zero.Set(m_worldMatrix.m01, m_worldMatrix.m11, m_worldMatrix.m21); }
	private function set_up(v:Vector3):Vector3 { return v; }
	
	/**
	 * Forward world axis vector
	 */
	public var forward(get_forward, null):Vector3;
	private function get_forward():Vector3 { return Vector3.zero.Set(m_worldMatrix.m02, m_worldMatrix.m12, m_worldMatrix.m22); }
	private function set_forward(v:Vector3):Vector3 { return v; }
	
	
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
		m_dirty = true;	
		UpdateDepth();		
		Concat();		
		return this;
	}
	private var m_parent : Transform;
	
	/**
	 * 
	 */
	private function UpdateDepth():Void
	{
		m_depth = m_parent == null ? 0 : m_parent.m_depth + 1;		
		for (i in 0...m_hierarchy.length) m_hierarchy[i].UpdateDepth();
	}
	
	
	/**
	 * Sets the Transform position.
	 */
	public var position(get_position, set_position):Vector3;		
	private function get_position():Vector3 { return Vector3.zero.Set(m_position.x,m_position.y,m_position.z); }
	private function set_position(v:Vector3):Vector3
	{ 
		if (Math.abs(m_position.x - v.x) < Mathf.Epsilon)
		if (Math.abs(m_position.y - v.y) < Mathf.Epsilon)
		if (Math.abs(m_position.z - v.z) < Mathf.Epsilon) return v;		
		m_position.x = v.x;
		m_position.y = v.y;
		m_position.z = v.z;		
		m_dirty = true;		
		Concat();		
		return v;
	}
	private var m_position : Vector3;
	
	/**
	 * Sets the Transform rotation.
	 */
	public var rotation(get_rotation, set_rotation):Quaternion;		
	private function get_rotation():Quaternion { return Quaternion.identity.Set(m_rotation.x,m_rotation.y,m_rotation.z,m_rotation.w); }
	private function set_rotation(v:Quaternion):Quaternion
	{ 
		if (Math.abs(m_rotation.x - v.x) < Mathf.Epsilon)
		if (Math.abs(m_rotation.y - v.y) < Mathf.Epsilon)				
		if (Math.abs(m_rotation.z - v.z) < Mathf.Epsilon)
		if (Math.abs(m_rotation.w - v.w) < Mathf.Epsilon) return v;
		
		m_rotation.x = v.x;
		m_rotation.y = v.y;
		m_rotation.z = v.z;
		m_rotation.w = v.w;		
		
		m_dirty = true;		
		Concat();		
		return v;
	}
	private var m_rotation : Quaternion;
	
	
	/**
	 * Sets the Transform scale.
	 */
	public var scale(get_scale, set_scale):Vector3;		
	private function get_scale():Vector3 { return Vector3.zero.Set(m_scale.x,m_scale.y,m_scale.z); }
	private function set_scale(v:Vector3):Vector3
	{ 		
		if (Math.abs(m_scale.x - v.x) < Mathf.Epsilon)
		if (Math.abs(m_scale.y - v.y) < Mathf.Epsilon)
		if (Math.abs(m_scale.z - v.z) < Mathf.Epsilon) return v;		
		m_scale.x = v.x;
		m_scale.y = v.y;
		m_scale.z = v.z;		
		m_dirty = true;		
		Concat();				
		return v;
	}
	private var m_scale : Vector3;
	
	/**
	 * Local space transform matrix.
	 */
	public var LocalMatrix(get_LocalMatrix, never) : Matrix4;			
	private function get_LocalMatrix() : Matrix4		
	{
		if (m_dirty)
		{
			SetLocalTRS();
			m_dirty = false;
		}		
		var m : Matrix4 = Matrix4.identity;
		var v : Matrix4 = m_localMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 				
		return m;
	}
	private var m_localMatrix : Matrix4;
	
	/**
	 * World space transform matrix.
	 */
	public var WorldMatrix(get_WorldMatrix, never) : Matrix4;			
	private function get_WorldMatrix() : Matrix4		
	{
		var m : Matrix4 = Matrix4.identity;
		var v : Matrix4 = m_worldMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23;		
		return m;
	}	
	private var m_worldMatrix : Matrix4;
	
	/**
	 * World space inverse matrix.
	 */
	public var WorldMatrixInverse(get_WorldMatrixInverse, never) : Matrix4;			
	private function get_WorldMatrixInverse() : Matrix4		
	{
		var m : Matrix4 = Matrix4.identity;
		var v : Matrix4 = m_worldMatrixInverse;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}
	private var m_worldMatrixInverse : Matrix4;
	
	/**
	 * Creates a new Transform
	 */
	function new() 
	{
		super();
		
		m_position = Vector3.zero;
		m_rotation = Quaternion.identity;
		m_scale    = Vector3.one;
		
		m_localMatrix 			= Matrix4.identity;
		m_worldMatrixInverse    = Matrix4.identity;
		m_worldMatrix 			= Matrix4.identity;
		
		m_depth 	  		 = 0;
		m_hierarchy   		 = [];
		m_dirty  	  		 = true;
		m_concat			 = true;
		
		if (m_root != null) parent = null;	else m_root = this;
		
	}
	
	
	public function Concat():Void
	{	
		//if (parent != null)
		{
			var v : Matrix4 = parent.m_worldMatrix;
			var m : Matrix4 = m_worldMatrix;
			m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
			m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
			m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 			
			m.MultiplyTransform(LocalMatrix);			
			Matrix4.GetInverseTransform(m, m_worldMatrixInverse);			
			UpdateComponents();
			for (i in 0...m_hierarchy.length) m_hierarchy[i].Concat();
		}
	}
	
	private function UpdateComponents():Void
	{
		for (i in 0...entity.m_components.length) entity.m_components[i].OnTransformUpdate();
	}
	
	private function SetLocalTRS():Void
	{
		var sx:Float = m_scale.x;			
		var sy:Float = m_scale.y;
		var sz:Float = m_scale.z;		
		var px:Float = m_position.x;			
		var py:Float = m_position.y;
		var pz:Float = m_position.z;		
		var rx : Float = m_rotation.x;
		var ry : Float = m_rotation.y;
		var rz : Float = m_rotation.z;
		var rw : Float = m_rotation.w;		
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
		 
		//*/
		
		var l : Matrix4 = m_localMatrix;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz; l.m03 = px;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz; l.m13 = py;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz; l.m23 = pz;
		
	}
	
	
	/**
	 * 
	 */
	public var childCount(get_childCount, null):Int;
	private function get_childCount():Int { return m_hierarchy.length; }
	
	
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();		
	}
	
	/**
	 * Locks the update of matrix for this Transform and its children.
	 */
	public function Lock():Void
	{
		m_lock = true;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Lock();
	}
	
	/**
	 * Unlocks the update of matrix for this Transform and its children and apply the changes.
	 */
	public function Unlock():Void
	{
		m_lock = false;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Unlock();
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
		var d0 : Int = cast m_depth;
		var hs : String = "";
		Traverse(function(t : Transform):Bool
		{
			var tab : String = "";
			var td : Int = cast t.m_depth;
			var d	: Int = Mathf.MaxInt(0, td - d0);
			for (i in 0...d) tab += " ";
			hs += tab + t.name + " " + t.position.ToString() + t.rotation.ToString() + t.scale.ToString() + "\n";
			return true;
		});
		return hs;		
	}
	
	/**
	 * Perform a DepthFirstSearch in this transform hierarchy, calling the specified method in each child.
	 * @param	p_callback
	 */
	public function Traverse(p_callback : Transform -> Bool):Void
	{
		TraverseStep(this, p_callback);
	}
	
	/**
	 * Auxiliar function for the Traverse method.
	 * @param	p_child
	 * @param	p_callback
	 */
	private function TraverseStep(p_child : Transform, p_callback : Transform -> Bool):Void
	{
		var go_deep : Bool = p_callback(p_child);
		if(go_deep) for (i in 0...p_child.childCount) TraverseStep(p_child.GetChild(i), p_callback);		
	}
}