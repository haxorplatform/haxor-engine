package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class SkinnedMesh3 extends haxor.graphics.mesh.Mesh3
{
	public    SkinnedMesh3(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    SkinnedMesh3(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.SkinnedMesh3.__hx_ctor_haxor_graphics_mesh_SkinnedMesh3(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_SkinnedMesh3(haxor.graphics.mesh.SkinnedMesh3 __temp_me164256, java.lang.String p_name)
	{
		haxor.graphics.mesh.Mesh3.__hx_ctor_haxor_graphics_mesh_Mesh3(__temp_me164256, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.SkinnedMesh3(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.SkinnedMesh3(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   haxe.root.Array<haxor.math.Matrix4> get_binds()
	{
		return this.m_binds;
	}
	
	
	public   haxe.root.Array<haxor.math.Matrix4> set_binds(haxe.root.Array<haxor.math.Matrix4> v)
	{
		this.m_binds = v.copy();
		return v;
	}
	
	
	public  haxe.root.Array<haxor.math.Matrix4> m_binds;
	
	
	
	public   haxe.root.Array<haxor.math.Vector4> get_bone()
	{
		return this.m_bone;
	}
	
	
	public   haxe.root.Array<haxor.math.Vector4> set_bone(haxe.root.Array<haxor.math.Vector4> v)
	{
		return this.m_bone = this.UpdateAttribute("bone", v, false);
	}
	
	
	public  haxe.root.Array<haxor.math.Vector4> m_bone;
	
	
	
	public   haxe.root.Array<haxor.math.Vector4> get_weight()
	{
		return this.m_weight;
	}
	
	
	public   haxe.root.Array<haxor.math.Vector4> set_weight(haxe.root.Array<haxor.math.Vector4> v)
	{
		return this.m_weight = this.UpdateAttribute("weight", v, false);
	}
	
	
	public  haxe.root.Array<haxor.math.Vector4> m_weight;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164969 = true;
			switch (field.hashCode())
			{
				case -1390323062:
				{
					if (field.equals("m_weight")) 
					{
						__temp_executeDef164969 = false;
						this.m_weight = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 93742038:
				{
					if (field.equals("binds")) 
					{
						__temp_executeDef164969 = false;
						this.set_binds(((haxe.root.Array<haxor.math.Matrix4>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -791592328:
				{
					if (field.equals("weight")) 
					{
						__temp_executeDef164969 = false;
						this.set_weight(((haxe.root.Array<haxor.math.Vector4>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 767164804:
				{
					if (field.equals("m_binds")) 
					{
						__temp_executeDef164969 = false;
						this.m_binds = ((haxe.root.Array<haxor.math.Matrix4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083625642:
				{
					if (field.equals("m_bone")) 
					{
						__temp_executeDef164969 = false;
						this.m_bone = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3029700:
				{
					if (field.equals("bone")) 
					{
						__temp_executeDef164969 = false;
						this.set_bone(((haxe.root.Array<haxor.math.Vector4>) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164969) 
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
			boolean __temp_executeDef164970 = true;
			switch (field.hashCode())
			{
				case -1390323062:
				{
					if (field.equals("m_weight")) 
					{
						__temp_executeDef164970 = false;
						return this.m_weight;
					}
					
					break;
				}
				
				
				case 93742038:
				{
					if (field.equals("binds")) 
					{
						__temp_executeDef164970 = false;
						return this.get_binds();
					}
					
					break;
				}
				
				
				case -1069076235:
				{
					if (field.equals("set_weight")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_weight"))) );
					}
					
					break;
				}
				
				
				case 1130692013:
				{
					if (field.equals("get_binds")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_binds"))) );
					}
					
					break;
				}
				
				
				case 1289085825:
				{
					if (field.equals("get_weight")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_weight"))) );
					}
					
					break;
				}
				
				
				case 916074937:
				{
					if (field.equals("set_binds")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_binds"))) );
					}
					
					break;
				}
				
				
				case -791592328:
				{
					if (field.equals("weight")) 
					{
						__temp_executeDef164970 = false;
						return this.get_weight();
					}
					
					break;
				}
				
				
				case 767164804:
				{
					if (field.equals("m_binds")) 
					{
						__temp_executeDef164970 = false;
						return this.m_binds;
					}
					
					break;
				}
				
				
				case -1083625642:
				{
					if (field.equals("m_bone")) 
					{
						__temp_executeDef164970 = false;
						return this.m_bone;
					}
					
					break;
				}
				
				
				case 3029700:
				{
					if (field.equals("bone")) 
					{
						__temp_executeDef164970 = false;
						return this.get_bone();
					}
					
					break;
				}
				
				
				case 1415029889:
				{
					if (field.equals("set_bone")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_bone"))) );
					}
					
					break;
				}
				
				
				case 1976142349:
				{
					if (field.equals("get_bone")) 
					{
						__temp_executeDef164970 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_bone"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164970) 
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
			boolean __temp_executeDef164971 = true;
			switch (field.hashCode())
			{
				case -1069076235:
				{
					if (field.equals("set_weight")) 
					{
						__temp_executeDef164971 = false;
						return this.set_weight(((haxe.root.Array<haxor.math.Vector4>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1130692013:
				{
					if (field.equals("get_binds")) 
					{
						__temp_executeDef164971 = false;
						return this.get_binds();
					}
					
					break;
				}
				
				
				case 1289085825:
				{
					if (field.equals("get_weight")) 
					{
						__temp_executeDef164971 = false;
						return this.get_weight();
					}
					
					break;
				}
				
				
				case 916074937:
				{
					if (field.equals("set_binds")) 
					{
						__temp_executeDef164971 = false;
						return this.set_binds(((haxe.root.Array<haxor.math.Matrix4>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415029889:
				{
					if (field.equals("set_bone")) 
					{
						__temp_executeDef164971 = false;
						return this.set_bone(((haxe.root.Array<haxor.math.Vector4>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1976142349:
				{
					if (field.equals("get_bone")) 
					{
						__temp_executeDef164971 = false;
						return this.get_bone();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164971) 
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
		baseArr.push("m_weight");
		baseArr.push("weight");
		baseArr.push("m_bone");
		baseArr.push("bone");
		baseArr.push("m_binds");
		baseArr.push("binds");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


