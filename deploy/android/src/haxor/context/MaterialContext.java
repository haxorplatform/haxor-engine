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
	
	
	public static   void __hx_ctor_haxor_context_MaterialContext(haxor.context.MaterialContext __temp_me164185)
	{
		__temp_me164185.uniform_globals = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"ViewMatrix", "ProjectionMatrix", "WorldMatrix", "Time", "RandomSeed", "RandomTexture", "ScreenTexture", "ScreenDepth", "Ambient", "CameraPosition", "ProjectionMatrixInverse", "ViewMatrixInverse"});
		__temp_me164185.mid = new haxor.context.UID();
		__temp_me164185.sid = new haxor.context.UID();
		__temp_me164185.uid = new haxor.context.UID();
		__temp_me164185.zfunc = 515;
		__temp_me164185.ztest = true;
		__temp_me164185.zwrite = true;
		__temp_me164185.blend = false;
		__temp_me164185.blendSrc = 1;
		__temp_me164185.blendDst = 0;
		__temp_me164185.invert = false;
		__temp_me164185.cull = 2;
		int max_buffers = 512;
		int max_programs = 1024;
		__temp_me164185.locations = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me164185.uniforms = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me164185.programs = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me164185.vertex_shaders = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me164185.fragment_shaders = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me164185.globals = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me164185.camera = new haxe.root.Array<haxor.component.Camera>(new haxor.component.Camera[]{});
		__temp_me164185.transform = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{});
		__temp_me164185.slot = 0;
		__temp_me164185.viewmatrix = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me164185.projmatrix = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < max_programs ))
			{
				int i = _g++;
				haxe.root.Array<java.lang.Object> l = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
				haxe.root.Array<java.lang.Object> ul = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
				{
					int _g1 = 0;
					while (( _g1 < max_buffers ))
					{
						int j = _g1++;
						l.push(-1);
					}
					
				}
				
				{
					int _g11 = 0;
					while (( _g11 < 200 ))
					{
						int j1 = _g11++;
						ul.push(haxor.graphics.GL.INVALID);
					}
					
				}
				
				__temp_me164185.camera.push(null);
				__temp_me164185.transform.push(null);
				__temp_me164185.globals.push(((haxe.root.Array) (new haxe.root.Array<java.lang.String>(new java.lang.String[]{})) ));
				__temp_me164185.locations.push(((haxe.root.Array) (l) ));
				__temp_me164185.uniforms.push(((haxe.root.Array) (ul) ));
				__temp_me164185.programs.push(haxor.graphics.GL.INVALID);
				__temp_me164185.vertex_shaders.push(haxor.graphics.GL.INVALID);
				__temp_me164185.fragment_shaders.push(haxor.graphics.GL.INVALID);
				__temp_me164185.viewmatrix.push(false);
				__temp_me164185.projmatrix.push(false);
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
	
	
	public  haxe.root.Array<java.lang.String> uniform_globals;
	
	public  haxe.root.Array<haxe.root.Array> globals;
	
	public  haxor.context.UID mid;
	
	public  haxor.context.UID sid;
	
	public  haxor.context.UID uid;
	
	public  haxe.root.Array<java.lang.Object> vertex_shaders;
	
	public  haxe.root.Array<java.lang.Object> fragment_shaders;
	
	public  haxor.graphics.material.Shader error_shader;
	
	public  haxe.root.Array<java.lang.Object> programs;
	
	public  haxe.root.Array<haxor.component.Camera> camera;
	
	public  haxe.root.Array<haxor.component.Transform> transform;
	
	public  haxe.root.Array<java.lang.Object> viewmatrix;
	
	public  haxe.root.Array<java.lang.Object> projmatrix;
	
	public  haxe.root.Array<haxe.root.Array> locations;
	
	public  int slot;
	
	public  haxe.root.Array<haxe.root.Array> uniforms;
	
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
		haxor.graphics.GL.m_gl.DepthFunc(515);
		haxor.graphics.GL.m_gl.Enable(2929);
		haxor.graphics.GL.m_gl.DepthMask(true);
		haxor.graphics.GL.m_gl.Disable(3042);
		haxor.graphics.GL.m_gl.BlendFunc(1, 0);
		haxor.graphics.GL.m_gl.Enable(2884);
		haxor.graphics.GL.m_gl.FrontFace(2305);
		haxor.graphics.GL.m_gl.CullFace(1029);
		haxor.graphics.GL.m_gl.Enable(3089);
	}
	
	
	public   void UpdateFlags(haxor.graphics.material.Material m)
	{
		if (( m.zfunc != this.zfunc )) 
		{
			this.zfunc = m.zfunc;
			haxor.graphics.GL.m_gl.DepthFunc(this.zfunc);
		}
		
		if (( m.ztest != this.ztest )) 
		{
			this.ztest = m.ztest;
			if (this.ztest) 
			{
				haxor.graphics.GL.m_gl.Enable(2929);
			}
			 else 
			{
				haxor.graphics.GL.m_gl.Disable(2929);
			}
			
		}
		
		if (( m.zwrite != this.zwrite )) 
		{
			this.zwrite = m.zwrite;
			haxor.graphics.GL.m_gl.DepthMask(this.zwrite);
		}
		
		if (( m.blend != this.blend )) 
		{
			this.blend = m.blend;
			if (this.blend) 
			{
				haxor.graphics.GL.m_gl.Enable(3042);
			}
			 else 
			{
				haxor.graphics.GL.m_gl.Disable(3042);
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
			haxor.graphics.GL.m_gl.BlendFunc(this.blendSrc, this.blendDst);
		}
		
		if (( m.invert != this.invert )) 
		{
			this.invert = m.invert;
			haxor.graphics.GL.m_gl.FrontFace(( (this.invert) ? (2304) : (2305) ));
		}
		
		if (( m.cull != this.cull )) 
		{
			this.cull = m.cull;
			if (( this.cull == 0 )) 
			{
				haxor.graphics.GL.m_gl.Disable(2884);
			}
			 else 
			{
				haxor.graphics.GL.m_gl.Enable(2884);
				haxor.graphics.GL.m_gl.CullFace(( (( this.cull == 1 )) ? (1028) : (1029) ));
			}
			
		}
		
	}
	
	
	public   void InitializeMaterial(haxor.graphics.material.Material m)
	{
		this.programs.__set(m.__cid, haxor.graphics.GL.m_gl.CreateProgram());
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
		
	}
	
	
	public   void CreateUniform(haxor.graphics.material.Material m, haxor.graphics.material.MaterialUniform u)
	{
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m.__cid))) );
		int loc = haxor.graphics.GL.m_gl.GetUniformLocation(p, u.name);
		((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.uniforms.__get(m.__cid)) )) ).__set(u.__cid, loc);
		u.__d = true;
		u.exists = ( loc != haxor.graphics.GL.INVALID );
	}
	
	
	public   void DestroyUniform(haxor.graphics.material.Material m, haxor.graphics.material.MaterialUniform u)
	{
		if (( m != null )) 
		{
			((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.uniforms.__get(m.__cid)) )) ).__set(u.__cid, haxor.graphics.GL.INVALID);
		}
		
		{
			int v = u.__cid;
			haxor.context.EngineContext.material.uid.m_cache.push(v);
			int __temp_expr164811 = v;
		}
		
	}
	
	
	public   java.lang.String CreateCompileShader(haxor.graphics.material.Shader s, int t, haxe.root.Array<java.lang.Object> c)
	{
		int id = haxor.graphics.GL.m_gl.CreateShader(t);
		java.lang.String ss = null;
		if (( t == 35633 )) 
		{
			ss = s.m_vss;
		}
		 else 
		{
			ss = s.m_fss;
		}
		
		c.__set(s.__cid, id);
		haxor.graphics.GL.m_gl.ShaderSource(id, ss);
		haxor.graphics.GL.m_gl.CompileShader(id);
		if (( haxor.graphics.GL.m_gl.GetShaderParameter(id, 35713) == 0 )) 
		{
			s.m_hasError = true;
			return haxor.graphics.GL.m_gl.GetShaderInfoLog(id);
		}
		
		return "";
	}
	
	
	public   void UpdateShader(haxor.graphics.material.Material m, haxor.graphics.material.Shader s0, haxor.graphics.material.Shader s1)
	{
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m.__cid))) );
		int vs_id = 0;
		int fs_id = 0;
		if (( s0 != null )) 
		{
			vs_id = ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s0.__cid))) );
			fs_id = ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s0.__cid))) );
			haxor.graphics.GL.m_gl.DetachShader(p, vs_id);
			haxor.graphics.GL.m_gl.DetachShader(p, fs_id);
		}
		
		if (( s1 != null )) 
		{
			vs_id = ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s1.__cid))) );
			fs_id = ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s1.__cid))) );
			haxor.graphics.GL.m_gl.AttachShader(p, vs_id);
			haxor.graphics.GL.m_gl.AttachShader(p, fs_id);
			haxe.root.Array<java.lang.String> al = haxor.context.EngineContext.mesh.attribs;
			{
				int _g1 = 0;
				int _g = al.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					haxor.graphics.GL.m_gl.BindAttribLocation(p, i, al.__get(i));
				}
				
			}
			
			haxor.graphics.GL.m_gl.LinkProgram(p);
			if (( haxor.graphics.GL.m_gl.GetProgramParameter(p, 35714) == 0 )) 
			{
				haxor.core.Console.LogError(( ( ( ( "Material> [" + m.get_name() ) + "] Link Error @ [" ) + s1.get_name() ) + "]" ), null);
			}
			
			haxe.root.Array<haxor.graphics.material.MaterialUniform> ul = m.m_uniforms;
			{
				int _g11 = 0;
				int _g2 = ul.length;
				while (( _g11 < _g2 ))
				{
					int i1 = _g11++;
					this.CreateUniform(m, ul.__get(i1));
				}
				
			}
			
			{
				int _g12 = 0;
				int _g3 = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(m.__cid)) )) ).length;
				while (( _g12 < _g3 ))
				{
					int i2 = _g12++;
					((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(m.__cid)) )) ).__set(i2, -1);
				}
				
			}
			
		}
		
		haxe.root.Array<java.lang.String> gl = this.uniform_globals;
		int k = 0;
		haxor.math.Matrix4 m4 = null;
		{
			haxor.math.Matrix4 _this = null;
			{
				haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
				_this = _this1.m_m4.__get(_this1.m_nq = ( (( _this1.m_nm4 + 1 )) % _this1.m_m4.length ));
			}
			
			m4 = _this.Set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		}
		
		while (( k < gl.length ))
		{
			java.lang.String un = gl.__get(k);
			if (( haxor.graphics.GL.m_gl.GetUniformLocation(p, un) == haxor.graphics.GL.INVALID )) 
			{
				gl.remove(un);
				continue;
			}
			
			{
				java.lang.String __temp_svar164814 = (un);
				switch (__temp_svar164814.hashCode())
				{
					case 772508280:
					{
						if (__temp_svar164814.equals("Ambient")) 
						{
							haxor.math.Color __temp_stmt164812 = null;
							{
								haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
								__temp_stmt164812 = _this2.m_c.__get(_this2.m_nc = ( (( _this2.m_nc + 1 )) % _this2.m_c.length ));
							}
							
							haxor.math.Color p_color = __temp_stmt164812.Set(1, 1, 1, 1);
							m.SetFloat4(un, p_color.r, p_color.g, p_color.b, p_color.a);
						}
						
						break;
					}
					
					
					case -168262144:
					{
						if (__temp_svar164814.equals("ProjectionMatrixInverse")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case 2606829:
					{
						if (__temp_svar164814.equals("Time")) 
						{
							m.SetFloat(un, 0.0);
						}
						
						break;
					}
					
					
					case -1609016560:
					{
						if (__temp_svar164814.equals("ProjectionMatrix")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case 2109073908:
					{
						if (__temp_svar164814.equals("RandomSeed")) 
						{
							m.SetFloat(un, 0.0);
						}
						
						break;
					}
					
					
					case 1363491178:
					{
						if (__temp_svar164814.equals("ViewMatrixInverse")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case -1846881837:
					{
						if (__temp_svar164814.equals("WorldMatrix")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case -57914650:
					{
						if (__temp_svar164814.equals("ViewMatrix")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case -1625653795:
					{
						if (__temp_svar164814.equals("WorldMatrixInverse")) 
						{
							m.SetMatrix4(un, m4);
						}
						
						break;
					}
					
					
					case -1466001522:
					{
						if (__temp_svar164814.equals("CameraPosition")) 
						{
							haxor.math.Vector3 __temp_stmt164813 = null;
							{
								haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
								__temp_stmt164813 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
							}
							
							haxor.math.Vector3 p_v = __temp_stmt164813.Set(0, 0, 0);
							m.SetFloat3(un, p_v.x, p_v.y, p_v.z);
						}
						
						break;
					}
					
					
				}
				
			}
			
			k++;
		}
		
		this.globals.__set(m.__cid, ((haxe.root.Array) (gl) ));
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
		
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(this.current.__cid))) );
		int loc = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(this.current.__cid)) )) ).__get(a.__cid))) );
		if (( loc == -1 )) 
		{
			loc = haxor.graphics.GL.m_gl.GetAttribLocation(p, a.m_name);
			if (( loc < 0 )) 
			{
				((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.locations.__get(this.current.__cid)) )) ).__set(a.__cid, -2);
			}
			
		}
		
		return loc;
	}
	
	
	public   void Bind(haxor.graphics.material.Material m, haxor.component.Transform t, haxor.component.Camera c)
	{
		boolean material_change = ( m != this.current );
		this.UseMaterial(m);
		this.UpdateMaterialUniforms(t, c, material_change);
	}
	
	
	public   void UseMaterial(haxor.graphics.material.Material m)
	{
		if (( m != this.current )) 
		{
			this.Unbind();
			this.current = m;
			if (( m != null )) 
			{
				this.viewmatrix.__set(m.__cid, false);
				this.projmatrix.__set(m.__cid, false);
				int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m.__cid))) );
				this.UpdateFlags(m);
				haxor.graphics.GL.m_gl.UseProgram(p);
			}
			
		}
		
	}
	
	
	public   void UpdateMaterialUniforms(haxor.component.Transform t, haxor.component.Camera c, boolean p_changed)
	{
		if (( this.current != null )) 
		{
			{
				if (( c == null )) 
				{
					this.viewmatrix.__set(this.current.__cid, false);
				}
				 else 
				{
					this.viewmatrix.__set(this.current.__cid, c.m_view_uniform_dirty);
				}
				
				if (( c == null )) 
				{
					this.projmatrix.__set(this.current.__cid, false);
				}
				 else 
				{
					this.projmatrix.__set(this.current.__cid, c.m_proj_uniform_dirty);
				}
				
			}
			
			if (( t == null )) 
			{
				t = haxor.component.Transform.get_root();
			}
			 else 
			{
				t = t;
			}
			
			boolean ut = ( t != this.transform.__get(this.current.__cid) );
			if (( this.transform.__get(this.current.__cid) != null )) 
			{
				this.transform.__get(this.current.__cid).m_uniform_dirty = false;
			}
			
			this.transform.__set(this.current.__cid, t);
			ut = ( ut || t.m_uniform_dirty );
			boolean uc = ( ( c != this.camera.__get(this.current.__cid) ) && ( c != null ) );
			boolean ucv = ( haxe.lang.Runtime.toBool(this.viewmatrix.__get(this.current.__cid)) || uc );
			boolean ucp = ( haxe.lang.Runtime.toBool(this.projmatrix.__get(this.current.__cid)) || uc );
			if (( c != null )) 
			{
				this.camera.__set(this.current.__cid, c);
			}
			
			this.UploadUniforms(ut, ucv, ucp, t, c);
			this.viewmatrix.__set(this.current.__cid, false);
			this.projmatrix.__set(this.current.__cid, false);
		}
		
	}
	
	
	public   void UploadUniforms(boolean ut, boolean ucv, boolean ucp, haxor.component.Transform t, haxor.component.Camera c)
	{
		haxe.root.Array<haxor.graphics.material.MaterialUniform> ul = this.current.m_uniforms;
		{
			int _g1 = 0;
			int _g = ul.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.graphics.material.MaterialUniform u = ul.__get(i);
				this.UploadGlobalUniform(u, ut, ucv, ucp, t, c);
				this.UploadUniform(this.current, u);
			}
			
		}
		
	}
	
	
	public   void UploadUniform(haxor.graphics.material.Material m, haxor.graphics.material.MaterialUniform u)
	{
		int loc = 0;
		loc = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.uniforms.__get(m.__cid)) )) ).__get(u.__cid))) );
		if (( loc == haxor.graphics.GL.INVALID )) 
		{
			return ;
		}
		
		if (( u.texture != null )) 
		{
			haxor.context.EngineContext.texture.Activate(u.texture, u.texture.__slot);
		}
		
		if ( ! (u.__d) ) 
		{
			return ;
		}
		
		this.ApplyUniform(loc, u);
	}
	
	
	public   void ApplyUniform(int loc, haxor.graphics.material.MaterialUniform u)
	{
		int off = u.offset;
		if (u.isFloat) 
		{
			haxor.io.FloatArray b = ((haxor.io.FloatArray) (u.data) );
			switch (off)
			{
				case 1:
				{
					double p_x = b.Get(0);
					haxor.graphics.GL.m_gl.Uniform1f(loc, p_x);
					break;
				}
				
				
				case 2:
				{
					double p_x1 = b.Get(0);
					double p_y = b.Get(1);
					haxor.graphics.GL.m_gl.Uniform2f(loc, p_x1, p_y);
					break;
				}
				
				
				case 3:
				{
					double p_x2 = b.Get(0);
					double p_y1 = b.Get(1);
					double p_z = b.Get(2);
					haxor.graphics.GL.m_gl.Uniform3f(loc, p_x2, p_y1, p_z);
					break;
				}
				
				
				case 4:
				{
					double p_x3 = b.Get(0);
					double p_y2 = b.Get(1);
					double p_z1 = b.Get(2);
					double p_w = b.Get(3);
					haxor.graphics.GL.m_gl.Uniform4f(loc, p_x3, p_y2, p_z1, p_w);
					break;
				}
				
				
				case 16:
				{
					haxor.graphics.GL.m_gl.UniformMatrix4fv(loc, false, b);
					break;
				}
				
				
				default:
				{
					haxor.graphics.GL.m_gl.Uniform1fv(loc, b);
					break;
				}
				
			}
			
		}
		 else 
		{
			haxor.io.Int32Array b1 = ((haxor.io.Int32Array) (u.data) );
			switch (off)
			{
				case 1:
				{
					int p_x4 = b1.Get(0);
					haxor.graphics.GL.m_gl.Uniform1i(loc, p_x4);
					break;
				}
				
				
				case 2:
				{
					int p_x5 = b1.Get(0);
					int p_y3 = b1.Get(1);
					haxor.graphics.GL.m_gl.Uniform2i(loc, p_x5, p_y3);
					break;
				}
				
				
				case 3:
				{
					int p_x6 = b1.Get(0);
					int p_y4 = b1.Get(1);
					int p_z2 = b1.Get(2);
					haxor.graphics.GL.m_gl.Uniform3i(loc, p_x6, p_y4, p_z2);
					break;
				}
				
				
				case 4:
				{
					int p_x7 = b1.Get(0);
					int p_y5 = b1.Get(1);
					int p_z3 = b1.Get(2);
					int p_w1 = b1.Get(3);
					haxor.graphics.GL.m_gl.Uniform4i(loc, p_x7, p_y5, p_z3, p_w1);
					break;
				}
				
				
				default:
				{
					haxor.graphics.GL.m_gl.Uniform1iv(loc, b1);
					break;
				}
				
			}
			
		}
		
		u.__d = false;
	}
	
	
	public   void UploadGlobalUniform(haxor.graphics.material.MaterialUniform u, boolean ut, boolean ucv, boolean ucp, haxor.component.Transform t, haxor.component.Camera c)
	{
		java.lang.String _g = u.name;
		{
			java.lang.String __temp_svar164818 = (_g);
			switch (__temp_svar164818.hashCode())
			{
				case 772508280:
				{
					if (__temp_svar164818.equals("Ambient")) 
					{
						haxor.math.Color p_color = haxor.component.Light.ambient;
						u.SetFloat4(p_color.r, p_color.g, p_color.b, p_color.a);
					}
					
					break;
				}
				
				
				case -168262144:
				{
					if (__temp_svar164818.equals("ProjectionMatrixInverse")) 
					{
						if (ucp) 
						{
							haxor.math.Matrix4 __temp_stmt164817 = null;
							{
								c.UpdateProjection();
								__temp_stmt164817 = c.m_projectionMatrixInverse;
							}
							
							u.SetMatrix4(__temp_stmt164817);
						}
						
					}
					
					break;
				}
				
				
				case 2606829:
				{
					if (__temp_svar164818.equals("Time")) 
					{
						u.SetFloat(haxor.core.Time.m_elapsed);
					}
					
					break;
				}
				
				
				case -1609016560:
				{
					if (__temp_svar164818.equals("ProjectionMatrix")) 
					{
						if (ucp) 
						{
							haxor.math.Matrix4 __temp_stmt164816 = null;
							{
								c.UpdateProjection();
								__temp_stmt164816 = c.m_projectionMatrix;
							}
							
							u.SetMatrix4(__temp_stmt164816);
						}
						
					}
					
					break;
				}
				
				
				case 2109073908:
				{
					if (__temp_svar164818.equals("RandomSeed")) 
					{
						u.SetFloat(java.lang.Math.random());
					}
					
					break;
				}
				
				
				case 1363491178:
				{
					if (__temp_svar164818.equals("ViewMatrixInverse")) 
					{
						if (ucv) 
						{
							u.SetMatrix4(c.m_entity.m_transform.get_WorldMatrix());
						}
						
					}
					
					break;
				}
				
				
				case -1846881837:
				{
					if (__temp_svar164818.equals("WorldMatrix")) 
					{
						if (ut) 
						{
							u.SetMatrix4(t.get_WorldMatrix());
						}
						
					}
					
					break;
				}
				
				
				case -57914650:
				{
					if (__temp_svar164818.equals("ViewMatrix")) 
					{
						if (ucv) 
						{
							u.SetMatrix4(c.m_entity.m_transform.get_WorldMatrixInverse());
						}
						
					}
					
					break;
				}
				
				
				case -1625653795:
				{
					if (__temp_svar164818.equals("WorldMatrixInverse")) 
					{
						if (ut) 
						{
							u.SetMatrix4(t.get_WorldMatrixInverse());
						}
						
					}
					
					break;
				}
				
				
				case -1466001522:
				{
					if (__temp_svar164818.equals("CameraPosition")) 
					{
						if (ucv) 
						{
							haxor.math.Vector3 p_v = c.m_entity.m_transform.get_position();
							u.SetFloat3(p_v.x, p_v.y, p_v.z);
						}
						
					}
					
					break;
				}
				
				
			}
			
		}
		
	}
	
	
	public   void Unbind()
	{
		{
		}
		
	}
	
	
	public   void DestroyMaterial(haxor.graphics.material.Material m)
	{
		int p = ((int) (haxe.lang.Runtime.toInt(this.programs.__get(m.__cid))) );
		if (( m.m_shader != null )) 
		{
			haxor.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(m.m_shader.__cid))) ));
			haxor.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(m.m_shader.__cid))) ));
		}
		
		haxor.graphics.GL.m_gl.DeleteProgram(p);
		{
			int v = m.__cid;
			haxor.context.EngineContext.material.mid.m_cache.push(v);
			int __temp_expr164820 = v;
		}
		
		{
			int _g1 = 0;
			int _g = m.m_uniforms.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int v1 = m.m_uniforms.__get(i).__cid;
				this.uid.m_cache.push(v1);
				int __temp_expr164821 = v1;
			}
			
		}
		
	}
	
	
	public   void DestroyShader(haxor.graphics.material.Shader s)
	{
		haxor.graphics.GL.m_gl.DeleteShader(((int) (haxe.lang.Runtime.toInt(this.vertex_shaders.__get(s.__cid))) ));
		haxor.graphics.GL.m_gl.DeleteShader(((int) (haxe.lang.Runtime.toInt(this.fragment_shaders.__get(s.__cid))) ));
		{
			int v = s.__cid;
			haxor.context.EngineContext.material.sid.m_cache.push(v);
			int __temp_expr164822 = v;
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164823 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef164823 = false;
						this.cull = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3533310:
				{
					if (field.equals("slot")) 
					{
						__temp_executeDef164823 = false;
						this.slot = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef164823 = false;
						this.blendDst = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef164823 = false;
						this.zfunc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef164823 = false;
						this.blendSrc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef164823 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164823) 
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
			boolean __temp_executeDef164824 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef164824 = false;
						this.cull = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 266468773:
				{
					if (field.equals("uniform_globals")) 
					{
						__temp_executeDef164824 = false;
						this.uniform_globals = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef164824 = false;
						this.invert = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 121073968:
				{
					if (field.equals("globals")) 
					{
						__temp_executeDef164824 = false;
						this.globals = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef164824 = false;
						this.blendDst = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef164824 = false;
						this.mid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef164824 = false;
						this.blendSrc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef164824 = false;
						this.sid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef164824 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 115792:
				{
					if (field.equals("uid")) 
					{
						__temp_executeDef164824 = false;
						this.uid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef164824 = false;
						this.blend = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 45152659:
				{
					if (field.equals("vertex_shaders")) 
					{
						__temp_executeDef164824 = false;
						this.vertex_shaders = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef164824 = false;
						this.zwrite = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1577206209:
				{
					if (field.equals("fragment_shaders")) 
					{
						__temp_executeDef164824 = false;
						this.fragment_shaders = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef164824 = false;
						this.zfunc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 388549116:
				{
					if (field.equals("error_shader")) 
					{
						__temp_executeDef164824 = false;
						this.error_shader = ((haxor.graphics.material.Shader) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef164824 = false;
						this.ztest = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1001082257:
				{
					if (field.equals("programs")) 
					{
						__temp_executeDef164824 = false;
						this.programs = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef164824 = false;
						this.current = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1367751899:
				{
					if (field.equals("camera")) 
					{
						__temp_executeDef164824 = false;
						this.camera = ((haxe.root.Array<haxor.component.Camera>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -304784065:
				{
					if (field.equals("uniforms")) 
					{
						__temp_executeDef164824 = false;
						this.uniforms = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef164824 = false;
						this.transform = ((haxe.root.Array<haxor.component.Transform>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3533310:
				{
					if (field.equals("slot")) 
					{
						__temp_executeDef164824 = false;
						this.slot = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1135246682:
				{
					if (field.equals("viewmatrix")) 
					{
						__temp_executeDef164824 = false;
						this.viewmatrix = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1197189282:
				{
					if (field.equals("locations")) 
					{
						__temp_executeDef164824 = false;
						this.locations = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1742765730:
				{
					if (field.equals("projmatrix")) 
					{
						__temp_executeDef164824 = false;
						this.projmatrix = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164824) 
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
			boolean __temp_executeDef164825 = true;
			switch (field.hashCode())
			{
				case -1654730657:
				{
					if (field.equals("DestroyShader")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DestroyShader"))) );
					}
					
					break;
				}
				
				
				case 266468773:
				{
					if (field.equals("uniform_globals")) 
					{
						__temp_executeDef164825 = false;
						return this.uniform_globals;
					}
					
					break;
				}
				
				
				case -2521311:
				{
					if (field.equals("DestroyMaterial")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DestroyMaterial"))) );
					}
					
					break;
				}
				
				
				case 121073968:
				{
					if (field.equals("globals")) 
					{
						__temp_executeDef164825 = false;
						return this.globals;
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef164825 = false;
						return this.mid;
					}
					
					break;
				}
				
				
				case 833557488:
				{
					if (field.equals("UploadGlobalUniform")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UploadGlobalUniform"))) );
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef164825 = false;
						return this.sid;
					}
					
					break;
				}
				
				
				case -256497018:
				{
					if (field.equals("ApplyUniform")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ApplyUniform"))) );
					}
					
					break;
				}
				
				
				case 115792:
				{
					if (field.equals("uid")) 
					{
						__temp_executeDef164825 = false;
						return this.uid;
					}
					
					break;
				}
				
				
				case 1603207251:
				{
					if (field.equals("UploadUniform")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UploadUniform"))) );
					}
					
					break;
				}
				
				
				case 45152659:
				{
					if (field.equals("vertex_shaders")) 
					{
						__temp_executeDef164825 = false;
						return this.vertex_shaders;
					}
					
					break;
				}
				
				
				case -1840182656:
				{
					if (field.equals("UploadUniforms")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UploadUniforms"))) );
					}
					
					break;
				}
				
				
				case -1577206209:
				{
					if (field.equals("fragment_shaders")) 
					{
						__temp_executeDef164825 = false;
						return this.fragment_shaders;
					}
					
					break;
				}
				
				
				case 1605863055:
				{
					if (field.equals("UpdateMaterialUniforms")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateMaterialUniforms"))) );
					}
					
					break;
				}
				
				
				case 388549116:
				{
					if (field.equals("error_shader")) 
					{
						__temp_executeDef164825 = false;
						return this.error_shader;
					}
					
					break;
				}
				
				
				case -1046822994:
				{
					if (field.equals("UseMaterial")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UseMaterial"))) );
					}
					
					break;
				}
				
				
				case -1001082257:
				{
					if (field.equals("programs")) 
					{
						__temp_executeDef164825 = false;
						return this.programs;
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
				case -1367751899:
				{
					if (field.equals("camera")) 
					{
						__temp_executeDef164825 = false;
						return this.camera;
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef164825 = false;
						return this.transform;
					}
					
					break;
				}
				
				
				case 167245104:
				{
					if (field.equals("UpdateMaterial")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateMaterial"))) );
					}
					
					break;
				}
				
				
				case -1135246682:
				{
					if (field.equals("viewmatrix")) 
					{
						__temp_executeDef164825 = false;
						return this.viewmatrix;
					}
					
					break;
				}
				
				
				case -787515858:
				{
					if (field.equals("UpdateShader")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateShader"))) );
					}
					
					break;
				}
				
				
				case -1742765730:
				{
					if (field.equals("projmatrix")) 
					{
						__temp_executeDef164825 = false;
						return this.projmatrix;
					}
					
					break;
				}
				
				
				case -1727603652:
				{
					if (field.equals("CreateCompileShader")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateCompileShader"))) );
					}
					
					break;
				}
				
				
				case -1197189282:
				{
					if (field.equals("locations")) 
					{
						__temp_executeDef164825 = false;
						return this.locations;
					}
					
					break;
				}
				
				
				case -2097770374:
				{
					if (field.equals("DestroyUniform")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DestroyUniform"))) );
					}
					
					break;
				}
				
				
				case 3533310:
				{
					if (field.equals("slot")) 
					{
						__temp_executeDef164825 = false;
						return this.slot;
					}
					
					break;
				}
				
				
				case -1536414472:
				{
					if (field.equals("CreateUniform")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateUniform"))) );
					}
					
					break;
				}
				
				
				case -304784065:
				{
					if (field.equals("uniforms")) 
					{
						__temp_executeDef164825 = false;
						return this.uniforms;
					}
					
					break;
				}
				
				
				case 192317365:
				{
					if (field.equals("InitializeShader")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("InitializeShader"))) );
					}
					
					break;
				}
				
				
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef164825 = false;
						return this.current;
					}
					
					break;
				}
				
				
				case 1189134583:
				{
					if (field.equals("InitializeMaterial")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("InitializeMaterial"))) );
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef164825 = false;
						return this.ztest;
					}
					
					break;
				}
				
				
				case 1071088414:
				{
					if (field.equals("UpdateFlags")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateFlags"))) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef164825 = false;
						return this.zfunc;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef164825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef164825 = false;
						return this.zwrite;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef164825 = false;
						return this.cull;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef164825 = false;
						return this.blend;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef164825 = false;
						return this.invert;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef164825 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef164825 = false;
						return this.blendDst;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef164825 = false;
						return this.blendSrc;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164825) 
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
			boolean __temp_executeDef164826 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.cull) );
					}
					
					break;
				}
				
				
				case 3533310:
				{
					if (field.equals("slot")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.slot) );
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.blendDst) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.zfunc) );
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.blendSrc) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef164826 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164826) 
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
			boolean __temp_executeDef164827 = true;
			switch (field.hashCode())
			{
				case -1654730657:
				{
					if (field.equals("DestroyShader")) 
					{
						__temp_executeDef164827 = false;
						this.DestroyShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef164827 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -2521311:
				{
					if (field.equals("DestroyMaterial")) 
					{
						__temp_executeDef164827 = false;
						this.DestroyMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1071088414:
				{
					if (field.equals("UpdateFlags")) 
					{
						__temp_executeDef164827 = false;
						this.UpdateFlags(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef164827 = false;
						this.Unbind();
					}
					
					break;
				}
				
				
				case 1189134583:
				{
					if (field.equals("InitializeMaterial")) 
					{
						__temp_executeDef164827 = false;
						this.InitializeMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 833557488:
				{
					if (field.equals("UploadGlobalUniform")) 
					{
						__temp_executeDef164827 = false;
						this.UploadGlobalUniform(((haxor.graphics.material.MaterialUniform) (dynargs.__get(0)) ), haxe.lang.Runtime.toBool(dynargs.__get(1)), haxe.lang.Runtime.toBool(dynargs.__get(2)), haxe.lang.Runtime.toBool(dynargs.__get(3)), ((haxor.component.Transform) (dynargs.__get(4)) ), ((haxor.component.Camera) (dynargs.__get(5)) ));
					}
					
					break;
				}
				
				
				case 192317365:
				{
					if (field.equals("InitializeShader")) 
					{
						__temp_executeDef164827 = false;
						this.InitializeShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -256497018:
				{
					if (field.equals("ApplyUniform")) 
					{
						__temp_executeDef164827 = false;
						this.ApplyUniform(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.graphics.material.MaterialUniform) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1536414472:
				{
					if (field.equals("CreateUniform")) 
					{
						__temp_executeDef164827 = false;
						this.CreateUniform(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.graphics.material.MaterialUniform) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1603207251:
				{
					if (field.equals("UploadUniform")) 
					{
						__temp_executeDef164827 = false;
						this.UploadUniform(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.graphics.material.MaterialUniform) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -2097770374:
				{
					if (field.equals("DestroyUniform")) 
					{
						__temp_executeDef164827 = false;
						this.DestroyUniform(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.graphics.material.MaterialUniform) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1840182656:
				{
					if (field.equals("UploadUniforms")) 
					{
						__temp_executeDef164827 = false;
						this.UploadUniforms(haxe.lang.Runtime.toBool(dynargs.__get(0)), haxe.lang.Runtime.toBool(dynargs.__get(1)), haxe.lang.Runtime.toBool(dynargs.__get(2)), ((haxor.component.Transform) (dynargs.__get(3)) ), ((haxor.component.Camera) (dynargs.__get(4)) ));
					}
					
					break;
				}
				
				
				case -1727603652:
				{
					if (field.equals("CreateCompileShader")) 
					{
						__temp_executeDef164827 = false;
						return this.CreateCompileShader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1605863055:
				{
					if (field.equals("UpdateMaterialUniforms")) 
					{
						__temp_executeDef164827 = false;
						this.UpdateMaterialUniforms(((haxor.component.Transform) (dynargs.__get(0)) ), ((haxor.component.Camera) (dynargs.__get(1)) ), haxe.lang.Runtime.toBool(dynargs.__get(2)));
					}
					
					break;
				}
				
				
				case -787515858:
				{
					if (field.equals("UpdateShader")) 
					{
						__temp_executeDef164827 = false;
						this.UpdateShader(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.graphics.material.Shader) (dynargs.__get(1)) ), ((haxor.graphics.material.Shader) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -1046822994:
				{
					if (field.equals("UseMaterial")) 
					{
						__temp_executeDef164827 = false;
						this.UseMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 167245104:
				{
					if (field.equals("UpdateMaterial")) 
					{
						__temp_executeDef164827 = false;
						this.UpdateMaterial(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef164827 = false;
						this.Bind(((haxor.graphics.material.Material) (dynargs.__get(0)) ), ((haxor.component.Transform) (dynargs.__get(1)) ), ((haxor.component.Camera) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef164827 = false;
						return this.GetAttribLocation(((haxor.graphics.mesh.MeshAttrib) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164827) 
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
		baseArr.push("uniforms");
		baseArr.push("slot");
		baseArr.push("locations");
		baseArr.push("projmatrix");
		baseArr.push("viewmatrix");
		baseArr.push("transform");
		baseArr.push("camera");
		baseArr.push("programs");
		baseArr.push("error_shader");
		baseArr.push("fragment_shaders");
		baseArr.push("vertex_shaders");
		baseArr.push("uid");
		baseArr.push("sid");
		baseArr.push("mid");
		baseArr.push("globals");
		baseArr.push("uniform_globals");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


