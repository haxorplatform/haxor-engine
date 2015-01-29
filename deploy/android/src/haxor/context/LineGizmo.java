package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LineGizmo extends haxor.context.Gizmo
{
	public    LineGizmo(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    LineGizmo()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.context.LineGizmo.__hx_ctor_haxor_context_LineGizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_LineGizmo(haxor.context.LineGizmo __temp_me146)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(__temp_me146, haxor.context.Gizmo.LINE, ( haxor.context.Gizmo.MAX_GIZMOS * 3 ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.LineGizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.LineGizmo();
	}
	
	
	@Override public   void OnBuild()
	{
		haxor.graphics.mesh.Mesh3 m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		m.set_name("$GizmoLineMesh");
		m.primitive = 1;
		double id = 0.0;
		haxor.io.FloatArray ia = new haxor.io.FloatArray(((int) (( this.m_gizmo_count * 2 )) ));
		haxor.io.FloatArray va = new haxor.io.FloatArray(((int) (( ( this.m_gizmo_count * 2 ) * 3 )) ));
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
				va.Set(va_k++, 1.0);
				va.Set(va_k++, 1.0);
				va.Set(va_k++, 1.0);
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
			boolean __temp_executeDef850 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef850 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef850) 
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


