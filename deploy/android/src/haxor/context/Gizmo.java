package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Gizmo extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.Gizmo.POINT = 0;
		haxor.context.Gizmo.LINE = 1;
		haxor.context.Gizmo.AXIS = 2;
		haxor.context.Gizmo.WIRE_CUBE = 3;
		haxor.context.Gizmo.WIRE_SPHERE = 4;
		haxor.context.Gizmo.DATA_OFFSET = 24;
		haxor.context.Gizmo.MAX_GIZMOS = 500;
		haxor.context.Gizmo.IDM = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	public    Gizmo(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Gizmo(int p_type, int p_count)
	{
		haxor.context.Gizmo.__hx_ctor_haxor_context_Gizmo(this, p_type, p_count);
	}
	
	
	public static   void __hx_ctor_haxor_context_Gizmo(haxor.context.Gizmo __temp_me142, int p_type, int p_count)
	{
		__temp_me142.type = p_type;
		__temp_me142.m_render_count = 0;
		__temp_me142.m_gizmo_count = p_count;
		if (( haxor.context.Gizmo.SHADER == null )) 
		{
			haxor.context.Gizmo.SHADER = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.gizmo_source));
		}
		
		__temp_me142.material = new haxor.graphics.material.Material(haxe.lang.Runtime.toString(( ( "Gizmo" + p_type ) + "Material" )));
		__temp_me142.material.set_shader(haxor.context.Gizmo.SHADER);
		__temp_me142.material.blend = true;
		__temp_me142.material.SetBlending(770, 771);
		__temp_me142.material.SetInt("Type", p_type);
		__temp_me142.material.ztest = false;
		int tw = 0;
		int th = 0;
		if (( p_count >= 1 )) 
		{
			int data_tex_size = 0;
			double __temp_stmt844 = 0.0;
			{
				double b = 0.0;
				int __temp_stmt845 = 0;
				{
					int p_v = 0;
					double __temp_stmt846 = 0.0;
					{
						double p_v1 = java.lang.Math.sqrt(( p_count * (( ((double) (haxor.context.Gizmo.DATA_OFFSET) ) / 4 )) ));
						__temp_stmt846 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.9999999) : (0.9999999) )) )) )) );
					}
					
					p_v = ((int) (__temp_stmt846) );
					 -- p_v;
					p_v |= ( p_v >> 1 );
					p_v |= ( p_v >> 2 );
					p_v |= ( p_v >> 4 );
					p_v |= ( p_v >> 8 );
					p_v |= ( p_v >> 16 );
					__temp_stmt845 =  ++ p_v;
				}
				
				b = ((double) (__temp_stmt845) );
				__temp_stmt844 = java.lang.Math.max(((double) (2) ), b);
			}
			
			data_tex_size = ((int) (__temp_stmt844) );
			__temp_me142.data = new haxor.graphics.texture.ComputeTexture(((int) (data_tex_size) ), ((int) (data_tex_size) ), ((haxor.core.PixelFormat) (haxor.core.PixelFormat.Float4) ));
			__temp_me142.material.SetTexture("Data", __temp_me142.data);
			__temp_me142.material.SetInt("DataSize", __temp_me142.data.m_width);
			tw = __temp_me142.data.m_width;
			th = __temp_me142.data.m_height;
		}
		
		haxor.core.Console.Log(( ( ( ( ( ( "Gizmos> Created Renderer [" + p_type ) + "] data[" ) + tw ) + "x" ) + th ) + "]" ), null);
		__temp_me142.OnBuild();
	}
	
	
	public static  int POINT;
	
	public static  int LINE;
	
	public static  int AXIS;
	
	public static  int WIRE_CUBE;
	
	public static  int WIRE_SPHERE;
	
	public static  int DATA_OFFSET;
	
	public static  int MAX_GIZMOS;
	
	public static  haxor.math.Matrix4 IDM;
	
	public static  haxor.graphics.material.Shader SHADER;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.Gizmo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.Gizmo(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ));
	}
	
	
	public  haxor.graphics.texture.ComputeTexture data;
	
	public  haxor.graphics.mesh.Mesh mesh;
	
	public  haxor.graphics.material.Material material;
	
	public  int type;
	
	public  int m_render_count;
	
	public  int m_gizmo_count;
	
	public   void OnBuild()
	{
		{
		}
		
	}
	
	
	public   void Push(haxor.math.Color p_color, haxor.math.Vector4 p_a, haxor.math.Vector4 p_b, haxor.math.Matrix4 p_transform)
	{
		if (( this.m_render_count >= this.m_gizmo_count )) 
		{
			return ;
		}
		
		int id = this.m_render_count;
		haxor.io.FloatArray f32 = ((haxor.io.FloatArray) (this.data.m_data.get_buffer()) );
		int p = ( id * haxor.context.Gizmo.DATA_OFFSET );
		haxor.math.Color c = null;
		if (( p_color == null )) 
		{
			haxor.math.Color __temp_stmt838 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt838 = _this.m_c.__get(_this.m_nc = ( (( _this.m_nc + 1 )) % _this.m_c.length ));
			}
			
			c = __temp_stmt838.Set(1, 1, 1, 1);
		}
		 else 
		{
			c = p_color;
		}
		
		f32.Set(p++, c.r);
		f32.Set(p++, c.g);
		f32.Set(p++, c.b);
		f32.Set(p++, c.a);
		f32.Set(p++, p_a.x);
		f32.Set(p++, p_a.y);
		f32.Set(p++, p_a.z);
		f32.Set(p++, p_a.w);
		f32.Set(p++, p_b.x);
		f32.Set(p++, p_b.y);
		f32.Set(p++, p_b.z);
		f32.Set(p++, p_b.w);
		haxor.math.Matrix4 m = null;
		if (( p_transform == null )) 
		{
			m = haxor.context.Gizmo.IDM;
		}
		 else 
		{
			m = p_transform;
		}
		
		{
			int _g = 0;
			while (( _g < 12 ))
			{
				int i = _g++;
				f32.Set(p++, m.GetIndex(i));
			}
			
		}
		
		this.m_render_count++;
	}
	
	
	public   void Clear()
	{
		this.m_render_count = 0;
	}
	
	
	public   void Render()
	{
		if (( this.m_render_count > 0 )) 
		{
			this.data.Apply();
			this.material.SetInt("Count", this.m_render_count);
			haxor.graphics.Graphics.Render(this.mesh, this.material, null, haxor.component.Camera.m_main);
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef839 = true;
			switch (field.hashCode())
			{
				case -34743496:
				{
					if (field.equals("m_gizmo_count")) 
					{
						__temp_executeDef839 = false;
						this.m_gizmo_count = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef839 = false;
						this.type = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -305188936:
				{
					if (field.equals("m_render_count")) 
					{
						__temp_executeDef839 = false;
						this.m_render_count = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef839) 
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
			boolean __temp_executeDef840 = true;
			switch (field.hashCode())
			{
				case -34743496:
				{
					if (field.equals("m_gizmo_count")) 
					{
						__temp_executeDef840 = false;
						this.m_gizmo_count = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef840 = false;
						this.data = ((haxor.graphics.texture.ComputeTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -305188936:
				{
					if (field.equals("m_render_count")) 
					{
						__temp_executeDef840 = false;
						this.m_render_count = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef840 = false;
						this.mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef840 = false;
						this.type = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef840 = false;
						this.material = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef840) 
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
			boolean __temp_executeDef841 = true;
			switch (field.hashCode())
			{
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef841 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Render"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef841 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef841 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef841 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 2499386:
				{
					if (field.equals("Push")) 
					{
						__temp_executeDef841 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Push"))) );
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef841 = false;
						return this.material;
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef841 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef841 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case -34743496:
				{
					if (field.equals("m_gizmo_count")) 
					{
						__temp_executeDef841 = false;
						return this.m_gizmo_count;
					}
					
					break;
				}
				
				
				case -305188936:
				{
					if (field.equals("m_render_count")) 
					{
						__temp_executeDef841 = false;
						return this.m_render_count;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef841) 
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
			boolean __temp_executeDef842 = true;
			switch (field.hashCode())
			{
				case -34743496:
				{
					if (field.equals("m_gizmo_count")) 
					{
						__temp_executeDef842 = false;
						return ((double) (this.m_gizmo_count) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef842 = false;
						return ((double) (this.type) );
					}
					
					break;
				}
				
				
				case -305188936:
				{
					if (field.equals("m_render_count")) 
					{
						__temp_executeDef842 = false;
						return ((double) (this.m_render_count) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef842) 
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
			boolean __temp_executeDef843 = true;
			switch (field.hashCode())
			{
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef843 = false;
						this.Render();
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef843 = false;
						this.OnBuild();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef843 = false;
						this.Clear();
					}
					
					break;
				}
				
				
				case 2499386:
				{
					if (field.equals("Push")) 
					{
						__temp_executeDef843 = false;
						this.Push(((haxor.math.Color) (dynargs.__get(0)) ), ((haxor.math.Vector4) (dynargs.__get(1)) ), ((haxor.math.Vector4) (dynargs.__get(2)) ), ((haxor.math.Matrix4) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef843) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_gizmo_count");
		baseArr.push("m_render_count");
		baseArr.push("type");
		baseArr.push("material");
		baseArr.push("mesh");
		baseArr.push("data");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


