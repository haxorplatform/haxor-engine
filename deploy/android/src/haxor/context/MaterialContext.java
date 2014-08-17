package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MaterialContext extends haxe.lang.HxObject
{
	public    MaterialContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MaterialContext()
	{
		haxor.context.MaterialContext.__hx_ctor_haxor_context_MaterialContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_MaterialContext(haxor.context.MaterialContext __temp_me27884)
	{
		__temp_me27884.mid = 0;
		__temp_me27884.sid = 0;
		__temp_me27884.zfunc = 515;
		__temp_me27884.ztest = true;
		__temp_me27884.zwrite = true;
		__temp_me27884.blend = false;
		__temp_me27884.blendSrc = 1;
		__temp_me27884.blendDst = 0;
		__temp_me27884.invert = false;
		__temp_me27884.cull = 2;
		int max_buffers = 512;
		int max_programs = 256;
		__temp_me27884.locations = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me27884.programs = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me27884.vertex_shaders = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me27884.fragment_shaders = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < max_programs ))
			{
				int i = _g++;
				haxe.root.Array<java.lang.Object> l = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
				{
					int _g1 = 0;
					while (( _g1 < max_buffers ))
					{
						int j = _g1++;
						l.push(-1);
					}
					
				}
				
				__temp_me27884.locations.push(((haxe.root.Array) (l) ));
				__temp_me27884.programs.push(haxor.platform.graphics.GL.NULL);
				__temp_me27884.vertex_shaders.push(haxor.platform.graphics.GL.NULL);
				__temp_me27884.fragment_shaders.push(haxor.platform.graphics.GL.NULL);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.MaterialContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.MaterialContext();
	}
	
	
	public  int mid;
	
	public  int sid;
	
	public  haxe.root.Array<java.lang.Object> vertex_shaders;
	
	public  haxe.root.Array<java.lang.Object> fragment_shaders;
	
	public  haxor.graphics.material.Shader error_shader;
	
	public  haxe.root.Array<java.lang.Object> programs;
	
	public  haxe.root.Array<haxe.root.Array> locations;
	
	public  haxor.graphics.material.Material current;
	
	public  boolean ztest;
	
	public  int zfunc;
	
	public  boolean zwrite;
	
	public  boolean blend;
	
	public  int queue;
	
	public  int blendSrc;
	
	public  int blendDst;
	
	public  boolean invert;
	
	public  int cull;
	
	public   void Initialize()
	{
		haxor.core.Console.Log("MaterialContext> Initialize.", 3);
		haxor.platform.graphics.GL.m_gl.DepthFunc(515);
		haxor.platform.graphics.GL.m_gl.Enable(2929);
		haxor.platform.graphics.GL.m_gl.DepthMask(true);
		haxor.platform.graphics.GL.m_gl.Disable(3042);
		haxor.platform.graphics.GL.m_gl.BlendFunc(1, 0);
		haxor.platform.graphics.GL.m_gl.Enable(2884);
		haxor.platform.graphics.GL.m_gl.FrontFace(2305);
		haxor.platform.graphics.GL.m_gl.CullFace(1029);
	}
	
	
	public   void UpdateFlags(haxor.graphics.material.Material m)
	{
		if (( m.zfunc != this.zfunc )) 
		{
			this.zfunc = m.zfunc;
			haxor.platform.graphics.GL.m_gl.DepthFunc(this.zfunc);
		}
		
		if (( m.ztest != this.ztest )) 
		{
			this.ztest = m.ztest;
			if (this.ztest) 
			{
				haxor.platform.graphics.GL.m_gl.Enable(2929);
			}
			 else 
			{
				haxor.platform.graphics.GL.m_gl.Disable(2929);
			}
			
		}
		
		if (( m.zwrite != this.zwrite )) 
		{
			this.zwrite = m.zwrite;
			haxor.platform.graphics.GL.m_gl.DepthMask(this.zwrite);
		}
		
		if (( m.blend != this.blend )) 
		{
			this.blend = m.blend;
			if (this.blend) 
			{
				haxor.platform.graphics.GL.m_gl.Enable(3042);
			}
			 else 
			{
				haxor.platform.graphics.GL.m_gl.Disable(3042);
			}
			
		}
		
		boolean blend_change = false;
		if (( m.blendSrc != this.blendSrc )) 
		{
			blend_change = true;
			this.blendSrc = m.blendSrc;
		}
		
		if (( m.blendDst != this.blendDst )) 
		{
			blend_change = true;
			this.blendDst = m.blendDst;
		}
		
		if (blend_change) 
		{
			haxor.platform.graphics.GL.m_gl.BlendFunc(this.blendSrc, this.blendDst);
		}
		
		if (( m.invert != this.invert )) 
		{
			this.invert = m.invert;
			haxor.platform.graphics.GL.m_gl.FrontFace(( (this.invert) ? (2304) : (2305) ));
		}
		
		if (( m.cull != this.cull )) 
		{
			this.cull = m.cull;
			if (( this.cull == 0 )) 
			{
				haxor.platform.graphics.GL.m_gl.Disable(2884);
			}
			 else 
			{
				haxor.platform.graphics.GL.m_gl.Enable(2884);
				haxor.platform.graphics.GL.m_gl.CullFace(( (( this.cull == 1 )) ? (1028) : (1029) ));
			}
			
		}
		
	}
	
	
	public   void InitializeMaterial(haxor.graphics.material.Material m)
	{
		this.programs.__set(m._cid_, haxor.platform.graphics.GL.m_gl.CreateProgram());
		haxor.core.Console.Log(( ( "Material> id[" + ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m._cid_))) ) ) + "]" ), null);
	}
	
	
	public   void InitializeShader(haxor.graphics.material.Shader s)
	{
		if (( s instanceof haxor.graphics.material.UberShader )) 
		{
			return ;
		}
		
		java.lang.String vs_err = "";
		java.lang.String fs_err = "";
		vs_err = this.CreateCompileShader(s, 35633, this.vertex_shaders);
		fs_err = this.CreateCompileShader(s, 35632, this.fragment_shaders);
		if (s.m_hasError) 
		{
			haxor.core.Console.LogError(( ( "Shader> Compile Error @ [" + s.get_name() ) + "]" ), null);
			haxor.core.Console.Log(( "[vertex]\n" + vs_err ), null);
			haxor.core.Console.Log(( "[fragment]\n" + fs_err ), null);
		}
		
		haxor.platform.graphics.GL.m_gl.Assert("Shader> Init");
	}
	
	
	public   java.lang.String CreateCompileShader(haxor.graphics.material.Shader s, int t, haxe.root.Array<java.lang.Object> c)
	{
		int id = haxor.platform.graphics.GL.m_gl.CreateShader(t);
		java.lang.String ss = null;
		if (( t == 35633 )) 
		{
			ss = s.m_vss;
		}
		 else 
		{
			ss = s.m_fss;
		}
		
		c.__set(s._cid_, id);
		haxor.platform.graphics.GL.m_gl.ShaderSource(id, ss);
		haxor.platform.graphics.GL.m_gl.CompileShader(id);
		if (( haxor.platform.graphics.GL.m_gl.GetShaderParameter(id, 35713) == 0 )) 
		{
			s.m_hasError = true;
			return haxor.platform.graphics.GL.m_gl.GetShaderInfoLog(id);
		}
		
		return "";
	}
	
	
	public   void UpdateShader(haxor.graphics.material.Material m, haxor.graphics.material.Shader s0, haxor.graphics.material.Shader s1)
	{
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m._cid_))) );
		int vs_id = 0;
		int fs_id = 0;
		if (( s0 != null )) 
		{
			vs_id = ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s0._cid_))) );
			fs_id = ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s0._cid_))) );
			haxor.platform.graphics.GL.m_gl.DetachShader(p, vs_id);
			haxor.platform.graphics.GL.m_gl.DetachShader(p, fs_id);
		}
		
		if (( s1 != null )) 
		{
			vs_id = ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s1._cid_))) );
			fs_id = ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s1._cid_))) );
			haxor.platform.graphics.GL.m_gl.AttachShader(p, vs_id);
			haxor.platform.graphics.GL.m_gl.AttachShader(p, fs_id);
			haxe.root.Array<java.lang.String> al = haxor.context.EngineContext.mesh.attribs;
			{
				int _g1 = 0;
				int _g = al.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					haxor.platform.graphics.GL.m_gl.BindAttribLocation(p, i, al.__get(i));
				}
				
			}
			
			haxor.platform.graphics.GL.m_gl.LinkProgram(p);
			if (( haxor.platform.graphics.GL.m_gl.GetProgramParameter(p, 35714) == 0 )) 
			{
				haxor.core.Console.LogError(( ( ( ( "Material> [" + m.get_name() ) + "] Link Error @ [" ) + s1.get_name() ) + "]" ), null);
			}
			
			{
				int _g11 = 0;
				int _g2 = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(m._cid_)) )) ).length;
				while (( _g11 < _g2 ))
				{
					int i1 = _g11++;
					((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(m._cid_)) )) ).__set(i1, -1);
				}
				
			}
			
		}
		
	}
	
	
	public   void UpdateMaterial(haxor.graphics.material.Material m)
	{
		{
		}
		
	}
	
	
	public   int GetAttribLocation(haxor.graphics.mesh.MeshAttrib a)
	{
		if (( this.current == null )) 
		{
			return -1;
		}
		
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(this.current._cid_))) );
		int loc = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(this.current._cid_)) )) ).__get(a._cid_))) );
		if (( loc == -1 )) 
		{
			loc = haxor.platform.graphics.GL.m_gl.GetAttribLocation(p, a.m_name);
			if (( loc < 0 )) 
			{
				((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(this.current._cid_)) )) ).__set(a._cid_, -2);
			}
			
		}
		
		return loc;
	}
	
	
	public final   void Bind(haxor.graphics.material.Material m)
	{
		if (( m != this.current )) 
		{
			this.current = m;
			if (( m != null )) 
			{
				this.UpdateFlags(m);
				haxor.platform.graphics.GL.m_gl.UseProgram(((int) (haxe.lang.Runtime.toInt(this.programs.__get(m._cid_))) ));
			}
			
		}
		
	}
	
	
	public final   void Unbind()
	{
		{
		}
		
	}
	
	
	public final   void DestroyMaterial(haxor.graphics.material.Material m)
	{
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m._cid_))) );
		if (( m.m_shader != null )) 
		{
			haxor.platform.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(m.m_shader._cid_))) ));
			haxor.platform.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(m.m_shader._cid_))) ));
		}
		
		haxor.platform.graphics.GL.m_gl.DeleteProgram(p);
	}
	
	
	public final   void DestroyShader(haxor.graphics.material.Shader s)
	{
		haxor.platform.graphics.GL.m_gl.DeleteShader(((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s._cid_))) ));
		haxor.platform.graphics.GL.m_gl.DeleteShader(((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s._cid_))) ));
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28053 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef28053 = false;
						this.cull = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef28053 = false;
						this.mid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef28053 = false;
						this.blendDst = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef28053 = false;
						this.sid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef28053 = false;
						this.blendSrc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef28053 = false;
						this.zfunc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef28053 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28053) 
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
			boolean __temp_executeDef28054 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef28054 = false;
						this.cull = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef28054 = false;
						this.mid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef28054 = false;
						this.invert = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef28054 = false;
						this.sid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef28054 = false;
						this.blendDst = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 45152659:
				{
					if (field.equals("vertex_shaders")) 
					{
						__temp_executeDef28054 = false;
						this.vertex_shaders = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef28054 = false;
						this.blendSrc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1577206209:
				{
					if (field.equals("fragment_shaders")) 
					{
						__temp_executeDef28054 = false;
						this.fragment_shaders = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef28054 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 388549116:
				{
					if (field.equals("error_shader")) 
					{
						__temp_executeDef28054 = false;
						this.error_shader = ((haxor.graphics.material.Shader) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef28054 = false;
						this.blend = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1001082257:
				{
					if (field.equals("programs")) 
					{
						__temp_executeDef28054 = false;
						this.programs = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef28054 = false;
						this.zwrite = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1197189282:
				{
					if (field.equals("locations")) 
					{
						__temp_executeDef28054 = false;
						this.locations = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef28054 = false;
						this.zfunc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef28054 = false;
						this.current = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef28054 = false;
						this.ztest = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28054) 
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
			boolean __temp_executeDef28055 = true;
			switch (field.hashCode())
			{
				case -1654730657:
				{
					if (field.equals("DestroyShader")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DestroyShader"))) );
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef28055 = false;
						return this.mid;
					}
					
					break;
				}
				
				
				case -2521311:
				{
					if (field.equals("DestroyMaterial")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DestroyMaterial"))) );
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef28055 = false;
						return this.sid;
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 45152659:
				{
					if (field.equals("vertex_shaders")) 
					{
						__temp_executeDef28055 = false;
						return this.vertex_shaders;
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
				case -1577206209:
				{
					if (field.equals("fragment_shaders")) 
					{
						__temp_executeDef28055 = false;
						return this.fragment_shaders;
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 388549116:
				{
					if (field.equals("error_shader")) 
					{
						__temp_executeDef28055 = false;
						return this.error_shader;
					}
					
					break;
				}
				
				
				case 167245104:
				{
					if (field.equals("UpdateMaterial")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateMaterial"))) );
					}
					
					break;
				}
				
				
				case -1001082257:
				{
					if (field.equals("programs")) 
					{
						__temp_executeDef28055 = false;
						return this.programs;
					}
					
					break;
				}
				
				
				case -787515858:
				{
					if (field.equals("UpdateShader")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateShader"))) );
					}
					
					break;
				}
				
				
				case -1197189282:
				{
					if (field.equals("locations")) 
					{
						__temp_executeDef28055 = false;
						return this.locations;
					}
					
					break;
				}
				
				
				case -1727603652:
				{
					if (field.equals("CreateCompileShader")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateCompileShader"))) );
					}
					
					break;
				}
				
				
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef28055 = false;
						return this.current;
					}
					
					break;
				}
				
				
				case 192317365:
				{
					if (field.equals("InitializeShader")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("InitializeShader"))) );
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef28055 = false;
						return this.ztest;
					}
					
					break;
				}
				
				
				case 1189134583:
				{
					if (field.equals("InitializeMaterial")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("InitializeMaterial"))) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef28055 = false;
						return this.zfunc;
					}
					
					break;
				}
				
				
				case 1071088414:
				{
					if (field.equals("UpdateFlags")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateFlags"))) );
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef28055 = false;
						return this.zwrite;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef28055 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef28055 = false;
						return this.blend;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef28055 = false;
						return this.cull;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef28055 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef28055 = false;
						return this.invert;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef28055 = false;
						return this.blendSrc;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef28055 = false;
						return this.blendDst;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28055) 
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
			boolean __temp_executeDef28056 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.cull) );
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.mid) );
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.blendDst) );
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.sid) );
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.blendSrc) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.zfunc) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef28056 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28056) 
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
			boolean __temp_executeDef28057 = true;
			switch (field.hashCode())
			{
				case -1654730657:
				{
					if (field.equals("DestroyShader")) 
					{
						__temp_executeDef28057 = false;
						this.DestroyShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef28057 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -2521311:
				{
					if (field.equals("DestroyMaterial")) 
					{
						__temp_executeDef28057 = false;
						this.DestroyMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1071088414:
				{
					if (field.equals("UpdateFlags")) 
					{
						__temp_executeDef28057 = false;
						this.UpdateFlags(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef28057 = false;
						this.Unbind();
					}
					
					break;
				}
				
				
				case 1189134583:
				{
					if (field.equals("InitializeMaterial")) 
					{
						__temp_executeDef28057 = false;
						this.InitializeMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef28057 = false;
						this.Bind(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 192317365:
				{
					if (field.equals("InitializeShader")) 
					{
						__temp_executeDef28057 = false;
						this.InitializeShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef28057 = false;
						return this.GetAttribLocation(((haxor.graphics.mesh.MeshAttrib) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1727603652:
				{
					if (field.equals("CreateCompileShader")) 
					{
						__temp_executeDef28057 = false;
						return this.CreateCompileShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 167245104:
				{
					if (field.equals("UpdateMaterial")) 
					{
						__temp_executeDef28057 = false;
						this.UpdateMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -787515858:
				{
					if (field.equals("UpdateShader")) 
					{
						__temp_executeDef28057 = false;
						this.UpdateShader(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.graphics.material.Shader) (dynargs.__get(1)) ), ((haxor.graphics.material.Shader) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28057) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("cull");
		baseArr.push("invert");
		baseArr.push("blendDst");
		baseArr.push("blendSrc");
		baseArr.push("queue");
		baseArr.push("blend");
		baseArr.push("zwrite");
		baseArr.push("zfunc");
		baseArr.push("ztest");
		baseArr.push("current");
		baseArr.push("locations");
		baseArr.push("programs");
		baseArr.push("error_shader");
		baseArr.push("fragment_shaders");
		baseArr.push("vertex_shaders");
		baseArr.push("sid");
		baseArr.push("mid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


