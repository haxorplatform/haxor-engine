package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AxisGizmo extends haxor.context.Gizmo
{
	public    AxisGizmo(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    AxisGizmo()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.context.AxisGizmo.__hx_ctor_haxor_context_AxisGizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_AxisGizmo(haxor.context.AxisGizmo __temp_me145)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(__temp_me145, haxor.context.Gizmo.AXIS, haxor.context.Gizmo.MAX_GIZMOS);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.AxisGizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.AxisGizmo();
	}
	
	
	@Override public   void OnBuild()
	{
		haxor.graphics.mesh.Mesh3 m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		m.set_name("$GizmoAxisMesh");
		m.primitive = 1;
		haxor.math.Color cr = new haxor.math.Color(((java.lang.Object) (0.9) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (1) ));
		haxor.math.Color cg = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (1) ));
		haxor.math.Color cb = new haxor.math.Color(((java.lang.Object) (0.3) ), ((java.lang.Object) (0.3) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (1) ));
		double id = 0.0;
		haxor.io.FloatArray ia = new haxor.io.FloatArray(((int) (( this.m_gizmo_count * 6 )) ));
		haxor.io.FloatArray va = new haxor.io.FloatArray(((int) (( ( this.m_gizmo_count * 6 ) * 3 )) ));
		haxor.io.FloatArray ca = new haxor.io.FloatArray(((int) (( ( this.m_gizmo_count * 6 ) * 3 )) ));
		int va_k = 0;
		int ca_k = 0;
		int ia_k = 0;
		{
			int _g1 = 0;
			int _g = this.m_gizmo_count;
			while (( _g1 < _g ))
			{
				int k = _g1++;
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				ia.Set(ia_k++, id);
				va.Set(va_k++, 1.0);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				ia.Set(ia_k++, id);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				ia.Set(ia_k++, id);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 1.0);
				va.Set(va_k++, 0.0);
				ia.Set(ia_k++, id);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				ia.Set(ia_k++, id);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 0.0);
				va.Set(va_k++, 1.0);
				ia.Set(ia_k++, id);
				haxor.math.Color c = null;
				c = cr;
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				c = cg;
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				c = cb;
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				ca.Set(ca_k++, c.r);
				ca.Set(ca_k++, c.g);
				ca.Set(ca_k++, c.b);
				ca.Set(ca_k++, c.a);
				id += 1.0;
			}
			
		}
		
		m.Set("id", ia, 1);
		m.Set("vertex", va, 3);
		m.Set("color", ca, 4);
		this.mesh = m;
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef849 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef849 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef849) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
}


