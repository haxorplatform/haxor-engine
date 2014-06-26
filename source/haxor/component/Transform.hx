/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.component;

import haxe.Timer;
import js.Browser;
import js.html.ArrayBufferView;
import js.html.Float32Array;
import js.html.idb.Transaction;
import js.Lib;
import haxor.api.TextureAPI;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Time;
import haxor.math.Mathf;
import haxor.physics.BoxCollider;
import haxor.thread.Thread;
import haxor.thread.TransformKernel;

import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Transform extends Component
{
	
	
	
	/**
	 * 
	 */
	static public var root(get_root, never) : Transform;	
	static private var m_root : Transform;
	static function get_root():Transform { return m_root; }
	
	
	static private var m_indexes : Array<Int>;
	
	static private var m_list : Array<Transform>;
	
	static public var m_threaded : Bool;
	
	static public var m_kernel : TransformKernel;
	
	static private var m_sync_iterator : Int;
	
	static private var m_boot : Int;
	
	static private function Initialize():Void
	{	
		m_threaded  = TextureAPI.TEXTURE_FLOAT;		
		if (Browser.navigator.userAgent.toLowerCase().indexOf("chrome") < 0) 	m_threaded = false;
		if (Browser.navigator.userAgent.toLowerCase().indexOf("android") >= 0) 	m_threaded = false;
		if (Browser.navigator.userAgent.toLowerCase().indexOf("iphone") >= 0) 	m_threaded = false;
		if (Browser.navigator.userAgent.toLowerCase().indexOf("ipad") >= 0) 	m_threaded = false;
		m_threaded = false;
		if (m_threaded)
		{
			m_kernel = new TransformKernel();
			m_kernel.Init(m_root);
			m_sync_iterator = 0;
			m_boot = 8;
		}
		
		trace("Haxor> Transform Initialize Threaded["+m_threaded+"]");
	}
	
	
	
	static public function Update(p_sync : Bool):Void
	{	
		if (m_threaded)
		{				
			if (m_boot > 0) { root.Concat(); m_boot--; }
			if (p_sync)
			{				
				for (i in 0...cast(m_list.length))
				{
					m_list[m_sync_iterator].KernelSync();
					m_sync_iterator = (m_sync_iterator + 1) % m_list.length;
				}
			}
			else
			{
				m_kernel.Execute();
			}
		}
	}
	
	private var m_depth : Int;
	
	private var m_tid:Int;
	
	private var m_dirty:Bool;
	
	private var m_concat : Bool;
	
	private var m_hierarchy : Array<Transform>;	
	
	private var m_lock : Bool;
	
	private var m_tm0 : Matrix4;
	
	private var m_tm1 : Matrix4;
	
	/**
	 * 
	 */
	public var right(get_right, never):Vector3;	
	private function get_right():Vector3 
	{ 
		//return WorldMatrix.Rotate(Vector3.right);
		var wm :Matrix4 = m_worldMatrix;
		return Vector3.temp.Set(wm.m00, wm.m10, wm.m20);
	}
	private function set_right(v:Vector3):Vector3 { return v; }
	
	/**
	 * 
	 */
	public var up(get_up, never):Vector3;		
	private function get_up():Vector3 
	{ 
		//return WorldMatrix.Rotate(Vector3.right);
		var wm :Matrix4 = m_worldMatrix;
		return Vector3.temp.Set(wm.m01, wm.m11, wm.m21); 
	}
	private function set_up(v:Vector3):Vector3 { return v; }
	
	/**
	 * 
	 */
	public var forward(get_forward, never):Vector3;
	private function get_forward():Vector3 
	{ 
		//return WorldMatrix.Rotate(Vector3.right);
		var wm :Matrix4 = m_worldMatrix;
		return Vector3.temp.Set(wm.m02, wm.m12, wm.m22); 
	}
	private function set_forward(v:Vector3):Vector3 { return v; }
	
	
	/**
	 * 
	 */
	public var parent(get_parent, set_parent):Transform;
	private var m_parent : Transform;
	private function get_parent():Transform { return m_parent; }
	private function set_parent(v:Transform):Transform
	{		
		if (m_parent != null) m_parent.m_hierarchy.remove(this);
		m_parent = v == null ? m_root : v;		
		m_parent.m_hierarchy.push(this);
		if (m_threaded) { m_kernel.SetParent(this); m_kernel.SetConcat(this, true); }
		m_dirty = true;		
		UpdateDepth();		
		Concat();		
		return this;
	}
	
	private function UpdateDepth():Void
	{
		m_depth = m_parent == null ? 0 : m_parent.m_depth + 1;		
		for (i in 0...m_hierarchy.length) m_hierarchy[i].UpdateDepth();
	}
	
	
	/**
	 * 
	 */
	public var position(get_position, set_position):Vector3;	
	private var m_position : Vector3;
	private function get_position():Vector3 { return Vector3.temp.Set(m_position.x,m_position.y,m_position.z); }
	private function set_position(v:Vector3):Vector3
	{ 
		
		var tx : Float = m_position.x;		
		if (Math.abs(tx - v.x) < Mathf.Epsilon)
		{
			var ty : Float = m_position.y;
			if (Math.abs(ty - v.y) < Mathf.Epsilon)
			{
				var tz : Float = m_position.z;				
				if (Math.abs(tz - v.z) < Mathf.Epsilon)
				{
					return v;
				}
			}
		}		
		
		m_position.x = v.x;
		m_position.y = v.y;
		m_position.z = v.z;
		if (m_threaded) { m_kernel.SetPosition(this); m_kernel.SetDirty(this, true); }
		m_dirty = true;		
		Concat();		
		return v;
	}
	
	
	/**
	 * 
	 */
	public var rotation(get_rotation, set_rotation):Quaternion;	
	private var m_rotation : Quaternion;
	private function get_rotation():Quaternion { return Quaternion.temp.Set(m_rotation.x,m_rotation.y,m_rotation.z,m_rotation.w); }
	private function set_rotation(v:Quaternion):Quaternion
	{ 
		var tx : Float = m_rotation.x;		
		if (Math.abs(tx - v.x) < Mathf.Epsilon)
		{
			var ty : Float = m_rotation.y;
			if (Math.abs(ty - v.y) < Mathf.Epsilon)
			{
				var tz : Float = m_rotation.z;				
				if (Math.abs(tz - v.z) < Mathf.Epsilon)
				{
					var tw : Float = m_rotation.w;
					if (Math.abs(tw - v.w) < Mathf.Epsilon) return v;
				}
			}
		}		
		m_rotation.x = v.x;
		m_rotation.y = v.y;
		m_rotation.z = v.z;
		m_rotation.w = v.w;		
		if (m_threaded) { m_kernel.SetRotation(this); m_kernel.SetDirty(this, true); }
		m_dirty = true;		
		Concat();		
		return v;
	}
	
	
	
	/**
	 * 
	 */
	public var scale(get_scale, set_scale):Vector3;	
	private var m_scale : Vector3;
	private function get_scale():Vector3 { return Vector3.temp.Set(m_scale.x,m_scale.y,m_scale.z); }
	private function set_scale(v:Vector3):Vector3
	{ 
		var tx : Float = m_scale.x;		
		if (Math.abs(tx - v.x) < Mathf.Epsilon)
		{
			var ty : Float = m_scale.y;
			if (Math.abs(ty - v.y) < Mathf.Epsilon)
			{
				var tz : Float = m_scale.z;				
				if (Math.abs(tz - v.z) < Mathf.Epsilon)
				{
					return v;
				}
			}
		}			
		m_scale.x = v.x;
		m_scale.y = v.y;
		m_scale.z = v.z;	
		if (m_threaded) { m_kernel.SetScale(this); m_kernel.SetDirty(this, true); }
		m_dirty = true;		
		Concat();				
		return v;
	}
	
	
	public var LocalMatrix(get_LocalMatrix, never) : Matrix4;	
	private var m_localMatrix : Matrix4;
	private function set_LocalMatrix(v:Matrix4) : Void  
	{ 
		var m : Matrix4 = m_localMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23;		
		//m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
	}	
	private function get_LocalMatrix() : Matrix4		
	{
		if (m_threaded)
		{
			m_kernel.GetLocalMatrix(this);			
			m_dirty = false;
		}
		else
		{
			if (m_dirty)
			{
				SetLocalTRS();
				m_dirty = false;
			}
		}
		
		var m : Matrix4 = m_tm0;
		var v : Matrix4 = m_localMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		//*/
		return m;
	}	
	
	public var WorldMatrix(get_WorldMatrix, never) : Matrix4;	
	private var m_worldMatrix : Matrix4;
	private function set_WorldMatrix(v:Matrix4) : Void  
	{ 
		var m : Matrix4 = m_worldMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23;		
		//m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
	}
	
	private function get_WorldMatrix() : Matrix4		
	{
		var m : Matrix4 = Matrix4.temp;
		var v : Matrix4 = m_worldMatrix;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
		//m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}	
	
	public var WorldMatrixInverse(get_WorldMatrixInverse, never) : Matrix4;	
	private var m_worldMatrixInverse : Matrix4;
	private function set_WorldMatrixInverse(v:Matrix4) : Void  
	{ 
		var m : Matrix4 = m_worldMatrixInverse;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23;	
		//m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
	}
	
	private function get_WorldMatrixInverse() : Matrix4		
	{
		var m : Matrix4 = Matrix4.temp;
		var v : Matrix4 = m_worldMatrixInverse;
		m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
		m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
		m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}
	
	private function WMToF32() : Float32Array
	{
		if (m_threaded) return m_kernel.GetWorldMatrix(this).ToBuffer();
		return m_worldMatrix.ToBuffer();		
	}
	
	private function WMIToF32() : Float32Array
	{
		if (m_threaded) return m_kernel.GetWorldMatrixInverse(this).ToBuffer();
		return m_worldMatrixInverse.ToBuffer();		
	}
	
	public function Concat():Void
	{	
		
		if (m_lock) return;
		
		m_concat = true;
		
		
		if (m_threaded)
		{			
			m_kernel.SetConcat(this, true);
			for (i in 0...m_hierarchy.length) m_hierarchy[i].Concat();
		}
		else
		{
			//if (parent != null)
			{
				var v : Matrix4 = parent.m_worldMatrix;
				var m : Matrix4 = m_worldMatrix;
				m.m00 = v.m00; m.m01 = v.m01; m.m02 = v.m02; m.m03 = v.m03;
				m.m10 = v.m10; m.m11 = v.m11; m.m12 = v.m12; m.m13 = v.m13;
				m.m20 = v.m20; m.m21 = v.m21; m.m22 = v.m22; m.m23 = v.m23; 
				
				m.MultiplyTransform(LocalMatrix);
				//set_WorldMatrix(m);		
				Matrix4.GetInverseTransform(m, m_worldMatrixInverse);
				
				//set_WorldMatrixInverse(m);
				//if(name == "ground") trace("inverse: " + m.clone.MultiplyTransform(m_worldMatrixInverse).ToString());
				UpdateComponents();
				for (i in 0...m_hierarchy.length) m_hierarchy[i].Concat();
			}
		}			
	}
	
	
	
	private function KernelSync():Void
	{	
		if (m_dirty)
		{
			m_kernel.GetLocalMatrix(this);
			m_dirty = false;
			m_kernel.SetDirty(this, false);
		}
		
		if (m_concat)
		{
			m_kernel.GetWorldMatrix(this);
			m_kernel.GetWorldMatrixInverse(this);			
			UpdateComponents();
			m_concat = false;			
			m_kernel.SetConcat(this, false);
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
		
		var r : Matrix4 = m_tm1;
		
		r.m00 = 1.0 - 2.0 * ( y2 + z2 );
		r.m01 =       2.0 * ( xy - zw );
		r.m02 =       2.0 * ( xz + yw );		
		r.m10 =       2.0 * ( xy + zw );
		r.m11 = 1.0 - 2.0 * ( x2 + z2 );
		r.m12 =       2.0 * ( yz - xw );		
		r.m20 =       2.0 * ( xz - yw );
		r.m21 =       2.0 * ( yz + xw );
		r.m22 = 1.0 - 2.0 * ( x2 + y2 );
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
	
	
	/**
	 * 
	 */
	function new(p_entity : Entity) 
	{
		super(p_entity);
		
		if(m_list == null) 	  m_list		= [];
		if(m_indexes == null) m_indexes 	= [];
		
		m_position = Vector3.zero;
		m_rotation = Quaternion.identity;
		m_scale    = Vector3.one;
		
		m_localMatrix 			= Matrix4.identity;
		m_worldMatrixInverse    = Matrix4.identity;
		m_worldMatrix 			= Matrix4.identity;
		
		m_tm0 = Matrix4.identity;
		m_tm1 = Matrix4.identity;
		
		var tid : Int 	= m_indexes.length > 0 ? m_indexes.shift() : m_list.length;		
		m_tid 			= tid;
		if (tid >= m_list.length) m_list.push(this); else m_list[tid] = this;
		
		m_depth 	  		 = 0;
		m_hierarchy   		 = new Array<Transform>();
		m_dirty  	  		 = true;
		m_concat			 = true;
		
		if (m_root != null) parent = null;	
		
		if (m_threaded) m_kernel.Init(this);
		
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		var tid : Int = cast m_tid;
		m_list[tid] = null;		
		m_indexes.push(tid);
	}
	
	public function Lock():Void
	{
		m_lock = true;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Lock();
	}
	
	public function Unlock():Void
	{
		m_lock = false;
		for (i in 0...m_hierarchy.length) m_hierarchy[i].Unlock();
	}
	
	/**
	 * 
	 * @param	p_index
	 */
	public function GetChild(p_index : Int) : Transform { return m_hierarchy[p_index]; }
	
	/**
	 * 
	 * @param	p_index
	 */
	public function GetChildByName(p_name : String) : Transform 
	{
		for (i in 0...m_hierarchy.length) if (m_hierarchy[i].name == p_name) return m_hierarchy[i];
		return null;		
	}
	
	/**
	 * 
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
	 * 
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
			var d	: Int = Mathf.MaxInt([0, td - d0]);
			for (i in 0...d) tab += " ";
			hs += tab + t.name + " " + t.position.ToString() + t.rotation.ToString() + t.scale.ToString() + "\n";
			return true;
		});
		return hs;		
	}
	
	/**
	 * 
	 * @param	p_callback
	 */
	public function Traverse(p_callback : Transform -> Bool):Void
	{
		TraverseStep(this, p_callback);
	}
	
	function TraverseStep(p_child : Transform, p_callback : Transform -> Bool):Void
	{
		var go_deep : Bool = p_callback(p_child);
		if(go_deep) for (i in 0...p_child.childCount) TraverseStep(p_child.GetChild(i), p_callback);		
	}
}