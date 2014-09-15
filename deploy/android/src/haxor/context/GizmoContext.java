package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GizmoContext extends haxe.lang.HxObject
{
	public    GizmoContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GizmoContext()
	{
		haxor.context.GizmoContext.__hx_ctor_haxor_context_GizmoContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_GizmoContext(haxor.context.GizmoContext __temp_me255378)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.GizmoContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.GizmoContext();
	}
	
	
	public  haxor.graphics.mesh.Mesh grid;
	
	public  haxor.graphics.mesh.Mesh axis;
	
	public  haxor.graphics.material.Material gizmo_material;
	
	public   void Initialize()
	{
		haxor.graphics.material.Material mat = this.gizmo_material = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("$GizmoMaterial"));
		mat.set_shader(new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.gizmo_source)));
		mat.blend = true;
		mat.SetBlending(770, 771);
		mat.SetFloat("Area", 1000.0);
		{
			haxor.math.Color p_color = new haxor.math.Color(((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.4) ));
			mat.SetFloat4("Tint", p_color.r, p_color.g, p_color.b, p_color.a);
		}
		
		mat.ztest = false;
		this.CreateAxis();
		this.CreateGrid(100.0);
	}
	
	
	public   void CreateAxis()
	{
		haxor.graphics.mesh.Mesh m = this.axis = new haxor.graphics.mesh.Mesh(haxe.lang.Runtime.toString("$GridAxis"));
		m.primitive = 1;
		haxor.io.FloatArray vl = new haxor.io.FloatArray(((int) (18) ));
		haxor.io.FloatArray cl = new haxor.io.FloatArray(((int) (24) ));
		int k = 0;
		k = 0;
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 1.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 1.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 0.0);
		vl.Set(k++, 1.0);
		k = 0;
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.3);
		cl.Set(k++, 0.3);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.3);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.3);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 0.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 1.0);
		cl.Set(k++, 0.3);
		cl.Set(k++, 0.3);
		cl.Set(k++, 1.0);
		cl.Set(k++, 1.0);
		m.Set("vertex", vl, 3);
		m.Set("color", cl, 4);
		haxor.math.AABB3 __temp_stmt255981 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt255981 = _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
		m.set_bounds(m.GenerateAttribBounds("vertex", __temp_stmt255981));
	}
	
	
	public   void CreateGrid(double p_step)
	{
		this.grid = new haxor.graphics.mesh.Mesh(haxe.lang.Runtime.toString("$GridMesh"));
		this.grid.primitive = 1;
		int len = ((int) (( p_step + 1 )) );
		p_step = ( 1.0 / p_step );
		double ox = 0.5;
		double oz = 0.5;
		double px = 0.0;
		double pz = 0.0;
		haxor.io.FloatArray vl = new haxor.io.FloatArray(((int) (( 12 * len )) ));
		int k = 0;
		k = 0;
		{
			int _g = 0;
			while (( _g < len ))
			{
				int i = _g++;
				vl.Set(k++, ( px - ox ));
				vl.Set(k++, 0.0);
				vl.Set(k++, oz);
				vl.Set(k++, ( px - ox ));
				vl.Set(k++, 0.0);
				vl.Set(k++,  - (oz) );
				px += p_step;
			}
			
		}
		
		{
			int _g1 = 0;
			while (( _g1 < len ))
			{
				int i1 = _g1++;
				vl.Set(k++, ox);
				vl.Set(k++, 0.0);
				vl.Set(k++, ( pz - oz ));
				vl.Set(k++,  - (ox) );
				vl.Set(k++, 0.0);
				vl.Set(k++, ( pz - oz ));
				pz += p_step;
			}
			
		}
		
		this.grid.Set("vertex", vl, 3);
		haxor.math.AABB3 __temp_stmt255982 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt255982 = _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
		this.grid.set_bounds(this.grid.GenerateAttribBounds("vertex", __temp_stmt255982));
	}
	
	
	public   void DrawGrid(double p_area, haxor.math.Color p_color)
	{
		this.gizmo_material.SetFloat("Area", p_area);
		if (( p_color != null )) 
		{
			this.gizmo_material.SetFloat4("Tint", p_color.r, p_color.g, p_color.b, p_color.a);
		}
		
		haxor.graphics.Graphics.Render(this.grid, this.gizmo_material, null, haxor.component.Camera.m_main);
	}
	
	
	public   void DrawAxis(double p_area)
	{
		this.gizmo_material.SetFloat("Area", p_area);
		{
			haxor.math.Color __temp_stmt255983 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt255983 = _this.m_c.__get(_this.m_nc = ( (( _this.m_nc + 1 )) % _this.m_c.length ));
			}
			
			haxor.math.Color p_color = __temp_stmt255983.Set(1, 1, 1, 1);
			this.gizmo_material.SetFloat4("Tint", p_color.r, p_color.g, p_color.b, p_color.a);
		}
		
		haxor.graphics.Graphics.Render(this.axis, this.gizmo_material, null, haxor.component.Camera.m_main);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255984 = true;
			switch (field.hashCode())
			{
				case -955033524:
				{
					if (field.equals("gizmo_material")) 
					{
						__temp_executeDef255984 = false;
						this.gizmo_material = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3181382:
				{
					if (field.equals("grid")) 
					{
						__temp_executeDef255984 = false;
						this.grid = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3008417:
				{
					if (field.equals("axis")) 
					{
						__temp_executeDef255984 = false;
						this.axis = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255984) 
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
			boolean __temp_executeDef255985 = true;
			switch (field.hashCode())
			{
				case -762795227:
				{
					if (field.equals("DrawAxis")) 
					{
						__temp_executeDef255985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawAxis"))) );
					}
					
					break;
				}
				
				
				case 3181382:
				{
					if (field.equals("grid")) 
					{
						__temp_executeDef255985 = false;
						return this.grid;
					}
					
					break;
				}
				
				
				case -762622262:
				{
					if (field.equals("DrawGrid")) 
					{
						__temp_executeDef255985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawGrid"))) );
					}
					
					break;
				}
				
				
				case 3008417:
				{
					if (field.equals("axis")) 
					{
						__temp_executeDef255985 = false;
						return this.axis;
					}
					
					break;
				}
				
				
				case -932667774:
				{
					if (field.equals("CreateGrid")) 
					{
						__temp_executeDef255985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateGrid"))) );
					}
					
					break;
				}
				
				
				case -955033524:
				{
					if (field.equals("gizmo_material")) 
					{
						__temp_executeDef255985 = false;
						return this.gizmo_material;
					}
					
					break;
				}
				
				
				case -932840739:
				{
					if (field.equals("CreateAxis")) 
					{
						__temp_executeDef255985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateAxis"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef255985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255985) 
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
			boolean __temp_executeDef255986 = true;
			switch (field.hashCode())
			{
				case -762795227:
				{
					if (field.equals("DrawAxis")) 
					{
						__temp_executeDef255986 = false;
						this.DrawAxis(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef255986 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -762622262:
				{
					if (field.equals("DrawGrid")) 
					{
						__temp_executeDef255986 = false;
						this.DrawGrid(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((haxor.math.Color) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -932840739:
				{
					if (field.equals("CreateAxis")) 
					{
						__temp_executeDef255986 = false;
						this.CreateAxis();
					}
					
					break;
				}
				
				
				case -932667774:
				{
					if (field.equals("CreateGrid")) 
					{
						__temp_executeDef255986 = false;
						this.CreateGrid(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255986) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("gizmo_material");
		baseArr.push("axis");
		baseArr.push("grid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


