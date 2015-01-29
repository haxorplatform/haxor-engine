package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WireSphereGizmo extends haxor.context.Gizmo
{
	public    WireSphereGizmo(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    WireSphereGizmo()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.context.WireSphereGizmo.__hx_ctor_haxor_context_WireSphereGizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_WireSphereGizmo(haxor.context.WireSphereGizmo __temp_me143)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(__temp_me143, haxor.context.Gizmo.WIRE_SPHERE, haxor.context.Gizmo.MAX_GIZMOS);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.WireSphereGizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.WireSphereGizmo();
	}
	
	
	@Override public   void OnBuild()
	{
		haxor.graphics.mesh.Mesh3 m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		m.set_name("$GizmoWireSphereMesh");
		m.primitive = 1;
		double r = 1.0;
		haxor.math.Vector3 v = null;
		int steps = 720;
		haxor.io.FloatArray ia = new haxor.io.FloatArray(((int) (( ( steps * 6 ) * this.m_gizmo_count )) ));
		haxor.io.FloatArray va = new haxor.io.FloatArray(((int) (( ( steps * 18 ) * this.m_gizmo_count )) ));
		int va_k = 0;
		int ia_k = 0;
		double id = 0.0;
		{
			int _g1 = 0;
			int _g = this.m_gizmo_count;
			while (( _g1 < _g ))
			{
				int k = _g1++;
				{
					int _g2 = 0;
					while (( _g2 < steps ))
					{
						int i = _g2++;
						double astp = ( 1.0 / (( steps - 1 )) );
						double a = 0.0;
						a = ( ( 360 * i ) * astp );
						double sv0 = ( ( java.lang.Math.sin(( a * 0.01745329251994329576923690768489 )) * r ) * 0.5 );
						double cv0 = ( ( java.lang.Math.cos(( a * 0.01745329251994329576923690768489 )) * r ) * 0.5 );
						a = ( ( 360 * (( i + 1 )) ) * astp );
						double sv1 = ( ( java.lang.Math.sin(( a * 0.01745329251994329576923690768489 )) * r ) * 0.5 );
						double cv1 = ( ( java.lang.Math.cos(( a * 0.01745329251994329576923690768489 )) * r ) * 0.5 );
						va.Set(va_k++, cv0);
						va.Set(va_k++, 0.0);
						va.Set(va_k++, sv0);
						ia.Set(ia_k++, id);
						va.Set(va_k++, cv1);
						va.Set(va_k++, 0.0);
						va.Set(va_k++, sv1);
						ia.Set(ia_k++, id);
						va.Set(va_k++, 0.0);
						va.Set(va_k++, cv0);
						va.Set(va_k++, sv0);
						ia.Set(ia_k++, id);
						va.Set(va_k++, 0.0);
						va.Set(va_k++, cv1);
						va.Set(va_k++, sv1);
						ia.Set(ia_k++, id);
						va.Set(va_k++, cv0);
						va.Set(va_k++, sv0);
						va.Set(va_k++, 0.0);
						ia.Set(ia_k++, id);
						va.Set(va_k++, cv1);
						va.Set(va_k++, sv1);
						va.Set(va_k++, 0.0);
						ia.Set(ia_k++, id);
					}
					
				}
				
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
			boolean __temp_executeDef847 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef847 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef847) 
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


