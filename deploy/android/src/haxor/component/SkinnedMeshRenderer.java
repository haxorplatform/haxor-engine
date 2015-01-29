package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class SkinnedMeshRenderer extends haxor.component.MeshRenderer
{
	public    SkinnedMeshRenderer(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    SkinnedMeshRenderer(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.SkinnedMeshRenderer.__hx_ctor_haxor_component_SkinnedMeshRenderer(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_SkinnedMeshRenderer(haxor.component.SkinnedMeshRenderer __temp_me40, java.lang.String p_name)
	{
		haxor.component.MeshRenderer.__hx_ctor_haxor_component_MeshRenderer(__temp_me40, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.SkinnedMeshRenderer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.SkinnedMeshRenderer(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   haxe.root.Array<haxor.component.Transform> set_joints(haxe.root.Array<haxor.component.Transform> v)
	{
		if (( v == null )) 
		{
			this.m_joints = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{});
		}
		 else 
		{
			this.m_joints = v;
		}
		
		return this.m_joints;
	}
	
	
	public final   haxe.root.Array<haxor.component.Transform> get_joints()
	{
		return this.m_joints;
	}
	
	
	public  haxe.root.Array<haxor.component.Transform> m_joints;
	
	public  haxe.root.Array<java.lang.Object> m_buffer;
	
	public  haxor.graphics.texture.ComputeTexture m_data;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		this.m_joints = new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{});
		this.m_buffer = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 8192 ))
			{
				int i = _g++;
				this.m_buffer.push(0);
			}
			
		}
		
		this.m_data = new haxor.graphics.texture.ComputeTexture(((int) (1) ), ((int) (2048) ), ((haxor.core.PixelFormat) (haxor.core.PixelFormat.Float4) ));
		this.m_data.set_name(( "SkinningTexture" + this.get_uid() ));
	}
	
	
	@Override public   void OnRender()
	{
		if (( this.m_material != null )) 
		{
			haxor.graphics.mesh.SkinnedMesh3 skm = ((haxor.graphics.mesh.SkinnedMesh3) (this.m_mesh) );
			int k = 0;
			haxor.math.Matrix4 jm = null;
			haxor.math.Matrix4 bm = null;
			haxor.io.FloatArray f32 = ((haxor.io.FloatArray) (this.m_data.m_data.get_buffer()) );
			{
				int _g1 = 0;
				int _g = this.m_joints.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					jm = this.m_joints.__get(i).get_WorldMatrix();
					bm = skm.get_binds().__get(i);
					{
						int _g2 = 0;
						while (( _g2 < 12 ))
						{
							int j = _g2++;
							f32.Set(k, jm.GetIndex(j));
							f32.Set(( k + 4096 ), bm.GetIndex(j));
							k++;
						}
						
					}
					
				}
				
			}
			
			this.m_data.Invalidate();
			this.m_material.SetTexture("Skinning", this.m_data);
		}
		
		super.OnRender();
		double sh = haxor.graphics.Screen.m_height;
		double th = 2048.0;
		haxor.graphics.Graphics.DrawTexture(this.m_data, 0, ( th + 105 ), 256,  - (th) , null);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef657 = true;
			switch (field.hashCode())
			{
				case -1083579332:
				{
					if (field.equals("m_data")) 
					{
						__temp_executeDef657 = false;
						this.m_data = ((haxor.graphics.texture.ComputeTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1154528983:
				{
					if (field.equals("joints")) 
					{
						__temp_executeDef657 = false;
						this.set_joints(((haxe.root.Array<haxor.component.Transform>) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef657 = false;
						this.m_buffer = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1753259717:
				{
					if (field.equals("m_joints")) 
					{
						__temp_executeDef657 = false;
						this.m_joints = ((haxe.root.Array<haxor.component.Transform>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef657) 
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
			boolean __temp_executeDef658 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef658 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case -1154528983:
				{
					if (field.equals("joints")) 
					{
						__temp_executeDef658 = false;
						return this.get_joints();
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef658 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1432012890:
				{
					if (field.equals("set_joints")) 
					{
						__temp_executeDef658 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_joints"))) );
					}
					
					break;
				}
				
				
				case -1083579332:
				{
					if (field.equals("m_data")) 
					{
						__temp_executeDef658 = false;
						return this.m_data;
					}
					
					break;
				}
				
				
				case 926149170:
				{
					if (field.equals("get_joints")) 
					{
						__temp_executeDef658 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_joints"))) );
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef658 = false;
						return this.m_buffer;
					}
					
					break;
				}
				
				
				case -1753259717:
				{
					if (field.equals("m_joints")) 
					{
						__temp_executeDef658 = false;
						return this.m_joints;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef658) 
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
			int __temp_hash660 = field.hashCode();
			boolean __temp_executeDef659 = true;
			switch (__temp_hash660)
			{
				case 1528462453:case 312095663:
				{
					if (( (( ( __temp_hash660 == 1528462453 ) && field.equals("OnRender") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef659 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1432012890:
				{
					if (field.equals("set_joints")) 
					{
						__temp_executeDef659 = false;
						return this.set_joints(((haxe.root.Array<haxor.component.Transform>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 926149170:
				{
					if (field.equals("get_joints")) 
					{
						__temp_executeDef659 = false;
						return this.get_joints();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef659) 
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
		baseArr.push("m_data");
		baseArr.push("m_buffer");
		baseArr.push("m_joints");
		baseArr.push("joints");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


