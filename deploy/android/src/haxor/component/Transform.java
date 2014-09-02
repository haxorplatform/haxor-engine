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
	
	
	public static   void __hx_ctor_haxor_component_Transform(haxor.component.Transform __temp_me160442, java.lang.String p_name)
	{
		haxor.component.Component.__hx_ctor_haxor_component_Component(__temp_me160442, p_name);
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
	
	
	
	
	public   haxor.math.Vector3 get_euler()
	{
		return this.get_rotation().get_euler();
	}
	
	
	public   haxor.math.Vector3 set_euler(haxor.math.Vector3 v)
	{
		haxor.math.Quaternion __temp_stmt161100 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt161100 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		this.set_rotation(haxor.math.Quaternion.FromEuler(v, __temp_stmt161100));
		return v;
	}
	
	
	
	
	public   haxor.math.Vector3 get_localEuler()
	{
		return this.m_localRotation.get_euler();
	}
	
	
	public   haxor.math.Vector3 set_localEuler(haxor.math.Vector3 v)
	{
		haxor.math.Quaternion __temp_stmt161101 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt161101 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		this.set_localRotation(haxor.math.Quaternion.FromEuler(v, __temp_stmt161101));
		return v;
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
		this.UpdateWorldMatrix();
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
		this.UpdateWorldMatrix();
		return v;
	}
	
	
	public  haxor.math.Quaternion m_localRotation;
	
	
	
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
		this.UpdateWorldMatrix();
		return v;
	}
	
	
	public  haxor.math.Vector3 m_localScale;
	
	
	
	public   haxor.math.Vector3 get_position()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
	}
	
	
	public   haxor.math.Vector3 set_position(haxor.math.Vector3 v)
	{
		return v;
	}
	
	
	
	
	public   haxor.math.Quaternion get_rotation()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
	}
	
	
	public   haxor.math.Quaternion set_rotation(haxor.math.Quaternion v)
	{
		return v;
	}
	
	
	
	
	public   haxor.math.Vector3 get_scale()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
	}
	
	
	
	
	public   haxor.math.Matrix4 get_WorldMatrix()
	{
		this.UpdateWorldMatrix();
		return this.m_worldMatrix;
	}
	
	
	public  haxor.math.Matrix4 m_worldMatrix;
	
	
	
	public   haxor.math.Matrix4 get_WorldMatrixInverse()
	{
		this.UpdateWorldMatrix();
		return this.m_worldMatrixInverse;
	}
	
	
	public  haxor.math.Matrix4 m_worldMatrixInverse;
	
	public  haxor.math.Matrix4 m_localMatrix;
	
	public  boolean m_lmt_dirty;
	
	public  boolean m_lmrs_dirty;
	
	public  boolean m_uniform_dirty;
	
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
		this.m_lmt_dirty = false;
		this.m_lmrs_dirty = false;
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
	
	
	public   void UpdateLMRS()
	{
		double sx = this.m_localScale.x;
		double sy = this.m_localScale.y;
		double sz = this.m_localScale.z;
		haxor.math.Matrix4 __temp_stmt161102 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt161102 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4 r = haxor.math.Matrix4.FromQuaternion(this.m_localRotation, __temp_stmt161102);
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
	
	
	public   void UpdateWorldMatrix()
	{
		if (this.m_lmt_dirty) 
		{
			this.UpdateLMT();
			this.m_lmt_dirty = false;
		}
		
		if (this.m_lmrs_dirty) 
		{
			this.UpdateLMRS();
			this.m_lmrs_dirty = false;
		}
		
		if (( this.m_parent != null )) 
		{
			this.m_uniform_dirty = true;
			haxor.math.Matrix4 v = this.m_parent.m_worldMatrix;
			haxor.math.Matrix4 m = this.m_worldMatrix;
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
			m.MultiplyTransform(this.m_localMatrix);
			this.m_right.Set(m.m00, m.m10, m.m20);
			this.m_right.Normalize();
			this.m_up.Set(m.m01, m.m11, m.m21);
			this.m_up.Normalize();
			this.m_forward.Set(m.m02, m.m12, m.m22);
			this.m_forward.Normalize();
			haxor.math.Matrix4.GetInverseTransform(this.m_worldMatrix, this.m_worldMatrixInverse);
			haxor.context.EngineContext.transform.OnChange(this);
		}
		
		{
			int _g1 = 0;
			int _g = this.m_hierarchy.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_hierarchy.__get(i).UpdateWorldMatrix();
			}
			
		}
		
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
	
	
	public   void Lock()
	{
		{
		}
		
	}
	
	
	public   void Unlock()
	{
		{
		}
		
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
		boolean __temp_p_exact160439 = ( (( p_exact == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_exact)) );
		haxe.root.Array<java.lang.Object> p_exact1 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_p_exact160439});
		haxe.root.Array<java.lang.String> p_name1 = new haxe.root.Array<java.lang.String>(new java.lang.String[]{p_name});
		haxe.root.Array<haxor.component.Transform> _g = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{this});
		haxe.root.Array<haxor.component.Transform> res = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{null});
		this.Traverse(new haxor.component.Transform_Search_329__Fun(((haxe.root.Array<java.lang.String>) (p_name1) ), ((haxe.root.Array<haxor.component.Transform>) (res) ), ((haxe.root.Array<haxor.component.Transform>) (_g) ), ((haxe.root.Array<java.lang.Object>) (p_exact1) )));
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
	
	
	public   java.lang.String OutputHierarchy()
	{
		haxe.root.Array<java.lang.Object> d0 = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.String> hs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{""});
		this.Traverse(new haxor.component.Transform_OutputHierarchy_371__Fun(((haxe.root.Array<java.lang.String>) (hs) ), ((haxe.root.Array<java.lang.Object>) (d0) )));
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
		int __temp_expr161103 = v;
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_use_local, java.lang.Object p_places)
	{
		int __temp_p_places160441 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		boolean __temp_p_use_local160440 = ( (( p_use_local == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_use_local)) );
		haxor.math.Vector3 p = null;
		if (__temp_p_use_local160440) 
		{
			p = this.get_localPosition();
		}
		 else 
		{
			p = this.get_position();
		}
		
		haxor.math.Vector3 e = null;
		if (__temp_p_use_local160440) 
		{
			e = this.get_localEuler();
		}
		 else 
		{
			e = this.get_euler();
		}
		
		haxor.math.Vector3 s = null;
		if (__temp_p_use_local160440) 
		{
			s = this.get_localScale();
		}
		 else 
		{
			s = this.get_scale();
		}
		
		return ( ( ( ( ( ( this.get_name() + " " ) + p.ToString(__temp_p_places160441) ) + "" ) + e.ToString(__temp_p_places160441) ) + "" ) + s.ToString(__temp_p_places160441) );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161104 = true;
			switch (field.hashCode())
			{
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef161104 = false;
						this.childCount = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161104) 
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
			boolean __temp_executeDef161105 = true;
			switch (field.hashCode())
			{
				case -1967937309:
				{
					if (field.equals("m_hierarchy")) 
					{
						__temp_executeDef161105 = false;
						this.m_hierarchy = ((haxe.root.Array<haxor.component.Transform>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 781934538:
				{
					if (field.equals("m_right")) 
					{
						__temp_executeDef161105 = false;
						this.m_right = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -2067146443:
				{
					if (field.equals("m_uniform_dirty")) 
					{
						__temp_executeDef161105 = false;
						this.m_uniform_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3342253:
				{
					if (field.equals("m_up")) 
					{
						__temp_executeDef161105 = false;
						this.m_up = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1696750567:
				{
					if (field.equals("m_lmrs_dirty")) 
					{
						__temp_executeDef161105 = false;
						this.m_lmrs_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -2057929485:
				{
					if (field.equals("m_forward")) 
					{
						__temp_executeDef161105 = false;
						this.m_forward = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1954670164:
				{
					if (field.equals("m_lmt_dirty")) 
					{
						__temp_executeDef161105 = false;
						this.m_lmt_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef161105 = false;
						this.set_parent(((haxor.component.Transform) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1310324166:
				{
					if (field.equals("m_localMatrix")) 
					{
						__temp_executeDef161105 = false;
						this.m_localMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1594154820:
				{
					if (field.equals("m_parent")) 
					{
						__temp_executeDef161105 = false;
						this.m_parent = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 595152591:
				{
					if (field.equals("m_worldMatrixInverse")) 
					{
						__temp_executeDef161105 = false;
						this.m_worldMatrixInverse = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef161105 = false;
						this.childCount = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1757983455:
				{
					if (field.equals("m_worldMatrix")) 
					{
						__temp_executeDef161105 = false;
						this.m_worldMatrix = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef161105 = false;
						this.set_euler(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef161105 = false;
						this.set_rotation(((haxor.math.Quaternion) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 1279734462:
				{
					if (field.equals("localEuler")) 
					{
						__temp_executeDef161105 = false;
						this.set_localEuler(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef161105 = false;
						this.set_position(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -690077260:
				{
					if (field.equals("localPosition")) 
					{
						__temp_executeDef161105 = false;
						this.set_localPosition(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -729422927:
				{
					if (field.equals("m_localScale")) 
					{
						__temp_executeDef161105 = false;
						this.m_localScale = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -359116446:
				{
					if (field.equals("m_localPosition")) 
					{
						__temp_executeDef161105 = false;
						this.m_localPosition = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1292117151:
				{
					if (field.equals("localScale")) 
					{
						__temp_executeDef161105 = false;
						this.set_localScale(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1478182903:
				{
					if (field.equals("localRotation")) 
					{
						__temp_executeDef161105 = false;
						this.set_localRotation(((haxor.math.Quaternion) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1147222089:
				{
					if (field.equals("m_localRotation")) 
					{
						__temp_executeDef161105 = false;
						this.m_localRotation = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161105) 
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
			boolean __temp_executeDef161106 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 108511772:
				{
					if (field.equals("right")) 
					{
						__temp_executeDef161106 = false;
						return this.get_right();
					}
					
					break;
				}
				
				
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 1145461747:
				{
					if (field.equals("get_right")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_right"))) );
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseStep"))) );
					}
					
					break;
				}
				
				
				case 930844671:
				{
					if (field.equals("set_right")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_right"))) );
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Traverse"))) );
					}
					
					break;
				}
				
				
				case 781934538:
				{
					if (field.equals("m_right")) 
					{
						__temp_executeDef161106 = false;
						return this.m_right;
					}
					
					break;
				}
				
				
				case 427549204:
				{
					if (field.equals("OutputHierarchy")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OutputHierarchy"))) );
					}
					
					break;
				}
				
				
				case 3739:
				{
					if (field.equals("up")) 
					{
						__temp_executeDef161106 = false;
						return this.get_up();
					}
					
					break;
				}
				
				
				case 1360664152:
				{
					if (field.equals("GetPathToRoot")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetPathToRoot"))) );
					}
					
					break;
				}
				
				
				case -1249338332:
				{
					if (field.equals("get_up")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_up"))) );
					}
					
					break;
				}
				
				
				case -1822469688:
				{
					if (field.equals("Search")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Search"))) );
					}
					
					break;
				}
				
				
				case -905788520:
				{
					if (field.equals("set_up")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_up"))) );
					}
					
					break;
				}
				
				
				case -2127828591:
				{
					if (field.equals("Navigate")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Navigate"))) );
					}
					
					break;
				}
				
				
				case 3342253:
				{
					if (field.equals("m_up")) 
					{
						__temp_executeDef161106 = false;
						return this.m_up;
					}
					
					break;
				}
				
				
				case -1756574876:
				{
					if (field.equals("Unlock")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unlock"))) );
					}
					
					break;
				}
				
				
				case -677145915:
				{
					if (field.equals("forward")) 
					{
						__temp_executeDef161106 = false;
						return this.get_forward();
					}
					
					break;
				}
				
				
				case 2373963:
				{
					if (field.equals("Lock")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Lock"))) );
					}
					
					break;
				}
				
				
				case -600632612:
				{
					if (field.equals("get_forward")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_forward"))) );
					}
					
					break;
				}
				
				
				case 886154920:
				{
					if (field.equals("GetChildByName")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetChildByName"))) );
					}
					
					break;
				}
				
				
				case -689212440:
				{
					if (field.equals("set_forward")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_forward"))) );
					}
					
					break;
				}
				
				
				case 2015100806:
				{
					if (field.equals("GetChild")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetChild"))) );
					}
					
					break;
				}
				
				
				case -2057929485:
				{
					if (field.equals("m_forward")) 
					{
						__temp_executeDef161106 = false;
						return this.m_forward;
					}
					
					break;
				}
				
				
				case -715738806:
				{
					if (field.equals("UpdateWorldMatrix")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateWorldMatrix"))) );
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef161106 = false;
						return this.get_parent();
					}
					
					break;
				}
				
				
				case 1697267691:
				{
					if (field.equals("UpdateLMRS")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateLMRS"))) );
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_parent"))) );
					}
					
					break;
				}
				
				
				case 54750570:
				{
					if (field.equals("UpdateLMT")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateLMT"))) );
					}
					
					break;
				}
				
				
				case -1272907993:
				{
					if (field.equals("set_parent")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_parent"))) );
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1594154820:
				{
					if (field.equals("m_parent")) 
					{
						__temp_executeDef161106 = false;
						return this.m_parent;
					}
					
					break;
				}
				
				
				case -1967937309:
				{
					if (field.equals("m_hierarchy")) 
					{
						__temp_executeDef161106 = false;
						return this.m_hierarchy;
					}
					
					break;
				}
				
				
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef161106 = false;
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
				
				
				case -2067146443:
				{
					if (field.equals("m_uniform_dirty")) 
					{
						__temp_executeDef161106 = false;
						return this.m_uniform_dirty;
					}
					
					break;
				}
				
				
				case 109326812:
				{
					if (field.equals("get_childCount")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_childCount"))) );
					}
					
					break;
				}
				
				
				case 1696750567:
				{
					if (field.equals("m_lmrs_dirty")) 
					{
						__temp_executeDef161106 = false;
						return this.m_lmrs_dirty;
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef161106 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
				case 1954670164:
				{
					if (field.equals("m_lmt_dirty")) 
					{
						__temp_executeDef161106 = false;
						return this.m_lmt_dirty;
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_euler"))) );
					}
					
					break;
				}
				
				
				case -1310324166:
				{
					if (field.equals("m_localMatrix")) 
					{
						__temp_executeDef161106 = false;
						return this.m_localMatrix;
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_euler"))) );
					}
					
					break;
				}
				
				
				case 595152591:
				{
					if (field.equals("m_worldMatrixInverse")) 
					{
						__temp_executeDef161106 = false;
						return this.m_worldMatrixInverse;
					}
					
					break;
				}
				
				
				case 1279734462:
				{
					if (field.equals("localEuler")) 
					{
						__temp_executeDef161106 = false;
						return this.get_localEuler();
					}
					
					break;
				}
				
				
				case -19867290:
				{
					if (field.equals("get_WorldMatrixInverse")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_WorldMatrixInverse"))) );
					}
					
					break;
				}
				
				
				case 59909959:
				{
					if (field.equals("get_localEuler")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localEuler"))) );
					}
					
					break;
				}
				
				
				case -1625653795:
				{
					if (field.equals("WorldMatrixInverse")) 
					{
						__temp_executeDef161106 = false;
						return this.get_WorldMatrixInverse();
					}
					
					break;
				}
				
				
				case -1711826245:
				{
					if (field.equals("set_localEuler")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localEuler"))) );
					}
					
					break;
				}
				
				
				case -1757983455:
				{
					if (field.equals("m_worldMatrix")) 
					{
						__temp_executeDef161106 = false;
						return this.m_worldMatrix;
					}
					
					break;
				}
				
				
				case -690077260:
				{
					if (field.equals("localPosition")) 
					{
						__temp_executeDef161106 = false;
						return this.get_localPosition();
					}
					
					break;
				}
				
				
				case -1006735766:
				{
					if (field.equals("get_WorldMatrix")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_WorldMatrix"))) );
					}
					
					break;
				}
				
				
				case -763554677:
				{
					if (field.equals("get_localPosition")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localPosition"))) );
					}
					
					break;
				}
				
				
				case -1846881837:
				{
					if (field.equals("WorldMatrix")) 
					{
						__temp_executeDef161106 = false;
						return this.get_WorldMatrix();
					}
					
					break;
				}
				
				
				case -1703707497:
				{
					if (field.equals("set_localPosition")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localPosition"))) );
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_scale"))) );
					}
					
					break;
				}
				
				
				case -359116446:
				{
					if (field.equals("m_localPosition")) 
					{
						__temp_executeDef161106 = false;
						return this.m_localPosition;
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef161106 = false;
						return this.get_scale();
					}
					
					break;
				}
				
				
				case -1478182903:
				{
					if (field.equals("localRotation")) 
					{
						__temp_executeDef161106 = false;
						return this.get_localRotation();
					}
					
					break;
				}
				
				
				case -414362949:
				{
					if (field.equals("set_rotation")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rotation"))) );
					}
					
					break;
				}
				
				
				case -1551660320:
				{
					if (field.equals("get_localRotation")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localRotation"))) );
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rotation"))) );
					}
					
					break;
				}
				
				
				case 1803154156:
				{
					if (field.equals("set_localRotation")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localRotation"))) );
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef161106 = false;
						return this.get_rotation();
					}
					
					break;
				}
				
				
				case -1147222089:
				{
					if (field.equals("m_localRotation")) 
					{
						__temp_executeDef161106 = false;
						return this.m_localRotation;
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_position"))) );
					}
					
					break;
				}
				
				
				case 1292117151:
				{
					if (field.equals("localScale")) 
					{
						__temp_executeDef161106 = false;
						return this.get_localScale();
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_position"))) );
					}
					
					break;
				}
				
				
				case 72292648:
				{
					if (field.equals("get_localScale")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_localScale"))) );
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef161106 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case -1699443556:
				{
					if (field.equals("set_localScale")) 
					{
						__temp_executeDef161106 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_localScale"))) );
					}
					
					break;
				}
				
				
				case -729422927:
				{
					if (field.equals("m_localScale")) 
					{
						__temp_executeDef161106 = false;
						return this.m_localScale;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161106) 
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
			boolean __temp_executeDef161107 = true;
			switch (field.hashCode())
			{
				case 1329151315:
				{
					if (field.equals("childCount")) 
					{
						__temp_executeDef161107 = false;
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
			
			if (__temp_executeDef161107) 
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
			int __temp_hash161109 = field.hashCode();
			boolean __temp_executeDef161108 = true;
			switch (__temp_hash161109)
			{
				case 602652923:case 312095663:
				{
					if (( (( ( __temp_hash161109 == 602652923 ) && field.equals("OnDestroy") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef161108 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1145461747:
				{
					if (field.equals("get_right")) 
					{
						__temp_executeDef161108 = false;
						return this.get_right();
					}
					
					break;
				}
				
				
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161108 = false;
						return this.ToString(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 930844671:
				{
					if (field.equals("set_right")) 
					{
						__temp_executeDef161108 = false;
						return this.set_right(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef161108 = false;
						this.TraverseStep(((haxor.component.Transform) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.lang.Function) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -1249338332:
				{
					if (field.equals("get_up")) 
					{
						__temp_executeDef161108 = false;
						return this.get_up();
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef161108 = false;
						this.Traverse(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -905788520:
				{
					if (field.equals("set_up")) 
					{
						__temp_executeDef161108 = false;
						return this.set_up(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 427549204:
				{
					if (field.equals("OutputHierarchy")) 
					{
						__temp_executeDef161108 = false;
						return this.OutputHierarchy();
					}
					
					break;
				}
				
				
				case -600632612:
				{
					if (field.equals("get_forward")) 
					{
						__temp_executeDef161108 = false;
						return this.get_forward();
					}
					
					break;
				}
				
				
				case 1360664152:
				{
					if (field.equals("GetPathToRoot")) 
					{
						__temp_executeDef161108 = false;
						return this.GetPathToRoot();
					}
					
					break;
				}
				
				
				case -689212440:
				{
					if (field.equals("set_forward")) 
					{
						__temp_executeDef161108 = false;
						return this.set_forward(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1822469688:
				{
					if (field.equals("Search")) 
					{
						__temp_executeDef161108 = false;
						return this.Search(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef161108 = false;
						return this.get_parent();
					}
					
					break;
				}
				
				
				case -2127828591:
				{
					if (field.equals("Navigate")) 
					{
						__temp_executeDef161108 = false;
						return this.Navigate(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1272907993:
				{
					if (field.equals("set_parent")) 
					{
						__temp_executeDef161108 = false;
						return this.set_parent(((haxor.component.Transform) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756574876:
				{
					if (field.equals("Unlock")) 
					{
						__temp_executeDef161108 = false;
						this.Unlock();
					}
					
					break;
				}
				
				
				case 109326812:
				{
					if (field.equals("get_childCount")) 
					{
						__temp_executeDef161108 = false;
						return this.get_childCount();
					}
					
					break;
				}
				
				
				case 2373963:
				{
					if (field.equals("Lock")) 
					{
						__temp_executeDef161108 = false;
						this.Lock();
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef161108 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
				case 886154920:
				{
					if (field.equals("GetChildByName")) 
					{
						__temp_executeDef161108 = false;
						return this.GetChildByName(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef161108 = false;
						return this.set_euler(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2015100806:
				{
					if (field.equals("GetChild")) 
					{
						__temp_executeDef161108 = false;
						return this.GetChild(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 59909959:
				{
					if (field.equals("get_localEuler")) 
					{
						__temp_executeDef161108 = false;
						return this.get_localEuler();
					}
					
					break;
				}
				
				
				case -715738806:
				{
					if (field.equals("UpdateWorldMatrix")) 
					{
						__temp_executeDef161108 = false;
						this.UpdateWorldMatrix();
					}
					
					break;
				}
				
				
				case -1711826245:
				{
					if (field.equals("set_localEuler")) 
					{
						__temp_executeDef161108 = false;
						return this.set_localEuler(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1697267691:
				{
					if (field.equals("UpdateLMRS")) 
					{
						__temp_executeDef161108 = false;
						this.UpdateLMRS();
					}
					
					break;
				}
				
				
				case -763554677:
				{
					if (field.equals("get_localPosition")) 
					{
						__temp_executeDef161108 = false;
						return this.get_localPosition();
					}
					
					break;
				}
				
				
				case 54750570:
				{
					if (field.equals("UpdateLMT")) 
					{
						__temp_executeDef161108 = false;
						this.UpdateLMT();
					}
					
					break;
				}
				
				
				case -1703707497:
				{
					if (field.equals("set_localPosition")) 
					{
						__temp_executeDef161108 = false;
						return this.set_localPosition(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -19867290:
				{
					if (field.equals("get_WorldMatrixInverse")) 
					{
						__temp_executeDef161108 = false;
						return this.get_WorldMatrixInverse();
					}
					
					break;
				}
				
				
				case -1551660320:
				{
					if (field.equals("get_localRotation")) 
					{
						__temp_executeDef161108 = false;
						return this.get_localRotation();
					}
					
					break;
				}
				
				
				case -1006735766:
				{
					if (field.equals("get_WorldMatrix")) 
					{
						__temp_executeDef161108 = false;
						return this.get_WorldMatrix();
					}
					
					break;
				}
				
				
				case 1803154156:
				{
					if (field.equals("set_localRotation")) 
					{
						__temp_executeDef161108 = false;
						return this.set_localRotation(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef161108 = false;
						return this.get_scale();
					}
					
					break;
				}
				
				
				case 72292648:
				{
					if (field.equals("get_localScale")) 
					{
						__temp_executeDef161108 = false;
						return this.get_localScale();
					}
					
					break;
				}
				
				
				case -414362949:
				{
					if (field.equals("set_rotation")) 
					{
						__temp_executeDef161108 = false;
						return this.set_rotation(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1699443556:
				{
					if (field.equals("set_localScale")) 
					{
						__temp_executeDef161108 = false;
						return this.set_localScale(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef161108 = false;
						return this.get_rotation();
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef161108 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef161108 = false;
						return this.set_position(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161108) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_hierarchy");
		baseArr.push("m_uniform_dirty");
		baseArr.push("m_lmrs_dirty");
		baseArr.push("m_lmt_dirty");
		baseArr.push("m_localMatrix");
		baseArr.push("m_worldMatrixInverse");
		baseArr.push("WorldMatrixInverse");
		baseArr.push("m_worldMatrix");
		baseArr.push("WorldMatrix");
		baseArr.push("scale");
		baseArr.push("rotation");
		baseArr.push("position");
		baseArr.push("m_localScale");
		baseArr.push("localScale");
		baseArr.push("m_localRotation");
		baseArr.push("localRotation");
		baseArr.push("m_localPosition");
		baseArr.push("localPosition");
		baseArr.push("localEuler");
		baseArr.push("euler");
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


