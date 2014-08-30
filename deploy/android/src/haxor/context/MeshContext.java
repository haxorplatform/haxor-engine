package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshContext extends haxe.lang.HxObject
{
	public    MeshContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MeshContext()
	{
		haxor.context.MeshContext.__hx_ctor_haxor_context_MeshContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_MeshContext(haxor.context.MeshContext __temp_me151343)
	{
		__temp_me151343.attribs = new haxe.root.Array<java.lang.String>(new java.lang.String[]{"vertex", "normal", "uv0", "uv1", "uv2", "color", "weight", "index"});
		__temp_me151343.aid = new haxor.context.UID();
		__temp_me151343.mid = new haxor.context.UID();
		__temp_me151343.buffers = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me151343.activated = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 32 ))
			{
				int i = _g++;
				__temp_me151343.activated.push(false);
			}
			
		}
		
		int max_buffers = 512;
		{
			int _g1 = 0;
			while (( _g1 < max_buffers ))
			{
				int i1 = _g1++;
				__temp_me151343.buffers.push(haxor.graphics.GL.INVALID);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.MeshContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.MeshContext();
	}
	
	
	public  haxor.context.UID aid;
	
	public  haxor.context.UID mid;
	
	public  haxe.root.Array<java.lang.String> attribs;
	
	public  haxe.root.Array<java.lang.Object> buffers;
	
	public  haxe.root.Array<java.lang.Object> activated;
	
	public  int active_max;
	
	public  haxor.graphics.mesh.Mesh current;
	
	public   void Initialize()
	{
		haxor.core.Console.Log("MeshContext> Initialize.", 3);
	}
	
	
	public final   void Bind(haxor.graphics.mesh.Mesh p_mesh)
	{
		if (( p_mesh != this.current )) 
		{
			this.current = p_mesh;
			haxor.graphics.mesh.MeshAttrib a = null;
			if (( this.current != null )) 
			{
				haxe.root.Array<haxor.graphics.mesh.MeshAttrib> al = this.current.m_attribs;
				int id = 0;
				int type = 0;
				boolean has_color = false;
				{
					int _g1 = 0;
					int _g = al.length;
					while (( _g1 < _g ))
					{
						int i = _g1++;
						a = al.__get(i);
						int loc = a._loc_;
						if (( loc == 5 )) 
						{
							has_color = true;
						}
						
						if (( loc < 0 )) 
						{
							loc = haxor.context.EngineContext.material.GetAttribLocation(a);
							if (( loc < 0 )) 
							{
								continue;
							}
							
						}
						
						type = 5126;
						if ( ! (haxe.lang.Runtime.toBool(this.activated.__get(loc))) ) 
						{
							this.activated.__set(loc, true);
							this.active_max = ((int) (java.lang.Math.max(((double) (this.active_max) ), ((double) (loc) ))) );
							haxor.graphics.GL.m_gl.EnableVertexAttrib(loc);
						}
						
						haxor.graphics.GL.m_gl.BindBuffer(34962, ((int) (haxe.lang.Runtime.toInt(this.buffers.__get(a.__cid))) ));
						haxor.graphics.GL.m_gl.VertexAttribPointer(loc, a.offset, type, false, 0, 0);
					}
					
				}
				
				if ( ! (has_color) ) 
				{
					if (haxe.lang.Runtime.toBool(this.activated.__get(5))) 
					{
						haxor.graphics.GL.m_gl.DisableVertexAttrib(5);
						this.activated.__set(5, false);
					}
					
					haxor.graphics.GL.m_gl.VertexAttrib4f(5, 1.0, 1.0, 1.0, 1.0);
				}
				
				if (this.current.m_indexed) 
				{
					a = this.current.m_topology_attrib;
					haxor.graphics.GL.m_gl.BindBuffer(34963, ((int) (haxe.lang.Runtime.toInt(this.buffers.__get(a.__cid))) ));
				}
				
			}
			
		}
		
	}
	
	
	public final   void Unbind()
	{
		{
		}
		
	}
	
	
	public final   void Draw(haxor.graphics.mesh.Mesh m)
	{
		if (m.m_indexed) 
		{
			haxor.graphics.GL.m_gl.DrawElements(m.primitive, m.m_topology_attrib.data.m_length, 5123, 0);
		}
		 else 
		{
			haxor.graphics.GL.m_gl.DrawArrays(m.primitive, 0, m.m_vcount);
		}
		
	}
	
	
	public   void RemoveAttrib(haxor.graphics.mesh.MeshAttrib p_attrib)
	{
		int id = ((int) (haxe.lang.Runtime.toInt(this.buffers.__get(p_attrib.__cid))) );
		if (( id == haxor.graphics.GL.INVALID )) 
		{
			return ;
		}
		
		haxor.graphics.GL.m_gl.DeleteBuffer(id);
		this.buffers.__set(p_attrib.__cid, haxor.graphics.GL.INVALID);
		{
			int v = p_attrib.__cid;
			this.aid.m_cache.push(v);
			int __temp_expr152047 = v;
		}
		
	}
	
	
	public   void UpdateAttrib(haxor.graphics.mesh.MeshAttrib a, int p_mode, boolean p_is_index)
	{
		int id = ((int) (haxe.lang.Runtime.toInt(this.buffers.__get(a.__cid))) );
		int target_flag = 0;
		if (p_is_index) 
		{
			target_flag = 34963;
		}
		 else 
		{
			target_flag = 34962;
		}
		
		a._loc_ = this.attribs.indexOf(a.m_name, null);
		if (( id == haxor.graphics.GL.INVALID )) 
		{
			id = haxor.graphics.GL.m_gl.CreateBuffer();
			this.buffers.__set(a.__cid, id);
		}
		
		haxor.graphics.GL.m_gl.BindBuffer(target_flag, id);
		haxor.graphics.GL.m_gl.BufferData(target_flag, a.data, p_mode);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152048 = true;
			switch (field.hashCode())
			{
				case 2044289195:
				{
					if (field.equals("active_max")) 
					{
						__temp_executeDef152048 = false;
						this.active_max = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152048) 
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
			boolean __temp_executeDef152049 = true;
			switch (field.hashCode())
			{
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef152049 = false;
						this.current = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef152049 = false;
						this.aid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2044289195:
				{
					if (field.equals("active_max")) 
					{
						__temp_executeDef152049 = false;
						this.active_max = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef152049 = false;
						this.mid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 204392913:
				{
					if (field.equals("activated")) 
					{
						__temp_executeDef152049 = false;
						this.activated = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef152049 = false;
						this.attribs = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 227996723:
				{
					if (field.equals("buffers")) 
					{
						__temp_executeDef152049 = false;
						this.buffers = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152049) 
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
			boolean __temp_executeDef152050 = true;
			switch (field.hashCode())
			{
				case -1291178733:
				{
					if (field.equals("UpdateAttrib")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateAttrib"))) );
					}
					
					break;
				}
				
				
				case 96572:
				{
					if (field.equals("aid")) 
					{
						__temp_executeDef152050 = false;
						return this.aid;
					}
					
					break;
				}
				
				
				case -1204358002:
				{
					if (field.equals("RemoveAttrib")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveAttrib"))) );
					}
					
					break;
				}
				
				
				case 108104:
				{
					if (field.equals("mid")) 
					{
						__temp_executeDef152050 = false;
						return this.mid;
					}
					
					break;
				}
				
				
				case 2138468:
				{
					if (field.equals("Draw")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Draw"))) );
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef152050 = false;
						return this.attribs;
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Unbind"))) );
					}
					
					break;
				}
				
				
				case 227996723:
				{
					if (field.equals("buffers")) 
					{
						__temp_executeDef152050 = false;
						return this.buffers;
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Bind"))) );
					}
					
					break;
				}
				
				
				case 204392913:
				{
					if (field.equals("activated")) 
					{
						__temp_executeDef152050 = false;
						return this.activated;
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef152050 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 2044289195:
				{
					if (field.equals("active_max")) 
					{
						__temp_executeDef152050 = false;
						return this.active_max;
					}
					
					break;
				}
				
				
				case 1126940025:
				{
					if (field.equals("current")) 
					{
						__temp_executeDef152050 = false;
						return this.current;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152050) 
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
			boolean __temp_executeDef152051 = true;
			switch (field.hashCode())
			{
				case 2044289195:
				{
					if (field.equals("active_max")) 
					{
						__temp_executeDef152051 = false;
						return ((double) (this.active_max) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152051) 
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
			boolean __temp_executeDef152052 = true;
			switch (field.hashCode())
			{
				case -1291178733:
				{
					if (field.equals("UpdateAttrib")) 
					{
						__temp_executeDef152052 = false;
						this.UpdateAttrib(((haxor.graphics.mesh.MeshAttrib) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), haxe.lang.Runtime.toBool(dynargs.__get(2)));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef152052 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -1204358002:
				{
					if (field.equals("RemoveAttrib")) 
					{
						__temp_executeDef152052 = false;
						this.RemoveAttrib(((haxor.graphics.mesh.MeshAttrib) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2070621:
				{
					if (field.equals("Bind")) 
					{
						__temp_executeDef152052 = false;
						this.Bind(((haxor.graphics.mesh.Mesh) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2138468:
				{
					if (field.equals("Draw")) 
					{
						__temp_executeDef152052 = false;
						this.Draw(((haxor.graphics.mesh.Mesh) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1756878218:
				{
					if (field.equals("Unbind")) 
					{
						__temp_executeDef152052 = false;
						this.Unbind();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152052) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("current");
		baseArr.push("active_max");
		baseArr.push("activated");
		baseArr.push("buffers");
		baseArr.push("attribs");
		baseArr.push("mid");
		baseArr.push("aid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


