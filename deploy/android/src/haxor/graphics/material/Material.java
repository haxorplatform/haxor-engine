package haxor.graphics.material;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Material extends haxor.core.Resource
{
	public    Material(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Material(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.material.Material.__hx_ctor_haxor_graphics_material_Material(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_material_Material(haxor.graphics.material.Material __temp_me80648, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me80648, ( (( p_name == null )) ? (haxe.lang.Runtime.toString("")) : (p_name) ));
		__temp_me80648.grab = false;
		if (( p_name == null )) 
		{
			p_name = "";
		}
		
		{
			haxor.context.UID _this = haxor.context.EngineContext.material.mid;
			if (( _this.m_cache.length <= 0 )) 
			{
				__temp_me80648.__cid = _this.m_id++;
			}
			 else 
			{
				__temp_me80648.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		__temp_me80648.m_uniforms = new haxe.root.Array<haxor.graphics.material.MaterialUniform>(new haxor.graphics.material.MaterialUniform[]{});
		__temp_me80648.queue = 1000;
		__temp_me80648.zfunc = 515;
		__temp_me80648.ztest = true;
		__temp_me80648.zwrite = true;
		__temp_me80648.blend = false;
		__temp_me80648.blendSrc = 1;
		__temp_me80648.blendDst = 0;
		__temp_me80648.invert = false;
		__temp_me80648.cull = 2;
		__temp_me80648.lighting = false;
		__temp_me80648.grab = false;
		haxor.context.EngineContext.material.InitializeMaterial(__temp_me80648);
	}
	
	
	public static   haxor.graphics.material.Material Transparent(haxor.graphics.texture.Texture p_texture, java.lang.Object p_ztest, java.lang.Object p_zwrite, java.lang.Object p_double_sided)
	{
		boolean __temp_p_double_sided80641 = ( (( p_double_sided == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_double_sided)) );
		boolean __temp_p_zwrite80640 = ( (( p_zwrite == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_zwrite)) );
		boolean __temp_p_ztest80639 = ( (( p_ztest == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_ztest)) );
		haxor.graphics.material.Material m = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("Transparent"));
		if (__temp_p_double_sided80641) 
		{
			m.cull = 0;
		}
		
		m.SetBlending(770, 771);
		m.set_shader(( (( p_texture == null )) ? (( (( haxor.graphics.material.Shader.m_flat_shader == null )) ? (haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source))) : (haxor.graphics.material.Shader.m_flat_shader) )) : (( (( haxor.graphics.material.Shader.m_flat_texture_shader == null )) ? (haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_texture_source))) : (haxor.graphics.material.Shader.m_flat_texture_shader) )) ));
		m.queue = 2000;
		m.ztest = __temp_p_ztest80639;
		m.zwrite = __temp_p_zwrite80640;
		m.blend = true;
		if (( p_texture != null )) 
		{
			m.SetTexture("DiffuseTexture", p_texture);
		}
		
		return m;
	}
	
	
	public static   haxor.graphics.material.Material AdditiveAlpha(haxor.graphics.texture.Texture p_texture, java.lang.Object p_ztest, java.lang.Object p_zwrite, java.lang.Object p_double_sided)
	{
		boolean __temp_p_double_sided80644 = ( (( p_double_sided == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_double_sided)) );
		boolean __temp_p_zwrite80643 = ( (( p_zwrite == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_zwrite)) );
		boolean __temp_p_ztest80642 = ( (( p_ztest == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_ztest)) );
		haxor.graphics.material.Material m = null;
		{
			haxor.graphics.material.Material m1 = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("Transparent"));
			if (__temp_p_double_sided80644) 
			{
				m1.cull = 0;
			}
			
			m1.SetBlending(770, 771);
			m1.set_shader(( (( haxor.graphics.material.Shader.m_flat_shader == null )) ? (haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source))) : (haxor.graphics.material.Shader.m_flat_shader) ));
			m1.queue = 2000;
			m1.ztest = __temp_p_ztest80642;
			m1.zwrite = __temp_p_zwrite80643;
			m1.blend = true;
			m = m1;
		}
		
		m.set_name("AdditiveAlpha");
		m.SetBlending(770, 1);
		return m;
	}
	
	
	public static   haxor.graphics.material.Material Additive(haxor.graphics.texture.Texture p_texture, java.lang.Object p_ztest, java.lang.Object p_zwrite, java.lang.Object p_double_sided)
	{
		boolean __temp_p_double_sided80647 = ( (( p_double_sided == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_double_sided)) );
		boolean __temp_p_zwrite80646 = ( (( p_zwrite == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_zwrite)) );
		boolean __temp_p_ztest80645 = ( (( p_ztest == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_ztest)) );
		haxor.graphics.material.Material m = null;
		{
			haxor.graphics.material.Material m1 = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("Transparent"));
			if (__temp_p_double_sided80647) 
			{
				m1.cull = 0;
			}
			
			m1.SetBlending(770, 771);
			m1.set_shader(( (( haxor.graphics.material.Shader.m_flat_shader == null )) ? (haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source))) : (haxor.graphics.material.Shader.m_flat_shader) ));
			m1.queue = 2000;
			m1.ztest = __temp_p_ztest80645;
			m1.zwrite = __temp_p_zwrite80646;
			m1.blend = true;
			m = m1;
		}
		
		m.set_name("Additive");
		m.SetBlending(1, 1);
		return m;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.material.Material(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.material.Material(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  boolean ztest;
	
	public  int zfunc;
	
	public  boolean zwrite;
	
	public  boolean blend;
	
	public  int queue;
	
	public  int blendSrc;
	
	public  int blendDst;
	
	public  boolean invert;
	
	public  int cull;
	
	public  boolean lighting;
	
	public  boolean grab;
	
	
	
	public final   haxor.graphics.material.Shader get_shader()
	{
		return this.m_shader;
	}
	
	
	public   haxor.graphics.material.Shader set_shader(haxor.graphics.material.Shader v)
	{
		if (( this.m_shader == v )) 
		{
			return v;
		}
		
		haxor.context.EngineContext.material.UpdateShader(this, this.m_shader, v);
		this.m_shader = v;
		return v;
	}
	
	
	public  haxor.graphics.material.Shader m_shader;
	
	public  haxe.root.Array<haxor.graphics.material.MaterialUniform> m_uniforms;
	
	public   void SetBlending(int p_src, int p_dst)
	{
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	
	
	public   void SetTexture(java.lang.String p_name, haxor.graphics.texture.Texture p_texture)
	{
		if (( p_texture == null )) 
		{
			this.RemoveUniform(p_name);
			return ;
		}
		
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, 1, 1, true);
		if (u.exists) 
		{
			u.SetTexture(p_texture);
		}
		
	}
	
	
	public   void SetMatrix4(java.lang.String p_name, haxor.math.Matrix4 p_matrix4)
	{
		if (( p_matrix4 == null )) 
		{
			this.RemoveUniform(p_name);
			return ;
		}
		
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, 16, 16, true);
		if (u.exists) 
		{
			u.SetMatrix4(p_matrix4);
		}
		
	}
	
	
	public final   void SetVector2(java.lang.String p_name, haxor.math.Vector2 p_v)
	{
		this.SetFloat2(p_name, p_v.x, p_v.y);
	}
	
	
	public final   void SetVector3(java.lang.String p_name, haxor.math.Vector3 p_v)
	{
		this.SetFloat3(p_name, p_v.x, p_v.y, p_v.z);
	}
	
	
	public final   void SetVector4(java.lang.String p_name, haxor.math.Vector4 p_v)
	{
		this.SetFloat4(p_name, p_v.x, p_v.y, p_v.z, p_v.w);
	}
	
	
	public final   void SetColor(java.lang.String p_name, haxor.math.Color p_color)
	{
		this.SetFloat4(p_name, p_color.r, p_color.g, p_color.b, p_color.a);
	}
	
	
	public   void SetFloat(java.lang.String p_name, double p_v)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, 1, 1, true);
		if (u.exists) 
		{
			u.SetFloat(p_v);
		}
		
	}
	
	
	public   void SetFloat2(java.lang.String p_name, double p_x, double p_y)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, 2, 2, true);
		if (u.exists) 
		{
			u.SetFloat2(p_x, p_y);
		}
		
	}
	
	
	public   void SetFloat3(java.lang.String p_name, double p_x, double p_y, double p_z)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, 3, 3, true);
		if (u.exists) 
		{
			u.SetFloat3(p_x, p_y, p_z);
		}
		
	}
	
	
	public   void SetFloat4(java.lang.String p_name, double p_x, double p_y, double p_z, double p_w)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, 4, 4, true);
		if (u.exists) 
		{
			u.SetFloat4(p_x, p_y, p_z, p_w);
		}
		
	}
	
	
	public   void SetFloatArray(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, p_list.length, 1, true);
		if (u.exists) 
		{
			u.SetFloatArray(p_list);
		}
		
	}
	
	
	public   void SetFloat2Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, p_list.length, 2, true);
		if (u.exists) 
		{
			u.SetFloat2Array(p_list);
		}
		
	}
	
	
	public   void SetFloat3Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, p_list.length, 3, true);
		if (u.exists) 
		{
			u.SetFloat3Array(p_list);
		}
		
	}
	
	
	public   void SetFloat4Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, true, p_list.length, 4, true);
		if (u.exists) 
		{
			u.SetFloat4Array(p_list);
		}
		
	}
	
	
	public   void SetInt(java.lang.String p_name, int p_v)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, 1, 1, true);
		if (u.exists) 
		{
			u.SetInt(p_v);
		}
		
	}
	
	
	public   void SetInt2(java.lang.String p_name, int p_x, int p_y)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, 2, 2, true);
		if (u.exists) 
		{
			u.SetInt2(p_x, p_y);
		}
		
	}
	
	
	public   void SetInt3(java.lang.String p_name, int p_x, int p_y, int p_z)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, 3, 3, true);
		if (u.exists) 
		{
			u.SetInt3(p_x, p_y, p_z);
		}
		
	}
	
	
	public   void SetInt4(java.lang.String p_name, int p_x, int p_y, int p_z, int p_w)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, 4, 4, true);
		if (u.exists) 
		{
			u.SetInt4(p_x, p_y, p_z, p_w);
		}
		
	}
	
	
	public   void SetIntArray(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, p_list.length, 1, true);
		if (u.exists) 
		{
			u.SetIntArray(p_list);
		}
		
	}
	
	
	public   void SetInt2Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, p_list.length, 2, true);
		if (u.exists) 
		{
			u.SetInt2Array(p_list);
		}
		
	}
	
	
	public   void SetInt3Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, p_list.length, 3, true);
		if (u.exists) 
		{
			u.SetInt3Array(p_list);
		}
		
	}
	
	
	public   void SetInt4Array(java.lang.String p_name, haxe.root.Array<java.lang.Object> p_list)
	{
		haxor.graphics.material.MaterialUniform u = this.FetchUniform(p_name, false, p_list.length, 4, true);
		if (u.exists) 
		{
			u.SetInt4Array(p_list);
		}
		
	}
	
	
	public   haxor.graphics.material.MaterialUniform GetUniform(java.lang.String p_name)
	{
		{
			int _g1 = 0;
			int _g = this.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.m_uniforms.__get(i).name, p_name)) 
				{
					return this.m_uniforms.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   boolean HasUniform(java.lang.String p_name, java.lang.Object p_check_shader)
	{
		boolean __temp_p_check_shader80638 = ( (( p_check_shader == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_check_shader)) );
		{
			int _g1 = 0;
			int _g = this.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.m_uniforms.__get(i).name, p_name)) 
				{
					if (__temp_p_check_shader80638) 
					{
						return this.m_uniforms.__get(i).exists;
					}
					
					return true;
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public   void RemoveUniform(java.lang.String p_name)
	{
		haxor.graphics.material.MaterialUniform u = null;
		{
			int _g1 = 0;
			int _g = this.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				u = this.m_uniforms.__get(i);
				if (haxe.lang.Runtime.valEq(u.name, p_name)) 
				{
					break;
				}
				
			}
			
		}
		
		if (( u != null )) 
		{
			haxor.context.EngineContext.material.DestroyUniform(this, u);
			this.m_uniforms.remove(u);
		}
		
	}
	
	
	public   haxor.graphics.material.MaterialUniform FetchUniform(java.lang.String p_name, boolean p_is_float, int p_length, int p_offset, boolean p_create)
	{
		haxor.graphics.material.MaterialUniform u = null;
		{
			int _g1 = 0;
			int _g = this.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				u = this.m_uniforms.__get(i);
				if (haxe.lang.Runtime.valEq(u.name, p_name)) 
				{
					if (( u.isFloat == p_is_float )) 
					{
						if (( u.offset == p_offset )) 
						{
							if (( u.data.m_length == p_length )) 
							{
								u.__d = true;
							}
							
							return u;
						}
						
					}
					
					haxor.context.EngineContext.material.DestroyUniform(this, u);
					this.m_uniforms.remove(u);
					break;
				}
				
			}
			
		}
		
		if (p_create) 
		{
			u = new haxor.graphics.material.MaterialUniform(haxe.lang.Runtime.toString(p_name), haxe.lang.Runtime.toBool(p_is_float), ((int) (p_length) ), ((int) (p_offset) ));
			haxor.context.EngineContext.material.CreateUniform(this, u);
			this.m_uniforms.push(u);
		}
		
		return u;
	}
	
	
	@Override public   void OnDestroy()
	{
		haxor.context.MaterialContext _this = haxor.context.EngineContext.material;
		int p = ((int) (haxe.lang.Runtime.toInt(_this.programs.__get(this.__cid))) );
		if (( this.m_shader != null )) 
		{
			haxor.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(_this.vertex_shaders.__get(this.m_shader.__cid))) ));
			haxor.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(_this.fragment_shaders.__get(this.m_shader.__cid))) ));
		}
		
		haxor.graphics.GL.m_gl.DeleteProgram(p);
		{
			int v = this.__cid;
			haxor.context.EngineContext.material.mid.m_cache.push(v);
			int __temp_expr81375 = v;
		}
		
		{
			int _g1 = 0;
			int _g = this.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int v1 = this.m_uniforms.__get(i).__cid;
				_this.uid.m_cache.push(v1);
				int __temp_expr81376 = v1;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81377 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef81377 = false;
						this.cull = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef81377 = false;
						this.zfunc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef81377 = false;
						this.blendDst = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81377 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef81377 = false;
						this.blendSrc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81377) 
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
			boolean __temp_executeDef81378 = true;
			switch (field.hashCode())
			{
				case -159401775:
				{
					if (field.equals("m_uniforms")) 
					{
						__temp_executeDef81378 = false;
						this.m_uniforms = ((haxe.root.Array<haxor.graphics.material.MaterialUniform>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef81378 = false;
						this.ztest = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1502310409:
				{
					if (field.equals("m_shader")) 
					{
						__temp_executeDef81378 = false;
						this.m_shader = ((haxor.graphics.material.Shader) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef81378 = false;
						this.zfunc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef81378 = false;
						this.set_shader(((haxor.graphics.material.Shader) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef81378 = false;
						this.zwrite = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef81378 = false;
						this.grab = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef81378 = false;
						this.blend = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef81378 = false;
						this.lighting = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81378 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef81378 = false;
						this.cull = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef81378 = false;
						this.blendSrc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef81378 = false;
						this.invert = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef81378 = false;
						this.blendDst = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81378) 
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
			boolean __temp_executeDef81379 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef81379 = false;
						return this.ztest;
					}
					
					break;
				}
				
				
				case 1713674682:
				{
					if (field.equals("FetchUniform")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FetchUniform"))) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef81379 = false;
						return this.zfunc;
					}
					
					break;
				}
				
				
				case 1707527280:
				{
					if (field.equals("RemoveUniform")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveUniform"))) );
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef81379 = false;
						return this.zwrite;
					}
					
					break;
				}
				
				
				case -556041766:
				{
					if (field.equals("HasUniform")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("HasUniform"))) );
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef81379 = false;
						return this.blend;
					}
					
					break;
				}
				
				
				case -1551568482:
				{
					if (field.equals("GetUniform")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetUniform"))) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81379 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case 758624530:
				{
					if (field.equals("SetInt4Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt4Array"))) );
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef81379 = false;
						return this.blendSrc;
					}
					
					break;
				}
				
				
				case 729995379:
				{
					if (field.equals("SetInt3Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt3Array"))) );
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef81379 = false;
						return this.blendDst;
					}
					
					break;
				}
				
				
				case 701366228:
				{
					if (field.equals("SetInt2Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt2Array"))) );
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef81379 = false;
						return this.invert;
					}
					
					break;
				}
				
				
				case -100610548:
				{
					if (field.equals("SetIntArray")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetIntArray"))) );
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef81379 = false;
						return this.cull;
					}
					
					break;
				}
				
				
				case -645649017:
				{
					if (field.equals("SetInt4")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt4"))) );
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef81379 = false;
						return this.lighting;
					}
					
					break;
				}
				
				
				case -645649018:
				{
					if (field.equals("SetInt3")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt3"))) );
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef81379 = false;
						return this.grab;
					}
					
					break;
				}
				
				
				case -645649019:
				{
					if (field.equals("SetInt2")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt2"))) );
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef81379 = false;
						return this.get_shader();
					}
					
					break;
				}
				
				
				case -1821942707:
				{
					if (field.equals("SetInt")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt"))) );
					}
					
					break;
				}
				
				
				case 1177098478:
				{
					if (field.equals("get_shader")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_shader"))) );
					}
					
					break;
				}
				
				
				case -1854671297:
				{
					if (field.equals("SetFloat4Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat4Array"))) );
					}
					
					break;
				}
				
				
				case -1181063582:
				{
					if (field.equals("set_shader")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_shader"))) );
					}
					
					break;
				}
				
				
				case -1883300448:
				{
					if (field.equals("SetFloat3Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat3Array"))) );
					}
					
					break;
				}
				
				
				case -1502310409:
				{
					if (field.equals("m_shader")) 
					{
						__temp_executeDef81379 = false;
						return this.m_shader;
					}
					
					break;
				}
				
				
				case -1911929599:
				{
					if (field.equals("SetFloat2Array")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat2Array"))) );
					}
					
					break;
				}
				
				
				case -159401775:
				{
					if (field.equals("m_uniforms")) 
					{
						__temp_executeDef81379 = false;
						return this.m_uniforms;
					}
					
					break;
				}
				
				
				case 230731583:
				{
					if (field.equals("SetFloatArray")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloatArray"))) );
					}
					
					break;
				}
				
				
				case -1578692525:
				{
					if (field.equals("SetBlending")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetBlending"))) );
					}
					
					break;
				}
				
				
				case -2081251270:
				{
					if (field.equals("SetFloat4")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat4"))) );
					}
					
					break;
				}
				
				
				case -745653639:
				{
					if (field.equals("SetTexture")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetTexture"))) );
					}
					
					break;
				}
				
				
				case -2081251271:
				{
					if (field.equals("SetFloat3")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat3"))) );
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetMatrix4"))) );
					}
					
					break;
				}
				
				
				case -2081251272:
				{
					if (field.equals("SetFloat2")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat2"))) );
					}
					
					break;
				}
				
				
				case 1009953965:
				{
					if (field.equals("SetVector2")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector2"))) );
					}
					
					break;
				}
				
				
				case 1456883514:
				{
					if (field.equals("SetFloat")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat"))) );
					}
					
					break;
				}
				
				
				case 1009953966:
				{
					if (field.equals("SetVector3")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector3"))) );
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColor"))) );
					}
					
					break;
				}
				
				
				case 1009953967:
				{
					if (field.equals("SetVector4")) 
					{
						__temp_executeDef81379 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector4"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81379) 
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
			boolean __temp_executeDef81380 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef81380 = false;
						return ((double) (this.cull) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef81380 = false;
						return ((double) (this.zfunc) );
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef81380 = false;
						return ((double) (this.blendDst) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81380 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef81380 = false;
						return ((double) (this.blendSrc) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81380) 
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
			boolean __temp_executeDef81381 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef81381 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1177098478:
				{
					if (field.equals("get_shader")) 
					{
						__temp_executeDef81381 = false;
						return this.get_shader();
					}
					
					break;
				}
				
				
				case 1713674682:
				{
					if (field.equals("FetchUniform")) 
					{
						__temp_executeDef81381 = false;
						return this.FetchUniform(haxe.lang.Runtime.toString(dynargs.__get(0)), haxe.lang.Runtime.toBool(dynargs.__get(1)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), haxe.lang.Runtime.toBool(dynargs.__get(4)));
					}
					
					break;
				}
				
				
				case -1181063582:
				{
					if (field.equals("set_shader")) 
					{
						__temp_executeDef81381 = false;
						return this.set_shader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1707527280:
				{
					if (field.equals("RemoveUniform")) 
					{
						__temp_executeDef81381 = false;
						this.RemoveUniform(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1578692525:
				{
					if (field.equals("SetBlending")) 
					{
						__temp_executeDef81381 = false;
						this.SetBlending(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -556041766:
				{
					if (field.equals("HasUniform")) 
					{
						__temp_executeDef81381 = false;
						return this.HasUniform(haxe.lang.Runtime.toString(dynargs.__get(0)), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -745653639:
				{
					if (field.equals("SetTexture")) 
					{
						__temp_executeDef81381 = false;
						this.SetTexture(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.graphics.texture.Texture) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1551568482:
				{
					if (field.equals("GetUniform")) 
					{
						__temp_executeDef81381 = false;
						return this.GetUniform(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef81381 = false;
						this.SetMatrix4(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.Matrix4) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 758624530:
				{
					if (field.equals("SetInt4Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt4Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1009953965:
				{
					if (field.equals("SetVector2")) 
					{
						__temp_executeDef81381 = false;
						this.SetVector2(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.Vector2) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 729995379:
				{
					if (field.equals("SetInt3Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt3Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1009953966:
				{
					if (field.equals("SetVector3")) 
					{
						__temp_executeDef81381 = false;
						this.SetVector3(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.Vector3) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 701366228:
				{
					if (field.equals("SetInt2Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt2Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1009953967:
				{
					if (field.equals("SetVector4")) 
					{
						__temp_executeDef81381 = false;
						this.SetVector4(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.Vector4) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -100610548:
				{
					if (field.equals("SetIntArray")) 
					{
						__temp_executeDef81381 = false;
						this.SetIntArray(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef81381 = false;
						this.SetColor(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.Color) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -645649017:
				{
					if (field.equals("SetInt4")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt4(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case 1456883514:
				{
					if (field.equals("SetFloat")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat(haxe.lang.Runtime.toString(dynargs.__get(0)), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -645649018:
				{
					if (field.equals("SetInt3")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt3(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -2081251272:
				{
					if (field.equals("SetFloat2")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat2(haxe.lang.Runtime.toString(dynargs.__get(0)), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -645649019:
				{
					if (field.equals("SetInt2")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt2(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -2081251271:
				{
					if (field.equals("SetFloat3")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat3(haxe.lang.Runtime.toString(dynargs.__get(0)), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -1821942707:
				{
					if (field.equals("SetInt")) 
					{
						__temp_executeDef81381 = false;
						this.SetInt(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -2081251270:
				{
					if (field.equals("SetFloat4")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat4(haxe.lang.Runtime.toString(dynargs.__get(0)), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -1854671297:
				{
					if (field.equals("SetFloat4Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat4Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 230731583:
				{
					if (field.equals("SetFloatArray")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloatArray(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1883300448:
				{
					if (field.equals("SetFloat3Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat3Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1911929599:
				{
					if (field.equals("SetFloat2Array")) 
					{
						__temp_executeDef81381 = false;
						this.SetFloat2Array(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81381) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_uniforms");
		baseArr.push("m_shader");
		baseArr.push("shader");
		baseArr.push("grab");
		baseArr.push("lighting");
		baseArr.push("cull");
		baseArr.push("invert");
		baseArr.push("blendDst");
		baseArr.push("blendSrc");
		baseArr.push("queue");
		baseArr.push("blend");
		baseArr.push("zwrite");
		baseArr.push("zfunc");
		baseArr.push("ztest");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


