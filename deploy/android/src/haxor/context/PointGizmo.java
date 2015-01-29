package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class PointGizmo extends haxor.context.Gizmo
{
	public    PointGizmo(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    PointGizmo()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.context.PointGizmo.__hx_ctor_haxor_context_PointGizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_PointGizmo(haxor.context.PointGizmo __temp_me147)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(__temp_me147, haxor.context.Gizmo.POINT, ( haxor.context.Gizmo.MAX_GIZMOS * 5 ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.PointGizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.PointGizmo();
	}
	
	
	@Override public   void OnBuild()
	{
		haxor.graphics.mesh.Mesh3 m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		m.set_name("$GizmoPointMesh");
		m.primitive = 0;
		double id = 0.0;
		haxor.io.FloatArray ia = new haxor.io.FloatArray(((int) (this.m_gizmo_count) ));
		haxor.io.FloatArray va = new haxor.io.FloatArray(((int) (( this.m_gizmo_count * 3 )) ));
		int va_k = 0;
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
				id += 1.0;
			}
			
		}
		
		m.Set("id", ia, 1);
		m.Set("vertex", va, 3);
		this.mesh = m;
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef851 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef851) 
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


