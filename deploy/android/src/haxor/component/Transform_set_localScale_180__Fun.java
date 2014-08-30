package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Transform_set_localScale_180__Fun extends haxe.lang.Function
{
	public    Transform_set_localScale_180__Fun(haxe.root.Array<haxor.component.Transform> _g, haxe.root.Array<haxor.math.Vector3> ps)
	{
		super(2, 0);
		this._g = _g;
		this.ps = ps;
	}
	
	
	@Override public   java.lang.Object __hx_invoke2_o(double __fn_float1, java.lang.Object __fn_dyn1, double __fn_float2, java.lang.Object __fn_dyn2)
	{
		int d = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float2) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn2)) )) );
		haxor.component.Transform t = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.component.Transform) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.component.Transform) (__fn_dyn1) )) );
		if (( t == this._g.__get(0) )) 
		{
			return true;
		}
		
		haxor.math.Vector3 pp = null;
		if (( t.m_parent == null )) 
		{
			haxor.math.Vector3 __temp_stmt152005 = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				__temp_stmt152005 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
			}
			
			pp = __temp_stmt152005.Set(0, 0, 0);
		}
		 else 
		{
			pp = t.m_parent.m_position;
		}
		
		if (( t.m_parent == null )) 
		{
			haxor.math.Vector3 __temp_stmt152006 = null;
			{
				haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
				__temp_stmt152006 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
			}
			
			this.ps.__set(0, __temp_stmt152006.Set(1, 1, 1));
		}
		 else 
		{
			this.ps.__set(0, t.m_parent.m_scale);
		}
		
		t.m_scale.x = ( t.m_localScale.x * this.ps.__get(0).x );
		t.m_scale.y = ( t.m_localScale.y * this.ps.__get(0).y );
		t.m_scale.z = ( t.m_localScale.z * this.ps.__get(0).z );
		haxor.math.Vector3 __temp_stmt152008 = null;
		{
			haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
			__temp_stmt152008 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt152007 = __temp_stmt152008.Set3(t.m_position);
		haxor.math.Vector3 v1 = __temp_stmt152007.Sub(pp);
		v1.Multiply(this.ps.__get(0));
		v1.Add(pp);
		t.set_position(v1);
		t.m_dirty = true;
		haxor.context.EngineContext.transform.OnChange(t);
		return true;
	}
	
	
	public  haxe.root.Array<haxor.component.Transform> _g;
	
	public  haxe.root.Array<haxor.math.Vector3> ps;
	
}


