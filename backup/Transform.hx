package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Console;
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
	private function get_forward():Vector3 { RefreshWM(); return m_forward.inverse; }
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
		var ps : Vector3 = m_parent.scale;
		ps.x = ps.x <= 0.0 ? 0.0 : (1.0 / ps.x);
		ps.y = ps.y <= 0.0 ? 0.0 : (1.0 / ps.y);
		ps.z = ps.z <= 0.0 ? 0.0 : (1.0 / ps.z);
		m_localScale.x *= ps.x;
		m_localScale.y *= ps.y;
		m_localScale.z *= ps.z;		
		localScale = m_localScale;		
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
	private function get_euler():Vector3 { return m_rotation.euler; }
	private function set_euler(v:Vector3):Vector3 { rotation = Quaternion.FromEuler(v, Quaternion.temp); return v; }
	
	
	/**
	 * Sets the Transform euler angles in its parent local space.
	 */
	public var localEuler(get_localEuler, set_localEuler):Vector3;		
	private function get_localEuler():Vector3 { if (parent == null) return euler; return localRotation.euler; }
	private function set_localEuler(v:Vector3):Vector3 { if (parent == null) return v; localRotation = Quaternion.FromEuler(v,Quaternion.temp); return v; }
	
	
	/**
	 * Sets the Transform rotation in world space.
	 */
	public var rotation(get_rotation, set_rotation):Quaternion;		
	private function get_rotation():Quaternion { return m_rotation.clone; }
	private function set_rotation(v:Quaternion):Quaternion 
	{ 
		var dx : Float = (v.x-m_rotation.x); var dy : Float = (v.y-m_rotation.y); var dz : Float = (v.z-m_rotation.z); var dw : Float = (v.w-m_rotation.w);
		if (Math.abs(dx) < Mathf.Epsilon)
		if (Math.abs(dy) < Mathf.Epsilon)
		if (Math.abs(dz) < Mathf.Epsilon)
		if (Math.abs(dw) < Mathf.Epsilon) return v;	
		
		var dq : Quaternion = Quaternion.DeltaRotation(m_rotation, v, Quaternion.temp);
		m_rotation.Multiply(dq);
		
		Traverse(function(t:Transform,d:Int):Bool
		{
			if (t == this) return true;
			var pp : Vector3 = t.parent == null ? Vector3.temp.Set(0, 0, 0) : t.parent.m_position;
			var v : Vector3    = Vector3.temp.Set3(t.m_position).Sub(pp);
			dq.Transform(v);			
			v.Add(pp);
			t.position = v;
			//trace(t.name+" " + t.scale.ToString());
			t.m_dirty = true;
			EngineContext.transform.OnChange(t);			
			return true;
		});	
		EngineContext.transform.OnChange(this);
		m_dirty = true;		
		return v;	
	}
	private var m_rotation : Quaternion;
	
	
	/**
	 * Sets the Transform rotation in its parent local space.
	 */
	public var localRotation(get_localRotation, set_localRotation):Quaternion;		
	private function get_localRotation():Quaternion 
	{ 
		if (parent == null) return rotation; 		
		var dq : Quaternion = Quaternion.DeltaRotation(parent.m_rotation, m_rotation, Quaternion.temp);
		return dq;
	}
	private function set_localRotation(v:Quaternion):Quaternion 
	{ 
		if (parent == null) { rotation = v; return v; }
		var pq : Quaternion = Quaternion.temp.SetQuaternion(parent.m_rotation);
		rotation = pq.Multiply(v);
		return v; 
	}
	
	/**
	 * Sets the Transform scale in world space.
	 */
	public var scale(get_scale, never):Vector3;		
	private function get_scale():Vector3 
	{ 
		RefreshWM();
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
		
		Traverse(function(t:Transform,d:Int):Bool
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
			//trace(t.name+" " + t.scale.ToString());
			t.m_dirty = true;
			EngineContext.transform.OnChange(t);
			
			return true;
		});	
		EngineContext.transform.OnChange(this);
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
	 * Flag that indicates if the uniforms using this transform must be updates.
	 */
	private var m_uniform_dirty : Bool;
	
	/**
	 * List of children.
	 */
	private var m_hierarchy : Array<Transform>;	
	
	
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		
		__cid = EngineContext.transform.tid.id;		
		m_position   = Vector3.zero;		
		m_rotation	 = Quaternion.identity;
		m_localScale = Vector3.one;	
		m_scale		 = Vector3.one;	
		m_dirty 	 = false;		
		m_uniform_dirty = true;
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
		var rq : Quaternion = Quaternion.FromEuler(Vector3.temp.Set(p_dx, p_dy, p_dz), Quaternion.temp);
		m_rotation.Multiply(rq);
		//Console.Log(name);// +" rotate " + m_euler.ToString());
		for (i in 0...m_hierarchy.length)
		{
			var c : Transform = m_hierarchy[i];							
			var de : Vector3 = Vector3.temp.Set(p_dx, p_dy, p_dz);			
			var q : Quaternion = Quaternion.FromEuler(de, Quaternion.temp);			
			var v : Vector3    = Vector3.temp.Set3(c.m_position).Sub(m_position);			
			q.Transform(v);
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
		var q : Quaternion = m_rotation;
		//var ps : Vector3 = parent == null ? Vector3.temp.Set(1, 1, 1) :	parent.scale;		
		var sx:Float = m_scale.x; 		var sy:Float = m_scale.y; 		var sz:Float = m_scale.z;		
		var px:Float = m_position.x;	var py:Float = m_position.y;	var pz:Float = m_position.z;		
				
		var r : Matrix4 = Matrix4.FromQuaternion(q,Matrix4.temp);		
		
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
		Traverse(function(it : Transform,d:Int):Bool
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
		Traverse(function(t : Transform,d:Int):Bool
		{
			var tab : String = "";
			var td : Int = d;
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
	public function Traverse(p_callback : Transform->Int-> Bool):Void { TraverseStep(this,0, p_callback); }
	
	/**
	 * Auxiliar function for the Traverse method.
	 * @param	p_child
	 * @param	p_callback
	 */
	private function TraverseStep(p_child : Transform,p_depth:Int, p_callback : Transform ->Int-> Bool):Void { if(p_callback(p_child,p_depth)) for (i in 0...p_child.childCount) TraverseStep(p_child.GetChild(i),p_depth+1,p_callback); }
	
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
		var e : Vector3 = p_use_local ? localEuler	  : euler;
		var s : Vector3 = p_use_local ? localScale    : scale;
		return name+" " + p.ToString(p_places) + "" + e.ToString(p_places) + "" + s.ToString(p_places);
	}
}