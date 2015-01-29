package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WireCubeGizmo extends haxor.context.Gizmo
{
	public    WireCubeGizmo(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    WireCubeGizmo()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.context.WireCubeGizmo.__hx_ctor_haxor_context_WireCubeGizmo(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_WireCubeGizmo(haxor.context.WireCubeGizmo __temp_me144)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(__temp_me144, haxor.context.Gizmo.WIRE_CUBE, haxor.context.Gizmo.MAX_GIZMOS);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.WireCubeGizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.WireCubeGizmo();
	}
	
	
	@Override public   void OnBuild()
	{
		haxor.graphics.mesh.Mesh3 m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		m.set_name("$GizmoWireCubeMesh");
		m.primitive = 1;
		double a = -0.5;
		double b = 0.5;
		haxe.root.Array<haxor.math.Vector3> p = new haxe.root.Array<haxor.math.Vector3>(new haxor.math.Vector3[]{new haxor.math.Vector3(((java.lang.Object) (a) ), ((java.lang.Object) (a) ), ((java.lang.Object) (a) )), new haxor.math.Vector3(((java.lang.Object) (a) ), ((java.lang.Object) (a) ), ((java.lang.Object) (b) )), new haxor.math.Vector3(((java.lang.Object) (b) ), ((java.lang.Object) (a) ), ((java.lang.Object) (b) )), new haxor.math.Vector3(((java.lang.Object) (b) ), ((java.lang.Object) (a) ), ((java.lang.Object) (a) )), new haxor.math.Vector3(((java.lang.Object) (a) ), ((java.lang.Object) (b) ), ((java.lang.Object) (a) )), new haxor.math.Vector3(((java.lang.Object) (a) ), ((java.lang.Object) (b) ), ((java.lang.Object) (b) )), new haxor.math.Vector3(((java.lang.Object) (b) ), ((java.lang.Object) (b) ), ((java.lang.Object) (b) )), new haxor.math.Vector3(((java.lang.Object) (b) ), ((java.lang.Object) (b) ), ((java.lang.Object) (a) ))});
		haxe.root.Array<java.lang.Object> tp = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0, 1, 1, 2, 2, 3, 3, 0, 4, 5, 5, 6, 6, 7, 7, 4, 0, 1, 1, 5, 5, 4, 4, 0, 3, 2, 2, 6, 6, 7, 7, 3, 0, 3, 3, 7, 7, 4, 4, 0, 1, 5, 5, 6, 6, 2, 2, 1});
		haxor.io.FloatArray va = new haxor.io.FloatArray(((int) (( ( tp.length * 3 ) * this.m_gizmo_count )) ));
		haxor.io.FloatArray ia = new haxor.io.FloatArray(((int) (( tp.length * this.m_gizmo_count )) ));
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
					int _g3 = 0;
					int _g2 = tp.length;
					while (( _g3 < _g2 ))
					{
						int i = _g3++;
						int vid = ((int) (haxe.lang.Runtime.toInt(tp.__get(i))) );
						va.Set(va_k++, p.__get(vid).x);
						va.Set(va_k++, p.__get(vid).y);
						va.Set(va_k++, p.__get(vid).z);
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
			boolean __temp_executeDef848 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef848 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef848) 
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


