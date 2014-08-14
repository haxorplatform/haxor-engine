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
	
	
	public static   void __hx_ctor_haxor_graphics_material_Material(haxor.graphics.material.Material __temp_me21755, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me21755, p_name);
		__temp_me21755.grab = false;
		__temp_me21755._cid_ = haxor.context.EngineContext.material.mid++;
		__temp_me21755.queue = 1000;
		__temp_me21755.zfunc = 515;
		__temp_me21755.ztest = true;
		__temp_me21755.zwrite = true;
		__temp_me21755.blend = false;
		__temp_me21755.blendSrc = 1;
		__temp_me21755.blendDst = 0;
		__temp_me21755.invert = false;
		__temp_me21755.cull = 2;
		__temp_me21755.lighting = false;
		__temp_me21755.grab = false;
		haxor.context.EngineContext.material.InitializeMaterial(__temp_me21755);
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
	
	public   void SetBlending(int p_src, int p_dst)
	{
		this.blend =  ! ((( ( p_src == 1 ) && ( p_dst == 0 ) ))) ;
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	
	
	@Override public   void OnDestroy()
	{
		haxor.context.MaterialContext _this = haxor.context.EngineContext.material;
		int p = ((int) (haxe.lang.Runtime.toInt(_this.programs.__get(this._cid_))) );
		if (( this.m_shader != null )) 
		{
			haxor.platform.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(_this.vertex_shaders.__get(this.m_shader._cid_))) ));
			haxor.platform.graphics.GL.m_gl.DetachShader(p, ((int) (haxe.lang.Runtime.toInt(_this.fragment_shaders.__get(this.m_shader._cid_))) ));
		}
		
		haxor.platform.graphics.GL.m_gl.DeleteProgram(p);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21911 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef21911 = false;
						this.cull = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef21911 = false;
						this.zfunc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef21911 = false;
						this.blendDst = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef21911 = false;
						this.queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef21911 = false;
						this.blendSrc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21911) 
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
			boolean __temp_executeDef21912 = true;
			switch (field.hashCode())
			{
				case -1502310409:
				{
					if (field.equals("m_shader")) 
					{
						__temp_executeDef21912 = false;
						this.m_shader = ((haxor.graphics.material.Shader) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef21912 = false;
						this.ztest = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef21912 = false;
						this.set_shader(((haxor.graphics.material.Shader) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef21912 = false;
						this.zfunc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef21912 = false;
						this.grab = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef21912 = false;
						this.zwrite = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef21912 = false;
						this.lighting = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef21912 = false;
						this.blend = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef21912 = false;
						this.cull = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef21912 = false;
						this.queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef21912 = false;
						this.invert = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef21912 = false;
						this.blendSrc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef21912 = false;
						this.blendDst = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21912) 
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
			boolean __temp_executeDef21913 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef21913 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef21913 = false;
						return this.ztest;
					}
					
					break;
				}
				
				
				case -1578692525:
				{
					if (field.equals("SetBlending")) 
					{
						__temp_executeDef21913 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetBlending"))) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef21913 = false;
						return this.zfunc;
					}
					
					break;
				}
				
				
				case -1502310409:
				{
					if (field.equals("m_shader")) 
					{
						__temp_executeDef21913 = false;
						return this.m_shader;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef21913 = false;
						return this.zwrite;
					}
					
					break;
				}
				
				
				case -1181063582:
				{
					if (field.equals("set_shader")) 
					{
						__temp_executeDef21913 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_shader"))) );
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef21913 = false;
						return this.blend;
					}
					
					break;
				}
				
				
				case 1177098478:
				{
					if (field.equals("get_shader")) 
					{
						__temp_executeDef21913 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_shader"))) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef21913 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef21913 = false;
						return this.get_shader();
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef21913 = false;
						return this.blendSrc;
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef21913 = false;
						return this.grab;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef21913 = false;
						return this.blendDst;
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef21913 = false;
						return this.lighting;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef21913 = false;
						return this.invert;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef21913 = false;
						return this.cull;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21913) 
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
			boolean __temp_executeDef21914 = true;
			switch (field.hashCode())
			{
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef21914 = false;
						return ((double) (this.cull) );
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef21914 = false;
						return ((double) (this.zfunc) );
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef21914 = false;
						return ((double) (this.blendDst) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef21914 = false;
						return ((double) (this.queue) );
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef21914 = false;
						return ((double) (this.blendSrc) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21914) 
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
			boolean __temp_executeDef21915 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef21915 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1177098478:
				{
					if (field.equals("get_shader")) 
					{
						__temp_executeDef21915 = false;
						return this.get_shader();
					}
					
					break;
				}
				
				
				case -1578692525:
				{
					if (field.equals("SetBlending")) 
					{
						__temp_executeDef21915 = false;
						this.SetBlending(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1181063582:
				{
					if (field.equals("set_shader")) 
					{
						__temp_executeDef21915 = false;
						return this.set_shader(((haxor.graphics.material.Shader) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21915) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
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


