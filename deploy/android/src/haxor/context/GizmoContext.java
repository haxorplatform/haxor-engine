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
	
	
	public static   void __hx_ctor_haxor_context_GizmoContext(haxor.context.GizmoContext __temp_me106)
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
	
	public  haxor.graphics.mesh.Mesh texture;
	
	public  haxor.graphics.material.Material gizmo_material;
	
	public  haxor.graphics.material.Material texture_material;
	
	public  haxor.context.WireSphereGizmo wire_sphere_renderer;
	
	public  haxor.context.WireCubeGizmo wire_cube_renderer;
	
	public  haxor.context.AxisGizmo axis_renderer;
	
	public  haxor.context.LineGizmo line_renderer;
	
	public  haxor.context.PointGizmo point_renderer;
	
	public  haxor.context.PointGizmo point_smooth_renderer;
	
	public   void Initialize()
	{
		haxor.graphics.material.Material mat = null;
		mat = this.gizmo_material = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("$GizmoMaterial"));
		mat.set_shader(new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.grid_source)));
		mat.blend = true;
		mat.SetBlending(770, 771);
		mat.SetFloat("Area", 1000.0);
		{
			haxor.math.Color p_color = new haxor.math.Color(((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.4) ));
			mat.SetFloat4("Tint", p_color.r, p_color.g, p_color.b, p_color.a);
		}
		
		mat.ztest = false;
		mat = this.texture_material = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("$TextureMaterial"));
		mat.set_shader(new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.texture_source)));
		mat.blend = true;
		mat.SetBlending(770, 771);
		mat.SetFloat2("Screen", haxor.graphics.Screen.m_width, haxor.graphics.Screen.m_height);
		mat.SetFloat4("Rect", ((double) (0) ), ((double) (0) ), ((double) (100) ), ((double) (100) ));
		{
			haxor.math.Color p_color1 = new haxor.math.Color(((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ));
			mat.SetFloat4("Tint", p_color1.r, p_color1.g, p_color1.b, p_color1.a);
		}
		
		mat.cull = 0;
		mat.ztest = false;
		this.CreateAxis();
		this.CreateGrid(100.0);
		this.CreateTextureQuad();
		this.wire_sphere_renderer = new haxor.context.WireSphereGizmo();
		this.wire_cube_renderer = new haxor.context.WireCubeGizmo();
		this.axis_renderer = new haxor.context.AxisGizmo();
		this.line_renderer = new haxor.context.LineGizmo();
		this.point_renderer = new haxor.context.PointGizmo();
	}
	
	
	public   void CreateTextureQuad()
	{
		haxor.graphics.mesh.Mesh m = this.texture = new haxor.graphics.mesh.Mesh(haxe.lang.Runtime.toString("$TextureQuad"));
		haxor.io.FloatArray vl = null;
		vl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (-1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (-1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (-1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )}));
		m.Set("vertex", vl, 3);
		haxor.math.AABB3 __temp_stmt803 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt803 = _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
		m.set_bounds(m.GenerateAttribBounds("vertex", __temp_stmt803));
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
		haxor.math.AABB3 __temp_stmt804 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt804 = _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
		m.set_bounds(m.GenerateAttribBounds("vertex", __temp_stmt804));
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
		haxor.math.AABB3 __temp_stmt805 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt805 = _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
		this.grid.set_bounds(this.grid.GenerateAttribBounds("vertex", __temp_stmt805));
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
	
	
	public   void DrawWireSphere(haxor.math.Vector3 p_position, double p_radius, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.math.Vector4 __temp_stmt806 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt806 = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		haxor.math.Vector4 __temp_stmt807 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt807 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		this.wire_sphere_renderer.Push(p_color, __temp_stmt806.Set(p_radius, p_radius, p_radius, 1.0), __temp_stmt807.Set3(p_position), p_transform);
	}
	
	
	public   void DrawWireCube(haxor.math.Vector3 p_position, haxor.math.Vector3 p_size, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.math.Vector4 __temp_stmt808 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt808 = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		haxor.math.Vector4 __temp_stmt809 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt809 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		this.wire_cube_renderer.Push(p_color, __temp_stmt808.Set3(p_size), __temp_stmt809.Set3(p_position), p_transform);
	}
	
	
	public   void DrawAxis(haxor.math.Vector3 p_position, haxor.math.Vector3 p_size, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.math.Vector4 __temp_stmt810 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt810 = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		haxor.math.Vector4 __temp_stmt811 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt811 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		this.axis_renderer.Push(p_color, __temp_stmt810.Set3(p_size), __temp_stmt811.Set3(p_position), p_transform);
	}
	
	
	public   void DrawLine(haxor.math.Vector3 p_from, haxor.math.Vector3 p_to, haxor.math.Color p_color, haxor.math.Matrix4 p_transform)
	{
		haxor.math.Vector4 __temp_stmt812 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt812 = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		haxor.math.Vector4 __temp_stmt813 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt813 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		this.line_renderer.Push(p_color, __temp_stmt812.Set3(p_from), __temp_stmt813.Set3(p_to), p_transform);
	}
	
	
	public   void DrawPoint(haxor.math.Vector3 p_position, double p_size, haxor.math.Color p_color, boolean p_smooth, haxor.math.Matrix4 p_transform)
	{
		haxor.math.Vector4 __temp_stmt814 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt814 = _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
		haxor.math.Vector4 __temp_stmt815 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt815 = _this1.m_v4.__get(_this1.m_nv4 = ( (( _this1.m_nv4 + 1 )) % _this1.m_v4.length ));
		}
		
		this.point_renderer.Push(p_color, __temp_stmt814.Set(p_size, ( (p_smooth) ? (1.0) : (0.0) ), 0.0, 0.0), __temp_stmt815.Set3(p_position), p_transform);
	}
	
	
	public   void Render()
	{
		haxor.context.Gizmo gr = null;
		gr = this.wire_sphere_renderer;
		gr.Render();
		gr.Clear();
		gr = this.wire_cube_renderer;
		gr.Render();
		gr.Clear();
		gr = this.axis_renderer;
		gr.Render();
		gr.Clear();
		gr = this.line_renderer;
		gr.Render();
		gr.Clear();
		gr = this.point_renderer;
		gr.Render();
		gr.Clear();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef816 = true;
			switch (field.hashCode())
			{
				case -319419515:
				{
					if (field.equals("point_smooth_renderer")) 
					{
						__temp_executeDef816 = false;
						this.point_smooth_renderer = ((haxor.context.PointGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3181382:
				{
					if (field.equals("grid")) 
					{
						__temp_executeDef816 = false;
						this.grid = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -148414830:
				{
					if (field.equals("point_renderer")) 
					{
						__temp_executeDef816 = false;
						this.point_renderer = ((haxor.context.PointGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3008417:
				{
					if (field.equals("axis")) 
					{
						__temp_executeDef816 = false;
						this.axis = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 172520622:
				{
					if (field.equals("line_renderer")) 
					{
						__temp_executeDef816 = false;
						this.line_renderer = ((haxor.context.LineGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef816 = false;
						this.texture = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1315139679:
				{
					if (field.equals("axis_renderer")) 
					{
						__temp_executeDef816 = false;
						this.axis_renderer = ((haxor.context.AxisGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -955033524:
				{
					if (field.equals("gizmo_material")) 
					{
						__temp_executeDef816 = false;
						this.gizmo_material = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 915951443:
				{
					if (field.equals("wire_cube_renderer")) 
					{
						__temp_executeDef816 = false;
						this.wire_cube_renderer = ((haxor.context.WireCubeGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -415674421:
				{
					if (field.equals("texture_material")) 
					{
						__temp_executeDef816 = false;
						this.texture_material = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -874848965:
				{
					if (field.equals("wire_sphere_renderer")) 
					{
						__temp_executeDef816 = false;
						this.wire_sphere_renderer = ((haxor.context.WireSphereGizmo) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef816) 
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
			boolean __temp_executeDef817 = true;
			switch (field.hashCode())
			{
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Render"))) );
					}
					
					break;
				}
				
				
				case 3181382:
				{
					if (field.equals("grid")) 
					{
						__temp_executeDef817 = false;
						return this.grid;
					}
					
					break;
				}
				
				
				case 2136736396:
				{
					if (field.equals("DrawPoint")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawPoint"))) );
					}
					
					break;
				}
				
				
				case 3008417:
				{
					if (field.equals("axis")) 
					{
						__temp_executeDef817 = false;
						return this.axis;
					}
					
					break;
				}
				
				
				case -762481800:
				{
					if (field.equals("DrawLine")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawLine"))) );
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef817 = false;
						return this.texture;
					}
					
					break;
				}
				
				
				case -762795227:
				{
					if (field.equals("DrawAxis")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawAxis"))) );
					}
					
					break;
				}
				
				
				case -955033524:
				{
					if (field.equals("gizmo_material")) 
					{
						__temp_executeDef817 = false;
						return this.gizmo_material;
					}
					
					break;
				}
				
				
				case -1663598626:
				{
					if (field.equals("DrawWireCube")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawWireCube"))) );
					}
					
					break;
				}
				
				
				case -415674421:
				{
					if (field.equals("texture_material")) 
					{
						__temp_executeDef817 = false;
						return this.texture_material;
					}
					
					break;
				}
				
				
				case -536814282:
				{
					if (field.equals("DrawWireSphere")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawWireSphere"))) );
					}
					
					break;
				}
				
				
				case -874848965:
				{
					if (field.equals("wire_sphere_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.wire_sphere_renderer;
					}
					
					break;
				}
				
				
				case -762622262:
				{
					if (field.equals("DrawGrid")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawGrid"))) );
					}
					
					break;
				}
				
				
				case 915951443:
				{
					if (field.equals("wire_cube_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.wire_cube_renderer;
					}
					
					break;
				}
				
				
				case -932667774:
				{
					if (field.equals("CreateGrid")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateGrid"))) );
					}
					
					break;
				}
				
				
				case -1315139679:
				{
					if (field.equals("axis_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.axis_renderer;
					}
					
					break;
				}
				
				
				case -932840739:
				{
					if (field.equals("CreateAxis")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateAxis"))) );
					}
					
					break;
				}
				
				
				case 172520622:
				{
					if (field.equals("line_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.line_renderer;
					}
					
					break;
				}
				
				
				case 2014410310:
				{
					if (field.equals("CreateTextureQuad")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateTextureQuad"))) );
					}
					
					break;
				}
				
				
				case -148414830:
				{
					if (field.equals("point_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.point_renderer;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -319419515:
				{
					if (field.equals("point_smooth_renderer")) 
					{
						__temp_executeDef817 = false;
						return this.point_smooth_renderer;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef817) 
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
			boolean __temp_executeDef818 = true;
			switch (field.hashCode())
			{
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef818 = false;
						this.Render();
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef818 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case 2136736396:
				{
					if (field.equals("DrawPoint")) 
					{
						__temp_executeDef818 = false;
						this.DrawPoint(((haxor.math.Vector3) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((haxor.math.Color) (dynargs.__get(2)) ), haxe.lang.Runtime.toBool(dynargs.__get(3)), ((haxor.math.Matrix4) (dynargs.__get(4)) ));
					}
					
					break;
				}
				
				
				case 2014410310:
				{
					if (field.equals("CreateTextureQuad")) 
					{
						__temp_executeDef818 = false;
						this.CreateTextureQuad();
					}
					
					break;
				}
				
				
				case -762481800:
				{
					if (field.equals("DrawLine")) 
					{
						__temp_executeDef818 = false;
						this.DrawLine(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), ((haxor.math.Color) (dynargs.__get(2)) ), ((haxor.math.Matrix4) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -932840739:
				{
					if (field.equals("CreateAxis")) 
					{
						__temp_executeDef818 = false;
						this.CreateAxis();
					}
					
					break;
				}
				
				
				case -762795227:
				{
					if (field.equals("DrawAxis")) 
					{
						__temp_executeDef818 = false;
						this.DrawAxis(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), ((haxor.math.Color) (dynargs.__get(2)) ), ((haxor.math.Matrix4) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -932667774:
				{
					if (field.equals("CreateGrid")) 
					{
						__temp_executeDef818 = false;
						this.CreateGrid(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1663598626:
				{
					if (field.equals("DrawWireCube")) 
					{
						__temp_executeDef818 = false;
						this.DrawWireCube(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), ((haxor.math.Color) (dynargs.__get(2)) ), ((haxor.math.Matrix4) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -762622262:
				{
					if (field.equals("DrawGrid")) 
					{
						__temp_executeDef818 = false;
						this.DrawGrid(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((haxor.math.Color) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -536814282:
				{
					if (field.equals("DrawWireSphere")) 
					{
						__temp_executeDef818 = false;
						this.DrawWireSphere(((haxor.math.Vector3) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((haxor.math.Color) (dynargs.__get(2)) ), ((haxor.math.Matrix4) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef818) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("point_smooth_renderer");
		baseArr.push("point_renderer");
		baseArr.push("line_renderer");
		baseArr.push("axis_renderer");
		baseArr.push("wire_cube_renderer");
		baseArr.push("wire_sphere_renderer");
		baseArr.push("texture_material");
		baseArr.push("gizmo_material");
		baseArr.push("texture");
		baseArr.push("axis");
		baseArr.push("grid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


