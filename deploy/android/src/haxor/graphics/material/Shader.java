package haxor.graphics.material;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Shader extends haxor.core.Resource
{
	public    Shader(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Shader(java.lang.String p_source)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.material.Shader.__hx_ctor_haxor_graphics_material_Shader(this, p_source);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_material_Shader(haxor.graphics.material.Shader __temp_me164247, java.lang.String p_source)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me164247, null);
		{
			haxor.context.UID _this = haxor.context.EngineContext.material.sid;
			if (( _this.m_cache.length <= 0 )) 
			{
				__temp_me164247.__cid = _this.m_id++;
			}
			 else 
			{
				__temp_me164247.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		int vt0 = haxe.lang.StringExt.indexOf(p_source, "<vertex", null);
		int vt1 = haxe.lang.StringExt.indexOf(p_source, ">", ( vt0 + 1 ));
		java.lang.String vt = haxe.lang.StringExt.substring(p_source, vt0, ( vt1 + 1 ));
		int ft0 = haxe.lang.StringExt.indexOf(p_source, "<fragment", null);
		int ft1 = haxe.lang.StringExt.indexOf(p_source, ">", ( ft0 + 1 ));
		java.lang.String ft = haxe.lang.StringExt.substring(p_source, ft0, ( ft1 + 1 ));
		p_source = haxe.root.StringTools.replace(p_source, vt, ( vt + "<![CDATA[" ));
		p_source = haxe.root.StringTools.replace(p_source, "</vertex>", "]]></vertex>");
		p_source = haxe.root.StringTools.replace(p_source, ft, ( ft + "<![CDATA[" ));
		p_source = haxe.root.StringTools.replace(p_source, "</fragment>", "]]></fragment>");
		haxe.root.Xml x = null;
		x = haxe.root.Xml.parse(p_source);
		x = x.firstElement();
		__temp_me164247.set_name(x.get("id"));
		if (( ( __temp_me164247.get_name() == null ) || haxe.lang.Runtime.valEq(__temp_me164247.get_name(), "") )) 
		{
			__temp_me164247.set_name(( "Shader" + __temp_me164247.__cid ));
		}
		
		haxe.root.Xml vs = ((haxe.root.Xml) (haxe.lang.Runtime.callField(x.elementsNamed("vertex"), "next", null)) );
		haxe.root.Xml fs = ((haxe.root.Xml) (haxe.lang.Runtime.callField(x.elementsNamed("fragment"), "next", null)) );
		__temp_me164247.m_vss = __temp_me164247.GetShaderSource(vs);
		__temp_me164247.m_fss = __temp_me164247.GetShaderSource(fs);
		__temp_me164247.m_hasError = false;
		haxor.context.EngineContext.material.InitializeShader(__temp_me164247);
	}
	
	
	public static  haxor.graphics.material.Shader Flat;
	
	public static   haxor.graphics.material.Shader get_Flat()
	{
		if (( haxor.graphics.material.Shader.m_flat_shader == null )) 
		{
			return haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_source));
		}
		 else 
		{
			return haxor.graphics.material.Shader.m_flat_shader;
		}
		
	}
	
	
	public static  haxor.graphics.material.Shader m_flat_shader;
	
	public static  haxor.graphics.material.Shader FlatTexture;
	
	public static   haxor.graphics.material.Shader get_FlatTexture()
	{
		if (( haxor.graphics.material.Shader.m_flat_texture_shader == null )) 
		{
			return haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(haxor.context.ShaderContext.flat_texture_source));
		}
		 else 
		{
			return haxor.graphics.material.Shader.m_flat_texture_shader;
		}
		
	}
	
	
	public static  haxor.graphics.material.Shader m_flat_texture_shader;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.material.Shader(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  java.lang.String m_vss;
	
	public  java.lang.String m_fss;
	
	
	
	public final   boolean get_hasError()
	{
		return this.m_hasError;
	}
	
	
	public  boolean m_hasError;
	
	public   java.lang.String GetShaderSource(haxe.root.Xml n)
	{
		if (( n == null )) 
		{
			return "";
		}
		
		java.lang.String src = n.firstChild().get_nodeValue().toString();
		java.lang.String prec = (( (( n.get("precision") == null )) ? ("low") : (n.get("precision")) )).toLowerCase();
		{
			java.lang.String __temp_svar164950 = (prec);
			switch (__temp_svar164950.hashCode())
			{
				case 107348:
				{
					if (__temp_svar164950.equals("low")) 
					{
						prec = "precision lowp float;";
					}
					
					break;
				}
				
				
				case 3202466:
				{
					if (__temp_svar164950.equals("high")) 
					{
						prec = "precision highp float;";
					}
					
					break;
				}
				
				
				case -1078030475:
				{
					if (__temp_svar164950.equals("medium")) 
					{
						prec = "precision mediump float;";
					}
					
					break;
				}
				
				
			}
			
		}
		
		return ( prec + src );
	}
	
	
	@Override public   void OnDestroy()
	{
		haxor.context.EngineContext.material.DestroyShader(this);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164952 = true;
			switch (field.hashCode())
			{
				case 262159136:
				{
					if (field.equals("m_hasError")) 
					{
						__temp_executeDef164952 = false;
						this.m_hasError = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 103611012:
				{
					if (field.equals("m_vss")) 
					{
						__temp_executeDef164952 = false;
						this.m_vss = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 103595636:
				{
					if (field.equals("m_fss")) 
					{
						__temp_executeDef164952 = false;
						this.m_fss = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164952) 
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
			boolean __temp_executeDef164953 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef164953 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 103611012:
				{
					if (field.equals("m_vss")) 
					{
						__temp_executeDef164953 = false;
						return this.m_vss;
					}
					
					break;
				}
				
				
				case -1340287306:
				{
					if (field.equals("GetShaderSource")) 
					{
						__temp_executeDef164953 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderSource"))) );
					}
					
					break;
				}
				
				
				case 103595636:
				{
					if (field.equals("m_fss")) 
					{
						__temp_executeDef164953 = false;
						return this.m_fss;
					}
					
					break;
				}
				
				
				case 262159136:
				{
					if (field.equals("m_hasError")) 
					{
						__temp_executeDef164953 = false;
						return this.m_hasError;
					}
					
					break;
				}
				
				
				case 116776846:
				{
					if (field.equals("hasError")) 
					{
						__temp_executeDef164953 = false;
						return this.get_hasError();
					}
					
					break;
				}
				
				
				case -1806278057:
				{
					if (field.equals("get_hasError")) 
					{
						__temp_executeDef164953 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_hasError"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164953) 
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
			boolean __temp_executeDef164954 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef164954 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1806278057:
				{
					if (field.equals("get_hasError")) 
					{
						__temp_executeDef164954 = false;
						return this.get_hasError();
					}
					
					break;
				}
				
				
				case -1340287306:
				{
					if (field.equals("GetShaderSource")) 
					{
						__temp_executeDef164954 = false;
						return this.GetShaderSource(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164954) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_hasError");
		baseArr.push("hasError");
		baseArr.push("m_fss");
		baseArr.push("m_vss");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


