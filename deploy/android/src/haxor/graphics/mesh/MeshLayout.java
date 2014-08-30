package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshLayout<VL, NL, UL0, UL1, TL, BL> extends haxor.graphics.mesh.Mesh
{
	public    MeshLayout(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    MeshLayout(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.MeshLayout.__hx_ctor_haxor_graphics_mesh_MeshLayout(this, p_name);
	}
	
	
	public static  <VL_c, NL_c, UL0_c, UL1_c, TL_c, BL_c> void __hx_ctor_haxor_graphics_mesh_MeshLayout(haxor.graphics.mesh.MeshLayout<VL_c, NL_c, UL0_c, UL1_c, TL_c, BL_c> __temp_me151399, java.lang.String p_name)
	{
		haxor.graphics.mesh.Mesh.__hx_ctor_haxor_graphics_mesh_Mesh(__temp_me151399, ( (( p_name == null )) ? (haxe.lang.Runtime.toString("")) : (p_name) ));
		if (( p_name == null )) 
		{
			p_name = "";
		}
		
		__temp_me151399.m_vertex = new haxe.root.Array<VL_c>(( (VL_c[]) (new java.lang.Object[] {}) ));
		__temp_me151399.m_normal = new haxe.root.Array<NL_c>(( (NL_c[]) (new java.lang.Object[] {}) ));
		__temp_me151399.m_color = new haxe.root.Array<haxor.math.Color>(new haxor.math.Color[]{});
		__temp_me151399.m_uv0 = new haxe.root.Array<UL0_c>(( (UL0_c[]) (new java.lang.Object[] {}) ));
		__temp_me151399.m_uv1 = new haxe.root.Array<UL1_c>(( (UL1_c[]) (new java.lang.Object[] {}) ));
		__temp_me151399.m_tangent = new haxe.root.Array<TL_c>(( (TL_c[]) (new java.lang.Object[] {}) ));
		__temp_me151399.m_binormal = new haxe.root.Array<BL_c>(( (BL_c[]) (new java.lang.Object[] {}) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.MeshLayout<java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.MeshLayout<java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object, java.lang.Object>(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   haxe.root.Array<VL> get_vertex()
	{
		return this.m_vertex;
	}
	
	
	public   haxe.root.Array<VL> set_vertex(haxe.root.Array<VL> v)
	{
		return this.m_vertex = this.UpdateAttribute("vertex", v, false);
	}
	
	
	public  haxe.root.Array<VL> m_vertex;
	
	
	
	public   haxe.root.Array<NL> get_normal()
	{
		return this.m_normal;
	}
	
	
	public   haxe.root.Array<NL> set_normal(haxe.root.Array<NL> v)
	{
		return this.m_normal = this.UpdateAttribute("normal", v, false);
	}
	
	
	public  haxe.root.Array<NL> m_normal;
	
	
	
	public   haxe.root.Array<haxor.math.Color> get_color()
	{
		return this.m_color;
	}
	
	
	public   haxe.root.Array<haxor.math.Color> set_color(haxe.root.Array<haxor.math.Color> v)
	{
		return this.m_color = this.UpdateAttribute("color", v, true);
	}
	
	
	public  haxe.root.Array<haxor.math.Color> m_color;
	
	
	
	public   haxe.root.Array<UL0> get_uv0()
	{
		return this.m_uv0;
	}
	
	
	public   haxe.root.Array<UL0> set_uv0(haxe.root.Array<UL0> v)
	{
		return this.m_uv0 = this.UpdateAttribute("uv0", v, false);
	}
	
	
	public  haxe.root.Array<UL0> m_uv0;
	
	
	
	public   haxe.root.Array<UL1> get_uv1()
	{
		return this.m_uv1;
	}
	
	
	public   haxe.root.Array<UL1> set_uv1(haxe.root.Array<UL1> v)
	{
		return this.m_uv1 = this.UpdateAttribute("uv1", v, false);
	}
	
	
	public  haxe.root.Array<UL1> m_uv1;
	
	
	
	public   haxe.root.Array<TL> get_tangent()
	{
		return this.m_tangent;
	}
	
	
	public   haxe.root.Array<TL> set_tangent(haxe.root.Array<TL> v)
	{
		return this.m_tangent = this.UpdateAttribute("tangent", v, false);
	}
	
	
	public  haxe.root.Array<TL> m_tangent;
	
	
	
	public   haxe.root.Array<BL> get_binormal()
	{
		return this.m_binormal;
	}
	
	
	public   haxe.root.Array<BL> set_binormal(haxe.root.Array<BL> v)
	{
		return this.m_binormal = this.UpdateAttribute("binormal", v, false);
	}
	
	
	public  haxe.root.Array<BL> m_binormal;
	
	public   void GenerateBounds()
	{
		this.GenerateAttribBounds("vertex", this.m_bounds);
	}
	
	
	public  <T> haxe.root.Array<T> UpdateAttribute(java.lang.String p_name, haxe.root.Array<T> p_list, java.lang.Object p_is_color)
	{
		boolean __temp_p_is_color151398 = ( (( p_is_color == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_is_color)) );
		if (( p_list == null )) 
		{
			this.Remove(p_name);
			return new haxe.root.Array<T>(( (T[]) (new java.lang.Object[] {}) ));
		}
		
		if (( p_list.length <= 0 )) 
		{
			this.Remove(p_name);
			return new haxe.root.Array<T>(( (T[]) (new java.lang.Object[] {}) ));
		}
		
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		int off = 1;
		if (( p_list.__get(0) instanceof haxor.math.Vector2 )) 
		{
			off = 2;
		}
		
		if (( p_list.__get(0) instanceof haxor.math.Vector3 )) 
		{
			off = 3;
		}
		
		if (( p_list.__get(0) instanceof haxor.math.Vector4 )) 
		{
			off = 4;
		}
		
		if (( p_list.__get(0) instanceof haxor.math.Color )) 
		{
			off = 4;
		}
		
		if (( a == null )) 
		{
			a = this.Set(p_name, new haxor.io.FloatArray(((int) (1) )), off);
		}
		
		int p = 0;
		haxor.io.FloatArray f = ((haxor.io.FloatArray) (a.data = new haxor.io.FloatArray(((int) (( p_list.length * off )) ))) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				T it = p_list.__get(i);
				switch (off)
				{
					case 1:
					{
						double v = ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (it) ))) );
						f.Set(p++, v);
						break;
					}
					
					
					case 2:
					{
						haxor.math.Vector2 v2 = ((haxor.math.Vector2) (((java.lang.Object) (it) )) );
						f.Set(p++, v2.x);
						f.Set(p++, v2.y);
						break;
					}
					
					
					case 3:
					{
						haxor.math.Vector3 v3 = ((haxor.math.Vector3) (((java.lang.Object) (it) )) );
						f.Set(p++, v3.x);
						f.Set(p++, v3.y);
						f.Set(p++, v3.z);
						break;
					}
					
					
					case 4:
					{
						if (__temp_p_is_color151398) 
						{
							haxor.math.Color c = ((haxor.math.Color) (((java.lang.Object) (it) )) );
							f.Set(p++, c.r);
							f.Set(p++, c.g);
							f.Set(p++, c.b);
							f.Set(p++, c.a);
						}
						 else 
						{
							haxor.math.Vector4 v4 = ((haxor.math.Vector4) (((java.lang.Object) (it) )) );
							f.Set(p++, v4.x);
							f.Set(p++, v4.y);
							f.Set(p++, v4.z);
							f.Set(p++, v4.w);
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
		return p_list;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152162 = true;
			switch (field.hashCode())
			{
				case 1095930752:
				{
					if (field.equals("m_binormal")) 
					{
						__temp_executeDef152162 = false;
						this.m_binormal = ((haxe.root.Array<BL>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -819940956:
				{
					if (field.equals("vertex")) 
					{
						__temp_executeDef152162 = false;
						this.set_vertex(((haxe.root.Array<VL>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 950548462:
				{
					if (field.equals("binormal")) 
					{
						__temp_executeDef152162 = false;
						this.set_binormal(((haxe.root.Array<BL>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1418671690:
				{
					if (field.equals("m_vertex")) 
					{
						__temp_executeDef152162 = false;
						this.m_vertex = ((haxe.root.Array<VL>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1372212339:
				{
					if (field.equals("m_tangent")) 
					{
						__temp_executeDef152162 = false;
						this.m_tangent = ((haxe.root.Array<TL>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1039745817:
				{
					if (field.equals("normal")) 
					{
						__temp_executeDef152162 = false;
						this.set_normal(((haxe.root.Array<NL>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1541971387:
				{
					if (field.equals("tangent")) 
					{
						__temp_executeDef152162 = false;
						this.set_tangent(((haxe.root.Array<TL>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1638476551:
				{
					if (field.equals("m_normal")) 
					{
						__temp_executeDef152162 = false;
						this.m_normal = ((haxe.root.Array<NL>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103610078:
				{
					if (field.equals("m_uv1")) 
					{
						__temp_executeDef152162 = false;
						this.m_uv1 = ((haxe.root.Array<UL1>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef152162 = false;
						this.set_color(((haxe.root.Array<haxor.math.Color>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 116144:
				{
					if (field.equals("uv1")) 
					{
						__temp_executeDef152162 = false;
						this.set_uv1(((haxe.root.Array<UL1>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 768265489:
				{
					if (field.equals("m_color")) 
					{
						__temp_executeDef152162 = false;
						this.m_color = ((haxe.root.Array<haxor.math.Color>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103610077:
				{
					if (field.equals("m_uv0")) 
					{
						__temp_executeDef152162 = false;
						this.m_uv0 = ((haxe.root.Array<UL0>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116143:
				{
					if (field.equals("uv0")) 
					{
						__temp_executeDef152162 = false;
						this.set_uv0(((haxe.root.Array<UL0>) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152162) 
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
			boolean __temp_executeDef152163 = true;
			switch (field.hashCode())
			{
				case 221584307:
				{
					if (field.equals("UpdateAttribute")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateAttribute"))) );
					}
					
					break;
				}
				
				
				case -819940956:
				{
					if (field.equals("vertex")) 
					{
						__temp_executeDef152163 = false;
						return this.get_vertex();
					}
					
					break;
				}
				
				
				case 691476650:
				{
					if (field.equals("GenerateBounds")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateBounds"))) );
					}
					
					break;
				}
				
				
				case 1260737197:
				{
					if (field.equals("get_vertex")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vertex"))) );
					}
					
					break;
				}
				
				
				case 1095930752:
				{
					if (field.equals("m_binormal")) 
					{
						__temp_executeDef152163 = false;
						return this.m_binormal;
					}
					
					break;
				}
				
				
				case -1097424863:
				{
					if (field.equals("set_vertex")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_vertex"))) );
					}
					
					break;
				}
				
				
				case 576486187:
				{
					if (field.equals("set_binormal")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_binormal"))) );
					}
					
					break;
				}
				
				
				case -1418671690:
				{
					if (field.equals("m_vertex")) 
					{
						__temp_executeDef152163 = false;
						return this.m_vertex;
					}
					
					break;
				}
				
				
				case -972506441:
				{
					if (field.equals("get_binormal")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_binormal"))) );
					}
					
					break;
				}
				
				
				case -1039745817:
				{
					if (field.equals("normal")) 
					{
						__temp_executeDef152163 = false;
						return this.get_normal();
					}
					
					break;
				}
				
				
				case 950548462:
				{
					if (field.equals("binormal")) 
					{
						__temp_executeDef152163 = false;
						return this.get_binormal();
					}
					
					break;
				}
				
				
				case 1040932336:
				{
					if (field.equals("get_normal")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_normal"))) );
					}
					
					break;
				}
				
				
				case 1372212339:
				{
					if (field.equals("m_tangent")) 
					{
						__temp_executeDef152163 = false;
						return this.m_tangent;
					}
					
					break;
				}
				
				
				case -1317229724:
				{
					if (field.equals("set_normal")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_normal"))) );
					}
					
					break;
				}
				
				
				case -1554037912:
				{
					if (field.equals("set_tangent")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_tangent"))) );
					}
					
					break;
				}
				
				
				case -1638476551:
				{
					if (field.equals("m_normal")) 
					{
						__temp_executeDef152163 = false;
						return this.m_normal;
					}
					
					break;
				}
				
				
				case -1465458084:
				{
					if (field.equals("get_tangent")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_tangent"))) );
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef152163 = false;
						return this.get_color();
					}
					
					break;
				}
				
				
				case -1541971387:
				{
					if (field.equals("tangent")) 
					{
						__temp_executeDef152163 = false;
						return this.get_tangent();
					}
					
					break;
				}
				
				
				case 1131792698:
				{
					if (field.equals("get_color")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_color"))) );
					}
					
					break;
				}
				
				
				case 103610078:
				{
					if (field.equals("m_uv1")) 
					{
						__temp_executeDef152163 = false;
						return this.m_uv1;
					}
					
					break;
				}
				
				
				case 917175622:
				{
					if (field.equals("set_color")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_color"))) );
					}
					
					break;
				}
				
				
				case 1985327187:
				{
					if (field.equals("set_uv1")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_uv1"))) );
					}
					
					break;
				}
				
				
				case 768265489:
				{
					if (field.equals("m_color")) 
					{
						__temp_executeDef152163 = false;
						return this.m_color;
					}
					
					break;
				}
				
				
				case -74782393:
				{
					if (field.equals("get_uv1")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_uv1"))) );
					}
					
					break;
				}
				
				
				case 116143:
				{
					if (field.equals("uv0")) 
					{
						__temp_executeDef152163 = false;
						return this.get_uv0();
					}
					
					break;
				}
				
				
				case 116144:
				{
					if (field.equals("uv1")) 
					{
						__temp_executeDef152163 = false;
						return this.get_uv1();
					}
					
					break;
				}
				
				
				case -74782394:
				{
					if (field.equals("get_uv0")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_uv0"))) );
					}
					
					break;
				}
				
				
				case 103610077:
				{
					if (field.equals("m_uv0")) 
					{
						__temp_executeDef152163 = false;
						return this.m_uv0;
					}
					
					break;
				}
				
				
				case 1985327186:
				{
					if (field.equals("set_uv0")) 
					{
						__temp_executeDef152163 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_uv0"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152163) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef152164 = true;
			switch (field.hashCode())
			{
				case 221584307:
				{
					if (field.equals("UpdateAttribute")) 
					{
						__temp_executeDef152164 = false;
						return this.UpdateAttribute(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 1260737197:
				{
					if (field.equals("get_vertex")) 
					{
						__temp_executeDef152164 = false;
						return this.get_vertex();
					}
					
					break;
				}
				
				
				case 691476650:
				{
					if (field.equals("GenerateBounds")) 
					{
						__temp_executeDef152164 = false;
						this.GenerateBounds();
					}
					
					break;
				}
				
				
				case -1097424863:
				{
					if (field.equals("set_vertex")) 
					{
						__temp_executeDef152164 = false;
						return this.set_vertex(((haxe.root.Array<VL>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 576486187:
				{
					if (field.equals("set_binormal")) 
					{
						__temp_executeDef152164 = false;
						return this.set_binormal(((haxe.root.Array<BL>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1040932336:
				{
					if (field.equals("get_normal")) 
					{
						__temp_executeDef152164 = false;
						return this.get_normal();
					}
					
					break;
				}
				
				
				case -972506441:
				{
					if (field.equals("get_binormal")) 
					{
						__temp_executeDef152164 = false;
						return this.get_binormal();
					}
					
					break;
				}
				
				
				case -1317229724:
				{
					if (field.equals("set_normal")) 
					{
						__temp_executeDef152164 = false;
						return this.set_normal(((haxe.root.Array<NL>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1554037912:
				{
					if (field.equals("set_tangent")) 
					{
						__temp_executeDef152164 = false;
						return this.set_tangent(((haxe.root.Array<TL>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1131792698:
				{
					if (field.equals("get_color")) 
					{
						__temp_executeDef152164 = false;
						return this.get_color();
					}
					
					break;
				}
				
				
				case -1465458084:
				{
					if (field.equals("get_tangent")) 
					{
						__temp_executeDef152164 = false;
						return this.get_tangent();
					}
					
					break;
				}
				
				
				case 917175622:
				{
					if (field.equals("set_color")) 
					{
						__temp_executeDef152164 = false;
						return this.set_color(((haxe.root.Array<haxor.math.Color>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985327187:
				{
					if (field.equals("set_uv1")) 
					{
						__temp_executeDef152164 = false;
						return this.set_uv1(((haxe.root.Array<UL1>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -74782394:
				{
					if (field.equals("get_uv0")) 
					{
						__temp_executeDef152164 = false;
						return this.get_uv0();
					}
					
					break;
				}
				
				
				case -74782393:
				{
					if (field.equals("get_uv1")) 
					{
						__temp_executeDef152164 = false;
						return this.get_uv1();
					}
					
					break;
				}
				
				
				case 1985327186:
				{
					if (field.equals("set_uv0")) 
					{
						__temp_executeDef152164 = false;
						return this.set_uv0(((haxe.root.Array<UL0>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152164) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_binormal");
		baseArr.push("binormal");
		baseArr.push("m_tangent");
		baseArr.push("tangent");
		baseArr.push("m_uv1");
		baseArr.push("uv1");
		baseArr.push("m_uv0");
		baseArr.push("uv0");
		baseArr.push("m_color");
		baseArr.push("color");
		baseArr.push("m_normal");
		baseArr.push("normal");
		baseArr.push("m_vertex");
		baseArr.push("vertex");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


