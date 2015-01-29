package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Transform extends haxor.component.Component
{
	public    Transform(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Transform(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.Transform.__hx_ctor_haxor_component_Transform(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_Transform(haxor.component.Transform __temp_me47, java.lang.String p_name)
	{
		haxor.component.Component.__hx_ctor_haxor_component_Component(__temp_me47, p_name);
	}
	
	
	public static   void TransformConcat(haxor.component.Transform t)
	{
		haxor.math.Matrix4 v = t.m_parent.m_worldMatrix;
		haxor.math.Matrix4 m = t.m_worldMatrix;
		m.m00 = v.m00;
		m.m01 = v.m01;
		m.m02 = v.m02;
		m.m03 = v.m03;
		m.m10 = v.m10;
		m.m11 = v.m11;
		m.m12 = v.m12;
		m.m13 = v.m13;
		m.m20 = v.m20;
		m.m21 = v.m21;
		m.m22 = v.m22;
		m.m23 = v.m23;
		m.MultiplyTransform(t.m_localMatrix);
		t.m_wsp_dirty = true;
		t.m_wsrs_dirty = true;
		t.m_right.Set(m.m00, m.m10, m.m20).Normalize();
		t.m_up.Set(m.m01, m.m11, m.m21).Normalize();
		t.m_forward.Set(m.m02, m.m12, m.m22).Normalize();
		t.m_inverse_dirty = true;
	}
	
	
	
	
	public static   haxor.component.Transform get_root()
	{
		return haxor.component.Transform.m_root;
	}
	
	
	public static  haxor.component.Transform m_root;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Transform(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Transform(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   haxor.math.Vector3 get_right()
	{
		this.UpdateWorldMatrix();
		{
			haxor.math.Vector3 _this = this.m_right;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_right(haxor.math.Vector3 v)
	{
		return v;
	}
	
	
	public  haxor.math.Vector3 m_right;
	
	
	
	public   haxor.math.Vector3 get_up()
	{
		this.UpdateWorldMatrix();
		{
			haxor.math.Vector3 _this = this.m_up;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_up(haxor.math.Vector3 v)
	{
		return v;
	}
	
	
	public  haxor.math.Vector3 m_up;
	
	
	
	public   haxor.math.Vector3 get_forward()
	{
		this.UpdateWorldMatrix();
		{
			haxor.math.Vector3 _this = this.m_forward;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) )).Invert();
		}
		
	}
	
	
	public   haxor.math.Vector3 set_forward(haxor.math.Vector3 v)
	{
		return v;
	}
	
	
	public  haxor.math.Vector3 m_forward;
	
	
	
	public final   haxor.component.Transform get_parent()
	{
		return this.m_parent;
	}
	
	
	public   haxor.component.Transform set_parent(haxor.component.Transform v)
	{
		haxor.math.Vector3 wp = this.get_position();
		haxor.math.Quaternion wr = this.get_rotation();
		haxor.math.Vector3 ws = this.get_scale();
		if (( this.m_parent != null )) 
		{
			this.m_parent.m_hierarchy.remove(this);
		}
		
		if (( v == null )) 
		{
			this.m_parent = haxor.component.Transform.m_root;
		}
		 else 
		{
			this.m_parent = v;
		}
		
		this.m_parent.m_hierarchy.push(this);
		return this.m_parent;
	}
	
	
	public  haxor.component.Transform m_parent;
	
	public  int childCount;
	
	public final   int get_childCount()
	{
		return this.m_hierarchy.length;
	}
	
	
	
	
	public   haxor.math.Vector3 get_localPosition()
	{
		{
			haxor.math.Vector3 _this = this.m_localPosition;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_localPosition(haxor.math.Vector3 v)
	{
		double dx = ( v.x - this.m_localPosition.x );
		double dy = ( v.y - this.m_localPosition.y );
		double dz = ( v.z - this.m_localPosition.z );
		if (( java.lang.Math.abs(dx) < 0.0001 )) 
		{
			if (( java.lang.Math.abs(dy) < 0.0001 )) 
			{
				if (( java.lang.Math.abs(dz) < 0.0001 )) 
				{
					return v;
				}
				
			}
			
		}
		
		this.m_localPosition.Set3(v);
		this.m_lmt_dirty = true;
		this.Invalidate();
		return v;
	}
	
	
	public  haxor.math.Vector3 m_localPosition;
	
	
	
	public   haxor.math.Quaternion get_localRotation()
	{
		{
			haxor.math.Quaternion _this = this.m_localRotation;
			return new haxor.math.Quaternion(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ), ((java.lang.Object) (_this.w) ));
		}
		
	}
	
	
	public   haxor.math.Quaternion set_localRotation(haxor.math.Quaternion v)
	{
		double dx = ( v.x - this.m_localRotation.x );
		double dy = ( v.y - this.m_localRotation.y );
		double dz = ( v.z - this.m_localRotation.z );
		double dw = ( v.w - this.m_localRotation.w );
		if (( java.lang.Math.abs(dx) < 0.0001 )) 
		{
			if (( java.lang.Math.abs(dy) < 0.0001 )) 
			{
				if (( java.lang.Math.abs(dz) < 0.0001 )) 
				{
					if (( java.lang.Math.abs(dw) < 0.0001 )) 
					{
						return v;
					}
					
				}
				
			}
			
		}
		
		this.m_localRotation.SetQuaternion(v);
		this.m_lmrs_dirty = true;
		this.Invalidate();
		return v;
	}
	
	
	public  haxor.math.Quaternion m_localRotation;
	
	
	
	public   haxor.math.Vector3 get_localEuler()
	{
		return this.m_localRotation.get_euler();
	}
	
	
	public   haxor.math.Vector3 set_localEuler(haxor.math.Vector3 v)
	{
		haxor.math.Quaternion __temp_stmt661 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt661 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		this.set_localRotation(haxor.math.Quaternion.FromEuler(v, __temp_stmt661));
		return v;
	}
	
	
	
	
	public   haxor.math.Vector3 get_localScale()
	{
		{
			haxor.math.Vector3 _this = this.m_localScale;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_localScale(haxor.math.Vector3 v)
	{
		double dx = ( v.x - this.m_localScale.x );
		double dy = ( v.y - this.m_localScale.y );
		double dz = ( v.z - this.m_localScale.z );
		if (( java.lang.Math.abs(dx) < 0.0001 )) 
		{
			if (( java.lang.Math.abs(dy) < 0.0001 )) 
			{
				if (( java.lang.Math.abs(dz) < 0.0001 )) 
				{
					return v;
				}
				
			}
			
		}
		
		this.m_localScale.Set3(v);
		this.m_lmrs_dirty = true;
		this.Invalidate();
		return v;
	}
	
	
	public  haxor.math.Vector3 m_localScale;
	
	
	
	public   haxor.math.Vector3 get_position()
	{
		this.UpdateWorldMatrix();
		this.UpdateWSP();
		{
			haxor.math.Vector3 _this = this.m_position;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_position(haxor.math.Vector3 v)
	{
		haxor.math.Vector3 __temp_stmt662 = null;
		{
			haxor.math.Matrix4 _this = this.m_parent.get_WorldMatrixInverse();
			haxor.math.Vector3 __temp_stmt663 = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				__temp_stmt663 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
			}
			
			haxor.math.Vector3 p_point = __temp_stmt663.Set3(v);
			double vx = ( ( ( ( _this.m00 * p_point.x ) + ( _this.m01 * p_point.y ) ) + ( _this.m02 * p_point.z ) ) + _this.m03 );
			double vy = ( ( ( ( _this.m10 * p_point.x ) + ( _this.m11 * p_point.y ) ) + ( _this.m12 * p_point.z ) ) + _this.m13 );
			double vz = ( ( ( ( _this.m20 * p_point.x ) + ( _this.m21 * p_point.y ) ) + ( _this.m22 * p_point.z ) ) + _this.m23 );
			p_point.x = vx;
			p_point.y = vy;
			p_point.z = vz;
			__temp_stmt662 = p_point;
		}
		
		this.set_localPosition(__temp_stmt662);
		return v;
	}
	
	
	public  haxor.math.Vector3 m_position;
	
	
	
	public   haxor.math.Quaternion get_rotation()
	{
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		{
			haxor.math.Quaternion _this = this.m_rotation;
			return new haxor.math.Quaternion(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ), ((java.lang.Object) (_this.w) ));
		}
		
	}
	
	
	public   haxor.math.Quaternion set_rotation(haxor.math.Quaternion v)
	{
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		haxor.math.Quaternion __temp_stmt664 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt664 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion iq = haxor.math.Quaternion.Inverse(this.m_rotation, __temp_stmt664);
		haxor.math.Quaternion __temp_stmt666 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt666 = _this1.m_q.__get(_this1.m_nq = ( (( _this1.m_nq + 1 )) % _this1.m_q.length ));
		}
		
		haxor.math.Quaternion __temp_stmt665 = __temp_stmt666.SetQuaternion(v);
		this.set_localRotation(__temp_stmt665.Multiply(iq, null));
		return v;
	}
	
	
	public  haxor.math.Quaternion m_rotation;
	
	
	
	public   haxor.math.Vector3 get_euler()
	{
		return this.get_rotation().get_euler();
	}
	
	
	public   haxor.math.Vector3 set_euler(haxor.math.Vector3 v)
	{
		haxor.math.Quaternion __temp_stmt667 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt667 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		this.set_rotation(haxor.math.Quaternion.FromEuler(v, __temp_stmt667));
		return v;
	}
	
	
	
	
	public   haxor.math.Vector3 get_scale()
	{
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		{
			haxor.math.Vector3 _this = this.m_scale;
			return new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
	}
	
	
	public  haxor.math.Vector3 m_scale;
	
	
	
	public   haxor.math.Matrix4 get_WorldMatrix()
	{
		this.UpdateWorldMatrix();
		return this.m_worldMatrix;
	}
	
	
	public  haxor.math.Matrix4 m_worldMatrix;
	
	
	
	public   haxor.math.Matrix4 get_WorldMatrixInverse()
	{
		this.UpdateWorldMatrix();
		if (this.m_inverse_dirty) 
		{
			haxor.math.Matrix4.GetInverseTransform(this.m_worldMatrix, this.m_worldMatrixInverse);
			this.m_inverse_dirty = false;
		}
		
		return this.m_worldMatrixInverse;
	}
	
	
	public  haxor.math.Matrix4 m_worldMatrixInverse;
	
	public  haxor.math.Matrix4 m_localMatrix;
	
	public  boolean m_lmt_dirty;
	
	public  boolean m_lmrs_dirty;
	
	public  boolean m_uniform_dirty;
	
	public  boolean m_dirty;
	
	public  boolean m_inverse_dirty;
	
	public  boolean m_wsp_dirty;
	
	public  boolean m_wsrs_dirty;
	
	public  haxe.root.Array<haxor.component.Transform> m_hierarchy;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		{
			haxor.context.UID _this = haxor.context.EngineContext.transform.tid;
			if (( _this.m_cache.length <= 0 )) 
			{
				this.__cid = _this.m_id++;
			}
			 else 
			{
				this.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		this.m_localPosition = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		this.m_localRotation = new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
		this.m_localScale = new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
		this.m_position = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		this.m_rotation = new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
		this.m_scale = new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
		this.m_lmt_dirty = false;
		this.m_lmrs_dirty = false;
		this.m_dirty = false;
		this.m_inverse_dirty = false;
		this.m_wsp_dirty = false;
		this.m_wsrs_dirty = false;
		this.m_uniform_dirty = true;
		this.m_right = new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		this.m_up = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ));
		this.m_forward = haxor.math.Vector3.get_forward();
		this.m_localMatrix = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_worldMatrixInverse = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_worldMatrix = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		this.m_hierarchy = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{});
		if (( haxor.component.Transform.m_root != null )) 
		{
			this.set_parent(null);
		}
		 else 
		{
			haxor.component.Transform.m_root = this;
		}
		
	}
	
	
	public   void UpdateLMT()
	{
		this.m_localMatrix.m03 = this.m_localPosition.x;
		this.m_localMatrix.m13 = this.m_localPosition.y;
		this.m_localMatrix.m23 = this.m_localPosition.z;
	}
	
	
	public   void UpdateWSP()
	{
		if (this.m_wsp_dirty) 
		{
			this.m_position.x = this.m_worldMatrix.m03;
			this.m_position.y = this.m_worldMatrix.m13;
			this.m_position.z = this.m_worldMatrix.m23;
			this.m_wsp_dirty = false;
		}
		
	}
	
	
	public   void UpdateLMRS()
	{
		double sx = this.m_localScale.x;
		double sy = this.m_localScale.y;
		double sz = this.m_localScale.z;
		haxor.math.Matrix4 __temp_stmt668 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt668 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4 r = haxor.math.Matrix4.FromQuaternion(this.m_localRotation, __temp_stmt668);
		haxor.math.Matrix4 l = this.m_localMatrix;
		l.m00 = ( r.m00 * sx );
		l.m01 = ( r.m01 * sy );
		l.m02 = ( r.m02 * sz );
		l.m10 = ( r.m10 * sx );
		l.m11 = ( r.m11 * sy );
		l.m12 = ( r.m12 * sz );
		l.m20 = ( r.m20 * sx );
		l.m21 = ( r.m21 * sy );
		l.m22 = ( r.m22 * sz );
	}
	
	
	public   void UpdateWSRS()
	{
		if (this.m_wsrs_dirty) 
		{
			haxor.math.Matrix4 m = this.m_worldMatrix;
			haxor.math.Vector3 __temp_stmt669 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt669 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
			}
			
			haxor.math.Vector3 c0 = __temp_stmt669.Set(m.m00, m.m10, m.m20);
			haxor.math.Vector3 __temp_stmt670 = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				__temp_stmt670 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
			}
			
			haxor.math.Vector3 c1 = __temp_stmt670.Set(m.m01, m.m11, m.m21);
			haxor.math.Vector3 __temp_stmt671 = null;
			{
				haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
				__temp_stmt671 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
			}
			
			haxor.math.Vector3 c2 = __temp_stmt671.Set(m.m02, m.m12, m.m22);
			double l0 = java.lang.Math.sqrt(( ( ( c0.x * c0.x ) + ( c0.y * c0.y ) ) + ( c0.z * c0.z ) ));
			double l1 = java.lang.Math.sqrt(( ( ( c1.x * c1.x ) + ( c1.y * c1.y ) ) + ( c1.z * c1.z ) ));
			double l2 = java.lang.Math.sqrt(( ( ( c2.x * c2.x ) + ( c2.y * c2.y ) ) + ( c2.z * c2.z ) ));
			this.m_scale.x = l0;
			this.m_scale.y = l1;
			this.m_scale.z = l2;
			if (( l0 <= 0.0 )) 
			{
				l0 = 0.0;
			}
			 else 
			{
				l0 = ( 1.0 / l0 );
			}
			
			if (( l1 <= 0.0 )) 
			{
				l1 = 0.0;
			}
			 else 
			{
				l1 = ( 1.0 / l1 );
			}
			
			if (( l2 <= 0.0 )) 
			{
				l2 = 0.0;
			}
			 else 
			{
				l2 = ( 1.0 / l2 );
			}
			
			c0.Scale(l0);
			c1.Scale(l1);
			c2.Scale(l2);
			haxor.math.Matrix4 __temp_stmt672 = null;
			{
				haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
				__temp_stmt672 = _this3.m_m4.__get(_this3.m_nq = ( (( _this3.m_nm4 + 1 )) % _this3.m_m4.length ));
			}
			
			haxor.math.Matrix4 r = __temp_stmt672.Set(c0.x, c1.x, c2.x, 0.0, c0.y, c1.y, c2.y, 0.0, c0.z, c1.z, c2.z, 0.0, 0.0, 0.0, 0.0, 1.0);
			haxor.math.Quaternion.FromMatrix4(r, this.m_rotation);
			this.m_wsrs_dirty = false;
		}
		
	}
	
	
	public   void UpdateWorldMatrix()
	{
		boolean need_concat = this.m_dirty;
		if (this.m_lmt_dirty) 
		{
			this.UpdateLMT();
			this.m_lmt_dirty = false;
			need_concat = true;
		}
		
		if (this.m_lmrs_dirty) 
		{
			this.UpdateLMRS();
			this.m_lmrs_dirty = false;
			need_concat = true;
		}
		
		if (( this.m_parent != null )) 
		{
			if (this.m_dirty) 
			{
				this.m_parent.UpdateWorldMatrix();
			}
			
			this.m_dirty = false;
			if (need_concat) 
			{
				haxor.component.Transform.TransformConcat(this);
			}
			
		}
		
	}
	
	
	public   void Invalidate()
	{
		if (this.m_dirty) 
		{
			return ;
		}
		
		this.m_uniform_dirty = true;
		this.m_dirty = true;
		haxor.context.EngineContext.transform.OnChange(this);
		{
			int _g1 = 0;
			int _g = this.m_hierarchy.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_hierarchy.__get(i).Invalidate();
			}
			
		}
		
	}
	
	
	public   void LookAt(haxor.math.Vector3 p_at, haxor.math.Vector3 p_up, java.lang.Object p_smooth)
	{
		double __temp_p_smooth41 = ( (( p_smooth == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_smooth)) )) );
		haxor.math.Vector3 p = this.m_entity.m_transform.get_position();
		haxor.math.Quaternion r = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			r = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion q = null;
		{
			haxor.math.Quaternion p_result = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				p_result = _this1.m_q.__get(_this1.m_nq = ( (( _this1.m_nq + 1 )) % _this1.m_q.length ));
			}
			
			haxor.math.Matrix4 __temp_stmt674 = null;
			{
				haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
				__temp_stmt674 = _this2.m_m4.__get(_this2.m_nq = ( (( _this2.m_nm4 + 1 )) % _this2.m_m4.length ));
			}
			
			haxor.math.Matrix4 __temp_stmt673 = haxor.math.Matrix4.LookAt(p, p_at, p_up, __temp_stmt674);
			q = haxor.math.Quaternion.FromMatrix4(__temp_stmt673, p_result);
		}
		
		if (( __temp_p_smooth41 > 0 )) 
		{
			haxor.math.Quaternion __temp_stmt675 = null;
			{
				haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
				__temp_stmt675 = _this3.m_q.__get(_this3.m_nq = ( (( _this3.m_nq + 1 )) % _this3.m_q.length ));
			}
			
			r = haxor.math.Quaternion.Lerp(r, q, ( __temp_p_smooth41 * haxor.core.Time.m_delta ), __temp_stmt675);
		}
		 else 
		{
			r = q;
		}
		
		this.m_entity.m_transform.set_rotation(r);
	}
	
	
	public   haxor.component.Transform GetChild(int p_index)
	{
		return this.m_hierarchy.__get(p_index);
	}
	
	
	public   haxor.component.Transform GetChildByName(java.lang.String p_name)
	{
		{
			int _g1 = 0;
			int _g = this.m_hierarchy.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.m_hierarchy.__get(i).get_name(), p_name)) 
				{
					return this.m_hierarchy.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   haxor.component.Transform Navigate(java.lang.String p_path)
	{
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_path, ".");
		haxor.component.Transform t = this;
		while (( tk.length > 0 ))
		{
			java.lang.String p = tk.shift();
			t = t.GetChildByName(p);
			if (( t == null )) 
			{
				return null;
			}
			
		}
		
		return t;
	}
	
	
	public   haxor.component.Transform Search(java.lang.String p_name, java.lang.Object p_exact)
	{
		boolean __temp_p_exact42 = ( (( p_exact == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_exact)) );
		haxe.root.Array<java.lang.Object> p_exact1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_p_exact42});
		haxe.root.Array<java.lang.String> p_name1 = new haxe.root.Array<java.lang.String>(new java.lang.String[]{p_name});
		haxe.root.Array<haxor.component.Transform> _g = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{this});
		haxe.root.Array<haxor.component.Transform> res = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{null});
		this.Traverse(new haxor.component.Transform_Search_471__Fun(((haxe.root.Array<haxor.component.Transform>) (_g) ), ((haxe.root.Array<java.lang.String>) (p_name1) ), ((haxe.root.Array<java.lang.Object>) (p_exact1) ), ((haxe.root.Array<haxor.component.Transform>) (res) )));
		return res.__get(0);
	}
	
	
	public   haxe.root.Array<haxor.component.Transform> GetPathToRoot()
	{
		haxor.component.Transform p = this.m_parent;
		haxe.root.Array<haxor.component.Transform> res = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{});
		while (( p != null ))
		{
			res.push(p);
			p = p.m_parent;
		}
		
		res.reverse();
		return res;
	}
	
	
	public   java.lang.String OutputHierarchy(java.lang.Object p_show_transform, java.lang.Object p_show_world)
	{
		boolean __temp_p_show_world44 = ( (( p_show_world == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_show_world)) );
		boolean __temp_p_show_transform43 = ( (( p_show_transform == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_show_transform)) );
		haxe.root.Array<java.lang.Object> p_show_world1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_p_show_world44});
		haxe.root.Array<java.lang.Object> p_show_transform1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_p_show_transform43});
		haxe.root.Array<java.lang.Object> d0 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.String> hs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{""});
		this.Traverse(new haxor.component.Transform_OutputHierarchy_513__Fun(((haxe.root.Array<java.lang.Object>) (p_show_transform1) ), ((haxe.root.Array<java.lang.String>) (hs) ), ((haxe.root.Array<java.lang.Object>) (d0) ), ((haxe.root.Array<java.lang.Object>) (p_show_world1) )));
		return hs.__get(0);
	}
	
	
	public   void Traverse(haxe.lang.Function p_callback)
	{
		this.TraverseStep(this, 0, p_callback);
	}
	
	
	public   void TraverseStep(haxor.component.Transform p_child, int p_depth, haxe.lang.Function p_callback)
	{
		if (haxe.lang.Runtime.toBool(p_callback.__hx_invoke2_o(0.0, p_child, ((double) (p_depth) ), haxe.lang.Runtime.undefined))) 
		{
			int _g1 = 0;
			int _g = p_child.m_hierarchy.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.TraverseStep(p_child.GetChild(i), ( p_depth + 1 ), p_callback);
			}
			
		}
		
	}
	
	
	@Override public   void OnDestroy()
	{
		int v = this.__cid;
		haxor.context.EngineContext.transform.tid.m_cache.push(v);
		int __temp_expr676 = v;
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_use_local, java.lang.Object p_places)
	{
		int __temp_p_places46 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		boolean __temp_p_use_local45 = ( (( p_use_local == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_use_local)) );
		haxor.math.Vector3 p = null;
		if (__temp_p_use_local45) 
		{
			p = this.get_localPosition();
		}
		 else 
		{
			p = this.get_position();
		}
		
		haxor.math.Vector3 e = null;
		if (__temp_p_use_local45) 
		{
			e = this.get_localEuler();
		}
		 else 
		{
			e = this.get_euler();
		}
		
		haxor.math.Vector3 s = null;
		if (__temp_p_use_local45) 
		{
			s = this.get_localScale();
		}
		 else 
		{
			s = this.get_scale();
		}
		
		return ( ( ( ( ( ( this.get_name() + " " ) + p.ToString(__temp_p_places46) ) + "" ) + e.ToString(__temp_p_places46) ) + "" ) + s.ToString(__temp_p_places46) );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef677 = true;
			switch (field.hashCode())
			{
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef677 = false;
						this.childCount = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef677) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef678 = true;
			switch (field.hashCode())
			{
				case -1967937309:
				{
					if (field.equals("m_hierarchy")) 
					{
						__temp_executeDef678 = false;
						this.m_hierarchy = ((haxe.root.Array<haxor.component.Transform>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 781934538:
				{
					if (field.equals("m_right")) 
					{
						__temp_executeDef678 = false;
						this.m_right = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1575277122:
				{
					if (field.equals("m_wsrs_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_wsrs_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3342253:
				{
					if (field.equals("m_up")) 
					{
						__temp_executeDef678 = false;
						this.m_up = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1864420245:
				{
					if (field.equals("m_wsp_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_wsp_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -2057929485:
				{
					if (field.equals("m_forward")) 
					{
						__temp_executeDef678 = false;
						this.m_forward = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1869991345:
				{
					if (field.equals("m_inverse_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_inverse_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef678 = false;
						this.set_parent(((haxor.component.Transform) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 769016192:
				{
					if (field.equals("m_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1594154820:
				{
					if (field.equals("m_parent")) 
					{
						__temp_executeDef678 = false;
						this.m_parent = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -2067146443:
				{
					if (field.equals("m_uniform_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_uniform_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef678 = false;
						this.childCount = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1696750567:
				{
					if (field.equals("m_lmrs_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_lmrs_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -690077260:
				{
					if (field.equals("localPosition")) 
					{
						__temp_executeDef678 = false;
						this.set_localPosition(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 1954670164:
				{
					if (field.equals("m_lmt_dirty")) 
					{
						__temp_executeDef678 = false;
						this.m_lmt_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -359116446:
				{
					if (field.equals("m_localPosition")) 
					{
						__temp_executeDef678 = false;
						this.m_localPosition = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1310324166:
				{
					if (field.equals("m_localMatrix")) 
					{
						__temp_executeDef678 = false;
						this.m_localMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1478182903:
				{
					if (field.equals("localRotation")) 
					{
						__temp_executeDef678 = false;
						this.set_localRotation(((haxor.math.Quaternion) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 595152591:
				{
					if (field.equals("m_worldMatrixInverse")) 
					{
						__temp_executeDef678 = false;
						this.m_worldMatrixInverse = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1147222089:
				{
					if (field.equals("m_localRotation")) 
					{
						__temp_executeDef678 = false;
						this.m_localRotation = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1757983455:
				{
					if (field.equals("m_worldMatrix")) 
					{
						__temp_executeDef678 = false;
						this.m_worldMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1279734462:
				{
					if (field.equals("localEuler")) 
					{
						__temp_executeDef678 = false;
						this.set_localEuler(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 782673656:
				{
					if (field.equals("m_scale")) 
					{
						__temp_executeDef678 = false;
						this.m_scale = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1292117151:
				{
					if (field.equals("localScale")) 
					{
						__temp_executeDef678 = false;
						this.set_localScale(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef678 = false;
						this.set_euler(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -729422927:
				{
					if (field.equals("m_localScale")) 
					{
						__temp_executeDef678 = false;
						this.m_localScale = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 105081616:
				{
					if (field.equals("m_rotation")) 
					{
						__temp_executeDef678 = false;
						this.m_rotation = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef678 = false;
						this.set_position(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef678 = false;
						this.set_rotation(((haxor.math.Quaternion) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 893187259:
				{
					if (field.equals("m_position")) 
					{
						__temp_executeDef678 = false;
						this.m_position = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef678) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef679 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 108511772:
				{
					if (field.equals("right")) 
					{
						__temp_executeDef679 = false;
						return this.get_right();
					}
					
					break;
				}
				
				
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 1145461747:
				{
					if (field.equals("get_right")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_right"))) );
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseStep"))) );
					}
					
					break;
				}
				
				
				case 930844671:
				{
					if (field.equals("set_right")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_right"))) );
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Traverse"))) );
					}
					
					break;
				}
				
				
				case 781934538:
				{
					if (field.equals("m_right")) 
					{
						__temp_executeDef679 = false;
						return this.m_right;
					}
					
					break;
				}
				
				
				case 427549204:
				{
					if (field.equals("OutputHierarchy")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OutputHierarchy"))) );
					}
					
					break;
				}
				
				
				case 3739:
				{
					if (field.equals("up")) 
					{
						__temp_executeDef679 = false;
						return this.get_up();
					}
					
					break;
				}
				
				
				case 1360664152:
				{
					if (field.equals("GetPathToRoot")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetPathToRoot"))) );
					}
					
					break;
				}
				
				
				case -1249338332:
				{
					if (field.equals("get_up")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_up"))) );
					}
					
					break;
				}
				
				
				case -1822469688:
				{
					if (field.equals("Search")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Search"))) );
					}
					
					break;
				}
				
				
				case -905788520:
				{
					if (field.equals("set_up")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_up"))) );
					}
					
					break;
				}
				
				
				case -2127828591:
				{
					if (field.equals("Navigate")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Navigate"))) );
					}
					
					break;
				}
				
				
				case 3342253:
				{
					if (field.equals("m_up")) 
					{
						__temp_executeDef679 = false;
						return this.m_up;
					}
					
					break;
				}
				
				
				case 886154920:
				{
					if (field.equals("GetChildByName")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetChildByName"))) );
					}
					
					break;
				}
				
				
				case -677145915:
				{
					if (field.equals("forward")) 
					{
						__temp_executeDef679 = false;
						return this.get_forward();
					}
					
					break;
				}
				
				
				case 2015100806:
				{
					if (field.equals("GetChild")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetChild"))) );
					}
					
					break;
				}
				
				
				case -600632612:
				{
					if (field.equals("get_forward")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_forward"))) );
					}
					
					break;
				}
				
				
				case -2013229230:
				{
					if (field.equals("LookAt")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LookAt"))) );
					}
					
					break;
				}
				
				
				case -689212440:
				{
					if (field.equals("set_forward")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_forward"))) );
					}
					
					break;
				}
				
				
				case 161615195:
				{
					if (field.equals("Invalidate")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Invalidate"))) );
					}
					
					break;
				}
				
				
				case -2057929485:
				{
					if (field.equals("m_forward")) 
					{
						__temp_executeDef679 = false;
						return this.m_forward;
					}
					
					break;
				}
				
				
				case -715738806:
				{
					if (field.equals("UpdateWorldMatrix")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateWorldMatrix"))) );
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef679 = false;
						return this.get_parent();
					}
					
					break;
				}
				
				
				case 1697601158:
				{
					if (field.equals("UpdateWSRS")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateWSRS"))) );
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_parent"))) );
					}
					
					break;
				}
				
				
				case 1697267691:
				{
					if (field.equals("UpdateLMRS")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateLMRS"))) );
					}
					
					break;
				}
				
				
				case -1272907993:
				{
					if (field.equals("set_parent")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_parent"))) );
					}
					
					break;
				}
				
				
				case 54761323:
				{
					if (field.equals("UpdateWSP")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateWSP"))) );
					}
					
					break;
				}
				
				
				case -1594154820:
				{
					if (field.equals("m_parent")) 
					{
						__temp_executeDef679 = false;
						return this.m_parent;
					}
					
					break;
				}
				
				
				case 54750570:
				{
					if (field.equals("UpdateLMT")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateLMT"))) );
					}
					
					break;
				}
				
				
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef679 = false;
						if (handleProperties) 
						{
							return this.get_childCount();
						}
						 else 
						{
							return this.childCount;
						}
						
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case 109326812:
				{
					if (field.equals("get_childCount")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_childCount"))) );
					}
					
					break;
				}
				
				
				case -1967937309:
				{
					if (field.equals("m_hierarchy")) 
					{
						__temp_executeDef679 = false;
						return this.m_hierarchy;
					}
					
					break;
				}
				
				
				case -690077260:
				{
					if (field.equals("localPosition")) 
					{
						__temp_executeDef679 = false;
						return this.get_localPosition();
					}
					
					break;
				}
				
				
				case 1575277122:
				{
					if (field.equals("m_wsrs_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_wsrs_dirty;
					}
					
					break;
				}
				
				
				case -763554677:
				{
					if (field.equals("get_localPosition")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localPosition"))) );
					}
					
					break;
				}
				
				
				case 1864420245:
				{
					if (field.equals("m_wsp_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_wsp_dirty;
					}
					
					break;
				}
				
				
				case -1703707497:
				{
					if (field.equals("set_localPosition")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localPosition"))) );
					}
					
					break;
				}
				
				
				case 1869991345:
				{
					if (field.equals("m_inverse_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_inverse_dirty;
					}
					
					break;
				}
				
				
				case -359116446:
				{
					if (field.equals("m_localPosition")) 
					{
						__temp_executeDef679 = false;
						return this.m_localPosition;
					}
					
					break;
				}
				
				
				case 769016192:
				{
					if (field.equals("m_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_dirty;
					}
					
					break;
				}
				
				
				case -1478182903:
				{
					if (field.equals("localRotation")) 
					{
						__temp_executeDef679 = false;
						return this.get_localRotation();
					}
					
					break;
				}
				
				
				case -2067146443:
				{
					if (field.equals("m_uniform_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_uniform_dirty;
					}
					
					break;
				}
				
				
				case -1551660320:
				{
					if (field.equals("get_localRotation")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localRotation"))) );
					}
					
					break;
				}
				
				
				case 1696750567:
				{
					if (field.equals("m_lmrs_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_lmrs_dirty;
					}
					
					break;
				}
				
				
				case 1803154156:
				{
					if (field.equals("set_localRotation")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localRotation"))) );
					}
					
					break;
				}
				
				
				case 1954670164:
				{
					if (field.equals("m_lmt_dirty")) 
					{
						__temp_executeDef679 = false;
						return this.m_lmt_dirty;
					}
					
					break;
				}
				
				
				case -1147222089:
				{
					if (field.equals("m_localRotation")) 
					{
						__temp_executeDef679 = false;
						return this.m_localRotation;
					}
					
					break;
				}
				
				
				case -1310324166:
				{
					if (field.equals("m_localMatrix")) 
					{
						__temp_executeDef679 = false;
						return this.m_localMatrix;
					}
					
					break;
				}
				
				
				case 1279734462:
				{
					if (field.equals("localEuler")) 
					{
						__temp_executeDef679 = false;
						return this.get_localEuler();
					}
					
					break;
				}
				
				
				case 595152591:
				{
					if (field.equals("m_worldMatrixInverse")) 
					{
						__temp_executeDef679 = false;
						return this.m_worldMatrixInverse;
					}
					
					break;
				}
				
				
				case 59909959:
				{
					if (field.equals("get_localEuler")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localEuler"))) );
					}
					
					break;
				}
				
				
				case -19867290:
				{
					if (field.equals("get_WorldMatrixInverse")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_WorldMatrixInverse"))) );
					}
					
					break;
				}
				
				
				case -1711826245:
				{
					if (field.equals("set_localEuler")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localEuler"))) );
					}
					
					break;
				}
				
				
				case -1625653795:
				{
					if (field.equals("WorldMatrixInverse")) 
					{
						__temp_executeDef679 = false;
						return this.get_WorldMatrixInverse();
					}
					
					break;
				}
				
				
				case 1292117151:
				{
					if (field.equals("localScale")) 
					{
						__temp_executeDef679 = false;
						return this.get_localScale();
					}
					
					break;
				}
				
				
				case -1757983455:
				{
					if (field.equals("m_worldMatrix")) 
					{
						__temp_executeDef679 = false;
						return this.m_worldMatrix;
					}
					
					break;
				}
				
				
				case 72292648:
				{
					if (field.equals("get_localScale")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localScale"))) );
					}
					
					break;
				}
				
				
				case -1006735766:
				{
					if (field.equals("get_WorldMatrix")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_WorldMatrix"))) );
					}
					
					break;
				}
				
				
				case -1699443556:
				{
					if (field.equals("set_localScale")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localScale"))) );
					}
					
					break;
				}
				
				
				case -1846881837:
				{
					if (field.equals("WorldMatrix")) 
					{
						__temp_executeDef679 = false;
						return this.get_WorldMatrix();
					}
					
					break;
				}
				
				
				case -729422927:
				{
					if (field.equals("m_localScale")) 
					{
						__temp_executeDef679 = false;
						return this.m_localScale;
					}
					
					break;
				}
				
				
				case 782673656:
				{
					if (field.equals("m_scale")) 
					{
						__temp_executeDef679 = false;
						return this.m_scale;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef679 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_scale"))) );
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_position"))) );
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef679 = false;
						return this.get_scale();
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_position"))) );
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_euler"))) );
					}
					
					break;
				}
				
				
				case 893187259:
				{
					if (field.equals("m_position")) 
					{
						__temp_executeDef679 = false;
						return this.m_position;
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_euler"))) );
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef679 = false;
						return this.get_rotation();
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef679 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rotation"))) );
					}
					
					break;
				}
				
				
				case 105081616:
				{
					if (field.equals("m_rotation")) 
					{
						__temp_executeDef679 = false;
						return this.m_rotation;
					}
					
					break;
				}
				
				
				case -414362949:
				{
					if (field.equals("set_rotation")) 
					{
						__temp_executeDef679 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rotation"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef679) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef680 = true;
			switch (field.hashCode())
			{
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef680 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_childCount()) );
						}
						 else 
						{
							return ((double) (this.childCount) );
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef680) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			int __temp_hash682 = field.hashCode();
			boolean __temp_executeDef681 = true;
			switch (__temp_hash682)
			{
				case 602652923:case 312095663:
				{
					if (( (( ( __temp_hash682 == 602652923 ) && field.equals("OnDestroy") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef681 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1145461747:
				{
					if (field.equals("get_right")) 
					{
						__temp_executeDef681 = false;
						return this.get_right();
					}
					
					break;
				}
				
				
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef681 = false;
						return this.ToString(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 930844671:
				{
					if (field.equals("set_right")) 
					{
						__temp_executeDef681 = false;
						return this.set_right(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef681 = false;
						this.TraverseStep(((haxor.component.Transform) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.lang.Function) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -1249338332:
				{
					if (field.equals("get_up")) 
					{
						__temp_executeDef681 = false;
						return this.get_up();
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef681 = false;
						this.Traverse(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -905788520:
				{
					if (field.equals("set_up")) 
					{
						__temp_executeDef681 = false;
						return this.set_up(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 427549204:
				{
					if (field.equals("OutputHierarchy")) 
					{
						__temp_executeDef681 = false;
						return this.OutputHierarchy(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -600632612:
				{
					if (field.equals("get_forward")) 
					{
						__temp_executeDef681 = false;
						return this.get_forward();
					}
					
					break;
				}
				
				
				case 1360664152:
				{
					if (field.equals("GetPathToRoot")) 
					{
						__temp_executeDef681 = false;
						return this.GetPathToRoot();
					}
					
					break;
				}
				
				
				case -689212440:
				{
					if (field.equals("set_forward")) 
					{
						__temp_executeDef681 = false;
						return this.set_forward(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1822469688:
				{
					if (field.equals("Search")) 
					{
						__temp_executeDef681 = false;
						return this.Search(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef681 = false;
						return this.get_parent();
					}
					
					break;
				}
				
				
				case -2127828591:
				{
					if (field.equals("Navigate")) 
					{
						__temp_executeDef681 = false;
						return this.Navigate(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1272907993:
				{
					if (field.equals("set_parent")) 
					{
						__temp_executeDef681 = false;
						return this.set_parent(((haxor.component.Transform) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 886154920:
				{
					if (field.equals("GetChildByName")) 
					{
						__temp_executeDef681 = false;
						return this.GetChildByName(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 109326812:
				{
					if (field.equals("get_childCount")) 
					{
						__temp_executeDef681 = false;
						return this.get_childCount();
					}
					
					break;
				}
				
				
				case 2015100806:
				{
					if (field.equals("GetChild")) 
					{
						__temp_executeDef681 = false;
						return this.GetChild(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -763554677:
				{
					if (field.equals("get_localPosition")) 
					{
						__temp_executeDef681 = false;
						return this.get_localPosition();
					}
					
					break;
				}
				
				
				case -2013229230:
				{
					if (field.equals("LookAt")) 
					{
						__temp_executeDef681 = false;
						this.LookAt(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case -1703707497:
				{
					if (field.equals("set_localPosition")) 
					{
						__temp_executeDef681 = false;
						return this.set_localPosition(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 161615195:
				{
					if (field.equals("Invalidate")) 
					{
						__temp_executeDef681 = false;
						this.Invalidate();
					}
					
					break;
				}
				
				
				case -1551660320:
				{
					if (field.equals("get_localRotation")) 
					{
						__temp_executeDef681 = false;
						return this.get_localRotation();
					}
					
					break;
				}
				
				
				case -715738806:
				{
					if (field.equals("UpdateWorldMatrix")) 
					{
						__temp_executeDef681 = false;
						this.UpdateWorldMatrix();
					}
					
					break;
				}
				
				
				case 1803154156:
				{
					if (field.equals("set_localRotation")) 
					{
						__temp_executeDef681 = false;
						return this.set_localRotation(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1697601158:
				{
					if (field.equals("UpdateWSRS")) 
					{
						__temp_executeDef681 = false;
						this.UpdateWSRS();
					}
					
					break;
				}
				
				
				case 59909959:
				{
					if (field.equals("get_localEuler")) 
					{
						__temp_executeDef681 = false;
						return this.get_localEuler();
					}
					
					break;
				}
				
				
				case 1697267691:
				{
					if (field.equals("UpdateLMRS")) 
					{
						__temp_executeDef681 = false;
						this.UpdateLMRS();
					}
					
					break;
				}
				
				
				case -1711826245:
				{
					if (field.equals("set_localEuler")) 
					{
						__temp_executeDef681 = false;
						return this.set_localEuler(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 54761323:
				{
					if (field.equals("UpdateWSP")) 
					{
						__temp_executeDef681 = false;
						this.UpdateWSP();
					}
					
					break;
				}
				
				
				case 72292648:
				{
					if (field.equals("get_localScale")) 
					{
						__temp_executeDef681 = false;
						return this.get_localScale();
					}
					
					break;
				}
				
				
				case 54750570:
				{
					if (field.equals("UpdateLMT")) 
					{
						__temp_executeDef681 = false;
						this.UpdateLMT();
					}
					
					break;
				}
				
				
				case -1699443556:
				{
					if (field.equals("set_localScale")) 
					{
						__temp_executeDef681 = false;
						return this.set_localScale(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -19867290:
				{
					if (field.equals("get_WorldMatrixInverse")) 
					{
						__temp_executeDef681 = false;
						return this.get_WorldMatrixInverse();
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef681 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case -1006735766:
				{
					if (field.equals("get_WorldMatrix")) 
					{
						__temp_executeDef681 = false;
						return this.get_WorldMatrix();
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef681 = false;
						return this.set_position(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef681 = false;
						return this.get_scale();
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef681 = false;
						return this.get_rotation();
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef681 = false;
						return this.set_euler(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -414362949:
				{
					if (field.equals("set_rotation")) 
					{
						__temp_executeDef681 = false;
						return this.set_rotation(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef681 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef681) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_hierarchy");
		baseArr.push("m_wsrs_dirty");
		baseArr.push("m_wsp_dirty");
		baseArr.push("m_inverse_dirty");
		baseArr.push("m_dirty");
		baseArr.push("m_uniform_dirty");
		baseArr.push("m_lmrs_dirty");
		baseArr.push("m_lmt_dirty");
		baseArr.push("m_localMatrix");
		baseArr.push("m_worldMatrixInverse");
		baseArr.push("WorldMatrixInverse");
		baseArr.push("m_worldMatrix");
		baseArr.push("WorldMatrix");
		baseArr.push("m_scale");
		baseArr.push("scale");
		baseArr.push("euler");
		baseArr.push("m_rotation");
		baseArr.push("rotation");
		baseArr.push("m_position");
		baseArr.push("position");
		baseArr.push("m_localScale");
		baseArr.push("localScale");
		baseArr.push("localEuler");
		baseArr.push("m_localRotation");
		baseArr.push("localRotation");
		baseArr.push("m_localPosition");
		baseArr.push("localPosition");
		baseArr.push("childCount");
		baseArr.push("m_parent");
		baseArr.push("parent");
		baseArr.push("m_forward");
		baseArr.push("forward");
		baseArr.push("m_up");
		baseArr.push("up");
		baseArr.push("m_right");
		baseArr.push("right");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


