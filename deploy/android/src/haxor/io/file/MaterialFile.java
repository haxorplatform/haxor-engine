package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MaterialFile extends haxor.io.file.AssetXML
{
	public    MaterialFile(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    MaterialFile(java.lang.String p_src)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.io.file.MaterialFile.__hx_ctor_haxor_io_file_MaterialFile(this, p_src);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_MaterialFile(haxor.io.file.MaterialFile __temp_me312, java.lang.String p_src)
	{
		__temp_me312.mguid = "";
		__temp_me312.mname = "";
		__temp_me312.queue = "opaque";
		__temp_me312.offset = 0;
		__temp_me312.shader = "";
		__temp_me312.ztest = true;
		__temp_me312.zfunc = "lessequal";
		__temp_me312.zwrite = true;
		__temp_me312.blend = false;
		__temp_me312.blendSrc = "one";
		__temp_me312.blendDst = "zero";
		__temp_me312.invert = false;
		__temp_me312.lighting = false;
		__temp_me312.grab = false;
		__temp_me312.cull = "back";
		__temp_me312.uniforms = new haxe.root.Array<haxor.io.file.MaterialFileUniform>(new haxor.io.file.MaterialFileUniform[]{});
		haxor.io.file.AssetXML.__hx_ctor_haxor_io_file_AssetXML(__temp_me312, "", p_src);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.MaterialFile(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.MaterialFile(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  java.lang.String mguid;
	
	public  java.lang.String mname;
	
	public  java.lang.String queue;
	
	public  java.lang.String shader;
	
	public  int offset;
	
	public  boolean ztest;
	
	public  java.lang.String zfunc;
	
	public  boolean zwrite;
	
	public  boolean blend;
	
	public  java.lang.String blendSrc;
	
	public  java.lang.String blendDst;
	
	public  boolean invert;
	
	public  boolean lighting;
	
	public  boolean grab;
	
	public  java.lang.String cull;
	
	public  haxe.root.Array<haxor.io.file.MaterialFileUniform> uniforms;
	
	@Override public   java.lang.Object get_asset()
	{
		haxor.graphics.material.Material m = new haxor.graphics.material.Material(haxe.lang.Runtime.toString(null));
		m.set_name(this.mname);
		m.m_guid = this.mguid;
		{
			java.lang.String _g = this.queue;
			{
				java.lang.String __temp_svar1215 = (_g);
				switch (__temp_svar1215.hashCode())
				{
					case -1332194002:
					{
						if (__temp_svar1215.equals("background")) 
						{
							m.queue = 0;
						}
						
						break;
					}
					
					
					case 502623545:
					{
						if (__temp_svar1215.equals("interface")) 
						{
							m.queue = 4000;
						}
						
						break;
					}
					
					
					case -1010695135:
					{
						if (__temp_svar1215.equals("opaque")) 
						{
							m.queue = 1000;
						}
						
						break;
					}
					
					
					case -1091287984:
					{
						if (__temp_svar1215.equals("overlay")) 
						{
							m.queue = 3000;
						}
						
						break;
					}
					
					
					case -1726194350:
					{
						if (__temp_svar1215.equals("transparent")) 
						{
							m.queue = 2000;
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
		m.queue += this.offset;
		m.set_shader(((haxor.graphics.material.Shader) (haxor.io.file.Asset.Get(this.shader)) ));
		m.ztest = this.ztest;
		m.zfunc = 515;
		{
			java.lang.String _g1 = this.zfunc;
			{
				java.lang.String __temp_svar1217 = (_g1);
				switch (__temp_svar1217.hashCode())
				{
					case 104712844:
					{
						if (__temp_svar1217.equals("never")) 
						{
							m.zfunc = 512;
						}
						
						break;
					}
					
					
					case -1369217158:
					{
						if (__temp_svar1217.equals("greaterequal")) 
						{
							m.zfunc = 518;
						}
						
						break;
					}
					
					
					case -1414557169:
					{
						if (__temp_svar1217.equals("always")) 
						{
							m.zfunc = 519;
						}
						
						break;
					}
					
					
					case 283601914:
					{
						if (__temp_svar1217.equals("greater")) 
						{
							m.zfunc = 516;
						}
						
						break;
					}
					
					
					case 1582008385:
					{
						if (__temp_svar1217.equals("notequal")) 
						{
							m.zfunc = 517;
						}
						
						break;
					}
					
					
					case 371449147:
					{
						if (__temp_svar1217.equals("lessequal")) 
						{
							m.zfunc = 515;
						}
						
						break;
					}
					
					
					case 96757556:
					{
						if (__temp_svar1217.equals("equal")) 
						{
							m.zfunc = 514;
						}
						
						break;
					}
					
					
					case 3318169:
					{
						if (__temp_svar1217.equals("less")) 
						{
							m.zfunc = 513;
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
		m.zwrite = this.zwrite;
		m.blend = this.blend;
		m.blendSrc = this.BlendModeNameToEnum(this.blendSrc);
		m.blendDst = this.BlendModeNameToEnum(this.blendDst);
		m.invert = this.invert;
		m.lighting = this.lighting;
		m.grab = this.grab;
		{
			java.lang.String _g2 = this.cull;
			{
				java.lang.String __temp_svar1219 = (_g2);
				switch (__temp_svar1219.hashCode())
				{
					case 3387192:
					{
						if (__temp_svar1219.equals("none")) 
						{
							m.cull = 0;
						}
						
						break;
					}
					
					
					case 3015911:
					{
						if (__temp_svar1219.equals("back")) 
						{
							m.cull = 2;
						}
						
						break;
					}
					
					
					case 97705513:
					{
						if (__temp_svar1219.equals("front")) 
						{
							m.cull = 1;
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
		{
			int _g11 = 0;
			int _g3 = this.uniforms.length;
			while (( _g11 < _g3 ))
			{
				int i = _g11++;
				haxor.io.file.MaterialFileUniform u = this.uniforms.__get(i);
				haxe.root.Array<java.lang.Object> a = this.stof32a(u.value, null);
				{
					java.lang.String _g21 = u.type;
					{
						java.lang.String __temp_svar1221 = (_g21);
						switch (__temp_svar1221.hashCode())
						{
							case 104431:
							{
								if (__temp_svar1221.equals("int")) 
								{
									m.SetInt(u.name, ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(u.value))) ));
								}
								
								break;
							}
							
							
							case -1417816805:
							{
								if (__temp_svar1221.equals("texture")) 
								{
									m.SetTexture(u.name, ((haxor.graphics.texture.Texture) (haxor.io.file.Asset.Get(u.value)) ));
								}
								
								break;
							}
							
							
							case 3615518:
							{
								if (__temp_svar1221.equals("vec2")) 
								{
									m.SetFloat2(u.name, ((double) (haxe.lang.Runtime.toDouble(a.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(1))) ));
								}
								
								break;
							}
							
							
							case 94842723:
							{
								if (__temp_svar1221.equals("color")) 
								{
									m.SetFloat4(u.name, ((double) (haxe.lang.Runtime.toDouble(a.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(3))) ));
								}
								
								break;
							}
							
							
							case 3615519:
							{
								if (__temp_svar1221.equals("vec3")) 
								{
									m.SetFloat3(u.name, ((double) (haxe.lang.Runtime.toDouble(a.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(2))) ));
								}
								
								break;
							}
							
							
							case 3344084:
							{
								if (__temp_svar1221.equals("mat4")) 
								{
									haxor.math.Matrix4 __temp_stmt1214 = null;
									{
										haxor.context.DataContext _this = haxor.context.EngineContext.data;
										__temp_stmt1214 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
									}
									
									m.SetMatrix4(u.name, haxor.math.Matrix4.FromArray(a, __temp_stmt1214), null);
								}
								
								break;
							}
							
							
							case 3615520:
							{
								if (__temp_svar1221.equals("vec4")) 
								{
									m.SetFloat4(u.name, ((double) (haxe.lang.Runtime.toDouble(a.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(a.__get(3))) ));
								}
								
								break;
							}
							
							
						}
						
					}
					
				}
				
			}
			
		}
		
		return m;
	}
	
	
	@Override public   void Parse(haxe.root.Xml n)
	{
		java.lang.String _g = n.get_nodeName();
		{
			java.lang.String __temp_svar1223 = (_g);
			switch (__temp_svar1223.hashCode())
			{
				case 299066663:
				{
					if (__temp_svar1223.equals("material")) 
					{
						this.guid = this._a(n, "guid", "");
						this.set_name(this._a(n, "name", ""));
					}
					
					break;
				}
				
				
				case -304784065:
				{
					if (__temp_svar1223.equals("uniforms")) 
					{
						this.ParseUniforms(n);
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (__temp_svar1223.equals("queue")) 
					{
						this.offset = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(n, "offset", "0")))) );
						this.queue = haxe.lang.Runtime.toString(this._p(n, "$text", "geometry", true, true));
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (__temp_svar1223.equals("cull")) 
					{
						this.cull = haxe.lang.Runtime.toString(this._p(n, "$text", this.cull, true, true));
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (__temp_svar1223.equals("shader")) 
					{
						this.shader = haxe.lang.Runtime.toString(this._p(n, "$text", "", null, null));
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (__temp_svar1223.equals("grab")) 
					{
						this.grab = haxe.lang.Runtime.eq(this._p(n, "$text", "false", true, true), "true");
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (__temp_svar1223.equals("ztest")) 
					{
						this.ztest = haxe.lang.Runtime.eq(this._p(n, "$text", "true", true, true), "true");
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (__temp_svar1223.equals("lighting")) 
					{
						this.lighting = haxe.lang.Runtime.eq(this._p(n, "$text", "false", true, true), "true");
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (__temp_svar1223.equals("zfunc")) 
					{
						this.zfunc = haxe.lang.Runtime.toString(this._p(n, "$text", this.zfunc, null, null));
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (__temp_svar1223.equals("invert")) 
					{
						this.invert = haxe.lang.Runtime.eq(this._p(n, "$text", "false", true, true), "true");
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (__temp_svar1223.equals("zwrite")) 
					{
						this.zwrite = haxe.lang.Runtime.eq(this._p(n, "$text", "true", true, true), "true");
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (__temp_svar1223.equals("blend")) 
					{
						this.blend = haxe.lang.Runtime.valEq(this._a(n, "enabled", "false"), "true");
						this.blendSrc = haxe.lang.Runtime.toString(this._p(n, "src.$text", "one", true, true));
						this.blendDst = haxe.lang.Runtime.toString(this._p(n, "dst.$text", "zero", true, true));
					}
					
					break;
				}
				
				
			}
			
		}
		
	}
	
	
	public   void ParseUniforms(haxe.root.Xml n)
	{
		java.lang.Object it = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			haxor.io.file.MaterialFileUniform u = new haxor.io.file.MaterialFileUniform();
			u.type = n.get_nodeName().toLowerCase();
			u.name = this._a(n, "name", "");
			u.value = haxe.lang.Runtime.toString(this._p(n, "$text", "", true, null));
			this.uniforms.push(u);
		}
		
	}
	
	
	public   int BlendModeNameToEnum(java.lang.String b)
	{
		{
			java.lang.String __temp_svar1225 = (b);
			switch (__temp_svar1225.hashCode())
			{
				case 3735208:
				{
					if (__temp_svar1225.equals("zero")) 
					{
						return 0;
					}
					
					break;
				}
				
				
				case 1634088617:
				{
					if (__temp_svar1225.equals("srcalphasaturate")) 
					{
						return 776;
					}
					
					break;
				}
				
				
				case 110182:
				{
					if (__temp_svar1225.equals("one")) 
					{
						return 1;
					}
					
					break;
				}
				
				
				case -1707287416:
				{
					if (__temp_svar1225.equals("oneminusdstcolor")) 
					{
						return 775;
					}
					
					break;
				}
				
				
				case -414941185:
				{
					if (__temp_svar1225.equals("srccolor")) 
					{
						return 768;
					}
					
					break;
				}
				
				
				case 586906814:
				{
					if (__temp_svar1225.equals("dstcolor")) 
					{
						return 774;
					}
					
					break;
				}
				
				
				case 1585831881:
				{
					if (__temp_svar1225.equals("oneminussrccolor")) 
					{
						return 769;
					}
					
					break;
				}
				
				
				case -1709220221:
				{
					if (__temp_svar1225.equals("oneminusdstalpha")) 
					{
						return 773;
					}
					
					break;
				}
				
				
				case -416873990:
				{
					if (__temp_svar1225.equals("srcalpha")) 
					{
						return 770;
					}
					
					break;
				}
				
				
				case 584974009:
				{
					if (__temp_svar1225.equals("dstalpha")) 
					{
						return 772;
					}
					
					break;
				}
				
				
				case 1583899076:
				{
					if (__temp_svar1225.equals("oneminussrcalpha")) 
					{
						return 771;
					}
					
					break;
				}
				
				
			}
			
		}
		
		return 0;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1227 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1227 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1227) 
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
			boolean __temp_executeDef1228 = true;
			switch (field.hashCode())
			{
				case -304784065:
				{
					if (field.equals("uniforms")) 
					{
						__temp_executeDef1228 = false;
						this.uniforms = ((haxe.root.Array<haxor.io.file.MaterialFileUniform>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103848054:
				{
					if (field.equals("mguid")) 
					{
						__temp_executeDef1228 = false;
						this.mguid = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef1228 = false;
						this.cull = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 104037496:
				{
					if (field.equals("mname")) 
					{
						__temp_executeDef1228 = false;
						this.mname = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef1228 = false;
						this.grab = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef1228 = false;
						this.queue = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef1228 = false;
						this.lighting = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef1228 = false;
						this.shader = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef1228 = false;
						this.invert = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1228 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef1228 = false;
						this.blendDst = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef1228 = false;
						this.ztest = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef1228 = false;
						this.blendSrc = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef1228 = false;
						this.zfunc = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef1228 = false;
						this.blend = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef1228 = false;
						this.zwrite = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1228) 
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
			boolean __temp_executeDef1229 = true;
			switch (field.hashCode())
			{
				case 849145115:
				{
					if (field.equals("BlendModeNameToEnum")) 
					{
						__temp_executeDef1229 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BlendModeNameToEnum"))) );
					}
					
					break;
				}
				
				
				case 103848054:
				{
					if (field.equals("mguid")) 
					{
						__temp_executeDef1229 = false;
						return this.mguid;
					}
					
					break;
				}
				
				
				case -288970510:
				{
					if (field.equals("ParseUniforms")) 
					{
						__temp_executeDef1229 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseUniforms"))) );
					}
					
					break;
				}
				
				
				case 104037496:
				{
					if (field.equals("mname")) 
					{
						__temp_executeDef1229 = false;
						return this.mname;
					}
					
					break;
				}
				
				
				case 76884627:
				{
					if (field.equals("Parse")) 
					{
						__temp_executeDef1229 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Parse"))) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef1229 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case 1130071239:
				{
					if (field.equals("get_asset")) 
					{
						__temp_executeDef1229 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_asset"))) );
					}
					
					break;
				}
				
				
				case -903579675:
				{
					if (field.equals("shader")) 
					{
						__temp_executeDef1229 = false;
						return this.shader;
					}
					
					break;
				}
				
				
				case -304784065:
				{
					if (field.equals("uniforms")) 
					{
						__temp_executeDef1229 = false;
						return this.uniforms;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1229 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case 3065202:
				{
					if (field.equals("cull")) 
					{
						__temp_executeDef1229 = false;
						return this.cull;
					}
					
					break;
				}
				
				
				case 116226060:
				{
					if (field.equals("ztest")) 
					{
						__temp_executeDef1229 = false;
						return this.ztest;
					}
					
					break;
				}
				
				
				case 3181132:
				{
					if (field.equals("grab")) 
					{
						__temp_executeDef1229 = false;
						return this.grab;
					}
					
					break;
				}
				
				
				case 115824190:
				{
					if (field.equals("zfunc")) 
					{
						__temp_executeDef1229 = false;
						return this.zfunc;
					}
					
					break;
				}
				
				
				case 991970060:
				{
					if (field.equals("lighting")) 
					{
						__temp_executeDef1229 = false;
						return this.lighting;
					}
					
					break;
				}
				
				
				case -688811099:
				{
					if (field.equals("zwrite")) 
					{
						__temp_executeDef1229 = false;
						return this.zwrite;
					}
					
					break;
				}
				
				
				case -1183703082:
				{
					if (field.equals("invert")) 
					{
						__temp_executeDef1229 = false;
						return this.invert;
					}
					
					break;
				}
				
				
				case 93823057:
				{
					if (field.equals("blend")) 
					{
						__temp_executeDef1229 = false;
						return this.blend;
					}
					
					break;
				}
				
				
				case -940949580:
				{
					if (field.equals("blendDst")) 
					{
						__temp_executeDef1229 = false;
						return this.blendDst;
					}
					
					break;
				}
				
				
				case -940935213:
				{
					if (field.equals("blendSrc")) 
					{
						__temp_executeDef1229 = false;
						return this.blendSrc;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1229) 
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
			boolean __temp_executeDef1230 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1230 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1230) 
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
			int __temp_hash1232 = field.hashCode();
			boolean __temp_executeDef1231 = true;
			switch (__temp_hash1232)
			{
				case 76884627:case 1130071239:
				{
					if (( (( ( __temp_hash1232 == 76884627 ) && field.equals("Parse") )) || field.equals("get_asset") )) 
					{
						__temp_executeDef1231 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -288970510:
				{
					if (field.equals("ParseUniforms")) 
					{
						__temp_executeDef1231 = false;
						this.ParseUniforms(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 849145115:
				{
					if (field.equals("BlendModeNameToEnum")) 
					{
						__temp_executeDef1231 = false;
						return this.BlendModeNameToEnum(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1231) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("uniforms");
		baseArr.push("cull");
		baseArr.push("grab");
		baseArr.push("lighting");
		baseArr.push("invert");
		baseArr.push("blendDst");
		baseArr.push("blendSrc");
		baseArr.push("blend");
		baseArr.push("zwrite");
		baseArr.push("zfunc");
		baseArr.push("ztest");
		baseArr.push("offset");
		baseArr.push("shader");
		baseArr.push("queue");
		baseArr.push("mname");
		baseArr.push("mguid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


