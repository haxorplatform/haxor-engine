package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.Time;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;




/**
 * Component that handles all Transformation matrix of Entities.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Transform extends Component
{
	
	/**
	 * Updates the matrix system of the transform.
	 * @param	t
	 */
	static private function TransformConcat(t : Transform):Void
	{
		//Parent world matrix should be updated.			
		var v : Matrix4 = t.parent.m_worldMatrix;
		
		//Copy the parent world matrix in this transform.
		var m : Matrix4 = t.m_worldMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
	
		m.MultiplyTransform(t.m_localMatrix);
		
		//Update de 'WS' flags.
		t.m_wsp_dirty  = true;
		t.m_wsrs_dirty = true;
		
		
		t.m_right.Set   (m.m00, m.m10, m.m20).Normalize();
		t.m_up.Set	 	(m.m01, m.m11, m.m21).Normalize();
		t.m_forward.Set (m.m02, m.m12, m.m22).Normalize();
		
		//Signal that the inverse matrix must be rebuilt if requested.
		t.m_inverse_dirty = true;
	}
	
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
	private function get_right():Vector3 { UpdateWorldMatrix(); return m_right.clone; }
	private function set_right(v:Vector3):Vector3 { return v; }
	private var m_right : Vector3;
		
	/**
	 * Up world axis vector
	 */
	public var up(get_up, never):Vector3;		
	private function get_up():Vector3 { UpdateWorldMatrix(); return m_up.clone; }
	private function set_up(v:Vector3):Vector3 { return v; }
	private var m_up : Vector3;
	
	/**
	 * Forward world axis vector
	 */
	public var forward(get_forward, never):Vector3;
	private function get_forward():Vector3 { UpdateWorldMatrix(); return m_forward.inverse; }
	private function set_forward(v:Vector3):Vector3 { return v; }
	private var m_forward : Vector3;
	
	
	/**
	 * Parent Transform of this instance. If set to null the parent will be the  root transform.
	 */
	@serialize
	public var parent(get_parent, set_parent):Transform;	
	private inline function get_parent():Transform { return m_parent; }
	private function set_parent(v:Transform):Transform
	{		
		//Store world coords
		var wp : Vector3 	= position;
		var wr : Quaternion = rotation;
		var ws : Vector3 	= scale;
		
		if (m_parent != null) m_parent.m_hierarchy.remove(this);
		m_parent = v == null ? m_root : v;		
		m_parent.m_hierarchy.push(this);
		
		//Use world coords in new hierarchy.
		//position = wp;
		//rotation = wr;
		//scale 	 = ws;
		Invalidate();
		
		return m_parent;
	}
	private var m_parent : Transform;
	
	/**
	 * Number of children in this transform.
	 */
	public var childCount(get_childCount, null):Int;
	private inline function get_childCount():Int { return m_hierarchy.length; }
	
	/**
	 * Get/set the local position of this transform.
	 */
	@serialize
	public var localPosition(get_localPosition, set_localPosition):Vector3;		
	private function get_localPosition():Vector3 {  return m_localPosition.clone; }
	private function set_localPosition(v:Vector3):Vector3 
	{ 
		var dx : Float32 = (v.x - m_localPosition.x); var dy : Float32 = (v.y - m_localPosition.y); var dz : Float32 = (v.z - m_localPosition.z);		
		if (Math.abs(dx) < Mathf.Epsilon) if (Math.abs(dy) < Mathf.Epsilon)	if (Math.abs(dz) < Mathf.Epsilon) return v;	
		m_localPosition.Set3(v); m_lmt_dirty 	= true;		
		Invalidate();
		return v;
	}
	private var m_localPosition : Vector3;
	
	/**
	 * Get/set this transform local rotation in quaternion form.
	 */
	public var localRotation(get_localRotation, set_localRotation):Quaternion;		
	private function get_localRotation():Quaternion { return m_localRotation.clone;	}
	private function set_localRotation(v:Quaternion):Quaternion 
	{
		var dx : Float32 = (v.x-m_localRotation.x); var dy : Float32 = (v.y-m_localRotation.y); var dz : Float32 = (v.z-m_localRotation.z); var dw : Float32 = (v.w-m_localRotation.w);
		if (Mathf.Abs(dx) < Mathf.Epsilon) if (Mathf.Abs(dy) < Mathf.Epsilon)	if (Mathf.Abs(dz) < Mathf.Epsilon) if (Mathf.Abs(dw) < Mathf.Epsilon) return v;	
		m_localRotation.SetQuaternion(v); m_lmrs_dirty 	= true;			
		Invalidate();
		return v; 
	}
	private var m_localRotation : Quaternion;
	
	/**
	 * Get/set this transform quaternion local rotation in euler form.
	 */
	@serialize
	public var localEuler(get_localEuler, set_localEuler):Vector3;		
	private function get_localEuler():Vector3 { return m_localRotation.euler; }
	private function set_localEuler(v:Vector3):Vector3 { localRotation = Quaternion.FromEuler(v,Quaternion.temp); return v; }
	
	
	/**
	 * Sets the Transform euler angles in its parent local space.
	 */
	@serialize
	public var localScale(get_localScale, set_localScale):Vector3;		
	private function get_localScale():Vector3 { return m_localScale.clone; }
	private function set_localScale(v:Vector3):Vector3 
	{ 
		var dx : Float32 = (v.x - m_localScale.x); var dy : Float32 = (v.y - m_localScale.y); var dz : Float32 = (v.z - m_localScale.z);		
		if (Math.abs(dx) < Mathf.Epsilon) if (Math.abs(dy) < Mathf.Epsilon)	if (Math.abs(dz) < Mathf.Epsilon) return v;	
		m_localScale.Set3(v); m_lmrs_dirty 	= true;
		Invalidate();
		return v;
	}
	private var m_localScale : Vector3;
	
	/**
	 * Get/set the world position of this transform.
	 */
	public var position(get_position, set_position):Vector3;		
	private function get_position():Vector3 { UpdateWorldMatrix(); UpdateWSP(); return m_position.clone; }
	private function set_position(v:Vector3):Vector3 { localPosition = parent.WorldMatrixInverse.Transform3x4(Vector3.temp.Set3(v)); return v; }
	private var m_position : Vector3;
	
	/**
	 * Get/set the world rotation of this transform.
	 */
	public var rotation(get_rotation, set_rotation):Quaternion;		
	private function get_rotation():Quaternion { UpdateWorldMatrix(); UpdateWSRS(); return m_rotation.clone; }
	private function set_rotation(v:Quaternion):Quaternion 
	{ 
		UpdateWorldMatrix(); 
		UpdateWSRS();		
		var iq : Quaternion = Quaternion.Inverse(m_rotation, Quaternion.temp);
		localRotation = Quaternion.temp.SetQuaternion(v).Multiply(iq);
		return v; 
	}
	private var m_rotation : Quaternion;
	
	/**
	 * Get/set the world rotation of this transform in euler form.
	 */
	public var euler(get_euler, set_euler):Vector3;		
	private function get_euler():Vector3 { return rotation.euler; }
	private function set_euler(v:Vector3):Vector3 { rotation = Quaternion.FromEuler(v, Quaternion.temp); return v; }
	
	/**
	 * Gets the aproximate world scale of this transform. Concatenated rotations and scales can alter the precise result of this attribute.
	 */
	public var scale(get_scale, never):Vector3;		
	private function get_scale():Vector3 { UpdateWorldMatrix(); UpdateWSRS(); return m_scale.clone; }
	private var m_scale : Vector3;
	
	/**
	 * World space transform matrix.
	 */	
	public var WorldMatrix(get_WorldMatrix, never) : Matrix4;			
	private function get_WorldMatrix() : Matrix4 { UpdateWorldMatrix(); return m_worldMatrix; }	
	private var m_worldMatrix : Matrix4;
	
	/**
	 * World space inverse matrix.
	 */
	public var WorldMatrixInverse(get_WorldMatrixInverse, never) : Matrix4;			
	private function get_WorldMatrixInverse() : Matrix4 { UpdateWorldMatrix(); if (m_inverse_dirty) { Matrix4.GetInverseTransform(m_worldMatrix, m_worldMatrixInverse); m_inverse_dirty = false; } return m_worldMatrixInverse; }
	private var m_worldMatrixInverse : Matrix4;
	
	/**
	 * Local matrix for matrix combination.
	 */
	private var m_localMatrix : Matrix4;
	
	/**
	 * Flag that indicates that this transform local matrix translation must be updated.
	 */
	private var m_lmt_dirty : Bool;
	
	/**
	 * Flag that indicates that this transform local matrix rotation/scale must be updated.
	 */
	private var m_lmrs_dirty : Bool;
	
	/**
	 * Flag that indicates if the uniforms using this transform must be updated.
	 */
	private var m_uniform_dirty : Bool;
	
	/**
	 * Flag to signal concatenation.
	 */
	private var m_dirty : Bool;
	
	/**
	 * Flag that the inverse world matrix is dirty.
	 */
	private var m_inverse_dirty : Bool;
	
	/**
	 * Flag that indicates if the world space position is dirty.
	 */
	private var m_wsp_dirty : Bool;
	
	/**
	 * Flag that indicates if the world space rotation/scale is dirty.
	 */
	private var m_wsrs_dirty : Bool;
	
	/**
	 * Flag that indicates invalidation is locked.
	 */
	private var m_locked : Bool;
	
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
		m_localPosition = Vector3.zero;		
		m_localRotation	= Quaternion.identity;
		m_localScale 	= Vector3.one;	
		
		m_position		= Vector3.zero;
		m_rotation		= Quaternion.identity;
		m_scale			= Vector3.one;
		
		m_lmt_dirty 	 = false;		
		m_lmrs_dirty	 = false;
		m_dirty			 = false;
		m_inverse_dirty  = false;
		m_wsp_dirty		 = false;
		m_wsrs_dirty	 = false;
		
		m_locked = false;
		
		m_uniform_dirty = true;
		
		m_right		= Vector3.right;
		m_up		= Vector3.up;
		m_forward	= Vector3.forward;		
		m_localMatrix 			= Matrix4.identity;
		m_worldMatrixInverse    = Matrix4.identity;
		m_worldMatrix 			= Matrix4.identity;		
		m_hierarchy   		 	= [];		
		if (m_root != null) parent = null;	else m_root = this;		
	}
	
	/**
	 * Updates the translation sector of local matrix.
	 */
	private function UpdateLMT():Void
	{
		m_localMatrix.m03 = m_localPosition.x;
		m_localMatrix.m13 = m_localPosition.y;
		m_localMatrix.m23 = m_localPosition.z;
	}
	
	/**
	 * Updates the world space position.
	 */
	private function UpdateWSP():Void
	{
		if (m_wsp_dirty)
		{
			m_position.x = m_worldMatrix.m03;
			m_position.y = m_worldMatrix.m13;
			m_position.z = m_worldMatrix.m23;
			m_wsp_dirty = false;
		}
	}
	
	/**
	 * Updates the rotation/scale sector of local matrix.
	 */
	private function UpdateLMRS():Void
	{
		var sx:Float32= m_localScale.x; 		
		var sy:Float32= m_localScale.y; 		
		var sz:Float32= m_localScale.z;
		var r : Matrix4 = Matrix4.FromQuaternion(m_localRotation, Matrix4.temp);		
		var l : Matrix4 = m_localMatrix;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz;
	}
	
	/**
	 * Updates the world rotation/scale of this transform.
	 */
	private function UpdateWSRS():Void
	{
		if (m_wsrs_dirty)
		{
			var m : Matrix4  = m_worldMatrix;
			
			var c0 : Vector3 = Vector3.temp.Set(m.m00, m.m10, m.m20);
			var c1 : Vector3 = Vector3.temp.Set(m.m01, m.m11, m.m21);
			var c2 : Vector3 = Vector3.temp.Set(m.m02, m.m12, m.m22);
			
			var l0 : Float32   = c0.length;	var l1 : Float32   = c1.length; var l2 : Float32   = c2.length;
			
			m_scale.x = l0; m_scale.y = l1;	m_scale.z = l2;
			
			l0 = l0 <= 0.0? 0.0 : (1.0 / l0); l1 = l1 <= 0.0? 0.0 : (1.0 / l1);	l2 = l2 <= 0.0? 0.0 : (1.0 / l2);
			
			c0.Scale(l0); c1.Scale(l1); c2.Scale(l2);
			
			var r : Matrix4 = Matrix4.temp.Set(
			c0.x, c1.x, c2.x, 0.0,
			c0.y, c1.y, c2.y, 0.0,
			c0.z, c1.z, c2.z, 0.0,
			0.0, 0.0, 0.0, 1.0);
			
			Quaternion.FromMatrix4(r, m_rotation);
			
			m_wsrs_dirty = false;
		}
	}
	
	/**
	 * Method invoked when this Transform suffered changes and must be updated.
	 */
	private function UpdateWorldMatrix():Void
	{	
		var need_concat : Bool = m_dirty;		
		//Checks if the local data is dirty and update local matrix.
		if (m_lmt_dirty)  { UpdateLMT();  m_lmt_dirty  = false; need_concat = true; }
		if (m_lmrs_dirty) { UpdateLMRS(); m_lmrs_dirty = false; need_concat = true; }		
		//If the local matrix is dirty, must concat stuff.
		if (parent != null)
		{
			if (m_dirty) { parent.UpdateWorldMatrix(); }
			m_dirty = false;			
			if (need_concat) TransformConcat(this);
		}		
	}
	
	/**
	 * Downward invalidate the hierarchy so they can rebuild their world matrix.
	 */
	private function Invalidate():Void
	{
		if (m_locked) return;
		if (m_dirty) return;
		
		m_uniform_dirty = true;
		m_dirty 		= true;
		
		//Notify components.
		EngineContext.transform.OnChange(this);
		
		//Propagates the invalidation
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Invalidate();
	}
	
	/**
	 * Points the camera towards the target in world space. If smooth is greater than zero the camera will lerp to the orientation during time.
	 * @param	p_at
	 * @param	p_up
	 */
	public function LookAt(p_at : Vector3, p_up : Vector3 = null,p_smooth:Float32=0.0):Void
	{
		var p : Vector3 	= transform.position;
		var r : Quaternion  = Quaternion.temp;
		var q : Quaternion  = Quaternion.LookAt(p, p_at, p_up, Quaternion.temp);
		if (p_smooth > 0)
		{
			r = Quaternion.Lerp(r, q, p_smooth * Time.delta, Quaternion.temp);
		}
		else
		{
			r = q;
		}
		transform.rotation = r;		
	}
	
	/**
	 * Returns a child at a given index.
	 * @param	p_index
	 */
	public function GetChild(p_index : Int) : Transform { return m_hierarchy[p_index]; }
	
	/**
	 * Returns a child with the specified name. If 'deep' is specified, the whole hierarchy is searched.
	 * @param	p_index
	 */
	public function GetChildByName(p_name : String,p_deep:Bool=false) : Transform 
	{
		if (p_deep)
		{
			var res : Transform = null;
			transform.Traverse(function(t:Transform, d:Int):Bool
			{
				if (res != null) return false;
				if (t.name == p_name) { res = t; return false; }				
				return true;
			});
			return res;
		}		
		for (i in 0...m_hierarchy.length) if (m_hierarchy[i].name == p_name) return m_hierarchy[i];
		return null;		
	}
	
	/**
	 * Blocks invalidation and matrix concat until it is unlocked.
	 */
	public function Lock():Void
	{
		m_locked = true;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Lock();
	}
	
	/**
	 * Unlocks invalidation and updates all hierarchy.
	 * @param	p_invalidate
	 */
	public function Unlock(p_invalidate:Bool=true):Void
	{
		m_locked = false;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Unlock(p_invalidate);
		if (p_invalidate) Invalidate();
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
	public function OutputHierarchy(p_show_transform:Bool=true,p_show_world:Bool=false):String
	{
		var d0 : Int = 0;// cast m_depth;
		var hs : String = "";
		Traverse(function(t : Transform,d:Int):Bool
		{
			var tab : String = "";
			var td : Int = d;
			var d	: Int = Mathf.MaxInt(0, td - d0);
			for (i in 0...d) tab += " ";
			hs += tab + t.name + " ";
			if (p_show_transform) hs += t.position.ToString() + t.rotation.ToString() + t.scale.ToString();
			if (p_show_world) 	  hs += t.WorldMatrix.ToString(true, 3);
			hs += "\n";
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
		var p : Vector3 = p_use_local ? localPosition : position;
		var e : Vector3 = p_use_local ? localEuler	  : euler;
		var s : Vector3 = p_use_local ? localScale    : scale;
		return name+" " + p.ToString(p_places) + "" + e.ToString(p_places) + "" + s.ToString(p_places);
	}
}